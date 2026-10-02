#include "softtria.h"
#include <lib/thread.h>

namespace softtria
{

/* align: skip 0x8d 0x40 0x00 */
void sub_a94bd4(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a94bd4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a94bd5  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a94bd6  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a94bd8  ff1570e1a900           -call dword ptr [0xa9e170]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11133296) /* 0xa9e170 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a94bde  803d1010aa0000         +cmp byte ptr [0xaa1010], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(11145232) /* 0xaa1010 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a94be5  750f                   -jne 0xa94bf6
    if (!cpu.flags.zf)
    {
        goto L_0x00a94bf6;
    }
    // 00a94be7  baff000000             -mov edx, 0xff
    cpu.edx = 255 /*0xff*/;
    // 00a94bec  b810000000             -mov eax, 0x10
    cpu.eax = 16 /*0x10*/;
    // 00a94bf1  e8260b0000             -call 0xa9571c
    cpu.esp -= 4;
    sub_a9571c(app, cpu);
    if (cpu.terminate) return;
L_0x00a94bf6:
    // 00a94bf6  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a94bf8  e803000000             -call 0xa94c00
    cpu.esp -= 4;
    sub_a94c00(app, cpu);
    if (cpu.terminate) return;
    // 00a94bfd  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a94bfe  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a94bff  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a94c00(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a94c00  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a94c01  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a94c03  ff1570e1a900           -call dword ptr [0xa9e170]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11133296) /* 0xa9e170 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a94c09  ff1574e1a900           -call dword ptr [0xa9e174]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11133300) /* 0xa9e174 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a94c0f  833d20e3a90000         +cmp dword ptr [0xa9e320], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(11133728) /* 0xa9e320 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a94c16  7406                   -je 0xa94c1e
    if (cpu.flags.zf)
    {
        goto L_0x00a94c1e;
    }
    // 00a94c18  ff1520e3a900           -call dword ptr [0xa9e320]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11133728) /* 0xa9e320 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00a94c1e:
    // 00a94c1e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a94c20  e9170a0000             -jmp 0xa9563c
    return sub_a9563c(app, cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a94c30(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a94c30  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a94c31  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a94c32  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00a94c34  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00a94c36  8d4a01                 -lea ecx, [edx + 1]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 00a94c39  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 00a94c3b  881a                   -mov byte ptr [edx], bl
    app->getMemory<x86::reg8>(cpu.edx) = cpu.bl;
    // 00a94c3d  ff4010                 -inc dword ptr [eax + 0x10]
    (app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */))++;
    // 00a94c40  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a94c41  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a94c42  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void sub_a94c44(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a94c44  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a94c45  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a94c46  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a94c48  b9304ca900             -mov ecx, 0xa94c30
    cpu.ecx = 11095088 /*0xa94c30*/;
    // 00a94c4d  e81e0b0000             -call 0xa95770
    cpu.esp -= 4;
    sub_a95770(app, cpu);
    if (cpu.terminate) return;
    // 00a94c52  c6040600               -mov byte ptr [esi + eax], 0
    app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1) = 0 /*0x0*/;
    // 00a94c56  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a94c57  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a94c58  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void sub_a94c5a(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a94c5a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a94c5b  9b                     -wait 
    /*nothing*/;
    // 00a94c5c  d93c24                 -fnstcw word ptr [esp]
    app->getMemory<x86::reg16>(cpu.esp) = cpu.fpu.control.word;
    // 00a94c5f  9b                     -wait 
    /*nothing*/;
    // 00a94c60  ff3424                 -push dword ptr [esp]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp -= 4;
    // 00a94c63  c64424011f             -mov byte ptr [esp + 1], 0x1f
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1) /* 0x1 */) = 31 /*0x1f*/;
    // 00a94c68  d92c24                 -fldcw word ptr [esp]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.esp);
    // 00a94c6b  d9fc                   -frndint 
    cpu.fpu.st(0) = cpu.fpu.rndint();
    // 00a94c6d  d96c2404               -fldcw word ptr [esp + 4]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a94c71  9b                     -wait 
    /*nothing*/;
    // 00a94c72  8d642408               -lea esp, [esp + 8]
    cpu.esp = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00a94c76  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a94c80(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a94c80  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a94c81  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a94c82  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a94c83  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a94c84  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a94c85  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a94c86  0fa0                   -push fs
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.fs;
    cpu.esp -= 4;
    // 00a94c88  0fa8                   -push gs
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.gs;
    cpu.esp -= 4;
    // 00a94c8a  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a94c8b  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a94c8e  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a94c90  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a94c92  7405                   -je 0xa94c99
    if (cpu.flags.zf)
    {
        goto L_0x00a94c99;
    }
    // 00a94c94  83f8d4                 +cmp eax, -0x2c
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-44 /*-0x2c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a94c97  7607                   -jbe 0xa94ca0
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a94ca0;
    }
L_0x00a94c99:
    // 00a94c99  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a94c9b  e9be000000             -jmp 0xa94d5e
    goto L_0x00a94d5e;
L_0x00a94ca0:
    // 00a94ca0  8d680b                 -lea ebp, [eax + 0xb]
    cpu.ebp = x86::reg32(cpu.eax + x86::reg32(11) /* 0xb */);
    // 00a94ca3  83e5f8                 -and ebp, 0xfffffff8
    cpu.ebp &= x86::reg32(x86::sreg32(4294967288 /*0xfffffff8*/));
    // 00a94ca6  83fd10                 +cmp ebp, 0x10
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a94ca9  7305                   -jae 0xa94cb0
    if (!cpu.flags.cf)
    {
        goto L_0x00a94cb0;
    }
    // 00a94cab  bd10000000             -mov ebp, 0x10
    cpu.ebp = 16 /*0x10*/;
L_0x00a94cb0:
    // 00a94cb0  ff15b0e2a900           -call dword ptr [0xa9e2b0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11133616) /* 0xa9e2b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a94cb6  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 00a94cb8  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a94cba  882424                 -mov byte ptr [esp], ah
    app->getMemory<x86::reg8>(cpu.esp) = cpu.ah;
L_0x00a94cbd:
    // 00a94cbd  3b2d80e1a900           +cmp ebp, dword ptr [0xa9e180]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(11133312) /* 0xa9e180 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a94cc3  760c                   -jbe 0xa94cd1
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a94cd1;
    }
    // 00a94cc5  8b0d7ce1a900           -mov ecx, dword ptr [0xa9e17c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11133308) /* 0xa9e17c */);
    // 00a94ccb  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00a94ccd  7510                   -jne 0xa94cdf
    if (!cpu.flags.zf)
    {
        goto L_0x00a94cdf;
    }
    // 00a94ccf  eb02                   -jmp 0xa94cd3
    goto L_0x00a94cd3;
L_0x00a94cd1:
    // 00a94cd1  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x00a94cd3:
    // 00a94cd3  890d80e1a900           -mov dword ptr [0xa9e180], ecx
    app->getMemory<x86::reg32>(x86::reg32(11133312) /* 0xa9e180 */) = cpu.ecx;
    // 00a94cd9  8b0d78e1a900           -mov ecx, dword ptr [0xa9e178]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11133304) /* 0xa9e178 */);
L_0x00a94cdf:
    // 00a94cdf  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00a94ce1  743c                   -je 0xa94d1f
    if (cpu.flags.zf)
    {
        goto L_0x00a94d1f;
    }
    // 00a94ce3  8b7114                 -mov esi, dword ptr [ecx + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 00a94ce6  890d7ce1a900           -mov dword ptr [0xa9e17c], ecx
    app->getMemory<x86::reg32>(x86::reg32(11133308) /* 0xa9e17c */) = cpu.ecx;
    // 00a94cec  39fe                   +cmp esi, edi
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a94cee  721c                   -jb 0xa94d0c
    if (cpu.flags.cf)
    {
        goto L_0x00a94d0c;
    }
    // 00a94cf0  b878e1a900             -mov eax, 0xa9e178
    cpu.eax = 11133304 /*0xa9e178*/;
    // 00a94cf5  8cda                   -mov edx, ds
    cpu.edx = cpu.ds;
    // 00a94cf7  81e2ffff0000           -and edx, 0xffff
    cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00a94cfd  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00a94cff  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a94d01  e89a180000             -call 0xa965a0
    cpu.esp -= 4;
    sub_a965a0(app, cpu);
    if (cpu.terminate) return;
    // 00a94d06  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a94d08  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a94d0a  7542                   -jne 0xa94d4e
    if (!cpu.flags.zf)
    {
        goto L_0x00a94d4e;
    }
L_0x00a94d0c:
    // 00a94d0c  3b3580e1a900           +cmp esi, dword ptr [0xa9e180]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(11133312) /* 0xa9e180 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a94d12  7606                   -jbe 0xa94d1a
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a94d1a;
    }
    // 00a94d14  893580e1a900           -mov dword ptr [0xa9e180], esi
    app->getMemory<x86::reg32>(x86::reg32(11133312) /* 0xa9e180 */) = cpu.esi;
L_0x00a94d1a:
    // 00a94d1a  8b4908                 -mov ecx, dword ptr [ecx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00a94d1d  ebc0                   -jmp 0xa94cdf
    goto L_0x00a94cdf;
L_0x00a94d1f:
    // 00a94d1f  803c2400               +cmp byte ptr [esp], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esp);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a94d23  750b                   -jne 0xa94d30
    if (!cpu.flags.zf)
    {
        goto L_0x00a94d30;
    }
    // 00a94d25  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a94d27  e8881b0000             -call 0xa968b4
    cpu.esp -= 4;
    sub_a968b4(app, cpu);
    if (cpu.terminate) return;
    // 00a94d2c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a94d2e  7515                   -jne 0xa94d45
    if (!cpu.flags.zf)
    {
        goto L_0x00a94d45;
    }
L_0x00a94d30:
    // 00a94d30  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a94d32  e8e91b0000             -call 0xa96920
    cpu.esp -= 4;
    sub_a96920(app, cpu);
    if (cpu.terminate) return;
    // 00a94d37  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a94d39  7413                   -je 0xa94d4e
    if (cpu.flags.zf)
    {
        goto L_0x00a94d4e;
    }
    // 00a94d3b  30c9                   +xor cl, cl
    cpu.clear_co();
    cpu.set_szp((cpu.cl ^= x86::reg8(x86::sreg8(cpu.cl))));
    // 00a94d3d  880c24                 -mov byte ptr [esp], cl
    app->getMemory<x86::reg8>(cpu.esp) = cpu.cl;
    // 00a94d40  e978ffffff             -jmp 0xa94cbd
    goto L_0x00a94cbd;
L_0x00a94d45:
    // 00a94d45  c6042401               -mov byte ptr [esp], 1
    app->getMemory<x86::reg8>(cpu.esp) = 1 /*0x1*/;
    // 00a94d49  e96fffffff             -jmp 0xa94cbd
    goto L_0x00a94cbd;
L_0x00a94d4e:
    // 00a94d4e  30ed                   -xor ch, ch
    cpu.ch ^= x86::reg8(x86::sreg8(cpu.ch));
    // 00a94d50  882d4016aa00           -mov byte ptr [0xaa1640], ch
    app->getMemory<x86::reg8>(x86::reg32(11146816) /* 0xaa1640 */) = cpu.ch;
    // 00a94d56  ff15b8e2a900           -call dword ptr [0xa9e2b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11133624) /* 0xa9e2b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a94d5c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x00a94d5e:
    // 00a94d5e  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a94d61  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a94d62  0fa9                   -pop gs
    cpu.gs = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a94d64  0fa1                   -pop fs
    cpu.fs = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a94d66  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a94d67  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a94d68  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a94d69  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a94d6a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a94d6b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a94d6c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void sub_a94d70(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a94d70  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a94d71  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a94d72  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a94d73  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a94d74  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a94d76  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a94d78  0f84f3000000           -je 0xa94e71
    if (cpu.flags.zf)
    {
        goto L_0x00a94e71;
    }
    // 00a94d7e  ff15b0e2a900           -call dword ptr [0xa9e2b0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11133616) /* 0xa9e2b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a94d84  8b0df00faa00           -mov ecx, dword ptr [0xaa0ff0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11145200) /* 0xaa0ff0 */);
    // 00a94d8a  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00a94d8c  7440                   -je 0xa94dce
    if (cpu.flags.zf)
    {
        goto L_0x00a94dce;
    }
    // 00a94d8e  39f1                   +cmp ecx, esi
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a94d90  770c                   -ja 0xa94d9e
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a94d9e;
    }
    // 00a94d92  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 00a94d94  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00a94d96  39f0                   +cmp eax, esi
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
    // 00a94d98  0f878d000000           -ja 0xa94e2b
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a94e2b;
    }
L_0x00a94d9e:
    // 00a94d9e  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00a94da0  8b4904                 -mov ecx, dword ptr [ecx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00a94da3  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00a94da5  7410                   -je 0xa94db7
    if (cpu.flags.zf)
    {
        goto L_0x00a94db7;
    }
    // 00a94da7  39f1                   +cmp ecx, esi
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a94da9  770c                   -ja 0xa94db7
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a94db7;
    }
    // 00a94dab  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 00a94dad  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00a94daf  39f0                   +cmp eax, esi
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
    // 00a94db1  0f8774000000           -ja 0xa94e2b
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a94e2b;
    }
L_0x00a94db7:
    // 00a94db7  8b4a08                 -mov ecx, dword ptr [edx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00a94dba  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00a94dbc  7410                   -je 0xa94dce
    if (cpu.flags.zf)
    {
        goto L_0x00a94dce;
    }
    // 00a94dbe  39f1                   +cmp ecx, esi
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a94dc0  770c                   -ja 0xa94dce
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a94dce;
    }
    // 00a94dc2  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 00a94dc4  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00a94dc6  39f0                   +cmp eax, esi
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
    // 00a94dc8  0f875d000000           -ja 0xa94e2b
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a94e2b;
    }
L_0x00a94dce:
    // 00a94dce  8b0d7ce1a900           -mov ecx, dword ptr [0xa9e17c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11133308) /* 0xa9e17c */);
    // 00a94dd4  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00a94dd6  7434                   -je 0xa94e0c
    if (cpu.flags.zf)
    {
        goto L_0x00a94e0c;
    }
    // 00a94dd8  39f1                   +cmp ecx, esi
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a94dda  7708                   -ja 0xa94de4
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a94de4;
    }
    // 00a94ddc  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 00a94dde  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00a94de0  39f0                   +cmp eax, esi
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
    // 00a94de2  7747                   -ja 0xa94e2b
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a94e2b;
    }
L_0x00a94de4:
    // 00a94de4  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00a94de6  8b4904                 -mov ecx, dword ptr [ecx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00a94de9  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00a94deb  740c                   -je 0xa94df9
    if (cpu.flags.zf)
    {
        goto L_0x00a94df9;
    }
    // 00a94ded  39f1                   +cmp ecx, esi
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a94def  7708                   -ja 0xa94df9
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a94df9;
    }
    // 00a94df1  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 00a94df3  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00a94df5  39f0                   +cmp eax, esi
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
    // 00a94df7  7732                   -ja 0xa94e2b
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a94e2b;
    }
L_0x00a94df9:
    // 00a94df9  8b4a08                 -mov ecx, dword ptr [edx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00a94dfc  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00a94dfe  740c                   -je 0xa94e0c
    if (cpu.flags.zf)
    {
        goto L_0x00a94e0c;
    }
    // 00a94e00  39f1                   +cmp ecx, esi
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a94e02  7708                   -ja 0xa94e0c
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a94e0c;
    }
    // 00a94e04  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 00a94e06  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00a94e08  39f0                   +cmp eax, esi
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
    // 00a94e0a  771f                   -ja 0xa94e2b
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a94e2b;
    }
L_0x00a94e0c:
    // 00a94e0c  8b0d78e1a900           -mov ecx, dword ptr [0xa9e178]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11133304) /* 0xa9e178 */);
    // 00a94e12  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00a94e14  7455                   -je 0xa94e6b
    if (cpu.flags.zf)
    {
        goto L_0x00a94e6b;
    }
L_0x00a94e16:
    // 00a94e16  39f1                   +cmp ecx, esi
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a94e18  7708                   -ja 0xa94e22
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a94e22;
    }
    // 00a94e1a  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 00a94e1c  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00a94e1e  39f0                   +cmp eax, esi
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
    // 00a94e20  7709                   -ja 0xa94e2b
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a94e2b;
    }
L_0x00a94e22:
    // 00a94e22  8b4908                 -mov ecx, dword ptr [ecx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00a94e25  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00a94e27  75ed                   -jne 0xa94e16
    if (!cpu.flags.zf)
    {
        goto L_0x00a94e16;
    }
    // 00a94e29  eb40                   -jmp 0xa94e6b
    goto L_0x00a94e6b;
L_0x00a94e2b:
    // 00a94e2b  b878e1a900             -mov eax, 0xa9e178
    cpu.eax = 11133304 /*0xa9e178*/;
    // 00a94e30  8cda                   -mov edx, ds
    cpu.edx = cpu.ds;
    // 00a94e32  81e2ffff0000           -and edx, 0xffff
    cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00a94e38  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00a94e3a  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a94e3c  e80f180000             -call 0xa96650
    cpu.esp -= 4;
    sub_a96650(app, cpu);
    if (cpu.terminate) return;
    // 00a94e41  8b157ce1a900           -mov edx, dword ptr [0xa9e17c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11133308) /* 0xa9e17c */);
    // 00a94e47  890df00faa00           -mov dword ptr [0xaa0ff0], ecx
    app->getMemory<x86::reg32>(x86::reg32(11145200) /* 0xaa0ff0 */) = cpu.ecx;
    // 00a94e4d  39d1                   +cmp ecx, edx
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a94e4f  7312                   -jae 0xa94e63
    if (!cpu.flags.cf)
    {
        goto L_0x00a94e63;
    }
    // 00a94e51  8b1d80e1a900           -mov ebx, dword ptr [0xa9e180]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(11133312) /* 0xa9e180 */);
    // 00a94e57  8b4114                 -mov eax, dword ptr [ecx + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 00a94e5a  39d8                   +cmp eax, ebx
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a94e5c  7605                   -jbe 0xa94e63
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a94e63;
    }
    // 00a94e5e  a380e1a900             -mov dword ptr [0xa9e180], eax
    app->getMemory<x86::reg32>(x86::reg32(11133312) /* 0xa9e180 */) = cpu.eax;
L_0x00a94e63:
    // 00a94e63  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 00a94e65  88254016aa00           -mov byte ptr [0xaa1640], ah
    app->getMemory<x86::reg8>(x86::reg32(11146816) /* 0xaa1640 */) = cpu.ah;
L_0x00a94e6b:
    // 00a94e6b  ff15b8e2a900           -call dword ptr [0xa9e2b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11133624) /* 0xa9e2b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00a94e71:
    // 00a94e71  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a94e72  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a94e73  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a94e74  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a94e75  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a94e80(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a94e80  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a94e81(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a94e81  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a94e82(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a94e82  e9791b0000             -jmp 0xa96a00
    return sub_a96a00(app, cpu);
}

/* align: skip  */
/* data blob: 030ca600574154434f4d20432f432b2b33322052756e2d54696d652073797374656d2e2028632920436f7079726967687420627920574154434f4d20496e7465726e6174696f6e616c20436f72702e20313938382d313939342e20416c6c207269676874732072657365727665642e00000000000000000000 */
void sub_a94f00(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a94f00  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a94f01  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a94f02  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a94f04  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00a94f06  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a94f08  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a94f0a  763c                   -jbe 0xa94f48
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a94f48;
    }
L_0x00a94f0c:
    // 00a94f0c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a94f0e  e8cd1d0000             -call 0xa96ce0
    cpu.esp -= 4;
    sub_a96ce0(app, cpu);
    if (cpu.terminate) return;
    // 00a94f13  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a94f15  7531                   -jne 0xa94f48
    if (!cpu.flags.zf)
    {
        goto L_0x00a94f48;
    }
    // 00a94f17  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a94f19  e8c21d0000             -call 0xa96ce0
    cpu.esp -= 4;
    sub_a96ce0(app, cpu);
    if (cpu.terminate) return;
    // 00a94f1e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a94f20  7526                   -jne 0xa94f48
    if (!cpu.flags.zf)
    {
        goto L_0x00a94f48;
    }
    // 00a94f22  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00a94f24  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a94f26  e8f51d0000             -call 0xa96d20
    cpu.esp -= 4;
    sub_a96d20(app, cpu);
    if (cpu.terminate) return;
    // 00a94f2b  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a94f2d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a94f2f  753d                   -jne 0xa94f6e
    if (!cpu.flags.zf)
    {
        goto L_0x00a94f6e;
    }
    // 00a94f31  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a94f33  e8481e0000             -call 0xa96d80
    cpu.esp -= 4;
    sub_a96d80(app, cpu);
    if (cpu.terminate) return;
    // 00a94f38  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a94f3a  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a94f3c  4b                     -dec ebx
    (cpu.ebx)--;
    // 00a94f3d  e83e1e0000             -call 0xa96d80
    cpu.esp -= 4;
    sub_a96d80(app, cpu);
    if (cpu.terminate) return;
    // 00a94f42  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a94f44  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a94f46  77c4                   -ja 0xa94f0c
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a94f0c;
    }
L_0x00a94f48:
    // 00a94f48  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a94f4a  7620                   -jbe 0xa94f6c
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a94f6c;
    }
    // 00a94f4c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a94f4e  e88d1d0000             -call 0xa96ce0
    cpu.esp -= 4;
    sub_a96ce0(app, cpu);
    if (cpu.terminate) return;
    // 00a94f53  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a94f55  750b                   -jne 0xa94f62
    if (!cpu.flags.zf)
    {
        goto L_0x00a94f62;
    }
    // 00a94f57  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a94f59  e8821d0000             -call 0xa96ce0
    cpu.esp -= 4;
    sub_a96ce0(app, cpu);
    if (cpu.terminate) return;
    // 00a94f5e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a94f60  740a                   -je 0xa94f6c
    if (cpu.flags.zf)
    {
        goto L_0x00a94f6c;
    }
L_0x00a94f62:
    // 00a94f62  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a94f64  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a94f66  8a11                   -mov dl, byte ptr [ecx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx);
    // 00a94f68  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00a94f6a  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
L_0x00a94f6c:
    // 00a94f6c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x00a94f6e:
    // 00a94f6e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a94f6f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a94f70  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a94f80(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a94f80  09c9                   +or ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx |= x86::reg32(x86::sreg32(cpu.ecx))));
    // 00a94f82  742c                   -je 0xa94fb0
    if (cpu.flags.zf)
    {
        goto L_0x00a94fb0;
    }
    // 00a94f84  3810                   -cmp byte ptr [eax], dl
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.dl));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
L_0x00a94f86:
    // 00a94f86  a803                   +test al, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 3 /*0x3*/));
    // 00a94f88  7409                   -je 0xa94f93
    if (cpu.flags.zf)
    {
        goto L_0x00a94f93;
    }
    // 00a94f8a  8810                   -mov byte ptr [eax], dl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.dl;
    // 00a94f8c  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a94f8d  c1ca08                 +ror edx, 8
    {
        x86::reg32& op = cpu.edx;
        x86::reg32 count = 8 /*0x8*/ % 32;
        if (count) {
            op = (op >> count) | (op << (32 - count));
            cpu.flags.cf = (op >> (32 - 1)) & 1;
            if (count == 1) {
                cpu.flags.of = ((op >> (32 - 1)) ^ (op >> (32 - 2))) & 1;
            }
        }
    }
    // 00a94f90  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a94f91  75f3                   -jne 0xa94f86
    if (!cpu.flags.zf)
    {
        goto L_0x00a94f86;
    }
L_0x00a94f93:
    // 00a94f93  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a94f94  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00a94f97  e81b000000             -call 0xa94fb7
    cpu.esp -= 4;
    sub_a94fb7(app, cpu);
    if (cpu.terminate) return;
    // 00a94f9c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a94f9d  83e103                 +and ecx, 3
    cpu.clear_co();
    cpu.set_szp((cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/))));
    // 00a94fa0  740e                   -je 0xa94fb0
    if (cpu.flags.zf)
    {
        goto L_0x00a94fb0;
    }
    // 00a94fa2  8810                   -mov byte ptr [eax], dl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.dl;
    // 00a94fa4  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a94fa5  7409                   -je 0xa94fb0
    if (cpu.flags.zf)
    {
        goto L_0x00a94fb0;
    }
    // 00a94fa7  887001                 -mov byte ptr [eax + 1], dh
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */) = cpu.dh;
    // 00a94faa  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a94fab  7403                   -je 0xa94fb0
    if (cpu.flags.zf)
    {
        goto L_0x00a94fb0;
    }
    // 00a94fad  885002                 -mov byte ptr [eax + 2], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */) = cpu.dl;
L_0x00a94fb0:
    // 00a94fb0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void sub_a94fb2(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a94fb2  90                     -nop 
    ;
    // 00a94fb3  90                     -nop 
    ;
    // 00a94fb4  90                     -nop 
    ;
    // 00a94fb5  90                     -nop 
    ;
    // 00a94fb6  90                     -nop 
    ;
    // 00a94fb7  09c9                   +or ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx |= x86::reg32(x86::sreg32(cpu.ecx))));
    // 00a94fb9  7467                   -je 0xa95022
    if (cpu.flags.zf)
    {
        goto L_0x00a95022;
    }
L_0x00a94fbb:
    // 00a94fbb  a81f                   +test al, 0x1f
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 31 /*0x1f*/));
    // 00a94fbd  7408                   -je 0xa94fc7
    if (cpu.flags.zf)
    {
        goto L_0x00a94fc7;
    }
    // 00a94fbf  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 00a94fc1  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00a94fc4  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a94fc5  75f4                   -jne 0xa94fbb
    if (!cpu.flags.zf)
    {
        goto L_0x00a94fbb;
    }
L_0x00a94fc7:
    // 00a94fc7  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a94fc8  c1e902                 +shr ecx, 2
    {
        x86::reg8 tmp = 2 /*0x2*/ % 32;
        x86::reg32& op = cpu.ecx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 00a94fcb  743a                   -je 0xa95007
    if (cpu.flags.zf)
    {
        goto L_0x00a95007;
    }
    // 00a94fcd  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a94fce  7429                   -je 0xa94ff9
    if (cpu.flags.zf)
    {
        goto L_0x00a94ff9;
    }
L_0x00a94fd0:
    // 00a94fd0  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 00a94fd2  895004                 -mov dword ptr [eax + 4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00a94fd5  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a94fd6  895008                 -mov dword ptr [eax + 8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00a94fd9  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00a94fdc  7418                   -je 0xa94ff6
    if (cpu.flags.zf)
    {
        goto L_0x00a94ff6;
    }
    // 00a94fde  385020                 +cmp byte ptr [eax + 0x20], dl
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(32) /* 0x20 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.dl));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a94fe1  895010                 -mov dword ptr [eax + 0x10], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 00a94fe4  895014                 -mov dword ptr [eax + 0x14], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 00a94fe7  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a94fe8  895018                 -mov dword ptr [eax + 0x18], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 00a94feb  89501c                 -mov dword ptr [eax + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 00a94fee  8d4020                 -lea eax, [eax + 0x20]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 00a94ff1  75dd                   -jne 0xa94fd0
    if (!cpu.flags.zf)
    {
        goto L_0x00a94fd0;
    }
    // 00a94ff3  8d40f0                 -lea eax, [eax - 0x10]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(-16) /* -0x10 */);
L_0x00a94ff6:
    // 00a94ff6  8d4010                 -lea eax, [eax + 0x10]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(16) /* 0x10 */);
L_0x00a94ff9:
    // 00a94ff9  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 00a94ffb  895004                 -mov dword ptr [eax + 4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00a94ffe  895008                 -mov dword ptr [eax + 8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00a95001  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00a95004  8d4010                 -lea eax, [eax + 0x10]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(16) /* 0x10 */);
L_0x00a95007:
    // 00a95007  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a95008  83e103                 +and ecx, 3
    cpu.clear_co();
    cpu.set_szp((cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/))));
    // 00a9500b  7415                   -je 0xa95022
    if (cpu.flags.zf)
    {
        goto L_0x00a95022;
    }
    // 00a9500d  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 00a9500f  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00a95012  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a95013  740d                   -je 0xa95022
    if (cpu.flags.zf)
    {
        goto L_0x00a95022;
    }
    // 00a95015  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 00a95017  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00a9501a  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a9501b  7405                   -je 0xa95022
    if (cpu.flags.zf)
    {
        goto L_0x00a95022;
    }
    // 00a9501d  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 00a9501f  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
L_0x00a95022:
    // 00a95022  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a94fb7(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00a94fb7;
    // 00a94fb2  90                     -nop 
    ;
    // 00a94fb3  90                     -nop 
    ;
    // 00a94fb4  90                     -nop 
    ;
    // 00a94fb5  90                     -nop 
    ;
    // 00a94fb6  90                     -nop 
    ;
L_entry_0x00a94fb7:
    // 00a94fb7  09c9                   +or ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx |= x86::reg32(x86::sreg32(cpu.ecx))));
    // 00a94fb9  7467                   -je 0xa95022
    if (cpu.flags.zf)
    {
        goto L_0x00a95022;
    }
L_0x00a94fbb:
    // 00a94fbb  a81f                   +test al, 0x1f
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 31 /*0x1f*/));
    // 00a94fbd  7408                   -je 0xa94fc7
    if (cpu.flags.zf)
    {
        goto L_0x00a94fc7;
    }
    // 00a94fbf  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 00a94fc1  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00a94fc4  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a94fc5  75f4                   -jne 0xa94fbb
    if (!cpu.flags.zf)
    {
        goto L_0x00a94fbb;
    }
L_0x00a94fc7:
    // 00a94fc7  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a94fc8  c1e902                 +shr ecx, 2
    {
        x86::reg8 tmp = 2 /*0x2*/ % 32;
        x86::reg32& op = cpu.ecx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 00a94fcb  743a                   -je 0xa95007
    if (cpu.flags.zf)
    {
        goto L_0x00a95007;
    }
    // 00a94fcd  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a94fce  7429                   -je 0xa94ff9
    if (cpu.flags.zf)
    {
        goto L_0x00a94ff9;
    }
L_0x00a94fd0:
    // 00a94fd0  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 00a94fd2  895004                 -mov dword ptr [eax + 4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00a94fd5  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a94fd6  895008                 -mov dword ptr [eax + 8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00a94fd9  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00a94fdc  7418                   -je 0xa94ff6
    if (cpu.flags.zf)
    {
        goto L_0x00a94ff6;
    }
    // 00a94fde  385020                 +cmp byte ptr [eax + 0x20], dl
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(32) /* 0x20 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.dl));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a94fe1  895010                 -mov dword ptr [eax + 0x10], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 00a94fe4  895014                 -mov dword ptr [eax + 0x14], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 00a94fe7  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a94fe8  895018                 -mov dword ptr [eax + 0x18], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 00a94feb  89501c                 -mov dword ptr [eax + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 00a94fee  8d4020                 -lea eax, [eax + 0x20]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 00a94ff1  75dd                   -jne 0xa94fd0
    if (!cpu.flags.zf)
    {
        goto L_0x00a94fd0;
    }
    // 00a94ff3  8d40f0                 -lea eax, [eax - 0x10]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(-16) /* -0x10 */);
L_0x00a94ff6:
    // 00a94ff6  8d4010                 -lea eax, [eax + 0x10]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(16) /* 0x10 */);
L_0x00a94ff9:
    // 00a94ff9  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 00a94ffb  895004                 -mov dword ptr [eax + 4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00a94ffe  895008                 -mov dword ptr [eax + 8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00a95001  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00a95004  8d4010                 -lea eax, [eax + 0x10]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(16) /* 0x10 */);
L_0x00a95007:
    // 00a95007  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a95008  83e103                 +and ecx, 3
    cpu.clear_co();
    cpu.set_szp((cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/))));
    // 00a9500b  7415                   -je 0xa95022
    if (cpu.flags.zf)
    {
        goto L_0x00a95022;
    }
    // 00a9500d  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 00a9500f  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00a95012  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a95013  740d                   -je 0xa95022
    if (cpu.flags.zf)
    {
        goto L_0x00a95022;
    }
    // 00a95015  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 00a95017  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00a9501a  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a9501b  7405                   -je 0xa95022
    if (cpu.flags.zf)
    {
        goto L_0x00a95022;
    }
    // 00a9501d  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 00a9501f  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
L_0x00a95022:
    // 00a95022  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a95030(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a95030  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a95031  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a95033  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a95035  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 00a95037  e8741d0000             -call 0xa96db0
    cpu.esp -= 4;
    sub_a96db0(app, cpu);
    if (cpu.terminate) return;
    // 00a9503c  ff4310                 -inc dword ptr [ebx + 0x10]
    (app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */))++;
    // 00a9503f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a95040  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_a95044(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a95044  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a95045  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a95046  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a95047  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a95048  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a9504a  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 00a9504d  ff1598e2a900           -call dword ptr [0xa9e298]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11133592) /* 0xa9e298 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a95053  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00a95056  8b480c                 -mov ecx, dword ptr [eax + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00a95059  83f901                 +cmp ecx, 1
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a9505c  741b                   -je 0xa95079
    if (cpu.flags.zf)
    {
        goto L_0x00a95079;
    }
    // 00a9505e  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00a95060  7410                   -je 0xa95072
    if (cpu.flags.zf)
    {
        goto L_0x00a95072;
    }
    // 00a95062  8b4610                 -mov eax, dword ptr [esi + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 00a95065  ff159ce2a900           -call dword ptr [0xa9e29c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11133596) /* 0xa9e29c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a9506b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a9506d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9506e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9506f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a95070  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a95071  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a95072:
    // 00a95072  c7400c01000000         -mov dword ptr [eax + 0xc], 1
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = 1 /*0x1*/;
L_0x00a95079:
    // 00a95079  8a660c                 -mov ah, byte ptr [esi + 0xc]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 00a9507c  80e4cf                 -and ah, 0xcf
    cpu.ah &= x86::reg8(x86::sreg8(207 /*0xcf*/));
    // 00a9507f  8b6e0c                 -mov ebp, dword ptr [esi + 0xc]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 00a95082  88660c                 -mov byte ptr [esi + 0xc], ah
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.ah;
    // 00a95085  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00a95088  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00a9508b  83e530                 -and ebp, 0x30
    cpu.ebp &= x86::reg32(x86::sreg32(48 /*0x30*/));
    // 00a9508e  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00a95090  7507                   -jne 0xa95099
    if (!cpu.flags.zf)
    {
        goto L_0x00a95099;
    }
    // 00a95092  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a95094  e8371e0000             -call 0xa96ed0
    cpu.esp -= 4;
    sub_a96ed0(app, cpu);
    if (cpu.terminate) return;
L_0x00a95099:
    // 00a95099  8a4e0d                 -mov cl, byte ptr [esi + 0xd]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(13) /* 0xd */);
    // 00a9509c  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00a9509e  f6c104                 +test cl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 4 /*0x4*/));
    // 00a950a1  7414                   -je 0xa950b7
    if (cpu.flags.zf)
    {
        goto L_0x00a950b7;
    }
    // 00a950a3  88cd                   -mov ch, cl
    cpu.ch = cpu.cl;
    // 00a950a5  80e5fa                 -and ch, 0xfa
    cpu.ch &= x86::reg8(x86::sreg8(250 /*0xfa*/));
    // 00a950a8  88e8                   -mov al, ch
    cpu.al = cpu.ch;
    // 00a950aa  886e0d                 -mov byte ptr [esi + 0xd], ch
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(13) /* 0xd */) = cpu.ch;
    // 00a950ad  0c01                   -or al, 1
    cpu.al |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00a950af  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 00a950b4  88460d                 -mov byte ptr [esi + 0xd], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(13) /* 0xd */) = cpu.al;
L_0x00a950b7:
    // 00a950b7  b93050a900             -mov ecx, 0xa95030
    cpu.ecx = 11096112 /*0xa95030*/;
    // 00a950bc  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a950be  e8ad060000             -call 0xa95770
    cpu.esp -= 4;
    sub_a95770(app, cpu);
    if (cpu.terminate) return;
    // 00a950c3  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a950c5  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00a950c7  7418                   -je 0xa950e1
    if (cpu.flags.zf)
    {
        goto L_0x00a950e1;
    }
    // 00a950c9  8a660d                 -mov ah, byte ptr [esi + 0xd]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(13) /* 0xd */);
    // 00a950cc  80e4fa                 -and ah, 0xfa
    cpu.ah &= x86::reg8(x86::sreg8(250 /*0xfa*/));
    // 00a950cf  88e3                   -mov bl, ah
    cpu.bl = cpu.ah;
    // 00a950d1  88660d                 -mov byte ptr [esi + 0xd], ah
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(13) /* 0xd */) = cpu.ah;
    // 00a950d4  80cb04                 -or bl, 4
    cpu.bl |= x86::reg8(x86::sreg8(4 /*0x4*/));
    // 00a950d7  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a950d9  885e0d                 -mov byte ptr [esi + 0xd], bl
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(13) /* 0xd */) = cpu.bl;
    // 00a950dc  e83f010000             -call 0xa95220
    cpu.esp -= 4;
    sub_a95220(app, cpu);
    if (cpu.terminate) return;
L_0x00a950e1:
    // 00a950e1  f6460c20               +test byte ptr [esi + 0xc], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(12) /* 0xc */) & 32 /*0x20*/));
    // 00a950e5  7405                   -je 0xa950ec
    if (cpu.flags.zf)
    {
        goto L_0x00a950ec;
    }
    // 00a950e7  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
L_0x00a950ec:
    // 00a950ec  8b7e0c                 -mov edi, dword ptr [esi + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 00a950ef  09ef                   -or edi, ebp
    cpu.edi |= x86::reg32(x86::sreg32(cpu.ebp));
    // 00a950f1  8b4610                 -mov eax, dword ptr [esi + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 00a950f4  897e0c                 -mov dword ptr [esi + 0xc], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.edi;
    // 00a950f7  ff159ce2a900           -call dword ptr [0xa9e29c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11133596) /* 0xa9e29c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a950fd  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a950ff  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a95100  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a95101  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a95102  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a95103  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a95110(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a95110  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a95111  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a95112  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a95113  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a95114  8a25a1dfa900           -mov ah, byte ptr [0xa9dfa1]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(11132833) /* 0xa9dfa1 */);
    // 00a9511a  80e4f8                 -and ah, 0xf8
    cpu.ah &= x86::reg8(x86::sreg8(248 /*0xf8*/));
    // 00a9511d  88e2                   -mov dl, ah
    cpu.dl = cpu.ah;
    // 00a9511f  8825a1dfa900           -mov byte ptr [0xa9dfa1], ah
    app->getMemory<x86::reg8>(x86::reg32(11132833) /* 0xa9dfa1 */) = cpu.ah;
    // 00a95125  80ca04                 -or dl, 4
    cpu.dl |= x86::reg8(x86::sreg8(4 /*0x4*/));
    // 00a95128  8815a1dfa900           -mov byte ptr [0xa9dfa1], dl
    app->getMemory<x86::reg8>(x86::reg32(11132833) /* 0xa9dfa1 */) = cpu.dl;
    // 00a9512e  8b156cdfa900           -mov edx, dword ptr [0xa9df6c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11132780) /* 0xa9df6c */);
    // 00a95134  bb60dfa900             -mov ebx, 0xa9df60
    cpu.ebx = 11132768 /*0xa9df60*/;
    // 00a95139  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a9513b  7466                   -je 0xa951a3
    if (cpu.flags.zf)
    {
        goto L_0x00a951a3;
    }
