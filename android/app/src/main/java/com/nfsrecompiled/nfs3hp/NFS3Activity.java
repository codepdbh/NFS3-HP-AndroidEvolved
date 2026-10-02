package com.nfsrecompiled.nfs3hp;

import org.libsdl.app.SDLActivity;
import android.app.AlertDialog;
import android.content.pm.ActivityInfo;
import android.graphics.Typeface;
import android.hardware.input.InputManager;
import android.os.Bundle;
import android.os.Environment;
import android.view.InputDevice;
import android.view.KeyEvent;
import android.view.MotionEvent;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.CheckBox;
import android.widget.LinearLayout;
import android.widget.RadioButton;
import android.widget.RadioGroup;
import android.widget.ScrollView;
import android.widget.SeekBar;
import android.widget.TextView;
import android.widget.Toast;

/** SDL owns surface, audio and native-thread lifecycle; this adds touch and gamepad input. */
public final class NFS3Activity extends SDLActivity implements InputManager.InputDeviceListener {
    private static native void nativeSetDisplayAspect(float aspect);
    private static native int nativeGetFrameTriangles();
    private static native int nativeGetRenderWidth();
    private static native int nativeGetGameState();

    private static final long RACE_AFTER_MS = 600, MENU_AFTER_MS = 1200, POLL_MS = 200;

    private final KeyInput input = new KeyInput();
    private ControlSettings settings;
    private TouchControlsView controls;
    private InputManager inputManager;
    private AlertDialog dialog;
    private final android.os.Handler handler = new android.os.Handler(android.os.Looper.getMainLooper());
    private long candidateSince;
    private int candidateMode = -1;
    private final Runnable detectMode = new Runnable() {
        @Override public void run() {
            updateLayoutMode();
            handler.postDelayed(this, POLL_MS);
        }
    };

    // Gamepad state that arrives as motion events and must be turned into key edges.
    private boolean padGas, padBrake, padUp, padDown;
    private float padDpadSteer, padStickSteer;

    @Override protected String[] getLibraries() { return new String[] { "SDL2", "nfs3hp" }; }
    @Override protected String[] getArguments() {
        return new String[] { new java.io.File(Environment.getExternalStorageDirectory(), "nfs3hpandroidevolved").getAbsolutePath() };
    }

    // SDL can request an orientation again when the guest creates a new window.
    @Override public void setOrientationBis(int w, int h, boolean resizable, String hint) {
        setRequestedOrientation(ActivityInfo.SCREEN_ORIENTATION_SENSOR_LANDSCAPE);
    }

    @Override protected void onCreate(Bundle state) {
        super.onCreate(state);
        setRequestedOrientation(ActivityInfo.SCREEN_ORIENTATION_SENSOR_LANDSCAPE);
        if (mLayout == null) return;
        settings = new ControlSettings(this);
        nativeSetDisplayAspect(settings.displayAspect());
        controls = new TouchControlsView(this, settings, input, this::showSettings);
        mLayout.addView(controls, new ViewGroup.LayoutParams(ViewGroup.LayoutParams.MATCH_PARENT, ViewGroup.LayoutParams.MATCH_PARENT));
        inputManager = (InputManager) getSystemService(INPUT_SERVICE);
        if (mSurface != null && android.os.Build.VERSION.SDK_INT >= 30) {
            // Ask for a steady 60 Hz: variable-refresh panels otherwise drop the
            // rate when the screen isn't touched, halving the game's frame rate.
            mSurface.getHolder().addCallback(new android.view.SurfaceHolder.Callback() {
                @Override public void surfaceCreated(android.view.SurfaceHolder holder) { pinFrameRate(holder); }
                @Override public void surfaceChanged(android.view.SurfaceHolder holder, int f, int w, int h) { pinFrameRate(holder); }
                @Override public void surfaceDestroyed(android.view.SurfaceHolder holder) {}
            });
            pinFrameRate(mSurface.getHolder());
        }
    }

    private static void pinFrameRate(android.view.SurfaceHolder holder) {
        android.view.Surface surface = holder.getSurface();
        if (surface == null || !surface.isValid() || android.os.Build.VERSION.SDK_INT < 30) return;
        try {
            surface.setFrameRate(60f, android.view.Surface.FRAME_RATE_COMPATIBILITY_FIXED_SOURCE);
        } catch (RuntimeException ignored) {
        }
    }

