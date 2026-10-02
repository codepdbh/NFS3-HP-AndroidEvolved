#include "softtria.h"
#include <lib/thread.h>

namespace softtria
{

/* align: skip 0x8b 0xc0 */
void sub_a978dc(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a978dc  b87016aa00             -mov eax, 0xaa1670
    cpu.eax = 11146864 /*0xaa1670*/;
    // 00a978e1  e9ea000000             -jmp 0xa979d0
    return sub_a979d0(app, cpu);
}

/* align: skip 0x8b 0xc0 */
void sub_a978e8(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a978e8  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00a978eb  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00a978ee  059016aa00             +add eax, 0xaa1690
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(11146896 /*0xaa1690*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a978f3  e974000000             -jmp 0xa9796c
    return sub_a9796c(app, cpu);
}

/* align: skip  */
void sub_a978f8(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a978f8  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00a978fb  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00a978fe  059016aa00             +add eax, 0xaa1690
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(11146896 /*0xaa1690*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a97903  e9c8000000             -jmp 0xa979d0
    return sub_a979d0(app, cpu);
}

/* align: skip  */
void sub_a97908(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a97908  e947fcffff             -jmp 0xa97554
    return sub_a97554(app, cpu);
}

/* align: skip 0x8d 0x40 0x00 */
void sub_a97910(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a97910  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a97911  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a97913  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00a97916  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00a97919  059016aa00             -add eax, 0xaa1690
    (cpu.eax) += x86::reg32(x86::sreg32(11146896 /*0xaa1690*/));
    // 00a9791e  e89dffffff             -call 0xa978c0
    cpu.esp -= 4;
    sub_a978c0(app, cpu);
    if (cpu.terminate) return;
    // 00a97923  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a97925  e882fdffff             -call 0xa976ac
    cpu.esp -= 4;
    sub_a976ac(app, cpu);
    if (cpu.terminate) return;
    // 00a9792a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9792b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a9792c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9792c  b89017aa00             -mov eax, 0xaa1790
    cpu.eax = 11147152 /*0xaa1790*/;
    // 00a97931  eb39                   -jmp 0xa9796c
    return sub_a9796c(app, cpu);
}

/* align: skip 0x90 */
void sub_a97934(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a97934  b89017aa00             -mov eax, 0xaa1790
    cpu.eax = 11147152 /*0xaa1790*/;
    // 00a97939  e992000000             -jmp 0xa979d0
    return sub_a979d0(app, cpu);
}

/* align: skip 0x8b 0xc0 */
void sub_a97940(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a97940  b88016aa00             -mov eax, 0xaa1680
    cpu.eax = 11146880 /*0xaa1680*/;
    // 00a97945  eb25                   -jmp 0xa9796c
    return sub_a9796c(app, cpu);
}

/* align: skip 0x90 */
void sub_a97948(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a97948  b88016aa00             -mov eax, 0xaa1680
    cpu.eax = 11146880 /*0xaa1680*/;
    // 00a9794d  e97e000000             -jmp 0xa979d0
    return sub_a979d0(app, cpu);
}

/* align: skip 0x8b 0xc0 */
void sub_a97954(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a97954  b8b01daa00             -mov eax, 0xaa1db0
    cpu.eax = 11148720 /*0xaa1db0*/;
    // 00a97959  eb11                   -jmp 0xa9796c
    return sub_a9796c(app, cpu);
}

/* align: skip 0x90 */
void sub_a9795c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9795c  b8b01daa00             -mov eax, 0xaa1db0
    cpu.eax = 11148720 /*0xaa1db0*/;
    // 00a97961  eb6d                   -jmp 0xa979d0
    return sub_a979d0(app, cpu);
}

/* align: skip 0x90 */
void sub_a97964(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a97964  b8c01daa00             -mov eax, 0xaa1dc0
    cpu.eax = 11148736 /*0xaa1dc0*/;
    // 00a97969  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 00a9796c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a9796d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a9796e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a9796f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a97970  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a97971  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a97973  2eff15cccda900         -call dword ptr cs:[0xa9cdcc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11128268) /* 0xa9cdcc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a9797a  8b5308                 -mov edx, dword ptr [ebx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 00a9797d  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a9797f  39d0                   +cmp eax, edx
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a97981  743b                   -je 0xa979be
    if (cpu.flags.zf)
    {
        goto L_0x00a979be;
    }
    // 00a97983  837b0400               +cmp dword ptr [ebx + 4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a97987  7528                   -jne 0xa979b1
    if (!cpu.flags.zf)
    {
        goto L_0x00a979b1;
    }
    // 00a97989  b8a01daa00             -mov eax, 0xaa1da0
    cpu.eax = 11148704 /*0xaa1da0*/;
    // 00a9798e  e8d9ffffff             -call 0xa9796c
    cpu.esp -= 4;
    sub_a9796c(app, cpu);
    if (cpu.terminate) return;
    // 00a97993  837b0400               +cmp dword ptr [ebx + 4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a97997  750e                   -jne 0xa979a7
    if (!cpu.flags.zf)
    {
        goto L_0x00a979a7;
    }
    // 00a97999  e8f6fdffff             -call 0xa97794
    cpu.esp -= 4;
    sub_a97794(app, cpu);
    if (cpu.terminate) return;
    // 00a9799e  c7430401000000         -mov dword ptr [ebx + 4], 1
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = 1 /*0x1*/;
    // 00a979a5  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
L_0x00a979a7:
    // 00a979a7  b8a01daa00             -mov eax, 0xaa1da0
    cpu.eax = 11148704 /*0xaa1da0*/;
    // 00a979ac  e81f000000             -call 0xa979d0
    cpu.esp -= 4;
    sub_a979d0(app, cpu);
    if (cpu.terminate) return;
L_0x00a979b1:
    // 00a979b1  8b2b                   -mov ebp, dword ptr [ebx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx);
    // 00a979b3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a979b4  2eff15a0cda900         -call dword ptr cs:[0xa9cda0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11128224) /* 0xa9cda0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a979bb  897308                 -mov dword ptr [ebx + 8], esi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.esi;
L_0x00a979be:
    // 00a979be  ff430c                 -inc dword ptr [ebx + 0xc]
    (app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */))++;
    // 00a979c1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a979c2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a979c3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a979c4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a979c5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a979c6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a9796c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00a9796c;
    // 00a97964  b8c01daa00             -mov eax, 0xaa1dc0
    cpu.eax = 11148736 /*0xaa1dc0*/;
    // 00a97969  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_entry_0x00a9796c:
    // 00a9796c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a9796d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a9796e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a9796f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a97970  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a97971  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a97973  2eff15cccda900         -call dword ptr cs:[0xa9cdcc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11128268) /* 0xa9cdcc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a9797a  8b5308                 -mov edx, dword ptr [ebx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 00a9797d  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a9797f  39d0                   +cmp eax, edx
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a97981  743b                   -je 0xa979be
    if (cpu.flags.zf)
    {
        goto L_0x00a979be;
    }
    // 00a97983  837b0400               +cmp dword ptr [ebx + 4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a97987  7528                   -jne 0xa979b1
    if (!cpu.flags.zf)
    {
        goto L_0x00a979b1;
    }
    // 00a97989  b8a01daa00             -mov eax, 0xaa1da0
    cpu.eax = 11148704 /*0xaa1da0*/;
    // 00a9798e  e8d9ffffff             -call 0xa9796c
    cpu.esp -= 4;
    sub_a9796c(app, cpu);
    if (cpu.terminate) return;
    // 00a97993  837b0400               +cmp dword ptr [ebx + 4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a97997  750e                   -jne 0xa979a7
    if (!cpu.flags.zf)
    {
        goto L_0x00a979a7;
    }
    // 00a97999  e8f6fdffff             -call 0xa97794
    cpu.esp -= 4;
    sub_a97794(app, cpu);
    if (cpu.terminate) return;
    // 00a9799e  c7430401000000         -mov dword ptr [ebx + 4], 1
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = 1 /*0x1*/;
    // 00a979a5  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
L_0x00a979a7:
    // 00a979a7  b8a01daa00             -mov eax, 0xaa1da0
    cpu.eax = 11148704 /*0xaa1da0*/;
    // 00a979ac  e81f000000             -call 0xa979d0
    cpu.esp -= 4;
    sub_a979d0(app, cpu);
    if (cpu.terminate) return;
L_0x00a979b1:
    // 00a979b1  8b2b                   -mov ebp, dword ptr [ebx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx);
    // 00a979b3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a979b4  2eff15a0cda900         -call dword ptr cs:[0xa9cda0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11128224) /* 0xa9cda0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a979bb  897308                 -mov dword ptr [ebx + 8], esi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.esi;
L_0x00a979be:
    // 00a979be  ff430c                 -inc dword ptr [ebx + 0xc]
    (app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */))++;
    // 00a979c1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a979c2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a979c3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a979c4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a979c5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a979c6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void sub_a979c8(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a979c8  b8c01daa00             -mov eax, 0xaa1dc0
    cpu.eax = 11148736 /*0xaa1dc0*/;
    // 00a979cd  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 00a979d0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a979d1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a979d2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a979d3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a979d4  8b500c                 -mov edx, dword ptr [eax + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00a979d7  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a979d9  7617                   -jbe 0xa979f2
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a979f2;
    }
    // 00a979db  8d5aff                 -lea ebx, [edx - 1]
    cpu.ebx = x86::reg32(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 00a979de  89580c                 -mov dword ptr [eax + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 00a979e1  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a979e3  750d                   -jne 0xa979f2
    if (!cpu.flags.zf)
    {
        goto L_0x00a979f2;
    }
    // 00a979e5  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax);
    // 00a979e7  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a979e8  895808                 -mov dword ptr [eax + 8], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 00a979eb  2eff150ccea900         -call dword ptr cs:[0xa9ce0c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11128332) /* 0xa9ce0c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00a979f2:
    // 00a979f2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a979f3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a979f4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a979f5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a979f6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a979d0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00a979d0;
    // 00a979c8  b8c01daa00             -mov eax, 0xaa1dc0
    cpu.eax = 11148736 /*0xaa1dc0*/;
    // 00a979cd  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_entry_0x00a979d0:
    // 00a979d0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a979d1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a979d2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a979d3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a979d4  8b500c                 -mov edx, dword ptr [eax + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00a979d7  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a979d9  7617                   -jbe 0xa979f2
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a979f2;
    }
    // 00a979db  8d5aff                 -lea ebx, [edx - 1]
    cpu.ebx = x86::reg32(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 00a979de  89580c                 -mov dword ptr [eax + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 00a979e1  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a979e3  750d                   -jne 0xa979f2
    if (!cpu.flags.zf)
    {
        goto L_0x00a979f2;
    }
    // 00a979e5  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax);
    // 00a979e7  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a979e8  895808                 -mov dword ptr [eax + 8], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 00a979eb  2eff150ccea900         -call dword ptr cs:[0xa9ce0c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11128332) /* 0xa9ce0c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00a979f2:
    // 00a979f2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a979f3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a979f4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a979f5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a979f6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void sub_a979f8(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a979f8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a979f9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a979fa  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a979fb  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a979fc  2eff15e4cda900         -call dword ptr cs:[0xa9cde4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11128292) /* 0xa9cde4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a97a03  8b1590e2a900           -mov edx, dword ptr [0xa9e290]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11133584) /* 0xa9e290 */);
    // 00a97a09  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a97a0a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a97a0c  2eff1548cea900         -call dword ptr cs:[0xa9ce48]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11128392) /* 0xa9ce48 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a97a13  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a97a15  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a97a17  7507                   -jne 0xa97a20
    if (!cpu.flags.zf)
    {
        goto L_0x00a97a20;
    }
    // 00a97a19  e822170000             -call 0xa99140
    cpu.esp -= 4;
    sub_a99140(app, cpu);
    if (cpu.terminate) return;
    // 00a97a1e  eb0b                   -jmp 0xa97a2b
    goto L_0x00a97a2b;
L_0x00a97a20:
    // 00a97a20  80785300               +cmp byte ptr [eax + 0x53], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(83) /* 0x53 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a97a24  7407                   -je 0xa97a2d
    if (cpu.flags.zf)
    {
        goto L_0x00a97a2d;
    }
    // 00a97a26  e851170000             -call 0xa9917c
    cpu.esp -= 4;
    sub_a9917c(app, cpu);
    if (cpu.terminate) return;
L_0x00a97a2b:
    // 00a97a2b  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x00a97a2d:
    // 00a97a2d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a97a2e  2eff1534cea900         -call dword ptr cs:[0xa9ce34]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11128372) /* 0xa9ce34 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a97a35  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a97a37  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a97a38  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a97a39  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a97a3a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a97a3b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a97a3c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a97a3c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a97a3d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a97a3e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a97a40  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a97a42  7526                   -jne 0xa97a6a
    if (!cpu.flags.zf)
    {
        goto L_0x00a97a6a;
    }
    // 00a97a44  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a97a49  8b15dce5a900           -mov edx, dword ptr [0xa9e5dc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11134428) /* 0xa9e5dc */);
    // 00a97a4f  e8cc160000             -call 0xa99120
    cpu.esp -= 4;
    sub_a99120(app, cpu);
    if (cpu.terminate) return;
    // 00a97a54  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a97a56  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a97a58  7410                   -je 0xa97a6a
    if (cpu.flags.zf)
    {
        goto L_0x00a97a6a;
    }
    // 00a97a5a  8b1ddce5a900           -mov ebx, dword ptr [0xa9e5dc]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(11134428) /* 0xa9e5dc */);
    // 00a97a60  c6405201               -mov byte ptr [eax + 0x52], 1
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(82) /* 0x52 */) = 1 /*0x1*/;
    // 00a97a64  8998f0000000           -mov dword ptr [eax + 0xf0], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(240) /* 0xf0 */) = cpu.ebx;
L_0x00a97a6a:
    // 00a97a6a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a97a6c  e81f190000             -call 0xa99390
    cpu.esp -= 4;
    sub_a99390(app, cpu);
    if (cpu.terminate) return;
    // 00a97a71  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a97a73  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a97a74  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a97a75  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void sub_a97a78(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a97a78  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a97a79  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a97a7a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a97a7b  8b1d90e2a900           -mov ebx, dword ptr [0xa9e290]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(11133584) /* 0xa9e290 */);
    // 00a97a81  83fbff                 +cmp ebx, -1
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a97a84  753b                   -jne 0xa97ac1
    if (!cpu.flags.zf)
    {
        goto L_0x00a97ac1;
    }
    // 00a97a86  2eff1540cea900         -call dword ptr cs:[0xa9ce40]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11128384) /* 0xa9ce40 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a97a8d  668b1571e3a900         -mov dx, word ptr [0xa9e371]
    cpu.dx = app->getMemory<x86::reg16>(x86::reg32(11133809) /* 0xa9e371 */);
    // 00a97a94  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a97a96  6681fa0080             +cmp dx, 0x8000
    {
        x86::reg16 tmp1 = cpu.dx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(32768 /*0x8000*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00a97a9b  7224                   -jb 0xa97ac1
    if (cpu.flags.cf)
    {
        goto L_0x00a97ac1;
    }
    // 00a97a9d  803d6fe3a90004         +cmp byte ptr [0xa9e36f], 4
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(11133807) /* 0xa9e36f */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(4 /*0x4*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a97aa4  731b                   -jae 0xa97ac1
    if (!cpu.flags.cf)
    {
        goto L_0x00a97ac1;
    }
L_0x00a97aa6:
    // 00a97aa6  83fbff                 +cmp ebx, -1
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a97aa9  7416                   -je 0xa97ac1
    if (cpu.flags.zf)
    {
        goto L_0x00a97ac1;
    }
    // 00a97aab  83fb02                 +cmp ebx, 2
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a97aae  7711                   -ja 0xa97ac1
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a97ac1;
    }
    // 00a97ab0  891d90e2a900           -mov dword ptr [0xa9e290], ebx
    app->getMemory<x86::reg32>(x86::reg32(11133584) /* 0xa9e290 */) = cpu.ebx;
    // 00a97ab6  2eff1540cea900         -call dword ptr cs:[0xa9ce40]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11128384) /* 0xa9ce40 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a97abd  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a97abf  ebe5                   -jmp 0xa97aa6
    goto L_0x00a97aa6;
L_0x00a97ac1:
    // 00a97ac1  83fbff                 +cmp ebx, -1
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a97ac4  0f95c0                 -setne al
    cpu.al = !cpu.flags.zf;
    // 00a97ac7  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00a97acc  891d90e2a900           -mov dword ptr [0xa9e290], ebx
    app->getMemory<x86::reg32>(x86::reg32(11133584) /* 0xa9e290 */) = cpu.ebx;
    // 00a97ad2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a97ad3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a97ad4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a97ad5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void sub_a97ad8(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a97ad8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a97ad9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a97ada  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a97adb  833d90e2a900ff         +cmp dword ptr [0xa9e290], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(11133584) /* 0xa9e290 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a97ae2  7506                   -jne 0xa97aea
    if (!cpu.flags.zf)
    {
        goto L_0x00a97aea;
    }
    // 00a97ae4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a97ae6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a97ae7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a97ae8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a97ae9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a97aea:
    // 00a97aea  e84dffffff             -call 0xa97a3c
    cpu.esp -= 4;
    sub_a97a3c(app, cpu);
    if (cpu.terminate) return;
    // 00a97aef  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a97af1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a97af3  7432                   -je 0xa97b27
    if (cpu.flags.zf)
    {
        goto L_0x00a97b27;
    }
    // 00a97af5  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00a97af7  8b80da000000           -mov eax, dword ptr [eax + 0xda]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(218) /* 0xda */);
    // 00a97afd  e84e170000             -call 0xa99250
    cpu.esp -= 4;
    sub_a99250(app, cpu);
    if (cpu.terminate) return;
    // 00a97b02  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a97b04  750d                   -jne 0xa97b13
    if (!cpu.flags.zf)
    {
        goto L_0x00a97b13;
    }
    // 00a97b06  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a97b08  e863d2ffff             -call 0xa94d70
    cpu.esp -= 4;
    sub_a94d70(app, cpu);
    if (cpu.terminate) return;
    // 00a97b0d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a97b0f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a97b10  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a97b11  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a97b12  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a97b13:
    // 00a97b13  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a97b14  8b1d90e2a900           -mov ebx, dword ptr [0xa9e290]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(11133584) /* 0xa9e290 */);
    // 00a97b1a  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a97b1b  2eff154ccea900         -call dword ptr cs:[0xa9ce4c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11128396) /* 0xa9ce4c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a97b22  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x00a97b27:
    // 00a97b27  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a97b28  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a97b29  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a97b2a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void sub_a97b2c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a97b2c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a97b2d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a97b2e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a97b2f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a97b30  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a97b31  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a97b33  8b1590e2a900           -mov edx, dword ptr [0xa9e290]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11133584) /* 0xa9e290 */);
    // 00a97b39  83faff                 +cmp edx, -1
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a97b3c  743d                   -je 0xa97b7b
    if (cpu.flags.zf)
    {
        goto L_0x00a97b7b;
    }
    // 00a97b3e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a97b3f  2eff1548cea900         -call dword ptr cs:[0xa9ce48]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11128392) /* 0xa9ce48 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a97b46  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a97b48  7431                   -je 0xa97b7b
    if (cpu.flags.zf)
    {
        goto L_0x00a97b7b;
    }
    // 00a97b4a  8bb0de000000           -mov esi, dword ptr [eax + 0xde]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(222) /* 0xde */);
    // 00a97b50  8b80da000000           -mov eax, dword ptr [eax + 0xda]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(218) /* 0xda */);
    // 00a97b56  e859170000             -call 0xa992b4
    cpu.esp -= 4;
    sub_a992b4(app, cpu);
    if (cpu.terminate) return;
    // 00a97b5b  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a97b5d  8b3d90e2a900           -mov edi, dword ptr [0xa9e290]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(11133584) /* 0xa9e290 */);
    // 00a97b63  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a97b64  2eff154ccea900         -call dword ptr cs:[0xa9ce4c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11128396) /* 0xa9ce4c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a97b6b  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a97b6d  740c                   -je 0xa97b7b
    if (cpu.flags.zf)
    {
        goto L_0x00a97b7b;
    }
    // 00a97b6f  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a97b71  7408                   -je 0xa97b7b
    if (cpu.flags.zf)
    {
        goto L_0x00a97b7b;
    }
    // 00a97b73  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a97b74  2eff1588cda900         -call dword ptr cs:[0xa9cd88]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11128200) /* 0xa9cd88 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00a97b7b:
    // 00a97b7b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a97b7c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a97b7d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a97b7e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a97b7f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a97b80  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_a97b84(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a97b84  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a97b89  e89effffff             -call 0xa97b2c
    cpu.esp -= 4;
    sub_a97b2c(app, cpu);
    if (cpu.terminate) return;
    // 00a97b8e  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
    // 00a97b90  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a97b91  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a97b92  8b1590e2a900           -mov edx, dword ptr [0xa9e290]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11133584) /* 0xa9e290 */);
    // 00a97b98  83faff                 +cmp edx, -1
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a97b9b  7412                   -je 0xa97baf
    if (cpu.flags.zf)
    {
        goto L_0x00a97baf;
    }
    // 00a97b9d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a97b9e  2eff1544cea900         -call dword ptr cs:[0xa9ce44]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11128388) /* 0xa9ce44 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a97ba5  c70590e2a900ffffffff   -mov dword ptr [0xa9e290], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(11133584) /* 0xa9e290 */) = 4294967295 /*0xffffffff*/;
L_0x00a97baf:
    // 00a97baf  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a97bb0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a97bb1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a97b90(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00a97b90;
    // 00a97b84  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a97b89  e89effffff             -call 0xa97b2c
    cpu.esp -= 4;
    sub_a97b2c(app, cpu);
    if (cpu.terminate) return;
    // 00a97b8e  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_entry_0x00a97b90:
    // 00a97b90  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a97b91  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a97b92  8b1590e2a900           -mov edx, dword ptr [0xa9e290]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11133584) /* 0xa9e290 */);
    // 00a97b98  83faff                 +cmp edx, -1
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a97b9b  7412                   -je 0xa97baf
    if (cpu.flags.zf)
    {
        goto L_0x00a97baf;
    }
    // 00a97b9d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a97b9e  2eff1544cea900         -call dword ptr cs:[0xa9ce44]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11128388) /* 0xa9ce44 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a97ba5  c70590e2a900ffffffff   -mov dword ptr [0xa9e290], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(11133584) /* 0xa9e290 */) = 4294967295 /*0xffffffff*/;
L_0x00a97baf:
    // 00a97baf  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a97bb0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a97bb1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void sub_a97bb4(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a97bb4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a97bb5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a97bb6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a97bb7  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a97bb8  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a97bb9  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a97bba  bae878a900             -mov edx, 0xa978e8
    cpu.edx = 11106536 /*0xa978e8*/;
    // 00a97bbf  bbf878a900             -mov ebx, 0xa978f8
    cpu.ebx = 11106552 /*0xa978f8*/;
    // 00a97bc4  b90879a900             -mov ecx, 0xa97908
    cpu.ecx = 11106568 /*0xa97908*/;
    // 00a97bc9  be1079a900             -mov esi, 0xa97910
    cpu.esi = 11106576 /*0xa97910*/;
    // 00a97bce  bfd078a900             -mov edi, 0xa978d0
    cpu.edi = 11106512 /*0xa978d0*/;
    // 00a97bd3  bddc78a900             -mov ebp, 0xa978dc
    cpu.ebp = 11106524 /*0xa978dc*/;
    // 00a97bd8  b85479a900             -mov eax, 0xa97954
    cpu.eax = 11106644 /*0xa97954*/;
    // 00a97bdd  891598e2a900           -mov dword ptr [0xa9e298], edx
    app->getMemory<x86::reg32>(x86::reg32(11133592) /* 0xa9e298 */) = cpu.edx;
    // 00a97be3  891d9ce2a900           -mov dword ptr [0xa9e29c], ebx
    app->getMemory<x86::reg32>(x86::reg32(11133596) /* 0xa9e29c */) = cpu.ebx;
    // 00a97be9  890da0e2a900           -mov dword ptr [0xa9e2a0], ecx
    app->getMemory<x86::reg32>(x86::reg32(11133600) /* 0xa9e2a0 */) = cpu.ecx;
    // 00a97bef  8935a4e2a900           -mov dword ptr [0xa9e2a4], esi
    app->getMemory<x86::reg32>(x86::reg32(11133604) /* 0xa9e2a4 */) = cpu.esi;
    // 00a97bf5  893da8e2a900           -mov dword ptr [0xa9e2a8], edi
    app->getMemory<x86::reg32>(x86::reg32(11133608) /* 0xa9e2a8 */) = cpu.edi;
    // 00a97bfb  892dace2a900           -mov dword ptr [0xa9e2ac], ebp
    app->getMemory<x86::reg32>(x86::reg32(11133612) /* 0xa9e2ac */) = cpu.ebp;
    // 00a97c01  a3c0e2a900             -mov dword ptr [0xa9e2c0], eax
    app->getMemory<x86::reg32>(x86::reg32(11133632) /* 0xa9e2c0 */) = cpu.eax;
    // 00a97c06  ba5c79a900             -mov edx, 0xa9795c
    cpu.edx = 11106652 /*0xa9795c*/;
    // 00a97c0b  bb6c79a900             -mov ebx, 0xa9796c
    cpu.ebx = 11106668 /*0xa9796c*/;
    // 00a97c10  b9d079a900             -mov ecx, 0xa979d0
    cpu.ecx = 11106768 /*0xa979d0*/;
    // 00a97c15  bec078a900             -mov esi, 0xa978c0
    cpu.esi = 11106496 /*0xa978c0*/;
    // 00a97c1a  bf2c79a900             -mov edi, 0xa9792c
    cpu.edi = 11106604 /*0xa9792c*/;
    // 00a97c1f  bd4079a900             -mov ebp, 0xa97940
    cpu.ebp = 11106624 /*0xa97940*/;
    // 00a97c24  b83479a900             -mov eax, 0xa97934
    cpu.eax = 11106612 /*0xa97934*/;
    // 00a97c29  8915c4e2a900           -mov dword ptr [0xa9e2c4], edx
    app->getMemory<x86::reg32>(x86::reg32(11133636) /* 0xa9e2c4 */) = cpu.edx;
    // 00a97c2f  891d94e3a900           -mov dword ptr [0xa9e394], ebx
    app->getMemory<x86::reg32>(x86::reg32(11133844) /* 0xa9e394 */) = cpu.ebx;
    // 00a97c35  890d98e3a900           -mov dword ptr [0xa9e398], ecx
    app->getMemory<x86::reg32>(x86::reg32(11133848) /* 0xa9e398 */) = cpu.ecx;
    // 00a97c3b  89359ce3a900           -mov dword ptr [0xa9e39c], esi
    app->getMemory<x86::reg32>(x86::reg32(11133852) /* 0xa9e39c */) = cpu.esi;
    // 00a97c41  893db0e2a900           -mov dword ptr [0xa9e2b0], edi
    app->getMemory<x86::reg32>(x86::reg32(11133616) /* 0xa9e2b0 */) = cpu.edi;
    // 00a97c47  892db4e2a900           -mov dword ptr [0xa9e2b4], ebp
    app->getMemory<x86::reg32>(x86::reg32(11133620) /* 0xa9e2b4 */) = cpu.ebp;
    // 00a97c4d  a3b8e2a900             -mov dword ptr [0xa9e2b8], eax
    app->getMemory<x86::reg32>(x86::reg32(11133624) /* 0xa9e2b8 */) = cpu.eax;
    // 00a97c52  ba4879a900             -mov edx, 0xa97948
    cpu.edx = 11106632 /*0xa97948*/;
    // 00a97c57  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00a97c5c  b96479a900             -mov ecx, 0xa97964
    cpu.ecx = 11106660 /*0xa97964*/;
    // 00a97c61  bec879a900             -mov esi, 0xa979c8
    cpu.esi = 11106760 /*0xa979c8*/;
    // 00a97c66  bf847ba900             -mov edi, 0xa97b84
    cpu.edi = 11107204 /*0xa97b84*/;
    // 00a97c6b  8915bce2a900           -mov dword ptr [0xa9e2bc], edx
    app->getMemory<x86::reg32>(x86::reg32(11133628) /* 0xa9e2bc */) = cpu.edx;
    // 00a97c71  e81efbffff             -call 0xa97794
    cpu.esp -= 4;
    sub_a97794(app, cpu);
    if (cpu.terminate) return;
    // 00a97c76  8b151c10aa00           -mov edx, dword ptr [0xaa101c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11145244) /* 0xaa101c */);
    // 00a97c7c  a3a01daa00             -mov dword ptr [0xaa1da0], eax
    app->getMemory<x86::reg32>(x86::reg32(11148704) /* 0xaa1da0 */) = cpu.eax;
    // 00a97c81  891da41daa00           -mov dword ptr [0xaa1da4], ebx
    app->getMemory<x86::reg32>(x86::reg32(11148708) /* 0xaa1da4 */) = cpu.ebx;
    // 00a97c87  890dc8e2a900           -mov dword ptr [0xa9e2c8], ecx
    app->getMemory<x86::reg32>(x86::reg32(11133640) /* 0xa9e2c8 */) = cpu.ecx;
    // 00a97c8d  8935cce2a900           -mov dword ptr [0xa9e2cc], esi
    app->getMemory<x86::reg32>(x86::reg32(11133644) /* 0xa9e2cc */) = cpu.esi;
    // 00a97c93  8b82da000000           -mov eax, dword ptr [edx + 0xda]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(218) /* 0xda */);
    // 00a97c99  893dd0e2a900           -mov dword ptr [0xa9e2d0], edi
    app->getMemory<x86::reg32>(x86::reg32(11133648) /* 0xa9e2d0 */) = cpu.edi;
    // 00a97c9f  e8ac150000             -call 0xa99250
    cpu.esp -= 4;
    sub_a99250(app, cpu);
    if (cpu.terminate) return;
    // 00a97ca4  8b2d1c10aa00           -mov ebp, dword ptr [0xaa101c]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(11145244) /* 0xaa101c */);
    // 00a97caa  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a97cab  a190e2a900             -mov eax, dword ptr [0xa9e290]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11133584) /* 0xa9e290 */);
    // 00a97cb0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a97cb1  2eff154ccea900         -call dword ptr cs:[0xa9ce4c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11128396) /* 0xa9ce4c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a97cb8  c70594e2a900f879a900   -mov dword ptr [0xa9e294], 0xa979f8
    app->getMemory<x86::reg32>(x86::reg32(11133588) /* 0xa9e294 */) = 11106808 /*0xa979f8*/;
    // 00a97cc2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a97cc3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a97cc4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a97cc5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a97cc6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a97cc7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a97cc8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_a97ccc(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a97ccc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a97ccd  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a97cce  b87016aa00             -mov eax, 0xaa1670
    cpu.eax = 11146864 /*0xaa1670*/;
    // 00a97cd3  ba9016aa00             -mov edx, 0xaa1690
    cpu.edx = 11146896 /*0xaa1690*/;
    // 00a97cd8  ff159ce3a900           -call dword ptr [0xa9e39c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11133852) /* 0xa9e39c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a97cde  8d9a00010000           -lea ebx, [edx + 0x100]
    cpu.ebx = x86::reg32(cpu.edx + x86::reg32(256) /* 0x100 */);
L_0x00a97ce4:
    // 00a97ce4  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a97ce6  83c210                 -add edx, 0x10
    (cpu.edx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00a97ce9  ff159ce3a900           -call dword ptr [0xa9e39c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11133852) /* 0xa9e39c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a97cef  39da                   +cmp edx, ebx
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a97cf1  75f1                   -jne 0xa97ce4
    if (!cpu.flags.zf)
    {
        goto L_0x00a97ce4;
    }
    // 00a97cf3  b8c01daa00             -mov eax, 0xaa1dc0
    cpu.eax = 11148736 /*0xaa1dc0*/;
    // 00a97cf8  ff159ce3a900           -call dword ptr [0xa9e39c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11133852) /* 0xa9e39c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a97cfe  e865fbffff             -call 0xa97868
    cpu.esp -= 4;
    sub_a97868(app, cpu);
    if (cpu.terminate) return;
    // 00a97d03  e8b8160000             -call 0xa993c0
    cpu.esp -= 4;
    sub_a993c0(app, cpu);
    if (cpu.terminate) return;
    // 00a97d08  e813090000             -call 0xa98620
    cpu.esp -= 4;
    sub_a98620(app, cpu);
    if (cpu.terminate) return;
    // 00a97d0d  b89017aa00             -mov eax, 0xaa1790
    cpu.eax = 11147152 /*0xaa1790*/;
    // 00a97d12  ff159ce3a900           -call dword ptr [0xa9e39c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11133852) /* 0xa9e39c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a97d18  b88016aa00             -mov eax, 0xaa1680
    cpu.eax = 11146880 /*0xaa1680*/;
    // 00a97d1d  ff159ce3a900           -call dword ptr [0xa9e39c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11133852) /* 0xa9e39c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a97d23  b8b01daa00             -mov eax, 0xaa1db0
    cpu.eax = 11148720 /*0xaa1db0*/;
    // 00a97d28  ff159ce3a900           -call dword ptr [0xa9e39c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11133852) /* 0xa9e39c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a97d2e  b8a01daa00             -mov eax, 0xaa1da0
    cpu.eax = 11148704 /*0xaa1da0*/;
    // 00a97d33  ff159ce3a900           -call dword ptr [0xa9e39c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11133852) /* 0xa9e39c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a97d39  e8fafaffff             -call 0xa97838
    cpu.esp -= 4;
    sub_a97838(app, cpu);
    if (cpu.terminate) return;
    // 00a97d3e  e84dfeffff             -call 0xa97b90
    cpu.esp -= 4;
    sub_a97b90(app, cpu);
    if (cpu.terminate) return;
    // 00a97d43  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a97d44  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a97d45  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a97d50(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a97d50  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a97d51  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a97d52  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a97d53  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a97d54  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00a97d56  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00a97d58  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00a97d5a  2eff1504cea900         -call dword ptr cs:[0xa9ce04]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11128324) /* 0xa9ce04 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a97d61  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 00a97d64  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00a97d69  663d0080               +cmp ax, 0x8000
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(32768 /*0x8000*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00a97d6d  730f                   -jae 0xa97d7e
    if (!cpu.flags.cf)
    {
        goto L_0x00a97d7e;
    }
    // 00a97d6f  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a97d70  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a97d71  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a97d72  2eff15eccda900         -call dword ptr cs:[0xa9cdec]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11128300) /* 0xa9cdec */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a97d79  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a97d7a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a97d7b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a97d7c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a97d7d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a97d7e:
    // 00a97d7e  b808020000             -mov eax, 0x208
    cpu.eax = 520 /*0x208*/;
    // 00a97d83  e8f8ceffff             -call 0xa94c80
    cpu.esp -= 4;
    sub_a94c80(app, cpu);
    if (cpu.terminate) return;
    // 00a97d88  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a97d8a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a97d8c  7452                   -je 0xa97de0
    if (cpu.flags.zf)
    {
        goto L_0x00a97de0;
    }
    // 00a97d8e  6808020000             -push 0x208
    app->getMemory<x86::reg32>(cpu.esp-4) = 520 /*0x208*/;
    cpu.esp -= 4;
    // 00a97d93  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a97d94  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a97d95  2eff15e8cda900         -call dword ptr cs:[0xa9cde8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11128296) /* 0xa9cde8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a97d9c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a97d9e  750e                   -jne 0xa97dae
    if (!cpu.flags.zf)
    {
        goto L_0x00a97dae;
    }
    // 00a97da0  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a97da2  e8c9cfffff             -call 0xa94d70
    cpu.esp -= 4;
    sub_a94d70(app, cpu);
    if (cpu.terminate) return;
    // 00a97da7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a97da9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a97daa  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a97dab  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a97dac  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a97dad  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a97dae:
    // 00a97dae  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a97daf  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a97db0  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 00a97db2  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a97db3  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00a97db5  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00a97db7  2eff1518cea900         -call dword ptr cs:[0xa9ce18]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11128344) /* 0xa9ce18 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a97dbe  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00a97dc0  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a97dc2  e8a9cfffff             -call 0xa94d70
    cpu.esp -= 4;
    sub_a94d70(app, cpu);
    if (cpu.terminate) return;
    // 00a97dc7  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00a97dc9  7507                   -jne 0xa97dd2
    if (!cpu.flags.zf)
    {
        goto L_0x00a97dd2;
    }
    // 00a97dcb  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a97dcd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a97dce  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a97dcf  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a97dd0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a97dd1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a97dd2:
    // 00a97dd2  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a97dd4  66c7447efe0000         -mov word ptr [esi + edi*2 - 2], 0
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(-2) /* -0x2 */ + cpu.edi * 2) = 0 /*0x0*/;
    // 00a97ddb  e8f0150000             -call 0xa993d0
    cpu.esp -= 4;
    sub_a993d0(app, cpu);
    if (cpu.terminate) return;
L_0x00a97de0:
    // 00a97de0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a97de1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a97de2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a97de3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a97de4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a97df0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a97df0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a97df1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a97df2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a97df3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a97df4  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a97df6  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a97df8  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a97df9  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a97dfb  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a97dfd  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a97dff  49                     -dec ecx
    (cpu.ecx)--;
    // 00a97e00  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a97e02  f2ae                   -repne scasb al, byte ptr es:[edi]
    while (cpu.ecx)
    {
        {
            x86::reg8 tmp1 = cpu.al;
            x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ees + cpu.edi)));
            x86::reg8 result = tmp1 - tmp2;
            cpu.flags.cf = tmp1 < tmp2;
            cpu.flags.of = 1 & (tmp1 >> 7);
            cpu.flags.of ^= 1 & (result >> 7);
            cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
            cpu.set_szp(result);
        }
        if (cpu.flags.df)
        {
            cpu.edi -= 1;
        }
        else
        {
            cpu.edi += 1;
        }
        --cpu.ecx;
        if (cpu.flags.zf)
            break;
    }
    // 00a97e04  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00a97e06  49                     -dec ecx
    (cpu.ecx)--;
    // 00a97e07  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a97e08  41                     -inc ecx
    (cpu.ecx)++;
    // 00a97e09  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a97e0b  e870ceffff             -call 0xa94c80
    cpu.esp -= 4;
    sub_a94c80(app, cpu);
    if (cpu.terminate) return;
    // 00a97e10  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a97e12  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a97e14  7418                   -je 0xa97e2e
    if (cpu.flags.zf)
    {
        goto L_0x00a97e2e;
    }
    // 00a97e16  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a97e18  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a97e19  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a97e1b  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a97e1d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a97e1e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a97e20  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00a97e23  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
    while (cpu.ecx)
    {
        app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
        if (cpu.flags.df)
        {
            cpu.edi -= 4;
            cpu.esi -= 4;
        }
        else
        {
            cpu.edi += 4;
            cpu.esi += 4;
        }
        --cpu.ecx;
    }
    // 00a97e25  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00a97e27  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00a97e2a  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
    while (cpu.ecx)
    {
        app->getMemory<x86::reg8>(cpu.ees + cpu.edi) = app->getMemory<x86::reg8>(cpu.esi);
        if (cpu.flags.df)
        {
            cpu.edi -= 1;
            cpu.esi -= 1;
        }
        else
        {
            cpu.edi += 1;
            cpu.esi += 1;
        }
        --cpu.ecx;
        if (cpu.flags.zf)
            break;
    }
    // 00a97e2c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a97e2d  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
L_0x00a97e2e:
    // 00a97e2e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a97e30  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a97e31  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a97e32  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a97e33  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a97e34  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a97e40(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a97e40  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a97e41  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a97e42  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a97e43  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a97e45  e886150000             -call 0xa993d0
    cpu.esp -= 4;
    sub_a993d0(app, cpu);
    if (cpu.terminate) return;
    // 00a97e4a  40                     -inc eax
    (cpu.eax)++;
    // 00a97e4b  8d1c4500000000         -lea ebx, [eax*2]
    cpu.ebx = x86::reg32(cpu.eax * 2);
    // 00a97e52  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a97e54  e827ceffff             -call 0xa94c80
    cpu.esp -= 4;
    sub_a94c80(app, cpu);
    if (cpu.terminate) return;
    // 00a97e59  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a97e5b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a97e5d  7405                   -je 0xa97e64
    if (cpu.flags.zf)
    {
        goto L_0x00a97e64;
    }
    // 00a97e5f  e88c150000             -call 0xa993f0
    cpu.esp -= 4;
    sub_a993f0(app, cpu);
    if (cpu.terminate) return;
L_0x00a97e64:
    // 00a97e64  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a97e66  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a97e67  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a97e68  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a97e69  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a97e70(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a97e70  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a97e71  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a97e72  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a97e73  83ec20                 -sub esp, 0x20
    (cpu.esp) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00a97e76  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a97e78  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00a97e7a  6a1c                   -push 0x1c
    app->getMemory<x86::reg32>(cpu.esp-4) = 28 /*0x1c*/;
    cpu.esp -= 4;
    // 00a97e7c  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a97e80  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a97e81  8d442424               -lea eax, [esp + 0x24]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00a97e85  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a97e86  2eff1560cea900         -call dword ptr cs:[0xa9ce60]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11128416) /* 0xa9ce60 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a97e8d  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 00a97e90  0354240c               -add edx, dword ptr [esp + 0xc]
    (cpu.edx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 00a97e94  668b0d71e3a900         -mov cx, word ptr [0xa9e371]
    cpu.cx = app->getMemory<x86::reg16>(x86::reg32(11133809) /* 0xa9e371 */);
    // 00a97e9b  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a97e9f  6681f90080             +cmp cx, 0x8000
    {
        x86::reg16 tmp1 = cpu.cx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(32768 /*0x8000*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00a97ea4  7307                   -jae 0xa97ead
    if (!cpu.flags.cf)
    {
        goto L_0x00a97ead;
    }
    // 00a97ea6  0500300000             +add eax, 0x3000
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(12288 /*0x3000*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a97eab  eb17                   -jmp 0xa97ec4
    goto L_0x00a97ec4;
L_0x00a97ead:
    // 00a97ead  7210                   -jb 0xa97ebf
    if (cpu.flags.cf)
    {
        goto L_0x00a97ebf;
    }
    // 00a97eaf  803d6fe3a90004         +cmp byte ptr [0xa9e36f], 4
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(11133807) /* 0xa9e36f */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(4 /*0x4*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a97eb6  7307                   -jae 0xa97ebf
    if (!cpu.flags.cf)
    {
        goto L_0x00a97ebf;
    }
    // 00a97eb8  0500200100             +add eax, 0x12000
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(73728 /*0x12000*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a97ebd  eb05                   -jmp 0xa97ec4
    goto L_0x00a97ec4;
L_0x00a97ebf:
    // 00a97ebf  0500300100             -add eax, 0x13000
    (cpu.eax) += x86::reg32(x86::sreg32(77824 /*0x13000*/));
L_0x00a97ec4:
    // 00a97ec4  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a97ec6  7402                   -je 0xa97eca
    if (cpu.flags.zf)
    {
        goto L_0x00a97eca;
    }
    // 00a97ec8  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
L_0x00a97eca:
    // 00a97eca  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a97ecc  7402                   -je 0xa97ed0
    if (cpu.flags.zf)
    {
        goto L_0x00a97ed0;
    }
    // 00a97ece  8916                   -mov dword ptr [esi], edx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edx;
L_0x00a97ed0:
    // 00a97ed0  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00a97ed3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a97ed4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a97ed5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a97ed6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a97ee0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a97ee0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a97ee1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a97ee2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a97ee3  68a8eda900             -push 0xa9eda8
    app->getMemory<x86::reg32>(cpu.esp-4) = 11136424 /*0xa9eda8*/;
    cpu.esp -= 4;
    // 00a97ee8  2eff1510cea900         -call dword ptr cs:[0xa9ce10]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11128336) /* 0xa9ce10 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a97eef  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a97ef1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a97ef3  7417                   -je 0xa97f0c
    if (cpu.flags.zf)
    {
        goto L_0x00a97f0c;
    }
    // 00a97ef5  68b4eda900             -push 0xa9edb4
    app->getMemory<x86::reg32>(cpu.esp-4) = 11136436 /*0xa9edb4*/;
    cpu.esp -= 4;
    // 00a97efa  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a97efb  2eff15f8cda900         -call dword ptr cs:[0xa9cdf8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11128312) /* 0xa9cdf8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a97f02  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a97f04  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a97f06  7404                   -je 0xa97f0c
    if (cpu.flags.zf)
    {
        goto L_0x00a97f0c;
    }
    // 00a97f08  ffd2                   -call edx
    cpu.ip = cpu.edx;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a97f0a  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x00a97f0c:
    // 00a97f0c  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a97f0e  0f95c0                 -setne al
    cpu.al = !cpu.flags.zf;
    // 00a97f11  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00a97f16  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a97f17  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a97f18  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a97f19  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void sub_a97f1c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a97f1c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a97f1d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a97f1e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a97f1f  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00a97f21  8a08                   -mov cl, byte ptr [eax]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax);
    // 00a97f23  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a97f25  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 00a97f27  7408                   -je 0xa97f31
    if (cpu.flags.zf)
    {
        goto L_0x00a97f31;
    }
L_0x00a97f29:
    // 00a97f29  8a6801                 -mov ch, byte ptr [eax + 1]
    cpu.ch = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a97f2c  40                     -inc eax
    (cpu.eax)++;
    // 00a97f2d  84ed                   +test ch, ch
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & cpu.ch));
    // 00a97f2f  75f8                   -jne 0xa97f29
    if (!cpu.flags.zf)
    {
        goto L_0x00a97f29;
    }
L_0x00a97f31:
    // 00a97f31  8d7009                 -lea esi, [eax + 9]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(9) /* 0x9 */);
L_0x00a97f34:
    // 00a97f34  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 00a97f36  8808                   -mov byte ptr [eax], cl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.cl;
    // 00a97f38  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 00a97f3a  7412                   -je 0xa97f4e
    if (cpu.flags.zf)
    {
        goto L_0x00a97f4e;
    }
    // 00a97f3c  80f930                 +cmp cl, 0x30
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(48 /*0x30*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a97f3f  7508                   -jne 0xa97f49
    if (!cpu.flags.zf)
    {
        goto L_0x00a97f49;
    }
    // 00a97f41  807a0178               +cmp byte ptr [edx + 1], 0x78
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(120 /*0x78*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a97f45  7502                   -jne 0xa97f49
    if (!cpu.flags.zf)
    {
        goto L_0x00a97f49;
    }
    // 00a97f47  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
L_0x00a97f49:
    // 00a97f49  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a97f4a  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a97f4b  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a97f4c  ebe6                   -jmp 0xa97f34
    goto L_0x00a97f34;
L_0x00a97f4e:
    // 00a97f4e  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a97f50  741c                   -je 0xa97f6e
    if (cpu.flags.zf)
    {
        goto L_0x00a97f6e;
    }
    // 00a97f52  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a97f54  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00a97f56  7416                   -je 0xa97f6e
    if (cpu.flags.zf)
    {
        goto L_0x00a97f6e;
    }
L_0x00a97f58:
    // 00a97f58  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a97f5a  83e20f                 -and edx, 0xf
    cpu.edx &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00a97f5d  4b                     -dec ebx
    (cpu.ebx)--;
    // 00a97f5e  8a92a8e3a900           -mov dl, byte ptr [edx + 0xa9e3a8]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(11133864) /* 0xa9e3a8 */);
    // 00a97f64  c1e804                 -shr eax, 4
    cpu.eax >>= 4 /*0x4*/ % 32;
    // 00a97f67  885301                 -mov byte ptr [ebx + 1], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(1) /* 0x1 */) = cpu.dl;
    // 00a97f6a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a97f6c  75ea                   -jne 0xa97f58
    if (!cpu.flags.zf)
    {
        goto L_0x00a97f58;
    }
L_0x00a97f6e:
    // 00a97f6e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a97f6f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a97f70  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a97f71  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void sub_a97f74(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a97f74  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a97f75  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a97f76  81ec04010000           -sub esp, 0x104
    (cpu.esp) -= x86::reg32(x86::sreg32(260 /*0x104*/));
    // 00a97f7c  8b9c2410010000         -mov ebx, dword ptr [esp + 0x110]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(272) /* 0x110 */);
    // 00a97f83  8b0b                   -mov ecx, dword ptr [ebx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx);
    // 00a97f85  8b5b04                 -mov ebx, dword ptr [ebx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 00a97f88  e853ffffff             -call 0xa97ee0
    cpu.esp -= 4;
    sub_a97ee0(app, cpu);
    if (cpu.terminate) return;
    // 00a97f8d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a97f8f  750a                   -jne 0xa97f9b
    if (!cpu.flags.zf)
    {
        goto L_0x00a97f9b;
    }
    // 00a97f91  e82e150000             -call 0xa994c4
    cpu.esp -= 4;
    sub_a994c4(app, cpu);
    if (cpu.terminate) return;
    // 00a97f96  83f8ff                 +cmp eax, -1
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a97f99  7507                   -jne 0xa97fa2
    if (!cpu.flags.zf)
    {
        goto L_0x00a97fa2;
    }
L_0x00a97f9b:
    // 00a97f9b  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a97f9d  e98c010000             -jmp 0xa9812e
    goto L_0x00a9812e;
L_0x00a97fa2:
    // 00a97fa2  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 00a97fa4  882424                 -mov byte ptr [esp], ah
    app->getMemory<x86::reg8>(cpu.esp) = cpu.ah;
    // 00a97fa7  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 00a97fa9  3d900000c0             +cmp eax, 0xc0000090
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3221225616 /*0xc0000090*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a97fae  724d                   -jb 0xa97ffd
    if (cpu.flags.cf)
    {
        goto L_0x00a97ffd;
    }
    // 00a97fb0  0f86c2000000           -jbe 0xa98078
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a98078;
    }
    // 00a97fb6  3d930000c0             +cmp eax, 0xc0000093
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3221225619 /*0xc0000093*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a97fbb  7233                   -jb 0xa97ff0
    if (cpu.flags.cf)
    {
        goto L_0x00a97ff0;
    }
    // 00a97fbd  0f86ab000000           -jbe 0xa9806e
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a9806e;
    }
    // 00a97fc3  3d960000c0             +cmp eax, 0xc0000096
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3221225622 /*0xc0000096*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a97fc8  7216                   -jb 0xa97fe0
    if (cpu.flags.cf)
    {
        goto L_0x00a97fe0;
    }
    // 00a97fca  0f86ec000000           -jbe 0xa980bc
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a980bc;
    }
    // 00a97fd0  3dfd0000c0             +cmp eax, 0xc00000fd
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3221225725 /*0xc00000fd*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a97fd5  0f84f6000000           -je 0xa980d1
    if (cpu.flags.zf)
    {
        goto L_0x00a980d1;
    }
    // 00a97fdb  e9f8000000             -jmp 0xa980d8
    goto L_0x00a980d8;
L_0x00a97fe0:
    // 00a97fe0  3d940000c0             +cmp eax, 0xc0000094
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3221225620 /*0xc0000094*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a97fe5  0f84df000000           -je 0xa980ca
    if (cpu.flags.zf)
    {
        goto L_0x00a980ca;
    }
    // 00a97feb  e9e8000000             -jmp 0xa980d8
    goto L_0x00a980d8;
L_0x00a97ff0:
    // 00a97ff0  3d910000c0             +cmp eax, 0xc0000091
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3221225617 /*0xc0000091*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a97ff5  0f8669000000           -jbe 0xa98064
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a98064;
    }
    // 00a97ffb  eb2f                   -jmp 0xa9802c
    goto L_0x00a9802c;
L_0x00a97ffd:
    // 00a97ffd  3d8d0000c0             +cmp eax, 0xc000008d
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3221225613 /*0xc000008d*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a98002  720b                   -jb 0xa9800f
    if (cpu.flags.cf)
    {
        goto L_0x00a9800f;
    }
    // 00a98004  7640                   -jbe 0xa98046
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a98046;
    }
    // 00a98006  3d8e0000c0             +cmp eax, 0xc000008e
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3221225614 /*0xc000008e*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a9800b  7643                   -jbe 0xa98050
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a98050;
    }
    // 00a9800d  eb4b                   -jmp 0xa9805a
    goto L_0x00a9805a;
L_0x00a9800f:
    // 00a9800f  3d050000c0             +cmp eax, 0xc0000005
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3221225477 /*0xc0000005*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a98014  0f82be000000           -jb 0xa980d8
    if (cpu.flags.cf)
    {
        goto L_0x00a980d8;
    }
    // 00a9801a  7666                   -jbe 0xa98082
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a98082;
    }
    // 00a9801c  3d1d0000c0             +cmp eax, 0xc000001d
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3221225501 /*0xc000001d*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a98021  0f849c000000           -je 0xa980c3
    if (cpu.flags.zf)
    {
        goto L_0x00a980c3;
    }
    // 00a98027  e9ac000000             -jmp 0xa980d8
    goto L_0x00a980d8;
L_0x00a9802c:
    // 00a9802c  f6432102               +test byte ptr [ebx + 0x21], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(33) /* 0x21 */) & 2 /*0x2*/));
    // 00a98030  740a                   -je 0xa9803c
    if (cpu.flags.zf)
    {
        goto L_0x00a9803c;
    }
    // 00a98032  bac4eda900             -mov edx, 0xa9edc4
    cpu.edx = 11136452 /*0xa9edc4*/;
    // 00a98037  e9af000000             -jmp 0xa980eb
    goto L_0x00a980eb;
L_0x00a9803c:
    // 00a9803c  ba18eea900             -mov edx, 0xa9ee18
    cpu.edx = 11136536 /*0xa9ee18*/;
    // 00a98041  e9a5000000             -jmp 0xa980eb
    goto L_0x00a980eb;
L_0x00a98046:
    // 00a98046  ba6ceea900             -mov edx, 0xa9ee6c
    cpu.edx = 11136620 /*0xa9ee6c*/;
    // 00a9804b  e99b000000             -jmp 0xa980eb
    goto L_0x00a980eb;
L_0x00a98050:
    // 00a98050  bac0eea900             -mov edx, 0xa9eec0
    cpu.edx = 11136704 /*0xa9eec0*/;
    // 00a98055  e991000000             -jmp 0xa980eb
    goto L_0x00a980eb;
L_0x00a9805a:
    // 00a9805a  ba14efa900             -mov edx, 0xa9ef14
    cpu.edx = 11136788 /*0xa9ef14*/;
    // 00a9805f  e987000000             -jmp 0xa980eb
    goto L_0x00a980eb;
L_0x00a98064:
    // 00a98064  ba68efa900             -mov edx, 0xa9ef68
    cpu.edx = 11136872 /*0xa9ef68*/;
    // 00a98069  e97d000000             -jmp 0xa980eb
    goto L_0x00a980eb;
L_0x00a9806e:
    // 00a9806e  bab4efa900             -mov edx, 0xa9efb4
    cpu.edx = 11136948 /*0xa9efb4*/;
    // 00a98073  e973000000             -jmp 0xa980eb
    goto L_0x00a980eb;
L_0x00a98078:
    // 00a98078  ba04f0a900             -mov edx, 0xa9f004
    cpu.edx = 11137028 /*0xa9f004*/;
    // 00a9807d  e969000000             -jmp 0xa980eb
    goto L_0x00a980eb;
L_0x00a98082:
    // 00a98082  ba5cf0a900             -mov edx, 0xa9f05c
    cpu.edx = 11137116 /*0xa9f05c*/;
    // 00a98087  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a98089  8b590c                 -mov ebx, dword ptr [ecx + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00a9808c  e88bfeffff             -call 0xa97f1c
    cpu.esp -= 4;
    sub_a97f1c(app, cpu);
    if (cpu.terminate) return;
    // 00a98091  ba90f0a900             -mov edx, 0xa9f090
    cpu.edx = 11137168 /*0xa9f090*/;
    // 00a98096  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a98098  8b5918                 -mov ebx, dword ptr [ecx + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 00a9809b  e87cfeffff             -call 0xa97f1c
    cpu.esp -= 4;
    sub_a97f1c(app, cpu);
    if (cpu.terminate) return;
    // 00a980a0  83791400               +cmp dword ptr [ecx + 0x14], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a980a4  750b                   -jne 0xa980b1
    if (!cpu.flags.zf)
    {
        goto L_0x00a980b1;
    }
    // 00a980a6  bab8f0a900             -mov edx, 0xa9f0b8
    cpu.edx = 11137208 /*0xa9f0b8*/;
    // 00a980ab  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a980ad  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 00a980af  eb3f                   -jmp 0xa980f0
    goto L_0x00a980f0;
L_0x00a980b1:
    // 00a980b1  bac0f0a900             -mov edx, 0xa9f0c0
    cpu.edx = 11137216 /*0xa9f0c0*/;
    // 00a980b6  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a980b8  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 00a980ba  eb34                   -jmp 0xa980f0
    goto L_0x00a980f0;
L_0x00a980bc:
    // 00a980bc  baccf0a900             -mov edx, 0xa9f0cc
    cpu.edx = 11137228 /*0xa9f0cc*/;
    // 00a980c1  eb28                   -jmp 0xa980eb
    goto L_0x00a980eb;
L_0x00a980c3:
    // 00a980c3  ba0cf1a900             -mov edx, 0xa9f10c
    cpu.edx = 11137292 /*0xa9f10c*/;
    // 00a980c8  eb21                   -jmp 0xa980eb
    goto L_0x00a980eb;
L_0x00a980ca:
    // 00a980ca  ba48f1a900             -mov edx, 0xa9f148
    cpu.edx = 11137352 /*0xa9f148*/;
    // 00a980cf  eb1a                   -jmp 0xa980eb
    goto L_0x00a980eb;
L_0x00a980d1:
    // 00a980d1  ba8cf1a900             -mov edx, 0xa9f18c
    cpu.edx = 11137420 /*0xa9f18c*/;
    // 00a980d6  eb13                   -jmp 0xa980eb
    goto L_0x00a980eb;
L_0x00a980d8:
    // 00a980d8  bac8f1a900             -mov edx, 0xa9f1c8
    cpu.edx = 11137480 /*0xa9f1c8*/;
    // 00a980dd  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a980df  8b19                   -mov ebx, dword ptr [ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx);
    // 00a980e1  e836feffff             -call 0xa97f1c
    cpu.esp -= 4;
    sub_a97f1c(app, cpu);
    if (cpu.terminate) return;
    // 00a980e6  bafcf1a900             -mov edx, 0xa9f1fc
    cpu.edx = 11137532 /*0xa9f1fc*/;
L_0x00a980eb:
    // 00a980eb  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a980ed  8b590c                 -mov ebx, dword ptr [ecx + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
L_0x00a980f0:
    // 00a980f0  e827feffff             -call 0xa97f1c
    cpu.esp -= 4;
    sub_a97f1c(app, cpu);
    if (cpu.terminate) return;
    // 00a980f5  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a980f7  8d842404010000         -lea eax, [esp + 0x104]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 00a980fe  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a980ff  8d7c2408               -lea edi, [esp + 8]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00a98103  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a98104  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a98106  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a98108  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a9810a  49                     -dec ecx
    (cpu.ecx)--;
    // 00a9810b  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a9810d  f2ae                   -repne scasb al, byte ptr es:[edi]
    while (cpu.ecx)
    {
        {
            x86::reg8 tmp1 = cpu.al;
            x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ees + cpu.edi)));
            x86::reg8 result = tmp1 - tmp2;
            cpu.flags.cf = tmp1 < tmp2;
            cpu.flags.of = 1 & (tmp1 >> 7);
            cpu.flags.of ^= 1 & (result >> 7);
            cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
            cpu.set_szp(result);
        }
        if (cpu.flags.df)
        {
            cpu.edi -= 1;
        }
        else
        {
            cpu.edi += 1;
        }
        --cpu.ecx;
        if (cpu.flags.zf)
            break;
    }
    // 00a9810f  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00a98111  49                     -dec ecx
    (cpu.ecx)--;
    // 00a98112  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a98113  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a98114  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00a98118  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a98119  a188e3a900             -mov eax, dword ptr [0xa9e388]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11133832) /* 0xa9e388 */);
    // 00a9811e  8b5808                 -mov ebx, dword ptr [eax + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00a98121  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a98122  2eff156ccea900         -call dword ptr cs:[0xa9ce6c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11128428) /* 0xa9ce6c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a98129  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x00a9812e:
    // 00a9812e  81c404010000           -add esp, 0x104
    (cpu.esp) += x86::reg32(x86::sreg32(260 /*0x104*/));
    // 00a98134  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a98135  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a98136  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_a98158(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 00a98158  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a98159  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a9815a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a9815b  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00a9815e  8b742418               -mov esi, dword ptr [esp + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00a98162  8b7c2420               -mov edi, dword ptr [esp + 0x20]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00a98166  f6460406               +test byte ptr [esi + 4], 6
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(4) /* 0x4 */) & 6 /*0x6*/));
    // 00a9816a  0f85a1010000           -jne 0xa98311
    if (!cpu.flags.zf)
    {
        goto L_0x00a98311;
    }
    // 00a98170  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00a98172  0573ffff3f             -add eax, 0x3fffff73
    (cpu.eax) += x86::reg32(x86::sreg32(1073741683 /*0x3fffff73*/));
    // 00a98177  83f806                 +cmp eax, 6
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(6 /*0x6*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a9817a  0f871f010000           -ja 0xa9829f
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a9829f;
    }
    // 00a98180  2eff24853c81a900       -jmp dword ptr cs:[eax*4 + 0xa9813c]
    cpu.ip = app->getMemory<x86::reg32>(11108668 + cpu.eax * 4); goto dynamic_jump;
  case 0x00a98188:
    // 00a98188  f6472102               +test byte ptr [edi + 0x21], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edi + x86::reg32(33) /* 0x21 */) & 2 /*0x2*/));
    // 00a9818c  740a                   -je 0xa98198
    if (cpu.flags.zf)
    {
        goto L_0x00a98198;
    }
    // 00a9818e  bb8a000000             -mov ebx, 0x8a
    cpu.ebx = 138 /*0x8a*/;
    // 00a98193  e9ca000000             -jmp 0xa98262
    goto L_0x00a98262;