L_0x00a9513d:
    // 00a9513d  b81d000000             -mov eax, 0x1d
    cpu.eax = 29 /*0x1d*/;
    // 00a95142  e839fbffff             -call 0xa94c80
    cpu.esp -= 4;
    sub_a94c80(app, cpu);
    if (cpu.terminate) return;
    // 00a95147  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a95149  7521                   -jne 0xa9516c
    if (!cpu.flags.zf)
    {
        goto L_0x00a9516c;
    }
    // 00a9514b  b81d000000             -mov eax, 0x1d
    cpu.eax = 29 /*0x1d*/;
    // 00a95150  e82bfbffff             -call 0xa94c80
    cpu.esp -= 4;
    sub_a94c80(app, cpu);
    if (cpu.terminate) return;
    // 00a95155  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a95157  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a95159  7513                   -jne 0xa9516e
    if (!cpu.flags.zf)
    {
        goto L_0x00a9516e;
    }
    // 00a9515b  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00a95160  b82ceda900             -mov eax, 0xa9ed2c
    cpu.eax = 11136300 /*0xa9ed2c*/;
    // 00a95165  e8321e0000             -call 0xa96f9c
    cpu.esp -= 4;
    sub_a96f9c(app, cpu);
    if (cpu.terminate) return;
    // 00a9516a  eb02                   -jmp 0xa9516e
    goto L_0x00a9516e;
L_0x00a9516c:
    // 00a9516c  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_0x00a9516e:
    // 00a9516e  a1e00faa00             -mov eax, dword ptr [0xaa0fe0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11145184) /* 0xaa0fe0 */);
    // 00a95173  895904                 -mov dword ptr [ecx + 4], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 00a95176  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 00a95178  894b08                 -mov dword ptr [ebx + 8], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 00a9517b  c7410800000000         -mov dword ptr [ecx + 8], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 00a95182  8b4308                 -mov eax, dword ptr [ebx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 00a95185  c6401400               -mov byte ptr [eax + 0x14], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(20) /* 0x14 */) = 0 /*0x0*/;
    // 00a95189  8b4308                 -mov eax, dword ptr [ebx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 00a9518c  c7400c00000000         -mov dword ptr [eax + 0xc], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 00a95193  890de00faa00           -mov dword ptr [0xaa0fe0], ecx
    app->getMemory<x86::reg32>(x86::reg32(11145184) /* 0xaa0fe0 */) = cpu.ecx;
    // 00a95199  8b4b26                 -mov ecx, dword ptr [ebx + 0x26]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(38) /* 0x26 */);
    // 00a9519c  83c31a                 -add ebx, 0x1a
    (cpu.ebx) += x86::reg32(x86::sreg32(26 /*0x1a*/));
    // 00a9519f  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00a951a1  759a                   -jne 0xa9513d
    if (!cpu.flags.zf)
    {
        goto L_0x00a9513d;
    }
L_0x00a951a3:
    // 00a951a3  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00a951a5  8935e40faa00           -mov dword ptr [0xaa0fe4], esi
    app->getMemory<x86::reg32>(x86::reg32(11145188) /* 0xaa0fe4 */) = cpu.esi;
    // 00a951ab  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a951ac  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a951ad  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a951ae  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a951af  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a951b0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a951b0  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a951b2  e80d000000             -call 0xa951c4
    cpu.esp -= 4;
    sub_a951c4(app, cpu);
    if (cpu.terminate) return;
    // 00a951b7  e9041f0000             -jmp 0xa970c0
    return sub_a970c0(app, cpu);
}

/* align: skip  */
void sub_a951bc(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a951bc  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 00a951c1  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 00a951c4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a951c5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a951c6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a951c7  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a951c8  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a951ca  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00a951cd  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00a951cf  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00a951d2  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00a951d4  be60dfa900             -mov esi, 0xa9df60
    cpu.esi = 11132768 /*0xa9df60*/;
    // 00a951d9  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 00a951db  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00a951dd  a1e00faa00             -mov eax, dword ptr [0xaa0fe0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11145184) /* 0xaa0fe0 */);
    // 00a951e2  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a951e4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a951e6  742f                   -je 0xa95217
    if (cpu.flags.zf)
    {
        goto L_0x00a95217;
    }
L_0x00a951e8:
    // 00a951e8  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 00a951ea  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00a951ed  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00a951f2  f6400d40               +test byte ptr [eax + 0xd], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(13) /* 0xd */) & 64 /*0x40*/));
    // 00a951f6  7513                   -jne 0xa9520b
    if (!cpu.flags.zf)
    {
        goto L_0x00a9520b;
    }
    // 00a951f8  f6400d08               +test byte ptr [eax + 0xd], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(13) /* 0xd */) & 8 /*0x8*/));
    // 00a951fc  750d                   -jne 0xa9520b
    if (!cpu.flags.zf)
    {
        goto L_0x00a9520b;
    }
    // 00a951fe  39f0                   +cmp eax, esi
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
    // 00a95200  720f                   -jb 0xa95211
    if (cpu.flags.cf)
    {
        goto L_0x00a95211;
    }
    // 00a95202  3daedfa900             +cmp eax, 0xa9dfae
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(11132846 /*0xa9dfae*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a95207  7302                   -jae 0xa9520b
    if (!cpu.flags.cf)
    {
        goto L_0x00a9520b;
    }
    // 00a95209  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00a9520b:
    // 00a9520b  e8241f0000             -call 0xa97134
    cpu.esp -= 4;
    sub_a97134(app, cpu);
    if (cpu.terminate) return;
    // 00a95210  43                     -inc ebx
    (cpu.ebx)++;
L_0x00a95211:
    // 00a95211  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a95213  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00a95215  75d1                   -jne 0xa951e8
    if (!cpu.flags.zf)
    {
        goto L_0x00a951e8;
    }
L_0x00a95217:
    // 00a95217  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a95219  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9521a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9521b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9521c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9521d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a951c4(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00a951c4;
    // 00a951bc  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 00a951c1  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_entry_0x00a951c4:
    // 00a951c4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a951c5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a951c6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a951c7  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a951c8  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a951ca  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00a951cd  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00a951cf  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00a951d2  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00a951d4  be60dfa900             -mov esi, 0xa9df60
    cpu.esi = 11132768 /*0xa9df60*/;
    // 00a951d9  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 00a951db  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00a951dd  a1e00faa00             -mov eax, dword ptr [0xaa0fe0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11145184) /* 0xaa0fe0 */);
    // 00a951e2  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a951e4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a951e6  742f                   -je 0xa95217
    if (cpu.flags.zf)
    {
        goto L_0x00a95217;
    }
L_0x00a951e8:
    // 00a951e8  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 00a951ea  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00a951ed  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00a951f2  f6400d40               +test byte ptr [eax + 0xd], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(13) /* 0xd */) & 64 /*0x40*/));
    // 00a951f6  7513                   -jne 0xa9520b
    if (!cpu.flags.zf)
    {
        goto L_0x00a9520b;
    }
    // 00a951f8  f6400d08               +test byte ptr [eax + 0xd], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(13) /* 0xd */) & 8 /*0x8*/));
    // 00a951fc  750d                   -jne 0xa9520b
    if (!cpu.flags.zf)
    {
        goto L_0x00a9520b;
    }
    // 00a951fe  39f0                   +cmp eax, esi
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
    // 00a95200  720f                   -jb 0xa95211
    if (cpu.flags.cf)
    {
        goto L_0x00a95211;
    }
    // 00a95202  3daedfa900             +cmp eax, 0xa9dfae
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(11132846 /*0xa9dfae*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a95207  7302                   -jae 0xa9520b
    if (!cpu.flags.cf)
    {
        goto L_0x00a9520b;
    }
    // 00a95209  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00a9520b:
    // 00a9520b  e8241f0000             -call 0xa97134
    cpu.esp -= 4;
    sub_a97134(app, cpu);
    if (cpu.terminate) return;
    // 00a95210  43                     -inc ebx
    (cpu.ebx)++;
L_0x00a95211:
    // 00a95211  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a95213  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00a95215  75d1                   -jne 0xa951e8
    if (!cpu.flags.zf)
    {
        goto L_0x00a951e8;
    }
L_0x00a95217:
    // 00a95217  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a95219  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9521a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9521b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9521c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9521d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void sub_a95220(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a95220  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a95221  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a95222  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a95223  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a95224  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a95225  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a95226  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a95228  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 00a9522b  ff1598e2a900           -call dword ptr [0xa9e298]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11133592) /* 0xa9e298 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a95231  8a610d                 -mov ah, byte ptr [ecx + 0xd]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(13) /* 0xd */);
    // 00a95234  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 00a95236  f6c410                 +test ah, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 16 /*0x10*/));
    // 00a95239  0f847a000000           -je 0xa952b9
    if (cpu.flags.zf)
    {
        goto L_0x00a952b9;
    }
    // 00a9523f  88e7                   -mov bh, ah
    cpu.bh = cpu.ah;
    // 00a95241  80e7ef                 -and bh, 0xef
    cpu.bh &= x86::reg8(x86::sreg8(239 /*0xef*/));
    // 00a95244  8a410c                 -mov al, byte ptr [ecx + 0xc]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00a95247  88790d                 -mov byte ptr [ecx + 0xd], bh
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(13) /* 0xd */) = cpu.bh;
    // 00a9524a  a802                   +test al, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 2 /*0x2*/));
    // 00a9524c  0f84a2000000           -je 0xa952f4
    if (cpu.flags.zf)
    {
        goto L_0x00a952f4;
    }
    // 00a95252  8b7908                 -mov edi, dword ptr [ecx + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00a95255  8b5f08                 -mov ebx, dword ptr [edi + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 00a95258  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a9525a  0f8494000000           -je 0xa952f4
    if (cpu.flags.zf)
    {
        goto L_0x00a952f4;
    }
    // 00a95260  8b7104                 -mov esi, dword ptr [ecx + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00a95263  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00a95265  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a95267  0f8487000000           -je 0xa952f4
    if (cpu.flags.zf)
    {
        goto L_0x00a952f4;
    }
L_0x00a9526d:
    // 00a9526d  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00a9526f  0f857f000000           -jne 0xa952f4
    if (!cpu.flags.zf)
    {
        goto L_0x00a952f4;
    }
    // 00a95275  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00a95277  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00a95279  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00a9527c  e84f200000             -call 0xa972d0
    cpu.esp -= 4;
    sub_a972d0(app, cpu);
    if (cpu.terminate) return;
    // 00a95281  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a95283  83f8ff                 +cmp eax, -1
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
    // 00a95286  750d                   -jne 0xa95295
    if (!cpu.flags.zf)
    {
        goto L_0x00a95295;
    }
    // 00a95288  8a590c                 -mov bl, byte ptr [ecx + 0xc]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00a9528b  80cb20                 +or bl, 0x20
    cpu.clear_co();
    cpu.set_szp((cpu.bl |= x86::reg8(x86::sreg8(32 /*0x20*/))));
    // 00a9528e  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00a95290  88590c                 -mov byte ptr [ecx + 0xc], bl
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.bl;
    // 00a95293  eb1c                   -jmp 0xa952b1
    goto L_0x00a952b1;
L_0x00a95295:
    // 00a95295  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a95297  7518                   -jne 0xa952b1
    if (!cpu.flags.zf)
    {
        goto L_0x00a952b1;
    }
    // 00a95299  b80c000000             -mov eax, 0xc
    cpu.eax = 12 /*0xc*/;
    // 00a9529e  e81d210000             -call 0xa973c0
    cpu.esp -= 4;
    sub_a973c0(app, cpu);
    if (cpu.terminate) return;
    // 00a952a3  8a610c                 -mov ah, byte ptr [ecx + 0xc]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00a952a6  80cc20                 -or ah, 0x20
    cpu.ah |= x86::reg8(x86::sreg8(32 /*0x20*/));
    // 00a952a9  bdffffffff             -mov ebp, 0xffffffff
    cpu.ebp = 4294967295 /*0xffffffff*/;
    // 00a952ae  88610c                 -mov byte ptr [ecx + 0xc], ah
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.ah;
L_0x00a952b1:
    // 00a952b1  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 00a952b3  29d6                   +sub esi, edx
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a952b5  75b6                   -jne 0xa9526d
    if (!cpu.flags.zf)
    {
        goto L_0x00a9526d;
    }
    // 00a952b7  eb3b                   -jmp 0xa952f4
    goto L_0x00a952f4;
L_0x00a952b9:
    // 00a952b9  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00a952bc  83780800               +cmp dword ptr [eax + 8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a952c0  7432                   -je 0xa952f4
    if (cpu.flags.zf)
    {
        goto L_0x00a952f4;
    }
    // 00a952c2  80610cef               -and byte ptr [ecx + 0xc], 0xef
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */) &= x86::reg8(x86::sreg8(239 /*0xef*/));
    // 00a952c6  f6410d20               +test byte ptr [ecx + 0xd], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(13) /* 0xd */) & 32 /*0x20*/));
    // 00a952ca  7528                   -jne 0xa952f4
    if (!cpu.flags.zf)
    {
        goto L_0x00a952f4;
    }
    // 00a952cc  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00a952cf  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a952d1  7411                   -je 0xa952e4
    if (cpu.flags.zf)
    {
        goto L_0x00a952e4;
    }
    // 00a952d3  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a952d5  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00a952da  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
    // 00a952dc  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00a952df  e83c210000             -call 0xa97420
    cpu.esp -= 4;
    sub_a97420(app, cpu);
    if (cpu.terminate) return;
L_0x00a952e4:
    // 00a952e4  83f8ff                 +cmp eax, -1
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
    // 00a952e7  750b                   -jne 0xa952f4
    if (!cpu.flags.zf)
    {
        goto L_0x00a952f4;
    }
    // 00a952e9  8a590c                 -mov bl, byte ptr [ecx + 0xc]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00a952ec  80cb20                 -or bl, 0x20
    cpu.bl |= x86::reg8(x86::sreg8(32 /*0x20*/));
    // 00a952ef  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00a952f1  88590c                 -mov byte ptr [ecx + 0xc], bl
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.bl;
L_0x00a952f4:
    // 00a952f4  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00a952f7  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00a952fa  c7410400000000         -mov dword ptr [ecx + 4], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 00a95301  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 00a95303  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00a95305  7518                   -jne 0xa9531f
    if (!cpu.flags.zf)
    {
        goto L_0x00a9531f;
    }
    // 00a95307  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00a9530a  f6401001               +test byte ptr [eax + 0x10], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(16) /* 0x10 */) & 1 /*0x1*/));
    // 00a9530e  740f                   -je 0xa9531f
    if (cpu.flags.zf)
    {
        goto L_0x00a9531f;
    }
    // 00a95310  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00a95313  e888210000             -call 0xa974a0
    cpu.esp -= 4;
    sub_a974a0(app, cpu);
    if (cpu.terminate) return;
    // 00a95318  83f8ff                 +cmp eax, -1
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
    // 00a9531b  7502                   -jne 0xa9531f
    if (!cpu.flags.zf)
    {
        goto L_0x00a9531f;
    }
    // 00a9531d  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
L_0x00a9531f:
    // 00a9531f  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00a95322  ff159ce2a900           -call dword ptr [0xa9e29c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11133596) /* 0xa9e29c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a95328  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00a9532a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9532b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9532c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9532d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9532e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9532f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a95330  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a95340(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a95340  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a95345  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 00a95348  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a95349  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a9534a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a9534b  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a9534d  ff15a8e2a900           -call dword ptr [0xa9e2a8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11133608) /* 0xa9e2a8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a95353  8b15e00faa00           -mov edx, dword ptr [0xaa0fe0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11145184) /* 0xaa0fe0 */);
    // 00a95359  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a9535b  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a9535d  741a                   -je 0xa95379
    if (cpu.flags.zf)
    {
        goto L_0x00a95379;
    }
L_0x00a9535f:
    // 00a9535f  8b4204                 -mov eax, dword ptr [edx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00a95362  85480c                 -test dword ptr [eax + 0xc], ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) & cpu.ecx));
    // 00a95365  740c                   -je 0xa95373
    if (cpu.flags.zf)
    {
        goto L_0x00a95373;
    }
    // 00a95367  43                     -inc ebx
    (cpu.ebx)++;
    // 00a95368  f6400d10               +test byte ptr [eax + 0xd], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(13) /* 0xd */) & 16 /*0x10*/));
    // 00a9536c  7405                   -je 0xa95373
    if (cpu.flags.zf)
    {
        goto L_0x00a95373;
    }
    // 00a9536e  e8adfeffff             -call 0xa95220
    cpu.esp -= 4;
    sub_a95220(app, cpu);
    if (cpu.terminate) return;
L_0x00a95373:
    // 00a95373  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 00a95375  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a95377  75e6                   -jne 0xa9535f
    if (!cpu.flags.zf)
    {
        goto L_0x00a9535f;
    }
L_0x00a95379:
    // 00a95379  ff15ace2a900           -call dword ptr [0xa9e2ac]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11133612) /* 0xa9e2ac */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a9537f  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a95381  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a95382  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a95383  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a95384  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a95390(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a95390  ff1594e2a900           -call dword ptr [0xa9e294]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11133588) /* 0xa9e294 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a95396  05da000000             -add eax, 0xda
    (cpu.eax) += x86::reg32(x86::sreg32(218 /*0xda*/));
    // 00a9539b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a9539c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9539c  a11c10aa00             -mov eax, dword ptr [0xaa101c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11145244) /* 0xaa101c */);
    // 00a953a1  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 00a953a4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a953a4(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00a953a4;
    // 00a9539c  a11c10aa00             -mov eax, dword ptr [0xaa101c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11145244) /* 0xaa101c */);
    // 00a953a1  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_entry_0x00a953a4:
    // 00a953a4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_a953a8(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a953a8  e9a7210000             -jmp 0xa97554
    return sub_a97554(app, cpu);
}

/* align: skip 0x8d 0x40 0x00 */
void sub_a953b0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a953b0  e9f7220000             -jmp 0xa976ac
    return sub_a976ac(app, cpu);
}

/* align: skip 0x8d 0x40 0x00 */
void sub_a953b8(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a953b8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a953b9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a953ba  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a953bb  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a953bd  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00a953bf  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a953c1  89351010aa00           -mov dword ptr [0xaa1010], esi
    app->getMemory<x86::reg32>(x86::reg32(11145232) /* 0xaa1010 */) = cpu.esi;
    // 00a953c7  e870260000             -call 0xa97a3c
    cpu.esp -= 4;
    sub_a97a3c(app, cpu);
    if (cpu.terminate) return;
    // 00a953cc  a31c10aa00             -mov dword ptr [0xaa101c], eax
    app->getMemory<x86::reg32>(x86::reg32(11145244) /* 0xaa101c */) = cpu.eax;
    // 00a953d1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a953d3  7511                   -jne 0xa953e6
    if (!cpu.flags.zf)
    {
        goto L_0x00a953e6;
    }
    // 00a953d5  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a953d7  0f8505020000           -jne 0xa955e2
    if (!cpu.flags.zf)
    {
        goto L_0x00a955e2;
    }
    // 00a953dd  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00a953df  2eff15a4cda900         -call dword ptr cs:[0xa9cda4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11128228) /* 0xa9cda4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00a953e6:
    // 00a953e6  e8f5220000             -call 0xa976e0
    cpu.esp -= 4;
    sub_a976e0(app, cpu);
    if (cpu.terminate) return;
    // 00a953eb  2eff15d4cda900         -call dword ptr cs:[0xa9cdd4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11128276) /* 0xa9cdd4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a953f2  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a953f4  a369e3a900             -mov dword ptr [0xa9e369], eax
    app->getMemory<x86::reg32>(x86::reg32(11133801) /* 0xa9e369 */) = cpu.eax;
    // 00a953f9  89150410aa00           -mov dword ptr [0xaa1004], edx
    app->getMemory<x86::reg32>(x86::reg32(11145220) /* 0xaa1004 */) = cpu.edx;
    // 00a953ff  2eff1504cea900         -call dword ptr cs:[0xa9ce04]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11128324) /* 0xa9ce04 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a95406  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a95408  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a9540a  a26fe3a900             -mov byte ptr [0xa9e36f], al
    app->getMemory<x86::reg8>(x86::reg32(11133807) /* 0xa9e36f */) = cpu.al;
    // 00a9540f  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 00a95412  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00a95417  6804010000             -push 0x104
    app->getMemory<x86::reg32>(cpu.esp-4) = 260 /*0x104*/;
    cpu.esp -= 4;
    // 00a9541c  66a371e3a900           -mov word ptr [0xa9e371], ax
    app->getMemory<x86::reg16>(x86::reg32(11133809) /* 0xa9e371 */) = cpu.ax;
    // 00a95422  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a95424  81e2ffff0000           -and edx, 0xffff
    cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00a9542a  66a171e3a900           -mov ax, word ptr [0xa9e371]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(11133809) /* 0xa9e371 */);
    // 00a95430  682010aa00             -push 0xaa1020
    app->getMemory<x86::reg32>(cpu.esp-4) = 11145248 /*0xaa1020*/;
    cpu.esp -= 4;
    // 00a95435  a373e3a900             -mov dword ptr [0xa9e373], eax
    app->getMemory<x86::reg32>(x86::reg32(11133811) /* 0xa9e373 */) = cpu.eax;
    // 00a9543a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a9543c  c1fa08                 -sar edx, 8
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (8 /*0x8*/ % 32));
    // 00a9543f  88d8                   -mov al, bl
    cpu.al = cpu.bl;
    // 00a95441  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00a95447  a377e3a900             -mov dword ptr [0xa9e377], eax
    app->getMemory<x86::reg32>(x86::reg32(11133815) /* 0xa9e377 */) = cpu.eax;
    // 00a9544c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a9544e  881570e3a900           -mov byte ptr [0xa9e370], dl
    app->getMemory<x86::reg8>(x86::reg32(11133808) /* 0xa9e370 */) = cpu.dl;
    // 00a95454  88d0                   -mov al, dl
    cpu.al = cpu.dl;
    // 00a95456  8b1577e3a900           -mov edx, dword ptr [0xa9e377]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11133815) /* 0xa9e377 */);
    // 00a9545c  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a9545e  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 00a95461  bb2010aa00             -mov ebx, 0xaa1020
    cpu.ebx = 11145248 /*0xaa1020*/;
    // 00a95466  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 00a95468  a37be3a900             -mov dword ptr [0xa9e37b], eax
    app->getMemory<x86::reg32>(x86::reg32(11133819) /* 0xa9e37b */) = cpu.eax;
    // 00a9546d  89157fe3a900           -mov dword ptr [0xa9e37f], edx
    app->getMemory<x86::reg32>(x86::reg32(11133823) /* 0xa9e37f */) = cpu.edx;
    // 00a95473  2eff15e8cda900         -call dword ptr cs:[0xa9cde8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11128296) /* 0xa9cde8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a9547a  ba2411aa00             -mov edx, 0xaa1124
    cpu.edx = 11145508 /*0xaa1124*/;
    // 00a9547f  891d30e3a900           -mov dword ptr [0xa9e330], ebx
    app->getMemory<x86::reg32>(x86::reg32(11133744) /* 0xa9e330 */) = cpu.ebx;
    // 00a95485  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a95487  bb08020000             -mov ebx, 0x208
    cpu.ebx = 520 /*0x208*/;
    // 00a9548c  b92411aa00             -mov ecx, 0xaa1124
    cpu.ecx = 11145508 /*0xaa1124*/;
    // 00a95491  e8ba280000             -call 0xa97d50
    cpu.esp -= 4;
    sub_a97d50(app, cpu);
    if (cpu.terminate) return;
    // 00a95496  890d3ce3a900           -mov dword ptr [0xa9e33c], ecx
    app->getMemory<x86::reg32>(x86::reg32(11133756) /* 0xa9e33c */) = cpu.ecx;
    // 00a9549c  2eff15bccda900         -call dword ptr cs:[0xa9cdbc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11128252) /* 0xa9cdbc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a954a3  e848290000             -call 0xa97df0
    cpu.esp -= 4;
    sub_a97df0(app, cpu);
    if (cpu.terminate) return;
    // 00a954a8  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a954aa  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 00a954ac  a31410aa00             -mov dword ptr [0xaa1014], eax
    app->getMemory<x86::reg32>(x86::reg32(11145236) /* 0xaa1014 */) = cpu.eax;
    // 00a954b1  80fb22                 +cmp bl, 0x22
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(34 /*0x22*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a954b4  751e                   -jne 0xa954d4
    if (!cpu.flags.zf)
    {
        goto L_0x00a954d4;
    }
    // 00a954b6  8a7801                 -mov bh, byte ptr [eax + 1]
    cpu.bh = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a954b9  40                     -inc eax
    (cpu.eax)++;
    // 00a954ba  38df                   +cmp bh, bl
    {
        x86::reg8 tmp1 = cpu.bh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.bl));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a954bc  740e                   -je 0xa954cc
    if (cpu.flags.zf)
    {
        goto L_0x00a954cc;
    }
L_0x00a954be:
    // 00a954be  803800                 +cmp byte ptr [eax], 0
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
    // 00a954c1  7409                   -je 0xa954cc
    if (cpu.flags.zf)
    {
        goto L_0x00a954cc;
    }
    // 00a954c3  8a5001                 -mov dl, byte ptr [eax + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a954c6  40                     -inc eax
    (cpu.eax)++;
    // 00a954c7  80fa22                 +cmp dl, 0x22
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(34 /*0x22*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a954ca  75f2                   -jne 0xa954be
    if (!cpu.flags.zf)
    {
        goto L_0x00a954be;
    }
L_0x00a954cc:
    // 00a954cc  803800                 +cmp byte ptr [eax], 0
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
    // 00a954cf  741e                   -je 0xa954ef
    if (cpu.flags.zf)
    {
        goto L_0x00a954ef;
    }
    // 00a954d1  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a954d2  eb1b                   -jmp 0xa954ef
    goto L_0x00a954ef;
L_0x00a954d4:
    // 00a954d4  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 00a954d6  fec2                   -inc dl
    (cpu.dl)++;
    // 00a954d8  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00a954de  f6828ce1a90002         +test byte ptr [edx + 0xa9e18c], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(11133324) /* 0xa9e18c */) & 2 /*0x2*/));
    // 00a954e5  7508                   -jne 0xa954ef
    if (!cpu.flags.zf)
    {
        goto L_0x00a954ef;
    }
    // 00a954e7  803800                 +cmp byte ptr [eax], 0
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
    // 00a954ea  7403                   -je 0xa954ef
    if (cpu.flags.zf)
    {
        goto L_0x00a954ef;
    }
    // 00a954ec  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a954ed  ebe5                   -jmp 0xa954d4
    goto L_0x00a954d4;
L_0x00a954ef:
    // 00a954ef  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 00a954f1  fec2                   -inc dl
    (cpu.dl)++;
    // 00a954f3  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00a954f9  f6828ce1a90002         +test byte ptr [edx + 0xa9e18c], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(11133324) /* 0xa9e18c */) & 2 /*0x2*/));
    // 00a95500  7403                   -je 0xa95505
    if (cpu.flags.zf)
    {
        goto L_0x00a95505;
    }
    // 00a95502  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a95503  ebea                   -jmp 0xa954ef
    goto L_0x00a954ef;
L_0x00a95505:
    // 00a95505  a32ce3a900             -mov dword ptr [0xa9e32c], eax
    app->getMemory<x86::reg32>(x86::reg32(11133740) /* 0xa9e32c */) = cpu.eax;
    // 00a9550a  2eff15c0cda900         -call dword ptr cs:[0xa9cdc0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11128256) /* 0xa9cdc0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a95511  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a95513  0f847d000000           -je 0xa95596
    if (cpu.flags.zf)
    {
        goto L_0x00a95596;
    }
    // 00a95519  e822290000             -call 0xa97e40
    cpu.esp -= 4;
    sub_a97e40(app, cpu);
    if (cpu.terminate) return;
    // 00a9551e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a95520  668b18                 -mov bx, word ptr [eax]
    cpu.bx = app->getMemory<x86::reg16>(cpu.eax);
    // 00a95523  a31810aa00             -mov dword ptr [0xaa1018], eax
    app->getMemory<x86::reg32>(x86::reg32(11145240) /* 0xaa1018 */) = cpu.eax;
    // 00a95528  6683fb22               +cmp bx, 0x22
    {
        x86::reg16 tmp1 = cpu.bx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(34 /*0x22*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00a9552c  752a                   -jne 0xa95558
    if (!cpu.flags.zf)
    {
        goto L_0x00a95558;
    }
    // 00a9552e  668b4802               -mov cx, word ptr [eax + 2]
    cpu.cx = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 00a95532  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00a95535  6639d9                 +cmp cx, bx
    {
        x86::reg16 tmp1 = cpu.cx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(cpu.bx));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00a95538  7413                   -je 0xa9554d
    if (cpu.flags.zf)
    {
        goto L_0x00a9554d;
    }
L_0x00a9553a:
    // 00a9553a  66833800               +cmp word ptr [eax], 0
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
    // 00a9553e  740d                   -je 0xa9554d
    if (cpu.flags.zf)
    {
        goto L_0x00a9554d;
    }
    // 00a95540  668b5802               -mov bx, word ptr [eax + 2]
    cpu.bx = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 00a95544  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00a95547  6683fb22               +cmp bx, 0x22
    {
        x86::reg16 tmp1 = cpu.bx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(34 /*0x22*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00a9554b  75ed                   -jne 0xa9553a
    if (!cpu.flags.zf)
    {
        goto L_0x00a9553a;
    }
L_0x00a9554d:
    // 00a9554d  66833800               +cmp word ptr [eax], 0
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
    // 00a95551  7427                   -je 0xa9557a
    if (cpu.flags.zf)
    {
        goto L_0x00a9557a;
    }
    // 00a95553  83c002                 +add eax, 2
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a95556  eb22                   -jmp 0xa9557a
    goto L_0x00a9557a;
L_0x00a95558:
    // 00a95558  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
L_0x00a9555d:
    // 00a9555d  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 00a9555f  fec2                   -inc dl
    (cpu.dl)++;
    // 00a95561  81e2ff000000           +and edx, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 00a95567  849a8ce1a900           -test byte ptr [edx + 0xa9e18c], bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(11133324) /* 0xa9e18c */) & cpu.bl));
    // 00a9556d  750b                   -jne 0xa9557a
    if (!cpu.flags.zf)
    {
        goto L_0x00a9557a;
    }
    // 00a9556f  66833800               +cmp word ptr [eax], 0
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
    // 00a95573  7405                   -je 0xa9557a
    if (cpu.flags.zf)
    {
        goto L_0x00a9557a;
    }
    // 00a95575  83c002                 +add eax, 2
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a95578  ebe3                   -jmp 0xa9555d
    goto L_0x00a9555d;
L_0x00a9557a:
    // 00a9557a  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
L_0x00a9557f:
    // 00a9557f  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 00a95581  fec2                   -inc dl
    (cpu.dl)++;
    // 00a95583  81e2ff000000           +and edx, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 00a95589  849a8ce1a900           -test byte ptr [edx + 0xa9e18c], bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(11133324) /* 0xa9e18c */) & cpu.bl));
    // 00a9558f  740a                   -je 0xa9559b
    if (cpu.flags.zf)
    {
        goto L_0x00a9559b;
    }
    // 00a95591  83c002                 +add eax, 2
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a95594  ebe9                   -jmp 0xa9557f
    goto L_0x00a9557f;
L_0x00a95596:
    // 00a95596  b85ceda900             -mov eax, 0xa9ed5c
    cpu.eax = 11136348 /*0xa9ed5c*/;
L_0x00a9559b:
    // 00a9559b  a338e3a900             -mov dword ptr [0xa9e338], eax
    app->getMemory<x86::reg32>(x86::reg32(11133752) /* 0xa9e338 */) = cpu.eax;
    // 00a955a0  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a955a2  7439                   -je 0xa955dd
    if (cpu.flags.zf)
    {
        goto L_0x00a955dd;
    }
    // 00a955a4  6804010000             -push 0x104
    app->getMemory<x86::reg32>(cpu.esp-4) = 260 /*0x104*/;
    cpu.esp -= 4;
    // 00a955a9  682c13aa00             -push 0xaa132c
    app->getMemory<x86::reg32>(cpu.esp-4) = 11146028 /*0xaa132c*/;
    cpu.esp -= 4;
    // 00a955ae  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a955af  be2c13aa00             -mov esi, 0xaa132c
    cpu.esi = 11146028 /*0xaa132c*/;
    // 00a955b4  bb08020000             -mov ebx, 0x208
    cpu.ebx = 520 /*0x208*/;
    // 00a955b9  2eff15e8cda900         -call dword ptr cs:[0xa9cde8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11128296) /* 0xa9cde8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a955c0  ba3014aa00             -mov edx, 0xaa1430
    cpu.edx = 11146288 /*0xaa1430*/;
    // 00a955c5  893534e3a900           -mov dword ptr [0xa9e334], esi
    app->getMemory<x86::reg32>(x86::reg32(11133748) /* 0xa9e334 */) = cpu.esi;
    // 00a955cb  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a955cd  bf3014aa00             -mov edi, 0xaa1430
    cpu.edi = 11146288 /*0xaa1430*/;
    // 00a955d2  e879270000             -call 0xa97d50
    cpu.esp -= 4;
    sub_a97d50(app, cpu);
    if (cpu.terminate) return;
    // 00a955d7  893d40e3a900           -mov dword ptr [0xa9e340], edi
    app->getMemory<x86::reg32>(x86::reg32(11133760) /* 0xa9e340 */) = cpu.edi;
L_0x00a955dd:
    // 00a955dd  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x00a955e2:
    // 00a955e2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a955e3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a955e4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a955e5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void sub_a955e8(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a955e8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a955e9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a955ea  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a955eb  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a955ec  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a955ee  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00a955f0  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a955f2  2eff15f0cda900         -call dword ptr cs:[0xa9cdf0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11128304) /* 0xa9cdf0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a955f9  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a955fb  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00a955fd  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a955ff  e8b4fdffff             -call 0xa953b8
    cpu.esp -= 4;
    sub_a953b8(app, cpu);
    if (cpu.terminate) return;
    // 00a95604  ba4ce3a900             -mov edx, 0xa9e34c
    cpu.edx = 11133772 /*0xa9e34c*/;
    // 00a95609  ff1594e2a900           -call dword ptr [0xa9e294]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11133588) /* 0xa9e294 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a9560f  e85c280000             -call 0xa97e70
    cpu.esp -= 4;
    sub_a97e70(app, cpu);
    if (cpu.terminate) return;
    // 00a95614  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a95616  e8052d0000             -call 0xa98320
    cpu.esp -= 4;
    sub_a98320(app, cpu);
    if (cpu.terminate) return;
    // 00a9561b  b821000000             -mov eax, 0x21
    cpu.eax = 33 /*0x21*/;
    // 00a95620  e8a7000000             -call 0xa956cc
    cpu.esp -= 4;
    sub_a956cc(app, cpu);
    if (cpu.terminate) return;
    // 00a95625  ff15d4e2a900           -call dword ptr [0xa9e2d4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11133652) /* 0xa9e2d4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a9562b  b8ff000000             -mov eax, 0xff
    cpu.eax = 255 /*0xff*/;
    // 00a95630  e897000000             -call 0xa956cc
    cpu.esp -= 4;
    sub_a956cc(app, cpu);
    if (cpu.terminate) return;
    // 00a95635  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a95636  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a95637  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a95638  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a95639  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void sub_a9563c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9563c  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a9563e  833d1010aa0000         +cmp dword ptr [0xaa1010], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(11145232) /* 0xaa1010 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a95645  7418                   -je 0xa9565f
    if (cpu.flags.zf)
    {
        goto L_0x00a9565f;
    }
    // 00a95647  833ddce2a90000         +cmp dword ptr [0xa9e2dc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(11133660) /* 0xa9e2dc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a9564e  7426                   -je 0xa95676
    if (cpu.flags.zf)
    {
        goto L_0x00a95676;
    }
    // 00a95650  baff000000             -mov edx, 0xff
    cpu.edx = 255 /*0xff*/;
    // 00a95655  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a95657  ff15dce2a900           -call dword ptr [0xa9e2dc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11133660) /* 0xa9e2dc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a9565d  eb17                   -jmp 0xa95676
    goto L_0x00a95676;
L_0x00a9565f:
    // 00a9565f  e8082d0000             -call 0xa9836c
    cpu.esp -= 4;
    sub_a9836c(app, cpu);
    if (cpu.terminate) return;
    // 00a95664  ba0f000000             -mov edx, 0xf
    cpu.edx = 15 /*0xf*/;
    // 00a95669  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a9566b  e8ac000000             -call 0xa9571c
    cpu.esp -= 4;
    sub_a9571c(app, cpu);
    if (cpu.terminate) return;
    // 00a95670  ff15d0e2a900           -call dword ptr [0xa9e2d0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11133648) /* 0xa9e2d0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00a95676:
    // 00a95676  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a95677  2eff15a4cda900         -call dword ptr cs:[0xa9cda4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11128228) /* 0xa9cda4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a9567e  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
    // 00a95680  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a95681  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a95682  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a95683  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a95684  8b151410aa00           -mov edx, dword ptr [0xaa1014]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11145236) /* 0xaa1014 */);
    // 00a9568a  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a9568c  740f                   -je 0xa9569d
    if (cpu.flags.zf)
    {
        goto L_0x00a9569d;
    }
    // 00a9568e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a95690  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a95692  e8d9f6ffff             -call 0xa94d70
    cpu.esp -= 4;
    sub_a94d70(app, cpu);
    if (cpu.terminate) return;
    // 00a95697  891d1410aa00           -mov dword ptr [0xaa1014], ebx
    app->getMemory<x86::reg32>(x86::reg32(11145236) /* 0xaa1014 */) = cpu.ebx;
L_0x00a9569d:
    // 00a9569d  8b0d1810aa00           -mov ecx, dword ptr [0xaa1018]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11145240) /* 0xaa1018 */);
    // 00a956a3  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00a956a5  740f                   -je 0xa956b6
    if (cpu.flags.zf)
    {
        goto L_0x00a956b6;
    }
    // 00a956a7  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a956a9  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00a956ab  e8c0f6ffff             -call 0xa94d70
    cpu.esp -= 4;
    sub_a94d70(app, cpu);
    if (cpu.terminate) return;
    // 00a956b0  89351810aa00           -mov dword ptr [0xaa1018], esi
    app->getMemory<x86::reg32>(x86::reg32(11145240) /* 0xaa1018 */) = cpu.esi;
