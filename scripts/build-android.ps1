$ErrorActionPreference = 'Stop'
Push-Location (Join-Path $PSScriptRoot '..')
try {
    if (!(Test-Path 'vendor/SDL/CMakeLists.txt')) {
        New-Item -ItemType Directory -Force vendor | Out-Null
        git clone --depth 1 --branch release-2.32.10 https://github.com/libsdl-org/SDL.git vendor/SDL
        if ($LASTEXITCODE -ne 0) { throw 'SDL download failed' }
    }
    $sdlRevision = git -C vendor/SDL rev-parse HEAD
    if ($sdlRevision -ne '5d249570393f7a37e037abf22cd6012a4cc56a71') { throw 'Unexpected SDL revision' }
    if (!$env:ANDROID_HOME) { $env:ANDROID_HOME = Join-Path $env:LOCALAPPDATA 'Android/Sdk' }
    if (!$env:JAVA_HOME -and (Test-Path 'C:/Program Files/Android/Android Studio/jbr')) {
        $env:JAVA_HOME = 'C:/Program Files/Android/Android Studio/jbr'
    }
    & ./android/gradlew.bat -p android assembleRelease --console=plain
    if ($LASTEXITCODE -ne 0) { throw 'APK build failed' }
    Write-Output 'APK: android/app/build/outputs/apk/release/app-release.apk'
} finally { Pop-Location }
