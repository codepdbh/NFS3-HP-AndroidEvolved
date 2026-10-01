#!/usr/bin/env bash
set -euo pipefail
cd "$(dirname "$0")/.."
adb install -r android/app/build/outputs/apk/debug/app-debug.apk
adb shell am start -n com.nfsrecompiled.nfs3hp/.LauncherActivity
