package com.nfsrecompiled.nfs3hp;

import android.app.Activity;
import android.content.Intent;
import android.content.pm.PackageManager;
import android.net.Uri;
import android.os.Build;
import android.os.Bundle;
import android.os.Environment;
import android.provider.Settings;
import android.view.Gravity;
import android.widget.Button;
import android.widget.LinearLayout;
import android.widget.TextView;
import java.io.File;
import java.io.FileOutputStream;
import java.io.InputStream;

/** Grant shared-storage access before SDL starts the native game thread. */
public final class LauncherActivity extends Activity {
    private boolean starting;
    private boolean hasAccess() {
        return Build.VERSION.SDK_INT >= 30 ? Environment.isExternalStorageManager()
            : checkSelfPermission("android.permission.WRITE_EXTERNAL_STORAGE") == PackageManager.PERMISSION_GRANTED;
    }
    @Override protected void onCreate(Bundle state) { super.onCreate(state); }
    @Override protected void onResume() { super.onResume(); refresh(); }
    private void refresh() {
        if (starting) return;
        File data = new File(Environment.getExternalStorageDirectory(), "nfs3hpandroidevolved");
        if (hasAccess()) {
            data.mkdirs();
            File manifest = new File(data, "install.win");
            if (!manifest.exists()) {
                try (InputStream input = getAssets().open("install.win");
                     FileOutputStream output = new FileOutputStream(manifest)) {
                    byte[] bytes = new byte[4096]; int count;
                    while ((count = input.read(bytes)) != -1) output.write(bytes, 0, count);
                } catch (Exception error) {
                    android.util.Log.e("NFS3/FILESYSTEM", "Cannot create installation paths", error);
                }
            }
            if (find(data, "fedata") && find(data, "gamedata") && find(data, "nfs3.exe")) {
                starting = true; startActivity(new Intent(this, NFS3Activity.class)); finish(); return;
            }
        }
        LinearLayout layout = new LinearLayout(this);
        layout.setOrientation(LinearLayout.VERTICAL); layout.setGravity(Gravity.CENTER);
        layout.setPadding(32, 20, 32, 20);
        TextView message = new TextView(this);
        message.setGravity(Gravity.CENTER); message.setTextSize(18);
        message.setText("NFS3 HP Android Evolved\n\nCopia tus archivos originales en:\n" + data.getAbsolutePath()
            + "\n\nfedata/   gamedata/   nfs3.exe\n\n" + (hasAccess() ? "Faltan archivos del juego." : "Permite acceso a archivos para leer esta carpeta."));
        layout.addView(message);
        Button action = new Button(this);
        action.setText(hasAccess() ? "COMPROBAR ARCHIVOS Y ABRIR" : "PERMITIR ACCESO A ARCHIVOS");
        action.setOnClickListener(view -> {
            if (hasAccess()) { refresh(); }
            else if (Build.VERSION.SDK_INT >= 30) {
                startActivity(new Intent(Settings.ACTION_MANAGE_APP_ALL_FILES_ACCESS_PERMISSION,
                    Uri.parse("package:" + getPackageName())));
            } else {
                requestPermissions(new String[] { "android.permission.READ_EXTERNAL_STORAGE", "android.permission.WRITE_EXTERNAL_STORAGE" }, 1);
            }
        });
        layout.addView(action); setContentView(layout);
    }
    private boolean find(File directory, String name) {
        File[] entries = directory.listFiles();
        if (entries != null) for (File entry : entries) if (entry.getName().equalsIgnoreCase(name)) return true;
        return false;
    }
    @Override public void onRequestPermissionsResult(int request, String[] permissions, int[] grants) {
        super.onRequestPermissionsResult(request, permissions, grants); refresh();
    }
}
