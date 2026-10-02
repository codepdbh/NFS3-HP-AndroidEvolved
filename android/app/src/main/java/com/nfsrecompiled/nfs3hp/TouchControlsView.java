package com.nfsrecompiled.nfs3hp;

import android.content.Context;
import android.graphics.Canvas;
import android.graphics.Paint;
import android.graphics.Path;
import android.graphics.RectF;
import android.graphics.Typeface;
import android.hardware.Sensor;
import android.hardware.SensorEvent;
import android.hardware.SensorEventListener;
import android.hardware.SensorManager;
import android.os.SystemClock;
import android.util.SparseArray;
import android.view.HapticFeedbackConstants;
import android.view.KeyEvent;
import android.view.MotionEvent;
import android.view.Surface;
import android.view.View;
import android.view.WindowManager;
import java.util.ArrayList;
import java.util.List;

/**
 * On-screen racing controls drawn on one view. They only appear during a race
 * (steering, pedals, utilities below the HUD); menus are tapped directly.
 *
 * Every finger is tracked on its own and may slide from one control to another
 * (gas to brake, left to right) without lifting. Touches that land on no
 * control fall through to the SDL surface, so menus can still be tapped.
 * An edit mode lets the player drag and resize every control.
 */
final class TouchControlsView extends View implements SensorEventListener {
    static final int MODE_MENU = 0, MODE_RACE = 1;

    private static final int KIND_KEY = 0, KIND_LEFT = 1, KIND_RIGHT = 2, KIND_SETTINGS = 3, KIND_SLIDE = 4, KIND_STICK = 5;
    private static final int ICON_NONE = 0, ICON_LEFT = 1, ICON_RIGHT = 2, ICON_UP = 3, ICON_DOWN = 4, ICON_GEAR = 5,
        ICON_GAS = 6, ICON_BRAKE = 7, ICON_PAUSE = 8, ICON_CAMERA = 9, ICON_HORN = 10, ICON_CHECK = 11, ICON_BACK = 12,
        ICON_PLUS = 13, ICON_MINUS = 14, ICON_HANDBRAKE = 15;
    /** Tilt only steers while a pedal is held (or just released), so a resting phone never drifts. */
    private static final long TILT_GRACE_MS = 1500;
    private static final int WHITE = 0xFFFFFFFF;

    private static final class Control {
        final String id, caption; final int key, kind, accent, icon; final boolean pedal;
        final RectF rect = new RectF();
        final RectF base = new RectF();
        boolean visible; int pointers;
        Control(String id, String caption, int key, int kind, int accent, int icon, boolean pedal) {
            this.id = id; this.caption = caption; this.key = key; this.kind = kind;
            this.accent = accent; this.icon = icon; this.pedal = pedal;
        }
        boolean editable() { return kind != KIND_SETTINGS && kind != KIND_SLIDE; }
    }

    private final ControlSettings settings;
    private final KeyInput input;
    private final Runnable openSettings;
    private final List<Control> controls = new ArrayList<>();
    private final SparseArray<Control> pointerControl = new SparseArray<>();
    private final Paint fill = new Paint(Paint.ANTI_ALIAS_FLAG);
    private final Paint stroke = new Paint(Paint.ANTI_ALIAS_FLAG);
    private final Paint text = new Paint(Paint.ANTI_ALIAS_FLAG);
    private final Paint ink = new Paint(Paint.ANTI_ALIAS_FLAG);
    private final Path path = new Path();
    private final RectF scratch = new RectF();
    private final float density;

    // Race.
    private final Control gas, brake, handbrake, left, right, gearUp, gearDown, slideZone, stick, pause, camera, horn;
    private final Control settingsButton;

    private int mode = MODE_MENU;
    private int slidePointer = -1;
    private int stickPointer = -1;
    private float stickX, stickY;
    private float slideOriginX, slideX;
    private boolean gamepadMode;
    private long pedalReleasedAt;
    private float tiltAngle;
    private SensorManager sensors;
    private boolean sensorRegistered;

    // Layout editor.
    private boolean editing;
    private Runnable editDone;
    private Control selected;
    private int dragPointer = -1;
    private float dragDx, dragDy;
    private final RectF[] toolbar = { new RectF(), new RectF(), new RectF(), new RectF() };
    private static final String[] TOOLBAR_LABELS = { "−", "+", "RESTABLECER", "LISTO" };

