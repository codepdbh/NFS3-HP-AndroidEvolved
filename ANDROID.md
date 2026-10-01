# NFS3 HP Android Evolved

Port comunitario nativo ARM64 de **Need for Speed III: Hot Pursuit** basado en
`motor-dev/nfs-recompiled`, revisión `77ebdb3`. Solo se construye `nfs3hp`.
Los archivos originales del juego no se distribuyen con el proyecto ni el APK.

## Herramientas

Android Studio con soporte para Android Gradle Plugin 8.7.3, JDK 17 o superior,
SDK Android 35, NDK **27.2.12479018**, CMake **3.30.5**, Git y Python 3 para los
scripts de datos. Gradle 8.9 se descarga mediante el wrapper. Instala las
versiones indicadas desde SDK Manager. Android mínimo: 8.0 / API 26.

SDL **2.32.10** se descarga desde su repositorio oficial y se construye para
ARM64 con el NDK. Su código Java proporciona SDLActivity, audio, entrada y ciclo
de vida. No se ejecutan instrucciones x86 ni bibliotecas de Windows.
MMX se traduce a NEON con `sse2neon`, revisión
`60fc9391e378b58c60899791c0e9ee9cdaf43c08`, con licencia incluida.

## Construir

Windows PowerShell:

```powershell
./scripts/build-android.ps1
```

Linux / WSL (configura `ANDROID_HOME` y `JAVA_HOME`):

```bash
bash scripts/build-android.sh
```

APK: `android/app/build/outputs/apk/debug/app-debug.apk`.
Se compila C++17, Debug, `arm64-v8a`, OpenGL ES 3 y `BUILD_NFS2=OFF`.
Las fuentes generadas existentes se usan directamente.

## Instalar y copiar datos

```bash
adb install -r android/app/build/outputs/apk/debug/app-debug.apk
adb shell am start -n com.nfsrecompiled.nfs3hp/.LauncherActivity
```

En el primer arranque, concede acceso a archivos. La carpeta solicitada es
**`/storage/emulated/0/nfs3hpandroidevolved/`**, visible en la memoria interna.
No es la carpeta privada `Android/data`.

```text
nfs3hpandroidevolved/
├── install.win
├── nfs3.exe
├── fedata/
│   ├── art/
│   ├── config/
│   ├── menus/
│   ├── movies/
│   ├── save/
│   ├── stats/
│   └── text/
└── gamedata/
    ├── audio/
    ├── carmodel/
    ├── dashhud/
    ├── render/
    └── tracks/
```

Combina los datos de tu instalación y tu CD legalmente adquirido. Las rutas
aceptan mayúsculas/minúsculas y separadores de Windows. `nfs3.exe` se lee para
comprobaciones de integridad del juego; no se ejecuta ni emula. Las DLL se
resuelven mediante las implementaciones compiladas, sin cargarlas desde Windows.

Si falta `install.win`, el launcher crea una configuración de rutas relativas.
No sustituye un archivo existente. También puedes generarlo en tu carpeta local:

```bash
python scripts/make-install-win.py /ruta/al/juego
python scripts/copy-game-data.py /ruta/al/juego
```

El segundo script requiere el APK Debug y ADB. Admite `--adb /ruta/a/adb`.
No sobrescribas tus partidas sin guardar antes una copia de seguridad.

## Controles

La app permanece horizontal. El contenido conserva la proporción original 4:3.

| Botón | Entrada |
|---|---|
| SALTAR / OK | Enter: saltar cinemática y confirmar |
| VOLVER | Escape |
| ◀ / ▶ | Flechas izquierda / derecha |
| GAS / FRENO | Flechas arriba / abajo; también navegación del menú |
| MANO | Espacio |
| PAUSA | Escape: men? de pausa durante la carrera |
| CÁMARA | C |
| BOCINA | H |

Los controles envían teclas a SDL, permiten mantener pulsaciones y liberan las
teclas al poner la app en segundo plano. Los mandos usan el backend SDL existente;
la asignación de cada mando necesita validación y puede ajustarse en el juego.

## Diagnóstico y estado comprobado

```bash
bash scripts/logcat.sh
```

Se ha comprobado: compilación desktop Debug de NFS3, biblioteca ARM64, APK,
instalación en un dispositivo real Android 16, inicialización, lectura de datos,
cinemática y dibujo del menú principal en GLES3. Icono y controles incluidos.
La pantalla negra del menú causada por constantes enteras en el shader GLES
se corrigió; los fallos de compilación ahora detienen el arranque con diagnóstico.

Pendiente: validación de carreras, controles de conducción, mandos Bluetooth/USB,
audio audible y supervivencia completa a pausa/reanudación y recreación de superficie.
SDL gestiona la pausa de audio y del hilo Android; todavía hace falta comprobar
el comportamiento del runtime del juego durante estas transiciones.

La FPU usa el fallback portable `double`; no garantiza precisión x87 de 80 bits.
`WITH_PEDANTIC_FPU=ON` se rechaza en Android porque requiere NASM x86.
La memoria invitada mantiene bloques de 4 KB pero usa una arena Android escribible
para evitar proteger bloques vecinos en kernels con páginas de 16 KB. No hay
guardas de páginas por bloque en esta versión. El enlace ARM64 admite páginas de
16 KB. No se activan sanitizers por defecto.

Si faltan archivos, revisa la pantalla inicial y el registro `FILESYSTEM`.
Si un APK no arranca, busca `AndroidRuntime`, `NFS3/CPU`, `VIDEO` o `GLIDE`.

## Referencias

* [Proyecto original](https://github.com/motor-dev/nfs-recompiled)
* [SDL2 Android](https://github.com/libsdl-org/SDL/blob/release-2.32.10/docs/README-android.md)
* [sse2neon](https://github.com/DLTcollab/sse2neon)
* [Investigación independiente del formato install.win](https://github.com/ZloiKILLER/nfs3recompiled-android/blob/main/tools/make_install_win.py)
