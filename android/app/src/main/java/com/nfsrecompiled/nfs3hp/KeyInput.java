package com.nfsrecompiled.nfs3hp;

import android.os.Handler;
import android.os.Looper;
import android.os.SystemClock;
import android.util.SparseIntArray;
import android.view.KeyEvent;
import org.libsdl.app.SDLActivity;

/**
 * Sends keys to SDL on behalf of every input source (touch overlay, tilt, gamepad).
 *
 * Presses are reference counted so two sources holding the same key do not
 * release it for each other. The game only understands digital keys, so analog
 * inputs (steering, trigger pressure) drive pulse-width-modulated channels: the
 * further the stick or trigger, the longer the key stays down in each period.
 * NFS3 ramps keyboard steering and throttle internally, so this reads as partial input.
 */
final class KeyInput {
    static final int SRC_TOUCH = 0, SRC_TILT = 1, SRC_PAD = 2;

    private static final float FULL = 0.94f;
    private static final long TICK_MS = 8;

    /** One analog axis mapped to a negative and a positive key. */
    private final class Channel {
        final int negativeKey, positiveKey;
        final float[] sources = new float[3];
        final boolean shaped;
        int heldKey;
        Channel(int negativeKey, int positiveKey, boolean shaped) {
            this.negativeKey = negativeKey; this.positiveKey = positiveKey; this.shaped = shaped;
        }

        void update(long now) {
            // The strongest source wins, so a resting tilt never fights a held button.
            float value = 0f;
            for (float v : sources) if (Math.abs(v) > Math.abs(value)) value = v;
            float magnitude = Math.abs(value);
            if (shaped && magnitude < 0.999f) magnitude = shape(magnitude);
            boolean down;
            if (magnitude <= 0f) down = false;
            else if (magnitude > FULL) down = true;
            else {
                long period = Math.max(60, pwmPeriodMs);
                // At least ~one game frame on, or short taps are never seen.
                float duty = Math.max(magnitude, 34f / period);
                down = (now % period) < duty * period;
            }
            int key = !down ? 0 : value < 0 ? negativeKey : positiveKey;
            if (key == heldKey) return;
            if (heldKey != 0) release(heldKey);
            heldKey = key;
            if (key != 0) press(key);
        }

        void reset() {
            sources[0] = sources[1] = sources[2] = 0f;
            if (heldKey != 0) release(heldKey);
            heldKey = 0;
        }
    }

    private final SparseIntArray counts = new SparseIntArray();
    private final Handler handler = new Handler(Looper.getMainLooper());
    private final Channel steering = new Channel(KeyEvent.KEYCODE_DPAD_LEFT, KeyEvent.KEYCODE_DPAD_RIGHT, true);
    private final Channel throttle = new Channel(KeyEvent.KEYCODE_DPAD_DOWN, KeyEvent.KEYCODE_DPAD_UP, false);
    private boolean running;

    /** Tunables, copied from ControlSettings. */
    float deadZone = 0.08f;
    float curve = 1.0f;
    long pwmPeriodMs = 140;

    private final Runnable tick = new Runnable() {
        @Override public void run() {
            long now = SystemClock.uptimeMillis();
            steering.update(now);
            throttle.update(now);
            if (running) handler.postDelayed(this, TICK_MS);
        }
    };

    void configure(ControlSettings settings) {
        deadZone = settings.deadZone / 100f;
        curve = settings.steerCurve / 100f;
        pwmPeriodMs = settings.pwmPeriod;
    }

    /** Dead zone and response curve: >1 gives finer control near the centre. */
    private float shape(float magnitude) {
        if (magnitude <= deadZone) return 0f;
        float x = (magnitude - deadZone) / (1f - deadZone);
        return (float) Math.pow(x, curve);
    }

    void press(int key) {
        int count = counts.get(key);
        counts.put(key, count + 1);
        if (count == 0) SDLActivity.onNativeKeyDown(key);
    }

    void release(int key) {
        int count = counts.get(key);
        if (count <= 0) return;
        counts.put(key, count - 1);
        if (count == 1) SDLActivity.onNativeKeyUp(key);
    }

    /** Analog steering from one source, -1 (full left) .. 1 (full right). */
    void setSteering(int source, float value) {
        steering.sources[source] = clamp(value);
        steering.update(SystemClock.uptimeMillis());
    }

    float getSteering(int source) { return steering.sources[source]; }

    /** Analog throttle from one source, -1 (full brake) .. 1 (full gas). */
    void setThrottle(int source, float value) {
        throttle.sources[source] = clamp(value);
        throttle.update(SystemClock.uptimeMillis());
    }

    private static float clamp(float value) { return Math.max(-1f, Math.min(1f, value)); }

    void start() {
        if (running) return;
        running = true;
        handler.post(tick);
    }

    /** Lifts every key; used when the activity loses focus with fingers down. */
    void stop() {
        running = false;
        handler.removeCallbacks(tick);
        steering.reset();
        throttle.reset();
        for (int i = 0; i < counts.size(); ++i)
            if (counts.valueAt(i) > 0) SDLActivity.onNativeKeyUp(counts.keyAt(i));
        counts.clear();
    }
}