    TouchControlsView(Context context, ControlSettings settings, KeyInput input, Runnable openSettings) {
        super(context);
        this.settings = settings; this.input = input; this.openSettings = openSettings;
        density = getResources().getDisplayMetrics().density;
        stroke.setStyle(Paint.Style.STROKE);
        text.setTextAlign(Paint.Align.CENTER);
        text.setTypeface(Typeface.create("sans-serif-condensed", Typeface.BOLD));
        text.setLetterSpacing(0.08f);
        ink.setStrokeCap(Paint.Cap.ROUND);
        ink.setStrokeJoin(Paint.Join.ROUND);
        setHapticFeedbackEnabled(true);

        int green = 0xFF34C759, red = 0xFFFF453A, amber = 0xFFFF9F0A, blue = 0xFF0A84FF, grey = 0xFF8E8E93;
        gas = add("gas", "GAS", KeyEvent.KEYCODE_DPAD_UP, KIND_KEY, green, ICON_GAS, true);
        brake = add("brake", "FRENO", KeyEvent.KEYCODE_DPAD_DOWN, KIND_KEY, red, ICON_BRAKE, true);
        handbrake = add("handbrake", "MANO", KeyEvent.KEYCODE_SPACE, KIND_KEY, amber, ICON_HANDBRAKE, true);
        gearUp = add("gearUp", "", KeyEvent.KEYCODE_A, KIND_KEY, blue, ICON_PLUS, false);
        gearDown = add("gearDown", "", KeyEvent.KEYCODE_Z, KIND_KEY, blue, ICON_MINUS, false);
        left = add("left", "", 0, KIND_LEFT, blue, ICON_LEFT, false);
        right = add("right", "", 0, KIND_RIGHT, blue, ICON_RIGHT, false);
        slideZone = add("slide", "", 0, KIND_SLIDE, blue, ICON_NONE, false);
        stick = add("stick", "", 0, KIND_STICK, blue, ICON_NONE, false);
        pause = add("pause", "", KeyEvent.KEYCODE_ESCAPE, KIND_KEY, grey, ICON_PAUSE, false);
        camera = add("camera", "", KeyEvent.KEYCODE_C, KIND_KEY, grey, ICON_CAMERA, false);
        horn = add("horn", "", KeyEvent.KEYCODE_H, KIND_KEY, grey, ICON_HORN, false);


        settingsButton = add("settings", "", 0, KIND_SETTINGS, grey, ICON_GEAR, false);
    }

    private Control add(String id, String caption, int key, int kind, int accent, int icon, boolean pedal) {
        Control control = new Control(id, caption, key, kind, accent, icon, pedal);
        controls.add(control);
        return control;
    }

    // ---- lifecycle -------------------------------------------------------

    void resume() {
        input.configure(settings);
        input.start();
        updateSensor();
    }

    void pause() {
        releaseAll();
        if (sensorRegistered) sensors.unregisterListener(this);
        sensorRegistered = false;
    }

    /** Re-applies settings after the settings dialog closes. */
    void applySettings() {
        releaseAll();
        input.configure(settings);
        layoutControls(getWidth(), getHeight());
        updateSensor();
        invalidate();
    }

    void setGamepadMode(boolean enabled) {
        if (enabled == gamepadMode) return;
        gamepadMode = enabled;
        applySettings();
    }

    /** Switches between the menu and race layouts. */
    void setMode(int newMode) {
        if (newMode == mode || editing) return;
        mode = newMode;
        applySettings();
    }

    int getMode() { return mode; }

    boolean isGamepadMode() { return gamepadMode; }

    private int fps = -1;

    /** Frames per second to show in a corner, or -1 to hide the counter. */
    void setFps(int value) {
        if (value == fps) return;
        fps = value;
        invalidate();
    }

    boolean isEditing() { return editing; }

    /** Lets the player drag and resize controls; {@code done} runs when they tap LISTO. */
    void startEditing(Runnable done) {
        pause();
        editing = true;
        editDone = done;
        selected = null;
        layoutControls(getWidth(), getHeight());
        invalidate();
    }

    private void releaseAll() {
        for (int i = 0; i < pointerControl.size(); ++i) {
            Control control = pointerControl.valueAt(i);
            if (control != null) up(control);
        }
        pointerControl.clear();
        for (Control control : controls) control.pointers = 0;
        slidePointer = -1;
        stickPointer = -1;
        input.setSteering(KeyInput.SRC_TOUCH, 0f);
        input.setSteering(KeyInput.SRC_TILT, 0f);
    }

    private void updateSensor() {
        boolean want = settings.steering == ControlSettings.STEER_TILT && mode == MODE_RACE && !gamepadMode && !editing;
        if (sensors == null) sensors = (SensorManager) getContext().getSystemService(Context.SENSOR_SERVICE);
        if (want && !sensorRegistered && sensors != null) {
            Sensor sensor = sensors.getDefaultSensor(Sensor.TYPE_GRAVITY);
            if (sensor == null) sensor = sensors.getDefaultSensor(Sensor.TYPE_ACCELEROMETER);
            if (sensor != null) sensorRegistered = sensors.registerListener(this, sensor, SensorManager.SENSOR_DELAY_GAME);
        } else if (!want && sensorRegistered) {
            sensors.unregisterListener(this);
            sensorRegistered = false;
            input.setSteering(KeyInput.SRC_TILT, 0f);
        }
    }

    /** Current roll in degrees, used by the settings dialog to calibrate the centre. */
    float currentTiltAngle() { return tiltAngle; }

    // ---- tilt --------------------------------------------------------------

    @Override public void onSensorChanged(SensorEvent event) {
        float ax = event.values[0], ay = event.values[1], az = event.values[2];
        // Roll around the screen normal, independent of how far the phone leans back.
        float angle = (float) Math.toDegrees(Math.atan2(ay, Math.sqrt(ax * ax + az * az)));
        int rotation = ((WindowManager) getContext().getSystemService(Context.WINDOW_SERVICE))
            .getDefaultDisplay().getRotation();
        if (rotation == Surface.ROTATION_270) angle = -angle;
        if (settings.tiltInvert) angle = -angle;
        tiltAngle = angle;

        boolean pedalHeld = gas.pointers > 0 || brake.pointers > 0 || handbrake.pointers > 0;
        boolean active = pedalHeld || SystemClock.uptimeMillis() - pedalReleasedAt < TILT_GRACE_MS;
        float value = active ? (angle - settings.tiltCenter) / Math.max(5, settings.tiltRange) : 0f;
        input.setSteering(KeyInput.SRC_TILT, value);
        invalidate();
    }

