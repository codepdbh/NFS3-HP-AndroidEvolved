package com.nfsrecompiled.nfs3hp;

import android.app.Activity;
import android.content.Intent;
import android.content.pm.PackageManager;
import android.graphics.Color;
import android.graphics.Typeface;
import android.graphics.drawable.GradientDrawable;
import android.net.Uri;
import android.os.Build;
import android.os.Bundle;
import android.os.Environment;
import android.provider.Settings;
import android.view.Gravity;
import android.view.View;
import android.view.WindowInsets;
import android.view.WindowInsetsController;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.ScrollView;
import android.widget.TextView;
import java.io.ByteArrayOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.InputStream;
import java.nio.charset.StandardCharsets;
import java.util.ArrayList;
import java.util.List;

/** Grants storage access, then lets the player pick language and screen mode before SDL starts. */
public final class LauncherActivity extends Activity {
    private static final int ACCENT = 0xFFFFA000;
    private static final String[] LANGUAGE_FILES = { "spa", "eng", "fre", "ger", "ita", "swe" };
    private static final String[] SCREEN_LABELS = { "Original 4:3", "Panorámica 16:9", "Completa" };

    private boolean starting;
    private ControlSettings settings;
    private File data;
    private final List<Button> languageButtons = new ArrayList<>();
    private final List<Button> screenButtons = new ArrayList<>();
    private final List<Button> resolutionButtons = new ArrayList<>();
    private final List<Button> fpsButtons = new ArrayList<>();
    private Button showFpsButton;

    private boolean hasAccess() {
        return Build.VERSION.SDK_INT >= 30 ? Environment.isExternalStorageManager()
            : checkSelfPermission("android.permission.WRITE_EXTERNAL_STORAGE") == PackageManager.PERMISSION_GRANTED;
    }

    @Override protected void onCreate(Bundle state) {
        super.onCreate(state);
        settings = new ControlSettings(this);
        data = new File(Environment.getExternalStorageDirectory(), "nfs3hpandroidevolved");
    }

    @Override protected void onResume() { super.onResume(); hideSystemBars(); refresh(); }

    private int dp(float value) { return Math.round(value * getResources().getDisplayMetrics().density); }

    private void hideSystemBars() {
        if (Build.VERSION.SDK_INT >= 30) {
            WindowInsetsController controller = getWindow().getInsetsController();
            if (controller != null) {
                controller.hide(WindowInsets.Type.systemBars());
                controller.setSystemBarsBehavior(WindowInsetsController.BEHAVIOR_SHOW_TRANSIENT_BARS_BY_SWIPE);
            }
        }
    }

    private void refresh() {
        if (starting) return;
        boolean ready = false;
        if (hasAccess()) {
            data.mkdirs();
            ensureManifest();
            ready = find(data, "fedata") != null && find(data, "gamedata") != null && find(data, "nfs3.exe") != null;
        }
        LinearLayout screen = new LinearLayout(this);
        screen.setOrientation(LinearLayout.HORIZONTAL);
        screen.setGravity(Gravity.CENTER);
        screen.setBackground(new GradientDrawable(GradientDrawable.Orientation.TL_BR, new int[] { 0xFF1B2030, 0xFF07080C }));
        screen.setPadding(dp(24), dp(16), dp(24), dp(16));

        ImageView logo = new ImageView(this);
        logo.setImageResource(R.drawable.launcher_logo);
        logo.setAdjustViewBounds(true);
        screen.addView(logo, new LinearLayout.LayoutParams(0, LinearLayout.LayoutParams.MATCH_PARENT, 0.85f));

        LinearLayout panel = new LinearLayout(this);
        panel.setOrientation(LinearLayout.VERTICAL);
        panel.setGravity(Gravity.CENTER_HORIZONTAL);
        panel.setPadding(dp(24), 0, 0, 0);
        ScrollView scroll = new ScrollView(this);
        scroll.setFillViewport(true);
        scroll.addView(panel);
        screen.addView(scroll, new LinearLayout.LayoutParams(0, LinearLayout.LayoutParams.MATCH_PARENT, 1.15f));

        if (ready) buildMenu(panel); else buildSetup(panel);
        setContentView(screen);
    }