    @Override protected void onResume() {
        super.onResume();
        if (controls == null) return;
        inputManager.registerInputDeviceListener(this, null);
        controls.setGamepadMode(gamepadName() != null);
        controls.resume();
        handler.post(detectMode);
    }

    /** Picks the menu or race layout from what the game is drawing, unless the player fixed one. */
    private long lastDiagnostic;

    private void updateLayoutMode() {
        long uptime = android.os.SystemClock.uptimeMillis();
        if (uptime - lastDiagnostic > 5000) {
            lastDiagnostic = uptime;
            android.util.Log.i("NFS3/INPUT", "state=" + nativeGetGameState() + " width=" + nativeGetRenderWidth()
                + " triangles=" + nativeGetFrameTriangles() + " mode=" + controls.getMode()
                + " layoutSetting=" + settings.layout + " gamepad=" + controls.isGamepadMode()
                + " editing=" + controls.isEditing());
        }
        if (settings.layout != ControlSettings.LAYOUT_AUTO) {
            if (candidateMode != -2) {
                android.util.Log.i("NFS3/INPUT", "Touch layout fixed by settings: " + settings.layout);
                candidateMode = -2;
            }
            controls.setMode(settings.layout == ControlSettings.LAYOUT_RACE ? TouchControlsView.MODE_RACE : TouchControlsView.MODE_MENU);
            return;
        }
        int triangles = nativeGetFrameTriangles();
        int width = nativeGetRenderWidth();
        int current = controls.getMode();
        // The game state comes from the files the game loads (track data starts
        // a race, a front-end menu ends it); the Modern Patch races at 640x480,
        // so resolution alone cannot tell; the menus draw as many triangles as a race.
        boolean race = nativeGetGameState() == 1 || width > 640;
        int wanted = race ? TouchControlsView.MODE_RACE : TouchControlsView.MODE_MENU;
        long now = android.os.SystemClock.uptimeMillis();
        if (wanted == current) { candidateMode = -1; return; }
        if (wanted != candidateMode) { candidateMode = wanted; candidateSince = now; return; }
        long wait = wanted == TouchControlsView.MODE_RACE ? RACE_AFTER_MS : MENU_AFTER_MS;
        if (now - candidateSince >= wait) {
            android.util.Log.i("NFS3/INPUT", "Layout " + (wanted == TouchControlsView.MODE_RACE ? "race" : "menu") + " (state " + nativeGetGameState() + ", " + width + " px, " + triangles + " triangles)");
            controls.setMode(wanted);
            candidateMode = -1;
        }
    }

    @Override protected void onPause() {
        handler.removeCallbacks(detectMode);
        // A finger may still be down when Android backgrounds the activity.
        if (controls != null) {
            controls.pause();
            inputManager.unregisterInputDeviceListener(this);
        }
        releasePad();
        input.stop();
        super.onPause();
    }

    // ---- settings ----------------------------------------------------------

    private int dp(int value) { return Math.round(value * getResources().getDisplayMetrics().density); }