    @Override public void onAccuracyChanged(Sensor sensor, int accuracy) {}

    // ---- layout ----------------------------------------------------------

    @Override protected void onSizeChanged(int w, int h, int oldw, int oldh) {
        layoutControls(w, h);
    }

    private float dp(float value) { return value * density; }

    /** Places a circle by centre; mirrored for the left-handed layout. */
    private void circle(Control control, float cx, float cy, float diameter, int viewWidth) {
        if (settings.leftHanded) cx = viewWidth - cx;
        float r = diameter / 2f;
        control.base.set(cx - r, cy - r, cx + r, cy + r);
        control.visible = true;
    }

    private void layoutControls(int w, int h) {
        if (w == 0 || h == 0) return;
        for (Control control : controls) control.visible = false;
        float s = settings.size / 100f;
        float m = dp(18);
        float gap = dp(12);
        // The game's HUD fills the top band, so nothing is placed above this line.
        float top = Math.max(dp(66), h * 0.16f);

        float g = dp(42);
        circle(settingsButton, m + g / 2f, top + g / 2f, g, w);
        settingsButton.visible = !editing;
        if (!(gamepadMode && settings.hideWithGamepad) || editing) {
            if (mode == MODE_RACE) layoutRace(w, h, s, m, gap, top);
            else layoutMenu();
        }

        // Saved placements override the defaults.
        for (Control control : controls) {
            control.rect.set(control.base);
            ControlSettings.Placement p = settings.placements.get(control.id);
            if (p != null && control.editable()) {
                float hw = control.base.width() * p.scale / 2f, hh = control.base.height() * p.scale / 2f;
                float cx = p.centerX * w, cy = p.centerY * h;
                control.rect.set(cx - hw, cy - hh, cx + hw, cy + hh);
            }
        }
        float bw = dp(76), bh = dp(48), wide = dp(150), tg = dp(10);
        float x = (w - (2 * bw + 2 * wide + 3 * tg)) / 2f, y = h / 2f - bh / 2f;
        for (int i = 0; i < toolbar.length; ++i) {
            float width = i < 2 ? bw : wide;
            toolbar[i].set(x, y, x + width, y + bh);
            x += width + tg;
        }
    }

    private void layoutRace(int w, int h, float s, float m, float gap, float top) {
        boolean tilt = settings.steering == ControlSettings.STEER_TILT;

        // Pedal cluster, bottom right: big gas, brake beside it, handbrake above the brake.
        float gd = dp(128) * s, bd = dp(104) * s, hd = dp(72) * s;
        float gx = w - m - gd / 2f, gy = h - m - gd / 2f;
        circle(gas, gx, gy, gd, w);
        if (tilt) {
            // Both thumbs are free: brake mirrors gas on the left.
            circle(brake, m + gd / 2f, h - m - gd / 2f, gd, w);
            circle(handbrake, gx - gd / 2f - gap - hd / 2f, h - m - hd / 2f, hd, w);
        } else {
            float bx = gx - gd / 2f - gap - bd / 2f, by = h - m - bd / 2f;
            circle(brake, bx, by, bd, w);
            circle(handbrake, bx + bd * 0.1f, by - bd / 2f - gap - hd / 2f, hd, w);
        }
        if (settings.gearButtons) {
            float ed = dp(58) * s;
            circle(gearUp, gx, gy - gd / 2f - gap - ed / 2f, ed, w);
            circle(gearDown, gx, gy - gd / 2f - 2 * gap - ed * 1.5f, ed, w);
        }

        // Utilities: a compact row under the HUD, top right.
        float ud = dp(46);
        float uy = top + ud / 2f;
        circle(pause, w - m - ud / 2f, uy, ud, w);
        circle(camera, w - m - ud * 1.5f - gap, uy, ud, w);
        circle(horn, w - m - ud * 2.5f - 2 * gap, uy, ud, w);

        // Steering, bottom left.
        if (settings.steering == ControlSettings.STEER_STICK) {
            float sd = dp(156) * s;
            circle(stick, m + dp(10) + sd / 2f, h - m - sd / 2f, sd, w);
        } else if (settings.steering == ControlSettings.STEER_BUTTONS) {
            float sd = dp(112) * s;
            circle(left, m + sd / 2f, h - m - sd / 2f, sd, w);
            circle(right, m + sd * 1.5f + gap * 1.5f, h - m - sd / 2f, sd, w);
        } else if (settings.steering == ControlSettings.STEER_SLIDE) {
            float x = settings.leftHanded ? w * 0.52f : 0;
            slideZone.base.set(x, h * 0.35f, x + w * 0.48f, h);
            slideZone.visible = true;
        }
    }

    private void layoutMenu() {
        // Menus are driven by tapping them directly (touches reach the game as mouse
        // clicks) and Android's back gesture sends Escape, so only settings stays visible.
    }