L_0x00a956b6:
    // 00a956b6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a956b7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a956b8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a956b9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a956ba  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void sub_a956c0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a956c0  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a956c1  833800                 +cmp dword ptr [eax], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a956c4  7404                   -je 0xa956ca
    if (cpu.flags.zf)
    {
        goto L_0x00a956ca;
    }
    // 00a956c6  1e                     -push ds
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.ds;
    cpu.esp -= 4;
    // 00a956c7  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a956c8  ff10                   -call dword ptr [eax]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00a956ca:
    // 00a956ca  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a956cb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a956cc(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a956cc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a956cd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a956ce  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a956cf  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a956d0  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a956d1  be9ef4a900             -mov esi, 0xa9f49e
    cpu.esi = 11138206 /*0xa9f49e*/;
    // 00a956d6  88c6                   -mov dh, al
    cpu.dh = cpu.al;
L_0x00a956d8:
    // 00a956d8  b874f4a900             -mov eax, 0xa9f474
    cpu.eax = 11138164 /*0xa9f474*/;
    // 00a956dd  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00a956df  88f2                   -mov dl, dh
    cpu.dl = cpu.dh;
    // 00a956e1  39c6                   +cmp esi, eax
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a956e3  761a                   -jbe 0xa956ff
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a956ff;
    }
L_0x00a956e5:
    // 00a956e5  803802                 +cmp byte ptr [eax], 2
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(2 /*0x2*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a956e8  740b                   -je 0xa956f5
    if (cpu.flags.zf)
    {
        goto L_0x00a956f5;
    }
    // 00a956ea  8a6801                 -mov ch, byte ptr [eax + 1]
    cpu.ch = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a956ed  38ea                   +cmp dl, ch
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.ch));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a956ef  7204                   -jb 0xa956f5
    if (cpu.flags.cf)
    {
        goto L_0x00a956f5;
    }
    // 00a956f1  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a956f3  88ea                   -mov dl, ch
    cpu.dl = cpu.ch;
L_0x00a956f5:
    // 00a956f5  83c006                 -add eax, 6
    (cpu.eax) += x86::reg32(x86::sreg32(6 /*0x6*/));
    // 00a956f8  3d9ef4a900             +cmp eax, 0xa9f49e
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(11138206 /*0xa9f49e*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a956fd  72e6                   -jb 0xa956e5
    if (cpu.flags.cf)
    {
        goto L_0x00a956e5;
    }
L_0x00a956ff:
    // 00a956ff  81fb9ef4a900           +cmp ebx, 0xa9f49e
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(11138206 /*0xa9f49e*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a95705  740d                   -je 0xa95714
    if (cpu.flags.zf)
    {
        goto L_0x00a95714;
    }
    // 00a95707  8d4302                 -lea eax, [ebx + 2]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(2) /* 0x2 */);
    // 00a9570a  e8b1ffffff             -call 0xa956c0
    cpu.esp -= 4;
    sub_a956c0(app, cpu);
    if (cpu.terminate) return;
    // 00a9570f  c60302                 -mov byte ptr [ebx], 2
    app->getMemory<x86::reg8>(cpu.ebx) = 2 /*0x2*/;
    // 00a95712  ebc4                   -jmp 0xa956d8
    goto L_0x00a956d8;
L_0x00a95714:
    // 00a95714  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a95715  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a95716  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a95717  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a95718  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a95719  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void sub_a9571c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9571c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a9571d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a9571e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a9571f  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a95720  be74f4a900             -mov esi, 0xa9f474
    cpu.esi = 11138164 /*0xa9f474*/;
    // 00a95725  88c1                   -mov cl, al
    cpu.cl = cpu.al;
    // 00a95727  88d6                   -mov dh, dl
    cpu.dh = cpu.dl;
L_0x00a95729:
    // 00a95729  b850f4a900             -mov eax, 0xa9f450
    cpu.eax = 11138128 /*0xa9f450*/;
    // 00a9572e  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00a95730  88ca                   -mov dl, cl
    cpu.dl = cpu.cl;
    // 00a95732  39c6                   +cmp esi, eax
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a95734  761a                   -jbe 0xa95750
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a95750;
    }
L_0x00a95736:
    // 00a95736  803802                 +cmp byte ptr [eax], 2
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(2 /*0x2*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a95739  740b                   -je 0xa95746
    if (cpu.flags.zf)
    {
        goto L_0x00a95746;
    }
    // 00a9573b  8a6801                 -mov ch, byte ptr [eax + 1]
    cpu.ch = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a9573e  38ea                   +cmp dl, ch
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.ch));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a95740  7704                   -ja 0xa95746
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a95746;
    }
    // 00a95742  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a95744  88ea                   -mov dl, ch
    cpu.dl = cpu.ch;
L_0x00a95746:
    // 00a95746  83c006                 -add eax, 6
    (cpu.eax) += x86::reg32(x86::sreg32(6 /*0x6*/));
    // 00a95749  3d74f4a900             +cmp eax, 0xa9f474
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(11138164 /*0xa9f474*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a9574e  72e6                   -jb 0xa95736
    if (cpu.flags.cf)
    {
        goto L_0x00a95736;
    }
L_0x00a95750:
    // 00a95750  81fb74f4a900           +cmp ebx, 0xa9f474
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(11138164 /*0xa9f474*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a95756  7412                   -je 0xa9576a
    if (cpu.flags.zf)
    {
        goto L_0x00a9576a;
    }
    // 00a95758  3a7301                 +cmp dh, byte ptr [ebx + 1]
    {
        x86::reg8 tmp1 = cpu.dh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(1) /* 0x1 */)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a9575b  7208                   -jb 0xa95765
    if (cpu.flags.cf)
    {
        goto L_0x00a95765;
    }
    // 00a9575d  8d4302                 -lea eax, [ebx + 2]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(2) /* 0x2 */);
    // 00a95760  e85bffffff             -call 0xa956c0
    cpu.esp -= 4;
    sub_a956c0(app, cpu);
    if (cpu.terminate) return;
L_0x00a95765:
    // 00a95765  c60302                 -mov byte ptr [ebx], 2
    app->getMemory<x86::reg8>(cpu.ebx) = 2 /*0x2*/;
    // 00a95768  ebbf                   -jmp 0xa95729
    goto L_0x00a95729;
L_0x00a9576a:
    // 00a9576a  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a9576b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9576c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9576d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9576e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void sub_a95770(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a95770  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a95771  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a95772  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a95773  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a95774  83ec70                 -sub esp, 0x70
    (cpu.esp) -= x86::reg32(x86::sreg32(112 /*0x70*/));
    // 00a95777  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 00a95779  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 00a9577b  30db                   -xor bl, bl
    cpu.bl ^= x86::reg8(x86::sreg8(cpu.bl));
    // 00a9577d  b964000000             -mov ecx, 0x64
    cpu.ecx = 100 /*0x64*/;
    // 00a95782  885c246c               -mov byte ptr [esp + 0x6c], bl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(108) /* 0x6c */) = cpu.bl;
    // 00a95786  30ff                   -xor bh, bh
    cpu.bh ^= x86::reg8(x86::sreg8(cpu.bh));
    // 00a95788  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00a9578b  66895c241e             -mov word ptr [esp + 0x1e], bx
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(30) /* 0x1e */) = cpu.bx;
    // 00a95790  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a95792  66894c241c             -mov word ptr [esp + 0x1c], cx
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.cx;
    // 00a95797  895c2410               -mov dword ptr [esp + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 00a9579b  8a3a                   -mov bh, byte ptr [edx]
    cpu.bh = app->getMemory<x86::reg8>(cpu.edx);
    // 00a9579d  89542468               -mov dword ptr [esp + 0x68], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */) = cpu.edx;
    // 00a957a1  84ff                   +test bh, bh
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & cpu.bh));
    // 00a957a3  0f8461030000           -je 0xa95b0a
    if (cpu.flags.zf)
    {
        goto L_0x00a95b0a;
    }
L_0x00a957a9:
    // 00a957a9  8b442468               -mov eax, dword ptr [esp + 0x68]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 00a957ad  8b6c2468               -mov ebp, dword ptr [esp + 0x68]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 00a957b1  8a28                   -mov ch, byte ptr [eax]
    cpu.ch = app->getMemory<x86::reg8>(cpu.eax);
    // 00a957b3  45                     -inc ebp
    (cpu.ebp)++;
    // 00a957b4  80fd25                 +cmp ch, 0x25
    {
        x86::reg8 tmp1 = cpu.ch;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(37 /*0x25*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a957b7  7411                   -je 0xa957ca
    if (cpu.flags.zf)
    {
        goto L_0x00a957ca;
    }
    // 00a957b9  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00a957bb  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a957bd  88ea                   -mov dl, ch
    cpu.dl = cpu.ch;
    // 00a957bf  896c2468               -mov dword ptr [esp + 0x68], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */) = cpu.ebp;
    // 00a957c3  ffd7                   -call edi
    cpu.ip = cpu.edi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a957c5  e918030000             -jmp 0xa95ae2
    goto L_0x00a95ae2;
L_0x00a957ca:
    // 00a957ca  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 00a957cc  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00a957ce  8d542460               -lea edx, [esp + 0x60]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 00a957d2  89442460               -mov dword ptr [esp + 0x60], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */) = cpu.eax;
    // 00a957d6  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00a957d8  e83b030000             -call 0xa95b18
    cpu.esp -= 4;
    sub_a95b18(app, cpu);
    if (cpu.terminate) return;
    // 00a957dd  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00a957df  8b442460               -mov eax, dword ptr [esp + 0x60]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 00a957e3  45                     -inc ebp
    (cpu.ebp)++;
    // 00a957e4  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 00a957e6  8a45ff                 -mov al, byte ptr [ebp - 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-1) /* -0x1 */);
    // 00a957e9  896c2468               -mov dword ptr [esp + 0x68], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */) = cpu.ebp;
    // 00a957ed  88442415               -mov byte ptr [esp + 0x15], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(21) /* 0x15 */) = cpu.al;
    // 00a957f1  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 00a957f3  0f8411030000           -je 0xa95b0a
    if (cpu.flags.zf)
    {
        goto L_0x00a95b0a;
    }
    // 00a957f9  3c6e                   +cmp al, 0x6e
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(110 /*0x6e*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a957fb  0f8570010000           -jne 0xa95971
    if (!cpu.flags.zf)
    {
        goto L_0x00a95971;
    }
    // 00a95801  8a5c241e               -mov bl, byte ptr [esp + 0x1e]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(30) /* 0x1e */);
    // 00a95805  f6c320                 +test bl, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 32 /*0x20*/));
    // 00a95808  744f                   -je 0xa95859
    if (cpu.flags.zf)
    {
        goto L_0x00a95859;
    }
    // 00a9580a  f6c380                 +test bl, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 128 /*0x80*/));
    // 00a9580d  741f                   -je 0xa9582e
    if (cpu.flags.zf)
    {
        goto L_0x00a9582e;
    }
    // 00a9580f  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 00a95811  83c208                 -add edx, 8
    (cpu.edx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00a95814  8916                   -mov dword ptr [esi], edx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edx;
    // 00a95816  c452f8                 -les edx, ptr [edx - 8]
    NFS2_ASSERT(false);
    // 00a95819  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00a9581d  268902                 -mov dword ptr es:[edx], eax
    app->getMemory<x86::reg32>(cpu.ees + cpu.edx) = cpu.eax;
    // 00a95820  8b442468               -mov eax, dword ptr [esp + 0x68]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 00a95824  803800                 +cmp byte ptr [eax], 0
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
    // 00a95827  7580                   -jne 0xa957a9
    if (!cpu.flags.zf)
    {
        goto L_0x00a957a9;
    }
    // 00a95829  e9dc020000             -jmp 0xa95b0a
    goto L_0x00a95b0a;
L_0x00a9582e:
    // 00a9582e  f6c340                 +test bl, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 64 /*0x40*/));
    // 00a95831  0f84e8000000           -je 0xa9591f
    if (cpu.flags.zf)
    {
        goto L_0x00a9591f;
    }
    // 00a95837  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00a95839  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a9583c  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 00a9583e  8b50fc                 -mov edx, dword ptr [eax - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */);
    // 00a95841  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00a95845  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 00a95847  8b442468               -mov eax, dword ptr [esp + 0x68]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 00a9584b  803800                 +cmp byte ptr [eax], 0
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
    // 00a9584e  0f8555ffffff           -jne 0xa957a9
    if (!cpu.flags.zf)
    {
        goto L_0x00a957a9;
    }
    // 00a95854  e9b1020000             -jmp 0xa95b0a
    goto L_0x00a95b0a;
L_0x00a95859:
    // 00a95859  f6c310                 +test bl, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 16 /*0x10*/));
    // 00a9585c  0f8489000000           -je 0xa958eb
    if (cpu.flags.zf)
    {
        goto L_0x00a958eb;
    }
    // 00a95862  f6c380                 +test bl, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 128 /*0x80*/));
    // 00a95865  742b                   -je 0xa95892
    if (cpu.flags.zf)
    {
        goto L_0x00a95892;
    }
    // 00a95867  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 00a95869  83c108                 -add ecx, 8
    (cpu.ecx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00a9586c  890e                   -mov dword ptr [esi], ecx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.ecx;
    // 00a9586e  c451f8                 -les edx, ptr [ecx - 8]
    NFS2_ASSERT(false);
    // 00a95871  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00a95875  66268902               -mov word ptr es:[edx], ax
    app->getMemory<x86::reg16>(cpu.ees + cpu.edx) = cpu.ax;
    // 00a95879  8b442468               -mov eax, dword ptr [esp + 0x68]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 00a9587d  803800                 +cmp byte ptr [eax], 0
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
    // 00a95880  0f8523ffffff           -jne 0xa957a9
    if (!cpu.flags.zf)
    {
        goto L_0x00a957a9;
    }
    // 00a95886  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00a9588a  83c470                 -add esp, 0x70
    (cpu.esp) += x86::reg32(x86::sreg32(112 /*0x70*/));
    // 00a9588d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9588e  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a9588f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a95890  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a95891  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a95892:
    // 00a95892  f6c340                 +test bl, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 64 /*0x40*/));
    // 00a95895  742a                   -je 0xa958c1
    if (cpu.flags.zf)
    {
        goto L_0x00a958c1;
    }
    // 00a95897  8b1e                   -mov ebx, dword ptr [esi]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi);
    // 00a95899  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a9589c  891e                   -mov dword ptr [esi], ebx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.ebx;
    // 00a9589e  8b53fc                 -mov edx, dword ptr [ebx - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-4) /* -0x4 */);
    // 00a958a1  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00a958a5  668902                 -mov word ptr [edx], ax
    app->getMemory<x86::reg16>(cpu.edx) = cpu.ax;
    // 00a958a8  8b442468               -mov eax, dword ptr [esp + 0x68]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 00a958ac  803800                 +cmp byte ptr [eax], 0
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
    // 00a958af  0f85f4feffff           -jne 0xa957a9
    if (!cpu.flags.zf)
    {
        goto L_0x00a957a9;
    }
    // 00a958b5  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00a958b9  83c470                 -add esp, 0x70
    (cpu.esp) += x86::reg32(x86::sreg32(112 /*0x70*/));
    // 00a958bc  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a958bd  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a958be  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a958bf  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a958c0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a958c1:
    // 00a958c1  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 00a958c3  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a958c6  8916                   -mov dword ptr [esi], edx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edx;
    // 00a958c8  8b52fc                 -mov edx, dword ptr [edx - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */);
    // 00a958cb  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00a958cf  668902                 -mov word ptr [edx], ax
    app->getMemory<x86::reg16>(cpu.edx) = cpu.ax;
    // 00a958d2  8b442468               -mov eax, dword ptr [esp + 0x68]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 00a958d6  803800                 +cmp byte ptr [eax], 0
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
    // 00a958d9  0f85cafeffff           -jne 0xa957a9
    if (!cpu.flags.zf)
    {
        goto L_0x00a957a9;
    }
    // 00a958df  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00a958e3  83c470                 -add esp, 0x70
    (cpu.esp) += x86::reg32(x86::sreg32(112 /*0x70*/));
    // 00a958e6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a958e7  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a958e8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a958e9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a958ea  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a958eb:
    // 00a958eb  f6c380                 +test bl, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 128 /*0x80*/));
    // 00a958ee  742a                   -je 0xa9591a
    if (cpu.flags.zf)
    {
        goto L_0x00a9591a;
    }
    // 00a958f0  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00a958f2  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00a958f5  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 00a958f7  c450f8                 -les edx, ptr [eax - 8]
    NFS2_ASSERT(false);
    // 00a958fa  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00a958fe  268902                 -mov dword ptr es:[edx], eax
    app->getMemory<x86::reg32>(cpu.ees + cpu.edx) = cpu.eax;
    // 00a95901  8b442468               -mov eax, dword ptr [esp + 0x68]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 00a95905  803800                 +cmp byte ptr [eax], 0
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
    // 00a95908  0f859bfeffff           -jne 0xa957a9
    if (!cpu.flags.zf)
    {
        goto L_0x00a957a9;
    }
    // 00a9590e  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00a95912  83c470                 -add esp, 0x70
    (cpu.esp) += x86::reg32(x86::sreg32(112 /*0x70*/));
    // 00a95915  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a95916  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a95917  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a95918  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a95919  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a9591a:
    // 00a9591a  f6c340                 +test bl, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 64 /*0x40*/));
    // 00a9591d  7429                   -je 0xa95948
    if (cpu.flags.zf)
    {
        goto L_0x00a95948;
    }
L_0x00a9591f:
    // 00a9591f  8b2e                   -mov ebp, dword ptr [esi]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi);
    // 00a95921  83c504                 -add ebp, 4
    (cpu.ebp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a95924  892e                   -mov dword ptr [esi], ebp
    app->getMemory<x86::reg32>(cpu.esi) = cpu.ebp;
    // 00a95926  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00a95929  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00a9592d  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 00a9592f  8b442468               -mov eax, dword ptr [esp + 0x68]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 00a95933  803800                 +cmp byte ptr [eax], 0
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
    // 00a95936  0f856dfeffff           -jne 0xa957a9
    if (!cpu.flags.zf)
    {
        goto L_0x00a957a9;
    }
    // 00a9593c  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00a95940  83c470                 -add esp, 0x70
    (cpu.esp) += x86::reg32(x86::sreg32(112 /*0x70*/));
    // 00a95943  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a95944  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a95945  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a95946  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a95947  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a95948:
    // 00a95948  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 00a9594a  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a9594d  890e                   -mov dword ptr [esi], ecx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.ecx;
    // 00a9594f  8b51fc                 -mov edx, dword ptr [ecx - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-4) /* -0x4 */);
    // 00a95952  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00a95956  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 00a95958  8b442468               -mov eax, dword ptr [esp + 0x68]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 00a9595c  803800                 +cmp byte ptr [eax], 0
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
    // 00a9595f  0f8544feffff           -jne 0xa957a9
    if (!cpu.flags.zf)
    {
        goto L_0x00a957a9;
    }
    // 00a95965  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00a95969  83c470                 -add esp, 0x70
    (cpu.esp) += x86::reg32(x86::sreg32(112 /*0x70*/));
    // 00a9596c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9596d  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a9596e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9596f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a95970  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a95971:
    // 00a95971  8d4c246c               -lea ecx, [esp + 0x6c]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(108) /* 0x6c */);
    // 00a95975  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 00a95977  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00a95979  8d542464               -lea edx, [esp + 0x64]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(100) /* 0x64 */);
    // 00a9597d  89442464               -mov dword ptr [esp + 0x64], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */) = cpu.eax;
    // 00a95981  8d442438               -lea eax, [esp + 0x38]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 00a95985  e8ea050000             -call 0xa95f74
    cpu.esp -= 4;
    sub_a95f74(app, cpu);
    if (cpu.terminate) return;
    // 00a9598a  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00a9598c  8b442464               -mov eax, dword ptr [esp + 0x64]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */);
    // 00a95990  8ec2                   -mov es, edx
    cpu.es = cpu.edx;
    // 00a95992  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 00a95994  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00a95998  8b4c2424               -mov ecx, dword ptr [esp + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00a9599c  8b542428               -mov edx, dword ptr [esp + 0x28]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00a959a0  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00a959a2  8b5c242c               -mov ebx, dword ptr [esp + 0x2c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00a959a6  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00a959a8  8b4c2430               -mov ecx, dword ptr [esp + 0x30]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 00a959ac  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00a959ae  8b542434               -mov edx, dword ptr [esp + 0x34]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00a959b2  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00a959b4  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a959b8  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00a959ba  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00a959bc  8a54241e               -mov dl, byte ptr [esp + 0x1e]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(30) /* 0x1e */);
    // 00a959c0  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 00a959c4  f6c208                 +test dl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 8 /*0x8*/));
    // 00a959c7  751d                   -jne 0xa959e6
    if (!cpu.flags.zf)
    {
        goto L_0x00a959e6;
    }
    // 00a959c9  807c241620             +cmp byte ptr [esp + 0x16], 0x20
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(22) /* 0x16 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(32 /*0x20*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a959ce  7516                   -jne 0xa959e6
    if (!cpu.flags.zf)
    {
        goto L_0x00a959e6;
    }
L_0x00a959d0:
    // 00a959d0  837c240400             +cmp dword ptr [esp + 4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a959d5  7e0f                   -jle 0xa959e6
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a959e6;
    }
    // 00a959d7  ba20000000             -mov edx, 0x20
    cpu.edx = 32 /*0x20*/;
    // 00a959dc  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a959de  ffd7                   -call edi
    cpu.ip = cpu.edi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a959e0  ff4c2404               +dec dword ptr [esp + 4]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a959e4  ebea                   -jmp 0xa959d0
    goto L_0x00a959d0;
L_0x00a959e6:
    // 00a959e6  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00a959ea  8d5c2438               -lea ebx, [esp + 0x38]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 00a959ee  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a959f0  7e16                   -jle 0xa95a08
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a95a08;
    }
L_0x00a959f2:
    // 00a959f2  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a959f4  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a959f6  8a13                   -mov dl, byte ptr [ebx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebx);
    // 00a959f8  ffd7                   -call edi
    cpu.ip = cpu.edi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a959fa  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00a959fe  4a                     -dec edx
    (cpu.edx)--;
    // 00a959ff  43                     -inc ebx
    (cpu.ebx)++;
    // 00a95a00  89542420               -mov dword ptr [esp + 0x20], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 00a95a04  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a95a06  7fea                   -jg 0xa959f2
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00a959f2;
    }
L_0x00a95a08:
    // 00a95a08  837c242400             +cmp dword ptr [esp + 0x24], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a95a0d  7e0f                   -jle 0xa95a1e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a95a1e;
    }
    // 00a95a0f  ba30000000             -mov edx, 0x30
    cpu.edx = 48 /*0x30*/;
    // 00a95a14  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a95a16  ffd7                   -call edi
    cpu.ip = cpu.edi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a95a18  ff4c2424               +dec dword ptr [esp + 0x24]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a95a1c  ebea                   -jmp 0xa95a08
    goto L_0x00a95a08;
L_0x00a95a1e:
    // 00a95a1e  8a5c2415               -mov bl, byte ptr [esp + 0x15]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(21) /* 0x15 */);
    // 00a95a22  80fb73                 +cmp bl, 0x73
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(115 /*0x73*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a95a25  7533                   -jne 0xa95a5a
    if (!cpu.flags.zf)
    {
        goto L_0x00a95a5a;
    }
    // 00a95a27  f644241e20             +test byte ptr [esp + 0x1e], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(30) /* 0x1e */) & 32 /*0x20*/));
    // 00a95a2c  740f                   -je 0xa95a3d
    if (cpu.flags.zf)
    {
        goto L_0x00a95a3d;
    }
    // 00a95a2e  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 00a95a30  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 00a95a32  8cc2                   -mov edx, es
    cpu.edx = cpu.es;
    // 00a95a34  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00a95a36  e8d5040000             -call 0xa95f10
    cpu.esp -= 4;
    sub_a95f10(app, cpu);
    if (cpu.terminate) return;
    // 00a95a3b  eb4e                   -jmp 0xa95a8b
    goto L_0x00a95a8b;
L_0x00a95a3d:
    // 00a95a3d  837c242800             +cmp dword ptr [esp + 0x28], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a95a42  7e47                   -jle 0xa95a8b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a95a8b;
    }
    // 00a95a44  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00a95a46  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a95a48  268a5500               -mov dl, byte ptr es:[ebp]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ees + cpu.ebp);
    // 00a95a4c  ffd7                   -call edi
    cpu.ip = cpu.edi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a95a4e  8b542428               -mov edx, dword ptr [esp + 0x28]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00a95a52  4a                     +dec edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a95a53  45                     +inc ebp
    {
        x86::reg32& tmp = cpu.ebp;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a95a54  89542428               -mov dword ptr [esp + 0x28], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.edx;
    // 00a95a58  ebe3                   -jmp 0xa95a3d
    goto L_0x00a95a3d;
L_0x00a95a5a:
    // 00a95a5a  80fb53                 +cmp bl, 0x53
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(83 /*0x53*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a95a5d  750f                   -jne 0xa95a6e
    if (!cpu.flags.zf)
    {
        goto L_0x00a95a6e;
    }
    // 00a95a5f  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 00a95a61  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 00a95a63  8cc2                   -mov edx, es
    cpu.edx = cpu.es;
    // 00a95a65  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00a95a67  e8a4040000             -call 0xa95f10
    cpu.esp -= 4;
    sub_a95f10(app, cpu);
    if (cpu.terminate) return;
    // 00a95a6c  eb1d                   -jmp 0xa95a8b
    goto L_0x00a95a8b;
L_0x00a95a6e:
    // 00a95a6e  837c242800             +cmp dword ptr [esp + 0x28], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a95a73  7e16                   -jle 0xa95a8b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a95a8b;
    }
    // 00a95a75  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00a95a77  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a95a79  268a5500               -mov dl, byte ptr es:[ebp]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ees + cpu.ebp);
    // 00a95a7d  ffd7                   -call edi
    cpu.ip = cpu.edi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a95a7f  8b4c2428               -mov ecx, dword ptr [esp + 0x28]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00a95a83  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a95a84  45                     +inc ebp
    {
        x86::reg32& tmp = cpu.ebp;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a95a85  894c2428               -mov dword ptr [esp + 0x28], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.ecx;
    // 00a95a89  ebe3                   -jmp 0xa95a6e
    goto L_0x00a95a6e;
L_0x00a95a8b:
    // 00a95a8b  837c242c00             +cmp dword ptr [esp + 0x2c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a95a90  7e0f                   -jle 0xa95aa1
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a95aa1;
    }
    // 00a95a92  ba30000000             -mov edx, 0x30
    cpu.edx = 48 /*0x30*/;
    // 00a95a97  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a95a99  ffd7                   -call edi
    cpu.ip = cpu.edi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a95a9b  ff4c242c               +dec dword ptr [esp + 0x2c]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a95a9f  ebea                   -jmp 0xa95a8b
    goto L_0x00a95a8b;
L_0x00a95aa1:
    // 00a95aa1  837c243000             +cmp dword ptr [esp + 0x30], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a95aa6  7e16                   -jle 0xa95abe
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a95abe;
    }
    // 00a95aa8  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00a95aaa  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a95aac  268a5500               -mov dl, byte ptr es:[ebp]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ees + cpu.ebp);
    // 00a95ab0  ffd7                   -call edi
    cpu.ip = cpu.edi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a95ab2  8b542430               -mov edx, dword ptr [esp + 0x30]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 00a95ab6  4a                     +dec edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a95ab7  45                     +inc ebp
    {
        x86::reg32& tmp = cpu.ebp;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a95ab8  89542430               -mov dword ptr [esp + 0x30], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.edx;
    // 00a95abc  ebe3                   -jmp 0xa95aa1
    goto L_0x00a95aa1;
L_0x00a95abe:
    // 00a95abe  837c243400             +cmp dword ptr [esp + 0x34], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a95ac3  7e0f                   -jle 0xa95ad4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a95ad4;
    }
    // 00a95ac5  ba30000000             -mov edx, 0x30
    cpu.edx = 48 /*0x30*/;
    // 00a95aca  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a95acc  ffd7                   -call edi
    cpu.ip = cpu.edi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a95ace  ff4c2434               +dec dword ptr [esp + 0x34]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a95ad2  ebea                   -jmp 0xa95abe
    goto L_0x00a95abe;
L_0x00a95ad4:
    // 00a95ad4  f644241e08             +test byte ptr [esp + 0x1e], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(30) /* 0x1e */) & 8 /*0x8*/));
    // 00a95ad9  7407                   -je 0xa95ae2
    if (cpu.flags.zf)
    {
        goto L_0x00a95ae2;
    }
L_0x00a95adb:
    // 00a95adb  837c240400             +cmp dword ptr [esp + 4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a95ae0  7f19                   -jg 0xa95afb
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00a95afb;
    }
L_0x00a95ae2:
    // 00a95ae2  8b442468               -mov eax, dword ptr [esp + 0x68]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 00a95ae6  803800                 +cmp byte ptr [eax], 0
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
    // 00a95ae9  0f85bafcffff           -jne 0xa957a9
    if (!cpu.flags.zf)
    {
        goto L_0x00a957a9;
    }
    // 00a95aef  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00a95af3  83c470                 +add esp, 0x70
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(112 /*0x70*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a95af6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a95af7  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a95af8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a95af9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a95afa  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a95afb:
    // 00a95afb  ba20000000             -mov edx, 0x20
    cpu.edx = 32 /*0x20*/;
    // 00a95b00  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a95b02  ffd7                   -call edi
    cpu.ip = cpu.edi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a95b04  ff4c2404               +dec dword ptr [esp + 4]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a95b08  ebd1                   -jmp 0xa95adb
    goto L_0x00a95adb;
L_0x00a95b0a:
    // 00a95b0a  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00a95b0e  83c470                 -add esp, 0x70
    (cpu.esp) += x86::reg32(x86::sreg32(112 /*0x70*/));
    // 00a95b11  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a95b12  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a95b13  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a95b14  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a95b15  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void sub_a95b18(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a95b18  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a95b19  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a95b1a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a95b1b  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00a95b1d  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00a95b1f  c6431620               -mov byte ptr [ebx + 0x16], 0x20
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(22) /* 0x16 */) = 32 /*0x20*/;
    // 00a95b23  e844010000             -call 0xa95c6c
    cpu.esp -= 4;
    sub_a95c6c(app, cpu);
    if (cpu.terminate) return;
    // 00a95b28  c7430400000000         -mov dword ptr [ebx + 4], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 00a95b2f  80382a                 +cmp byte ptr [eax], 0x2a
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(42 /*0x2a*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a95b32  7524                   -jne 0xa95b58
    if (!cpu.flags.zf)
    {
        goto L_0x00a95b58;
    }
    // 00a95b34  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 00a95b36  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a95b39  8916                   -mov dword ptr [esi], edx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edx;
    // 00a95b3b  8b52fc                 -mov edx, dword ptr [edx - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */);
    // 00a95b3e  895304                 -mov dword ptr [ebx + 4], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00a95b41  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a95b43  7d10                   -jge 0xa95b55
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a95b55;
    }
    // 00a95b45  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00a95b47  8a6b1e                 -mov ch, byte ptr [ebx + 0x1e]
    cpu.ch = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(30) /* 0x1e */);
    // 00a95b4a  f7df                   -neg edi
    cpu.edi = ~cpu.edi + 1;
    // 00a95b4c  80cd08                 +or ch, 8
    cpu.clear_co();
    cpu.set_szp((cpu.ch |= x86::reg8(x86::sreg8(8 /*0x8*/))));
    // 00a95b4f  897b04                 -mov dword ptr [ebx + 4], edi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 00a95b52  886b1e                 -mov byte ptr [ebx + 0x1e], ch
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(30) /* 0x1e */) = cpu.ch;
L_0x00a95b55:
    // 00a95b55  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a95b56  eb1f                   -jmp 0xa95b77
    goto L_0x00a95b77;
L_0x00a95b58:
    // 00a95b58  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 00a95b5a  80fa30                 +cmp dl, 0x30
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(48 /*0x30*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a95b5d  7218                   -jb 0xa95b77
    if (cpu.flags.cf)
    {
        goto L_0x00a95b77;
    }
    // 00a95b5f  80fa39                 +cmp dl, 0x39
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(57 /*0x39*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a95b62  7713                   -ja 0xa95b77
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a95b77;
    }
    // 00a95b64  6b4b040a               -imul ecx, dword ptr [ebx + 4], 0xa
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */))) * x86::sreg64(x86::sreg32(10 /*0xa*/)));
    // 00a95b68  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a95b6a  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 00a95b6c  83ea30                 -sub edx, 0x30
    (cpu.edx) -= x86::reg32(x86::sreg32(48 /*0x30*/));
    // 00a95b6f  01d1                   +add ecx, edx
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a95b71  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a95b72  894b04                 -mov dword ptr [ebx + 4], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 00a95b75  ebe1                   -jmp 0xa95b58
    goto L_0x00a95b58;
L_0x00a95b77:
    // 00a95b77  c74308ffffffff         -mov dword ptr [ebx + 8], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = 4294967295 /*0xffffffff*/;
    // 00a95b7e  80382e                 +cmp byte ptr [eax], 0x2e
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(46 /*0x2e*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a95b81  7554                   -jne 0xa95bd7
    if (!cpu.flags.zf)
    {
        goto L_0x00a95bd7;
    }
    // 00a95b83  c7430800000000         -mov dword ptr [ebx + 8], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 00a95b8a  8a6801                 -mov ch, byte ptr [eax + 1]
    cpu.ch = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a95b8d  40                     -inc eax
    (cpu.eax)++;
    // 00a95b8e  80fd2a                 +cmp ch, 0x2a
    {
        x86::reg8 tmp1 = cpu.ch;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(42 /*0x2a*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a95b91  751b                   -jne 0xa95bae
    if (!cpu.flags.zf)
    {
        goto L_0x00a95bae;
    }
    // 00a95b93  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 00a95b95  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a95b98  8916                   -mov dword ptr [esi], edx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edx;
    // 00a95b9a  8b52fc                 -mov edx, dword ptr [edx - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */);
    // 00a95b9d  895308                 -mov dword ptr [ebx + 8], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00a95ba0  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a95ba2  7d07                   -jge 0xa95bab
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a95bab;
    }
    // 00a95ba4  c74308ffffffff         -mov dword ptr [ebx + 8], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = 4294967295 /*0xffffffff*/;
L_0x00a95bab:
    // 00a95bab  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a95bac  eb1f                   -jmp 0xa95bcd
    goto L_0x00a95bcd;
L_0x00a95bae:
    // 00a95bae  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 00a95bb0  80fa30                 +cmp dl, 0x30
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(48 /*0x30*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a95bb3  7218                   -jb 0xa95bcd
    if (cpu.flags.cf)
    {
        goto L_0x00a95bcd;
    }
    // 00a95bb5  80fa39                 +cmp dl, 0x39
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(57 /*0x39*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a95bb8  7713                   -ja 0xa95bcd
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a95bcd;
    }
    // 00a95bba  6b4b080a               -imul ecx, dword ptr [ebx + 8], 0xa
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */))) * x86::sreg64(x86::sreg32(10 /*0xa*/)));
    // 00a95bbe  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a95bc0  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 00a95bc2  83ea30                 -sub edx, 0x30
    (cpu.edx) -= x86::reg32(x86::sreg32(48 /*0x30*/));
    // 00a95bc5  01d1                   +add ecx, edx
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a95bc7  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a95bc8  894b08                 -mov dword ptr [ebx + 8], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 00a95bcb  ebe1                   -jmp 0xa95bae
    goto L_0x00a95bae;
L_0x00a95bcd:
    // 00a95bcd  837b08ff               +cmp dword ptr [ebx + 8], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a95bd1  7404                   -je 0xa95bd7
    if (cpu.flags.zf)
    {
        goto L_0x00a95bd7;
    }
    // 00a95bd3  c6431620               -mov byte ptr [ebx + 0x16], 0x20
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(22) /* 0x16 */) = 32 /*0x20*/;
L_0x00a95bd7:
    // 00a95bd7  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 00a95bd9  8d4801                 -lea ecx, [eax + 1]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a95bdc  80fa4e                 +cmp dl, 0x4e
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(78 /*0x4e*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a95bdf  721f                   -jb 0xa95c00
    if (cpu.flags.cf)
    {
        goto L_0x00a95c00;
    }
    // 00a95be1  0f867b000000           -jbe 0xa95c62
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a95c62;
    }
    // 00a95be7  80fa6c                 +cmp dl, 0x6c
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(108 /*0x6c*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a95bea  720b                   -jb 0xa95bf7
    if (cpu.flags.cf)
    {
        goto L_0x00a95bf7;
    }
    // 00a95bec  762b                   -jbe 0xa95c19
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a95c19;
    }
    // 00a95bee  80fa77                 +cmp dl, 0x77
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(119 /*0x77*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a95bf1  7426                   -je 0xa95c19
    if (cpu.flags.zf)
    {
        goto L_0x00a95c19;
    }
    // 00a95bf3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a95bf4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a95bf5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a95bf6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a95bf7:
    // 00a95bf7  80fa68                 +cmp dl, 0x68
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(104 /*0x68*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a95bfa  742b                   -je 0xa95c27
    if (cpu.flags.zf)
    {
        goto L_0x00a95c27;
    }
    // 00a95bfc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a95bfd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a95bfe  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a95bff  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a95c00:
    // 00a95c00  80fa49                 +cmp dl, 0x49
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(73 /*0x49*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a95c03  720b                   -jb 0xa95c10
    if (cpu.flags.cf)
    {
        goto L_0x00a95c10;
    }
    // 00a95c05  7626                   -jbe 0xa95c2d
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a95c2d;
    }
    // 00a95c07  80fa4c                 +cmp dl, 0x4c
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(76 /*0x4c*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a95c0a  743d                   -je 0xa95c49
    if (cpu.flags.zf)
    {
        goto L_0x00a95c49;
    }
    // 00a95c0c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a95c0d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a95c0e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a95c0f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a95c10:
    // 00a95c10  80fa46                 +cmp dl, 0x46
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(70 /*0x46*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a95c13  7443                   -je 0xa95c58
    if (cpu.flags.zf)
    {
        goto L_0x00a95c58;
    }
    // 00a95c15  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a95c16  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a95c17  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a95c18  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a95c19:
    // 00a95c19  8a4b1e                 -mov cl, byte ptr [ebx + 0x1e]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(30) /* 0x1e */);
    // 00a95c1c  80c920                 -or cl, 0x20
    cpu.cl |= x86::reg8(x86::sreg8(32 /*0x20*/));
    // 00a95c1f  40                     -inc eax
    (cpu.eax)++;
    // 00a95c20  884b1e                 -mov byte ptr [ebx + 0x1e], cl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(30) /* 0x1e */) = cpu.cl;
    // 00a95c23  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a95c24  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a95c25  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a95c26  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a95c27:
    // 00a95c27  804b1e10               +or byte ptr [ebx + 0x1e], 0x10
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(30) /* 0x1e */) |= x86::reg8(x86::sreg8(16 /*0x10*/))));
    // 00a95c2b  eb39                   -jmp 0xa95c66
    goto L_0x00a95c66;