    private void showSettings() {
        if (dialog != null && dialog.isShowing()) return;
        controls.pause();
        releasePad();
        LinearLayout root = new LinearLayout(this);
        root.setOrientation(LinearLayout.VERTICAL);
        root.setPadding(dp(22), dp(4), dp(22), dp(8));

        section(root, "Pantalla");
        RadioGroup screen = radios(root, new String[] { "Original 4:3", "Panorámica 16:9", "Completa" }, settings.screen);

        section(root, "Controles táctiles");
        RadioGroup layout = radios(root, new String[] { "Solo en carrera", "Ocultos", "Siempre visibles" }, settings.layout);
        TextView layoutInfo = new TextView(this);
        layoutInfo.setText("En los menús toca las opciones directamente; el gesto Atrás de Android equivale a Esc.");
        layoutInfo.setTextSize(12);
        root.addView(layoutInfo);

        section(root, "Dirección");
        RadioGroup steering = radios(root, new String[] { "Joystick", "Botones", "Deslizar", "Inclinación" }, settings.steering);
        SeekBar curve = slider(root, "Precisión en el centro (curva)", 100, 250, settings.steerCurve, "%");
        SeekBar deadZone = slider(root, "Zona muerta", 0, 30, settings.deadZone, "%");
        SeekBar period = slider(root, "Ciclo de giro parcial (menor = más suave)", 70, 250, settings.pwmPeriod, " ms");
        SeekBar tiltRange = slider(root, "Inclinación para giro máximo", 10, 45, settings.tiltRange, "°");
        Button calibrate = new Button(this);
        calibrate.setText(String.format("Calibrar centro de inclinación (actual: %.1f°)", settings.tiltCenter));
        calibrate.setOnClickListener(v -> {
            settings.tiltCenter = controls.currentTiltAngle();
            calibrate.setText(String.format("Centro calibrado: %.1f°", settings.tiltCenter));
        });
        root.addView(calibrate);
        CheckBox tiltInvert = check(root, "Invertir inclinación", settings.tiltInvert);

        section(root, "Aspecto de los botones");
        SeekBar opacity = slider(root, "Opacidad", 15, 100, settings.opacity, "%");
        SeekBar size = slider(root, "Tamaño", 60, 160, settings.size, "%");
        CheckBox haptics = check(root, "Vibración al pulsar", settings.haptics);
        CheckBox leftHanded = check(root, "Modo zurdo (pedales a la izquierda)", settings.leftHanded);
        CheckBox gears = check(root, "Botones de cambio manual (A / Z)", settings.gearButtons);
        Button edit = new Button(this);
        edit.setText("Mover y redimensionar botones (disposición actual)…");
        root.addView(edit);

        section(root, "Mando físico");
        CheckBox analog = check(root, "Gatillos progresivos (acelerar a medias)", settings.analogTriggers);
        CheckBox hidePad = check(root, "Ocultar controles táctiles con mando conectado", settings.hideWithGamepad);
        TextView padInfo = new TextView(this);
        String pad = gamepadName();
        padInfo.setText((pad != null ? "Conectado: " + pad + "\n" : "Ningún mando conectado.\n")
            + "RT gas · LT freno · stick/cruceta dirección · A OK · B volver · X freno de mano\n"
            + "Y cámara · LB/RB marcha −/+ · Start pausa · Select bocina");
        padInfo.setTextSize(12);
        root.addView(padInfo);

        Runnable store = () -> {
            settings.screen = screen.getCheckedRadioButtonId() - 1000;
            settings.layout = layout.getCheckedRadioButtonId() - 1000;
            settings.steering = steering.getCheckedRadioButtonId() - 1000;
            settings.steerCurve = curve.getProgress() + 100;
            settings.deadZone = deadZone.getProgress();
            settings.pwmPeriod = period.getProgress() + 70;
            settings.tiltRange = tiltRange.getProgress() + 10;
            settings.tiltInvert = tiltInvert.isChecked();
            settings.opacity = opacity.getProgress() + 15;
            settings.size = size.getProgress() + 60;
            settings.haptics = haptics.isChecked();
            settings.leftHanded = leftHanded.isChecked();
            settings.gearButtons = gears.isChecked();
            settings.analogTriggers = analog.isChecked();
            settings.hideWithGamepad = hidePad.isChecked();
            settings.save();
            nativeSetDisplayAspect(settings.displayAspect());
        };

        ScrollView scroll = new ScrollView(this);
        scroll.addView(root);
        dialog = new AlertDialog.Builder(this)
            .setTitle("Ajustes")
            .setView(scroll)
            .setPositiveButton("Guardar", (d, w) -> store.run())
            .setNegativeButton("Cancelar", null)
            .setOnDismissListener(d -> {
                if (controls.isEditing()) return;
                controls.applySettings();
                controls.resume();
            })
            .create();
        edit.setOnClickListener(v -> {
            store.run();
            controls.applySettings();
            controls.startEditing(() -> { controls.applySettings(); controls.resume(); });
            dialog.dismiss();
        });
        dialog.show();
    }

    private void section(LinearLayout root, String title) {
        TextView view = new TextView(this);
        view.setText(title.toUpperCase());
        view.setTextSize(13);
        view.setTypeface(Typeface.DEFAULT_BOLD);
        view.setTextColor(0xFFFFA000);
        view.setPadding(0, dp(16), 0, dp(2));
        root.addView(view);
    }

