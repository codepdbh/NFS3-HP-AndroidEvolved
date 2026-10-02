#!/usr/bin/env bash
set -euo pipefail
cd "$(dirname "$0")/.."
mkdir -p vendor
if [[ ! -f vendor/SDL/CMakeLists.txt ]]; then
    git clone --depth 1 --branch release-2.32.10 https://github.com/libsdl-org/SDL.git vendor/SDL
fi
[[ "$(git -C vendor/SDL rev-parse HEAD)" == 5d249570393f7a37e037abf22cd6012a4cc56a71 ]] || { echo "Unexpected SDL revision" >&2; exit 1; }
cd android
bash ./gradlew assembleRelease --console=plain
echo "APK: android/app/build/outputs/apk/release/app-release.apk"