    private void saveSelected() {
        if (selected == null || getWidth() == 0) return;
        float scale = selected.rect.width() / Math.max(1f, selected.base.width());
        settings.placements.put(selected.id, new ControlSettings.Placement(
            selected.rect.centerX() / getWidth(), selected.rect.centerY() / getHeight(), scale));
    }

    // ---- touch -----------------------------------------------------------

    private static boolean inCircle(RectF r, float x, float y, float margin) {
        float dx = x - r.centerX(), dy = y - r.centerY(), radius = r.width() / 2f + margin;
        return dx * dx + dy * dy <= radius * radius;
    }

    private Control hit(float x, float y, Control current) {
        // The held control gets a generous margin so a drifting thumb doesn't drop the gas.
        if (current != null && current.kind != KIND_SETTINGS && current.kind != KIND_SLIDE
                && inCircle(current.rect, x, y, dp(26))) return current;
        Control slide = null;
        Control nearest = null;
        float best = Float.MAX_VALUE;
        for (Control control : controls) {
            if (!control.visible) continue;
            if (control.kind == KIND_SLIDE) { if (control.rect.contains(x, y)) slide = control; continue; }
            // Slightly larger than drawn: thumbs are imprecise. The closest centre wins.
            if (!inCircle(control.rect, x, y, dp(10))) continue;
            float dx = x - control.rect.centerX(), dy = y - control.rect.centerY();
            float distance = (dx * dx + dy * dy) / (control.rect.width() * control.rect.width());
            if (distance < best) { best = distance; nearest = control; }
        }
        return nearest != null ? nearest : slide;
    }

    @Override public boolean onTouchEvent(MotionEvent event) {
        if (editing) return onEditTouch(event);
        int action = event.getActionMasked();
        int index = event.getActionIndex();
        switch (action) {
            case MotionEvent.ACTION_DOWN:
            case MotionEvent.ACTION_POINTER_DOWN: {
                int id = event.getPointerId(index);
                Control control = hit(event.getX(index), event.getY(index), null);
                if (control == null) return action != MotionEvent.ACTION_DOWN;  // fall through to SDL
                if (control.kind == KIND_SETTINGS) {
                    if (action == MotionEvent.ACTION_DOWN) openSettings.run();
                    return true;
                }
                if (control.kind == KIND_STICK) {
                    stickPointer = id;
                    stickX = event.getX(index); stickY = event.getY(index);
                }
                if (control.kind == KIND_SLIDE) {
                    slidePointer = id;
                    slideOriginX = slideX = event.getX(index);
                }
                pointerControl.put(id, control);
                down(control);
                break;
            }
            case MotionEvent.ACTION_MOVE:
                for (int i = 0; i < event.getPointerCount(); ++i) {
                    int id = event.getPointerId(i);
                    if (pointerControl.indexOfKey(id) < 0) continue;
                    Control current = pointerControl.get(id);
                    if (id == stickPointer) {
                        stickX = event.getX(i); stickY = event.getY(i);
                        updateStick();
                        continue;
                    }
                    if (id == slidePointer) {
                        slideX = event.getX(i);
                        updateSlide();
                        continue;
                    }
                    Control next = hit(event.getX(i), event.getY(i), current);
                    if (next != null && (next.kind == KIND_SLIDE || next.kind == KIND_SETTINGS || next.kind == KIND_STICK)) next = null;
                    if (next != current) {
                        if (current != null) up(current);
                        if (next != null) down(next);
                        pointerControl.put(id, next);
                    }
                }
                break;
            case MotionEvent.ACTION_UP:
            case MotionEvent.ACTION_POINTER_UP:
            case MotionEvent.ACTION_CANCEL: {
                if (action == MotionEvent.ACTION_CANCEL) { releaseAll(); break; }
                int id = event.getPointerId(index);
                Control control = pointerControl.get(id);
                pointerControl.remove(id);
                if (control != null) up(control);
                if (id == slidePointer) slidePointer = -1;
                if (id == stickPointer) stickPointer = -1;
                break;
            }
            default:
                break;
        }
        invalidate();
        return true;
    }

    private boolean onEditTouch(MotionEvent event) {
        int action = event.getActionMasked();
        int index = event.getActionIndex();
        float x = event.getX(index), y = event.getY(index);
        if (action == MotionEvent.ACTION_DOWN || action == MotionEvent.ACTION_POINTER_DOWN) {
            for (int i = 0; i < toolbar.length; ++i) {
                if (!toolbar[i].contains(x, y)) continue;
                onToolbar(i);
                return true;
            }
            Control control = hit(x, y, null);
            if (control != null && control.editable()) {
                selected = control;
                dragPointer = event.getPointerId(index);
                dragDx = x - control.rect.centerX();
                dragDy = y - control.rect.centerY();
                if (settings.haptics) performHapticFeedback(HapticFeedbackConstants.VIRTUAL_KEY);
            }
        } else if (action == MotionEvent.ACTION_MOVE && dragPointer >= 0 && selected != null) {
            int i = event.findPointerIndex(dragPointer);
            if (i >= 0) {
                float hw = selected.rect.width() / 2f, hh = selected.rect.height() / 2f;
                float cx = Math.max(hw, Math.min(getWidth() - hw, event.getX(i) - dragDx));
                float cy = Math.max(hh, Math.min(getHeight() - hh, event.getY(i) - dragDy));
                selected.rect.set(cx - hw, cy - hh, cx + hw, cy + hh);
            }
        } else if (action == MotionEvent.ACTION_UP || action == MotionEvent.ACTION_POINTER_UP
                || action == MotionEvent.ACTION_CANCEL) {
            if (event.getPointerId(index) == dragPointer || action == MotionEvent.ACTION_CANCEL) {
                saveSelected();
                dragPointer = -1;
            }
        }
        invalidate();
        return true;
    }