    private RadioGroup radios(LinearLayout root, String[] options, int checked) {
        RadioGroup group = new RadioGroup(this);
        group.setOrientation(RadioGroup.HORIZONTAL);
        for (int i = 0; i < options.length; ++i) {
            RadioButton option = new RadioButton(this);
            option.setText(options[i]); option.setId(1000 + i);
            option.setPadding(0, 0, dp(14), 0);
            group.addView(option);
        }
        group.check(1000 + checked);
        root.addView(group);
        return group;
    }

    private SeekBar slider(LinearLayout root, String name, int min, int max, int value, String unit) {
        TextView title = new TextView(this);
        title.setText(name + ": " + value + unit);
        title.setPadding(0, dp(8), 0, 0);
        root.addView(title);
        SeekBar bar = new SeekBar(this);
        bar.setMax(max - min);
        bar.setProgress(Math.max(0, Math.min(max - min, value - min)));
        bar.setOnSeekBarChangeListener(new SeekBar.OnSeekBarChangeListener() {
            @Override public void onProgressChanged(SeekBar s, int progress, boolean user) { title.setText(name + ": " + (progress + min) + unit); }
            @Override public void onStartTrackingTouch(SeekBar s) {}
            @Override public void onStopTrackingTouch(SeekBar s) {}
        });
        root.addView(bar);
        return bar;
    }

    private CheckBox check(LinearLayout root, String name, boolean value) {
        CheckBox box = new CheckBox(this);
        box.setText(name);
        box.setChecked(value);
        root.addView(box);
        return box;
    }

    // ---- gamepad -----------------------------------------------------------

    private static boolean isGamepad(int source) {
        return (source & InputDevice.SOURCE_GAMEPAD) == InputDevice.SOURCE_GAMEPAD
            || (source & InputDevice.SOURCE_JOYSTICK) == InputDevice.SOURCE_JOYSTICK;
    }

    /** Name of the first physical gamepad, or null. */
    private static String gamepadName() {
        for (int id : InputDevice.getDeviceIds()) {
            InputDevice device = InputDevice.getDevice(id);
            if (device != null && !device.isVirtual() && isGamepad(device.getSources())) return device.getName();
        }
        return null;
    }

    @Override public void onInputDeviceAdded(int id) {
        InputDevice device = InputDevice.getDevice(id);
        if (device != null && !device.isVirtual() && isGamepad(device.getSources()))
            Toast.makeText(this, "Mando conectado: " + device.getName(), Toast.LENGTH_SHORT).show();
        if (controls != null) controls.setGamepadMode(gamepadName() != null);
    }
    @Override public void onInputDeviceRemoved(int id) {
        releasePad();
        if (controls != null) controls.setGamepadMode(gamepadName() != null);
    }
    @Override public void onInputDeviceChanged(int id) {}

    /**
     * Gamepads are translated to the keyboard layout the game already uses,
     * which works without configuring a joystick inside NFS3.
     */
    private static int padKey(int keyCode) {
        switch (keyCode) {
            case KeyEvent.KEYCODE_BUTTON_A: case KeyEvent.KEYCODE_DPAD_CENTER: return KeyEvent.KEYCODE_ENTER;
            case KeyEvent.KEYCODE_BUTTON_B: case KeyEvent.KEYCODE_BACK: return KeyEvent.KEYCODE_ESCAPE;
            case KeyEvent.KEYCODE_BUTTON_X: return KeyEvent.KEYCODE_SPACE;
            case KeyEvent.KEYCODE_BUTTON_Y: return KeyEvent.KEYCODE_C;
            case KeyEvent.KEYCODE_BUTTON_L1: return KeyEvent.KEYCODE_Z;
            case KeyEvent.KEYCODE_BUTTON_R1: return KeyEvent.KEYCODE_A;
            case KeyEvent.KEYCODE_BUTTON_START: return KeyEvent.KEYCODE_ESCAPE;
            case KeyEvent.KEYCODE_BUTTON_SELECT: case KeyEvent.KEYCODE_BUTTON_THUMBL: return KeyEvent.KEYCODE_H;
            case KeyEvent.KEYCODE_BUTTON_R2: case KeyEvent.KEYCODE_DPAD_UP: return KeyEvent.KEYCODE_DPAD_UP;
            case KeyEvent.KEYCODE_BUTTON_L2: case KeyEvent.KEYCODE_DPAD_DOWN: return KeyEvent.KEYCODE_DPAD_DOWN;
            default: return 0;
        }
    }