    private void buildMenu(LinearLayout panel) {
        panel.setGravity(Gravity.CENTER);
        heading(panel, "IDIOMA / LANGUAGE");
        File text = find(find(data, "fedata"), "text");
        LinearLayout row = null;
        languageButtons.clear();
        for (int i = 0; i < ControlSettings.LANGUAGES.length; ++i) {
            if (i % 3 == 0) row = row(panel);
            String code = ControlSettings.LANGUAGES[i][0];
            boolean available = text != null && find(text, "text." + LANGUAGE_FILES[i]) != null;
            Button button = chip(row, ControlSettings.LANGUAGES[i][1]);
            button.setEnabled(available);
            button.setAlpha(available ? 1f : 0.35f);
            button.setTag(code);
            button.setOnClickListener(v -> { settings.language = code; updateChips(); });
            languageButtons.add(button);
        }
        if (!isAvailable(settings.language)) settings.language = isAvailable("spanish") ? "spanish" : "english";

        heading(panel, "PANTALLA");
        row = row(panel);
        screenButtons.clear();
        for (int i = 0; i < SCREEN_LABELS.length; ++i) {
            int mode = i;
            Button button = chip(row, SCREEN_LABELS[i]);
            button.setOnClickListener(v -> { settings.screen = mode; updateChips(); });
            screenButtons.add(button);
        }
        heading(panel, "RESOLUCIÓN");
        resolutionButtons.clear();
        List<Integer> heights = new ArrayList<>();
        heights.add(0);  // native
        for (int h : new int[] { 900, 720, 540 }) if (h < screenHeight()) heights.add(h);
        heights.add(-1);  // the game's own resolution
        for (int i = 0; i < heights.size(); ++i) {
            if (i % 3 == 0) row = row(panel);
            int height = heights.get(i);
            Button button = chip(row, "");
            button.setTag(height);
            button.setOnClickListener(v -> { settings.outputHeight = height; updateChips(); });
            resolutionButtons.add(button);
        }

        heading(panel, "FPS");
        fpsButtons.clear();
        List<Integer> rates = new ArrayList<>();
        rates.add(30);
        for (int fps : supportedRefreshRates()) if (fps > 30 && !rates.contains(fps)) rates.add(fps);
        rates.add(0);  // display maximum
        if (!rates.contains(settings.fpsLimit)) settings.fpsLimit = 60;
        for (int i = 0; i < rates.size(); ++i) {
            if (i % 3 == 0) row = row(panel);
            int fps = rates.get(i);
            Button button = chip(row, fps == 0 ? "Máx" : fps + " FPS");
            button.setTag(fps);
            button.setOnClickListener(v -> { settings.fpsLimit = fps; updateChips(); });
            fpsButtons.add(button);
        }
        row = row(panel);
        showFpsButton = chip(row, "Mostrar FPS");
        showFpsButton.setOnClickListener(v -> { settings.showFps = !settings.showFps; updateChips(); });

        TextView note = new TextView(this);
        note.setText("La resolución dibuja el juego a más detalle; Completa lo estira a toda la pantalla.");
        note.setTextColor(0x99FFFFFF);
        note.setTextSize(12);
        note.setGravity(Gravity.CENTER);
        note.setPadding(0, dp(6), 0, 0);
        panel.addView(note);

        Button play = new Button(this);
        play.setText("JUGAR");
        play.setTextSize(22);
        play.setTypeface(Typeface.DEFAULT_BOLD);
        play.setTextColor(Color.BLACK);
        play.setBackground(rounded(ACCENT, ACCENT));
        LinearLayout.LayoutParams params = new LinearLayout.LayoutParams(dp(260), dp(60));
        params.topMargin = dp(20);
        play.setOnClickListener(v -> start());
        panel.addView(play, params);
        updateChips();
    }

    private void buildSetup(LinearLayout panel) {
        panel.setGravity(Gravity.CENTER);
        TextView message = new TextView(this);
        message.setGravity(Gravity.CENTER);
        message.setTextSize(16);
        message.setTextColor(Color.WHITE);
        message.setText("Copia tus archivos originales en:\n" + data.getAbsolutePath()
            + "\n\nfedata/   gamedata/   nfs3.exe\n\n"
            + (hasAccess() ? "Faltan archivos del juego." : "Permite acceso a archivos para leer esta carpeta."));
        panel.addView(message);
        Button action = new Button(this);
        action.setText(hasAccess() ? "COMPROBAR DE NUEVO" : "PERMITIR ACCESO A ARCHIVOS");
        action.setTextColor(Color.BLACK);
        action.setBackground(rounded(ACCENT, ACCENT));
        action.setOnClickListener(view -> {
            if (hasAccess()) refresh();
            else if (Build.VERSION.SDK_INT >= 30) {
                startActivity(new Intent(Settings.ACTION_MANAGE_APP_ALL_FILES_ACCESS_PERMISSION,
                    Uri.parse("package:" + getPackageName())));
            } else {
                requestPermissions(new String[] { "android.permission.READ_EXTERNAL_STORAGE", "android.permission.WRITE_EXTERNAL_STORAGE" }, 1);
            }
        });
        LinearLayout.LayoutParams params = new LinearLayout.LayoutParams(dp(300), dp(56));
        params.topMargin = dp(20);
        panel.addView(action, params);
    }