L_0x00a98198:
    // 00a98198  bb8b000000             -mov ebx, 0x8b
    cpu.ebx = 139 /*0x8b*/;
    // 00a9819d  e9c0000000             -jmp 0xa98262
    goto L_0x00a98262;
  case 0x00a981a2:
    // 00a981a2  bb82000000             -mov ebx, 0x82
    cpu.ebx = 130 /*0x82*/;
    // 00a981a7  e9b6000000             -jmp 0xa98262
    goto L_0x00a98262;
  case 0x00a981ac:
    // 00a981ac  bb86000000             -mov ebx, 0x86
    cpu.ebx = 134 /*0x86*/;
    // 00a981b1  e9ac000000             -jmp 0xa98262
    goto L_0x00a98262;
  case 0x00a981b6:
    // 00a981b6  bb84000000             -mov ebx, 0x84
    cpu.ebx = 132 /*0x84*/;
    // 00a981bb  e9a2000000             -jmp 0xa98262
    goto L_0x00a98262;
  case 0x00a981c0:
    // 00a981c0  bb85000000             -mov ebx, 0x85
    cpu.ebx = 133 /*0x85*/;
    // 00a981c5  e998000000             -jmp 0xa98262
    goto L_0x00a98262;
  case 0x00a981ca:
    // 00a981ca  8b4728                 -mov eax, dword ptr [edi + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(40) /* 0x28 */);
    // 00a981cd  668b10                 -mov dx, word ptr [eax]
    cpu.dx = app->getMemory<x86::reg16>(cpu.eax);
    // 00a981d0  bb81000000             -mov ebx, 0x81
    cpu.ebx = 129 /*0x81*/;
    // 00a981d5  6681fad9fa             +cmp dx, 0xfad9
    {
        x86::reg16 tmp1 = cpu.dx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(64217 /*0xfad9*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00a981da  750a                   -jne 0xa981e6
    if (!cpu.flags.zf)
    {
        goto L_0x00a981e6;
    }
    // 00a981dc  bb88000000             -mov ebx, 0x88
    cpu.ebx = 136 /*0x88*/;
    // 00a981e1  e97c000000             -jmp 0xa98262
    goto L_0x00a98262;
L_0x00a981e6:
    // 00a981e6  6681fad9f1             +cmp dx, 0xf1d9
    {
        x86::reg16 tmp1 = cpu.dx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(61913 /*0xf1d9*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00a981eb  750a                   -jne 0xa981f7
    if (!cpu.flags.zf)
    {
        goto L_0x00a981f7;
    }
    // 00a981ed  bb8e000000             -mov ebx, 0x8e
    cpu.ebx = 142 /*0x8e*/;
    // 00a981f2  e96b000000             -jmp 0xa98262
    goto L_0x00a98262;
L_0x00a981f7:
    // 00a981f7  750a                   -jne 0xa98203
    if (!cpu.flags.zf)
    {
        goto L_0x00a98203;
    }
    // 00a981f9  bb8f000000             -mov ebx, 0x8f
    cpu.ebx = 143 /*0x8f*/;
    // 00a981fe  e95f000000             -jmp 0xa98262
    goto L_0x00a98262;
L_0x00a98203:
    // 00a98203  8a30                   -mov dh, byte ptr [eax]
    cpu.dh = app->getMemory<x86::reg8>(cpu.eax);
    // 00a98205  80fedb                 +cmp dh, 0xdb
    {
        x86::reg8 tmp1 = cpu.dh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(219 /*0xdb*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a98208  7405                   -je 0xa9820f
    if (cpu.flags.zf)
    {
        goto L_0x00a9820f;
    }
    // 00a9820a  80fedf                 +cmp dh, 0xdf
    {
        x86::reg8 tmp1 = cpu.dh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(223 /*0xdf*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a9820d  7510                   -jne 0xa9821f
    if (!cpu.flags.zf)
    {
        goto L_0x00a9821f;
    }
L_0x00a9820f:
    // 00a9820f  8a5001                 -mov dl, byte ptr [eax + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a98212  80e230                 -and dl, 0x30
    cpu.dl &= x86::reg8(x86::sreg8(48 /*0x30*/));
    // 00a98215  80fa10                 +cmp dl, 0x10
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(16 /*0x10*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a98218  7505                   -jne 0xa9821f
    if (!cpu.flags.zf)
    {
        goto L_0x00a9821f;
    }
    // 00a9821a  bb8d000000             -mov ebx, 0x8d
    cpu.ebx = 141 /*0x8d*/;
L_0x00a9821f:
    // 00a9821f  f60001                 +test byte ptr [eax], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax) & 1 /*0x1*/));
    // 00a98222  7539                   -jne 0xa9825d
    if (!cpu.flags.zf)
    {
        goto L_0x00a9825d;
    }
    // 00a98224  8a4001                 -mov al, byte ptr [eax + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a98227  2430                   -and al, 0x30
    cpu.al &= x86::reg8(x86::sreg8(48 /*0x30*/));
    // 00a98229  3c30                   +cmp al, 0x30
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(48 /*0x30*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a9822b  7530                   -jne 0xa9825d
    if (!cpu.flags.zf)
    {
        goto L_0x00a9825d;
    }
    // 00a9822d  8b4720                 -mov eax, dword ptr [edi + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(32) /* 0x20 */);
    // 00a98230  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00a98235  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00a98238  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a9823a  66c1e80d               -shr ax, 0xd
    cpu.ax >>= 13 /*0xd*/ % 32;
    // 00a9823e  8b5724                 -mov edx, dword ptr [edi + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(36) /* 0x24 */);
    // 00a98241  6689c1                 -mov cx, ax
    cpu.cx = cpu.ax;
    // 00a98244  81e2ffff0000           -and edx, 0xffff
    cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00a9824a  01c9                   -add ecx, ecx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00a9824c  d3ea                   -shr edx, cl
    cpu.edx >>= cpu.cl % 32;
    // 00a9824e  83e201                 -and edx, 1
    cpu.edx &= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 00a98251  83fa01                 +cmp edx, 1
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a98254  7507                   -jne 0xa9825d
    if (!cpu.flags.zf)
    {
        goto L_0x00a9825d;
    }
  [[fallthrough]];
  case 0x00a98256:
    // 00a98256  bb83000000             -mov ebx, 0x83
    cpu.ebx = 131 /*0x83*/;
    // 00a9825b  eb05                   -jmp 0xa98262
    goto L_0x00a98262;
L_0x00a9825d:
    // 00a9825d  83fbff                 +cmp ebx, -1
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a98260  743d                   -je 0xa9829f
    if (cpu.flags.zf)
    {
        goto L_0x00a9829f;
    }
L_0x00a98262:
    // 00a98262  c605e41daa0001         -mov byte ptr [0xaa1de4], 1
    app->getMemory<x86::reg8>(x86::reg32(11148772) /* 0xaa1de4 */) = 1 /*0x1*/;
    // 00a98269  e862120000             -call 0xa994d0
    cpu.esp -= 4;
    sub_a994d0(app, cpu);
    if (cpu.terminate) return;
    // 00a9826e  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a98270  e82f140000             -call 0xa996a4
    cpu.esp -= 4;
    sub_a996a4(app, cpu);
    if (cpu.terminate) return;
    // 00a98275  83f8ff                 +cmp eax, -1
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a98278  0f8474000000           -je 0xa982f2
    if (cpu.flags.zf)
    {
        goto L_0x00a982f2;
    }
    // 00a9827e  803de41daa0000         +cmp byte ptr [0xaa1de4], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(11148772) /* 0xaa1de4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a98285  0f8467000000           -je 0xa982f2
    if (cpu.flags.zf)
    {
        goto L_0x00a982f2;
    }
    // 00a9828b  668b5f20               -mov bx, word ptr [edi + 0x20]
    cpu.bx = app->getMemory<x86::reg16>(cpu.edi + x86::reg32(32) /* 0x20 */);
    // 00a9828f  30db                   -xor bl, bl
    cpu.bl ^= x86::reg8(x86::sreg8(cpu.bl));
    // 00a98291  80e77f                 -and bh, 0x7f
    cpu.bh &= x86::reg8(x86::sreg8(127 /*0x7f*/));
    // 00a98294  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a98296  66895f20               -mov word ptr [edi + 0x20], bx
    app->getMemory<x86::reg16>(cpu.edi + x86::reg32(32) /* 0x20 */) = cpu.bx;
    // 00a9829a  e977000000             -jmp 0xa98316
    goto L_0x00a98316;
L_0x00a9829f:
    // 00a9829f  833da4e3a90000         +cmp dword ptr [0xa9e3a4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(11133860) /* 0xa9e3a4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a982a6  744a                   -je 0xa982f2
    if (cpu.flags.zf)
    {
        goto L_0x00a982f2;
    }
    // 00a982a8  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00a982ad  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
L_0x00a982af:
    // 00a982af  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a982b1  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 00a982b3  ff15a0e3a900           -call dword ptr [0xa9e3a0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11133856) /* 0xa9e3a0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a982b9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a982bb  742f                   -je 0xa982ec
    if (cpu.flags.zf)
    {
        goto L_0x00a982ec;
    }
    // 00a982bd  83f801                 +cmp eax, 1
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a982c0  7430                   -je 0xa982f2
    if (cpu.flags.zf)
    {
        goto L_0x00a982f2;
    }
    // 00a982c2  83f802                 +cmp eax, 2
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a982c5  742b                   -je 0xa982f2
    if (cpu.flags.zf)
    {
        goto L_0x00a982f2;
    }
    // 00a982c7  83f803                 +cmp eax, 3
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a982ca  7426                   -je 0xa982f2
    if (cpu.flags.zf)
    {
        goto L_0x00a982f2;
    }
    // 00a982cc  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a982ce  880de41daa00           -mov byte ptr [0xaa1de4], cl
    app->getMemory<x86::reg8>(x86::reg32(11148772) /* 0xaa1de4 */) = cpu.cl;
    // 00a982d4  ff15a4e3a900           -call dword ptr [0xa9e3a4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11133860) /* 0xa9e3a4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a982da  803de41daa0000         +cmp byte ptr [0xaa1de4], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(11148772) /* 0xaa1de4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a982e1  7409                   -je 0xa982ec
    if (cpu.flags.zf)
    {
        goto L_0x00a982ec;
    }
    // 00a982e3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a982e5  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00a982e8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a982e9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a982ea  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a982eb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a982ec:
    // 00a982ec  43                     -inc ebx
    (cpu.ebx)++;
    // 00a982ed  83fb0c                 +cmp ebx, 0xc
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(12 /*0xc*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a982f0  7ebd                   -jle 0xa982af
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a982af;
    }
L_0x00a982f2:
    // 00a982f2  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a982f4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a982f5  89742404               -mov dword ptr [esp + 4], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 00a982f9  897c2408               -mov dword ptr [esp + 8], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edi;
    // 00a982fd  2eff1550cea900         -call dword ptr cs:[0xa9ce50]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11128400) /* 0xa9ce50 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a98304  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a98306  7409                   -je 0xa98311
    if (cpu.flags.zf)
    {
        goto L_0x00a98311;
    }
    // 00a98308  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 00a9830a  2eff15a4cda900         -call dword ptr cs:[0xa9cda4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11128228) /* 0xa9cda4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00a98311:
    // 00a98311  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x00a98316:
    // 00a98316  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00a98319  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9831a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9831b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9831c  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x8d 0x40 0x00 */
void sub_a98320(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a98320  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a98321  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a98322  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a98324  ff1594e2a900           -call dword ptr [0xa9e294]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11133588) /* 0xa9e294 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a9832a  895054                 -mov dword ptr [eax + 0x54], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(84) /* 0x54 */) = cpu.edx;
    // 00a9832d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a9832f  648b00                 -mov eax, dword ptr fs:[eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.efs + cpu.eax);
    // 00a98332  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a98334  ff1594e2a900           -call dword ptr [0xa9e294]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11133588) /* 0xa9e294 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a9833a  8b4054                 -mov eax, dword ptr [eax + 0x54]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(84) /* 0x54 */);
    // 00a9833d  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 00a9833f  ff1594e2a900           -call dword ptr [0xa9e294]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11133588) /* 0xa9e294 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a98345  8b4054                 -mov eax, dword ptr [eax + 0x54]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(84) /* 0x54 */);
    // 00a98348  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a9834a  c740045881a900         -mov dword ptr [eax + 4], 0xa98158
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 11108696 /*0xa98158*/;
    // 00a98351  ff1594e2a900           -call dword ptr [0xa9e294]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11133588) /* 0xa9e294 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a98357  8b4054                 -mov eax, dword ptr [eax + 0x54]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(84) /* 0x54 */);
    // 00a9835a  648902                 -mov dword ptr fs:[edx], eax
    app->getMemory<x86::reg32>(cpu.efs + cpu.edx) = cpu.eax;
    // 00a9835d  68747fa900             -push 0xa97f74
    app->getMemory<x86::reg32>(cpu.esp-4) = 11108212 /*0xa97f74*/;
    cpu.esp -= 4;
    // 00a98362  2eff153ccea900         -call dword ptr cs:[0xa9ce3c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11128380) /* 0xa9ce3c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a98369  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9836a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9836b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a9836c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9836c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a9836d  ff1594e2a900           -call dword ptr [0xa9e294]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11133588) /* 0xa9e294 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a98373  8b4054                 -mov eax, dword ptr [eax + 0x54]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(84) /* 0x54 */);
    // 00a98376  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a98378  7407                   -je 0xa98381
    if (cpu.flags.zf)
    {
        goto L_0x00a98381;
    }
    // 00a9837a  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00a9837c  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a9837e  648902                 -mov dword ptr fs:[edx], eax
    app->getMemory<x86::reg32>(cpu.efs + cpu.edx) = cpu.eax;
L_0x00a98381:
    // 00a98381  ff1594e2a900           -call dword ptr [0xa9e294]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11133588) /* 0xa9e294 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a98387  c7405400000000         -mov dword ptr [eax + 0x54], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(84) /* 0x54 */) = 0 /*0x0*/;
    // 00a9838e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9838f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a98390(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a98390  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a98391  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a98394  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 00a98397  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a98399  742a                   -je 0xa983c5
    if (cpu.flags.zf)
    {
        goto L_0x00a983c5;
    }
    // 00a9839b  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a9839d  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a9839f  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00a983a1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a983a2  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00a983a4  8d442414               -lea eax, [esp + 0x14]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00a983a8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a983a9  6800020000             -push 0x200
    app->getMemory<x86::reg32>(cpu.esp-4) = 512 /*0x200*/;
    cpu.esp -= 4;
    // 00a983ae  8b1554e6a900           -mov edx, dword ptr [0xa9e654]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11134548) /* 0xa9e654 */);
    // 00a983b4  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a983b5  2eff1568cea900         -call dword ptr cs:[0xa9ce68]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11128424) /* 0xa9ce68 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a983bc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a983be  7505                   -jne 0xa983c5
    if (!cpu.flags.zf)
    {
        goto L_0x00a983c5;
    }
    // 00a983c0  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
L_0x00a983c5:
    // 00a983c5  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a983c8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a983c9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a983d0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a983d0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a983d1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a983d2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a983d3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a983d4  83ec28                 -sub esp, 0x28
    (cpu.esp) -= x86::reg32(x86::sreg32(40 /*0x28*/));
    // 00a983d7  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 00a983d9  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00a983db  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00a983dd  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 00a983df  8d4c2401               -lea ecx, [esp + 1]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(1) /* 0x1 */);
    // 00a983e3  881424                 -mov byte ptr [esp], dl
    app->getMemory<x86::reg8>(cpu.esp) = cpu.dl;
L_0x00a983e6:
    // 00a983e6  8d5c2424               -lea ebx, [esp + 0x24]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00a983ea  897c2424               -mov dword ptr [esp + 0x24], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.edi;
    // 00a983ee  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a983f0  f733                   -div dword ptr [ebx]
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = app->getMemory<x86::reg32>(cpu.ebx);
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 00a983f2  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 00a983f4  8a82bce3a900           -mov al, byte ptr [edx + 0xa9e3bc]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(11133884) /* 0xa9e3bc */);
    // 00a983fa  8801                   -mov byte ptr [ecx], al
    app->getMemory<x86::reg8>(cpu.ecx) = cpu.al;
    // 00a983fc  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00a98400  41                     -inc ecx
    (cpu.ecx)++;
    // 00a98401  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a98403  75e1                   -jne 0xa983e6
    if (!cpu.flags.zf)
    {
        goto L_0x00a983e6;
    }
L_0x00a98405:
    // 00a98405  46                     -inc esi
    (cpu.esi)++;
    // 00a98406  8a41ff                 -mov al, byte ptr [ecx - 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(-1) /* -0x1 */);
    // 00a98409  49                     -dec ecx
    (cpu.ecx)--;
    // 00a9840a  8846ff                 -mov byte ptr [esi - 1], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(-1) /* -0x1 */) = cpu.al;
    // 00a9840d  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 00a9840f  75f4                   -jne 0xa98405
    if (!cpu.flags.zf)
    {
        goto L_0x00a98405;
    }
    // 00a98411  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00a98413  83c428                 -add esp, 0x28
    (cpu.esp) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 00a98416  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a98417  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a98418  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a98419  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9841a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void sub_a9841c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9841c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a9841d  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00a9841f  83fb0a                 +cmp ebx, 0xa
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(10 /*0xa*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a98422  750a                   -jne 0xa9842e
    if (!cpu.flags.zf)
    {
        goto L_0x00a9842e;
    }
    // 00a98424  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a98426  7d06                   -jge 0xa9842e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a9842e;
    }
    // 00a98428  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 00a9842a  c6022d                 -mov byte ptr [edx], 0x2d
    app->getMemory<x86::reg8>(cpu.edx) = 45 /*0x2d*/;
    // 00a9842d  42                     -inc edx
    (cpu.edx)++;
L_0x00a9842e:
    // 00a9842e  e89dffffff             -call 0xa983d0
    cpu.esp -= 4;
    sub_a983d0(app, cpu);
    if (cpu.terminate) return;
    // 00a98433  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a98435  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a98436  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a98440(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a98440  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a98441  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00a98446  b828f2a900             -mov eax, 0xa9f228
    cpu.eax = 11137576 /*0xa9f228*/;
    // 00a9844b  e84cebffff             -call 0xa96f9c
    cpu.esp -= 4;
    sub_a96f9c(app, cpu);
    if (cpu.terminate) return;
    // 00a98450  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a98451  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a98460(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a98460  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a98461  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a98462  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a98463  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a98464  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a98465  83ec44                 -sub esp, 0x44
    (cpu.esp) -= x86::reg32(x86::sreg32(68 /*0x44*/));
    // 00a98468  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a9846a  8954243c               -mov dword ptr [esp + 0x3c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */) = cpu.edx;
    // 00a9846e  8d7c2434               -lea edi, [esp + 0x34]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00a98472  8d6c2401               -lea ebp, [esp + 1]
    cpu.ebp = x86::reg32(cpu.esp + x86::reg32(1) /* 0x1 */);
    // 00a98476  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a98478  89542440               -mov dword ptr [esp + 0x40], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */) = cpu.edx;
    // 00a9847c  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a9847e  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a98480  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 00a98482  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00a98483  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00a98484  895c2424               -mov dword ptr [esp + 0x24], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.ebx;
    // 00a98488  89542428               -mov dword ptr [esp + 0x28], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.edx;
    // 00a9848c  882424                 -mov byte ptr [esp], ah
    app->getMemory<x86::reg8>(cpu.esp) = cpu.ah;
L_0x00a9848f:
    // 00a9848f  8d7c242c               -lea edi, [esp + 0x2c]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00a98493  8d742434               -lea esi, [esp + 0x34]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00a98497  8d5c2424               -lea ebx, [esp + 0x24]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00a9849b  8d442434               -lea eax, [esp + 0x34]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00a9849f  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00a984a2  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00a984a4  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 00a984a7  8b1b                   -mov ebx, dword ptr [ebx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx);
    // 00a984a9  e8ab150000             -call 0xa99a59
    cpu.esp -= 4;
    sub_a99a59(app, cpu);
    if (cpu.terminate) return;
    // 00a984ae  895604                 -mov dword ptr [esi + 4], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00a984b1  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 00a984b3  894f04                 -mov dword ptr [edi + 4], ecx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 00a984b6  891f                   -mov dword ptr [edi], ebx
    app->getMemory<x86::reg32>(cpu.edi) = cpu.ebx;
    // 00a984b8  8b44242c               -mov eax, dword ptr [esp + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00a984bc  8a80ece3a900           -mov al, byte ptr [eax + 0xa9e3ec]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(11133932) /* 0xa9e3ec */);
    // 00a984c2  884500                 -mov byte ptr [ebp], al
    app->getMemory<x86::reg8>(cpu.ebp) = cpu.al;
    // 00a984c5  8b5c2434               -mov ebx, dword ptr [esp + 0x34]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00a984c9  45                     -inc ebp
    (cpu.ebp)++;
    // 00a984ca  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a984cc  75c1                   -jne 0xa9848f
    if (!cpu.flags.zf)
    {
        goto L_0x00a9848f;
    }
    // 00a984ce  837c243800             +cmp dword ptr [esp + 0x38], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a984d3  75ba                   -jne 0xa9848f
    if (!cpu.flags.zf)
    {
        goto L_0x00a9848f;
    }
L_0x00a984d5:
    // 00a984d5  8b5c2440               -mov ebx, dword ptr [esp + 0x40]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 00a984d9  8a45ff                 -mov al, byte ptr [ebp - 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-1) /* -0x1 */);
    // 00a984dc  4d                     -dec ebp
    (cpu.ebp)--;
    // 00a984dd  8d7301                 -lea esi, [ebx + 1]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 00a984e0  8803                   -mov byte ptr [ebx], al
    app->getMemory<x86::reg8>(cpu.ebx) = cpu.al;
    // 00a984e2  89742440               -mov dword ptr [esp + 0x40], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */) = cpu.esi;
    // 00a984e6  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 00a984e8  75eb                   -jne 0xa984d5
    if (!cpu.flags.zf)
    {
        goto L_0x00a984d5;
    }
    // 00a984ea  8b44243c               -mov eax, dword ptr [esp + 0x3c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00a984ee  83c444                 -add esp, 0x44
    (cpu.esp) += x86::reg32(x86::sreg32(68 /*0x44*/));
    // 00a984f1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a984f2  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a984f3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a984f4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a984f5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a984f6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void sub_a984f8(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a984f8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a984f9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a984fa  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a984fb  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a984fc  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00a984ff  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a98501  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00a98503  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a98505  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 00a98507  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a98509  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00a9850a  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00a9850b  83fb0a                 +cmp ebx, 0xa
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(10 /*0xa*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a9850e  752d                   -jne 0xa9853d
    if (!cpu.flags.zf)
    {
        goto L_0x00a9853d;
    }
    // 00a98510  f644240780             +test byte ptr [esp + 7], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(7) /* 0x7 */) & 128 /*0x80*/));
    // 00a98515  7426                   -je 0xa9853d
    if (cpu.flags.zf)
    {
        goto L_0x00a9853d;
    }
    // 00a98517  c6022d                 -mov byte ptr [edx], 0x2d
    app->getMemory<x86::reg8>(cpu.edx) = 45 /*0x2d*/;
    // 00a9851a  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 00a9851d  8b742404               -mov esi, dword ptr [esp + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a98521  f7d2                   -not edx
    cpu.edx = ~cpu.edx;
    // 00a98523  f7d6                   -not esi
    cpu.esi = ~cpu.esi;
    // 00a98525  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 00a98528  89742404               -mov dword ptr [esp + 4], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 00a9852c  8b3c24                 -mov edi, dword ptr [esp]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    // 00a9852f  8d5101                 -lea edx, [ecx + 1]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 00a98532  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a98533  893c24                 -mov dword ptr [esp], edi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edi;
    // 00a98536  7501                   -jne 0xa98539
    if (!cpu.flags.zf)
    {
        goto L_0x00a98539;
    }
    // 00a98538  46                     -inc esi
    (cpu.esi)++;
L_0x00a98539:
    // 00a98539  89742404               -mov dword ptr [esp + 4], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.esi;
L_0x00a9853d:
    // 00a9853d  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a9853f  e81cffffff             -call 0xa98460
    cpu.esp -= 4;
    sub_a98460(app, cpu);
    if (cpu.terminate) return;
    // 00a98544  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a98546  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00a98549  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a9854a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9854b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9854c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9854d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void sub_a98550(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a98550  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a98551  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a98552  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a98553  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a98554  83ec28                 -sub esp, 0x28
    (cpu.esp) -= x86::reg32(x86::sreg32(40 /*0x28*/));
    // 00a98557  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 00a98559  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00a9855b  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00a9855d  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 00a9855f  8d4c2401               -lea ecx, [esp + 1]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(1) /* 0x1 */);
    // 00a98563  881424                 -mov byte ptr [esp], dl
    app->getMemory<x86::reg8>(cpu.esp) = cpu.dl;
L_0x00a98566:
    // 00a98566  8d5c2424               -lea ebx, [esp + 0x24]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00a9856a  897c2424               -mov dword ptr [esp + 0x24], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.edi;
    // 00a9856e  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a98570  f733                   -div dword ptr [ebx]
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = app->getMemory<x86::reg32>(cpu.ebx);
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 00a98572  8913                   -mov dword ptr [ebx], edx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
    // 00a98574  8b5c2424               -mov ebx, dword ptr [esp + 0x24]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00a98578  41                     -inc ecx
    (cpu.ecx)++;
    // 00a98579  8a9b14e4a900           -mov bl, byte ptr [ebx + 0xa9e414]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(11133972) /* 0xa9e414 */);
    // 00a9857f  8859ff                 -mov byte ptr [ecx - 1], bl
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(-1) /* -0x1 */) = cpu.bl;
    // 00a98582  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a98584  75e0                   -jne 0xa98566
    if (!cpu.flags.zf)
    {
        goto L_0x00a98566;
    }
L_0x00a98586:
    // 00a98586  46                     -inc esi
    (cpu.esi)++;
    // 00a98587  8a41ff                 -mov al, byte ptr [ecx - 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(-1) /* -0x1 */);
    // 00a9858a  49                     -dec ecx
    (cpu.ecx)--;
    // 00a9858b  8846ff                 -mov byte ptr [esi - 1], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(-1) /* -0x1 */) = cpu.al;
    // 00a9858e  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 00a98590  75f4                   -jne 0xa98586
    if (!cpu.flags.zf)
    {
        goto L_0x00a98586;
    }
    // 00a98592  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00a98594  83c428                 -add esp, 0x28
    (cpu.esp) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 00a98597  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a98598  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a98599  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9859a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9859b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a9859c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9859c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a9859d  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00a9859f  83fb0a                 +cmp ebx, 0xa
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(10 /*0xa*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a985a2  750a                   -jne 0xa985ae
    if (!cpu.flags.zf)
    {
        goto L_0x00a985ae;
    }
    // 00a985a4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a985a6  7d06                   -jge 0xa985ae
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a985ae;
    }
    // 00a985a8  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 00a985aa  c6022d                 -mov byte ptr [edx], 0x2d
    app->getMemory<x86::reg8>(cpu.edx) = 45 /*0x2d*/;
    // 00a985ad  42                     -inc edx
    (cpu.edx)++;
L_0x00a985ae:
    // 00a985ae  e89dffffff             -call 0xa98550
    cpu.esp -= 4;
    sub_a98550(app, cpu);
    if (cpu.terminate) return;
    // 00a985b3  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a985b5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a985b6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a985c0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a985c0  8a80011eaa00           -mov al, byte ptr [eax + 0xaa1e01]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(11148801) /* 0xaa1e01 */);
    // 00a985c6  2401                   -and al, 1
    cpu.al &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00a985c8  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00a985cd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void sub_a985d0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a985d0  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a985d2  e9c9120000             -jmp 0xa998a0
    return sub_a998a0(app, cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a985e0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a985e0  83f861                 +cmp eax, 0x61
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(97 /*0x61*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a985e3  7c08                   -jl 0xa985ed
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a985ed;
    }
    // 00a985e5  83f87a                 +cmp eax, 0x7a
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(122 /*0x7a*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a985e8  7f03                   -jg 0xa985ed
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00a985ed;
    }
    // 00a985ea  83e820                 -sub eax, 0x20
    (cpu.eax) -= x86::reg32(x86::sreg32(32 /*0x20*/));
L_0x00a985ed:
    // 00a985ed  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void sub_a985f0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a985f0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a985f1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a985f2  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a985f4  ff15b0e2a900           -call dword ptr [0xa9e2b0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11133616) /* 0xa9e2b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a985fa  8b153ce4a900           -mov edx, dword ptr [0xa9e43c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11134012) /* 0xa9e43c */);
    // 00a98600  891d3ce4a900           -mov dword ptr [0xa9e43c], ebx
    app->getMemory<x86::reg32>(x86::reg32(11134012) /* 0xa9e43c */) = cpu.ebx;
    // 00a98606  ff15b8e2a900           -call dword ptr [0xa9e2b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11133624) /* 0xa9e2b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a9860c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a9860e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9860f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a98610  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a98620(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a98620  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a98621  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a98622  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a98623  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a98624  ff15b0e2a900           -call dword ptr [0xa9e2b0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11133616) /* 0xa9e2b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a9862a  a178e1a900             -mov eax, dword ptr [0xa9e178]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11133304) /* 0xa9e178 */);
    // 00a9862f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a98631  741c                   -je 0xa9864f
    if (cpu.flags.zf)
    {
        goto L_0x00a9864f;
    }
L_0x00a98633:
    // 00a98633  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 00a98635  8b4824                 -mov ecx, dword ptr [eax + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 00a98638  83eb2c                 -sub ebx, 0x2c
    (cpu.ebx) -= x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00a9863b  8b31                   -mov esi, dword ptr [ecx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx);
    // 00a9863d  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00a98640  39f3                   +cmp ebx, esi
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a98642  7505                   -jne 0xa98649
    if (!cpu.flags.zf)
    {
        goto L_0x00a98649;
    }
    // 00a98644  e873000000             -call 0xa986bc
    cpu.esp -= 4;
    sub_a986bc(app, cpu);
    if (cpu.terminate) return;
L_0x00a98649:
    // 00a98649  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a9864b  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a9864d  75e4                   -jne 0xa98633
    if (!cpu.flags.zf)
    {
        goto L_0x00a98633;
    }
L_0x00a9864f:
    // 00a9864f  ff15b8e2a900           -call dword ptr [0xa9e2b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11133624) /* 0xa9e2b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a98655  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a98657  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a98658  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a98659  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9865a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9865b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a9865c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9865c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a9865d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a9865e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a9865f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a98660  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a98661  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a98663  6800800000             -push 0x8000
    app->getMemory<x86::reg32>(cpu.esp-4) = 32768 /*0x8000*/;
    cpu.esp -= 4;
    // 00a98668  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a9866a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a9866b  8b7008                 -mov esi, dword ptr [eax + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00a9866e  2eff1558cea900         -call dword ptr cs:[0xa9ce58]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11128408) /* 0xa9ce58 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a98675  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a98677  7507                   -jne 0xa98680
    if (!cpu.flags.zf)
    {
        goto L_0x00a98680;
    }
    // 00a98679  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a9867e  eb36                   -jmp 0xa986b6
    goto L_0x00a986b6;
L_0x00a98680:
    // 00a98680  3b1d7ce1a900           +cmp ebx, dword ptr [0xa9e17c]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(11133308) /* 0xa9e17c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a98686  751c                   -jne 0xa986a4
    if (!cpu.flags.zf)
    {
        goto L_0x00a986a4;
    }
    // 00a98688  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a9868a  7408                   -je 0xa98694
    if (cpu.flags.zf)
    {
        goto L_0x00a98694;
    }
    // 00a9868c  89357ce1a900           -mov dword ptr [0xa9e17c], esi
    app->getMemory<x86::reg32>(x86::reg32(11133308) /* 0xa9e17c */) = cpu.esi;
    // 00a98692  eb10                   -jmp 0xa986a4
    goto L_0x00a986a4;
L_0x00a98694:
    // 00a98694  a178e1a900             -mov eax, dword ptr [0xa9e178]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11133304) /* 0xa9e178 */);
    // 00a98699  893580e1a900           -mov dword ptr [0xa9e180], esi
    app->getMemory<x86::reg32>(x86::reg32(11133312) /* 0xa9e180 */) = cpu.esi;
    // 00a9869f  a37ce1a900             -mov dword ptr [0xa9e17c], eax
    app->getMemory<x86::reg32>(x86::reg32(11133308) /* 0xa9e17c */) = cpu.eax;
L_0x00a986a4:
    // 00a986a4  3b1df00faa00           +cmp ebx, dword ptr [0xaa0ff0]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(11145200) /* 0xaa0ff0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a986aa  7508                   -jne 0xa986b4
    if (!cpu.flags.zf)
    {
        goto L_0x00a986b4;
    }
    // 00a986ac  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00a986ae  893df00faa00           -mov dword ptr [0xaa0ff0], edi
    app->getMemory<x86::reg32>(x86::reg32(11145200) /* 0xaa0ff0 */) = cpu.edi;
L_0x00a986b4:
    // 00a986b4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00a986b6:
    // 00a986b6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a986b7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a986b8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a986b9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a986ba  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a986bb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a986bc(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a986bc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a986bd  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a986be  8b5804                 -mov ebx, dword ptr [eax + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00a986c1  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00a986c4  e893ffffff             -call 0xa9865c
    cpu.esp -= 4;
    sub_a9865c(app, cpu);
    if (cpu.terminate) return;
    // 00a986c9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a986cb  7516                   -jne 0xa986e3
    if (!cpu.flags.zf)
    {
        goto L_0x00a986e3;
    }
    // 00a986cd  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a986cf  7508                   -jne 0xa986d9
    if (!cpu.flags.zf)
    {
        goto L_0x00a986d9;
    }
    // 00a986d1  891578e1a900           -mov dword ptr [0xa9e178], edx
    app->getMemory<x86::reg32>(x86::reg32(11133304) /* 0xa9e178 */) = cpu.edx;
    // 00a986d7  eb03                   -jmp 0xa986dc
    goto L_0x00a986dc;
L_0x00a986d9:
    // 00a986d9  895308                 -mov dword ptr [ebx + 8], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.edx;
L_0x00a986dc:
    // 00a986dc  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a986de  7403                   -je 0xa986e3
    if (cpu.flags.zf)
    {
        goto L_0x00a986e3;
    }
    // 00a986e0  895a04                 -mov dword ptr [edx + 4], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.ebx;
L_0x00a986e3:
    // 00a986e3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a986e4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a986e5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a986f0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a986f0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a986f1  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00a986f3  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a986f4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a986f5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a986f6  83ec40                 -sub esp, 0x40
    (cpu.esp) -= x86::reg32(x86::sreg32(64 /*0x40*/));
    // 00a986f9  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a986fb  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00a986fd  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a986ff  8a4315                 -mov al, byte ptr [ebx + 0x15]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(21) /* 0x15 */);
    // 00a98702  8945c0                 -mov dword ptr [ebp - 0x40], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-64) /* -0x40 */) = cpu.eax;
    // 00a98705  8a4115                 -mov al, byte ptr [ecx + 0x15]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(21) /* 0x15 */);
    // 00a98708  8b5b08                 -mov ebx, dword ptr [ebx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 00a9870b  245f                   -and al, 0x5f
    cpu.al &= x86::reg8(x86::sreg8(95 /*0x5f*/));
    // 00a9870d  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00a98712  83f847                 +cmp eax, 0x47
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(71 /*0x47*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a98715  7523                   -jne 0xa9873a
    if (!cpu.flags.zf)
    {
        goto L_0x00a9873a;
    }
    // 00a98717  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a98719  7505                   -jne 0xa98720
    if (!cpu.flags.zf)
    {
        goto L_0x00a98720;
    }
    // 00a9871b  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
L_0x00a98720:
    // 00a98720  c745bc04000000         -mov dword ptr [ebp - 0x44], 4
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-68) /* -0x44 */) = 4 /*0x4*/;
    // 00a98727  8b7dc0                 -mov edi, dword ptr [ebp - 0x40]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-64) /* -0x40 */);
    // 00a9872a  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a9872f  83ef02                 +sub edi, 2
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a98732  8945b8                 -mov dword ptr [ebp - 0x48], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-72) /* -0x48 */) = cpu.eax;
    // 00a98735  897dc0                 -mov dword ptr [ebp - 0x40], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-64) /* -0x40 */) = cpu.edi;
    // 00a98738  eb1f                   -jmp 0xa98759
    goto L_0x00a98759;
L_0x00a9873a:
    // 00a9873a  83f845                 +cmp eax, 0x45
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(69 /*0x45*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a9873d  750d                   -jne 0xa9874c
    if (!cpu.flags.zf)
    {
        goto L_0x00a9874c;
    }
    // 00a9873f  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 00a98744  897dbc                 -mov dword ptr [ebp - 0x44], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-68) /* -0x44 */) = cpu.edi;
    // 00a98747  897db8                 -mov dword ptr [ebp - 0x48], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-72) /* -0x48 */) = cpu.edi;
    // 00a9874a  eb0d                   -jmp 0xa98759
    goto L_0x00a98759;
L_0x00a9874c:
    // 00a9874c  bf02000000             -mov edi, 2
    cpu.edi = 2 /*0x2*/;
    // 00a98751  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a98753  897dbc                 -mov dword ptr [ebp - 0x44], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-68) /* -0x44 */) = cpu.edi;
    // 00a98756  8945b8                 -mov dword ptr [ebp - 0x48], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-72) /* -0x48 */) = cpu.eax;
L_0x00a98759:
    // 00a98759  f6411e01               +test byte ptr [ecx + 0x1e], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */) & 1 /*0x1*/));
    // 00a9875d  7404                   -je 0xa98763
    if (cpu.flags.zf)
    {
        goto L_0x00a98763;
    }
    // 00a9875f  804dbc10               -or byte ptr [ebp - 0x44], 0x10
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-68) /* -0x44 */) |= x86::reg8(x86::sreg8(16 /*0x10*/));
L_0x00a98763:
    // 00a98763  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 00a98765  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00a98768  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 00a9876a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a9876c  8b40f8                 -mov eax, dword ptr [eax - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-8) /* -0x8 */);
    // 00a9876f  8945ec                 -mov dword ptr [ebp - 0x14], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.eax;
    // 00a98772  8b42fc                 -mov eax, dword ptr [edx - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */);
    // 00a98775  8d55e0                 -lea edx, [ebp - 0x20]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 00a98778  8945f0                 -mov dword ptr [ebp - 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
    // 00a9877b  8d45ec                 -lea eax, [ebp - 0x14]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00a9877e  dd00                   -fld qword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.eax)));
    // 00a98780  db3a                   -fstp xword ptr [edx]
    app->getMemory<x86::IEEEf80>(cpu.edx) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a98782  83fbff                 +cmp ebx, -1
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a98785  7505                   -jne 0xa9878c
    if (!cpu.flags.zf)
    {
        goto L_0x00a9878c;
    }
    // 00a98787  bb06000000             -mov ebx, 6
    cpu.ebx = 6 /*0x6*/;