    @Override public boolean dispatchKeyEvent(KeyEvent event) {
        if (controls != null && event.getKeyCode() == KeyEvent.KEYCODE_BACK && !isGamepad(event.getSource())) {
            // Android's back gesture/button acts as the game's Escape (back in menus, pause in a race).
            if (event.getRepeatCount() == 0) {
                if (event.getAction() == KeyEvent.ACTION_DOWN) input.press(KeyEvent.KEYCODE_ESCAPE);
                else if (event.getAction() == KeyEvent.ACTION_UP) input.release(KeyEvent.KEYCODE_ESCAPE);
            }
            return true;
        }
        if (controls == null || !isGamepad(event.getSource())) return super.dispatchKeyEvent(event);
        int code = event.getKeyCode();
        boolean down = event.getAction() == KeyEvent.ACTION_DOWN;
        if (code == KeyEvent.KEYCODE_DPAD_LEFT || code == KeyEvent.KEYCODE_DPAD_RIGHT) {
            if (event.getRepeatCount() == 0) {
                padDpadSteer = !down ? 0f : code == KeyEvent.KEYCODE_DPAD_LEFT ? -1f : 1f;
                updatePadSteering();
            }
            return true;
        }
        int key = padKey(code);
        if (key == 0) return super.dispatchKeyEvent(event);
        if (event.getRepeatCount() == 0) {
            if (event.getAction() == KeyEvent.ACTION_DOWN) input.press(key);
            else if (event.getAction() == KeyEvent.ACTION_UP) input.release(key);
        }
        controls.setGamepadMode(true);
        return true;
    }

    @Override public boolean dispatchGenericMotionEvent(MotionEvent event) {
        if (controls == null || !isGamepad(event.getSource()) || event.getActionMasked() != MotionEvent.ACTION_MOVE)
            return super.dispatchGenericMotionEvent(event);
        padStickSteer = event.getAxisValue(MotionEvent.AXIS_X);
        float hatX = event.getAxisValue(MotionEvent.AXIS_HAT_X);
        float hatY = event.getAxisValue(MotionEvent.AXIS_HAT_Y);
        padDpadSteer = Math.abs(hatX) > 0.5f ? Math.signum(hatX) : 0f;
        updatePadSteering();

        float gas = Math.max(event.getAxisValue(MotionEvent.AXIS_RTRIGGER), event.getAxisValue(MotionEvent.AXIS_GAS));
        float brake = Math.max(event.getAxisValue(MotionEvent.AXIS_LTRIGGER), event.getAxisValue(MotionEvent.AXIS_BRAKE));
        if (settings.analogTriggers) {
            // Trigger pressure becomes partial throttle; the stronger trigger wins.
            gas = gas < 0.06f ? 0f : gas;
            brake = brake < 0.06f ? 0f : brake;
            input.setThrottle(KeyInput.SRC_PAD, brake > gas ? -brake : gas);
        } else {
            padGas = edge(padGas, gas > 0.3f, KeyEvent.KEYCODE_DPAD_UP);
            padBrake = edge(padBrake, brake > 0.3f, KeyEvent.KEYCODE_DPAD_DOWN);
        }
        padUp = edge(padUp, hatY < -0.5f, KeyEvent.KEYCODE_DPAD_UP);
        padDown = edge(padDown, hatY > 0.5f, KeyEvent.KEYCODE_DPAD_DOWN);
        controls.setGamepadMode(true);
        return true;
    }

    private boolean edge(boolean was, boolean now, int key) {
        if (now && !was) input.press(key);
        else if (!now && was) input.release(key);
        return now;
    }

    private void updatePadSteering() {
        input.setSteering(KeyInput.SRC_PAD, padDpadSteer != 0f ? padDpadSteer : padStickSteer);
    }

    private void releasePad() {
        padGas = edge(padGas, false, KeyEvent.KEYCODE_DPAD_UP);
        padBrake = edge(padBrake, false, KeyEvent.KEYCODE_DPAD_DOWN);
        padUp = edge(padUp, false, KeyEvent.KEYCODE_DPAD_UP);
        padDown = edge(padDown, false, KeyEvent.KEYCODE_DPAD_DOWN);
        padDpadSteer = padStickSteer = 0f;
        input.setSteering(KeyInput.SRC_PAD, 0f);
        input.setThrottle(KeyInput.SRC_PAD, 0f);
    }
}