    private boolean isAvailable(String code) {
        for (Button button : languageButtons) if (code.equals(button.getTag())) return button.isEnabled();
        return false;
    }

    private void heading(LinearLayout panel, String title) {
        TextView view = new TextView(this);
        view.setText(title);
        view.setTextColor(ACCENT);
        view.setTextSize(13);
        view.setTypeface(Typeface.DEFAULT_BOLD);
        view.setLetterSpacing(0.15f);
        view.setPadding(0, dp(14), 0, dp(6));
        panel.addView(view);
    }

    private LinearLayout row(LinearLayout panel) {
        LinearLayout row = new LinearLayout(this);
        row.setOrientation(LinearLayout.HORIZONTAL);
        row.setGravity(Gravity.CENTER);
        panel.addView(row);
        return row;
    }

    private Button chip(LinearLayout row, String label) {
        Button button = new Button(this);
        button.setText(label);
        button.setAllCaps(false);
        button.setTextSize(15);
        button.setStateListAnimator(null);
        button.setPadding(dp(4), 0, dp(4), 0);
        button.setMaxLines(1);
        LinearLayout.LayoutParams params = new LinearLayout.LayoutParams(dp(124), dp(44));
        params.setMargins(dp(4), dp(4), dp(4), dp(4));
        row.addView(button, params);
        return button;
    }

    private GradientDrawable rounded(int fill, int stroke) {
        GradientDrawable drawable = new GradientDrawable();
        drawable.setColor(fill);
        drawable.setCornerRadius(dp(14));
        drawable.setStroke(dp(2), stroke);
        return drawable;
    }

    private void updateChips() {
        for (Button button : languageButtons) style(button, settings.language.equals(button.getTag()));
        for (int i = 0; i < screenButtons.size(); ++i) style(screenButtons.get(i), settings.screen == i);
        for (Button button : resolutionButtons) {
            int height = (Integer) button.getTag();
            button.setText(resolutionLabel(height));
            style(button, settings.outputHeight == height);
        }
        for (Button button : fpsButtons) style(button, settings.fpsLimit == (Integer) button.getTag());
        if (showFpsButton != null) style(showFpsButton, settings.showFps);
    }

    /** Pixel size the game is drawn at for an output height, in the chosen screen mode. */
    private String resolutionLabel(int height) {
        if (height < 0) return "Juego";
        int h = height == 0 ? screenHeight() : height;
        int w;
        switch (settings.screen) {
            case ControlSettings.SCREEN_ORIGINAL: w = h * 4 / 3; break;
            case ControlSettings.SCREEN_WIDE: w = h * 16 / 9; break;
            default: w = h * screenWidth() / screenHeight(); break;
        }
        return (height == 0 ? "Nativa " : "") + (w & ~1) + "×" + h;
    }

    private android.util.DisplayMetrics realMetrics() {
        android.util.DisplayMetrics metrics = new android.util.DisplayMetrics();
        getWindowManager().getDefaultDisplay().getRealMetrics(metrics);
        return metrics;
    }

    private int screenWidth() { android.util.DisplayMetrics m = realMetrics(); return Math.max(m.widthPixels, m.heightPixels); }
    private int screenHeight() { android.util.DisplayMetrics m = realMetrics(); return Math.min(m.widthPixels, m.heightPixels); }

    private List<Integer> supportedRefreshRates() {
        List<Integer> rates = new ArrayList<>();
        for (android.view.Display.Mode mode : getWindowManager().getDefaultDisplay().getSupportedModes()) {
            int fps = Math.round(mode.getRefreshRate());
            if (!rates.contains(fps)) rates.add(fps);
        }
        java.util.Collections.sort(rates);
        return rates;
    }

    private void style(Button button, boolean selected) {
        button.setBackground(rounded(selected ? 0x33FFA000 : 0x22FFFFFF, selected ? ACCENT : 0x44FFFFFF));
        button.setTextColor(selected ? ACCENT : Color.WHITE);
        button.setTypeface(selected ? Typeface.DEFAULT_BOLD : Typeface.DEFAULT);
    }