L_0x00a9878c:
    // 00a9878c  8d45e0                 -lea eax, [ebp - 0x20]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 00a9878f  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a98791  895db4                 -mov dword ptr [ebp - 0x4c], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-76) /* -0x4c */) = cpu.ebx;
    // 00a98794  8955c4                 -mov dword ptr [ebp - 0x3c], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-60) /* -0x3c */) = cpu.edx;
    // 00a98797  8d5e01                 -lea ebx, [esi + 1]
    cpu.ebx = x86::reg32(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00a9879a  8d55b4                 -lea edx, [ebp - 0x4c]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-76) /* -0x4c */);
    // 00a9879d  e87d140000             -call 0xa99c1f
    cpu.esp -= 4;
    sub_a99c1f(app, cpu);
    if (cpu.terminate) return;
    // 00a987a2  8b45d0                 -mov eax, dword ptr [ebp - 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-48) /* -0x30 */);
    // 00a987a5  894128                 -mov dword ptr [ecx + 0x28], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 00a987a8  8b45d4                 -mov eax, dword ptr [ebp - 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    // 00a987ab  89412c                 -mov dword ptr [ecx + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 00a987ae  8b45d8                 -mov eax, dword ptr [ebp - 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */);
    // 00a987b1  894130                 -mov dword ptr [ecx + 0x30], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(48) /* 0x30 */) = cpu.eax;
    // 00a987b4  8b45dc                 -mov eax, dword ptr [ebp - 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 00a987b7  894134                 -mov dword ptr [ecx + 0x34], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(52) /* 0x34 */) = cpu.eax;
    // 00a987ba  837dc800               +cmp dword ptr [ebp - 0x38], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-56) /* -0x38 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a987be  7d0f                   -jge 0xa987cf
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a987cf;
    }
    // 00a987c0  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 00a987c3  8d5001                 -lea edx, [eax + 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a987c6  895120                 -mov dword ptr [ecx + 0x20], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 00a987c9  c604062d               -mov byte ptr [esi + eax], 0x2d
    app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1) = 45 /*0x2d*/;
    // 00a987cd  eb29                   -jmp 0xa987f8
    goto L_0x00a987f8;
