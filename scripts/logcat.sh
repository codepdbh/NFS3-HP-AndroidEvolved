#!/usr/bin/env bash
set -euo pipefail
adb logcat 'SDL:*' 'SDL/APP:*' 'NFS3/CPU:*' 'AndroidRuntime:E' 'DEBUG:E' '*:S'