L_0x00a95c2d:
    // 00a95c2d  80780136               +cmp byte ptr [eax + 1], 0x36
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(54 /*0x36*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a95c31  7535                   -jne 0xa95c68
    if (!cpu.flags.zf)
    {
        goto L_0x00a95c68;
    }
    // 00a95c33  80780234               +cmp byte ptr [eax + 2], 0x34
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(52 /*0x34*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a95c37  752f                   -jne 0xa95c68
    if (!cpu.flags.zf)
    {
        goto L_0x00a95c68;
    }
    // 00a95c39  8a6b1f                 -mov ch, byte ptr [ebx + 0x1f]
    cpu.ch = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(31) /* 0x1f */);
    // 00a95c3c  80cd01                 -or ch, 1
    cpu.ch |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00a95c3f  83c003                 -add eax, 3
    (cpu.eax) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 00a95c42  886b1f                 -mov byte ptr [ebx + 0x1f], ch
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(31) /* 0x1f */) = cpu.ch;
    // 00a95c45  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a95c46  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a95c47  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a95c48  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a95c49:
    // 00a95c49  8a531f                 -mov dl, byte ptr [ebx + 0x1f]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(31) /* 0x1f */);
    // 00a95c4c  80ca01                 -or dl, 1
    cpu.dl |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00a95c4f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a95c51  88531f                 -mov byte ptr [ebx + 0x1f], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(31) /* 0x1f */) = cpu.dl;
    // 00a95c54  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a95c55  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a95c56  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a95c57  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a95c58:
    // 00a95c58  804b1e80               -or byte ptr [ebx + 0x1e], 0x80
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(30) /* 0x1e */) |= x86::reg8(x86::sreg8(128 /*0x80*/));
    // 00a95c5c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a95c5e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a95c5f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a95c60  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a95c61  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a95c62:
    // 00a95c62  804b1e40               -or byte ptr [ebx + 0x1e], 0x40
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(30) /* 0x1e */) |= x86::reg8(x86::sreg8(64 /*0x40*/));
L_0x00a95c66:
    // 00a95c66  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
L_0x00a95c68:
    // 00a95c68  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a95c69  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a95c6a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a95c6b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a95c6c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a95c6c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a95c6d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a95c6e  66c7421e0000           -mov word ptr [edx + 0x1e], 0
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(30) /* 0x1e */) = 0 /*0x0*/;
    // 00a95c74  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 00a95c76  80fb2d                 +cmp bl, 0x2d
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(45 /*0x2d*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a95c79  7506                   -jne 0xa95c81
    if (!cpu.flags.zf)
    {
        goto L_0x00a95c81;
    }
    // 00a95c7b  804a1e08               +or byte ptr [edx + 0x1e], 8
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.edx + x86::reg32(30) /* 0x1e */) |= x86::reg8(x86::sreg8(8 /*0x8*/))));
    // 00a95c7f  eb42                   -jmp 0xa95cc3
    goto L_0x00a95cc3;
L_0x00a95c81:
    // 00a95c81  80fb23                 +cmp bl, 0x23
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(35 /*0x23*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a95c84  7506                   -jne 0xa95c8c
    if (!cpu.flags.zf)
    {
        goto L_0x00a95c8c;
    }
    // 00a95c86  804a1e01               +or byte ptr [edx + 0x1e], 1
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.edx + x86::reg32(30) /* 0x1e */) |= x86::reg8(x86::sreg8(1 /*0x1*/))));
    // 00a95c8a  eb37                   -jmp 0xa95cc3
    goto L_0x00a95cc3;
L_0x00a95c8c:
    // 00a95c8c  80fb2b                 +cmp bl, 0x2b
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(43 /*0x2b*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a95c8f  7513                   -jne 0xa95ca4
    if (!cpu.flags.zf)
    {
        goto L_0x00a95ca4;
    }
    // 00a95c91  8a6a1e                 -mov ch, byte ptr [edx + 0x1e]
    cpu.ch = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(30) /* 0x1e */);
    // 00a95c94  80cd04                 -or ch, 4
    cpu.ch |= x86::reg8(x86::sreg8(4 /*0x4*/));
    // 00a95c97  88eb                   -mov bl, ch
    cpu.bl = cpu.ch;
    // 00a95c99  886a1e                 -mov byte ptr [edx + 0x1e], ch
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(30) /* 0x1e */) = cpu.ch;
    // 00a95c9c  80e3fd                 +and bl, 0xfd
    cpu.clear_co();
    cpu.set_szp((cpu.bl &= x86::reg8(x86::sreg8(253 /*0xfd*/))));
    // 00a95c9f  885a1e                 -mov byte ptr [edx + 0x1e], bl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(30) /* 0x1e */) = cpu.bl;
    // 00a95ca2  eb1f                   -jmp 0xa95cc3
    goto L_0x00a95cc3;
L_0x00a95ca4:
    // 00a95ca4  80fb20                 +cmp bl, 0x20
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(32 /*0x20*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a95ca7  7512                   -jne 0xa95cbb
    if (!cpu.flags.zf)
    {
        goto L_0x00a95cbb;
    }
    // 00a95ca9  8a7a1e                 -mov bh, byte ptr [edx + 0x1e]
    cpu.bh = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(30) /* 0x1e */);
    // 00a95cac  f6c704                 +test bh, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 4 /*0x4*/));
    // 00a95caf  7512                   -jne 0xa95cc3
    if (!cpu.flags.zf)
    {
        goto L_0x00a95cc3;
    }
    // 00a95cb1  88f9                   -mov cl, bh
    cpu.cl = cpu.bh;
    // 00a95cb3  80c902                 +or cl, 2
    cpu.clear_co();
    cpu.set_szp((cpu.cl |= x86::reg8(x86::sreg8(2 /*0x2*/))));
    // 00a95cb6  884a1e                 -mov byte ptr [edx + 0x1e], cl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(30) /* 0x1e */) = cpu.cl;
    // 00a95cb9  eb08                   -jmp 0xa95cc3
    goto L_0x00a95cc3;
L_0x00a95cbb:
    // 00a95cbb  80fb30                 +cmp bl, 0x30
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(48 /*0x30*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a95cbe  7511                   -jne 0xa95cd1
    if (!cpu.flags.zf)
    {
        goto L_0x00a95cd1;
    }
    // 00a95cc0  885a16                 -mov byte ptr [edx + 0x16], bl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(22) /* 0x16 */) = cpu.bl;
L_0x00a95cc3:
    // 00a95cc3  40                     -inc eax
    (cpu.eax)++;
    // 00a95cc4  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 00a95cc6  80fb2d                 +cmp bl, 0x2d
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(45 /*0x2d*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a95cc9  75b6                   -jne 0xa95c81
    if (!cpu.flags.zf)
    {
        goto L_0x00a95c81;
    }
    // 00a95ccb  804a1e08               +or byte ptr [edx + 0x1e], 8
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.edx + x86::reg32(30) /* 0x1e */) |= x86::reg8(x86::sreg8(8 /*0x8*/))));
    // 00a95ccf  ebf2                   -jmp 0xa95cc3
    goto L_0x00a95cc3;
L_0x00a95cd1:
    // 00a95cd1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a95cd2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a95cd3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a95cd4(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a95cd4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a95cd5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a95cd6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a95cd7  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a95cd8  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00a95cda  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00a95cdc  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a95cde  8ec1                   -mov es, ecx
    cpu.es = cpu.ecx;
    // 00a95ce0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00a95ce2:
    // 00a95ce2  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00a95ce4  268a1e                 -mov bl, byte ptr es:[esi]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ees + cpu.esi);
    // 00a95ce7  42                     -inc edx
    (cpu.edx)++;
    // 00a95ce8  84db                   +test bl, bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.bl));
    // 00a95cea  7407                   -je 0xa95cf3
    if (cpu.flags.zf)
    {
        goto L_0x00a95cf3;
    }
    // 00a95cec  39f8                   +cmp eax, edi
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
    // 00a95cee  7403                   -je 0xa95cf3
    if (cpu.flags.zf)
    {
        goto L_0x00a95cf3;
    }
    // 00a95cf0  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a95cf1  ebef                   -jmp 0xa95ce2
    goto L_0x00a95ce2;
L_0x00a95cf3:
    // 00a95cf3  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a95cf4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a95cf5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a95cf6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a95cf7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a95cf8(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a95cf8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a95cf9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a95cfa  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a95cfb  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a95cfe  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 00a95d00  8ec2                   -mov es, edx
    cpu.es = cpu.edx;
    // 00a95d02  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a95d04  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a95d06  83feff                 +cmp esi, -1
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a95d09  7521                   -jne 0xa95d2c
    if (!cpu.flags.zf)
    {
        goto L_0x00a95d2c;
    }
L_0x00a95d0b:
    // 00a95d0b  66268b33               -mov si, word ptr es:[ebx]
    cpu.si = app->getMemory<x86::reg16>(cpu.ees + cpu.ebx);
    // 00a95d0f  6685f6                 +test si, si
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.si & cpu.si));
    // 00a95d12  7440                   -je 0xa95d54
    if (cpu.flags.zf)
    {
        goto L_0x00a95d54;
    }
    // 00a95d14  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a95d16  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a95d18  6689f2                 -mov dx, si
    cpu.dx = cpu.si;
    // 00a95d1b  83c302                 -add ebx, 2
    (cpu.ebx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00a95d1e  e86d260000             -call 0xa98390
    cpu.esp -= 4;
    sub_a98390(app, cpu);
    if (cpu.terminate) return;
    // 00a95d23  83f8ff                 +cmp eax, -1
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
    // 00a95d26  74e3                   -je 0xa95d0b
    if (cpu.flags.zf)
    {
        goto L_0x00a95d0b;
    }
    // 00a95d28  01c1                   +add ecx, eax
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a95d2a  ebdf                   -jmp 0xa95d0b
    goto L_0x00a95d0b;
L_0x00a95d2c:
    // 00a95d2c  6626833b00             +cmp word ptr es:[ebx], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.ees + cpu.ebx);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00a95d31  741d                   -je 0xa95d50
    if (cpu.flags.zf)
    {
        goto L_0x00a95d50;
    }
    // 00a95d33  39f1                   +cmp ecx, esi
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a95d35  7f19                   -jg 0xa95d50
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00a95d50;
    }
    // 00a95d37  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a95d39  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a95d3b  66268b13               -mov dx, word ptr es:[ebx]
    cpu.dx = app->getMemory<x86::reg16>(cpu.ees + cpu.ebx);
    // 00a95d3f  83c302                 -add ebx, 2
    (cpu.ebx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00a95d42  e849260000             -call 0xa98390
    cpu.esp -= 4;
    sub_a98390(app, cpu);
    if (cpu.terminate) return;
    // 00a95d47  83f8ff                 +cmp eax, -1
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
    // 00a95d4a  74e0                   -je 0xa95d2c
    if (cpu.flags.zf)
    {
        goto L_0x00a95d2c;
    }
    // 00a95d4c  01c1                   +add ecx, eax
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a95d4e  ebdc                   -jmp 0xa95d2c
    goto L_0x00a95d2c;
L_0x00a95d50:
    // 00a95d50  39f1                   +cmp ecx, esi
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a95d52  7f04                   -jg 0xa95d58
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00a95d58;
    }
L_0x00a95d54:
    // 00a95d54  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a95d56  eb02                   -jmp 0xa95d5a
    goto L_0x00a95d5a;
L_0x00a95d58:
    // 00a95d58  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x00a95d5a:
    // 00a95d5a  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a95d5d  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a95d5e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a95d5f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a95d60  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_a95d64(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a95d64  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a95d65  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a95d66  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a95d67  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a95d68  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a95d6b  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 00a95d6d  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 00a95d70  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
    // 00a95d75  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 00a95d77  e8a0260000             -call 0xa9841c
    cpu.esp -= 4;
    sub_a9841c(app, cpu);
    if (cpu.terminate) return;
    // 00a95d7c  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a95d7d  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a95d7f  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a95d81  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a95d83  49                     -dec ecx
    (cpu.ecx)--;
    // 00a95d84  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a95d86  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00a95d88  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00a95d8a  49                     -dec ecx
    (cpu.ecx)--;
    // 00a95d8b  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a95d8c  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00a95d8f  48                     -dec eax
    (cpu.eax)--;
    // 00a95d90  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00a95d92  7415                   -je 0xa95da9
    if (cpu.flags.zf)
    {
        goto L_0x00a95da9;
    }
    // 00a95d94  89ee                   -mov esi, ebp
    cpu.esi = cpu.ebp;
    // 00a95d96  8d1c28                 -lea ebx, [eax + ebp]
    cpu.ebx = x86::reg32(cpu.eax + cpu.ebp * 1);
    // 00a95d99  8d1429                 -lea edx, [ecx + ebp]
    cpu.edx = x86::reg32(cpu.ecx + cpu.ebp * 1);
L_0x00a95d9c:
    // 00a95d9c  4b                     -dec ebx
    (cpu.ebx)--;
    // 00a95d9d  8a4aff                 -mov cl, byte ptr [edx - 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 00a95da0  4a                     -dec edx
    (cpu.edx)--;
    // 00a95da1  48                     -dec eax
    (cpu.eax)--;
    // 00a95da2  884b01                 -mov byte ptr [ebx + 1], cl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(1) /* 0x1 */) = cpu.cl;
    // 00a95da5  39f2                   +cmp edx, esi
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a95da7  75f3                   -jne 0xa95d9c
    if (!cpu.flags.zf)
    {
        goto L_0x00a95d9c;
    }
L_0x00a95da9:
    // 00a95da9  8d1428                 -lea edx, [eax + ebp]
    cpu.edx = x86::reg32(cpu.eax + cpu.ebp * 1);
L_0x00a95dac:
    // 00a95dac  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a95dae  7c07                   -jl 0xa95db7
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a95db7;
    }
    // 00a95db0  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a95db1  c60230                 -mov byte ptr [edx], 0x30
    app->getMemory<x86::reg8>(cpu.edx) = 48 /*0x30*/;
    // 00a95db4  4a                     +dec edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a95db5  ebf5                   -jmp 0xa95dac
    goto L_0x00a95dac;
L_0x00a95db7:
    // 00a95db7  032c24                 -add ebp, dword ptr [esp]
    (cpu.ebp) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp)));
    // 00a95dba  c6450000               -mov byte ptr [ebp], 0
    app->getMemory<x86::reg8>(cpu.ebp) = 0 /*0x0*/;
    // 00a95dbe  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a95dc1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a95dc2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a95dc3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a95dc4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a95dc5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a95dbe(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00a95dbe;
    // 00a95d64  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a95d65  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a95d66  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a95d67  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a95d68  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a95d6b  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 00a95d6d  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 00a95d70  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
    // 00a95d75  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 00a95d77  e8a0260000             -call 0xa9841c
    cpu.esp -= 4;
    sub_a9841c(app, cpu);
    if (cpu.terminate) return;
    // 00a95d7c  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a95d7d  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a95d7f  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a95d81  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a95d83  49                     -dec ecx
    (cpu.ecx)--;
    // 00a95d84  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a95d86  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00a95d88  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00a95d8a  49                     -dec ecx
    (cpu.ecx)--;
    // 00a95d8b  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a95d8c  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00a95d8f  48                     -dec eax
    (cpu.eax)--;
    // 00a95d90  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00a95d92  7415                   -je 0xa95da9
    if (cpu.flags.zf)
    {
        goto L_0x00a95da9;
    }
    // 00a95d94  89ee                   -mov esi, ebp
    cpu.esi = cpu.ebp;
    // 00a95d96  8d1c28                 -lea ebx, [eax + ebp]
    cpu.ebx = x86::reg32(cpu.eax + cpu.ebp * 1);
    // 00a95d99  8d1429                 -lea edx, [ecx + ebp]
    cpu.edx = x86::reg32(cpu.ecx + cpu.ebp * 1);
L_0x00a95d9c:
    // 00a95d9c  4b                     -dec ebx
    (cpu.ebx)--;
    // 00a95d9d  8a4aff                 -mov cl, byte ptr [edx - 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 00a95da0  4a                     -dec edx
    (cpu.edx)--;
    // 00a95da1  48                     -dec eax
    (cpu.eax)--;
    // 00a95da2  884b01                 -mov byte ptr [ebx + 1], cl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(1) /* 0x1 */) = cpu.cl;
    // 00a95da5  39f2                   +cmp edx, esi
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a95da7  75f3                   -jne 0xa95d9c
    if (!cpu.flags.zf)
    {
        goto L_0x00a95d9c;
    }
L_0x00a95da9:
    // 00a95da9  8d1428                 -lea edx, [eax + ebp]
    cpu.edx = x86::reg32(cpu.eax + cpu.ebp * 1);
L_0x00a95dac:
    // 00a95dac  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a95dae  7c07                   -jl 0xa95db7
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a95db7;
    }
    // 00a95db0  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a95db1  c60230                 -mov byte ptr [edx], 0x30
    app->getMemory<x86::reg8>(cpu.edx) = 48 /*0x30*/;
    // 00a95db4  4a                     +dec edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a95db5  ebf5                   -jmp 0xa95dac
    goto L_0x00a95dac;
L_0x00a95db7:
    // 00a95db7  032c24                 -add ebp, dword ptr [esp]
    (cpu.ebp) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp)));
    // 00a95dba  c6450000               -mov byte ptr [ebp], 0
    app->getMemory<x86::reg8>(cpu.ebp) = 0 /*0x0*/;
L_entry_0x00a95dbe:
    // 00a95dbe  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a95dc1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a95dc2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a95dc3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a95dc4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a95dc5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void sub_a95dc8(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a95dc8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a95dc9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a95dca  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a95dcb  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a95dcc  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a95dcf  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a95dd1  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 00a95dd3  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 00a95dd6  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a95dd8  7d0b                   -jge 0xa95de5
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a95de5;
    }
    // 00a95dda  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
    // 00a95ddc  8d4801                 -lea ecx, [eax + 1]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a95ddf  c6002d                 -mov byte ptr [eax], 0x2d
    app->getMemory<x86::reg8>(cpu.eax) = 45 /*0x2d*/;
    // 00a95de2  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
L_0x00a95de5:
    // 00a95de5  837e08ff               +cmp dword ptr [esi + 8], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a95de9  7507                   -jne 0xa95df2
    if (!cpu.flags.zf)
    {
        goto L_0x00a95df2;
    }
    // 00a95deb  c7460804000000         -mov dword ptr [esi + 8], 4
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = 4 /*0x4*/;
L_0x00a95df2:
    // 00a95df2  bb0a000000             -mov ebx, 0xa
    cpu.ebx = 10 /*0xa*/;
    // 00a95df7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a95df9  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00a95dfb  668b442402             -mov ax, word ptr [esp + 2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(2) /* 0x2 */);
    // 00a95e00  e817260000             -call 0xa9841c
    cpu.esp -= 4;
    sub_a9841c(app, cpu);
    if (cpu.terminate) return;
    // 00a95e05  8a21                   -mov ah, byte ptr [ecx]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ecx);
    // 00a95e07  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00a95e09  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 00a95e0b  7408                   -je 0xa95e15
    if (cpu.flags.zf)
    {
        goto L_0x00a95e15;
    }
L_0x00a95e0d:
    // 00a95e0d  8a5101                 -mov dl, byte ptr [ecx + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 00a95e10  41                     -inc ecx
    (cpu.ecx)++;
    // 00a95e11  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 00a95e13  75f8                   -jne 0xa95e0d
    if (!cpu.flags.zf)
    {
        goto L_0x00a95e0d;
    }
L_0x00a95e15:
    // 00a95e15  837e0800               +cmp dword ptr [esi + 8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a95e19  7432                   -je 0xa95e4d
    if (cpu.flags.zf)
    {
        goto L_0x00a95e4d;
    }
    // 00a95e1b  c6012e                 -mov byte ptr [ecx], 0x2e
    app->getMemory<x86::reg8>(cpu.ecx) = 46 /*0x2e*/;
    // 00a95e1e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a95e20  8b6e08                 -mov ebp, dword ptr [esi + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00a95e23  41                     -inc ecx
    (cpu.ecx)++;
    // 00a95e24  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00a95e26  7e22                   -jle 0xa95e4a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a95e4a;
    }
L_0x00a95e28:
    // 00a95e28  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a95e2a  6689542402             -mov word ptr [esp + 2], dx
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(2) /* 0x2 */) = cpu.dx;
    // 00a95e2f  8b3c24                 -mov edi, dword ptr [esp]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    // 00a95e32  6bd70a                 -imul edx, edi, 0xa
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edi)) * x86::sreg64(x86::sreg32(10 /*0xa*/)));
    // 00a95e35  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 00a95e38  8a542402               -mov dl, byte ptr [esp + 2]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(2) /* 0x2 */);
    // 00a95e3c  80c230                 -add dl, 0x30
    (cpu.dl) += x86::reg8(x86::sreg8(48 /*0x30*/));
    // 00a95e3f  8811                   -mov byte ptr [ecx], dl
    app->getMemory<x86::reg8>(cpu.ecx) = cpu.dl;
    // 00a95e41  40                     -inc eax
    (cpu.eax)++;
    // 00a95e42  8b6e08                 -mov ebp, dword ptr [esi + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00a95e45  41                     -inc ecx
    (cpu.ecx)++;
    // 00a95e46  39e8                   +cmp eax, ebp
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a95e48  7cde                   -jl 0xa95e28
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a95e28;
    }
L_0x00a95e4a:
    // 00a95e4a  c60100                 -mov byte ptr [ecx], 0
    app->getMemory<x86::reg8>(cpu.ecx) = 0 /*0x0*/;
L_0x00a95e4d:
    // 00a95e4d  f644240180             +test byte ptr [esp + 1], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1) /* 0x1 */) & 128 /*0x80*/));
    // 00a95e52  0f8466ffffff           -je 0xa95dbe
    if (cpu.flags.zf)
    {
        return sub_a95dbe(app, cpu);
    }
L_0x00a95e58:
    // 00a95e58  39d9                   +cmp ecx, ebx
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a95e5a  7541                   -jne 0xa95e9d
    if (!cpu.flags.zf)
    {
        goto L_0x00a95e9d;
    }
    // 00a95e5c  8d4b01                 -lea ecx, [ebx + 1]
    cpu.ecx = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 00a95e5f  c60331                 -mov byte ptr [ebx], 0x31
    app->getMemory<x86::reg8>(cpu.ebx) = 49 /*0x31*/;
    // 00a95e62  803930                 +cmp byte ptr [ecx], 0x30
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(48 /*0x30*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a95e65  7508                   -jne 0xa95e6f
    if (!cpu.flags.zf)
    {
        goto L_0x00a95e6f;
    }
L_0x00a95e67:
    // 00a95e67  8a4101                 -mov al, byte ptr [ecx + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 00a95e6a  41                     -inc ecx
    (cpu.ecx)++;
    // 00a95e6b  3c30                   +cmp al, 0x30
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
    // 00a95e6d  74f8                   -je 0xa95e67
    if (cpu.flags.zf)
    {
        goto L_0x00a95e67;
    }
L_0x00a95e6f:
    // 00a95e6f  8a21                   -mov ah, byte ptr [ecx]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ecx);
    // 00a95e71  80fc2e                 +cmp ah, 0x2e
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(46 /*0x2e*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a95e74  7518                   -jne 0xa95e8e
    if (!cpu.flags.zf)
    {
        goto L_0x00a95e8e;
    }
    // 00a95e76  c60130                 -mov byte ptr [ecx], 0x30
    app->getMemory<x86::reg8>(cpu.ecx) = 48 /*0x30*/;
    // 00a95e79  41                     -inc ecx
    (cpu.ecx)++;
    // 00a95e7a  8821                   -mov byte ptr [ecx], ah
    app->getMemory<x86::reg8>(cpu.ecx) = cpu.ah;
    // 00a95e7c  8a5101                 -mov dl, byte ptr [ecx + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 00a95e7f  41                     -inc ecx
    (cpu.ecx)++;
    // 00a95e80  80fa30                 +cmp dl, 0x30
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(48 /*0x30*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a95e83  7509                   -jne 0xa95e8e
    if (!cpu.flags.zf)
    {
        goto L_0x00a95e8e;
    }
L_0x00a95e85:
    // 00a95e85  8a7101                 -mov dh, byte ptr [ecx + 1]
    cpu.dh = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 00a95e88  41                     -inc ecx
    (cpu.ecx)++;
    // 00a95e89  80fe30                 +cmp dh, 0x30
    {
        x86::reg8 tmp1 = cpu.dh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(48 /*0x30*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a95e8c  74f7                   -je 0xa95e85
    if (cpu.flags.zf)
    {
        goto L_0x00a95e85;
    }
L_0x00a95e8e:
    // 00a95e8e  c60130                 -mov byte ptr [ecx], 0x30
    app->getMemory<x86::reg8>(cpu.ecx) = 48 /*0x30*/;
    // 00a95e91  41                     -inc ecx
    (cpu.ecx)++;
    // 00a95e92  c60100                 -mov byte ptr [ecx], 0
    app->getMemory<x86::reg8>(cpu.ecx) = 0 /*0x0*/;
    // 00a95e95  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a95e98  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a95e99  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a95e9a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a95e9b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a95e9c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a95e9d:
    // 00a95e9d  8a51ff                 -mov dl, byte ptr [ecx - 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(-1) /* -0x1 */);
    // 00a95ea0  49                     -dec ecx
    (cpu.ecx)--;
    // 00a95ea1  80fa2e                 +cmp dl, 0x2e
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(46 /*0x2e*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a95ea4  7501                   -jne 0xa95ea7
    if (!cpu.flags.zf)
    {
        goto L_0x00a95ea7;
    }
    // 00a95ea6  49                     -dec ecx
    (cpu.ecx)--;
L_0x00a95ea7:
    // 00a95ea7  8a31                   -mov dh, byte ptr [ecx]
    cpu.dh = app->getMemory<x86::reg8>(cpu.ecx);
    // 00a95ea9  80fe39                 +cmp dh, 0x39
    {
        x86::reg8 tmp1 = cpu.dh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(57 /*0x39*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a95eac  740e                   -je 0xa95ebc
    if (cpu.flags.zf)
    {
        goto L_0x00a95ebc;
    }
    // 00a95eae  88f3                   -mov bl, dh
    cpu.bl = cpu.dh;
    // 00a95eb0  fec3                   -inc bl
    (cpu.bl)++;
    // 00a95eb2  8819                   -mov byte ptr [ecx], bl
    app->getMemory<x86::reg8>(cpu.ecx) = cpu.bl;
    // 00a95eb4  83c404                 +add esp, 4
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
    // 00a95eb7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a95eb8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a95eb9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a95eba  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a95ebb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a95ebc:
    // 00a95ebc  c60130                 -mov byte ptr [ecx], 0x30
    app->getMemory<x86::reg8>(cpu.ecx) = 48 /*0x30*/;
    // 00a95ebf  eb97                   -jmp 0xa95e58
    goto L_0x00a95e58;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_a95ec4(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a95ec4  ff15e4e3a900           -call dword ptr [0xa9e3e4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11133924) /* 0xa9e3e4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a95eca  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void sub_a95ecc(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a95ecc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a95ecd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a95ece  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a95ecf  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a95ed0  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a95ed1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a95ed2  f6401e08               +test byte ptr [eax + 0x1e], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(30) /* 0x1e */) & 8 /*0x8*/));
    // 00a95ed6  7530                   -jne 0xa95f08
    if (!cpu.flags.zf)
    {
        goto L_0x00a95f08;
    }
    // 00a95ed8  80781630               +cmp byte ptr [eax + 0x16], 0x30
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(22) /* 0x16 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(48 /*0x30*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a95edc  752a                   -jne 0xa95f08
    if (!cpu.flags.zf)
    {
        goto L_0x00a95f08;
    }
    // 00a95ede  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00a95ee1  8b5820                 -mov ebx, dword ptr [eax + 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 00a95ee4  8b4824                 -mov ecx, dword ptr [eax + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 00a95ee7  29da                   -sub edx, ebx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a95ee9  8b7028                 -mov esi, dword ptr [eax + 0x28]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */);
    // 00a95eec  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a95eee  8b782c                 -mov edi, dword ptr [eax + 0x2c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(44) /* 0x2c */);
    // 00a95ef1  29f2                   -sub edx, esi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00a95ef3  8b6830                 -mov ebp, dword ptr [eax + 0x30]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(48) /* 0x30 */);
    // 00a95ef6  29fa                   -sub edx, edi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edi));
    // 00a95ef8  8b5834                 -mov ebx, dword ptr [eax + 0x34]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(52) /* 0x34 */);
    // 00a95efb  29ea                   -sub edx, ebp
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 00a95efd  29da                   -sub edx, ebx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a95eff  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a95f01  7e05                   -jle 0xa95f08
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a95f08;
    }
    // 00a95f03  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00a95f05  894824                 -mov dword ptr [eax + 0x24], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */) = cpu.ecx;
L_0x00a95f08:
    // 00a95f08  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a95f09  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a95f0a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a95f0b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a95f0c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a95f0d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a95f0e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void sub_a95f10(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a95f10  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a95f11  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a95f12  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a95f13  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a95f14  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a95f17  8ec2                   -mov es, edx
    cpu.es = cpu.edx;
    // 00a95f19  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a95f1b  8b5328                 -mov edx, dword ptr [ebx + 0x28]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */);
    // 00a95f1e  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 00a95f20  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a95f22  7e45                   -jle 0xa95f69
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a95f69;
    }
L_0x00a95f24:
    // 00a95f24  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a95f26  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a95f28  66268b17               -mov dx, word ptr es:[edi]
    cpu.dx = app->getMemory<x86::reg16>(cpu.ees + cpu.edi);
    // 00a95f2c  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00a95f2f  e85c240000             -call 0xa98390
    cpu.esp -= 4;
    sub_a98390(app, cpu);
    if (cpu.terminate) return;
    // 00a95f34  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a95f36  83f8ff                 +cmp eax, -1
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
    // 00a95f39  740d                   -je 0xa95f48
    if (cpu.flags.zf)
    {
        goto L_0x00a95f48;
    }
    // 00a95f3b  3b4328                 +cmp eax, dword ptr [ebx + 0x28]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a95f3e  7f22                   -jg 0xa95f62
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00a95f62;
    }
    // 00a95f40  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
L_0x00a95f42:
    // 00a95f42  49                     -dec ecx
    (cpu.ecx)--;
    // 00a95f43  83f9ff                 +cmp ecx, -1
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a95f46  7508                   -jne 0xa95f50
    if (!cpu.flags.zf)
    {
        goto L_0x00a95f50;
    }
L_0x00a95f48:
    // 00a95f48  837b2800               +cmp dword ptr [ebx + 0x28], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a95f4c  7fd6                   -jg 0xa95f24
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00a95f24;
    }
    // 00a95f4e  eb19                   -jmp 0xa95f69
    goto L_0x00a95f69;
L_0x00a95f50:
    // 00a95f50  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00a95f52  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a95f54  8a16                   -mov dl, byte ptr [esi]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi);
    // 00a95f56  ffd5                   -call ebp
    cpu.ip = cpu.ebp;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a95f58  8b4328                 -mov eax, dword ptr [ebx + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */);
    // 00a95f5b  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a95f5c  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a95f5d  894328                 -mov dword ptr [ebx + 0x28], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 00a95f60  ebe0                   -jmp 0xa95f42
    goto L_0x00a95f42;
L_0x00a95f62:
    // 00a95f62  c7432800000000         -mov dword ptr [ebx + 0x28], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */) = 0 /*0x0*/;
L_0x00a95f69:
    // 00a95f69  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a95f6c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a95f6d  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a95f6e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a95f6f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a95f70  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_a95f74(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a95f74  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a95f75  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a95f76  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a95f77  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a95f78  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00a95f7b  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a95f7d  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00a95f7f  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a95f81  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a95f83  c7432000000000         -mov dword ptr [ebx + 0x20], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */) = 0 /*0x0*/;
    // 00a95f8a  c7432400000000         -mov dword ptr [ebx + 0x24], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(36) /* 0x24 */) = 0 /*0x0*/;
    // 00a95f91  c7432800000000         -mov dword ptr [ebx + 0x28], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */) = 0 /*0x0*/;
    // 00a95f98  c7432c00000000         -mov dword ptr [ebx + 0x2c], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(44) /* 0x2c */) = 0 /*0x0*/;
    // 00a95f9f  c7433000000000         -mov dword ptr [ebx + 0x30], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(48) /* 0x30 */) = 0 /*0x0*/;
    // 00a95fa6  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 00a95fa8  8a4315                 -mov al, byte ptr [ebx + 0x15]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(21) /* 0x15 */);
    // 00a95fab  c7433400000000         -mov dword ptr [ebx + 0x34], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(52) /* 0x34 */) = 0 /*0x0*/;
    // 00a95fb2  3c69                   +cmp al, 0x69
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(105 /*0x69*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a95fb4  721e                   -jb 0xa95fd4
    if (cpu.flags.cf)
    {
        goto L_0x00a95fd4;
    }
    // 00a95fb6  0f8692000000           -jbe 0xa9604e
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a9604e;
    }
    // 00a95fbc  3c75                   +cmp al, 0x75
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(117 /*0x75*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a95fbe  720b                   -jb 0xa95fcb
    if (cpu.flags.cf)
    {
        goto L_0x00a95fcb;
    }
    // 00a95fc0  7625                   -jbe 0xa95fe7
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a95fe7;
    }
    // 00a95fc2  3c78                   +cmp al, 0x78
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(120 /*0x78*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a95fc4  7421                   -je 0xa95fe7
    if (cpu.flags.zf)
    {
        goto L_0x00a95fe7;
    }
    // 00a95fc6  e960010000             -jmp 0xa9612b
    goto L_0x00a9612b;
L_0x00a95fcb:
    // 00a95fcb  3c6f                   +cmp al, 0x6f
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(111 /*0x6f*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a95fcd  7418                   -je 0xa95fe7
    if (cpu.flags.zf)
    {
        goto L_0x00a95fe7;
    }
    // 00a95fcf  e957010000             -jmp 0xa9612b
    goto L_0x00a9612b;
L_0x00a95fd4:
    // 00a95fd4  3c58                   +cmp al, 0x58
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(88 /*0x58*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a95fd6  0f824f010000           -jb 0xa9612b
    if (cpu.flags.cf)
    {
        goto L_0x00a9612b;
    }
    // 00a95fdc  7609                   -jbe 0xa95fe7
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a95fe7;
    }
    // 00a95fde  3c64                   +cmp al, 0x64
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(100 /*0x64*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a95fe0  746c                   -je 0xa9604e
    if (cpu.flags.zf)
    {
        goto L_0x00a9604e;
    }
    // 00a95fe2  e944010000             -jmp 0xa9612b
    goto L_0x00a9612b;
L_0x00a95fe7:
    // 00a95fe7  f6411f01               +test byte ptr [ecx + 0x1f], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(31) /* 0x1f */) & 1 /*0x1*/));
    // 00a95feb  7420                   -je 0xa9600d
    if (cpu.flags.zf)
    {
        goto L_0x00a9600d;
    }
    // 00a95fed  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 00a95fef  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a95ff2  891a                   -mov dword ptr [edx], ebx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebx;
    // 00a95ff4  8b43fc                 -mov eax, dword ptr [ebx - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-4) /* -0x4 */);
    // 00a95ff7  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00a95ffa  8b2a                   -mov ebp, dword ptr [edx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx);
    // 00a95ffc  83c504                 +add ebp, 4
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a95fff  892a                   -mov dword ptr [edx], ebp
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebp;
    // 00a96001  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00a96004  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00a96008  e91e010000             -jmp 0xa9612b
    goto L_0x00a9612b;
L_0x00a9600d:
    // 00a9600d  f6411e20               +test byte ptr [ecx + 0x1e], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */) & 32 /*0x20*/));
    // 00a96011  7413                   -je 0xa96026
    if (cpu.flags.zf)
    {
        goto L_0x00a96026;
    }
    // 00a96013  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 00a96015  83c004                 +add eax, 4
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a96018  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 00a9601a  8b40fc                 -mov eax, dword ptr [eax - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */);
    // 00a9601d  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00a96021  e905010000             -jmp 0xa9612b
    goto L_0x00a9612b;
L_0x00a96026:
    // 00a96026  8b2a                   -mov ebp, dword ptr [edx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx);
    // 00a96028  83c504                 -add ebp, 4
    (cpu.ebp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a9602b  892a                   -mov dword ptr [edx], ebp
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebp;
    // 00a9602d  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00a96030  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00a96034  f6411e10               +test byte ptr [ecx + 0x1e], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */) & 16 /*0x10*/));
    // 00a96038  0f84ed000000           -je 0xa9612b
    if (cpu.flags.zf)
    {
        goto L_0x00a9612b;
    }
    // 00a9603e  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a96040  668b442408             -mov ax, word ptr [esp + 8]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00a96045  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00a96049  e9dd000000             -jmp 0xa9612b
    goto L_0x00a9612b;
L_0x00a9604e:
    // 00a9604e  f6411f01               +test byte ptr [ecx + 0x1f], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(31) /* 0x1f */) & 1 /*0x1*/));
    // 00a96052  741d                   -je 0xa96071
    if (cpu.flags.zf)
    {
        goto L_0x00a96071;
    }
    // 00a96054  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 00a96056  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a96059  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 00a9605b  8b40fc                 -mov eax, dword ptr [eax - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */);
    // 00a9605e  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00a96061  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 00a96063  83c304                 +add ebx, 4
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a96066  891a                   -mov dword ptr [edx], ebx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebx;
    // 00a96068  8b43fc                 -mov eax, dword ptr [ebx - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-4) /* -0x4 */);
    // 00a9606b  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00a9606f  eb33                   -jmp 0xa960a4
    goto L_0x00a960a4;
L_0x00a96071:
    // 00a96071  f6411e20               +test byte ptr [ecx + 0x1e], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */) & 32 /*0x20*/));
    // 00a96075  740c                   -je 0xa96083
    if (cpu.flags.zf)
    {
        goto L_0x00a96083;
    }
    // 00a96077  8b2a                   -mov ebp, dword ptr [edx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx);
    // 00a96079  83c504                 +add ebp, 4
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a9607c  892a                   -mov dword ptr [edx], ebp
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebp;
    // 00a9607e  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00a96081  eb1d                   -jmp 0xa960a0
    goto L_0x00a960a0;
L_0x00a96083:
    // 00a96083  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 00a96085  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a96088  891a                   -mov dword ptr [edx], ebx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebx;
    // 00a9608a  8b43fc                 -mov eax, dword ptr [ebx - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-4) /* -0x4 */);
    // 00a9608d  8a791e                 -mov bh, byte ptr [ecx + 0x1e]
    cpu.bh = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */);
    // 00a96090  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00a96094  f6c710                 +test bh, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 16 /*0x10*/));
    // 00a96097  740b                   -je 0xa960a4
    if (cpu.flags.zf)
    {
        goto L_0x00a960a4;
    }
    // 00a96099  8b442406               -mov eax, dword ptr [esp + 6]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(6) /* 0x6 */);
    // 00a9609d  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