L_0x00a987cf:
    // 00a987cf  8a611e                 -mov ah, byte ptr [ecx + 0x1e]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */);
    // 00a987d2  f6c404                 +test ah, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 4 /*0x4*/));
    // 00a987d5  740f                   -je 0xa987e6
    if (cpu.flags.zf)
    {
        goto L_0x00a987e6;
    }
    // 00a987d7  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 00a987da  8d5001                 -lea edx, [eax + 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a987dd  895120                 -mov dword ptr [ecx + 0x20], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 00a987e0  c604062b               -mov byte ptr [esi + eax], 0x2b
    app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1) = 43 /*0x2b*/;
    // 00a987e4  eb12                   -jmp 0xa987f8
    goto L_0x00a987f8;
L_0x00a987e6:
    // 00a987e6  f6c402                 +test ah, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 2 /*0x2*/));
    // 00a987e9  740d                   -je 0xa987f8
    if (cpu.flags.zf)
    {
        goto L_0x00a987f8;
    }
    // 00a987eb  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 00a987ee  8d5001                 -lea edx, [eax + 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a987f1  895120                 -mov dword ptr [ecx + 0x20], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 00a987f4  c6040620               -mov byte ptr [esi + eax], 0x20
    app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1) = 32 /*0x20*/;
L_0x00a987f8:
    // 00a987f8  8cda                   -mov edx, ds
    cpu.edx = cpu.ds;
    // 00a987fa  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a987fc  8d65f4                 -lea esp, [ebp - 0xc]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a987ff  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a98800  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a98801  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a98802  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a98803  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a98804(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a98804  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a98805  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00a98807  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a98809  e85b1f0000             -call 0xa9a769
    cpu.esp -= 4;
    sub_a9a769(app, cpu);
    if (cpu.terminate) return;
    // 00a9880e  dd1b                   -fstp qword ptr [ebx]
    app->getMemory<double>(cpu.ebx) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a98810  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a98811  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a98820(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a98820  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a98830(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a98830  6650                   -push ax
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.ax;
    cpu.esp -= 4;
    // 00a98832  9b                     -wait 
    /*nothing*/;
    // 00a98833  dbe3                   +fninit 
    cpu.fpu.init();
    // 00a98835  d9e8                   +fld1 
    cpu.fpu.push(1.0);
    // 00a98837  d9ee                   +fldz 
    cpu.fpu.push(0.0);
    // 00a98839  def9                   +fdivp st(1)
    cpu.fpu.st(1) /= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00a9883b  d9c0                   +fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 00a9883d  d9e0                   +fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
    // 00a9883f  ded9                   +fcompp 
    cpu.fpu.compare(cpu.fpu.st(0), cpu.fpu.st(1));
    cpu.fpu.pop();
    cpu.fpu.pop();
    // 00a98841  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00a98843  b002                   -mov al, 2
    cpu.al = 2 /*0x2*/;
    // 00a98845  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 00a98846  7402                   -je 0xa9884a
    if (cpu.flags.zf)
    {
        goto L_0x00a9884a;
    }
    // 00a98848  b003                   -mov al, 3
    cpu.al = 3 /*0x3*/;
L_0x00a9884a:
    // 00a9884a  9b                     -wait 
    /*nothing*/;
    // 00a9884b  dbe3                   -fninit 
    cpu.fpu.init();
    // 00a9884d  d92c24                 -fldcw word ptr [esp]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.esp);
    // 00a98850  66870424               -xchg word ptr [esp], ax
    {
        x86::reg16 tmp = app->getMemory<x86::reg16>(cpu.esp);
        app->getMemory<x86::reg16>(cpu.esp) = cpu.ax;
        cpu.ax = tmp;
    }
    // 00a98854  6658                   -pop ax
    cpu.ax = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a98856  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a98860(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a98860  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a98861  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a98862  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a98863  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a98864  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a98865  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a98867  6804010000             -push 0x104
    app->getMemory<x86::reg32>(cpu.esp-4) = 260 /*0x104*/;
    cpu.esp -= 4;
    // 00a9886c  68f820aa00             -push 0xaa20f8
    app->getMemory<x86::reg32>(cpu.esp-4) = 11149560 /*0xaa20f8*/;
    cpu.esp -= 4;
    // 00a98871  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a98873  2eff15e8cda900         -call dword ptr cs:[0xa9cde8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11128296) /* 0xa9cde8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a9887a  6804010000             -push 0x104
    app->getMemory<x86::reg32>(cpu.esp-4) = 260 /*0x104*/;
    cpu.esp -= 4;
    // 00a9887f  68fc21aa00             -push 0xaa21fc
    app->getMemory<x86::reg32>(cpu.esp-4) = 11149820 /*0xaa21fc*/;
    cpu.esp -= 4;
    // 00a98884  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a98885  be4cf2a900             -mov esi, 0xa9f24c
    cpu.esi = 11137612 /*0xa9f24c*/;
    // 00a9888a  2eff15e8cda900         -call dword ptr cs:[0xa9cde8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11128296) /* 0xa9cde8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a98891  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 00a98893  bf101faa00             -mov edi, 0xaa1f10
    cpu.edi = 11149072 /*0xaa1f10*/;
    // 00a98898  8825101faa00           -mov byte ptr [0xaa1f10], ah
    app->getMemory<x86::reg8>(x86::reg32(11149072) /* 0xaa1f10 */) = cpu.ah;
    // 00a9889e  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a9889f  1e                     -push ds
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.ds;
    cpu.esp -= 4;
    // 00a988a0  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a988a1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a988a2  2bc9                   +sub ecx, ecx
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a988a4  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a988a5  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 00a988a7  f2ae                   -repne scasb al, byte ptr es:[edi]
    while (cpu.ecx)
    {
        {
            x86::reg8 tmp1 = cpu.al;
            x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ees + cpu.edi)));
            x86::reg8 result = tmp1 - tmp2;
            cpu.flags.cf = tmp1 < tmp2;
            cpu.flags.of = 1 & (tmp1 >> 7);
            cpu.flags.of ^= 1 & (result >> 7);
            cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
            cpu.set_szp(result);
        }
        if (cpu.flags.df)
        {
            cpu.edi -= 1;
        }
        else
        {
            cpu.edi += 1;
        }
        --cpu.ecx;
        if (cpu.flags.zf)
            break;
    }
    // 00a988a9  4f                     -dec edi
    (cpu.edi)--;
