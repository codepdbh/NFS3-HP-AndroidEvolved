package com.nfsrecompiled.nfs3hp;

import android.content.Context;
import android.content.SharedPreferences;
import java.util.HashMap;
import java.util.Locale;
import java.util.Map;

/** Launcher, display and control preferences, persisted between sessions. */
final class ControlSettings {
    static final int STEER_STICK = 0, STEER_BUTTONS = 1, STEER_SLIDE = 2, STEER_TILT = 3;
    static final int SCREEN_ORIGINAL = 0, SCREEN_WIDE = 1, SCREEN_FULL = 2;
    static final int LAYOUT_AUTO = 0, LAYOUT_MENU = 1, LAYOUT_RACE = 2;

    /** Game language as written to install.win, with the label shown to the player. */
    static final String[][] LANGUAGES = {
        { "spanish", "Español" }, { "english", "English" }, { "french", "Français" },
        { "german", "Deutsch" }, { "italian", "Italiano" }, { "swedish", "Svenska" },
    };

    /** A control moved or resized in the layout editor; centre is relative to the view. */
    static final class Placement {
        float centerX, centerY, scale;
        Placement(float centerX, float centerY, float scale) {
            this.centerX = centerX; this.centerY = centerY; this.scale = scale;
        }
    }

    String language;
    int screen = SCREEN_FULL;
    int layout = LAYOUT_AUTO;
    int steering = STEER_STICK;
    int opacity = 60;        // percent
    int size = 100;          // percent
    int tiltRange = 25;      // degrees for full lock
    float tiltCenter = 0f;   // degrees, set by calibration
    boolean tiltInvert = false;
    int deadZone = 8;        // percent of analog travel ignored
    int steerCurve = 130;    // response exponent x100; >100 = finer near centre
    int pwmPeriod = 140;     // ms; shorter is smoother but needs a faster frame rate
    boolean analogTriggers = true;
    boolean haptics = true;
    boolean leftHanded = false;
    boolean gearButtons = false;
    boolean hideWithGamepad = true;
    final Map<String, Placement> placements = new HashMap<>();

    private final SharedPreferences prefs;

    ControlSettings(Context context) {
        prefs = context.getSharedPreferences("controls", Context.MODE_PRIVATE);
        language = prefs.getString("language", systemLanguage());
        screen = prefs.getInt("screen", screen);
        layout = prefs.getInt("layoutMode", layout);
        steering = prefs.getInt("steeringMode", steering);
        opacity = prefs.getInt("opacity", opacity);
        size = prefs.getInt("size", size);
        tiltRange = prefs.getInt("tiltRange", tiltRange);
        tiltCenter = prefs.getFloat("tiltCenter", tiltCenter);
        tiltInvert = prefs.getBoolean("tiltInvert", tiltInvert);
        deadZone = prefs.getInt("deadZone", deadZone);
        steerCurve = prefs.getInt("steerCurve", steerCurve);
        pwmPeriod = prefs.getInt("pwmPeriod", pwmPeriod);
        analogTriggers = prefs.getBoolean("analogTriggers", analogTriggers);
        haptics = prefs.getBoolean("haptics", haptics);
        leftHanded = prefs.getBoolean("leftHanded", leftHanded);
        gearButtons = prefs.getBoolean("gearButtons", gearButtons);
        hideWithGamepad = prefs.getBoolean("hideWithGamepad", hideWithGamepad);
        for (String item : prefs.getString("layout", "").split(";")) {
            String[] parts = item.split(",");
            if (parts.length != 4) continue;
            try {
                placements.put(parts[0], new Placement(Float.parseFloat(parts[1]), Float.parseFloat(parts[2]), Float.parseFloat(parts[3])));
            } catch (NumberFormatException ignored) {
            }
        }
    }

    private static String systemLanguage() {
        switch (Locale.getDefault().getLanguage()) {
            case "es": return "spanish";
            case "fr": return "french";
            case "de": return "german";
            case "it": return "italian";
            case "sv": return "swedish";
            default: return "english";
        }
    }

    /** Aspect handed to the renderer: <0 keeps 4:3, 0 fills the screen. */
    float displayAspect() {
        switch (screen) {
            case SCREEN_ORIGINAL: return -1f;
            case SCREEN_WIDE: return 16f / 9f;
            default: return 0f;
        }
    }

    void save() {
        StringBuilder placementText = new StringBuilder();
        for (Map.Entry<String, Placement> entry : placements.entrySet()) {
            Placement p = entry.getValue();
            placementText.append(entry.getKey()).append(',').append(p.centerX).append(',')
                .append(p.centerY).append(',').append(p.scale).append(';');
        }
        prefs.edit()
            .putString("language", language).putInt("screen", screen)
            .putInt("layoutMode", layout).putInt("steeringMode", steering).putInt("opacity", opacity).putInt("size", size)
            .putInt("tiltRange", tiltRange).putFloat("tiltCenter", tiltCenter)
            .putBoolean("tiltInvert", tiltInvert).putInt("deadZone", deadZone)
            .putInt("steerCurve", steerCurve).putInt("pwmPeriod", pwmPeriod)
            .putBoolean("analogTriggers", analogTriggers).putBoolean("haptics", haptics)
            .putBoolean("leftHanded", leftHanded).putBoolean("gearButtons", gearButtons)
            .putBoolean("hideWithGamepad", hideWithGamepad).putString("layout", placementText.toString())
            .apply();
    }
}