L_0x00a960a0:
    // 00a960a0  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
L_0x00a960a4:
    // 00a960a4  8a591f                 -mov bl, byte ptr [ecx + 0x1f]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(31) /* 0x1f */);
    // 00a960a7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a960a9  f6c301                 +test bl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 1 /*0x1*/));
    // 00a960ac  7409                   -je 0xa960b7
    if (cpu.flags.zf)
    {
        goto L_0x00a960b7;
    }
    // 00a960ae  f644240780             +test byte ptr [esp + 7], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(7) /* 0x7 */) & 128 /*0x80*/));
    // 00a960b3  7409                   -je 0xa960be
    if (cpu.flags.zf)
    {
        goto L_0x00a960be;
    }
    // 00a960b5  eb0b                   -jmp 0xa960c2
    goto L_0x00a960c2;
L_0x00a960b7:
    // 00a960b7  837c240800             +cmp dword ptr [esp + 8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a960bc  7c04                   -jl 0xa960c2
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a960c2;
    }
L_0x00a960be:
    // 00a960be  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a960c0  7442                   -je 0xa96104
    if (cpu.flags.zf)
    {
        goto L_0x00a96104;
    }
L_0x00a960c2:
    // 00a960c2  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 00a960c5  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a960c8  895920                 -mov dword ptr [ecx + 0x20], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.ebx;
    // 00a960cb  c604062d               -mov byte ptr [esi + eax], 0x2d
    app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1) = 45 /*0x2d*/;
    // 00a960cf  f6411f01               +test byte ptr [ecx + 0x1f], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(31) /* 0x1f */) & 1 /*0x1*/));
    // 00a960d3  7429                   -je 0xa960fe
    if (cpu.flags.zf)
    {
        goto L_0x00a960fe;
    }
    // 00a960d5  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 00a960d8  8b6c2404               -mov ebp, dword ptr [esp + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a960dc  f7d3                   -not ebx
    cpu.ebx = ~cpu.ebx;
    // 00a960de  f7d5                   -not ebp
    cpu.ebp = ~cpu.ebp;
    // 00a960e0  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 00a960e3  8d4301                 -lea eax, [ebx + 1]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 00a960e6  896c2404               -mov dword ptr [esp + 4], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 00a960ea  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00a960ed  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a960ef  7505                   -jne 0xa960f6
    if (!cpu.flags.zf)
    {
        goto L_0x00a960f6;
    }
    // 00a960f1  8d4501                 -lea eax, [ebp + 1]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(1) /* 0x1 */);
    // 00a960f4  eb02                   -jmp 0xa960f8
    goto L_0x00a960f8;
L_0x00a960f6:
    // 00a960f6  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
L_0x00a960f8:
    // 00a960f8  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00a960fc  eb2d                   -jmp 0xa9612b
    goto L_0x00a9612b;
L_0x00a960fe:
    // 00a960fe  f75c2408               +neg dword ptr [esp + 8]
    {
        x86::reg32 tmp1 = 0;
        auto tmp2 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp2 = result;
        cpu.set_szp(tmp2);
    }
    // 00a96102  eb27                   -jmp 0xa9612b
    goto L_0x00a9612b;
L_0x00a96104:
    // 00a96104  8a411e                 -mov al, byte ptr [ecx + 0x1e]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */);
    // 00a96107  a804                   +test al, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 4 /*0x4*/));
    // 00a96109  740f                   -je 0xa9611a
    if (cpu.flags.zf)
    {
        goto L_0x00a9611a;
    }
    // 00a9610b  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 00a9610e  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a96111  895920                 -mov dword ptr [ecx + 0x20], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.ebx;
    // 00a96114  c604062b               -mov byte ptr [esi + eax], 0x2b
    app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1) = 43 /*0x2b*/;
    // 00a96118  eb11                   -jmp 0xa9612b
    goto L_0x00a9612b;
L_0x00a9611a:
    // 00a9611a  a802                   +test al, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 2 /*0x2*/));
    // 00a9611c  740d                   -je 0xa9612b
    if (cpu.flags.zf)
    {
        goto L_0x00a9612b;
    }
    // 00a9611e  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 00a96121  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a96124  895920                 -mov dword ptr [ecx + 0x20], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.ebx;
    // 00a96127  c6040620               -mov byte ptr [esi + eax], 0x20
    app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1) = 32 /*0x20*/;
L_0x00a9612b:
    // 00a9612b  8a4115                 -mov al, byte ptr [ecx + 0x15]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(21) /* 0x15 */);
    // 00a9612e  bb0a000000             -mov ebx, 0xa
    cpu.ebx = 10 /*0xa*/;
    // 00a96133  3c64                   +cmp al, 0x64
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(100 /*0x64*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a96135  7261                   -jb 0xa96198
    if (cpu.flags.cf)
    {
        goto L_0x00a96198;
    }
    // 00a96137  0f860b020000           -jbe 0xa96348
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a96348;
    }
    // 00a9613d  3c6f                   +cmp al, 0x6f
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(111 /*0x6f*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a9613f  7238                   -jb 0xa96179
    if (cpu.flags.cf)
    {
        goto L_0x00a96179;
    }
    // 00a96141  0f86e1010000           -jbe 0xa96328
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a96328;
    }
    // 00a96147  3c73                   +cmp al, 0x73
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(115 /*0x73*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a96149  7221                   -jb 0xa9616c
    if (cpu.flags.cf)
    {
        goto L_0x00a9616c;
    }
    // 00a9614b  0f86f0000000           -jbe 0xa96241
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a96241;
    }
    // 00a96151  3c75                   +cmp al, 0x75
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(117 /*0x75*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a96153  0f8204040000           -jb 0xa9655d
    if (cpu.flags.cf)
    {
        goto L_0x00a9655d;
    }
    // 00a96159  0f86e9010000           -jbe 0xa96348
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a96348;
    }
    // 00a9615f  3c78                   +cmp al, 0x78
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(120 /*0x78*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a96161  0f847c010000           -je 0xa962e3
    if (cpu.flags.zf)
    {
        goto L_0x00a962e3;
    }
    // 00a96167  e9f1030000             -jmp 0xa9655d
    goto L_0x00a9655d;
L_0x00a9616c:
    // 00a9616c  3c70                   +cmp al, 0x70
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(112 /*0x70*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a9616e  0f8489020000           -je 0xa963fd
    if (cpu.flags.zf)
    {
        goto L_0x00a963fd;
    }
    // 00a96174  e9e4030000             -jmp 0xa9655d
    goto L_0x00a9655d;
L_0x00a96179:
    // 00a96179  3c66                   +cmp al, 0x66
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(102 /*0x66*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a9617b  0f829d000000           -jb 0xa9621e
    if (cpu.flags.cf)
    {
        goto L_0x00a9621e;
    }
    // 00a96181  7666                   -jbe 0xa961e9
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a961e9;
    }
    // 00a96183  3c67                   +cmp al, 0x67
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(103 /*0x67*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a96185  0f8693000000           -jbe 0xa9621e
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a9621e;
    }
    // 00a9618b  3c69                   +cmp al, 0x69
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(105 /*0x69*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a9618d  0f84b5010000           -je 0xa96348
    if (cpu.flags.zf)
    {
        goto L_0x00a96348;
    }
    // 00a96193  e9c5030000             -jmp 0xa9655d
    goto L_0x00a9655d;
L_0x00a96198:
    // 00a96198  3c47                   +cmp al, 0x47
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(71 /*0x47*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a9619a  7238                   -jb 0xa961d4
    if (cpu.flags.cf)
    {
        goto L_0x00a961d4;
    }
    // 00a9619c  0f867c000000           -jbe 0xa9621e
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a9621e;
    }
    // 00a961a2  3c53                   +cmp al, 0x53
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(83 /*0x53*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a961a4  7221                   -jb 0xa961c7
    if (cpu.flags.cf)
    {
        goto L_0x00a961c7;
    }
    // 00a961a6  0f8695000000           -jbe 0xa96241
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a96241;
    }
    // 00a961ac  3c58                   +cmp al, 0x58
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(88 /*0x58*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a961ae  0f82a9030000           -jb 0xa9655d
    if (cpu.flags.cf)
    {
        goto L_0x00a9655d;
    }
    // 00a961b4  0f8629010000           -jbe 0xa962e3
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a962e3;
    }
    // 00a961ba  3c63                   +cmp al, 0x63
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(99 /*0x63*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a961bc  0f84ce020000           -je 0xa96490
    if (cpu.flags.zf)
    {
        goto L_0x00a96490;
    }
    // 00a961c2  e996030000             -jmp 0xa9655d
    goto L_0x00a9655d;
L_0x00a961c7:
    // 00a961c7  3c50                   +cmp al, 0x50
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(80 /*0x50*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a961c9  0f842e020000           -je 0xa963fd
    if (cpu.flags.zf)
    {
        goto L_0x00a963fd;
    }
    // 00a961cf  e989030000             -jmp 0xa9655d
    goto L_0x00a9655d;
L_0x00a961d4:
    // 00a961d4  3c45                   +cmp al, 0x45
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(69 /*0x45*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a961d6  7204                   -jb 0xa961dc
    if (cpu.flags.cf)
    {
        goto L_0x00a961dc;
    }
    // 00a961d8  7644                   -jbe 0xa9621e
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a9621e;
    }
    // 00a961da  eb0d                   -jmp 0xa961e9
    goto L_0x00a961e9;
L_0x00a961dc:
    // 00a961dc  3c43                   +cmp al, 0x43
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(67 /*0x43*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a961de  0f8438030000           -je 0xa9651c
    if (cpu.flags.zf)
    {
        goto L_0x00a9651c;
    }
    // 00a961e4  e974030000             -jmp 0xa9655d
    goto L_0x00a9655d;
L_0x00a961e9:
    // 00a961e9  f6411e10               +test byte ptr [ecx + 0x1e], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */) & 16 /*0x10*/));
    // 00a961ed  742f                   -je 0xa9621e
    if (cpu.flags.zf)
    {
        goto L_0x00a9621e;
    }
    // 00a961ef  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 00a961f1  83c304                 +add ebx, 4
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a961f4  891a                   -mov dword ptr [edx], ebx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebx;
    // 00a961f6  8b43fc                 -mov eax, dword ptr [ebx - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-4) /* -0x4 */);
    // 00a961f9  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00a961fd  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00a961ff  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a96201  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a96203  e8c0fbffff             -call 0xa95dc8
    cpu.esp -= 4;
    sub_a95dc8(app, cpu);
    if (cpu.terminate) return;
    // 00a96208  bbffffffff             -mov ebx, 0xffffffff
    cpu.ebx = 4294967295 /*0xffffffff*/;
    // 00a9620d  8cda                   -mov edx, ds
    cpu.edx = cpu.ds;
    // 00a9620f  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a96211  e8befaffff             -call 0xa95cd4
    cpu.esp -= 4;
    sub_a95cd4(app, cpu);
    if (cpu.terminate) return;
    // 00a96216  894128                 -mov dword ptr [ecx + 0x28], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 00a96219  e952030000             -jmp 0xa96570
    goto L_0x00a96570;
L_0x00a9621e:
    // 00a9621e  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00a96220  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a96222  e89dfcffff             -call 0xa95ec4
    cpu.esp -= 4;
    sub_a95ec4(app, cpu);
    if (cpu.terminate) return;
    // 00a96227  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a96229  e89efcffff             -call 0xa95ecc
    cpu.esp -= 4;
    sub_a95ecc(app, cpu);
    if (cpu.terminate) return;
    // 00a9622e  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a96230  8d7e01                 -lea edi, [esi + 1]
    cpu.edi = x86::reg32(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00a96233  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a96235  8cc2                   -mov edx, es
    cpu.edx = cpu.es;
    // 00a96237  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a96239  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00a9623c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9623d  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a9623e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9623f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a96240  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a96241:
    // 00a96241  c60600                 -mov byte ptr [esi], 0
    app->getMemory<x86::reg8>(cpu.esi) = 0 /*0x0*/;
    // 00a96244  8a411e                 -mov al, byte ptr [ecx + 0x1e]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */);
    // 00a96247  a880                   +test al, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 128 /*0x80*/));
    // 00a96249  741d                   -je 0xa96268
    if (cpu.flags.zf)
    {
        goto L_0x00a96268;
    }
    // 00a9624b  8b2a                   -mov ebp, dword ptr [edx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx);
    // 00a9624d  83c508                 -add ebp, 8
    (cpu.ebp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00a96250  892a                   -mov dword ptr [edx], ebp
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebp;
    // 00a96252  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00a96255  668b55fc               -mov dx, word ptr [ebp - 4]
    cpu.dx = app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00a96259  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a9625b  7505                   -jne 0xa96262
    if (!cpu.flags.zf)
    {
        goto L_0x00a96262;
    }
    // 00a9625d  6685d2                 +test dx, dx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.dx & cpu.dx));
    // 00a96260  742e                   -je 0xa96290
    if (cpu.flags.zf)
    {
        goto L_0x00a96290;
    }
L_0x00a96262:
    // 00a96262  8ec2                   -mov es, edx
    cpu.es = cpu.edx;
    // 00a96264  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a96266  eb28                   -jmp 0xa96290
    goto L_0x00a96290;
L_0x00a96268:
    // 00a96268  a840                   +test al, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 64 /*0x40*/));
    // 00a9626a  7410                   -je 0xa9627c
    if (cpu.flags.zf)
    {
        goto L_0x00a9627c;
    }
    // 00a9626c  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx);
    // 00a9626e  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a96271  8932                   -mov dword ptr [edx], esi
    app->getMemory<x86::reg32>(cpu.edx) = cpu.esi;
    // 00a96273  8b46fc                 -mov eax, dword ptr [esi - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-4) /* -0x4 */);
    // 00a96276  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a96278  7416                   -je 0xa96290
    if (cpu.flags.zf)
    {
        goto L_0x00a96290;
    }
    // 00a9627a  eb0e                   -jmp 0xa9628a
    goto L_0x00a9628a;
L_0x00a9627c:
    // 00a9627c  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 00a9627e  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a96281  891a                   -mov dword ptr [edx], ebx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebx;
    // 00a96283  8b43fc                 -mov eax, dword ptr [ebx - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-4) /* -0x4 */);
    // 00a96286  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a96288  7406                   -je 0xa96290
    if (cpu.flags.zf)
    {
        goto L_0x00a96290;
    }
L_0x00a9628a:
    // 00a9628a  8cda                   -mov edx, ds
    cpu.edx = cpu.ds;
    // 00a9628c  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a9628e  8ec2                   -mov es, edx
    cpu.es = cpu.edx;
L_0x00a96290:
    // 00a96290  80791553               +cmp byte ptr [ecx + 0x15], 0x53
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(21) /* 0x15 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(83 /*0x53*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a96294  7508                   -jne 0xa9629e
    if (!cpu.flags.zf)
    {
        goto L_0x00a9629e;
    }
    // 00a96296  f6411e10               +test byte ptr [ecx + 0x1e], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */) & 16 /*0x10*/));
    // 00a9629a  7408                   -je 0xa962a4
    if (cpu.flags.zf)
    {
        goto L_0x00a962a4;
    }
    // 00a9629c  eb14                   -jmp 0xa962b2
    goto L_0x00a962b2;
L_0x00a9629e:
    // 00a9629e  f6411e20               +test byte ptr [ecx + 0x1e], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */) & 32 /*0x20*/));
    // 00a962a2  740e                   -je 0xa962b2
    if (cpu.flags.zf)
    {
        goto L_0x00a962b2;
    }
L_0x00a962a4:
    // 00a962a4  8cc2                   -mov edx, es
    cpu.edx = cpu.es;
    // 00a962a6  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a962a8  8b5908                 -mov ebx, dword ptr [ecx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00a962ab  e848faffff             -call 0xa95cf8
    cpu.esp -= 4;
    sub_a95cf8(app, cpu);
    if (cpu.terminate) return;
    // 00a962b0  eb0c                   -jmp 0xa962be
    goto L_0x00a962be;
L_0x00a962b2:
    // 00a962b2  8cc2                   -mov edx, es
    cpu.edx = cpu.es;
    // 00a962b4  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a962b6  8b5908                 -mov ebx, dword ptr [ecx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00a962b9  e816faffff             -call 0xa95cd4
    cpu.esp -= 4;
    sub_a95cd4(app, cpu);
    if (cpu.terminate) return;
L_0x00a962be:
    // 00a962be  8b5108                 -mov edx, dword ptr [ecx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00a962c1  894128                 -mov dword ptr [ecx + 0x28], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 00a962c4  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a962c6  0f8ca4020000           -jl 0xa96570
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a96570;
    }
    // 00a962cc  39d0                   +cmp eax, edx
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
    // 00a962ce  0f8e9c020000           -jle 0xa96570
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a96570;
    }
    // 00a962d4  895128                 -mov dword ptr [ecx + 0x28], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */) = cpu.edx;
    // 00a962d7  8cc2                   -mov edx, es
    cpu.edx = cpu.es;
    // 00a962d9  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a962db  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00a962de  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a962df  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a962e0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a962e1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a962e2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a962e3:
    // 00a962e3  f6411e01               +test byte ptr [ecx + 0x1e], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */) & 1 /*0x1*/));
    // 00a962e7  743a                   -je 0xa96323
    if (cpu.flags.zf)
    {
        goto L_0x00a96323;
    }
    // 00a962e9  f6411f01               +test byte ptr [ecx + 0x1f], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(31) /* 0x1f */) & 1 /*0x1*/));
    // 00a962ed  740f                   -je 0xa962fe
    if (cpu.flags.zf)
    {
        goto L_0x00a962fe;
    }
    // 00a962ef  833c2400               +cmp dword ptr [esp], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a962f3  7510                   -jne 0xa96305
    if (!cpu.flags.zf)
    {
        goto L_0x00a96305;
    }
    // 00a962f5  837c240400             +cmp dword ptr [esp + 4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a962fa  7427                   -je 0xa96323
    if (cpu.flags.zf)
    {
        goto L_0x00a96323;
    }
    // 00a962fc  eb07                   -jmp 0xa96305
    goto L_0x00a96305;
L_0x00a962fe:
    // 00a962fe  837c240800             +cmp dword ptr [esp + 8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a96303  741e                   -je 0xa96323
    if (cpu.flags.zf)
    {
        goto L_0x00a96323;
    }
L_0x00a96305:
    // 00a96305  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 00a96308  8d5001                 -lea edx, [eax + 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a9630b  895120                 -mov dword ptr [ecx + 0x20], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 00a9630e  c6040630               -mov byte ptr [esi + eax], 0x30
    app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1) = 48 /*0x30*/;
    // 00a96312  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 00a96315  8d5001                 -lea edx, [eax + 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a96318  895120                 -mov dword ptr [ecx + 0x20], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 00a9631b  8d1406                 -lea edx, [esi + eax]
    cpu.edx = x86::reg32(cpu.esi + cpu.eax * 1);
    // 00a9631e  8a4115                 -mov al, byte ptr [ecx + 0x15]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(21) /* 0x15 */);
    // 00a96321  8802                   -mov byte ptr [edx], al
    app->getMemory<x86::reg8>(cpu.edx) = cpu.al;
L_0x00a96323:
    // 00a96323  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
L_0x00a96328:
    // 00a96328  8079156f               +cmp byte ptr [ecx + 0x15], 0x6f
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(21) /* 0x15 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(111 /*0x6f*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a9632c  751a                   -jne 0xa96348
    if (!cpu.flags.zf)
    {
        goto L_0x00a96348;
    }
    // 00a9632e  8a511e                 -mov dl, byte ptr [ecx + 0x1e]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */);
    // 00a96331  bb08000000             -mov ebx, 8
    cpu.ebx = 8 /*0x8*/;
    // 00a96336  f6c201                 +test dl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 1 /*0x1*/));
    // 00a96339  740d                   -je 0xa96348
    if (cpu.flags.zf)
    {
        goto L_0x00a96348;
    }
    // 00a9633b  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 00a9633e  8d5001                 -lea edx, [eax + 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a96341  895120                 -mov dword ptr [ecx + 0x20], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 00a96344  c6040630               -mov byte ptr [esi + eax], 0x30
    app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1) = 48 /*0x30*/;
L_0x00a96348:
    // 00a96348  8cda                   -mov edx, ds
    cpu.edx = cpu.ds;
    // 00a9634a  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 00a9634d  8ec2                   -mov es, edx
    cpu.es = cpu.edx;
    // 00a9634f  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 00a96351  8a711f                 -mov dh, byte ptr [ecx + 0x1f]
    cpu.dh = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(31) /* 0x1f */);
    // 00a96354  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a96356  f6c601                 +test dh, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 1 /*0x1*/));
    // 00a96359  7436                   -je 0xa96391
    if (cpu.flags.zf)
    {
        goto L_0x00a96391;
    }
    // 00a9635b  83790800               +cmp dword ptr [ecx + 8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a9635f  7515                   -jne 0xa96376
    if (!cpu.flags.zf)
    {
        goto L_0x00a96376;
    }
    // 00a96361  833c2400               +cmp dword ptr [esp], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a96365  750f                   -jne 0xa96376
    if (!cpu.flags.zf)
    {
        goto L_0x00a96376;
    }
    // 00a96367  837c240400             +cmp dword ptr [esp + 4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a9636c  7508                   -jne 0xa96376
    if (!cpu.flags.zf)
    {
        goto L_0x00a96376;
    }
    // 00a9636e  26c60000               -mov byte ptr es:[eax], 0
    app->getMemory<x86::reg8>(cpu.ees + cpu.eax) = 0 /*0x0*/;
    // 00a96372  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a96374  eb59                   -jmp 0xa963cf
    goto L_0x00a963cf;
L_0x00a96376:
    // 00a96376  8b5120                 -mov edx, dword ptr [ecx + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 00a96379  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a9637b  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 00a9637d  e8de200000             -call 0xa98460
    cpu.esp -= 4;
    sub_a98460(app, cpu);
    if (cpu.terminate) return;
    // 00a96382  80791558               +cmp byte ptr [ecx + 0x15], 0x58
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(21) /* 0x15 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(88 /*0x58*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a96386  7539                   -jne 0xa963c1
    if (!cpu.flags.zf)
    {
        goto L_0x00a963c1;
    }
    // 00a96388  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a9638a  e8ed010000             -call 0xa9657c
    cpu.esp -= 4;
    sub_a9657c(app, cpu);
    if (cpu.terminate) return;
    // 00a9638f  eb30                   -jmp 0xa963c1
    goto L_0x00a963c1;
L_0x00a96391:
    // 00a96391  83790800               +cmp dword ptr [ecx + 8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a96395  750f                   -jne 0xa963a6
    if (!cpu.flags.zf)
    {
        goto L_0x00a963a6;
    }
    // 00a96397  837c240800             +cmp dword ptr [esp + 8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a9639c  7508                   -jne 0xa963a6
    if (!cpu.flags.zf)
    {
        goto L_0x00a963a6;
    }
    // 00a9639e  26c60000               -mov byte ptr es:[eax], 0
    app->getMemory<x86::reg8>(cpu.ees + cpu.eax) = 0 /*0x0*/;
    // 00a963a2  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a963a4  eb29                   -jmp 0xa963cf
    goto L_0x00a963cf;
L_0x00a963a6:
    // 00a963a6  8b5120                 -mov edx, dword ptr [ecx + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 00a963a9  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00a963ad  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 00a963af  e89c210000             -call 0xa98550
    cpu.esp -= 4;
    sub_a98550(app, cpu);
    if (cpu.terminate) return;
    // 00a963b4  80791558               +cmp byte ptr [ecx + 0x15], 0x58
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(21) /* 0x15 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(88 /*0x58*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a963b8  7507                   -jne 0xa963c1
    if (!cpu.flags.zf)
    {
        goto L_0x00a963c1;
    }
    // 00a963ba  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a963bc  e8bb010000             -call 0xa9657c
    cpu.esp -= 4;
    sub_a9657c(app, cpu);
    if (cpu.terminate) return;
L_0x00a963c1:
    // 00a963c1  bbffffffff             -mov ebx, 0xffffffff
    cpu.ebx = 4294967295 /*0xffffffff*/;
    // 00a963c6  8cc2                   -mov edx, es
    cpu.edx = cpu.es;
    // 00a963c8  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a963ca  e805f9ffff             -call 0xa95cd4
    cpu.esp -= 4;
    sub_a95cd4(app, cpu);
    if (cpu.terminate) return;
L_0x00a963cf:
    // 00a963cf  894128                 -mov dword ptr [ecx + 0x28], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 00a963d2  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a963d4  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00a963d7  39c2                   +cmp edx, eax
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
    // 00a963d9  7d05                   -jge 0xa963e0
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a963e0;
    }
    // 00a963db  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00a963dd  894124                 -mov dword ptr [ecx + 0x24], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(36) /* 0x24 */) = cpu.eax;
L_0x00a963e0:
    // 00a963e0  837908ff               +cmp dword ptr [ecx + 8], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a963e4  0f8586010000           -jne 0xa96570
    if (!cpu.flags.zf)
    {
        goto L_0x00a96570;
    }
    // 00a963ea  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a963ec  e8dbfaffff             -call 0xa95ecc
    cpu.esp -= 4;
    sub_a95ecc(app, cpu);
    if (cpu.terminate) return;
    // 00a963f1  8cc2                   -mov edx, es
    cpu.edx = cpu.es;
    // 00a963f3  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a963f5  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00a963f8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a963f9  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a963fa  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a963fb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a963fc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a963fd:
    // 00a963fd  83790400               +cmp dword ptr [ecx + 4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a96401  7516                   -jne 0xa96419
    if (!cpu.flags.zf)
    {
        goto L_0x00a96419;
    }
    // 00a96403  f6411e80               +test byte ptr [ecx + 0x1e], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */) & 128 /*0x80*/));
    // 00a96407  7409                   -je 0xa96412
    if (cpu.flags.zf)
    {
        goto L_0x00a96412;
    }
    // 00a96409  c741040d000000         -mov dword ptr [ecx + 4], 0xd
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = 13 /*0xd*/;
    // 00a96410  eb07                   -jmp 0xa96419
    goto L_0x00a96419;
L_0x00a96412:
    // 00a96412  c7410408000000         -mov dword ptr [ecx + 4], 8
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = 8 /*0x8*/;
L_0x00a96419:
    // 00a96419  80611ef9               -and byte ptr [ecx + 0x1e], 0xf9
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */) &= x86::reg8(x86::sreg8(249 /*0xf9*/));
    // 00a9641d  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 00a9641f  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a96422  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 00a96424  8a591e                 -mov bl, byte ptr [ecx + 0x1e]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */);
    // 00a96427  8b68fc                 -mov ebp, dword ptr [eax - 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */);
    // 00a9642a  f6c380                 +test bl, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 128 /*0x80*/));
    // 00a9642d  7429                   -je 0xa96458
    if (cpu.flags.zf)
    {
        goto L_0x00a96458;
    }
    // 00a9642f  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a96432  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 00a96434  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 00a96439  8b40fc                 -mov eax, dword ptr [eax - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */);
    // 00a9643c  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00a9643e  25ffff0000             +and eax, 0xffff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/))));
    // 00a96443  e81cf9ffff             -call 0xa95d64
    cpu.esp -= 4;
    sub_a95d64(app, cpu);
    if (cpu.terminate) return;
    // 00a96448  bb08000000             -mov ebx, 8
    cpu.ebx = 8 /*0x8*/;
    // 00a9644d  8d5605                 -lea edx, [esi + 5]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(5) /* 0x5 */);
    // 00a96450  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00a96452  c646043a               -mov byte ptr [esi + 4], 0x3a
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(4) /* 0x4 */) = 58 /*0x3a*/;
    // 00a96456  eb09                   -jmp 0xa96461
    goto L_0x00a96461;
L_0x00a96458:
    // 00a96458  bb08000000             -mov ebx, 8
    cpu.ebx = 8 /*0x8*/;
    // 00a9645d  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00a9645f  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
L_0x00a96461:
    // 00a96461  e8fef8ffff             -call 0xa95d64
    cpu.esp -= 4;
    sub_a95d64(app, cpu);
    if (cpu.terminate) return;
    // 00a96466  80791550               +cmp byte ptr [ecx + 0x15], 0x50
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(21) /* 0x15 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(80 /*0x50*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a9646a  7507                   -jne 0xa96473
    if (!cpu.flags.zf)
    {
        goto L_0x00a96473;
    }
    // 00a9646c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a9646e  e809010000             -call 0xa9657c
    cpu.esp -= 4;
    sub_a9657c(app, cpu);
    if (cpu.terminate) return;
L_0x00a96473:
    // 00a96473  bbffffffff             -mov ebx, 0xffffffff
    cpu.ebx = 4294967295 /*0xffffffff*/;
    // 00a96478  8cc2                   -mov edx, es
    cpu.edx = cpu.es;
    // 00a9647a  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a9647c  e853f8ffff             -call 0xa95cd4
    cpu.esp -= 4;
    sub_a95cd4(app, cpu);
    if (cpu.terminate) return;
    // 00a96481  894120                 -mov dword ptr [ecx + 0x20], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 00a96484  8cc2                   -mov edx, es
    cpu.edx = cpu.es;
    // 00a96486  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a96488  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00a9648b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9648c  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a9648d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9648e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9648f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a96490:
    // 00a96490  8a591e                 -mov bl, byte ptr [ecx + 0x1e]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */);
    // 00a96493  c7412001000000         -mov dword ptr [ecx + 0x20], 1
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = 1 /*0x1*/;
    // 00a9649a  f6c320                 +test bl, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 32 /*0x20*/));
    // 00a9649d  7465                   -je 0xa96504
    if (cpu.flags.zf)
    {
        goto L_0x00a96504;
    }
    // 00a9649f  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 00a964a1  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a964a4  891a                   -mov dword ptr [edx], ebx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebx;
    // 00a964a6  668b43fc               -mov ax, word ptr [ebx - 4]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(-4) /* -0x4 */);
    // 00a964aa  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a964ac  6689c2                 -mov dx, ax
    cpu.dx = cpu.ax;
    // 00a964af  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00a964b3  e8d81e0000             -call 0xa98390
    cpu.esp -= 4;
    sub_a98390(app, cpu);
    if (cpu.terminate) return;
    // 00a964b8  83f8ff                 +cmp eax, -1
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
    // 00a964bb  0f84af000000           -je 0xa96570
    if (cpu.flags.zf)
    {
        goto L_0x00a96570;
    }
    // 00a964c1  8a44240c               -mov al, byte ptr [esp + 0xc]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00a964c5  8b2df01daa00           -mov ebp, dword ptr [0xaa1df0]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(11148784) /* 0xaa1df0 */);
    // 00a964cb  8806                   -mov byte ptr [esi], al
    app->getMemory<x86::reg8>(cpu.esi) = cpu.al;
    // 00a964cd  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00a964cf  0f849b000000           -je 0xa96570
    if (cpu.flags.zf)
    {
        goto L_0x00a96570;
    }
    // 00a964d5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a964d7  8a44240c               -mov al, byte ptr [esp + 0xc]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00a964db  8a80011eaa00           -mov al, byte ptr [eax + 0xaa1e01]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(11148801) /* 0xaa1e01 */);
    // 00a964e1  2401                   -and al, 1
    cpu.al &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00a964e3  25ff000000             +and eax, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 00a964e8  0f8482000000           -je 0xa96570
    if (cpu.flags.zf)
    {
        goto L_0x00a96570;
    }
    // 00a964ee  8a44240d               -mov al, byte ptr [esp + 0xd]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(13) /* 0xd */);
    // 00a964f2  884601                 -mov byte ptr [esi + 1], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00a964f5  ff4120                 -inc dword ptr [ecx + 0x20]
    (app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */))++;
    // 00a964f8  8cc2                   -mov edx, es
    cpu.edx = cpu.es;
    // 00a964fa  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a964fc  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00a964ff  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a96500  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a96501  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a96502  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a96503  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a96504:
    // 00a96504  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 00a96506  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a96509  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 00a9650b  8a40fc                 -mov al, byte ptr [eax - 4]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(-4) /* -0x4 */);
    // 00a9650e  8806                   -mov byte ptr [esi], al
    app->getMemory<x86::reg8>(cpu.esi) = cpu.al;
    // 00a96510  8cc2                   -mov edx, es
    cpu.edx = cpu.es;
    // 00a96512  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a96514  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00a96517  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a96518  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a96519  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9651a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9651b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a9651c:
    // 00a9651c  8b2a                   -mov ebp, dword ptr [edx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx);
    // 00a9651e  83c504                 -add ebp, 4
    (cpu.ebp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a96521  892a                   -mov dword ptr [edx], ebp
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebp;
    // 00a96523  668b55fc               -mov dx, word ptr [ebp - 4]
    cpu.dx = app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00a96527  81e2ffff0000           -and edx, 0xffff
    cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00a9652d  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a9652f  e85c1e0000             -call 0xa98390
    cpu.esp -= 4;
    sub_a98390(app, cpu);
    if (cpu.terminate) return;
    // 00a96534  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a96536  83f8ff                 +cmp eax, -1
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
    // 00a96539  740f                   -je 0xa9654a
    if (cpu.flags.zf)
    {
        goto L_0x00a9654a;
    }
    // 00a9653b  894120                 -mov dword ptr [ecx + 0x20], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 00a9653e  8cc2                   -mov edx, es
    cpu.edx = cpu.es;
    // 00a96540  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a96542  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00a96545  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a96546  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a96547  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a96548  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a96549  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a9654a:
    // 00a9654a  c7412000000000         -mov dword ptr [ecx + 0x20], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = 0 /*0x0*/;
    // 00a96551  8cc2                   -mov edx, es
    cpu.edx = cpu.es;
    // 00a96553  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a96555  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00a96558  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a96559  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a9655a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9655b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9655c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a9655d:
    // 00a9655d  c7410400000000         -mov dword ptr [ecx + 4], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 00a96564  8a4115                 -mov al, byte ptr [ecx + 0x15]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(21) /* 0x15 */);
    // 00a96567  8806                   -mov byte ptr [esi], al
    app->getMemory<x86::reg8>(cpu.esi) = cpu.al;
    // 00a96569  c7412001000000         -mov dword ptr [ecx + 0x20], 1
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = 1 /*0x1*/;
L_0x00a96570:
    // 00a96570  8cc2                   -mov edx, es
    cpu.edx = cpu.es;
    // 00a96572  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a96574  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00a96577  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a96578  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a96579  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9657a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9657b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a9657c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9657c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a9657d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a9657e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a96580  803800                 +cmp byte ptr [eax], 0
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
    // 00a96583  7413                   -je 0xa96598
    if (cpu.flags.zf)
    {
        goto L_0x00a96598;
    }
L_0x00a96585:
    // 00a96585  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a96587  8a02                   -mov al, byte ptr [edx]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx);
    // 00a96589  e852200000             -call 0xa985e0
    cpu.esp -= 4;
    sub_a985e0(app, cpu);
    if (cpu.terminate) return;
    // 00a9658e  8802                   -mov byte ptr [edx], al
    app->getMemory<x86::reg8>(cpu.edx) = cpu.al;
    // 00a96590  8a5a01                 -mov bl, byte ptr [edx + 1]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 00a96593  42                     -inc edx
    (cpu.edx)++;
    // 00a96594  84db                   +test bl, bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.bl));
    // 00a96596  75ed                   -jne 0xa96585
    if (!cpu.flags.zf)
    {
        goto L_0x00a96585;
    }
L_0x00a96598:
    // 00a96598  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a96599  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9659a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void sub_a965a0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a965a0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a965a1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a965a2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a965a3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a965a4  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 00a965a6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a965a8  0f849a000000           -je 0xa96648
    if (cpu.flags.zf)
    {
        goto L_0x00a96648;
    }
    // 00a965ae  8d480b                 -lea ecx, [eax + 0xb]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(11) /* 0xb */);
    // 00a965b1  39c1                   +cmp ecx, eax
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a965b3  0f828f000000           -jb 0xa96648
    if (cpu.flags.cf)
    {
        goto L_0x00a96648;
    }
    // 00a965b9  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00a965bb  80e1f8                 -and cl, 0xf8
    cpu.cl &= x86::reg8(x86::sreg8(248 /*0xf8*/));
    // 00a965be  8b4314                 -mov eax, dword ptr [ebx + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 00a965c1  83f910                 +cmp ecx, 0x10
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a965c4  7305                   -jae 0xa965cb
    if (!cpu.flags.cf)
    {
        goto L_0x00a965cb;
    }
    // 00a965c6  b910000000             -mov ecx, 0x10
    cpu.ecx = 16 /*0x10*/;
L_0x00a965cb:
    // 00a965cb  39c1                   +cmp ecx, eax
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a965cd  0f8775000000           -ja 0xa96648
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a96648;
    }
    // 00a965d3  8b5f10                 -mov ebx, dword ptr [edi + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(16) /* 0x10 */);
    // 00a965d6  8b470c                 -mov eax, dword ptr [edi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */);
    // 00a965d9  39d9                   +cmp ecx, ebx
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a965db  7705                   -ja 0xa965e2
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a965e2;
    }
    // 00a965dd  8b4728                 -mov eax, dword ptr [edi + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(40) /* 0x28 */);
    // 00a965e0  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x00a965e2:
    // 00a965e2  8d7720                 -lea esi, [edi + 0x20]
    cpu.esi = x86::reg32(cpu.edi + x86::reg32(32) /* 0x20 */);
L_0x00a965e5:
    // 00a965e5  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00a965e7  39d1                   +cmp ecx, edx
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a965e9  7612                   -jbe 0xa965fd
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a965fd;
    }
    // 00a965eb  39da                   +cmp edx, ebx
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
    // 00a965ed  7602                   -jbe 0xa965f1
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a965f1;
    }
    // 00a965ef  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
L_0x00a965f1:
    // 00a965f1  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00a965f4  39f0                   +cmp eax, esi
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
    // 00a965f6  75ed                   -jne 0xa965e5
    if (!cpu.flags.zf)
    {
        goto L_0x00a965e5;
    }
    // 00a965f8  895f14                 -mov dword ptr [edi + 0x14], ebx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(20) /* 0x14 */) = cpu.ebx;
    // 00a965fb  eb4b                   -jmp 0xa96648
    goto L_0x00a96648;
