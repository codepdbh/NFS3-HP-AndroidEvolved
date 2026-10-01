#!/usr/bin/env python3
"""Write a local-path installation manifest; never overwrite an existing one.

Path slots follow the original installer layout, with writable root in slot 2
and car specifications in slot 21. See docs/NFS3-DEPENDENCIES.md for provenance.
"""
import argparse
from pathlib import Path

paths = [
    'english', 'local', '.', 'gamedata/tracks', 'gamedata/tracks/tutor',
    'gamedata/carmodel', 'gamedata/render/pc', 'gamedata/dashhud',
    'gamedata/audio/pc', 'gamedata/audio/sfx', 'gamedata/audio/speech/english',
    'gamedata/audio/speech/german', 'gamedata/audio/speech/french',
    'gamedata/audio/speech/spanish', 'gamedata/audio/speech/italian',
    'fedata/art', 'fedata/text', 'fedata/text', 'fedata/save', 'fedata/stats',
    'fedata/config', 'fedata/stats/carspecs', 'fedata/art/slides',
    'fedata/art/track', 'fedata/art/showcase', 'fedata/movies', 'fedata/stats/prh'
]

if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('directory', type=Path)
    args = parser.parse_args()
    args.directory.mkdir(parents=True, exist_ok=True)
    target = args.directory / 'install.win'
    # Empty lines shift the game's slot indexes. Preserve every slot.
    lines = paths[:2] + [p.replace('/', '\\') + '\\' for p in paths[2:]]
    with target.open('x', encoding='ascii', newline='') as output:
        output.write('\r\n'.join(lines) + '\r\n')
    print(target)
