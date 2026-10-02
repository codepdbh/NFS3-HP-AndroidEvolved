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

APK: `android/app/build/outputs/apk/release/app-release.apk`.
Se compila C++17, **Release (`-O2`)**, `arm64-v8a`, OpenGL ES 3 y `BUILD_NFS2=OFF`,
firmado con la clave de depuración para poder instalarlo encima del APK anterior.
No juegues con `assembleDebug`: el código recompilado depende de que cada acceso
a la memoria del juego se optimice, y en `-O0` corre varias veces más lento.
El APK Debug sigue disponible (`gradlew -p android assembleDebug`) para depurar.
Las fuentes generadas existentes se usan directamente.

## Instalar y copiar datos

```bash
adb install -r android/app/build/outputs/apk/release/app-release.apk
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

El segundo script usa `run-as` como alternativa, que solo funciona con el APK Debug; con el
Release copia los datos con un explorador de archivos o `adb push`. Requiere ADB. Admite `--adb /ruta/a/adb`.
No sobrescribas tus partidas sin guardar antes una copia de seguridad.

## Inicio, idioma y pantalla

Antes de arrancar, el launcher muestra un menú para elegir **idioma** (escribe la
primera línea de `install.win`, que es la que lee el juego; solo se activan los
idiomas cuyo `fedata/text/text.*` existe) y **pantalla**: Original 4:3,
Panorámica 16:9 o Completa (estira la imagen al tamaño del móvil).

## NFS3 Modern Patch

Por defecto se compila el **NFS3 Modern Patch v1.6.1** (VEG), recompilado igual que
el juego original: `nfs3hp_modern/nfs3.exe` →
`python disassemble_nfs3hp_modern.py` → `src/nfs3hp/disassembly_modern/`.
`gradlew assembleRelease -PoriginalExe` compila el ejecutable original.

* El parche modifica el `.exe` en el sitio, así que valen las pistas del original;
  las DLL suben 0x21000 y el script ajusta sus pistas. Veg reutilizó zonas de datos
  para código nuevo y vació funciones con `nop`; las zonas afectadas están listadas
  y comentadas en el script.
* Se usa el `voodoo2a.dll` **original** (Glide 2). El del parche usa Glide 3, que
  este runtime no implementa; el `.exe` habla con el driver por `THRASH_*`.
* Funciones añadidas para el parche: heap del proceso, `GetPrivateProfile*`
  (`nfs3.ini`, `thrash.ini`), recursos PE, `timeGetTime` y `PlaySoundA`.
* **Resolución nativa y panorámica real**: con el modo Completa, cualquier
  resolución de carrera que elijas en Opciones → Gráficos (800×600 o más) se
  renderiza a la resolución de la pantalla del móvil (p. ej. 2340×1080); con 16:9,
  a su altura en 16:9. El parche adapta campo de visión y HUD a ese tamaño, como
  con nGlide a resolución de escritorio. 640×480 se deja para los menús.

Datos: el parche necesita sus propios menús, textos, HUD y logos. Cópialos desde la
carpeta del parche (guarda en el móvil una copia de lo que reemplaza):

```bash
python scripts/copy-modern-patch-data.py /ruta/al/ModernPatch
```

El launcher crea `nfs3.ini` y `drivers/nglide/thrash.ini` si faltan y escribe el
idioma elegido en `nfs3.ini` (`Language=`) además de en `install.win`.

## Controles

* **Menús**: táctiles. Toca las opciones directamente; el gesto o botón **Atrás**
  de Android equivale a Esc (volver, pausar y **saltar cinemáticas**). Solo se ve
  el botón ⚙ de ajustes.
* **Carrera**: los controles aparecen solos al empezar (el menú del juego corre
  a 640×480 y la carrera a su propia resolución con miles de triángulos).
  Joystick a la izquierda (giro proporcional), GAS / FRENO / MANO a la derecha y
  bocina, cámara y pausa bajo el HUD. Los dedos pueden deslizarse entre botones.

Otros modos de dirección (⚙): Botones, Deslizar e Inclinación. También: curva de
respuesta, zona muerta, opacidad, tamaño, vibración, modo zurdo, marchas manuales
(A / Z) y un editor para mover y redimensionar cada botón.

NFS3 solo entiende dirección digital, así que el giro analógico se convierte en
pulsaciones moduladas: cuanto más giras, más tiempo se mantiene la flecha.

**Mando físico**: RT gas, LT freno (progresivos), stick/cruceta dirección, A OK,
B volver, X freno de mano, Y cámara, LB/RB marcha −/+, Start pausa, Select bocina.

El ratón de DirectInput (que usa NFS3 en los menús) se alimenta de los toques; cada
toque recoloca el cursor llevándolo primero a la esquina y luego a la posición.

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
