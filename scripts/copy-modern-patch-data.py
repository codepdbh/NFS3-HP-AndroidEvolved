#!/usr/bin/env python3
"""Copy the NFS3 Modern Patch v1.6.1 data files to the phone using ADB.

The Modern Patch build runs the patched executable, whose menus, texts, HUD and
logos must match it. Only fedata/ and gamedata/ files from the patch folder are
copied (no executable or DLL is needed on the phone). Every file that would be
replaced is first copied to <game>/backup-before-modern-patch/ on the device.
Existing nfs3.ini and drivers/ settings are left alone: the launcher creates them.
"""
import argparse
import posixpath
import subprocess
from pathlib import Path

parser = argparse.ArgumentParser(description=__doc__)
parser.add_argument('patch', type=Path, help='Folder with the extracted Modern Patch')
parser.add_argument('--adb', default='adb')
parser.add_argument('--device-dir', default='/sdcard/nfs3hpandroidevolved')
args = parser.parse_args()

root = args.patch.resolve()
files = [p for top in ('fedata', 'gamedata') for p in (root / top).rglob('*') if p.is_file()]
if not files:
    parser.error(f'No fedata/ or gamedata/ files in {root}')


def adb(*arguments, capture=False):
    result = subprocess.run([args.adb, *arguments], check=True, text=True,
                            stdout=subprocess.PIPE if capture else None)
    return result.stdout if capture else None


# The game resolves names case-insensitively, so match existing device files that way.
listing = adb('shell', f'cd {args.device_dir} && find fedata gamedata -type f', capture=True)
existing = {line.strip().lower(): line.strip() for line in listing.splitlines() if line.strip()}
backup = posixpath.join(args.device_dir, 'backup-before-modern-patch')

for path in files:
    relative = path.relative_to(root).as_posix()
    device_relative = existing.get(relative.lower(), relative)
    target = posixpath.join(args.device_dir, device_relative)
    if relative.lower() in existing:
        saved = posixpath.join(backup, device_relative)
        adb('shell', f'mkdir -p "{posixpath.dirname(saved)}" && [ -e "{saved}" ] || cp "{target}" "{saved}"')
    else:
        adb('shell', f'mkdir -p "{posixpath.dirname(target)}"')
    adb('push', str(path), target)
print(f'{len(files)} Modern Patch files copied; previous versions in {backup}')