L_0x00a988aa:
    // 00a988aa  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00a988ac  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00a988ae  3c00                   +cmp al, 0
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a988b0  7410                   -je 0xa988c2
    if (cpu.flags.zf)
    {
        goto L_0x00a988c2;
    }
    // 00a988b2  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00a988b5  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00a988b8  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00a988bb  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00a988be  3c00                   +cmp al, 0
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a988c0  75e8                   -jne 0xa988aa
    if (!cpu.flags.zf)
    {
        goto L_0x00a988aa;
    }
L_0x00a988c2:
    // 00a988c2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a988c3  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a988c4  bef820aa00             -mov esi, 0xaa20f8
    cpu.esi = 11149560 /*0xaa20f8*/;
    // 00a988c9  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a988ca  1e                     -push ds
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.ds;
    cpu.esp -= 4;
    // 00a988cb  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a988cc  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a988cd  2bc9                   +sub ecx, ecx
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a988cf  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a988d0  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 00a988d2  f2ae                   -repne scasb al, byte ptr es:[edi]
    while (cpu.ecx)
    {
        {
            x86::reg8 tmp1 = cpu.al;
            x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ees + cpu.edi)));
            x86::reg8 result = tmp1 - tmp2;
            cpu.flags.cf = tmp1 < tmp2;
            cpu.flags.of = 1 & (tmp1 >> 7);
            cpu.flags.of ^= 1 & (result >> 7);
            cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
            cpu.set_szp(result);
        }
        if (cpu.flags.df)
        {
            cpu.edi -= 1;
        }
        else
        {
            cpu.edi += 1;
        }
        --cpu.ecx;
        if (cpu.flags.zf)
            break;
    }
    // 00a988d4  4f                     -dec edi
    (cpu.edi)--;
L_0x00a988d5:
    // 00a988d5  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00a988d7  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00a988d9  3c00                   +cmp al, 0
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a988db  7410                   -je 0xa988ed
    if (cpu.flags.zf)
    {
        goto L_0x00a988ed;
    }
    // 00a988dd  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00a988e0  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00a988e3  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00a988e6  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00a988e9  3c00                   +cmp al, 0
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a988eb  75e8                   -jne 0xa988d5
    if (!cpu.flags.zf)
    {
        goto L_0x00a988d5;
    }
L_0x00a988ed:
    // 00a988ed  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a988ee  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a988ef  be80f2a900             -mov esi, 0xa9f280
    cpu.esi = 11137664 /*0xa9f280*/;
    // 00a988f4  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a988f5  1e                     -push ds
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.ds;
    cpu.esp -= 4;
    // 00a988f6  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a988f7  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a988f8  2bc9                   +sub ecx, ecx
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a988fa  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a988fb  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 00a988fd  f2ae                   -repne scasb al, byte ptr es:[edi]
    while (cpu.ecx)
    {
        {
            x86::reg8 tmp1 = cpu.al;
            x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ees + cpu.edi)));
            x86::reg8 result = tmp1 - tmp2;
            cpu.flags.cf = tmp1 < tmp2;
            cpu.flags.of = 1 & (tmp1 >> 7);
            cpu.flags.of ^= 1 & (result >> 7);
            cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
            cpu.set_szp(result);
        }
        if (cpu.flags.df)
        {
            cpu.edi -= 1;
        }
        else
        {
            cpu.edi += 1;
        }
        --cpu.ecx;
        if (cpu.flags.zf)
            break;
    }
    // 00a988ff  4f                     -dec edi
    (cpu.edi)--;
L_0x00a98900:
    // 00a98900  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00a98902  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00a98904  3c00                   +cmp al, 0
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a98906  7410                   -je 0xa98918
    if (cpu.flags.zf)
    {
        goto L_0x00a98918;
    }
    // 00a98908  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00a9890b  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00a9890e  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00a98911  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00a98914  3c00                   +cmp al, 0
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a98916  75e8                   -jne 0xa98900
    if (!cpu.flags.zf)
    {
        goto L_0x00a98900;
    }
L_0x00a98918:
    // 00a98918  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a98919  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a9891a  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a9891c  68fc21aa00             -push 0xaa21fc
    app->getMemory<x86::reg32>(cpu.esp-4) = 11149820 /*0xaa21fc*/;
    cpu.esp -= 4;
    // 00a98921  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a98922  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a98924  2eff1574cda900         -call dword ptr cs:[0xa9cd74]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11128180) /* 0xa9cd74 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a9892b  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a98930  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a98931  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a98932  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a98933  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a98934  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a98935  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a98940(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a98940  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a98950(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a98950  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a98951  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a98952  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a98953  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a98954  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a98955  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a98956  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00a98959  b834f3a900             -mov eax, 0xa9f334
    cpu.eax = 11137844 /*0xa9f334*/;
    // 00a9895e  e84dc1ffff             -call 0xa94ab0
    cpu.esp -= 4;
    sub_a94ab0(app, cpu);
    if (cpu.terminate) return;
    // 00a98963  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a98965  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a98967  0f84f9000000           -je 0xa98a66
    if (cpu.flags.zf)
    {
        goto L_0x00a98a66;
    }
L_0x00a9896d:
    // 00a9896d  803900                 +cmp byte ptr [ecx], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a98970  0f84e6000000           -je 0xa98a5c
    if (cpu.flags.zf)
    {
        goto L_0x00a98a5c;
    }
    // 00a98976  b23a                   -mov dl, 0x3a
    cpu.dl = 58 /*0x3a*/;
    // 00a98978  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
L_0x00a9897a:
    // 00a9897a  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00a9897c  3ac2                   +cmp al, dl
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.dl));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a9897e  7412                   -je 0xa98992
    if (cpu.flags.zf)
    {
        goto L_0x00a98992;
    }
    // 00a98980  3c00                   +cmp al, 0
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a98982  740c                   -je 0xa98990
    if (cpu.flags.zf)
    {
        goto L_0x00a98990;
    }
    // 00a98984  46                     -inc esi
    (cpu.esi)++;
    // 00a98985  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00a98987  3ac2                   +cmp al, dl
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.dl));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a98989  7407                   -je 0xa98992
    if (cpu.flags.zf)
    {
        goto L_0x00a98992;
    }
    // 00a9898b  46                     -inc esi
    (cpu.esi)++;
    // 00a9898c  3c00                   +cmp al, 0
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a9898e  75ea                   -jne 0xa9897a
    if (!cpu.flags.zf)
    {
        goto L_0x00a9897a;
    }
L_0x00a98990:
    // 00a98990  2bf6                   -sub esi, esi
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.esi));
L_0x00a98992:
    // 00a98992  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a98994  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
    // 00a98996  29ce                   -sub esi, ecx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a98998  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00a9899a  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00a9899c  e8af1e0000             -call 0xa9a850
    cpu.esp -= 4;
    sub_a9a850(app, cpu);
    if (cpu.terminate) return;
    // 00a989a1  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
    // 00a989a6  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 00a989a8  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a989aa  881434                 -mov byte ptr [esp + esi], dl
    app->getMemory<x86::reg8>(cpu.esp + cpu.esi * 1) = cpu.dl;
    // 00a989ad  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a989af  e82c200000             -call 0xa9a9e0
    cpu.esp -= 4;
    sub_a9a9e0(app, cpu);
    if (cpu.terminate) return;
    // 00a989b4  8d7501                 -lea esi, [ebp + 1]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(1) /* 0x1 */);
    // 00a989b7  b23a                   -mov dl, 0x3a
    cpu.dl = 58 /*0x3a*/;
    // 00a989b9  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a989bb  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
L_0x00a989bd:
    // 00a989bd  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00a989bf  3ac2                   +cmp al, dl
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.dl));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a989c1  7412                   -je 0xa989d5
    if (cpu.flags.zf)
    {
        goto L_0x00a989d5;
    }
    // 00a989c3  3c00                   +cmp al, 0
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a989c5  740c                   -je 0xa989d3
    if (cpu.flags.zf)
    {
        goto L_0x00a989d3;
    }
    // 00a989c7  46                     -inc esi
    (cpu.esi)++;
    // 00a989c8  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00a989ca  3ac2                   +cmp al, dl
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.dl));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a989cc  7407                   -je 0xa989d5
    if (cpu.flags.zf)
    {
        goto L_0x00a989d5;
    }
    // 00a989ce  46                     -inc esi
    (cpu.esi)++;
    // 00a989cf  3c00                   +cmp al, 0
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a989d1  75ea                   -jne 0xa989bd
    if (!cpu.flags.zf)
    {
        goto L_0x00a989bd;
    }
L_0x00a989d3:
    // 00a989d3  2bf6                   -sub esi, esi
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.esi));
L_0x00a989d5:
    // 00a989d5  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a989d7  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
    // 00a989d9  29ce                   -sub esi, ecx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a989db  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00a989dd  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00a989df  e86c1e0000             -call 0xa9a850
    cpu.esp -= 4;
    sub_a9a850(app, cpu);
    if (cpu.terminate) return;
    // 00a989e4  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
    // 00a989e9  30f6                   -xor dh, dh
    cpu.dh ^= x86::reg8(x86::sreg8(cpu.dh));
    // 00a989eb  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a989ed  883434                 -mov byte ptr [esp + esi], dh
    app->getMemory<x86::reg8>(cpu.esp + cpu.esi * 1) = cpu.dh;
    // 00a989f0  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a989f2  e8e91f0000             -call 0xa9a9e0
    cpu.esp -= 4;
    sub_a9a9e0(app, cpu);
    if (cpu.terminate) return;
    // 00a989f7  8d7501                 -lea esi, [ebp + 1]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(1) /* 0x1 */);
    // 00a989fa  b22a                   -mov dl, 0x2a
    cpu.dl = 42 /*0x2a*/;
    // 00a989fc  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00a98a00  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
L_0x00a98a02:
    // 00a98a02  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00a98a04  3ac2                   +cmp al, dl
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.dl));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a98a06  7412                   -je 0xa98a1a
    if (cpu.flags.zf)
    {
        goto L_0x00a98a1a;
    }
    // 00a98a08  3c00                   +cmp al, 0
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a98a0a  740c                   -je 0xa98a18
    if (cpu.flags.zf)
    {
        goto L_0x00a98a18;
    }
    // 00a98a0c  46                     -inc esi
    (cpu.esi)++;
    // 00a98a0d  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00a98a0f  3ac2                   +cmp al, dl
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.dl));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a98a11  7407                   -je 0xa98a1a
    if (cpu.flags.zf)
    {
        goto L_0x00a98a1a;
    }
    // 00a98a13  46                     -inc esi
    (cpu.esi)++;
    // 00a98a14  3c00                   +cmp al, 0
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a98a16  75ea                   -jne 0xa98a02
    if (!cpu.flags.zf)
    {
        goto L_0x00a98a02;
    }
L_0x00a98a18:
    // 00a98a18  2bf6                   -sub esi, esi
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.esi));
L_0x00a98a1a:
    // 00a98a1a  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a98a1c  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
    // 00a98a1e  29ce                   -sub esi, ecx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a98a20  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00a98a22  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00a98a24  e8271e0000             -call 0xa9a850
    cpu.esp -= 4;
    sub_a9a850(app, cpu);
    if (cpu.terminate) return;
    // 00a98a29  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a98a2b  30db                   -xor bl, bl
    cpu.bl ^= x86::reg8(x86::sreg8(cpu.bl));
    // 00a98a2d  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00a98a2f  881c34                 -mov byte ptr [esp + esi], bl
    app->getMemory<x86::reg8>(cpu.esp + cpu.esi * 1) = cpu.bl;
    // 00a98a32  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
    // 00a98a37  e8a41f0000             -call 0xa9a9e0
    cpu.esp -= 4;
    sub_a9a9e0(app, cpu);
    if (cpu.terminate) return;
    // 00a98a3c  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a98a3e  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00a98a40  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00a98a44  e88febffff             -call 0xa975d8
    cpu.esp -= 4;
    sub_a975d8(app, cpu);
    if (cpu.terminate) return;
    // 00a98a49  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00a98a4b  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a98a4d  8d7501                 -lea esi, [ebp + 1]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(1) /* 0x1 */);
    // 00a98a50  e893050000             -call 0xa98fe8
    cpu.esp -= 4;
    sub_a98fe8(app, cpu);
    if (cpu.terminate) return;
    // 00a98a55  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00a98a57  e911ffffff             -jmp 0xa9896d
    goto L_0x00a9896d;
L_0x00a98a5c:
    // 00a98a5c  b840f3a900             -mov eax, 0xa9f340
    cpu.eax = 11137856 /*0xa9f340*/;
    // 00a98a61  e8ea1f0000             -call 0xa9aa50
    cpu.esp -= 4;
    sub_a9aa50(app, cpu);
    if (cpu.terminate) return;
L_0x00a98a66:
    // 00a98a66  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00a98a69  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a98a6a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a98a6b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a98a6c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a98a6d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a98a6e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a98a6f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a98a70(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a98a70  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a98a71  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a98a72  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a98a73  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a98a74  8b150410aa00           -mov edx, dword ptr [0xaa1004]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11145220) /* 0xaa1004 */);
    // 00a98a7a  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a98a7c  0f8480000000           -je 0xa98b02
    if (cpu.flags.zf)
    {
        goto L_0x00a98b02;
    }
    // 00a98a82  eb30                   -jmp 0xa98ab4
    goto L_0x00a98ab4;
L_0x00a98a84:
    // 00a98a84  833d0010aa0000         +cmp dword ptr [0xaa1000], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(11145216) /* 0xaa1000 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a98a8b  7424                   -je 0xa98ab1
    if (cpu.flags.zf)
    {
        goto L_0x00a98ab1;
    }
    // 00a98a8d  8b350410aa00           -mov esi, dword ptr [0xaa1004]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(11145220) /* 0xaa1004 */);
    // 00a98a93  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00a98a95  29f1                   -sub ecx, esi
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00a98a97  8b1d0010aa00           -mov ebx, dword ptr [0xaa1000]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(11145216) /* 0xaa1000 */);
    // 00a98a9d  c1f902                 -sar ecx, 2
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (2 /*0x2*/ % 32));
    // 00a98aa0  803c1900               +cmp byte ptr [ecx + ebx], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx + cpu.ebx * 1);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a98aa4  7405                   -je 0xa98aab
    if (cpu.flags.zf)
    {
        goto L_0x00a98aab;
    }
    // 00a98aa6  e8c5c2ffff             -call 0xa94d70
    cpu.esp -= 4;
    sub_a94d70(app, cpu);
    if (cpu.terminate) return;
L_0x00a98aab:
    // 00a98aab  c70200000000           -mov dword ptr [edx], 0
    app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
L_0x00a98ab1:
    // 00a98ab1  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00a98ab4:
    // 00a98ab4  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 00a98ab6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a98ab8  75ca                   -jne 0xa98a84
    if (!cpu.flags.zf)
    {
        goto L_0x00a98a84;
    }
    // 00a98aba  833d0010aa0000         +cmp dword ptr [0xaa1000], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(11145216) /* 0xaa1000 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a98ac1  750c                   -jne 0xa98acf
    if (!cpu.flags.zf)
    {
        goto L_0x00a98acf;
    }
    // 00a98ac3  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 00a98ac8  e8b3c1ffff             -call 0xa94c80
    cpu.esp -= 4;
    sub_a94c80(app, cpu);
    if (cpu.terminate) return;
    // 00a98acd  eb0f                   -jmp 0xa98ade
    goto L_0x00a98ade;
L_0x00a98acf:
    // 00a98acf  ba05000000             -mov edx, 5
    cpu.edx = 5 /*0x5*/;
    // 00a98ad4  a10410aa00             -mov eax, dword ptr [0xaa1004]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11145220) /* 0xaa1004 */);
    // 00a98ad9  e8c2050000             -call 0xa990a0
    cpu.esp -= 4;
    sub_a990a0(app, cpu);
    if (cpu.terminate) return;
L_0x00a98ade:
    // 00a98ade  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a98ae0  750a                   -jne 0xa98aec
    if (!cpu.flags.zf)
    {
        goto L_0x00a98aec;
    }
    // 00a98ae2  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a98ae7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a98ae8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a98ae9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a98aea  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a98aeb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a98aec:
    // 00a98aec  a30410aa00             -mov dword ptr [0xaa1004], eax
    app->getMemory<x86::reg32>(x86::reg32(11145220) /* 0xaa1004 */) = cpu.eax;
    // 00a98af1  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 00a98af7  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a98afa  a30010aa00             -mov dword ptr [0xaa1000], eax
    app->getMemory<x86::reg32>(x86::reg32(11145216) /* 0xaa1000 */) = cpu.eax;
    // 00a98aff  c60000                 -mov byte ptr [eax], 0
    app->getMemory<x86::reg8>(cpu.eax) = 0 /*0x0*/;