L_0x00a965fd:
    // 00a965fd  895f10                 -mov dword ptr [edi + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 00a96600  8b5f18                 -mov ebx, dword ptr [edi + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */);
    // 00a96603  43                     -inc ebx
    (cpu.ebx)++;
    // 00a96604  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a96606  895f18                 -mov dword ptr [edi + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 00a96609  83fa10                 +cmp edx, 0x10
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a9660c  721e                   -jb 0xa9662c
    if (cpu.flags.cf)
    {
        goto L_0x00a9662c;
    }
    // 00a9660e  8d1c08                 -lea ebx, [eax + ecx]
    cpu.ebx = x86::reg32(cpu.eax + cpu.ecx * 1);
    // 00a96611  895f0c                 -mov dword ptr [edi + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 00a96614  8913                   -mov dword ptr [ebx], edx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
    // 00a96616  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 00a96618  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00a9661b  894b04                 -mov dword ptr [ebx + 4], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 00a9661e  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00a96621  895308                 -mov dword ptr [ebx + 8], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00a96624  895908                 -mov dword ptr [ecx + 8], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 00a96627  895a04                 -mov dword ptr [edx + 4], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 00a9662a  eb12                   -jmp 0xa9663e
    goto L_0x00a9663e;
L_0x00a9662c:
    // 00a9662c  ff4f1c                 -dec dword ptr [edi + 0x1c]
    (app->getMemory<x86::reg32>(cpu.edi + x86::reg32(28) /* 0x1c */))--;
    // 00a9662f  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00a96632  89570c                 -mov dword ptr [edi + 0xc], edx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00a96635  8b5808                 -mov ebx, dword ptr [eax + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00a96638  895a08                 -mov dword ptr [edx + 8], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 00a9663b  895304                 -mov dword ptr [ebx + 4], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.edx;
L_0x00a9663e:
    // 00a9663e  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 00a96640  80ca01                 -or dl, 1
    cpu.dl |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00a96643  8d6804                 -lea ebp, [eax + 4]
    cpu.ebp = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00a96646  8810                   -mov byte ptr [eax], dl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.dl;
L_0x00a96648:
    // 00a96648  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00a9664a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9664b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9664c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9664d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9664e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void sub_a96650(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a96650  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a96651  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a96652  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a96653  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a96654  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00a96656  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a96658  0f841d010000           -je 0xa9677b
    if (cpu.flags.zf)
    {
        goto L_0x00a9677b;
    }
    // 00a9665e  8d58fc                 -lea ebx, [eax - 4]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(-4) /* -0x4 */);
    // 00a96661  f60301                 +test byte ptr [ebx], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebx) & 1 /*0x1*/));
    // 00a96664  0f8411010000           -je 0xa9677b
    if (cpu.flags.zf)
    {
        goto L_0x00a9677b;
    }
    // 00a9666a  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 00a9666c  80e2fe                 -and dl, 0xfe
    cpu.dl &= x86::reg8(x86::sreg8(254 /*0xfe*/));
    // 00a9666f  8d0413                 -lea eax, [ebx + edx]
    cpu.eax = x86::reg32(cpu.ebx + cpu.edx * 1);
    // 00a96672  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00a96674  f60001                 +test byte ptr [eax], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax) & 1 /*0x1*/));
    // 00a96677  7522                   -jne 0xa9669b
    if (!cpu.flags.zf)
    {
        goto L_0x00a9669b;
    }
    // 00a96679  8b38                   -mov edi, dword ptr [eax]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax);
    // 00a9667b  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 00a9667d  8913                   -mov dword ptr [ebx], edx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
    // 00a9667f  3b410c                 +cmp eax, dword ptr [ecx + 0xc]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a96682  7503                   -jne 0xa96687
    if (!cpu.flags.zf)
    {
        goto L_0x00a96687;
    }
    // 00a96684  89590c                 -mov dword ptr [ecx + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.ebx;
L_0x00a96687:
    // 00a96687  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00a9668a  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00a9668d  894208                 -mov dword ptr [edx + 8], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00a96690  895004                 -mov dword ptr [eax + 4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00a96693  ff4e1c                 +dec dword ptr [esi + 0x1c]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a96696  e994000000             -jmp 0xa9672f
    goto L_0x00a9672f;
L_0x00a9669b:
    // 00a9669b  8913                   -mov dword ptr [ebx], edx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
    // 00a9669d  8b410c                 -mov eax, dword ptr [ecx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00a966a0  39c3                   +cmp ebx, eax
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a966a2  7316                   -jae 0xa966ba
    if (!cpu.flags.cf)
    {
        goto L_0x00a966ba;
    }
    // 00a966a4  3b5804                 +cmp ebx, dword ptr [eax + 4]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a966a7  0f8782000000           -ja 0xa9672f
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a9672f;
    }
    // 00a966ad  8b4128                 -mov eax, dword ptr [ecx + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */);
    // 00a966b0  39c3                   +cmp ebx, eax
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a966b2  0f8277000000           -jb 0xa9672f
    if (cpu.flags.cf)
    {
        goto L_0x00a9672f;
    }
    // 00a966b8  eb19                   -jmp 0xa966d3
    goto L_0x00a966d3;
L_0x00a966ba:
    // 00a966ba  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00a966bd  39c3                   +cmp ebx, eax
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a966bf  0f826a000000           -jb 0xa9672f
    if (cpu.flags.cf)
    {
        goto L_0x00a9672f;
    }
    // 00a966c5  8d4120                 -lea eax, [ecx + 0x20]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 00a966c8  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00a966cb  39d3                   +cmp ebx, edx
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a966cd  0f875c000000           -ja 0xa9672f
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a9672f;
    }
L_0x00a966d3:
    // 00a966d3  8b7e1c                 -mov edi, dword ptr [esi + 0x1c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 00a966d6  8b4618                 -mov eax, dword ptr [esi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 00a966d9  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a966db  8d4f01                 -lea ecx, [edi + 1]
    cpu.ecx = x86::reg32(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 00a966de  f7f1                   -div ecx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ecx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 00a966e0  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a966e2  39f8                   +cmp eax, edi
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
    // 00a966e4  7328                   -jae 0xa9670e
    if (!cpu.flags.cf)
    {
        goto L_0x00a9670e;
    }
    // 00a966e6  8b4618                 -mov eax, dword ptr [esi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 00a966e9  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 00a966eb  01c9                   -add ecx, ecx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00a966ed  39f8                   +cmp eax, edi
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
    // 00a966ef  7705                   -ja 0xa966f6
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a966f6;
    }
    // 00a966f1  b9ffffffff             -mov ecx, 0xffffffff
    cpu.ecx = 4294967295 /*0xffffffff*/;
L_0x00a966f6:
    // 00a966f6  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 00a966f8  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
L_0x00a966fa:
    // 00a966fa  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00a966fc  f6c201                 +test dl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 1 /*0x1*/));
    // 00a966ff  742e                   -je 0xa9672f
    if (cpu.flags.zf)
    {
        goto L_0x00a9672f;
    }
    // 00a96701  83faff                 +cmp edx, -1
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
    // 00a96704  7408                   -je 0xa9670e
    if (cpu.flags.zf)
    {
        goto L_0x00a9670e;
    }
    // 00a96706  80e2fe                 -and dl, 0xfe
    cpu.dl &= x86::reg8(x86::sreg8(254 /*0xfe*/));
    // 00a96709  01d0                   +add eax, edx
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a9670b  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a9670c  75ec                   -jne 0xa966fa
    if (!cpu.flags.zf)
    {
        goto L_0x00a966fa;
    }
L_0x00a9670e:
    // 00a9670e  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 00a96711  39c3                   +cmp ebx, eax
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a96713  7303                   -jae 0xa96718
    if (!cpu.flags.cf)
    {
        goto L_0x00a96718;
    }
    // 00a96715  8b4628                 -mov eax, dword ptr [esi + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
L_0x00a96718:
    // 00a96718  39c3                   +cmp ebx, eax
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a9671a  7213                   -jb 0xa9672f
    if (cpu.flags.cf)
    {
        goto L_0x00a9672f;
    }
    // 00a9671c  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00a9671f  39c3                   +cmp ebx, eax
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a96721  720c                   -jb 0xa9672f
    if (cpu.flags.cf)
    {
        goto L_0x00a9672f;
    }
    // 00a96723  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00a96726  39c3                   +cmp ebx, eax
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a96728  7205                   -jb 0xa9672f
    if (cpu.flags.cf)
    {
        goto L_0x00a9672f;
    }
    // 00a9672a  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00a9672d  ebe9                   -jmp 0xa96718
    goto L_0x00a96718;
L_0x00a9672f:
    // 00a9672f  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00a96732  8b3a                   -mov edi, dword ptr [edx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx);
    // 00a96734  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 00a96736  8b0b                   -mov ecx, dword ptr [ebx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx);
    // 00a96738  39df                   +cmp edi, ebx
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a9673a  7512                   -jne 0xa9674e
    if (!cpu.flags.zf)
    {
        goto L_0x00a9674e;
    }
    // 00a9673c  8b2a                   -mov ebp, dword ptr [edx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx);
    // 00a9673e  01e9                   -add ecx, ebp
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00a96740  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 00a96742  3b5e0c                 +cmp ebx, dword ptr [esi + 0xc]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a96745  7503                   -jne 0xa9674a
    if (!cpu.flags.zf)
    {
        goto L_0x00a9674a;
    }
    // 00a96747  89560c                 -mov dword ptr [esi + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.edx;
L_0x00a9674a:
    // 00a9674a  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00a9674c  eb0f                   -jmp 0xa9675d
    goto L_0x00a9675d;
L_0x00a9674e:
    // 00a9674e  ff461c                 -inc dword ptr [esi + 0x1c]
    (app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */))++;
    // 00a96751  894308                 -mov dword ptr [ebx + 8], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00a96754  895304                 -mov dword ptr [ebx + 4], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00a96757  895a08                 -mov dword ptr [edx + 8], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 00a9675a  895804                 -mov dword ptr [eax + 4], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ebx;
L_0x00a9675d:
    // 00a9675d  8b5618                 -mov edx, dword ptr [esi + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 00a96760  4a                     -dec edx
    (cpu.edx)--;
    // 00a96761  8b7e0c                 -mov edi, dword ptr [esi + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 00a96764  895618                 -mov dword ptr [esi + 0x18], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 00a96767  39fb                   +cmp ebx, edi
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a96769  7308                   -jae 0xa96773
    if (!cpu.flags.cf)
    {
        goto L_0x00a96773;
    }
    // 00a9676b  3b4e10                 +cmp ecx, dword ptr [esi + 0x10]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a9676e  7603                   -jbe 0xa96773
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a96773;
    }
    // 00a96770  894e10                 -mov dword ptr [esi + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.ecx;
L_0x00a96773:
    // 00a96773  3b4e14                 +cmp ecx, dword ptr [esi + 0x14]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a96776  7603                   -jbe 0xa9677b
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a9677b;
    }
    // 00a96778  894e14                 -mov dword ptr [esi + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.ecx;
L_0x00a9677b:
    // 00a9677b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9677c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9677d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9677e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9677f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a96780(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a96780  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a96781  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a96782  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a96784  a178e1a900             -mov eax, dword ptr [0xa9e178]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11133304) /* 0xa9e178 */);
    // 00a96789  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a9678b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a9678d  740d                   -je 0xa9679c
    if (cpu.flags.zf)
    {
        goto L_0x00a9679c;
    }
L_0x00a9678f:
    // 00a9678f  39c2                   +cmp edx, eax
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
    // 00a96791  7209                   -jb 0xa9679c
    if (cpu.flags.cf)
    {
        goto L_0x00a9679c;
    }
    // 00a96793  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a96795  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00a96798  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a9679a  75f3                   -jne 0xa9678f
    if (!cpu.flags.zf)
    {
        goto L_0x00a9678f;
    }
L_0x00a9679c:
    // 00a9679c  895a04                 -mov dword ptr [edx + 4], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 00a9679f  894208                 -mov dword ptr [edx + 8], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00a967a2  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a967a4  7405                   -je 0xa967ab
    if (cpu.flags.zf)
    {
        goto L_0x00a967ab;
    }
    // 00a967a6  895308                 -mov dword ptr [ebx + 8], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00a967a9  eb06                   -jmp 0xa967b1
    goto L_0x00a967b1;
L_0x00a967ab:
    // 00a967ab  891578e1a900           -mov dword ptr [0xa9e178], edx
    app->getMemory<x86::reg32>(x86::reg32(11133304) /* 0xa9e178 */) = cpu.edx;
L_0x00a967b1:
    // 00a967b1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a967b3  7403                   -je 0xa967b8
    if (cpu.flags.zf)
    {
        goto L_0x00a967b8;
    }
    // 00a967b5  895004                 -mov dword ptr [eax + 4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
L_0x00a967b8:
    // 00a967b8  8d5a20                 -lea ebx, [edx + 0x20]
    cpu.ebx = x86::reg32(cpu.edx + x86::reg32(32) /* 0x20 */);
    // 00a967bb  83c22c                 -add edx, 0x2c
    (cpu.edx) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00a967be  c742f400000000         -mov dword ptr [edx - 0xc], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-12) /* -0xc */) = 0 /*0x0*/;
    // 00a967c5  c742e400000000         -mov dword ptr [edx - 0x1c], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-28) /* -0x1c */) = 0 /*0x0*/;
    // 00a967cc  c742ec00000000         -mov dword ptr [edx - 0x14], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-20) /* -0x14 */) = 0 /*0x0*/;
    // 00a967d3  c742f000000000         -mov dword ptr [edx - 0x10], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-16) /* -0x10 */) = 0 /*0x0*/;
    // 00a967da  895af8                 -mov dword ptr [edx - 8], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-8) /* -0x8 */) = cpu.ebx;
    // 00a967dd  8b42d4                 -mov eax, dword ptr [edx - 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-44) /* -0x2c */);
    // 00a967e0  895afc                 -mov dword ptr [edx - 4], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */) = cpu.ebx;
    // 00a967e3  83e82c                 -sub eax, 0x2c
    (cpu.eax) -= x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00a967e6  895ae0                 -mov dword ptr [edx - 0x20], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-32) /* -0x20 */) = cpu.ebx;
    // 00a967e9  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 00a967eb  c70402ffffffff         -mov dword ptr [edx + eax], 0xffffffff
    app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 1) = 4294967295 /*0xffffffff*/;
    // 00a967f2  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a967f4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a967f5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a967f6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void sub_a967f8(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a967f8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a967f9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a967fa  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a967fb  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a967fc  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a967fd  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a96800  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00a96803  833d3ce4a90000         +cmp dword ptr [0xa9e43c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(11134012) /* 0xa9e43c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a9680a  7507                   -jne 0xa96813
    if (!cpu.flags.zf)
    {
        goto L_0x00a96813;
    }
    // 00a9680c  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a9680e  e998000000             -jmp 0xa968ab
    goto L_0x00a968ab;
L_0x00a96813:
    // 00a96813  833d28e3a900fe         +cmp dword ptr [0xa9e328], -2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(11133736) /* 0xa9e328 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-2 /*-0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a9681a  750b                   -jne 0xa96827
    if (!cpu.flags.zf)
    {
        goto L_0x00a96827;
    }
    // 00a9681c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a9681e  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a96821  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a96822  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a96823  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a96824  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a96825  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a96826  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a96827:
    // 00a96827  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a96829  e89a000000             -call 0xa968c8
    cpu.esp -= 4;
    sub_a968c8(app, cpu);
    if (cpu.terminate) return;
    // 00a9682e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a96830  0f8475000000           -je 0xa968ab
    if (cpu.flags.zf)
    {
        goto L_0x00a968ab;
    }
    // 00a96836  6a40                   -push 0x40
    app->getMemory<x86::reg32>(cpu.esp-4) = 64 /*0x40*/;
    cpu.esp -= 4;
    // 00a96838  6800100000             -push 0x1000
    app->getMemory<x86::reg32>(cpu.esp-4) = 4096 /*0x1000*/;
    cpu.esp -= 4;
    // 00a9683d  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00a96841  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a96842  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a96844  2eff1554cea900         -call dword ptr cs:[0xa9ce54]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11128404) /* 0xa9ce54 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a9684b  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a9684d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a9684f  745a                   -je 0xa968ab
    if (cpu.flags.zf)
    {
        goto L_0x00a968ab;
    }
    // 00a96851  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00a96854  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    // 00a96857  83e804                 -sub eax, 4
    (cpu.eax) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a9685a  39f0                   +cmp eax, esi
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
    // 00a9685c  760b                   -jbe 0xa96869
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a96869;
    }
    // 00a9685e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a96860  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a96863  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a96864  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a96865  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a96866  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a96867  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a96868  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a96869:
    // 00a96869  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00a9686c  83f838                 +cmp eax, 0x38
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(56 /*0x38*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a9686f  730b                   -jae 0xa9687c
    if (!cpu.flags.cf)
    {
        goto L_0x00a9687c;
    }
    // 00a96871  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a96873  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a96876  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a96877  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a96878  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a96879  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9687a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9687b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a9687c:
    // 00a9687c  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 00a9687e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a96880  e8fbfeffff             -call 0xa96780
    cpu.esp -= 4;
    sub_a96780(app, cpu);
    if (cpu.terminate) return;
    // 00a96885  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a96887  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00a96889  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00a9688c  0c01                   -or al, 1
    cpu.al |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00a9688e  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 00a96890  8b7a18                 -mov edi, dword ptr [edx + 0x18]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 00a96893  c7421400000000         -mov dword ptr [edx + 0x14], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */) = 0 /*0x0*/;
    // 00a9689a  47                     -inc edi
    (cpu.edi)++;
    // 00a9689b  8d4304                 -lea eax, [ebx + 4]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 00a9689e  897a18                 -mov dword ptr [edx + 0x18], edi
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */) = cpu.edi;
    // 00a968a1  e8cae4ffff             -call 0xa94d70
    cpu.esp -= 4;
    sub_a94d70(app, cpu);
    if (cpu.terminate) return;
    // 00a968a6  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x00a968ab:
    // 00a968ab  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a968ae  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a968af  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a968b0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a968b1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a968b2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a968b3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a968b4(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a968b4  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a968b5  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a968b7  e8641d0000             -call 0xa98620
    cpu.esp -= 4;
    sub_a98620(app, cpu);
    if (cpu.terminate) return;
    // 00a968bc  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a968be  e835ffffff             -call 0xa967f8
    cpu.esp -= 4;
    sub_a967f8(app, cpu);
    if (cpu.terminate) return;
    // 00a968c3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a968c4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_a968c8(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a968c8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a968c9  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a968ca  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a968cc  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00a968ce  83c007                 -add eax, 7
    (cpu.eax) += x86::reg32(x86::sreg32(7 /*0x7*/));
    // 00a968d1  24f8                   -and al, 0xf8
    cpu.al &= x86::reg8(x86::sreg8(248 /*0xf8*/));
    // 00a968d3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a968d5  743d                   -je 0xa96914
    if (cpu.flags.zf)
    {
        goto L_0x00a96914;
    }
    // 00a968d7  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 00a968d9  83c03c                 -add eax, 0x3c
    (cpu.eax) += x86::reg32(x86::sreg32(60 /*0x3c*/));
    // 00a968dc  3b02                   +cmp eax, dword ptr [edx]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a968de  7305                   -jae 0xa968e5
    if (!cpu.flags.cf)
    {
        goto L_0x00a968e5;
    }
    // 00a968e0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a968e2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a968e3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a968e4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a968e5:
    // 00a968e5  8b0d40e4a900           -mov ecx, dword ptr [0xa9e440]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11134016) /* 0xa9e440 */);
    // 00a968eb  39c8                   +cmp eax, ecx
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
    // 00a968ed  7304                   -jae 0xa968f3
    if (!cpu.flags.cf)
    {
        goto L_0x00a968f3;
    }
    // 00a968ef  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a968f1  24fe                   -and al, 0xfe
    cpu.al &= x86::reg8(x86::sreg8(254 /*0xfe*/));
L_0x00a968f3:
    // 00a968f3  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 00a968f5  05ff0f0000             -add eax, 0xfff
    (cpu.eax) += x86::reg32(x86::sreg32(4095 /*0xfff*/));
    // 00a968fa  3b02                   +cmp eax, dword ptr [edx]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a968fc  7305                   -jae 0xa96903
    if (!cpu.flags.cf)
    {
        goto L_0x00a96903;
    }
    // 00a968fe  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a96900  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a96901  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a96902  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a96903:
    // 00a96903  30c0                   -xor al, al
    cpu.al ^= x86::reg8(x86::sreg8(cpu.al));
    // 00a96905  80e4f0                 -and ah, 0xf0
    cpu.ah &= x86::reg8(x86::sreg8(240 /*0xf0*/));
    // 00a96908  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 00a9690a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a9690c  0f95c0                 -setne al
    cpu.al = !cpu.flags.zf;
    // 00a9690f  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
L_0x00a96914:
    // 00a96914  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a96915  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a96916  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a96920(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a96920  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a96922  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a96930(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a96930  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a96931  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a96932  baf086a900             -mov edx, 0xa986f0
    cpu.edx = 11110128 /*0xa986f0*/;
    // 00a96937  bb0488a900             -mov ebx, 0xa98804
    cpu.ebx = 11110404 /*0xa98804*/;
    // 00a9693c  8915e4e3a900           -mov dword ptr [0xa9e3e4], edx
    app->getMemory<x86::reg32>(x86::reg32(11133924) /* 0xa9e3e4 */) = cpu.edx;
    // 00a96942  891de8e3a900           -mov dword ptr [0xa9e3e8], ebx
    app->getMemory<x86::reg32>(x86::reg32(11133928) /* 0xa9e3e8 */) = cpu.ebx;
    // 00a96948  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a96949  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9694a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void sub_a96950(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a96950  9b                     -wait 
    /*nothing*/;
    // 00a96951  dd30                   -fnsave dword ptr [eax]
    NFS2_ASSERT(false);
    // 00a96953  9b                     -wait 
    /*nothing*/;
    // 00a96954  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_a96958(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a96958  dd20                   -frstor dword ptr [eax]
    NFS2_ASSERT(false);
    // 00a9695a  9b                     -wait 
    /*nothing*/;
    // 00a9695b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a9695c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9695c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a9695d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a9695e  803d89e1a90000         +cmp byte ptr [0xa9e189], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(11133321) /* 0xa9e189 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a96965  7416                   -je 0xa9697d
    if (cpu.flags.zf)
    {
        goto L_0x00a9697d;
    }
    // 00a96967  ba5069a900             -mov edx, 0xa96950
    cpu.edx = 11102544 /*0xa96950*/;
    // 00a9696c  bb5869a900             -mov ebx, 0xa96958
    cpu.ebx = 11102552 /*0xa96958*/;
    // 00a96971  891544e4a900           -mov dword ptr [0xa9e444], edx
    app->getMemory<x86::reg32>(x86::reg32(11134020) /* 0xa9e444 */) = cpu.edx;
    // 00a96977  891d48e4a900           -mov dword ptr [0xa9e448], ebx
    app->getMemory<x86::reg32>(x86::reg32(11134024) /* 0xa9e448 */) = cpu.ebx;
L_0x00a9697d:
    // 00a9697d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a9697f  66a14ce4a900           -mov ax, word ptr [0xa9e44c]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(11134028) /* 0xa9e44c */);
    // 00a96985  e8a61e0000             -call 0xa98830
    cpu.esp -= 4;
    sub_a98830(app, cpu);
    if (cpu.terminate) return;
    // 00a9698a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9698b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9698c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_a96990(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a96990  803d89e1a90000         +cmp byte ptr [0xa9e189], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(11133321) /* 0xa9e189 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a96997  75c3                   -jne 0xa9695c
    if (!cpu.flags.zf)
    {
        return sub_a9695c(app, cpu);
    }
    // 00a96999  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void sub_a9699c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9699c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a9699d  8a2588e1a900           -mov ah, byte ptr [0xa9e188]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(11133320) /* 0xa9e188 */);
    // 00a969a3  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 00a969a5  7537                   -jne 0xa969de
    if (!cpu.flags.zf)
    {
        goto L_0x00a969de;
    }
    // 00a969a7  882589e1a900           -mov byte ptr [0xa9e189], ah
    app->getMemory<x86::reg8>(x86::reg32(11133321) /* 0xa9e189 */) = cpu.ah;
    // 00a969ad  30f6                   -xor dh, dh
    cpu.dh ^= x86::reg8(x86::sreg8(cpu.dh));
    // 00a969af  2bc0                   -sub eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00a969b1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a969b2  dbe3                   -fninit 
    cpu.fpu.init();
    // 00a969b4  d93c24                 -fnstcw word ptr [esp]
    app->getMemory<x86::reg16>(cpu.esp) = cpu.fpu.control.word;
    // 00a969b7  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a969b8  8ac4                   -mov al, ah
    cpu.al = cpu.ah;
    // 00a969ba  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 00a969bc  3c03                   +cmp al, 3
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(3 /*0x3*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a969be  7509                   -jne 0xa969c9
    if (!cpu.flags.zf)
    {
        goto L_0x00a969c9;
    }
    // 00a969c0  e897ffffff             -call 0xa9695c
    cpu.esp -= 4;
    sub_a9695c(app, cpu);
    if (cpu.terminate) return;
    // 00a969c5  88c6                   -mov dh, al
    cpu.dh = cpu.al;
    // 00a969c7  88c2                   -mov dl, al
    cpu.dl = cpu.al;
L_0x00a969c9:
    // 00a969c9  803d64e3a90000         +cmp byte ptr [0xa9e364], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(11133796) /* 0xa9e364 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a969d0  750c                   -jne 0xa969de
    if (!cpu.flags.zf)
    {
        goto L_0x00a969de;
    }
    // 00a969d2  883588e1a900           -mov byte ptr [0xa9e188], dh
    app->getMemory<x86::reg8>(x86::reg32(11133320) /* 0xa9e188 */) = cpu.dh;
    // 00a969d8  881589e1a900           -mov byte ptr [0xa9e189], dl
    app->getMemory<x86::reg8>(x86::reg32(11133321) /* 0xa9e189 */) = cpu.dl;
L_0x00a969de:
    // 00a969de  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a969df  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a969e0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a969e0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a96a00(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 00a96a00  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a96a01  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a96a02  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a96a03  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a96a04  8b742414               -mov esi, dword ptr [esp + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00a96a08  8b7c2418               -mov edi, dword ptr [esp + 0x18]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00a96a0c  8b6c241c               -mov ebp, dword ptr [esp + 0x1c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00a96a10  83ff03                 +cmp edi, 3
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a96a13  0f8777010000           -ja 0xa96b90
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a96b90;
    }
    // 00a96a19  2eff24bdf069a900       -jmp dword ptr cs:[edi*4 + 0xa969f0]
    cpu.ip = app->getMemory<x86::reg32>(11102704 + cpu.edi * 4); goto dynamic_jump;
  case 0x00a96a21:
    // 00a96a21  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a96a23  e8b0100000             -call 0xa97ad8
    cpu.esp -= 4;
    sub_a97ad8(app, cpu);
    if (cpu.terminate) return;
    // 00a96a28  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a96a2a  0f8462010000           -je 0xa96b92
    if (cpu.flags.zf)
    {
        goto L_0x00a96b92;
    }
    // 00a96a30  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a96a31  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a96a32  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a96a33  e868e0ffff             -call 0xa94aa0
    cpu.esp -= 4;
    sub_a94aa0(app, cpu);
    if (cpu.terminate) return;
    // 00a96a38  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a96a3a  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a96a3c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a96a3d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a96a3e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a96a3f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a96a40  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
  case 0x00a96a43:
    // 00a96a43  8b155016aa00           -mov edx, dword ptr [0xaa1650]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11146832) /* 0xaa1650 */);
    // 00a96a49  42                     -inc edx
    (cpu.edx)++;
    // 00a96a4a  89155016aa00           -mov dword ptr [0xaa1650], edx
    app->getMemory<x86::reg32>(x86::reg32(11146832) /* 0xaa1650 */) = cpu.edx;
    // 00a96a50  83fa01                 +cmp edx, 1
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
    // 00a96a53  7e16                   -jle 0xa96a6b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a96a6b;
    }
    // 00a96a55  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a96a57  e8041e0000             -call 0xa98860
    cpu.esp -= 4;
    sub_a98860(app, cpu);
    if (cpu.terminate) return;
    // 00a96a5c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a96a5e  740b                   -je 0xa96a6b
    if (cpu.flags.zf)
    {
        goto L_0x00a96a6b;
    }
    // 00a96a60  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a96a62  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a96a64  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a96a65  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a96a66  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a96a67  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a96a68  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x00a96a6b:
    // 00a96a6b  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a96a70  e857ecffff             -call 0xa956cc
    cpu.esp -= 4;
    sub_a956cc(app, cpu);
    if (cpu.terminate) return;
    // 00a96a75  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00a96a77  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a96a79  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a96a7e  e835e9ffff             -call 0xa953b8
    cpu.esp -= 4;
    sub_a953b8(app, cpu);
    if (cpu.terminate) return;
    // 00a96a83  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a96a85  750b                   -jne 0xa96a92
    if (!cpu.flags.zf)
    {
        goto L_0x00a96a92;
    }
    // 00a96a87  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a96a89  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a96a8b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a96a8c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a96a8d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a96a8e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a96a8f  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x00a96a92:
    // 00a96a92  e8e10f0000             -call 0xa97a78
    cpu.esp -= 4;
    sub_a97a78(app, cpu);
    if (cpu.terminate) return;
    // 00a96a97  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a96a99  750b                   -jne 0xa96aa6
    if (!cpu.flags.zf)
    {
        goto L_0x00a96aa6;
    }
    // 00a96a9b  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a96a9d  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a96a9f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a96aa0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a96aa1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a96aa2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a96aa3  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x00a96aa6:
    // 00a96aa6  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a96aa8  e82b100000             -call 0xa97ad8
    cpu.esp -= 4;
    sub_a97ad8(app, cpu);
    if (cpu.terminate) return;
    // 00a96aad  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a96aaf  750b                   -jne 0xa96abc
    if (!cpu.flags.zf)
    {
        goto L_0x00a96abc;
    }
    // 00a96ab1  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a96ab3  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a96ab5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a96ab6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a96ab7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a96ab8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a96ab9  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x00a96abc:
    // 00a96abc  b80f000000             -mov eax, 0xf
    cpu.eax = 15 /*0xf*/;
    // 00a96ac1  e806ecffff             -call 0xa956cc
    cpu.esp -= 4;
    sub_a956cc(app, cpu);
    if (cpu.terminate) return;
    // 00a96ac6  e8e9100000             -call 0xa97bb4
    cpu.esp -= 4;
    sub_a97bb4(app, cpu);
    if (cpu.terminate) return;
    // 00a96acb  833d50e4a90000         +cmp dword ptr [0xa9e450], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(11134032) /* 0xa9e450 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a96ad2  7422                   -je 0xa96af6
    if (cpu.flags.zf)
    {
        goto L_0x00a96af6;
    }
    // 00a96ad4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a96ad5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a96ad6  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a96ad7  ff1550e4a900           -call dword ptr [0xa9e450]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11134032) /* 0xa9e450 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a96add  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a96adf  7515                   -jne 0xa96af6
    if (!cpu.flags.zf)
    {
        goto L_0x00a96af6;
    }
    // 00a96ae1  ba0f000000             -mov edx, 0xf
    cpu.edx = 15 /*0xf*/;
    // 00a96ae6  e831ecffff             -call 0xa9571c
    cpu.esp -= 4;
    sub_a9571c(app, cpu);
    if (cpu.terminate) return;
    // 00a96aeb  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a96aed  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a96aef  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a96af0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a96af1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a96af2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a96af3  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x00a96af6:
    // 00a96af6  b8ff000000             -mov eax, 0xff
    cpu.eax = 255 /*0xff*/;
    // 00a96afb  e8ccebffff             -call 0xa956cc
    cpu.esp -= 4;
    sub_a956cc(app, cpu);
    if (cpu.terminate) return;
    // 00a96b00  e83b1e0000             -call 0xa98940
    cpu.esp -= 4;
    sub_a98940(app, cpu);
    if (cpu.terminate) return;
    // 00a96b05  ff15d4e2a900           -call dword ptr [0xa9e2d4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11133652) /* 0xa9e2d4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a96b0b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a96b0c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a96b0d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a96b0e  e88ddfffff             -call 0xa94aa0
    cpu.esp -= 4;
    sub_a94aa0(app, cpu);
    if (cpu.terminate) return;
    // 00a96b13  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a96b15  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a96b17  7577                   -jne 0xa96b90
    if (!cpu.flags.zf)
    {
        goto L_0x00a96b90;
    }
    // 00a96b19  baff000000             -mov edx, 0xff
    cpu.edx = 255 /*0xff*/;
    // 00a96b1e  e8f9ebffff             -call 0xa9571c
    cpu.esp -= 4;
    sub_a9571c(app, cpu);
    if (cpu.terminate) return;
    // 00a96b23  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a96b25  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a96b26  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a96b27  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a96b28  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a96b29  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
  case 0x00a96b2c:
    // 00a96b2c  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a96b2d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a96b2e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a96b2f  e86cdfffff             -call 0xa94aa0
    cpu.esp -= 4;
    sub_a94aa0(app, cpu);
    if (cpu.terminate) return;
    // 00a96b34  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a96b36  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a96b3b  e8ec0f0000             -call 0xa97b2c
    cpu.esp -= 4;
    sub_a97b2c(app, cpu);
    if (cpu.terminate) return;
    // 00a96b40  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a96b42  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a96b43  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a96b44  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a96b45  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a96b46  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
  case 0x00a96b49:
    // 00a96b49  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a96b4a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a96b4b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a96b4c  e84fdfffff             -call 0xa94aa0
    cpu.esp -= 4;
    sub_a94aa0(app, cpu);
    if (cpu.terminate) return;
    // 00a96b51  baff000000             -mov edx, 0xff
    cpu.edx = 255 /*0xff*/;
    // 00a96b56  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a96b58  b810000000             -mov eax, 0x10
    cpu.eax = 16 /*0x10*/;
    // 00a96b5d  e8baebffff             -call 0xa9571c
    cpu.esp -= 4;
    sub_a9571c(app, cpu);
    if (cpu.terminate) return;
    // 00a96b62  833d50e4a90000         +cmp dword ptr [0xa9e450], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(11134032) /* 0xa9e450 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a96b69  7409                   -je 0xa96b74
    if (cpu.flags.zf)
    {
        goto L_0x00a96b74;
    }
    // 00a96b6b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a96b6c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a96b6d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a96b6e  ff1550e4a900           -call dword ptr [0xa9e450]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11134032) /* 0xa9e450 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00a96b74:
    // 00a96b74  ba0f000000             -mov edx, 0xf
    cpu.edx = 15 /*0xf*/;
    // 00a96b79  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a96b7b  e89cebffff             -call 0xa9571c
    cpu.esp -= 4;
    sub_a9571c(app, cpu);
    if (cpu.terminate) return;
    // 00a96b80  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a96b85  e8a20f0000             -call 0xa97b2c
    cpu.esp -= 4;
    sub_a97b2c(app, cpu);
    if (cpu.terminate) return;
    // 00a96b8a  ff0d5016aa00           -dec dword ptr [0xaa1650]
    (app->getMemory<x86::reg32>(x86::reg32(11146832) /* 0xaa1650 */))--;
L_0x00a96b90:
    // 00a96b90  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x00a96b92:
    // 00a96b92  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a96b93  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a96b94  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a96b95  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a96b96  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
  default:
    return app->dynamic_call(cpu.ip, cpu);
  }
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a96ba0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a96ba0  e9dbe0ffff             -jmp 0xa94c80
    return sub_a94c80(app, cpu);
}

/* align: skip 0x8d 0x40 0x00 */
void sub_a96ba8(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a96ba8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a96ba9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a96baa  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a96bab  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a96bac  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a96bad  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a96bae  8b3d0410aa00           -mov edi, dword ptr [0xaa1004]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(11145220) /* 0xaa1004 */);
    // 00a96bb4  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00a96bb6  0f85c1000000           -jne 0xa96c7d
    if (!cpu.flags.zf)
    {
        goto L_0x00a96c7d;
    }
    // 00a96bbc  8b2d69e3a900           -mov ebp, dword ptr [0xa9e369]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(11133801) /* 0xa9e369 */);
    // 00a96bc2  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a96bc4  8a5500                 -mov dl, byte ptr [ebp]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebp);
    // 00a96bc7  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00a96bc9  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 00a96bcb  7416                   -je 0xa96be3
    if (cpu.flags.zf)
    {
        goto L_0x00a96be3;
    }
L_0x00a96bcd:
    // 00a96bcd  8a30                   -mov dh, byte ptr [eax]
    cpu.dh = app->getMemory<x86::reg8>(cpu.eax);
    // 00a96bcf  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a96bd2  84f6                   +test dh, dh
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & cpu.dh));
    // 00a96bd4  7404                   -je 0xa96bda
    if (cpu.flags.zf)
    {
        goto L_0x00a96bda;
    }
    // 00a96bd6  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a96bd8  ebf3                   -jmp 0xa96bcd
    goto L_0x00a96bcd;
L_0x00a96bda:
    // 00a96bda  41                     -inc ecx
    (cpu.ecx)++;
    // 00a96bdb  8a33                   -mov dh, byte ptr [ebx]
    cpu.dh = app->getMemory<x86::reg8>(cpu.ebx);
    // 00a96bdd  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a96bdf  84f6                   +test dh, dh
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & cpu.dh));
    // 00a96be1  75ea                   -jne 0xa96bcd
    if (!cpu.flags.zf)
    {
        goto L_0x00a96bcd;
    }
L_0x00a96be3:
    // 00a96be3  893d0410aa00           -mov dword ptr [0xaa1004], edi
    app->getMemory<x86::reg32>(x86::reg32(11145220) /* 0xaa1004 */) = cpu.edi;
    // 00a96be9  29e8                   +sub eax, ebp
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a96beb  7505                   -jne 0xa96bf2
    if (!cpu.flags.zf)
    {
        goto L_0x00a96bf2;
    }
    // 00a96bed  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x00a96bf2:
    // 00a96bf2  e889e0ffff             -call 0xa94c80
    cpu.esp -= 4;
    sub_a94c80(app, cpu);
    if (cpu.terminate) return;
    // 00a96bf7  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a96bf9  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a96bfb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a96bfd  0f8475000000           -je 0xa96c78
    if (cpu.flags.zf)
    {
        goto L_0x00a96c78;
    }
    // 00a96c03  a36016aa00             -mov dword ptr [0xaa1660], eax
    app->getMemory<x86::reg32>(x86::reg32(11146848) /* 0xaa1660 */) = cpu.eax;
    // 00a96c08  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 00a96c0f  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a96c12  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00a96c14  e867e0ffff             -call 0xa94c80
    cpu.esp -= 4;
    sub_a94c80(app, cpu);
    if (cpu.terminate) return;
    // 00a96c19  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a96c1b  7454                   -je 0xa96c71
    if (cpu.flags.zf)
    {
        goto L_0x00a96c71;
    }
    // 00a96c1d  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a96c1f  8a5500                 -mov dl, byte ptr [ebp]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebp);
    // 00a96c22  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00a96c24  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a96c26  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00a96c28  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 00a96c2a  741a                   -je 0xa96c46
    if (cpu.flags.zf)
    {
        goto L_0x00a96c46;
    }
