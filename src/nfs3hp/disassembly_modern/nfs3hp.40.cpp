#include "nfs3hp.h"
#include <lib/thread.h>

namespace nfs3hp
{

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_4f0920(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f0920  d1fb                   +sar ebx, 1
    {
        x86::reg32 tmp = 1 /*0x1*/ % 32;
        x86::reg32& op = cpu.ebx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (x86::sreg32(op) >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = 0;
            cpu.set_szp((op = x86::reg32(x86::sreg32(op) >> tmp)));
        }
    }
    // 004f0922  e959290100             -jmp 0x503280
    return sub_503280(app, cpu);
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_4f0930(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f0930  01db                   +add ebx, ebx
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004f0932  e949290100             -jmp 0x503280
    return sub_503280(app, cpu);
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_4f0940(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f0940  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f0941  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004f0943  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 004f094a  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004f094c  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004f094e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004f0950  e82b290100             -call 0x503280
    cpu.esp -= 4;
    sub_503280(app, cpu);
    if (cpu.terminate) return;
    // 004f0955  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f0956  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_4f0960(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f0960  c1e302                 +shl ebx, 2
    {
        x86::reg8 tmp = 2 /*0x2*/ % 32;
        x86::reg32& op = cpu.ebx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 004f0963  e918290100             -jmp 0x503280
    return sub_503280(app, cpu);
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_4f0970(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f0970  d1fb                   +sar ebx, 1
    {
        x86::reg32 tmp = 1 /*0x1*/ % 32;
        x86::reg32& op = cpu.ebx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (x86::sreg32(op) >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = 0;
            cpu.set_szp((op = x86::reg32(x86::sreg32(op) >> tmp)));
        }
    }
    // 004f0972  e96d2a0100             -jmp 0x5033e4
    return sub_5033e4(app, cpu);
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_4f0980(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f0980  01db                   +add ebx, ebx
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004f0982  e95d2a0100             -jmp 0x5033e4
    return sub_5033e4(app, cpu);
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_4f0990(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f0990  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f0991  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004f0993  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 004f099a  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004f099c  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004f099e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004f09a0  e83f2a0100             -call 0x5033e4
    cpu.esp -= 4;
    sub_5033e4(app, cpu);
    if (cpu.terminate) return;
    // 004f09a5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f09a6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_4f09b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f09b0  c1e302                 +shl ebx, 2
    {
        x86::reg8 tmp = 2 /*0x2*/ % 32;
        x86::reg32& op = cpu.ebx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 004f09b3  e92c2a0100             -jmp 0x5033e4
    return sub_5033e4(app, cpu);
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_4f09c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f09c0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f09c1  833d7052560000         +cmp dword ptr [0x565270], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5657200) /* 0x565270 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f09c8  7d13                   -jge 0x4f09dd
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004f09dd;
    }
    // 004f09ca  833db443560000         +cmp dword ptr [0x5643b4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5653428) /* 0x5643b4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f09d1  7427                   -je 0x4f09fa
    if (cpu.flags.zf)
    {
        goto L_0x004f09fa;
    }
    // 004f09d3  c7057052560003000000   -mov dword ptr [0x565270], 3
    app->getMemory<x86::reg32>(x86::reg32(5657200) /* 0x565270 */) = 3 /*0x3*/;
L_0x004f09dd:
    // 004f09dd  8b0d70525600           -mov ecx, dword ptr [0x565270]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5657200) /* 0x565270 */);
    // 004f09e3  8b0c8d74525600         -mov ecx, dword ptr [ecx*4 + 0x565274]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5657204) /* 0x565274 */ + cpu.ecx * 4);
    // 004f09ea  e8c1a60100             -call 0x50b0b0
    cpu.esp -= 4;
    sub_50b0b0(app, cpu);
    if (cpu.terminate) return;
    // 004f09ef  833d7052560003         +cmp dword ptr [0x565270], 3
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5657200) /* 0x565270 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f09f6  740e                   -je 0x4f0a06
    if (cpu.flags.zf)
    {
        goto L_0x004f0a06;
    }
    // 004f09f8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f09f9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f09fa:
    // 004f09fa  c7057052560001000000   -mov dword ptr [0x565270], 1
    app->getMemory<x86::reg32>(x86::reg32(5657200) /* 0x565270 */) = 1 /*0x1*/;
    // 004f0a04  ebd7                   -jmp 0x4f09dd
    goto L_0x004f09dd;
L_0x004f0a06:
    // 004f0a06  0f77                   -emms 
    cpu.mmx.init();
    // 004f0a08  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f0a09  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_4f0a10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f0a10  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f0a11  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f0a12  8b580c                 -mov ebx, dword ptr [eax + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004f0a15  8b500c                 -mov edx, dword ptr [eax + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004f0a18  c1e304                 -shl ebx, 4
    cpu.ebx <<= 4 /*0x4*/ % 32;
    // 004f0a1b  c1e214                 -shl edx, 0x14
    cpu.edx <<= 20 /*0x14*/ % 32;
    // 004f0a1e  c1fb14                 -sar ebx, 0x14
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (20 /*0x14*/ % 32));
    // 004f0a21  c1fa14                 -sar edx, 0x14
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (20 /*0x14*/ % 32));
    // 004f0a24  e897ffffff             -call 0x4f09c0
    cpu.esp -= 4;
    sub_4f09c0(app, cpu);
    if (cpu.terminate) return;
    // 004f0a29  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f0a2a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f0a2b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_4f0a30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f0a30  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f0a31  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004f0a34  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 004f0a37  29cb                   -sub ebx, ecx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004f0a39  8b4806                 -mov ecx, dword ptr [eax + 6]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6) /* 0x6 */);
    // 004f0a3c  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 004f0a3f  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004f0a41  e87affffff             -call 0x4f09c0
    cpu.esp -= 4;
    sub_4f09c0(app, cpu);
    if (cpu.terminate) return;
    // 004f0a46  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f0a47  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_4f0a50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f0a50  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f0a51  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f0a52  8b580c                 -mov ebx, dword ptr [eax + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004f0a55  8b500c                 -mov edx, dword ptr [eax + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004f0a58  c1e304                 -shl ebx, 4
    cpu.ebx <<= 4 /*0x4*/ % 32;
    // 004f0a5b  c1e214                 -shl edx, 0x14
    cpu.edx <<= 20 /*0x14*/ % 32;
    // 004f0a5e  c1fb14                 -sar ebx, 0x14
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (20 /*0x14*/ % 32));
    // 004f0a61  c1fa14                 -sar edx, 0x14
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (20 /*0x14*/ % 32));
    // 004f0a64  e857ffffff             -call 0x4f09c0
    cpu.esp -= 4;
    sub_4f09c0(app, cpu);
    if (cpu.terminate) return;
    // 004f0a69  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f0a6a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f0a6b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_4f0a70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f0a70  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f0a71  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004f0a74  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 004f0a77  29cb                   -sub ebx, ecx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004f0a79  8b4806                 -mov ecx, dword ptr [eax + 6]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6) /* 0x6 */);
    // 004f0a7c  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 004f0a7f  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004f0a81  e83affffff             -call 0x4f09c0
    cpu.esp -= 4;
    sub_4f09c0(app, cpu);
    if (cpu.terminate) return;
    // 004f0a86  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f0a87  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4f0a90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f0a90  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f0a91  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f0a92  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004f0a94  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004f0a96  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004f0a98  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004f0a9a  bb20000000             -mov ebx, 0x20
    cpu.ebx = 32 /*0x20*/;
    // 004f0a9f  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004f0aa1  e8eae6ffff             -call 0x4ef190
    cpu.esp -= 4;
    sub_4ef190(app, cpu);
    if (cpu.terminate) return;
    // 004f0aa6  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004f0aa8  8b4028                 -mov eax, dword ptr [eax + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */);
    // 004f0aab  8b5108                 -mov edx, dword ptr [ecx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004f0aae  0fafd0                 -imul edx, eax
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 004f0ab1  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 004f0ab4  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004f0ab8  83c010                 -add eax, 0x10
    (cpu.eax) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004f0abb  e861fcfeff             -call 0x4e0721
    cpu.esp -= 4;
    sub_4e0721(app, cpu);
    if (cpu.terminate) return;
    // 004f0ac0  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004f0ac2  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004f0ac4  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 004f0ac7  e864d00100             -call 0x50db30
    cpu.esp -= 4;
    sub_50db30(app, cpu);
    if (cpu.terminate) return;
    // 004f0acc  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004f0ace  e82df4ffff             -call 0x4eff00
    cpu.esp -= 4;
    sub_4eff00(app, cpu);
    if (cpu.terminate) return;
    // 004f0ad3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f0ad4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f0ad5  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4f0ae0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f0ae0  83f841                 +cmp eax, 0x41
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65 /*0x41*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f0ae3  7c08                   -jl 0x4f0aed
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004f0aed;
    }
    // 004f0ae5  83f85a                 +cmp eax, 0x5a
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(90 /*0x5a*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f0ae8  7f03                   -jg 0x4f0aed
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004f0aed;
    }
    // 004f0aea  83c020                 -add eax, 0x20
    (cpu.eax) += x86::reg32(x86::sreg32(32 /*0x20*/));
L_0x004f0aed:
    // 004f0aed  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_4f0af0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f0af0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f0af1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f0af2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f0af3  8b0ddc0b9f00           -mov ecx, dword ptr [0x9f0bdc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10423260) /* 0x9f0bdc */);
    // 004f0af9  39c8                   +cmp eax, ecx
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f0afb  7e4c                   -jle 0x4f0b49
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004f0b49;
    }
L_0x004f0afd:
    // 004f0afd  8b1dd80b9f00           -mov ebx, dword ptr [0x9f0bd8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10423256) /* 0x9f0bd8 */);
    // 004f0b03  890ddc0b9f00           -mov dword ptr [0x9f0bdc], ecx
    app->getMemory<x86::reg32>(x86::reg32(10423260) /* 0x9f0bdc */) = cpu.ecx;
    // 004f0b09  39da                   +cmp edx, ebx
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
    // 004f0b0b  7e40                   -jle 0x4f0b4d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004f0b4d;
    }
    // 004f0b0d  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
L_0x004f0b0f:
    // 004f0b0f  8b742414               -mov esi, dword ptr [esp + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004f0b13  8b3dd00b9f00           -mov edi, dword ptr [0x9f0bd0]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(10423248) /* 0x9f0bd0 */);
    // 004f0b19  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 004f0b1b  890dd80b9f00           -mov dword ptr [0x9f0bd8], ecx
    app->getMemory<x86::reg32>(x86::reg32(10423256) /* 0x9f0bd8 */) = cpu.ecx;
    // 004f0b21  39f8                   +cmp eax, edi
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f0b23  7d02                   -jge 0x4f0b27
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004f0b27;
    }
    // 004f0b25  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
L_0x004f0b27:
    // 004f0b27  8b6c2418               -mov ebp, dword ptr [esp + 0x18]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004f0b2b  a3d00b9f00             -mov dword ptr [0x9f0bd0], eax
    app->getMemory<x86::reg32>(x86::reg32(10423248) /* 0x9f0bd0 */) = cpu.eax;
    // 004f0b30  a1d40b9f00             -mov eax, dword ptr [0x9f0bd4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10423252) /* 0x9f0bd4 */);
    // 004f0b35  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 004f0b37  39c2                   +cmp edx, eax
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
    // 004f0b39  7d02                   -jge 0x4f0b3d
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004f0b3d;
    }
    // 004f0b3b  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
L_0x004f0b3d:
    // 004f0b3d  8915d40b9f00           -mov dword ptr [0x9f0bd4], edx
    app->getMemory<x86::reg32>(x86::reg32(10423252) /* 0x9f0bd4 */) = cpu.edx;
    // 004f0b43  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f0b44  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f0b45  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f0b46  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x004f0b49:
    // 004f0b49  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004f0b4b  ebb0                   -jmp 0x4f0afd
    goto L_0x004f0afd;
L_0x004f0b4d:
    // 004f0b4d  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004f0b4f  ebbe                   -jmp 0x4f0b0f
    goto L_0x004f0b0f;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_4f0b60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f0b60  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f0b61  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f0b62  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f0b63  81ec10010000           -sub esp, 0x110
    (cpu.esp) -= x86::reg32(x86::sreg32(272 /*0x110*/));
    // 004f0b69  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004f0b6b  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004f0b6d  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 004f0b6f  a1f8715600             -mov eax, dword ptr [0x5671f8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5665272) /* 0x5671f8 */);
    // 004f0b74  8984240c010000         -mov dword ptr [esp + 0x10c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(268) /* 0x10c */) = cpu.eax;
    // 004f0b7b  a1fc715600             -mov eax, dword ptr [0x5671fc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5665276) /* 0x5671fc */);
    // 004f0b80  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004f0b82  89842404010000         -mov dword ptr [esp + 0x104], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */) = cpu.eax;
    // 004f0b89  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f0b8b  e8c0fcffff             -call 0x4f0850
    cpu.esp -= 4;
    sub_4f0850(app, cpu);
    if (cpu.terminate) return;
    // 004f0b90  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004f0b92  8915dc0b9f00           -mov dword ptr [0x9f0bdc], edx
    app->getMemory<x86::reg32>(x86::reg32(10423260) /* 0x9f0bdc */) = cpu.edx;
    // 004f0b98  8915d80b9f00           -mov dword ptr [0x9f0bd8], edx
    app->getMemory<x86::reg32>(x86::reg32(10423256) /* 0x9f0bd8 */) = cpu.edx;
    // 004f0b9e  8915d00b9f00           -mov dword ptr [0x9f0bd0], edx
    app->getMemory<x86::reg32>(x86::reg32(10423248) /* 0x9f0bd0 */) = cpu.edx;
    // 004f0ba4  8915d40b9f00           -mov dword ptr [0x9f0bd4], edx
    app->getMemory<x86::reg32>(x86::reg32(10423252) /* 0x9f0bd4 */) = cpu.edx;
    // 004f0baa  81fe00010000           +cmp esi, 0x100
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(256 /*0x100*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f0bb0  7e05                   -jle 0x4f0bb7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004f0bb7;
    }
    // 004f0bb2  be00010000             -mov esi, 0x100
    cpu.esi = 256 /*0x100*/;
L_0x004f0bb7:
    // 004f0bb7  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004f0bb9  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 004f0bbb  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004f0bbd  882434                 -mov byte ptr [esp + esi], ah
    app->getMemory<x86::reg8>(cpu.esp + cpu.esi * 1) = cpu.ah;
    // 004f0bc0  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004f0bc2  bef00a4f00             -mov esi, 0x4f0af0
    cpu.esi = 5180144 /*0x4f0af0*/;
    // 004f0bc7  e86402ffff             -call 0x4e0e30
    cpu.esp -= 4;
    sub_4e0e30(app, cpu);
    if (cpu.terminate) return;
    // 004f0bcc  8a1424                 -mov dl, byte ptr [esp]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp);
    // 004f0bcf  a188725600             -mov eax, dword ptr [0x567288]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5665416) /* 0x567288 */);
    // 004f0bd4  8b3d8c725600           -mov edi, dword ptr [0x56728c]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5665420) /* 0x56728c */);
    // 004f0bda  8b1d90725600           -mov ebx, dword ptr [0x567290]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5665424) /* 0x567290 */);
    // 004f0be0  89842408010000         -mov dword ptr [esp + 0x108], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(264) /* 0x108 */) = cpu.eax;
    // 004f0be7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f0be9  893588725600           -mov dword ptr [0x567288], esi
    app->getMemory<x86::reg32>(x86::reg32(5665416) /* 0x567288 */) = cpu.esi;
    // 004f0bef  a38c725600             -mov dword ptr [0x56728c], eax
    app->getMemory<x86::reg32>(x86::reg32(5665420) /* 0x56728c */) = cpu.eax;
    // 004f0bf4  a390725600             -mov dword ptr [0x567290], eax
    app->getMemory<x86::reg32>(x86::reg32(5665424) /* 0x567290 */) = cpu.eax;
    // 004f0bf9  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 004f0bfb  7407                   -je 0x4f0c04
    if (cpu.flags.zf)
    {
        goto L_0x004f0c04;
    }
    // 004f0bfd  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004f0bff  e84cefffff             -call 0x4efb50
    cpu.esp -= 4;
    sub_4efb50(app, cpu);
    if (cpu.terminate) return;
L_0x004f0c04:
    // 004f0c04  a1dc0b9f00             -mov eax, dword ptr [0x9f0bdc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10423260) /* 0x9f0bdc */);
    // 004f0c09  894500                 -mov dword ptr [ebp], eax
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.eax;
    // 004f0c0c  a1d80b9f00             -mov eax, dword ptr [0x9f0bd8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10423256) /* 0x9f0bd8 */);
    // 004f0c11  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 004f0c13  a1d00b9f00             -mov eax, dword ptr [0x9f0bd0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10423248) /* 0x9f0bd0 */);
    // 004f0c18  8b0ddc0b9f00           -mov ecx, dword ptr [0x9f0bdc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10423260) /* 0x9f0bdc */);
    // 004f0c1e  8b35f8715600           -mov esi, dword ptr [0x5671f8]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5665272) /* 0x5671f8 */);
    // 004f0c24  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004f0c26  39f0                   +cmp eax, esi
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f0c28  7d02                   -jge 0x4f0c2c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004f0c2c;
    }
    // 004f0c2a  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x004f0c2c:
    // 004f0c2c  8b8c2420010000         -mov ecx, dword ptr [esp + 0x120]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(288) /* 0x120 */);
    // 004f0c33  8b35d40b9f00           -mov esi, dword ptr [0x9f0bd4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(10423252) /* 0x9f0bd4 */);
    // 004f0c39  8b2dd80b9f00           -mov ebp, dword ptr [0x9f0bd8]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(10423256) /* 0x9f0bd8 */);
    // 004f0c3f  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 004f0c41  8b842424010000         -mov eax, dword ptr [esp + 0x124]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(292) /* 0x124 */);
    // 004f0c48  29ee                   -sub esi, ebp
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 004f0c4a  8b942404010000         -mov edx, dword ptr [esp + 0x104]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 004f0c51  8930                   -mov dword ptr [eax], esi
    app->getMemory<x86::reg32>(cpu.eax) = cpu.esi;
    // 004f0c53  8b84240c010000         -mov eax, dword ptr [esp + 0x10c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(268) /* 0x10c */);
    // 004f0c5a  e8f1fbffff             -call 0x4f0850
    cpu.esp -= 4;
    sub_4f0850(app, cpu);
    if (cpu.terminate) return;
    // 004f0c5f  8b842408010000         -mov eax, dword ptr [esp + 0x108]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(264) /* 0x108 */);
    // 004f0c66  893d8c725600           -mov dword ptr [0x56728c], edi
    app->getMemory<x86::reg32>(x86::reg32(5665420) /* 0x56728c */) = cpu.edi;
    // 004f0c6c  891d90725600           -mov dword ptr [0x567290], ebx
    app->getMemory<x86::reg32>(x86::reg32(5665424) /* 0x567290 */) = cpu.ebx;
    // 004f0c72  a388725600             -mov dword ptr [0x567288], eax
    app->getMemory<x86::reg32>(x86::reg32(5665416) /* 0x567288 */) = cpu.eax;
    // 004f0c77  81c410010000           -add esp, 0x110
    (cpu.esp) += x86::reg32(x86::sreg32(272 /*0x110*/));
    // 004f0c7d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f0c7e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f0c7f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f0c80  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4f0c90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f0c90  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f0c91  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004f0c95  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f0c96  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f0c97  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004f0c99  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004f0c9b  ba00010000             -mov edx, 0x100
    cpu.edx = 256 /*0x100*/;
    // 004f0ca0  e8bbfeffff             -call 0x4f0b60
    cpu.esp -= 4;
    sub_4f0b60(app, cpu);
    if (cpu.terminate) return;
    // 004f0ca5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f0ca6  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4f0cb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f0cb0  3b5004                 +cmp edx, dword ptr [eax + 4]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f0cb3  750b                   -jne 0x4f0cc0
    if (!cpu.flags.zf)
    {
        return sub_4f0cc0(app, cpu);
    }
    // 004f0cb5  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004f0cba  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_4f0cc0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f0cc0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f0cc2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4f0cd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f0cd0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f0cd1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f0cd2  8b15e00b9f00           -mov edx, dword ptr [0x9f0be0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10423264) /* 0x9f0be0 */);
    // 004f0cd8  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004f0cda  7434                   -je 0x4f0d10
    if (cpu.flags.zf)
    {
        goto L_0x004f0d10;
    }
    // 004f0cdc  8b4a18                 -mov ecx, dword ptr [edx + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 004f0cdf  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004f0ce1  7407                   -je 0x4f0cea
    if (cpu.flags.zf)
    {
        goto L_0x004f0cea;
    }
    // 004f0ce3  c7412000000000         -mov dword ptr [ecx + 0x20], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = 0 /*0x0*/;
L_0x004f0cea:
    // 004f0cea  8b15e00b9f00           -mov edx, dword ptr [0x9f0be0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10423264) /* 0x9f0be0 */);
    // 004f0cf0  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 004f0cf2  e839eefeff             -call 0x4dfb30
    cpu.esp -= 4;
    sub_4dfb30(app, cpu);
    if (cpu.terminate) return;
    // 004f0cf7  e884ea0000             -call 0x4ff780
    cpu.esp -= 4;
    sub_4ff780(app, cpu);
    if (cpu.terminate) return;
    // 004f0cfc  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x004f0cfe:
    // 004f0cfe  a1e00b9f00             -mov eax, dword ptr [0x9f0be0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10423264) /* 0x9f0be0 */);
    // 004f0d03  3b10                   +cmp edx, dword ptr [eax]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f0d05  7409                   -je 0x4f0d10
    if (cpu.flags.zf)
    {
        goto L_0x004f0d10;
    }
    // 004f0d07  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004f0d09  7405                   -je 0x4f0d10
    if (cpu.flags.zf)
    {
        goto L_0x004f0d10;
    }
    // 004f0d0b  3b4818                 +cmp ecx, dword ptr [eax + 0x18]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f0d0e  7403                   -je 0x4f0d13
    if (cpu.flags.zf)
    {
        goto L_0x004f0d13;
    }
L_0x004f0d10:
    // 004f0d10  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f0d11  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f0d12  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f0d13:
    // 004f0d13  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004f0d15  e8c6ebfeff             -call 0x4df8e0
    cpu.esp -= 4;
    sub_4df8e0(app, cpu);
    if (cpu.terminate) return;
    // 004f0d1a  ebe2                   -jmp 0x4f0cfe
    goto L_0x004f0cfe;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_4f0d20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f0d20  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f0d21  a1e00b9f00             -mov eax, dword ptr [0x9f0be0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10423264) /* 0x9f0be0 */);
    // 004f0d26  83c054                 -add eax, 0x54
    (cpu.eax) += x86::reg32(x86::sreg32(84 /*0x54*/));
    // 004f0d29  e8a2d40100             -call 0x50e1d0
    cpu.esp -= 4;
    sub_50e1d0(app, cpu);
    if (cpu.terminate) return;
    // 004f0d2e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f0d30  770f                   -ja 0x4f0d41
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004f0d41;
    }
L_0x004f0d32:
    // 004f0d32  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f0d34  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f0d35  8d8000000000           -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 004f0d3b  8d5200                 -lea edx, [edx]
    cpu.edx = x86::reg32(cpu.edx);
    // 004f0d3e  8bdb                   -mov ebx, ebx
    cpu.ebx = cpu.ebx;
    // 004f0d40  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f0d41:
    // 004f0d41  a1e00b9f00             -mov eax, dword ptr [0x9f0be0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10423264) /* 0x9f0be0 */);
    // 004f0d46  83c054                 -add eax, 0x54
    (cpu.eax) += x86::reg32(x86::sreg32(84 /*0x54*/));
    // 004f0d49  e8a2d20100             -call 0x50dff0
    cpu.esp -= 4;
    sub_50dff0(app, cpu);
    if (cpu.terminate) return;
    // 004f0d4e  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004f0d50  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f0d52  74de                   -je 0x4f0d32
    if (cpu.flags.zf)
    {
        goto L_0x004f0d32;
    }
L_0x004f0d54:
    // 004f0d54  8b5118                 -mov edx, dword ptr [ecx + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 004f0d57  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004f0d59  740a                   -je 0x4f0d65
    if (cpu.flags.zf)
    {
        goto L_0x004f0d65;
    }
    // 004f0d5b  a1e00b9f00             -mov eax, dword ptr [0x9f0be0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10423264) /* 0x9f0be0 */);
    // 004f0d60  3b5014                 +cmp edx, dword ptr [eax + 0x14]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f0d63  752c                   -jne 0x4f0d91
    if (!cpu.flags.zf)
    {
        goto L_0x004f0d91;
    }
L_0x004f0d65:
    // 004f0d65  a1e00b9f00             -mov eax, dword ptr [0x9f0be0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10423264) /* 0x9f0be0 */);
    // 004f0d6a  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004f0d6c  83c01c                 -add eax, 0x1c
    (cpu.eax) += x86::reg32(x86::sreg32(28 /*0x1c*/));
L_0x004f0d6f:
    // 004f0d6f  e8dcd00100             -call 0x50de50
    cpu.esp -= 4;
    sub_50de50(app, cpu);
    if (cpu.terminate) return;
    // 004f0d74  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 004f0d77  ff5124                 -call dword ptr [ecx + 0x24]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(36) /* 0x24 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f0d7a  a1e00b9f00             -mov eax, dword ptr [0x9f0be0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10423264) /* 0x9f0be0 */);
    // 004f0d7f  83c054                 -add eax, 0x54
    (cpu.eax) += x86::reg32(x86::sreg32(84 /*0x54*/));
    // 004f0d82  e869d20100             -call 0x50dff0
    cpu.esp -= 4;
    sub_50dff0(app, cpu);
    if (cpu.terminate) return;
    // 004f0d87  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004f0d89  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f0d8b  75c7                   -jne 0x4f0d54
    if (!cpu.flags.zf)
    {
        goto L_0x004f0d54;
    }
    // 004f0d8d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f0d8f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f0d90  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f0d91:
    // 004f0d91  83c038                 +add eax, 0x38
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(56 /*0x38*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004f0d94  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004f0d96  ebd7                   -jmp 0x4f0d6f
    goto L_0x004f0d6f;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_4f0da0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f0da0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f0da1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f0da2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f0da3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f0da4  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004f0da6  8d3400                 -lea esi, [eax + eax]
    cpu.esi = x86::reg32(cpu.eax + cpu.eax * 1);
    // 004f0da9  e8c2820000             -call 0x4f9070
    cpu.esp -= 4;
    sub_4f9070(app, cpu);
    if (cpu.terminate) return;
    // 004f0dae  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f0db0  0f8504010000           -jne 0x4f0eba
    if (!cpu.flags.zf)
    {
        goto L_0x004f0eba;
    }
L_0x004f0db6:
    // 004f0db6  833de00b9f0000         +cmp dword ptr [0x9f0be0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10423264) /* 0x9f0be0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f0dbd  0f852a010000           -jne 0x4f0eed
    if (!cpu.flags.zf)
    {
        goto L_0x004f0eed;
    }
L_0x004f0dc3:
    // 004f0dc3  c7059021550080c65400   -mov dword ptr [0x552190], 0x54c680
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = 5555840 /*0x54c680*/;
    // 004f0dcd  8d04b500000000         -lea eax, [esi*4]
    cpu.eax = x86::reg32(cpu.esi * 4);
    // 004f0dd4  ba8cc65400             -mov edx, 0x54c68c
    cpu.edx = 5555852 /*0x54c68c*/;
    // 004f0dd9  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 004f0ddb  b9c8000000             -mov ecx, 0xc8
    cpu.ecx = 200 /*0xc8*/;
    // 004f0de0  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004f0de3  890d98215500           -mov dword ptr [0x552198], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ecx;
    // 004f0de9  8d888c000000           -lea ecx, [eax + 0x8c]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(140) /* 0x8c */);
    // 004f0def  891594215500           -mov dword ptr [0x552194], edx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.edx;
    // 004f0df5  b8c8c65400             -mov eax, 0x54c6c8
    cpu.eax = 5555912 /*0x54c6c8*/;
    // 004f0dfa  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004f0dfc  e81f08ffff             -call 0x4e1620
    cpu.esp -= 4;
    sub_4e1620(app, cpu);
    if (cpu.terminate) return;
    // 004f0e01  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004f0e03  a3e00b9f00             -mov dword ptr [0x9f0be0], eax
    app->getMemory<x86::reg32>(x86::reg32(10423264) /* 0x9f0be0 */) = cpu.eax;
    // 004f0e08  e8fff8feff             -call 0x4e070c
    cpu.esp -= 4;
    sub_4e070c(app, cpu);
    if (cpu.terminate) return;
    // 004f0e0d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004f0e0f  a1e00b9f00             -mov eax, dword ptr [0x9f0be0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10423264) /* 0x9f0be0 */);
    // 004f0e14  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004f0e16  894014                 -mov dword ptr [eax + 0x14], eax
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 004f0e19  83c01c                 -add eax, 0x1c
    (cpu.eax) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004f0e1c  e8afce0100             -call 0x50dcd0
    cpu.esp -= 4;
    sub_50dcd0(app, cpu);
    if (cpu.terminate) return;
    // 004f0e21  a1e00b9f00             -mov eax, dword ptr [0x9f0be0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10423264) /* 0x9f0be0 */);
    // 004f0e26  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004f0e28  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004f0e2a  83c038                 -add eax, 0x38
    (cpu.eax) += x86::reg32(x86::sreg32(56 /*0x38*/));
    // 004f0e2d  e89ece0100             -call 0x50dcd0
    cpu.esp -= 4;
    sub_50dcd0(app, cpu);
    if (cpu.terminate) return;
    // 004f0e32  a1e00b9f00             -mov eax, dword ptr [0x9f0be0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10423264) /* 0x9f0be0 */);
    // 004f0e37  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004f0e39  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004f0e3b  83c054                 -add eax, 0x54
    (cpu.eax) += x86::reg32(x86::sreg32(84 /*0x54*/));
    // 004f0e3e  e88dce0100             -call 0x50dcd0
    cpu.esp -= 4;
    sub_50dcd0(app, cpu);
    if (cpu.terminate) return;
    // 004f0e43  a1e00b9f00             -mov eax, dword ptr [0x9f0be0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10423264) /* 0x9f0be0 */);
    // 004f0e48  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004f0e4a  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004f0e4c  83c070                 -add eax, 0x70
    (cpu.eax) += x86::reg32(x86::sreg32(112 /*0x70*/));
    // 004f0e4f  e87cce0100             -call 0x50dcd0
    cpu.esp -= 4;
    sub_50dcd0(app, cpu);
    if (cpu.terminate) return;
    // 004f0e54  8b0de00b9f00           -mov ecx, dword ptr [0x9f0be0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10423264) /* 0x9f0be0 */);
    // 004f0e5a  81c18c000000           -add ecx, 0x8c
    (cpu.ecx) += x86::reg32(x86::sreg32(140 /*0x8c*/));
L_0x004f0e60:
    // 004f0e60  a1e00b9f00             -mov eax, dword ptr [0x9f0be0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10423264) /* 0x9f0be0 */);
    // 004f0e65  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004f0e67  83c01c                 -add eax, 0x1c
    (cpu.eax) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004f0e6a  e8e1cf0100             -call 0x50de50
    cpu.esp -= 4;
    sub_50de50(app, cpu);
    if (cpu.terminate) return;
    // 004f0e6f  83c128                 +add ecx, 0x28
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(40 /*0x28*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004f0e72  4e                     +dec esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004f0e73  75eb                   -jne 0x4f0e60
    if (!cpu.flags.zf)
    {
        goto L_0x004f0e60;
    }
    // 004f0e75  bb03000000             -mov ebx, 3
    cpu.ebx = 3 /*0x3*/;
    // 004f0e7a  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 004f0e7f  b8200d4f00             -mov eax, 0x4f0d20
    cpu.eax = 5180704 /*0x4f0d20*/;
    // 004f0e84  b9ffffffff             -mov ecx, 0xffffffff
    cpu.ecx = 4294967295 /*0xffffffff*/;
    // 004f0e89  e89266ffff             -call 0x4e7520
    cpu.esp -= 4;
    sub_4e7520(app, cpu);
    if (cpu.terminate) return;
    // 004f0e8e  68e40b9f00             -push 0x9f0be4
    app->getMemory<x86::reg32>(cpu.esp-4) = 10423268 /*0x9f0be4*/;
    cpu.esp -= 4;
    // 004f0e93  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004f0e98  b820184f00             -mov eax, 0x4f1820
    cpu.eax = 5183520 /*0x4f1820*/;
    // 004f0e9d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004f0e9f  e8fce8feff             -call 0x4df7a0
    cpu.esp -= 4;
    sub_4df7a0(app, cpu);
    if (cpu.terminate) return;
    // 004f0ea4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f0ea6  744f                   -je 0x4f0ef7
    if (cpu.flags.zf)
    {
        goto L_0x004f0ef7;
    }
L_0x004f0ea8:
    // 004f0ea8  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004f0eaa  a1e00b9f00             -mov eax, dword ptr [0x9f0be0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10423264) /* 0x9f0be0 */);
    // 004f0eaf  8b28                   -mov ebp, dword ptr [eax]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.eax);
    // 004f0eb1  39e9                   +cmp ecx, ebp
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f0eb3  7472                   -je 0x4f0f27
    if (cpu.flags.zf)
    {
        goto L_0x004f0f27;
    }
    // 004f0eb5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f0eb6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f0eb7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f0eb8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f0eb9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f0eba:
    // 004f0eba  ba80c65400             -mov edx, 0x54c680
    cpu.edx = 5555840 /*0x54c680*/;
    // 004f0ebf  b98cc65400             -mov ecx, 0x54c68c
    cpu.ecx = 5555852 /*0x54c68c*/;
    // 004f0ec4  bfc4000000             -mov edi, 0xc4
    cpu.edi = 196 /*0xc4*/;
    // 004f0ec9  6898c65400             -push 0x54c698
    app->getMemory<x86::reg32>(cpu.esp-4) = 5555864 /*0x54c698*/;
    cpu.esp -= 4;
    // 004f0ece  891590215500           -mov dword ptr [0x552190], edx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edx;
    // 004f0ed4  890d94215500           -mov dword ptr [0x552194], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ecx;
    // 004f0eda  893d98215500           -mov dword ptr [0x552198], edi
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.edi;
    // 004f0ee0  e82b01f1ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004f0ee5  83c404                 +add esp, 4
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004f0ee8  e9c9feffff             -jmp 0x4f0db6
    goto L_0x004f0db6;
L_0x004f0eed:
    // 004f0eed  e84e000000             -call 0x4f0f40
    cpu.esp -= 4;
    sub_4f0f40(app, cpu);
    if (cpu.terminate) return;
    // 004f0ef2  e9ccfeffff             -jmp 0x4f0dc3
    goto L_0x004f0dc3;
L_0x004f0ef7:
    // 004f0ef7  bb80c65400             -mov ebx, 0x54c680
    cpu.ebx = 5555840 /*0x54c680*/;
    // 004f0efc  be8cc65400             -mov esi, 0x54c68c
    cpu.esi = 5555852 /*0x54c68c*/;
    // 004f0f01  bfde000000             -mov edi, 0xde
    cpu.edi = 222 /*0xde*/;
    // 004f0f06  68d4c65400             -push 0x54c6d4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5555924 /*0x54c6d4*/;
    cpu.esp -= 4;
    // 004f0f0b  891d90215500           -mov dword ptr [0x552190], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ebx;
    // 004f0f11  893594215500           -mov dword ptr [0x552194], esi
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.esi;
    // 004f0f17  893d98215500           -mov dword ptr [0x552198], edi
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.edi;
    // 004f0f1d  e8ee00f1ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004f0f22  83c404                 +add esp, 4
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004f0f25  eb81                   -jmp 0x4f0ea8
    goto L_0x004f0ea8;
L_0x004f0f27:
    // 004f0f27  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004f0f29  e8b2e9feff             -call 0x4df8e0
    cpu.esp -= 4;
    sub_4df8e0(app, cpu);
    if (cpu.terminate) return;
    // 004f0f2e  a1e00b9f00             -mov eax, dword ptr [0x9f0be0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10423264) /* 0x9f0be0 */);
    // 004f0f33  8b28                   -mov ebp, dword ptr [eax]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.eax);
    // 004f0f35  39e9                   +cmp ecx, ebp
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f0f37  74ee                   -je 0x4f0f27
    if (cpu.flags.zf)
    {
        goto L_0x004f0f27;
    }
    // 004f0f39  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f0f3a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f0f3b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f0f3c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f0f3d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4f0f40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f0f40  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f0f41  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f0f42  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f0f43  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f0f44  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f0f45  e826810000             -call 0x4f9070
    cpu.esp -= 4;
    sub_4f9070(app, cpu);
    if (cpu.terminate) return;
    // 004f0f4a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f0f4c  7510                   -jne 0x4f0f5e
    if (!cpu.flags.zf)
    {
        goto L_0x004f0f5e;
    }
    // 004f0f4e  8b35e00b9f00           -mov esi, dword ptr [0x9f0be0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(10423264) /* 0x9f0be0 */);
    // 004f0f54  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004f0f56  7544                   -jne 0x4f0f9c
    if (!cpu.flags.zf)
    {
        goto L_0x004f0f9c;
    }
    // 004f0f58  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f0f59  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f0f5a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f0f5b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f0f5c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f0f5d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f0f5e:
    // 004f0f5e  ba80c65400             -mov edx, 0x54c680
    cpu.edx = 5555840 /*0x54c680*/;
    // 004f0f63  b904c75400             -mov ecx, 0x54c704
    cpu.ecx = 5555972 /*0x54c704*/;
    // 004f0f68  bb08010000             -mov ebx, 0x108
    cpu.ebx = 264 /*0x108*/;
    // 004f0f6d  6810c75400             -push 0x54c710
    app->getMemory<x86::reg32>(cpu.esp-4) = 5555984 /*0x54c710*/;
    cpu.esp -= 4;
    // 004f0f72  891590215500           -mov dword ptr [0x552190], edx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edx;
    // 004f0f78  890d94215500           -mov dword ptr [0x552194], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ecx;
    // 004f0f7e  891d98215500           -mov dword ptr [0x552198], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ebx;
    // 004f0f84  e88700f1ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004f0f89  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f0f8c  8b35e00b9f00           -mov esi, dword ptr [0x9f0be0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(10423264) /* 0x9f0be0 */);
    // 004f0f92  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004f0f94  7506                   -jne 0x4f0f9c
    if (!cpu.flags.zf)
    {
        goto L_0x004f0f9c;
    }
    // 004f0f96  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f0f97  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f0f98  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f0f99  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f0f9a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f0f9b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f0f9c:
    // 004f0f9c  c7460401000000         -mov dword ptr [esi + 4], 1
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = 1 /*0x1*/;
    // 004f0fa3  e828fdffff             -call 0x4f0cd0
    cpu.esp -= 4;
    sub_4f0cd0(app, cpu);
    if (cpu.terminate) return;
    // 004f0fa8  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x004f0faa:
    // 004f0faa  a1e00b9f00             -mov eax, dword ptr [0x9f0be0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10423264) /* 0x9f0be0 */);
    // 004f0faf  3b10                   +cmp edx, dword ptr [eax]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f0fb1  7409                   -je 0x4f0fbc
    if (cpu.flags.zf)
    {
        goto L_0x004f0fbc;
    }
    // 004f0fb3  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004f0fb5  e826e9feff             -call 0x4df8e0
    cpu.esp -= 4;
    sub_4df8e0(app, cpu);
    if (cpu.terminate) return;
    // 004f0fba  ebee                   -jmp 0x4f0faa
    goto L_0x004f0faa;
L_0x004f0fbc:
    // 004f0fbc  83c070                 -add eax, 0x70
    (cpu.eax) += x86::reg32(x86::sreg32(112 /*0x70*/));
    // 004f0fbf  e89ccf0100             -call 0x50df60
    cpu.esp -= 4;
    sub_50df60(app, cpu);
    if (cpu.terminate) return;
    // 004f0fc4  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004f0fc6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f0fc8  743a                   -je 0x4f1004
    if (cpu.flags.zf)
    {
        goto L_0x004f1004;
    }
L_0x004f0fca:
    // 004f0fca  8b6a1c                 -mov ebp, dword ptr [edx + 0x1c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */);
    // 004f0fcd  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004f0fcf  7407                   -je 0x4f0fd8
    if (cpu.flags.zf)
    {
        goto L_0x004f0fd8;
    }
    // 004f0fd1  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004f0fd3  e8b808ffff             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
L_0x004f0fd8:
    // 004f0fd8  8b4218                 -mov eax, dword ptr [edx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 004f0fdb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f0fdd  7405                   -je 0x4f0fe4
    if (cpu.flags.zf)
    {
        goto L_0x004f0fe4;
    }
    // 004f0fdf  e8ac08ffff             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
L_0x004f0fe4:
    // 004f0fe4  a1e00b9f00             -mov eax, dword ptr [0x9f0be0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10423264) /* 0x9f0be0 */);
    // 004f0fe9  83c01c                 -add eax, 0x1c
    (cpu.eax) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004f0fec  e85fce0100             -call 0x50de50
    cpu.esp -= 4;
    sub_50de50(app, cpu);
    if (cpu.terminate) return;
    // 004f0ff1  a1e00b9f00             -mov eax, dword ptr [0x9f0be0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10423264) /* 0x9f0be0 */);
    // 004f0ff6  83c070                 -add eax, 0x70
    (cpu.eax) += x86::reg32(x86::sreg32(112 /*0x70*/));
    // 004f0ff9  e862cf0100             -call 0x50df60
    cpu.esp -= 4;
    sub_50df60(app, cpu);
    if (cpu.terminate) return;
    // 004f0ffe  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004f1000  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f1002  75c6                   -jne 0x4f0fca
    if (!cpu.flags.zf)
    {
        goto L_0x004f0fca;
    }
L_0x004f1004:
    // 004f1004  a1e00b9f00             -mov eax, dword ptr [0x9f0be0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10423264) /* 0x9f0be0 */);
    // 004f1009  83c038                 -add eax, 0x38
    (cpu.eax) += x86::reg32(x86::sreg32(56 /*0x38*/));
    // 004f100c  e84fcf0100             -call 0x50df60
    cpu.esp -= 4;
    sub_50df60(app, cpu);
    if (cpu.terminate) return;
    // 004f1011  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004f1013  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f1015  743c                   -je 0x4f1053
    if (cpu.flags.zf)
    {
        goto L_0x004f1053;
    }
L_0x004f1017:
    // 004f1017  8b4a1c                 -mov ecx, dword ptr [edx + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */);
    // 004f101a  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004f101c  7407                   -je 0x4f1025
    if (cpu.flags.zf)
    {
        goto L_0x004f1025;
    }
    // 004f101e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004f1020  e86b08ffff             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
L_0x004f1025:
    // 004f1025  8b5a18                 -mov ebx, dword ptr [edx + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 004f1028  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004f102a  7407                   -je 0x4f1033
    if (cpu.flags.zf)
    {
        goto L_0x004f1033;
    }
    // 004f102c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004f102e  e85d08ffff             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
L_0x004f1033:
    // 004f1033  a1e00b9f00             -mov eax, dword ptr [0x9f0be0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10423264) /* 0x9f0be0 */);
    // 004f1038  83c01c                 -add eax, 0x1c
    (cpu.eax) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004f103b  e810ce0100             -call 0x50de50
    cpu.esp -= 4;
    sub_50de50(app, cpu);
    if (cpu.terminate) return;
    // 004f1040  a1e00b9f00             -mov eax, dword ptr [0x9f0be0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10423264) /* 0x9f0be0 */);
    // 004f1045  83c038                 -add eax, 0x38
    (cpu.eax) += x86::reg32(x86::sreg32(56 /*0x38*/));
    // 004f1048  e813cf0100             -call 0x50df60
    cpu.esp -= 4;
    sub_50df60(app, cpu);
    if (cpu.terminate) return;
    // 004f104d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004f104f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f1051  75c4                   -jne 0x4f1017
    if (!cpu.flags.zf)
    {
        goto L_0x004f1017;
    }
L_0x004f1053:
    // 004f1053  a1e00b9f00             -mov eax, dword ptr [0x9f0be0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10423264) /* 0x9f0be0 */);
    // 004f1058  83c054                 -add eax, 0x54
    (cpu.eax) += x86::reg32(x86::sreg32(84 /*0x54*/));
    // 004f105b  e800cf0100             -call 0x50df60
    cpu.esp -= 4;
    sub_50df60(app, cpu);
    if (cpu.terminate) return;
    // 004f1060  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004f1062  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f1064  743a                   -je 0x4f10a0
    if (cpu.flags.zf)
    {
        goto L_0x004f10a0;
    }
L_0x004f1066:
    // 004f1066  8b6a1c                 -mov ebp, dword ptr [edx + 0x1c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */);
    // 004f1069  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004f106b  7407                   -je 0x4f1074
    if (cpu.flags.zf)
    {
        goto L_0x004f1074;
    }
    // 004f106d  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004f106f  e81c08ffff             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
L_0x004f1074:
    // 004f1074  8b4218                 -mov eax, dword ptr [edx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 004f1077  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f1079  7405                   -je 0x4f1080
    if (cpu.flags.zf)
    {
        goto L_0x004f1080;
    }
    // 004f107b  e81008ffff             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
L_0x004f1080:
    // 004f1080  a1e00b9f00             -mov eax, dword ptr [0x9f0be0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10423264) /* 0x9f0be0 */);
    // 004f1085  83c01c                 -add eax, 0x1c
    (cpu.eax) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004f1088  e8c3cd0100             -call 0x50de50
    cpu.esp -= 4;
    sub_50de50(app, cpu);
    if (cpu.terminate) return;
    // 004f108d  a1e00b9f00             -mov eax, dword ptr [0x9f0be0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10423264) /* 0x9f0be0 */);
    // 004f1092  83c054                 -add eax, 0x54
    (cpu.eax) += x86::reg32(x86::sreg32(84 /*0x54*/));
    // 004f1095  e8c6ce0100             -call 0x50df60
    cpu.esp -= 4;
    sub_50df60(app, cpu);
    if (cpu.terminate) return;
    // 004f109a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004f109c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f109e  75c6                   -jne 0x4f1066
    if (!cpu.flags.zf)
    {
        goto L_0x004f1066;
    }
L_0x004f10a0:
    // 004f10a0  b8200d4f00             -mov eax, 0x4f0d20
    cpu.eax = 5180704 /*0x4f0d20*/;
    // 004f10a5  e83665ffff             -call 0x4e75e0
    cpu.esp -= 4;
    sub_4e75e0(app, cpu);
    if (cpu.terminate) return;
    // 004f10aa  a1e00b9f00             -mov eax, dword ptr [0x9f0be0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10423264) /* 0x9f0be0 */);
    // 004f10af  83c01c                 -add eax, 0x1c
    (cpu.eax) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004f10b2  e829cd0100             -call 0x50dde0
    cpu.esp -= 4;
    sub_50dde0(app, cpu);
    if (cpu.terminate) return;
    // 004f10b7  a1e00b9f00             -mov eax, dword ptr [0x9f0be0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10423264) /* 0x9f0be0 */);
    // 004f10bc  83c038                 -add eax, 0x38
    (cpu.eax) += x86::reg32(x86::sreg32(56 /*0x38*/));
    // 004f10bf  e81ccd0100             -call 0x50dde0
    cpu.esp -= 4;
    sub_50dde0(app, cpu);
    if (cpu.terminate) return;
    // 004f10c4  a1e00b9f00             -mov eax, dword ptr [0x9f0be0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10423264) /* 0x9f0be0 */);
    // 004f10c9  83c070                 -add eax, 0x70
    (cpu.eax) += x86::reg32(x86::sreg32(112 /*0x70*/));
    // 004f10cc  e80fcd0100             -call 0x50dde0
    cpu.esp -= 4;
    sub_50dde0(app, cpu);
    if (cpu.terminate) return;
    // 004f10d1  a1e00b9f00             -mov eax, dword ptr [0x9f0be0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10423264) /* 0x9f0be0 */);
    // 004f10d6  83c054                 -add eax, 0x54
    (cpu.eax) += x86::reg32(x86::sreg32(84 /*0x54*/));
    // 004f10d9  e802cd0100             -call 0x50dde0
    cpu.esp -= 4;
    sub_50dde0(app, cpu);
    if (cpu.terminate) return;
    // 004f10de  a1e00b9f00             -mov eax, dword ptr [0x9f0be0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10423264) /* 0x9f0be0 */);
    // 004f10e3  8b7008                 -mov esi, dword ptr [eax + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004f10e6  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004f10e8  7407                   -je 0x4f10f1
    if (cpu.flags.zf)
    {
        goto L_0x004f10f1;
    }
    // 004f10ea  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004f10ec  e8af1cffff             -call 0x4e2da0
    cpu.esp -= 4;
    sub_4e2da0(app, cpu);
    if (cpu.terminate) return;
L_0x004f10f1:
    // 004f10f1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f10f2  a1e00b9f00             -mov eax, dword ptr [0x9f0be0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10423264) /* 0x9f0be0 */);
    // 004f10f7  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004f10f9  e89207ffff             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
    // 004f10fe  893de00b9f00           -mov dword ptr [0x9f0be0], edi
    app->getMemory<x86::reg32>(x86::reg32(10423264) /* 0x9f0be0 */) = cpu.edi;
    // 004f1104  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f1105  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f1106  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f1107  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f1108  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f1109  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f110a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_4f1110(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f1110  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f1111  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f1112  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f1113  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004f1115  833de00b9f0000         +cmp dword ptr [0x9f0be0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10423264) /* 0x9f0be0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f111c  752d                   -jne 0x4f114b
    if (!cpu.flags.zf)
    {
        goto L_0x004f114b;
    }
    // 004f111e  bf80c65400             -mov edi, 0x54c680
    cpu.edi = 5555840 /*0x54c680*/;
    // 004f1123  bd3cc75400             -mov ebp, 0x54c73c
    cpu.ebp = 5556028 /*0x54c73c*/;
    // 004f1128  b874010000             -mov eax, 0x174
    cpu.eax = 372 /*0x174*/;
    // 004f112d  6854c75400             -push 0x54c754
    app->getMemory<x86::reg32>(cpu.esp-4) = 5556052 /*0x54c754*/;
    cpu.esp -= 4;
    // 004f1132  893d90215500           -mov dword ptr [0x552190], edi
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edi;
    // 004f1138  892d94215500           -mov dword ptr [0x552194], ebp
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebp;
    // 004f113e  a398215500             -mov dword ptr [0x552198], eax
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.eax;
    // 004f1143  e8c8fef0ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004f1148  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x004f114b:
    // 004f114b  a1e00b9f00             -mov eax, dword ptr [0x9f0be0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10423264) /* 0x9f0be0 */);
    // 004f1150  83c01c                 -add eax, 0x1c
    (cpu.eax) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004f1153  e808ce0100             -call 0x50df60
    cpu.esp -= 4;
    sub_50df60(app, cpu);
    if (cpu.terminate) return;
    // 004f1158  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004f115a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f115c  7504                   -jne 0x4f1162
    if (!cpu.flags.zf)
    {
        goto L_0x004f1162;
    }
    // 004f115e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f115f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f1160  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f1161  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f1162:
    // 004f1162  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f1163  c7450800000000         -mov dword ptr [ebp + 8], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 004f116a  c7450c00000000         -mov dword ptr [ebp + 0xc], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 004f1171  c7451000000000         -mov dword ptr [ebp + 0x10], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
    // 004f1178  c7452001000000         -mov dword ptr [ebp + 0x20], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */) = 1 /*0x1*/;
    // 004f117f  b93cc75400             -mov ecx, 0x54c73c
    cpu.ecx = 5556028 /*0x54c73c*/;
    // 004f1184  c7451800000000         -mov dword ptr [ebp + 0x18], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 004f118b  a184525600             -mov eax, dword ptr [0x565284]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5657220) /* 0x565284 */);
    // 004f1190  895514                 -mov dword ptr [ebp + 0x14], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 004f1193  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 004f1195  895d24                 -mov dword ptr [ebp + 0x24], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(36) /* 0x24 */) = cpu.ebx;
    // 004f1198  ba80c65400             -mov edx, 0x54c680
    cpu.edx = 5555840 /*0x54c680*/;
    // 004f119d  bb82010000             -mov ebx, 0x182
    cpu.ebx = 386 /*0x182*/;
    // 004f11a2  890d94215500           -mov dword ptr [0x552194], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ecx;
    // 004f11a8  894504                 -mov dword ptr [ebp + 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004f11ab  891590215500           -mov dword ptr [0x552190], edx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edx;
    // 004f11b1  891d98215500           -mov dword ptr [0x552198], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ebx;
    // 004f11b7  40                     -inc eax
    (cpu.eax)++;
    // 004f11b8  8b1df4435600           -mov ebx, dword ptr [0x5643f4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5653492) /* 0x5643f4 */);
    // 004f11be  a384525600             -mov dword ptr [0x565284], eax
    app->getMemory<x86::reg32>(x86::reg32(5657220) /* 0x565284 */) = cpu.eax;
    // 004f11c3  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004f11c5  49                     -dec ecx
    (cpu.ecx)--;
    // 004f11c6  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004f11c8  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 004f11ca  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 004f11cc  49                     -dec ecx
    (cpu.ecx)--;
    // 004f11cd  b880c75400             -mov eax, 0x54c780
    cpu.eax = 5556096 /*0x54c780*/;
    // 004f11d2  8d5101                 -lea edx, [ecx + 1]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 004f11d5  e84604ffff             -call 0x4e1620
    cpu.esp -= 4;
    sub_4e1620(app, cpu);
    if (cpu.terminate) return;
    // 004f11da  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004f11dc  89451c                 -mov dword ptr [ebp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 004f11df  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x004f11e0:
    // 004f11e0  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004f11e2  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 004f11e4  3c00                   +cmp al, 0
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
    // 004f11e6  7410                   -je 0x4f11f8
    if (cpu.flags.zf)
    {
        goto L_0x004f11f8;
    }
    // 004f11e8  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004f11eb  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004f11ee  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 004f11f1  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004f11f4  3c00                   +cmp al, 0
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
    // 004f11f6  75e8                   -jne 0x4f11e0
    if (!cpu.flags.zf)
    {
        goto L_0x004f11e0;
    }
L_0x004f11f8:
    // 004f11f8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f11f9  a1e00b9f00             -mov eax, dword ptr [0x9f0be0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10423264) /* 0x9f0be0 */);
    // 004f11fe  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004f1200  83c070                 -add eax, 0x70
    (cpu.eax) += x86::reg32(x86::sreg32(112 /*0x70*/));
    // 004f1203  e848cc0100             -call 0x50de50
    cpu.esp -= 4;
    sub_50de50(app, cpu);
    if (cpu.terminate) return;
    // 004f1208  8b15e00b9f00           -mov edx, dword ptr [0x9f0be0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10423264) /* 0x9f0be0 */);
    // 004f120e  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 004f1210  b8e40b9f00             -mov eax, 0x9f0be4
    cpu.eax = 10423268 /*0x9f0be4*/;
    // 004f1215  e806e9feff             -call 0x4dfb20
    cpu.esp -= 4;
    sub_4dfb20(app, cpu);
    if (cpu.terminate) return;
    // 004f121a  8b4504                 -mov eax, dword ptr [ebp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 004f121d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f121e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f121f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f1220  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f1221  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_4f1230(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f1230  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f1231  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004f1233  e8d8feffff             -call 0x4f1110
    cpu.esp -= 4;
    sub_4f1110(app, cpu);
    if (cpu.terminate) return;
    // 004f1238  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f1239  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_4f1240(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f1240  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f1241  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f1242  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f1243  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004f1245  833de00b9f0000         +cmp dword ptr [0x9f0be0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10423264) /* 0x9f0be0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f124c  752d                   -jne 0x4f127b
    if (!cpu.flags.zf)
    {
        goto L_0x004f127b;
    }
    // 004f124e  bf80c65400             -mov edi, 0x54c680
    cpu.edi = 5555840 /*0x54c680*/;
    // 004f1253  bd8cc75400             -mov ebp, 0x54c78c
    cpu.ebp = 5556108 /*0x54c78c*/;
    // 004f1258  b8bc010000             -mov eax, 0x1bc
    cpu.eax = 444 /*0x1bc*/;
    // 004f125d  6854c75400             -push 0x54c754
    app->getMemory<x86::reg32>(cpu.esp-4) = 5556052 /*0x54c754*/;
    cpu.esp -= 4;
    // 004f1262  893d90215500           -mov dword ptr [0x552190], edi
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edi;
    // 004f1268  892d94215500           -mov dword ptr [0x552194], ebp
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebp;
    // 004f126e  a398215500             -mov dword ptr [0x552198], eax
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.eax;
    // 004f1273  e898fdf0ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004f1278  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x004f127b:
    // 004f127b  a1e00b9f00             -mov eax, dword ptr [0x9f0be0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10423264) /* 0x9f0be0 */);
    // 004f1280  83c01c                 -add eax, 0x1c
    (cpu.eax) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004f1283  e8d8cc0100             -call 0x50df60
    cpu.esp -= 4;
    sub_50df60(app, cpu);
    if (cpu.terminate) return;
    // 004f1288  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004f128a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f128c  7504                   -jne 0x4f1292
    if (!cpu.flags.zf)
    {
        goto L_0x004f1292;
    }
    // 004f128e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f128f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f1290  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f1291  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f1292:
    // 004f1292  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f1293  c7450c00000000         -mov dword ptr [ebp + 0xc], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 004f129a  c7451000000000         -mov dword ptr [ebp + 0x10], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
    // 004f12a1  c7452001000000         -mov dword ptr [ebp + 0x20], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */) = 1 /*0x1*/;
    // 004f12a8  b98cc75400             -mov ecx, 0x54c78c
    cpu.ecx = 5556108 /*0x54c78c*/;
    // 004f12ad  c7451800000000         -mov dword ptr [ebp + 0x18], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 004f12b4  a184525600             -mov eax, dword ptr [0x565284]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5657220) /* 0x565284 */);
    // 004f12b9  895508                 -mov dword ptr [ebp + 8], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004f12bc  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 004f12be  895d24                 -mov dword ptr [ebp + 0x24], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(36) /* 0x24 */) = cpu.ebx;
    // 004f12c1  bbca010000             -mov ebx, 0x1ca
    cpu.ebx = 458 /*0x1ca*/;
    // 004f12c6  8b15f4435600           -mov edx, dword ptr [0x5643f4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5653492) /* 0x5643f4 */);
    // 004f12cc  890d94215500           -mov dword ptr [0x552194], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ecx;
    // 004f12d2  894504                 -mov dword ptr [ebp + 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004f12d5  891d98215500           -mov dword ptr [0x552198], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ebx;
    // 004f12db  40                     -inc eax
    (cpu.eax)++;
    // 004f12dc  895514                 -mov dword ptr [ebp + 0x14], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 004f12df  ba80c65400             -mov edx, 0x54c680
    cpu.edx = 5555840 /*0x54c680*/;
    // 004f12e4  8b1df4435600           -mov ebx, dword ptr [0x5643f4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5653492) /* 0x5643f4 */);
    // 004f12ea  a384525600             -mov dword ptr [0x565284], eax
    app->getMemory<x86::reg32>(x86::reg32(5657220) /* 0x565284 */) = cpu.eax;
    // 004f12ef  891590215500           -mov dword ptr [0x552190], edx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edx;
    // 004f12f5  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004f12f7  49                     -dec ecx
    (cpu.ecx)--;
    // 004f12f8  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004f12fa  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 004f12fc  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 004f12fe  49                     -dec ecx
    (cpu.ecx)--;
    // 004f12ff  b880c75400             -mov eax, 0x54c780
    cpu.eax = 5556096 /*0x54c780*/;
    // 004f1304  8d5101                 -lea edx, [ecx + 1]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 004f1307  e81403ffff             -call 0x4e1620
    cpu.esp -= 4;
    sub_4e1620(app, cpu);
    if (cpu.terminate) return;
    // 004f130c  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004f130e  89451c                 -mov dword ptr [ebp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 004f1311  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x004f1312:
    // 004f1312  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004f1314  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 004f1316  3c00                   +cmp al, 0
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
    // 004f1318  7410                   -je 0x4f132a
    if (cpu.flags.zf)
    {
        goto L_0x004f132a;
    }
    // 004f131a  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004f131d  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004f1320  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 004f1323  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004f1326  3c00                   +cmp al, 0
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
    // 004f1328  75e8                   -jne 0x4f1312
    if (!cpu.flags.zf)
    {
        goto L_0x004f1312;
    }
L_0x004f132a:
    // 004f132a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f132b  a1e00b9f00             -mov eax, dword ptr [0x9f0be0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10423264) /* 0x9f0be0 */);
    // 004f1330  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004f1332  83c070                 -add eax, 0x70
    (cpu.eax) += x86::reg32(x86::sreg32(112 /*0x70*/));
    // 004f1335  e816cb0100             -call 0x50de50
    cpu.esp -= 4;
    sub_50de50(app, cpu);
    if (cpu.terminate) return;
    // 004f133a  8b15e00b9f00           -mov edx, dword ptr [0x9f0be0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10423264) /* 0x9f0be0 */);
    // 004f1340  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 004f1342  b8e40b9f00             -mov eax, 0x9f0be4
    cpu.eax = 10423268 /*0x9f0be4*/;
    // 004f1347  e8d4e7feff             -call 0x4dfb20
    cpu.esp -= 4;
    sub_4dfb20(app, cpu);
    if (cpu.terminate) return;
    // 004f134c  8b4504                 -mov eax, dword ptr [ebp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 004f134f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f1350  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f1351  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f1352  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f1353  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_4f1360(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f1360  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f1361  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004f1363  e8d8feffff             -call 0x4f1240
    cpu.esp -= 4;
    sub_4f1240(app, cpu);
    if (cpu.terminate) return;
    // 004f1368  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f1369  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_4f1370(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f1370  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f1371  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f1372  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f1373  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f1374  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f1377  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004f1379  833de00b9f0000         +cmp dword ptr [0x9f0be0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10423264) /* 0x9f0be0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f1380  752e                   -jne 0x4f13b0
    if (!cpu.flags.zf)
    {
        goto L_0x004f13b0;
    }
    // 004f1382  b980c65400             -mov ecx, 0x54c680
    cpu.ecx = 5555840 /*0x54c680*/;
    // 004f1387  bba4c75400             -mov ebx, 0x54c7a4
    cpu.ebx = 5556132 /*0x54c7a4*/;
    // 004f138c  be03020000             -mov esi, 0x203
    cpu.esi = 515 /*0x203*/;
    // 004f1391  68b4c75400             -push 0x54c7b4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5556148 /*0x54c7b4*/;
    cpu.esp -= 4;
    // 004f1396  890d90215500           -mov dword ptr [0x552190], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ecx;
    // 004f139c  891d94215500           -mov dword ptr [0x552194], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebx;
    // 004f13a2  893598215500           -mov dword ptr [0x552198], esi
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.esi;
    // 004f13a8  e863fcf0ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004f13ad  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x004f13b0:
    // 004f13b0  a1e00b9f00             -mov eax, dword ptr [0x9f0be0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10423264) /* 0x9f0be0 */);
    // 004f13b5  83c01c                 -add eax, 0x1c
    (cpu.eax) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004f13b8  e8a3cb0100             -call 0x50df60
    cpu.esp -= 4;
    sub_50df60(app, cpu);
    if (cpu.terminate) return;
    // 004f13bd  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004f13bf  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004f13c2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f13c4  746d                   -je 0x4f1433
    if (cpu.flags.zf)
    {
        goto L_0x004f1433;
    }
    // 004f13c6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f13c7  c7460800000000         -mov dword ptr [esi + 8], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 004f13ce  c7460c00000000         -mov dword ptr [esi + 0xc], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 004f13d5  c7461000000000         -mov dword ptr [esi + 0x10], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
    // 004f13dc  c7462002000000         -mov dword ptr [esi + 0x20], 2
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */) = 2 /*0x2*/;
    // 004f13e3  c7462400000000         -mov dword ptr [esi + 0x24], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = 0 /*0x0*/;
    // 004f13ea  a184525600             -mov eax, dword ptr [0x565284]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5657220) /* 0x565284 */);
    // 004f13ef  c7461800000000         -mov dword ptr [esi + 0x18], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 004f13f6  8b15f4435600           -mov edx, dword ptr [0x5643f4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5653492) /* 0x5643f4 */);
    // 004f13fc  894604                 -mov dword ptr [esi + 4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004f13ff  40                     -inc eax
    (cpu.eax)++;
    // 004f1400  895614                 -mov dword ptr [esi + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 004f1403  a384525600             -mov dword ptr [0x565284], eax
    app->getMemory<x86::reg32>(x86::reg32(5657220) /* 0x565284 */) = cpu.eax;
    // 004f1408  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004f140a  752f                   -jne 0x4f143b
    if (!cpu.flags.zf)
    {
        goto L_0x004f143b;
    }
    // 004f140c  896e1c                 -mov dword ptr [esi + 0x1c], ebp
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.ebp;
L_0x004f140f:
    // 004f140f  a1e00b9f00             -mov eax, dword ptr [0x9f0be0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10423264) /* 0x9f0be0 */);
    // 004f1414  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004f1418  83c070                 -add eax, 0x70
    (cpu.eax) += x86::reg32(x86::sreg32(112 /*0x70*/));
    // 004f141b  e830ca0100             -call 0x50de50
    cpu.esp -= 4;
    sub_50de50(app, cpu);
    if (cpu.terminate) return;
    // 004f1420  8b15e00b9f00           -mov edx, dword ptr [0x9f0be0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10423264) /* 0x9f0be0 */);
    // 004f1426  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 004f1428  b8e40b9f00             -mov eax, 0x9f0be4
    cpu.eax = 10423268 /*0x9f0be4*/;
    // 004f142d  e8eee6feff             -call 0x4dfb20
    cpu.esp -= 4;
    sub_4dfb20(app, cpu);
    if (cpu.terminate) return;
    // 004f1432  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004f1433:
    // 004f1433  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f1436  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f1437  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f1438  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f1439  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f143a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f143b:
    // 004f143b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f143c  bf80c65400             -mov edi, 0x54c680
    cpu.edi = 5555840 /*0x54c680*/;
    // 004f1441  b8a4c75400             -mov eax, 0x54c7a4
    cpu.eax = 5556132 /*0x54c7a4*/;
    // 004f1446  ba14020000             -mov edx, 0x214
    cpu.edx = 532 /*0x214*/;
    // 004f144b  8b1df4435600           -mov ebx, dword ptr [0x5643f4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5653492) /* 0x5643f4 */);
    // 004f1451  893d90215500           -mov dword ptr [0x552190], edi
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edi;
    // 004f1457  a394215500             -mov dword ptr [0x552194], eax
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.eax;
    // 004f145c  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 004f145e  891598215500           -mov dword ptr [0x552198], edx
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.edx;
    // 004f1464  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004f1466  49                     -dec ecx
    (cpu.ecx)--;
    // 004f1467  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004f1469  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 004f146b  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 004f146d  49                     -dec ecx
    (cpu.ecx)--;
    // 004f146e  b880c75400             -mov eax, 0x54c780
    cpu.eax = 5556096 /*0x54c780*/;
    // 004f1473  8d5101                 -lea edx, [ecx + 1]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 004f1476  e8a501ffff             -call 0x4e1620
    cpu.esp -= 4;
    sub_4e1620(app, cpu);
    if (cpu.terminate) return;
    // 004f147b  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004f147d  89461c                 -mov dword ptr [esi + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 004f1480  89ee                   -mov esi, ebp
    cpu.esi = cpu.ebp;
    // 004f1482  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x004f1483:
    // 004f1483  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004f1485  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 004f1487  3c00                   +cmp al, 0
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
    // 004f1489  7410                   -je 0x4f149b
    if (cpu.flags.zf)
    {
        goto L_0x004f149b;
    }
    // 004f148b  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004f148e  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004f1491  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 004f1494  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004f1497  3c00                   +cmp al, 0
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
    // 004f1499  75e8                   -jne 0x4f1483
    if (!cpu.flags.zf)
    {
        goto L_0x004f1483;
    }
L_0x004f149b:
    // 004f149b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f149c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f149d  e96dffffff             -jmp 0x4f140f
    goto L_0x004f140f;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_4f14b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f14b0  ba80c65400             -mov edx, 0x54c680
    cpu.edx = 5555840 /*0x54c680*/;
    // 004f14b5  b9e0c75400             -mov ecx, 0x54c7e0
    cpu.ecx = 5556192 /*0x54c7e0*/;
    // 004f14ba  bb48020000             -mov ebx, 0x248
    cpu.ebx = 584 /*0x248*/;
    // 004f14bf  68f8c75400             -push 0x54c7f8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5556216 /*0x54c7f8*/;
    cpu.esp -= 4;
    // 004f14c4  891590215500           -mov dword ptr [0x552190], edx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edx;
    // 004f14ca  890d94215500           -mov dword ptr [0x552194], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ecx;
    // 004f14d0  891d98215500           -mov dword ptr [0x552198], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ebx;
    // 004f14d6  e835fbf0ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004f14db  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f14de  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f14e0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_4f14f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f14f0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f14f1  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004f14f3  e8b8ffffff             -call 0x4f14b0
    cpu.esp -= 4;
    sub_4f14b0(app, cpu);
    if (cpu.terminate) return;
    // 004f14f8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f14f9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_4f1500(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f1500  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f1501  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f1502  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f1503  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f1506  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004f1509  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004f150b  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004f150d  833de00b9f0000         +cmp dword ptr [0x9f0be0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10423264) /* 0x9f0be0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f1514  752d                   -jne 0x4f1543
    if (!cpu.flags.zf)
    {
        goto L_0x004f1543;
    }
    // 004f1516  be80c65400             -mov esi, 0x54c680
    cpu.esi = 5555840 /*0x54c680*/;
    // 004f151b  bd20c85400             -mov ebp, 0x54c820
    cpu.ebp = 5556256 /*0x54c820*/;
    // 004f1520  b87d020000             -mov eax, 0x27d
    cpu.eax = 637 /*0x27d*/;
    // 004f1525  683cc85400             -push 0x54c83c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5556284 /*0x54c83c*/;
    cpu.esp -= 4;
    // 004f152a  893590215500           -mov dword ptr [0x552190], esi
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.esi;
    // 004f1530  892d94215500           -mov dword ptr [0x552194], ebp
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebp;
    // 004f1536  a398215500             -mov dword ptr [0x552198], eax
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.eax;
    // 004f153b  e8d0faf0ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004f1540  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x004f1543:
    // 004f1543  a1e00b9f00             -mov eax, dword ptr [0x9f0be0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10423264) /* 0x9f0be0 */);
    // 004f1548  83c01c                 -add eax, 0x1c
    (cpu.eax) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004f154b  e810ca0100             -call 0x50df60
    cpu.esp -= 4;
    sub_50df60(app, cpu);
    if (cpu.terminate) return;
    // 004f1550  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004f1552  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f1554  7507                   -jne 0x4f155d
    if (!cpu.flags.zf)
    {
        goto L_0x004f155d;
    }
    // 004f1556  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f1559  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f155a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f155b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f155c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f155d:
    // 004f155d  a184525600             -mov eax, dword ptr [0x565284]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5657220) /* 0x565284 */);
    // 004f1562  894104                 -mov dword ptr [ecx + 4], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004f1565  40                     -inc eax
    (cpu.eax)++;
    // 004f1566  8b35e00b9f00           -mov esi, dword ptr [0x9f0be0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(10423264) /* 0x9f0be0 */);
    // 004f156c  a384525600             -mov dword ptr [0x565284], eax
    app->getMemory<x86::reg32>(x86::reg32(5657220) /* 0x565284 */) = cpu.eax;
    // 004f1571  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004f1574  c7412003000000         -mov dword ptr [ecx + 0x20], 3
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = 3 /*0x3*/;
    // 004f157b  c7411800000000         -mov dword ptr [ecx + 0x18], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 004f1582  c7411c00000000         -mov dword ptr [ecx + 0x1c], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
    // 004f1589  8b2c24                 -mov ebp, dword ptr [esp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    // 004f158c  897910                 -mov dword ptr [ecx + 0x10], edi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */) = cpu.edi;
    // 004f158f  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 004f1591  895108                 -mov dword ptr [ecx + 8], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004f1594  89410c                 -mov dword ptr [ecx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004f1597  a1f4435600             -mov eax, dword ptr [0x5643f4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653492) /* 0x5643f4 */);
    // 004f159c  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004f159e  894114                 -mov dword ptr [ecx + 0x14], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 004f15a1  8d4670                 -lea eax, [esi + 0x70]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(112) /* 0x70 */);
    // 004f15a4  895924                 -mov dword ptr [ecx + 0x24], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(36) /* 0x24 */) = cpu.ebx;
    // 004f15a7  e8a4c80100             -call 0x50de50
    cpu.esp -= 4;
    sub_50de50(app, cpu);
    if (cpu.terminate) return;
    // 004f15ac  8b15e00b9f00           -mov edx, dword ptr [0x9f0be0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10423264) /* 0x9f0be0 */);
    // 004f15b2  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 004f15b4  b8e40b9f00             -mov eax, 0x9f0be4
    cpu.eax = 10423268 /*0x9f0be4*/;
    // 004f15b9  e862e5feff             -call 0x4dfb20
    cpu.esp -= 4;
    sub_4dfb20(app, cpu);
    if (cpu.terminate) return;
    // 004f15be  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 004f15c1  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f15c4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f15c5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f15c6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f15c7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_4f15d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f15d0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f15d1  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004f15d3  e828ffffff             -call 0x4f1500
    cpu.esp -= 4;
    sub_4f1500(app, cpu);
    if (cpu.terminate) return;
    // 004f15d8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f15d9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_4f15e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f15e0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f15e1  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004f15e3  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004f15e5  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004f15e7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f15e9  e812ffffff             -call 0x4f1500
    cpu.esp -= 4;
    sub_4f1500(app, cpu);
    if (cpu.terminate) return;
    // 004f15ee  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f15ef  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4f15f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f15f0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f15f1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f15f2  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004f15f4  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004f15f6  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004f15f8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f15fa  e801ffffff             -call 0x4f1500
    cpu.esp -= 4;
    sub_4f1500(app, cpu);
    if (cpu.terminate) return;
    // 004f15ff  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f1600  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f1601  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_4f1610(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f1610  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f1611  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f1612  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f1613  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f1614  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f1615  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004f1617  833de00b9f0000         +cmp dword ptr [0x9f0be0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10423264) /* 0x9f0be0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f161e  7530                   -jne 0x4f1650
    if (!cpu.flags.zf)
    {
        goto L_0x004f1650;
    }
    // 004f1620  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f1621  bb80c65400             -mov ebx, 0x54c680
    cpu.ebx = 5555840 /*0x54c680*/;
    // 004f1626  be6cc85400             -mov esi, 0x54c86c
    cpu.esi = 5556332 /*0x54c86c*/;
    // 004f162b  bff2020000             -mov edi, 0x2f2
    cpu.edi = 754 /*0x2f2*/;
    // 004f1630  687cc85400             -push 0x54c87c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5556348 /*0x54c87c*/;
    cpu.esp -= 4;
    // 004f1635  891d90215500           -mov dword ptr [0x552190], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ebx;
    // 004f163b  893594215500           -mov dword ptr [0x552194], esi
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.esi;
    // 004f1641  893d98215500           -mov dword ptr [0x552198], edi
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.edi;
    // 004f1647  e8c4f9f0ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004f164c  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f164f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004f1650:
    // 004f1650  bab00c4f00             -mov edx, 0x4f0cb0
    cpu.edx = 5180592 /*0x4f0cb0*/;
    // 004f1655  a1e00b9f00             -mov eax, dword ptr [0x9f0be0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10423264) /* 0x9f0be0 */);
    // 004f165a  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004f165c  83c070                 -add eax, 0x70
    (cpu.eax) += x86::reg32(x86::sreg32(112 /*0x70*/));
    // 004f165f  e83ccf0100             -call 0x50e5a0
    cpu.esp -= 4;
    sub_50e5a0(app, cpu);
    if (cpu.terminate) return;
    // 004f1664  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004f1666  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f1668  7437                   -je 0x4f16a1
    if (cpu.flags.zf)
    {
        goto L_0x004f16a1;
    }
    // 004f166a  8b7020                 -mov esi, dword ptr [eax + 0x20]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 004f166d  83fe01                 +cmp esi, 1
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f1670  7528                   -jne 0x4f169a
    if (!cpu.flags.zf)
    {
        goto L_0x004f169a;
    }
L_0x004f1672:
    // 004f1672  8b6a1c                 -mov ebp, dword ptr [edx + 0x1c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */);
    // 004f1675  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004f1677  740e                   -je 0x4f1687
    if (cpu.flags.zf)
    {
        goto L_0x004f1687;
    }
    // 004f1679  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004f167b  e81002ffff             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
    // 004f1680  c7421c00000000         -mov dword ptr [edx + 0x1c], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
L_0x004f1687:
    // 004f1687  a1e00b9f00             -mov eax, dword ptr [0x9f0be0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10423264) /* 0x9f0be0 */);
    // 004f168c  83c01c                 -add eax, 0x1c
    (cpu.eax) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004f168f  e8bcc70100             -call 0x50de50
    cpu.esp -= 4;
    sub_50de50(app, cpu);
    if (cpu.terminate) return;
L_0x004f1694:
    // 004f1694  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f1695  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f1696  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f1697  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f1698  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f1699  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f169a:
    // 004f169a  83fe02                 +cmp esi, 2
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f169d  74d3                   -je 0x4f1672
    if (cpu.flags.zf)
    {
        goto L_0x004f1672;
    }
    // 004f169f  ebe6                   -jmp 0x4f1687
    goto L_0x004f1687;
L_0x004f16a1:
    // 004f16a1  e82af6ffff             -call 0x4f0cd0
    cpu.esp -= 4;
    sub_4f0cd0(app, cpu);
    if (cpu.terminate) return;
    // 004f16a6  bab00c4f00             -mov edx, 0x4f0cb0
    cpu.edx = 5180592 /*0x4f0cb0*/;
    // 004f16ab  a1e00b9f00             -mov eax, dword ptr [0x9f0be0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10423264) /* 0x9f0be0 */);
    // 004f16b0  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004f16b2  83c038                 -add eax, 0x38
    (cpu.eax) += x86::reg32(x86::sreg32(56 /*0x38*/));
    // 004f16b5  e8e6ce0100             -call 0x50e5a0
    cpu.esp -= 4;
    sub_50e5a0(app, cpu);
    if (cpu.terminate) return;
    // 004f16ba  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004f16bc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f16be  7516                   -jne 0x4f16d6
    if (!cpu.flags.zf)
    {
        goto L_0x004f16d6;
    }
    // 004f16c0  bab00c4f00             -mov edx, 0x4f0cb0
    cpu.edx = 5180592 /*0x4f0cb0*/;
    // 004f16c5  a1e00b9f00             -mov eax, dword ptr [0x9f0be0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10423264) /* 0x9f0be0 */);
    // 004f16ca  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004f16cc  83c054                 -add eax, 0x54
    (cpu.eax) += x86::reg32(x86::sreg32(84 /*0x54*/));
    // 004f16cf  e8ccce0100             -call 0x50e5a0
    cpu.esp -= 4;
    sub_50e5a0(app, cpu);
    if (cpu.terminate) return;
    // 004f16d4  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
L_0x004f16d6:
    // 004f16d6  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004f16d8  74ba                   -je 0x4f1694
    if (cpu.flags.zf)
    {
        goto L_0x004f1694;
    }
    // 004f16da  8b6a18                 -mov ebp, dword ptr [edx + 0x18]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 004f16dd  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004f16df  7411                   -je 0x4f16f2
    if (cpu.flags.zf)
    {
        goto L_0x004f16f2;
    }
    // 004f16e1  a1e00b9f00             -mov eax, dword ptr [0x9f0be0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10423264) /* 0x9f0be0 */);
    // 004f16e6  3b6814                 +cmp ebp, dword ptr [eax + 0x14]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f16e9  7407                   -je 0x4f16f2
    if (cpu.flags.zf)
    {
        goto L_0x004f16f2;
    }
    // 004f16eb  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004f16ed  e89e01ffff             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
L_0x004f16f2:
    // 004f16f2  a1e00b9f00             -mov eax, dword ptr [0x9f0be0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10423264) /* 0x9f0be0 */);
    // 004f16f7  83c01c                 -add eax, 0x1c
    (cpu.eax) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004f16fa  c7421800000000         -mov dword ptr [edx + 0x18], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 004f1701  e84ac70100             -call 0x50de50
    cpu.esp -= 4;
    sub_50de50(app, cpu);
    if (cpu.terminate) return;
    // 004f1706  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f1707  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f1708  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f1709  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f170a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f170b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_4f1710(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f1710  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f1711  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f1712  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f1713  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004f1715  833de00b9f0000         +cmp dword ptr [0x9f0be0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10423264) /* 0x9f0be0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f171c  7532                   -jne 0x4f1750
    if (!cpu.flags.zf)
    {
        goto L_0x004f1750;
    }
    // 004f171e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f171f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f1720  b980c65400             -mov ecx, 0x54c680
    cpu.ecx = 5555840 /*0x54c680*/;
    // 004f1725  beacc85400             -mov esi, 0x54c8ac
    cpu.esi = 5556396 /*0x54c8ac*/;
    // 004f172a  bf3b030000             -mov edi, 0x33b
    cpu.edi = 827 /*0x33b*/;
    // 004f172f  68bcc85400             -push 0x54c8bc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5556412 /*0x54c8bc*/;
    cpu.esp -= 4;
    // 004f1734  890d90215500           -mov dword ptr [0x552190], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ecx;
    // 004f173a  893594215500           -mov dword ptr [0x552194], esi
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.esi;
    // 004f1740  893d98215500           -mov dword ptr [0x552198], edi
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.edi;
    // 004f1746  e8c5f8f0ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004f174b  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f174e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f174f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004f1750:
    // 004f1750  a1e00b9f00             -mov eax, dword ptr [0x9f0be0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10423264) /* 0x9f0be0 */);
    // 004f1755  bab00c4f00             -mov edx, 0x4f0cb0
    cpu.edx = 5180592 /*0x4f0cb0*/;
    // 004f175a  83c038                 -add eax, 0x38
    (cpu.eax) += x86::reg32(x86::sreg32(56 /*0x38*/));
    // 004f175d  e83ece0100             -call 0x50e5a0
    cpu.esp -= 4;
    sub_50e5a0(app, cpu);
    if (cpu.terminate) return;
    // 004f1762  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004f1764  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f1766  741c                   -je 0x4f1784
    if (cpu.flags.zf)
    {
        goto L_0x004f1784;
    }
    // 004f1768  a1e00b9f00             -mov eax, dword ptr [0x9f0be0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10423264) /* 0x9f0be0 */);
    // 004f176d  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004f176f  83c01c                 -add eax, 0x1c
    (cpu.eax) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004f1772  e8d9c60100             -call 0x50de50
    cpu.esp -= 4;
    sub_50de50(app, cpu);
    if (cpu.terminate) return;
    // 004f1777  83792000               +cmp dword ptr [ecx + 0x20], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f177b  7407                   -je 0x4f1784
    if (cpu.flags.zf)
    {
        goto L_0x004f1784;
    }
    // 004f177d  8b4118                 -mov eax, dword ptr [ecx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 004f1780  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f1781  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f1782  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f1783  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f1784:
    // 004f1784  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f1786  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f1787  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f1788  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f1789  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_4f1790(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f1790  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f1791  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f1792  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f1793  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004f1795  833de00b9f0000         +cmp dword ptr [0x9f0be0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10423264) /* 0x9f0be0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f179c  7532                   -jne 0x4f17d0
    if (!cpu.flags.zf)
    {
        goto L_0x004f17d0;
    }
    // 004f179e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f179f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f17a0  b980c65400             -mov ecx, 0x54c680
    cpu.ecx = 5555840 /*0x54c680*/;
    // 004f17a5  beecc85400             -mov esi, 0x54c8ec
    cpu.esi = 5556460 /*0x54c8ec*/;
    // 004f17aa  bf77030000             -mov edi, 0x377
    cpu.edi = 887 /*0x377*/;
    // 004f17af  6800c95400             -push 0x54c900
    app->getMemory<x86::reg32>(cpu.esp-4) = 5556480 /*0x54c900*/;
    cpu.esp -= 4;
    // 004f17b4  890d90215500           -mov dword ptr [0x552190], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ecx;
    // 004f17ba  893594215500           -mov dword ptr [0x552194], esi
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.esi;
    // 004f17c0  893d98215500           -mov dword ptr [0x552198], edi
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.edi;
    // 004f17c6  e845f8f0ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004f17cb  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f17ce  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f17cf  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004f17d0:
    // 004f17d0  a1e00b9f00             -mov eax, dword ptr [0x9f0be0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10423264) /* 0x9f0be0 */);
    // 004f17d5  bab00c4f00             -mov edx, 0x4f0cb0
    cpu.edx = 5180592 /*0x4f0cb0*/;
    // 004f17da  83c038                 -add eax, 0x38
    (cpu.eax) += x86::reg32(x86::sreg32(56 /*0x38*/));
    // 004f17dd  e8becd0100             -call 0x50e5a0
    cpu.esp -= 4;
    sub_50e5a0(app, cpu);
    if (cpu.terminate) return;
    // 004f17e2  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004f17e4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f17e6  741a                   -je 0x4f1802
    if (cpu.flags.zf)
    {
        goto L_0x004f1802;
    }
    // 004f17e8  a1e00b9f00             -mov eax, dword ptr [0x9f0be0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10423264) /* 0x9f0be0 */);
    // 004f17ed  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004f17ef  83c01c                 -add eax, 0x1c
    (cpu.eax) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004f17f2  e859c60100             -call 0x50de50
    cpu.esp -= 4;
    sub_50de50(app, cpu);
    if (cpu.terminate) return;
    // 004f17f7  83792000               +cmp dword ptr [ecx + 0x20], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f17fb  7409                   -je 0x4f1806
    if (cpu.flags.zf)
    {
        goto L_0x004f1806;
    }
    // 004f17fd  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x004f1802:
    // 004f1802  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f1803  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f1804  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f1805  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f1806:
    // 004f1806  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004f180b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f180c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f180d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f180e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4f1820(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 004f1820  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f1821  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f1822  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f1823  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f1824  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f1825  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f1826  81ec08010000           -sub esp, 0x108
    (cpu.esp) -= x86::reg32(x86::sreg32(264 /*0x108*/));
    // 004f182c  e8cfe2feff             -call 0x4dfb00
    cpu.esp -= 4;
    sub_4dfb00(app, cpu);
    if (cpu.terminate) return;
    // 004f1831  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004f1833  a1e00b9f00             -mov eax, dword ptr [0x9f0be0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10423264) /* 0x9f0be0 */);
    // 004f1838  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 004f183a  c7401800000000         -mov dword ptr [eax + 0x18], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 004f1841  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
L_0x004f1848:
    // 004f1848  a1e00b9f00             -mov eax, dword ptr [0x9f0be0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10423264) /* 0x9f0be0 */);
    // 004f184d  83780400               +cmp dword ptr [eax + 4], 0
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
    // 004f1851  743d                   -je 0x4f1890
    if (cpu.flags.zf)
    {
        goto L_0x004f1890;
    }
    // 004f1853  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004f1856  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004f1858  0f85c6030000           -jne 0x4f1c24
    if (!cpu.flags.zf)
    {
        goto L_0x004f1c24;
    }
L_0x004f185e:
    // 004f185e  a1e00b9f00             -mov eax, dword ptr [0x9f0be0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10423264) /* 0x9f0be0 */);
    // 004f1863  c7400800000000         -mov dword ptr [eax + 8], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 004f186a  c7401800000000         -mov dword ptr [eax + 0x18], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 004f1871  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004f1873  e888e3feff             -call 0x4dfc00
    cpu.esp -= 4;
    sub_4dfc00(app, cpu);
    if (cpu.terminate) return;
    // 004f1878  a1e00b9f00             -mov eax, dword ptr [0x9f0be0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10423264) /* 0x9f0be0 */);
    // 004f187d  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 004f1883  81c408010000           -add esp, 0x108
    (cpu.esp) += x86::reg32(x86::sreg32(264 /*0x108*/));
    // 004f1889  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f188a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f188b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f188c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f188d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f188e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f188f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f1890:
    // 004f1890  83c070                 -add eax, 0x70
    (cpu.eax) += x86::reg32(x86::sreg32(112 /*0x70*/));
    // 004f1893  e858c70100             -call 0x50dff0
    cpu.esp -= 4;
    sub_50dff0(app, cpu);
    if (cpu.terminate) return;
    // 004f1898  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004f189a  89842404010000         -mov dword ptr [esp + 0x104], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */) = cpu.eax;
    // 004f18a1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f18a3  0f846a030000           -je 0x4f1c13
    if (cpu.flags.zf)
    {
        goto L_0x004f1c13;
    }
    // 004f18a9  a1e00b9f00             -mov eax, dword ptr [0x9f0be0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10423264) /* 0x9f0be0 */);
    // 004f18ae  896818                 -mov dword ptr [eax + 0x18], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.ebp;
    // 004f18b1  8b5520                 -mov edx, dword ptr [ebp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 004f18b4  4a                     -dec edx
    (cpu.edx)--;
    // 004f18b5  83fa03                 +cmp edx, 3
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
    // 004f18b8  0f8722030000           -ja 0x4f1be0
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004f1be0;
    }
    // 004f18be  ff249510184f00         -jmp dword ptr [edx*4 + 0x4f1810]
    cpu.ip = app->getMemory<x86::reg32>(5183504 + cpu.edx * 4); goto dynamic_jump;
  case 0x004f18c5:
    // 004f18c5  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 004f18c7  8b751c                 -mov esi, dword ptr [ebp + 0x1c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 004f18ca  8d942400010000         -lea edx, [esp + 0x100]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 004f18d1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x004f18d2:
    // 004f18d2  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004f18d4  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 004f18d6  3c00                   +cmp al, 0
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
    // 004f18d8  7410                   -je 0x4f18ea
    if (cpu.flags.zf)
    {
        goto L_0x004f18ea;
    }
    // 004f18da  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004f18dd  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004f18e0  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 004f18e3  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004f18e6  3c00                   +cmp al, 0
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
    // 004f18e8  75e8                   -jne 0x4f18d2
    if (!cpu.flags.zf)
    {
        goto L_0x004f18d2;
    }
L_0x004f18ea:
    // 004f18ea  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f18eb  8b451c                 -mov eax, dword ptr [ebp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 004f18ee  8d4d10                 -lea ecx, [ebp + 0x10]
    cpu.ecx = x86::reg32(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004f18f1  e89afffeff             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
    // 004f18f6  8d5d0c                 -lea ebx, [ebp + 0xc]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004f18f9  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004f18fb  c7451c00000000         -mov dword ptr [ebp + 0x1c], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
    // 004f1902  e8c90fffff             -call 0x4e28d0
    cpu.esp -= 4;
    sub_4e28d0(app, cpu);
    if (cpu.terminate) return;
    // 004f1907  c7451800000000         -mov dword ptr [ebp + 0x18], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 004f190e  8bbc2400010000         -mov edi, dword ptr [esp + 0x100]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 004f1915  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004f1917  0f8464010000           -je 0x4f1a81
    if (cpu.flags.zf)
    {
        goto L_0x004f1a81;
    }
    // 004f191d  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004f1920  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004f1922  b90e010000             -mov ecx, 0x10e
    cpu.ecx = 270 /*0x10e*/;
    // 004f1927  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004f192a  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004f192c  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004f192e  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004f1930  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f1932  e8e9de0000             -call 0x4ff820
    cpu.esp -= 4;
    sub_4ff820(app, cpu);
    if (cpu.terminate) return;
    // 004f1937  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004f1939  837d0800               +cmp dword ptr [ebp + 8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f193d  0f852e010000           -jne 0x4f1a71
    if (!cpu.flags.zf)
    {
        goto L_0x004f1a71;
    }
    // 004f1943  ba80c65400             -mov edx, 0x54c680
    cpu.edx = 5555840 /*0x54c680*/;
    // 004f1948  bb30c95400             -mov ebx, 0x54c930
    cpu.ebx = 5556528 /*0x54c930*/;
    // 004f194d  bea7030000             -mov esi, 0x3a7
    cpu.esi = 935 /*0x3a7*/;
    // 004f1952  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004f1954  891590215500           -mov dword ptr [0x552190], edx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edx;
    // 004f195a  891d94215500           -mov dword ptr [0x552194], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebx;
    // 004f1960  8b5d14                 -mov ebx, dword ptr [ebp + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004f1963  8b5510                 -mov edx, dword ptr [ebp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004f1966  893598215500           -mov dword ptr [0x552198], esi
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.esi;
    // 004f196c  e8affcfeff             -call 0x4e1620
    cpu.esp -= 4;
    sub_4e1620(app, cpu);
    if (cpu.terminate) return;
    // 004f1971  894518                 -mov dword ptr [ebp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004f1974  894508                 -mov dword ptr [ebp + 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.eax;
L_0x004f1977:
    // 004f1977  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004f1979  e8f2dc0000             -call 0x4ff670
    cpu.esp -= 4;
    sub_4ff670(app, cpu);
    if (cpu.terminate) return;
    // 004f197e  e86dde0000             -call 0x4ff7f0
    cpu.esp -= 4;
    sub_4ff7f0(app, cpu);
    if (cpu.terminate) return;
    // 004f1983  8b842400010000         -mov eax, dword ptr [esp + 0x100]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 004f198a  8b942404010000         -mov edx, dword ptr [esp + 0x104]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 004f1991  e80a27ffff             -call 0x4e40a0
    cpu.esp -= 4;
    sub_4e40a0(app, cpu);
    if (cpu.terminate) return;
    // 004f1996  8b842400010000         -mov eax, dword ptr [esp + 0x100]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 004f199d  8b520c                 -mov edx, dword ptr [edx + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 004f19a0  8b9c2404010000         -mov ebx, dword ptr [esp + 0x104]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 004f19a7  e8b414ffff             -call 0x4e2e60
    cpu.esp -= 4;
    sub_4e2e60(app, cpu);
    if (cpu.terminate) return;
    // 004f19ac  8b942404010000         -mov edx, dword ptr [esp + 0x104]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 004f19b3  8b842400010000         -mov eax, dword ptr [esp + 0x100]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 004f19ba  8b5b10                 -mov ebx, dword ptr [ebx + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 004f19bd  8b5208                 -mov edx, dword ptr [edx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004f19c0  e81b14ffff             -call 0x4e2de0
    cpu.esp -= 4;
    sub_4e2de0(app, cpu);
    if (cpu.terminate) return;
    // 004f19c5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f19c7  750e                   -jne 0x4f19d7
    if (!cpu.flags.zf)
    {
        goto L_0x004f19d7;
    }
    // 004f19c9  8b842404010000         -mov eax, dword ptr [esp + 0x104]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 004f19d0  c7402000000000         -mov dword ptr [eax + 0x20], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = 0 /*0x0*/;
L_0x004f19d7:
    // 004f19d7  8b842400010000         -mov eax, dword ptr [esp + 0x100]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 004f19de  e80d27ffff             -call 0x4e40f0
    cpu.esp -= 4;
    sub_4e40f0(app, cpu);
    if (cpu.terminate) return;
    // 004f19e3  8b842400010000         -mov eax, dword ptr [esp + 0x100]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 004f19ea  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004f19ec  e8af13ffff             -call 0x4e2da0
    cpu.esp -= 4;
    sub_4e2da0(app, cpu);
    if (cpu.terminate) return;
    // 004f19f1  8b842404010000         -mov eax, dword ptr [esp + 0x104]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 004f19f8  89bc2400010000         -mov dword ptr [esp + 0x100], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */) = cpu.edi;
    // 004f19ff  83782000               +cmp dword ptr [eax + 0x20], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f1a03  7530                   -jne 0x4f1a35
    if (!cpu.flags.zf)
    {
        goto L_0x004f1a35;
    }
    // 004f1a05  8b942404010000         -mov edx, dword ptr [esp + 0x104]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 004f1a0c  a1e00b9f00             -mov eax, dword ptr [0x9f0be0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10423264) /* 0x9f0be0 */);
    // 004f1a11  8b5218                 -mov edx, dword ptr [edx + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 004f1a14  3b5014                 +cmp edx, dword ptr [eax + 0x14]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f1a17  741c                   -je 0x4f1a35
    if (cpu.flags.zf)
    {
        goto L_0x004f1a35;
    }
    // 004f1a19  8b842404010000         -mov eax, dword ptr [esp + 0x104]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 004f1a20  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004f1a23  e868fefeff             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
    // 004f1a28  8b842404010000         -mov eax, dword ptr [esp + 0x104]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 004f1a2f  897818                 -mov dword ptr [eax + 0x18], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.edi;
    // 004f1a32  897808                 -mov dword ptr [eax + 8], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edi;
L_0x004f1a35:
    // 004f1a35  8b842404010000         -mov eax, dword ptr [esp + 0x104]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 004f1a3c  83782400               +cmp dword ptr [eax + 0x24], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f1a40  7444                   -je 0x4f1a86
    if (cpu.flags.zf)
    {
        goto L_0x004f1a86;
    }
L_0x004f1a42:
    // 004f1a42  a1e00b9f00             -mov eax, dword ptr [0x9f0be0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10423264) /* 0x9f0be0 */);
    // 004f1a47  8b942404010000         -mov edx, dword ptr [esp + 0x104]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 004f1a4e  83c054                 +add eax, 0x54
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(84 /*0x54*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
L_0x004f1a51:
    // 004f1a51  e8fac30100             -call 0x50de50
    cpu.esp -= 4;
    sub_50de50(app, cpu);
    if (cpu.terminate) return;
L_0x004f1a56:
    // 004f1a56  a1e00b9f00             -mov eax, dword ptr [0x9f0be0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10423264) /* 0x9f0be0 */);
    // 004f1a5b  c7401800000000         -mov dword ptr [eax + 0x18], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 004f1a62  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004f1a67  e874defeff             -call 0x4df8e0
    cpu.esp -= 4;
    sub_4df8e0(app, cpu);
    if (cpu.terminate) return;
    // 004f1a6c  e9d7fdffff             -jmp 0x4f1848
    goto L_0x004f1848;
L_0x004f1a71:
    // 004f1a71  a1e00b9f00             -mov eax, dword ptr [0x9f0be0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10423264) /* 0x9f0be0 */);
    // 004f1a76  8b4014                 -mov eax, dword ptr [eax + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 004f1a79  894518                 -mov dword ptr [ebp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004f1a7c  e9f6feffff             -jmp 0x4f1977
    goto L_0x004f1977;
L_0x004f1a81:
    // 004f1a81  897d08                 -mov dword ptr [ebp + 8], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.edi;
    // 004f1a84  ebaf                   -jmp 0x4f1a35
    goto L_0x004f1a35;
L_0x004f1a86:
    // 004f1a86  a1e00b9f00             -mov eax, dword ptr [0x9f0be0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10423264) /* 0x9f0be0 */);
    // 004f1a8b  8b942404010000         -mov edx, dword ptr [esp + 0x104]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 004f1a92  83c038                 +add eax, 0x38
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(56 /*0x38*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004f1a95  ebba                   -jmp 0x4f1a51
    goto L_0x004f1a51;
  case 0x004f1a97:
    // 004f1a97  8b5808                 -mov ebx, dword ptr [eax + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004f1a9a  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004f1a9c  0f857a000000           -jne 0x4f1b1c
    if (!cpu.flags.zf)
    {
        goto L_0x004f1b1c;
    }
L_0x004f1aa2:
    // 004f1aa2  a1e00b9f00             -mov eax, dword ptr [0x9f0be0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10423264) /* 0x9f0be0 */);
    // 004f1aa7  c7400800000000         -mov dword ptr [eax + 8], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 004f1aae  8b842404010000         -mov eax, dword ptr [esp + 0x104]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 004f1ab5  83781c00               +cmp dword ptr [eax + 0x1c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f1ab9  744d                   -je 0x4f1b08
    if (cpu.flags.zf)
    {
        goto L_0x004f1b08;
    }
    // 004f1abb  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004f1abd  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f1abf  e85cdd0000             -call 0x4ff820
    cpu.esp -= 4;
    sub_4ff820(app, cpu);
    if (cpu.terminate) return;
    // 004f1ac4  e8a7db0000             -call 0x4ff670
    cpu.esp -= 4;
    sub_4ff670(app, cpu);
    if (cpu.terminate) return;
    // 004f1ac9  e822dd0000             -call 0x4ff7f0
    cpu.esp -= 4;
    sub_4ff7f0(app, cpu);
    if (cpu.terminate) return;
    // 004f1ace  a1e00b9f00             -mov eax, dword ptr [0x9f0be0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10423264) /* 0x9f0be0 */);
    // 004f1ad3  8d4810                 -lea ecx, [eax + 0x10]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004f1ad6  8d580c                 -lea ebx, [eax + 0xc]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004f1ad9  8d5008                 -lea edx, [eax + 8]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004f1adc  8b842404010000         -mov eax, dword ptr [esp + 0x104]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 004f1ae3  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004f1ae6  e8e50dffff             -call 0x4e28d0
    cpu.esp -= 4;
    sub_4e28d0(app, cpu);
    if (cpu.terminate) return;
    // 004f1aeb  8b842404010000         -mov eax, dword ptr [esp + 0x104]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 004f1af2  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004f1af5  e896fdfeff             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
    // 004f1afa  8b842404010000         -mov eax, dword ptr [esp + 0x104]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 004f1b01  c7401c00000000         -mov dword ptr [eax + 0x1c], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
L_0x004f1b08:
    // 004f1b08  a1e00b9f00             -mov eax, dword ptr [0x9f0be0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10423264) /* 0x9f0be0 */);
    // 004f1b0d  8b942404010000         -mov edx, dword ptr [esp + 0x104]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 004f1b14  83c01c                 +add eax, 0x1c
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(28 /*0x1c*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004f1b17  e935ffffff             -jmp 0x4f1a51
    goto L_0x004f1a51;
L_0x004f1b1c:
    // 004f1b1c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004f1b1e  e87d12ffff             -call 0x4e2da0
    cpu.esp -= 4;
    sub_4e2da0(app, cpu);
    if (cpu.terminate) return;
    // 004f1b23  e97affffff             -jmp 0x4f1aa2
    goto L_0x004f1aa2;
  case 0x004f1b28:
    // 004f1b28  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004f1b2b  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004f1b2d  7519                   -jne 0x4f1b48
    if (!cpu.flags.zf)
    {
        goto L_0x004f1b48;
    }
    // 004f1b2f  895520                 -mov dword ptr [ebp + 0x20], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */) = cpu.edx;
L_0x004f1b32:
    // 004f1b32  8b842404010000         -mov eax, dword ptr [esp + 0x104]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 004f1b39  83782400               +cmp dword ptr [eax + 0x24], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f1b3d  0f8443ffffff           -je 0x4f1a86
    if (cpu.flags.zf)
    {
        goto L_0x004f1a86;
    }
    // 004f1b43  e9fafeffff             -jmp 0x4f1a42
    goto L_0x004f1a42;
L_0x004f1b48:
    // 004f1b48  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004f1b4b  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004f1b4d  b90e010000             -mov ecx, 0x10e
    cpu.ecx = 270 /*0x10e*/;
    // 004f1b52  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004f1b55  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004f1b57  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004f1b59  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004f1b5b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f1b5d  e8bedc0000             -call 0x4ff820
    cpu.esp -= 4;
    sub_4ff820(app, cpu);
    if (cpu.terminate) return;
    // 004f1b62  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004f1b64  e807db0000             -call 0x4ff670
    cpu.esp -= 4;
    sub_4ff670(app, cpu);
    if (cpu.terminate) return;
    // 004f1b69  e882dc0000             -call 0x4ff7f0
    cpu.esp -= 4;
    sub_4ff7f0(app, cpu);
    if (cpu.terminate) return;
    // 004f1b6e  a1e00b9f00             -mov eax, dword ptr [0x9f0be0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10423264) /* 0x9f0be0 */);
    // 004f1b73  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004f1b76  e82525ffff             -call 0x4e40a0
    cpu.esp -= 4;
    sub_4e40a0(app, cpu);
    if (cpu.terminate) return;
    // 004f1b7b  a1e00b9f00             -mov eax, dword ptr [0x9f0be0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10423264) /* 0x9f0be0 */);
    // 004f1b80  8b550c                 -mov edx, dword ptr [ebp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004f1b83  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004f1b86  e8d512ffff             -call 0x4e2e60
    cpu.esp -= 4;
    sub_4e2e60(app, cpu);
    if (cpu.terminate) return;
    // 004f1b8b  a1e00b9f00             -mov eax, dword ptr [0x9f0be0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10423264) /* 0x9f0be0 */);
    // 004f1b90  8b5d10                 -mov ebx, dword ptr [ebp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004f1b93  8b5508                 -mov edx, dword ptr [ebp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004f1b96  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004f1b99  e84212ffff             -call 0x4e2de0
    cpu.esp -= 4;
    sub_4e2de0(app, cpu);
    if (cpu.terminate) return;
    // 004f1b9e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f1ba0  7503                   -jne 0x4f1ba5
    if (!cpu.flags.zf)
    {
        goto L_0x004f1ba5;
    }
    // 004f1ba2  894520                 -mov dword ptr [ebp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */) = cpu.eax;
L_0x004f1ba5:
    // 004f1ba5  a1e00b9f00             -mov eax, dword ptr [0x9f0be0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10423264) /* 0x9f0be0 */);
    // 004f1baa  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004f1bad  e83e25ffff             -call 0x4e40f0
    cpu.esp -= 4;
    sub_4e40f0(app, cpu);
    if (cpu.terminate) return;
    // 004f1bb2  e97bffffff             -jmp 0x4f1b32
    goto L_0x004f1b32;
  case 0x004f1bb7:
    // 004f1bb7  8b6808                 -mov ebp, dword ptr [eax + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004f1bba  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004f1bbc  7407                   -je 0x4f1bc5
    if (cpu.flags.zf)
    {
        goto L_0x004f1bc5;
    }
    // 004f1bbe  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004f1bc0  e8db11ffff             -call 0x4e2da0
    cpu.esp -= 4;
    sub_4e2da0(app, cpu);
    if (cpu.terminate) return;
L_0x004f1bc5:
    // 004f1bc5  a1e00b9f00             -mov eax, dword ptr [0x9f0be0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10423264) /* 0x9f0be0 */);
    // 004f1bca  83c01c                 +add eax, 0x1c
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(28 /*0x1c*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004f1bcd  8b942404010000         -mov edx, dword ptr [esp + 0x104]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 004f1bd4  c740ec00000000         -mov dword ptr [eax - 0x14], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-20) /* -0x14 */) = 0 /*0x0*/;
    // 004f1bdb  e971feffff             -jmp 0x4f1a51
    goto L_0x004f1a51;
L_0x004f1be0:
    // 004f1be0  bb80c65400             -mov ebx, 0x54c680
    cpu.ebx = 5555840 /*0x54c680*/;
    // 004f1be5  be30c95400             -mov esi, 0x54c930
    cpu.esi = 5556528 /*0x54c930*/;
    // 004f1bea  bffb030000             -mov edi, 0x3fb
    cpu.edi = 1019 /*0x3fb*/;
    // 004f1bef  6840c95400             -push 0x54c940
    app->getMemory<x86::reg32>(cpu.esp-4) = 5556544 /*0x54c940*/;
    cpu.esp -= 4;
    // 004f1bf4  891d90215500           -mov dword ptr [0x552190], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ebx;
    // 004f1bfa  893594215500           -mov dword ptr [0x552194], esi
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.esi;
    // 004f1c00  893d98215500           -mov dword ptr [0x552198], edi
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.edi;
    // 004f1c06  e805f4f0ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004f1c0b  83c404                 +add esp, 4
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004f1c0e  e943feffff             -jmp 0x4f1a56
    goto L_0x004f1a56;
L_0x004f1c13:
    // 004f1c13  a1e00b9f00             -mov eax, dword ptr [0x9f0be0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10423264) /* 0x9f0be0 */);
    // 004f1c18  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004f1c1a  e851dffeff             -call 0x4dfb70
    cpu.esp -= 4;
    sub_4dfb70(app, cpu);
    if (cpu.terminate) return;
    // 004f1c1f  e924fcffff             -jmp 0x4f1848
    goto L_0x004f1848;
L_0x004f1c24:
    // 004f1c24  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004f1c26  e87511ffff             -call 0x4e2da0
    cpu.esp -= 4;
    sub_4e2da0(app, cpu);
    if (cpu.terminate) return;
    // 004f1c2b  e92efcffff             -jmp 0x4f185e
    goto L_0x004f185e;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip  */
void Application::sub_4f1c30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f1c30  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f1c31  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004f1c33  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f1c34  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f1c35  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f1c36  83ec08                 +sub esp, 8
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004f1c39  8d45ec                 -lea eax, [ebp - 0x14]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 004f1c3c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f1c3d  8b550c                 -mov edx, dword ptr [ebp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004f1c40  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f1c41  8b5d08                 -mov ebx, dword ptr [ebp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004f1c44  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f1c45  e804ce0100             -call 0x50ea4e
    cpu.esp -= 4;
    sub_50ea4e(app, cpu);
    if (cpu.terminate) return;
    // 004f1c4a  d9ee                   +fldz 
    cpu.fpu.push(0.0);
    // 004f1c4c  ded9                   +fcompp 
    cpu.fpu.compare(cpu.fpu.st(0), cpu.fpu.st(1));
    cpu.fpu.pop();
    cpu.fpu.pop();
    // 004f1c4e  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004f1c50  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 004f1c51  760c                   -jbe 0x4f1c5f
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004f1c5f;
    }
    // 004f1c53  dd45ec                 -fld qword ptr [ebp - 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.ebp + x86::reg32(-20) /* -0x14 */)));
    // 004f1c56  dc0570c95400           -fadd qword ptr [0x54c970]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(x86::reg32(5556592) /* 0x54c970 */));
    // 004f1c5c  dd5dec                 -fstp qword ptr [ebp - 0x14]
    app->getMemory<double>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x004f1c5f:
    // 004f1c5f  dd45ec                 -fld qword ptr [ebp - 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.ebp + x86::reg32(-20) /* -0x14 */)));
    // 004f1c62  8d65f4                 -lea esp, [ebp - 0xc]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004f1c65  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f1c66  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f1c67  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f1c68  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f1c69  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_4f1c70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f1c70  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f1c71  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f1c72  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f1c73  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f1c74  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f1c75  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004f1c78  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004f1c7a  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 004f1c7c  8915a0525600           -mov dword ptr [0x5652a0], edx
    app->getMemory<x86::reg32>(x86::reg32(5657248) /* 0x5652a0 */) = cpu.edx;
    // 004f1c82  89159c525600           -mov dword ptr [0x56529c], edx
    app->getMemory<x86::reg32>(x86::reg32(5657244) /* 0x56529c */) = cpu.edx;
    // 004f1c88  891598525600           -mov dword ptr [0x565298], edx
    app->getMemory<x86::reg32>(x86::reg32(5657240) /* 0x565298 */) = cpu.edx;
    // 004f1c8e  8915cc435600           -mov dword ptr [0x5643cc], edx
    app->getMemory<x86::reg32>(x86::reg32(5653452) /* 0x5643cc */) = cpu.edx;
    // 004f1c94  8915c8435600           -mov dword ptr [0x5643c8], edx
    app->getMemory<x86::reg32>(x86::reg32(5653448) /* 0x5643c8 */) = cpu.edx;
    // 004f1c9a  8915c4435600           -mov dword ptr [0x5643c4], edx
    app->getMemory<x86::reg32>(x86::reg32(5653444) /* 0x5643c4 */) = cpu.edx;
    // 004f1ca0  8915c0435600           -mov dword ptr [0x5643c0], edx
    app->getMemory<x86::reg32>(x86::reg32(5653440) /* 0x5643c0 */) = cpu.edx;
    // 004f1ca6  8915bc435600           -mov dword ptr [0x5643bc], edx
    app->getMemory<x86::reg32>(x86::reg32(5653436) /* 0x5643bc */) = cpu.edx;
    // 004f1cac  8915b4435600           -mov dword ptr [0x5643b4], edx
    app->getMemory<x86::reg32>(x86::reg32(5653428) /* 0x5643b4 */) = cpu.edx;
    // 004f1cb2  8915b0435600           -mov dword ptr [0x5643b0], edx
    app->getMemory<x86::reg32>(x86::reg32(5653424) /* 0x5643b0 */) = cpu.edx;
    // 004f1cb8  8915ac435600           -mov dword ptr [0x5643ac], edx
    app->getMemory<x86::reg32>(x86::reg32(5653420) /* 0x5643ac */) = cpu.edx;
    // 004f1cbe  882588525600           -mov byte ptr [0x565288], ah
    app->getMemory<x86::reg8>(x86::reg32(5657224) /* 0x565288 */) = cpu.ah;
    // 004f1cc4  e89fcd0100             -call 0x50ea68
    cpu.esp -= 4;
    sub_50ea68(app, cpu);
    if (cpu.terminate) return;
    // 004f1cc9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f1ccb  0f84ba010000           -je 0x4f1e8b
    if (cpu.flags.zf)
    {
        return sub_4f1e8b(app, cpu);
    }
    // 004f1cd1  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004f1cd3  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004f1cd5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f1cd6  8d742408               -lea esi, [esp + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004f1cda  30db                   -xor bl, bl
    cpu.bl ^= x86::reg8(x86::sreg8(cpu.bl));
    // 004f1cdc  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f1cdd  897c2418               -mov dword ptr [esp + 0x18], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edi;
    // 004f1ce1  bf88525600             -mov edi, 0x565288
    cpu.edi = 5657224 /*0x565288*/;
    // 004f1ce6  e89acd0100             -call 0x50ea85
    cpu.esp -= 4;
    sub_50ea85(app, cpu);
    if (cpu.terminate) return;
    // 004f1ceb  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004f1cee  b90c000000             -mov ecx, 0xc
    cpu.ecx = 12 /*0xc*/;
    // 004f1cf3  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 004f1cf6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f1cf7  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004f1cf9  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004f1cfc  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004f1cfe  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 004f1d00  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 004f1d03  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004f1d05  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f1d06  881d94525600           -mov byte ptr [0x565294], bl
    app->getMemory<x86::reg8>(x86::reg32(5657236) /* 0x565294 */) = cpu.bl;
    // 004f1d0c  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004f1d0e  7f09                   -jg 0x4f1d19
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004f1d19;
    }
L_0x004f1d10:
    // 004f1d10  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004f1d13  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f1d14  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f1d15  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f1d16  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f1d17  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f1d18  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f1d19:
    // 004f1d19  ba78c95400             -mov edx, 0x54c978
    cpu.edx = 5556600 /*0x54c978*/;
    // 004f1d1e  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004f1d20  e8ebc5ffff             -call 0x4ee310
    cpu.esp -= 4;
    sub_4ee310(app, cpu);
    if (cpu.terminate) return;
    // 004f1d25  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f1d27  0f85f9000000           -jne 0x4f1e26
    if (!cpu.flags.zf)
    {
        return sub_4f1e26(app, cpu);
    }
    // 004f1d2d  c705c443560001000000   -mov dword ptr [0x5643c4], 1
    app->getMemory<x86::reg32>(x86::reg32(5653444) /* 0x5643c4 */) = 1 /*0x1*/;
    // 004f1d37  833dcc43560000         +cmp dword ptr [0x5643cc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5653452) /* 0x5643cc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f1d3e  0f8424010000           -je 0x4f1e68
    if (cpu.flags.zf)
    {
        return sub_4f1e68(app, cpu);
    }
    // 004f1d44  6801000080             -push 0x80000001
    app->getMemory<x86::reg32>(cpu.esp-4) = 2147483649 /*0x80000001*/;
    cpu.esp -= 4;
    // 004f1d49  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004f1d4d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f1d4e  e832cd0100             -call 0x50ea85
    cpu.esp -= 4;
    sub_50ea85(app, cpu);
    if (cpu.terminate) return;
    // 004f1d53  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004f1d56  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004f1d59  25000f0000             -and eax, 0xf00
    cpu.eax &= x86::reg32(x86::sreg32(3840 /*0xf00*/));
    // 004f1d5e  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 004f1d61  a398525600             -mov dword ptr [0x565298], eax
    app->getMemory<x86::reg32>(x86::reg32(5657240) /* 0x565298 */) = cpu.eax;
    // 004f1d66  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004f1d69  25f0000000             -and eax, 0xf0
    cpu.eax &= x86::reg32(x86::sreg32(240 /*0xf0*/));
    // 004f1d6e  c1f804                 -sar eax, 4
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (4 /*0x4*/ % 32));
    // 004f1d71  a39c525600             -mov dword ptr [0x56529c], eax
    app->getMemory<x86::reg32>(x86::reg32(5657244) /* 0x56529c */) = cpu.eax;
    // 004f1d76  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004f1d79  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 004f1d7c  8b1d98525600           -mov ebx, dword ptr [0x565298]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5657240) /* 0x565298 */);
    // 004f1d82  a3a0525600             -mov dword ptr [0x5652a0], eax
    app->getMemory<x86::reg32>(x86::reg32(5657248) /* 0x5652a0 */) = cpu.eax;
    // 004f1d87  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f1d89  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004f1d8b  40                     -inc eax
    (cpu.eax)++;
    // 004f1d8c  83fb05                 +cmp ebx, 5
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5 /*0x5*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f1d8f  7c05                   -jl 0x4f1d96
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004f1d96;
    }
    // 004f1d91  a3ac435600             -mov dword ptr [0x5643ac], eax
    app->getMemory<x86::reg32>(x86::reg32(5653420) /* 0x5643ac */) = cpu.eax;
L_0x004f1d96:
    // 004f1d96  83fb06                 +cmp ebx, 6
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(6 /*0x6*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f1d99  7c06                   -jl 0x4f1da1
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004f1da1;
    }
    // 004f1d9b  41                     -inc ecx
    (cpu.ecx)++;
    // 004f1d9c  a3b0435600             -mov dword ptr [0x5643b0], eax
    app->getMemory<x86::reg32>(x86::reg32(5653424) /* 0x5643b0 */) = cpu.eax;
L_0x004f1da1:
    // 004f1da1  f644240b80             +test byte ptr [esp + 0xb], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(11) /* 0xb */) & 128 /*0x80*/));
    // 004f1da6  0f95c0                 -setne al
    cpu.al = !cpu.flags.zf;
    // 004f1da9  a3b8435600             -mov dword ptr [0x5643b8], eax
    app->getMemory<x86::reg32>(x86::reg32(5653432) /* 0x5643b8 */) = cpu.eax;
    // 004f1dae  f644240a80             +test byte ptr [esp + 0xa], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(10) /* 0xa */) & 128 /*0x80*/));
    // 004f1db3  0f95c0                 -setne al
    cpu.al = !cpu.flags.zf;
    // 004f1db6  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004f1db8  a3b4435600             -mov dword ptr [0x5643b4], eax
    app->getMemory<x86::reg32>(x86::reg32(5653428) /* 0x5643b4 */) = cpu.eax;
    // 004f1dbd  f644240810             +test byte ptr [esp + 8], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */) & 16 /*0x10*/));
    // 004f1dc2  0f95c0                 -setne al
    cpu.al = !cpu.flags.zf;
    // 004f1dc5  a3bc435600             -mov dword ptr [0x5643bc], eax
    app->getMemory<x86::reg32>(x86::reg32(5653436) /* 0x5643bc */) = cpu.eax;
    // 004f1dca  f644240980             +test byte ptr [esp + 9], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(9) /* 0x9 */) & 128 /*0x80*/));
    // 004f1dcf  0f95c0                 -setne al
    cpu.al = !cpu.flags.zf;
    // 004f1dd2  a3c0435600             -mov dword ptr [0x5643c0], eax
    app->getMemory<x86::reg32>(x86::reg32(5653440) /* 0x5643c0 */) = cpu.eax;
    // 004f1dd7  f644240b02             +test byte ptr [esp + 0xb], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(11) /* 0xb */) & 2 /*0x2*/));
    // 004f1ddc  0f95c0                 -setne al
    cpu.al = !cpu.flags.zf;
    // 004f1ddf  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004f1de1  f644240b04             +test byte ptr [esp + 0xb], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(11) /* 0xb */) & 4 /*0x4*/));
    // 004f1de6  0f95c0                 -setne al
    cpu.al = !cpu.flags.zf;
    // 004f1de9  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004f1deb  f644240c01             +test byte ptr [esp + 0xc], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */) & 1 /*0x1*/));
    // 004f1df0  0f95c0                 -setne al
    cpu.al = !cpu.flags.zf;
    // 004f1df3  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004f1df5  890da4525600           -mov dword ptr [0x5652a4], ecx
    app->getMemory<x86::reg32>(x86::reg32(5657252) /* 0x5652a4 */) = cpu.ecx;
    // 004f1dfb  833dac43560000         +cmp dword ptr [0x5643ac], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5653420) /* 0x5643ac */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f1e02  750a                   -jne 0x4f1e0e
    if (!cpu.flags.zf)
    {
        goto L_0x004f1e0e;
    }
    // 004f1e04  b831d25300             -mov eax, 0x53d231
    cpu.eax = 5493297 /*0x53d231*/;
    // 004f1e09  e81a39fcff             -call 0x4b5728
    cpu.esp -= 4;
    sub_4b5728(app, cpu);
    if (cpu.terminate) return;
L_0x004f1e0e:
    // 004f1e0e  e9fdfeffff             -jmp 0x4f1d10
    goto L_0x004f1d10;
}

/* align: skip  */
void Application::sub_4f1d49(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004f1d49;
    // 004f1c70  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f1c71  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f1c72  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f1c73  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f1c74  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f1c75  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004f1c78  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004f1c7a  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 004f1c7c  8915a0525600           -mov dword ptr [0x5652a0], edx
    app->getMemory<x86::reg32>(x86::reg32(5657248) /* 0x5652a0 */) = cpu.edx;
    // 004f1c82  89159c525600           -mov dword ptr [0x56529c], edx
    app->getMemory<x86::reg32>(x86::reg32(5657244) /* 0x56529c */) = cpu.edx;
    // 004f1c88  891598525600           -mov dword ptr [0x565298], edx
    app->getMemory<x86::reg32>(x86::reg32(5657240) /* 0x565298 */) = cpu.edx;
    // 004f1c8e  8915cc435600           -mov dword ptr [0x5643cc], edx
    app->getMemory<x86::reg32>(x86::reg32(5653452) /* 0x5643cc */) = cpu.edx;
    // 004f1c94  8915c8435600           -mov dword ptr [0x5643c8], edx
    app->getMemory<x86::reg32>(x86::reg32(5653448) /* 0x5643c8 */) = cpu.edx;
    // 004f1c9a  8915c4435600           -mov dword ptr [0x5643c4], edx
    app->getMemory<x86::reg32>(x86::reg32(5653444) /* 0x5643c4 */) = cpu.edx;
    // 004f1ca0  8915c0435600           -mov dword ptr [0x5643c0], edx
    app->getMemory<x86::reg32>(x86::reg32(5653440) /* 0x5643c0 */) = cpu.edx;
    // 004f1ca6  8915bc435600           -mov dword ptr [0x5643bc], edx
    app->getMemory<x86::reg32>(x86::reg32(5653436) /* 0x5643bc */) = cpu.edx;
    // 004f1cac  8915b4435600           -mov dword ptr [0x5643b4], edx
    app->getMemory<x86::reg32>(x86::reg32(5653428) /* 0x5643b4 */) = cpu.edx;
    // 004f1cb2  8915b0435600           -mov dword ptr [0x5643b0], edx
    app->getMemory<x86::reg32>(x86::reg32(5653424) /* 0x5643b0 */) = cpu.edx;
    // 004f1cb8  8915ac435600           -mov dword ptr [0x5643ac], edx
    app->getMemory<x86::reg32>(x86::reg32(5653420) /* 0x5643ac */) = cpu.edx;
    // 004f1cbe  882588525600           -mov byte ptr [0x565288], ah
    app->getMemory<x86::reg8>(x86::reg32(5657224) /* 0x565288 */) = cpu.ah;
    // 004f1cc4  e89fcd0100             -call 0x50ea68
    cpu.esp -= 4;
    sub_50ea68(app, cpu);
    if (cpu.terminate) return;
    // 004f1cc9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f1ccb  0f84ba010000           -je 0x4f1e8b
    if (cpu.flags.zf)
    {
        return sub_4f1e8b(app, cpu);
    }
    // 004f1cd1  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004f1cd3  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004f1cd5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f1cd6  8d742408               -lea esi, [esp + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004f1cda  30db                   -xor bl, bl
    cpu.bl ^= x86::reg8(x86::sreg8(cpu.bl));
    // 004f1cdc  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f1cdd  897c2418               -mov dword ptr [esp + 0x18], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edi;
    // 004f1ce1  bf88525600             -mov edi, 0x565288
    cpu.edi = 5657224 /*0x565288*/;
    // 004f1ce6  e89acd0100             -call 0x50ea85
    cpu.esp -= 4;
    sub_50ea85(app, cpu);
    if (cpu.terminate) return;
    // 004f1ceb  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004f1cee  b90c000000             -mov ecx, 0xc
    cpu.ecx = 12 /*0xc*/;
    // 004f1cf3  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 004f1cf6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f1cf7  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004f1cf9  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004f1cfc  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004f1cfe  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 004f1d00  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 004f1d03  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004f1d05  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f1d06  881d94525600           -mov byte ptr [0x565294], bl
    app->getMemory<x86::reg8>(x86::reg32(5657236) /* 0x565294 */) = cpu.bl;
    // 004f1d0c  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004f1d0e  7f09                   -jg 0x4f1d19
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004f1d19;
    }
L_0x004f1d10:
    // 004f1d10  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004f1d13  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f1d14  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f1d15  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f1d16  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f1d17  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f1d18  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f1d19:
    // 004f1d19  ba78c95400             -mov edx, 0x54c978
    cpu.edx = 5556600 /*0x54c978*/;
    // 004f1d1e  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004f1d20  e8ebc5ffff             -call 0x4ee310
    cpu.esp -= 4;
    sub_4ee310(app, cpu);
    if (cpu.terminate) return;
    // 004f1d25  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f1d27  0f85f9000000           -jne 0x4f1e26
    if (!cpu.flags.zf)
    {
        return sub_4f1e26(app, cpu);
    }
    // 004f1d2d  c705c443560001000000   -mov dword ptr [0x5643c4], 1
    app->getMemory<x86::reg32>(x86::reg32(5653444) /* 0x5643c4 */) = 1 /*0x1*/;
    // 004f1d37  833dcc43560000         +cmp dword ptr [0x5643cc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5653452) /* 0x5643cc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f1d3e  0f8424010000           -je 0x4f1e68
    if (cpu.flags.zf)
    {
        return sub_4f1e68(app, cpu);
    }
    // 004f1d44  6801000080             -push 0x80000001
    app->getMemory<x86::reg32>(cpu.esp-4) = 2147483649 /*0x80000001*/;
    cpu.esp -= 4;
L_entry_0x004f1d49:
    // 004f1d49  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004f1d4d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f1d4e  e832cd0100             -call 0x50ea85
    cpu.esp -= 4;
    sub_50ea85(app, cpu);
    if (cpu.terminate) return;
    // 004f1d53  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004f1d56  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004f1d59  25000f0000             -and eax, 0xf00
    cpu.eax &= x86::reg32(x86::sreg32(3840 /*0xf00*/));
    // 004f1d5e  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 004f1d61  a398525600             -mov dword ptr [0x565298], eax
    app->getMemory<x86::reg32>(x86::reg32(5657240) /* 0x565298 */) = cpu.eax;
    // 004f1d66  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004f1d69  25f0000000             -and eax, 0xf0
    cpu.eax &= x86::reg32(x86::sreg32(240 /*0xf0*/));
    // 004f1d6e  c1f804                 -sar eax, 4
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (4 /*0x4*/ % 32));
    // 004f1d71  a39c525600             -mov dword ptr [0x56529c], eax
    app->getMemory<x86::reg32>(x86::reg32(5657244) /* 0x56529c */) = cpu.eax;
    // 004f1d76  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004f1d79  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 004f1d7c  8b1d98525600           -mov ebx, dword ptr [0x565298]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5657240) /* 0x565298 */);
    // 004f1d82  a3a0525600             -mov dword ptr [0x5652a0], eax
    app->getMemory<x86::reg32>(x86::reg32(5657248) /* 0x5652a0 */) = cpu.eax;
    // 004f1d87  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f1d89  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004f1d8b  40                     -inc eax
    (cpu.eax)++;
    // 004f1d8c  83fb05                 +cmp ebx, 5
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5 /*0x5*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f1d8f  7c05                   -jl 0x4f1d96
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004f1d96;
    }
    // 004f1d91  a3ac435600             -mov dword ptr [0x5643ac], eax
    app->getMemory<x86::reg32>(x86::reg32(5653420) /* 0x5643ac */) = cpu.eax;
L_0x004f1d96:
    // 004f1d96  83fb06                 +cmp ebx, 6
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(6 /*0x6*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f1d99  7c06                   -jl 0x4f1da1
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004f1da1;
    }
    // 004f1d9b  41                     -inc ecx
    (cpu.ecx)++;
    // 004f1d9c  a3b0435600             -mov dword ptr [0x5643b0], eax
    app->getMemory<x86::reg32>(x86::reg32(5653424) /* 0x5643b0 */) = cpu.eax;
L_0x004f1da1:
    // 004f1da1  f644240b80             +test byte ptr [esp + 0xb], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(11) /* 0xb */) & 128 /*0x80*/));
    // 004f1da6  0f95c0                 -setne al
    cpu.al = !cpu.flags.zf;
    // 004f1da9  a3b8435600             -mov dword ptr [0x5643b8], eax
    app->getMemory<x86::reg32>(x86::reg32(5653432) /* 0x5643b8 */) = cpu.eax;
    // 004f1dae  f644240a80             +test byte ptr [esp + 0xa], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(10) /* 0xa */) & 128 /*0x80*/));
    // 004f1db3  0f95c0                 -setne al
    cpu.al = !cpu.flags.zf;
    // 004f1db6  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004f1db8  a3b4435600             -mov dword ptr [0x5643b4], eax
    app->getMemory<x86::reg32>(x86::reg32(5653428) /* 0x5643b4 */) = cpu.eax;
    // 004f1dbd  f644240810             +test byte ptr [esp + 8], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */) & 16 /*0x10*/));
    // 004f1dc2  0f95c0                 -setne al
    cpu.al = !cpu.flags.zf;
    // 004f1dc5  a3bc435600             -mov dword ptr [0x5643bc], eax
    app->getMemory<x86::reg32>(x86::reg32(5653436) /* 0x5643bc */) = cpu.eax;
    // 004f1dca  f644240980             +test byte ptr [esp + 9], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(9) /* 0x9 */) & 128 /*0x80*/));
    // 004f1dcf  0f95c0                 -setne al
    cpu.al = !cpu.flags.zf;
    // 004f1dd2  a3c0435600             -mov dword ptr [0x5643c0], eax
    app->getMemory<x86::reg32>(x86::reg32(5653440) /* 0x5643c0 */) = cpu.eax;
    // 004f1dd7  f644240b02             +test byte ptr [esp + 0xb], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(11) /* 0xb */) & 2 /*0x2*/));
    // 004f1ddc  0f95c0                 -setne al
    cpu.al = !cpu.flags.zf;
    // 004f1ddf  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004f1de1  f644240b04             +test byte ptr [esp + 0xb], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(11) /* 0xb */) & 4 /*0x4*/));
    // 004f1de6  0f95c0                 -setne al
    cpu.al = !cpu.flags.zf;
    // 004f1de9  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004f1deb  f644240c01             +test byte ptr [esp + 0xc], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */) & 1 /*0x1*/));
    // 004f1df0  0f95c0                 -setne al
    cpu.al = !cpu.flags.zf;
    // 004f1df3  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004f1df5  890da4525600           -mov dword ptr [0x5652a4], ecx
    app->getMemory<x86::reg32>(x86::reg32(5657252) /* 0x5652a4 */) = cpu.ecx;
    // 004f1dfb  833dac43560000         +cmp dword ptr [0x5643ac], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5653420) /* 0x5643ac */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f1e02  750a                   -jne 0x4f1e0e
    if (!cpu.flags.zf)
    {
        goto L_0x004f1e0e;
    }
    // 004f1e04  b831d25300             -mov eax, 0x53d231
    cpu.eax = 5493297 /*0x53d231*/;
    // 004f1e09  e81a39fcff             -call 0x4b5728
    cpu.esp -= 4;
    sub_4b5728(app, cpu);
    if (cpu.terminate) return;
L_0x004f1e0e:
    // 004f1e0e  e9fdfeffff             -jmp 0x4f1d10
    goto L_0x004f1d10;
}

/* align: skip  */
void Application::sub_4f1d44(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004f1d44;
    // 004f1c70  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f1c71  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f1c72  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f1c73  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f1c74  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f1c75  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004f1c78  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004f1c7a  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 004f1c7c  8915a0525600           -mov dword ptr [0x5652a0], edx
    app->getMemory<x86::reg32>(x86::reg32(5657248) /* 0x5652a0 */) = cpu.edx;
    // 004f1c82  89159c525600           -mov dword ptr [0x56529c], edx
    app->getMemory<x86::reg32>(x86::reg32(5657244) /* 0x56529c */) = cpu.edx;
    // 004f1c88  891598525600           -mov dword ptr [0x565298], edx
    app->getMemory<x86::reg32>(x86::reg32(5657240) /* 0x565298 */) = cpu.edx;
    // 004f1c8e  8915cc435600           -mov dword ptr [0x5643cc], edx
    app->getMemory<x86::reg32>(x86::reg32(5653452) /* 0x5643cc */) = cpu.edx;
    // 004f1c94  8915c8435600           -mov dword ptr [0x5643c8], edx
    app->getMemory<x86::reg32>(x86::reg32(5653448) /* 0x5643c8 */) = cpu.edx;
    // 004f1c9a  8915c4435600           -mov dword ptr [0x5643c4], edx
    app->getMemory<x86::reg32>(x86::reg32(5653444) /* 0x5643c4 */) = cpu.edx;
    // 004f1ca0  8915c0435600           -mov dword ptr [0x5643c0], edx
    app->getMemory<x86::reg32>(x86::reg32(5653440) /* 0x5643c0 */) = cpu.edx;
    // 004f1ca6  8915bc435600           -mov dword ptr [0x5643bc], edx
    app->getMemory<x86::reg32>(x86::reg32(5653436) /* 0x5643bc */) = cpu.edx;
    // 004f1cac  8915b4435600           -mov dword ptr [0x5643b4], edx
    app->getMemory<x86::reg32>(x86::reg32(5653428) /* 0x5643b4 */) = cpu.edx;
    // 004f1cb2  8915b0435600           -mov dword ptr [0x5643b0], edx
    app->getMemory<x86::reg32>(x86::reg32(5653424) /* 0x5643b0 */) = cpu.edx;
    // 004f1cb8  8915ac435600           -mov dword ptr [0x5643ac], edx
    app->getMemory<x86::reg32>(x86::reg32(5653420) /* 0x5643ac */) = cpu.edx;
    // 004f1cbe  882588525600           -mov byte ptr [0x565288], ah
    app->getMemory<x86::reg8>(x86::reg32(5657224) /* 0x565288 */) = cpu.ah;
    // 004f1cc4  e89fcd0100             -call 0x50ea68
    cpu.esp -= 4;
    sub_50ea68(app, cpu);
    if (cpu.terminate) return;
    // 004f1cc9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f1ccb  0f84ba010000           -je 0x4f1e8b
    if (cpu.flags.zf)
    {
        return sub_4f1e8b(app, cpu);
    }
    // 004f1cd1  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004f1cd3  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004f1cd5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f1cd6  8d742408               -lea esi, [esp + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004f1cda  30db                   -xor bl, bl
    cpu.bl ^= x86::reg8(x86::sreg8(cpu.bl));
    // 004f1cdc  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f1cdd  897c2418               -mov dword ptr [esp + 0x18], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edi;
    // 004f1ce1  bf88525600             -mov edi, 0x565288
    cpu.edi = 5657224 /*0x565288*/;
    // 004f1ce6  e89acd0100             -call 0x50ea85
    cpu.esp -= 4;
    sub_50ea85(app, cpu);
    if (cpu.terminate) return;
    // 004f1ceb  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004f1cee  b90c000000             -mov ecx, 0xc
    cpu.ecx = 12 /*0xc*/;
    // 004f1cf3  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 004f1cf6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f1cf7  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004f1cf9  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004f1cfc  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004f1cfe  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 004f1d00  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 004f1d03  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004f1d05  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f1d06  881d94525600           -mov byte ptr [0x565294], bl
    app->getMemory<x86::reg8>(x86::reg32(5657236) /* 0x565294 */) = cpu.bl;
    // 004f1d0c  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004f1d0e  7f09                   -jg 0x4f1d19
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004f1d19;
    }
L_0x004f1d10:
    // 004f1d10  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004f1d13  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f1d14  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f1d15  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f1d16  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f1d17  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f1d18  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f1d19:
    // 004f1d19  ba78c95400             -mov edx, 0x54c978
    cpu.edx = 5556600 /*0x54c978*/;
    // 004f1d1e  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004f1d20  e8ebc5ffff             -call 0x4ee310
    cpu.esp -= 4;
    sub_4ee310(app, cpu);
    if (cpu.terminate) return;
    // 004f1d25  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f1d27  0f85f9000000           -jne 0x4f1e26
    if (!cpu.flags.zf)
    {
        return sub_4f1e26(app, cpu);
    }
    // 004f1d2d  c705c443560001000000   -mov dword ptr [0x5643c4], 1
    app->getMemory<x86::reg32>(x86::reg32(5653444) /* 0x5643c4 */) = 1 /*0x1*/;
    // 004f1d37  833dcc43560000         +cmp dword ptr [0x5643cc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5653452) /* 0x5643cc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f1d3e  0f8424010000           -je 0x4f1e68
    if (cpu.flags.zf)
    {
        return sub_4f1e68(app, cpu);
    }
L_entry_0x004f1d44:
    // 004f1d44  6801000080             -push 0x80000001
    app->getMemory<x86::reg32>(cpu.esp-4) = 2147483649 /*0x80000001*/;
    cpu.esp -= 4;
    // 004f1d49  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004f1d4d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f1d4e  e832cd0100             -call 0x50ea85
    cpu.esp -= 4;
    sub_50ea85(app, cpu);
    if (cpu.terminate) return;
    // 004f1d53  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004f1d56  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004f1d59  25000f0000             -and eax, 0xf00
    cpu.eax &= x86::reg32(x86::sreg32(3840 /*0xf00*/));
    // 004f1d5e  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 004f1d61  a398525600             -mov dword ptr [0x565298], eax
    app->getMemory<x86::reg32>(x86::reg32(5657240) /* 0x565298 */) = cpu.eax;
    // 004f1d66  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004f1d69  25f0000000             -and eax, 0xf0
    cpu.eax &= x86::reg32(x86::sreg32(240 /*0xf0*/));
    // 004f1d6e  c1f804                 -sar eax, 4
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (4 /*0x4*/ % 32));
    // 004f1d71  a39c525600             -mov dword ptr [0x56529c], eax
    app->getMemory<x86::reg32>(x86::reg32(5657244) /* 0x56529c */) = cpu.eax;
    // 004f1d76  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004f1d79  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 004f1d7c  8b1d98525600           -mov ebx, dword ptr [0x565298]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5657240) /* 0x565298 */);
    // 004f1d82  a3a0525600             -mov dword ptr [0x5652a0], eax
    app->getMemory<x86::reg32>(x86::reg32(5657248) /* 0x5652a0 */) = cpu.eax;
    // 004f1d87  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f1d89  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004f1d8b  40                     -inc eax
    (cpu.eax)++;
    // 004f1d8c  83fb05                 +cmp ebx, 5
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5 /*0x5*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f1d8f  7c05                   -jl 0x4f1d96
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004f1d96;
    }
    // 004f1d91  a3ac435600             -mov dword ptr [0x5643ac], eax
    app->getMemory<x86::reg32>(x86::reg32(5653420) /* 0x5643ac */) = cpu.eax;
L_0x004f1d96:
    // 004f1d96  83fb06                 +cmp ebx, 6
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(6 /*0x6*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f1d99  7c06                   -jl 0x4f1da1
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004f1da1;
    }
    // 004f1d9b  41                     -inc ecx
    (cpu.ecx)++;
    // 004f1d9c  a3b0435600             -mov dword ptr [0x5643b0], eax
    app->getMemory<x86::reg32>(x86::reg32(5653424) /* 0x5643b0 */) = cpu.eax;
L_0x004f1da1:
    // 004f1da1  f644240b80             +test byte ptr [esp + 0xb], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(11) /* 0xb */) & 128 /*0x80*/));
    // 004f1da6  0f95c0                 -setne al
    cpu.al = !cpu.flags.zf;
    // 004f1da9  a3b8435600             -mov dword ptr [0x5643b8], eax
    app->getMemory<x86::reg32>(x86::reg32(5653432) /* 0x5643b8 */) = cpu.eax;
    // 004f1dae  f644240a80             +test byte ptr [esp + 0xa], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(10) /* 0xa */) & 128 /*0x80*/));
    // 004f1db3  0f95c0                 -setne al
    cpu.al = !cpu.flags.zf;
    // 004f1db6  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004f1db8  a3b4435600             -mov dword ptr [0x5643b4], eax
    app->getMemory<x86::reg32>(x86::reg32(5653428) /* 0x5643b4 */) = cpu.eax;
    // 004f1dbd  f644240810             +test byte ptr [esp + 8], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */) & 16 /*0x10*/));
    // 004f1dc2  0f95c0                 -setne al
    cpu.al = !cpu.flags.zf;
    // 004f1dc5  a3bc435600             -mov dword ptr [0x5643bc], eax
    app->getMemory<x86::reg32>(x86::reg32(5653436) /* 0x5643bc */) = cpu.eax;
    // 004f1dca  f644240980             +test byte ptr [esp + 9], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(9) /* 0x9 */) & 128 /*0x80*/));
    // 004f1dcf  0f95c0                 -setne al
    cpu.al = !cpu.flags.zf;
    // 004f1dd2  a3c0435600             -mov dword ptr [0x5643c0], eax
    app->getMemory<x86::reg32>(x86::reg32(5653440) /* 0x5643c0 */) = cpu.eax;
    // 004f1dd7  f644240b02             +test byte ptr [esp + 0xb], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(11) /* 0xb */) & 2 /*0x2*/));
    // 004f1ddc  0f95c0                 -setne al
    cpu.al = !cpu.flags.zf;
    // 004f1ddf  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004f1de1  f644240b04             +test byte ptr [esp + 0xb], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(11) /* 0xb */) & 4 /*0x4*/));
    // 004f1de6  0f95c0                 -setne al
    cpu.al = !cpu.flags.zf;
    // 004f1de9  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004f1deb  f644240c01             +test byte ptr [esp + 0xc], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */) & 1 /*0x1*/));
    // 004f1df0  0f95c0                 -setne al
    cpu.al = !cpu.flags.zf;
    // 004f1df3  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004f1df5  890da4525600           -mov dword ptr [0x5652a4], ecx
    app->getMemory<x86::reg32>(x86::reg32(5657252) /* 0x5652a4 */) = cpu.ecx;
    // 004f1dfb  833dac43560000         +cmp dword ptr [0x5643ac], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5653420) /* 0x5643ac */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f1e02  750a                   -jne 0x4f1e0e
    if (!cpu.flags.zf)
    {
        goto L_0x004f1e0e;
    }
    // 004f1e04  b831d25300             -mov eax, 0x53d231
    cpu.eax = 5493297 /*0x53d231*/;
    // 004f1e09  e81a39fcff             -call 0x4b5728
    cpu.esp -= 4;
    sub_4b5728(app, cpu);
    if (cpu.terminate) return;
L_0x004f1e0e:
    // 004f1e0e  e9fdfeffff             -jmp 0x4f1d10
    goto L_0x004f1d10;
}

/* align: skip  */
void Application::sub_4f1d37(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004f1d37;
    // 004f1c70  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f1c71  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f1c72  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f1c73  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f1c74  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f1c75  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004f1c78  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004f1c7a  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 004f1c7c  8915a0525600           -mov dword ptr [0x5652a0], edx
    app->getMemory<x86::reg32>(x86::reg32(5657248) /* 0x5652a0 */) = cpu.edx;
    // 004f1c82  89159c525600           -mov dword ptr [0x56529c], edx
    app->getMemory<x86::reg32>(x86::reg32(5657244) /* 0x56529c */) = cpu.edx;
    // 004f1c88  891598525600           -mov dword ptr [0x565298], edx
    app->getMemory<x86::reg32>(x86::reg32(5657240) /* 0x565298 */) = cpu.edx;
    // 004f1c8e  8915cc435600           -mov dword ptr [0x5643cc], edx
    app->getMemory<x86::reg32>(x86::reg32(5653452) /* 0x5643cc */) = cpu.edx;
    // 004f1c94  8915c8435600           -mov dword ptr [0x5643c8], edx
    app->getMemory<x86::reg32>(x86::reg32(5653448) /* 0x5643c8 */) = cpu.edx;
    // 004f1c9a  8915c4435600           -mov dword ptr [0x5643c4], edx
    app->getMemory<x86::reg32>(x86::reg32(5653444) /* 0x5643c4 */) = cpu.edx;
    // 004f1ca0  8915c0435600           -mov dword ptr [0x5643c0], edx
    app->getMemory<x86::reg32>(x86::reg32(5653440) /* 0x5643c0 */) = cpu.edx;
    // 004f1ca6  8915bc435600           -mov dword ptr [0x5643bc], edx
    app->getMemory<x86::reg32>(x86::reg32(5653436) /* 0x5643bc */) = cpu.edx;
    // 004f1cac  8915b4435600           -mov dword ptr [0x5643b4], edx
    app->getMemory<x86::reg32>(x86::reg32(5653428) /* 0x5643b4 */) = cpu.edx;
    // 004f1cb2  8915b0435600           -mov dword ptr [0x5643b0], edx
    app->getMemory<x86::reg32>(x86::reg32(5653424) /* 0x5643b0 */) = cpu.edx;
    // 004f1cb8  8915ac435600           -mov dword ptr [0x5643ac], edx
    app->getMemory<x86::reg32>(x86::reg32(5653420) /* 0x5643ac */) = cpu.edx;
    // 004f1cbe  882588525600           -mov byte ptr [0x565288], ah
    app->getMemory<x86::reg8>(x86::reg32(5657224) /* 0x565288 */) = cpu.ah;
    // 004f1cc4  e89fcd0100             -call 0x50ea68
    cpu.esp -= 4;
    sub_50ea68(app, cpu);
    if (cpu.terminate) return;
    // 004f1cc9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f1ccb  0f84ba010000           -je 0x4f1e8b
    if (cpu.flags.zf)
    {
        return sub_4f1e8b(app, cpu);
    }
    // 004f1cd1  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004f1cd3  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004f1cd5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f1cd6  8d742408               -lea esi, [esp + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004f1cda  30db                   -xor bl, bl
    cpu.bl ^= x86::reg8(x86::sreg8(cpu.bl));
    // 004f1cdc  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f1cdd  897c2418               -mov dword ptr [esp + 0x18], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edi;
    // 004f1ce1  bf88525600             -mov edi, 0x565288
    cpu.edi = 5657224 /*0x565288*/;
    // 004f1ce6  e89acd0100             -call 0x50ea85
    cpu.esp -= 4;
    sub_50ea85(app, cpu);
    if (cpu.terminate) return;
    // 004f1ceb  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004f1cee  b90c000000             -mov ecx, 0xc
    cpu.ecx = 12 /*0xc*/;
    // 004f1cf3  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 004f1cf6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f1cf7  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004f1cf9  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004f1cfc  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004f1cfe  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 004f1d00  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 004f1d03  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004f1d05  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f1d06  881d94525600           -mov byte ptr [0x565294], bl
    app->getMemory<x86::reg8>(x86::reg32(5657236) /* 0x565294 */) = cpu.bl;
    // 004f1d0c  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004f1d0e  7f09                   -jg 0x4f1d19
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004f1d19;
    }
L_0x004f1d10:
    // 004f1d10  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004f1d13  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f1d14  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f1d15  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f1d16  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f1d17  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f1d18  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f1d19:
    // 004f1d19  ba78c95400             -mov edx, 0x54c978
    cpu.edx = 5556600 /*0x54c978*/;
    // 004f1d1e  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004f1d20  e8ebc5ffff             -call 0x4ee310
    cpu.esp -= 4;
    sub_4ee310(app, cpu);
    if (cpu.terminate) return;
    // 004f1d25  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f1d27  0f85f9000000           -jne 0x4f1e26
    if (!cpu.flags.zf)
    {
        return sub_4f1e26(app, cpu);
    }
    // 004f1d2d  c705c443560001000000   -mov dword ptr [0x5643c4], 1
    app->getMemory<x86::reg32>(x86::reg32(5653444) /* 0x5643c4 */) = 1 /*0x1*/;
L_entry_0x004f1d37:
    // 004f1d37  833dcc43560000         +cmp dword ptr [0x5643cc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5653452) /* 0x5643cc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f1d3e  0f8424010000           -je 0x4f1e68
    if (cpu.flags.zf)
    {
        return sub_4f1e68(app, cpu);
    }
    // 004f1d44  6801000080             -push 0x80000001
    app->getMemory<x86::reg32>(cpu.esp-4) = 2147483649 /*0x80000001*/;
    cpu.esp -= 4;
    // 004f1d49  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004f1d4d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f1d4e  e832cd0100             -call 0x50ea85
    cpu.esp -= 4;
    sub_50ea85(app, cpu);
    if (cpu.terminate) return;
    // 004f1d53  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004f1d56  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004f1d59  25000f0000             -and eax, 0xf00
    cpu.eax &= x86::reg32(x86::sreg32(3840 /*0xf00*/));
    // 004f1d5e  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 004f1d61  a398525600             -mov dword ptr [0x565298], eax
    app->getMemory<x86::reg32>(x86::reg32(5657240) /* 0x565298 */) = cpu.eax;
    // 004f1d66  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004f1d69  25f0000000             -and eax, 0xf0
    cpu.eax &= x86::reg32(x86::sreg32(240 /*0xf0*/));
    // 004f1d6e  c1f804                 -sar eax, 4
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (4 /*0x4*/ % 32));
    // 004f1d71  a39c525600             -mov dword ptr [0x56529c], eax
    app->getMemory<x86::reg32>(x86::reg32(5657244) /* 0x56529c */) = cpu.eax;
    // 004f1d76  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004f1d79  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 004f1d7c  8b1d98525600           -mov ebx, dword ptr [0x565298]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5657240) /* 0x565298 */);
    // 004f1d82  a3a0525600             -mov dword ptr [0x5652a0], eax
    app->getMemory<x86::reg32>(x86::reg32(5657248) /* 0x5652a0 */) = cpu.eax;
    // 004f1d87  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f1d89  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004f1d8b  40                     -inc eax
    (cpu.eax)++;
    // 004f1d8c  83fb05                 +cmp ebx, 5
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5 /*0x5*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f1d8f  7c05                   -jl 0x4f1d96
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004f1d96;
    }
    // 004f1d91  a3ac435600             -mov dword ptr [0x5643ac], eax
    app->getMemory<x86::reg32>(x86::reg32(5653420) /* 0x5643ac */) = cpu.eax;
L_0x004f1d96:
    // 004f1d96  83fb06                 +cmp ebx, 6
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(6 /*0x6*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f1d99  7c06                   -jl 0x4f1da1
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004f1da1;
    }
    // 004f1d9b  41                     -inc ecx
    (cpu.ecx)++;
    // 004f1d9c  a3b0435600             -mov dword ptr [0x5643b0], eax
    app->getMemory<x86::reg32>(x86::reg32(5653424) /* 0x5643b0 */) = cpu.eax;
L_0x004f1da1:
    // 004f1da1  f644240b80             +test byte ptr [esp + 0xb], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(11) /* 0xb */) & 128 /*0x80*/));
    // 004f1da6  0f95c0                 -setne al
    cpu.al = !cpu.flags.zf;
    // 004f1da9  a3b8435600             -mov dword ptr [0x5643b8], eax
    app->getMemory<x86::reg32>(x86::reg32(5653432) /* 0x5643b8 */) = cpu.eax;
    // 004f1dae  f644240a80             +test byte ptr [esp + 0xa], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(10) /* 0xa */) & 128 /*0x80*/));
    // 004f1db3  0f95c0                 -setne al
    cpu.al = !cpu.flags.zf;
    // 004f1db6  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004f1db8  a3b4435600             -mov dword ptr [0x5643b4], eax
    app->getMemory<x86::reg32>(x86::reg32(5653428) /* 0x5643b4 */) = cpu.eax;
    // 004f1dbd  f644240810             +test byte ptr [esp + 8], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */) & 16 /*0x10*/));
    // 004f1dc2  0f95c0                 -setne al
    cpu.al = !cpu.flags.zf;
    // 004f1dc5  a3bc435600             -mov dword ptr [0x5643bc], eax
    app->getMemory<x86::reg32>(x86::reg32(5653436) /* 0x5643bc */) = cpu.eax;
    // 004f1dca  f644240980             +test byte ptr [esp + 9], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(9) /* 0x9 */) & 128 /*0x80*/));
    // 004f1dcf  0f95c0                 -setne al
    cpu.al = !cpu.flags.zf;
    // 004f1dd2  a3c0435600             -mov dword ptr [0x5643c0], eax
    app->getMemory<x86::reg32>(x86::reg32(5653440) /* 0x5643c0 */) = cpu.eax;
    // 004f1dd7  f644240b02             +test byte ptr [esp + 0xb], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(11) /* 0xb */) & 2 /*0x2*/));
    // 004f1ddc  0f95c0                 -setne al
    cpu.al = !cpu.flags.zf;
    // 004f1ddf  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004f1de1  f644240b04             +test byte ptr [esp + 0xb], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(11) /* 0xb */) & 4 /*0x4*/));
    // 004f1de6  0f95c0                 -setne al
    cpu.al = !cpu.flags.zf;
    // 004f1de9  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004f1deb  f644240c01             +test byte ptr [esp + 0xc], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */) & 1 /*0x1*/));
    // 004f1df0  0f95c0                 -setne al
    cpu.al = !cpu.flags.zf;
    // 004f1df3  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004f1df5  890da4525600           -mov dword ptr [0x5652a4], ecx
    app->getMemory<x86::reg32>(x86::reg32(5657252) /* 0x5652a4 */) = cpu.ecx;
    // 004f1dfb  833dac43560000         +cmp dword ptr [0x5643ac], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5653420) /* 0x5643ac */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f1e02  750a                   -jne 0x4f1e0e
    if (!cpu.flags.zf)
    {
        goto L_0x004f1e0e;
    }
    // 004f1e04  b831d25300             -mov eax, 0x53d231
    cpu.eax = 5493297 /*0x53d231*/;
    // 004f1e09  e81a39fcff             -call 0x4b5728
    cpu.esp -= 4;
    sub_4b5728(app, cpu);
    if (cpu.terminate) return;
L_0x004f1e0e:
    // 004f1e0e  e9fdfeffff             -jmp 0x4f1d10
    goto L_0x004f1d10;
}

/* align: skip 0x90 */
void Application::sub_4f1e14(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f1e14  90                     -nop 
    ;
    // 004f1e15  90                     -nop 
    ;
    // 004f1e16  90                     -nop 
    ;
    // 004f1e17  90                     -nop 
    ;
    // 004f1e18  90                     -nop 
    ;
    // 004f1e19  90                     -nop 
    ;
    // 004f1e1a  90                     -nop 
    ;
    // 004f1e1b  90                     -nop 
    ;
    // 004f1e1c  90                     -nop 
    ;
    // 004f1e1d  90                     -nop 
    ;
    // 004f1e1e  90                     -nop 
    ;
    // 004f1e1f  90                     -nop 
    ;
    // 004f1e20  90                     -nop 
    ;
    // 004f1e21  90                     -nop 
    ;
    // 004f1e22  90                     -nop 
    ;
    // 004f1e23  90                     -nop 
    ;
    // 004f1e24  90                     -nop 
    ;
    // 004f1e25  90                     -nop 
    ;
    // 004f1e26  ba88c95400             -mov edx, 0x54c988
    cpu.edx = 5556616 /*0x54c988*/;
    // 004f1e2b  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004f1e2d  e8dec4ffff             -call 0x4ee310
    cpu.esp -= 4;
    sub_4ee310(app, cpu);
    if (cpu.terminate) return;
    // 004f1e32  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f1e34  750f                   -jne 0x4f1e45
    if (!cpu.flags.zf)
    {
        goto L_0x004f1e45;
    }
    // 004f1e36  c705cc43560001000000   -mov dword ptr [0x5643cc], 1
    app->getMemory<x86::reg32>(x86::reg32(5653452) /* 0x5643cc */) = 1 /*0x1*/;
    // 004f1e40  e9fffeffff             -jmp 0x4f1d44
    return sub_4f1d44(app, cpu);
L_0x004f1e45:
    // 004f1e45  ba98c95400             -mov edx, 0x54c998
    cpu.edx = 5556632 /*0x54c998*/;
    // 004f1e4a  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004f1e4c  e8bfc4ffff             -call 0x4ee310
    cpu.esp -= 4;
    sub_4ee310(app, cpu);
    if (cpu.terminate) return;
    // 004f1e51  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f1e53  0f85defeffff           -jne 0x4f1d37
    if (!cpu.flags.zf)
    {
        return sub_4f1d37(app, cpu);
    }
    // 004f1e59  c705c843560001000000   -mov dword ptr [0x5643c8], 1
    app->getMemory<x86::reg32>(x86::reg32(5653448) /* 0x5643c8 */) = 1 /*0x1*/;
    // 004f1e63  e9cffeffff             -jmp 0x4f1d37
    return sub_4f1d37(app, cpu);
}

/* align: skip  */
void Application::sub_4f1e26(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004f1e26;
    // 004f1e14  90                     -nop 
    ;
    // 004f1e15  90                     -nop 
    ;
    // 004f1e16  90                     -nop 
    ;
    // 004f1e17  90                     -nop 
    ;
    // 004f1e18  90                     -nop 
    ;
    // 004f1e19  90                     -nop 
    ;
    // 004f1e1a  90                     -nop 
    ;
    // 004f1e1b  90                     -nop 
    ;
    // 004f1e1c  90                     -nop 
    ;
    // 004f1e1d  90                     -nop 
    ;
    // 004f1e1e  90                     -nop 
    ;
    // 004f1e1f  90                     -nop 
    ;
    // 004f1e20  90                     -nop 
    ;
    // 004f1e21  90                     -nop 
    ;
    // 004f1e22  90                     -nop 
    ;
    // 004f1e23  90                     -nop 
    ;
    // 004f1e24  90                     -nop 
    ;
    // 004f1e25  90                     -nop 
    ;
L_entry_0x004f1e26:
    // 004f1e26  ba88c95400             -mov edx, 0x54c988
    cpu.edx = 5556616 /*0x54c988*/;
    // 004f1e2b  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004f1e2d  e8dec4ffff             -call 0x4ee310
    cpu.esp -= 4;
    sub_4ee310(app, cpu);
    if (cpu.terminate) return;
    // 004f1e32  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f1e34  750f                   -jne 0x4f1e45
    if (!cpu.flags.zf)
    {
        goto L_0x004f1e45;
    }
    // 004f1e36  c705cc43560001000000   -mov dword ptr [0x5643cc], 1
    app->getMemory<x86::reg32>(x86::reg32(5653452) /* 0x5643cc */) = 1 /*0x1*/;
    // 004f1e40  e9fffeffff             -jmp 0x4f1d44
    return sub_4f1d44(app, cpu);
L_0x004f1e45:
    // 004f1e45  ba98c95400             -mov edx, 0x54c998
    cpu.edx = 5556632 /*0x54c998*/;
    // 004f1e4a  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004f1e4c  e8bfc4ffff             -call 0x4ee310
    cpu.esp -= 4;
    sub_4ee310(app, cpu);
    if (cpu.terminate) return;
    // 004f1e51  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f1e53  0f85defeffff           -jne 0x4f1d37
    if (!cpu.flags.zf)
    {
        return sub_4f1d37(app, cpu);
    }
    // 004f1e59  c705c843560001000000   -mov dword ptr [0x5643c8], 1
    app->getMemory<x86::reg32>(x86::reg32(5653448) /* 0x5643c8 */) = 1 /*0x1*/;
    // 004f1e63  e9cffeffff             -jmp 0x4f1d37
    return sub_4f1d37(app, cpu);
}

/* align: skip  */
void Application::sub_4f1e68(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f1e68  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004f1e6a  e9dafeffff             -jmp 0x4f1d49
    return sub_4f1d49(app, cpu);
}

/* align: skip 0x90 */
void Application::sub_4f1e70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f1e70  90                     -nop 
    ;
    // 004f1e71  90                     -nop 
    ;
    // 004f1e72  90                     -nop 
    ;
    // 004f1e73  90                     -nop 
    ;
    // 004f1e74  90                     -nop 
    ;
    // 004f1e75  90                     -nop 
    ;
    // 004f1e76  90                     -nop 
    ;
    // 004f1e77  90                     -nop 
    ;
    // 004f1e78  90                     -nop 
    ;
    // 004f1e79  90                     -nop 
    ;
    // 004f1e7a  90                     -nop 
    ;
    // 004f1e7b  90                     -nop 
    ;
    // 004f1e7c  90                     -nop 
    ;
    // 004f1e7d  90                     -nop 
    ;
    // 004f1e7e  90                     -nop 
    ;
    // 004f1e7f  90                     -nop 
    ;
    // 004f1e80  90                     -nop 
    ;
    // 004f1e81  90                     -nop 
    ;
    // 004f1e82  90                     -nop 
    ;
    // 004f1e83  90                     -nop 
    ;
    // 004f1e84  90                     -nop 
    ;
    // 004f1e85  90                     -nop 
    ;
    // 004f1e86  90                     -nop 
    ;
    // 004f1e87  90                     -nop 
    ;
    // 004f1e88  90                     -nop 
    ;
    // 004f1e89  90                     -nop 
    ;
    // 004f1e8a  90                     -nop 
    ;
    // 004f1e8b  e817cc0100             -call 0x50eaa7
    cpu.esp -= 4;
    sub_50eaa7(app, cpu);
    if (cpu.terminate) return;
    // 004f1e90  a3c8435600             -mov dword ptr [0x5643c8], eax
    app->getMemory<x86::reg32>(x86::reg32(5653448) /* 0x5643c8 */) = cpu.eax;
    // 004f1e95  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004f1e98  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f1e99  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f1e9a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f1e9b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f1e9c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f1e9d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4f1e8b(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004f1e8b;
    // 004f1e70  90                     -nop 
    ;
    // 004f1e71  90                     -nop 
    ;
    // 004f1e72  90                     -nop 
    ;
    // 004f1e73  90                     -nop 
    ;
    // 004f1e74  90                     -nop 
    ;
    // 004f1e75  90                     -nop 
    ;
    // 004f1e76  90                     -nop 
    ;
    // 004f1e77  90                     -nop 
    ;
    // 004f1e78  90                     -nop 
    ;
    // 004f1e79  90                     -nop 
    ;
    // 004f1e7a  90                     -nop 
    ;
    // 004f1e7b  90                     -nop 
    ;
    // 004f1e7c  90                     -nop 
    ;
    // 004f1e7d  90                     -nop 
    ;
    // 004f1e7e  90                     -nop 
    ;
    // 004f1e7f  90                     -nop 
    ;
    // 004f1e80  90                     -nop 
    ;
    // 004f1e81  90                     -nop 
    ;
    // 004f1e82  90                     -nop 
    ;
    // 004f1e83  90                     -nop 
    ;
    // 004f1e84  90                     -nop 
    ;
    // 004f1e85  90                     -nop 
    ;
    // 004f1e86  90                     -nop 
    ;
    // 004f1e87  90                     -nop 
    ;
    // 004f1e88  90                     -nop 
    ;
    // 004f1e89  90                     -nop 
    ;
    // 004f1e8a  90                     -nop 
    ;
L_entry_0x004f1e8b:
    // 004f1e8b  e817cc0100             -call 0x50eaa7
    cpu.esp -= 4;
    sub_50eaa7(app, cpu);
    if (cpu.terminate) return;
    // 004f1e90  a3c8435600             -mov dword ptr [0x5643c8], eax
    app->getMemory<x86::reg32>(x86::reg32(5653448) /* 0x5643c8 */) = cpu.eax;
    // 004f1e95  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004f1e98  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f1e99  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f1e9a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f1e9b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f1e9c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f1e9d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_4f1ea0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f1ea0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f1ea1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f1ea2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f1ea3  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004f1ea5  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f1ea6  ff154c455300           -call dword ptr [0x53454c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457228) /* 0x53454c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f1eac  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f1eae  7507                   -jne 0x4f1eb7
    if (!cpu.flags.zf)
    {
        goto L_0x004f1eb7;
    }
    // 004f1eb0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f1eb1  ff158c455300           -call dword ptr [0x53458c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457292) /* 0x53458c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004f1eb7:
    // 004f1eb7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f1eb8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f1eb9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f1eba  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4f1ebc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f1ebc  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f1ebd  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f1ebe  e8ddffffff             -call 0x4f1ea0
    cpu.esp -= 4;
    sub_4f1ea0(app, cpu);
    if (cpu.terminate) return;
    // 004f1ec3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f1ec5  7408                   -je 0x4f1ecf
    if (cpu.flags.zf)
    {
        goto L_0x004f1ecf;
    }
    // 004f1ec7  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f1ec8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f1ec9  ff1558455300           -call dword ptr [0x534558]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457240) /* 0x534558 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004f1ecf:
    // 004f1ecf  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f1ed0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f1ed1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4f1ed2(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f1ed2  90                     -nop 
    ;
    // 004f1ed3  90                     -nop 
    ;
    // 004f1ed4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f1ed5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f1ed6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f1ed7  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004f1ed9  b88cf75300             -mov eax, 0x53f78c
    cpu.eax = 5502860 /*0x53f78c*/;
    // 004f1ede  bab4f75300             -mov edx, 0x53f7b4
    cpu.edx = 5502900 /*0x53f7b4*/;
    // 004f1ee3  e8d4ffffff             -call 0x4f1ebc
    cpu.esp -= 4;
    sub_4f1ebc(app, cpu);
    if (cpu.terminate) return;
    // 004f1ee8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f1eea  7403                   -je 0x4f1eef
    if (cpu.flags.zf)
    {
        goto L_0x004f1eef;
    }
    // 004f1eec  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f1eed  ffd0                   -call eax
    cpu.ip = cpu.eax;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004f1eef:
    // 004f1eef  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f1ef0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f1ef1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f1ef2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4f1ed4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004f1ed4;
    // 004f1ed2  90                     -nop 
    ;
    // 004f1ed3  90                     -nop 
    ;
L_entry_0x004f1ed4:
    // 004f1ed4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f1ed5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f1ed6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f1ed7  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004f1ed9  b88cf75300             -mov eax, 0x53f78c
    cpu.eax = 5502860 /*0x53f78c*/;
    // 004f1ede  bab4f75300             -mov edx, 0x53f7b4
    cpu.edx = 5502900 /*0x53f7b4*/;
    // 004f1ee3  e8d4ffffff             -call 0x4f1ebc
    cpu.esp -= 4;
    sub_4f1ebc(app, cpu);
    if (cpu.terminate) return;
    // 004f1ee8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f1eea  7403                   -je 0x4f1eef
    if (cpu.flags.zf)
    {
        goto L_0x004f1eef;
    }
    // 004f1eec  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f1eed  ffd0                   -call eax
    cpu.ip = cpu.eax;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004f1eef:
    // 004f1eef  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f1ef0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f1ef1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f1ef2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4f1ef4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f1ef4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f1ef5  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f1ef6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f1ef7  6a08                   -push 8
    app->getMemory<x86::reg32>(cpu.esp-4) = 8 /*0x8*/;
    cpu.esp -= 4;
    // 004f1ef9  eb06                   -jmp 0x4f1f01
    return sub_4f1f01(app, cpu);
}

/* align: skip 0x90 */
void Application::sub_4f1efc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f1efc  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f1efd  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f1efe  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f1eff  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f1f01  ff35403d9f00           -push dword ptr [0x9f3d40]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(10435904) /* 0x9f3d40 */);
    cpu.esp -= 4;
    // 004f1f07  ff1544465300           -call dword ptr [0x534644]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457476) /* 0x534644 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f1f0d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f1f0e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f1f0f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4f1f01(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004f1f01;
    // 004f1efc  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f1efd  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f1efe  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f1eff  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
L_entry_0x004f1f01:
    // 004f1f01  ff35403d9f00           -push dword ptr [0x9f3d40]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(10435904) /* 0x9f3d40 */);
    cpu.esp -= 4;
    // 004f1f07  ff1544465300           -call dword ptr [0x534644]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457476) /* 0x534644 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f1f0d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f1f0e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f1f0f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4f1f10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f1f10  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f1f11  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f1f12  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f1f13  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f1f14  6a08                   -push 8
    app->getMemory<x86::reg32>(cpu.esp-4) = 8 /*0x8*/;
    cpu.esp -= 4;
    // 004f1f16  eb06                   -jmp 0x4f1f1e
    goto L_0x004f1f1e;
    // 004f1f18  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f1f19  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f1f1a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f1f1b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f1f1c  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
L_0x004f1f1e:
    // 004f1f1e  ff35403d9f00           -push dword ptr [0x9f3d40]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(10435904) /* 0x9f3d40 */);
    cpu.esp -= 4;
    // 004f1f24  ff1518455300           -call dword ptr [0x534518]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457176) /* 0x534518 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f1f2a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f1f2b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f1f2c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4f1f2e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f1f2e  90                     -nop 
    ;
    // 004f1f2f  90                     -nop 
    ;
    // 004f1f30  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f1f31  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f1f32  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f1f33  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f1f35  ff35403d9f00           -push dword ptr [0x9f3d40]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(10435904) /* 0x9f3d40 */);
    cpu.esp -= 4;
    // 004f1f3b  ff1548465300           -call dword ptr [0x534648]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457480) /* 0x534648 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f1f41  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f1f42  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f1f43  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4f1f30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004f1f30;
    // 004f1f2e  90                     -nop 
    ;
    // 004f1f2f  90                     -nop 
    ;
L_entry_0x004f1f30:
    // 004f1f30  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f1f31  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f1f32  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f1f33  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f1f35  ff35403d9f00           -push dword ptr [0x9f3d40]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(10435904) /* 0x9f3d40 */);
    cpu.esp -= 4;
    // 004f1f3b  ff1548465300           -call dword ptr [0x534648]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457480) /* 0x534648 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f1f41  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f1f42  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f1f43  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4f1f44(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f1f44  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f1f45  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f1f46  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f1f47  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f1f49  ff35403d9f00           -push dword ptr [0x9f3d40]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(10435904) /* 0x9f3d40 */);
    cpu.esp -= 4;
    // 004f1f4f  ff1528455300           -call dword ptr [0x534528]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457192) /* 0x534528 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f1f55  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f1f56  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f1f57  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4f1f58(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f1f58  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f1f59  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f1f5a  6a0a                   -push 0xa
    app->getMemory<x86::reg32>(cpu.esp-4) = 10 /*0xa*/;
    cpu.esp -= 4;
    // 004f1f5c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f1f5d  ff35483d9f00           -push dword ptr [0x9f3d48]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(10435912) /* 0x9f3d48 */);
    cpu.esp -= 4;
    // 004f1f63  ff153c455300           -call dword ptr [0x53453c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457212) /* 0x53453c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f1f69  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f1f6b  7418                   -je 0x4f1f85
    if (cpu.flags.zf)
    {
        goto L_0x004f1f85;
    }
    // 004f1f6d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f1f6e  ff35483d9f00           -push dword ptr [0x9f3d48]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(10435912) /* 0x9f3d48 */);
    cpu.esp -= 4;
    // 004f1f74  ff1540455300           -call dword ptr [0x534540]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457216) /* 0x534540 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f1f7a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f1f7c  7407                   -je 0x4f1f85
    if (cpu.flags.zf)
    {
        goto L_0x004f1f85;
    }
    // 004f1f7e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f1f7f  ff1570455300           -call dword ptr [0x534570]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457264) /* 0x534570 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004f1f85:
    // 004f1f85  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f1f86  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f1f87  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4f1f88(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f1f88  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f1f89  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f1f8a  6a0a                   -push 0xa
    app->getMemory<x86::reg32>(cpu.esp-4) = 10 /*0xa*/;
    cpu.esp -= 4;
    // 004f1f8c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f1f8d  ff35483d9f00           -push dword ptr [0x9f3d48]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(10435912) /* 0x9f3d48 */);
    cpu.esp -= 4;
    // 004f1f93  ff153c455300           -call dword ptr [0x53453c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457212) /* 0x53453c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f1f99  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f1f9b  740d                   -je 0x4f1faa
    if (cpu.flags.zf)
    {
        goto L_0x004f1faa;
    }
    // 004f1f9d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f1f9e  ff35483d9f00           -push dword ptr [0x9f3d48]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(10435912) /* 0x9f3d48 */);
    cpu.esp -= 4;
    // 004f1fa4  ff1578455300           -call dword ptr [0x534578]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457272) /* 0x534578 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004f1faa:
    // 004f1faa  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f1fab  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f1fac  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4f1fae(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f1fae  90                     -nop 
    ;
    // 004f1faf  90                     -nop 
    ;
    // 004f1fb0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f1fb1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f1fb2  e8a1ffffff             -call 0x4f1f58
    cpu.esp -= 4;
    sub_4f1f58(app, cpu);
    if (cpu.terminate) return;
    // 004f1fb7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f1fb9  740b                   -je 0x4f1fc6
    if (cpu.flags.zf)
    {
        goto L_0x004f1fc6;
    }
    // 004f1fbb  6a07                   -push 7
    app->getMemory<x86::reg32>(cpu.esp-4) = 7 /*0x7*/;
    cpu.esp -= 4;
    // 004f1fbd  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f1fbf  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f1fc0  ff1568465300           -call dword ptr [0x534668]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457512) /* 0x534668 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004f1fc6:
    // 004f1fc6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f1fc7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f1fc8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4f1fb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004f1fb0;
    // 004f1fae  90                     -nop 
    ;
    // 004f1faf  90                     -nop 
    ;
L_entry_0x004f1fb0:
    // 004f1fb0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f1fb1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f1fb2  e8a1ffffff             -call 0x4f1f58
    cpu.esp -= 4;
    sub_4f1f58(app, cpu);
    if (cpu.terminate) return;
    // 004f1fb7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f1fb9  740b                   -je 0x4f1fc6
    if (cpu.flags.zf)
    {
        goto L_0x004f1fc6;
    }
    // 004f1fbb  6a07                   -push 7
    app->getMemory<x86::reg32>(cpu.esp-4) = 7 /*0x7*/;
    cpu.esp -= 4;
    // 004f1fbd  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f1fbf  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f1fc0  ff1568465300           -call dword ptr [0x534668]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457512) /* 0x534668 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004f1fc6:
    // 004f1fc6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f1fc7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f1fc8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4f1fca(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f1fca  90                     -nop 
    ;
    // 004f1fcb  90                     -nop 
    ;
    // 004f1fcc  b010                   -mov al, 0x10
    cpu.al = 16 /*0x10*/;
    // 004f1fce  eb06                   -jmp 0x4f1fd6
    return sub_4f1fd6(app, cpu);
}

/* align: skip  */
void Application::sub_4f1fcc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004f1fcc;
    // 004f1fca  90                     -nop 
    ;
    // 004f1fcb  90                     -nop 
    ;
L_entry_0x004f1fcc:
    // 004f1fcc  b010                   -mov al, 0x10
    cpu.al = 16 /*0x10*/;
    // 004f1fce  eb06                   -jmp 0x4f1fd6
    return sub_4f1fd6(app, cpu);
}

/* align: skip  */
void Application::sub_4f1fd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f1fd0  b011                   -mov al, 0x11
    cpu.al = 17 /*0x11*/;
    // 004f1fd2  eb02                   -jmp 0x4f1fd6
    return sub_4f1fd6(app, cpu);
}

/* align: skip  */
void Application::sub_4f1fd4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f1fd4  b012                   -mov al, 0x12
    cpu.al = 18 /*0x12*/;
    // 004f1fd6  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f1fd7  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f1fd8  0fb6c0                 -movzx eax, al
    cpu.eax = x86::reg32(cpu.al);
    // 004f1fdb  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f1fdc  ff1538475300           -call dword ptr [0x534738]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457720) /* 0x534738 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f1fe2  6685c0                 +test ax, ax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.ax & cpu.ax));
    // 004f1fe5  0f9cc0                 -setl al
    NFS2_ASSERT(false);
    // 004f1fe8  0fb6c0                 -movzx eax, al
    cpu.eax = x86::reg32(cpu.al);
    // 004f1feb  85c0                   -test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f1fed  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f1fee  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f1fef  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4f1fd6(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004f1fd6;
    // 004f1fd4  b012                   -mov al, 0x12
    cpu.al = 18 /*0x12*/;
L_entry_0x004f1fd6:
    // 004f1fd6  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f1fd7  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f1fd8  0fb6c0                 -movzx eax, al
    cpu.eax = x86::reg32(cpu.al);
    // 004f1fdb  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f1fdc  ff1538475300           -call dword ptr [0x534738]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457720) /* 0x534738 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f1fe2  6685c0                 +test ax, ax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.ax & cpu.ax));
    // 004f1fe5  0f9cc0                 -setl al
    NFS2_ASSERT(false);
    // 004f1fe8  0fb6c0                 -movzx eax, al
    cpu.eax = x86::reg32(cpu.al);
    // 004f1feb  85c0                   -test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f1fed  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f1fee  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f1fef  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4f1ff0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f1ff0  90                     -nop 
    ;
    // 004f1ff1  90                     -nop 
    ;
    // 004f1ff2  90                     -nop 
    ;
    // 004f1ff3  90                     -nop 
    ;
    // 004f1ff4  90                     -nop 
    ;
    // 004f1ff5  90                     -nop 
    ;
    // 004f1ff6  90                     -nop 
    ;
    // 004f1ff7  90                     -nop 
    ;
    // 004f1ff8  90                     -nop 
    ;
    // 004f1ff9  90                     -nop 
    ;
    // 004f1ffa  90                     -nop 
    ;
    // 004f1ffb  90                     -nop 
    ;
    // 004f1ffc  90                     -nop 
    ;
    // 004f1ffd  90                     -nop 
    ;
    // 004f1ffe  90                     -nop 
    ;
    // 004f1fff  90                     -nop 
    ;
    // 004f2000  90                     -nop 
    ;
    // 004f2001  90                     -nop 
    ;
    // 004f2002  90                     -nop 
    ;
    // 004f2003  90                     -nop 
    ;
    // 004f2004  90                     -nop 
    ;
    // 004f2005  90                     -nop 
    ;
    // 004f2006  90                     -nop 
    ;
    // 004f2007  90                     -nop 
    ;
    // 004f2008  90                     -nop 
    ;
    // 004f2009  90                     -nop 
    ;
    // 004f200a  90                     -nop 
    ;
    // 004f200b  90                     -nop 
    ;
    // 004f200c  90                     -nop 
    ;
    // 004f200d  90                     -nop 
    ;
    // 004f200e  90                     -nop 
    ;
    // 004f200f  90                     -nop 
    ;
    // 004f2010  90                     -nop 
    ;
    // 004f2011  90                     -nop 
    ;
    // 004f2012  90                     -nop 
    ;
    // 004f2013  90                     -nop 
    ;
    // 004f2014  90                     -nop 
    ;
    // 004f2015  90                     -nop 
    ;
    // 004f2016  90                     -nop 
    ;
    // 004f2017  90                     -nop 
    ;
    // 004f2018  90                     -nop 
    ;
    // 004f2019  90                     -nop 
    ;
    // 004f201a  90                     -nop 
    ;
    // 004f201b  90                     -nop 
    ;
    // 004f201c  90                     -nop 
    ;
    // 004f201d  90                     -nop 
    ;
    // 004f201e  90                     -nop 
    ;
    // 004f201f  90                     -nop 
    ;
    // 004f2020  90                     -nop 
    ;
    // 004f2021  90                     -nop 
    ;
    // 004f2022  90                     -nop 
    ;
    // 004f2023  90                     -nop 
    ;
    // 004f2024  90                     -nop 
    ;
    // 004f2025  90                     -nop 
    ;
    // 004f2026  90                     -nop 
    ;
    // 004f2027  90                     -nop 
    ;
    // 004f2028  90                     -nop 
    ;
    // 004f2029  90                     -nop 
    ;
    // 004f202a  90                     -nop 
    ;
    // 004f202b  90                     -nop 
    ;
    // 004f202c  90                     -nop 
    ;
    // 004f202d  90                     -nop 
    ;
    // 004f202e  90                     -nop 
    ;
    // 004f202f  90                     -nop 
    ;
    // 004f2030  90                     -nop 
    ;
    // 004f2031  90                     -nop 
    ;
    // 004f2032  90                     -nop 
    ;
    // 004f2033  90                     -nop 
    ;
    // 004f2034  90                     -nop 
    ;
    // 004f2035  90                     -nop 
    ;
    // 004f2036  90                     -nop 
    ;
    // 004f2037  90                     -nop 
    ;
    // 004f2038  90                     -nop 
    ;
    // 004f2039  90                     -nop 
    ;
    // 004f203a  90                     -nop 
    ;
    // 004f203b  90                     -nop 
    ;
    // 004f203c  90                     -nop 
    ;
    // 004f203d  90                     -nop 
    ;
    // 004f203e  90                     -nop 
    ;
    // 004f203f  90                     -nop 
    ;
    // 004f2040  90                     -nop 
    ;
    // 004f2041  90                     -nop 
    ;
    // 004f2042  90                     -nop 
    ;
    // 004f2043  90                     -nop 
    ;
    // 004f2044  90                     -nop 
    ;
    // 004f2045  90                     -nop 
    ;
    // 004f2046  90                     -nop 
    ;
    // 004f2047  90                     -nop 
    ;
    // 004f2048  90                     -nop 
    ;
    // 004f2049  90                     -nop 
    ;
    // 004f204a  90                     -nop 
    ;
    // 004f204b  90                     -nop 
    ;
    // 004f204c  90                     -nop 
    ;
    // 004f204d  90                     -nop 
    ;
    // 004f204e  90                     -nop 
    ;
    // 004f204f  90                     -nop 
    ;
    // 004f2050  90                     -nop 
    ;
    // 004f2051  90                     -nop 
    ;
    // 004f2052  90                     -nop 
    ;
    // 004f2053  90                     -nop 
    ;
    // 004f2054  90                     -nop 
    ;
    // 004f2055  90                     -nop 
    ;
    // 004f2056  90                     -nop 
    ;
    // 004f2057  90                     -nop 
    ;
    // 004f2058  90                     -nop 
    ;
    // 004f2059  90                     -nop 
    ;
    // 004f205a  90                     -nop 
    ;
    // 004f205b  90                     -nop 
    ;
    // 004f205c  90                     -nop 
    ;
    // 004f205d  90                     -nop 
    ;
    // 004f205e  90                     -nop 
    ;
    // 004f205f  90                     -nop 
    ;
    // 004f2060  90                     -nop 
    ;
    // 004f2061  90                     -nop 
    ;
    // 004f2062  90                     -nop 
    ;
    // 004f2063  90                     -nop 
    ;
    // 004f2064  90                     -nop 
    ;
    // 004f2065  90                     -nop 
    ;
    // 004f2066  90                     -nop 
    ;
    // 004f2067  90                     -nop 
    ;
    // 004f2068  90                     -nop 
    ;
    // 004f2069  90                     -nop 
    ;
    // 004f206a  90                     -nop 
    ;
    // 004f206b  90                     -nop 
    ;
    // 004f206c  90                     -nop 
    ;
    // 004f206d  90                     -nop 
    ;
    // 004f206e  90                     -nop 
    ;
    // 004f206f  90                     -nop 
    ;
    // 004f2070  90                     -nop 
    ;
    // 004f2071  90                     -nop 
    ;
    // 004f2072  90                     -nop 
    ;
    // 004f2073  90                     -nop 
    ;
    // 004f2074  90                     -nop 
    ;
    // 004f2075  90                     -nop 
    ;
    // 004f2076  90                     -nop 
    ;
    // 004f2077  90                     -nop 
    ;
    // 004f2078  90                     -nop 
    ;
    // 004f2079  90                     -nop 
    ;
    // 004f207a  90                     -nop 
    ;
    // 004f207b  90                     -nop 
    ;
    // 004f207c  90                     -nop 
    ;
    // 004f207d  90                     -nop 
    ;
    // 004f207e  90                     -nop 
    ;
    // 004f207f  90                     -nop 
    ;
    // 004f2080  90                     -nop 
    ;
    // 004f2081  90                     -nop 
    ;
    // 004f2082  90                     -nop 
    ;
    // 004f2083  90                     -nop 
    ;
    // 004f2084  90                     -nop 
    ;
    // 004f2085  90                     -nop 
    ;
    // 004f2086  90                     -nop 
    ;
    // 004f2087  90                     -nop 
    ;
    // 004f2088  90                     -nop 
    ;
    // 004f2089  90                     -nop 
    ;
    // 004f208a  90                     -nop 
    ;
    // 004f208b  90                     -nop 
    ;
    // 004f208c  90                     -nop 
    ;
    // 004f208d  90                     -nop 
    ;
    // 004f208e  90                     -nop 
    ;
    // 004f208f  90                     -nop 
    ;
    // 004f2090  90                     -nop 
    ;
    // 004f2091  90                     -nop 
    ;
    // 004f2092  90                     -nop 
    ;
    // 004f2093  90                     -nop 
    ;
    // 004f2094  90                     -nop 
    ;
    // 004f2095  90                     -nop 
    ;
    // 004f2096  90                     -nop 
    ;
    // 004f2097  90                     -nop 
    ;
    // 004f2098  90                     -nop 
    ;
    // 004f2099  90                     -nop 
    ;
    // 004f209a  90                     -nop 
    ;
    // 004f209b  90                     -nop 
    ;
    // 004f209c  90                     -nop 
    ;
    // 004f209d  90                     -nop 
    ;
    // 004f209e  90                     -nop 
    ;
    // 004f209f  90                     -nop 
    ;
    // 004f20a0  90                     -nop 
    ;
    // 004f20a1  90                     -nop 
    ;
    // 004f20a2  90                     -nop 
    ;
    // 004f20a3  90                     -nop 
    ;
    // 004f20a4  90                     -nop 
    ;
    // 004f20a5  90                     -nop 
    ;
    // 004f20a6  90                     -nop 
    ;
    // 004f20a7  90                     -nop 
    ;
    // 004f20a8  90                     -nop 
    ;
    // 004f20a9  90                     -nop 
    ;
    // 004f20aa  90                     -nop 
    ;
    // 004f20ab  90                     -nop 
    ;
    // 004f20ac  90                     -nop 
    ;
    // 004f20ad  90                     -nop 
    ;
    // 004f20ae  90                     -nop 
    ;
    // 004f20af  90                     -nop 
    ;
    // 004f20b0  90                     -nop 
    ;
    // 004f20b1  90                     -nop 
    ;
    // 004f20b2  90                     -nop 
    ;
    // 004f20b3  90                     -nop 
    ;
    // 004f20b4  90                     -nop 
    ;
    // 004f20b5  90                     -nop 
    ;
    // 004f20b6  90                     -nop 
    ;
    // 004f20b7  90                     -nop 
    ;
    // 004f20b8  90                     -nop 
    ;
    // 004f20b9  90                     -nop 
    ;
    // 004f20ba  90                     -nop 
    ;
    // 004f20bb  90                     -nop 
    ;
    // 004f20bc  90                     -nop 
    ;
    // 004f20bd  90                     -nop 
    ;
    // 004f20be  90                     -nop 
    ;
    // 004f20bf  90                     -nop 
    ;
    // 004f20c0  90                     -nop 
    ;
    // 004f20c1  90                     -nop 
    ;
    // 004f20c2  90                     -nop 
    ;
    // 004f20c3  90                     -nop 
    ;
    // 004f20c4  90                     -nop 
    ;
    // 004f20c5  90                     -nop 
    ;
    // 004f20c6  90                     -nop 
    ;
    // 004f20c7  90                     -nop 
    ;
    // 004f20c8  90                     -nop 
    ;
    // 004f20c9  90                     -nop 
    ;
    // 004f20ca  90                     -nop 
    ;
    // 004f20cb  90                     -nop 
    ;
    // 004f20cc  90                     -nop 
    ;
    // 004f20cd  90                     -nop 
    ;
    // 004f20ce  90                     -nop 
    ;
    // 004f20cf  90                     -nop 
    ;
    // 004f20d0  90                     -nop 
    ;
    // 004f20d1  90                     -nop 
    ;
    // 004f20d2  90                     -nop 
    ;
    // 004f20d3  90                     -nop 
    ;
    // 004f20d4  90                     -nop 
    ;
    // 004f20d5  90                     -nop 
    ;
    // 004f20d6  90                     -nop 
    ;
    // 004f20d7  90                     -nop 
    ;
    // 004f20d8  90                     -nop 
    ;
    // 004f20d9  90                     -nop 
    ;
    // 004f20da  90                     -nop 
    ;
    // 004f20db  90                     -nop 
    ;
    // 004f20dc  90                     -nop 
    ;
    // 004f20dd  90                     -nop 
    ;
    // 004f20de  90                     -nop 
    ;
    // 004f20df  90                     -nop 
    ;
    // 004f20e0  90                     -nop 
    ;
    // 004f20e1  90                     -nop 
    ;
    // 004f20e2  90                     -nop 
    ;
    // 004f20e3  90                     -nop 
    ;
    // 004f20e4  90                     -nop 
    ;
    // 004f20e5  90                     -nop 
    ;
    // 004f20e6  90                     -nop 
    ;
    // 004f20e7  90                     -nop 
    ;
    // 004f20e8  90                     -nop 
    ;
    // 004f20e9  90                     -nop 
    ;
    // 004f20ea  90                     -nop 
    ;
    // 004f20eb  90                     -nop 
    ;
    // 004f20ec  90                     -nop 
    ;
    // 004f20ed  90                     -nop 
    ;
    // 004f20ee  90                     -nop 
    ;
    // 004f20ef  90                     -nop 
    ;
    // 004f20f0  90                     -nop 
    ;
    // 004f20f1  90                     -nop 
    ;
    // 004f20f2  90                     -nop 
    ;
    // 004f20f3  90                     -nop 
    ;
    // 004f20f4  90                     -nop 
    ;
    // 004f20f5  90                     -nop 
    ;
    // 004f20f6  90                     -nop 
    ;
    // 004f20f7  90                     -nop 
    ;
    // 004f20f8  90                     -nop 
    ;
    // 004f20f9  90                     -nop 
    ;
    // 004f20fa  90                     -nop 
    ;
    // 004f20fb  90                     -nop 
    ;
    // 004f20fc  90                     -nop 
    ;
    // 004f20fd  90                     -nop 
    ;
    // 004f20fe  90                     -nop 
    ;
    // 004f20ff  90                     -nop 
    ;
    // 004f2100  90                     -nop 
    ;
    // 004f2101  90                     -nop 
    ;
    // 004f2102  90                     -nop 
    ;
    // 004f2103  90                     -nop 
    ;
    // 004f2104  90                     -nop 
    ;
    // 004f2105  90                     -nop 
    ;
    // 004f2106  90                     -nop 
    ;
    // 004f2107  90                     -nop 
    ;
    // 004f2108  90                     -nop 
    ;
    // 004f2109  90                     -nop 
    ;
    // 004f210a  90                     -nop 
    ;
    // 004f210b  90                     -nop 
    ;
    // 004f210c  90                     -nop 
    ;
    // 004f210d  90                     -nop 
    ;
    // 004f210e  90                     -nop 
    ;
    // 004f210f  90                     -nop 
    ;
    // 004f2110  90                     -nop 
    ;
    // 004f2111  90                     -nop 
    ;
    // 004f2112  90                     -nop 
    ;
    // 004f2113  90                     -nop 
    ;
    // 004f2114  90                     -nop 
    ;
    // 004f2115  90                     -nop 
    ;
    // 004f2116  90                     -nop 
    ;
    // 004f2117  90                     -nop 
    ;
    // 004f2118  90                     -nop 
    ;
    // 004f2119  90                     -nop 
    ;
    // 004f211a  90                     -nop 
    ;
    // 004f211b  90                     -nop 
    ;
    // 004f211c  90                     -nop 
    ;
    // 004f211d  90                     -nop 
    ;
    // 004f211e  90                     -nop 
    ;
    // 004f211f  90                     -nop 
    ;
    // 004f2120  90                     -nop 
    ;
    // 004f2121  90                     -nop 
    ;
    // 004f2122  90                     -nop 
    ;
    // 004f2123  90                     -nop 
    ;
    // 004f2124  90                     -nop 
    ;
    // 004f2125  90                     -nop 
    ;
    // 004f2126  90                     -nop 
    ;
    // 004f2127  90                     -nop 
    ;
    // 004f2128  90                     -nop 
    ;
    // 004f2129  90                     -nop 
    ;
    // 004f212a  90                     -nop 
    ;
    // 004f212b  90                     -nop 
    ;
    // 004f212c  90                     -nop 
    ;
    // 004f212d  90                     -nop 
    ;
    // 004f212e  90                     -nop 
    ;
    // 004f212f  90                     -nop 
    ;
    // 004f2130  90                     -nop 
    ;
    // 004f2131  90                     -nop 
    ;
    // 004f2132  90                     -nop 
    ;
    // 004f2133  90                     -nop 
    ;
    // 004f2134  90                     -nop 
    ;
    // 004f2135  90                     -nop 
    ;
    // 004f2136  90                     -nop 
    ;
    // 004f2137  90                     -nop 
    ;
    // 004f2138  90                     -nop 
    ;
    // 004f2139  90                     -nop 
    ;
    // 004f213a  90                     -nop 
    ;
    // 004f213b  90                     -nop 
    ;
    // 004f213c  90                     -nop 
    ;
    // 004f213d  90                     -nop 
    ;
    // 004f213e  90                     -nop 
    ;
    // 004f213f  90                     -nop 
    ;
    // 004f2140  90                     -nop 
    ;
    // 004f2141  90                     -nop 
    ;
    // 004f2142  90                     -nop 
    ;
    // 004f2143  90                     -nop 
    ;
    // 004f2144  90                     -nop 
    ;
    // 004f2145  90                     -nop 
    ;
    // 004f2146  90                     -nop 
    ;
    // 004f2147  90                     -nop 
    ;
    // 004f2148  90                     -nop 
    ;
    // 004f2149  90                     -nop 
    ;
    // 004f214a  90                     -nop 
    ;
    // 004f214b  90                     -nop 
    ;
    // 004f214c  90                     -nop 
    ;
    // 004f214d  90                     -nop 
    ;
    // 004f214e  90                     -nop 
    ;
    // 004f214f  90                     -nop 
    ;
    // 004f2150  90                     -nop 
    ;
    // 004f2151  90                     -nop 
    ;
    // 004f2152  90                     -nop 
    ;
    // 004f2153  90                     -nop 
    ;
    // 004f2154  90                     -nop 
    ;
    // 004f2155  90                     -nop 
    ;
    // 004f2156  90                     -nop 
    ;
    // 004f2157  90                     -nop 
    ;
    // 004f2158  90                     -nop 
    ;
    // 004f2159  90                     -nop 
    ;
    // 004f215a  90                     -nop 
    ;
    // 004f215b  90                     -nop 
    ;
    // 004f215c  90                     -nop 
    ;
    // 004f215d  90                     -nop 
    ;
    // 004f215e  90                     -nop 
    ;
    // 004f215f  90                     -nop 
    ;
    // 004f2160  90                     -nop 
    ;
    // 004f2161  90                     -nop 
    ;
    // 004f2162  90                     -nop 
    ;
    // 004f2163  90                     -nop 
    ;
    // 004f2164  90                     -nop 
    ;
    // 004f2165  90                     -nop 
    ;
    // 004f2166  90                     -nop 
    ;
    // 004f2167  90                     -nop 
    ;
    // 004f2168  90                     -nop 
    ;
    // 004f2169  90                     -nop 
    ;
    // 004f216a  90                     -nop 
    ;
    // 004f216b  90                     -nop 
    ;
    // 004f216c  90                     -nop 
    ;
    // 004f216d  90                     -nop 
    ;
    // 004f216e  90                     -nop 
    ;
    // 004f216f  90                     -nop 
    ;
    // 004f2170  90                     -nop 
    ;
    // 004f2171  90                     -nop 
    ;
    // 004f2172  90                     -nop 
    ;
    // 004f2173  90                     -nop 
    ;
    // 004f2174  90                     -nop 
    ;
    // 004f2175  90                     -nop 
    ;
    // 004f2176  90                     -nop 
    ;
    // 004f2177  90                     -nop 
    ;
    // 004f2178  90                     -nop 
    ;
    // 004f2179  90                     -nop 
    ;
    // 004f217a  90                     -nop 
    ;
    // 004f217b  90                     -nop 
    ;
    // 004f217c  90                     -nop 
    ;
    // 004f217d  90                     -nop 
    ;
    // 004f217e  90                     -nop 
    ;
    // 004f217f  90                     -nop 
    ;
    // 004f2180  90                     -nop 
    ;
    // 004f2181  90                     -nop 
    ;
    // 004f2182  90                     -nop 
    ;
    // 004f2183  90                     -nop 
    ;
    // 004f2184  90                     -nop 
    ;
    // 004f2185  90                     -nop 
    ;
    // 004f2186  90                     -nop 
    ;
    // 004f2187  90                     -nop 
    ;
    // 004f2188  90                     -nop 
    ;
    // 004f2189  90                     -nop 
    ;
    // 004f218a  90                     -nop 
    ;
    // 004f218b  90                     -nop 
    ;
    // 004f218c  90                     -nop 
    ;
    // 004f218d  90                     -nop 
    ;
    // 004f218e  90                     -nop 
    ;
    // 004f218f  90                     -nop 
    ;
    // 004f2190  90                     -nop 
    ;
    // 004f2191  90                     -nop 
    ;
    // 004f2192  90                     -nop 
    ;
    // 004f2193  90                     -nop 
    ;
    // 004f2194  90                     -nop 
    ;
    // 004f2195  90                     -nop 
    ;
    // 004f2196  90                     -nop 
    ;
    // 004f2197  90                     -nop 
    ;
    // 004f2198  90                     -nop 
    ;
    // 004f2199  90                     -nop 
    ;
    // 004f219a  90                     -nop 
    ;
    // 004f219b  90                     -nop 
    ;
    // 004f219c  90                     -nop 
    ;
    // 004f219d  90                     -nop 
    ;
    // 004f219e  90                     -nop 
    ;
    // 004f219f  90                     -nop 
    ;
    // 004f21a0  90                     -nop 
    ;
    // 004f21a1  90                     -nop 
    ;
    // 004f21a2  90                     -nop 
    ;
    // 004f21a3  90                     -nop 
    ;
    // 004f21a4  90                     -nop 
    ;
    // 004f21a5  90                     -nop 
    ;
    // 004f21a6  90                     -nop 
    ;
    // 004f21a7  90                     -nop 
    ;
    // 004f21a8  90                     -nop 
    ;
    // 004f21a9  90                     -nop 
    ;
    // 004f21aa  90                     -nop 
    ;
    // 004f21ab  90                     -nop 
    ;
    // 004f21ac  90                     -nop 
    ;
    // 004f21ad  90                     -nop 
    ;
    // 004f21ae  90                     -nop 
    ;
    // 004f21af  90                     -nop 
    ;
    // 004f21b0  90                     -nop 
    ;
    // 004f21b1  90                     -nop 
    ;
    // 004f21b2  90                     -nop 
    ;
    // 004f21b3  90                     -nop 
    ;
    // 004f21b4  90                     -nop 
    ;
    // 004f21b5  90                     -nop 
    ;
    // 004f21b6  90                     -nop 
    ;
    // 004f21b7  90                     -nop 
    ;
    // 004f21b8  90                     -nop 
    ;
    // 004f21b9  90                     -nop 
    ;
    // 004f21ba  90                     -nop 
    ;
    // 004f21bb  90                     -nop 
    ;
    // 004f21bc  90                     -nop 
    ;
    // 004f21bd  90                     -nop 
    ;
    // 004f21be  90                     -nop 
    ;
    // 004f21bf  90                     -nop 
    ;
    // 004f21c0  90                     -nop 
    ;
    // 004f21c1  90                     -nop 
    ;
    // 004f21c2  90                     -nop 
    ;
    // 004f21c3  90                     -nop 
    ;
    // 004f21c4  90                     -nop 
    ;
    // 004f21c5  90                     -nop 
    ;
    // 004f21c6  90                     -nop 
    ;
    // 004f21c7  90                     -nop 
    ;
    // 004f21c8  90                     -nop 
    ;
    // 004f21c9  90                     -nop 
    ;
    // 004f21ca  90                     -nop 
    ;
    // 004f21cb  90                     -nop 
    ;
    // 004f21cc  90                     -nop 
    ;
    // 004f21cd  90                     -nop 
    ;
    // 004f21ce  90                     -nop 
    ;
    // 004f21cf  90                     -nop 
    ;
    // 004f21d0  90                     -nop 
    ;
    // 004f21d1  90                     -nop 
    ;
    // 004f21d2  90                     -nop 
    ;
    // 004f21d3  90                     -nop 
    ;
    // 004f21d4  90                     -nop 
    ;
    // 004f21d5  90                     -nop 
    ;
    // 004f21d6  90                     -nop 
    ;
    // 004f21d7  90                     -nop 
    ;
    // 004f21d8  90                     -nop 
    ;
    // 004f21d9  90                     -nop 
    ;
    // 004f21da  90                     -nop 
    ;
    // 004f21db  90                     -nop 
    ;
    // 004f21dc  90                     -nop 
    ;
    // 004f21dd  90                     -nop 
    ;
    // 004f21de  90                     -nop 
    ;
    // 004f21df  90                     -nop 
    ;
    // 004f21e0  90                     -nop 
    ;
    // 004f21e1  90                     -nop 
    ;
    // 004f21e2  90                     -nop 
    ;
    // 004f21e3  90                     -nop 
    ;
    // 004f21e4  90                     -nop 
    ;
    // 004f21e5  90                     -nop 
    ;
    // 004f21e6  90                     -nop 
    ;
    // 004f21e7  90                     -nop 
    ;
    // 004f21e8  90                     -nop 
    ;
    // 004f21e9  90                     -nop 
    ;
    // 004f21ea  90                     -nop 
    ;
    // 004f21eb  90                     -nop 
    ;
    // 004f21ec  90                     -nop 
    ;
    // 004f21ed  90                     -nop 
    ;
    // 004f21ee  90                     -nop 
    ;
    // 004f21ef  90                     -nop 
    ;
    // 004f21f0  90                     -nop 
    ;
    // 004f21f1  90                     -nop 
    ;
    // 004f21f2  90                     -nop 
    ;
    // 004f21f3  90                     -nop 
    ;
    // 004f21f4  90                     -nop 
    ;
    // 004f21f5  90                     -nop 
    ;
    // 004f21f6  90                     -nop 
    ;
    // 004f21f7  90                     -nop 
    ;
    // 004f21f8  90                     -nop 
    ;
    // 004f21f9  90                     -nop 
    ;
    // 004f21fa  90                     -nop 
    ;
    // 004f21fb  90                     -nop 
    ;
    // 004f21fc  90                     -nop 
    ;
    // 004f21fd  90                     -nop 
    ;
    // 004f21fe  90                     -nop 
    ;
    // 004f21ff  90                     -nop 
    ;
    // 004f2200  90                     -nop 
    ;
    // 004f2201  90                     -nop 
    ;
    // 004f2202  90                     -nop 
    ;
    // 004f2203  90                     -nop 
    ;
    // 004f2204  90                     -nop 
    ;
    // 004f2205  90                     -nop 
    ;
    // 004f2206  90                     -nop 
    ;
    // 004f2207  90                     -nop 
    ;
    // 004f2208  90                     -nop 
    ;
    // 004f2209  90                     -nop 
    ;
    // 004f220a  90                     -nop 
    ;
    // 004f220b  90                     -nop 
    ;
    // 004f220c  90                     -nop 
    ;
    // 004f220d  90                     -nop 
    ;
    // 004f220e  90                     -nop 
    ;
    // 004f220f  90                     -nop 
    ;
    // 004f2210  90                     -nop 
    ;
    // 004f2211  90                     -nop 
    ;
    // 004f2212  90                     -nop 
    ;
    // 004f2213  90                     -nop 
    ;
    // 004f2214  90                     -nop 
    ;
    // 004f2215  90                     -nop 
    ;
    // 004f2216  90                     -nop 
    ;
    // 004f2217  90                     -nop 
    ;
    // 004f2218  90                     -nop 
    ;
    // 004f2219  90                     -nop 
    ;
    // 004f221a  90                     -nop 
    ;
    // 004f221b  90                     -nop 
    ;
    // 004f221c  90                     -nop 
    ;
    // 004f221d  90                     -nop 
    ;
    // 004f221e  90                     -nop 
    ;
    // 004f221f  90                     -nop 
    ;
    // 004f2220  90                     -nop 
    ;
    // 004f2221  90                     -nop 
    ;
    // 004f2222  90                     -nop 
    ;
    // 004f2223  90                     -nop 
    ;
    // 004f2224  90                     -nop 
    ;
    // 004f2225  90                     -nop 
    ;
    // 004f2226  90                     -nop 
    ;
    // 004f2227  90                     -nop 
    ;
    // 004f2228  90                     -nop 
    ;
    // 004f2229  90                     -nop 
    ;
    // 004f222a  90                     -nop 
    ;
    // 004f222b  90                     -nop 
    ;
    // 004f222c  90                     -nop 
    ;
    // 004f222d  90                     -nop 
    ;
    // 004f222e  90                     -nop 
    ;
    // 004f222f  90                     -nop 
    ;
    // 004f2230  90                     -nop 
    ;
    // 004f2231  90                     -nop 
    ;
    // 004f2232  90                     -nop 
    ;
    // 004f2233  90                     -nop 
    ;
    // 004f2234  90                     -nop 
    ;
    // 004f2235  90                     -nop 
    ;
    // 004f2236  90                     -nop 
    ;
    // 004f2237  90                     -nop 
    ;
    // 004f2238  90                     -nop 
    ;
    // 004f2239  90                     -nop 
    ;
    // 004f223a  90                     -nop 
    ;
    // 004f223b  90                     -nop 
    ;
    // 004f223c  90                     -nop 
    ;
    // 004f223d  90                     -nop 
    ;
    // 004f223e  90                     -nop 
    ;
    // 004f223f  90                     -nop 
    ;
    // 004f2240  90                     -nop 
    ;
    // 004f2241  90                     -nop 
    ;
    // 004f2242  90                     -nop 
    ;
    // 004f2243  90                     -nop 
    ;
    // 004f2244  90                     -nop 
    ;
    // 004f2245  90                     -nop 
    ;
    // 004f2246  90                     -nop 
    ;
    // 004f2247  90                     -nop 
    ;
    // 004f2248  90                     -nop 
    ;
    // 004f2249  90                     -nop 
    ;
    // 004f224a  90                     -nop 
    ;
    // 004f224b  90                     -nop 
    ;
    // 004f224c  90                     -nop 
    ;
    // 004f224d  90                     -nop 
    ;
    // 004f224e  90                     -nop 
    ;
    // 004f224f  90                     -nop 
    ;
    // 004f2250  90                     -nop 
    ;
    // 004f2251  90                     -nop 
    ;
    // 004f2252  90                     -nop 
    ;
    // 004f2253  90                     -nop 
    ;
    // 004f2254  90                     -nop 
    ;
    // 004f2255  90                     -nop 
    ;
    // 004f2256  90                     -nop 
    ;
    // 004f2257  90                     -nop 
    ;
    // 004f2258  90                     -nop 
    ;
    // 004f2259  90                     -nop 
    ;
    // 004f225a  90                     -nop 
    ;
    // 004f225b  90                     -nop 
    ;
    // 004f225c  90                     -nop 
    ;
    // 004f225d  90                     -nop 
    ;
    // 004f225e  90                     -nop 
    ;
    // 004f225f  90                     -nop 
    ;
    // 004f2260  90                     -nop 
    ;
    // 004f2261  90                     -nop 
    ;
    // 004f2262  90                     -nop 
    ;
    // 004f2263  90                     -nop 
    ;
    // 004f2264  90                     -nop 
    ;
    // 004f2265  90                     -nop 
    ;
    // 004f2266  90                     -nop 
    ;
    // 004f2267  90                     -nop 
    ;
    // 004f2268  90                     -nop 
    ;
    // 004f2269  90                     -nop 
    ;
    // 004f226a  90                     -nop 
    ;
    // 004f226b  90                     -nop 
    ;
    // 004f226c  90                     -nop 
    ;
    // 004f226d  90                     -nop 
    ;
    // 004f226e  90                     -nop 
    ;
    // 004f226f  90                     -nop 
    ;
    // 004f2270  90                     -nop 
    ;
    // 004f2271  90                     -nop 
    ;
    // 004f2272  90                     -nop 
    ;
    // 004f2273  90                     -nop 
    ;
    // 004f2274  90                     -nop 
    ;
    // 004f2275  90                     -nop 
    ;
    // 004f2276  90                     -nop 
    ;
    // 004f2277  90                     -nop 
    ;
    // 004f2278  90                     -nop 
    ;
    // 004f2279  90                     -nop 
    ;
    // 004f227a  90                     -nop 
    ;
    // 004f227b  90                     -nop 
    ;
    // 004f227c  90                     -nop 
    ;
    // 004f227d  90                     -nop 
    ;
    // 004f227e  90                     -nop 
    ;
    // 004f227f  90                     -nop 
    ;
    // 004f2280  90                     -nop 
    ;
    // 004f2281  90                     -nop 
    ;
    // 004f2282  90                     -nop 
    ;
    // 004f2283  90                     -nop 
    ;
    // 004f2284  90                     -nop 
    ;
    // 004f2285  90                     -nop 
    ;
    // 004f2286  90                     -nop 
    ;
    // 004f2287  90                     -nop 
    ;
    // 004f2288  90                     -nop 
    ;
    // 004f2289  90                     -nop 
    ;
    // 004f228a  90                     -nop 
    ;
    // 004f228b  90                     -nop 
    ;
    // 004f228c  90                     -nop 
    ;
    // 004f228d  90                     -nop 
    ;
    // 004f228e  90                     -nop 
    ;
    // 004f228f  90                     -nop 
    ;
    // 004f2290  90                     -nop 
    ;
    // 004f2291  90                     -nop 
    ;
    // 004f2292  90                     -nop 
    ;
    // 004f2293  90                     -nop 
    ;
    // 004f2294  90                     -nop 
    ;
    // 004f2295  90                     -nop 
    ;
    // 004f2296  90                     -nop 
    ;
    // 004f2297  90                     -nop 
    ;
    // 004f2298  90                     -nop 
    ;
    // 004f2299  90                     -nop 
    ;
    // 004f229a  90                     -nop 
    ;
    // 004f229b  90                     -nop 
    ;
    // 004f229c  90                     -nop 
    ;
    // 004f229d  90                     -nop 
    ;
    // 004f229e  90                     -nop 
    ;
    // 004f229f  90                     -nop 
    ;
    // 004f22a0  90                     -nop 
    ;
    // 004f22a1  90                     -nop 
    ;
    // 004f22a2  90                     -nop 
    ;
    // 004f22a3  90                     -nop 
    ;
    // 004f22a4  90                     -nop 
    ;
    // 004f22a5  90                     -nop 
    ;
    // 004f22a6  90                     -nop 
    ;
    // 004f22a7  90                     -nop 
    ;
    // 004f22a8  90                     -nop 
    ;
    // 004f22a9  90                     -nop 
    ;
    // 004f22aa  90                     -nop 
    ;
    // 004f22ab  90                     -nop 
    ;
    // 004f22ac  90                     -nop 
    ;
    // 004f22ad  90                     -nop 
    ;
    // 004f22ae  90                     -nop 
    ;
    // 004f22af  90                     -nop 
    ;
    // 004f22b0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f22b1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f22b2  83ec24                 -sub esp, 0x24
    (cpu.esp) -= x86::reg32(x86::sreg32(36 /*0x24*/));
    // 004f22b5  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004f22b7  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004f22b9  e872c80100             -call 0x50eb30
    cpu.esp -= 4;
    sub_50eb30(app, cpu);
    if (cpu.terminate) return;
    // 004f22be  3df4010000             +cmp eax, 0x1f4
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(500 /*0x1f4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f22c3  7c03                   -jl 0x4f22c8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004f22c8;
    }
    // 004f22c5  ff0424                 -inc dword ptr [esp]
    (app->getMemory<x86::reg32>(cpu.esp))++;
L_0x004f22c8:
    // 004f22c8  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004f22ca  e8d1c80100             -call 0x50eba0
    cpu.esp -= 4;
    sub_50eba0(app, cpu);
    if (cpu.terminate) return;
    // 004f22cf  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004f22d1  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004f22d3  7402                   -je 0x4f22d7
    if (cpu.flags.zf)
    {
        goto L_0x004f22d7;
    }
    // 004f22d5  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
L_0x004f22d7:
    // 004f22d7  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004f22d9  83c424                 -add esp, 0x24
    (cpu.esp) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 004f22dc  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f22dd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f22de  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4f22b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004f22b0;
    // 004f1ff0  90                     -nop 
    ;
    // 004f1ff1  90                     -nop 
    ;
    // 004f1ff2  90                     -nop 
    ;
    // 004f1ff3  90                     -nop 
    ;
    // 004f1ff4  90                     -nop 
    ;
    // 004f1ff5  90                     -nop 
    ;
    // 004f1ff6  90                     -nop 
    ;
    // 004f1ff7  90                     -nop 
    ;
    // 004f1ff8  90                     -nop 
    ;
    // 004f1ff9  90                     -nop 
    ;
    // 004f1ffa  90                     -nop 
    ;
    // 004f1ffb  90                     -nop 
    ;
    // 004f1ffc  90                     -nop 
    ;
    // 004f1ffd  90                     -nop 
    ;
    // 004f1ffe  90                     -nop 
    ;
    // 004f1fff  90                     -nop 
    ;
    // 004f2000  90                     -nop 
    ;
    // 004f2001  90                     -nop 
    ;
    // 004f2002  90                     -nop 
    ;
    // 004f2003  90                     -nop 
    ;
    // 004f2004  90                     -nop 
    ;
    // 004f2005  90                     -nop 
    ;
    // 004f2006  90                     -nop 
    ;
    // 004f2007  90                     -nop 
    ;
    // 004f2008  90                     -nop 
    ;
    // 004f2009  90                     -nop 
    ;
    // 004f200a  90                     -nop 
    ;
    // 004f200b  90                     -nop 
    ;
    // 004f200c  90                     -nop 
    ;
    // 004f200d  90                     -nop 
    ;
    // 004f200e  90                     -nop 
    ;
    // 004f200f  90                     -nop 
    ;
    // 004f2010  90                     -nop 
    ;
    // 004f2011  90                     -nop 
    ;
    // 004f2012  90                     -nop 
    ;
    // 004f2013  90                     -nop 
    ;
    // 004f2014  90                     -nop 
    ;
    // 004f2015  90                     -nop 
    ;
    // 004f2016  90                     -nop 
    ;
    // 004f2017  90                     -nop 
    ;
    // 004f2018  90                     -nop 
    ;
    // 004f2019  90                     -nop 
    ;
    // 004f201a  90                     -nop 
    ;
    // 004f201b  90                     -nop 
    ;
    // 004f201c  90                     -nop 
    ;
    // 004f201d  90                     -nop 
    ;
    // 004f201e  90                     -nop 
    ;
    // 004f201f  90                     -nop 
    ;
    // 004f2020  90                     -nop 
    ;
    // 004f2021  90                     -nop 
    ;
    // 004f2022  90                     -nop 
    ;
    // 004f2023  90                     -nop 
    ;
    // 004f2024  90                     -nop 
    ;
    // 004f2025  90                     -nop 
    ;
    // 004f2026  90                     -nop 
    ;
    // 004f2027  90                     -nop 
    ;
    // 004f2028  90                     -nop 
    ;
    // 004f2029  90                     -nop 
    ;
    // 004f202a  90                     -nop 
    ;
    // 004f202b  90                     -nop 
    ;
    // 004f202c  90                     -nop 
    ;
    // 004f202d  90                     -nop 
    ;
    // 004f202e  90                     -nop 
    ;
    // 004f202f  90                     -nop 
    ;
    // 004f2030  90                     -nop 
    ;
    // 004f2031  90                     -nop 
    ;
    // 004f2032  90                     -nop 
    ;
    // 004f2033  90                     -nop 
    ;
    // 004f2034  90                     -nop 
    ;
    // 004f2035  90                     -nop 
    ;
    // 004f2036  90                     -nop 
    ;
    // 004f2037  90                     -nop 
    ;
    // 004f2038  90                     -nop 
    ;
    // 004f2039  90                     -nop 
    ;
    // 004f203a  90                     -nop 
    ;
    // 004f203b  90                     -nop 
    ;
    // 004f203c  90                     -nop 
    ;
    // 004f203d  90                     -nop 
    ;
    // 004f203e  90                     -nop 
    ;
    // 004f203f  90                     -nop 
    ;
    // 004f2040  90                     -nop 
    ;
    // 004f2041  90                     -nop 
    ;
    // 004f2042  90                     -nop 
    ;
    // 004f2043  90                     -nop 
    ;
    // 004f2044  90                     -nop 
    ;
    // 004f2045  90                     -nop 
    ;
    // 004f2046  90                     -nop 
    ;
    // 004f2047  90                     -nop 
    ;
    // 004f2048  90                     -nop 
    ;
    // 004f2049  90                     -nop 
    ;
    // 004f204a  90                     -nop 
    ;
    // 004f204b  90                     -nop 
    ;
    // 004f204c  90                     -nop 
    ;
    // 004f204d  90                     -nop 
    ;
    // 004f204e  90                     -nop 
    ;
    // 004f204f  90                     -nop 
    ;
    // 004f2050  90                     -nop 
    ;
    // 004f2051  90                     -nop 
    ;
    // 004f2052  90                     -nop 
    ;
    // 004f2053  90                     -nop 
    ;
    // 004f2054  90                     -nop 
    ;
    // 004f2055  90                     -nop 
    ;
    // 004f2056  90                     -nop 
    ;
    // 004f2057  90                     -nop 
    ;
    // 004f2058  90                     -nop 
    ;
    // 004f2059  90                     -nop 
    ;
    // 004f205a  90                     -nop 
    ;
    // 004f205b  90                     -nop 
    ;
    // 004f205c  90                     -nop 
    ;
    // 004f205d  90                     -nop 
    ;
    // 004f205e  90                     -nop 
    ;
    // 004f205f  90                     -nop 
    ;
    // 004f2060  90                     -nop 
    ;
    // 004f2061  90                     -nop 
    ;
    // 004f2062  90                     -nop 
    ;
    // 004f2063  90                     -nop 
    ;
    // 004f2064  90                     -nop 
    ;
    // 004f2065  90                     -nop 
    ;
    // 004f2066  90                     -nop 
    ;
    // 004f2067  90                     -nop 
    ;
    // 004f2068  90                     -nop 
    ;
    // 004f2069  90                     -nop 
    ;
    // 004f206a  90                     -nop 
    ;
    // 004f206b  90                     -nop 
    ;
    // 004f206c  90                     -nop 
    ;
    // 004f206d  90                     -nop 
    ;
    // 004f206e  90                     -nop 
    ;
    // 004f206f  90                     -nop 
    ;
    // 004f2070  90                     -nop 
    ;
    // 004f2071  90                     -nop 
    ;
    // 004f2072  90                     -nop 
    ;
    // 004f2073  90                     -nop 
    ;
    // 004f2074  90                     -nop 
    ;
    // 004f2075  90                     -nop 
    ;
    // 004f2076  90                     -nop 
    ;
    // 004f2077  90                     -nop 
    ;
    // 004f2078  90                     -nop 
    ;
    // 004f2079  90                     -nop 
    ;
    // 004f207a  90                     -nop 
    ;
    // 004f207b  90                     -nop 
    ;
    // 004f207c  90                     -nop 
    ;
    // 004f207d  90                     -nop 
    ;
    // 004f207e  90                     -nop 
    ;
    // 004f207f  90                     -nop 
    ;
    // 004f2080  90                     -nop 
    ;
    // 004f2081  90                     -nop 
    ;
    // 004f2082  90                     -nop 
    ;
    // 004f2083  90                     -nop 
    ;
    // 004f2084  90                     -nop 
    ;
    // 004f2085  90                     -nop 
    ;
    // 004f2086  90                     -nop 
    ;
    // 004f2087  90                     -nop 
    ;
    // 004f2088  90                     -nop 
    ;
    // 004f2089  90                     -nop 
    ;
    // 004f208a  90                     -nop 
    ;
    // 004f208b  90                     -nop 
    ;
    // 004f208c  90                     -nop 
    ;
    // 004f208d  90                     -nop 
    ;
    // 004f208e  90                     -nop 
    ;
    // 004f208f  90                     -nop 
    ;
    // 004f2090  90                     -nop 
    ;
    // 004f2091  90                     -nop 
    ;
    // 004f2092  90                     -nop 
    ;
    // 004f2093  90                     -nop 
    ;
    // 004f2094  90                     -nop 
    ;
    // 004f2095  90                     -nop 
    ;
    // 004f2096  90                     -nop 
    ;
    // 004f2097  90                     -nop 
    ;
    // 004f2098  90                     -nop 
    ;
    // 004f2099  90                     -nop 
    ;
    // 004f209a  90                     -nop 
    ;
    // 004f209b  90                     -nop 
    ;
    // 004f209c  90                     -nop 
    ;
    // 004f209d  90                     -nop 
    ;
    // 004f209e  90                     -nop 
    ;
    // 004f209f  90                     -nop 
    ;
    // 004f20a0  90                     -nop 
    ;
    // 004f20a1  90                     -nop 
    ;
    // 004f20a2  90                     -nop 
    ;
    // 004f20a3  90                     -nop 
    ;
    // 004f20a4  90                     -nop 
    ;
    // 004f20a5  90                     -nop 
    ;
    // 004f20a6  90                     -nop 
    ;
    // 004f20a7  90                     -nop 
    ;
    // 004f20a8  90                     -nop 
    ;
    // 004f20a9  90                     -nop 
    ;
    // 004f20aa  90                     -nop 
    ;
    // 004f20ab  90                     -nop 
    ;
    // 004f20ac  90                     -nop 
    ;
    // 004f20ad  90                     -nop 
    ;
    // 004f20ae  90                     -nop 
    ;
    // 004f20af  90                     -nop 
    ;
    // 004f20b0  90                     -nop 
    ;
    // 004f20b1  90                     -nop 
    ;
    // 004f20b2  90                     -nop 
    ;
    // 004f20b3  90                     -nop 
    ;
    // 004f20b4  90                     -nop 
    ;
    // 004f20b5  90                     -nop 
    ;
    // 004f20b6  90                     -nop 
    ;
    // 004f20b7  90                     -nop 
    ;
    // 004f20b8  90                     -nop 
    ;
    // 004f20b9  90                     -nop 
    ;
    // 004f20ba  90                     -nop 
    ;
    // 004f20bb  90                     -nop 
    ;
    // 004f20bc  90                     -nop 
    ;
    // 004f20bd  90                     -nop 
    ;
    // 004f20be  90                     -nop 
    ;
    // 004f20bf  90                     -nop 
    ;
    // 004f20c0  90                     -nop 
    ;
    // 004f20c1  90                     -nop 
    ;
    // 004f20c2  90                     -nop 
    ;
    // 004f20c3  90                     -nop 
    ;
    // 004f20c4  90                     -nop 
    ;
    // 004f20c5  90                     -nop 
    ;
    // 004f20c6  90                     -nop 
    ;
    // 004f20c7  90                     -nop 
    ;
    // 004f20c8  90                     -nop 
    ;
    // 004f20c9  90                     -nop 
    ;
    // 004f20ca  90                     -nop 
    ;
    // 004f20cb  90                     -nop 
    ;
    // 004f20cc  90                     -nop 
    ;
    // 004f20cd  90                     -nop 
    ;
    // 004f20ce  90                     -nop 
    ;
    // 004f20cf  90                     -nop 
    ;
    // 004f20d0  90                     -nop 
    ;
    // 004f20d1  90                     -nop 
    ;
    // 004f20d2  90                     -nop 
    ;
    // 004f20d3  90                     -nop 
    ;
    // 004f20d4  90                     -nop 
    ;
    // 004f20d5  90                     -nop 
    ;
    // 004f20d6  90                     -nop 
    ;
    // 004f20d7  90                     -nop 
    ;
    // 004f20d8  90                     -nop 
    ;
    // 004f20d9  90                     -nop 
    ;
    // 004f20da  90                     -nop 
    ;
    // 004f20db  90                     -nop 
    ;
    // 004f20dc  90                     -nop 
    ;
    // 004f20dd  90                     -nop 
    ;
    // 004f20de  90                     -nop 
    ;
    // 004f20df  90                     -nop 
    ;
    // 004f20e0  90                     -nop 
    ;
    // 004f20e1  90                     -nop 
    ;
    // 004f20e2  90                     -nop 
    ;
    // 004f20e3  90                     -nop 
    ;
    // 004f20e4  90                     -nop 
    ;
    // 004f20e5  90                     -nop 
    ;
    // 004f20e6  90                     -nop 
    ;
    // 004f20e7  90                     -nop 
    ;
    // 004f20e8  90                     -nop 
    ;
    // 004f20e9  90                     -nop 
    ;
    // 004f20ea  90                     -nop 
    ;
    // 004f20eb  90                     -nop 
    ;
    // 004f20ec  90                     -nop 
    ;
    // 004f20ed  90                     -nop 
    ;
    // 004f20ee  90                     -nop 
    ;
    // 004f20ef  90                     -nop 
    ;
    // 004f20f0  90                     -nop 
    ;
    // 004f20f1  90                     -nop 
    ;
    // 004f20f2  90                     -nop 
    ;
    // 004f20f3  90                     -nop 
    ;
    // 004f20f4  90                     -nop 
    ;
    // 004f20f5  90                     -nop 
    ;
    // 004f20f6  90                     -nop 
    ;
    // 004f20f7  90                     -nop 
    ;
    // 004f20f8  90                     -nop 
    ;
    // 004f20f9  90                     -nop 
    ;
    // 004f20fa  90                     -nop 
    ;
    // 004f20fb  90                     -nop 
    ;
    // 004f20fc  90                     -nop 
    ;
    // 004f20fd  90                     -nop 
    ;
    // 004f20fe  90                     -nop 
    ;
    // 004f20ff  90                     -nop 
    ;
    // 004f2100  90                     -nop 
    ;
    // 004f2101  90                     -nop 
    ;
    // 004f2102  90                     -nop 
    ;
    // 004f2103  90                     -nop 
    ;
    // 004f2104  90                     -nop 
    ;
    // 004f2105  90                     -nop 
    ;
    // 004f2106  90                     -nop 
    ;
    // 004f2107  90                     -nop 
    ;
    // 004f2108  90                     -nop 
    ;
    // 004f2109  90                     -nop 
    ;
    // 004f210a  90                     -nop 
    ;
    // 004f210b  90                     -nop 
    ;
    // 004f210c  90                     -nop 
    ;
    // 004f210d  90                     -nop 
    ;
    // 004f210e  90                     -nop 
    ;
    // 004f210f  90                     -nop 
    ;
    // 004f2110  90                     -nop 
    ;
    // 004f2111  90                     -nop 
    ;
    // 004f2112  90                     -nop 
    ;
    // 004f2113  90                     -nop 
    ;
    // 004f2114  90                     -nop 
    ;
    // 004f2115  90                     -nop 
    ;
    // 004f2116  90                     -nop 
    ;
    // 004f2117  90                     -nop 
    ;
    // 004f2118  90                     -nop 
    ;
    // 004f2119  90                     -nop 
    ;
    // 004f211a  90                     -nop 
    ;
    // 004f211b  90                     -nop 
    ;
    // 004f211c  90                     -nop 
    ;
    // 004f211d  90                     -nop 
    ;
    // 004f211e  90                     -nop 
    ;
    // 004f211f  90                     -nop 
    ;
    // 004f2120  90                     -nop 
    ;
    // 004f2121  90                     -nop 
    ;
    // 004f2122  90                     -nop 
    ;
    // 004f2123  90                     -nop 
    ;
    // 004f2124  90                     -nop 
    ;
    // 004f2125  90                     -nop 
    ;
    // 004f2126  90                     -nop 
    ;
    // 004f2127  90                     -nop 
    ;
    // 004f2128  90                     -nop 
    ;
    // 004f2129  90                     -nop 
    ;
    // 004f212a  90                     -nop 
    ;
    // 004f212b  90                     -nop 
    ;
    // 004f212c  90                     -nop 
    ;
    // 004f212d  90                     -nop 
    ;
    // 004f212e  90                     -nop 
    ;
    // 004f212f  90                     -nop 
    ;
    // 004f2130  90                     -nop 
    ;
    // 004f2131  90                     -nop 
    ;
    // 004f2132  90                     -nop 
    ;
    // 004f2133  90                     -nop 
    ;
    // 004f2134  90                     -nop 
    ;
    // 004f2135  90                     -nop 
    ;
    // 004f2136  90                     -nop 
    ;
    // 004f2137  90                     -nop 
    ;
    // 004f2138  90                     -nop 
    ;
    // 004f2139  90                     -nop 
    ;
    // 004f213a  90                     -nop 
    ;
    // 004f213b  90                     -nop 
    ;
    // 004f213c  90                     -nop 
    ;
    // 004f213d  90                     -nop 
    ;
    // 004f213e  90                     -nop 
    ;
    // 004f213f  90                     -nop 
    ;
    // 004f2140  90                     -nop 
    ;
    // 004f2141  90                     -nop 
    ;
    // 004f2142  90                     -nop 
    ;
    // 004f2143  90                     -nop 
    ;
    // 004f2144  90                     -nop 
    ;
    // 004f2145  90                     -nop 
    ;
    // 004f2146  90                     -nop 
    ;
    // 004f2147  90                     -nop 
    ;
    // 004f2148  90                     -nop 
    ;
    // 004f2149  90                     -nop 
    ;
    // 004f214a  90                     -nop 
    ;
    // 004f214b  90                     -nop 
    ;
    // 004f214c  90                     -nop 
    ;
    // 004f214d  90                     -nop 
    ;
    // 004f214e  90                     -nop 
    ;
    // 004f214f  90                     -nop 
    ;
    // 004f2150  90                     -nop 
    ;
    // 004f2151  90                     -nop 
    ;
    // 004f2152  90                     -nop 
    ;
    // 004f2153  90                     -nop 
    ;
    // 004f2154  90                     -nop 
    ;
    // 004f2155  90                     -nop 
    ;
    // 004f2156  90                     -nop 
    ;
    // 004f2157  90                     -nop 
    ;
    // 004f2158  90                     -nop 
    ;
    // 004f2159  90                     -nop 
    ;
    // 004f215a  90                     -nop 
    ;
    // 004f215b  90                     -nop 
    ;
    // 004f215c  90                     -nop 
    ;
    // 004f215d  90                     -nop 
    ;
    // 004f215e  90                     -nop 
    ;
    // 004f215f  90                     -nop 
    ;
    // 004f2160  90                     -nop 
    ;
    // 004f2161  90                     -nop 
    ;
    // 004f2162  90                     -nop 
    ;
    // 004f2163  90                     -nop 
    ;
    // 004f2164  90                     -nop 
    ;
    // 004f2165  90                     -nop 
    ;
    // 004f2166  90                     -nop 
    ;
    // 004f2167  90                     -nop 
    ;
    // 004f2168  90                     -nop 
    ;
    // 004f2169  90                     -nop 
    ;
    // 004f216a  90                     -nop 
    ;
    // 004f216b  90                     -nop 
    ;
    // 004f216c  90                     -nop 
    ;
    // 004f216d  90                     -nop 
    ;
    // 004f216e  90                     -nop 
    ;
    // 004f216f  90                     -nop 
    ;
    // 004f2170  90                     -nop 
    ;
    // 004f2171  90                     -nop 
    ;
    // 004f2172  90                     -nop 
    ;
    // 004f2173  90                     -nop 
    ;
    // 004f2174  90                     -nop 
    ;
    // 004f2175  90                     -nop 
    ;
    // 004f2176  90                     -nop 
    ;
    // 004f2177  90                     -nop 
    ;
    // 004f2178  90                     -nop 
    ;
    // 004f2179  90                     -nop 
    ;
    // 004f217a  90                     -nop 
    ;
    // 004f217b  90                     -nop 
    ;
    // 004f217c  90                     -nop 
    ;
    // 004f217d  90                     -nop 
    ;
    // 004f217e  90                     -nop 
    ;
    // 004f217f  90                     -nop 
    ;
    // 004f2180  90                     -nop 
    ;
    // 004f2181  90                     -nop 
    ;
    // 004f2182  90                     -nop 
    ;
    // 004f2183  90                     -nop 
    ;
    // 004f2184  90                     -nop 
    ;
    // 004f2185  90                     -nop 
    ;
    // 004f2186  90                     -nop 
    ;
    // 004f2187  90                     -nop 
    ;
    // 004f2188  90                     -nop 
    ;
    // 004f2189  90                     -nop 
    ;
    // 004f218a  90                     -nop 
    ;
    // 004f218b  90                     -nop 
    ;
    // 004f218c  90                     -nop 
    ;
    // 004f218d  90                     -nop 
    ;
    // 004f218e  90                     -nop 
    ;
    // 004f218f  90                     -nop 
    ;
    // 004f2190  90                     -nop 
    ;
    // 004f2191  90                     -nop 
    ;
    // 004f2192  90                     -nop 
    ;
    // 004f2193  90                     -nop 
    ;
    // 004f2194  90                     -nop 
    ;
    // 004f2195  90                     -nop 
    ;
    // 004f2196  90                     -nop 
    ;
    // 004f2197  90                     -nop 
    ;
    // 004f2198  90                     -nop 
    ;
    // 004f2199  90                     -nop 
    ;
    // 004f219a  90                     -nop 
    ;
    // 004f219b  90                     -nop 
    ;
    // 004f219c  90                     -nop 
    ;
    // 004f219d  90                     -nop 
    ;
    // 004f219e  90                     -nop 
    ;
    // 004f219f  90                     -nop 
    ;
    // 004f21a0  90                     -nop 
    ;
    // 004f21a1  90                     -nop 
    ;
    // 004f21a2  90                     -nop 
    ;
    // 004f21a3  90                     -nop 
    ;
    // 004f21a4  90                     -nop 
    ;
    // 004f21a5  90                     -nop 
    ;
    // 004f21a6  90                     -nop 
    ;
    // 004f21a7  90                     -nop 
    ;
    // 004f21a8  90                     -nop 
    ;
    // 004f21a9  90                     -nop 
    ;
    // 004f21aa  90                     -nop 
    ;
    // 004f21ab  90                     -nop 
    ;
    // 004f21ac  90                     -nop 
    ;
    // 004f21ad  90                     -nop 
    ;
    // 004f21ae  90                     -nop 
    ;
    // 004f21af  90                     -nop 
    ;
    // 004f21b0  90                     -nop 
    ;
    // 004f21b1  90                     -nop 
    ;
    // 004f21b2  90                     -nop 
    ;
    // 004f21b3  90                     -nop 
    ;
    // 004f21b4  90                     -nop 
    ;
    // 004f21b5  90                     -nop 
    ;
    // 004f21b6  90                     -nop 
    ;
    // 004f21b7  90                     -nop 
    ;
    // 004f21b8  90                     -nop 
    ;
    // 004f21b9  90                     -nop 
    ;
    // 004f21ba  90                     -nop 
    ;
    // 004f21bb  90                     -nop 
    ;
    // 004f21bc  90                     -nop 
    ;
    // 004f21bd  90                     -nop 
    ;
    // 004f21be  90                     -nop 
    ;
    // 004f21bf  90                     -nop 
    ;
    // 004f21c0  90                     -nop 
    ;
    // 004f21c1  90                     -nop 
    ;
    // 004f21c2  90                     -nop 
    ;
    // 004f21c3  90                     -nop 
    ;
    // 004f21c4  90                     -nop 
    ;
    // 004f21c5  90                     -nop 
    ;
    // 004f21c6  90                     -nop 
    ;
    // 004f21c7  90                     -nop 
    ;
    // 004f21c8  90                     -nop 
    ;
    // 004f21c9  90                     -nop 
    ;
    // 004f21ca  90                     -nop 
    ;
    // 004f21cb  90                     -nop 
    ;
    // 004f21cc  90                     -nop 
    ;
    // 004f21cd  90                     -nop 
    ;
    // 004f21ce  90                     -nop 
    ;
    // 004f21cf  90                     -nop 
    ;
    // 004f21d0  90                     -nop 
    ;
    // 004f21d1  90                     -nop 
    ;
    // 004f21d2  90                     -nop 
    ;
    // 004f21d3  90                     -nop 
    ;
    // 004f21d4  90                     -nop 
    ;
    // 004f21d5  90                     -nop 
    ;
    // 004f21d6  90                     -nop 
    ;
    // 004f21d7  90                     -nop 
    ;
    // 004f21d8  90                     -nop 
    ;
    // 004f21d9  90                     -nop 
    ;
    // 004f21da  90                     -nop 
    ;
    // 004f21db  90                     -nop 
    ;
    // 004f21dc  90                     -nop 
    ;
    // 004f21dd  90                     -nop 
    ;
    // 004f21de  90                     -nop 
    ;
    // 004f21df  90                     -nop 
    ;
    // 004f21e0  90                     -nop 
    ;
    // 004f21e1  90                     -nop 
    ;
    // 004f21e2  90                     -nop 
    ;
    // 004f21e3  90                     -nop 
    ;
    // 004f21e4  90                     -nop 
    ;
    // 004f21e5  90                     -nop 
    ;
    // 004f21e6  90                     -nop 
    ;
    // 004f21e7  90                     -nop 
    ;
    // 004f21e8  90                     -nop 
    ;
    // 004f21e9  90                     -nop 
    ;
    // 004f21ea  90                     -nop 
    ;
    // 004f21eb  90                     -nop 
    ;
    // 004f21ec  90                     -nop 
    ;
    // 004f21ed  90                     -nop 
    ;
    // 004f21ee  90                     -nop 
    ;
    // 004f21ef  90                     -nop 
    ;
    // 004f21f0  90                     -nop 
    ;
    // 004f21f1  90                     -nop 
    ;
    // 004f21f2  90                     -nop 
    ;
    // 004f21f3  90                     -nop 
    ;
    // 004f21f4  90                     -nop 
    ;
    // 004f21f5  90                     -nop 
    ;
    // 004f21f6  90                     -nop 
    ;
    // 004f21f7  90                     -nop 
    ;
    // 004f21f8  90                     -nop 
    ;
    // 004f21f9  90                     -nop 
    ;
    // 004f21fa  90                     -nop 
    ;
    // 004f21fb  90                     -nop 
    ;
    // 004f21fc  90                     -nop 
    ;
    // 004f21fd  90                     -nop 
    ;
    // 004f21fe  90                     -nop 
    ;
    // 004f21ff  90                     -nop 
    ;
    // 004f2200  90                     -nop 
    ;
    // 004f2201  90                     -nop 
    ;
    // 004f2202  90                     -nop 
    ;
    // 004f2203  90                     -nop 
    ;
    // 004f2204  90                     -nop 
    ;
    // 004f2205  90                     -nop 
    ;
    // 004f2206  90                     -nop 
    ;
    // 004f2207  90                     -nop 
    ;
    // 004f2208  90                     -nop 
    ;
    // 004f2209  90                     -nop 
    ;
    // 004f220a  90                     -nop 
    ;
    // 004f220b  90                     -nop 
    ;
    // 004f220c  90                     -nop 
    ;
    // 004f220d  90                     -nop 
    ;
    // 004f220e  90                     -nop 
    ;
    // 004f220f  90                     -nop 
    ;
    // 004f2210  90                     -nop 
    ;
    // 004f2211  90                     -nop 
    ;
    // 004f2212  90                     -nop 
    ;
    // 004f2213  90                     -nop 
    ;
    // 004f2214  90                     -nop 
    ;
    // 004f2215  90                     -nop 
    ;
    // 004f2216  90                     -nop 
    ;
    // 004f2217  90                     -nop 
    ;
    // 004f2218  90                     -nop 
    ;
    // 004f2219  90                     -nop 
    ;
    // 004f221a  90                     -nop 
    ;
    // 004f221b  90                     -nop 
    ;
    // 004f221c  90                     -nop 
    ;
    // 004f221d  90                     -nop 
    ;
    // 004f221e  90                     -nop 
    ;
    // 004f221f  90                     -nop 
    ;
    // 004f2220  90                     -nop 
    ;
    // 004f2221  90                     -nop 
    ;
    // 004f2222  90                     -nop 
    ;
    // 004f2223  90                     -nop 
    ;
    // 004f2224  90                     -nop 
    ;
    // 004f2225  90                     -nop 
    ;
    // 004f2226  90                     -nop 
    ;
    // 004f2227  90                     -nop 
    ;
    // 004f2228  90                     -nop 
    ;
    // 004f2229  90                     -nop 
    ;
    // 004f222a  90                     -nop 
    ;
    // 004f222b  90                     -nop 
    ;
    // 004f222c  90                     -nop 
    ;
    // 004f222d  90                     -nop 
    ;
    // 004f222e  90                     -nop 
    ;
    // 004f222f  90                     -nop 
    ;
    // 004f2230  90                     -nop 
    ;
    // 004f2231  90                     -nop 
    ;
    // 004f2232  90                     -nop 
    ;
    // 004f2233  90                     -nop 
    ;
    // 004f2234  90                     -nop 
    ;
    // 004f2235  90                     -nop 
    ;
    // 004f2236  90                     -nop 
    ;
    // 004f2237  90                     -nop 
    ;
    // 004f2238  90                     -nop 
    ;
    // 004f2239  90                     -nop 
    ;
    // 004f223a  90                     -nop 
    ;
    // 004f223b  90                     -nop 
    ;
    // 004f223c  90                     -nop 
    ;
    // 004f223d  90                     -nop 
    ;
    // 004f223e  90                     -nop 
    ;
    // 004f223f  90                     -nop 
    ;
    // 004f2240  90                     -nop 
    ;
    // 004f2241  90                     -nop 
    ;
    // 004f2242  90                     -nop 
    ;
    // 004f2243  90                     -nop 
    ;
    // 004f2244  90                     -nop 
    ;
    // 004f2245  90                     -nop 
    ;
    // 004f2246  90                     -nop 
    ;
    // 004f2247  90                     -nop 
    ;
    // 004f2248  90                     -nop 
    ;
    // 004f2249  90                     -nop 
    ;
    // 004f224a  90                     -nop 
    ;
    // 004f224b  90                     -nop 
    ;
    // 004f224c  90                     -nop 
    ;
    // 004f224d  90                     -nop 
    ;
    // 004f224e  90                     -nop 
    ;
    // 004f224f  90                     -nop 
    ;
    // 004f2250  90                     -nop 
    ;
    // 004f2251  90                     -nop 
    ;
    // 004f2252  90                     -nop 
    ;
    // 004f2253  90                     -nop 
    ;
    // 004f2254  90                     -nop 
    ;
    // 004f2255  90                     -nop 
    ;
    // 004f2256  90                     -nop 
    ;
    // 004f2257  90                     -nop 
    ;
    // 004f2258  90                     -nop 
    ;
    // 004f2259  90                     -nop 
    ;
    // 004f225a  90                     -nop 
    ;
    // 004f225b  90                     -nop 
    ;
    // 004f225c  90                     -nop 
    ;
    // 004f225d  90                     -nop 
    ;
    // 004f225e  90                     -nop 
    ;
    // 004f225f  90                     -nop 
    ;
    // 004f2260  90                     -nop 
    ;
    // 004f2261  90                     -nop 
    ;
    // 004f2262  90                     -nop 
    ;
    // 004f2263  90                     -nop 
    ;
    // 004f2264  90                     -nop 
    ;
    // 004f2265  90                     -nop 
    ;
    // 004f2266  90                     -nop 
    ;
    // 004f2267  90                     -nop 
    ;
    // 004f2268  90                     -nop 
    ;
    // 004f2269  90                     -nop 
    ;
    // 004f226a  90                     -nop 
    ;
    // 004f226b  90                     -nop 
    ;
    // 004f226c  90                     -nop 
    ;
    // 004f226d  90                     -nop 
    ;
    // 004f226e  90                     -nop 
    ;
    // 004f226f  90                     -nop 
    ;
    // 004f2270  90                     -nop 
    ;
    // 004f2271  90                     -nop 
    ;
    // 004f2272  90                     -nop 
    ;
    // 004f2273  90                     -nop 
    ;
    // 004f2274  90                     -nop 
    ;
    // 004f2275  90                     -nop 
    ;
    // 004f2276  90                     -nop 
    ;
    // 004f2277  90                     -nop 
    ;
    // 004f2278  90                     -nop 
    ;
    // 004f2279  90                     -nop 
    ;
    // 004f227a  90                     -nop 
    ;
    // 004f227b  90                     -nop 
    ;
    // 004f227c  90                     -nop 
    ;
    // 004f227d  90                     -nop 
    ;
    // 004f227e  90                     -nop 
    ;
    // 004f227f  90                     -nop 
    ;
    // 004f2280  90                     -nop 
    ;
    // 004f2281  90                     -nop 
    ;
    // 004f2282  90                     -nop 
    ;
    // 004f2283  90                     -nop 
    ;
    // 004f2284  90                     -nop 
    ;
    // 004f2285  90                     -nop 
    ;
    // 004f2286  90                     -nop 
    ;
    // 004f2287  90                     -nop 
    ;
    // 004f2288  90                     -nop 
    ;
    // 004f2289  90                     -nop 
    ;
    // 004f228a  90                     -nop 
    ;
    // 004f228b  90                     -nop 
    ;
    // 004f228c  90                     -nop 
    ;
    // 004f228d  90                     -nop 
    ;
    // 004f228e  90                     -nop 
    ;
    // 004f228f  90                     -nop 
    ;
    // 004f2290  90                     -nop 
    ;
    // 004f2291  90                     -nop 
    ;
    // 004f2292  90                     -nop 
    ;
    // 004f2293  90                     -nop 
    ;
    // 004f2294  90                     -nop 
    ;
    // 004f2295  90                     -nop 
    ;
    // 004f2296  90                     -nop 
    ;
    // 004f2297  90                     -nop 
    ;
    // 004f2298  90                     -nop 
    ;
    // 004f2299  90                     -nop 
    ;
    // 004f229a  90                     -nop 
    ;
    // 004f229b  90                     -nop 
    ;
    // 004f229c  90                     -nop 
    ;
    // 004f229d  90                     -nop 
    ;
    // 004f229e  90                     -nop 
    ;
    // 004f229f  90                     -nop 
    ;
    // 004f22a0  90                     -nop 
    ;
    // 004f22a1  90                     -nop 
    ;
    // 004f22a2  90                     -nop 
    ;
    // 004f22a3  90                     -nop 
    ;
    // 004f22a4  90                     -nop 
    ;
    // 004f22a5  90                     -nop 
    ;
    // 004f22a6  90                     -nop 
    ;
    // 004f22a7  90                     -nop 
    ;
    // 004f22a8  90                     -nop 
    ;
    // 004f22a9  90                     -nop 
    ;
    // 004f22aa  90                     -nop 
    ;
    // 004f22ab  90                     -nop 
    ;
    // 004f22ac  90                     -nop 
    ;
    // 004f22ad  90                     -nop 
    ;
    // 004f22ae  90                     -nop 
    ;
    // 004f22af  90                     -nop 
    ;
L_entry_0x004f22b0:
    // 004f22b0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f22b1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f22b2  83ec24                 -sub esp, 0x24
    (cpu.esp) -= x86::reg32(x86::sreg32(36 /*0x24*/));
    // 004f22b5  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004f22b7  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004f22b9  e872c80100             -call 0x50eb30
    cpu.esp -= 4;
    sub_50eb30(app, cpu);
    if (cpu.terminate) return;
    // 004f22be  3df4010000             +cmp eax, 0x1f4
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(500 /*0x1f4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f22c3  7c03                   -jl 0x4f22c8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004f22c8;
    }
    // 004f22c5  ff0424                 -inc dword ptr [esp]
    (app->getMemory<x86::reg32>(cpu.esp))++;
L_0x004f22c8:
    // 004f22c8  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004f22ca  e8d1c80100             -call 0x50eba0
    cpu.esp -= 4;
    sub_50eba0(app, cpu);
    if (cpu.terminate) return;
    // 004f22cf  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004f22d1  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004f22d3  7402                   -je 0x4f22d7
    if (cpu.flags.zf)
    {
        goto L_0x004f22d7;
    }
    // 004f22d5  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
L_0x004f22d7:
    // 004f22d7  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004f22d9  83c424                 -add esp, 0x24
    (cpu.esp) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 004f22dc  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f22dd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f22de  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_4f22e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f22e0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f22e1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f22e2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f22e3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f22e4  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004f22e7  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004f22e9  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004f22eb  b890010000             -mov eax, 0x190
    cpu.eax = 400 /*0x190*/;
    // 004f22f0  89e1                   -mov ecx, esp
    cpu.ecx = cpu.esp;
    // 004f22f2  8d5c2404               -lea ebx, [esp + 4]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004f22f6  8d542408               -lea edx, [esp + 8]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004f22fa  e8c1d40000             -call 0x4ff7c0
    cpu.esp -= 4;
    sub_4ff7c0(app, cpu);
    if (cpu.terminate) return;
    // 004f22ff  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004f2301  e8ca05ffff             -call 0x4e28d0
    cpu.esp -= 4;
    sub_4e28d0(app, cpu);
    if (cpu.terminate) return;
    // 004f2306  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 004f2309  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004f230b  750c                   -jne 0x4f2319
    if (!cpu.flags.zf)
    {
        goto L_0x004f2319;
    }
    // 004f230d  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004f230f  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004f2311  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004f2314  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2315  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2316  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2317  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2318  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f2319:
    // 004f2319  b9c2010000             -mov ecx, 0x1c2
    cpu.ecx = 450 /*0x1c2*/;
    // 004f231e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004f2320  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004f2323  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004f2325  0590010000             -add eax, 0x190
    (cpu.eax) += x86::reg32(x86::sreg32(400 /*0x190*/));
    // 004f232a  e891d40000             -call 0x4ff7c0
    cpu.esp -= 4;
    sub_4ff7c0(app, cpu);
    if (cpu.terminate) return;
    // 004f232f  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004f2331  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 004f2334  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004f2338  e8a30affff             -call 0x4e2de0
    cpu.esp -= 4;
    sub_4e2de0(app, cpu);
    if (cpu.terminate) return;
    // 004f233d  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004f2340  a3f8435600             -mov dword ptr [0x5643f8], eax
    app->getMemory<x86::reg32>(x86::reg32(5653496) /* 0x5643f8 */) = cpu.eax;
    // 004f2345  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004f2349  e8520affff             -call 0x4e2da0
    cpu.esp -= 4;
    sub_4e2da0(app, cpu);
    if (cpu.terminate) return;
    // 004f234e  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004f2350  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004f2353  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2354  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2355  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2356  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2357  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_4f2360(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f2360  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f2361  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f2362  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004f2364  8b0d0c445600           -mov ecx, dword ptr [0x56440c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5653516) /* 0x56440c */);
    // 004f236a  891d0c445600           -mov dword ptr [0x56440c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5653516) /* 0x56440c */) = cpu.ebx;
    // 004f2370  e86bffffff             -call 0x4f22e0
    cpu.esp -= 4;
    sub_4f22e0(app, cpu);
    if (cpu.terminate) return;
    // 004f2375  890d0c445600           -mov dword ptr [0x56440c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5653516) /* 0x56440c */) = cpu.ecx;
    // 004f237b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f237c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f237d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_4f2380(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f2380  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f2381  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f2382  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f2383  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f2384  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f2385  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004f2387  83e63f                 -and esi, 0x3f
    cpu.esi &= x86::reg32(x86::sreg32(63 /*0x3f*/));
    // 004f238a  69f67e480600           -imul esi, esi, 0x6487e
    cpu.esi = x86::reg32(x86::sreg64(x86::sreg32(cpu.esi)) * x86::sreg64(x86::sreg32(411774 /*0x6487e*/)));
    // 004f2390  c1f806                 -sar eax, 6
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (6 /*0x6*/ % 32));
    // 004f2393  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004f2395  c0e407                 +shl ah, 7
    {
        x86::reg8 tmp = 7 /*0x7*/ % 32;
        x86::reg8& op = cpu.ah;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (8 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (8 - 1))));
        }
    }
    // 004f2398  19d2                   -sbb edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004f239a  00e4                   +add ah, ah
    {
        x86::reg8& tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.ah));
        x86::reg8 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) == (1 & (tmp2 >> 7));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004f239c  19c9                   -sbb ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
    // 004f239e  31c8                   -xor eax, ecx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004f23a0  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004f23a5  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004f23a7  8b0485ac725600         -mov eax, dword ptr [eax*4 + 0x5672ac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5665452) /* 0x5672ac */ + cpu.eax * 4);
    // 004f23ae  31d0                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004f23b0  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004f23b2  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004f23b4  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004f23b6  8d8800010000           -lea ecx, [eax + 0x100]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(256) /* 0x100 */);
    // 004f23bc  c0e507                 +shl ch, 7
    {
        x86::reg8 tmp = 7 /*0x7*/ % 32;
        x86::reg8& op = cpu.ch;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (8 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (8 - 1))));
        }
    }
    // 004f23bf  19d2                   -sbb edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004f23c1  00ed                   +add ch, ch
    {
        x86::reg8& tmp1 = cpu.ch;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.ch));
        x86::reg8 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) == (1 & (tmp2 >> 7));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004f23c3  19c9                   -sbb ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
    // 004f23c5  31c8                   -xor eax, ecx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004f23c7  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004f23cc  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004f23ce  8b0485ac725600         -mov eax, dword ptr [eax*4 + 0x5672ac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5665452) /* 0x5672ac */ + cpu.eax * 4);
    // 004f23d5  31d0                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004f23d7  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004f23d9  c1f802                 -sar eax, 2
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (2 /*0x2*/ % 32));
    // 004f23dc  c1fe09                 -sar esi, 9
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (9 /*0x9*/ % 32));
    // 004f23df  0fafc6                 -imul eax, esi
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 004f23e2  c1f815                 -sar eax, 0x15
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (21 /*0x15*/ % 32));
    // 004f23e5  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 004f23e7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f23e8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f23e9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f23ea  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f23eb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f23ec  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4f23f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f23f0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f23f1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f23f2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f23f3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f23f4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f23f5  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004f23f7  83e63f                 -and esi, 0x3f
    cpu.esi &= x86::reg32(x86::sreg32(63 /*0x3f*/));
    // 004f23fa  69f67e480600           -imul esi, esi, 0x6487e
    cpu.esi = x86::reg32(x86::sreg64(x86::sreg32(cpu.esi)) * x86::sreg64(x86::sreg32(411774 /*0x6487e*/)));
    // 004f2400  c1f806                 -sar eax, 6
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (6 /*0x6*/ % 32));
    // 004f2403  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004f2405  8d8800010000           -lea ecx, [eax + 0x100]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(256) /* 0x100 */);
    // 004f240b  c0e507                 +shl ch, 7
    {
        x86::reg8 tmp = 7 /*0x7*/ % 32;
        x86::reg8& op = cpu.ch;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (8 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (8 - 1))));
        }
    }
    // 004f240e  19d2                   -sbb edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004f2410  00ed                   +add ch, ch
    {
        x86::reg8& tmp1 = cpu.ch;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.ch));
        x86::reg8 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) == (1 & (tmp2 >> 7));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004f2412  19c9                   -sbb ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
    // 004f2414  31c8                   -xor eax, ecx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004f2416  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004f241b  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004f241d  8b0485ac725600         -mov eax, dword ptr [eax*4 + 0x5672ac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5665452) /* 0x5672ac */ + cpu.eax * 4);
    // 004f2424  31d0                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004f2426  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004f2428  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004f242a  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004f242c  c0e407                 +shl ah, 7
    {
        x86::reg8 tmp = 7 /*0x7*/ % 32;
        x86::reg8& op = cpu.ah;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (8 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (8 - 1))));
        }
    }
    // 004f242f  19d2                   -sbb edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004f2431  00e4                   +add ah, ah
    {
        x86::reg8& tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.ah));
        x86::reg8 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) == (1 & (tmp2 >> 7));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004f2433  19c9                   -sbb ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
    // 004f2435  31c8                   -xor eax, ecx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004f2437  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004f243c  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004f243e  8b0485ac725600         -mov eax, dword ptr [eax*4 + 0x5672ac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5665452) /* 0x5672ac */ + cpu.eax * 4);
    // 004f2445  31d0                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004f2447  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004f2449  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 004f244b  c1f802                 -sar eax, 2
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (2 /*0x2*/ % 32));
    // 004f244e  c1fe09                 -sar esi, 9
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (9 /*0x9*/ % 32));
    // 004f2451  0fafc6                 -imul eax, esi
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 004f2454  c1f815                 -sar eax, 0x15
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (21 /*0x15*/ % 32));
    // 004f2457  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 004f2459  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f245a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f245b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f245c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f245d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f245e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_4f2460(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f2460  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f2461  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004f2463  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f2465  7504                   -jne 0x4f246b
    if (!cpu.flags.zf)
    {
        goto L_0x004f246b;
    }
L_0x004f2467:
    // 004f2467  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f2469  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f246a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f246b:
    // 004f246b  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004f246d  83e07f                 -and eax, 0x7f
    cpu.eax &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 004f2470  8a80546d5600           -mov al, byte ptr [eax + 0x566d54]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5664084) /* 0x566d54 */);
    // 004f2476  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f2478  741d                   -je 0x4f2497
    if (cpu.flags.zf)
    {
        goto L_0x004f2497;
    }
L_0x004f247a:
    // 004f247a  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004f247c  74e9                   -je 0x4f2467
    if (cpu.flags.zf)
    {
        goto L_0x004f2467;
    }
    // 004f247e  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 004f2480  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004f2485  83f87c                 +cmp eax, 0x7c
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(124 /*0x7c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f2488  744b                   -je 0x4f24d5
    if (cpu.flags.zf)
    {
        goto L_0x004f24d5;
    }
    // 004f248a  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 004f248c  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 004f248f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f2491  7447                   -je 0x4f24da
    if (cpu.flags.zf)
    {
        goto L_0x004f24da;
    }
    // 004f2493  01c2                   +add edx, eax
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004f2495  ebe3                   -jmp 0x4f247a
    goto L_0x004f247a;
L_0x004f2497:
    // 004f2497  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f2498  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f2499  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f249a  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 004f249c  b9d4ca5400             -mov ecx, 0x54cad4
    cpu.ecx = 5556948 /*0x54cad4*/;
    // 004f24a1  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004f24a6  bbe4ca5400             -mov ebx, 0x54cae4
    cpu.ebx = 5556964 /*0x54cae4*/;
    // 004f24ab  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f24ac  be31000000             -mov esi, 0x31
    cpu.esi = 49 /*0x31*/;
    // 004f24b1  890d90215500           -mov dword ptr [0x552190], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ecx;
    // 004f24b7  68f8ca5400             -push 0x54caf8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5556984 /*0x54caf8*/;
    cpu.esp -= 4;
    // 004f24bc  891d94215500           -mov dword ptr [0x552194], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebx;
    // 004f24c2  893598215500           -mov dword ptr [0x552198], esi
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.esi;
    // 004f24c8  e843ebf0ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004f24cd  83c408                 +add esp, 8
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004f24d0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f24d1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f24d2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f24d3  eba5                   -jmp 0x4f247a
    goto L_0x004f247a;
L_0x004f24d5:
    // 004f24d5  8d4208                 -lea eax, [edx + 8]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004f24d8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f24d9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f24da:
    // 004f24da  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004f24dc  eb9c                   -jmp 0x4f247a
    goto L_0x004f247a;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4f24e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f24e0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f24e1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004f24e3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f24e5  7504                   -jne 0x4f24eb
    if (!cpu.flags.zf)
    {
        goto L_0x004f24eb;
    }
L_0x004f24e7:
    // 004f24e7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f24e9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f24ea  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f24eb:
    // 004f24eb  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004f24ed  83e07f                 -and eax, 0x7f
    cpu.eax &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 004f24f0  8a80546d5600           -mov al, byte ptr [eax + 0x566d54]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5664084) /* 0x566d54 */);
    // 004f24f6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f24f8  741d                   -je 0x4f2517
    if (cpu.flags.zf)
    {
        goto L_0x004f2517;
    }
L_0x004f24fa:
    // 004f24fa  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004f24fc  74e9                   -je 0x4f24e7
    if (cpu.flags.zf)
    {
        goto L_0x004f24e7;
    }
    // 004f24fe  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 004f2500  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004f2505  83f86f                 +cmp eax, 0x6f
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(111 /*0x6f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f2508  744b                   -je 0x4f2555
    if (cpu.flags.zf)
    {
        goto L_0x004f2555;
    }
    // 004f250a  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 004f250c  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 004f250f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f2511  7447                   -je 0x4f255a
    if (cpu.flags.zf)
    {
        goto L_0x004f255a;
    }
    // 004f2513  01c2                   +add edx, eax
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004f2515  ebe3                   -jmp 0x4f24fa
    goto L_0x004f24fa;
L_0x004f2517:
    // 004f2517  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f2518  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f2519  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f251a  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 004f251c  b9d4ca5400             -mov ecx, 0x54cad4
    cpu.ecx = 5556948 /*0x54cad4*/;
    // 004f2521  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004f2526  bb28cb5400             -mov ebx, 0x54cb28
    cpu.ebx = 5557032 /*0x54cb28*/;
    // 004f252b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f252c  be69000000             -mov esi, 0x69
    cpu.esi = 105 /*0x69*/;
    // 004f2531  890d90215500           -mov dword ptr [0x552190], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ecx;
    // 004f2537  6838cb5400             -push 0x54cb38
    app->getMemory<x86::reg32>(cpu.esp-4) = 5557048 /*0x54cb38*/;
    cpu.esp -= 4;
    // 004f253c  891d94215500           -mov dword ptr [0x552194], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebx;
    // 004f2542  893598215500           -mov dword ptr [0x552198], esi
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.esi;
    // 004f2548  e8c3eaf0ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004f254d  83c408                 +add esp, 8
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004f2550  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2551  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2552  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2553  eba5                   -jmp 0x4f24fa
    goto L_0x004f24fa;
L_0x004f2555:
    // 004f2555  8d4208                 -lea eax, [edx + 8]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004f2558  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2559  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f255a:
    // 004f255a  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004f255c  eb9c                   -jmp 0x4f24fa
    goto L_0x004f24fa;
}

/* align: skip 0x00 0x00 */
void Application::sub_4f2560(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f2560  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f2561  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f2562  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004f2564  8a6001                 -mov ah, byte ptr [eax + 1]
    cpu.ah = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004f2567  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004f2569  80fcfb                 +cmp ah, 0xfb
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(251 /*0xfb*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f256c  7519                   -jne 0x4f2587
    if (!cpu.flags.zf)
    {
        goto L_0x004f2587;
    }
L_0x004f256e:
    // 004f256e  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004f2570  24fe                   -and al, 0xfe
    cpu.al &= x86::reg8(x86::sreg8(254 /*0xfe*/));
    // 004f2572  3c32                   +cmp al, 0x32
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(50 /*0x32*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f2574  731c                   -jae 0x4f2592
    if (!cpu.flags.cf)
    {
        goto L_0x004f2592;
    }
    // 004f2576  3c18                   +cmp al, 0x18
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(24 /*0x18*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f2578  7362                   -jae 0x4f25dc
    if (!cpu.flags.cf)
    {
        goto L_0x004f25dc;
    }
    // 004f257a  3c10                   +cmp al, 0x10
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(16 /*0x10*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f257c  0f8465000000           -je 0x4f25e7
    if (cpu.flags.zf)
    {
        goto L_0x004f25e7;
    }
L_0x004f2582:
    // 004f2582  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004f2584  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2585  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2586  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f2587:
    // 004f2587  807e0132               +cmp byte ptr [esi + 1], 0x32
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(50 /*0x32*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f258b  74e1                   -je 0x4f256e
    if (cpu.flags.zf)
    {
        goto L_0x004f256e;
    }
    // 004f258d  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004f258f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2590  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2591  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f2592:
    // 004f2592  7608                   -jbe 0x4f259c
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004f259c;
    }
    // 004f2594  3c46                   +cmp al, 0x46
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(70 /*0x46*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f2596  7317                   -jae 0x4f25af
    if (!cpu.flags.cf)
    {
        goto L_0x004f25af;
    }
    // 004f2598  3c34                   +cmp al, 0x34
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(52 /*0x34*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f259a  75e6                   -jne 0x4f2582
    if (!cpu.flags.zf)
    {
        goto L_0x004f2582;
    }
L_0x004f259c:
    // 004f259c  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004f25a1  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004f25a3  e8a8c70100             -call 0x50ed50
    cpu.esp -= 4;
    sub_50ed50(app, cpu);
    if (cpu.terminate) return;
    // 004f25a8  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004f25aa  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004f25ac  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f25ad  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f25ae  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f25af:
    // 004f25af  765c                   -jbe 0x4f260d
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004f260d;
    }
    // 004f25b1  3c4a                   +cmp al, 0x4a
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(74 /*0x4a*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f25b3  75cd                   -jne 0x4f2582
    if (!cpu.flags.zf)
    {
        goto L_0x004f2582;
    }
    // 004f25b5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f25b6  b903000000             -mov ecx, 3
    cpu.ecx = 3 /*0x3*/;
    // 004f25bb  8d4602                 -lea eax, [esi + 2]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 004f25be  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004f25c0  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 004f25c2  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004f25c4  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 004f25cb  d3e8                   +shr eax, cl
    {
        x86::reg8 tmp = cpu.cl % 32;
        x86::reg32& op = cpu.eax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 004f25cd  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004f25cf  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004f25d1  e83adb0100             -call 0x510110
    cpu.esp -= 4;
    sub_510110(app, cpu);
    if (cpu.terminate) return;
    // 004f25d6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f25d7  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004f25d9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f25da  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f25db  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f25dc:
    // 004f25dc  761c                   -jbe 0x4f25fa
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004f25fa;
    }
    // 004f25de  3c30                   +cmp al, 0x30
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
    // 004f25e0  74ba                   -je 0x4f259c
    if (cpu.flags.zf)
    {
        goto L_0x004f259c;
    }
    // 004f25e2  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004f25e4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f25e5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f25e6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f25e7:
    // 004f25e7  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004f25ec  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004f25ee  e8b1dc0100             -call 0x5102a4
    cpu.esp -= 4;
    sub_5102a4(app, cpu);
    if (cpu.terminate) return;
    // 004f25f3  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004f25f5  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004f25f7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f25f8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f25f9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f25fa:
    // 004f25fa  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004f25ff  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004f2601  e85ae10100             -call 0x510760
    cpu.esp -= 4;
    sub_510760(app, cpu);
    if (cpu.terminate) return;
    // 004f2606  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004f2608  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004f260a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f260b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f260c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f260d:
    // 004f260d  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004f260f  e85ce20100             -call 0x510870
    cpu.esp -= 4;
    sub_510870(app, cpu);
    if (cpu.terminate) return;
    // 004f2614  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004f2616  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004f2618  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2619  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f261a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_4f2620(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f2620  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f2621  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f2622  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004f2624  e837ffffff             -call 0x4f2560
    cpu.esp -= 4;
    sub_4f2560(app, cpu);
    if (cpu.terminate) return;
    // 004f2629  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004f262b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f262d  751b                   -jne 0x4f264a
    if (!cpu.flags.zf)
    {
        goto L_0x004f264a;
    }
    // 004f262f  833d0c44560000         +cmp dword ptr [0x56440c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5653516) /* 0x56440c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f2636  7412                   -je 0x4f264a
    if (cpu.flags.zf)
    {
        goto L_0x004f264a;
    }
    // 004f2638  8a23                   -mov ah, byte ptr [ebx]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebx);
    // 004f263a  80fc10                 +cmp ah, 0x10
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(16 /*0x10*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f263d  720b                   -jb 0x4f264a
    if (cpu.flags.cf)
    {
        goto L_0x004f264a;
    }
    // 004f263f  80fc80                 +cmp ah, 0x80
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(128 /*0x80*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f2642  7306                   -jae 0x4f264a
    if (!cpu.flags.cf)
    {
        goto L_0x004f264a;
    }
    // 004f2644  807b01fb               +cmp byte ptr [ebx + 1], 0xfb
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(1) /* 0x1 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(251 /*0xfb*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f2648  7405                   -je 0x4f264f
    if (cpu.flags.zf)
    {
        goto L_0x004f264f;
    }
L_0x004f264a:
    // 004f264a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004f264c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f264d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f264e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f264f:
    // 004f264f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f2650  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f2651  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f2652  be68cb5400             -mov esi, 0x54cb68
    cpu.esi = 5557096 /*0x54cb68*/;
    // 004f2657  bf78cb5400             -mov edi, 0x54cb78
    cpu.edi = 5557112 /*0x54cb78*/;
    // 004f265c  bd6d000000             -mov ebp, 0x6d
    cpu.ebp = 109 /*0x6d*/;
    // 004f2661  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 004f2666  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004f2668  893590215500           -mov dword ptr [0x552190], esi
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.esi;
    // 004f266e  893d94215500           -mov dword ptr [0x552194], edi
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.edi;
    // 004f2674  892d98215500           -mov dword ptr [0x552198], ebp
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ebp;
    // 004f267a  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004f267c  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 004f267e  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004f2680  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 004f2687  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 004f2689  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f268a  6880cb5400             -push 0x54cb80
    app->getMemory<x86::reg32>(cpu.esp-4) = 5557120 /*0x54cb80*/;
    cpu.esp -= 4;
    // 004f268f  e87ce9f0ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004f2694  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004f2697  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2698  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2699  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f269a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004f269c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f269d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f269e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4f26a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f26a0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f26a1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f26a2  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004f26a4  8a6001                 -mov ah, byte ptr [eax + 1]
    cpu.ah = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004f26a7  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004f26a9  80fcfb                 +cmp ah, 0xfb
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(251 /*0xfb*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f26ac  7515                   -jne 0x4f26c3
    if (!cpu.flags.zf)
    {
        goto L_0x004f26c3;
    }
L_0x004f26ae:
    // 004f26ae  8a02                   -mov al, byte ptr [edx]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx);
    // 004f26b0  24fe                   -and al, 0xfe
    cpu.al &= x86::reg8(x86::sreg8(254 /*0xfe*/));
    // 004f26b2  3c32                   +cmp al, 0x32
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(50 /*0x32*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f26b4  7318                   -jae 0x4f26ce
    if (!cpu.flags.cf)
    {
        goto L_0x004f26ce;
    }
    // 004f26b6  3c18                   +cmp al, 0x18
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(24 /*0x18*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f26b8  7349                   -jae 0x4f2703
    if (!cpu.flags.cf)
    {
        goto L_0x004f2703;
    }
    // 004f26ba  3c10                   +cmp al, 0x10
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(16 /*0x10*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f26bc  741a                   -je 0x4f26d8
    if (cpu.flags.zf)
    {
        goto L_0x004f26d8;
    }
L_0x004f26be:
    // 004f26be  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004f26c0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f26c1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f26c2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f26c3:
    // 004f26c3  807a0132               +cmp byte ptr [edx + 1], 0x32
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(50 /*0x32*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f26c7  74e5                   -je 0x4f26ae
    if (cpu.flags.zf)
    {
        goto L_0x004f26ae;
    }
    // 004f26c9  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004f26cb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f26cc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f26cd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f26ce:
    // 004f26ce  7608                   -jbe 0x4f26d8
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004f26d8;
    }
    // 004f26d0  3c46                   +cmp al, 0x46
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(70 /*0x46*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f26d2  7322                   -jae 0x4f26f6
    if (!cpu.flags.cf)
    {
        goto L_0x004f26f6;
    }
    // 004f26d4  3c34                   +cmp al, 0x34
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(52 /*0x34*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f26d6  75e6                   -jne 0x4f26be
    if (!cpu.flags.zf)
    {
        goto L_0x004f26be;
    }
L_0x004f26d8:
    // 004f26d8  b903000000             -mov ecx, 3
    cpu.ecx = 3 /*0x3*/;
    // 004f26dd  8d4202                 -lea eax, [edx + 2]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 004f26e0  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004f26e2  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 004f26e4  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004f26e6  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 004f26ed  d3e8                   +shr eax, cl
    {
        x86::reg8 tmp = cpu.cl % 32;
        x86::reg32& op = cpu.eax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 004f26ef  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004f26f1  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004f26f3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f26f4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f26f5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f26f6:
    // 004f26f6  76e0                   -jbe 0x4f26d8
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004f26d8;
    }
    // 004f26f8  3c4a                   +cmp al, 0x4a
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(74 /*0x4a*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f26fa  72c2                   -jb 0x4f26be
    if (cpu.flags.cf)
    {
        goto L_0x004f26be;
    }
    // 004f26fc  76da                   -jbe 0x4f26d8
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004f26d8;
    }
    // 004f26fe  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004f2700  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2701  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2702  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f2703:
    // 004f2703  76d3                   -jbe 0x4f26d8
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004f26d8;
    }
    // 004f2705  3c30                   +cmp al, 0x30
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
    // 004f2707  74cf                   -je 0x4f26d8
    if (cpu.flags.zf)
    {
        goto L_0x004f26d8;
    }
    // 004f2709  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004f270b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f270c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f270d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4f2710(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f2710  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f2711  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f2712  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004f2714  e887ffffff             -call 0x4f26a0
    cpu.esp -= 4;
    sub_4f26a0(app, cpu);
    if (cpu.terminate) return;
    // 004f2719  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004f271b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f271d  7512                   -jne 0x4f2731
    if (!cpu.flags.zf)
    {
        goto L_0x004f2731;
    }
    // 004f271f  8a22                   -mov ah, byte ptr [edx]
    cpu.ah = app->getMemory<x86::reg8>(cpu.edx);
    // 004f2721  80fc10                 +cmp ah, 0x10
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(16 /*0x10*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f2724  720b                   -jb 0x4f2731
    if (cpu.flags.cf)
    {
        goto L_0x004f2731;
    }
    // 004f2726  80fc80                 +cmp ah, 0x80
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(128 /*0x80*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f2729  7306                   -jae 0x4f2731
    if (!cpu.flags.cf)
    {
        goto L_0x004f2731;
    }
    // 004f272b  807a01fb               +cmp byte ptr [edx + 1], 0xfb
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(251 /*0xfb*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f272f  7405                   -je 0x4f2736
    if (cpu.flags.zf)
    {
        goto L_0x004f2736;
    }
L_0x004f2731:
    // 004f2731  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004f2733  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2734  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2735  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f2736:
    // 004f2736  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f2737  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f2738  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f2739  b968cb5400             -mov ecx, 0x54cb68
    cpu.ecx = 5557096 /*0x54cb68*/;
    // 004f273e  bea4cb5400             -mov esi, 0x54cba4
    cpu.esi = 5557156 /*0x54cba4*/;
    // 004f2743  bfc9000000             -mov edi, 0xc9
    cpu.edi = 201 /*0xc9*/;
    // 004f2748  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004f274a  890d90215500           -mov dword ptr [0x552190], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ecx;
    // 004f2750  893594215500           -mov dword ptr [0x552194], esi
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.esi;
    // 004f2756  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 004f275b  893d98215500           -mov dword ptr [0x552198], edi
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.edi;
    // 004f2761  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004f2763  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 004f2765  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004f2767  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 004f276e  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 004f2770  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f2771  68b0cb5400             -push 0x54cbb0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5557168 /*0x54cbb0*/;
    cpu.esp -= 4;
    // 004f2776  e895e8f0ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004f277b  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004f277e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f277f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2780  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2781  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004f2783  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2784  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2785  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4f2790(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f2790  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f2791  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f2792  ff1564465300           -call dword ptr [0x534664]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457508) /* 0x534664 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f2798  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2799  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f279a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4f279c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f279c  90                     -nop 
    ;
    // 004f279d  90                     -nop 
    ;
    // 004f279e  90                     -nop 
    ;
    // 004f279f  90                     -nop 
    ;
    // 004f27a0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f27a1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f27a2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f27a3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f27a4  e857d3feff             -call 0x4dfb00
    cpu.esp -= 4;
    sub_4dfb00(app, cpu);
    if (cpu.terminate) return;
    // 004f27a9  8b15340c9f00           -mov edx, dword ptr [0x9f0c34]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10423348) /* 0x9f0c34 */);
    // 004f27af  a3ac525600             -mov dword ptr [0x5652ac], eax
    app->getMemory<x86::reg32>(x86::reg32(5657260) /* 0x5652ac */) = cpu.eax;
    // 004f27b4  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004f27b6  7455                   -je 0x4f280d
    if (cpu.flags.zf)
    {
        goto L_0x004f280d;
    }
L_0x004f27b8:
    // 004f27b8  a1ac525600             -mov eax, dword ptr [0x5652ac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5657260) /* 0x5652ac */);
    // 004f27bd  e8aed3feff             -call 0x4dfb70
    cpu.esp -= 4;
    sub_4dfb70(app, cpu);
    if (cpu.terminate) return;
    // 004f27c2  8b1d340c9f00           -mov ebx, dword ptr [0x9f0c34]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10423348) /* 0x9f0c34 */);
    // 004f27c8  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004f27ca  7438                   -je 0x4f2804
    if (cpu.flags.zf)
    {
        goto L_0x004f2804;
    }
    // 004f27cc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f27cd  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f27d3  8b3d000c9f00           -mov edi, dword ptr [0x9f0c00]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(10423296) /* 0x9f0c00 */);
    // 004f27d9  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004f27db  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004f27dd  7419                   -je 0x4f27f8
    if (cpu.flags.zf)
    {
        goto L_0x004f27f8;
    }
L_0x004f27df:
    // 004f27df  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004f27e1  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f27e4  ff90000c9f00           -call dword ptr [eax + 0x9f0c00]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(10423296) /* 0x9f0c00 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f27ea  83fa20                 +cmp edx, 0x20
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f27ed  7d09                   -jge 0x4f27f8
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004f27f8;
    }
    // 004f27ef  83ba000c9f0000         +cmp dword ptr [edx + 0x9f0c00], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(10423296) /* 0x9f0c00 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f27f6  75e7                   -jne 0x4f27df
    if (!cpu.flags.zf)
    {
        goto L_0x004f27df;
    }
L_0x004f27f8:
    // 004f27f8  a1340c9f00             -mov eax, dword ptr [0x9f0c34]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10423348) /* 0x9f0c34 */);
    // 004f27fd  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f27fe  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004f2804:
    // 004f2804  833d340c9f0000         +cmp dword ptr [0x9f0c34], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10423348) /* 0x9f0c34 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f280b  75ab                   -jne 0x4f27b8
    if (!cpu.flags.zf)
    {
        goto L_0x004f27b8;
    }
L_0x004f280d:
    // 004f280d  a1ac525600             -mov eax, dword ptr [0x5652ac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5657260) /* 0x5652ac */);
    // 004f2812  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004f2814  e8e7d3feff             -call 0x4dfc00
    cpu.esp -= 4;
    sub_4dfc00(app, cpu);
    if (cpu.terminate) return;
    // 004f2819  8915ac525600           -mov dword ptr [0x5652ac], edx
    app->getMemory<x86::reg32>(x86::reg32(5657260) /* 0x5652ac */) = cpu.edx;
    // 004f281f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2820  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2821  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2822  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2823  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_4f2830(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f2830  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f2831  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f2832  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f2833  8b15340c9f00           -mov edx, dword ptr [0x9f0c34]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10423348) /* 0x9f0c34 */);
    // 004f2839  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004f283b  7504                   -jne 0x4f2841
    if (!cpu.flags.zf)
    {
        goto L_0x004f2841;
    }
L_0x004f283d:
    // 004f283d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f283e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f283f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2840  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f2841:
    // 004f2841  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f2842  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004f2844  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f284a  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004f284c  a1ac525600             -mov eax, dword ptr [0x5652ac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5657260) /* 0x5652ac */);
    // 004f2851  890d340c9f00           -mov dword ptr [0x9f0c34], ecx
    app->getMemory<x86::reg32>(x86::reg32(10423348) /* 0x9f0c34 */) = cpu.ecx;
    // 004f2857  e8d4d2feff             -call 0x4dfb30
    cpu.esp -= 4;
    sub_4dfb30(app, cpu);
    if (cpu.terminate) return;
    // 004f285c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f285d  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f2863  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004f2865  e8f68affff             -call 0x4eb360
    cpu.esp -= 4;
    sub_4eb360(app, cpu);
    if (cpu.terminate) return;
    // 004f286a  b8200c9f00             -mov eax, 0x9f0c20
    cpu.eax = 10423328 /*0x9f0c20*/;
    // 004f286f  e8bcd0feff             -call 0x4df930
    cpu.esp -= 4;
    sub_4df930(app, cpu);
    if (cpu.terminate) return;
    // 004f2874  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f2876  75c5                   -jne 0x4f283d
    if (!cpu.flags.zf)
    {
        goto L_0x004f283d;
    }
    // 004f2878  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x004f287a:
    // 004f287a  3b1dac525600           +cmp ebx, dword ptr [0x5652ac]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5657260) /* 0x5652ac */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f2880  74bb                   -je 0x4f283d
    if (cpu.flags.zf)
    {
        goto L_0x004f283d;
    }
    // 004f2882  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004f2884  e857d0feff             -call 0x4df8e0
    cpu.esp -= 4;
    sub_4df8e0(app, cpu);
    if (cpu.terminate) return;
    // 004f2889  ebef                   -jmp 0x4f287a
    goto L_0x004f287a;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_4f2890(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f2890  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f2891  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f2892  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f2893  b830284f00             -mov eax, 0x4f2830
    cpu.eax = 5187632 /*0x4f2830*/;
    // 004f2898  e8db010000             -call 0x4f2a78
    cpu.esp -= 4;
    sub_4f2a78(app, cpu);
    if (cpu.terminate) return;
    // 004f289d  e83e8affff             -call 0x4eb2e0
    cpu.esp -= 4;
    sub_4eb2e0(app, cpu);
    if (cpu.terminate) return;
    // 004f28a2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f28a3  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 004f28a8  a3340c9f00             -mov dword ptr [0x9f0c34], eax
    app->getMemory<x86::reg32>(x86::reg32(10423348) /* 0x9f0c34 */) = cpu.eax;
    // 004f28ad  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f28b3  68200c9f00             -push 0x9f0c20
    app->getMemory<x86::reg32>(cpu.esp-4) = 10423328 /*0x9f0c20*/;
    cpu.esp -= 4;
    // 004f28b8  b9ffffffff             -mov ecx, 0xffffffff
    cpu.ecx = 4294967295 /*0xffffffff*/;
    // 004f28bd  b8a0274f00             -mov eax, 0x4f27a0
    cpu.eax = 5187488 /*0x4f27a0*/;
    // 004f28c2  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004f28c4  e8d7cefeff             -call 0x4df7a0
    cpu.esp -= 4;
    sub_4df7a0(app, cpu);
    if (cpu.terminate) return;
    // 004f28c9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f28cb  7548                   -jne 0x4f2915
    if (!cpu.flags.zf)
    {
        goto L_0x004f2915;
    }
    // 004f28cd  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f28ce  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f28cf  bbd8cb5400             -mov ebx, 0x54cbd8
    cpu.ebx = 5557208 /*0x54cbd8*/;
    // 004f28d4  bee8cb5400             -mov esi, 0x54cbe8
    cpu.esi = 5557224 /*0x54cbe8*/;
    // 004f28d9  a1340c9f00             -mov eax, dword ptr [0x9f0c34]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10423348) /* 0x9f0c34 */);
    // 004f28de  bf4d000000             -mov edi, 0x4d
    cpu.edi = 77 /*0x4d*/;
    // 004f28e3  e8788affff             -call 0x4eb360
    cpu.esp -= 4;
    sub_4eb360(app, cpu);
    if (cpu.terminate) return;
    // 004f28e8  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004f28ea  68f8cb5400             -push 0x54cbf8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5557240 /*0x54cbf8*/;
    cpu.esp -= 4;
    // 004f28ef  890d340c9f00           -mov dword ptr [0x9f0c34], ecx
    app->getMemory<x86::reg32>(x86::reg32(10423348) /* 0x9f0c34 */) = cpu.ecx;
    // 004f28f5  891d90215500           -mov dword ptr [0x552190], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ebx;
    // 004f28fb  893594215500           -mov dword ptr [0x552194], esi
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.esi;
    // 004f2901  893d98215500           -mov dword ptr [0x552198], edi
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.edi;
    // 004f2907  e804e7f0ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004f290c  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f290f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2910  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2911  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2912  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2913  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2914  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f2915:
    // 004f2915  8b15340c9f00           -mov edx, dword ptr [0x9f0c34]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10423348) /* 0x9f0c34 */);
    // 004f291b  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f291c  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f2922  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2923  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2924  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2925  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void Application::sub_4f2930(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f2930  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f2931  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f2932  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f2933  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f2934  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004f2936  8b15340c9f00           -mov edx, dword ptr [0x9f0c34]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10423348) /* 0x9f0c34 */);
    // 004f293c  bbffffffff             -mov ebx, 0xffffffff
    cpu.ebx = 4294967295 /*0xffffffff*/;
    // 004f2941  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004f2943  744d                   -je 0x4f2992
    if (cpu.flags.zf)
    {
        goto L_0x004f2992;
    }
L_0x004f2945:
    // 004f2945  8b0d340c9f00           -mov ecx, dword ptr [0x9f0c34]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10423348) /* 0x9f0c34 */);
    // 004f294b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f294c  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f2952  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004f2954  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004f2956:
    // 004f2956  83b8000c9f0000         +cmp dword ptr [eax + 0x9f0c00], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(10423296) /* 0x9f0c00 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f295d  7504                   -jne 0x4f2963
    if (!cpu.flags.zf)
    {
        goto L_0x004f2963;
    }
    // 004f295f  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004f2961  7c36                   -jl 0x4f2999
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004f2999;
    }
L_0x004f2963:
    // 004f2963  3bb0000c9f00           +cmp esi, dword ptr [eax + 0x9f0c00]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(10423296) /* 0x9f0c00 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f2969  7432                   -je 0x4f299d
    if (cpu.flags.zf)
    {
        goto L_0x004f299d;
    }
L_0x004f296b:
    // 004f296b  42                     -inc edx
    (cpu.edx)++;
    // 004f296c  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f296f  83fa08                 +cmp edx, 8
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f2972  7ce2                   -jl 0x4f2956
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004f2956;
    }
    // 004f2974  83fbff                 +cmp ebx, -1
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
    // 004f2977  7407                   -je 0x4f2980
    if (cpu.flags.zf)
    {
        goto L_0x004f2980;
    }
    // 004f2979  89349d000c9f00         -mov dword ptr [ebx*4 + 0x9f0c00], esi
    app->getMemory<x86::reg32>(x86::reg32(10423296) /* 0x9f0c00 */ + cpu.ebx * 4) = cpu.esi;
L_0x004f2980:
    // 004f2980  8b15340c9f00           -mov edx, dword ptr [0x9f0c34]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10423348) /* 0x9f0c34 */);
    // 004f2986  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f2987  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f298d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f298e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f298f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2990  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2991  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f2992:
    // 004f2992  e8f9feffff             -call 0x4f2890
    cpu.esp -= 4;
    sub_4f2890(app, cpu);
    if (cpu.terminate) return;
    // 004f2997  ebac                   -jmp 0x4f2945
    goto L_0x004f2945;
L_0x004f2999:
    // 004f2999  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004f299b  ebce                   -jmp 0x4f296b
    goto L_0x004f296b;
L_0x004f299d:
    // 004f299d  a1340c9f00             -mov eax, dword ptr [0x9f0c34]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10423348) /* 0x9f0c34 */);
    // 004f29a2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f29a3  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f29a9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f29aa  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f29ab  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f29ac  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f29ad  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4f29b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f29b0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f29b1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f29b2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f29b3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f29b4  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004f29b6  8b15340c9f00           -mov edx, dword ptr [0x9f0c34]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10423348) /* 0x9f0c34 */);
    // 004f29bc  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004f29be  7505                   -jne 0x4f29c5
    if (!cpu.flags.zf)
    {
        goto L_0x004f29c5;
    }
L_0x004f29c0:
    // 004f29c0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f29c1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f29c2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f29c3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f29c4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f29c5:
    // 004f29c5  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f29c6  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f29cc  8b35000c9f00           -mov esi, dword ptr [0x9f0c00]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(10423296) /* 0x9f0c00 */);
    // 004f29d2  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004f29d4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f29d6  39f3                   +cmp ebx, esi
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
    // 004f29d8  7411                   -je 0x4f29eb
    if (cpu.flags.zf)
    {
        goto L_0x004f29eb;
    }
L_0x004f29da:
    // 004f29da  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f29dd  42                     -inc edx
    (cpu.edx)++;
    // 004f29de  83f820                 +cmp eax, 0x20
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f29e1  7d08                   -jge 0x4f29eb
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004f29eb;
    }
    // 004f29e3  3b98000c9f00           +cmp ebx, dword ptr [eax + 0x9f0c00]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(10423296) /* 0x9f0c00 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f29e9  75ef                   -jne 0x4f29da
    if (!cpu.flags.zf)
    {
        goto L_0x004f29da;
    }
L_0x004f29eb:
    // 004f29eb  83fa08                 +cmp edx, 8
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f29ee  7d37                   -jge 0x4f2a27
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004f2a27;
    }
    // 004f29f0  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 004f29f7  3b98000c9f00           +cmp ebx, dword ptr [eax + 0x9f0c00]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(10423296) /* 0x9f0c00 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f29fd  7528                   -jne 0x4f2a27
    if (!cpu.flags.zf)
    {
        goto L_0x004f2a27;
    }
    // 004f29ff  83fa07                 +cmp edx, 7
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(7 /*0x7*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f2a02  7d1c                   -jge 0x4f2a20
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004f2a20;
    }
L_0x004f2a04:
    // 004f2a04  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f2a07  8b90000c9f00           -mov edx, dword ptr [eax + 0x9f0c00]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(10423296) /* 0x9f0c00 */);
    // 004f2a0d  8990fc0b9f00           -mov dword ptr [eax + 0x9f0bfc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(10423292) /* 0x9f0bfc */) = cpu.edx;
    // 004f2a13  83f81c                 +cmp eax, 0x1c
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(28 /*0x1c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f2a16  7cec                   -jl 0x4f2a04
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004f2a04;
    }
    // 004f2a18  8d8000000000           -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 004f2a1e  8bd2                   -mov edx, edx
    cpu.edx = cpu.edx;
L_0x004f2a20:
    // 004f2a20  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f2a22  a31c0c9f00             -mov dword ptr [0x9f0c1c], eax
    app->getMemory<x86::reg32>(x86::reg32(10423324) /* 0x9f0c1c */) = cpu.eax;
L_0x004f2a27:
    // 004f2a27  8b15340c9f00           -mov edx, dword ptr [0x9f0c34]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10423348) /* 0x9f0c34 */);
    // 004f2a2d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f2a2e  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f2a34  8b0d000c9f00           -mov ecx, dword ptr [0x9f0c00]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10423296) /* 0x9f0c00 */);
    // 004f2a3a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f2a3c  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
L_0x004f2a3e:
    // 004f2a3e  7580                   -jne 0x4f29c0
    if (!cpu.flags.zf)
    {
        goto L_0x004f29c0;
    }
    // 004f2a40  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f2a43  83f820                 +cmp eax, 0x20
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f2a46  7d09                   -jge 0x4f2a51
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004f2a51;
    }
    // 004f2a48  83b8000c9f0000         +cmp dword ptr [eax + 0x9f0c00], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(10423296) /* 0x9f0c00 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f2a4f  ebed                   -jmp 0x4f2a3e
    goto L_0x004f2a3e;
L_0x004f2a51:
    // 004f2a51  e8dafdffff             -call 0x4f2830
    cpu.esp -= 4;
    sub_4f2830(app, cpu);
    if (cpu.terminate) return;
    // 004f2a56  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2a57  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2a58  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2a59  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2a5a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_4f2a60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f2a60  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f2a61  8b15ac525600           -mov edx, dword ptr [0x5652ac]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5657260) /* 0x5652ac */);
    // 004f2a67  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004f2a69  7502                   -jne 0x4f2a6d
    if (!cpu.flags.zf)
    {
        goto L_0x004f2a6d;
    }
    // 004f2a6b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2a6c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f2a6d:
    // 004f2a6d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004f2a6f  e8bcd0feff             -call 0x4dfb30
    cpu.esp -= 4;
    sub_4dfb30(app, cpu);
    if (cpu.terminate) return;
    // 004f2a74  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2a75  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_4f2a78(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f2a78  e9a3510000             -jmp 0x4f7c20
    return sub_4f7c20(app, cpu);
}

/* align: skip  */
void Application::sub_4f2a7d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 004f2a7d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f2a7f  e880d2feff             -call 0x4dfd04
    cpu.esp -= 4;
    sub_4dfd04(app, cpu);
    if (cpu.terminate) return;
    // 004f2a84  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004f2a86  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004f2a88  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004f2a8a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004f2a8c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004f2a8e  0000                   +add byte ptr [eax], al
    {
        auto tmp1 = app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.al));
        x86::reg8 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) == (1 & (tmp2 >> 7));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004f2a90  142b                   -adc al, 0x2b
    (cpu.al) += x86::reg8(x86::sreg8(43 /*0x2b*/) + cpu.flags.cf);
    // 004f2a92  4f                     -dec edi
    (cpu.edi)--;
    // 004f2a93  00c3                   -add bl, al
    (cpu.bl) += x86::reg8(x86::sreg8(cpu.al));
    // 004f2a95  2b4f00                 -sub ecx, dword ptr [edi]
    (cpu.ecx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi)));
    // 004f2a98  b82b4f00ad             -mov eax, 0xad004f2b
    cpu.eax = 2902478635 /*0xad004f2b*/;
    // 004f2a9d  2b4f00                 -sub ecx, dword ptr [edi]
    (cpu.ecx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi)));
    // 004f2aa0  a22b4f0097             -mov byte ptr [0x97004f2b], al
    app->getMemory<x86::reg8>(x86::reg32(2533379883) /* 0x97004f2b */) = cpu.al;
    // 004f2aa5  2b4f00                 -sub ecx, dword ptr [edi]
    (cpu.ecx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi)));
    // 004f2aa8  8c2b                   -mov word ptr [ebx], gs
    app->getMemory<x86::reg16>(cpu.ebx) = cpu.gs;
    // 004f2aaa  4f                     -dec edi
    (cpu.edi)--;
    // 004f2aab  00812b4f0076           -add byte ptr [ecx + 0x76004f2b], al
    (app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1979731755) /* 0x76004f2b */)) += x86::reg8(x86::sreg8(cpu.al));
    // 004f2ab1  2b4f00                 -sub ecx, dword ptr [edi]
    (cpu.ecx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi)));
    // 004f2ab4  6b2b4f                 -imul ebp, dword ptr [ebx], 0x4f
    cpu.ebp = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx))) * x86::sreg64(x86::sreg32(79 /*0x4f*/)));
    // 004f2ab7  00602b                 -add byte ptr [eax + 0x2b], ah
    (app->getMemory<x86::reg8>(cpu.eax + x86::reg32(43) /* 0x2b */)) += x86::reg8(x86::sreg8(cpu.ah));
    // 004f2aba  4f                     -dec edi
    (cpu.edi)--;
    // 004f2abb  00552b                 -add byte ptr [ebp + 0x2b], dl
    (app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(43) /* 0x2b */)) += x86::reg8(x86::sreg8(cpu.dl));
    // 004f2abe  4f                     -dec edi
    (cpu.edi)--;
    // 004f2abf  004a2b                 -add byte ptr [edx + 0x2b], cl
    (app->getMemory<x86::reg8>(cpu.edx + x86::reg32(43) /* 0x2b */)) += x86::reg8(x86::sreg8(cpu.cl));
    // 004f2ac2  4f                     -dec edi
    (cpu.edi)--;
    // 004f2ac3  003f                   -add byte ptr [edi], bh
    (app->getMemory<x86::reg8>(cpu.edi)) += x86::reg8(x86::sreg8(cpu.bh));
    // 004f2ac5  2b4f00                 -sub ecx, dword ptr [edi]
    (cpu.ecx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi)));
    // 004f2ac8  342b                   -xor al, 0x2b
    cpu.al ^= x86::reg8(x86::sreg8(43 /*0x2b*/));
    // 004f2aca  4f                     -dec edi
    (cpu.edi)--;
    // 004f2acb  0029                   -add byte ptr [ecx], ch
    (app->getMemory<x86::reg8>(cpu.ecx)) += x86::reg8(x86::sreg8(cpu.ch));
    // 004f2acd  2b4f00                 -sub ecx, dword ptr [edi]
    (cpu.ecx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi)));
    // 004f2ad0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f2ad1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f2ad2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f2ad3  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004f2ad5  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004f2ad7  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004f2ad9  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004f2adb  7411                   -je 0x4f2aee
    if (cpu.flags.zf)
    {
        goto L_0x004f2aee;
    }
    // 004f2add  29cb                   -sub ebx, ecx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ecx));
L_0x004f2adf:
    // 004f2adf  48                     -dec eax
    (cpu.eax)--;
    // 004f2ae0  83f8ff                 +cmp eax, -1
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
    // 004f2ae3  7409                   -je 0x4f2aee
    if (cpu.flags.zf)
    {
        goto L_0x004f2aee;
    }
    // 004f2ae5  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004f2ae6  8a16                   -mov dl, byte ptr [esi]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi);
    // 004f2ae8  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004f2ae9  8857ff                 -mov byte ptr [edi - 1], dl
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(-1) /* -0x1 */) = cpu.dl;
    // 004f2aec  ebf1                   -jmp 0x4f2adf
    goto L_0x004f2adf;
L_0x004f2aee:
    // 004f2aee  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004f2af0  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004f2af2  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 004f2af4  c1f902                 -sar ecx, 2
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (2 /*0x2*/ % 32));
    // 004f2af7  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004f2af9  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004f2afb  83e303                 -and ebx, 3
    cpu.ebx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004f2afe  83e60f                 -and esi, 0xf
    cpu.esi &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 004f2b01  c1fd06                 -sar ebp, 6
    cpu.ebp = x86::reg32(x86::sreg32(cpu.ebp) >> (6 /*0x6*/ % 32));
    // 004f2b04  83fe0f                 +cmp esi, 0xf
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(15 /*0xf*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f2b07  0f87c6000000           -ja 0x4f2bd3
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004f2bd3;
    }
    // 004f2b0d  ff24b5902a4f00         -jmp dword ptr [esi*4 + 0x4f2a90]
    cpu.ip = app->getMemory<x86::reg32>(5188240 + cpu.esi * 4); goto dynamic_jump;
  case 0x004f2b14:
L_0x004f2b14:
    // 004f2b14  4d                     -dec ebp
    (cpu.ebp)--;
    // 004f2b15  83fdff                 +cmp ebp, -1
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f2b18  0f84b5000000           -je 0x4f2bd3
    if (cpu.flags.zf)
    {
        goto L_0x004f2bd3;
    }
    // 004f2b1e  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f2b21  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx);
    // 004f2b23  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f2b26  8970fc                 -mov dword ptr [eax - 4], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.esi;
  [[fallthrough]];
  case 0x004f2b29:
    // 004f2b29  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f2b2c  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 004f2b2e  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f2b31  8948fc                 -mov dword ptr [eax - 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
  [[fallthrough]];
  case 0x004f2b34:
    // 004f2b34  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f2b37  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 004f2b39  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f2b3c  8948fc                 -mov dword ptr [eax - 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
  [[fallthrough]];
  case 0x004f2b3f:
    // 004f2b3f  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f2b42  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 004f2b44  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f2b47  8948fc                 -mov dword ptr [eax - 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
  [[fallthrough]];
  case 0x004f2b4a:
    // 004f2b4a  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f2b4d  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 004f2b4f  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f2b52  8948fc                 -mov dword ptr [eax - 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
  [[fallthrough]];
  case 0x004f2b55:
    // 004f2b55  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f2b58  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx);
    // 004f2b5a  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f2b5d  8970fc                 -mov dword ptr [eax - 4], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.esi;
  [[fallthrough]];
  case 0x004f2b60:
    // 004f2b60  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f2b63  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 004f2b65  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f2b68  8948fc                 -mov dword ptr [eax - 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
  [[fallthrough]];
  case 0x004f2b6b:
    // 004f2b6b  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f2b6e  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 004f2b70  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f2b73  8948fc                 -mov dword ptr [eax - 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
  [[fallthrough]];
  case 0x004f2b76:
    // 004f2b76  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f2b79  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 004f2b7b  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f2b7e  8948fc                 -mov dword ptr [eax - 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
  [[fallthrough]];
  case 0x004f2b81:
    // 004f2b81  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f2b84  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 004f2b86  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f2b89  8948fc                 -mov dword ptr [eax - 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
  [[fallthrough]];
  case 0x004f2b8c:
    // 004f2b8c  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f2b8f  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 004f2b91  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f2b94  8948fc                 -mov dword ptr [eax - 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
  [[fallthrough]];
  case 0x004f2b97:
    // 004f2b97  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f2b9a  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx);
    // 004f2b9c  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f2b9f  8970fc                 -mov dword ptr [eax - 4], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.esi;
  [[fallthrough]];
  case 0x004f2ba2:
    // 004f2ba2  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f2ba5  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx);
    // 004f2ba7  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f2baa  8970fc                 -mov dword ptr [eax - 4], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.esi;
  [[fallthrough]];
  case 0x004f2bad:
    // 004f2bad  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f2bb0  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx);
    // 004f2bb2  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f2bb5  8970fc                 -mov dword ptr [eax - 4], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.esi;
  [[fallthrough]];
  case 0x004f2bb8:
    // 004f2bb8  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f2bbb  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx);
    // 004f2bbd  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f2bc0  8970fc                 -mov dword ptr [eax - 4], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.esi;
  [[fallthrough]];
  case 0x004f2bc3:
    // 004f2bc3  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f2bc6  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx);
    // 004f2bc8  83c204                 +add edx, 4
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004f2bcb  8970fc                 -mov dword ptr [eax - 4], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.esi;
    // 004f2bce  e941ffffff             -jmp 0x4f2b14
    goto L_0x004f2b14;
L_0x004f2bd3:
    // 004f2bd3  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x004f2bd5:
    // 004f2bd5  4b                     -dec ebx
    (cpu.ebx)--;
    // 004f2bd6  83fbff                 +cmp ebx, -1
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
    // 004f2bd9  740d                   -je 0x4f2be8
    if (cpu.flags.zf)
    {
        goto L_0x004f2be8;
    }
    // 004f2bdb  8d0c32                 -lea ecx, [edx + esi]
    cpu.ecx = x86::reg32(cpu.edx + cpu.esi * 1);
    // 004f2bde  8d3c30                 -lea edi, [eax + esi]
    cpu.edi = x86::reg32(cpu.eax + cpu.esi * 1);
    // 004f2be1  8a09                   -mov cl, byte ptr [ecx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ecx);
    // 004f2be3  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004f2be4  880f                   -mov byte ptr [edi], cl
    app->getMemory<x86::reg8>(cpu.edi) = cpu.cl;
    // 004f2be6  ebed                   -jmp 0x4f2bd5
    goto L_0x004f2bd5;
L_0x004f2be8:
    // 004f2be8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2be9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2bea  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2beb  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip  */
void Application::sub_4f2ad0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    goto L_entry_0x004f2ad0;
    // 004f2a7d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f2a7f  e880d2feff             -call 0x4dfd04
    cpu.esp -= 4;
    sub_4dfd04(app, cpu);
    if (cpu.terminate) return;
    // 004f2a84  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004f2a86  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004f2a88  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004f2a8a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004f2a8c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004f2a8e  0000                   +add byte ptr [eax], al
    {
        auto tmp1 = app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.al));
        x86::reg8 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) == (1 & (tmp2 >> 7));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004f2a90  142b                   -adc al, 0x2b
    (cpu.al) += x86::reg8(x86::sreg8(43 /*0x2b*/) + cpu.flags.cf);
    // 004f2a92  4f                     -dec edi
    (cpu.edi)--;
    // 004f2a93  00c3                   -add bl, al
    (cpu.bl) += x86::reg8(x86::sreg8(cpu.al));
    // 004f2a95  2b4f00                 -sub ecx, dword ptr [edi]
    (cpu.ecx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi)));
    // 004f2a98  b82b4f00ad             -mov eax, 0xad004f2b
    cpu.eax = 2902478635 /*0xad004f2b*/;
    // 004f2a9d  2b4f00                 -sub ecx, dword ptr [edi]
    (cpu.ecx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi)));
    // 004f2aa0  a22b4f0097             -mov byte ptr [0x97004f2b], al
    app->getMemory<x86::reg8>(x86::reg32(2533379883) /* 0x97004f2b */) = cpu.al;
    // 004f2aa5  2b4f00                 -sub ecx, dword ptr [edi]
    (cpu.ecx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi)));
    // 004f2aa8  8c2b                   -mov word ptr [ebx], gs
    app->getMemory<x86::reg16>(cpu.ebx) = cpu.gs;
    // 004f2aaa  4f                     -dec edi
    (cpu.edi)--;
    // 004f2aab  00812b4f0076           -add byte ptr [ecx + 0x76004f2b], al
    (app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1979731755) /* 0x76004f2b */)) += x86::reg8(x86::sreg8(cpu.al));
    // 004f2ab1  2b4f00                 -sub ecx, dword ptr [edi]
    (cpu.ecx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi)));
    // 004f2ab4  6b2b4f                 -imul ebp, dword ptr [ebx], 0x4f
    cpu.ebp = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx))) * x86::sreg64(x86::sreg32(79 /*0x4f*/)));
    // 004f2ab7  00602b                 -add byte ptr [eax + 0x2b], ah
    (app->getMemory<x86::reg8>(cpu.eax + x86::reg32(43) /* 0x2b */)) += x86::reg8(x86::sreg8(cpu.ah));
    // 004f2aba  4f                     -dec edi
    (cpu.edi)--;
    // 004f2abb  00552b                 -add byte ptr [ebp + 0x2b], dl
    (app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(43) /* 0x2b */)) += x86::reg8(x86::sreg8(cpu.dl));
    // 004f2abe  4f                     -dec edi
    (cpu.edi)--;
    // 004f2abf  004a2b                 -add byte ptr [edx + 0x2b], cl
    (app->getMemory<x86::reg8>(cpu.edx + x86::reg32(43) /* 0x2b */)) += x86::reg8(x86::sreg8(cpu.cl));
    // 004f2ac2  4f                     -dec edi
    (cpu.edi)--;
    // 004f2ac3  003f                   -add byte ptr [edi], bh
    (app->getMemory<x86::reg8>(cpu.edi)) += x86::reg8(x86::sreg8(cpu.bh));
    // 004f2ac5  2b4f00                 -sub ecx, dword ptr [edi]
    (cpu.ecx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi)));
    // 004f2ac8  342b                   -xor al, 0x2b
    cpu.al ^= x86::reg8(x86::sreg8(43 /*0x2b*/));
    // 004f2aca  4f                     -dec edi
    (cpu.edi)--;
    // 004f2acb  0029                   -add byte ptr [ecx], ch
    (app->getMemory<x86::reg8>(cpu.ecx)) += x86::reg8(x86::sreg8(cpu.ch));
    // 004f2acd  2b4f00                 -sub ecx, dword ptr [edi]
    (cpu.ecx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi)));
L_entry_0x004f2ad0:
    // 004f2ad0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f2ad1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f2ad2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f2ad3  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004f2ad5  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004f2ad7  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004f2ad9  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004f2adb  7411                   -je 0x4f2aee
    if (cpu.flags.zf)
    {
        goto L_0x004f2aee;
    }
    // 004f2add  29cb                   -sub ebx, ecx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ecx));
L_0x004f2adf:
    // 004f2adf  48                     -dec eax
    (cpu.eax)--;
    // 004f2ae0  83f8ff                 +cmp eax, -1
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
    // 004f2ae3  7409                   -je 0x4f2aee
    if (cpu.flags.zf)
    {
        goto L_0x004f2aee;
    }
    // 004f2ae5  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004f2ae6  8a16                   -mov dl, byte ptr [esi]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi);
    // 004f2ae8  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004f2ae9  8857ff                 -mov byte ptr [edi - 1], dl
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(-1) /* -0x1 */) = cpu.dl;
    // 004f2aec  ebf1                   -jmp 0x4f2adf
    goto L_0x004f2adf;
L_0x004f2aee:
    // 004f2aee  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004f2af0  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004f2af2  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 004f2af4  c1f902                 -sar ecx, 2
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (2 /*0x2*/ % 32));
    // 004f2af7  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004f2af9  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004f2afb  83e303                 -and ebx, 3
    cpu.ebx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004f2afe  83e60f                 -and esi, 0xf
    cpu.esi &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 004f2b01  c1fd06                 -sar ebp, 6
    cpu.ebp = x86::reg32(x86::sreg32(cpu.ebp) >> (6 /*0x6*/ % 32));
    // 004f2b04  83fe0f                 +cmp esi, 0xf
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(15 /*0xf*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f2b07  0f87c6000000           -ja 0x4f2bd3
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004f2bd3;
    }
    // 004f2b0d  ff24b5902a4f00         -jmp dword ptr [esi*4 + 0x4f2a90]
    cpu.ip = app->getMemory<x86::reg32>(5188240 + cpu.esi * 4); goto dynamic_jump;
  case 0x004f2b14:
L_0x004f2b14:
    // 004f2b14  4d                     -dec ebp
    (cpu.ebp)--;
    // 004f2b15  83fdff                 +cmp ebp, -1
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f2b18  0f84b5000000           -je 0x4f2bd3
    if (cpu.flags.zf)
    {
        goto L_0x004f2bd3;
    }
    // 004f2b1e  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f2b21  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx);
    // 004f2b23  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f2b26  8970fc                 -mov dword ptr [eax - 4], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.esi;
  [[fallthrough]];
  case 0x004f2b29:
    // 004f2b29  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f2b2c  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 004f2b2e  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f2b31  8948fc                 -mov dword ptr [eax - 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
  [[fallthrough]];
  case 0x004f2b34:
    // 004f2b34  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f2b37  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 004f2b39  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f2b3c  8948fc                 -mov dword ptr [eax - 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
  [[fallthrough]];
  case 0x004f2b3f:
    // 004f2b3f  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f2b42  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 004f2b44  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f2b47  8948fc                 -mov dword ptr [eax - 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
  [[fallthrough]];
  case 0x004f2b4a:
    // 004f2b4a  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f2b4d  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 004f2b4f  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f2b52  8948fc                 -mov dword ptr [eax - 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
  [[fallthrough]];
  case 0x004f2b55:
    // 004f2b55  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f2b58  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx);
    // 004f2b5a  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f2b5d  8970fc                 -mov dword ptr [eax - 4], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.esi;
  [[fallthrough]];
  case 0x004f2b60:
    // 004f2b60  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f2b63  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 004f2b65  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f2b68  8948fc                 -mov dword ptr [eax - 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
  [[fallthrough]];
  case 0x004f2b6b:
    // 004f2b6b  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f2b6e  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 004f2b70  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f2b73  8948fc                 -mov dword ptr [eax - 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
  [[fallthrough]];
  case 0x004f2b76:
    // 004f2b76  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f2b79  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 004f2b7b  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f2b7e  8948fc                 -mov dword ptr [eax - 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
  [[fallthrough]];
  case 0x004f2b81:
    // 004f2b81  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f2b84  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 004f2b86  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f2b89  8948fc                 -mov dword ptr [eax - 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
  [[fallthrough]];
  case 0x004f2b8c:
    // 004f2b8c  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f2b8f  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 004f2b91  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f2b94  8948fc                 -mov dword ptr [eax - 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
  [[fallthrough]];
  case 0x004f2b97:
    // 004f2b97  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f2b9a  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx);
    // 004f2b9c  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f2b9f  8970fc                 -mov dword ptr [eax - 4], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.esi;
  [[fallthrough]];
  case 0x004f2ba2:
    // 004f2ba2  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f2ba5  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx);
    // 004f2ba7  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f2baa  8970fc                 -mov dword ptr [eax - 4], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.esi;
  [[fallthrough]];
  case 0x004f2bad:
    // 004f2bad  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f2bb0  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx);
    // 004f2bb2  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f2bb5  8970fc                 -mov dword ptr [eax - 4], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.esi;
  [[fallthrough]];
  case 0x004f2bb8:
    // 004f2bb8  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f2bbb  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx);
    // 004f2bbd  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f2bc0  8970fc                 -mov dword ptr [eax - 4], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.esi;
  [[fallthrough]];
  case 0x004f2bc3:
    // 004f2bc3  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f2bc6  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx);
    // 004f2bc8  83c204                 +add edx, 4
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004f2bcb  8970fc                 -mov dword ptr [eax - 4], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.esi;
    // 004f2bce  e941ffffff             -jmp 0x4f2b14
    goto L_0x004f2b14;
L_0x004f2bd3:
    // 004f2bd3  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x004f2bd5:
    // 004f2bd5  4b                     -dec ebx
    (cpu.ebx)--;
    // 004f2bd6  83fbff                 +cmp ebx, -1
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
    // 004f2bd9  740d                   -je 0x4f2be8
    if (cpu.flags.zf)
    {
        goto L_0x004f2be8;
    }
    // 004f2bdb  8d0c32                 -lea ecx, [edx + esi]
    cpu.ecx = x86::reg32(cpu.edx + cpu.esi * 1);
    // 004f2bde  8d3c30                 -lea edi, [eax + esi]
    cpu.edi = x86::reg32(cpu.eax + cpu.esi * 1);
    // 004f2be1  8a09                   -mov cl, byte ptr [ecx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ecx);
    // 004f2be3  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004f2be4  880f                   -mov byte ptr [edi], cl
    app->getMemory<x86::reg8>(cpu.edi) = cpu.cl;
    // 004f2be6  ebed                   -jmp 0x4f2bd5
    goto L_0x004f2bd5;
L_0x004f2be8:
    // 004f2be8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2be9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2bea  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2beb  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_4f2bf0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f2bf0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f2bf1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f2bf2  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004f2bf4  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004f2bf6  83fb04                 +cmp ebx, 4
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f2bf9  7d13                   -jge 0x4f2c0e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004f2c0e;
    }
L_0x004f2bfb:
    // 004f2bfb  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004f2bfd  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
L_0x004f2bff:
    // 004f2bff  4b                     -dec ebx
    (cpu.ebx)--;
    // 004f2c00  83fbff                 +cmp ebx, -1
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
    // 004f2c03  742a                   -je 0x4f2c2f
    if (cpu.flags.zf)
    {
        goto L_0x004f2c2f;
    }
    // 004f2c05  4a                     +dec edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004f2c06  8a48ff                 -mov cl, byte ptr [eax - 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(-1) /* -0x1 */);
    // 004f2c09  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004f2c0a  880a                   -mov byte ptr [edx], cl
    app->getMemory<x86::reg8>(cpu.edx) = cpu.cl;
    // 004f2c0c  ebf1                   -jmp 0x4f2bff
    goto L_0x004f2bff;
L_0x004f2c0e:
    // 004f2c0e  39c2                   +cmp edx, eax
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
    // 004f2c10  7607                   -jbe 0x4f2c19
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004f2c19;
    }
    // 004f2c12  8d0c18                 -lea ecx, [eax + ebx]
    cpu.ecx = x86::reg32(cpu.eax + cpu.ebx * 1);
    // 004f2c15  39ca                   +cmp edx, ecx
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f2c17  72e2                   -jb 0x4f2bfb
    if (cpu.flags.cf)
    {
        goto L_0x004f2bfb;
    }
L_0x004f2c19:
    // 004f2c19  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004f2c1b  be04000000             -mov esi, 4
    cpu.esi = 4 /*0x4*/;
    // 004f2c20  83e103                 -and ecx, 3
    cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004f2c23  29ce                   -sub esi, ecx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004f2c25  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004f2c27  83e103                 -and ecx, 3
    cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004f2c2a  e8a1feffff             -call 0x4f2ad0
    cpu.esp -= 4;
    sub_4f2ad0(app, cpu);
    if (cpu.terminate) return;
L_0x004f2c2f:
    // 004f2c2f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2c30  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2c31  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_4f2c40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f2c40  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f2c41  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004f2c43  d1fb                   -sar ebx, 1
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (1 /*0x1*/ % 32));
    // 004f2c45  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004f2c47  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004f2c49  e8a2ffffff             -call 0x4f2bf0
    cpu.esp -= 4;
    sub_4f2bf0(app, cpu);
    if (cpu.terminate) return;
    // 004f2c4e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2c4f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4f2c50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f2c50  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f2c51  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004f2c53  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004f2c55  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004f2c57  e894ffffff             -call 0x4f2bf0
    cpu.esp -= 4;
    sub_4f2bf0(app, cpu);
    if (cpu.terminate) return;
    // 004f2c5c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2c5d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4f2c60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f2c60  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f2c61  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004f2c63  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004f2c65  01db                   -add ebx, ebx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004f2c67  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004f2c69  e882ffffff             -call 0x4f2bf0
    cpu.esp -= 4;
    sub_4f2bf0(app, cpu);
    if (cpu.terminate) return;
    // 004f2c6e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2c6f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4f2c70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f2c70  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f2c71  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f2c72  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004f2c74  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004f2c76  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004f2c78  c1e302                 -shl ebx, 2
    cpu.ebx <<= 2 /*0x2*/ % 32;
    // 004f2c7b  29d3                   -sub ebx, edx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004f2c7d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004f2c7f  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004f2c81  e86affffff             -call 0x4f2bf0
    cpu.esp -= 4;
    sub_4f2bf0(app, cpu);
    if (cpu.terminate) return;
    // 004f2c86  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2c87  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2c88  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4f2c90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f2c90  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f2c91  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004f2c93  c1e302                 -shl ebx, 2
    cpu.ebx <<= 2 /*0x2*/ % 32;
    // 004f2c96  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004f2c98  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004f2c9a  e851ffffff             -call 0x4f2bf0
    cpu.esp -= 4;
    sub_4f2bf0(app, cpu);
    if (cpu.terminate) return;
    // 004f2c9f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2ca0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_4f2cb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f2cb0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f2cb1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f2cb2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f2cb3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f2cb4  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004f2cb6  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004f2cb8  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 004f2cba  b9b0525600             -mov ecx, 0x5652b0
    cpu.ecx = 5657264 /*0x5652b0*/;
    // 004f2cbf  e8ec830100             -call 0x50b0b0
    cpu.esp -= 4;
    sub_50b0b0(app, cpu);
    if (cpu.terminate) return;
    // 004f2cc4  6681660c00f0           -and word ptr [esi + 0xc], 0xf000
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(12) /* 0xc */) &= x86::reg16(x86::sreg16(61440 /*0xf000*/));
    // 004f2cca  81e7ff0f0000           -and edi, 0xfff
    cpu.edi &= x86::reg32(x86::sreg32(4095 /*0xfff*/));
    // 004f2cd0  097e0c                 -or dword ptr [esi + 0xc], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) |= x86::reg32(x86::sreg32(cpu.edi));
    // 004f2cd3  668b5e0e               -mov bx, word ptr [esi + 0xe]
    cpu.bx = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(14) /* 0xe */);
    // 004f2cd7  81e300f0ffff           -and ebx, 0xfffff000
    cpu.ebx &= x86::reg32(x86::sreg32(4294963200 /*0xfffff000*/));
    // 004f2cdd  81e5ff0f0000           -and ebp, 0xfff
    cpu.ebp &= x86::reg32(x86::sreg32(4095 /*0xfff*/));
    // 004f2ce3  66895e0e               -mov word ptr [esi + 0xe], bx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(14) /* 0xe */) = cpu.bx;
    // 004f2ce7  c1e510                 -shl ebp, 0x10
    cpu.ebp <<= 16 /*0x10*/ % 32;
    // 004f2cea  096e0c                 -or dword ptr [esi + 0xc], ebp
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) |= x86::reg32(x86::sreg32(cpu.ebp));
    // 004f2ced  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2cee  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2cef  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2cf0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2cf1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_4f2d00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f2d00  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f2d01  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f2d02  8b580c                 -mov ebx, dword ptr [eax + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004f2d05  8b500c                 -mov edx, dword ptr [eax + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004f2d08  c1e304                 -shl ebx, 4
    cpu.ebx <<= 4 /*0x4*/ % 32;
    // 004f2d0b  c1e214                 -shl edx, 0x14
    cpu.edx <<= 20 /*0x14*/ % 32;
    // 004f2d0e  c1fb14                 -sar ebx, 0x14
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (20 /*0x14*/ % 32));
    // 004f2d11  c1fa14                 -sar edx, 0x14
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (20 /*0x14*/ % 32));
    // 004f2d14  e897ffffff             -call 0x4f2cb0
    cpu.esp -= 4;
    sub_4f2cb0(app, cpu);
    if (cpu.terminate) return;
    // 004f2d19  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2d1a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2d1b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_4f2d20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f2d20  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f2d21  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004f2d24  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 004f2d27  29cb                   -sub ebx, ecx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004f2d29  8b4806                 -mov ecx, dword ptr [eax + 6]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6) /* 0x6 */);
    // 004f2d2c  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 004f2d2f  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004f2d31  e87affffff             -call 0x4f2cb0
    cpu.esp -= 4;
    sub_4f2cb0(app, cpu);
    if (cpu.terminate) return;
    // 004f2d36  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f2d37  c3                     -ret 
    cpu.esp += 4;
    return;
}

}
