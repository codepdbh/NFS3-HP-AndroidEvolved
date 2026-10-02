"""Recompile NFS3 Modern Patch v1.6.1 (by VEG) into src/nfs3hp/disassembly_modern.

The patch edits nfs3.exe in place: code and data keep their addresses, so the
hints of disassemble_nfs3hp.py still apply to the executable. Its larger .bss
and resources push every DLL up by 0x21000, so DLL hints are shifted by that.
Put the patched nfs3.exe in nfs3hp_modern/ with the ORIGINAL eacsnd.dll,
softtria.dll and voodoo2a.dll: the patch's own voodoo2a.dll targets Glide 3,
while this runtime implements Glide 2. The patched exe talks to the driver
through the unchanged THRASH_* interface and asks Glide 2 for the screen size.
"""
import os
import shutil
import sys

ROOT = os.path.dirname(os.path.abspath(__file__))
sys.path.append(os.path.join(ROOT, 'disasm'))
from disasm import disassembler, dll
import disassemble_nfs3hp as original

DLL_SHIFT = 0x21000
INPUT = os.path.join(ROOT, 'nfs3hp_modern')
WORK = os.path.join(ROOT, 'build-modern-disasm')
OUTPUT = os.path.join(ROOT, 'src', 'nfs3hp', 'disassembly_modern')


# Veg reused two former data areas for new code, and replaced the CPU-speed
# calibration loop and an odd byte sequence with NOPs, so those hints go.
PATCH_CODE_AREAS = [(0x4a2f50, 0x4a3050), (0x4b5580, 0x4b56d0)]
# Code the patch blanked with NOPs right before data is unreachable (each run
# follows a ret); keeping it as data stops it being glued to the next function.
# 0x40ff80 is a table Veg placed inside his own code.
EXTENDED_DATA = {(0x454f10, 0x455020): (0x454e44, 0x455020),
                 (0x472160, 0x4721f0): (0x472156, 0x4721f0)}
DATA_SEGMENTS = [EXTENDED_DATA.get(s, s) for s in original.DATA_SEGMENTS if s not in PATCH_CODE_AREAS] + [
    (0x40ff80, 0x40ff9c),   # new lookup table
    (0x41d6e4, 0x41d7e4),   # new table of 16-bit values
    (0x43f7ca, 0x43f7e0),   # padding and jump table after patched code
    (0x4ccaf6, 0x4ccb84),   # new key code table
    (0x44be20, 0x44be60),   # blanked function, jump table, padding
    (0x4961f0, 0x496200),   # former jump table, now data pointers
    (0x4a39c6, 0x4a3db0),   # blanked original WinMain, then a new jump table
    (0x4a6f2e, 0x4a7080),   # blanked code before a float constant table
    (0x4d5730, 0x4d5840),   # blanked function before a float constant table
    (0x4f8390, 0x4f84a8),   # function replaced by a pointer table
]
# Each range above starts where realign() leaves the cursor after the preceding
# ret, otherwise the hint is ignored.
THREAD_SEGMENTS = [a for a in original.THREAD_SEGMENTS if a != 0x4f2191]
SKIP_INSTRUCTIONS = [a for a in original.SKIP_INSTRUCTIONS if a != 0x4a3aec]

# Functions the original registers that the patch keeps byte for byte but that
# are only reached through pointers (e.g. thread entries passed to the thread
# helper the patch rewrote); without the hint they get merged and the dynamic
# call to them fails.
# 0x4cccc4..0x4ccd98: new stdcall callbacks registered through 0x4cc6d0.
PATCH_CALLBACKS = [0x4cccc4, 0x4ccce4, 0x4ccd04, 0x4ccd78, 0x4ccd98]
# Original functions the patch changed but still references through pointer
# tables in its data (menu callbacks); two of them are now NOP-filled stubs.
POINTER_TARGETS = [0x405fc0, 0x448440, 0x478000]
KNOWN_SUBROUTINES = original.KNOWN_SUBROUTINES + PATCH_CALLBACKS + POINTER_TARGETS + [
    0x408af0, 0x418670, 0x437990, 0x43d5f0, 0x43ebc0, 0x43f7e0,
    0x43fee0, 0x4405c0, 0x443260, 0x446740, 0x448570, 0x453ef0,
    0x45d300, 0x45d630, 0x45d840, 0x45d9a0, 0x490430, 0x496300,
    0x4b67b0, 0x4cce90, 0x4cd4e0, 0x4cdcd0, 0x4d56c0, 0x4edbc0,
    0x4f27a0, 0x4f8b50, 0x4f9260, 0x4f9470, 0x4fb790, 0x4fd490,
    0x52468f, 0x524820,
]


def shifted(ranges):
    return [(a + DLL_SHIFT, b + DLL_SHIFT) for a, b in ranges]


if __name__ == '__main__':
    shutil.rmtree(WORK, ignore_errors=True)
    os.makedirs(WORK)
    os.chdir(WORK)  # the writer emits into ./src/<name>/disassembly
    application = disassembler.disassemble('nfs3hp', os.path.join(INPUT, 'nfs3.exe'), DATA_SEGMENTS,
                                           KNOWN_SUBROUTINES, original.SPLIT_INSTRUCTIONS,
                                           original.THREAD_ROUTINES, THREAD_SEGMENTS,
                                           original.MERGE_ROUTINES)
    eacsnd = disassembler.disassemble('eacsnd', os.path.join(INPUT, 'eacsnd.dll'), type=dll.DLL,
                                      data_segments=shifted([(0xa35749, 0xa3575f), (0xa372bf, 0xa372dd)]),
                                      rebase_after=application)
    softtria = disassembler.disassemble('softtria', os.path.join(INPUT, 'softtria.dll'), type=dll.DLL,
                                        data_segments=shifted([(0xa73e87, 0xa73f00), (0xa78c09, 0xa78c1f),
                                                               (0xa3fc04, 0xa3fc10)]),
                                        rebase_after=eacsnd)
    voodoo2a = disassembler.disassemble('voodoo2a', os.path.join(INPUT, 'voodoo2a.dll'), type=dll.DLL,
                                        data_segments=shifted([(0xa83204, 0xa83210), (0xA86833, 0xA868A2)]),
                                        known_subroutines=[0xA847D0 + DLL_SHIFT, 0xA84810 + DLL_SHIFT],
                                        rebase_after=softtria)
    application.write(THREAD_SEGMENTS, skip_instructions=SKIP_INSTRUCTIONS,
                      dlls=[eacsnd, softtria, voodoo2a])
    # Replace only files whose content changed, so rebuilds stay incremental.
    generated = os.path.join(WORK, 'src', 'nfs3hp', 'disassembly')
    os.makedirs(OUTPUT, exist_ok=True)
    names = set(os.listdir(generated))
    for name in os.listdir(OUTPUT):
        if name not in names:
            os.remove(os.path.join(OUTPUT, name))
    for name in names:
        source, target = os.path.join(generated, name), os.path.join(OUTPUT, name)
        if os.path.exists(target):
            with open(source, 'rb') as a, open(target, 'rb') as b:
                if a.read() == b.read():
                    continue
        shutil.copyfile(source, target)
    os.chdir(ROOT)
    shutil.rmtree(WORK, ignore_errors=True)
    print(OUTPUT)