    private void onToolbar(int button) {
        switch (button) {
            case 0: case 1: {
                if (selected == null) break;
                float current = selected.rect.width() / Math.max(1f, selected.base.width());
                float scale = Math.max(0.5f, Math.min(2.5f, current + (button == 0 ? -0.1f : 0.1f)));
                float hw = selected.base.width() * scale / 2f, hh = selected.base.height() * scale / 2f;
                float cx = selected.rect.centerX(), cy = selected.rect.centerY();
                selected.rect.set(cx - hw, cy - hh, cx + hw, cy + hh);
                saveSelected();
                break;
            }
            case 2:
                // Only the layout being edited is reset.
                for (Control control : controls) if (control.visible) settings.placements.remove(control.id);
                selected = null;
                layoutControls(getWidth(), getHeight());
                break;
            default:
                editing = false;
                selected = null;
                settings.save();
                layoutControls(getWidth(), getHeight());
                if (editDone != null) editDone.run();
                break;
        }
        if (settings.haptics) performHapticFeedback(HapticFeedbackConstants.VIRTUAL_KEY);
        invalidate();
    }

    /** Horizontal deflection steers; the knob travels 70% of the base radius. */
    private void updateStick() {
        float travel = stick.rect.width() / 2f * 0.7f;
        input.setSteering(KeyInput.SRC_TOUCH, (stickX - stick.rect.centerX()) / travel);
    }

    private void updateSlide() {
        input.setSteering(KeyInput.SRC_TOUCH, (slideX - slideOriginX) / (dp(90) * settings.size / 100f));
    }

    private void down(Control control) {
        if (control.pointers++ > 0) return;
        if (settings.haptics) performHapticFeedback(HapticFeedbackConstants.VIRTUAL_KEY);
        switch (control.kind) {
            case KIND_KEY: input.press(control.key); break;
            case KIND_LEFT: input.setSteering(KeyInput.SRC_TOUCH, -1f); break;
            case KIND_RIGHT: input.setSteering(KeyInput.SRC_TOUCH, 1f); break;
            case KIND_SLIDE: updateSlide(); break;
            case KIND_STICK: updateStick(); break;
            default: break;
        }
    }

    private void up(Control control) {
        if (control.pointers == 0 || --control.pointers > 0) return;
        switch (control.kind) {
            case KIND_KEY: input.release(control.key); break;
            case KIND_LEFT:
            case KIND_RIGHT:
                // The other arrow may still be held by a second finger.
                Control other = control == left ? right : left;
                input.setSteering(KeyInput.SRC_TOUCH, other.pointers > 0 ? (other == left ? -1f : 1f) : 0f);
                break;
            case KIND_SLIDE:
            case KIND_STICK: input.setSteering(KeyInput.SRC_TOUCH, 0f); break;
            default: break;
        }
        if (control.pedal) pedalReleasedAt = SystemClock.uptimeMillis();
    }

    // ---- drawing ---------------------------------------------------------

    private static int withAlpha(int color, float alpha) {
        int a = Math.round(((color >>> 24) & 0xff) * Math.max(0f, Math.min(1f, alpha)));
        return (a << 24) | (color & 0x00ffffff);
    }

    @Override protected void onDraw(Canvas canvas) {
        float opacity = editing ? Math.max(0.75f, settings.opacity / 100f) : settings.opacity / 100f;
        if (editing) canvas.drawColor(0x88000000);
        for (Control control : controls) {
            if (!control.visible) continue;
            if (control.kind == KIND_SLIDE) drawSlide(canvas, control, opacity);
            else if (control.kind == KIND_STICK) drawStick(canvas, control, opacity);
            else drawControl(canvas, control, opacity);
        }
        if (settings.steering == ControlSettings.STEER_TILT && mode == MODE_RACE
                && !(gamepadMode && settings.hideWithGamepad) && !editing)
            drawTiltMeter(canvas, opacity);
        if (editing) drawEditor(canvas);
        if (fps >= 0) {
            text.setTextSize(dp(13));
            text.setColor(fps >= 55 ? 0xFF34C759 : fps >= 28 ? 0xFFFFD60A : 0xFFFF453A);
            canvas.drawText(fps + " FPS", getWidth() / 2f, dp(16), text);
        }
    }

