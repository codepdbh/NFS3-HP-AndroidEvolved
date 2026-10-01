# NFS3 dependency map

Audited upstream `77ebdb3b6a21925ccfc4fc4c1d712abec3e1945a`.

* `nfs3hp`: `src/nfs3hp/nfs3hp_main.cpp` and every generated `.cpp` in
  `src/nfs3hp/disassembly/`. Generated headers include embedded executable
  sections and symbol registration. No original executable is needed to build.
* `nfs_core`: `src/lib/*.cpp`, `src/lib/sdl-backend/*.cpp`,
  `src/lib/winapi/*.cpp`, and the `ddraw`, `dinput`, `dsound` subdirectories.
* Public runtime: `include/{cpu,x86,fpu,mmx}.h`, `include/lib`, `include/winapi`.
* External dependencies: SDL2, desktop OpenGL or Android GLES3, C++17 runtime.
* `disasm/` and `disassemble_nfs3hp.py` are regeneration tools only.
* `src/nfs2se`, `nfs2se/`, and `disassemble_nfs2se.py` are not NFS3 dependencies.

Upstream migrated to SDL3 in `4f7480b`. The shared SDL backend is restored from
its immediate parent `03a1c93` to satisfy this port's SDL2 requirement. Current
MemoryAccessor/FPU fixes and generated NFS3 sources are retained. Shared backend
changes are necessary for NFS3; no NFS2 source is edited or compiled.

## Portability audit

Guest registers/addresses are fixed-width integers. Host memory is a separate
64-bit pointer plus guest offsets; resource handles are indexes in a map.
MemoryAccessor uses memcpy for unaligned guest accesses. MMX uses SSE intrinsics,
requiring an ARM implementation. Assertions contain x86 `int3`. MemMap assumes
4096-byte protection pages, incompatible with Android 16 KB pages. Optional
pedantic x87 uses NASM and must be rejected on ARM; default FPU is portable
double precision, with accuracy still requiring gameplay validation.

DirectDraw presentation uses immediate mode and matrix stacks. Glide uses
shader/VBO/FBO rendering but desktop GLSL 400, matrix stacks and glClearDepth.
Both require GLES adaptations. Files already support case-insensitive lookup
and separate installation/CD roots. Audio and input already use SDL.
