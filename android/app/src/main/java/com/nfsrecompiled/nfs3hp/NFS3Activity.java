package com.nfsrecompiled.nfs3hp;

import org.libsdl.app.SDLActivity;
import android.content.pm.ActivityInfo;
import android.os.Bundle;
import android.os.Environment;
import android.view.Gravity;
import android.view.KeyEvent;
import android.view.MotionEvent;
import android.widget.Button;
import android.widget.LinearLayout;
import android.widget.RelativeLayout;
import java.util.HashSet;
import java.util.Set;

/** SDL owns surface, controller, audio and native-thread lifecycle. */
public final class NFS3Activity extends SDLActivity {
    private final Set<Integer> heldKeys = new HashSet<>();
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
        LinearLayout steering = group(RelativeLayout.ALIGN_PARENT_LEFT, RelativeLayout.ALIGN_PARENT_BOTTOM);
        control(steering, "◀", KeyEvent.KEYCODE_DPAD_LEFT);
        control(steering, "▶", KeyEvent.KEYCODE_DPAD_RIGHT);
        LinearLayout pedals = group(RelativeLayout.ALIGN_PARENT_RIGHT, RelativeLayout.ALIGN_PARENT_BOTTOM);
        control(pedals, "MANO", KeyEvent.KEYCODE_SPACE);
        control(pedals, "FRENO", KeyEvent.KEYCODE_DPAD_DOWN);
        control(pedals, "GAS", KeyEvent.KEYCODE_DPAD_UP);
        LinearLayout actions = group(RelativeLayout.ALIGN_PARENT_RIGHT, RelativeLayout.ALIGN_PARENT_TOP);
        control(actions, "CÁMARA", KeyEvent.KEYCODE_C);
        control(actions, "BOCINA", KeyEvent.KEYCODE_H);
        control(actions, "PAUSA", KeyEvent.KEYCODE_ESCAPE);
        LinearLayout menu = group(RelativeLayout.ALIGN_PARENT_LEFT, RelativeLayout.ALIGN_PARENT_TOP);
        control(menu, "VOLVER", KeyEvent.KEYCODE_ESCAPE);
        control(menu, "SALTAR / OK", KeyEvent.KEYCODE_ENTER);
    }

    private LinearLayout group(int horizontal, int vertical) {
        LinearLayout row = new LinearLayout(this);
        row.setGravity(Gravity.CENTER);
        RelativeLayout.LayoutParams params = new RelativeLayout.LayoutParams(-2, -2);
        params.addRule(horizontal); params.addRule(vertical);
        int margin = dp(10); params.setMargins(margin, margin, margin, margin);
        mLayout.addView(row, params);
        return row;
    }

    private int dp(int value) { return Math.round(value * getResources().getDisplayMetrics().density); }

    private void control(LinearLayout row, String label, int key) {
        Button button = new Button(this);
        button.setText(label); button.setTextSize(12); button.setAlpha(0.65f);
        button.setFocusable(false); button.setMinWidth(0); button.setMinimumWidth(0);
        LinearLayout.LayoutParams params = new LinearLayout.LayoutParams(dp(label.length()>8 ? 112 : 76), dp(58));
        params.setMargins(dp(2), 0, dp(2), 0); row.addView(button, params);
        button.setOnTouchListener((view, event) -> {
            switch (event.getActionMasked()) {
                case MotionEvent.ACTION_DOWN:
                    if (heldKeys.add(key)) onNativeKeyDown(key);
                    view.setPressed(true); return true;
                case MotionEvent.ACTION_UP:
                case MotionEvent.ACTION_CANCEL:
                    if (heldKeys.remove(key)) onNativeKeyUp(key);
                    view.setPressed(false); return true;
                default: return true;
            }
        });
    }

    @Override protected void onPause() {
        // A finger may still be down when Android backgrounds the activity.
        for (int key : heldKeys) onNativeKeyUp(key);
        heldKeys.clear();
        super.onPause();
    }
}