    /** Frosted glass circle with a thin ring; pressed controls light up in their accent colour. */
    private void drawControl(Canvas canvas, Control control, float opacity) {
        boolean pressed = control.pointers > 0;
        RectF r = control.rect;
        float cx = r.centerX(), cy = r.centerY();
        float radius = r.width() / 2f * (pressed ? 0.94f : 1f);

        if (pressed) {
            fill.setColor(withAlpha(control.accent, 0.22f));
            canvas.drawCircle(cx, cy, radius + dp(8), fill);
        }
        fill.setColor(pressed ? withAlpha(control.accent, 0.55f + 0.3f * opacity) : withAlpha(0xFF101318, 0.45f * opacity + 0.05f));
        canvas.drawCircle(cx, cy, radius, fill);
        // Inner highlight gives a little depth without heavy gradients.
        fill.setColor(withAlpha(WHITE, (pressed ? 0.10f : 0.07f) * (0.5f + opacity)));
        canvas.drawCircle(cx, cy - radius * 0.06f, radius * 0.9f, fill);
        stroke.setStrokeWidth(dp(control.pedal ? 2.5f : 2f));
        stroke.setColor(pressed ? withAlpha(WHITE, 0.95f)
            : withAlpha(control.pedal ? control.accent : WHITE, 0.35f + 0.5f * opacity));
        canvas.drawCircle(cx, cy, radius, stroke);
        if (editing && control == selected) {
            stroke.setColor(0xFFFFD60A);
            stroke.setStrokeWidth(dp(3));
            canvas.drawCircle(cx, cy, radius + dp(5), stroke);
        }

        int color = withAlpha(WHITE, Math.min(1f, 0.55f + opacity * 0.6f));
        boolean captioned = !control.caption.isEmpty() && radius > dp(30);
        float iconSize = radius * (captioned ? 0.72f : 0.9f);
        float iconY = captioned ? cy - radius * 0.14f : cy;
        drawIcon(canvas, control.icon, cx, iconY, iconSize, color);
        if (captioned) {
            text.setTextSize(Math.min(dp(13), radius * 0.26f));
            text.setColor(color);
            canvas.drawText(control.caption, cx, cy + radius * 0.58f, text);
        }
    }