    private void start() {
        settings.save();
        writeLanguage(settings.language);
        starting = true;
        startActivity(new Intent(this, NFS3Activity.class));
        finish();
    }

    // ---- install.win -------------------------------------------------------

    /** Installation paths plus the Modern Patch configuration, never overwriting the player's files. */
    private void ensureManifest() {
        for (String asset : new String[] { "install.win", "nfs3.ini", "drivers/nglide/thrash.ini", "drivers/nglide/voodoo2a.dll" }) {
            if (resolve(asset) != null) continue;
            File target = new File(data, asset);
            target.getParentFile().mkdirs();
            try (InputStream input = getAssets().open(asset);
                 FileOutputStream output = new FileOutputStream(target)) {
                byte[] bytes = new byte[4096]; int count;
                while ((count = input.read(bytes)) != -1) output.write(bytes, 0, count);
            } catch (Exception error) {
                android.util.Log.e("NFS3/FILESYSTEM", "Cannot create " + asset, error);
            }
        }
    }

    /** Finds a relative path inside the game folder, ignoring case like the game does. */
    private File resolve(String path) {
        File current = data;
        for (String part : path.split("/")) {
            current = find(current, part);
            if (current == null) return null;
        }
        return current;
    }

    private static String readText(File file) throws java.io.IOException {
        ByteArrayOutputStream buffer = new ByteArrayOutputStream();
        try (InputStream input = new FileInputStream(file)) {
            byte[] bytes = new byte[4096]; int count;
            while ((count = input.read(bytes)) != -1) buffer.write(bytes, 0, count);
        }
        return new String(buffer.toByteArray(), StandardCharsets.ISO_8859_1);
    }

    private static void writeText(File file, String text) throws java.io.IOException {
        try (FileOutputStream output = new FileOutputStream(file)) {
            output.write(text.getBytes(StandardCharsets.ISO_8859_1));
        }
    }

    /**
     * The original executable reads its language from the first line of
     * install.win; the Modern Patch reads Language= from nfs3.ini. Both are set.
     */
    private void writeLanguage(String language) {
        try {
            File manifest = resolve("install.win");
            if (manifest != null) {
                String content = readText(manifest);
                int end = content.indexOf('\n');
                String first = (end < 0 ? content : content.substring(0, end)).trim();
                if (!first.equalsIgnoreCase(language))
                    writeText(manifest, language + "\r\n" + (end < 0 ? "" : content.substring(end + 1)));
            }
            File ini = resolve("nfs3.ini");
            if (ini != null) writeText(ini, setIniValue(readText(ini), "NFS3", "Language", language));
        } catch (Exception error) {
            android.util.Log.e("NFS3/FILESYSTEM", "Cannot set language", error);
        }
    }

    /** Replaces or adds key=value inside [section], keeping every other line as it was. */
    static String setIniValue(String text, String section, String key, String value) {
        String[] lines = text.split("\r?\n", -1);
        StringBuilder out = new StringBuilder();
        boolean inSection = false, done = false;
        for (int i = 0; i < lines.length; ++i) {
            String line = lines[i];
            String trimmed = line.trim();
            if (trimmed.startsWith("[")) {
                if (inSection && !done) { out.append(key).append('=').append(value).append("\r\n"); done = true; }
                inSection = trimmed.equalsIgnoreCase("[" + section + "]");
            } else if (inSection && !done) {
                int equals = trimmed.indexOf('=');
                if (equals > 0 && trimmed.substring(0, equals).trim().equalsIgnoreCase(key)) {
                    line = key + "=" + value;
                    done = true;
                }
            }
            if (i == lines.length - 1 && line.isEmpty()) break;
            out.append(line).append("\r\n");
        }
        if (!done) {
            if (!inSection) out.append('[').append(section).append("]\r\n");
            out.append(key).append('=').append(value).append("\r\n");
        }
        return out.toString();
    }

    private static File find(File directory, String name) {
        if (directory == null) return null;
        File[] entries = directory.listFiles();
        if (entries != null) for (File entry : entries) if (entry.getName().equalsIgnoreCase(name)) return entry;
        return null;
    }

    @Override public void onRequestPermissionsResult(int request, String[] permissions, int[] grants) {
        super.onRequestPermissionsResult(request, permissions, grants);
        refresh();
    }
}