L_0x00a98b02:
    // 00a98b02  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a98b04  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a98b05  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a98b06  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a98b07  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a98b08  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a98b10(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a98b10  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a98b11  833df01daa0000         +cmp dword ptr [0xaa1df0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(11148784) /* 0xaa1df0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a98b18  7421                   -je 0xa98b3b
    if (cpu.flags.zf)
    {
        goto L_0x00a98b3b;
    }
    // 00a98b1a  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a98b1c  8a1a                   -mov bl, byte ptr [edx]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx);
    // 00a98b1e  8a9b011eaa00           -mov bl, byte ptr [ebx + 0xaa1e01]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(11148801) /* 0xaa1e01 */);
    // 00a98b24  80e301                 -and bl, 1
    cpu.bl &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00a98b27  81e3ff000000           +and ebx, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 00a98b2d  740c                   -je 0xa98b3b
    if (cpu.flags.zf)
    {
        goto L_0x00a98b3b;
    }
    // 00a98b2f  8a1a                   -mov bl, byte ptr [edx]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx);
    // 00a98b31  8818                   -mov byte ptr [eax], bl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.bl;
    // 00a98b33  8a5201                 -mov dl, byte ptr [edx + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 00a98b36  885001                 -mov byte ptr [eax + 1], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */) = cpu.dl;
    // 00a98b39  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a98b3a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a98b3b:
    // 00a98b3b  8a12                   -mov dl, byte ptr [edx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx);
    // 00a98b3d  8810                   -mov byte ptr [eax], dl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.dl;
    // 00a98b3f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a98b40  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a98b50(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a98b50  833df01daa0000         +cmp dword ptr [0xaa1df0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(11148784) /* 0xaa1df0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a98b57  741c                   -je 0xa98b75
    if (cpu.flags.zf)
    {
        goto L_0x00a98b75;
    }
    // 00a98b59  8a00                   -mov al, byte ptr [eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax);
    // 00a98b5b  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00a98b60  8a80011eaa00           -mov al, byte ptr [eax + 0xaa1e01]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(11148801) /* 0xaa1e01 */);
    // 00a98b66  2401                   -and al, 1
    cpu.al &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00a98b68  25ff000000             +and eax, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 00a98b6d  7406                   -je 0xa98b75
    if (cpu.flags.zf)
    {
        goto L_0x00a98b75;
    }
    // 00a98b6f  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 00a98b74  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a98b75:
    // 00a98b75  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a98b7a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void sub_a98b80(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a98b80  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a98b81  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a98b82  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a98b83  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a98b86  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_0x00a98b88:
    // 00a98b88  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a98b8a  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a98b8c  e84fe1ffff             -call 0xa96ce0
    cpu.esp -= 4;
    sub_a96ce0(app, cpu);
    if (cpu.terminate) return;
    // 00a98b91  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a98b93  7531                   -jne 0xa98bc6
    if (!cpu.flags.zf)
    {
        goto L_0x00a98bc6;
    }
    // 00a98b95  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a98b97  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00a98b99  e822230000             -call 0xa9aec0
    cpu.esp -= 4;
    sub_a9aec0(app, cpu);
    if (cpu.terminate) return;
    // 00a98b9e  e85d230000             -call 0xa9af00
    cpu.esp -= 4;
    sub_a9af00(app, cpu);
    if (cpu.terminate) return;
    // 00a98ba3  e8c8230000             -call 0xa9af70
    cpu.esp -= 4;
    sub_a9af70(app, cpu);
    if (cpu.terminate) return;
    // 00a98ba8  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a98baa  30d2                   +xor dl, dl
    cpu.clear_co();
    cpu.set_szp((cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl))));
    // 00a98bac  e89fffffff             -call 0xa98b50
    cpu.esp -= 4;
    sub_a98b50(app, cpu);
    if (cpu.terminate) return;
    // 00a98bb1  881404                 -mov byte ptr [esp + eax], dl
    app->getMemory<x86::reg8>(cpu.esp + cpu.eax * 1) = cpu.dl;
    // 00a98bb4  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00a98bb6  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a98bb8  e853ffffff             -call 0xa98b10
    cpu.esp -= 4;
    sub_a98b10(app, cpu);
    if (cpu.terminate) return;
    // 00a98bbd  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a98bbf  e8bce1ffff             -call 0xa96d80
    cpu.esp -= 4;
    sub_a96d80(app, cpu);
    if (cpu.terminate) return;
    // 00a98bc4  ebc2                   -jmp 0xa98b88
    goto L_0x00a98b88;
L_0x00a98bc6:
    // 00a98bc6  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a98bc8  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a98bcb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a98bcc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a98bcd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a98bce  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void sub_a98bd0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a98bd0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a98bd1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a98bd2  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 00a98bd4  3a1a                   +cmp bl, byte ptr [edx]
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.edx)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a98bd6  7541                   -jne 0xa98c19
    if (!cpu.flags.zf)
    {
        goto L_0x00a98c19;
    }
    // 00a98bd8  833df01daa0000         +cmp dword ptr [0xaa1df0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(11148784) /* 0xaa1df0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a98bdf  741f                   -je 0xa98c00
    if (cpu.flags.zf)
    {
        goto L_0x00a98c00;
    }
    // 00a98be1  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a98be3  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 00a98be5  8a9b011eaa00           -mov bl, byte ptr [ebx + 0xaa1e01]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(11148801) /* 0xaa1e01 */);
    // 00a98beb  80e301                 -and bl, 1
    cpu.bl &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00a98bee  81e3ff000000           +and ebx, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 00a98bf4  740a                   -je 0xa98c00
    if (cpu.flags.zf)
    {
        goto L_0x00a98c00;
    }
    // 00a98bf6  8a5801                 -mov bl, byte ptr [eax + 1]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a98bf9  8a4a01                 -mov cl, byte ptr [edx + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 00a98bfc  38cb                   +cmp bl, cl
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.cl));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a98bfe  7505                   -jne 0xa98c05
    if (!cpu.flags.zf)
    {
        goto L_0x00a98c05;
    }
L_0x00a98c00:
    // 00a98c00  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a98c02  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a98c03  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a98c04  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a98c05:
    // 00a98c05  88d8                   -mov al, bl
    cpu.al = cpu.bl;
    // 00a98c07  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00a98c0c  88ca                   -mov dl, cl
    cpu.dl = cpu.cl;
    // 00a98c0e  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00a98c14  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00a98c16  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a98c17  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a98c18  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a98c19:
    // 00a98c19  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a98c1b  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 00a98c1d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a98c1f  8a02                   -mov al, byte ptr [edx]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx);
    // 00a98c21  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00a98c23  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a98c25  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a98c26  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a98c27  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a98c30(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a98c30  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a98c31  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a98c32  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a98c33  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a98c35  f6400d20               +test byte ptr [eax + 0xd], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(13) /* 0xd */) & 32 /*0x20*/));
    // 00a98c39  7522                   -jne 0xa98c5d
    if (!cpu.flags.zf)
    {
        goto L_0x00a98c5d;
    }
    // 00a98c3b  8b4210                 -mov eax, dword ptr [edx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00a98c3e  e84d230000             -call 0xa9af90
    cpu.esp -= 4;
    sub_a9af90(app, cpu);
    if (cpu.terminate) return;
    // 00a98c43  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a98c45  7416                   -je 0xa98c5d
    if (cpu.flags.zf)
    {
        goto L_0x00a98c5d;
    }
    // 00a98c47  8a5a0d                 -mov bl, byte ptr [edx + 0xd]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(13) /* 0xd */);
    // 00a98c4a  80cb20                 -or bl, 0x20
    cpu.bl |= x86::reg8(x86::sreg8(32 /*0x20*/));
    // 00a98c4d  885a0d                 -mov byte ptr [edx + 0xd], bl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(13) /* 0xd */) = cpu.bl;
    // 00a98c50  f6c307                 +test bl, 7
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 7 /*0x7*/));
    // 00a98c53  7508                   -jne 0xa98c5d
    if (!cpu.flags.zf)
    {
        goto L_0x00a98c5d;
    }
    // 00a98c55  88d9                   -mov cl, bl
    cpu.cl = cpu.bl;
    // 00a98c57  80c902                 -or cl, 2
    cpu.cl |= x86::reg8(x86::sreg8(2 /*0x2*/));
    // 00a98c5a  884a0d                 -mov byte ptr [edx + 0xd], cl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(13) /* 0xd */) = cpu.cl;
L_0x00a98c5d:
    // 00a98c5d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a98c5e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a98c5f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a98c60  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a98c70(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a98c70  803d54e4a90000         +cmp byte ptr [0xa9e454], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(11134036) /* 0xa9e454 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a98c77  741a                   -je 0xa98c93
    if (cpu.flags.zf)
    {
        goto L_0x00a98c93;
    }
    // 00a98c79  81e2ffff0000           +and edx, 0xffff
    cpu.clear_co();
    cpu.set_szp((cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/))));
    // 00a98c7f  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a98c80  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a98c81  cc                     -int3 
    NFS2_ASSERT(false);
    // 00a98c82  eb06                   -jmp 0xa98c8a
    goto L_0x00a98c8a;
    // 00a98c84  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a98c85  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a98c86  49                     -dec ecx
    (cpu.ecx)--;
    // 00a98c87  44                     -inc esp
    (cpu.esp)++;
    // 00a98c88  45                     -inc ebp
    (cpu.ebp)++;
    // 00a98c89  4f                     -dec edi
    (cpu.edi)--;
L_0x00a98c8a:
    // 00a98c8a  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a98c8f  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00a98c92  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a98c93:
    // 00a98c93  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a98c95  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a98ca0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a98ca0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a98ca1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a98ca2  2eff15c8cda900         -call dword ptr cs:[0xa9cdc8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11128264) /* 0xa9cdc8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a98ca9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a98caa  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a98cab  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void sub_a98cb0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a98cb0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a98cb1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a98cb2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a98cb3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a98cb4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a98cb5  81ec28020000           -sub esp, 0x228
    (cpu.esp) -= x86::reg32(x86::sreg32(552 /*0x228*/));
    // 00a98cbb  ff1594e2a900           -call dword ptr [0xa9e294]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11133588) /* 0xa9e294 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a98cc1  bd70f3a900             -mov ebp, 0xa9f370
    cpu.ebp = 11137904 /*0xa9f370*/;
    // 00a98cc6  8b7004                 -mov esi, dword ptr [eax + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00a98cc9  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x00a98ccb:
    // 00a98ccb  8d842414010000         -lea eax, [esp + 0x114]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(276) /* 0x114 */);
    // 00a98cd2  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00a98cd4  e87fe4ffff             -call 0xa97158
    cpu.esp -= 4;
    sub_a97158(app, cpu);
    if (cpu.terminate) return;
    // 00a98cd9  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 00a98cde  8d842414010000         -lea eax, [esp + 0x114]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(276) /* 0x114 */);
    // 00a98ce5  41                     -inc ecx
    (cpu.ecx)++;
    // 00a98ce6  e815230000             -call 0xa9b000
    cpu.esp -= 4;
    sub_a9b000(app, cpu);
    if (cpu.terminate) return;
    // 00a98ceb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a98ced  74dc                   -je 0xa98ccb
    if (cpu.flags.zf)
    {
        goto L_0x00a98ccb;
    }
    // 00a98cef  8d842414010000         -lea eax, [esp + 0x114]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(276) /* 0x114 */);
    // 00a98cf6  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00a98cf8  e8ab250000             -call 0xa9b2a8
    cpu.esp -= 4;
    sub_a9b2a8(app, cpu);
    if (cpu.terminate) return;
    // 00a98cfd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a98cff  751b                   -jne 0xa98d1c
    if (!cpu.flags.zf)
    {
        goto L_0x00a98d1c;
    }
    // 00a98d01  e8ba260000             -call 0xa9b3c0
    cpu.esp -= 4;
    sub_a9b3c0(app, cpu);
    if (cpu.terminate) return;
    // 00a98d06  83380b                 +cmp dword ptr [eax], 0xb
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(11 /*0xb*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a98d09  740a                   -je 0xa98d15
    if (cpu.flags.zf)
    {
        goto L_0x00a98d15;
    }
    // 00a98d0b  e8b0260000             -call 0xa9b3c0
    cpu.esp -= 4;
    sub_a9b3c0(app, cpu);
    if (cpu.terminate) return;
    // 00a98d10  833806                 +cmp dword ptr [eax], 6
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(6 /*0x6*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a98d13  75b6                   -jne 0xa98ccb
    if (!cpu.flags.zf)
    {
        goto L_0x00a98ccb;
    }
L_0x00a98d15:
    // 00a98d15  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a98d17  e998000000             -jmp 0xa98db4
    goto L_0x00a98db4;
L_0x00a98d1c:
    // 00a98d1c  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a98d1e  e8cde3ffff             -call 0xa970f0
    cpu.esp -= 4;
    sub_a970f0(app, cpu);
    if (cpu.terminate) return;
    // 00a98d23  8a1d68e1a900           -mov bl, byte ptr [0xa9e168]
    cpu.bl = app->getMemory<x86::reg8>(x86::reg32(11133288) /* 0xa9e168 */);
L_0x00a98d29:
    // 00a98d29  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a98d2b  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00a98d2d  e826e4ffff             -call 0xa97158
    cpu.esp -= 4;
    sub_a97158(app, cpu);
    if (cpu.terminate) return;
    // 00a98d32  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00a98d34  8d842414010000         -lea eax, [esp + 0x114]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(276) /* 0x114 */);
    // 00a98d3b  e8a0260000             -call 0xa9b3e0
    cpu.esp -= 4;
    sub_a9b3e0(app, cpu);
    if (cpu.terminate) return;
    // 00a98d40  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a98d42  7551                   -jne 0xa98d95
    if (!cpu.flags.zf)
    {
        goto L_0x00a98d95;
    }
    // 00a98d44  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a98d46  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00a98d48  e85b250000             -call 0xa9b2a8
    cpu.esp -= 4;
    sub_a9b2a8(app, cpu);
    if (cpu.terminate) return;
    // 00a98d4d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a98d4f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a98d51  742a                   -je 0xa98d7d
    if (cpu.flags.zf)
    {
        goto L_0x00a98d7d;
    }
    // 00a98d53  8a600d                 -mov ah, byte ptr [eax + 0xd]
    cpu.ah = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(13) /* 0xd */);
    // 00a98d56  80cc08                 -or ah, 8
    cpu.ah |= x86::reg8(x86::sreg8(8 /*0x8*/));
    // 00a98d59  88620d                 -mov byte ptr [edx + 0xd], ah
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(13) /* 0xd */) = cpu.ah;
    // 00a98d5c  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00a98d5f  885814                 -mov byte ptr [eax + 0x14], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.bl;
    // 00a98d62  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a98d64  881d68e1a900           -mov byte ptr [0xa9e168], bl
    app->getMemory<x86::reg8>(x86::reg32(11133288) /* 0xa9e168 */) = cpu.bl;
    // 00a98d6a  e851e6ffff             -call 0xa973c0
    cpu.esp -= 4;
    sub_a973c0(app, cpu);
    if (cpu.terminate) return;
    // 00a98d6f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a98d71  81c428020000           -add esp, 0x228
    (cpu.esp) += x86::reg32(x86::sreg32(552 /*0x228*/));
    // 00a98d77  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a98d78  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a98d79  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a98d7a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a98d7b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a98d7c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a98d7d:
    // 00a98d7d  e83e260000             -call 0xa9b3c0
    cpu.esp -= 4;
    sub_a9b3c0(app, cpu);
    if (cpu.terminate) return;
    // 00a98d82  83380b                 +cmp dword ptr [eax], 0xb
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(11 /*0xb*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a98d85  750e                   -jne 0xa98d95
    if (!cpu.flags.zf)
    {
        goto L_0x00a98d95;
    }
    // 00a98d87  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a98d89  81c428020000           -add esp, 0x228
    (cpu.esp) += x86::reg32(x86::sreg32(552 /*0x228*/));
    // 00a98d8f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a98d90  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a98d91  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a98d92  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a98d93  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a98d94  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a98d95:
    // 00a98d95  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 00a98d9a  8d842414010000         -lea eax, [esp + 0x114]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(276) /* 0x114 */);
    // 00a98da1  43                     -inc ebx
    (cpu.ebx)++;
    // 00a98da2  e859220000             -call 0xa9b000
    cpu.esp -= 4;
    sub_a9b000(app, cpu);
    if (cpu.terminate) return;
    // 00a98da7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a98da9  0f851cffffff           -jne 0xa98ccb
    if (!cpu.flags.zf)
    {
        goto L_0x00a98ccb;
    }
    // 00a98daf  e975ffffff             -jmp 0xa98d29
    goto L_0x00a98d29;
L_0x00a98db4:
    // 00a98db4  81c428020000           -add esp, 0x228
    (cpu.esp) += x86::reg32(x86::sreg32(552 /*0x228*/));
    // 00a98dba  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a98dbb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a98dbc  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a98dbd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a98dbe  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a98dbf  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a98dc0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a98dc0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a98dc1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a98dc2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a98dc3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a98dc4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a98dc5  803d6ce4a90000         +cmp byte ptr [0xa9e46c], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(11134060) /* 0xa9e46c */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a98dcc  0f85ab000000           -jne 0xa98e7d
    if (!cpu.flags.zf)
    {
        goto L_0x00a98e7d;
    }
    // 00a98dd2  bb58e4a900             -mov ebx, 0xa9e458
    cpu.ebx = 11134040 /*0xa9e458*/;
    // 00a98dd7  eb39                   -jmp 0xa98e12
    goto L_0x00a98e12;
L_0x00a98dd9:
    // 00a98dd9  e8d2bcffff             -call 0xa94ab0
    cpu.esp -= 4;
    sub_a94ab0(app, cpu);
    if (cpu.terminate) return;
    // 00a98dde  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a98de0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a98de2  742b                   -je 0xa98e0f
    if (cpu.flags.zf)
    {
        goto L_0x00a98e0f;
    }
    // 00a98de4  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a98de6  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a98de7  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a98de9  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a98deb  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a98ded  49                     -dec ecx
    (cpu.ecx)--;
    // 00a98dee  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a98df0  f2ae                   -repne scasb al, byte ptr es:[edi]
    while (cpu.ecx)
    {
        {
            x86::reg8 tmp1 = cpu.al;
            x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ees + cpu.edi)));
            x86::reg8 result = tmp1 - tmp2;
            cpu.flags.cf = tmp1 < tmp2;
            cpu.flags.of = 1 & (tmp1 >> 7);
            cpu.flags.of ^= 1 & (result >> 7);
            cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
            cpu.set_szp(result);
        }
        if (cpu.flags.df)
        {
            cpu.edi -= 1;
        }
        else
        {
            cpu.edi += 1;
        }
        --cpu.ecx;
        if (cpu.flags.zf)
            break;
    }
    // 00a98df2  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00a98df4  49                     -dec ecx
    (cpu.ecx)--;
    // 00a98df5  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a98df6  81f903010000           +cmp ecx, 0x103
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(259 /*0x103*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a98dfc  7711                   -ja 0xa98e0f
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a98e0f;
    }
    // 00a98dfe  bb03010000             -mov ebx, 0x103
    cpu.ebx = 259 /*0x103*/;
    // 00a98e03  b86ce4a900             -mov eax, 0xa9e46c
    cpu.eax = 11134060 /*0xa9e46c*/;
    // 00a98e08  e8f3250000             -call 0xa9b400
    cpu.esp -= 4;
    sub_a9b400(app, cpu);
    if (cpu.terminate) return;
    // 00a98e0d  eb0a                   -jmp 0xa98e19
    goto L_0x00a98e19;
L_0x00a98e0f:
    // 00a98e0f  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00a98e12:
    // 00a98e12  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 00a98e14  803800                 +cmp byte ptr [eax], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a98e17  75c0                   -jne 0xa98dd9
    if (!cpu.flags.zf)
    {
        goto L_0x00a98dd9;
    }
L_0x00a98e19:
    // 00a98e19  803d6ce4a90000         +cmp byte ptr [0xa9e46c], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(11134060) /* 0xa9e46c */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a98e20  752a                   -jne 0xa98e4c
    if (!cpu.flags.zf)
    {
        goto L_0x00a98e4c;
    }
    // 00a98e22  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a98e24  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a98e26  bf6ce4a900             -mov edi, 0xa9e46c
    cpu.edi = 11134060 /*0xa9e46c*/;
    // 00a98e2b  e880260000             -call 0xa9b4b0
    cpu.esp -= 4;
    sub_a9b4b0(app, cpu);
    if (cpu.terminate) return;
    // 00a98e30  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a98e32  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x00a98e33:
    // 00a98e33  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00a98e35  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00a98e37  3c00                   +cmp al, 0
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a98e39  7410                   -je 0xa98e4b
    if (cpu.flags.zf)
    {
        goto L_0x00a98e4b;
    }
    // 00a98e3b  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00a98e3e  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00a98e41  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00a98e44  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00a98e47  3c00                   +cmp al, 0
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a98e49  75e8                   -jne 0xa98e33
    if (!cpu.flags.zf)
    {
        goto L_0x00a98e33;
    }
L_0x00a98e4b:
    // 00a98e4b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00a98e4c:
    // 00a98e4c  bf6ce4a900             -mov edi, 0xa9e46c
    cpu.edi = 11134060 /*0xa9e46c*/;
    // 00a98e51  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a98e52  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a98e54  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a98e56  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a98e58  49                     -dec ecx
    (cpu.ecx)--;
    // 00a98e59  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a98e5b  f2ae                   -repne scasb al, byte ptr es:[edi]
    while (cpu.ecx)
    {
        {
            x86::reg8 tmp1 = cpu.al;
            x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ees + cpu.edi)));
            x86::reg8 result = tmp1 - tmp2;
            cpu.flags.cf = tmp1 < tmp2;
            cpu.flags.of = 1 & (tmp1 >> 7);
            cpu.flags.of ^= 1 & (result >> 7);
            cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
            cpu.set_szp(result);
        }
        if (cpu.flags.df)
        {
            cpu.edi -= 1;
        }
        else
        {
            cpu.edi += 1;
        }
        --cpu.ecx;
        if (cpu.flags.zf)
            break;
    }
    // 00a98e5d  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00a98e5f  49                     -dec ecx
    (cpu.ecx)--;
    // 00a98e60  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a98e61  8d41ff                 -lea eax, [ecx - 1]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(-1) /* -0x1 */);
    // 00a98e64  056ce4a900             -add eax, 0xa9e46c
    (cpu.eax) += x86::reg32(x86::sreg32(11134060 /*0xa9e46c*/));
    // 00a98e69  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 00a98e6b  80fb5c                 +cmp bl, 0x5c
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(92 /*0x5c*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a98e6e  740d                   -je 0xa98e7d
    if (cpu.flags.zf)
    {
        goto L_0x00a98e7d;
    }
    // 00a98e70  80fb2f                 +cmp bl, 0x2f
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(47 /*0x2f*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a98e73  7408                   -je 0xa98e7d
    if (cpu.flags.zf)
    {
        goto L_0x00a98e7d;
    }
    // 00a98e75  40                     -inc eax
    (cpu.eax)++;
    // 00a98e76  c6005c                 -mov byte ptr [eax], 0x5c
    app->getMemory<x86::reg8>(cpu.eax) = 92 /*0x5c*/;
    // 00a98e79  40                     -inc eax
    (cpu.eax)++;
    // 00a98e7a  c60000                 -mov byte ptr [eax], 0
    app->getMemory<x86::reg8>(cpu.eax) = 0 /*0x0*/;
L_0x00a98e7d:
    // 00a98e7d  b86ce4a900             -mov eax, 0xa9e46c
    cpu.eax = 11134060 /*0xa9e46c*/;
    // 00a98e82  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a98e83  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a98e84  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a98e85  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a98e86  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a98e87  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a98e90(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a98e90  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a98e91  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a98e92  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a98e93  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a98e94  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a98e96  f6400c80               +test byte ptr [eax + 0xc], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(12) /* 0xc */) & 128 /*0x80*/));
    // 00a98e9a  740d                   -je 0xa98ea9
    if (cpu.flags.zf)
    {
        goto L_0x00a98ea9;
    }
    // 00a98e9c  f6420d10               +test byte ptr [edx + 0xd], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(13) /* 0xd */) & 16 /*0x10*/));
    // 00a98ea0  7407                   -je 0xa98ea9
    if (cpu.flags.zf)
    {
        goto L_0x00a98ea9;
    }
    // 00a98ea2  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a98ea4  e817bdffff             -call 0xa94bc0
    cpu.esp -= 4;
    sub_a94bc0(app, cpu);
    if (cpu.terminate) return;
L_0x00a98ea9:
    // 00a98ea9  8b4210                 -mov eax, dword ptr [edx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00a98eac  e89f260000             -call 0xa9b550
    cpu.esp -= 4;
    sub_a9b550(app, cpu);
    if (cpu.terminate) return;
    // 00a98eb1  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a98eb3  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a98eb5  83f8ff                 +cmp eax, -1
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a98eb8  742a                   -je 0xa98ee4
    if (cpu.flags.zf)
    {
        goto L_0x00a98ee4;
    }
    // 00a98eba  8b4210                 -mov eax, dword ptr [edx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00a98ebd  ff1598e2a900           -call dword ptr [0xa9e298]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11133592) /* 0xa9e298 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a98ec3  8b7204                 -mov esi, dword ptr [edx + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00a98ec6  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a98ec8  740f                   -je 0xa98ed9
    if (cpu.flags.zf)
    {
        goto L_0x00a98ed9;
    }
    // 00a98eca  f6420d10               +test byte ptr [edx + 0xd], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(13) /* 0xd */) & 16 /*0x10*/));
    // 00a98ece  7405                   -je 0xa98ed5
    if (cpu.flags.zf)
    {
        goto L_0x00a98ed5;
    }
    // 00a98ed0  8d0c1e                 -lea ecx, [esi + ebx]
    cpu.ecx = x86::reg32(cpu.esi + cpu.ebx * 1);
    // 00a98ed3  eb04                   -jmp 0xa98ed9
    goto L_0x00a98ed9;
L_0x00a98ed5:
    // 00a98ed5  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00a98ed7  29f1                   -sub ecx, esi
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.esi));
L_0x00a98ed9:
    // 00a98ed9  8b4210                 -mov eax, dword ptr [edx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00a98edc  ff159ce2a900           -call dword ptr [0xa9e29c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11133596) /* 0xa9e29c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a98ee2  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