    private void drawIcon(Canvas canvas, int kind, float cx, float cy, float size, int color) {
        ink.setColor(color);
        float h = size / 2f;
        path.reset();
        switch (kind) {
            case ICON_LEFT: case ICON_RIGHT: case ICON_UP: case ICON_DOWN: {
                // Rounded triangle pointing in the given direction.
                float dx = kind == ICON_LEFT ? -1 : kind == ICON_RIGHT ? 1 : 0;
                float dy = kind == ICON_UP ? -1 : kind == ICON_DOWN ? 1 : 0;
                float t = h * 0.62f;
                ink.setStyle(Paint.Style.FILL_AND_STROKE);
                ink.setStrokeWidth(h * 0.18f);
                path.moveTo(cx + dx * t, cy + dy * t);
                path.lineTo(cx - dx * t * 0.6f - dy * t * 0.85f, cy - dy * t * 0.6f - dx * t * 0.85f);
                path.lineTo(cx - dx * t * 0.6f + dy * t * 0.85f, cy - dy * t * 0.6f + dx * t * 0.85f);
                path.close();
                canvas.drawPath(path, ink);
                break;
            }
            case ICON_GAS: case ICON_BRAKE: {
                // Pedal: a rounded plate with grip lines; the gas plate is taller.
                boolean isGas = kind == ICON_GAS;
                float pw = h * (isGas ? 0.62f : 0.9f), ph = h * (isGas ? 1.0f : 0.68f);
                ink.setStyle(Paint.Style.STROKE);
                ink.setStrokeWidth(h * 0.14f);
                scratch.set(cx - pw / 2f, cy - ph / 2f, cx + pw / 2f, cy + ph / 2f);
                canvas.drawRoundRect(scratch, h * 0.16f, h * 0.16f, ink);
                ink.setStrokeWidth(h * 0.1f);
                int lines = isGas ? 3 : 2;
                for (int i = 1; i <= lines; ++i) {
                    float y = scratch.top + ph * i / (lines + 1f);
                    canvas.drawLine(scratch.left + pw * 0.28f, y, scratch.right - pw * 0.28f, y, ink);
                }
                break;
            }
            case ICON_HANDBRAKE: {
                // (P) in a ring, the dashboard parking-brake symbol.
                ink.setStyle(Paint.Style.STROKE);
                ink.setStrokeWidth(h * 0.12f);
                canvas.drawCircle(cx, cy, h * 0.55f, ink);
                canvas.drawArc(cx - h * 0.85f, cy - h * 0.85f, cx + h * 0.85f, cy + h * 0.85f, 130, 100, false, ink);
                canvas.drawArc(cx - h * 0.85f, cy - h * 0.85f, cx + h * 0.85f, cy + h * 0.85f, -50, 100, false, ink);
                text.setTextSize(h * 0.75f);
                text.setColor(color);
                canvas.drawText("P", cx, cy - (text.descent() + text.ascent()) / 2f, text);
                break;
            }
            case ICON_PAUSE: {
                ink.setStyle(Paint.Style.FILL);
                float bw = h * 0.26f, bh = h * 0.95f;
                scratch.set(cx - h * 0.42f, cy - bh / 2f, cx - h * 0.42f + bw, cy + bh / 2f);
                canvas.drawRoundRect(scratch, bw / 3f, bw / 3f, ink);
                scratch.offset(h * 0.84f - bw, 0);
                canvas.drawRoundRect(scratch, bw / 3f, bw / 3f, ink);
                break;
            }
            case ICON_CAMERA: {
                ink.setStyle(Paint.Style.STROKE);
                ink.setStrokeWidth(h * 0.13f);
                scratch.set(cx - h * 0.8f, cy - h * 0.45f, cx + h * 0.8f, cy + h * 0.6f);
                canvas.drawRoundRect(scratch, h * 0.2f, h * 0.2f, ink);
                canvas.drawCircle(cx, cy + h * 0.07f, h * 0.3f, ink);
                canvas.drawLine(cx - h * 0.3f, cy - h * 0.62f, cx + h * 0.3f, cy - h * 0.62f, ink);
                break;
            }
            case ICON_HORN: {
                // Speaker cone with two sound waves.
                ink.setStyle(Paint.Style.FILL);
                path.moveTo(cx - h * 0.85f, cy - h * 0.25f);
                path.lineTo(cx - h * 0.45f, cy - h * 0.25f);
                path.lineTo(cx, cy - h * 0.65f);
                path.lineTo(cx, cy + h * 0.65f);
                path.lineTo(cx - h * 0.45f, cy + h * 0.25f);
                path.lineTo(cx - h * 0.85f, cy + h * 0.25f);
                path.close();
                canvas.drawPath(path, ink);
                ink.setStyle(Paint.Style.STROKE);
                ink.setStrokeWidth(h * 0.12f);
                canvas.drawArc(cx - h * 0.35f, cy - h * 0.45f, cx + h * 0.45f, cy + h * 0.45f, -50, 100, false, ink);
                canvas.drawArc(cx - h * 0.55f, cy - h * 0.8f, cx + h * 0.85f, cy + h * 0.8f, -50, 100, false, ink);
                break;
            }
            case ICON_CHECK: {
                ink.setStyle(Paint.Style.STROKE);
                ink.setStrokeWidth(h * 0.2f);
                path.moveTo(cx - h * 0.6f, cy + h * 0.02f);
                path.lineTo(cx - h * 0.15f, cy + h * 0.45f);
                path.lineTo(cx + h * 0.65f, cy - h * 0.45f);
                canvas.drawPath(path, ink);
                break;
            }
            case ICON_BACK: {
                // U-turn arrow.
                ink.setStyle(Paint.Style.STROKE);
                ink.setStrokeWidth(h * 0.17f);
                path.moveTo(cx - h * 0.55f, cy - h * 0.25f);
                path.lineTo(cx + h * 0.2f, cy - h * 0.25f);
                path.quadTo(cx + h * 0.7f, cy - h * 0.25f, cx + h * 0.7f, cy + h * 0.15f);
                path.quadTo(cx + h * 0.7f, cy + h * 0.55f, cx + h * 0.2f, cy + h * 0.55f);
                path.lineTo(cx - h * 0.25f, cy + h * 0.55f);
                path.moveTo(cx - h * 0.25f, cy - h * 0.6f);
                path.lineTo(cx - h * 0.6f, cy - h * 0.25f);
                path.lineTo(cx - h * 0.25f, cy + h * 0.1f);
                canvas.drawPath(path, ink);
                break;
            }
            case ICON_PLUS: case ICON_MINUS: {
                ink.setStyle(Paint.Style.STROKE);
                ink.setStrokeWidth(h * 0.18f);
                canvas.drawLine(cx - h * 0.5f, cy, cx + h * 0.5f, cy, ink);
                if (kind == ICON_PLUS) canvas.drawLine(cx, cy - h * 0.5f, cx, cy + h * 0.5f, ink);
                break;
            }
            case ICON_GEAR: {
                ink.setStyle(Paint.Style.STROKE);
                ink.setStrokeWidth(h * 0.15f);
                canvas.drawCircle(cx, cy, h * 0.3f, ink);
                ink.setStrokeWidth(h * 0.2f);
                for (int i = 0; i < 8; ++i) {
                    double a = i * Math.PI / 4;
                    float c = (float) Math.cos(a), sn = (float) Math.sin(a);
                    canvas.drawLine(cx + c * h * 0.5f, cy + sn * h * 0.5f, cx + c * h * 0.72f, cy + sn * h * 0.72f, ink);
                }
                break;
            }
            default:
                break;
        }
    }