L_0x00a96c2c:
    // 00a96c2c  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00a96c2e  891c11                 -mov dword ptr [ecx + edx], ebx
    app->getMemory<x86::reg32>(cpu.ecx + cpu.edx * 1) = cpu.ebx;
L_0x00a96c31:
    // 00a96c31  43                     -inc ebx
    (cpu.ebx)++;
    // 00a96c32  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 00a96c34  40                     -inc eax
    (cpu.eax)++;
    // 00a96c35  8853ff                 -mov byte ptr [ebx - 1], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(-1) /* -0x1 */) = cpu.dl;
    // 00a96c38  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 00a96c3a  75f5                   -jne 0xa96c31
    if (!cpu.flags.zf)
    {
        goto L_0x00a96c31;
    }
    // 00a96c3c  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a96c3f  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 00a96c41  46                     -inc esi
    (cpu.esi)++;
    // 00a96c42  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 00a96c44  75e6                   -jne 0xa96c2c
    if (!cpu.flags.zf)
    {
        goto L_0x00a96c2c;
    }
L_0x00a96c46:
    // 00a96c46  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a96c48  c7040100000000         -mov dword ptr [ecx + eax], 0
    app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 1) = 0 /*0x0*/;
    // 00a96c4f  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a96c52  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00a96c54  8d040f                 -lea eax, [edi + ecx]
    cpu.eax = x86::reg32(cpu.edi + cpu.ecx * 1);
    // 00a96c57  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00a96c59  a30010aa00             -mov dword ptr [0xaa1000], eax
    app->getMemory<x86::reg32>(x86::reg32(11145216) /* 0xaa1000 */) = cpu.eax;
    // 00a96c5e  893d0410aa00           -mov dword ptr [0xaa1004], edi
    app->getMemory<x86::reg32>(x86::reg32(11145220) /* 0xaa1004 */) = cpu.edi;
    // 00a96c64  e807dfffff             -call 0xa94b70
    cpu.esp -= 4;
    sub_a94b70(app, cpu);
    if (cpu.terminate) return;
    // 00a96c69  8b3d0410aa00           -mov edi, dword ptr [0xaa1004]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(11145220) /* 0xaa1004 */);
    // 00a96c6f  eb07                   -jmp 0xa96c78
    goto L_0x00a96c78;
L_0x00a96c71:
    // 00a96c71  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a96c73  e8f8e0ffff             -call 0xa94d70
    cpu.esp -= 4;
    sub_a94d70(app, cpu);
    if (cpu.terminate) return;
L_0x00a96c78:
    // 00a96c78  e8d31c0000             -call 0xa98950
    cpu.esp -= 4;
    sub_a98950(app, cpu);
    if (cpu.terminate) return;
L_0x00a96c7d:
    // 00a96c7d  8b3d0410aa00           -mov edi, dword ptr [0xaa1004]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(11145220) /* 0xaa1004 */);
    // 00a96c83  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a96c84  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a96c85  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a96c86  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a96c87  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a96c88  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a96c89  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void sub_a96c8c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a96c8c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a96c8d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a96c8e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a96c8f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a96c90  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a96c91  e8da1d0000             -call 0xa98a70
    cpu.esp -= 4;
    sub_a98a70(app, cpu);
    if (cpu.terminate) return;
    // 00a96c96  8b150410aa00           -mov edx, dword ptr [0xaa1004]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11145220) /* 0xaa1004 */);
    // 00a96c9c  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a96c9e  740f                   -je 0xa96caf
    if (cpu.flags.zf)
    {
        goto L_0x00a96caf;
    }
    // 00a96ca0  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a96ca2  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a96ca4  e8c7e0ffff             -call 0xa94d70
    cpu.esp -= 4;
    sub_a94d70(app, cpu);
    if (cpu.terminate) return;
    // 00a96ca9  891d0410aa00           -mov dword ptr [0xaa1004], ebx
    app->getMemory<x86::reg32>(x86::reg32(11145220) /* 0xaa1004 */) = cpu.ebx;
L_0x00a96caf:
    // 00a96caf  8b0d6016aa00           -mov ecx, dword ptr [0xaa1660]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11146848) /* 0xaa1660 */);
    // 00a96cb5  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00a96cb7  740f                   -je 0xa96cc8
    if (cpu.flags.zf)
    {
        goto L_0x00a96cc8;
    }
    // 00a96cb9  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a96cbb  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00a96cbd  e8aee0ffff             -call 0xa94d70
    cpu.esp -= 4;
    sub_a94d70(app, cpu);
    if (cpu.terminate) return;
    // 00a96cc2  89356016aa00           -mov dword ptr [0xaa1660], esi
    app->getMemory<x86::reg32>(x86::reg32(11146848) /* 0xaa1660 */) = cpu.esi;
L_0x00a96cc8:
    // 00a96cc8  8b3d69e3a900           -mov edi, dword ptr [0xa9e369]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(11133801) /* 0xa9e369 */);
    // 00a96cce  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00a96cd0  7408                   -je 0xa96cda
    if (cpu.flags.zf)
    {
        goto L_0x00a96cda;
    }
    // 00a96cd2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a96cd3  2eff15b0cda900         -call dword ptr cs:[0xa9cdb0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11128240) /* 0xa9cdb0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00a96cda:
    // 00a96cda  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a96cdb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a96cdc  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a96cdd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a96cde  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a96cdf  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a96ce0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a96ce0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a96ce1  803800                 +cmp byte ptr [eax], 0
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
    // 00a96ce4  7507                   -jne 0xa96ced
    if (!cpu.flags.zf)
    {
        goto L_0x00a96ced;
    }
    // 00a96ce6  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a96ceb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a96cec  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a96ced:
    // 00a96ced  833df01daa0000         +cmp dword ptr [0xaa1df0], 0
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
    // 00a96cf4  7422                   -je 0xa96d18
    if (cpu.flags.zf)
    {
        goto L_0x00a96d18;
    }
    // 00a96cf6  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a96cf8  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 00a96cfa  8a92011eaa00           -mov dl, byte ptr [edx + 0xaa1e01]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(11148801) /* 0xaa1e01 */);
    // 00a96d00  80e201                 -and dl, 1
    cpu.dl &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00a96d03  81e2ff000000           +and edx, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 00a96d09  740d                   -je 0xa96d18
    if (cpu.flags.zf)
    {
        goto L_0x00a96d18;
    }
    // 00a96d0b  80780100               +cmp byte ptr [eax + 1], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a96d0f  7507                   -jne 0xa96d18
    if (!cpu.flags.zf)
    {
        goto L_0x00a96d18;
    }
    // 00a96d11  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 00a96d16  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a96d17  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a96d18:
    // 00a96d18  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a96d1a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a96d1b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void sub_a96d20(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a96d20  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a96d21  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a96d22  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00a96d25  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a96d27  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00a96d29  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a96d2b  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a96d2d  e8de1d0000             -call 0xa98b10
    cpu.esp -= 4;
    sub_a98b10(app, cpu);
    if (cpu.terminate) return;
    // 00a96d32  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a96d34  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 00a96d36  e8151e0000             -call 0xa98b50
    cpu.esp -= 4;
    sub_a98b50(app, cpu);
    if (cpu.terminate) return;
    // 00a96d3b  881404                 -mov byte ptr [esp + eax], dl
    app->getMemory<x86::reg8>(cpu.esp + cpu.eax * 1) = cpu.dl;
    // 00a96d3e  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a96d42  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00a96d44  e8c71d0000             -call 0xa98b10
    cpu.esp -= 4;
    sub_a98b10(app, cpu);
    if (cpu.terminate) return;
    // 00a96d49  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a96d4b  30f6                   -xor dh, dh
    cpu.dh ^= x86::reg8(x86::sreg8(cpu.dh));
    // 00a96d4d  e8fe1d0000             -call 0xa98b50
    cpu.esp -= 4;
    sub_a98b50(app, cpu);
    if (cpu.terminate) return;
    // 00a96d52  88740404               -mov byte ptr [esp + eax + 4], dh
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */ + cpu.eax * 1) = cpu.dh;
    // 00a96d56  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a96d58  e8231e0000             -call 0xa98b80
    cpu.esp -= 4;
    sub_a98b80(app, cpu);
    if (cpu.terminate) return;
    // 00a96d5d  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a96d61  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a96d65  e8161e0000             -call 0xa98b80
    cpu.esp -= 4;
    sub_a98b80(app, cpu);
    if (cpu.terminate) return;
    // 00a96d6a  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a96d6c  e85f1e0000             -call 0xa98bd0
    cpu.esp -= 4;
    sub_a98bd0(app, cpu);
    if (cpu.terminate) return;
    // 00a96d71  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00a96d74  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a96d75  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a96d76  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a96d80(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a96d80  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a96d81  833df01daa0000         +cmp dword ptr [0xaa1df0], 0
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
    // 00a96d88  7420                   -je 0xa96daa
    if (cpu.flags.zf)
    {
        goto L_0x00a96daa;
    }
    // 00a96d8a  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a96d8c  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 00a96d8e  8a92011eaa00           -mov dl, byte ptr [edx + 0xaa1e01]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(11148801) /* 0xaa1e01 */);
    // 00a96d94  80e201                 -and dl, 1
    cpu.dl &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00a96d97  81e2ff000000           +and edx, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 00a96d9d  740b                   -je 0xa96daa
    if (cpu.flags.zf)
    {
        goto L_0x00a96daa;
    }
    // 00a96d9f  80780100               +cmp byte ptr [eax + 1], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a96da3  7405                   -je 0xa96daa
    if (cpu.flags.zf)
    {
        goto L_0x00a96daa;
    }
    // 00a96da5  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00a96da8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a96da9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a96daa:
    // 00a96daa  40                     -inc eax
    (cpu.eax)++;
    // 00a96dab  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a96dac  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void sub_a96db0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a96db0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a96db1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a96db2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a96db3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a96db4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a96db5  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a96db7  8b4210                 -mov eax, dword ptr [edx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00a96dba  ff1598e2a900           -call dword ptr [0xa9e298]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11133592) /* 0xa9e298 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a96dc0  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00a96dc3  8b480c                 -mov ecx, dword ptr [eax + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00a96dc6  83f901                 +cmp ecx, 1
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a96dc9  741e                   -je 0xa96de9
    if (cpu.flags.zf)
    {
        goto L_0x00a96de9;
    }
    // 00a96dcb  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00a96dcd  7413                   -je 0xa96de2
    if (cpu.flags.zf)
    {
        goto L_0x00a96de2;
    }
    // 00a96dcf  8b4210                 -mov eax, dword ptr [edx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00a96dd2  ff159ce2a900           -call dword ptr [0xa9e29c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11133596) /* 0xa9e29c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a96dd8  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a96ddd  e9dc000000             -jmp 0xa96ebe
    goto L_0x00a96ebe;
L_0x00a96de2:
    // 00a96de2  c7400c01000000         -mov dword ptr [eax + 0xc], 1
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = 1 /*0x1*/;
L_0x00a96de9:
    // 00a96de9  f6420c02               +test byte ptr [edx + 0xc], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */) & 2 /*0x2*/));
    // 00a96ded  7522                   -jne 0xa96e11
    if (!cpu.flags.zf)
    {
        goto L_0x00a96e11;
    }
    // 00a96def  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 00a96df4  e8c7050000             -call 0xa973c0
    cpu.esp -= 4;
    sub_a973c0(app, cpu);
    if (cpu.terminate) return;
    // 00a96df9  804a0c20               -or byte ptr [edx + 0xc], 0x20
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */) |= x86::reg8(x86::sreg8(32 /*0x20*/));
    // 00a96dfd  8b4210                 -mov eax, dword ptr [edx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00a96e00  ff159ce2a900           -call dword ptr [0xa9e29c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11133596) /* 0xa9e29c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a96e06  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a96e0b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a96e0c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a96e0d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a96e0e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a96e0f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a96e10  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a96e11:
    // 00a96e11  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00a96e14  83780800               +cmp dword ptr [eax + 8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a96e18  7507                   -jne 0xa96e21
    if (!cpu.flags.zf)
    {
        goto L_0x00a96e21;
    }
    // 00a96e1a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a96e1c  e8af000000             -call 0xa96ed0
    cpu.esp -= 4;
    sub_a96ed0(app, cpu);
    if (cpu.terminate) return;
L_0x00a96e21:
    // 00a96e21  b900040000             -mov ecx, 0x400
    cpu.ecx = 1024 /*0x400*/;
    // 00a96e26  83fb0a                 +cmp ebx, 0xa
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
    // 00a96e29  7547                   -jne 0xa96e72
    if (!cpu.flags.zf)
    {
        goto L_0x00a96e72;
    }
    // 00a96e2b  8a420c                 -mov al, byte ptr [edx + 0xc]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00a96e2e  b900060000             -mov ecx, 0x600
    cpu.ecx = 1536 /*0x600*/;
    // 00a96e33  a840                   +test al, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 64 /*0x40*/));
    // 00a96e35  753b                   -jne 0xa96e72
    if (!cpu.flags.zf)
    {
        goto L_0x00a96e72;
    }
    // 00a96e37  804a0d10               -or byte ptr [edx + 0xd], 0x10
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(13) /* 0xd */) |= x86::reg8(x86::sreg8(16 /*0x10*/));
    // 00a96e3b  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 00a96e3d  c6000d                 -mov byte ptr [eax], 0xd
    app->getMemory<x86::reg8>(cpu.eax) = 13 /*0xd*/;
    // 00a96e40  8b2a                   -mov ebp, dword ptr [edx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx);
    // 00a96e42  45                     -inc ebp
    (cpu.ebp)++;
    // 00a96e43  8b4204                 -mov eax, dword ptr [edx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00a96e46  892a                   -mov dword ptr [edx], ebp
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebp;
    // 00a96e48  40                     -inc eax
    (cpu.eax)++;
    // 00a96e49  8b7214                 -mov esi, dword ptr [edx + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */);
    // 00a96e4c  894204                 -mov dword ptr [edx + 4], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00a96e4f  39f0                   +cmp eax, esi
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
    // 00a96e51  751f                   -jne 0xa96e72
    if (!cpu.flags.zf)
    {
        goto L_0x00a96e72;
    }
    // 00a96e53  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a96e55  e8c6e3ffff             -call 0xa95220
    cpu.esp -= 4;
    sub_a95220(app, cpu);
    if (cpu.terminate) return;
    // 00a96e5a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a96e5c  7414                   -je 0xa96e72
    if (cpu.flags.zf)
    {
        goto L_0x00a96e72;
    }
    // 00a96e5e  8b4210                 -mov eax, dword ptr [edx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00a96e61  ff159ce2a900           -call dword ptr [0xa9e29c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11133596) /* 0xa9e29c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a96e67  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a96e6c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a96e6d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a96e6e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a96e6f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a96e70  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a96e71  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a96e72:
    // 00a96e72  804a0d10               -or byte ptr [edx + 0xd], 0x10
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(13) /* 0xd */) |= x86::reg8(x86::sreg8(16 /*0x10*/));
    // 00a96e76  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 00a96e78  8818                   -mov byte ptr [eax], bl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.bl;
    // 00a96e7a  8b3a                   -mov edi, dword ptr [edx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx);
    // 00a96e7c  47                     -inc edi
    (cpu.edi)++;
    // 00a96e7d  8b6a04                 -mov ebp, dword ptr [edx + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00a96e80  893a                   -mov dword ptr [edx], edi
    app->getMemory<x86::reg32>(cpu.edx) = cpu.edi;
    // 00a96e82  45                     -inc ebp
    (cpu.ebp)++;
    // 00a96e83  8b420c                 -mov eax, dword ptr [edx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00a96e86  896a04                 -mov dword ptr [edx + 4], ebp
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 00a96e89  85c1                   +test ecx, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.eax));
    // 00a96e8b  7505                   -jne 0xa96e92
    if (!cpu.flags.zf)
    {
        goto L_0x00a96e92;
    }
    // 00a96e8d  3b6a14                 +cmp ebp, dword ptr [edx + 0x14]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a96e90  751f                   -jne 0xa96eb1
    if (!cpu.flags.zf)
    {
        goto L_0x00a96eb1;
    }
L_0x00a96e92:
    // 00a96e92  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a96e94  e887e3ffff             -call 0xa95220
    cpu.esp -= 4;
    sub_a95220(app, cpu);
    if (cpu.terminate) return;
    // 00a96e99  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a96e9b  7414                   -je 0xa96eb1
    if (cpu.flags.zf)
    {
        goto L_0x00a96eb1;
    }
    // 00a96e9d  8b4210                 -mov eax, dword ptr [edx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00a96ea0  ff159ce2a900           -call dword ptr [0xa9e29c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11133596) /* 0xa9e29c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a96ea6  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a96eab  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a96eac  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a96ead  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a96eae  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a96eaf  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a96eb0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a96eb1:
    // 00a96eb1  8b4210                 -mov eax, dword ptr [edx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00a96eb4  ff159ce2a900           -call dword ptr [0xa9e29c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11133596) /* 0xa9e29c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a96eba  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a96ebc  88d8                   -mov al, bl
    cpu.al = cpu.bl;
L_0x00a96ebe:
    // 00a96ebe  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a96ebf  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a96ec0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a96ec1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a96ec2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a96ec3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a96ed0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a96ed0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a96ed1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a96ed2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a96ed3  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a96ed5  e8561d0000             -call 0xa98c30
    cpu.esp -= 4;
    sub_a98c30(app, cpu);
    if (cpu.terminate) return;
    // 00a96eda  837a1400               +cmp dword ptr [edx + 0x14], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a96ede  7526                   -jne 0xa96f06
    if (!cpu.flags.zf)
    {
        goto L_0x00a96f06;
    }
    // 00a96ee0  8a620d                 -mov ah, byte ptr [edx + 0xd]
    cpu.ah = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(13) /* 0xd */);
    // 00a96ee3  f6c402                 +test ah, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 2 /*0x2*/));
    // 00a96ee6  7409                   -je 0xa96ef1
    if (cpu.flags.zf)
    {
        goto L_0x00a96ef1;
    }
    // 00a96ee8  c7421486000000         -mov dword ptr [edx + 0x14], 0x86
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */) = 134 /*0x86*/;
    // 00a96eef  eb15                   -jmp 0xa96f06
    goto L_0x00a96f06;
L_0x00a96ef1:
    // 00a96ef1  f6c404                 +test ah, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 4 /*0x4*/));
    // 00a96ef4  7409                   -je 0xa96eff
    if (cpu.flags.zf)
    {
        goto L_0x00a96eff;
    }
    // 00a96ef6  c7421401000000         -mov dword ptr [edx + 0x14], 1
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */) = 1 /*0x1*/;
    // 00a96efd  eb07                   -jmp 0xa96f06
    goto L_0x00a96f06;
L_0x00a96eff:
    // 00a96eff  c7421400100000         -mov dword ptr [edx + 0x14], 0x1000
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */) = 4096 /*0x1000*/;
L_0x00a96f06:
    // 00a96f06  8b4214                 -mov eax, dword ptr [edx + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */);
    // 00a96f09  e872ddffff             -call 0xa94c80
    cpu.esp -= 4;
    sub_a94c80(app, cpu);
    if (cpu.terminate) return;
    // 00a96f0e  8b5a08                 -mov ebx, dword ptr [edx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00a96f11  894308                 -mov dword ptr [ebx + 8], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00a96f14  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00a96f17  83780800               +cmp dword ptr [eax + 8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a96f1b  7523                   -jne 0xa96f40
    if (!cpu.flags.zf)
    {
        goto L_0x00a96f40;
    }
    // 00a96f1d  8a4a0d                 -mov cl, byte ptr [edx + 0xd]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(13) /* 0xd */);
    // 00a96f20  80e1f8                 -and cl, 0xf8
    cpu.cl &= x86::reg8(x86::sreg8(248 /*0xf8*/));
    // 00a96f23  884a0d                 -mov byte ptr [edx + 0xd], cl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(13) /* 0xd */) = cpu.cl;
    // 00a96f26  88cd                   -mov ch, cl
    cpu.ch = cpu.cl;
    // 00a96f28  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00a96f2b  80cd04                 +or ch, 4
    cpu.clear_co();
    cpu.set_szp((cpu.ch |= x86::reg8(x86::sreg8(4 /*0x4*/))));
    // 00a96f2e  8d5a18                 -lea ebx, [edx + 0x18]
    cpu.ebx = x86::reg32(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 00a96f31  886a0d                 -mov byte ptr [edx + 0xd], ch
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(13) /* 0xd */) = cpu.ch;
    // 00a96f34  895808                 -mov dword ptr [eax + 8], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 00a96f37  c7421401000000         -mov dword ptr [edx + 0x14], 1
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */) = 1 /*0x1*/;
    // 00a96f3e  eb04                   -jmp 0xa96f44
    goto L_0x00a96f44;
L_0x00a96f40:
    // 00a96f40  804a0c08               -or byte ptr [edx + 0xc], 8
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */) |= x86::reg8(x86::sreg8(8 /*0x8*/));
L_0x00a96f44:
    // 00a96f44  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00a96f47  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00a96f4a  c7420400000000         -mov dword ptr [edx + 4], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 00a96f51  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 00a96f53  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a96f54  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a96f55  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a96f56  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a96f60(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a96f60  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a96f61  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a96f62  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a96f63  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a96f64  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a96f67  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a96f69  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00a96f6b  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00a96f6d  eb01                   -jmp 0xa96f70
    goto L_0x00a96f70;
L_0x00a96f6f:
    // 00a96f6f  42                     -inc edx
    (cpu.edx)++;
L_0x00a96f70:
    // 00a96f70  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a96f72  8a0b                   -mov cl, byte ptr [ebx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ebx);
    // 00a96f74  40                     -inc eax
    (cpu.eax)++;
    // 00a96f75  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 00a96f77  75f6                   -jne 0xa96f6f
    if (!cpu.flags.zf)
    {
        goto L_0x00a96f6f;
    }
    // 00a96f79  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a96f7b  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a96f7f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a96f80  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a96f81  a188e3a900             -mov eax, dword ptr [0xa9e388]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11133832) /* 0xa9e388 */);
    // 00a96f86  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a96f87  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00a96f8a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a96f8b  2eff156ccea900         -call dword ptr cs:[0xa9ce6c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11128428) /* 0xa9ce6c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a96f92  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a96f94  e9a3e6ffff             -jmp 0xa9563c
    return sub_a9563c(app, cpu);
}

/* align: skip 0x8d 0x40 0x00 */
void sub_a96f9c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a96f9c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a96f9d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a96f9e  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a96fa0  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00a96fa2  8cda                   -mov edx, ds
    cpu.edx = cpu.ds;
    // 00a96fa4  e8c71c0000             -call 0xa98c70
    cpu.esp -= 4;
    sub_a98c70(app, cpu);
    if (cpu.terminate) return;
    // 00a96fa9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a96fab  7509                   -jne 0xa96fb6
    if (!cpu.flags.zf)
    {
        goto L_0x00a96fb6;
    }
    // 00a96fad  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00a96faf  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a96fb1  e8aaffffff             -call 0xa96f60
    cpu.esp -= 4;
    sub_a96f60(app, cpu);
    if (cpu.terminate) return;
L_0x00a96fb6:
    // 00a96fb6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a96fb7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a96fb8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a96fc0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a96fc0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a96fc1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a96fc2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a96fc3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a96fc4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a96fc5  ff15a8e2a900           -call dword ptr [0xa9e2a8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11133608) /* 0xa9e2a8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a96fcb  8b35e40faa00           -mov esi, dword ptr [0xaa0fe4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(11145188) /* 0xaa0fe4 */);
    // 00a96fd1  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a96fd3  7419                   -je 0xa96fee
    if (cpu.flags.zf)
    {
        goto L_0x00a96fee;
    }
    // 00a96fd5  8b4e04                 -mov ecx, dword ptr [esi + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00a96fd8  8b790c                 -mov edi, dword ptr [ecx + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00a96fdb  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00a96fdd  81e703400000           -and edi, 0x4003
    cpu.edi &= x86::reg32(x86::sreg32(16387 /*0x4003*/));
    // 00a96fe3  a3e40faa00             -mov dword ptr [0xaa0fe4], eax
    app->getMemory<x86::reg32>(x86::reg32(11145188) /* 0xaa0fe4 */) = cpu.eax;
    // 00a96fe8  6683cf03               +or di, 3
    cpu.clear_co();
    cpu.set_szp((cpu.di |= x86::reg16(x86::sreg16(3 /*0x3*/))));
    // 00a96fec  eb4d                   -jmp 0xa9703b
    goto L_0x00a9703b;
L_0x00a96fee:
    // 00a96fee  b960dfa900             -mov ecx, 0xa9df60
    cpu.ecx = 11132768 /*0xa9df60*/;
    // 00a96ff3  81f968e1a900           +cmp ecx, 0xa9e168
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(11133288 /*0xa9e168*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a96ff9  7328                   -jae 0xa97023
    if (!cpu.flags.cf)
    {
        goto L_0x00a97023;
    }
L_0x00a96ffb:
    // 00a96ffb  f6410c03               +test byte ptr [ecx + 0xc], 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */) & 3 /*0x3*/));
    // 00a96fff  7517                   -jne 0xa97018
    if (!cpu.flags.zf)
    {
        goto L_0x00a97018;
    }
    // 00a97001  b81d000000             -mov eax, 0x1d
    cpu.eax = 29 /*0x1d*/;
    // 00a97006  e875dcffff             -call 0xa94c80
    cpu.esp -= 4;
    sub_a94c80(app, cpu);
    if (cpu.terminate) return;
    // 00a9700b  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a9700d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a9700f  7458                   -je 0xa97069
    if (cpu.flags.zf)
    {
        goto L_0x00a97069;
    }
    // 00a97011  bf03000000             -mov edi, 3
    cpu.edi = 3 /*0x3*/;
    // 00a97016  eb23                   -jmp 0xa9703b
    goto L_0x00a9703b;
L_0x00a97018:
    // 00a97018  83c11a                 -add ecx, 0x1a
    (cpu.ecx) += x86::reg32(x86::sreg32(26 /*0x1a*/));
    // 00a9701b  81f968e1a900           +cmp ecx, 0xa9e168
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(11133288 /*0xa9e168*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a97021  72d8                   -jb 0xa96ffb
    if (cpu.flags.cf)
    {
        goto L_0x00a96ffb;
    }
L_0x00a97023:
    // 00a97023  b837000000             -mov eax, 0x37
    cpu.eax = 55 /*0x37*/;
    // 00a97028  bf03400000             -mov edi, 0x4003
    cpu.edi = 16387 /*0x4003*/;
    // 00a9702d  e84edcffff             -call 0xa94c80
    cpu.esp -= 4;
    sub_a94c80(app, cpu);
    if (cpu.terminate) return;
    // 00a97032  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a97034  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a97036  7431                   -je 0xa97069
    if (cpu.flags.zf)
    {
        goto L_0x00a97069;
    }
    // 00a97038  8d481d                 -lea ecx, [eax + 0x1d]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(29) /* 0x1d */);
L_0x00a9703b:
    // 00a9703b  bb1a000000             -mov ebx, 0x1a
    cpu.ebx = 26 /*0x1a*/;
    // 00a97040  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a97042  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00a97044  e827dbffff             -call 0xa94b70
    cpu.esp -= 4;
    sub_a94b70(app, cpu);
    if (cpu.terminate) return;
    // 00a97049  89790c                 -mov dword ptr [ecx + 0xc], edi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.edi;
    // 00a9704c  894e04                 -mov dword ptr [esi + 4], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 00a9704f  a1e00faa00             -mov eax, dword ptr [0xaa0fe0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11145184) /* 0xaa0fe0 */);
    // 00a97054  897108                 -mov dword ptr [ecx + 8], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.esi;
    // 00a97057  8935e00faa00           -mov dword ptr [0xaa0fe0], esi
    app->getMemory<x86::reg32>(x86::reg32(11145184) /* 0xaa0fe0 */) = cpu.esi;
    // 00a9705d  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 00a9705f  ff15ace2a900           -call dword ptr [0xa9e2ac]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11133612) /* 0xa9e2ac */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a97065  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a97067  eb12                   -jmp 0xa9707b
    goto L_0x00a9707b;
L_0x00a97069:
    // 00a97069  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 00a9706e  e84d030000             -call 0xa973c0
    cpu.esp -= 4;
    sub_a973c0(app, cpu);
    if (cpu.terminate) return;
    // 00a97073  ff15ace2a900           -call dword ptr [0xa9e2ac]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11133612) /* 0xa9e2ac */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a97079  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00a9707b:
    // 00a9707b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9707c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9707d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9707e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9707f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a97080  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_a97084(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a97084  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a97085  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a97086  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a97087  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a97089  bae00faa00             -mov edx, 0xaa0fe0
    cpu.edx = 11145184 /*0xaa0fe0*/;
L_0x00a9708e:
    // 00a9708e  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 00a97090  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a97092  7425                   -je 0xa970b9
    if (cpu.flags.zf)
    {
        goto L_0x00a970b9;
    }
    // 00a97094  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00a97097  39cb                   +cmp ebx, ecx
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a97099  7404                   -je 0xa9709f
    if (cpu.flags.zf)
    {
        goto L_0x00a9709f;
    }
    // 00a9709b  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a9709d  ebef                   -jmp 0xa9708e
    goto L_0x00a9708e;
L_0x00a9709f:
    // 00a9709f  8a490c                 -mov cl, byte ptr [ecx + 0xc]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00a970a2  80c903                 -or cl, 3
    cpu.cl |= x86::reg8(x86::sreg8(3 /*0x3*/));
    // 00a970a5  884b0c                 -mov byte ptr [ebx + 0xc], cl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.cl;
    // 00a970a8  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 00a970aa  891a                   -mov dword ptr [edx], ebx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebx;
    // 00a970ac  8b15e40faa00           -mov edx, dword ptr [0xaa0fe4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11145188) /* 0xaa0fe4 */);
    // 00a970b2  a3e40faa00             -mov dword ptr [0xaa0fe4], eax
    app->getMemory<x86::reg32>(x86::reg32(11145188) /* 0xaa0fe4 */) = cpu.eax;
    // 00a970b7  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
L_0x00a970b9:
    // 00a970b9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a970ba  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a970bb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a970bc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_a970c0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a970c0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a970c1  833de40faa0000         +cmp dword ptr [0xaa0fe4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(11145188) /* 0xaa0fe4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a970c8  7416                   -je 0xa970e0
    if (cpu.flags.zf)
    {
        goto L_0x00a970e0;
    }
L_0x00a970ca:
    // 00a970ca  a1e40faa00             -mov eax, dword ptr [0xaa0fe4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11145188) /* 0xaa0fe4 */);
    // 00a970cf  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00a970d1  e89adcffff             -call 0xa94d70
    cpu.esp -= 4;
    sub_a94d70(app, cpu);
    if (cpu.terminate) return;
    // 00a970d6  8915e40faa00           -mov dword ptr [0xaa0fe4], edx
    app->getMemory<x86::reg32>(x86::reg32(11145188) /* 0xaa0fe4 */) = cpu.edx;
    // 00a970dc  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a970de  75ea                   -jne 0xa970ca
    if (!cpu.flags.zf)
    {
        goto L_0x00a970ca;
    }
L_0x00a970e0:
    // 00a970e0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a970e1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a970f0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a970f0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a970f1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a970f2  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a970f4  ff15a8e2a900           -call dword ptr [0xa9e2a8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11133608) /* 0xa9e2a8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a970fa  a1e00faa00             -mov eax, dword ptr [0xaa0fe0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11145184) /* 0xaa0fe0 */);
    // 00a970ff  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a97101  750e                   -jne 0xa97111
    if (!cpu.flags.zf)
    {
        goto L_0x00a97111;
    }
L_0x00a97103:
    // 00a97103  ff15ace2a900           -call dword ptr [0xa9e2ac]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11133612) /* 0xa9e2ac */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a97109  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a9710e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9710f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a97110  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a97111:
    // 00a97111  3b5804                 +cmp ebx, dword ptr [eax + 4]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a97114  7408                   -je 0xa9711e
    if (cpu.flags.zf)
    {
        goto L_0x00a9711e;
    }
    // 00a97116  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00a97118  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a9711a  74e7                   -je 0xa97103
    if (cpu.flags.zf)
    {
        goto L_0x00a97103;
    }
    // 00a9711c  ebf3                   -jmp 0xa97111
    goto L_0x00a97111;
L_0x00a9711e:
    // 00a9711e  ff15ace2a900           -call dword ptr [0xa9e2ac]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11133612) /* 0xa9e2ac */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a97124  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00a97129  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a9712b  e804000000             -call 0xa97134
    cpu.esp -= 4;
    sub_a97134(app, cpu);
    if (cpu.terminate) return;
    // 00a97130  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a97131  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a97132  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void sub_a97134(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a97134  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a97135  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a97137  e8c8000000             -call 0xa97204
    cpu.esp -= 4;
    sub_a97204(app, cpu);
    if (cpu.terminate) return;
    // 00a9713c  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a9713e  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a97140  e83fffffff             -call 0xa97084
    cpu.esp -= 4;
    sub_a97084(app, cpu);
    if (cpu.terminate) return;
    // 00a97145  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a97147  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a97148  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_a9714c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9714c  83c030                 -add eax, 0x30
    (cpu.eax) += x86::reg32(x86::sreg32(48 /*0x30*/));
    // 00a9714f  83f839                 +cmp eax, 0x39
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(57 /*0x39*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a97152  7e03                   -jle 0xa97157
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a97157;
    }
    // 00a97154  83c027                 -add eax, 0x27
    (cpu.eax) += x86::reg32(x86::sreg32(39 /*0x27*/));
L_0x00a97157:
    // 00a97157  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a97158(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a97158  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a97159  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a9715a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a9715b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a9715c  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a9715d  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a97160  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00a97162  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 00a97165  e8361b0000             -call 0xa98ca0
    cpu.esp -= 4;
    sub_a98ca0(app, cpu);
    if (cpu.terminate) return;
    // 00a9716a  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a9716c  c1eb10                 -shr ebx, 0x10
    cpu.ebx >>= 16 /*0x10*/ % 32;
    // 00a9716f  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 00a97171  09c3                   -or ebx, eax
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.eax));
    // 00a97173  e8481c0000             -call 0xa98dc0
    cpu.esp -= 4;
    sub_a98dc0(app, cpu);
    if (cpu.terminate) return;
    // 00a97178  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a9717a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x00a9717b:
    // 00a9717b  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00a9717d  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00a9717f  3c00                   +cmp al, 0
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
    // 00a97181  7410                   -je 0xa97193
    if (cpu.flags.zf)
    {
        goto L_0x00a97193;
    }
    // 00a97183  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00a97186  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00a97189  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00a9718c  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00a9718f  3c00                   +cmp al, 0
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
    // 00a97191  75e8                   -jne 0xa9717b
    if (!cpu.flags.zf)
    {
        goto L_0x00a9717b;
    }
L_0x00a97193:
    // 00a97193  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a97194  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a97195  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a97197  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a97199  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a9719b  49                     -dec ecx
    (cpu.ecx)--;
    // 00a9719c  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a9719e  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00a971a0  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00a971a2  49                     -dec ecx
    (cpu.ecx)--;
    // 00a971a3  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a971a4  8d3429                 -lea esi, [ecx + ebp]
    cpu.esi = x86::reg32(cpu.ecx + cpu.ebp * 1);
    // 00a971a7  8d5604                 -lea edx, [esi + 4]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00a971aa  c60674                 -mov byte ptr [esi], 0x74
    app->getMemory<x86::reg8>(cpu.esi) = 116 /*0x74*/;
    // 00a971ad  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
L_0x00a971af:
    // 00a971af  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a971b1  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00a971b4  4a                     -dec edx
    (cpu.edx)--;
    // 00a971b5  e892ffffff             -call 0xa9714c
    cpu.esp -= 4;
    sub_a9714c(app, cpu);
    if (cpu.terminate) return;
    // 00a971ba  c1eb04                 -shr ebx, 4
    cpu.ebx >>= 4 /*0x4*/ % 32;
    // 00a971bd  884201                 -mov byte ptr [edx + 1], al
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00a971c0  39ca                   +cmp edx, ecx
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
    // 00a971c2  75eb                   -jne 0xa971af
    if (!cpu.flags.zf)
    {
        goto L_0x00a971af;
    }
    // 00a971c4  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00a971c7  c1f804                 -sar eax, 4
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (4 /*0x4*/ % 32));
    // 00a971ca  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00a971cd  c646055f               -mov byte ptr [esi + 5], 0x5f
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(5) /* 0x5 */) = 95 /*0x5f*/;
    // 00a971d1  e876ffffff             -call 0xa9714c
    cpu.esp -= 4;
    sub_a9714c(app, cpu);
    if (cpu.terminate) return;
    // 00a971d6  884606                 -mov byte ptr [esi + 6], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(6) /* 0x6 */) = cpu.al;
    // 00a971d9  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00a971dc  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00a971df  e868ffffff             -call 0xa9714c
    cpu.esp -= 4;
    sub_a9714c(app, cpu);
    if (cpu.terminate) return;
    // 00a971e4  c646082e               -mov byte ptr [esi + 8], 0x2e
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */) = 46 /*0x2e*/;
    // 00a971e8  c6460974               -mov byte ptr [esi + 9], 0x74
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(9) /* 0x9 */) = 116 /*0x74*/;
    // 00a971ec  c6460a6d               -mov byte ptr [esi + 0xa], 0x6d
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(10) /* 0xa */) = 109 /*0x6d*/;
    // 00a971f0  c6460b70               -mov byte ptr [esi + 0xb], 0x70
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(11) /* 0xb */) = 112 /*0x70*/;
    // 00a971f4  c6460c00               -mov byte ptr [esi + 0xc], 0
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 00a971f8  884607                 -mov byte ptr [esi + 7], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(7) /* 0x7 */) = cpu.al;
    // 00a971fb  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a971fe  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a971ff  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a97200  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a97201  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a97202  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a97203  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a97204(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a97204  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a97205  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a97206  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a97207  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a97208  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a97209  81ec14010000           -sub esp, 0x114
    (cpu.esp) -= x86::reg32(x86::sreg32(276 /*0x114*/));
    // 00a9720f  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a97211  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00a97213  83780c00               +cmp dword ptr [eax + 0xc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a97217  750a                   -jne 0xa97223
    if (!cpu.flags.zf)
    {
        goto L_0x00a97223;
    }
    // 00a97219  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a9721e  e997000000             -jmp 0xa972ba
    goto L_0x00a972ba;