L_0x00a98ee4:
    // 00a98ee4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a98ee5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a98ee6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a98ee7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a98ee8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a98ef0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a98ef0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a98ef1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a98ef2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a98ef3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a98ef4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a98ef5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a98ef6  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a98ef8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a98efa  7c08                   -jl 0xa98f04
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a98f04;
    }
    // 00a98efc  3b0570e5a900           +cmp eax, dword ptr [0xa9e570]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(11134320) /* 0xa9e570 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a98f02  7611                   -jbe 0xa98f15
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a98f15;
    }
L_0x00a98f04:
    // 00a98f04  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 00a98f09  e8b2e4ffff             -call 0xa973c0
    cpu.esp -= 4;
    sub_a973c0(app, cpu);
    if (cpu.terminate) return;
    // 00a98f0e  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a98f13  eb61                   -jmp 0xa98f76
    goto L_0x00a98f76;
L_0x00a98f15:
    // 00a98f15  8b1588e3a900           -mov edx, dword ptr [0xa9e388]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11133832) /* 0xa9e388 */);
    // 00a98f1b  8b2dece2a900           -mov ebp, dword ptr [0xa9e2ec]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(11133676) /* 0xa9e2ec */);
    // 00a98f21  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a98f23  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00a98f25  8b3c9a                 -mov edi, dword ptr [edx + ebx*4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + cpu.ebx * 4);
    // 00a98f28  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00a98f2a  741e                   -je 0xa98f4a
    if (cpu.flags.zf)
    {
        goto L_0x00a98f4a;
    }
    // 00a98f2c  ff15e0e2a900           -call dword ptr [0xa9e2e0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11133664) /* 0xa9e2e0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a98f32  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a98f34  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a98f36  7412                   -je 0xa98f4a
    if (cpu.flags.zf)
    {
        goto L_0x00a98f4a;
    }
    // 00a98f38  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a98f3a  ff15e4e2a900           -call dword ptr [0xa9e2e4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11133668) /* 0xa9e2e4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a98f40  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a98f42  ff15ece2a900           -call dword ptr [0xa9e2ec]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11133676) /* 0xa9e2ec */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a98f48  eb21                   -jmp 0xa98f6b
    goto L_0x00a98f6b;
L_0x00a98f4a:
    // 00a98f4a  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00a98f4c  751d                   -jne 0xa98f6b
    if (!cpu.flags.zf)
    {
        goto L_0x00a98f6b;
    }
    // 00a98f4e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a98f4f  2eff1588cda900         -call dword ptr cs:[0xa9cd88]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11128200) /* 0xa9cd88 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a98f56  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a98f58  7511                   -jne 0xa98f6b
    if (!cpu.flags.zf)
    {
        goto L_0x00a98f6b;
    }
    // 00a98f5a  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 00a98f5f  beffffffff             -mov esi, 0xffffffff
    cpu.esi = 4294967295 /*0xffffffff*/;
    // 00a98f64  e857e4ffff             -call 0xa973c0
    cpu.esp -= 4;
    sub_a973c0(app, cpu);
    if (cpu.terminate) return;
    // 00a98f69  eb09                   -jmp 0xa98f74
    goto L_0x00a98f74;
L_0x00a98f6b:
    // 00a98f6b  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a98f6d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a98f6f  e874000000             -call 0xa98fe8
    cpu.esp -= 4;
    sub_a98fe8(app, cpu);
    if (cpu.terminate) return;
L_0x00a98f74:
    // 00a98f74  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x00a98f76:
    // 00a98f76  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a98f77  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a98f78  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a98f79  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a98f7a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a98f7b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a98f7c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void sub_a98f80(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a98f80  e92b260000             -jmp 0xa9b5b0
    return sub_a9b5b0(app, cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a98f90(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a98f90  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a98f91  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a98f92  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a98f93  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a98f95  3b0570e5a900           +cmp eax, dword ptr [0xa9e570]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(11134320) /* 0xa9e570 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a98f9b  7206                   -jb 0xa98fa3
    if (cpu.flags.cf)
    {
        goto L_0x00a98fa3;
    }
    // 00a98f9d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a98f9f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a98fa0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a98fa1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a98fa2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a98fa3:
    // 00a98fa3  83f803                 +cmp eax, 3
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a98fa6  7d33                   -jge 0xa98fdb
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a98fdb;
    }
    // 00a98fa8  8d1c8500000000         -lea ebx, [eax*4]
    cpu.ebx = x86::reg32(cpu.eax * 4);
    // 00a98faf  a1c4e5a900             -mov eax, dword ptr [0xa9e5c4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11134404) /* 0xa9e5c4 */);
    // 00a98fb4  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00a98fb6  8a4801                 -mov cl, byte ptr [eax + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a98fb9  f6c140                 +test cl, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 64 /*0x40*/));
    // 00a98fbc  751d                   -jne 0xa98fdb
    if (!cpu.flags.zf)
    {
        goto L_0x00a98fdb;
    }
    // 00a98fbe  88cd                   -mov ch, cl
    cpu.ch = cpu.cl;
    // 00a98fc0  80cd40                 -or ch, 0x40
    cpu.ch |= x86::reg8(x86::sreg8(64 /*0x40*/));
    // 00a98fc3  886801                 -mov byte ptr [eax + 1], ch
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */) = cpu.ch;
    // 00a98fc6  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a98fc8  e8c31f0000             -call 0xa9af90
    cpu.esp -= 4;
    sub_a9af90(app, cpu);
    if (cpu.terminate) return;
    // 00a98fcd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a98fcf  740a                   -je 0xa98fdb
    if (cpu.flags.zf)
    {
        goto L_0x00a98fdb;
    }
    // 00a98fd1  a1c4e5a900             -mov eax, dword ptr [0xa9e5c4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11134404) /* 0xa9e5c4 */);
    // 00a98fd6  804c030120             -or byte ptr [ebx + eax + 1], 0x20
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(1) /* 0x1 */ + cpu.eax * 1) |= x86::reg8(x86::sreg8(32 /*0x20*/));
L_0x00a98fdb:
    // 00a98fdb  a1c4e5a900             -mov eax, dword ptr [0xa9e5c4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11134404) /* 0xa9e5c4 */);
    // 00a98fe0  8b0490                 -mov eax, dword ptr [eax + edx*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 4);
    // 00a98fe3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a98fe4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a98fe5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a98fe6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void sub_a98fe8(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a98fe8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a98fe9  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00a98fec  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a98fee  740e                   -je 0xa98ffe
    if (cpu.flags.zf)
    {
        goto L_0x00a98ffe;
    }
    // 00a98ff0  8b1dc4e5a900           -mov ebx, dword ptr [0xa9e5c4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(11134404) /* 0xa9e5c4 */);
    // 00a98ff6  80ce40                 -or dh, 0x40
    cpu.dh |= x86::reg8(x86::sreg8(64 /*0x40*/));
    // 00a98ff9  891403                 -mov dword ptr [ebx + eax], edx
    app->getMemory<x86::reg32>(cpu.ebx + cpu.eax * 1) = cpu.edx;
    // 00a98ffc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a98ffd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a98ffe:
    // 00a98ffe  8b1dc4e5a900           -mov ebx, dword ptr [0xa9e5c4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(11134404) /* 0xa9e5c4 */);
    // 00a99004  891403                 -mov dword ptr [ebx + eax], edx
    app->getMemory<x86::reg32>(cpu.ebx + cpu.eax * 1) = cpu.edx;
    // 00a99007  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a99008  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a99010(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a99010  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a99012  7504                   -jne 0xa99018
    if (!cpu.flags.zf)
    {
        goto L_0x00a99018;
    }
    // 00a99014  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00a99016:
    // 00a99016  c3                     -ret 
    cpu.esp += 4;
    return;
    // 00a99017  90                     -nop 
    ;
L_0x00a99018:
    // 00a99018  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a9901a  74fa                   -je 0xa99016
    if (cpu.flags.zf)
    {
        goto L_0x00a99016;
    }
    // 00a9901c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a9901d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a9901f  e8e4e3ffff             -call 0xa97408
    cpu.esp -= 4;
    sub_a97408(app, cpu);
    if (cpu.terminate) return;
    // 00a99024  83fa7b                 +cmp edx, 0x7b
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(123 /*0x7b*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a99027  7507                   -jne 0xa99030
    if (!cpu.flags.zf)
    {
        goto L_0x00a99030;
    }
    // 00a99029  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a9902e  eb45                   -jmp 0xa99075
    goto L_0x00a99075;
L_0x00a99030:
    // 00a99030  81face000000           +cmp edx, 0xce
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(206 /*0xce*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a99036  7511                   -jne 0xa99049
    if (!cpu.flags.zf)
    {
        goto L_0x00a99049;
    }
    // 00a99038  b809000000             -mov eax, 9
    cpu.eax = 9 /*0x9*/;
    // 00a9903d  e87ee3ffff             -call 0xa973c0
    cpu.esp -= 4;
    sub_a973c0(app, cpu);
    if (cpu.terminate) return;
    // 00a99042  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a99047  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a99048  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a99049:
    // 00a99049  81fab7000000           +cmp edx, 0xb7
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(183 /*0xb7*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a9904f  7511                   -jne 0xa99062
    if (!cpu.flags.zf)
    {
        goto L_0x00a99062;
    }
    // 00a99051  b807000000             -mov eax, 7
    cpu.eax = 7 /*0x7*/;
    // 00a99056  e865e3ffff             -call 0xa973c0
    cpu.esp -= 4;
    sub_a973c0(app, cpu);
    if (cpu.terminate) return;
    // 00a9905b  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a99060  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a99061  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a99062:
    // 00a99062  83fa13                 +cmp edx, 0x13
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(19 /*0x13*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a99065  7605                   -jbe 0xa9906c
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a9906c;
    }
    // 00a99067  ba13000000             -mov edx, 0x13
    cpu.edx = 19 /*0x13*/;
L_0x00a9906c:
    // 00a9906c  8b82c5e5a900           -mov eax, dword ptr [edx + 0xa9e5c5]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(11134405) /* 0xa9e5c5 */);
    // 00a99072  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
L_0x00a99075:
    // 00a99075  e846e3ffff             -call 0xa973c0
    cpu.esp -= 4;
    sub_a973c0(app, cpu);
    if (cpu.terminate) return;
    // 00a9907a  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a9907f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a99080  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a9901c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00a9901c;
    // 00a99010  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a99012  7504                   -jne 0xa99018
    if (!cpu.flags.zf)
    {
        goto L_0x00a99018;
    }
    // 00a99014  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00a99016:
    // 00a99016  c3                     -ret 
    cpu.esp += 4;
    return;
    // 00a99017  90                     -nop 
    ;
L_0x00a99018:
    // 00a99018  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a9901a  74fa                   -je 0xa99016
    if (cpu.flags.zf)
    {
        goto L_0x00a99016;
    }
L_entry_0x00a9901c:
    // 00a9901c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a9901d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a9901f  e8e4e3ffff             -call 0xa97408
    cpu.esp -= 4;
    sub_a97408(app, cpu);
    if (cpu.terminate) return;
    // 00a99024  83fa7b                 +cmp edx, 0x7b
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(123 /*0x7b*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a99027  7507                   -jne 0xa99030
    if (!cpu.flags.zf)
    {
        goto L_0x00a99030;
    }
    // 00a99029  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a9902e  eb45                   -jmp 0xa99075
    goto L_0x00a99075;
L_0x00a99030:
    // 00a99030  81face000000           +cmp edx, 0xce
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(206 /*0xce*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a99036  7511                   -jne 0xa99049
    if (!cpu.flags.zf)
    {
        goto L_0x00a99049;
    }
    // 00a99038  b809000000             -mov eax, 9
    cpu.eax = 9 /*0x9*/;
    // 00a9903d  e87ee3ffff             -call 0xa973c0
    cpu.esp -= 4;
    sub_a973c0(app, cpu);
    if (cpu.terminate) return;
    // 00a99042  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a99047  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a99048  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a99049:
    // 00a99049  81fab7000000           +cmp edx, 0xb7
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(183 /*0xb7*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a9904f  7511                   -jne 0xa99062
    if (!cpu.flags.zf)
    {
        goto L_0x00a99062;
    }
    // 00a99051  b807000000             -mov eax, 7
    cpu.eax = 7 /*0x7*/;
    // 00a99056  e865e3ffff             -call 0xa973c0
    cpu.esp -= 4;
    sub_a973c0(app, cpu);
    if (cpu.terminate) return;
    // 00a9905b  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a99060  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a99061  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a99062:
    // 00a99062  83fa13                 +cmp edx, 0x13
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(19 /*0x13*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a99065  7605                   -jbe 0xa9906c
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a9906c;
    }
    // 00a99067  ba13000000             -mov edx, 0x13
    cpu.edx = 19 /*0x13*/;
L_0x00a9906c:
    // 00a9906c  8b82c5e5a900           -mov eax, dword ptr [edx + 0xa9e5c5]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(11134405) /* 0xa9e5c5 */);
    // 00a99072  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
L_0x00a99075:
    // 00a99075  e846e3ffff             -call 0xa973c0
    cpu.esp -= 4;
    sub_a973c0(app, cpu);
    if (cpu.terminate) return;
    // 00a9907a  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a9907f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a99080  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_a99084(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a99084  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a99085  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a99086  2eff15e4cda900         -call dword ptr cs:[0xa9cde4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11128292) /* 0xa9cde4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a9908d  e88affffff             -call 0xa9901c
    cpu.esp -= 4;
    sub_a9901c(app, cpu);
    if (cpu.terminate) return;
    // 00a99092  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a99093  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a99094  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a990a0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a990a0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a990a1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a990a2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a990a3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a990a4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a990a5  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a990a7  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00a990a9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a990ab  7509                   -jne 0xa990b6
    if (!cpu.flags.zf)
    {
        goto L_0x00a990b6;
    }
    // 00a990ad  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a990af  e8ccbbffff             -call 0xa94c80
    cpu.esp -= 4;
    sub_a94c80(app, cpu);
    if (cpu.terminate) return;
    // 00a990b4  eb62                   -jmp 0xa99118
    goto L_0x00a99118;
L_0x00a990b6:
    // 00a990b6  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a990b8  750d                   -jne 0xa990c7
    if (!cpu.flags.zf)
    {
        goto L_0x00a990c7;
    }
    // 00a990ba  e8b1bcffff             -call 0xa94d70
    cpu.esp -= 4;
    sub_a94d70(app, cpu);
    if (cpu.terminate) return;
    // 00a990bf  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a990c1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a990c2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a990c3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a990c4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a990c5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a990c6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a990c7:
    // 00a990c7  e804250000             -call 0xa9b5d0
    cpu.esp -= 4;
    sub_a9b5d0(app, cpu);
    if (cpu.terminate) return;
    // 00a990cc  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a990ce  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a990d0  e80b250000             -call 0xa9b5e0
    cpu.esp -= 4;
    sub_a9b5e0(app, cpu);
    if (cpu.terminate) return;
    // 00a990d5  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00a990d7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a990d9  753b                   -jne 0xa99116
    if (!cpu.flags.zf)
    {
        goto L_0x00a99116;
    }
    // 00a990db  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a990dd  e89ebbffff             -call 0xa94c80
    cpu.esp -= 4;
    sub_a94c80(app, cpu);
    if (cpu.terminate) return;
    // 00a990e2  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00a990e4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a990e6  7425                   -je 0xa9910d
    if (cpu.flags.zf)
    {
        goto L_0x00a9910d;
    }
    // 00a990e8  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00a990ea  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a990ec  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 00a990ee  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a990ef  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a990f1  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a990f3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a990f4  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a990f6  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00a990f9  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
    while (cpu.ecx)
    {
        app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
        if (cpu.flags.df)
        {
            cpu.edi -= 4;
            cpu.esi -= 4;
        }
        else
        {
            cpu.edi += 4;
            cpu.esi += 4;
        }
        --cpu.ecx;
    }
    // 00a990fb  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00a990fd  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00a99100  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
    while (cpu.ecx)
    {
        app->getMemory<x86::reg8>(cpu.ees + cpu.edi) = app->getMemory<x86::reg8>(cpu.esi);
        if (cpu.flags.df)
        {
            cpu.edi -= 1;
            cpu.esi -= 1;
        }
        else
        {
            cpu.edi += 1;
            cpu.esi += 1;
        }
        --cpu.ecx;
        if (cpu.flags.zf)
            break;
    }
    // 00a99102  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a99103  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a99104  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a99106  e865bcffff             -call 0xa94d70
    cpu.esp -= 4;
    sub_a94d70(app, cpu);
    if (cpu.terminate) return;
    // 00a9910b  eb09                   -jmp 0xa99116
    goto L_0x00a99116;
L_0x00a9910d:
    // 00a9910d  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00a9910f  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a99111  e8ca240000             -call 0xa9b5e0
    cpu.esp -= 4;
    sub_a9b5e0(app, cpu);
    if (cpu.terminate) return;
L_0x00a99116:
    // 00a99116  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
L_0x00a99118:
    // 00a99118  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a99119  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9911a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9911b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9911c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9911d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void sub_a99120(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a99120  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a99121  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00a99124  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a99126  e855bbffff             -call 0xa94c80
    cpu.esp -= 4;
    sub_a94c80(app, cpu);
    if (cpu.terminate) return;
    // 00a9912b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a9912d  7407                   -je 0xa99136
    if (cpu.flags.zf)
    {
        goto L_0x00a99136;
    }
    // 00a9912f  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a99131  e83abaffff             -call 0xa94b70
    cpu.esp -= 4;
    sub_a94b70(app, cpu);
    if (cpu.terminate) return;
L_0x00a99136:
    // 00a99136  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a99137  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a99140(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a99140  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a99141  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a99142  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a99143  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a99145  e88ee9ffff             -call 0xa97ad8
    cpu.esp -= 4;
    sub_a97ad8(app, cpu);
    if (cpu.terminate) return;
    // 00a9914a  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a9914c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a9914e  7410                   -je 0xa99160
    if (cpu.flags.zf)
    {
        goto L_0x00a99160;
    }
    // 00a99150  8b1590e2a900           -mov edx, dword ptr [0xa9e290]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11133584) /* 0xa9e290 */);
    // 00a99156  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a99157  2eff1548cea900         -call dword ptr cs:[0xa9ce48]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11128392) /* 0xa9ce48 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a9915e  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x00a99160:
    // 00a99160  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a99162  750f                   -jne 0xa99173
    if (!cpu.flags.zf)
    {
        goto L_0x00a99173;
    }
    // 00a99164  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00a99169  b874f3a900             -mov eax, 0xa9f374
    cpu.eax = 11137908 /*0xa9f374*/;
    // 00a9916e  e829deffff             -call 0xa96f9c
    cpu.esp -= 4;
    sub_a96f9c(app, cpu);
    if (cpu.terminate) return;
L_0x00a99173:
    // 00a99173  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a99175  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a99176  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a99177  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a99178  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_a9917c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9917c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a9917d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a9917e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a9917f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a99180  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a99181  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a99182  ff15c0e2a900           -call dword ptr [0xa9e2c0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11133632) /* 0xa9e2c0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a99188  2eff15cccda900         -call dword ptr cs:[0xa9cdcc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11128268) /* 0xa9cdcc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a9918f  8b1d0023aa00           -mov ebx, dword ptr [0xaa2300]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(11150080) /* 0xaa2300 */);
    // 00a99195  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a99197  740b                   -je 0xa991a4
    if (cpu.flags.zf)
    {
        goto L_0x00a991a4;
    }
L_0x00a99199:
    // 00a99199  3b4304                 +cmp eax, dword ptr [ebx + 4]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a9919c  7406                   -je 0xa991a4
    if (cpu.flags.zf)
    {
        goto L_0x00a991a4;
    }
    // 00a9919e  8b1b                   -mov ebx, dword ptr [ebx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx);
    // 00a991a0  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a991a2  75f5                   -jne 0xa99199
    if (!cpu.flags.zf)
    {
        goto L_0x00a99199;
    }
L_0x00a991a4:
    // 00a991a4  837b0c00               +cmp dword ptr [ebx + 0xc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a991a8  7425                   -je 0xa991cf
    if (cpu.flags.zf)
    {
        goto L_0x00a991cf;
    }
    // 00a991aa  8b15dce5a900           -mov edx, dword ptr [0xa9e5dc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11134428) /* 0xa9e5dc */);
    // 00a991b0  8b4308                 -mov eax, dword ptr [ebx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 00a991b3  e8e8feffff             -call 0xa990a0
    cpu.esp -= 4;
    sub_a990a0(app, cpu);
    if (cpu.terminate) return;
    // 00a991b8  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00a991ba  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a991bc  755e                   -jne 0xa9921c
    if (!cpu.flags.zf)
    {
        goto L_0x00a9921c;
    }
    // 00a991be  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00a991c3  b89cf3a900             -mov eax, 0xa9f39c
    cpu.eax = 11137948 /*0xa9f39c*/;
    // 00a991c8  e8cfddffff             -call 0xa96f9c
    cpu.esp -= 4;
    sub_a96f9c(app, cpu);
    if (cpu.terminate) return;
    // 00a991cd  eb4d                   -jmp 0xa9921c
    goto L_0x00a9921c;
L_0x00a991cf:
    // 00a991cf  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a991d4  8b15dce5a900           -mov edx, dword ptr [0xa9e5dc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11134428) /* 0xa9e5dc */);
    // 00a991da  e841ffffff             -call 0xa99120
    cpu.esp -= 4;
    sub_a99120(app, cpu);
    if (cpu.terminate) return;
    // 00a991df  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00a991e1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a991e3  750f                   -jne 0xa991f4
    if (!cpu.flags.zf)
    {
        goto L_0x00a991f4;
    }
    // 00a991e5  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00a991ea  b8c4f3a900             -mov eax, 0xa9f3c4
    cpu.eax = 11137988 /*0xa9f3c4*/;
    // 00a991ef  e8a8ddffff             -call 0xa96f9c
    cpu.esp -= 4;
    sub_a96f9c(app, cpu);
    if (cpu.terminate) return;
L_0x00a991f4:
    // 00a991f4  8b7308                 -mov esi, dword ptr [ebx + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 00a991f7  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 00a991f9  8b8ef0000000           -mov ecx, dword ptr [esi + 0xf0]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(240) /* 0xf0 */);
    // 00a991ff  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a99200  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a99202  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a99204  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a99205  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a99207  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00a9920a  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
    while (cpu.ecx)
    {
        app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
        if (cpu.flags.df)
        {
            cpu.edi -= 4;
            cpu.esi -= 4;
        }
        else
        {
            cpu.edi += 4;
            cpu.esi += 4;
        }
        --cpu.ecx;
    }
    // 00a9920c  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00a9920e  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00a99211  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
    while (cpu.ecx)
    {
        app->getMemory<x86::reg8>(cpu.ees + cpu.edi) = app->getMemory<x86::reg8>(cpu.esi);
        if (cpu.flags.df)
        {
            cpu.edi -= 1;
            cpu.esi -= 1;
        }
        else
        {
            cpu.edi += 1;
            cpu.esi += 1;
        }
        --cpu.ecx;
        if (cpu.flags.zf)
            break;
    }
    // 00a99213  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a99214  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a99215  c7430c01000000         -mov dword ptr [ebx + 0xc], 1
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = 1 /*0x1*/;
L_0x00a9921c:
    // 00a9921c  896b08                 -mov dword ptr [ebx + 8], ebp
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.ebp;
    // 00a9921f  a1dce5a900             -mov eax, dword ptr [0xa9e5dc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11134428) /* 0xa9e5dc */);
    // 00a99224  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a99225  c6455201               -mov byte ptr [ebp + 0x52], 1
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(82) /* 0x52 */) = 1 /*0x1*/;
    // 00a99229  8b3590e2a900           -mov esi, dword ptr [0xa9e290]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(11133584) /* 0xa9e290 */);
    // 00a9922f  c6455300               -mov byte ptr [ebp + 0x53], 0
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(83) /* 0x53 */) = 0 /*0x0*/;
    // 00a99233  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a99234  8985f0000000           -mov dword ptr [ebp + 0xf0], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(240) /* 0xf0 */) = cpu.eax;
    // 00a9923a  2eff154ccea900         -call dword ptr cs:[0xa9ce4c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11128396) /* 0xa9ce4c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a99241  ff15c4e2a900           -call dword ptr [0xa9e2c4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11133636) /* 0xa9e2c4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a99247  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00a99249  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9924a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9924b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9924c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9924d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9924e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9924f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a99250(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a99250  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a99251  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a99252  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a99253  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a99255  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00a99257  ff15c0e2a900           -call dword ptr [0xa9e2c0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11133632) /* 0xa9e2c0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a9925d  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00a99262  ba10000000             -mov edx, 0x10
    cpu.edx = 16 /*0x10*/;
    // 00a99267  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a99269  e8b2feffff             -call 0xa99120
    cpu.esp -= 4;
    sub_a99120(app, cpu);
    if (cpu.terminate) return;
    // 00a9926e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a99270  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a99272  742f                   -je 0xa992a3
    if (cpu.flags.zf)
    {
        goto L_0x00a992a3;
    }
    // 00a99274  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a99276  e879250000             -call 0xa9b7f4
    cpu.esp -= 4;
    sub_a9b7f4(app, cpu);
    if (cpu.terminate) return;
    // 00a9927b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a9927d  7409                   -je 0xa99288
    if (cpu.flags.zf)
    {
        goto L_0x00a99288;
    }
    // 00a9927f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a99281  e8eabaffff             -call 0xa94d70
    cpu.esp -= 4;
    sub_a94d70(app, cpu);
    if (cpu.terminate) return;
    // 00a99286  eb1b                   -jmp 0xa992a3
    goto L_0x00a992a3;
L_0x00a99288:
    // 00a99288  895a08                 -mov dword ptr [edx + 8], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 00a9928b  897204                 -mov dword ptr [edx + 4], esi
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 00a9928e  8a4352                 -mov al, byte ptr [ebx + 0x52]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(82) /* 0x52 */);
    // 00a99291  89420c                 -mov dword ptr [edx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00a99294  a10023aa00             -mov eax, dword ptr [0xaa2300]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11150080) /* 0xaa2300 */);
    // 00a99299  89150023aa00           -mov dword ptr [0xaa2300], edx
    app->getMemory<x86::reg32>(x86::reg32(11150080) /* 0xaa2300 */) = cpu.edx;
    // 00a9929f  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 00a992a1  eb02                   -jmp 0xa992a5
    goto L_0x00a992a5;
L_0x00a992a3:
    // 00a992a3  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x00a992a5:
    // 00a992a5  ff15c4e2a900           -call dword ptr [0xa9e2c4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11133636) /* 0xa9e2c4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a992ab  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a992ad  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a992ae  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a992af  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a992b0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_a992b4(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a992b4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a992b5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a992b6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a992b7  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a992b9  ff15c0e2a900           -call dword ptr [0xa9e2c0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11133632) /* 0xa9e2c0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a992bf  8b150023aa00           -mov edx, dword ptr [0xaa2300]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11150080) /* 0xaa2300 */);
    // 00a992c5  b90023aa00             -mov ecx, 0xaa2300
    cpu.ecx = 11150080 /*0xaa2300*/;
    // 00a992ca  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a992cc  7428                   -je 0xa992f6
    if (cpu.flags.zf)
    {
        goto L_0x00a992f6;
    }
L_0x00a992ce:
    // 00a992ce  3b5a04                 +cmp ebx, dword ptr [edx + 4]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a992d1  751b                   -jne 0xa992ee
    if (!cpu.flags.zf)
    {
        goto L_0x00a992ee;
    }
    // 00a992d3  837a0c00               +cmp dword ptr [edx + 0xc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a992d7  7408                   -je 0xa992e1
    if (cpu.flags.zf)
    {
        goto L_0x00a992e1;
    }
    // 00a992d9  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00a992dc  e88fbaffff             -call 0xa94d70
    cpu.esp -= 4;
    sub_a94d70(app, cpu);
    if (cpu.terminate) return;
L_0x00a992e1:
    // 00a992e1  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 00a992e3  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 00a992e5  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a992e7  e884baffff             -call 0xa94d70
    cpu.esp -= 4;
    sub_a94d70(app, cpu);
    if (cpu.terminate) return;
    // 00a992ec  eb08                   -jmp 0xa992f6
    goto L_0x00a992f6;
L_0x00a992ee:
    // 00a992ee  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00a992f0  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 00a992f2  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a992f4  75d8                   -jne 0xa992ce
    if (!cpu.flags.zf)
    {
        goto L_0x00a992ce;
    }
L_0x00a992f6:
    // 00a992f6  ff15c4e2a900           -call dword ptr [0xa9e2c4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11133636) /* 0xa9e2c4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a992fc  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a992fd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a992fe  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a992ff  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a99300(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a99300  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a99301  ff15c0e2a900           -call dword ptr [0xa9e2c0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11133632) /* 0xa9e2c0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a99307  a10023aa00             -mov eax, dword ptr [0xaa2300]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11150080) /* 0xaa2300 */);
    // 00a9930c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a9930e  740d                   -je 0xa9931d
    if (cpu.flags.zf)
    {
        goto L_0x00a9931d;
    }
L_0x00a99310:
    // 00a99310  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00a99313  c6425301               -mov byte ptr [edx + 0x53], 1
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(83) /* 0x53 */) = 1 /*0x1*/;
    // 00a99317  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00a99319  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a9931b  75f3                   -jne 0xa99310
    if (!cpu.flags.zf)
    {
        goto L_0x00a99310;
    }
L_0x00a9931d:
    // 00a9931d  ff15c4e2a900           -call dword ptr [0xa9e2c4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11133636) /* 0xa9e2c4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a99323  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a99324  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_a99328(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a99328  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a99329  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a9932a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a9932b  8b150023aa00           -mov edx, dword ptr [0xaa2300]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11150080) /* 0xaa2300 */);
    // 00a99331  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a99333  741e                   -je 0xa99353
    if (cpu.flags.zf)
    {
        goto L_0x00a99353;
    }
L_0x00a99335:
    // 00a99335  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00a99338  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 00a9933a  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00a9933c  7408                   -je 0xa99346
    if (cpu.flags.zf)
    {
        goto L_0x00a99346;
    }
    // 00a9933e  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00a99341  e82abaffff             -call 0xa94d70
    cpu.esp -= 4;
    sub_a94d70(app, cpu);
    if (cpu.terminate) return;
L_0x00a99346:
    // 00a99346  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a99348  e823baffff             -call 0xa94d70
    cpu.esp -= 4;
    sub_a94d70(app, cpu);
    if (cpu.terminate) return;
    // 00a9934d  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00a9934f  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a99351  75e2                   -jne 0xa99335
    if (!cpu.flags.zf)
    {
        goto L_0x00a99335;
    }
L_0x00a99353:
    // 00a99353  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a99354  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a99355  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a99356  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a99360(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a99360  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a99361  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a99362  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a99364  ff15c0e2a900           -call dword ptr [0xa9e2c0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11133632) /* 0xa9e2c0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a9936a  8b15dce5a900           -mov edx, dword ptr [0xa9e5dc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11134428) /* 0xa9e5dc */);
    // 00a99370  8d041a                 -lea eax, [edx + ebx]
    cpu.eax = x86::reg32(cpu.edx + cpu.ebx * 1);
    // 00a99373  a3dce5a900             -mov dword ptr [0xa9e5dc], eax
    app->getMemory<x86::reg32>(x86::reg32(11134428) /* 0xa9e5dc */) = cpu.eax;
    // 00a99378  e883ffffff             -call 0xa99300
    cpu.esp -= 4;
    sub_a99300(app, cpu);
    if (cpu.terminate) return;
    // 00a9937d  ff15c4e2a900           -call dword ptr [0xa9e2c4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11133636) /* 0xa9e2c4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a99383  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a99385  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a99386  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a99387  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a99390(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a99390  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a99391  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a99392  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a99393  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a99395  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a99397  741b                   -je 0xa993b4
    if (cpu.flags.zf)
    {
        goto L_0x00a993b4;
    }
    // 00a99399  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a9939b  c7400c01000000         -mov dword ptr [eax + 0xc], 1
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = 1 /*0x1*/;
    // 00a993a2  e8c9eaffff             -call 0xa97e70
    cpu.esp -= 4;
    sub_a97e70(app, cpu);
    if (cpu.terminate) return;
    // 00a993a7  2eff15cccda900         -call dword ptr cs:[0xa9cdcc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11128268) /* 0xa9cdcc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a993ae  8983da000000           -mov dword ptr [ebx + 0xda], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(218) /* 0xda */) = cpu.eax;
L_0x00a993b4:
    // 00a993b4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a993b5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a993b6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a993b7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a993c0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a993c0  e963ffffff             -jmp 0xa99328
    return sub_a99328(app, cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a993d0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a993d0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a993d1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a993d2  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a993d4  66833800               +cmp word ptr [eax], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.eax);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00a993d8  740c                   -je 0xa993e6
    if (cpu.flags.zf)
    {
        goto L_0x00a993e6;
    }
L_0x00a993da:
    // 00a993da  668b4802               -mov cx, word ptr [eax + 2]
    cpu.cx = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 00a993de  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00a993e1  6685c9                 +test cx, cx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.cx & cpu.cx));
    // 00a993e4  75f4                   -jne 0xa993da
    if (!cpu.flags.zf)
    {
        goto L_0x00a993da;
    }
