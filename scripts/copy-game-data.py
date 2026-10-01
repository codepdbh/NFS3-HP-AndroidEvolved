#!/usr/bin/env python3
"""Import legally owned NFS3 data into the installed Debug app using ADB.

run-as is needed on devices that prevent adb shell writing scoped storage.
The native code is already compiled; nfs3.exe is read only for guest integrity
checks. No Windows executable or DLL is executed on Android.
"""
import argparse
import subprocess
import tempfile
import tarfile
from pathlib import Path

parser = argparse.ArgumentParser(description=__doc__)
parser.add_argument('directory', type=Path)
parser.add_argument('--adb', default='adb')
args = parser.parse_args()
root = args.directory.resolve()
entries = {p.name.lower(): p for p in root.iterdir()}
for name in ['fedata', 'gamedata', 'nfs3.exe', 'install.win']:
    if name not in entries:
        parser.error(f'Missing {name} in {root}')
package = 'com.nfsrecompiled.nfs3hp'
destination = '/sdcard/nfs3hpandroidevolved'
remote = '/data/local/tmp/nfs3hp-game-data.tar'

def adb(*arguments):
    subprocess.run([args.adb, *arguments], check=True)

with tempfile.TemporaryDirectory(prefix='nfs3hp-') as temporary:
    archive_path = Path(temporary) / 'game-data.tar'
    with tarfile.open(archive_path, 'w') as archive:
        for name in ['fedata', 'gamedata', 'nfs3.exe', 'install.win']:
            archive.add(entries[name], arcname=name)
    adb('push', str(archive_path), remote)
    try:
        adb('shell', 'run-as', package, 'mkdir', '-p', destination)
        adb('shell', 'run-as', package, 'tar', '-xf', remote, '-C', destination)
    finally:
        adb('shell', 'rm', '-f', remote)
print(f'Game files imported to {destination}')