L_0x00a97223:
    // 00a97223  8a600d                 -mov ah, byte ptr [eax + 0xd]
    cpu.ah = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(13) /* 0xd */);
    // 00a97226  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00a97228  f6c410                 +test ah, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 16 /*0x10*/));
    // 00a9722b  7409                   -je 0xa97236
    if (cpu.flags.zf)
    {
        goto L_0x00a97236;
    }
    // 00a9722d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a9722f  e8ecdfffff             -call 0xa95220
    cpu.esp -= 4;
    sub_a95220(app, cpu);
    if (cpu.terminate) return;
    // 00a97234  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
L_0x00a97236:
    // 00a97236  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00a97239  ff1598e2a900           -call dword ptr [0xa9e298]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11133592) /* 0xa9e298 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a9723f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a97241  e84a1c0000             -call 0xa98e90
    cpu.esp -= 4;
    sub_a98e90(app, cpu);
    if (cpu.terminate) return;
    // 00a97246  83f8ff                 +cmp eax, -1
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
    // 00a97249  740e                   -je 0xa97259
    if (cpu.flags.zf)
    {
        goto L_0x00a97259;
    }
    // 00a9724b  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a9724d  8b6910                 -mov ebp, dword ptr [ecx + 0x10]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00a97250  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a97252  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00a97254  e8c7010000             -call 0xa97420
    cpu.esp -= 4;
    sub_a97420(app, cpu);
    if (cpu.terminate) return;
L_0x00a97259:
    // 00a97259  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00a9725b  740a                   -je 0xa97267
    if (cpu.flags.zf)
    {
        goto L_0x00a97267;
    }
    // 00a9725d  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00a97260  e88b1c0000             -call 0xa98ef0
    cpu.esp -= 4;
    sub_a98ef0(app, cpu);
    if (cpu.terminate) return;
    // 00a97265  09c6                   -or esi, eax
    cpu.esi |= x86::reg32(x86::sreg32(cpu.eax));
L_0x00a97267:
    // 00a97267  f6410c08               +test byte ptr [ecx + 0xc], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */) & 8 /*0x8*/));
    // 00a9726b  7415                   -je 0xa97282
    if (cpu.flags.zf)
    {
        goto L_0x00a97282;
    }
    // 00a9726d  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00a97270  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00a97273  e8f8daffff             -call 0xa94d70
    cpu.esp -= 4;
    sub_a94d70(app, cpu);
    if (cpu.terminate) return;
    // 00a97278  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00a9727b  c7400800000000         -mov dword ptr [eax + 8], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
L_0x00a97282:
    // 00a97282  f6410d08               +test byte ptr [ecx + 0xd], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(13) /* 0xd */) & 8 /*0x8*/));
    // 00a97286  741a                   -je 0xa972a2
    if (cpu.flags.zf)
    {
        goto L_0x00a972a2;
    }
    // 00a97288  8b5108                 -mov edx, dword ptr [ecx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00a9728b  8a5214                 -mov dl, byte ptr [edx + 0x14]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(20) /* 0x14 */);
    // 00a9728e  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a97290  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00a97296  e8bdfeffff             -call 0xa97158
    cpu.esp -= 4;
    sub_a97158(app, cpu);
    if (cpu.terminate) return;
    // 00a9729b  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a9729d  e8de1c0000             -call 0xa98f80
    cpu.esp -= 4;
    sub_a98f80(app, cpu);
    if (cpu.terminate) return;
L_0x00a972a2:
    // 00a972a2  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00a972a5  ff159ce2a900           -call dword ptr [0xa9e29c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11133596) /* 0xa9e29c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a972ab  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00a972ad  7409                   -je 0xa972b8
    if (cpu.flags.zf)
    {
        goto L_0x00a972b8;
    }
    // 00a972af  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00a972b2  ff15a4e2a900           -call dword ptr [0xa9e2a4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11133604) /* 0xa9e2a4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00a972b8:
    // 00a972b8  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x00a972ba:
    // 00a972ba  81c414010000           -add esp, 0x114
    (cpu.esp) += x86::reg32(x86::sreg32(276 /*0x114*/));
    // 00a972c0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a972c1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a972c2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a972c3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a972c4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a972c5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a972d0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a972d0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a972d1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a972d2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a972d3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a972d4  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a972d7  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a972d9  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00a972db  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a972dd  7c08                   -jl 0xa972e7
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a972e7;
    }
    // 00a972df  3b0570e5a900           +cmp eax, dword ptr [0xa9e570]
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
    // 00a972e5  7614                   -jbe 0xa972fb
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a972fb;
    }
L_0x00a972e7:
    // 00a972e7  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 00a972ec  e8cf000000             -call 0xa973c0
    cpu.esp -= 4;
    sub_a973c0(app, cpu);
    if (cpu.terminate) return;
    // 00a972f1  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a972f6  e9b8000000             -jmp 0xa973b3
    goto L_0x00a973b3;
L_0x00a972fb:
    // 00a972fb  8b2d88e3a900           -mov ebp, dword ptr [0xa9e388]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(11133832) /* 0xa9e388 */);
    // 00a97301  8b6cb500               -mov ebp, dword ptr [ebp + esi*4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + cpu.esi * 4);
    // 00a97305  ff1598e2a900           -call dword ptr [0xa9e298]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11133592) /* 0xa9e298 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a9730b  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a9730d  e87e1c0000             -call 0xa98f90
    cpu.esp -= 4;
    sub_a98f90(app, cpu);
    if (cpu.terminate) return;
    // 00a97312  a880                   +test al, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 128 /*0x80*/));
    // 00a97314  7428                   -je 0xa9733e
    if (cpu.flags.zf)
    {
        goto L_0x00a9733e;
    }
    // 00a97316  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00a97318  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a9731a  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a9731c  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a9731d  2eff1530cea900         -call dword ptr cs:[0xa9ce30]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11128368) /* 0xa9ce30 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a97324  83f8ff                 +cmp eax, -1
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
    // 00a97327  7515                   -jne 0xa9733e
    if (!cpu.flags.zf)
    {
        goto L_0x00a9733e;
    }
    // 00a97329  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a9732b  ff159ce2a900           -call dword ptr [0xa9e29c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11133596) /* 0xa9e29c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a97331  e84e1d0000             -call 0xa99084
    cpu.esp -= 4;
    sub_a99084(app, cpu);
    if (cpu.terminate) return;
    // 00a97336  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a97339  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9733a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9733b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9733c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9733d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a9733e:
    // 00a9733e  833d0ce3a90000         +cmp dword ptr [0xa9e30c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(11133708) /* 0xa9e30c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a97345  7428                   -je 0xa9736f
    if (cpu.flags.zf)
    {
        goto L_0x00a9736f;
    }
    // 00a97347  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a97349  ff15e0e2a900           -call dword ptr [0xa9e2e0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11133664) /* 0xa9e2e0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a9734f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a97351  741c                   -je 0xa9736f
    if (cpu.flags.zf)
    {
        goto L_0x00a9736f;
    }
    // 00a97353  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00a97355  ff150ce3a900           -call dword ptr [0xa9e30c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11133708) /* 0xa9e30c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a9735b  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a9735d  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a9735f  ff159ce2a900           -call dword ptr [0xa9e29c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11133596) /* 0xa9e29c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a97365  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a97367  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a9736a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9736b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9736c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9736d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9736e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a9736f:
    // 00a9736f  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a97371  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a97375  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a97376  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a97377  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a97378  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a97379  2eff156ccea900         -call dword ptr cs:[0xa9ce6c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11128428) /* 0xa9ce6c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a97380  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a97382  7515                   -jne 0xa97399
    if (!cpu.flags.zf)
    {
        goto L_0x00a97399;
    }
    // 00a97384  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a97386  ff159ce2a900           -call dword ptr [0xa9e29c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11133596) /* 0xa9e29c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a9738c  e8f31c0000             -call 0xa99084
    cpu.esp -= 4;
    sub_a99084(app, cpu);
    if (cpu.terminate) return;
    // 00a97391  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a97394  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a97395  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a97396  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a97397  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a97398  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a97399:
    // 00a97399  3b1c24                 +cmp ebx, dword ptr [esp]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a9739c  740a                   -je 0xa973a8
    if (cpu.flags.zf)
    {
        goto L_0x00a973a8;
    }
    // 00a9739e  b80c000000             -mov eax, 0xc
    cpu.eax = 12 /*0xc*/;
    // 00a973a3  e818000000             -call 0xa973c0
    cpu.esp -= 4;
    sub_a973c0(app, cpu);
    if (cpu.terminate) return;
L_0x00a973a8:
    // 00a973a8  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a973aa  ff159ce2a900           -call dword ptr [0xa9e29c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11133596) /* 0xa9e29c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a973b0  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
L_0x00a973b3:
    // 00a973b3  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a973b6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a973b7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a973b8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a973b9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a973ba  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void sub_a973c0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a973c0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a973c1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a973c3  ff1594e2a900           -call dword ptr [0xa9e294]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11133588) /* 0xa9e294 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a973c9  895004                 -mov dword ptr [eax + 4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00a973cc  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a973cd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void sub_a973d0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a973d0  b80d000000             -mov eax, 0xd
    cpu.eax = 13 /*0xd*/;
    // 00a973d5  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a973d6  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a973d8  ff1594e2a900           -call dword ptr [0xa9e294]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11133588) /* 0xa9e294 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a973de  895004                 -mov dword ptr [eax + 4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00a973e1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a973e2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void sub_a973e4(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a973e4  b80e000000             -mov eax, 0xe
    cpu.eax = 14 /*0xe*/;
    // 00a973e9  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a973ea  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a973ec  ff1594e2a900           -call dword ptr [0xa9e294]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11133588) /* 0xa9e294 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a973f2  895004                 -mov dword ptr [eax + 4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00a973f5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a973f6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void sub_a973f8(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a973f8  b809000000             -mov eax, 9
    cpu.eax = 9 /*0x9*/;
    // 00a973fd  e8beffffff             -call 0xa973c0
    cpu.esp -= 4;
    sub_a973c0(app, cpu);
    if (cpu.terminate) return;
    // 00a97402  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a97407  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a97408(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a97408  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a97409  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a9740b  ff1594e2a900           -call dword ptr [0xa9e294]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11133588) /* 0xa9e294 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a97411  895008                 -mov dword ptr [eax + 8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00a97414  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a97415  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a97420(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a97420  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a97421  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a97422  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a97424  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00a97426  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a97428  7c08                   -jl 0xa97432
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a97432;
    }
    // 00a9742a  3b0570e5a900           +cmp eax, dword ptr [0xa9e570]
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
    // 00a97430  7612                   -jbe 0xa97444
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a97444;
    }
L_0x00a97432:
    // 00a97432  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 00a97437  e884ffffff             -call 0xa973c0
    cpu.esp -= 4;
    sub_a973c0(app, cpu);
    if (cpu.terminate) return;
    // 00a9743c  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a97441  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a97442  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a97443  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a97444:
    // 00a97444  ff1598e2a900           -call dword ptr [0xa9e298]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11133592) /* 0xa9e298 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a9744a  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a9744c  e83f1b0000             -call 0xa98f90
    cpu.esp -= 4;
    sub_a98f90(app, cpu);
    if (cpu.terminate) return;
    // 00a97451  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00a97453  7e10                   -jle 0xa97465
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a97465;
    }
    // 00a97455  a880                   +test al, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 128 /*0x80*/));
    // 00a97457  750c                   -jne 0xa97465
    if (!cpu.flags.zf)
    {
        goto L_0x00a97465;
    }
    // 00a97459  80cc80                 -or ah, 0x80
    cpu.ah |= x86::reg8(x86::sreg8(128 /*0x80*/));
    // 00a9745c  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a9745e  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a97460  e8831b0000             -call 0xa98fe8
    cpu.esp -= 4;
    sub_a98fe8(app, cpu);
    if (cpu.terminate) return;
L_0x00a97465:
    // 00a97465  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a97466  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a97468  8b1588e3a900           -mov edx, dword ptr [0xa9e388]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11133832) /* 0xa9e388 */);
    // 00a9746e  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a9746f  8b04b2                 -mov eax, dword ptr [edx + esi*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.esi * 4);
    // 00a97472  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a97473  2eff1530cea900         -call dword ptr cs:[0xa9ce30]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11128368) /* 0xa9ce30 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a9747a  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a9747c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a9747e  ff159ce2a900           -call dword ptr [0xa9e29c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11133596) /* 0xa9e29c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a97484  83f9ff                 +cmp ecx, -1
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a97487  7505                   -jne 0xa9748e
    if (!cpu.flags.zf)
    {
        goto L_0x00a9748e;
    }
    // 00a97489  e8f61b0000             -call 0xa99084
    cpu.esp -= 4;
    sub_a99084(app, cpu);
    if (cpu.terminate) return;
L_0x00a9748e:
    // 00a9748e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a97490  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a97491  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a97492  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a974a0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a974a0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a974a1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a974a2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a974a3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a974a4  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a974a6  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00a974a8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a974aa  7c08                   -jl 0xa974b4
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a974b4;
    }
    // 00a974ac  3b0570e5a900           +cmp eax, dword ptr [0xa9e570]
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
    // 00a974b2  7614                   -jbe 0xa974c8
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a974c8;
    }
L_0x00a974b4:
    // 00a974b4  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 00a974b9  e802ffffff             -call 0xa973c0
    cpu.esp -= 4;
    sub_a973c0(app, cpu);
    if (cpu.terminate) return;
    // 00a974be  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a974c3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a974c4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a974c5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a974c6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a974c7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a974c8:
    // 00a974c8  ff1598e2a900           -call dword ptr [0xa9e298]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11133592) /* 0xa9e298 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a974ce  a188e3a900             -mov eax, dword ptr [0xa9e388]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11133832) /* 0xa9e388 */);
    // 00a974d3  8b0498                 -mov eax, dword ptr [eax + ebx*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + cpu.ebx * 4);
    // 00a974d6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a974d7  2eff15accda900         -call dword ptr cs:[0xa9cdac]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11128236) /* 0xa9cdac */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a974de  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a974e0  750a                   -jne 0xa974ec
    if (!cpu.flags.zf)
    {
        goto L_0x00a974ec;
    }
    // 00a974e2  e89d1b0000             -call 0xa99084
    cpu.esp -= 4;
    sub_a99084(app, cpu);
    if (cpu.terminate) return;
    // 00a974e7  beffffffff             -mov esi, 0xffffffff
    cpu.esi = 4294967295 /*0xffffffff*/;
L_0x00a974ec:
    // 00a974ec  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a974ee  ff159ce2a900           -call dword ptr [0xa9e29c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11133596) /* 0xa9e29c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a974f4  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a974f6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a974f7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a974f8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a974f9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a974fa  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void sub_a97500(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a97500  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a97501  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a97502  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a97503  8b0d88e3a900           -mov ecx, dword ptr [0xa9e388]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11133832) /* 0xa9e388 */);
    // 00a97509  a18ce3a900             -mov eax, dword ptr [0xa9e38c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11133836) /* 0xa9e38c */);
    // 00a9750e  3b0570e5a900           +cmp eax, dword ptr [0xa9e570]
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
    // 00a97514  7304                   -jae 0xa9751a
    if (!cpu.flags.cf)
    {
        goto L_0x00a9751a;
    }
    // 00a97516  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a97518  eb2f                   -jmp 0xa97549
    goto L_0x00a97549;
L_0x00a9751a:
    // 00a9751a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a9751c  7e26                   -jle 0xa97544
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a97544;
    }
    // 00a9751e  8b1d8ce3a900           -mov ebx, dword ptr [0xa9e38c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(11133836) /* 0xa9e38c */);
    // 00a97524  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00a97526  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a97528  c1e302                 -shl ebx, 2
    cpu.ebx <<= 2 /*0x2*/ % 32;
L_0x00a9752b:
    // 00a9752b  833c0200               +cmp dword ptr [edx + eax], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 1);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a9752f  750c                   -jne 0xa9753d
    if (!cpu.flags.zf)
    {
        goto L_0x00a9753d;
    }
    // 00a97531  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a97533  890d88e3a900           -mov dword ptr [0xa9e388], ecx
    app->getMemory<x86::reg32>(x86::reg32(11133832) /* 0xa9e388 */) = cpu.ecx;
    // 00a97539  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9753a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9753b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9753c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a9753d:
    // 00a9753d  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a97540  39d8                   +cmp eax, ebx
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a97542  7ce7                   -jl 0xa9752b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a9752b;
    }
L_0x00a97544:
    // 00a97544  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x00a97549:
    // 00a97549  890d88e3a900           -mov dword ptr [0xa9e388], ecx
    app->getMemory<x86::reg32>(x86::reg32(11133832) /* 0xa9e388 */) = cpu.ecx;
    // 00a9754f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a97550  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a97551  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a97552  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void sub_a97554(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a97554  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a97555  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a97556  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a97557  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a97558  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a9755a  ff15c8e2a900           -call dword ptr [0xa9e2c8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11133640) /* 0xa9e2c8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a97560  8b1d8ce3a900           -mov ebx, dword ptr [0xa9e38c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(11133836) /* 0xa9e38c */);
    // 00a97566  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a97568  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a9756a  7e2d                   -jle 0xa97599
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a97599;
    }
    // 00a9756c  8d0c9d00000000         -lea ecx, [ebx*4]
    cpu.ecx = x86::reg32(cpu.ebx * 4);
    // 00a97573  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00a97575:
    // 00a97575  8b1d88e3a900           -mov ebx, dword ptr [0xa9e388]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(11133832) /* 0xa9e388 */);
    // 00a9757b  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00a9757d  833b00                 +cmp dword ptr [ebx], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a97580  750f                   -jne 0xa97591
    if (!cpu.flags.zf)
    {
        goto L_0x00a97591;
    }
    // 00a97582  8933                   -mov dword ptr [ebx], esi
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.esi;
    // 00a97584  ff15cce2a900           -call dword ptr [0xa9e2cc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11133644) /* 0xa9e2cc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a9758a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a9758c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9758d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9758e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9758f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a97590  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a97591:
    // 00a97591  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a97594  42                     -inc edx
    (cpu.edx)++;
    // 00a97595  39c8                   +cmp eax, ecx
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
    // 00a97597  7cdc                   -jl 0xa97575
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a97575;
    }
L_0x00a97599:
    // 00a97599  8b158ce3a900           -mov edx, dword ptr [0xa9e38c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11133836) /* 0xa9e38c */);
    // 00a9759f  42                     -inc edx
    (cpu.edx)++;
    // 00a975a0  a188e3a900             -mov eax, dword ptr [0xa9e388]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11133832) /* 0xa9e388 */);
    // 00a975a5  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 00a975a8  e8f31a0000             -call 0xa990a0
    cpu.esp -= 4;
    sub_a990a0(app, cpu);
    if (cpu.terminate) return;
    // 00a975ad  8b158ce3a900           -mov edx, dword ptr [0xa9e38c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11133836) /* 0xa9e38c */);
    // 00a975b3  a388e3a900             -mov dword ptr [0xa9e388], eax
    app->getMemory<x86::reg32>(x86::reg32(11133832) /* 0xa9e388 */) = cpu.eax;
    // 00a975b8  8d4a01                 -lea ecx, [edx + 1]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 00a975bb  893490                 -mov dword ptr [eax + edx*4], esi
    app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 4) = cpu.esi;
    // 00a975be  890d8ce3a900           -mov dword ptr [0xa9e38c], ecx
    app->getMemory<x86::reg32>(x86::reg32(11133836) /* 0xa9e38c */) = cpu.ecx;
    // 00a975c4  ff15cce2a900           -call dword ptr [0xa9e2cc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11133644) /* 0xa9e2cc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a975ca  a18ce3a900             -mov eax, dword ptr [0xa9e38c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11133836) /* 0xa9e38c */);
    // 00a975cf  48                     -dec eax
    (cpu.eax)--;
    // 00a975d0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a975d1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a975d2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a975d3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a975d4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_a975d8(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a975d8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a975d9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a975da  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a975db  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a975dc  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a975dd  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a975e0  8b3d88e3a900           -mov edi, dword ptr [0xa9e388]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(11133832) /* 0xa9e388 */);
    // 00a975e6  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00a975e9  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00a975eb  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a975ed  0f8caa000000           -jl 0xa9769d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a9769d;
    }
    // 00a975f3  ff15c8e2a900           -call dword ptr [0xa9e2c8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11133640) /* 0xa9e2c8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a975f9  83fa01                 +cmp edx, 1
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
    // 00a975fc  7209                   -jb 0xa97607
    if (cpu.flags.cf)
    {
        goto L_0x00a97607;
    }
    // 00a975fe  7613                   -jbe 0xa97613
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a97613;
    }
    // 00a97600  83fa02                 +cmp edx, 2
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
    // 00a97603  7416                   -je 0xa9761b
    if (cpu.flags.zf)
    {
        goto L_0x00a9761b;
    }
    // 00a97605  eb21                   -jmp 0xa97628
    goto L_0x00a97628;
L_0x00a97607:
    // 00a97607  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a97609  751d                   -jne 0xa97628
    if (!cpu.flags.zf)
    {
        goto L_0x00a97628;
    }
    // 00a9760b  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 00a9760e  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a9760f  6af6                   -push -0xa
    app->getMemory<x86::reg32>(cpu.esp-4) = -10 /*-0xa*/;
    cpu.esp -= 4;
    // 00a97611  eb0e                   -jmp 0xa97621
    goto L_0x00a97621;
L_0x00a97613:
    // 00a97613  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 00a97616  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a97617  6af5                   -push -0xb
    app->getMemory<x86::reg32>(cpu.esp-4) = -11 /*-0xb*/;
    cpu.esp -= 4;
    // 00a97619  eb06                   -jmp 0xa97621
    goto L_0x00a97621;
L_0x00a9761b:
    // 00a9761b  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 00a9761e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a9761f  6af4                   -push -0xc
    app->getMemory<x86::reg32>(cpu.esp-4) = -12 /*-0xc*/;
    cpu.esp -= 4;
L_0x00a97621:
    // 00a97621  2eff1538cea900         -call dword ptr cs:[0xa9ce38]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11128376) /* 0xa9ce38 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00a97628:
    // 00a97628  8b2d8ce3a900           -mov ebp, dword ptr [0xa9e38c]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(11133836) /* 0xa9e38c */);
    // 00a9762e  8d0cb500000000         -lea ecx, [esi*4]
    cpu.ecx = x86::reg32(cpu.esi * 4);
    // 00a97635  8b3d88e3a900           -mov edi, dword ptr [0xa9e388]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(11133832) /* 0xa9e388 */);
    // 00a9763b  39ee                   +cmp esi, ebp
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a9763d  7d09                   -jge 0xa97648
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a97648;
    }
    // 00a9763f  01f9                   +add ecx, edi
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a97641  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00a97644  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 00a97646  eb49                   -jmp 0xa97691
    goto L_0x00a97691;
L_0x00a97648:
    // 00a97648  8d5104                 -lea edx, [ecx + 4]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00a9764b  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a9764d  e84e1a0000             -call 0xa990a0
    cpu.esp -= 4;
    sub_a990a0(app, cpu);
    if (cpu.terminate) return;
    // 00a97652  8b158ce3a900           -mov edx, dword ptr [0xa9e38c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11133836) /* 0xa9e38c */);
    // 00a97658  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a9765a  39f2                   +cmp edx, esi
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a9765c  7d18                   -jge 0xa97676
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a97676;
    }
    // 00a9765e  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00a97665  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
L_0x00a97667:
    // 00a97667  c7040300000000         -mov dword ptr [ebx + eax], 0
    app->getMemory<x86::reg32>(cpu.ebx + cpu.eax * 1) = 0 /*0x0*/;
    // 00a9766e  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a97671  42                     -inc edx
    (cpu.edx)++;
    // 00a97672  39c8                   +cmp eax, ecx
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
    // 00a97674  7cf1                   -jl 0xa97667
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a97667;
    }
L_0x00a97676:
    // 00a97676  8d04b500000000         -lea eax, [esi*4]
    cpu.eax = x86::reg32(cpu.esi * 4);
    // 00a9767d  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 00a97680  46                     -inc esi
    (cpu.esi)++;
    // 00a97681  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 00a97683  893d88e3a900           -mov dword ptr [0xa9e388], edi
    app->getMemory<x86::reg32>(x86::reg32(11133832) /* 0xa9e388 */) = cpu.edi;
    // 00a97689  89358ce3a900           -mov dword ptr [0xa9e38c], esi
    app->getMemory<x86::reg32>(x86::reg32(11133836) /* 0xa9e38c */) = cpu.esi;
    // 00a9768f  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
L_0x00a97691:
    // 00a97691  ff15cce2a900           -call dword ptr [0xa9e2cc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11133644) /* 0xa9e2cc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a97697  8b3d88e3a900           -mov edi, dword ptr [0xa9e388]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(11133832) /* 0xa9e388 */);
L_0x00a9769d:
    // 00a9769d  8b3d88e3a900           -mov edi, dword ptr [0xa9e388]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(11133832) /* 0xa9e388 */);
    // 00a976a3  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a976a6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a976a7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a976a8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a976a9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a976aa  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a976ab  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a976ac(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a976ac  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a976ad  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a976af  ff15c8e2a900           -call dword ptr [0xa9e2c8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11133640) /* 0xa9e2c8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a976b5  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a976b7  7e1c                   -jle 0xa976d5
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a976d5;
    }
    // 00a976b9  3b158ce3a900           +cmp edx, dword ptr [0xa9e38c]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(11133836) /* 0xa9e38c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a976bf  7d14                   -jge 0xa976d5
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a976d5;
    }
    // 00a976c1  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00a976c8  8b1588e3a900           -mov edx, dword ptr [0xa9e388]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11133832) /* 0xa9e388 */);
    // 00a976ce  c7040200000000         -mov dword ptr [edx + eax], 0
    app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 1) = 0 /*0x0*/;
L_0x00a976d5:
    // 00a976d5  ff15cce2a900           -call dword ptr [0xa9e2cc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11133644) /* 0xa9e2cc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a976db  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a976dc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_a976e0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a976e0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a976e1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a976e2  6af6                   -push -0xa
    app->getMemory<x86::reg32>(cpu.esp-4) = -10 /*-0xa*/;
    cpu.esp -= 4;
    // 00a976e4  2eff15fccda900         -call dword ptr cs:[0xa9cdfc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11128316) /* 0xa9cdfc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a976eb  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a976ed  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a976ef  7405                   -je 0xa976f6
    if (cpu.flags.zf)
    {
        goto L_0x00a976f6;
    }
    // 00a976f1  83f8ff                 +cmp eax, -1
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
    // 00a976f4  7505                   -jne 0xa976fb
    if (!cpu.flags.zf)
    {
        goto L_0x00a976fb;
    }
L_0x00a976f6:
    // 00a976f6  e845000000             -call 0xa97740
    cpu.esp -= 4;
    sub_a97740(app, cpu);
    if (cpu.terminate) return;
L_0x00a976fb:
    // 00a976fb  e854feffff             -call 0xa97554
    cpu.esp -= 4;
    sub_a97554(app, cpu);
    if (cpu.terminate) return;
    // 00a97700  6af5                   -push -0xb
    app->getMemory<x86::reg32>(cpu.esp-4) = -11 /*-0xb*/;
    cpu.esp -= 4;
    // 00a97702  2eff15fccda900         -call dword ptr cs:[0xa9cdfc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11128316) /* 0xa9cdfc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a97709  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a9770b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a9770d  7405                   -je 0xa97714
    if (cpu.flags.zf)
    {
        goto L_0x00a97714;
    }
    // 00a9770f  83f8ff                 +cmp eax, -1
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
    // 00a97712  7505                   -jne 0xa97719
    if (!cpu.flags.zf)
    {
        goto L_0x00a97719;
    }
L_0x00a97714:
    // 00a97714  e827000000             -call 0xa97740
    cpu.esp -= 4;
    sub_a97740(app, cpu);
    if (cpu.terminate) return;
L_0x00a97719:
    // 00a97719  e836feffff             -call 0xa97554
    cpu.esp -= 4;
    sub_a97554(app, cpu);
    if (cpu.terminate) return;
    // 00a9771e  6af4                   -push -0xc
    app->getMemory<x86::reg32>(cpu.esp-4) = -12 /*-0xc*/;
    cpu.esp -= 4;
    // 00a97720  2eff15fccda900         -call dword ptr cs:[0xa9cdfc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11128316) /* 0xa9cdfc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a97727  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a97729  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a9772b  7405                   -je 0xa97732
    if (cpu.flags.zf)
    {
        goto L_0x00a97732;
    }
    // 00a9772d  83f8ff                 +cmp eax, -1
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
    // 00a97730  7505                   -jne 0xa97737
    if (!cpu.flags.zf)
    {
        goto L_0x00a97737;
    }
L_0x00a97732:
    // 00a97732  e809000000             -call 0xa97740
    cpu.esp -= 4;
    sub_a97740(app, cpu);
    if (cpu.terminate) return;
L_0x00a97737:
    // 00a97737  e818feffff             -call 0xa97554
    cpu.esp -= 4;
    sub_a97554(app, cpu);
    if (cpu.terminate) return;
    // 00a9773c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9773d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a9773e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void sub_a97740(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a97740  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a97741  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a97742  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a97744  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a97746  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a97748  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a9774a  2eff158ccda900         -call dword ptr cs:[0xa9cd8c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11128204) /* 0xa9cd8c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a97751  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a97753  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a97755  750d                   -jne 0xa97764
    if (!cpu.flags.zf)
    {
        goto L_0x00a97764;
    }
    // 00a97757  8b1590e3a900           -mov edx, dword ptr [0xa9e390]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11133840) /* 0xa9e390 */);
    // 00a9775d  42                     -inc edx
    (cpu.edx)++;
    // 00a9775e  891590e3a900           -mov dword ptr [0xa9e390], edx
    app->getMemory<x86::reg32>(x86::reg32(11133840) /* 0xa9e390 */) = cpu.edx;
L_0x00a97764:
    // 00a97764  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a97766  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a97767  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a97768  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_a9776c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a9776c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a9776d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a9776e  8b1588e3a900           -mov edx, dword ptr [0xa9e388]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11133832) /* 0xa9e388 */);
    // 00a97774  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a97776  740f                   -je 0xa97787
    if (cpu.flags.zf)
    {
        goto L_0x00a97787;
    }
    // 00a97778  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a9777a  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a9777c  e8efd5ffff             -call 0xa94d70
    cpu.esp -= 4;
    sub_a94d70(app, cpu);
    if (cpu.terminate) return;
    // 00a97781  891d88e3a900           -mov dword ptr [0xa9e388], ebx
    app->getMemory<x86::reg32>(x86::reg32(11133832) /* 0xa9e388 */) = cpu.ebx;
L_0x00a97787:
    // 00a97787  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a97788  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a97789  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a97790(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a97790  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_a97794(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a97794  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a97795  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a97796  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a97797  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a97798  8b15d01daa00           -mov edx, dword ptr [0xaa1dd0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11148752) /* 0xaa1dd0 */);
    // 00a9779e  83fa40                 +cmp edx, 0x40
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(64 /*0x40*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a977a1  7d1e                   -jge 0xa977c1
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a977c1;
    }
    // 00a977a3  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00a977aa  bba017aa00             -mov ebx, 0xaa17a0
    cpu.ebx = 11147168 /*0xaa17a0*/;
    // 00a977af  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00a977b1  8d7201                 -lea esi, [edx + 1]
    cpu.esi = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 00a977b4  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00a977b7  8935d01daa00           -mov dword ptr [0xaa1dd0], esi
    app->getMemory<x86::reg32>(x86::reg32(11148752) /* 0xaa1dd0 */) = cpu.esi;
    // 00a977bd  01c3                   +add ebx, eax
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a977bf  eb67                   -jmp 0xa97828
    goto L_0x00a97828;
L_0x00a977c1:
    // 00a977c1  ba18000000             -mov edx, 0x18
    cpu.edx = 24 /*0x18*/;
    // 00a977c6  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a977cb  e850190000             -call 0xa99120
    cpu.esp -= 4;
    sub_a99120(app, cpu);
    if (cpu.terminate) return;
    // 00a977d0  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a977d2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a977d4  750f                   -jne 0xa977e5
    if (!cpu.flags.zf)
    {
        goto L_0x00a977e5;
    }
    // 00a977d6  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00a977db  b860eda900             -mov eax, 0xa9ed60
    cpu.eax = 11136352 /*0xa9ed60*/;
    // 00a977e0  e8b7f7ffff             -call 0xa96f9c
    cpu.esp -= 4;
    sub_a96f9c(app, cpu);
    if (cpu.terminate) return;
L_0x00a977e5:
    // 00a977e5  8b15d41daa00           -mov edx, dword ptr [0xaa1dd4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11148756) /* 0xaa1dd4 */);
    // 00a977eb  42                     -inc edx
    (cpu.edx)++;
    // 00a977ec  a1d81daa00             -mov eax, dword ptr [0xaa1dd8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11148760) /* 0xaa1dd8 */);
    // 00a977f1  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 00a977f4  e8a7180000             -call 0xa990a0
    cpu.esp -= 4;
    sub_a990a0(app, cpu);
    if (cpu.terminate) return;
    // 00a977f9  a3d81daa00             -mov dword ptr [0xaa1dd8], eax
    app->getMemory<x86::reg32>(x86::reg32(11148760) /* 0xaa1dd8 */) = cpu.eax;
    // 00a977fe  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a97800  750f                   -jne 0xa97811
    if (!cpu.flags.zf)
    {
        goto L_0x00a97811;
    }
    // 00a97802  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00a97807  b884eda900             -mov eax, 0xa9ed84
    cpu.eax = 11136388 /*0xa9ed84*/;
    // 00a9780c  e88bf7ffff             -call 0xa96f9c
    cpu.esp -= 4;
    sub_a96f9c(app, cpu);
    if (cpu.terminate) return;
L_0x00a97811:
    // 00a97811  a1d41daa00             -mov eax, dword ptr [0xaa1dd4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11148756) /* 0xaa1dd4 */);
    // 00a97816  8b15d81daa00           -mov edx, dword ptr [0xaa1dd8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11148760) /* 0xaa1dd8 */);
    // 00a9781c  8d4801                 -lea ecx, [eax + 1]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a9781f  891c82                 -mov dword ptr [edx + eax*4], ebx
    app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 4) = cpu.ebx;
    // 00a97822  890dd41daa00           -mov dword ptr [0xaa1dd4], ecx
    app->getMemory<x86::reg32>(x86::reg32(11148756) /* 0xaa1dd4 */) = cpu.ecx;
L_0x00a97828:
    // 00a97828  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a97829  2eff1508cea900         -call dword ptr cs:[0xa9ce08]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11128328) /* 0xa9ce08 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a97830  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a97832  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a97833  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a97834  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a97835  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a97836  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void sub_a97838(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a97838  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a97839  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a9783a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a9783b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a9783c  8b15d01daa00           -mov edx, dword ptr [0xaa1dd0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11148752) /* 0xaa1dd0 */);
    // 00a97842  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00a97844  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a97846  7e1b                   -jle 0xa97863
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a97863;
    }
    // 00a97848  bba017aa00             -mov ebx, 0xaa17a0
    cpu.ebx = 11147168 /*0xaa17a0*/;
L_0x00a9784d:
    // 00a9784d  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a9784e  46                     -inc esi
    (cpu.esi)++;
    // 00a9784f  2eff1598cda900         -call dword ptr cs:[0xa9cd98]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11128216) /* 0xa9cd98 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a97856  8b0dd01daa00           -mov ecx, dword ptr [0xaa1dd0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11148752) /* 0xaa1dd0 */);
    // 00a9785c  83c318                 -add ebx, 0x18
    (cpu.ebx) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00a9785f  39ce                   +cmp esi, ecx
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a97861  7cea                   -jl 0xa9784d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a9784d;
    }
L_0x00a97863:
    // 00a97863  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a97864  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a97865  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a97866  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a97867  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a97868(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a97868  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a97869  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a9786a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a9786b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a9786c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a9786d  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a9786e  8b15d41daa00           -mov edx, dword ptr [0xaa1dd4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11148756) /* 0xaa1dd4 */);
    // 00a97874  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00a97876  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a97878  7e2d                   -jle 0xa978a7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a978a7;
    }
    // 00a9787a  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x00a9787c:
    // 00a9787c  a1d81daa00             -mov eax, dword ptr [0xaa1dd8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11148760) /* 0xaa1dd8 */);
    // 00a97881  8b0c03                 -mov ecx, dword ptr [ebx + eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + cpu.eax * 1);
    // 00a97884  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a97885  2eff1598cda900         -call dword ptr cs:[0xa9cd98]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11128216) /* 0xa9cd98 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a9788c  a1d81daa00             -mov eax, dword ptr [0xaa1dd8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11148760) /* 0xaa1dd8 */);
    // 00a97891  8b0403                 -mov eax, dword ptr [ebx + eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + cpu.eax * 1);
    // 00a97894  46                     -inc esi
    (cpu.esi)++;
    // 00a97895  e8d6d4ffff             -call 0xa94d70
    cpu.esp -= 4;
    sub_a94d70(app, cpu);
    if (cpu.terminate) return;
    // 00a9789a  8b3dd41daa00           -mov edi, dword ptr [0xaa1dd4]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(11148756) /* 0xaa1dd4 */);
    // 00a978a0  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a978a3  39fe                   +cmp esi, edi
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a978a5  7cd5                   -jl 0xa9787c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a9787c;
    }
L_0x00a978a7:
    // 00a978a7  8b2dd81daa00           -mov ebp, dword ptr [0xaa1dd8]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(11148760) /* 0xaa1dd8 */);
    // 00a978ad  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00a978af  7407                   -je 0xa978b8
    if (cpu.flags.zf)
    {
        goto L_0x00a978b8;
    }
    // 00a978b1  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00a978b3  e8b8d4ffff             -call 0xa94d70
    cpu.esp -= 4;
    sub_a94d70(app, cpu);
    if (cpu.terminate) return;
L_0x00a978b8:
    // 00a978b8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a978b9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a978ba  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a978bb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a978bc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a978bd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a978be  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void sub_a978c0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a978c0  c7400800000000         -mov dword ptr [eax + 8], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 00a978c7  c7400c00000000         -mov dword ptr [eax + 0xc], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 00a978ce  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void sub_a978d0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a978d0  b87016aa00             -mov eax, 0xaa1670
    cpu.eax = 11146864 /*0xaa1670*/;
    // 00a978d5  e992000000             -jmp 0xa9796c
    return sub_a9796c(app, cpu);
}

}