L_0x00a993e6:
    // 00a993e6  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00a993e8  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 00a993ea  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a993eb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a993ec  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void sub_a993f0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a993f0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a993f1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a993f2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a993f3  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00a993f5  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00a993f7  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a993f9  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a993fa  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a993fc  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a993fe  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a993ff  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a99401  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00a99404  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
    while (cpu.ecx)
    {
        app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
        if (cpu.flags.df)
        {
            cpu.edi -= 4;
            cpu.esi -= 4;
        }
        else
        {
            cpu.edi += 4;
            cpu.esi += 4;
        }
        --cpu.ecx;
    }
    // 00a99406  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00a99408  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00a9940b  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
    while (cpu.ecx)
    {
        app->getMemory<x86::reg8>(cpu.ees + cpu.edi) = app->getMemory<x86::reg8>(cpu.esi);
        if (cpu.flags.df)
        {
            cpu.edi -= 1;
            cpu.esi -= 1;
        }
        else
        {
            cpu.edi += 1;
            cpu.esi += 1;
        }
        --cpu.ecx;
        if (cpu.flags.zf)
            break;
    }
    // 00a9940d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9940e  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a9940f  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a99411  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a99412  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a99413  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a99414  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a99420(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a99420  66833801               +cmp word ptr [eax], 1
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.eax);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(1 /*0x1*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00a99424  751c                   -jne 0xa99442
    if (!cpu.flags.zf)
    {
        goto L_0x00a99442;
    }
    // 00a99426  83780400               +cmp dword ptr [eax + 4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a9942a  7416                   -je 0xa99442
    if (cpu.flags.zf)
    {
        goto L_0x00a99442;
    }
    // 00a9942c  668b400a               -mov ax, word ptr [eax + 0xa]
    cpu.ax = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(10) /* 0xa */);
    // 00a99430  663d1000               +cmp ax, 0x10
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(16 /*0x10*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00a99434  7206                   -jb 0xa9943c
    if (cpu.flags.cf)
    {
        goto L_0x00a9943c;
    }
    // 00a99436  663d1200               +cmp ax, 0x12
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(18 /*0x12*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00a9943a  7606                   -jbe 0xa99442
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a99442;
    }
L_0x00a9943c:
    // 00a9943c  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a99441  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a99442:
    // 00a99442  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a99444  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_a99448(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a99448  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a99449  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a9944a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a9944c  ff1598e2a900           -call dword ptr [0xa9e298]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11133592) /* 0xa9e298 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a99452  833de0e5a900ff         +cmp dword ptr [0xa9e5e0], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(11134432) /* 0xa9e5e0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a99459  7523                   -jne 0xa9947e
    if (!cpu.flags.zf)
    {
        goto L_0x00a9947e;
    }
    // 00a9945b  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a9945d  6880000000             -push 0x80
    app->getMemory<x86::reg32>(cpu.esp-4) = 128 /*0x80*/;
    cpu.esp -= 4;
    // 00a99462  6a03                   -push 3
    app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
    // 00a99464  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a99466  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00a99468  6800000080             -push 0x80000000
    app->getMemory<x86::reg32>(cpu.esp-4) = 2147483648 /*0x80000000*/;
    cpu.esp -= 4;
    // 00a9946d  68ecf3a900             -push 0xa9f3ec
    app->getMemory<x86::reg32>(cpu.esp-4) = 11138028 /*0xa9f3ec*/;
    cpu.esp -= 4;
    // 00a99472  2eff1590cda900         -call dword ptr cs:[0xa9cd90]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11128208) /* 0xa9cd90 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a99479  a3e0e5a900             -mov dword ptr [0xa9e5e0], eax
    app->getMemory<x86::reg32>(x86::reg32(11134432) /* 0xa9e5e0 */) = cpu.eax;
L_0x00a9947e:
    // 00a9947e  833de4e5a900ff         +cmp dword ptr [0xa9e5e4], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(11134436) /* 0xa9e5e4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a99485  7523                   -jne 0xa994aa
    if (!cpu.flags.zf)
    {
        goto L_0x00a994aa;
    }
    // 00a99487  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a99489  6880000000             -push 0x80
    app->getMemory<x86::reg32>(cpu.esp-4) = 128 /*0x80*/;
    cpu.esp -= 4;
    // 00a9948e  6a03                   -push 3
    app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
    // 00a99490  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a99492  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00a99494  6800000040             -push 0x40000000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1073741824 /*0x40000000*/;
    cpu.esp -= 4;
    // 00a99499  68f4f3a900             -push 0xa9f3f4
    app->getMemory<x86::reg32>(cpu.esp-4) = 11138036 /*0xa9f3f4*/;
    cpu.esp -= 4;
    // 00a9949e  2eff1590cda900         -call dword ptr cs:[0xa9cd90]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11128208) /* 0xa9cd90 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a994a5  a3e4e5a900             -mov dword ptr [0xa9e5e4], eax
    app->getMemory<x86::reg32>(x86::reg32(11134436) /* 0xa9e5e4 */) = cpu.eax;
L_0x00a994aa:
    // 00a994aa  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a994ac  ff159ce2a900           -call dword ptr [0xa9e29c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11133596) /* 0xa9e29c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a994b2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a994b3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a994b4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_a994b8(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a994b8  e88bffffff             -call 0xa99448
    cpu.esp -= 4;
    sub_a99448(app, cpu);
    if (cpu.terminate) return;
    // 00a994bd  a1e0e5a900             -mov eax, dword ptr [0xa9e5e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11134432) /* 0xa9e5e0 */);
    // 00a994c2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void sub_a994c4(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a994c4  e87fffffff             -call 0xa99448
    cpu.esp -= 4;
    sub_a99448(app, cpu);
    if (cpu.terminate) return;
    // 00a994c9  a1e4e5a900             -mov eax, dword ptr [0xa9e5e4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11134436) /* 0xa9e5e4 */);
    // 00a994ce  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void sub_a994d0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a994d0  dbe2                   -fnclex 
    /*nothing*/;
    // 00a994d2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a994e0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a994e0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a994e1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a994e2  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a994e4  83f807                 +cmp eax, 7
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(7 /*0x7*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a994e7  7405                   -je 0xa994ee
    if (cpu.flags.zf)
    {
        goto L_0x00a994ee;
    }
    // 00a994e9  83f804                 +cmp eax, 4
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a994ec  7518                   -jne 0xa99506
    if (!cpu.flags.zf)
    {
        goto L_0x00a99506;
    }
L_0x00a994ee:
    // 00a994ee  8d04dd00000000         -lea eax, [ebx*8]
    cpu.eax = x86::reg32(cpu.ebx * 8);
    // 00a994f5  8b98e8e5a900           -mov ebx, dword ptr [eax + 0xa9e5e8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(11134440) /* 0xa9e5e8 */);
    // 00a994fb  8990e8e5a900           -mov dword ptr [eax + 0xa9e5e8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(11134440) /* 0xa9e5e8 */) = cpu.edx;
    // 00a99501  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a99503  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a99504  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a99505  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a99506:
    // 00a99506  8d0cdd00000000         -lea ecx, [ebx*8]
    cpu.ecx = x86::reg32(cpu.ebx * 8);
    // 00a9950d  ff1594e2a900           -call dword ptr [0xa9e294]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11133588) /* 0xa9e294 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a99513  8b5c0158               -mov ebx, dword ptr [ecx + eax + 0x58]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(88) /* 0x58 */ + cpu.eax * 1);
    // 00a99517  ff1594e2a900           -call dword ptr [0xa9e294]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11133588) /* 0xa9e294 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a9951d  89540158               -mov dword ptr [ecx + eax + 0x58], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(88) /* 0x58 */ + cpu.eax * 1) = cpu.edx;
    // 00a99521  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a99523  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a99524  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a99525  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void sub_a99528(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a99528  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a99529  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a9952b  83f807                 +cmp eax, 7
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(7 /*0x7*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a9952e  7405                   -je 0xa99535
    if (cpu.flags.zf)
    {
        goto L_0x00a99535;
    }
    // 00a99530  83f804                 +cmp eax, 4
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a99533  7509                   -jne 0xa9953e
    if (!cpu.flags.zf)
    {
        goto L_0x00a9953e;
    }
L_0x00a99535:
    // 00a99535  8b04d5e8e5a900         -mov eax, dword ptr [edx*8 + 0xa9e5e8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11134440) /* 0xa9e5e8 */ + cpu.edx * 8);
    // 00a9953c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9953d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a9953e:
    // 00a9953e  ff1594e2a900           -call dword ptr [0xa9e294]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11133588) /* 0xa9e294 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a99544  8b44d058               -mov eax, dword ptr [eax + edx*8 + 0x58]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(88) /* 0x58 */ + cpu.edx * 8);
    // 00a99548  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a99549  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void sub_a9954c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9954c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a9954d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a9954f  83f807                 +cmp eax, 7
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(7 /*0x7*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a99552  7405                   -je 0xa99559
    if (cpu.flags.zf)
    {
        goto L_0x00a99559;
    }
    // 00a99554  83f804                 +cmp eax, 4
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a99557  7509                   -jne 0xa99562
    if (!cpu.flags.zf)
    {
        goto L_0x00a99562;
    }
L_0x00a99559:
    // 00a99559  8b04d5ece5a900         -mov eax, dword ptr [edx*8 + 0xa9e5ec]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11134444) /* 0xa9e5ec */ + cpu.edx * 8);
    // 00a99560  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a99561  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a99562:
    // 00a99562  ff1594e2a900           -call dword ptr [0xa9e294]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11133588) /* 0xa9e294 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a99568  8b44d05c               -mov eax, dword ptr [eax + edx*8 + 0x5c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(92) /* 0x5c */ + cpu.edx * 8);
    // 00a9956c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9956d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void sub_a99570(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a99570  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a99571  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a99573  e8d4ffffff             -call 0xa9954c
    cpu.esp -= 4;
    sub_a9954c(app, cpu);
    if (cpu.terminate) return;
    // 00a99578  39c2                   +cmp edx, eax
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a9957a  7509                   -jne 0xa99585
    if (!cpu.flags.zf)
    {
        goto L_0x00a99585;
    }
    // 00a9957c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a9957e  e8a5ffffff             -call 0xa99528
    cpu.esp -= 4;
    sub_a99528(app, cpu);
    if (cpu.terminate) return;
    // 00a99583  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a99584  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a99585:
    // 00a99585  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a99587  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a99588  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_a9958c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9958c  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a99590  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a99592  760a                   -jbe 0xa9959e
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a9959e;
    }
    // 00a99594  83f801                 +cmp eax, 1
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a99597  7424                   -je 0xa995bd
    if (cpu.flags.zf)
    {
        goto L_0x00a995bd;
    }
    // 00a99599  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a9959b  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00a9959e:
    // 00a9959e  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 00a995a3  e880ffffff             -call 0xa99528
    cpu.esp -= 4;
    sub_a99528(app, cpu);
    if (cpu.terminate) return;
    // 00a995a8  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a995aa  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a995ac  7503                   -jne 0xa995b1
    if (!cpu.flags.zf)
    {
        goto L_0x00a995b1;
    }
    // 00a995ae  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00a995b1:
    // 00a995b1  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 00a995b6  e8dd010000             -call 0xa99798
    cpu.esp -= 4;
    sub_a99798(app, cpu);
    if (cpu.terminate) return;
    // 00a995bb  eb1d                   -jmp 0xa995da
    goto L_0x00a995da;
L_0x00a995bd:
    // 00a995bd  b807000000             -mov eax, 7
    cpu.eax = 7 /*0x7*/;
    // 00a995c2  e861ffffff             -call 0xa99528
    cpu.esp -= 4;
    sub_a99528(app, cpu);
    if (cpu.terminate) return;
    // 00a995c7  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a995c9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a995cb  7503                   -jne 0xa995d0
    if (!cpu.flags.zf)
    {
        goto L_0x00a995d0;
    }
    // 00a995cd  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00a995d0:
    // 00a995d0  b807000000             -mov eax, 7
    cpu.eax = 7 /*0x7*/;
    // 00a995d5  e8be010000             -call 0xa99798
    cpu.esp -= 4;
    sub_a99798(app, cpu);
    if (cpu.terminate) return;
L_0x00a995da:
    // 00a995da  83fa02                 +cmp edx, 2
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a995dd  7405                   -je 0xa995e4
    if (cpu.flags.zf)
    {
        goto L_0x00a995e4;
    }
    // 00a995df  83fa03                 +cmp edx, 3
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a995e2  7505                   -jne 0xa995e9
    if (!cpu.flags.zf)
    {
        goto L_0x00a995e9;
    }
L_0x00a995e4:
    // 00a995e4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a995e6  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00a995e9:
    // 00a995e9  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a995ee  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_a995f4(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a995f4  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a995f5  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 00a995fa  e829ffffff             -call 0xa99528
    cpu.esp -= 4;
    sub_a99528(app, cpu);
    if (cpu.terminate) return;
    // 00a995ff  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a99601  b807000000             -mov eax, 7
    cpu.eax = 7 /*0x7*/;
    // 00a99606  e81dffffff             -call 0xa99528
    cpu.esp -= 4;
    sub_a99528(app, cpu);
    if (cpu.terminate) return;
    // 00a9960b  83fa02                 +cmp edx, 2
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a9960e  7405                   -je 0xa99615
    if (cpu.flags.zf)
    {
        goto L_0x00a99615;
    }
    // 00a99610  83fa03                 +cmp edx, 3
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a99613  750a                   -jne 0xa9961f
    if (!cpu.flags.zf)
    {
        goto L_0x00a9961f;
    }
L_0x00a99615:
    // 00a99615  83f802                 +cmp eax, 2
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a99618  740c                   -je 0xa99626
    if (cpu.flags.zf)
    {
        goto L_0x00a99626;
    }
    // 00a9961a  83f803                 +cmp eax, 3
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a9961d  7407                   -je 0xa99626
    if (cpu.flags.zf)
    {
        goto L_0x00a99626;
    }
L_0x00a9961f:
    // 00a9961f  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a99624  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a99625  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a99626:
    // 00a99626  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a99628  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a99629  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void sub_a9962c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9962c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a9962d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a9962e  803d50e6a90000         +cmp byte ptr [0xa9e650], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(11134544) /* 0xa9e650 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a99635  7519                   -jne 0xa99650
    if (!cpu.flags.zf)
    {
        goto L_0x00a99650;
    }
    // 00a99637  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00a99639  688c95a900             -push 0xa9958c
    app->getMemory<x86::reg32>(cpu.esp-4) = 11113868 /*0xa9958c*/;
    cpu.esp -= 4;
    // 00a9963e  2eff1520cea900         -call dword ptr cs:[0xa9ce20]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11128352) /* 0xa9ce20 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a99645  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a99647  7407                   -je 0xa99650
    if (cpu.flags.zf)
    {
        goto L_0x00a99650;
    }
    // 00a99649  c60550e6a90001         -mov byte ptr [0xa9e650], 1
    app->getMemory<x86::reg8>(x86::reg32(11134544) /* 0xa9e650 */) = 1 /*0x1*/;
L_0x00a99650:
    // 00a99650  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a99652  a050e6a900             -mov al, byte ptr [0xa9e650]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(11134544) /* 0xa9e650 */);
    // 00a99657  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a99658  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a99659  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void sub_a9965c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9965c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a9965d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a9965e  803d50e6a90000         +cmp byte ptr [0xa9e650], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(11134544) /* 0xa9e650 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a99665  741a                   -je 0xa99681
    if (cpu.flags.zf)
    {
        goto L_0x00a99681;
    }
    // 00a99667  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a99669  688c95a900             -push 0xa9958c
    app->getMemory<x86::reg32>(cpu.esp-4) = 11113868 /*0xa9958c*/;
    cpu.esp -= 4;
    // 00a9966e  2eff1520cea900         -call dword ptr cs:[0xa9ce20]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11128352) /* 0xa9ce20 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a99675  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a99677  7408                   -je 0xa99681
    if (cpu.flags.zf)
    {
        goto L_0x00a99681;
    }
    // 00a99679  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 00a9967b  881550e6a900           -mov byte ptr [0xa9e650], dl
    app->getMemory<x86::reg8>(x86::reg32(11134544) /* 0xa9e650 */) = cpu.dl;
L_0x00a99681:
    // 00a99681  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a99683  a050e6a900             -mov al, byte ptr [0xa9e650]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(11134544) /* 0xa9e650 */);
    // 00a99688  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a9968a  0f94c0                 -sete al
    cpu.al = cpu.flags.zf;
    // 00a9968d  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00a99692  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a99693  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a99694  c3                     -ret 
    cpu.esp += 4;
    return;
}

}