    private void drawStick(Canvas canvas, Control control, float opacity) {
        RectF r = control.rect;
        float cx = r.centerX(), cy = r.centerY(), radius = r.width() / 2f;
        boolean active = stickPointer >= 0 && !editing;
        // Base: glass disc with a horizontal guide and end ticks.
        fill.setColor(withAlpha(0xFF101318, 0.4f * opacity + 0.05f));
        canvas.drawCircle(cx, cy, radius, fill);
        stroke.setStrokeWidth(dp(2));
        stroke.setColor(withAlpha(active ? control.accent : WHITE, 0.3f + 0.5f * opacity));
        canvas.drawCircle(cx, cy, radius, stroke);
        float travel = radius * 0.7f;
        stroke.setColor(withAlpha(WHITE, 0.15f + 0.3f * opacity));
        canvas.drawLine(cx - travel, cy, cx + travel, cy, stroke);
        drawIcon(canvas, ICON_LEFT, cx - radius * 0.82f, cy, radius * 0.22f, withAlpha(WHITE, 0.3f + 0.5f * opacity));
        drawIcon(canvas, ICON_RIGHT, cx + radius * 0.82f, cy, radius * 0.22f, withAlpha(WHITE, 0.3f + 0.5f * opacity));
        // Knob follows the finger, clamped to the travel circle.
        float kx = cx, ky = cy;
        if (active) {
            float dx = stickX - cx, dy = stickY - cy;
            float len = (float) Math.sqrt(dx * dx + dy * dy);
            float k = len > travel ? travel / len : 1f;
            kx = cx + dx * k; ky = cy + dy * k * 0.5f;
        }
        float kr = radius * 0.42f;
        fill.setColor(active ? withAlpha(control.accent, 0.85f) : withAlpha(0xFF2A2F3A, 0.55f + 0.35f * opacity));
        canvas.drawCircle(kx, ky, kr, fill);
        fill.setColor(withAlpha(WHITE, 0.12f));
        canvas.drawCircle(kx, ky - kr * 0.08f, kr * 0.85f, fill);
        stroke.setColor(withAlpha(WHITE, 0.5f + 0.4f * opacity));
        canvas.drawCircle(kx, ky, kr, stroke);
        if (editing && control == selected) {
            stroke.setColor(0xFFFFD60A);
            stroke.setStrokeWidth(dp(3));
            canvas.drawCircle(cx, cy, radius + dp(5), stroke);
        }
    }

    private void drawSlide(Canvas canvas, Control zone, float opacity) {
        float s = settings.size / 100f;
        float trackW = dp(200) * s;
        float cy = zone.rect.bottom - dp(80) * s;
        float cx = slidePointer >= 0 ? slideOriginX : zone.rect.left + dp(40) + trackW / 2f;
        if (settings.leftHanded && slidePointer < 0) cx = zone.rect.right - dp(40) - trackW / 2f;
        scratch.set(cx - trackW / 2, cy - dp(6), cx + trackW / 2, cy + dp(6));
        fill.setColor(withAlpha(0xFF101318, 0.45f * opacity + 0.05f));
        canvas.drawRoundRect(scratch, dp(6), dp(6), fill);
        float value = input.getSteering(KeyInput.SRC_TOUCH);
        float knobX = cx + value * trackW / 2;
        fill.setColor(withAlpha(zone.accent, 0.5f + 0.4f * opacity));
        scratch.set(Math.min(cx, knobX), cy - dp(6), Math.max(cx, knobX), cy + dp(6));
        canvas.drawRoundRect(scratch, dp(6), dp(6), fill);
        boolean active = slidePointer >= 0;
        float kr = dp(30) * s;
        fill.setColor(active ? withAlpha(zone.accent, 0.85f) : withAlpha(0xFF101318, 0.45f * opacity + 0.05f));
        canvas.drawCircle(knobX, cy, kr, fill);
        stroke.setStrokeWidth(dp(2));
        stroke.setColor(withAlpha(WHITE, 0.35f + 0.5f * opacity));
        canvas.drawCircle(knobX, cy, kr, stroke);
        drawIcon(canvas, ICON_LEFT, knobX - kr * 0.38f, cy, kr * 0.55f, withAlpha(WHITE, 0.6f + 0.4f * opacity));
        drawIcon(canvas, ICON_RIGHT, knobX + kr * 0.38f, cy, kr * 0.55f, withAlpha(WHITE, 0.6f + 0.4f * opacity));
    }

    private void drawTiltMeter(Canvas canvas, float opacity) {
        float w = dp(160), cx = getWidth() / 2f, cy = getHeight() - dp(22);
        float value = input.getSteering(KeyInput.SRC_TILT);
        scratch.set(cx - w / 2, cy - dp(3), cx + w / 2, cy + dp(3));
        fill.setColor(withAlpha(0xFF101318, 0.45f * opacity + 0.05f));
        canvas.drawRoundRect(scratch, dp(3), dp(3), fill);
        fill.setColor(withAlpha(0xFF0A84FF, 0.6f + 0.4f * opacity));
        canvas.drawCircle(cx + value * w / 2, cy, dp(7), fill);
    }

    private void drawEditor(Canvas canvas) {
        text.setColor(WHITE);
        text.setTextSize(dp(15));
        String hint = selected == null ? "Arrastra un botón para moverlo"
            : "Usa − / + para cambiar el tamaño del botón elegido";
        canvas.drawText(hint, getWidth() / 2f, toolbar[0].top - dp(16), text);
        for (int i = 0; i < toolbar.length; ++i) {
            RectF r = toolbar[i];
            fill.setColor(i == 3 ? 0xFF34C759 : 0xEE1C1F26);
            canvas.drawRoundRect(r, r.height() / 2f, r.height() / 2f, fill);
            stroke.setStrokeWidth(dp(1.5f));
            stroke.setColor(0x99FFFFFF);
            canvas.drawRoundRect(r, r.height() / 2f, r.height() / 2f, stroke);
            text.setTextSize(dp(i < 2 ? 24 : 14));
            canvas.drawText(TOOLBAR_LABELS[i], r.centerX(), r.centerY() - (text.descent() + text.ascent()) / 2f, text);
        }
    }
}
