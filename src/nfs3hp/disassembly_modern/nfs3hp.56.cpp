#include "nfs3hp.h"
#include <lib/thread.h>

namespace nfs3hp
{

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_52b4d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052b4d0  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0052b4d4  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0052b4d8  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0052b4dc  c1e102                 -shl ecx, 2
    cpu.ecx <<= 2 /*0x2*/ % 32;
    // 0052b4df  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0052b4e1  39c8                   +cmp eax, ecx
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
    // 0052b4e3  7313                   -jae 0x52b4f8
    if (!cpu.flags.cf)
    {
        goto L_0x0052b4f8;
    }
L_0x0052b4e5:
    // 0052b4e5  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 0052b4e7  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052b4ea  d84204                 -fadd dword ptr [edx + 4]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */));
    // 0052b4ed  83c208                 -add edx, 8
    (cpu.edx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0052b4f0  d958fc                 -fstp dword ptr [eax - 4]
    app->getMemory<float>(cpu.eax + x86::reg32(-4) /* -0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0052b4f3  39c8                   +cmp eax, ecx
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
    // 0052b4f5  72ee                   -jb 0x52b4e5
    if (cpu.flags.cf)
    {
        goto L_0x0052b4e5;
    }
    // 0052b4f7  90                     -nop 
    ;
L_0x0052b4f8:
    // 0052b4f8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_52b500(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052b500  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052b501  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0052b503  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0052b506  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0052b508  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0052b50b  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0052b50d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0052b50f  c1e007                 -shl eax, 7
    cpu.eax <<= 7 /*0x7*/ % 32;
    // 0052b512  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0052b514  05b4bc9f00             -add eax, 0x9fbcb4
    (cpu.eax) += x86::reg32(x86::sreg32(10468532 /*0x9fbcb4*/));
    // 0052b519  884803                 -mov byte ptr [eax + 3], cl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(3) /* 0x3 */) = cpu.cl;
    // 0052b51c  e83351fdff             -call 0x500654
    cpu.esp -= 4;
    sub_500654(app, cpu);
    if (cpu.terminate) return;
    // 0052b521  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052b522  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_52b523(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052b523  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052b524  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0052b526  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0052b527  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0052b528  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052b529  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0052b52a  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0052b52d  8a6518                 -mov ah, byte ptr [ebp + 0x18]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 0052b530  80fc01                 +cmp ah, 1
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0052b533  772f                   -ja 0x52b564
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0052b564;
    }
    // 0052b535  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 0052b537  7524                   -jne 0x52b55d
    if (!cpu.flags.zf)
    {
        goto L_0x0052b55d;
    }
    // 0052b539  d9ee                   +fldz 
    cpu.fpu.push(0.0);
    // 0052b53b  dc5d10                 +fcomp qword ptr [ebp + 0x10]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<double>(cpu.ebp + x86::reg32(16) /* 0x10 */)));
    cpu.fpu.pop();
    // 0052b53e  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0052b540  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 0052b541  730a                   -jae 0x52b54d
    if (!cpu.flags.cf)
    {
        goto L_0x0052b54d;
    }
    // 0052b543  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 0052b545  894de8                 -mov dword ptr [ebp - 0x18], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.ecx;
    // 0052b548  894dec                 -mov dword ptr [ebp - 0x14], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.ecx;
    // 0052b54b  eb4f                   -jmp 0x52b59c
    goto L_0x0052b59c;
L_0x0052b54d:
    // 0052b54d  7607                   -jbe 0x52b556
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0052b556;
    }
    // 0052b54f  b847800000             -mov eax, 0x8047
    cpu.eax = 32839 /*0x8047*/;
    // 0052b554  eb38                   -jmp 0x52b58e
    goto L_0x0052b58e;
L_0x0052b556:
    // 0052b556  b847400000             -mov eax, 0x4047
    cpu.eax = 16455 /*0x4047*/;
    // 0052b55b  eb31                   -jmp 0x52b58e
    goto L_0x0052b58e;
L_0x0052b55d:
    // 0052b55d  b847200000             -mov eax, 0x2047
    cpu.eax = 8263 /*0x2047*/;
    // 0052b562  eb2a                   -jmp 0x52b58e
    goto L_0x0052b58e;
L_0x0052b564:
    // 0052b564  d9ee                   +fldz 
    cpu.fpu.push(0.0);
    // 0052b566  dc5d10                 +fcomp qword ptr [ebp + 0x10]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<double>(cpu.ebp + x86::reg32(16) /* 0x10 */)));
    cpu.fpu.pop();
    // 0052b569  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0052b56b  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 0052b56c  720a                   -jb 0x52b578
    if (cpu.flags.cf)
    {
        goto L_0x0052b578;
    }
    // 0052b56e  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0052b570  8955e8                 -mov dword ptr [ebp - 0x18], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.edx;
    // 0052b573  8955ec                 -mov dword ptr [ebp - 0x14], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.edx;
    // 0052b576  eb24                   -jmp 0x52b59c
    goto L_0x0052b59c;
L_0x0052b578:
    // 0052b578  d9ee                   +fldz 
    cpu.fpu.push(0.0);
    // 0052b57a  dc5d08                 +fcomp qword ptr [ebp + 8]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<double>(cpu.ebp + x86::reg32(8) /* 0x8 */)));
    cpu.fpu.pop();
    // 0052b57d  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0052b57f  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 0052b580  7307                   -jae 0x52b589
    if (!cpu.flags.cf)
    {
        goto L_0x0052b589;
    }
    // 0052b582  b807810000             -mov eax, 0x8107
    cpu.eax = 33031 /*0x8107*/;
    // 0052b587  eb05                   -jmp 0x52b58e
    goto L_0x0052b58e;
L_0x0052b589:
    // 0052b589  b807110000             -mov eax, 0x1107
    cpu.eax = 4359 /*0x1107*/;
L_0x0052b58e:
    // 0052b58e  8d5d10                 -lea ebx, [ebp + 0x10]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0052b591  8d5508                 -lea edx, [ebp + 8]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0052b594  e8188effff             -call 0x5243b1
    cpu.esp -= 4;
    sub_5243b1(app, cpu);
    if (cpu.terminate) return;
    // 0052b599  dd5de8                 -fstp qword ptr [ebp - 0x18]
    app->getMemory<double>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x0052b59c:
    // 0052b59c  dd45e8                 -fld qword ptr [ebp - 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.ebp + x86::reg32(-24) /* -0x18 */)));
    // 0052b59f  8d65f0                 -lea esp, [ebp - 0x10]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0052b5a2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052b5a3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052b5a4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052b5a5  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052b5a6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052b5a7  c21400                 -ret 0x14
    cpu.esp += 4+20 /*0x14*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_52b5b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052b5b0  833d00b2a00000         +cmp dword ptr [0xa0b200], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10531328) /* 0xa0b200 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052b5b7  741c                   -je 0x52b5d5
    if (cpu.flags.zf)
    {
        goto L_0x0052b5d5;
    }
    // 0052b5b9  8a00                   -mov al, byte ptr [eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax);
    // 0052b5bb  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0052b5c0  8a8011b2a000           -mov al, byte ptr [eax + 0xa0b211]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(10531345) /* 0xa0b211 */);
    // 0052b5c6  2401                   -and al, 1
    cpu.al &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 0052b5c8  25ff000000             +and eax, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 0052b5cd  7406                   -je 0x52b5d5
    if (cpu.flags.zf)
    {
        goto L_0x0052b5d5;
    }
    // 0052b5cf  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 0052b5d4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052b5d5:
    // 0052b5d5  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0052b5da  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_52b5e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052b5e0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0052b5e1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052b5e2  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0052b5e5  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0052b5e7  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0052b5e9  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0052b5eb  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0052b5ed  e81e2d0000             -call 0x52e310
    cpu.esp -= 4;
    sub_52e310(app, cpu);
    if (cpu.terminate) return;
    // 0052b5f2  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0052b5f4  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 0052b5f6  e8b5ffffff             -call 0x52b5b0
    cpu.esp -= 4;
    sub_52b5b0(app, cpu);
    if (cpu.terminate) return;
    // 0052b5fb  881404                 -mov byte ptr [esp + eax], dl
    app->getMemory<x86::reg8>(cpu.esp + cpu.eax * 1) = cpu.dl;
    // 0052b5fe  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0052b602  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0052b604  e8072d0000             -call 0x52e310
    cpu.esp -= 4;
    sub_52e310(app, cpu);
    if (cpu.terminate) return;
    // 0052b609  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0052b60b  30f6                   -xor dh, dh
    cpu.dh ^= x86::reg8(x86::sreg8(cpu.dh));
    // 0052b60d  e89effffff             -call 0x52b5b0
    cpu.esp -= 4;
    sub_52b5b0(app, cpu);
    if (cpu.terminate) return;
    // 0052b612  88740404               -mov byte ptr [esp + eax + 4], dh
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */ + cpu.eax * 1) = cpu.dh;
    // 0052b616  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0052b618  e8332d0000             -call 0x52e350
    cpu.esp -= 4;
    sub_52e350(app, cpu);
    if (cpu.terminate) return;
    // 0052b61d  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0052b621  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0052b625  e8262d0000             -call 0x52e350
    cpu.esp -= 4;
    sub_52e350(app, cpu);
    if (cpu.terminate) return;
    // 0052b62a  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0052b62c  e86f2d0000             -call 0x52e3a0
    cpu.esp -= 4;
    sub_52e3a0(app, cpu);
    if (cpu.terminate) return;
    // 0052b631  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0052b634  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052b635  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052b636  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_52b640(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052b640  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_52b641(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052b641  a36cb15600             -mov dword ptr [0x56b16c], eax
    app->getMemory<x86::reg32>(x86::reg32(5681516) /* 0x56b16c */) = cpu.eax;
    // 0052b646  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_52b647(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052b647  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0052b648  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052b649  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052b64a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0052b64c  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0052b64e  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 0052b653  e8a82d0000             -call 0x52e400
    cpu.esp -= 4;
    sub_52e400(app, cpu);
    if (cpu.terminate) return;
    // 0052b658  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0052b65a  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0052b65c  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0052b65e  8b048550b15600         -mov eax, dword ptr [eax*4 + 0x56b150]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5681488) /* 0x56b150 */ + cpu.eax * 4);
    // 0052b665  e816c7fcff             -call 0x4f7d80
    cpu.esp -= 4;
    sub_4f7d80(app, cpu);
    if (cpu.terminate) return;
    // 0052b66a  b8ed1f5500             -mov eax, 0x551fed
    cpu.eax = 5578733 /*0x551fed*/;
    // 0052b66f  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0052b671  e80ac7fcff             -call 0x4f7d80
    cpu.esp -= 4;
    sub_4f7d80(app, cpu);
    if (cpu.terminate) return;
    // 0052b676  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0052b678  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0052b67a  e801c7fcff             -call 0x4f7d80
    cpu.esp -= 4;
    sub_4f7d80(app, cpu);
    if (cpu.terminate) return;
    // 0052b67f  b80a000000             -mov eax, 0xa
    cpu.eax = 10 /*0xa*/;
    // 0052b684  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0052b686  e825e1fdff             -call 0x5097b0
    cpu.esp -= 4;
    sub_5097b0(app, cpu);
    if (cpu.terminate) return;
    // 0052b68b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052b68c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052b68d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052b68e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_52b68f(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052b68f  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0052b690  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0052b691  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0052b693  ff156cb15600           -call dword ptr [0x56b16c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5681516) /* 0x56b16c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0052b699  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052b69b  751b                   -jne 0x52b6b8
    if (!cpu.flags.zf)
    {
        goto L_0x0052b6b8;
    }
    // 0052b69d  8b5304                 -mov edx, dword ptr [ebx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0052b6a0  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 0052b6a2  e8a0ffffff             -call 0x52b647
    cpu.esp -= 4;
    sub_52b647(app, cpu);
    if (cpu.terminate) return;
    // 0052b6a7  833b01                 +cmp dword ptr [ebx], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052b6aa  7507                   -jne 0x52b6b3
    if (!cpu.flags.zf)
    {
        goto L_0x0052b6b3;
    }
    // 0052b6ac  e8df71fdff             -call 0x502890
    cpu.esp -= 4;
    sub_502890(app, cpu);
    if (cpu.terminate) return;
    // 0052b6b1  eb05                   -jmp 0x52b6b8
    goto L_0x0052b6b8;
L_0x0052b6b3:
    // 0052b6b3  e8ec71fdff             -call 0x5028a4
    cpu.esp -= 4;
    sub_5028a4(app, cpu);
    if (cpu.terminate) return;
L_0x0052b6b8:
    // 0052b6b8  dd4318                 -fld qword ptr [ebx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.ebx + x86::reg32(24) /* 0x18 */)));
    // 0052b6bb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052b6bc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052b6bd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_52b6c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052b6c0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052b6c1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0052b6c2  8b7c240c               -mov edi, dword ptr [esp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0052b6c6  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0052b6c8  7c3b                   -jl 0x52b705
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0052b705;
    }
L_0x0052b6ca:
    // 0052b6ca  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0052b6cc  7c3b                   -jl 0x52b709
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0052b709;
    }
L_0x0052b6ce:
    // 0052b6ce  8b7004                 -mov esi, dword ptr [eax + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0052b6d1  39f2                   +cmp edx, esi
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
    // 0052b6d3  7e02                   -jle 0x52b6d7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0052b6d7;
    }
    // 0052b6d5  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
L_0x0052b6d7:
    // 0052b6d7  39f1                   +cmp ecx, esi
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
    // 0052b6d9  7e02                   -jle 0x52b6dd
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0052b6dd;
    }
    // 0052b6db  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
L_0x0052b6dd:
    // 0052b6dd  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0052b6df  7c2c                   -jl 0x52b70d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0052b70d;
    }
L_0x0052b6e1:
    // 0052b6e1  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0052b6e3  7c2c                   -jl 0x52b711
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0052b711;
    }
L_0x0052b6e5:
    // 0052b6e5  8b7008                 -mov esi, dword ptr [eax + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0052b6e8  39f3                   +cmp ebx, esi
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
    // 0052b6ea  7e02                   -jle 0x52b6ee
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0052b6ee;
    }
    // 0052b6ec  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
L_0x0052b6ee:
    // 0052b6ee  39f7                   +cmp edi, esi
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052b6f0  7e02                   -jle 0x52b6f4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0052b6f4;
    }
    // 0052b6f2  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
L_0x0052b6f4:
    // 0052b6f4  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 0052b6f7  895810                 -mov dword ptr [eax + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 0052b6fa  897818                 -mov dword ptr [eax + 0x18], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.edi;
    // 0052b6fd  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0052b700  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052b701  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052b702  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x0052b705:
    // 0052b705  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0052b707  ebc1                   -jmp 0x52b6ca
    goto L_0x0052b6ca;
L_0x0052b709:
    // 0052b709  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 0052b70b  ebc1                   -jmp 0x52b6ce
    goto L_0x0052b6ce;
L_0x0052b70d:
    // 0052b70d  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 0052b70f  ebd0                   -jmp 0x52b6e1
    goto L_0x0052b6e1;
L_0x0052b711:
    // 0052b711  31ff                   +xor edi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 0052b713  ebd0                   -jmp 0x52b6e5
    goto L_0x0052b6e5;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_52b720(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052b720  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052b721  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0052b722  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052b723  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0052b726  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0052b728  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0052b72a  895c2408               -mov dword ptr [esp + 8], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 0052b72e  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 0052b730  39d8                   +cmp eax, ebx
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
    // 0052b732  0f8f84000000           -jg 0x52b7bc
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0052b7bc;
    }
L_0x0052b738:
    // 0052b738  39fd                   +cmp ebp, edi
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052b73a  7d06                   -jge 0x52b742
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0052b742;
    }
    // 0052b73c  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0052b73e  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 0052b740  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
L_0x0052b742:
    // 0052b742  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0052b746  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0052b748  8b4c241c               -mov ecx, dword ptr [esp + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0052b74c  40                     -inc eax
    (cpu.eax)++;
    // 0052b74d  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0052b74f  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0052b752  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0052b754  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052b755  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 0052b757  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0052b75c  48                     -dec eax
    (cpu.eax)--;
    // 0052b75d  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0052b761  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0052b765  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0052b767  47                     -inc edi
    (cpu.edi)++;
    // 0052b768  e8d31dfdff             -call 0x4fd540
    cpu.esp -= 4;
    sub_4fd540(app, cpu);
    if (cpu.terminate) return;
    // 0052b76d  8b5c241c               -mov ebx, dword ptr [esp + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0052b771  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0052b775  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0052b779  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0052b77a  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0052b77c  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0052b781  e8ba1dfdff             -call 0x4fd540
    cpu.esp -= 4;
    sub_4fd540(app, cpu);
    if (cpu.terminate) return;
    // 0052b786  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0052b78a  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0052b78e  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0052b793  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0052b794  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0052b796  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0052b798  e8a31dfdff             -call 0x4fd540
    cpu.esp -= 4;
    sub_4fd540(app, cpu);
    if (cpu.terminate) return;
    // 0052b79d  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0052b7a1  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0052b7a6  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 0052b7a9  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0052b7aa  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0052b7ac  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0052b7ae  e88d1dfdff             -call 0x4fd540
    cpu.esp -= 4;
    sub_4fd540(app, cpu);
    if (cpu.terminate) return;
    // 0052b7b3  83c40c                 +add esp, 0xc
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(12 /*0xc*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0052b7b6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052b7b7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052b7b8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052b7b9  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x0052b7bc:
    // 0052b7bc  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 0052b7be  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0052b7c2  e971ffffff             -jmp 0x52b738
    goto L_0x0052b738;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_52b7d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052b7d0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0052b7d1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0052b7d2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0052b7d3  81ec04010000           -sub esp, 0x104
    (cpu.esp) -= x86::reg32(x86::sreg32(260 /*0x104*/));
    // 0052b7d9  813d9472560080b55000   +cmp dword ptr [0x567294], 0x50b580
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5665428) /* 0x567294 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5289344 /*0x50b580*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052b7e3  7444                   -je 0x52b829
    if (cpu.flags.zf)
    {
        goto L_0x0052b829;
    }
L_0x0052b7e5:
    // 0052b7e5  8d84241c010000         -lea eax, [esp + 0x11c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(284) /* 0x11c */);
    // 0052b7ec  8d9c2400010000         -lea ebx, [esp + 0x100]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 0052b7f3  8b942418010000         -mov edx, dword ptr [esp + 0x118]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(280) /* 0x118 */);
    // 0052b7fa  89842400010000         -mov dword ptr [esp + 0x100], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */) = cpu.eax;
    // 0052b801  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0052b803  e86c3efbff             -call 0x4df674
    cpu.esp -= 4;
    sub_4df674(app, cpu);
    if (cpu.terminate) return;
    // 0052b808  8b942414010000         -mov edx, dword ptr [esp + 0x114]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(276) /* 0x114 */);
    // 0052b80f  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0052b811  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0052b813  e848000000             -call 0x52b860
    cpu.esp -= 4;
    sub_52b860(app, cpu);
    if (cpu.terminate) return;
    // 0052b818  89bc2400010000         -mov dword ptr [esp + 0x100], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */) = cpu.edi;
    // 0052b81f  81c404010000           -add esp, 0x104
    (cpu.esp) += x86::reg32(x86::sreg32(260 /*0x104*/));
    // 0052b825  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052b826  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052b827  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052b828  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052b829:
    // 0052b829  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052b82a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052b82b  b9f41f5500             -mov ecx, 0x551ff4
    cpu.ecx = 5578740 /*0x551ff4*/;
    // 0052b830  bb04205500             -mov ebx, 0x552004
    cpu.ebx = 5578756 /*0x552004*/;
    // 0052b835  be3c000000             -mov esi, 0x3c
    cpu.esi = 60 /*0x3c*/;
    // 0052b83a  6810205500             -push 0x552010
    app->getMemory<x86::reg32>(cpu.esp-4) = 5578768 /*0x552010*/;
    cpu.esp -= 4;
    // 0052b83f  890d90215500           -mov dword ptr [0x552190], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ecx;
    // 0052b845  891d94215500           -mov dword ptr [0x552194], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebx;
    // 0052b84b  893598215500           -mov dword ptr [0x552198], esi
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.esi;
    // 0052b851  e8ba57edff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 0052b856  83c404                 +add esp, 4
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
    // 0052b859  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052b85a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052b85b  eb88                   -jmp 0x52b7e5
    goto L_0x0052b7e5;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_52b860(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052b860  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0052b861  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052b862  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052b863  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0052b864  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0052b866  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0052b868  e88346fcff             -call 0x4efef0
    cpu.esp -= 4;
    sub_4efef0(app, cpu);
    if (cpu.terminate) return;
    // 0052b86d  8b1584435600           -mov edx, dword ptr [0x564384]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5653380) /* 0x564384 */);
    // 0052b873  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0052b875  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0052b877  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0052b87a  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0052b87c  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 0052b87e  8b3df8715600           -mov edi, dword ptr [0x5671f8]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5665272) /* 0x5671f8 */);
    // 0052b884  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0052b886  8b35fc715600           -mov esi, dword ptr [0x5671fc]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5665276) /* 0x5671fc */);
    // 0052b88c  e8bf4ffcff             -call 0x4f0850
    cpu.esp -= 4;
    sub_4f0850(app, cpu);
    if (cpu.terminate) return;
    // 0052b891  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0052b893  e8b842fcff             -call 0x4efb50
    cpu.esp -= 4;
    sub_4efb50(app, cpu);
    if (cpu.terminate) return;
    // 0052b898  893df8715600           -mov dword ptr [0x5671f8], edi
    app->getMemory<x86::reg32>(x86::reg32(5665272) /* 0x5671f8 */) = cpu.edi;
    // 0052b89e  8935fc715600           -mov dword ptr [0x5671fc], esi
    app->getMemory<x86::reg32>(x86::reg32(5665276) /* 0x5671fc */) = cpu.esi;
    // 0052b8a4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052b8a5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052b8a6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052b8a7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052b8a8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_52b8b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052b8b0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0052b8b1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052b8b2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0052b8b3  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0052b8b6  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0052b8b9  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0052b8ba  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0052b8bc  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0052b8be  e8fdfdffff             -call 0x52b6c0
    cpu.esp -= 4;
    sub_52b6c0(app, cpu);
    if (cpu.terminate) return;
    // 0052b8c3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052b8c4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052b8c5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052b8c6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_52b8d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052b8d0  b870b15600             -mov eax, 0x56b170
    cpu.eax = 5681520 /*0x56b170*/;
    // 0052b8d5  e946bdf6ff             -jmp 0x497620
    return sub_497620(app, cpu);
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_52b8e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052b8e0  e83bf4fbff             -call 0x4ead20
    cpu.esp -= 4;
    sub_4ead20(app, cpu);
    if (cpu.terminate) return;
    // 0052b8e5  e9362b0000             -jmp 0x52e420
    return sub_52e420(app, cpu);
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_52b8f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052b8f0  e99bf4fbff             -jmp 0x4ead90
    return sub_4ead90(app, cpu);
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_52b910(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 0052b910  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0052b911  83f804                 +cmp eax, 4
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
    // 0052b914  7707                   -ja 0x52b91d
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0052b91d;
    }
    // 0052b916  ff2485f8b85200         -jmp dword ptr [eax*4 + 0x52b8f8]
    cpu.ip = app->getMemory<x86::reg32>(5421304 + cpu.eax * 4); goto dynamic_jump;
  case 0x0052b91d:
L_0x0052b91d:
    // 0052b91d  a1f84f5600             -mov eax, dword ptr [0x564ff8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5656568) /* 0x564ff8 */);
    // 0052b922  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0052b924  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0052b927  c1e203                 +shl edx, 3
    {
        x86::reg8 tmp = 3 /*0x3*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 0052b92a  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0052b92c  c1f803                 -sar eax, 3
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (3 /*0x3*/ % 32));
    // 0052b92f  99                     -cdq 
    cpu.edx_eax = x86::reg64(static_cast<x86::sreg32>(cpu.eax));
    // 0052b930  31d0                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0052b932  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0052b934  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052b935  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0052b936:
    // 0052b936  a1fc4f5600             -mov eax, dword ptr [0x564ffc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5656572) /* 0x564ffc */);
    // 0052b93b  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0052b93d  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0052b940  c1e203                 +shl edx, 3
    {
        x86::reg8 tmp = 3 /*0x3*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 0052b943  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0052b945  c1f803                 -sar eax, 3
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (3 /*0x3*/ % 32));
    // 0052b948  99                     -cdq 
    cpu.edx_eax = x86::reg64(static_cast<x86::sreg32>(cpu.eax));
    // 0052b949  31d0                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0052b94b  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0052b94d  48                     -dec eax
    (cpu.eax)--;
    // 0052b94e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052b94f  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0052b950:
    // 0052b950  a1f84f5600             -mov eax, dword ptr [0x564ff8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5656568) /* 0x564ff8 */);
    // 0052b955  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052b956  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0052b957:
    // 0052b957  a1fc4f5600             -mov eax, dword ptr [0x564ffc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5656572) /* 0x564ffc */);
    // 0052b95c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052b95d  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0052b95e:
    // 0052b95e  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0052b963  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052b964  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    return app->dynamic_call(cpu.ip, cpu);
  }
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_52b970(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052b970  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0052b971  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052b972  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0052b973  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052b974  81ec04010000           -sub esp, 0x104
    (cpu.esp) -= x86::reg32(x86::sreg32(260 /*0x104*/));
    // 0052b97a  8bb4241c010000         -mov esi, dword ptr [esp + 0x11c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(284) /* 0x11c */);
    // 0052b981  8b8c2418010000         -mov ecx, dword ptr [esp + 0x118]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(280) /* 0x118 */);
    // 0052b988  8d842424010000         -lea eax, [esp + 0x124]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(292) /* 0x124 */);
    // 0052b98f  8d9c2400010000         -lea ebx, [esp + 0x100]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 0052b996  8b942420010000         -mov edx, dword ptr [esp + 0x120]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(288) /* 0x120 */);
    // 0052b99d  c1e603                 -shl esi, 3
    cpu.esi <<= 3 /*0x3*/ % 32;
    // 0052b9a0  89842400010000         -mov dword ptr [esp + 0x100], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */) = cpu.eax;
    // 0052b9a7  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0052b9a9  c1e103                 -shl ecx, 3
    cpu.ecx <<= 3 /*0x3*/ % 32;
    // 0052b9ac  e8c33cfbff             -call 0x4df674
    cpu.esp -= 4;
    sub_4df674(app, cpu);
    if (cpu.terminate) return;
    // 0052b9b1  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0052b9b3  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0052b9b5  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0052b9b7  e8242b0000             -call 0x52e4e0
    cpu.esp -= 4;
    sub_52e4e0(app, cpu);
    if (cpu.terminate) return;
    // 0052b9bc  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0052b9be  89942400010000         -mov dword ptr [esp + 0x100], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */) = cpu.edx;
    // 0052b9c5  81c404010000           -add esp, 0x104
    (cpu.esp) += x86::reg32(x86::sreg32(260 /*0x104*/));
    // 0052b9cb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052b9cc  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052b9cd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052b9ce  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052b9cf  90                     -nop 
    ;
    // 0052b9d0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_52b9d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x0052b9d0;
    // 0052b970  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0052b971  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052b972  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0052b973  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052b974  81ec04010000           -sub esp, 0x104
    (cpu.esp) -= x86::reg32(x86::sreg32(260 /*0x104*/));
    // 0052b97a  8bb4241c010000         -mov esi, dword ptr [esp + 0x11c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(284) /* 0x11c */);
    // 0052b981  8b8c2418010000         -mov ecx, dword ptr [esp + 0x118]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(280) /* 0x118 */);
    // 0052b988  8d842424010000         -lea eax, [esp + 0x124]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(292) /* 0x124 */);
    // 0052b98f  8d9c2400010000         -lea ebx, [esp + 0x100]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 0052b996  8b942420010000         -mov edx, dword ptr [esp + 0x120]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(288) /* 0x120 */);
    // 0052b99d  c1e603                 -shl esi, 3
    cpu.esi <<= 3 /*0x3*/ % 32;
    // 0052b9a0  89842400010000         -mov dword ptr [esp + 0x100], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */) = cpu.eax;
    // 0052b9a7  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0052b9a9  c1e103                 -shl ecx, 3
    cpu.ecx <<= 3 /*0x3*/ % 32;
    // 0052b9ac  e8c33cfbff             -call 0x4df674
    cpu.esp -= 4;
    sub_4df674(app, cpu);
    if (cpu.terminate) return;
    // 0052b9b1  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0052b9b3  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0052b9b5  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0052b9b7  e8242b0000             -call 0x52e4e0
    cpu.esp -= 4;
    sub_52e4e0(app, cpu);
    if (cpu.terminate) return;
    // 0052b9bc  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0052b9be  89942400010000         -mov dword ptr [esp + 0x100], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */) = cpu.edx;
    // 0052b9c5  81c404010000           -add esp, 0x104
    (cpu.esp) += x86::reg32(x86::sreg32(260 /*0x104*/));
    // 0052b9cb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052b9cc  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052b9cd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052b9ce  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052b9cf  90                     -nop 
    ;
L_entry_0x0052b9d0:
    // 0052b9d0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_52b9e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052b9e0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052b9e1  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0052b9e3  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0052b9e5  b8000000ff             -mov eax, 0xff000000
    cpu.eax = 4278190080 /*0xff000000*/;
    // 0052b9ea  e8713dfcff             -call 0x4ef760
    cpu.esp -= 4;
    sub_4ef760(app, cpu);
    if (cpu.terminate) return;
    // 0052b9ef  e8bc37fcff             -call 0x4ef1b0
    cpu.esp -= 4;
    sub_4ef1b0(app, cpu);
    if (cpu.terminate) return;
    // 0052b9f4  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0052b9f6  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0052b9f8  e8c34ffcff             -call 0x4f09c0
    cpu.esp -= 4;
    sub_4f09c0(app, cpu);
    if (cpu.terminate) return;
    // 0052b9fd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052b9fe  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_52ba00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052ba00  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052ba01  e86a000000             -call 0x52ba70
    cpu.esp -= 4;
    sub_52ba70(app, cpu);
    if (cpu.terminate) return;
    // 0052ba06  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0052ba08  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0052ba0a  e861000000             -call 0x52ba70
    cpu.esp -= 4;
    sub_52ba70(app, cpu);
    if (cpu.terminate) return;
    // 0052ba0f  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0052ba11  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0052ba13  e8183efcff             -call 0x4ef830
    cpu.esp -= 4;
    sub_4ef830(app, cpu);
    if (cpu.terminate) return;
    // 0052ba18  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052ba19  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_52ba70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 0052ba70  83f812                 +cmp eax, 0x12
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(18 /*0x12*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052ba73  7707                   -ja 0x52ba7c
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0052ba7c;
    }
    // 0052ba75  ff24851cba5200         -jmp dword ptr [eax*4 + 0x52ba1c]
    cpu.ip = app->getMemory<x86::reg32>(5421596 + cpu.eax * 4); goto dynamic_jump;
  case 0x0052ba7c:
L_0x0052ba7c:
    // 0052ba7c  b8aaaa00ff             -mov eax, 0xff00aaaa
    cpu.eax = 4278233770 /*0xff00aaaa*/;
    // 0052ba81  e9da3cfcff             -jmp 0x4ef760
    return sub_4ef760(app, cpu);
  case 0x0052ba86:
    // 0052ba86  b8000000ff             -mov eax, 0xff000000
    cpu.eax = 4278190080 /*0xff000000*/;
    // 0052ba8b  e9d03cfcff             -jmp 0x4ef760
    return sub_4ef760(app, cpu);
  case 0x0052ba90:
    // 0052ba90  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0052ba95  e9c63cfcff             -jmp 0x4ef760
    return sub_4ef760(app, cpu);
  case 0x0052ba9a:
    // 0052ba9a  b80000aaff             -mov eax, 0xffaa0000
    cpu.eax = 4289331200 /*0xffaa0000*/;
    // 0052ba9f  e9bc3cfcff             -jmp 0x4ef760
    return sub_4ef760(app, cpu);
  case 0x0052baa4:
    // 0052baa4  b850ffffff             -mov eax, 0xffffff50
    cpu.eax = 4294967120 /*0xffffff50*/;
    // 0052baa9  e9b23cfcff             -jmp 0x4ef760
    return sub_4ef760(app, cpu);
  case 0x0052baae:
    // 0052baae  b8aa0000ff             -mov eax, 0xff0000aa
    cpu.eax = 4278190250 /*0xff0000aa*/;
    // 0052bab3  e9a83cfcff             -jmp 0x4ef760
    return sub_4ef760(app, cpu);
  default:
    return app->dynamic_call(cpu.ip, cpu);
  }
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_52bac0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052bac0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0052bac1  b8e0004f00             -mov eax, 0x4f00e0
    cpu.eax = 5177568 /*0x4f00e0*/;
    // 0052bac6  e82546fcff             -call 0x4f00f0
    cpu.esp -= 4;
    sub_4f00f0(app, cpu);
    if (cpu.terminate) return;
L_0x0052bacb:
    // 0052bacb  e85046fcff             -call 0x4f0120
    cpu.esp -= 4;
    sub_4f0120(app, cpu);
    if (cpu.terminate) return;
    // 0052bad0  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0052bad2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052bad4  74f5                   -je 0x52bacb
    if (cpu.flags.zf)
    {
        goto L_0x0052bacb;
    }
    // 0052bad6  83f861                 +cmp eax, 0x61
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
    // 0052bad9  7c08                   -jl 0x52bae3
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0052bae3;
    }
    // 0052badb  83f87a                 +cmp eax, 0x7a
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
    // 0052bade  7f03                   -jg 0x52bae3
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0052bae3;
    }
    // 0052bae0  8d50e0                 -lea edx, [eax - 0x20]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(-32) /* -0x20 */);
L_0x0052bae3:
    // 0052bae3  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0052bae5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052bae6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_52baf0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052baf0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052baf1  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0052baf3  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0052baf7  e874ffffff             -call 0x52ba70
    cpu.esp -= 4;
    sub_52ba70(app, cpu);
    if (cpu.terminate) return;
    // 0052bafc  c1e603                 -shl esi, 3
    cpu.esi <<= 3 /*0x3*/ % 32;
    // 0052baff  c1e203                 -shl edx, 3
    cpu.edx <<= 3 /*0x3*/ % 32;
    // 0052bb02  c1e303                 -shl ebx, 3
    cpu.ebx <<= 3 /*0x3*/ % 32;
    // 0052bb05  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0052bb06  c1e103                 -shl ecx, 3
    cpu.ecx <<= 3 /*0x3*/ % 32;
    // 0052bb09  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0052bb0b  e8301afdff             -call 0x4fd540
    cpu.esp -= 4;
    sub_4fd540(app, cpu);
    if (cpu.terminate) return;
    // 0052bb10  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052bb11  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_52bb20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052bb20  b898b15600             -mov eax, 0x56b198
    cpu.eax = 5681560 /*0x56b198*/;
    // 0052bb25  e9f6baf6ff             -jmp 0x497620
    return sub_497620(app, cpu);
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_52bb50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 0052bb50  83f804                 +cmp eax, 4
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
    // 0052bb53  7707                   -ja 0x52bb5c
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0052bb5c;
    }
    // 0052bb55  ff248534bb5200         -jmp dword ptr [eax*4 + 0x52bb34]
    cpu.ip = app->getMemory<x86::reg32>(5421876 + cpu.eax * 4); goto dynamic_jump;
  case 0x0052bb5c:
L_0x0052bb5c:
    // 0052bb5c  b850000000             -mov eax, 0x50
    cpu.eax = 80 /*0x50*/;
    // 0052bb61  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0052bb62:
    // 0052bb62  b818000000             -mov eax, 0x18
    cpu.eax = 24 /*0x18*/;
    // 0052bb67  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0052bb68:
    // 0052bb68  a1f84f5600             -mov eax, dword ptr [0x564ff8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5656568) /* 0x564ff8 */);
    // 0052bb6d  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0052bb6e:
    // 0052bb6e  a1fc4f5600             -mov eax, dword ptr [0x564ffc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5656572) /* 0x564ffc */);
    // 0052bb73  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0052bb74:
    // 0052bb74  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0052bb76  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    return app->dynamic_call(cpu.ip, cpu);
  }
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_52bb80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052bb80  e91b51fbff             -jmp 0x4e0ca0
    return sub_4e0ca0(app, cpu);
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_52bb90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052bb90  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052bb91  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0052bb93  e888f1fbff             -call 0x4ead20
    cpu.esp -= 4;
    sub_4ead20(app, cpu);
    if (cpu.terminate) return;
    // 0052bb98  e883280000             -call 0x52e420
    cpu.esp -= 4;
    sub_52e420(app, cpu);
    if (cpu.terminate) return;
    // 0052bb9d  8b5602                 -mov edx, dword ptr [esi + 2]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 0052bba0  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 0052bba5  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0052bba8  e8a3ffffff             -call 0x52bb50
    cpu.esp -= 4;
    sub_52bb50(app, cpu);
    if (cpu.terminate) return;
    // 0052bbad  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0052bbaf  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0052bbb2  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0052bbb4  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 0052bbb9  c1fb10                 -sar ebx, 0x10
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (16 /*0x10*/ % 32));
    // 0052bbbc  e88fffffff             -call 0x52bb50
    cpu.esp -= 4;
    sub_52bb50(app, cpu);
    if (cpu.terminate) return;
    // 0052bbc1  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0052bbc3  d1fa                   -sar edx, 1
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (1 /*0x1*/ % 32));
    // 0052bbc5  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0052bbc7  b8000000ff             -mov eax, 0xff000000
    cpu.eax = 4278190080 /*0xff000000*/;
    // 0052bbcc  d1fb                   -sar ebx, 1
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (1 /*0x1*/ % 32));
    // 0052bbce  e88d3bfcff             -call 0x4ef760
    cpu.esp -= 4;
    sub_4ef760(app, cpu);
    if (cpu.terminate) return;
    // 0052bbd3  e8d835fcff             -call 0x4ef1b0
    cpu.esp -= 4;
    sub_4ef1b0(app, cpu);
    if (cpu.terminate) return;
    // 0052bbd8  e8c350fbff             -call 0x4e0ca0
    cpu.esp -= 4;
    sub_4e0ca0(app, cpu);
    if (cpu.terminate) return;
    // 0052bbdd  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0052bbdf  e8dc4dfcff             -call 0x4f09c0
    cpu.esp -= 4;
    sub_4f09c0(app, cpu);
    if (cpu.terminate) return;
    // 0052bbe4  e8a7f1fbff             -call 0x4ead90
    cpu.esp -= 4;
    sub_4ead90(app, cpu);
    if (cpu.terminate) return;
    // 0052bbe9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052bbea  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_52bbf0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052bbf0  e80b010000             -call 0x52bd00
    cpu.esp -= 4;
    sub_52bd00(app, cpu);
    if (cpu.terminate) return;
    // 0052bbf5  e95651fbff             -jmp 0x4e0d50
    return sub_4e0d50(app, cpu);
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_52bc00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052bc00  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0052bc01  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052bc02  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0052bc03  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052bc04  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052bc05  81ec04010000           -sub esp, 0x104
    (cpu.esp) -= x86::reg32(x86::sreg32(260 /*0x104*/));
    // 0052bc0b  8b8c241c010000         -mov ecx, dword ptr [esp + 0x11c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(284) /* 0x11c */);
    // 0052bc12  8bb42420010000         -mov esi, dword ptr [esp + 0x120]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(288) /* 0x120 */);
    // 0052bc19  8b1594725600           -mov edx, dword ptr [0x567294]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5665428) /* 0x567294 */);
    // 0052bc1f  c1e103                 -shl ecx, 3
    cpu.ecx <<= 3 /*0x3*/ % 32;
    // 0052bc22  c1e603                 -shl esi, 3
    cpu.esi <<= 3 /*0x3*/ % 32;
    // 0052bc25  81fa80b55000           +cmp edx, 0x50b580
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5289344 /*0x50b580*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052bc2b  7452                   -je 0x52bc7f
    if (cpu.flags.zf)
    {
        goto L_0x0052bc7f;
    }
L_0x0052bc2d:
    // 0052bc2d  8d842428010000         -lea eax, [esp + 0x128]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(296) /* 0x128 */);
    // 0052bc34  8d9c2400010000         -lea ebx, [esp + 0x100]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 0052bc3b  8b942424010000         -mov edx, dword ptr [esp + 0x124]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(292) /* 0x124 */);
    // 0052bc42  89842400010000         -mov dword ptr [esp + 0x100], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */) = cpu.eax;
    // 0052bc49  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0052bc4b  e8243afbff             -call 0x4df674
    cpu.esp -= 4;
    sub_4df674(app, cpu);
    if (cpu.terminate) return;
    // 0052bc50  e8cbf0fbff             -call 0x4ead20
    cpu.esp -= 4;
    sub_4ead20(app, cpu);
    if (cpu.terminate) return;
    // 0052bc55  e8c6270000             -call 0x52e420
    cpu.esp -= 4;
    sub_52e420(app, cpu);
    if (cpu.terminate) return;
    // 0052bc5a  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0052bc5c  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0052bc5e  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0052bc60  e87b280000             -call 0x52e4e0
    cpu.esp -= 4;
    sub_52e4e0(app, cpu);
    if (cpu.terminate) return;
    // 0052bc65  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0052bc67  89842400010000         -mov dword ptr [esp + 0x100], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */) = cpu.eax;
    // 0052bc6e  e81df1fbff             -call 0x4ead90
    cpu.esp -= 4;
    sub_4ead90(app, cpu);
    if (cpu.terminate) return;
    // 0052bc73  81c404010000           -add esp, 0x104
    (cpu.esp) += x86::reg32(x86::sreg32(260 /*0x104*/));
    // 0052bc79  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052bc7a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052bc7b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052bc7c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052bc7d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052bc7e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052bc7f:
    // 0052bc7f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0052bc80  bb50205500             -mov ebx, 0x552050
    cpu.ebx = 5578832 /*0x552050*/;
    // 0052bc85  bf60205500             -mov edi, 0x552060
    cpu.edi = 5578848 /*0x552060*/;
    // 0052bc8a  bd72000000             -mov ebp, 0x72
    cpu.ebp = 114 /*0x72*/;
    // 0052bc8f  6874205500             -push 0x552074
    app->getMemory<x86::reg32>(cpu.esp-4) = 5578868 /*0x552074*/;
    cpu.esp -= 4;
    // 0052bc94  891d90215500           -mov dword ptr [0x552190], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ebx;
    // 0052bc9a  893d94215500           -mov dword ptr [0x552194], edi
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.edi;
    // 0052bca0  892d98215500           -mov dword ptr [0x552198], ebp
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ebp;
    // 0052bca6  e86553edff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 0052bcab  83c404                 +add esp, 4
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
    // 0052bcae  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052bcaf  e979ffffff             -jmp 0x52bc2d
    goto L_0x0052bc2d;
}

/* align: skip  */
void Application::sub_52bd00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 0052bd00  83f812                 +cmp eax, 0x12
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(18 /*0x12*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052bd03  7707                   -ja 0x52bd0c
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0052bd0c;
    }
    // 0052bd05  ff2485b4bc5200         -jmp dword ptr [eax*4 + 0x52bcb4]
    cpu.ip = app->getMemory<x86::reg32>(5422260 + cpu.eax * 4); goto dynamic_jump;
  case 0x0052bd0c:
L_0x0052bd0c:
    // 0052bd0c  b807000000             -mov eax, 7
    cpu.eax = 7 /*0x7*/;
    // 0052bd11  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0052bd12:
    // 0052bd12  b870000000             -mov eax, 0x70
    cpu.eax = 112 /*0x70*/;
    // 0052bd17  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    return app->dynamic_call(cpu.ip, cpu);
  }
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_52bd20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052bd20  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0052bd21  b8e0004f00             -mov eax, 0x4f00e0
    cpu.eax = 5177568 /*0x4f00e0*/;
    // 0052bd26  e8c543fcff             -call 0x4f00f0
    cpu.esp -= 4;
    sub_4f00f0(app, cpu);
    if (cpu.terminate) return;
L_0x0052bd2b:
    // 0052bd2b  e8f043fcff             -call 0x4f0120
    cpu.esp -= 4;
    sub_4f0120(app, cpu);
    if (cpu.terminate) return;
    // 0052bd30  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0052bd32  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052bd34  74f5                   -je 0x52bd2b
    if (cpu.flags.zf)
    {
        goto L_0x0052bd2b;
    }
    // 0052bd36  83f861                 +cmp eax, 0x61
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
    // 0052bd39  7c08                   -jl 0x52bd43
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0052bd43;
    }
    // 0052bd3b  83f87a                 +cmp eax, 0x7a
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
    // 0052bd3e  7f03                   -jg 0x52bd43
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0052bd43;
    }
    // 0052bd40  8d50e0                 -lea edx, [eax - 0x20]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(-32) /* -0x20 */);
L_0x0052bd43:
    // 0052bd43  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0052bd45  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052bd46  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_52bd50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052bd50  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052bd51  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0052bd52  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052bd53  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0052bd56  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0052bd58  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 0052bd5b  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0052bd5d  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 0052bd5f  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0052bd63  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 0052bd66  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0052bd68  01cd                   -add ebp, ecx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0052bd6a  e881feffff             -call 0x52bbf0
    cpu.esp -= 4;
    sub_52bbf0(app, cpu);
    if (cpu.terminate) return;
    // 0052bd6f  39cd                   +cmp ebp, ecx
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052bd71  7e31                   -jle 0x52bda4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0052bda4;
    }
    // 0052bd73  89742408               -mov dword ptr [esp + 8], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.esi;
    // 0052bd77  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
L_0x0052bd7b:
    // 0052bd7b  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0052bd7d  7e20                   -jle 0x52bd9f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0052bd9f;
    }
    // 0052bd7f  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0052bd83  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0052bd87  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0052bd89  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
L_0x0052bd8b:
    // 0052bd8b  68b4205500             -push 0x5520b4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5578932 /*0x5520b4*/;
    cpu.esp -= 4;
    // 0052bd90  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052bd91  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0052bd92  e8e94bfbff             -call 0x4e0980
    cpu.esp -= 4;
    sub_4e0980(app, cpu);
    if (cpu.terminate) return;
    // 0052bd97  42                     -inc edx
    (cpu.edx)++;
    // 0052bd98  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0052bd9b  39da                   +cmp edx, ebx
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
    // 0052bd9d  7cec                   -jl 0x52bd8b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0052bd8b;
    }
L_0x0052bd9f:
    // 0052bd9f  41                     -inc ecx
    (cpu.ecx)++;
    // 0052bda0  39e9                   +cmp ecx, ebp
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
    // 0052bda2  7cd7                   -jl 0x52bd7b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0052bd7b;
    }
L_0x0052bda4:
    // 0052bda4  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0052bda7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052bda8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052bda9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052bdaa  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_52bdb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052bdb0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0052bdb1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052bdb2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0052bdb3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052bdb4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0052bdb5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052bdb6  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0052bdb9  b8b8205500             -mov eax, 0x5520b8
    cpu.eax = 5578936 /*0x5520b8*/;
    // 0052bdbe  e80d2dfeff             -call 0x50ead0
    cpu.esp -= 4;
    sub_50ead0(app, cpu);
    if (cpu.terminate) return;
    // 0052bdc3  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0052bdc5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052bdc7  0f84f9000000           -je 0x52bec6
    if (cpu.flags.zf)
    {
        goto L_0x0052bec6;
    }
L_0x0052bdcd:
    // 0052bdcd  803900                 +cmp byte ptr [ecx], 0
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
    // 0052bdd0  0f84e6000000           -je 0x52bebc
    if (cpu.flags.zf)
    {
        goto L_0x0052bebc;
    }
    // 0052bdd6  b23a                   -mov dl, 0x3a
    cpu.dl = 58 /*0x3a*/;
    // 0052bdd8  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
L_0x0052bdda:
    // 0052bdda  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0052bddc  3ac2                   +cmp al, dl
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
    // 0052bdde  7412                   -je 0x52bdf2
    if (cpu.flags.zf)
    {
        goto L_0x0052bdf2;
    }
    // 0052bde0  3c00                   +cmp al, 0
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
    // 0052bde2  740c                   -je 0x52bdf0
    if (cpu.flags.zf)
    {
        goto L_0x0052bdf0;
    }
    // 0052bde4  46                     -inc esi
    (cpu.esi)++;
    // 0052bde5  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0052bde7  3ac2                   +cmp al, dl
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
    // 0052bde9  7407                   -je 0x52bdf2
    if (cpu.flags.zf)
    {
        goto L_0x0052bdf2;
    }
    // 0052bdeb  46                     -inc esi
    (cpu.esi)++;
    // 0052bdec  3c00                   +cmp al, 0
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
    // 0052bdee  75ea                   -jne 0x52bdda
    if (!cpu.flags.zf)
    {
        goto L_0x0052bdda;
    }
L_0x0052bdf0:
    // 0052bdf0  2bf6                   -sub esi, esi
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.esi));
L_0x0052bdf2:
    // 0052bdf2  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0052bdf4  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
    // 0052bdf6  29ce                   -sub esi, ecx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0052bdf8  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0052bdfa  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0052bdfc  e82f50fbff             -call 0x4e0e30
    cpu.esp -= 4;
    sub_4e0e30(app, cpu);
    if (cpu.terminate) return;
    // 0052be01  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
    // 0052be06  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 0052be08  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0052be0a  881434                 -mov byte ptr [esp + esi], dl
    app->getMemory<x86::reg8>(cpu.esp + cpu.esi * 1) = cpu.dl;
    // 0052be0d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0052be0f  e84c280000             -call 0x52e660
    cpu.esp -= 4;
    sub_52e660(app, cpu);
    if (cpu.terminate) return;
    // 0052be14  8d7501                 -lea esi, [ebp + 1]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(1) /* 0x1 */);
    // 0052be17  b23a                   -mov dl, 0x3a
    cpu.dl = 58 /*0x3a*/;
    // 0052be19  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0052be1b  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
L_0x0052be1d:
    // 0052be1d  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0052be1f  3ac2                   +cmp al, dl
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
    // 0052be21  7412                   -je 0x52be35
    if (cpu.flags.zf)
    {
        goto L_0x0052be35;
    }
    // 0052be23  3c00                   +cmp al, 0
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
    // 0052be25  740c                   -je 0x52be33
    if (cpu.flags.zf)
    {
        goto L_0x0052be33;
    }
    // 0052be27  46                     -inc esi
    (cpu.esi)++;
    // 0052be28  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0052be2a  3ac2                   +cmp al, dl
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
    // 0052be2c  7407                   -je 0x52be35
    if (cpu.flags.zf)
    {
        goto L_0x0052be35;
    }
    // 0052be2e  46                     -inc esi
    (cpu.esi)++;
    // 0052be2f  3c00                   +cmp al, 0
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
    // 0052be31  75ea                   -jne 0x52be1d
    if (!cpu.flags.zf)
    {
        goto L_0x0052be1d;
    }
L_0x0052be33:
    // 0052be33  2bf6                   -sub esi, esi
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.esi));
L_0x0052be35:
    // 0052be35  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0052be37  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
    // 0052be39  29ce                   -sub esi, ecx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0052be3b  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0052be3d  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0052be3f  e8ec4ffbff             -call 0x4e0e30
    cpu.esp -= 4;
    sub_4e0e30(app, cpu);
    if (cpu.terminate) return;
    // 0052be44  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
    // 0052be49  30f6                   -xor dh, dh
    cpu.dh ^= x86::reg8(x86::sreg8(cpu.dh));
    // 0052be4b  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0052be4d  883434                 -mov byte ptr [esp + esi], dh
    app->getMemory<x86::reg8>(cpu.esp + cpu.esi * 1) = cpu.dh;
    // 0052be50  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0052be52  e809280000             -call 0x52e660
    cpu.esp -= 4;
    sub_52e660(app, cpu);
    if (cpu.terminate) return;
    // 0052be57  8d7501                 -lea esi, [ebp + 1]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(1) /* 0x1 */);
    // 0052be5a  b22a                   -mov dl, 0x2a
    cpu.dl = 42 /*0x2a*/;
    // 0052be5c  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0052be60  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
L_0x0052be62:
    // 0052be62  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0052be64  3ac2                   +cmp al, dl
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
    // 0052be66  7412                   -je 0x52be7a
    if (cpu.flags.zf)
    {
        goto L_0x0052be7a;
    }
    // 0052be68  3c00                   +cmp al, 0
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
    // 0052be6a  740c                   -je 0x52be78
    if (cpu.flags.zf)
    {
        goto L_0x0052be78;
    }
    // 0052be6c  46                     -inc esi
    (cpu.esi)++;
    // 0052be6d  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0052be6f  3ac2                   +cmp al, dl
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
    // 0052be71  7407                   -je 0x52be7a
    if (cpu.flags.zf)
    {
        goto L_0x0052be7a;
    }
    // 0052be73  46                     -inc esi
    (cpu.esi)++;
    // 0052be74  3c00                   +cmp al, 0
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
    // 0052be76  75ea                   -jne 0x52be62
    if (!cpu.flags.zf)
    {
        goto L_0x0052be62;
    }
L_0x0052be78:
    // 0052be78  2bf6                   -sub esi, esi
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.esi));
L_0x0052be7a:
    // 0052be7a  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0052be7c  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
    // 0052be7e  29ce                   -sub esi, ecx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0052be80  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0052be82  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0052be84  e8a74ffbff             -call 0x4e0e30
    cpu.esp -= 4;
    sub_4e0e30(app, cpu);
    if (cpu.terminate) return;
    // 0052be89  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0052be8b  30db                   -xor bl, bl
    cpu.bl ^= x86::reg8(x86::sreg8(cpu.bl));
    // 0052be8d  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0052be8f  881c34                 -mov byte ptr [esp + esi], bl
    app->getMemory<x86::reg8>(cpu.esp + cpu.esi * 1) = cpu.bl;
    // 0052be92  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
    // 0052be97  e8c4270000             -call 0x52e660
    cpu.esp -= 4;
    sub_52e660(app, cpu);
    if (cpu.terminate) return;
    // 0052be9c  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0052be9e  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0052bea0  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0052bea4  e8df24ffff             -call 0x51e388
    cpu.esp -= 4;
    sub_51e388(app, cpu);
    if (cpu.terminate) return;
    // 0052bea9  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0052beab  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0052bead  8d7501                 -lea esi, [ebp + 1]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(1) /* 0x1 */);
    // 0052beb0  e8836fffff             -call 0x522e38
    cpu.esp -= 4;
    sub_522e38(app, cpu);
    if (cpu.terminate) return;
    // 0052beb5  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0052beb7  e911ffffff             -jmp 0x52bdcd
    goto L_0x0052bdcd;
L_0x0052bebc:
    // 0052bebc  b8c4205500             -mov eax, 0x5520c4
    cpu.eax = 5578948 /*0x5520c4*/;
    // 0052bec1  e80a280000             -call 0x52e6d0
    cpu.esp -= 4;
    sub_52e6d0(app, cpu);
    if (cpu.terminate) return;
L_0x0052bec6:
    // 0052bec6  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0052bec9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052beca  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052becb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052becc  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052becd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052bece  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052becf  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_52bed0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052bed0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0052bed1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052bed2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0052bed3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052bed4  8b1554b1a000           -mov edx, dword ptr [0xa0b154]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10531156) /* 0xa0b154 */);
    // 0052beda  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0052bedc  0f8480000000           -je 0x52bf62
    if (cpu.flags.zf)
    {
        goto L_0x0052bf62;
    }
    // 0052bee2  eb30                   -jmp 0x52bf14
    goto L_0x0052bf14;
L_0x0052bee4:
    // 0052bee4  833d50b1a00000         +cmp dword ptr [0xa0b150], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10531152) /* 0xa0b150 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052beeb  7424                   -je 0x52bf11
    if (cpu.flags.zf)
    {
        goto L_0x0052bf11;
    }
    // 0052beed  8b3554b1a000           -mov esi, dword ptr [0xa0b154]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(10531156) /* 0xa0b154 */);
    // 0052bef3  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0052bef5  29f1                   -sub ecx, esi
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0052bef7  8b1d50b1a000           -mov ebx, dword ptr [0xa0b150]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10531152) /* 0xa0b150 */);
    // 0052befd  c1f902                 -sar ecx, 2
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (2 /*0x2*/ % 32));
    // 0052bf00  803c1900               +cmp byte ptr [ecx + ebx], 0
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
    // 0052bf04  7405                   -je 0x52bf0b
    if (cpu.flags.zf)
    {
        goto L_0x0052bf0b;
    }
    // 0052bf06  e8e5bafcff             -call 0x4f79f0
    cpu.esp -= 4;
    sub_4f79f0(app, cpu);
    if (cpu.terminate) return;
L_0x0052bf0b:
    // 0052bf0b  c70200000000           -mov dword ptr [edx], 0
    app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
L_0x0052bf11:
    // 0052bf11  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0052bf14:
    // 0052bf14  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 0052bf16  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052bf18  75ca                   -jne 0x52bee4
    if (!cpu.flags.zf)
    {
        goto L_0x0052bee4;
    }
    // 0052bf1a  833d50b1a00000         +cmp dword ptr [0xa0b150], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10531152) /* 0xa0b150 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052bf21  750c                   -jne 0x52bf2f
    if (!cpu.flags.zf)
    {
        goto L_0x0052bf2f;
    }
    // 0052bf23  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 0052bf28  e8d3b9fcff             -call 0x4f7900
    cpu.esp -= 4;
    sub_4f7900(app, cpu);
    if (cpu.terminate) return;
    // 0052bf2d  eb0f                   -jmp 0x52bf3e
    goto L_0x0052bf3e;
L_0x0052bf2f:
    // 0052bf2f  ba05000000             -mov edx, 5
    cpu.edx = 5 /*0x5*/;
    // 0052bf34  a154b1a000             -mov eax, dword ptr [0xa0b154]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10531156) /* 0xa0b154 */);
    // 0052bf39  e882c6feff             -call 0x5185c0
    cpu.esp -= 4;
    sub_5185c0(app, cpu);
    if (cpu.terminate) return;
L_0x0052bf3e:
    // 0052bf3e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052bf40  750a                   -jne 0x52bf4c
    if (!cpu.flags.zf)
    {
        goto L_0x0052bf4c;
    }
    // 0052bf42  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0052bf47  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052bf48  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052bf49  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052bf4a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052bf4b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052bf4c:
    // 0052bf4c  a354b1a000             -mov dword ptr [0xa0b154], eax
    app->getMemory<x86::reg32>(x86::reg32(10531156) /* 0xa0b154 */) = cpu.eax;
    // 0052bf51  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 0052bf57  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052bf5a  a350b1a000             -mov dword ptr [0xa0b150], eax
    app->getMemory<x86::reg32>(x86::reg32(10531152) /* 0xa0b150 */) = cpu.eax;
    // 0052bf5f  c60000                 -mov byte ptr [eax], 0
    app->getMemory<x86::reg8>(cpu.eax) = 0 /*0x0*/;
L_0x0052bf62:
    // 0052bf62  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0052bf64  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052bf65  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052bf66  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052bf67  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052bf68  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_52bf70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052bf70  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052bf71  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052bf72  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0052bf74  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0052bf76  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0052bf78  7505                   -jne 0x52bf7f
    if (!cpu.flags.zf)
    {
        goto L_0x0052bf7f;
    }
L_0x0052bf7a:
    // 0052bf7a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0052bf7c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052bf7d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052bf7e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052bf7f:
    // 0052bf7f  668b01                 -mov ax, word ptr [ecx]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ecx);
    // 0052bf82  668b16                 -mov dx, word ptr [esi]
    cpu.dx = app->getMemory<x86::reg16>(cpu.esi);
    // 0052bf85  f6c4ff                 +test ah, 0xff
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 255 /*0xff*/));
    // 0052bf88  7525                   -jne 0x52bfaf
    if (!cpu.flags.zf)
    {
        goto L_0x0052bfaf;
    }
    // 0052bf8a  f6c6ff                 +test dh, 0xff
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 255 /*0xff*/));
    // 0052bf8d  7520                   -jne 0x52bfaf
    if (!cpu.flags.zf)
    {
        goto L_0x0052bfaf;
    }
    // 0052bf8f  663d4100               +cmp ax, 0x41
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(65 /*0x41*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0052bf93  720b                   -jb 0x52bfa0
    if (cpu.flags.cf)
    {
        goto L_0x0052bfa0;
    }
    // 0052bf95  663d5a00               +cmp ax, 0x5a
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(90 /*0x5a*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0052bf99  7705                   -ja 0x52bfa0
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0052bfa0;
    }
    // 0052bf9b  0520000000             -add eax, 0x20
    (cpu.eax) += x86::reg32(x86::sreg32(32 /*0x20*/));
L_0x0052bfa0:
    // 0052bfa0  6683fa41               +cmp dx, 0x41
    {
        x86::reg16 tmp1 = cpu.dx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(65 /*0x41*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0052bfa4  7209                   -jb 0x52bfaf
    if (cpu.flags.cf)
    {
        goto L_0x0052bfaf;
    }
    // 0052bfa6  6683fa5a               +cmp dx, 0x5a
    {
        x86::reg16 tmp1 = cpu.dx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(90 /*0x5a*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0052bfaa  7703                   -ja 0x52bfaf
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0052bfaf;
    }
    // 0052bfac  83c220                 -add edx, 0x20
    (cpu.edx) += x86::reg32(x86::sreg32(32 /*0x20*/));
L_0x0052bfaf:
    // 0052bfaf  6639d0                 +cmp ax, dx
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(cpu.dx));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0052bfb2  740f                   -je 0x52bfc3
    if (cpu.flags.zf)
    {
        goto L_0x0052bfc3;
    }
    // 0052bfb4  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0052bfb6  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0052bfbb  6689d3                 -mov bx, dx
    cpu.bx = cpu.dx;
    // 0052bfbe  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0052bfc0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052bfc1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052bfc2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052bfc3:
    // 0052bfc3  6685d2                 +test dx, dx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.dx & cpu.dx));
    // 0052bfc6  7505                   -jne 0x52bfcd
    if (!cpu.flags.zf)
    {
        goto L_0x0052bfcd;
    }
    // 0052bfc8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0052bfca  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052bfcb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052bfcc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052bfcd:
    // 0052bfcd  83c102                 -add ecx, 2
    (cpu.ecx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0052bfd0  83c602                 +add esi, 2
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0052bfd3  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0052bfd4  74a4                   -je 0x52bf7a
    if (cpu.flags.zf)
    {
        goto L_0x0052bf7a;
    }
    // 0052bfd6  eba7                   -jmp 0x52bf7f
    goto L_0x0052bf7f;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_52bfe0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052bfe0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0052bfe1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052bfe2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0052bfe3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052bfe4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0052bfe5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052bfe6  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0052bfe9  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0052bfeb  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 0052bff0  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0052bff4  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 0052bff7  ba3d000000             -mov edx, 0x3d
    cpu.edx = 61 /*0x3d*/;
    // 0052bffc  e83f2b0000             -call 0x52eb40
    cpu.esp -= 4;
    sub_52eb40(app, cpu);
    if (cpu.terminate) return;
    // 0052c001  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0052c003  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052c005  750a                   -jne 0x52c011
    if (!cpu.flags.zf)
    {
        goto L_0x0052c011;
    }
    // 0052c007  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0052c00c  e95a010000             -jmp 0x52c16b
    goto L_0x0052c16b;
L_0x0052c011:
    // 0052c011  39c8                   +cmp eax, ecx
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
    // 0052c013  750f                   -jne 0x52c024
    if (!cpu.flags.zf)
    {
        goto L_0x0052c024;
    }
    // 0052c015  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0052c01a  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0052c01d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c01e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c01f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c020  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c021  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c022  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c023  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052c024:
    // 0052c024  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0052c026  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 0052c028  8d2c4500000000         -lea ebp, [eax*2]
    cpu.ebp = x86::reg32(cpu.eax * 2);
    // 0052c02f  8d4502                 -lea eax, [ebp + 2]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(2) /* 0x2 */);
    // 0052c032  e8c9b8fcff             -call 0x4f7900
    cpu.esp -= 4;
    sub_4f7900(app, cpu);
    if (cpu.terminate) return;
    // 0052c037  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0052c039  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0052c03d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052c03f  750f                   -jne 0x52c050
    if (!cpu.flags.zf)
    {
        goto L_0x0052c050;
    }
    // 0052c041  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0052c046  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0052c049  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c04a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c04b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c04c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c04d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c04e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c04f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052c050:
    // 0052c050  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 0052c052  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0052c054  e8c792ffff             -call 0x525320
    cpu.esp -= 4;
    sub_525320(app, cpu);
    if (cpu.terminate) return;
    // 0052c059  8d5702                 -lea edx, [edi + 2]
    cpu.edx = x86::reg32(cpu.edi + x86::reg32(2) /* 0x2 */);
    // 0052c05c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0052c05e  66c7042e0000           -mov word ptr [esi + ebp], 0
    app->getMemory<x86::reg16>(cpu.esi + cpu.ebp * 1) = 0 /*0x0*/;
    // 0052c064  e89792ffff             -call 0x525300
    cpu.esp -= 4;
    sub_525300(app, cpu);
    if (cpu.terminate) return;
    // 0052c069  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052c06b  7442                   -je 0x52c0af
    if (cpu.flags.zf)
    {
        goto L_0x0052c0af;
    }
    // 0052c06d  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 0052c06f  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0052c073  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0052c076  e885b8fcff             -call 0x4f7900
    cpu.esp -= 4;
    sub_4f7900(app, cpu);
    if (cpu.terminate) return;
    // 0052c07b  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0052c07d  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0052c07f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052c081  7516                   -jne 0x52c099
    if (!cpu.flags.zf)
    {
        goto L_0x0052c099;
    }
    // 0052c083  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0052c085  e866b9fcff             -call 0x4f79f0
    cpu.esp -= 4;
    sub_4f79f0(app, cpu);
    if (cpu.terminate) return;
    // 0052c08a  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0052c08f  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0052c092  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c093  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c094  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c095  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c096  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c097  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c098  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052c099:
    // 0052c099  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0052c09d  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0052c0a1  01f7                   +add edi, esi
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0052c0a3  e87892ffff             -call 0x525320
    cpu.esp -= 4;
    sub_525320(app, cpu);
    if (cpu.terminate) return;
    // 0052c0a8  66c7070000             -mov word ptr [edi], 0
    app->getMemory<x86::reg16>(cpu.edi) = 0 /*0x0*/;
    // 0052c0ad  eb02                   -jmp 0x52c0b1
    goto L_0x0052c0b1;
L_0x0052c0af:
    // 0052c0af  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
L_0x0052c0b1:
    // 0052c0b1  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0052c0b5  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0052c0b7  e8e490ffff             -call 0x5251a0
    cpu.esp -= 4;
    sub_5251a0(app, cpu);
    if (cpu.terminate) return;
    // 0052c0bc  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0052c0be  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0052c0c2  e829b9fcff             -call 0x4f79f0
    cpu.esp -= 4;
    sub_4f79f0(app, cpu);
    if (cpu.terminate) return;
    // 0052c0c7  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0052c0c9  e822b9fcff             -call 0x4f79f0
    cpu.esp -= 4;
    sub_4f79f0(app, cpu);
    if (cpu.terminate) return;
    // 0052c0ce  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0052c0d0  750f                   -jne 0x52c0e1
    if (!cpu.flags.zf)
    {
        goto L_0x0052c0e1;
    }
    // 0052c0d2  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0052c0d7  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0052c0da  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c0db  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c0dc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c0dd  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c0de  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c0df  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c0e0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052c0e1:
    // 0052c0e1  833d58b1a00000         +cmp dword ptr [0xa0b158], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10531160) /* 0xa0b158 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052c0e8  7505                   -jne 0x52c0ef
    if (!cpu.flags.zf)
    {
        goto L_0x0052c0ef;
    }
    // 0052c0ea  e8b191ffff             -call 0x5252a0
    cpu.esp -= 4;
    sub_5252a0(app, cpu);
    if (cpu.terminate) return;
L_0x0052c0ef:
    // 0052c0ef  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0052c0f1  e882000000             -call 0x52c178
    cpu.esp -= 4;
    sub_52c178(app, cpu);
    if (cpu.terminate) return;
    // 0052c0f6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052c0f8  740f                   -je 0x52c109
    if (cpu.flags.zf)
    {
        goto L_0x0052c109;
    }
    // 0052c0fa  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0052c0ff  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0052c102  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c103  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c104  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c105  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c106  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c107  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c108  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052c109:
    // 0052c109  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0052c10b  e8f091ffff             -call 0x525300
    cpu.esp -= 4;
    sub_525300(app, cpu);
    if (cpu.terminate) return;
    // 0052c110  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0052c113  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0052c117  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 0052c11a  e8e1b7fcff             -call 0x4f7900
    cpu.esp -= 4;
    sub_4f7900(app, cpu);
    if (cpu.terminate) return;
    // 0052c11f  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0052c121  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052c123  7519                   -jne 0x52c13e
    if (!cpu.flags.zf)
    {
        goto L_0x0052c13e;
    }
    // 0052c125  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 0052c12a  e85d4efdff             -call 0x500f8c
    cpu.esp -= 4;
    sub_500f8c(app, cpu);
    if (cpu.terminate) return;
    // 0052c12f  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0052c134  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0052c137  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c138  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c139  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c13a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c13b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c13c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c13d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052c13e:
    // 0052c13e  0faf1c24               -imul ebx, dword ptr [esp]
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp))));
    // 0052c142  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0052c144  e8a781ffff             -call 0x5242f0
    cpu.esp -= 4;
    sub_5242f0(app, cpu);
    if (cpu.terminate) return;
    // 0052c149  83f8ff                 +cmp eax, -1
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
    // 0052c14c  7516                   -jne 0x52c164
    if (!cpu.flags.zf)
    {
        goto L_0x0052c164;
    }
    // 0052c14e  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0052c150  e89bb8fcff             -call 0x4f79f0
    cpu.esp -= 4;
    sub_4f79f0(app, cpu);
    if (cpu.terminate) return;
    // 0052c155  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0052c15a  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0052c15d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c15e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c15f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c160  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c161  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c162  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c163  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052c164:
    // 0052c164  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0052c166  e821270000             -call 0x52e88c
    cpu.esp -= 4;
    sub_52e88c(app, cpu);
    if (cpu.terminate) return;
L_0x0052c16b:
    // 0052c16b  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0052c16e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c16f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c170  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c171  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c172  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c173  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c174  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_52c178(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052c178  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0052c179  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052c17a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0052c17b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052c17c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0052c17d  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052c17e  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0052c181  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0052c183  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052c185  750a                   -jne 0x52c191
    if (!cpu.flags.zf)
    {
        goto L_0x0052c191;
    }
    // 0052c187  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0052c18c  e963010000             -jmp 0x52c2f4
    goto L_0x0052c2f4;
L_0x0052c191:
    // 0052c191  66833800               +cmp word ptr [eax], 0
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
    // 0052c195  741b                   -je 0x52c1b2
    if (cpu.flags.zf)
    {
        goto L_0x0052c1b2;
    }
    // 0052c197  8d5002                 -lea edx, [eax + 2]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 0052c19a  66833a00               +cmp word ptr [edx], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.edx);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0052c19e  7412                   -je 0x52c1b2
    if (cpu.flags.zf)
    {
        goto L_0x0052c1b2;
    }
L_0x0052c1a0:
    // 0052c1a0  66833a3d               +cmp word ptr [edx], 0x3d
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.edx);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(61 /*0x3d*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0052c1a4  740c                   -je 0x52c1b2
    if (cpu.flags.zf)
    {
        goto L_0x0052c1b2;
    }
    // 0052c1a6  668b7202               -mov si, word ptr [edx + 2]
    cpu.si = app->getMemory<x86::reg16>(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 0052c1aa  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0052c1ad  6685f6                 +test si, si
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.si & cpu.si));
    // 0052c1b0  75ee                   -jne 0x52c1a0
    if (!cpu.flags.zf)
    {
        goto L_0x0052c1a0;
    }
L_0x0052c1b2:
    // 0052c1b2  66833a00               +cmp word ptr [edx], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.edx);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0052c1b6  750f                   -jne 0x52c1c7
    if (!cpu.flags.zf)
    {
        goto L_0x0052c1c7;
    }
    // 0052c1b8  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0052c1bd  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0052c1c0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c1c1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c1c2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c1c3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c1c4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c1c5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c1c6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052c1c7:
    // 0052c1c7  66837a0200             +cmp word ptr [edx + 2], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.edx + x86::reg32(2) /* 0x2 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0052c1cc  0f94c0                 -sete al
    cpu.al = cpu.flags.zf;
    // 0052c1cf  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0052c1d1  8b0d58b1a000           -mov ecx, dword ptr [0xa0b158]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10531160) /* 0xa0b158 */);
    // 0052c1d7  88c3                   -mov bl, al
    cpu.bl = cpu.al;
    // 0052c1d9  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0052c1db  7541                   -jne 0x52c21e
    if (!cpu.flags.zf)
    {
        goto L_0x0052c21e;
    }
    // 0052c1dd  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0052c1df  0f850d010000           -jne 0x52c2f2
    if (!cpu.flags.zf)
    {
        goto L_0x0052c2f2;
    }
    // 0052c1e5  b809000000             -mov eax, 9
    cpu.eax = 9 /*0x9*/;
    // 0052c1ea  e811b7fcff             -call 0x4f7900
    cpu.esp -= 4;
    sub_4f7900(app, cpu);
    if (cpu.terminate) return;
    // 0052c1ef  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0052c1f1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052c1f3  750f                   -jne 0x52c204
    if (!cpu.flags.zf)
    {
        goto L_0x0052c204;
    }
    // 0052c1f5  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0052c1fa  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0052c1fd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c1fe  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c1ff  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c200  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c201  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c202  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c203  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052c204:
    // 0052c204  a358b1a000             -mov dword ptr [0xa0b158], eax
    app->getMemory<x86::reg32>(x86::reg32(10531160) /* 0xa0b158 */) = cpu.eax;
    // 0052c209  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0052c20c  8958f8                 -mov dword ptr [eax - 8], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-8) /* -0x8 */) = cpu.ebx;
    // 0052c20f  31f6                   +xor esi, esi
    cpu.clear_co();
    cpu.set_szp((cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi))));
    // 0052c211  8958fc                 -mov dword ptr [eax - 4], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.ebx;
    // 0052c214  a350b1a000             -mov dword ptr [0xa0b150], eax
    app->getMemory<x86::reg32>(x86::reg32(10531152) /* 0xa0b150 */) = cpu.eax;
    // 0052c219  e9c8000000             -jmp 0x52c2e6
    goto L_0x0052c2e6;
L_0x0052c21e:
    // 0052c21e  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0052c220  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0052c222  e8d9000000             -call 0x52c300
    cpu.esp -= 4;
    sub_52c300(app, cpu);
    if (cpu.terminate) return;
    // 0052c227  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0052c229  0f85c3000000           -jne 0x52c2f2
    if (!cpu.flags.zf)
    {
        goto L_0x0052c2f2;
    }
    // 0052c22f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052c231  0f8fac000000           -jg 0x52c2e3
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0052c2e3;
    }
    // 0052c237  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 0052c239  8b2d50b1a000           -mov ebp, dword ptr [0xa0b150]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(10531152) /* 0xa0b150 */);
    // 0052c23f  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0052c241  40                     -inc eax
    (cpu.eax)++;
    // 0052c242  8d1cb500000000         -lea ebx, [esi*4]
    cpu.ebx = x86::reg32(cpu.esi * 4);
    // 0052c249  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0052c24c  8d4308                 -lea eax, [ebx + 8]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 0052c24f  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 0052c252  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0052c256  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0052c258  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0052c25a  753e                   -jne 0x52c29a
    if (!cpu.flags.zf)
    {
        goto L_0x0052c29a;
    }
    // 0052c25c  e89fb6fcff             -call 0x4f7900
    cpu.esp -= 4;
    sub_4f7900(app, cpu);
    if (cpu.terminate) return;
    // 0052c261  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0052c263  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0052c265  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052c267  750f                   -jne 0x52c278
    if (!cpu.flags.zf)
    {
        goto L_0x0052c278;
    }
    // 0052c269  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0052c26e  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0052c271  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c272  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c273  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c274  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c275  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c276  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c277  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052c278:
    // 0052c278  8b1558b1a000           -mov edx, dword ptr [0xa0b158]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10531160) /* 0xa0b158 */);
    // 0052c27e  e89d90ffff             -call 0x525320
    cpu.esp -= 4;
    sub_525320(app, cpu);
    if (cpu.terminate) return;
    // 0052c283  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0052c287  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 0052c28a  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0052c28c  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0052c28e  a350b1a000             -mov dword ptr [0xa0b150], eax
    app->getMemory<x86::reg32>(x86::reg32(10531152) /* 0xa0b150 */) = cpu.eax;
    // 0052c293  e8a843fbff             -call 0x4e0640
    cpu.esp -= 4;
    sub_4e0640(app, cpu);
    if (cpu.terminate) return;
    // 0052c298  eb39                   -jmp 0x52c2d3
    goto L_0x0052c2d3;
L_0x0052c29a:
    // 0052c29a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0052c29c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0052c29e  e81dc3feff             -call 0x5185c0
    cpu.esp -= 4;
    sub_5185c0(app, cpu);
    if (cpu.terminate) return;
    // 0052c2a3  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0052c2a5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052c2a7  750f                   -jne 0x52c2b8
    if (!cpu.flags.zf)
    {
        goto L_0x0052c2b8;
    }
    // 0052c2a9  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0052c2ae  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0052c2b1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c2b2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c2b3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c2b4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c2b5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c2b6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c2b7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052c2b8:
    // 0052c2b8  8b6c2404               -mov ebp, dword ptr [esp + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0052c2bc  8b1550b1a000           -mov edx, dword ptr [0xa0b150]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10531152) /* 0xa0b150 */);
    // 0052c2c2  01c5                   +add ebp, eax
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0052c2c4  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0052c2c6  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0052c2c8  e873c3feff             -call 0x518640
    cpu.esp -= 4;
    sub_518640(app, cpu);
    if (cpu.terminate) return;
    // 0052c2cd  892d50b1a000           -mov dword ptr [0xa0b150], ebp
    app->getMemory<x86::reg32>(x86::reg32(10531152) /* 0xa0b150 */) = cpu.ebp;
L_0x0052c2d3:
    // 0052c2d3  890d58b1a000           -mov dword ptr [0xa0b158], ecx
    app->getMemory<x86::reg32>(x86::reg32(10531160) /* 0xa0b158 */) = cpu.ecx;
    // 0052c2d9  c744b10400000000       -mov dword ptr [ecx + esi*4 + 4], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */ + cpu.esi * 4) = 0 /*0x0*/;
    // 0052c2e1  eb03                   -jmp 0x52c2e6
    goto L_0x0052c2e6;
L_0x0052c2e3:
    // 0052c2e3  8d70ff                 -lea esi, [eax - 1]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(-1) /* -0x1 */);
L_0x0052c2e6:
    // 0052c2e6  a150b1a000             -mov eax, dword ptr [0xa0b150]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10531152) /* 0xa0b150 */);
    // 0052c2eb  893cb1                 -mov dword ptr [ecx + esi*4], edi
    app->getMemory<x86::reg32>(cpu.ecx + cpu.esi * 4) = cpu.edi;
    // 0052c2ee  c6040600               -mov byte ptr [esi + eax], 0
    app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1) = 0 /*0x0*/;
L_0x0052c2f2:
    // 0052c2f2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0052c2f4:
    // 0052c2f4  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0052c2f7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c2f8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c2f9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c2fa  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c2fb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c2fc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c2fd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_52c300(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052c300  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0052c301  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052c302  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052c303  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0052c304  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052c305  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0052c307  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0052c309  8b3558b1a000           -mov esi, dword ptr [0xa0b158]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(10531160) /* 0xa0b158 */);
    // 0052c30f  e9d7000000             -jmp 0x52c3eb
    goto L_0x0052c3eb;
L_0x0052c314:
    // 0052c314  668b0f                 -mov cx, word ptr [edi]
    cpu.cx = app->getMemory<x86::reg16>(cpu.edi);
    // 0052c317  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 0052c319  6685c9                 +test cx, cx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.cx & cpu.cx));
    // 0052c31c  0f84c6000000           -je 0x52c3e8
    if (cpu.flags.zf)
    {
        goto L_0x0052c3e8;
    }
L_0x0052c322:
    // 0052c322  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0052c324  668b02                 -mov ax, word ptr [edx]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edx);
    // 0052c327  e84490ffff             -call 0x525370
    cpu.esp -= 4;
    sub_525370(app, cpu);
    if (cpu.terminate) return;
    // 0052c32c  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0052c32e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0052c330  668b03                 -mov ax, word ptr [ebx]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ebx);
    // 0052c333  e83890ffff             -call 0x525370
    cpu.esp -= 4;
    sub_525370(app, cpu);
    if (cpu.terminate) return;
    // 0052c338  6639c1                 +cmp cx, ax
    {
        x86::reg16 tmp1 = cpu.cx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(cpu.ax));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0052c33b  0f85a7000000           -jne 0x52c3e8
    if (!cpu.flags.zf)
    {
        goto L_0x0052c3e8;
    }
    // 0052c341  66833a3d               +cmp word ptr [edx], 0x3d
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.edx);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(61 /*0x3d*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0052c345  0f858a000000           -jne 0x52c3d5
    if (!cpu.flags.zf)
    {
        goto L_0x0052c3d5;
    }
    // 0052c34b  8b1558b1a000           -mov edx, dword ptr [0xa0b158]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10531160) /* 0xa0b158 */);
    // 0052c351  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 0052c353  29d7                   -sub edi, edx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0052c355  c1ff02                 -sar edi, 2
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (2 /*0x2*/ % 32));
    // 0052c358  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0052c35a  0f846c000000           -je 0x52c3cc
    if (cpu.flags.zf)
    {
        goto L_0x0052c3cc;
    }
    // 0052c360  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 0052c362  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0052c364  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0052c366  740f                   -je 0x52c377
    if (cpu.flags.zf)
    {
        goto L_0x0052c377;
    }
L_0x0052c368:
    // 0052c368  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0052c36b  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 0052c36d  8b5904                 -mov ebx, dword ptr [ecx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0052c370  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052c373  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0052c375  75f1                   -jne 0x52c368
    if (!cpu.flags.zf)
    {
        goto L_0x0052c368;
    }
L_0x0052c377:
    // 0052c377  8b3550b1a000           -mov esi, dword ptr [0xa0b150]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(10531152) /* 0xa0b150 */);
    // 0052c37d  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0052c37f  7443                   -je 0x52c3c4
    if (cpu.flags.zf)
    {
        goto L_0x0052c3c4;
    }
    // 0052c381  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0052c383  803c0700               +cmp byte ptr [edi + eax], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edi + cpu.eax * 1);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0052c387  7407                   -je 0x52c390
    if (cpu.flags.zf)
    {
        goto L_0x0052c390;
    }
    // 0052c389  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0052c38b  e860b6fcff             -call 0x4f79f0
    cpu.esp -= 4;
    sub_4f79f0(app, cpu);
    if (cpu.terminate) return;
L_0x0052c390:
    // 0052c390  8b2d58b1a000           -mov ebp, dword ptr [0xa0b158]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(10531160) /* 0xa0b158 */);
    // 0052c396  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0052c398  29ee                   -sub esi, ebp
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 0052c39a  8b1550b1a000           -mov edx, dword ptr [0xa0b150]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10531152) /* 0xa0b150 */);
    // 0052c3a0  c1fe02                 -sar esi, 2
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (2 /*0x2*/ % 32));
    // 0052c3a3  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0052c3a5  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0052c3a7  e894c2feff             -call 0x518640
    cpu.esp -= 4;
    sub_518640(app, cpu);
    if (cpu.terminate) return;
    // 0052c3ac  890d50b1a000           -mov dword ptr [0xa0b150], ecx
    app->getMemory<x86::reg32>(x86::reg32(10531152) /* 0xa0b150 */) = cpu.ecx;
    // 0052c3b2  39f7                   +cmp edi, esi
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052c3b4  7d0e                   -jge 0x52c3c4
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0052c3c4;
    }
    // 0052c3b6  8d040f                 -lea eax, [edi + ecx]
    cpu.eax = x86::reg32(cpu.edi + cpu.ecx * 1);
L_0x0052c3b9:
    // 0052c3b9  40                     -inc eax
    (cpu.eax)++;
    // 0052c3ba  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 0052c3bc  47                     -inc edi
    (cpu.edi)++;
    // 0052c3bd  8850ff                 -mov byte ptr [eax - 1], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(-1) /* -0x1 */) = cpu.dl;
    // 0052c3c0  39f7                   +cmp edi, esi
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052c3c2  7cf5                   -jl 0x52c3b9
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0052c3b9;
    }
L_0x0052c3c4:
    // 0052c3c4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0052c3c6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c3c7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c3c8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c3c9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c3ca  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c3cb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052c3cc:
    // 0052c3cc  8d4701                 -lea eax, [edi + 1]
    cpu.eax = x86::reg32(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 0052c3cf  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c3d0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c3d1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c3d2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c3d3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c3d4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052c3d5:
    // 0052c3d5  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0052c3d8  668b4302               -mov ax, word ptr [ebx + 2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(2) /* 0x2 */);
    // 0052c3dc  83c302                 -add ebx, 2
    (cpu.ebx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0052c3df  6685c0                 +test ax, ax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.ax & cpu.ax));
    // 0052c3e2  0f853affffff           -jne 0x52c322
    if (!cpu.flags.zf)
    {
        goto L_0x0052c322;
    }
L_0x0052c3e8:
    // 0052c3e8  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0052c3eb:
    // 0052c3eb  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 0052c3ed  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0052c3ef  0f851fffffff           -jne 0x52c314
    if (!cpu.flags.zf)
    {
        goto L_0x0052c314;
    }
    // 0052c3f5  a158b1a000             -mov eax, dword ptr [0xa0b158]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10531160) /* 0xa0b158 */);
    // 0052c3fa  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0052c3fc  c1f802                 -sar eax, 2
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (2 /*0x2*/ % 32));
    // 0052c3ff  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c400  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c401  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c402  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c403  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c404  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_52c410(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052c410  8b402c                 -mov eax, dword ptr [eax + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(44) /* 0x2c */);
    // 0052c413  8b400c                 -mov eax, dword ptr [eax + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0052c416  83e002                 -and eax, 2
    cpu.eax &= x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0052c419  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_52c420(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052c420  8b402c                 -mov eax, dword ptr [eax + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(44) /* 0x2c */);
    // 0052c423  8b400c                 -mov eax, dword ptr [eax + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0052c426  83e004                 -and eax, 4
    cpu.eax &= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052c429  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_52c430(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052c430  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052c431  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0052c432  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052c433  83ec1c                 -sub esp, 0x1c
    (cpu.esp) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0052c436  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0052c438  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0052c43a  c1ea10                 -shr edx, 0x10
    cpu.edx >>= 16 /*0x10*/ % 32;
    // 0052c43d  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0052c443  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0052c445  89542418               -mov dword ptr [esp + 0x18], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 0052c449  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0052c44b  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0052c450  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0052c454  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0052c456  c1ea08                 -shr edx, 8
    cpu.edx >>= 8 /*0x8*/ % 32;
    // 0052c459  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 0052c45c  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0052c462  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0052c467  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0052c46b  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0052c46f  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0052c471  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0052c473  c1e808                 -shr eax, 8
    cpu.eax >>= 8 /*0x8*/ % 32;
    // 0052c476  c1ea18                 -shr edx, 0x18
    cpu.edx >>= 24 /*0x18*/ % 32;
    // 0052c479  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0052c47e  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0052c484  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0052c488  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0052c48a  0fafc1                 -imul eax, ecx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 0052c48d  c1ef18                 -shr edi, 0x18
    cpu.edi >>= 24 /*0x18*/ % 32;
    // 0052c490  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0052c496  81e7ff000000           -and edi, 0xff
    cpu.edi &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0052c49c  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 0052c4a0  8d1c0e                 -lea ebx, [esi + ecx]
    cpu.ebx = x86::reg32(cpu.esi + cpu.ecx * 1);
    // 0052c4a3  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0052c4a5  0fafd6                 -imul edx, esi
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 0052c4a8  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0052c4aa  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0052c4ac  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0052c4af  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0052c4b1  3dff000000             +cmp eax, 0xff
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(255 /*0xff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052c4b6  0f8e93000000           -jle 0x52c54f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0052c54f;
    }
    // 0052c4bc  b8ff000000             -mov eax, 0xff
    cpu.eax = 255 /*0xff*/;
L_0x0052c4c1:
    // 0052c4c1  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0052c4c5  0fafd6                 -imul edx, esi
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 0052c4c8  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0052c4ca  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0052c4ce  0fafc1                 -imul eax, ecx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 0052c4d1  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0052c4d3  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0052c4d5  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0052c4d8  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0052c4da  3dff000000             +cmp eax, 0xff
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(255 /*0xff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052c4df  0f8e79000000           -jle 0x52c55e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0052c55e;
    }
    // 0052c4e5  b8ff000000             -mov eax, 0xff
    cpu.eax = 255 /*0xff*/;
L_0x0052c4ea:
    // 0052c4ea  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0052c4ee  0fafd1                 -imul edx, ecx
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 0052c4f1  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0052c4f4  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0052c4f8  0fafc6                 -imul eax, esi
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 0052c4fb  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0052c4fd  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0052c4ff  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0052c502  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0052c504  3dff000000             +cmp eax, 0xff
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(255 /*0xff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052c509  7e5b                   -jle 0x52c566
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0052c566;
    }
    // 0052c50b  b8ff000000             -mov eax, 0xff
    cpu.eax = 255 /*0xff*/;
L_0x0052c510:
    // 0052c510  0faf4c2404             -imul ecx, dword ptr [esp + 4]
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */))));
    // 0052c515  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0052c519  0fafd6                 -imul edx, esi
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 0052c51c  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0052c51e  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0052c520  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0052c522  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0052c525  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0052c527  3dff000000             +cmp eax, 0xff
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(255 /*0xff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052c52c  7f40                   -jg 0x52c56e
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0052c56e;
    }
    // 0052c52e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052c530  7c43                   -jl 0x52c575
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0052c575;
    }
L_0x0052c532:
    // 0052c532  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 0052c535  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0052c537  c1e110                 -shl ecx, 0x10
    cpu.ecx <<= 16 /*0x10*/ % 32;
    // 0052c53a  c1e218                 -shl edx, 0x18
    cpu.edx <<= 24 /*0x18*/ % 32;
    // 0052c53d  09d1                   -or ecx, edx
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.edx));
    // 0052c53f  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0052c541  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 0052c544  09ca                   -or edx, ecx
    cpu.edx |= x86::reg32(x86::sreg32(cpu.ecx));
    // 0052c546  09d0                   -or eax, edx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edx));
    // 0052c548  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0052c54b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c54c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c54d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c54e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052c54f:
    // 0052c54f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052c551  0f8d6affffff           -jge 0x52c4c1
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0052c4c1;
    }
    // 0052c557  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0052c559  e963ffffff             -jmp 0x52c4c1
    goto L_0x0052c4c1;
L_0x0052c55e:
    // 0052c55e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052c560  7d88                   -jge 0x52c4ea
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0052c4ea;
    }
    // 0052c562  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0052c564  eb84                   -jmp 0x52c4ea
    goto L_0x0052c4ea;
L_0x0052c566:
    // 0052c566  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052c568  7da6                   -jge 0x52c510
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0052c510;
    }
    // 0052c56a  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0052c56c  eba2                   -jmp 0x52c510
    goto L_0x0052c510;
L_0x0052c56e:
    // 0052c56e  b8ff000000             -mov eax, 0xff
    cpu.eax = 255 /*0xff*/;
    // 0052c573  ebbd                   -jmp 0x52c532
    goto L_0x0052c532;
L_0x0052c575:
    // 0052c575  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0052c577  ebb9                   -jmp 0x52c532
    goto L_0x0052c532;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_52c580(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052c580  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052c581  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052c582  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0052c583  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052c584  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0052c587  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0052c58b  f7c3000000ff           +test ebx, 0xff000000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & 4278190080 /*0xff000000*/));
    // 0052c591  7431                   -je 0x52c5c4
    if (cpu.flags.zf)
    {
        goto L_0x0052c5c4;
    }
L_0x0052c593:
    // 0052c593  bf0f000000             -mov edi, 0xf
    cpu.edi = 15 /*0xf*/;
    // 0052c598  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0052c59a  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 0052c59d  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x0052c59f:
    // 0052c59f  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 0052c5a2  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0052c5a6  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0052c5a8  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0052c5aa  e881feffff             -call 0x52c430
    cpu.esp -= 4;
    sub_52c430(app, cpu);
    if (cpu.terminate) return;
    // 0052c5af  83c504                 -add ebp, 4
    (cpu.ebp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052c5b2  4f                     -dec edi
    (cpu.edi)--;
    // 0052c5b3  46                     -inc esi
    (cpu.esi)++;
    // 0052c5b4  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0052c5b7  83fe10                 +cmp esi, 0x10
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052c5ba  7ce3                   -jl 0x52c59f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0052c59f;
    }
    // 0052c5bc  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0052c5bf  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c5c0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c5c1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c5c2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c5c3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052c5c4:
    // 0052c5c4  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0052c5c6  81e3ffffff00           +and ebx, 0xffffff
    cpu.clear_co();
    cpu.set_szp((cpu.ebx &= x86::reg32(x86::sreg32(16777215 /*0xffffff*/))));
    // 0052c5cc  ebc5                   -jmp 0x52c593
    goto L_0x0052c593;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_52c5d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052c5d0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052c5d1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0052c5d2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052c5d3  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0052c5d6  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0052c5d8  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0052c5da  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 0052c5dc  f7c3000000ff           +test ebx, 0xff000000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & 4278190080 /*0xff000000*/));
    // 0052c5e2  0f8524010000           -jne 0x52c70c
    if (!cpu.flags.zf)
    {
        goto L_0x0052c70c;
    }
    // 0052c5e8  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0052c5ea  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0052c5ee  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
L_0x0052c5f1:
    // 0052c5f1  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0052c5f5  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0052c5fa  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 0052c5fd  ba03000000             -mov edx, 3
    cpu.edx = 3 /*0x3*/;
    // 0052c602  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 0052c604  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0052c606  896f04                 -mov dword ptr [edi + 4], ebp
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 0052c609  e822feffff             -call 0x52c430
    cpu.esp -= 4;
    sub_52c430(app, cpu);
    if (cpu.terminate) return;
    // 0052c60e  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 0052c613  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 0052c616  894708                 -mov dword ptr [edi + 8], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0052c619  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0052c61b  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0052c61d  e80efeffff             -call 0x52c430
    cpu.esp -= 4;
    sub_52c430(app, cpu);
    if (cpu.terminate) return;
    // 0052c622  b903000000             -mov ecx, 3
    cpu.ecx = 3 /*0x3*/;
    // 0052c627  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 0052c62a  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0052c62f  89470c                 -mov dword ptr [edi + 0xc], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0052c632  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0052c634  e8f7fdffff             -call 0x52c430
    cpu.esp -= 4;
    sub_52c430(app, cpu);
    if (cpu.terminate) return;
    // 0052c639  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0052c63e  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 0052c643  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0052c645  894710                 -mov dword ptr [edi + 0x10], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0052c648  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0052c64c  e8dffdffff             -call 0x52c430
    cpu.esp -= 4;
    sub_52c430(app, cpu);
    if (cpu.terminate) return;
    // 0052c651  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 0052c656  ba03000000             -mov edx, 3
    cpu.edx = 3 /*0x3*/;
    // 0052c65b  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0052c65d  894714                 -mov dword ptr [edi + 0x14], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0052c660  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0052c664  e8c7fdffff             -call 0x52c430
    cpu.esp -= 4;
    sub_52c430(app, cpu);
    if (cpu.terminate) return;
    // 0052c669  b903000000             -mov ecx, 3
    cpu.ecx = 3 /*0x3*/;
    // 0052c66e  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 0052c673  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0052c675  894718                 -mov dword ptr [edi + 0x18], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 0052c678  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0052c67c  e8affdffff             -call 0x52c430
    cpu.esp -= 4;
    sub_52c430(app, cpu);
    if (cpu.terminate) return;
    // 0052c681  89471c                 -mov dword ptr [edi + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 0052c684  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 0052c689  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0052c68e  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0052c692  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0052c694  e897fdffff             -call 0x52c430
    cpu.esp -= 4;
    sub_52c430(app, cpu);
    if (cpu.terminate) return;
    // 0052c699  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0052c69e  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 0052c6a3  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 0052c6a5  894720                 -mov dword ptr [edi + 0x20], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 0052c6a8  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0052c6aa  897724                 -mov dword ptr [edi + 0x24], esi
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(36) /* 0x24 */) = cpu.esi;
    // 0052c6ad  e87efdffff             -call 0x52c430
    cpu.esp -= 4;
    sub_52c430(app, cpu);
    if (cpu.terminate) return;
    // 0052c6b2  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 0052c6b7  ba03000000             -mov edx, 3
    cpu.edx = 3 /*0x3*/;
    // 0052c6bc  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 0052c6be  894728                 -mov dword ptr [edi + 0x28], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 0052c6c1  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0052c6c3  e868fdffff             -call 0x52c430
    cpu.esp -= 4;
    sub_52c430(app, cpu);
    if (cpu.terminate) return;
    // 0052c6c8  b903000000             -mov ecx, 3
    cpu.ecx = 3 /*0x3*/;
    // 0052c6cd  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 0052c6d2  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 0052c6d4  89472c                 -mov dword ptr [edi + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 0052c6d7  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0052c6d9  e852fdffff             -call 0x52c430
    cpu.esp -= 4;
    sub_52c430(app, cpu);
    if (cpu.terminate) return;
    // 0052c6de  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 0052c6e3  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0052c6e8  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 0052c6ea  894730                 -mov dword ptr [edi + 0x30], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(48) /* 0x30 */) = cpu.eax;
    // 0052c6ed  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0052c6ef  e83cfdffff             -call 0x52c430
    cpu.esp -= 4;
    sub_52c430(app, cpu);
    if (cpu.terminate) return;
    // 0052c6f4  c7473800000000         -mov dword ptr [edi + 0x38], 0
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(56) /* 0x38 */) = 0 /*0x0*/;
    // 0052c6fb  c7473c00000000         -mov dword ptr [edi + 0x3c], 0
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(60) /* 0x3c */) = 0 /*0x0*/;
    // 0052c702  894734                 -mov dword ptr [edi + 0x34], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(52) /* 0x34 */) = cpu.eax;
    // 0052c705  83c408                 +add esp, 8
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
    // 0052c708  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c709  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c70a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c70b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052c70c:
    // 0052c70c  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 0052c710  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 0052c713  e9d9feffff             -jmp 0x52c5f1
    goto L_0x0052c5f1;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_52c720(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052c720  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052c721  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0052c722  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052c723  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0052c726  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0052c729  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0052c72d  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0052c72f  f7c3000000ff           +test ebx, 0xff000000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & 4278190080 /*0xff000000*/));
    // 0052c735  746e                   -je 0x52c7a5
    if (cpu.flags.zf)
    {
        goto L_0x0052c7a5;
    }
L_0x0052c737:
    // 0052c737  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0052c73a  bd08000000             -mov ebp, 8
    cpu.ebp = 8 /*0x8*/;
    // 0052c73f  895c2408               -mov dword ptr [esp + 8], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 0052c743  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0052c745  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
L_0x0052c749:
    // 0052c749  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0052c74d  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0052c74f  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 0052c751  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0052c753  e8d8fcffff             -call 0x52c430
    cpu.esp -= 4;
    sub_52c430(app, cpu);
    if (cpu.terminate) return;
    // 0052c758  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0052c75c  4d                     -dec ebp
    (cpu.ebp)--;
    // 0052c75d  46                     -inc esi
    (cpu.esi)++;
    // 0052c75e  8d5304                 -lea edx, [ebx + 4]
    cpu.edx = x86::reg32(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0052c761  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 0052c763  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0052c767  83fe07                 +cmp esi, 7
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(7 /*0x7*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052c76a  7edd                   -jle 0x52c749
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0052c749;
    }
    // 0052c76c  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0052c76f  bd07000000             -mov ebp, 7
    cpu.ebp = 7 /*0x7*/;
    // 0052c774  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0052c776  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
L_0x0052c77a:
    // 0052c77a  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0052c77e  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0052c780  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0052c782  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0052c784  e8a7fcffff             -call 0x52c430
    cpu.esp -= 4;
    sub_52c430(app, cpu);
    if (cpu.terminate) return;
    // 0052c789  8b5c2410               -mov ebx, dword ptr [esp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0052c78d  4d                     -dec ebp
    (cpu.ebp)--;
    // 0052c78e  46                     -inc esi
    (cpu.esi)++;
    // 0052c78f  8d4b04                 -lea ecx, [ebx + 4]
    cpu.ecx = x86::reg32(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0052c792  894320                 -mov dword ptr [ebx + 0x20], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 0052c795  894c2410               -mov dword ptr [esp + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 0052c799  83fe07                 +cmp esi, 7
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(7 /*0x7*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052c79c  7edc                   -jle 0x52c77a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0052c77a;
    }
    // 0052c79e  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0052c7a1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c7a2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c7a3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c7a4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052c7a5:
    // 0052c7a5  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0052c7a7  81e3ffffff00           +and ebx, 0xffffff
    cpu.clear_co();
    cpu.set_szp((cpu.ebx &= x86::reg32(x86::sreg32(16777215 /*0xffffff*/))));
    // 0052c7ad  eb88                   -jmp 0x52c737
    goto L_0x0052c737;
}

/* align: skip 0x90 */
void Application::sub_52c7b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052c7b0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0052c7b1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052c7b2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0052c7b3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052c7b4  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0052c7b6  e855fcffff             -call 0x52c410
    cpu.esp -= 4;
    sub_52c410(app, cpu);
    if (cpu.terminate) return;
    // 0052c7bb  8d727c                 -lea esi, [edx + 0x7c]
    cpu.esi = x86::reg32(cpu.edx + x86::reg32(124) /* 0x7c */);
    // 0052c7be  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052c7c0  7520                   -jne 0x52c7e2
    if (!cpu.flags.zf)
    {
        goto L_0x0052c7e2;
    }
    // 0052c7c2  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0052c7c4  e857fcffff             -call 0x52c420
    cpu.esp -= 4;
    sub_52c420(app, cpu);
    if (cpu.terminate) return;
    // 0052c7c9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052c7cb  742a                   -je 0x52c7f7
    if (cpu.flags.zf)
    {
        goto L_0x0052c7f7;
    }
    // 0052c7cd  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0052c7cf  8b4a78                 -mov ecx, dword ptr [edx + 0x78]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(120) /* 0x78 */);
    // 0052c7d2  8b5a70                 -mov ebx, dword ptr [edx + 0x70]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(112) /* 0x70 */);
    // 0052c7d5  8b526c                 -mov edx, dword ptr [edx + 0x6c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(108) /* 0x6c */);
    // 0052c7d8  e843ffffff             -call 0x52c720
    cpu.esp -= 4;
    sub_52c720(app, cpu);
    if (cpu.terminate) return;
    // 0052c7dd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c7de  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c7df  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c7e0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c7e1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052c7e2:
    // 0052c7e2  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0052c7e4  8b4a74                 -mov ecx, dword ptr [edx + 0x74]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(116) /* 0x74 */);
    // 0052c7e7  8b5a70                 -mov ebx, dword ptr [edx + 0x70]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(112) /* 0x70 */);
    // 0052c7ea  8b526c                 -mov edx, dword ptr [edx + 0x6c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(108) /* 0x6c */);
    // 0052c7ed  e8defdffff             -call 0x52c5d0
    cpu.esp -= 4;
    sub_52c5d0(app, cpu);
    if (cpu.terminate) return;
    // 0052c7f2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c7f3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c7f4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c7f5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c7f6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052c7f7:
    // 0052c7f7  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0052c7f9  8b5a70                 -mov ebx, dword ptr [edx + 0x70]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(112) /* 0x70 */);
    // 0052c7fc  8b526c                 -mov edx, dword ptr [edx + 0x6c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(108) /* 0x6c */);
    // 0052c7ff  e87cfdffff             -call 0x52c580
    cpu.esp -= 4;
    sub_52c580(app, cpu);
    if (cpu.terminate) return;
    // 0052c804  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c805  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c806  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c807  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c808  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_52c810(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052c810  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0052c812  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_52c814(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052c814  ff15c0b15600           -call dword ptr [0x56b1c0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5681600) /* 0x56b1c0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0052c81a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_52c81c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052c81c  ff15c4b15600           -call dword ptr [0x56b1c4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5681604) /* 0x56b1c4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0052c822  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_52c824(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052c824  ff15c8b15600           -call dword ptr [0x56b1c8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5681608) /* 0x56b1c8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0052c82a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_52c82c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052c82c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052c82d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052c82e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052c830  7410                   -je 0x52c842
    if (cpu.flags.zf)
    {
        goto L_0x0052c842;
    }
    // 0052c832  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0052c834  8b35c0b15600           -mov esi, dword ptr [0x56b1c0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5681600) /* 0x56b1c0 */);
    // 0052c83a  890dc0b15600           -mov dword ptr [0x56b1c0], ecx
    app->getMemory<x86::reg32>(x86::reg32(5681600) /* 0x56b1c0 */) = cpu.ecx;
    // 0052c840  8930                   -mov dword ptr [eax], esi
    app->getMemory<x86::reg32>(cpu.eax) = cpu.esi;
L_0x0052c842:
    // 0052c842  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0052c844  740f                   -je 0x52c855
    if (cpu.flags.zf)
    {
        goto L_0x0052c855;
    }
    // 0052c846  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 0052c848  8b0dc4b15600           -mov ecx, dword ptr [0x56b1c4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5681604) /* 0x56b1c4 */);
    // 0052c84e  a3c4b15600             -mov dword ptr [0x56b1c4], eax
    app->getMemory<x86::reg32>(x86::reg32(5681604) /* 0x56b1c4 */) = cpu.eax;
    // 0052c853  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
L_0x0052c855:
    // 0052c855  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0052c857  740f                   -je 0x52c868
    if (cpu.flags.zf)
    {
        goto L_0x0052c868;
    }
    // 0052c859  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 0052c85b  8b15c8b15600           -mov edx, dword ptr [0x56b1c8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5681608) /* 0x56b1c8 */);
    // 0052c861  a3c8b15600             -mov dword ptr [0x56b1c8], eax
    app->getMemory<x86::reg32>(x86::reg32(5681608) /* 0x56b1c8 */) = cpu.eax;
    // 0052c866  8913                   -mov dword ptr [ebx], edx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
L_0x0052c868:
    // 0052c868  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c869  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c86a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_52c870(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052c870  ff15ccb15600           -call dword ptr [0x56b1cc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5681612) /* 0x56b1cc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0052c876  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
    // 0052c878  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0052c879  baff000000             -mov edx, 0xff
    cpu.edx = 255 /*0xff*/;
    // 0052c87e  b8d4205500             -mov eax, 0x5520d4
    cpu.eax = 5578964 /*0x5520d4*/;
    // 0052c883  e88454feff             -call 0x511d0c
    cpu.esp -= 4;
    sub_511d0c(app, cpu);
    if (cpu.terminate) return;
    // 0052c888  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c889  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_52c878(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x0052c878;
    // 0052c870  ff15ccb15600           -call dword ptr [0x56b1cc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5681612) /* 0x56b1cc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0052c876  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_entry_0x0052c878:
    // 0052c878  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0052c879  baff000000             -mov edx, 0xff
    cpu.edx = 255 /*0xff*/;
    // 0052c87e  b8d4205500             -mov eax, 0x5520d4
    cpu.eax = 5578964 /*0x5520d4*/;
    // 0052c883  e88454feff             -call 0x511d0c
    cpu.esp -= 4;
    sub_511d0c(app, cpu);
    if (cpu.terminate) return;
    // 0052c888  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c889  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_52c88a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052c88a  29d2                   -sub edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0052c88c  29c0                   -sub eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0052c88e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_52c88f(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052c88f  b883000000             -mov eax, 0x83
    cpu.eax = 131 /*0x83*/;
    // 0052c894  e887240000             -call 0x52ed20
    cpu.esp -= 4;
    sub_52ed20(app, cpu);
    if (cpu.terminate) return;
    // 0052c899  eb1d                   -jmp 0x52c8b8
    goto L_0x0052c8b8;
    // 0052c89b  b883000000             -mov eax, 0x83
    cpu.eax = 131 /*0x83*/;
    // 0052c8a0  e87b240000             -call 0x52ed20
    cpu.esp -= 4;
    sub_52ed20(app, cpu);
    if (cpu.terminate) return;
    // 0052c8a5  eb11                   -jmp 0x52c8b8
    goto L_0x0052c8b8;
    // 0052c8a7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0052c8a8  e8f75ffdff             -call 0x5028a4
    cpu.esp -= 4;
    sub_5028a4(app, cpu);
    if (cpu.terminate) return;
    // 0052c8ad  b884000000             -mov eax, 0x84
    cpu.eax = 132 /*0x84*/;
    // 0052c8b2  e869240000             -call 0x52ed20
    cpu.esp -= 4;
    sub_52ed20(app, cpu);
    if (cpu.terminate) return;
    // 0052c8b7  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0052c8b8:
    // 0052c8b8  2500000080             -and eax, 0x80000000
    cpu.eax &= x86::reg32(x86::sreg32(2147483648 /*0x80000000*/));
    // 0052c8bd  0d0000f07f             -or eax, 0x7ff00000
    cpu.eax |= x86::reg32(x86::sreg32(2146435072 /*0x7ff00000*/));
    // 0052c8c2  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0052c8c4  29c0                   -sub eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0052c8c6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_52c8a7(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x0052c8a7;
    // 0052c88f  b883000000             -mov eax, 0x83
    cpu.eax = 131 /*0x83*/;
    // 0052c894  e887240000             -call 0x52ed20
    cpu.esp -= 4;
    sub_52ed20(app, cpu);
    if (cpu.terminate) return;
    // 0052c899  eb1d                   -jmp 0x52c8b8
    goto L_0x0052c8b8;
    // 0052c89b  b883000000             -mov eax, 0x83
    cpu.eax = 131 /*0x83*/;
    // 0052c8a0  e87b240000             -call 0x52ed20
    cpu.esp -= 4;
    sub_52ed20(app, cpu);
    if (cpu.terminate) return;
    // 0052c8a5  eb11                   -jmp 0x52c8b8
    goto L_0x0052c8b8;
L_entry_0x0052c8a7:
    // 0052c8a7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0052c8a8  e8f75ffdff             -call 0x5028a4
    cpu.esp -= 4;
    sub_5028a4(app, cpu);
    if (cpu.terminate) return;
    // 0052c8ad  b884000000             -mov eax, 0x84
    cpu.eax = 132 /*0x84*/;
    // 0052c8b2  e869240000             -call 0x52ed20
    cpu.esp -= 4;
    sub_52ed20(app, cpu);
    if (cpu.terminate) return;
    // 0052c8b7  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0052c8b8:
    // 0052c8b8  2500000080             -and eax, 0x80000000
    cpu.eax &= x86::reg32(x86::sreg32(2147483648 /*0x80000000*/));
    // 0052c8bd  0d0000f07f             -or eax, 0x7ff00000
    cpu.eax |= x86::reg32(x86::sreg32(2146435072 /*0x7ff00000*/));
    // 0052c8c2  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0052c8c4  29c0                   -sub eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0052c8c6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_52c89b(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x0052c89b;
    // 0052c88f  b883000000             -mov eax, 0x83
    cpu.eax = 131 /*0x83*/;
    // 0052c894  e887240000             -call 0x52ed20
    cpu.esp -= 4;
    sub_52ed20(app, cpu);
    if (cpu.terminate) return;
    // 0052c899  eb1d                   -jmp 0x52c8b8
    goto L_0x0052c8b8;
L_entry_0x0052c89b:
    // 0052c89b  b883000000             -mov eax, 0x83
    cpu.eax = 131 /*0x83*/;
    // 0052c8a0  e87b240000             -call 0x52ed20
    cpu.esp -= 4;
    sub_52ed20(app, cpu);
    if (cpu.terminate) return;
    // 0052c8a5  eb11                   -jmp 0x52c8b8
    goto L_0x0052c8b8;
    // 0052c8a7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0052c8a8  e8f75ffdff             -call 0x5028a4
    cpu.esp -= 4;
    sub_5028a4(app, cpu);
    if (cpu.terminate) return;
    // 0052c8ad  b884000000             -mov eax, 0x84
    cpu.eax = 132 /*0x84*/;
    // 0052c8b2  e869240000             -call 0x52ed20
    cpu.esp -= 4;
    sub_52ed20(app, cpu);
    if (cpu.terminate) return;
    // 0052c8b7  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0052c8b8:
    // 0052c8b8  2500000080             -and eax, 0x80000000
    cpu.eax &= x86::reg32(x86::sreg32(2147483648 /*0x80000000*/));
    // 0052c8bd  0d0000f07f             -or eax, 0x7ff00000
    cpu.eax |= x86::reg32(x86::sreg32(2146435072 /*0x7ff00000*/));
    // 0052c8c2  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0052c8c4  29c0                   -sub eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0052c8c6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_52c8c7(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052c8c7  b883000000             -mov eax, 0x83
    cpu.eax = 131 /*0x83*/;
    // 0052c8cc  e84f240000             -call 0x52ed20
    cpu.esp -= 4;
    sub_52ed20(app, cpu);
    if (cpu.terminate) return;
    // 0052c8d1  eb11                   -jmp 0x52c8e4
    goto L_0x0052c8e4;
    // 0052c8d3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0052c8d4  e8cb5ffdff             -call 0x5028a4
    cpu.esp -= 4;
    sub_5028a4(app, cpu);
    if (cpu.terminate) return;
    // 0052c8d9  b884000000             -mov eax, 0x84
    cpu.eax = 132 /*0x84*/;
    // 0052c8de  e83d240000             -call 0x52ed20
    cpu.esp -= 4;
    sub_52ed20(app, cpu);
    if (cpu.terminate) return;
    // 0052c8e3  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0052c8e4:
    // 0052c8e4  2500000080             -and eax, 0x80000000
    cpu.eax &= x86::reg32(x86::sreg32(2147483648 /*0x80000000*/));
    // 0052c8e9  0d0000807f             -or eax, 0x7f800000
    cpu.eax |= x86::reg32(x86::sreg32(2139095040 /*0x7f800000*/));
    // 0052c8ee  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_52c8f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052c8f0  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0052c8f3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_52c8f4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052c8f4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052c8f5  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052c8f8  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0052c8fa  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0052c8fd  3b4508                 +cmp eax, dword ptr [ebp + 8]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052c900  7366                   -jae 0x52c968
    if (!cpu.flags.cf)
    {
        goto L_0x0052c968;
    }
    // 0052c902  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0052c903  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052c904  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052c905  8b4504                 -mov eax, dword ptr [ebp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 0052c908  8d0c10                 -lea ecx, [eax + edx]
    cpu.ecx = x86::reg32(cpu.eax + cpu.edx * 1);
    // 0052c90b  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0052c90e  894d04                 -mov dword ptr [ebp + 4], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 0052c911  39f9                   +cmp ecx, edi
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052c913  725d                   -jb 0x52c972
    if (cpu.flags.cf)
    {
        goto L_0x0052c972;
    }
    // 0052c915  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0052c917  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0052c919  894c240c               -mov dword ptr [esp + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 0052c91d  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0052c921  8a4d0c                 -mov cl, byte ptr [ebp + 0xc]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0052c924  d3e6                   -shl esi, cl
    cpu.esi <<= cpu.cl % 32;
    // 0052c926  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 0052c928  8b4d00                 -mov ecx, dword ptr [ebp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp);
    // 0052c92b  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0052c92d  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0052c92f  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0052c931  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0052c933  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0052c934  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0052c936  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0052c939  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0052c93b  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0052c93d  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0052c940  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0052c942  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c943  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0052c947  8a4d0c                 -mov cl, byte ptr [ebp + 0xc]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0052c94a  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0052c94c  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 0052c94e  d3e2                   -shl edx, cl
    cpu.edx <<= cpu.cl % 32;
    // 0052c950  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0052c952  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0052c954  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0052c956  e8e53cfbff             -call 0x4e0640
    cpu.esp -= 4;
    sub_4e0640(app, cpu);
    if (cpu.terminate) return;
    // 0052c95b  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0052c960  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c961  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c962  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c963  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052c966  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c967  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052c968:
    // 0052c968  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0052c96d  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052c970  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c971  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052c972:
    // 0052c972  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0052c974  8a4d0c                 -mov cl, byte ptr [ebp + 0xc]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0052c977  8b7500                 -mov esi, dword ptr [ebp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp);
    // 0052c97a  d3e2                   -shl edx, cl
    cpu.edx <<= cpu.cl % 32;
    // 0052c97c  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 0052c97e  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0052c980  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0052c982  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0052c983  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0052c985  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0052c988  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0052c98a  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0052c98c  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0052c98f  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0052c991  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c992  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0052c997  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c998  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c999  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c99a  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052c99d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c99e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_52c9a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052c9a0  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 0052c9a7  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 0052c9a9  d1f9                   -sar ecx, 1
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (1 /*0x1*/ % 32));
    // 0052c9ab  895808                 -mov dword ptr [eax + 8], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 0052c9ae  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 0052c9b1  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0052c9b5  c700f4c85200           -mov dword ptr [eax], 0x52c8f4
    app->getMemory<x86::reg32>(cpu.eax) = 5425396 /*0x52c8f4*/;
    // 0052c9bb  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0052c9bf  c700f0c85200           -mov dword ptr [eax], 0x52c8f0
    app->getMemory<x86::reg32>(cpu.eax) = 5425392 /*0x52c8f0*/;
    // 0052c9c5  b810000000             -mov eax, 0x10
    cpu.eax = 16 /*0x10*/;
    // 0052c9ca  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_52c9d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052c9d0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052c9d1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052c9d2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0052c9d3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052c9d4  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052c9d7  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0052c9d9  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 0052c9dc  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0052c9de  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0052c9e0  7e59                   -jle 0x52ca3b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0052ca3b;
    }
L_0x0052c9e2:
    // 0052c9e2  8b5a0c                 -mov ebx, dword ptr [edx + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 0052c9e5  2b5a04                 -sub ebx, dword ptr [edx + 4]
    (cpu.ebx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 0052c9e8  43                     -inc ebx
    (cpu.ebx)++;
    // 0052c9e9  39dd                   +cmp ebp, ebx
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052c9eb  7d02                   -jge 0x52c9ef
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0052c9ef;
    }
    // 0052c9ed  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
L_0x0052c9ef:
    // 0052c9ef  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0052c9f1  8a4a10                 -mov cl, byte ptr [edx + 0x10]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 0052c9f4  8b4204                 -mov eax, dword ptr [edx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0052c9f7  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx);
    // 0052c9f9  d3e7                   -shl edi, cl
    cpu.edi <<= cpu.cl % 32;
    // 0052c9fb  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 0052c9fd  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0052c9ff  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0052ca01  8b3c24                 -mov edi, dword ptr [esp]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    // 0052ca04  29dd                   -sub ebp, ebx
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0052ca06  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0052ca07  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0052ca09  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0052ca0c  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0052ca0e  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0052ca10  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0052ca13  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0052ca15  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052ca16  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0052ca18  8b7204                 -mov esi, dword ptr [edx + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0052ca1b  8a4a10                 -mov cl, byte ptr [edx + 0x10]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 0052ca1e  01de                   -add esi, ebx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0052ca20  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 0052ca22  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 0052ca25  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0052ca27  897204                 -mov dword ptr [edx + 4], esi
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 0052ca2a  893c24                 -mov dword ptr [esp], edi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edi;
    // 0052ca2d  39ce                   +cmp esi, ecx
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
    // 0052ca2f  7606                   -jbe 0x52ca37
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0052ca37;
    }
    // 0052ca31  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0052ca34  894204                 -mov dword ptr [edx + 4], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.eax;
L_0x0052ca37:
    // 0052ca37  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0052ca39  7fa7                   -jg 0x52c9e2
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0052c9e2;
    }
L_0x0052ca3b:
    // 0052ca3b  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0052ca40  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052ca43  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052ca44  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052ca45  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052ca46  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052ca47  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_52ca48(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052ca48  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 0052ca4f  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 0052ca51  895808                 -mov dword ptr [eax + 8], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 0052ca54  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0052ca58  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 0052ca5b  d1fa                   -sar edx, 1
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (1 /*0x1*/ % 32));
    // 0052ca5d  895010                 -mov dword ptr [eax + 0x10], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 0052ca60  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0052ca64  c700d0c95200           -mov dword ptr [eax], 0x52c9d0
    app->getMemory<x86::reg32>(cpu.eax) = 5425616 /*0x52c9d0*/;
    // 0052ca6a  b814000000             -mov eax, 0x14
    cpu.eax = 20 /*0x14*/;
    // 0052ca6f  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_52ca80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052ca80  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052ca81  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052ca82  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0052ca83  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052ca84  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0052ca87  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0052ca8b  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 0052ca8f  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0052ca91  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0052ca93  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0052ca95  7471                   -je 0x52cb08
    if (cpu.flags.zf)
    {
        goto L_0x0052cb08;
    }
    // 0052ca97  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052ca9a  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
L_0x0052ca9d:
    // 0052ca9d  837c240800             +cmp dword ptr [esp + 8], 0
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
    // 0052caa2  0f8ebd000000           -jle 0x52cb65
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0052cb65;
    }
    // 0052caa8  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0052caab  3b4504                 +cmp eax, dword ptr [ebp + 4]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052caae  7d65                   -jge 0x52cb15
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0052cb15;
    }
L_0x0052cab0:
    // 0052cab0  8b5504                 -mov edx, dword ptr [ebp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 0052cab3  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0052cab6  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0052caba  29fa                   -sub edx, edi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edi));
    // 0052cabc  39c2                   +cmp edx, eax
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
    // 0052cabe  0f8f9a000000           -jg 0x52cb5e
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0052cb5e;
    }
L_0x0052cac4:
    // 0052cac4  8b7c2404               -mov edi, dword ptr [esp + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0052cac8  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0052caca  8a4d0c                 -mov cl, byte ptr [ebp + 0xc]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0052cacd  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0052cad0  8b7500                 -mov esi, dword ptr [ebp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp);
    // 0052cad3  d3e3                   -shl ebx, cl
    cpu.ebx <<= cpu.cl % 32;
    // 0052cad5  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 0052cad7  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0052cad9  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0052cadb  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0052cadc  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0052cade  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0052cae1  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0052cae3  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0052cae5  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0052cae8  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0052caea  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052caeb  015508                 -add dword ptr [ebp + 8], edx
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */)) += x86::reg32(x86::sreg32(cpu.edx));
    // 0052caee  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0052caf0  8a4d0c                 -mov cl, byte ptr [ebp + 0xc]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0052caf3  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0052caf7  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 0052caf9  29d6                   +sub esi, edx
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
    // 0052cafb  8d1c07                 -lea ebx, [edi + eax]
    cpu.ebx = x86::reg32(cpu.edi + cpu.eax * 1);
    // 0052cafe  89742408               -mov dword ptr [esp + 8], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.esi;
    // 0052cb02  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 0052cb06  eb95                   -jmp 0x52ca9d
    goto L_0x0052ca9d;
L_0x0052cb08:
    // 0052cb08  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0052cb0d  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0052cb10  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052cb11  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052cb12  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052cb13  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052cb14  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052cb15:
    // 0052cb15  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 0052cb18  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0052cb1a  ff15b4785600           -call dword ptr [0x5678b4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666996) /* 0x5678b4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0052cb20  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052cb22  750b                   -jne 0x52cb2f
    if (!cpu.flags.zf)
    {
        goto L_0x0052cb2f;
    }
    // 0052cb24  837d0000               +cmp dword ptr [ebp], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052cb28  7405                   -je 0x52cb2f
    if (cpu.flags.zf)
    {
        goto L_0x0052cb2f;
    }
    // 0052cb2a  894508                 -mov dword ptr [ebp + 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0052cb2d  eb81                   -jmp 0x52cab0
    goto L_0x0052cab0;
L_0x0052cb2f:
    // 0052cb2f  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0052cb33  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0052cb37  8a4d0c                 -mov cl, byte ptr [ebp + 0xc]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0052cb3a  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0052cb3c  d3e3                   -shl ebx, cl
    cpu.ebx <<= cpu.cl % 32;
    // 0052cb3e  e8fd3afbff             -call 0x4e0640
    cpu.esp -= 4;
    sub_4e0640(app, cpu);
    if (cpu.terminate) return;
    // 0052cb43  c7450800000000         -mov dword ptr [ebp + 8], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 0052cb4a  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0052cb4f  c7450400000000         -mov dword ptr [ebp + 4], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 0052cb56  83c40c                 +add esp, 0xc
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(12 /*0xc*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0052cb59  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052cb5a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052cb5b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052cb5c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052cb5d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052cb5e:
    // 0052cb5e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0052cb60  e95fffffff             -jmp 0x52cac4
    goto L_0x0052cac4;
L_0x0052cb65:
    // 0052cb65  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0052cb6a  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0052cb6d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052cb6e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052cb6f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052cb70  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052cb71  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_52cb74(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052cb74  c70001000000           -mov dword ptr [eax], 1
    app->getMemory<x86::reg32>(cpu.eax) = 1 /*0x1*/;
    // 0052cb7a  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 0052cb81  d1fa                   -sar edx, 1
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (1 /*0x1*/ % 32));
    // 0052cb83  c7400800000000         -mov dword ptr [eax + 8], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 0052cb8a  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0052cb8d  b810000000             -mov eax, 0x10
    cpu.eax = 16 /*0x10*/;
    // 0052cb92  c70380ca5200           -mov dword ptr [ebx], 0x52ca80
    app->getMemory<x86::reg32>(cpu.ebx) = 5425792 /*0x52ca80*/;
    // 0052cb98  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_52cba0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052cba0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052cba1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052cba2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0052cba3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052cba4  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0052cba7  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0052cba9  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0052cbad  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 0052cbb1  668b5012               -mov dx, word ptr [eax + 0x12]
    cpu.dx = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(18) /* 0x12 */);
    // 0052cbb5  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0052cbb7  6685d2                 +test dx, dx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.dx & cpu.dx));
    // 0052cbba  0f8589000000           -jne 0x52cc49
    if (!cpu.flags.zf)
    {
        goto L_0x0052cc49;
    }
L_0x0052cbc0:
    // 0052cbc0  837c240800             +cmp dword ptr [esp + 8], 0
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
    // 0052cbc5  0f8ec6000000           -jle 0x52cc91
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0052cc91;
    }
    // 0052cbcb  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0052cbce  3b4504                 +cmp eax, dword ptr [ebp + 4]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052cbd1  0f8d8b000000           -jge 0x52cc62
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0052cc62;
    }
L_0x0052cbd7:
    // 0052cbd7  8b5504                 -mov edx, dword ptr [ebp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 0052cbda  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0052cbdd  8b7c2408               -mov edi, dword ptr [esp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0052cbe1  29f2                   -sub edx, esi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0052cbe3  39fa                   +cmp edx, edi
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052cbe5  0f8fc6000000           -jg 0x52ccb1
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0052ccb1;
    }
L_0x0052cbeb:
    // 0052cbeb  8b7c2404               -mov edi, dword ptr [esp + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0052cbef  8b450e                 -mov eax, dword ptr [ebp + 0xe]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(14) /* 0xe */);
    // 0052cbf2  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0052cbf4  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0052cbf7  8b7500                 -mov esi, dword ptr [ebp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp);
    // 0052cbfa  88c1                   -mov cl, al
    cpu.cl = cpu.al;
    // 0052cbfc  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0052cbff  d3e3                   -shl ebx, cl
    cpu.ebx <<= cpu.cl % 32;
    // 0052cc01  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 0052cc03  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0052cc05  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0052cc07  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0052cc08  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0052cc0a  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0052cc0d  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0052cc0f  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0052cc11  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0052cc14  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0052cc16  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052cc17  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0052cc1b  8b4d0e                 -mov ecx, dword ptr [ebp + 0xe]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(14) /* 0xe */);
    // 0052cc1e  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0052cc21  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 0052cc24  29d3                   -sub ebx, edx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0052cc26  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0052cc28  895c2408               -mov dword ptr [esp + 8], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 0052cc2c  894508                 -mov dword ptr [ebp + 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0052cc2f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0052cc31  668b5d12               -mov bx, word ptr [ebp + 0x12]
    cpu.bx = app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(18) /* 0x12 */);
    // 0052cc35  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 0052cc37  01d3                   +add ebx, edx
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0052cc39  8d0c07                 -lea ecx, [edi + eax]
    cpu.ecx = x86::reg32(cpu.edi + cpu.eax * 1);
    // 0052cc3c  66895d12               -mov word ptr [ebp + 0x12], bx
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(18) /* 0x12 */) = cpu.bx;
    // 0052cc40  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 0052cc44  e977ffffff             -jmp 0x52cbc0
    goto L_0x0052cbc0;
L_0x0052cc49:
    // 0052cc49  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0052cc4b  668b5012               -mov dx, word ptr [eax + 0x12]
    cpu.dx = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(18) /* 0x12 */);
    // 0052cc4f  8b400c                 -mov eax, dword ptr [eax + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0052cc52  e8414dfeff             -call 0x511998
    cpu.esp -= 4;
    sub_511998(app, cpu);
    if (cpu.terminate) return;
    // 0052cc57  66c741120000           -mov word ptr [ecx + 0x12], 0
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(18) /* 0x12 */) = 0 /*0x0*/;
    // 0052cc5d  e95effffff             -jmp 0x52cbc0
    goto L_0x0052cbc0;
L_0x0052cc62:
    // 0052cc62  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0052cc64  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0052cc67  e8904cfeff             -call 0x5118fc
    cpu.esp -= 4;
    sub_5118fc(app, cpu);
    if (cpu.terminate) return;
    // 0052cc6c  894500                 -mov dword ptr [ebp], eax
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.eax;
    // 0052cc6f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052cc71  752c                   -jne 0x52cc9f
    if (!cpu.flags.zf)
    {
        goto L_0x0052cc9f;
    }
    // 0052cc73  66837d1200             +cmp word ptr [ebp + 0x12], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(18) /* 0x12 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0052cc78  7417                   -je 0x52cc91
    if (cpu.flags.zf)
    {
        goto L_0x0052cc91;
    }
    // 0052cc7a  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0052cc7e  8b4d0e                 -mov ecx, dword ptr [ebp + 0xe]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(14) /* 0xe */);
    // 0052cc81  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0052cc85  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 0052cc88  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0052cc8a  d3e3                   -shl ebx, cl
    cpu.ebx <<= cpu.cl % 32;
    // 0052cc8c  e8af39fbff             -call 0x4e0640
    cpu.esp -= 4;
    sub_4e0640(app, cpu);
    if (cpu.terminate) return;
L_0x0052cc91:
    // 0052cc91  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0052cc93  668b4512               -mov ax, word ptr [ebp + 0x12]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(18) /* 0x12 */);
    // 0052cc97  83c40c                 +add esp, 0xc
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(12 /*0xc*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0052cc9a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052cc9b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052cc9c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052cc9d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052cc9e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052cc9f:
    // 0052cc9f  c7450800000000         -mov dword ptr [ebp + 8], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 0052cca6  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0052cca9  894504                 -mov dword ptr [ebp + 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0052ccac  e926ffffff             -jmp 0x52cbd7
    goto L_0x0052cbd7;
L_0x0052ccb1:
    // 0052ccb1  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0052ccb3  e933ffffff             -jmp 0x52cbeb
    goto L_0x0052cbeb;
}

/* align: skip  */
void Application::sub_52ccb8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052ccb8  e8a3040000             -call 0x52d160
    cpu.esp -= 4;
    sub_52d160(app, cpu);
    if (cpu.terminate) return;
    // 0052ccbd  c70200000000           -mov dword ptr [edx], 0
    app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 0052ccc3  c74204ffffffff         -mov dword ptr [edx + 4], 0xffffffff
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = 4294967295 /*0xffffffff*/;
    // 0052ccca  c7420800000000         -mov dword ptr [edx + 8], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 0052ccd1  66c742120000           -mov word ptr [edx + 0x12], 0
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(18) /* 0x12 */) = 0 /*0x0*/;
    // 0052ccd7  d1fb                   -sar ebx, 1
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (1 /*0x1*/ % 32));
    // 0052ccd9  89420c                 -mov dword ptr [edx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0052ccdc  66895a10               -mov word ptr [edx + 0x10], bx
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(16) /* 0x10 */) = cpu.bx;
    // 0052cce0  b814000000             -mov eax, 0x14
    cpu.eax = 20 /*0x14*/;
    // 0052cce5  c701a0cb5200           -mov dword ptr [ecx], 0x52cba0
    app->getMemory<x86::reg32>(cpu.ecx) = 5426080 /*0x52cba0*/;
    // 0052cceb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_52ccf0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052ccf0  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0052ccf3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_52ccf4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052ccf4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052ccf5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0052ccf6  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052ccf7  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052ccfa  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0052ccfc  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 0052ccfe  8b5804                 -mov ebx, dword ptr [eax + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0052cd01  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0052cd04  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0052cd07  39d3                   +cmp ebx, edx
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
    // 0052cd09  733a                   -jae 0x52cd45
    if (!cpu.flags.cf)
    {
        goto L_0x0052cd45;
    }
    // 0052cd0b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052cd0c  8d143b                 -lea edx, [ebx + edi]
    cpu.edx = x86::reg32(cpu.ebx + cpu.edi * 1);
    // 0052cd0f  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0052cd12  895004                 -mov dword ptr [eax + 4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0052cd15  39ca                   +cmp edx, ecx
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
    // 0052cd17  734b                   -jae 0x52cd64
    if (!cpu.flags.cf)
    {
        goto L_0x0052cd64;
    }
    // 0052cd19  83781400               +cmp dword ptr [eax + 0x14], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052cd1d  742d                   -je 0x52cd4c
    if (cpu.flags.zf)
    {
        goto L_0x0052cd4c;
    }
    // 0052cd1f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052cd20  8a480c                 -mov cl, byte ptr [eax + 0xc]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0052cd23  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax);
    // 0052cd25  d3e3                   -shl ebx, cl
    cpu.ebx <<= cpu.cl % 32;
    // 0052cd27  01f3                   -add ebx, esi
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.esi));
    // 0052cd29  8a4818                 -mov cl, byte ptr [eax + 0x18]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0052cd2c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0052cd2d  d3e7                   -shl edi, cl
    cpu.edi <<= cpu.cl % 32;
    // 0052cd2f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0052cd30  e86b3bfdff             -call 0x5008a0
    cpu.esp -= 4;
    sub_5008a0(app, cpu);
    if (cpu.terminate) return;
L_0x0052cd35:
    // 0052cd35  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0052cd38  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0052cd3d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0052cd3e:
    // 0052cd3e  83c404                 +add esp, 4
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
    // 0052cd41  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052cd42  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052cd43  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052cd44  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052cd45:
    // 0052cd45  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0052cd4a  ebf2                   -jmp 0x52cd3e
    goto L_0x0052cd3e;
L_0x0052cd4c:
    // 0052cd4c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052cd4d  8a480c                 -mov cl, byte ptr [eax + 0xc]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0052cd50  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax);
    // 0052cd52  d3e3                   -shl ebx, cl
    cpu.ebx <<= cpu.cl % 32;
    // 0052cd54  01f3                   -add ebx, esi
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.esi));
    // 0052cd56  8a4818                 -mov cl, byte ptr [eax + 0x18]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0052cd59  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0052cd5a  d3e7                   +shl edi, cl
    {
        x86::reg8 tmp = cpu.cl % 32;
        x86::reg32& op = cpu.edi;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 0052cd5c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0052cd5d  e8ae3dfdff             -call 0x500b10
    cpu.esp -= 4;
    sub_500b10(app, cpu);
    if (cpu.terminate) return;
    // 0052cd62  ebd1                   -jmp 0x52cd35
    goto L_0x0052cd35;
L_0x0052cd64:
    // 0052cd64  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 0052cd66  8b5014                 -mov edx, dword ptr [eax + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 0052cd69  29dd                   -sub ebp, ebx
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0052cd6b  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0052cd6d  744b                   -je 0x52cdba
    if (cpu.flags.zf)
    {
        goto L_0x0052cdba;
    }
    // 0052cd6f  8a480c                 -mov cl, byte ptr [eax + 0xc]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0052cd72  d3e3                   -shl ebx, cl
    cpu.ebx <<= cpu.cl % 32;
    // 0052cd74  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0052cd76  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 0052cd78  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052cd79  01cb                   -add ebx, ecx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0052cd7b  8a4818                 -mov cl, byte ptr [eax + 0x18]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0052cd7e  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0052cd80  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0052cd81  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 0052cd83  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0052cd84  e8173bfdff             -call 0x5008a0
    cpu.esp -= 4;
    sub_5008a0(app, cpu);
    if (cpu.terminate) return;
L_0x0052cd89:
    // 0052cd89  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0052cd8c  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0052cd90  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 0052cd92  8a4910                 -mov cl, byte ptr [ecx + 0x10]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0052cd95  29eb                   -sub ebx, ebp
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 0052cd97  d3e3                   -shl ebx, cl
    cpu.ebx <<= cpu.cl % 32;
    // 0052cd99  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0052cd9d  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0052cd9f  8a4910                 -mov cl, byte ptr [ecx + 0x10]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0052cda2  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 0052cda4  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0052cda6  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 0052cda8  e89338fbff             -call 0x4e0640
    cpu.esp -= 4;
    sub_4e0640(app, cpu);
    if (cpu.terminate) return;
    // 0052cdad  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0052cdb2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052cdb3  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052cdb6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052cdb7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052cdb8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052cdb9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052cdba:
    // 0052cdba  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052cdbb  8a480c                 -mov cl, byte ptr [eax + 0xc]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0052cdbe  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0052cdc0  d3e3                   -shl ebx, cl
    cpu.ebx <<= cpu.cl % 32;
    // 0052cdc2  8a4818                 -mov cl, byte ptr [eax + 0x18]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0052cdc5  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0052cdc7  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0052cdc9  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0052cdca  d3e0                   +shl eax, cl
    {
        x86::reg8 tmp = cpu.cl % 32;
        x86::reg32& op = cpu.eax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 0052cdcc  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0052cdcd  e83e3dfdff             -call 0x500b10
    cpu.esp -= 4;
    sub_500b10(app, cpu);
    if (cpu.terminate) return;
    // 0052cdd2  ebb5                   -jmp 0x52cd89
    goto L_0x0052cd89;
}

/* align: skip  */
void Application::sub_52cdd4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052cdd4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052cdd5  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0052cdd9  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 0052cde0  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 0052cde2  895808                 -mov dword ptr [eax + 8], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 0052cde5  8d1431                 -lea edx, [ecx + esi]
    cpu.edx = x86::reg32(cpu.ecx + cpu.esi * 1);
    // 0052cde8  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0052cdeb  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 0052cdee  8d5602                 -lea edx, [esi + 2]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 0052cdf1  895010                 -mov dword ptr [eax + 0x10], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 0052cdf4  897018                 -mov dword ptr [eax + 0x18], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.esi;
    // 0052cdf7  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0052cdfb  c700f4cc5200           -mov dword ptr [eax], 0x52ccf4
    app->getMemory<x86::reg32>(cpu.eax) = 5426420 /*0x52ccf4*/;
    // 0052ce01  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0052ce05  c700f0cc5200           -mov dword ptr [eax], 0x52ccf0
    app->getMemory<x86::reg32>(cpu.eax) = 5426416 /*0x52ccf0*/;
    // 0052ce0b  b81c000000             -mov eax, 0x1c
    cpu.eax = 28 /*0x1c*/;
    // 0052ce10  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052ce11  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_52ce20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052ce20  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052ce21  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052ce22  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0052ce23  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052ce24  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0052ce26  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 0052ce28  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0052ce2a  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0052ce2c  7e58                   -jle 0x52ce86
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0052ce86;
    }
L_0x0052ce2e:
    // 0052ce2e  8b730c                 -mov esi, dword ptr [ebx + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 0052ce31  2b7304                 -sub esi, dword ptr [ebx + 4]
    (cpu.esi) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */)));
    // 0052ce34  46                     -inc esi
    (cpu.esi)++;
    // 0052ce35  39f7                   +cmp edi, esi
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052ce37  7d02                   -jge 0x52ce3b
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0052ce3b;
    }
    // 0052ce39  89fe                   -mov esi, edi
    cpu.esi = cpu.edi;
L_0x0052ce3b:
    // 0052ce3b  837b1800               +cmp dword ptr [ebx + 0x18], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052ce3f  744f                   -je 0x52ce90
    if (cpu.flags.zf)
    {
        goto L_0x0052ce90;
    }
    // 0052ce41  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0052ce44  8a4b10                 -mov cl, byte ptr [ebx + 0x10]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 0052ce47  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 0052ce49  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 0052ce4b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052ce4c  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0052ce4e  8a4b1c                 -mov cl, byte ptr [ebx + 0x1c]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(28) /* 0x1c */);
    // 0052ce51  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0052ce52  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0052ce54  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 0052ce56  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0052ce57  e8443afdff             -call 0x5008a0
    cpu.esp -= 4;
    sub_5008a0(app, cpu);
    if (cpu.terminate) return;
L_0x0052ce5c:
    // 0052ce5c  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0052ce5f  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0052ce62  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 0052ce64  8a4b14                 -mov cl, byte ptr [ebx + 0x14]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 0052ce67  894304                 -mov dword ptr [ebx + 4], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0052ce6a  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0052ce6c  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 0052ce6e  8b530c                 -mov edx, dword ptr [ebx + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 0052ce71  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 0052ce73  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0052ce76  29f7                   -sub edi, esi
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0052ce78  39d0                   +cmp eax, edx
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
    // 0052ce7a  7606                   -jbe 0x52ce82
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0052ce82;
    }
    // 0052ce7c  8b4308                 -mov eax, dword ptr [ebx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 0052ce7f  894304                 -mov dword ptr [ebx + 4], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.eax;
L_0x0052ce82:
    // 0052ce82  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0052ce84  7fa8                   -jg 0x52ce2e
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0052ce2e;
    }
L_0x0052ce86:
    // 0052ce86  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0052ce8b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052ce8c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052ce8d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052ce8e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052ce8f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052ce90:
    // 0052ce90  8b5304                 -mov edx, dword ptr [ebx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0052ce93  8a4b10                 -mov cl, byte ptr [ebx + 0x10]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 0052ce96  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 0052ce98  d3e2                   -shl edx, cl
    cpu.edx <<= cpu.cl % 32;
    // 0052ce9a  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052ce9b  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0052ce9d  8a4b1c                 -mov cl, byte ptr [ebx + 0x1c]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(28) /* 0x1c */);
    // 0052cea0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0052cea1  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0052cea3  d3e0                   +shl eax, cl
    {
        x86::reg8 tmp = cpu.cl % 32;
        x86::reg32& op = cpu.eax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 0052cea5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0052cea6  e8653cfdff             -call 0x500b10
    cpu.esp -= 4;
    sub_500b10(app, cpu);
    if (cpu.terminate) return;
    // 0052ceab  ebaf                   -jmp 0x52ce5c
    goto L_0x0052ce5c;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_52ceb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052ceb0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052ceb1  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0052ceb5  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 0052cebc  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 0052cebe  895808                 -mov dword ptr [eax + 8], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 0052cec1  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0052cec5  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 0052cec8  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 0052ceca  895010                 -mov dword ptr [eax + 0x10], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 0052cecd  8d5602                 -lea edx, [esi + 2]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 0052ced0  895014                 -mov dword ptr [eax + 0x14], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 0052ced3  89701c                 -mov dword ptr [eax + 0x1c], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.esi;
    // 0052ced6  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0052ceda  895018                 -mov dword ptr [eax + 0x18], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 0052cedd  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0052cee1  c70020ce5200           -mov dword ptr [eax], 0x52ce20
    app->getMemory<x86::reg32>(cpu.eax) = 5426720 /*0x52ce20*/;
    // 0052cee7  b820000000             -mov eax, 0x20
    cpu.eax = 32 /*0x20*/;
    // 0052ceec  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052ceed  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_52cef0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052cef0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052cef1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052cef2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0052cef3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052cef4  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052cef7  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0052cef9  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0052cefb  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0052cefd  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0052ceff  7467                   -je 0x52cf68
    if (cpu.flags.zf)
    {
        goto L_0x0052cf68;
    }
    // 0052cf01  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 0052cf03  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0052cf05  7e54                   -jle 0x52cf5b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0052cf5b;
    }
    // 0052cf07  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052cf0a  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
L_0x0052cf0d:
    // 0052cf0d  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0052cf10  3b4604                 +cmp eax, dword ptr [esi + 4]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052cf13  7d5a                   -jge 0x52cf6f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0052cf6f;
    }
L_0x0052cf15:
    // 0052cf15  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0052cf18  2b5e08                 -sub ebx, dword ptr [esi + 8]
    (cpu.ebx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */)));
    // 0052cf1b  39df                   +cmp edi, ebx
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
    // 0052cf1d  7d02                   -jge 0x52cf21
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0052cf21;
    }
    // 0052cf1f  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
L_0x0052cf21:
    // 0052cf21  837e1400               +cmp dword ptr [esi + 0x14], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052cf25  0f848c000000           -je 0x52cfb7
    if (cpu.flags.zf)
    {
        goto L_0x0052cfb7;
    }
    // 0052cf2b  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0052cf2e  8a4e0c                 -mov cl, byte ptr [esi + 0xc]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 0052cf31  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 0052cf33  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 0052cf35  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052cf36  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0052cf38  8a4e18                 -mov cl, byte ptr [esi + 0x18]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 0052cf3b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0052cf3c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0052cf3e  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 0052cf40  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0052cf41  e85a39fdff             -call 0x5008a0
    cpu.esp -= 4;
    sub_5008a0(app, cpu);
    if (cpu.terminate) return;
L_0x0052cf46:
    // 0052cf46  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0052cf49  015e08                 -add dword ptr [esi + 8], ebx
    (app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */)) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0052cf4c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0052cf4e  8a4e10                 -mov cl, byte ptr [esi + 0x10]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0052cf51  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 0052cf53  29df                   -sub edi, ebx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0052cf55  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 0052cf57  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0052cf59  7fb2                   -jg 0x52cf0d
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0052cf0d;
    }
L_0x0052cf5b:
    // 0052cf5b  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x0052cf60:
    // 0052cf60  83c404                 +add esp, 4
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
    // 0052cf63  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052cf64  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052cf65  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052cf66  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052cf67  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052cf68:
    // 0052cf68  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0052cf6d  ebf1                   -jmp 0x52cf60
    goto L_0x0052cf60;
L_0x0052cf6f:
    // 0052cf6f  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 0052cf72  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0052cf74  ff15b4785600           -call dword ptr [0x5678b4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666996) /* 0x5678b4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0052cf7a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052cf7c  750e                   -jne 0x52cf8c
    if (!cpu.flags.zf)
    {
        goto L_0x0052cf8c;
    }
    // 0052cf7e  833e00                 +cmp dword ptr [esi], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052cf81  7409                   -je 0x52cf8c
    if (cpu.flags.zf)
    {
        goto L_0x0052cf8c;
    }
    // 0052cf83  c7460800000000         -mov dword ptr [esi + 8], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 0052cf8a  eb89                   -jmp 0x52cf15
    goto L_0x0052cf15;
L_0x0052cf8c:
    // 0052cf8c  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 0052cf8e  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0052cf90  8a4e10                 -mov cl, byte ptr [esi + 0x10]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0052cf93  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0052cf95  d3e3                   -shl ebx, cl
    cpu.ebx <<= cpu.cl % 32;
    // 0052cf97  e8a436fbff             -call 0x4e0640
    cpu.esp -= 4;
    sub_4e0640(app, cpu);
    if (cpu.terminate) return;
    // 0052cf9c  c7460800000000         -mov dword ptr [esi + 8], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 0052cfa3  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0052cfa8  c7460400000000         -mov dword ptr [esi + 4], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 0052cfaf  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052cfb2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052cfb3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052cfb4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052cfb5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052cfb6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052cfb7:
    // 0052cfb7  8b5608                 -mov edx, dword ptr [esi + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0052cfba  8a4e0c                 -mov cl, byte ptr [esi + 0xc]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 0052cfbd  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0052cfbf  d3e2                   -shl edx, cl
    cpu.edx <<= cpu.cl % 32;
    // 0052cfc1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052cfc2  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0052cfc4  8a4e18                 -mov cl, byte ptr [esi + 0x18]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 0052cfc7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0052cfc8  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0052cfca  d3e0                   +shl eax, cl
    {
        x86::reg8 tmp = cpu.cl % 32;
        x86::reg32& op = cpu.eax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 0052cfcc  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0052cfcd  e83e3bfdff             -call 0x500b10
    cpu.esp -= 4;
    sub_500b10(app, cpu);
    if (cpu.terminate) return;
    // 0052cfd2  e96fffffff             -jmp 0x52cf46
    goto L_0x0052cf46;
}

/* align: skip 0x90 */
void Application::sub_52cfd8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052cfd8  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052cfd9  c70001000000           -mov dword ptr [eax], 1
    app->getMemory<x86::reg32>(cpu.eax) = 1 /*0x1*/;
    // 0052cfdf  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 0052cfe6  c7400800000000         -mov dword ptr [eax + 8], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 0052cfed  8d341a                 -lea esi, [edx + ebx]
    cpu.esi = x86::reg32(cpu.edx + cpu.ebx * 1);
    // 0052cff0  89700c                 -mov dword ptr [eax + 0xc], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.esi;
    // 0052cff3  895014                 -mov dword ptr [eax + 0x14], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 0052cff6  8d7302                 -lea esi, [ebx + 2]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(2) /* 0x2 */);
    // 0052cff9  897010                 -mov dword ptr [eax + 0x10], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.esi;
    // 0052cffc  895818                 -mov dword ptr [eax + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 0052cfff  b81c000000             -mov eax, 0x1c
    cpu.eax = 28 /*0x1c*/;
    // 0052d004  c701f0ce5200           -mov dword ptr [ecx], 0x52cef0
    app->getMemory<x86::reg32>(cpu.ecx) = 5426928 /*0x52cef0*/;
    // 0052d00a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052d00b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_52d010(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052d010  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052d011  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052d012  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0052d013  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052d014  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052d017  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0052d019  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0052d01b  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 0052d01d  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0052d020  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0052d022  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0052d024  756a                   -jne 0x52d090
    if (!cpu.flags.zf)
    {
        goto L_0x0052d090;
    }
L_0x0052d026:
    // 0052d026  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0052d028  0f8e9c000000           -jle 0x52d0ca
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0052d0ca;
    }
    // 0052d02e  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0052d031  3b4604                 +cmp eax, dword ptr [esi + 4]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052d034  7d6b                   -jge 0x52d0a1
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0052d0a1;
    }
L_0x0052d036:
    // 0052d036  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0052d039  2b5e08                 -sub ebx, dword ptr [esi + 8]
    (cpu.ebx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */)));
    // 0052d03c  39df                   +cmp edi, ebx
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
    // 0052d03e  7d02                   -jge 0x52d042
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0052d042;
    }
    // 0052d040  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
L_0x0052d042:
    // 0052d042  807e1600               +cmp byte ptr [esi + 0x16], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(22) /* 0x16 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0052d046  0f849b000000           -je 0x52d0e7
    if (cpu.flags.zf)
    {
        goto L_0x0052d0e7;
    }
    // 0052d04c  8b4e11                 -mov ecx, dword ptr [esi + 0x11]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(17) /* 0x11 */);
    // 0052d04f  8b5608                 -mov edx, dword ptr [esi + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0052d052  c1f918                 -sar ecx, 0x18
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (24 /*0x18*/ % 32));
    // 0052d055  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0052d057  d3e2                   -shl edx, cl
    cpu.edx <<= cpu.cl % 32;
    // 0052d059  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052d05a  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0052d05c  8b4e14                 -mov ecx, dword ptr [esi + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0052d05f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0052d060  c1f918                 -sar ecx, 0x18
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (24 /*0x18*/ % 32));
    // 0052d063  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0052d065  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 0052d067  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0052d068  e83338fdff             -call 0x5008a0
    cpu.esp -= 4;
    sub_5008a0(app, cpu);
    if (cpu.terminate) return;
L_0x0052d06d:
    // 0052d06d  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0052d070  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0052d072  8b5608                 -mov edx, dword ptr [esi + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0052d075  8b4e12                 -mov ecx, dword ptr [esi + 0x12]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(18) /* 0x12 */);
    // 0052d078  29df                   -sub edi, ebx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0052d07a  c1f918                 -sar ecx, 0x18
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (24 /*0x18*/ % 32));
    // 0052d07d  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0052d07f  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 0052d081  8b4e10                 -mov ecx, dword ptr [esi + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0052d084  895608                 -mov dword ptr [esi + 8], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0052d087  01d9                   -add ecx, ebx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0052d089  01c5                   +add ebp, eax
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0052d08b  894e10                 -mov dword ptr [esi + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 0052d08e  eb96                   -jmp 0x52d026
    goto L_0x0052d026;
L_0x0052d090:
    // 0052d090  8b400c                 -mov eax, dword ptr [eax + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0052d093  e80049feff             -call 0x511998
    cpu.esp -= 4;
    sub_511998(app, cpu);
    if (cpu.terminate) return;
    // 0052d098  c7411000000000         -mov dword ptr [ecx + 0x10], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
    // 0052d09f  eb85                   -jmp 0x52d026
    goto L_0x0052d026;
L_0x0052d0a1:
    // 0052d0a1  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0052d0a3  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 0052d0a6  e85148feff             -call 0x5118fc
    cpu.esp -= 4;
    sub_5118fc(app, cpu);
    if (cpu.terminate) return;
    // 0052d0ab  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 0052d0ad  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052d0af  7524                   -jne 0x52d0d5
    if (!cpu.flags.zf)
    {
        goto L_0x0052d0d5;
    }
    // 0052d0b1  837e1000               +cmp dword ptr [esi + 0x10], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052d0b5  7413                   -je 0x52d0ca
    if (cpu.flags.zf)
    {
        goto L_0x0052d0ca;
    }
    // 0052d0b7  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 0052d0b9  8b4e12                 -mov ecx, dword ptr [esi + 0x12]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(18) /* 0x12 */);
    // 0052d0bc  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0052d0be  c1f918                 -sar ecx, 0x18
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (24 /*0x18*/ % 32));
    // 0052d0c1  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0052d0c3  d3e3                   -shl ebx, cl
    cpu.ebx <<= cpu.cl % 32;
    // 0052d0c5  e87635fbff             -call 0x4e0640
    cpu.esp -= 4;
    sub_4e0640(app, cpu);
    if (cpu.terminate) return;
L_0x0052d0ca:
    // 0052d0ca  8b4610                 -mov eax, dword ptr [esi + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0052d0cd  83c404                 +add esp, 4
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
    // 0052d0d0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052d0d1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052d0d2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052d0d3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052d0d4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052d0d5:
    // 0052d0d5  c7460800000000         -mov dword ptr [esi + 8], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 0052d0dc  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0052d0df  894604                 -mov dword ptr [esi + 4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0052d0e2  e94fffffff             -jmp 0x52d036
    goto L_0x0052d036;
L_0x0052d0e7:
    // 0052d0e7  8b4e11                 -mov ecx, dword ptr [esi + 0x11]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(17) /* 0x11 */);
    // 0052d0ea  8b5608                 -mov edx, dword ptr [esi + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0052d0ed  c1f918                 -sar ecx, 0x18
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (24 /*0x18*/ % 32));
    // 0052d0f0  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0052d0f2  d3e2                   -shl edx, cl
    cpu.edx <<= cpu.cl % 32;
    // 0052d0f4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052d0f5  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0052d0f7  8b4e14                 -mov ecx, dword ptr [esi + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0052d0fa  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0052d0fb  c1f918                 -sar ecx, 0x18
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (24 /*0x18*/ % 32));
    // 0052d0fe  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0052d100  d3e0                   +shl eax, cl
    {
        x86::reg8 tmp = cpu.cl % 32;
        x86::reg32& op = cpu.eax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 0052d102  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0052d103  e8083afdff             -call 0x500b10
    cpu.esp -= 4;
    sub_500b10(app, cpu);
    if (cpu.terminate) return;
    // 0052d108  e960ffffff             -jmp 0x52d06d
    goto L_0x0052d06d;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_52d110(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052d110  e84b000000             -call 0x52d160
    cpu.esp -= 4;
    sub_52d160(app, cpu);
    if (cpu.terminate) return;
    // 0052d115  c70200000000           -mov dword ptr [edx], 0
    app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 0052d11b  c74204ffffffff         -mov dword ptr [edx + 4], 0xffffffff
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = 4294967295 /*0xffffffff*/;
    // 0052d122  c7420800000000         -mov dword ptr [edx + 8], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 0052d129  89420c                 -mov dword ptr [edx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0052d12c  88d8                   -mov al, bl
    cpu.al = cpu.bl;
    // 0052d12e  c7421000000000         -mov dword ptr [edx + 0x10], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
    // 0052d135  00c8                   -add al, cl
    (cpu.al) += x86::reg8(x86::sreg8(cpu.cl));
    // 0052d137  884214                 -mov byte ptr [edx + 0x14], al
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(20) /* 0x14 */) = cpu.al;
    // 0052d13a  88c8                   -mov al, cl
    cpu.al = cpu.cl;
    // 0052d13c  885a16                 -mov byte ptr [edx + 0x16], bl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(22) /* 0x16 */) = cpu.bl;
    // 0052d13f  0402                   -add al, 2
    (cpu.al) += x86::reg8(x86::sreg8(2 /*0x2*/));
    // 0052d141  884215                 -mov byte ptr [edx + 0x15], al
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(21) /* 0x15 */) = cpu.al;
    // 0052d144  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0052d148  884a17                 -mov byte ptr [edx + 0x17], cl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(23) /* 0x17 */) = cpu.cl;
    // 0052d14b  c70010d05200           -mov dword ptr [eax], 0x52d010
    app->getMemory<x86::reg32>(cpu.eax) = 5427216 /*0x52d010*/;
    // 0052d151  b818000000             -mov eax, 0x18
    cpu.eax = 24 /*0x18*/;
    // 0052d156  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_52d160(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052d160  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0052d161  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052d162  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0052d163  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0052d165  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0052d167  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0052d169:
    // 0052d169  8b8244b0a000           -mov eax, dword ptr [edx + 0xa0b044]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(10530884) /* 0xa0b044 */);
    // 0052d16f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052d171  7512                   -jne 0x52d185
    if (!cpu.flags.zf)
    {
        goto L_0x0052d185;
    }
L_0x0052d173:
    // 0052d173  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052d176  41                     -inc ecx
    (cpu.ecx)++;
    // 0052d177  83fa40                 +cmp edx, 0x40
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
    // 0052d17a  7ced                   -jl 0x52d169
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0052d169;
    }
    // 0052d17c  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0052d181  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052d182  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052d183  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052d184  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052d185:
    // 0052d185  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0052d187  e8102bfdff             -call 0x4ffc9c
    cpu.esp -= 4;
    sub_4ffc9c(app, cpu);
    if (cpu.terminate) return;
    // 0052d18c  39d8                   +cmp eax, ebx
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
    // 0052d18e  75e3                   -jne 0x52d173
    if (!cpu.flags.zf)
    {
        goto L_0x0052d173;
    }
    // 0052d190  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0052d192  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052d193  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052d194  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052d195  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_52d1a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052d1a0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052d1a1  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0052d1a3  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 0052d1a4  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0052d1a7  8b7e08                 -mov edi, dword ptr [esi + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0052d1aa  8b5e0c                 -mov ebx, dword ptr [esi + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 0052d1ad  0f6e5e04               -movd mm3, dword ptr [esi + 4]
    cpu.mmx.mm3 = { _mm_loadu_si32(&app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */)) };
    // 0052d1b1  ba0000ff7f             -mov edx, 0x7fff0000
    cpu.edx = 2147418112 /*0x7fff0000*/;
    // 0052d1b6  b800000080             -mov eax, 0x80000000
    cpu.eax = 2147483648 /*0x80000000*/;
    // 0052d1bb  0f6ee2                 -movd mm4, edx
    cpu.mmx.mm4 = { _mm_cvtsi32_si128(cpu.edx) };
    // 0052d1be  0f6ee8                 -movd mm5, eax
    cpu.mmx.mm5 = { _mm_cvtsi32_si128(cpu.eax) };
    // 0052d1c1  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0052d1c3:
    // 0052d1c3  833e00                 +cmp dword ptr [esi], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052d1c6  7e76                   -jle 0x52d23e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0052d23e;
    }
    // 0052d1c8  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0052d1ca  8a07                   -mov al, byte ptr [edi]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi);
    // 0052d1cc  832e1c                 -sub dword ptr [esi], 0x1c
    (app->getMemory<x86::reg32>(cpu.esi)) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0052d1cf  c1e804                 -shr eax, 4
    cpu.eax >>= 4 /*0x4*/ % 32;
    // 0052d1d2  83c338                 -add ebx, 0x38
    (cpu.ebx) += x86::reg32(x86::sreg32(56 /*0x38*/));
    // 0052d1d5  0f6e0c8570ad5600       -movd mm1, dword ptr [eax*4 + 0x56ad70]
    cpu.mmx.mm1 = { _mm_loadu_si32(&app->getMemory<x86::reg32>(x86::reg32(5680496) /* 0x56ad70 */ + cpu.eax * 4)) };
    // 0052d1dd  0f6e148580ad5600       -movd mm2, dword ptr [eax*4 + 0x56ad80]
    cpu.mmx.mm2 = { _mm_loadu_si32(&app->getMemory<x86::reg32>(x86::reg32(5680512) /* 0x56ad80 */ + cpu.eax * 4)) };
    // 0052d1e5  8a07                   -mov al, byte ptr [edi]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi);
    // 0052d1e7  b9f2ffffff             -mov ecx, 0xfffffff2
    cpu.ecx = 4294967282 /*0xfffffff2*/;
    // 0052d1ec  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 0052d1ef  83c70f                 -add edi, 0xf
    (cpu.edi) += x86::reg32(x86::sreg32(15 /*0xf*/));
    // 0052d1f2  c1e006                 -shl eax, 6
    cpu.eax <<= 6 /*0x6*/ % 32;
L_0x0052d1f5:
    // 0052d1f5  8a1439                 -mov dl, byte ptr [ecx + edi]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + cpu.edi * 1);
    // 0052d1f8  0f7fde                 -movq mm6, mm3
    cpu.mmx.mm6 = cpu.mmx.mm3;
    // 0052d1fb  c0ea04                 -shr dl, 4
    cpu.dl >>= 4 /*0x4*/ % 32;
    // 0052d1fe  0ff5f1                 -pmaddwd mm6, mm1
    cpu.mmx.mm6 = { _mm_madd_epi16(cpu.mmx.mm6, cpu.mmx.mm1) };
    // 0052d201  0f6e8490a0bea000       -movd mm0, dword ptr [eax + edx*4 + 0xa0bea0]
    cpu.mmx.mm0 = { _mm_loadu_si32(&app->getMemory<x86::reg32>(cpu.eax + x86::reg32(10534560) /* 0xa0bea0 */ + cpu.edx * 4)) };
    // 0052d209  0ffef0                 -paddd mm6, mm0
    cpu.mmx.mm6 = { _mm_add_epi32(cpu.mmx.mm6, cpu.mmx.mm0) };
    // 0052d20c  0f72f608               -pslld mm6, 8
    cpu.mmx.mm6 = { _mm_slli_epi32(cpu.mmx.mm6, 8 /*0x8*/) };
    // 0052d210  8a1439                 -mov dl, byte ptr [ecx + edi]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + cpu.edi * 1);
    // 0052d213  0f61f3                 -punpcklwd mm6, mm3
    cpu.mmx.mm6 = { _mm_unpacklo_epi16(cpu.mmx.mm6, cpu.mmx.mm3) };
    // 0052d216  80e20f                 +and dl, 0xf
    cpu.clear_co();
    cpu.set_szp((cpu.dl &= x86::reg8(x86::sreg8(15 /*0xf*/))));
    // 0052d219  0f73d620               -psrlq mm6, 0x20
    cpu.mmx.mm6 = { _mm_srli_epi64(cpu.mmx.mm6, 32 /*0x20*/) };
    // 0052d21d  0f7ff3                 -movq mm3, mm6
    cpu.mmx.mm3 = cpu.mmx.mm6;
    // 0052d220  0ff5f2                 -pmaddwd mm6, mm2
    cpu.mmx.mm6 = { _mm_madd_epi16(cpu.mmx.mm6, cpu.mmx.mm2) };
    // 0052d223  0f6e8490a0bea000       -movd mm0, dword ptr [eax + edx*4 + 0xa0bea0]
    cpu.mmx.mm0 = { _mm_loadu_si32(&app->getMemory<x86::reg32>(cpu.eax + x86::reg32(10534560) /* 0xa0bea0 */ + cpu.edx * 4)) };
    // 0052d22b  0ffef0                 -paddd mm6, mm0
    cpu.mmx.mm6 = { _mm_add_epi32(cpu.mmx.mm6, cpu.mmx.mm0) };
    // 0052d22e  0f73d608               -psrlq mm6, 8
    cpu.mmx.mm6 = { _mm_srli_epi64(cpu.mmx.mm6, 8 /*0x8*/) };
    // 0052d232  0f61de                 -punpcklwd mm3, mm6
    cpu.mmx.mm3 = { _mm_unpacklo_epi16(cpu.mmx.mm3, cpu.mmx.mm6) };
    // 0052d235  0f7e1c8b               -movd dword ptr [ebx + ecx*4], mm3
    _mm_storeu_si32(&app->getMemory<x86::reg32>(cpu.ebx + cpu.ecx * 4), cpu.mmx.mm3);
    // 0052d239  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0052d23a  7cb9                   -jl 0x52d1f5
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0052d1f5;
    }
    // 0052d23c  eb85                   -jmp 0x52d1c3
    goto L_0x0052d1c3;
L_0x0052d23e:
    // 0052d23e  0f7e5e04               -movd dword ptr [esi + 4], mm3
    _mm_storeu_si32(&app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */), cpu.mmx.mm3);
    // 0052d242  895e0c                 -mov dword ptr [esi + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 0052d245  61                     -popal 
    {
        cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
        cpu.esi = app->getMemory<x86::reg32>(cpu.esp + 4);
        cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + 8);
        // skip esp
        cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + 16);
        cpu.edx = app->getMemory<x86::reg32>(cpu.esp + 20);
        cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + 24);
        cpu.eax = app->getMemory<x86::reg32>(cpu.esp + 28);
        cpu.esp += 32;
    }
    // 0052d246  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052d247  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_52d250(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052d250  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052d251  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0052d253  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 0052d254  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0052d257  8b7e0c                 -mov edi, dword ptr [esi + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 0052d25a  8b5e10                 -mov ebx, dword ptr [esi + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0052d25d  0f6e5e04               -movd mm3, dword ptr [esi + 4]
    cpu.mmx.mm3 = { _mm_loadu_si32(&app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */)) };
    // 0052d261  0f625e08               -punpckldq mm3, dword ptr [esi + 8]
    cpu.mmx.mm3 = { _mm_unpacklo_epi32(cpu.mmx.mm3, x86::from_reg64(app->getMemory<x86::reg64>(cpu.esi + x86::reg32(8) /* 0x8 */))) };
    // 0052d265  b8ffff0000             -mov eax, 0xffff
    cpu.eax = 65535 /*0xffff*/;
    // 0052d26a  0f6ef8                 -movd mm7, eax
    cpu.mmx.mm7 = { _mm_cvtsi32_si128(cpu.eax) };
    // 0052d26d  0f62ff                 -punpckldq mm7, mm7
    cpu.mmx.mm7 = { _mm_unpacklo_epi32(cpu.mmx.mm7, cpu.mmx.mm7) };
    // 0052d270  0f7ffd                 -movq mm5, mm7
    cpu.mmx.mm5 = cpu.mmx.mm7;
    // 0052d273  0f72f510               -pslld mm5, 0x10
    cpu.mmx.mm5 = { _mm_slli_epi32(cpu.mmx.mm5, 16 /*0x10*/) };
    // 0052d277  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0052d279:
    // 0052d279  833e00                 +cmp dword ptr [esi], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052d27c  0f8edb000000           -jle 0x52d35d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0052d35d;
    }
    // 0052d282  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0052d284  8a07                   -mov al, byte ptr [edi]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi);
    // 0052d286  832e1c                 -sub dword ptr [esi], 0x1c
    (app->getMemory<x86::reg32>(cpu.esi)) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0052d289  8bd0                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0052d28b  c1e804                 -shr eax, 4
    cpu.eax >>= 4 /*0x4*/ % 32;
    // 0052d28e  83e20f                 -and edx, 0xf
    cpu.edx &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 0052d291  83c370                 -add ebx, 0x70
    (cpu.ebx) += x86::reg32(x86::sreg32(112 /*0x70*/));
    // 0052d294  0f6e0c8570ad5600       -movd mm1, dword ptr [eax*4 + 0x56ad70]
    cpu.mmx.mm1 = { _mm_loadu_si32(&app->getMemory<x86::reg32>(x86::reg32(5680496) /* 0x56ad70 */ + cpu.eax * 4)) };
    // 0052d29c  0f620c9570ad5600       -punpckldq mm1, dword ptr [edx*4 + 0x56ad70]
    cpu.mmx.mm1 = { _mm_unpacklo_epi32(cpu.mmx.mm1, x86::from_reg64(app->getMemory<x86::reg64>(x86::reg32(5680496) /* 0x56ad70 */ + cpu.edx * 4))) };
    // 0052d2a4  0f6e148580ad5600       -movd mm2, dword ptr [eax*4 + 0x56ad80]
    cpu.mmx.mm2 = { _mm_loadu_si32(&app->getMemory<x86::reg32>(x86::reg32(5680512) /* 0x56ad80 */ + cpu.eax * 4)) };
    // 0052d2ac  0f62149580ad5600       -punpckldq mm2, dword ptr [edx*4 + 0x56ad80]
    cpu.mmx.mm2 = { _mm_unpacklo_epi32(cpu.mmx.mm2, x86::from_reg64(app->getMemory<x86::reg64>(x86::reg32(5680512) /* 0x56ad80 */ + cpu.edx * 4))) };
    // 0052d2b4  8a4701                 -mov al, byte ptr [edi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 0052d2b7  b9e4ffffff             -mov ecx, 0xffffffe4
    cpu.ecx = 4294967268 /*0xffffffe4*/;
    // 0052d2bc  8bd0                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0052d2be  c1e804                 -shr eax, 4
    cpu.eax >>= 4 /*0x4*/ % 32;
    // 0052d2c1  83e20f                 -and edx, 0xf
    cpu.edx &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 0052d2c4  83c71e                 -add edi, 0x1e
    (cpu.edi) += x86::reg32(x86::sreg32(30 /*0x1e*/));
    // 0052d2c7  c1e206                 -shl edx, 6
    cpu.edx <<= 6 /*0x6*/ % 32;
    // 0052d2ca  c1e006                 -shl eax, 6
    cpu.eax <<= 6 /*0x6*/ % 32;
    // 0052d2cd  8bea                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0052d2cf  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0052d2d1:
    // 0052d2d1  8a1439                 -mov dl, byte ptr [ecx + edi]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + cpu.edi * 1);
    // 0052d2d4  c0ea04                 -shr dl, 4
    cpu.dl >>= 4 /*0x4*/ % 32;
    // 0052d2d7  0f7fde                 -movq mm6, mm3
    cpu.mmx.mm6 = cpu.mmx.mm3;
    // 0052d2da  0f6e8490a0bea000       -movd mm0, dword ptr [eax + edx*4 + 0xa0bea0]
    cpu.mmx.mm0 = { _mm_loadu_si32(&app->getMemory<x86::reg32>(cpu.eax + x86::reg32(10534560) /* 0xa0bea0 */ + cpu.edx * 4)) };
    // 0052d2e2  0ff5f1                 -pmaddwd mm6, mm1
    cpu.mmx.mm6 = { _mm_madd_epi16(cpu.mmx.mm6, cpu.mmx.mm1) };
    // 0052d2e5  8a1439                 -mov dl, byte ptr [ecx + edi]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + cpu.edi * 1);
    // 0052d2e8  80e20f                 -and dl, 0xf
    cpu.dl &= x86::reg8(x86::sreg8(15 /*0xf*/));
    // 0052d2eb  0f628495a0bea000       -punpckldq mm0, dword ptr [ebp + edx*4 + 0xa0bea0]
    cpu.mmx.mm0 = { _mm_unpacklo_epi32(cpu.mmx.mm0, x86::from_reg64(app->getMemory<x86::reg64>(cpu.ebp + x86::reg32(10534560) /* 0xa0bea0 */ + cpu.edx * 4))) };
    // 0052d2f3  0fdbdd                 -pand mm3, mm5
    cpu.mmx.mm3 = { _mm_and_si128(cpu.mmx.mm3, cpu.mmx.mm5) };
    // 0052d2f6  0ffef0                 -paddd mm6, mm0
    cpu.mmx.mm6 = { _mm_add_epi32(cpu.mmx.mm6, cpu.mmx.mm0) };
    // 0052d2f9  0f72d608               -psrld mm6, 8
    cpu.mmx.mm6 = { _mm_srli_epi32(cpu.mmx.mm6, 8 /*0x8*/) };
    // 0052d2fd  0fdbf7                 -pand mm6, mm7
    cpu.mmx.mm6 = { _mm_and_si128(cpu.mmx.mm6, cpu.mmx.mm7) };
    // 0052d300  0febde                 -por mm3, mm6
    cpu.mmx.mm3 = { _mm_or_si128(cpu.mmx.mm3, cpu.mmx.mm6) };
    // 0052d303  8a543901               -mov dl, byte ptr [ecx + edi + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */ + cpu.edi * 1);
    // 0052d307  c0ea04                 -shr dl, 4
    cpu.dl >>= 4 /*0x4*/ % 32;
    // 0052d30a  0f7fde                 -movq mm6, mm3
    cpu.mmx.mm6 = cpu.mmx.mm3;
    // 0052d30d  0f6e8490a0bea000       -movd mm0, dword ptr [eax + edx*4 + 0xa0bea0]
    cpu.mmx.mm0 = { _mm_loadu_si32(&app->getMemory<x86::reg32>(cpu.eax + x86::reg32(10534560) /* 0xa0bea0 */ + cpu.edx * 4)) };
    // 0052d315  8a543901               -mov dl, byte ptr [ecx + edi + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */ + cpu.edi * 1);
    // 0052d319  80e20f                 -and dl, 0xf
    cpu.dl &= x86::reg8(x86::sreg8(15 /*0xf*/));
    // 0052d31c  0f628495a0bea000       -punpckldq mm0, dword ptr [ebp + edx*4 + 0xa0bea0]
    cpu.mmx.mm0 = { _mm_unpacklo_epi32(cpu.mmx.mm0, x86::from_reg64(app->getMemory<x86::reg64>(cpu.ebp + x86::reg32(10534560) /* 0xa0bea0 */ + cpu.edx * 4))) };
    // 0052d324  0ff5f2                 -pmaddwd mm6, mm2
    cpu.mmx.mm6 = { _mm_madd_epi16(cpu.mmx.mm6, cpu.mmx.mm2) };
    // 0052d327  0fdbdf                 -pand mm3, mm7
    cpu.mmx.mm3 = { _mm_and_si128(cpu.mmx.mm3, cpu.mmx.mm7) };
    // 0052d32a  0ffef0                 -paddd mm6, mm0
    cpu.mmx.mm6 = { _mm_add_epi32(cpu.mmx.mm6, cpu.mmx.mm0) };
    // 0052d32d  0f72f608               -pslld mm6, 8
    cpu.mmx.mm6 = { _mm_slli_epi32(cpu.mmx.mm6, 8 /*0x8*/) };
    // 0052d331  0fdbf5                 -pand mm6, mm5
    cpu.mmx.mm6 = { _mm_and_si128(cpu.mmx.mm6, cpu.mmx.mm5) };
    // 0052d334  0febde                 -por mm3, mm6
    cpu.mmx.mm3 = { _mm_or_si128(cpu.mmx.mm3, cpu.mmx.mm6) };
    // 0052d337  0f7f1c8b               -movq qword ptr [ebx + ecx*4], mm3
    app->getMemory<x86::reg64>(cpu.ebx + cpu.ecx * 4) = cpu.mmx.mm3;
    // 0052d33b  66ff748b02             -push word ptr [ebx + ecx*4 + 2]
    app->getMemory<x86::reg16>(cpu.esp-4) = app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(2) /* 0x2 */ + cpu.ecx * 4);
    cpu.esp -= 4;
    // 0052d340  66ff748b04             -push word ptr [ebx + ecx*4 + 4]
    app->getMemory<x86::reg16>(cpu.esp-4) = app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(4) /* 0x4 */ + cpu.ecx * 4);
    cpu.esp -= 4;
    // 0052d345  668f448b02             -pop word ptr [ebx + ecx*4 + 2]
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(2) /* 0x2 */ + cpu.ecx * 4) = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 0052d34a  668f448b04             -pop word ptr [ebx + ecx*4 + 4]
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(4) /* 0x4 */ + cpu.ecx * 4) = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 0052d34f  83c102                 +add ecx, 2
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0052d352  0f8c79ffffff           -jl 0x52d2d1
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0052d2d1;
    }
    // 0052d358  e91cffffff             -jmp 0x52d279
    goto L_0x0052d279;
L_0x0052d35d:
    // 0052d35d  0f7e5e04               -movd dword ptr [esi + 4], mm3
    _mm_storeu_si32(&app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */), cpu.mmx.mm3);
    // 0052d361  0f73d320               -psrlq mm3, 0x20
    cpu.mmx.mm3 = { _mm_srli_epi64(cpu.mmx.mm3, 32 /*0x20*/) };
    // 0052d365  0f7e5e08               -movd dword ptr [esi + 8], mm3
    _mm_storeu_si32(&app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */), cpu.mmx.mm3);
    // 0052d369  895e10                 -mov dword ptr [esi + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 0052d36c  61                     -popal 
    {
        cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
        cpu.esi = app->getMemory<x86::reg32>(cpu.esp + 4);
        cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + 8);
        // skip esp
        cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + 16);
        cpu.edx = app->getMemory<x86::reg32>(cpu.esp + 20);
        cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + 24);
        cpu.eax = app->getMemory<x86::reg32>(cpu.esp + 28);
        cpu.esp += 32;
    }
    // 0052d36d  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052d36e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_52d370(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052d370  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0052d371  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052d372  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052d373  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0052d374  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0052d377  8b1c95d0b15600         -mov ebx, dword ptr [edx*4 + 0x56b1d0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5681616) /* 0x56b1d0 */ + cpu.edx * 4);
    // 0052d37e  8b7004                 -mov esi, dword ptr [eax + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0052d381  8b7808                 -mov edi, dword ptr [eax + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0052d384  21cb                   -and ebx, ecx
    cpu.ebx &= x86::reg32(x86::sreg32(cpu.ecx));
    // 0052d386  29d7                   -sub edi, edx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0052d388  88d1                   -mov cl, dl
    cpu.cl = cpu.dl;
    // 0052d38a  897808                 -mov dword ptr [eax + 8], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edi;
    // 0052d38d  d3ee                   -shr esi, cl
    cpu.esi >>= cpu.cl % 32;
    // 0052d38f  897004                 -mov dword ptr [eax + 4], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 0052d392  83ff08                 +cmp edi, 8
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052d395  7c07                   -jl 0x52d39e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0052d39e;
    }
    // 0052d397  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0052d399  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052d39a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052d39b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052d39c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052d39d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052d39e:
    // 0052d39e  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0052d3a0  8a12                   -mov dl, byte ptr [edx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx);
    // 0052d3a2  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0052d3a8  8a4808                 -mov cl, byte ptr [eax + 8]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0052d3ab  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax);
    // 0052d3ad  8b7808                 -mov edi, dword ptr [eax + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0052d3b0  46                     -inc esi
    (cpu.esi)++;
    // 0052d3b1  83c708                 -add edi, 8
    (cpu.edi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0052d3b4  8930                   -mov dword ptr [eax], esi
    app->getMemory<x86::reg32>(cpu.eax) = cpu.esi;
    // 0052d3b6  d3e2                   -shl edx, cl
    cpu.edx <<= cpu.cl % 32;
    // 0052d3b8  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0052d3bb  897808                 -mov dword ptr [eax + 8], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edi;
    // 0052d3be  09d1                   -or ecx, edx
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.edx));
    // 0052d3c0  894804                 -mov dword ptr [eax + 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 0052d3c3  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0052d3c5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052d3c6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052d3c7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052d3c8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052d3c9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_52d3cc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052d3cc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0052d3cd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052d3ce  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052d3cf  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052d3d0  88d1                   -mov cl, dl
    cpu.cl = cpu.dl;
    // 0052d3d2  8b5804                 -mov ebx, dword ptr [eax + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0052d3d5  8b7008                 -mov esi, dword ptr [eax + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0052d3d8  d3eb                   -shr ebx, cl
    cpu.ebx >>= cpu.cl % 32;
    // 0052d3da  29d6                   -sub esi, edx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0052d3dc  895804                 -mov dword ptr [eax + 4], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 0052d3df  897008                 -mov dword ptr [eax + 8], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.esi;
    // 0052d3e2  83fe08                 +cmp esi, 8
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052d3e5  7c05                   -jl 0x52d3ec
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0052d3ec;
    }
    // 0052d3e7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052d3e8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052d3e9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052d3ea  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052d3eb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052d3ec:
    // 0052d3ec  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0052d3ee  8a12                   -mov dl, byte ptr [edx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx);
    // 0052d3f0  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0052d3f6  8a4808                 -mov cl, byte ptr [eax + 8]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0052d3f9  8b6804                 -mov ebp, dword ptr [eax + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0052d3fc  d3e2                   -shl edx, cl
    cpu.edx <<= cpu.cl % 32;
    // 0052d3fe  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0052d401  09d5                   -or ebp, edx
    cpu.ebp |= x86::reg32(x86::sreg32(cpu.edx));
    // 0052d403  83c108                 -add ecx, 8
    (cpu.ecx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0052d406  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0052d408  896804                 -mov dword ptr [eax + 4], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 0052d40b  42                     -inc edx
    (cpu.edx)++;
    // 0052d40c  894808                 -mov dword ptr [eax + 8], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 0052d40f  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 0052d411  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052d412  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052d413  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052d414  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052d415  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_52d428(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 0052d428  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052d429  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0052d42a  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052d42b  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0052d42e  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0052d430  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 0052d432  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0052d434  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0052d436  753a                   -jne 0x52d472
    if (!cpu.flags.zf)
    {
        goto L_0x0052d472;
    }
    // 0052d438  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0052d43a  bb03000000             -mov ebx, 3
    cpu.ebx = 3 /*0x3*/;
L_0x0052d43f:
    // 0052d43f  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0052d442  21d8                   -and eax, ebx
    cpu.eax &= x86::reg32(x86::sreg32(cpu.ebx));
    // 0052d444  83f803                 +cmp eax, 3
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
    // 0052d447  771b                   -ja 0x52d464
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0052d464;
    }
    // 0052d449  ff248518d45200         -jmp dword ptr [eax*4 + 0x52d418]
    cpu.ip = app->getMemory<x86::reg32>(5428248 + cpu.eax * 4); goto dynamic_jump;
  case 0x0052d450:
    // 0052d450  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0052d455  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0052d457  c7448d0000000000       -mov dword ptr [ebp + ecx*4], 0
    app->getMemory<x86::reg32>(cpu.ebp + cpu.ecx * 4) = 0 /*0x0*/;
L_0x0052d45f:
    // 0052d45f  e868ffffff             -call 0x52d3cc
    cpu.esp -= 4;
    sub_52d3cc(app, cpu);
    if (cpu.terminate) return;
L_0x0052d464:
    // 0052d464  01f9                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 0052d466  83f96c                 +cmp ecx, 0x6c
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(108 /*0x6c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052d469  7cd4                   -jl 0x52d43f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0052d43f;
    }
    // 0052d46b  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0052d46e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052d46f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052d470  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052d471  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052d472:
    // 0052d472  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0052d474  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0052d476  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
L_0x0052d479:
    // 0052d479  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0052d47c  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 0052d47f  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0052d484  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 0052d487  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0052d489  8a9c02f4b25600         -mov bl, byte ptr [edx + eax + 0x56b2f4]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5681908) /* 0x56b2f4 */ + cpu.eax * 1);
    // 0052d490  6bc30c                 -imul eax, ebx, 0xc
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(12 /*0xc*/)));
    // 0052d493  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0052d497  8b80f4b45600           -mov eax, dword ptr [eax + 0x56b4f4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5682420) /* 0x56b4f4 */);
    // 0052d49d  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0052d4a1  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0052d4a4  8b92f8b45600           -mov edx, dword ptr [edx + 0x56b4f8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5682424) /* 0x56b4f8 */);
    // 0052d4aa  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0052d4ac  e81bffffff             -call 0x52d3cc
    cpu.esp -= 4;
    sub_52d3cc(app, cpu);
    if (cpu.terminate) return;
    // 0052d4b1  83fb03                 +cmp ebx, 3
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052d4b4  7e1c                   -jle 0x52d4d2
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0052d4d2;
    }
    // 0052d4b6  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0052d4ba  8b82fcb45600           -mov eax, dword ptr [edx + 0x56b4fc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5682428) /* 0x56b4fc */);
    // 0052d4c0  89448d00               -mov dword ptr [ebp + ecx*4], eax
    app->getMemory<x86::reg32>(cpu.ebp + cpu.ecx * 4) = cpu.eax;
    // 0052d4c4  01f9                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
L_0x0052d4c6:
    // 0052d4c6  83f96c                 +cmp ecx, 0x6c
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(108 /*0x6c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052d4c9  7cae                   -jl 0x52d479
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0052d479;
    }
    // 0052d4cb  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0052d4ce  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052d4cf  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052d4d0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052d4d1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052d4d2:
    // 0052d4d2  83fb01                 +cmp ebx, 1
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052d4d5  7f1a                   -jg 0x52d4f1
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0052d4f1;
    }
    // 0052d4d7  bb07000000             -mov ebx, 7
    cpu.ebx = 7 /*0x7*/;
L_0x0052d4dc:
    // 0052d4dc  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0052d4e1  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0052d4e3  e888feffff             -call 0x52d370
    cpu.esp -= 4;
    sub_52d370(app, cpu);
    if (cpu.terminate) return;
    // 0052d4e8  83f801                 +cmp eax, 1
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
    // 0052d4eb  7560                   -jne 0x52d54d
    if (!cpu.flags.zf)
    {
        goto L_0x0052d54d;
    }
    // 0052d4ed  01c3                   +add ebx, eax
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
    // 0052d4ef  ebeb                   -jmp 0x52d4dc
    goto L_0x0052d4dc;
L_0x0052d4f1:
    // 0052d4f1  ba06000000             -mov edx, 6
    cpu.edx = 6 /*0x6*/;
    // 0052d4f6  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0052d4f8  e873feffff             -call 0x52d370
    cpu.esp -= 4;
    sub_52d370(app, cpu);
    if (cpu.terminate) return;
    // 0052d4fd  83c007                 -add eax, 7
    (cpu.eax) += x86::reg32(x86::sreg32(7 /*0x7*/));
    // 0052d500  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0052d504  0fafc7                 -imul eax, edi
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edi)));
    // 0052d507  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0052d509  83f86c                 +cmp eax, 0x6c
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(108 /*0x6c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052d50c  7e12                   -jle 0x52d520
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0052d520;
    }
    // 0052d50e  ba6c000000             -mov edx, 0x6c
    cpu.edx = 108 /*0x6c*/;
    // 0052d513  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0052d515  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0052d517  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0052d51a  f7ff                   -idiv edi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.edi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0052d51c  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
L_0x0052d520:
    // 0052d520  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0052d524  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0052d526  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0052d528  7e9c                   -jle 0x52d4c6
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0052d4c6;
    }
    // 0052d52a  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
L_0x0052d52e:
    // 0052d52e  40                     -inc eax
    (cpu.eax)++;
    // 0052d52f  c7448d0000000000       -mov dword ptr [ebp + ecx*4], 0
    app->getMemory<x86::reg32>(cpu.ebp + cpu.ecx * 4) = 0 /*0x0*/;
    // 0052d537  01f9                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 0052d539  39d0                   +cmp eax, edx
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
    // 0052d53b  7cf1                   -jl 0x52d52e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0052d52e;
    }
    // 0052d53d  83f96c                 +cmp ecx, 0x6c
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(108 /*0x6c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052d540  0f8c33ffffff           -jl 0x52d479
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0052d479;
    }
    // 0052d546  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0052d549  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052d54a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052d54b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052d54c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052d54d:
    // 0052d54d  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0052d552  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0052d554  e817feffff             -call 0x52d370
    cpu.esp -= 4;
    sub_52d370(app, cpu);
    if (cpu.terminate) return;
    // 0052d559  8d148d00000000         -lea edx, [ecx*4]
    cpu.edx = x86::reg32(cpu.ecx * 4);
    // 0052d560  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0052d562  83f801                 +cmp eax, 1
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
    // 0052d565  751c                   -jne 0x52d583
    if (!cpu.flags.zf)
    {
        goto L_0x0052d583;
    }
    // 0052d567  895c240c               -mov dword ptr [esp + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 0052d56b  db44240c               -fild dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */))));
    // 0052d56f  d91a                   -fstp dword ptr [edx]
    app->getMemory<float>(cpu.edx) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0052d571  01f9                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 0052d573  83f96c                 +cmp ecx, 0x6c
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(108 /*0x6c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052d576  0f8cfdfeffff           -jl 0x52d479
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0052d479;
    }
    // 0052d57c  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0052d57f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052d580  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052d581  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052d582  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052d583:
    // 0052d583  f7db                   -neg ebx
    cpu.ebx = ~cpu.ebx + 1;
    // 0052d585  895c240c               -mov dword ptr [esp + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 0052d589  db44240c               -fild dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */))));
    // 0052d58d  d91a                   -fstp dword ptr [edx]
    app->getMemory<float>(cpu.edx) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0052d58f  01f9                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 0052d591  83f96c                 +cmp ecx, 0x6c
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(108 /*0x6c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052d594  0f8cdffeffff           -jl 0x52d479
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0052d479;
    }
    // 0052d59a  83c410                 +add esp, 0x10
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0052d59d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052d59e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052d59f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052d5a0  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0052d5a1:
    // 0052d5a1  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 0052d5a6  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0052d5a8  c7448d00000000c0       -mov dword ptr [ebp + ecx*4], 0xc0000000
    app->getMemory<x86::reg32>(cpu.ebp + cpu.ecx * 4) = 3221225472 /*0xc0000000*/;
    // 0052d5b0  e9aafeffff             -jmp 0x52d45f
    goto L_0x0052d45f;
  case 0x0052d5b5:
    // 0052d5b5  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 0052d5ba  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0052d5bc  c7448d0000000040       -mov dword ptr [ebp + ecx*4], 0x40000000
    app->getMemory<x86::reg32>(cpu.ebp + cpu.ecx * 4) = 1073741824 /*0x40000000*/;
    // 0052d5c4  e996feffff             -jmp 0x52d45f
    goto L_0x0052d45f;
  default:
    return app->dynamic_call(cpu.ip, cpu);
  }
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_52d5cc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052d5cc  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0052d5cd  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0052d5cf  8d90b0010000           -lea edx, [eax + 0x1b0]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(432) /* 0x1b0 */);
    // 0052d5d5  dd05fc205500           -fld qword ptr [0x5520fc]
    cpu.fpu.push(x86::Float(app->getMemory<double>(x86::reg32(5579004) /* 0x5520fc */)));
    // 0052d5db  dd05f4205500           -fld qword ptr [0x5520f4]
    cpu.fpu.push(x86::Float(app->getMemory<double>(x86::reg32(5578996) /* 0x5520f4 */)));
    // 0052d5e1  dd05ec205500           -fld qword ptr [0x5520ec]
    cpu.fpu.push(x86::Float(app->getMemory<double>(x86::reg32(5578988) /* 0x5520ec */)));
L_0x0052d5e7:
    // 0052d5e7  d940fc                 -fld dword ptr [eax - 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(-4) /* -0x4 */)));
    // 0052d5ea  d84004                 -fadd dword ptr [eax + 4]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */));
    // 0052d5ed  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 0052d5ef  d940f4                 -fld dword ptr [eax - 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(-12) /* -0xc */)));
    // 0052d5f2  d8400c                 -fadd dword ptr [eax + 0xc]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(12) /* 0xc */));
    // 0052d5f5  d8cb                   -fmul st(3)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(3));
    // 0052d5f7  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052d5f9  d940ec                 -fld dword ptr [eax - 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(-20) /* -0x14 */)));
    // 0052d5fc  d84014                 -fadd dword ptr [eax + 0x14]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(20) /* 0x14 */));
    // 0052d5ff  d8cc                   -fmul st(4)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(4));
    // 0052d601  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052d603  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0052d606  d958f8                 -fstp dword ptr [eax - 8]
    app->getMemory<float>(cpu.eax + x86::reg32(-8) /* -0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0052d609  39d0                   +cmp eax, edx
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
    // 0052d60b  75da                   -jne 0x52d5e7
    if (!cpu.flags.zf)
    {
        goto L_0x0052d5e7;
    }
    // 0052d60d  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0052d60f  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0052d611  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0052d613  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052d614  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_52d618(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052d618  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0052d619  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052d61a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052d61b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0052d61c  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052d61d  83ec6c                 -sub esp, 0x6c
    (cpu.esp) -= x86::reg32(x86::sreg32(108 /*0x6c*/));
    // 0052d620  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0052d622  89542464               -mov dword ptr [esp + 0x64], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */) = cpu.edx;
    // 0052d626  b80a000000             -mov eax, 0xa
    cpu.eax = 10 /*0xa*/;
    // 0052d62b  8d5528                 -lea edx, [ebp + 0x28]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(40) /* 0x28 */);
L_0x0052d62e:
    // 0052d62e  48                     -dec eax
    (cpu.eax)--;
    // 0052d62f  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 0052d631  83ea04                 -sub edx, 4
    (cpu.edx) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052d634  d95c8438               -fstp dword ptr [esp + eax*4 + 0x38]
    app->getMemory<float>(cpu.esp + x86::reg32(56) /* 0x38 */ + cpu.eax * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0052d638  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052d63a  7df2                   -jge 0x52d62e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0052d62e;
    }
    // 0052d63c  ba0000803f             -mov edx, 0x3f800000
    cpu.edx = 1065353216 /*0x3f800000*/;
    // 0052d641  8b7c2464               -mov edi, dword ptr [esp + 0x64]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */);
    // 0052d645  8d4528                 -lea eax, [ebp + 0x28]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(40) /* 0x28 */);
    // 0052d648  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0052d64a  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0052d64c  89542430               -mov dword ptr [esp + 0x30], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.edx;
    // 0052d650  89442460               -mov dword ptr [esp + 0x60], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */) = cpu.eax;
L_0x0052d654:
    // 0052d654  d9452c                 -fld dword ptr [ebp + 0x2c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(44) /* 0x2c */)));
    // 0052d657  d9e0                   -fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
    // 0052d659  d84c245c               -fmul dword ptr [esp + 0x5c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(92) /* 0x5c */));
    // 0052d65d  b80a000000             -mov eax, 0xa
    cpu.eax = 10 /*0xa*/;
    // 0052d662  8b542460               -mov edx, dword ptr [esp + 0x60]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 0052d666  d9542468               -fst dword ptr [esp + 0x68]
    app->getMemory<float>(cpu.esp + x86::reg32(104) /* 0x68 */) = float(cpu.fpu.st(0));
L_0x0052d66a:
    // 0052d66a  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 0052d66c  d84c8430               -fmul dword ptr [esp + eax*4 + 0x30]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(48) /* 0x30 */ + cpu.eax * 4));
    // 0052d670  dee9                   -fsubp st(1)
    cpu.fpu.st(1) -= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052d672  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 0052d674  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 0052d676  48                     -dec eax
    (cpu.eax)--;
    // 0052d677  d8448434               -fadd dword ptr [esp + eax*4 + 0x34]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(52) /* 0x34 */ + cpu.eax * 4));
    // 0052d67b  83ea04                 -sub edx, 4
    (cpu.edx) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052d67e  d95c8438               -fstp dword ptr [esp + eax*4 + 0x38]
    app->getMemory<float>(cpu.esp + x86::reg32(56) /* 0x38 */ + cpu.eax * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0052d682  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052d684  7de4                   -jge 0x52d66a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0052d66a;
    }
    // 0052d686  d95c2468               -fstp dword ptr [esp + 0x68]
    app->getMemory<float>(cpu.esp + x86::reg32(104) /* 0x68 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0052d68a  8b442468               -mov eax, dword ptr [esp + 0x68]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 0052d68e  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0052d690  89442430               -mov dword ptr [esp + 0x30], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.eax;
    // 0052d694  890434                 -mov dword ptr [esp + esi], eax
    app->getMemory<x86::reg32>(cpu.esp + cpu.esi * 1) = cpu.eax;
    // 0052d697  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0052d699  7e21                   -jle 0x52d6bc
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0052d6bc;
    }
    // 0052d69b  d9442468               -fld dword ptr [esp + 0x68]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(104) /* 0x68 */)));
    // 0052d69f  8b542464               -mov edx, dword ptr [esp + 0x64]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */);
    // 0052d6a3  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x0052d6a5:
    // 0052d6a5  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 0052d6a7  d84c04fc               -fmul dword ptr [esp + eax - 4]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(-4) /* -0x4 */ + cpu.eax * 1));
    // 0052d6ab  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052d6ae  83e804                 -sub eax, 4
    (cpu.eax) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052d6b1  41                     -inc ecx
    (cpu.ecx)++;
    // 0052d6b2  dee9                   -fsubp st(1)
    cpu.fpu.st(1) -= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052d6b4  39d9                   +cmp ecx, ebx
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
    // 0052d6b6  7ced                   -jl 0x52d6a5
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0052d6a5;
    }
    // 0052d6b8  d95c2468               -fstp dword ptr [esp + 0x68]
    app->getMemory<float>(cpu.esp + x86::reg32(104) /* 0x68 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x0052d6bc:
    // 0052d6bc  8b442468               -mov eax, dword ptr [esp + 0x68]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 0052d6c0  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052d6c3  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052d6c6  43                     -inc ebx
    (cpu.ebx)++;
    // 0052d6c7  8947fc                 -mov dword ptr [edi - 4], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0052d6ca  83fb0c                 +cmp ebx, 0xc
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
    // 0052d6cd  7c85                   -jl 0x52d654
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0052d654;
    }
    // 0052d6cf  83c46c                 -add esp, 0x6c
    (cpu.esp) += x86::reg32(x86::sreg32(108 /*0x6c*/));
    // 0052d6d2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052d6d3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052d6d4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052d6d5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052d6d6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052d6d7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_52d6d8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052d6d8  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052d6d9  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0052d6da  83ec34                 -sub esp, 0x34
    (cpu.esp) -= x86::reg32(x86::sreg32(52 /*0x34*/));
    // 0052d6dd  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0052d6df  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0052d6e1  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0052d6e3  0f859e070000           -jne 0x52de87
    if (!cpu.flags.zf)
    {
        goto L_0x0052de87;
    }
    // 0052d6e9  894c2430               -mov dword ptr [esp + 0x30], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.ecx;
L_0x0052d6ed:
    // 0052d6ed  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0052d6ef  8d8614010000           -lea eax, [esi + 0x114]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(276) /* 0x114 */);
    // 0052d6f5  e81effffff             -call 0x52d618
    cpu.esp -= 4;
    sub_52d618(app, cpu);
    if (cpu.terminate) return;
    // 0052d6fa  8d04bd00000000         -lea eax, [edi*4]
    cpu.eax = x86::reg32(cpu.edi * 4);
    // 0052d701  8d9684060000           -lea edx, [esi + 0x684]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(1668) /* 0x684 */);
    // 0052d707  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0052d709  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0052d70b  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0052d70d  0f8e6e070000           -jle 0x52de81
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0052de81;
    }
L_0x0052d713:
    // 0052d713  d90424                 -fld dword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp)));
    // 0052d716  d88e44010000           -fmul dword ptr [esi + 0x144]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(324) /* 0x144 */));
    // 0052d71c  d800                   -fadd dword ptr [eax]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.eax));
    // 0052d71e  d9442404               -fld dword ptr [esp + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 0052d722  d88e48010000           -fmul dword ptr [esi + 0x148]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(328) /* 0x148 */));
    // 0052d728  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052d72a  d9442408               -fld dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 0052d72e  d88e4c010000           -fmul dword ptr [esi + 0x14c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(332) /* 0x14c */));
    // 0052d734  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052d736  d944240c               -fld dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 0052d73a  d88e50010000           -fmul dword ptr [esi + 0x150]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(336) /* 0x150 */));
    // 0052d740  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052d742  d9442410               -fld dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 0052d746  d88e54010000           -fmul dword ptr [esi + 0x154]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(340) /* 0x154 */));
    // 0052d74c  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052d74e  d9442414               -fld dword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 0052d752  d88e58010000           -fmul dword ptr [esi + 0x158]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(344) /* 0x158 */));
    // 0052d758  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052d75a  d9442418               -fld dword ptr [esp + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(24) /* 0x18 */)));
    // 0052d75e  d88e5c010000           -fmul dword ptr [esi + 0x15c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(348) /* 0x15c */));
    // 0052d764  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052d766  d944241c               -fld dword ptr [esp + 0x1c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(28) /* 0x1c */)));
    // 0052d76a  d88e60010000           -fmul dword ptr [esi + 0x160]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(352) /* 0x160 */));
    // 0052d770  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052d772  d9442420               -fld dword ptr [esp + 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 0052d776  d88e64010000           -fmul dword ptr [esi + 0x164]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(356) /* 0x164 */));
    // 0052d77c  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052d77e  d9442424               -fld dword ptr [esp + 0x24]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(36) /* 0x24 */)));
    // 0052d782  d88e68010000           -fmul dword ptr [esi + 0x168]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(360) /* 0x168 */));
    // 0052d788  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052d78a  d9442428               -fld dword ptr [esp + 0x28]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(40) /* 0x28 */)));
    // 0052d78e  d88e6c010000           -fmul dword ptr [esi + 0x16c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(364) /* 0x16c */));
    // 0052d794  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052d796  d944242c               -fld dword ptr [esp + 0x2c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(44) /* 0x2c */)));
    // 0052d79a  d88e70010000           -fmul dword ptr [esi + 0x170]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(368) /* 0x170 */));
    // 0052d7a0  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052d7a2  d99670010000           -fst dword ptr [esi + 0x170]
    app->getMemory<float>(cpu.esi + x86::reg32(368) /* 0x170 */) = float(cpu.fpu.st(0));
    // 0052d7a8  d9442430               -fld dword ptr [esp + 0x30]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(48) /* 0x30 */)));
    // 0052d7ac  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0052d7ae  d8c1                   -fadd st(1)
    cpu.fpu.st(0) += x86::Float(cpu.fpu.st(1));
    // 0052d7b0  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0052d7b2  d90424                 -fld dword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp)));
    // 0052d7b5  d88e70010000           -fmul dword ptr [esi + 0x170]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(368) /* 0x170 */));
    // 0052d7bb  d84004                 -fadd dword ptr [eax + 4]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */));
    // 0052d7be  d9442404               -fld dword ptr [esp + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 0052d7c2  d88e44010000           -fmul dword ptr [esi + 0x144]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(324) /* 0x144 */));
    // 0052d7c8  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052d7ca  d9442408               -fld dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 0052d7ce  d88e48010000           -fmul dword ptr [esi + 0x148]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(328) /* 0x148 */));
    // 0052d7d4  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052d7d6  d944240c               -fld dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 0052d7da  d88e4c010000           -fmul dword ptr [esi + 0x14c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(332) /* 0x14c */));
    // 0052d7e0  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052d7e2  d9442410               -fld dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 0052d7e6  d88e50010000           -fmul dword ptr [esi + 0x150]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(336) /* 0x150 */));
    // 0052d7ec  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052d7ee  d9442414               -fld dword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 0052d7f2  d88e54010000           -fmul dword ptr [esi + 0x154]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(340) /* 0x154 */));
    // 0052d7f8  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052d7fa  d9442418               -fld dword ptr [esp + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(24) /* 0x18 */)));
    // 0052d7fe  d88e58010000           -fmul dword ptr [esi + 0x158]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(344) /* 0x158 */));
    // 0052d804  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052d806  d944241c               -fld dword ptr [esp + 0x1c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(28) /* 0x1c */)));
    // 0052d80a  d88e5c010000           -fmul dword ptr [esi + 0x15c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(348) /* 0x15c */));
    // 0052d810  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052d812  d9442420               -fld dword ptr [esp + 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 0052d816  d88e60010000           -fmul dword ptr [esi + 0x160]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(352) /* 0x160 */));
    // 0052d81c  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052d81e  d9442424               -fld dword ptr [esp + 0x24]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(36) /* 0x24 */)));
    // 0052d822  d88e64010000           -fmul dword ptr [esi + 0x164]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(356) /* 0x164 */));
    // 0052d828  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052d82a  d9442428               -fld dword ptr [esp + 0x28]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(40) /* 0x28 */)));
    // 0052d82e  d88e68010000           -fmul dword ptr [esi + 0x168]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(360) /* 0x168 */));
    // 0052d834  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052d836  d944242c               -fld dword ptr [esp + 0x2c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(44) /* 0x2c */)));
    // 0052d83a  d88e6c010000           -fmul dword ptr [esi + 0x16c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(364) /* 0x16c */));
    // 0052d840  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052d842  d9966c010000           -fst dword ptr [esi + 0x16c]
    app->getMemory<float>(cpu.esi + x86::reg32(364) /* 0x16c */) = float(cpu.fpu.st(0));
    // 0052d848  d8c1                   -fadd st(1)
    cpu.fpu.st(0) += x86::Float(cpu.fpu.st(1));
    // 0052d84a  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0052d84d  d90424                 -fld dword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp)));
    // 0052d850  d88e6c010000           -fmul dword ptr [esi + 0x16c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(364) /* 0x16c */));
    // 0052d856  d84008                 -fadd dword ptr [eax + 8]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(8) /* 0x8 */));
    // 0052d859  d9442404               -fld dword ptr [esp + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 0052d85d  d88e70010000           -fmul dword ptr [esi + 0x170]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(368) /* 0x170 */));
    // 0052d863  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052d865  d9442408               -fld dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 0052d869  d88e44010000           -fmul dword ptr [esi + 0x144]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(324) /* 0x144 */));
    // 0052d86f  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052d871  d944240c               -fld dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 0052d875  d88e48010000           -fmul dword ptr [esi + 0x148]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(328) /* 0x148 */));
    // 0052d87b  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052d87d  d9442410               -fld dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 0052d881  d88e4c010000           -fmul dword ptr [esi + 0x14c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(332) /* 0x14c */));
    // 0052d887  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052d889  d9442414               -fld dword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 0052d88d  d88e50010000           -fmul dword ptr [esi + 0x150]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(336) /* 0x150 */));
    // 0052d893  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052d895  d9442418               -fld dword ptr [esp + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(24) /* 0x18 */)));
    // 0052d899  d88e54010000           -fmul dword ptr [esi + 0x154]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(340) /* 0x154 */));
    // 0052d89f  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052d8a1  d944241c               -fld dword ptr [esp + 0x1c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(28) /* 0x1c */)));
    // 0052d8a5  d88e58010000           -fmul dword ptr [esi + 0x158]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(344) /* 0x158 */));
    // 0052d8ab  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052d8ad  d9442420               -fld dword ptr [esp + 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 0052d8b1  d88e5c010000           -fmul dword ptr [esi + 0x15c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(348) /* 0x15c */));
    // 0052d8b7  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052d8b9  d9442424               -fld dword ptr [esp + 0x24]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(36) /* 0x24 */)));
    // 0052d8bd  d88e60010000           -fmul dword ptr [esi + 0x160]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(352) /* 0x160 */));
    // 0052d8c3  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052d8c5  d9442428               -fld dword ptr [esp + 0x28]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(40) /* 0x28 */)));
    // 0052d8c9  d88e64010000           -fmul dword ptr [esi + 0x164]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(356) /* 0x164 */));
    // 0052d8cf  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052d8d1  d944242c               -fld dword ptr [esp + 0x2c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(44) /* 0x2c */)));
    // 0052d8d5  d88e68010000           -fmul dword ptr [esi + 0x168]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(360) /* 0x168 */));
    // 0052d8db  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052d8dd  d99668010000           -fst dword ptr [esi + 0x168]
    app->getMemory<float>(cpu.esi + x86::reg32(360) /* 0x168 */) = float(cpu.fpu.st(0));
    // 0052d8e3  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052d8e5  d95808                 -fstp dword ptr [eax + 8]
    app->getMemory<float>(cpu.eax + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0052d8e8  d90424                 -fld dword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp)));
    // 0052d8eb  d88e68010000           -fmul dword ptr [esi + 0x168]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(360) /* 0x168 */));
    // 0052d8f1  d8400c                 -fadd dword ptr [eax + 0xc]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(12) /* 0xc */));
    // 0052d8f4  d9442404               -fld dword ptr [esp + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 0052d8f8  d88e6c010000           -fmul dword ptr [esi + 0x16c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(364) /* 0x16c */));
    // 0052d8fe  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052d900  d9442408               -fld dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 0052d904  d88e70010000           -fmul dword ptr [esi + 0x170]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(368) /* 0x170 */));
    // 0052d90a  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052d90c  d944240c               -fld dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 0052d910  d88e44010000           -fmul dword ptr [esi + 0x144]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(324) /* 0x144 */));
    // 0052d916  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052d918  d9442410               -fld dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 0052d91c  d88e48010000           -fmul dword ptr [esi + 0x148]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(328) /* 0x148 */));
    // 0052d922  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052d924  d9442414               -fld dword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 0052d928  d88e4c010000           -fmul dword ptr [esi + 0x14c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(332) /* 0x14c */));
    // 0052d92e  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052d930  d9442418               -fld dword ptr [esp + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(24) /* 0x18 */)));
    // 0052d934  d88e50010000           -fmul dword ptr [esi + 0x150]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(336) /* 0x150 */));
    // 0052d93a  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052d93c  d944241c               -fld dword ptr [esp + 0x1c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(28) /* 0x1c */)));
    // 0052d940  d88e54010000           -fmul dword ptr [esi + 0x154]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(340) /* 0x154 */));
    // 0052d946  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052d948  d9442420               -fld dword ptr [esp + 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 0052d94c  d88e58010000           -fmul dword ptr [esi + 0x158]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(344) /* 0x158 */));
    // 0052d952  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052d954  d9442424               -fld dword ptr [esp + 0x24]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(36) /* 0x24 */)));
    // 0052d958  d88e5c010000           -fmul dword ptr [esi + 0x15c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(348) /* 0x15c */));
    // 0052d95e  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052d960  d9442428               -fld dword ptr [esp + 0x28]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(40) /* 0x28 */)));
    // 0052d964  d88e60010000           -fmul dword ptr [esi + 0x160]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(352) /* 0x160 */));
    // 0052d96a  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052d96c  d944242c               -fld dword ptr [esp + 0x2c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(44) /* 0x2c */)));
    // 0052d970  d88e64010000           -fmul dword ptr [esi + 0x164]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(356) /* 0x164 */));
    // 0052d976  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052d978  d99e64010000           -fstp dword ptr [esi + 0x164]
    app->getMemory<float>(cpu.esi + x86::reg32(356) /* 0x164 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0052d97e  d9442430               -fld dword ptr [esp + 0x30]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(48) /* 0x30 */)));
    // 0052d982  d98664010000           -fld dword ptr [esi + 0x164]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(356) /* 0x164 */)));
    // 0052d988  d8c1                   -fadd st(1)
    cpu.fpu.st(0) += x86::Float(cpu.fpu.st(1));
    // 0052d98a  d9580c                 -fstp dword ptr [eax + 0xc]
    app->getMemory<float>(cpu.eax + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0052d98d  d90424                 -fld dword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp)));
    // 0052d990  d88e64010000           -fmul dword ptr [esi + 0x164]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(356) /* 0x164 */));
    // 0052d996  d84010                 -fadd dword ptr [eax + 0x10]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(16) /* 0x10 */));
    // 0052d999  d9442404               -fld dword ptr [esp + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 0052d99d  d88e68010000           -fmul dword ptr [esi + 0x168]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(360) /* 0x168 */));
    // 0052d9a3  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052d9a5  d9442408               -fld dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 0052d9a9  d88e6c010000           -fmul dword ptr [esi + 0x16c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(364) /* 0x16c */));
    // 0052d9af  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052d9b1  d944240c               -fld dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 0052d9b5  d88e70010000           -fmul dword ptr [esi + 0x170]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(368) /* 0x170 */));
    // 0052d9bb  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052d9bd  d9442410               -fld dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 0052d9c1  d88e44010000           -fmul dword ptr [esi + 0x144]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(324) /* 0x144 */));
    // 0052d9c7  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052d9c9  d9442414               -fld dword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 0052d9cd  d88e48010000           -fmul dword ptr [esi + 0x148]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(328) /* 0x148 */));
    // 0052d9d3  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052d9d5  d9442418               -fld dword ptr [esp + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(24) /* 0x18 */)));
    // 0052d9d9  d88e4c010000           -fmul dword ptr [esi + 0x14c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(332) /* 0x14c */));
    // 0052d9df  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052d9e1  d944241c               -fld dword ptr [esp + 0x1c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(28) /* 0x1c */)));
    // 0052d9e5  d88e50010000           -fmul dword ptr [esi + 0x150]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(336) /* 0x150 */));
    // 0052d9eb  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052d9ed  d9442420               -fld dword ptr [esp + 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 0052d9f1  d88e54010000           -fmul dword ptr [esi + 0x154]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(340) /* 0x154 */));
    // 0052d9f7  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052d9f9  d9442424               -fld dword ptr [esp + 0x24]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(36) /* 0x24 */)));
    // 0052d9fd  d88e58010000           -fmul dword ptr [esi + 0x158]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(344) /* 0x158 */));
    // 0052da03  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052da05  d9442428               -fld dword ptr [esp + 0x28]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(40) /* 0x28 */)));
    // 0052da09  d88e5c010000           -fmul dword ptr [esi + 0x15c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(348) /* 0x15c */));
    // 0052da0f  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052da11  d944242c               -fld dword ptr [esp + 0x2c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(44) /* 0x2c */)));
    // 0052da15  d88e60010000           -fmul dword ptr [esi + 0x160]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(352) /* 0x160 */));
    // 0052da1b  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052da1d  d99660010000           -fst dword ptr [esi + 0x160]
    app->getMemory<float>(cpu.esi + x86::reg32(352) /* 0x160 */) = float(cpu.fpu.st(0));
    // 0052da23  d8c1                   -fadd st(1)
    cpu.fpu.st(0) += x86::Float(cpu.fpu.st(1));
    // 0052da25  d95810                 -fstp dword ptr [eax + 0x10]
    app->getMemory<float>(cpu.eax + x86::reg32(16) /* 0x10 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0052da28  d90424                 -fld dword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp)));
    // 0052da2b  d88e60010000           -fmul dword ptr [esi + 0x160]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(352) /* 0x160 */));
    // 0052da31  d84014                 -fadd dword ptr [eax + 0x14]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(20) /* 0x14 */));
    // 0052da34  d9442404               -fld dword ptr [esp + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 0052da38  d88e64010000           -fmul dword ptr [esi + 0x164]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(356) /* 0x164 */));
    // 0052da3e  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052da40  d9442408               -fld dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 0052da44  d88e68010000           -fmul dword ptr [esi + 0x168]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(360) /* 0x168 */));
    // 0052da4a  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052da4c  d944240c               -fld dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 0052da50  d88e6c010000           -fmul dword ptr [esi + 0x16c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(364) /* 0x16c */));
    // 0052da56  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052da58  d9442410               -fld dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 0052da5c  d88e70010000           -fmul dword ptr [esi + 0x170]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(368) /* 0x170 */));
    // 0052da62  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052da64  d9442414               -fld dword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 0052da68  d88e44010000           -fmul dword ptr [esi + 0x144]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(324) /* 0x144 */));
    // 0052da6e  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052da70  d9442418               -fld dword ptr [esp + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(24) /* 0x18 */)));
    // 0052da74  d88e48010000           -fmul dword ptr [esi + 0x148]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(328) /* 0x148 */));
    // 0052da7a  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052da7c  d944241c               -fld dword ptr [esp + 0x1c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(28) /* 0x1c */)));
    // 0052da80  d88e4c010000           -fmul dword ptr [esi + 0x14c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(332) /* 0x14c */));
    // 0052da86  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052da88  d9442420               -fld dword ptr [esp + 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 0052da8c  d88e50010000           -fmul dword ptr [esi + 0x150]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(336) /* 0x150 */));
    // 0052da92  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052da94  d9442424               -fld dword ptr [esp + 0x24]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(36) /* 0x24 */)));
    // 0052da98  d88e54010000           -fmul dword ptr [esi + 0x154]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(340) /* 0x154 */));
    // 0052da9e  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052daa0  d9442428               -fld dword ptr [esp + 0x28]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(40) /* 0x28 */)));
    // 0052daa4  d88e58010000           -fmul dword ptr [esi + 0x158]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(344) /* 0x158 */));
    // 0052daaa  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052daac  d944242c               -fld dword ptr [esp + 0x2c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(44) /* 0x2c */)));
    // 0052dab0  d88e5c010000           -fmul dword ptr [esi + 0x15c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(348) /* 0x15c */));
    // 0052dab6  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052dab8  d9965c010000           -fst dword ptr [esi + 0x15c]
    app->getMemory<float>(cpu.esi + x86::reg32(348) /* 0x15c */) = float(cpu.fpu.st(0));
    // 0052dabe  d8c1                   -fadd st(1)
    cpu.fpu.st(0) += x86::Float(cpu.fpu.st(1));
    // 0052dac0  d95814                 -fstp dword ptr [eax + 0x14]
    app->getMemory<float>(cpu.eax + x86::reg32(20) /* 0x14 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0052dac3  d90424                 -fld dword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp)));
    // 0052dac6  d88e5c010000           -fmul dword ptr [esi + 0x15c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(348) /* 0x15c */));
    // 0052dacc  d84018                 -fadd dword ptr [eax + 0x18]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */));
    // 0052dacf  d9442404               -fld dword ptr [esp + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 0052dad3  d88e60010000           -fmul dword ptr [esi + 0x160]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(352) /* 0x160 */));
    // 0052dad9  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052dadb  d9442408               -fld dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 0052dadf  d88e64010000           -fmul dword ptr [esi + 0x164]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(356) /* 0x164 */));
    // 0052dae5  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052dae7  d944240c               -fld dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 0052daeb  d88e68010000           -fmul dword ptr [esi + 0x168]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(360) /* 0x168 */));
    // 0052daf1  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052daf3  d9442410               -fld dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 0052daf7  d88e6c010000           -fmul dword ptr [esi + 0x16c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(364) /* 0x16c */));
    // 0052dafd  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052daff  d9442414               -fld dword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 0052db03  d88e70010000           -fmul dword ptr [esi + 0x170]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(368) /* 0x170 */));
    // 0052db09  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052db0b  d9442418               -fld dword ptr [esp + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(24) /* 0x18 */)));
    // 0052db0f  d88e44010000           -fmul dword ptr [esi + 0x144]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(324) /* 0x144 */));
    // 0052db15  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052db17  d944241c               -fld dword ptr [esp + 0x1c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(28) /* 0x1c */)));
    // 0052db1b  d88e48010000           -fmul dword ptr [esi + 0x148]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(328) /* 0x148 */));
    // 0052db21  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052db23  d9442420               -fld dword ptr [esp + 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 0052db27  d88e4c010000           -fmul dword ptr [esi + 0x14c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(332) /* 0x14c */));
    // 0052db2d  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052db2f  d9442424               -fld dword ptr [esp + 0x24]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(36) /* 0x24 */)));
    // 0052db33  d88e50010000           -fmul dword ptr [esi + 0x150]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(336) /* 0x150 */));
    // 0052db39  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052db3b  d9442428               -fld dword ptr [esp + 0x28]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(40) /* 0x28 */)));
    // 0052db3f  d88e54010000           -fmul dword ptr [esi + 0x154]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(340) /* 0x154 */));
    // 0052db45  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052db47  d944242c               -fld dword ptr [esp + 0x2c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(44) /* 0x2c */)));
    // 0052db4b  d88e58010000           -fmul dword ptr [esi + 0x158]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(344) /* 0x158 */));
    // 0052db51  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052db53  d99658010000           -fst dword ptr [esi + 0x158]
    app->getMemory<float>(cpu.esi + x86::reg32(344) /* 0x158 */) = float(cpu.fpu.st(0));
    // 0052db59  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052db5b  d95818                 -fstp dword ptr [eax + 0x18]
    app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0052db5e  d90424                 -fld dword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp)));
    // 0052db61  d88e58010000           -fmul dword ptr [esi + 0x158]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(344) /* 0x158 */));
    // 0052db67  d8401c                 -fadd dword ptr [eax + 0x1c]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(28) /* 0x1c */));
    // 0052db6a  d9442404               -fld dword ptr [esp + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 0052db6e  d88e5c010000           -fmul dword ptr [esi + 0x15c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(348) /* 0x15c */));
    // 0052db74  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052db76  d9442408               -fld dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 0052db7a  d88e60010000           -fmul dword ptr [esi + 0x160]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(352) /* 0x160 */));
    // 0052db80  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052db82  d944240c               -fld dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 0052db86  d88e64010000           -fmul dword ptr [esi + 0x164]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(356) /* 0x164 */));
    // 0052db8c  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052db8e  d9442410               -fld dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 0052db92  d88e68010000           -fmul dword ptr [esi + 0x168]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(360) /* 0x168 */));
    // 0052db98  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052db9a  d9442414               -fld dword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 0052db9e  d88e6c010000           -fmul dword ptr [esi + 0x16c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(364) /* 0x16c */));
    // 0052dba4  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052dba6  d9442418               -fld dword ptr [esp + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(24) /* 0x18 */)));
    // 0052dbaa  d88e70010000           -fmul dword ptr [esi + 0x170]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(368) /* 0x170 */));
    // 0052dbb0  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052dbb2  d944241c               -fld dword ptr [esp + 0x1c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(28) /* 0x1c */)));
    // 0052dbb6  d88e44010000           -fmul dword ptr [esi + 0x144]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(324) /* 0x144 */));
    // 0052dbbc  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052dbbe  d9442420               -fld dword ptr [esp + 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 0052dbc2  d88e48010000           -fmul dword ptr [esi + 0x148]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(328) /* 0x148 */));
    // 0052dbc8  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052dbca  d9442424               -fld dword ptr [esp + 0x24]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(36) /* 0x24 */)));
    // 0052dbce  d88e4c010000           -fmul dword ptr [esi + 0x14c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(332) /* 0x14c */));
    // 0052dbd4  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052dbd6  d9442428               -fld dword ptr [esp + 0x28]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(40) /* 0x28 */)));
    // 0052dbda  d88e50010000           -fmul dword ptr [esi + 0x150]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(336) /* 0x150 */));
    // 0052dbe0  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052dbe2  d944242c               -fld dword ptr [esp + 0x2c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(44) /* 0x2c */)));
    // 0052dbe6  d88e54010000           -fmul dword ptr [esi + 0x154]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(340) /* 0x154 */));
    // 0052dbec  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052dbee  d99654010000           -fst dword ptr [esi + 0x154]
    app->getMemory<float>(cpu.esi + x86::reg32(340) /* 0x154 */) = float(cpu.fpu.st(0));
    // 0052dbf4  d9442430               -fld dword ptr [esp + 0x30]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(48) /* 0x30 */)));
    // 0052dbf8  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0052dbfa  d8c1                   -fadd st(1)
    cpu.fpu.st(0) += x86::Float(cpu.fpu.st(1));
    // 0052dbfc  d9581c                 -fstp dword ptr [eax + 0x1c]
    app->getMemory<float>(cpu.eax + x86::reg32(28) /* 0x1c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0052dbff  d90424                 -fld dword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp)));
    // 0052dc02  d88e54010000           -fmul dword ptr [esi + 0x154]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(340) /* 0x154 */));
    // 0052dc08  d84020                 -fadd dword ptr [eax + 0x20]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(32) /* 0x20 */));
    // 0052dc0b  d9442404               -fld dword ptr [esp + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 0052dc0f  d88e58010000           -fmul dword ptr [esi + 0x158]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(344) /* 0x158 */));
    // 0052dc15  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052dc17  d9442408               -fld dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 0052dc1b  d88e5c010000           -fmul dword ptr [esi + 0x15c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(348) /* 0x15c */));
    // 0052dc21  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052dc23  d944240c               -fld dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 0052dc27  d88e60010000           -fmul dword ptr [esi + 0x160]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(352) /* 0x160 */));
    // 0052dc2d  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052dc2f  d9442410               -fld dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 0052dc33  d88e64010000           -fmul dword ptr [esi + 0x164]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(356) /* 0x164 */));
    // 0052dc39  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052dc3b  d9442414               -fld dword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 0052dc3f  d88e68010000           -fmul dword ptr [esi + 0x168]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(360) /* 0x168 */));
    // 0052dc45  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052dc47  d9442418               -fld dword ptr [esp + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(24) /* 0x18 */)));
    // 0052dc4b  d88e6c010000           -fmul dword ptr [esi + 0x16c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(364) /* 0x16c */));
    // 0052dc51  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052dc53  d944241c               -fld dword ptr [esp + 0x1c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(28) /* 0x1c */)));
    // 0052dc57  d88e70010000           -fmul dword ptr [esi + 0x170]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(368) /* 0x170 */));
    // 0052dc5d  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052dc5f  d9442420               -fld dword ptr [esp + 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 0052dc63  d88e44010000           -fmul dword ptr [esi + 0x144]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(324) /* 0x144 */));
    // 0052dc69  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052dc6b  d9442424               -fld dword ptr [esp + 0x24]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(36) /* 0x24 */)));
    // 0052dc6f  d88e48010000           -fmul dword ptr [esi + 0x148]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(328) /* 0x148 */));
    // 0052dc75  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052dc77  d9442428               -fld dword ptr [esp + 0x28]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(40) /* 0x28 */)));
    // 0052dc7b  d88e4c010000           -fmul dword ptr [esi + 0x14c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(332) /* 0x14c */));
    // 0052dc81  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052dc83  d944242c               -fld dword ptr [esp + 0x2c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(44) /* 0x2c */)));
    // 0052dc87  d88e50010000           -fmul dword ptr [esi + 0x150]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(336) /* 0x150 */));
    // 0052dc8d  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052dc8f  d99650010000           -fst dword ptr [esi + 0x150]
    app->getMemory<float>(cpu.esi + x86::reg32(336) /* 0x150 */) = float(cpu.fpu.st(0));
    // 0052dc95  d8c1                   -fadd st(1)
    cpu.fpu.st(0) += x86::Float(cpu.fpu.st(1));
    // 0052dc97  d95820                 -fstp dword ptr [eax + 0x20]
    app->getMemory<float>(cpu.eax + x86::reg32(32) /* 0x20 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0052dc9a  d90424                 -fld dword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp)));
    // 0052dc9d  d88e50010000           -fmul dword ptr [esi + 0x150]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(336) /* 0x150 */));
    // 0052dca3  d84024                 -fadd dword ptr [eax + 0x24]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */));
    // 0052dca6  d9442404               -fld dword ptr [esp + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 0052dcaa  d88e54010000           -fmul dword ptr [esi + 0x154]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(340) /* 0x154 */));
    // 0052dcb0  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052dcb2  d9442408               -fld dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 0052dcb6  d88e58010000           -fmul dword ptr [esi + 0x158]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(344) /* 0x158 */));
    // 0052dcbc  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052dcbe  d944240c               -fld dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 0052dcc2  d88e5c010000           -fmul dword ptr [esi + 0x15c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(348) /* 0x15c */));
    // 0052dcc8  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052dcca  d9442410               -fld dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 0052dcce  d88e60010000           -fmul dword ptr [esi + 0x160]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(352) /* 0x160 */));
    // 0052dcd4  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052dcd6  d9442414               -fld dword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 0052dcda  d88e64010000           -fmul dword ptr [esi + 0x164]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(356) /* 0x164 */));
    // 0052dce0  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052dce2  d9442418               -fld dword ptr [esp + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(24) /* 0x18 */)));
    // 0052dce6  d88e68010000           -fmul dword ptr [esi + 0x168]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(360) /* 0x168 */));
    // 0052dcec  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052dcee  d944241c               -fld dword ptr [esp + 0x1c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(28) /* 0x1c */)));
    // 0052dcf2  d88e6c010000           -fmul dword ptr [esi + 0x16c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(364) /* 0x16c */));
    // 0052dcf8  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052dcfa  d9442420               -fld dword ptr [esp + 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 0052dcfe  d88e70010000           -fmul dword ptr [esi + 0x170]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(368) /* 0x170 */));
    // 0052dd04  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052dd06  d9442424               -fld dword ptr [esp + 0x24]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(36) /* 0x24 */)));
    // 0052dd0a  d88e44010000           -fmul dword ptr [esi + 0x144]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(324) /* 0x144 */));
    // 0052dd10  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052dd12  d9442428               -fld dword ptr [esp + 0x28]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(40) /* 0x28 */)));
    // 0052dd16  d88e48010000           -fmul dword ptr [esi + 0x148]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(328) /* 0x148 */));
    // 0052dd1c  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052dd1e  d944242c               -fld dword ptr [esp + 0x2c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(44) /* 0x2c */)));
    // 0052dd22  d88e4c010000           -fmul dword ptr [esi + 0x14c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(332) /* 0x14c */));
    // 0052dd28  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052dd2a  d9964c010000           -fst dword ptr [esi + 0x14c]
    app->getMemory<float>(cpu.esi + x86::reg32(332) /* 0x14c */) = float(cpu.fpu.st(0));
    // 0052dd30  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052dd32  d95824                 -fstp dword ptr [eax + 0x24]
    app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0052dd35  d90424                 -fld dword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp)));
    // 0052dd38  d88e4c010000           -fmul dword ptr [esi + 0x14c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(332) /* 0x14c */));
    // 0052dd3e  d84028                 -fadd dword ptr [eax + 0x28]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */));
    // 0052dd41  d9442404               -fld dword ptr [esp + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 0052dd45  d88e50010000           -fmul dword ptr [esi + 0x150]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(336) /* 0x150 */));
    // 0052dd4b  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052dd4d  d9442408               -fld dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 0052dd51  d88e54010000           -fmul dword ptr [esi + 0x154]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(340) /* 0x154 */));
    // 0052dd57  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052dd59  d944240c               -fld dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 0052dd5d  d88e58010000           -fmul dword ptr [esi + 0x158]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(344) /* 0x158 */));
    // 0052dd63  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052dd65  d9442410               -fld dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 0052dd69  d88e5c010000           -fmul dword ptr [esi + 0x15c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(348) /* 0x15c */));
    // 0052dd6f  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052dd71  d9442414               -fld dword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 0052dd75  d88e60010000           -fmul dword ptr [esi + 0x160]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(352) /* 0x160 */));
    // 0052dd7b  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052dd7d  d9442418               -fld dword ptr [esp + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(24) /* 0x18 */)));
    // 0052dd81  d88e64010000           -fmul dword ptr [esi + 0x164]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(356) /* 0x164 */));
    // 0052dd87  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052dd89  d944241c               -fld dword ptr [esp + 0x1c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(28) /* 0x1c */)));
    // 0052dd8d  d88e68010000           -fmul dword ptr [esi + 0x168]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(360) /* 0x168 */));
    // 0052dd93  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052dd95  d9442420               -fld dword ptr [esp + 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 0052dd99  d88e6c010000           -fmul dword ptr [esi + 0x16c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(364) /* 0x16c */));
    // 0052dd9f  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052dda1  d9442424               -fld dword ptr [esp + 0x24]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(36) /* 0x24 */)));
    // 0052dda5  d88e70010000           -fmul dword ptr [esi + 0x170]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(368) /* 0x170 */));
    // 0052ddab  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052ddad  d9442428               -fld dword ptr [esp + 0x28]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(40) /* 0x28 */)));
    // 0052ddb1  d88e44010000           -fmul dword ptr [esi + 0x144]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(324) /* 0x144 */));
    // 0052ddb7  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052ddb9  d944242c               -fld dword ptr [esp + 0x2c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(44) /* 0x2c */)));
    // 0052ddbd  d88e48010000           -fmul dword ptr [esi + 0x148]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(328) /* 0x148 */));
    // 0052ddc3  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052ddc5  d99e48010000           -fstp dword ptr [esi + 0x148]
    app->getMemory<float>(cpu.esi + x86::reg32(328) /* 0x148 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0052ddcb  d9442430               -fld dword ptr [esp + 0x30]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(48) /* 0x30 */)));
    // 0052ddcf  d98648010000           -fld dword ptr [esi + 0x148]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(328) /* 0x148 */)));
    // 0052ddd5  d8c1                   -fadd st(1)
    cpu.fpu.st(0) += x86::Float(cpu.fpu.st(1));
    // 0052ddd7  d95828                 -fstp dword ptr [eax + 0x28]
    app->getMemory<float>(cpu.eax + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0052ddda  d90424                 -fld dword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp)));
    // 0052dddd  d88e48010000           -fmul dword ptr [esi + 0x148]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(328) /* 0x148 */));
    // 0052dde3  d8402c                 -fadd dword ptr [eax + 0x2c]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(44) /* 0x2c */));
    // 0052dde6  d9442404               -fld dword ptr [esp + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 0052ddea  d88e4c010000           -fmul dword ptr [esi + 0x14c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(332) /* 0x14c */));
    // 0052ddf0  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052ddf2  d9442408               -fld dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 0052ddf6  d88e50010000           -fmul dword ptr [esi + 0x150]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(336) /* 0x150 */));
    // 0052ddfc  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052ddfe  d944240c               -fld dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 0052de02  d88e54010000           -fmul dword ptr [esi + 0x154]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(340) /* 0x154 */));
    // 0052de08  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052de0a  d9442410               -fld dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 0052de0e  d88e58010000           -fmul dword ptr [esi + 0x158]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(344) /* 0x158 */));
    // 0052de14  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052de16  d9442414               -fld dword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 0052de1a  d88e5c010000           -fmul dword ptr [esi + 0x15c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(348) /* 0x15c */));
    // 0052de20  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052de22  d9442418               -fld dword ptr [esp + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(24) /* 0x18 */)));
    // 0052de26  d88e60010000           -fmul dword ptr [esi + 0x160]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(352) /* 0x160 */));
    // 0052de2c  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052de2e  d944241c               -fld dword ptr [esp + 0x1c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(28) /* 0x1c */)));
    // 0052de32  d88e64010000           -fmul dword ptr [esi + 0x164]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(356) /* 0x164 */));
    // 0052de38  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052de3a  d9442420               -fld dword ptr [esp + 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 0052de3e  d88e68010000           -fmul dword ptr [esi + 0x168]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(360) /* 0x168 */));
    // 0052de44  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052de46  d9442424               -fld dword ptr [esp + 0x24]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(36) /* 0x24 */)));
    // 0052de4a  d88e6c010000           -fmul dword ptr [esi + 0x16c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(364) /* 0x16c */));
    // 0052de50  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052de52  d9442428               -fld dword ptr [esp + 0x28]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(40) /* 0x28 */)));
    // 0052de56  d88e70010000           -fmul dword ptr [esi + 0x170]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(368) /* 0x170 */));
    // 0052de5c  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052de5e  d944242c               -fld dword ptr [esp + 0x2c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(44) /* 0x2c */)));
    // 0052de62  d88e44010000           -fmul dword ptr [esi + 0x144]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(324) /* 0x144 */));
    // 0052de68  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052de6a  83c030                 -add eax, 0x30
    (cpu.eax) += x86::reg32(x86::sreg32(48 /*0x30*/));
    // 0052de6d  d99644010000           -fst dword ptr [esi + 0x144]
    app->getMemory<float>(cpu.esi + x86::reg32(324) /* 0x144 */) = float(cpu.fpu.st(0));
    // 0052de73  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052de75  42                     -inc edx
    (cpu.edx)++;
    // 0052de76  d958fc                 -fstp dword ptr [eax - 4]
    app->getMemory<float>(cpu.eax + x86::reg32(-4) /* -0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0052de79  39da                   +cmp edx, ebx
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
    // 0052de7b  0f8c92f8ffff           -jl 0x52d713
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0052d713;
    }
L_0x0052de81:
    // 0052de81  83c434                 +add esp, 0x34
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(52 /*0x34*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0052de84  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052de85  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052de86  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052de87:
    // 0052de87  c74424300000404b       -mov dword ptr [esp + 0x30], 0x4b400000
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = 1262485504 /*0x4b400000*/;
    // 0052de8f  e959f8ffff             -jmp 0x52d6ed
    goto L_0x0052d6ed;
}

/* align: skip  */
void Application::sub_52de94(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052de94  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0052de95  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052de96  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0052de99  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0052de9b  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0052de9d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052de9e  ff15246b9f00           -call dword ptr [0x9f6b24]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10447652) /* 0x9f6b24 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0052dea4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0052dea6  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0052deab  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0052dead  c7430808000000         -mov dword ptr [ebx + 8], 8
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = 8 /*0x8*/;
    // 0052deb4  46                     -inc esi
    (cpu.esi)++;
    // 0052deb5  894304                 -mov dword ptr [ebx + 4], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0052deb8  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0052deba  8933                   -mov dword ptr [ebx], esi
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.esi;
    // 0052debc  e8aff4ffff             -call 0x52d370
    cpu.esp -= 4;
    sub_52d370(app, cpu);
    if (cpu.terminate) return;
    // 0052dec1  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 0052dec6  89430c                 -mov dword ptr [ebx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0052dec9  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0052decb  e8a0f4ffff             -call 0x52d370
    cpu.esp -= 4;
    sub_52d370(app, cpu);
    if (cpu.terminate) return;
    // 0052ded0  ba20000000             -mov edx, 0x20
    cpu.edx = 32 /*0x20*/;
    // 0052ded5  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0052ded7  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0052ded9  895310                 -mov dword ptr [ebx + 0x10], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 0052dedc  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 0052dee1  e88af4ffff             -call 0x52d370
    cpu.esp -= 4;
    sub_52d370(app, cpu);
    if (cpu.terminate) return;
    // 0052dee6  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0052dee8  40                     -inc eax
    (cpu.eax)++;
    // 0052dee9  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0052deed  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0052def1  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0052def3  df6c2404               -fild qword ptr [esp + 4]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.esp + x86::reg32(4) /* 0x4 */))));
    // 0052def7  dc0d04215500           -fmul qword ptr [0x552104]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5579012) /* 0x552104 */));
    // 0052defd  894c2408               -mov dword ptr [esp + 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 0052df01  ba06000000             -mov edx, 6
    cpu.edx = 6 /*0x6*/;
    // 0052df06  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0052df08  d95b14                 -fstp dword ptr [ebx + 0x14]
    app->getMemory<float>(cpu.ebx + x86::reg32(20) /* 0x14 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0052df0b  e860f4ffff             -call 0x52d370
    cpu.esp -= 4;
    sub_52d370(app, cpu);
    if (cpu.terminate) return;
    // 0052df10  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0052df14  df6c2404               -fild qword ptr [esp + 4]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.esp + x86::reg32(4) /* 0x4 */))));
    // 0052df18  dc0d0c215500           -fmul qword ptr [0x55210c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5579020) /* 0x55210c */));
    // 0052df1e  8d4304                 -lea eax, [ebx + 4]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0052df21  dc0514215500           -fadd qword ptr [0x552114]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(x86::reg32(5579028) /* 0x552114 */));
    // 0052df27  8d9300010000           -lea edx, [ebx + 0x100]
    cpu.edx = x86::reg32(cpu.ebx + x86::reg32(256) /* 0x100 */);
    // 0052df2d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0052df2e:
    // 0052df2e  d94010                 -fld dword ptr [eax + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(16) /* 0x10 */)));
    // 0052df31  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 0052df33  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052df36  d95810                 -fstp dword ptr [eax + 0x10]
    app->getMemory<float>(cpu.eax + x86::reg32(16) /* 0x10 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0052df39  39d0                   +cmp eax, edx
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
    // 0052df3b  75f1                   -jne 0x52df2e
    if (!cpu.flags.zf)
    {
        goto L_0x0052df2e;
    }
    // 0052df3d  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0052df3f  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0052df41  8d5330                 -lea edx, [ebx + 0x30]
    cpu.edx = x86::reg32(cpu.ebx + x86::reg32(48) /* 0x30 */);
L_0x0052df44:
    // 0052df44  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052df47  c7801001000000000000   -mov dword ptr [eax + 0x110], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(272) /* 0x110 */) = 0 /*0x0*/;
    // 0052df51  c7804001000000000000   -mov dword ptr [eax + 0x140], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(320) /* 0x140 */) = 0 /*0x0*/;
    // 0052df5b  39d0                   +cmp eax, edx
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
    // 0052df5d  75e5                   -jne 0x52df44
    if (!cpu.flags.zf)
    {
        goto L_0x0052df44;
    }
    // 0052df5f  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0052df61  81c310050000           -add ebx, 0x510
    (cpu.ebx) += x86::reg32(x86::sreg32(1296 /*0x510*/));
L_0x0052df67:
    // 0052df67  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052df6a  c7807001000000000000   -mov dword ptr [eax + 0x170], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(368) /* 0x170 */) = 0 /*0x0*/;
    // 0052df74  39d8                   +cmp eax, ebx
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
    // 0052df76  75ef                   -jne 0x52df67
    if (!cpu.flags.zf)
    {
        goto L_0x0052df67;
    }
    // 0052df78  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0052df7b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052df7c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052df7d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_52df80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052df80  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0052df81  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052df82  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052df83  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0052df84  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052df85  81ec30020000           -sub esp, 0x230
    (cpu.esp) -= x86::reg32(x86::sreg32(560 /*0x230*/));
    // 0052df8b  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0052df8d  89942414020000         -mov dword ptr [esp + 0x214], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(532) /* 0x214 */) = cpu.edx;
    // 0052df94  ff15246b9f00           -call dword ptr [0x9f6b24]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10447652) /* 0x9f6b24 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0052df9a  ba06000000             -mov edx, 6
    cpu.edx = 6 /*0x6*/;
    // 0052df9f  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0052dfa1  e8caf3ffff             -call 0x52d370
    cpu.esp -= 4;
    sub_52d370(app, cpu);
    if (cpu.terminate) return;
    // 0052dfa6  8b4e10                 -mov ecx, dword ptr [esi + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0052dfa9  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0052dfab  39c8                   +cmp eax, ecx
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
    // 0052dfad  0f838b020000           -jae 0x52e23e
    if (!cpu.flags.cf)
    {
        goto L_0x0052e23e;
    }
    // 0052dfb3  bd01000000             -mov ebp, 1
    cpu.ebp = 1 /*0x1*/;
L_0x0052dfb8:
    // 0052dfb8  d90495f4b15600         -fld dword ptr [edx*4 + 0x56b1f4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5681652) /* 0x56b1f4 */ + cpu.edx * 4)));
    // 0052dfbf  d8a614010000           -fsub dword ptr [esi + 0x114]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(276) /* 0x114 */));
    // 0052dfc5  dc0d1c215500           -fmul qword ptr [0x55211c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5579036) /* 0x55211c */));
    // 0052dfcb  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0052dfd0  8d7e04                 -lea edi, [esi + 4]
    cpu.edi = x86::reg32(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0052dfd3  d99c24d8010000         -fstp dword ptr [esp + 0x1d8]
    app->getMemory<float>(cpu.esp + x86::reg32(472) /* 0x1d8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0052dfda  bb06000000             -mov ebx, 6
    cpu.ebx = 6 /*0x6*/;
L_0x0052dfdf:
    // 0052dfdf  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0052dfe1  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0052dfe3  e888f3ffff             -call 0x52d370
    cpu.esp -= 4;
    sub_52d370(app, cpu);
    if (cpu.terminate) return;
    // 0052dfe8  d90485f4b15600         -fld dword ptr [eax*4 + 0x56b1f4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5681652) /* 0x56b1f4 */ + cpu.eax * 4)));
    // 0052dfef  d8a714010000           -fsub dword ptr [edi + 0x114]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(276) /* 0x114 */));
    // 0052dff5  dc0d1c215500           -fmul qword ptr [0x55211c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5579036) /* 0x55211c */));
    // 0052dffb  41                     -inc ecx
    (cpu.ecx)++;
    // 0052dffc  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052dfff  d99c8cd4010000         -fstp dword ptr [esp + ecx*4 + 0x1d4]
    app->getMemory<float>(cpu.esp + x86::reg32(468) /* 0x1d4 */ + cpu.ecx * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0052e006  83f904                 +cmp ecx, 4
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052e009  7cd4                   -jl 0x52dfdf
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0052dfdf;
    }
    // 0052e00b  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 0052e010  bb05000000             -mov ebx, 5
    cpu.ebx = 5 /*0x5*/;
    // 0052e015  8d7e10                 -lea edi, [esi + 0x10]
    cpu.edi = x86::reg32(cpu.esi + x86::reg32(16) /* 0x10 */);
L_0x0052e018:
    // 0052e018  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0052e01a  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0052e01c  e84ff3ffff             -call 0x52d370
    cpu.esp -= 4;
    sub_52d370(app, cpu);
    if (cpu.terminate) return;
    // 0052e021  d9048534b25600         -fld dword ptr [eax*4 + 0x56b234]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5681716) /* 0x56b234 */ + cpu.eax * 4)));
    // 0052e028  d8a714010000           -fsub dword ptr [edi + 0x114]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(276) /* 0x114 */));
    // 0052e02e  dc0d1c215500           -fmul qword ptr [0x55211c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5579036) /* 0x55211c */));
    // 0052e034  41                     -inc ecx
    (cpu.ecx)++;
    // 0052e035  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052e038  d99c8cd4010000         -fstp dword ptr [esp + ecx*4 + 0x1d4]
    app->getMemory<float>(cpu.esp + x86::reg32(468) /* 0x1d4 */ + cpu.ecx * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0052e03f  83f90c                 +cmp ecx, 0xc
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(12 /*0xc*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052e042  7cd4                   -jl 0x52e018
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0052e018;
    }
    // 0052e044  bbd8000000             -mov ebx, 0xd8
    cpu.ebx = 216 /*0xd8*/;
    // 0052e049  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0052e04b  899c2420020000         -mov dword ptr [esp + 0x220], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(544) /* 0x220 */) = cpu.ebx;
L_0x0052e052:
    // 0052e052  ba08000000             -mov edx, 8
    cpu.edx = 8 /*0x8*/;
    // 0052e057  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0052e059  e812f3ffff             -call 0x52d370
    cpu.esp -= 4;
    sub_52d370(app, cpu);
    if (cpu.terminate) return;
    // 0052e05e  8b942420020000         -mov edx, dword ptr [esp + 0x220]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(544) /* 0x220 */);
    // 0052e065  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0052e067  8994242c020000         -mov dword ptr [esp + 0x22c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(556) /* 0x22c */) = cpu.edx;
    // 0052e06e  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0052e070  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 0052e075  e8f6f2ffff             -call 0x52d370
    cpu.esp -= 4;
    sub_52d370(app, cpu);
    if (cpu.terminate) return;
    // 0052e07a  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0052e07c  89842408020000         -mov dword ptr [esp + 0x208], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(520) /* 0x208 */) = cpu.eax;
    // 0052e083  8994240c020000         -mov dword ptr [esp + 0x20c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(524) /* 0x20c */) = cpu.edx;
    // 0052e08a  dfac2408020000         -fild qword ptr [esp + 0x208]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.esp + x86::reg32(520) /* 0x208 */))));
    // 0052e091  dc0d24215500           -fmul qword ptr [0x552124]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5579044) /* 0x552124 */));
    // 0052e097  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0052e099  ba06000000             -mov edx, 6
    cpu.edx = 6 /*0x6*/;
    // 0052e09e  d99c2424020000         -fstp dword ptr [esp + 0x224]
    app->getMemory<float>(cpu.esp + x86::reg32(548) /* 0x224 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0052e0a5  e8c6f2ffff             -call 0x52d370
    cpu.esp -= 4;
    sub_52d370(app, cpu);
    if (cpu.terminate) return;
    // 0052e0aa  8b448614               -mov eax, dword ptr [esi + eax*4 + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */ + cpu.eax * 4);
    // 0052e0ae  8b4e0c                 -mov ecx, dword ptr [esi + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 0052e0b1  89842428020000         -mov dword ptr [esp + 0x228], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(552) /* 0x228 */) = cpu.eax;
    // 0052e0b8  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0052e0ba  0f8585010000           -jne 0x52e245
    if (!cpu.flags.zf)
    {
        goto L_0x0052e245;
    }
    // 0052e0c0  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0052e0c5  8d5c2414               -lea ebx, [esp + 0x14]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0052e0c9  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0052e0cb  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0052e0cd  e856f3ffff             -call 0x52d428
    cpu.esp -= 4;
    sub_52d428(app, cpu);
    if (cpu.terminate) return;
L_0x0052e0d2:
    // 0052e0d2  8b94242c020000         -mov edx, dword ptr [esp + 0x22c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(556) /* 0x22c */);
    // 0052e0d9  8d0c3e                 -lea ecx, [esi + edi]
    cpu.ecx = x86::reg32(cpu.esi + cpu.edi * 1);
    // 0052e0dc  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 0052e0df  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0052e0e1  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 0052e0e3  d9842428020000         -fld dword ptr [esp + 0x228]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(552) /* 0x228 */)));
    // 0052e0ea  d9842424020000         -fld dword ptr [esp + 0x224]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(548) /* 0x224 */)));
L_0x0052e0f1:
    // 0052e0f1  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 0052e0f3  d88a74010000           -fmul dword ptr [edx + 0x174]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(372) /* 0x174 */));
    // 0052e0f9  d9c2                   -fld st(2)
    cpu.fpu.push(x86::Float(cpu.fpu.st(2)));
    // 0052e0fb  d84c0414               -fmul dword ptr [esp + eax + 0x14]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */ + cpu.eax * 1));
    // 0052e0ff  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052e102  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052e105  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052e107  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052e10a  d99980060000           -fstp dword ptr [ecx + 0x680]
    app->getMemory<float>(cpu.ecx + x86::reg32(1664) /* 0x680 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0052e110  3db0010000             +cmp eax, 0x1b0
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(432 /*0x1b0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052e115  75da                   -jne 0x52e0f1
    if (!cpu.flags.zf)
    {
        goto L_0x0052e0f1;
    }
    // 0052e117  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0052e119  8b9c2420020000         -mov ebx, dword ptr [esp + 0x220]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(544) /* 0x220 */);
    // 0052e120  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0052e122  83c36c                 -add ebx, 0x6c
    (cpu.ebx) += x86::reg32(x86::sreg32(108 /*0x6c*/));
    // 0052e125  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0052e127  899c2420020000         -mov dword ptr [esp + 0x220], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(544) /* 0x220 */) = cpu.ebx;
    // 0052e12e  81ffc0060000           +cmp edi, 0x6c0
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1728 /*0x6c0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052e134  0f8518ffffff           -jne 0x52e052
    if (!cpu.flags.zf)
    {
        goto L_0x0052e052;
    }
    // 0052e13a  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0052e13c  8d9610050000           -lea edx, [esi + 0x510]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(1296) /* 0x510 */);
L_0x0052e142:
    // 0052e142  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052e145  8b8830080000           -mov ecx, dword ptr [eax + 0x830]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(2096) /* 0x830 */);
    // 0052e14b  898870010000           -mov dword ptr [eax + 0x170], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(368) /* 0x170 */) = cpu.ecx;
    // 0052e151  39d0                   +cmp eax, edx
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
    // 0052e153  75ed                   -jne 0x52e142
    if (!cpu.flags.zf)
    {
        goto L_0x0052e142;
    }
    // 0052e155  31d0                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0052e157  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
L_0x0052e159:
    // 0052e159  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052e15c  d98484d8010000         -fld dword ptr [esp + eax*4 + 0x1d8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(472) /* 0x1d8 */ + cpu.eax * 4)));
    // 0052e163  d88210010000           -fadd dword ptr [edx + 0x110]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(272) /* 0x110 */));
    // 0052e169  40                     -inc eax
    (cpu.eax)++;
    // 0052e16a  d99a10010000           -fstp dword ptr [edx + 0x110]
    app->getMemory<float>(cpu.edx + x86::reg32(272) /* 0x110 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0052e170  83f80c                 +cmp eax, 0xc
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(12 /*0xc*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052e173  7ce4                   -jl 0x52e159
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0052e159;
    }
    // 0052e175  8b8c2414020000         -mov ecx, dword ptr [esp + 0x214]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(532) /* 0x214 */);
    // 0052e17c  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0052e181  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0052e183  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0052e185  e84ef5ffff             -call 0x52d6d8
    cpu.esp -= 4;
    sub_52d6d8(app, cpu);
    if (cpu.terminate) return;
    // 0052e18a  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0052e18c  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0052e18e:
    // 0052e18e  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052e191  d98494d8010000         -fld dword ptr [esp + edx*4 + 0x1d8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(472) /* 0x1d8 */ + cpu.edx * 4)));
    // 0052e198  d88010010000           -fadd dword ptr [eax + 0x110]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(272) /* 0x110 */));
    // 0052e19e  42                     -inc edx
    (cpu.edx)++;
    // 0052e19f  d99810010000           -fstp dword ptr [eax + 0x110]
    app->getMemory<float>(cpu.eax + x86::reg32(272) /* 0x110 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0052e1a5  83fa0c                 +cmp edx, 0xc
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(12 /*0xc*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052e1a8  7ce4                   -jl 0x52e18e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0052e18e;
    }
    // 0052e1aa  8b8c2414020000         -mov ecx, dword ptr [esp + 0x214]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(532) /* 0x214 */);
    // 0052e1b1  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0052e1b6  ba0c000000             -mov edx, 0xc
    cpu.edx = 12 /*0xc*/;
    // 0052e1bb  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0052e1bd  e816f5ffff             -call 0x52d6d8
    cpu.esp -= 4;
    sub_52d6d8(app, cpu);
    if (cpu.terminate) return;
    // 0052e1c2  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0052e1c4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0052e1c6:
    // 0052e1c6  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052e1c9  d98484d8010000         -fld dword ptr [esp + eax*4 + 0x1d8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(472) /* 0x1d8 */ + cpu.eax * 4)));
    // 0052e1d0  d88210010000           -fadd dword ptr [edx + 0x110]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(272) /* 0x110 */));
    // 0052e1d6  40                     -inc eax
    (cpu.eax)++;
    // 0052e1d7  d99a10010000           -fstp dword ptr [edx + 0x110]
    app->getMemory<float>(cpu.edx + x86::reg32(272) /* 0x110 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0052e1dd  83f80c                 +cmp eax, 0xc
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(12 /*0xc*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052e1e0  7ce4                   -jl 0x52e1c6
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0052e1c6;
    }
    // 0052e1e2  8b8c2414020000         -mov ecx, dword ptr [esp + 0x214]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(532) /* 0x214 */);
    // 0052e1e9  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0052e1ee  ba18000000             -mov edx, 0x18
    cpu.edx = 24 /*0x18*/;
    // 0052e1f3  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0052e1f5  e8def4ffff             -call 0x52d6d8
    cpu.esp -= 4;
    sub_52d6d8(app, cpu);
    if (cpu.terminate) return;
    // 0052e1fa  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0052e1fc  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0052e1fe:
    // 0052e1fe  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052e201  d98494d8010000         -fld dword ptr [esp + edx*4 + 0x1d8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(472) /* 0x1d8 */ + cpu.edx * 4)));
    // 0052e208  d88010010000           -fadd dword ptr [eax + 0x110]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(272) /* 0x110 */));
    // 0052e20e  42                     -inc edx
    (cpu.edx)++;
    // 0052e20f  d99810010000           -fstp dword ptr [eax + 0x110]
    app->getMemory<float>(cpu.eax + x86::reg32(272) /* 0x110 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0052e215  83fa0c                 +cmp edx, 0xc
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(12 /*0xc*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052e218  7ce4                   -jl 0x52e1fe
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0052e1fe;
    }
    // 0052e21a  8b8c2414020000         -mov ecx, dword ptr [esp + 0x214]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(532) /* 0x214 */);
    // 0052e221  bb21000000             -mov ebx, 0x21
    cpu.ebx = 33 /*0x21*/;
    // 0052e226  ba24000000             -mov edx, 0x24
    cpu.edx = 36 /*0x24*/;
    // 0052e22b  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0052e22d  e8a6f4ffff             -call 0x52d6d8
    cpu.esp -= 4;
    sub_52d6d8(app, cpu);
    if (cpu.terminate) return;
    // 0052e232  81c430020000           -add esp, 0x230
    (cpu.esp) += x86::reg32(x86::sreg32(560 /*0x230*/));
    // 0052e238  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e239  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e23a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e23b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e23c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e23d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052e23e:
    // 0052e23e  31ed                   +xor ebp, ebp
    cpu.clear_co();
    cpu.set_szp((cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp))));
    // 0052e240  e973fdffff             -jmp 0x52dfb8
    goto L_0x0052dfb8;
L_0x0052e245:
    // 0052e245  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0052e24a  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0052e24c  e81ff1ffff             -call 0x52d370
    cpu.esp -= 4;
    sub_52d370(app, cpu);
    if (cpu.terminate) return;
    // 0052e251  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0052e256  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0052e258  89842418020000         -mov dword ptr [esp + 0x218], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(536) /* 0x218 */) = cpu.eax;
    // 0052e25f  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0052e261  8d5c2414               -lea ebx, [esp + 0x14]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0052e265  e806f1ffff             -call 0x52d370
    cpu.esp -= 4;
    sub_52d370(app, cpu);
    if (cpu.terminate) return;
    // 0052e26a  c1e102                 -shl ecx, 2
    cpu.ecx <<= 2 /*0x2*/ % 32;
    // 0052e26d  89842410020000         -mov dword ptr [esp + 0x210], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(528) /* 0x210 */) = cpu.eax;
    // 0052e274  898c241c020000         -mov dword ptr [esp + 0x21c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(540) /* 0x21c */) = cpu.ecx;
    // 0052e27b  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0052e27d  01cb                   -add ebx, ecx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0052e27f  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 0052e284  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0052e286  e89df1ffff             -call 0x52d428
    cpu.esp -= 4;
    sub_52d428(app, cpu);
    if (cpu.terminate) return;
    // 0052e28b  83bc241002000000       +cmp dword ptr [esp + 0x210], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(528) /* 0x210 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052e293  7424                   -je 0x52e2b9
    if (cpu.flags.zf)
    {
        goto L_0x0052e2b9;
    }
    // 0052e295  8b94241c020000         -mov edx, dword ptr [esp + 0x21c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(540) /* 0x21c */);
    // 0052e29c  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
    // 0052e29e  8d4218                 -lea eax, [edx + 0x18]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 0052e2a1  81c2c8010000           -add edx, 0x1c8
    (cpu.edx) += x86::reg32(x86::sreg32(456 /*0x1c8*/));
L_0x0052e2a7:
    // 0052e2a7  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0052e2aa  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0052e2ac  894c04f8               -mov dword ptr [esp + eax - 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(-8) /* -0x8 */ + cpu.eax * 1) = cpu.ecx;
    // 0052e2b0  39d0                   +cmp eax, edx
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
    // 0052e2b2  75f3                   -jne 0x52e2a7
    if (!cpu.flags.zf)
    {
        goto L_0x0052e2a7;
    }
    // 0052e2b4  e919feffff             -jmp 0x52e0d2
    goto L_0x0052e0d2;
L_0x0052e2b9:
    // 0052e2b9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0052e2bb:
    // 0052e2bb  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052e2be  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0052e2c0  894c04fc               -mov dword ptr [esp + eax - 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(-4) /* -0x4 */ + cpu.eax * 1) = cpu.ecx;
    // 0052e2c4  83f814                 +cmp eax, 0x14
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(20 /*0x14*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052e2c7  75f2                   -jne 0x52e2bb
    if (!cpu.flags.zf)
    {
        goto L_0x0052e2bb;
    }
    // 0052e2c9  b8c4010000             -mov eax, 0x1c4
    cpu.eax = 452 /*0x1c4*/;
L_0x0052e2ce:
    // 0052e2ce  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052e2d1  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0052e2d3  895c04fc               -mov dword ptr [esp + eax - 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(-4) /* -0x4 */ + cpu.eax * 1) = cpu.ebx;
    // 0052e2d7  3dd8010000             +cmp eax, 0x1d8
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(472 /*0x1d8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052e2dc  75f0                   -jne 0x52e2ce
    if (!cpu.flags.zf)
    {
        goto L_0x0052e2ce;
    }
    // 0052e2de  8b942418020000         -mov edx, dword ptr [esp + 0x218]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(536) /* 0x218 */);
    // 0052e2e5  8d442418               -lea eax, [esp + 0x18]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0052e2e9  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 0052e2ec  29d0                   +sub eax, edx
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0052e2ee  e8d9f2ffff             -call 0x52d5cc
    cpu.esp -= 4;
    sub_52d5cc(app, cpu);
    if (cpu.terminate) return;
    // 0052e2f3  d9842428020000         +fld dword ptr [esp + 0x228]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(552) /* 0x228 */)));
    // 0052e2fa  d9c0                   +fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 0052e2fc  dc0d2c215500           +fmul qword ptr [0x55212c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5579052) /* 0x55212c */));
    // 0052e302  ddd9                   +fstp st(1)
    cpu.fpu.st(1) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0052e304  d99c2428020000         +fstp dword ptr [esp + 0x228]
    app->getMemory<float>(cpu.esp + x86::reg32(552) /* 0x228 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0052e30b  e9c2fdffff             -jmp 0x52e0d2
    goto L_0x0052e0d2;
}

/* align: skip  */
void Application::sub_52e310(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052e310  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0052e311  833d00b2a00000         +cmp dword ptr [0xa0b200], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10531328) /* 0xa0b200 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052e318  7421                   -je 0x52e33b
    if (cpu.flags.zf)
    {
        goto L_0x0052e33b;
    }
    // 0052e31a  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0052e31c  8a1a                   -mov bl, byte ptr [edx]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx);
    // 0052e31e  8a9b11b2a000           -mov bl, byte ptr [ebx + 0xa0b211]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(10531345) /* 0xa0b211 */);
    // 0052e324  80e301                 -and bl, 1
    cpu.bl &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 0052e327  81e3ff000000           +and ebx, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 0052e32d  740c                   -je 0x52e33b
    if (cpu.flags.zf)
    {
        goto L_0x0052e33b;
    }
    // 0052e32f  8a1a                   -mov bl, byte ptr [edx]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx);
    // 0052e331  8818                   -mov byte ptr [eax], bl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.bl;
    // 0052e333  8a5201                 -mov dl, byte ptr [edx + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 0052e336  885001                 -mov byte ptr [eax + 1], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */) = cpu.dl;
    // 0052e339  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e33a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052e33b:
    // 0052e33b  8a12                   -mov dl, byte ptr [edx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx);
    // 0052e33d  8810                   -mov byte ptr [eax], dl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.dl;
    // 0052e33f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e340  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_52e350(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052e350  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0052e351  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052e352  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0052e353  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052e356  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_0x0052e358:
    // 0052e358  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0052e35a  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0052e35c  e85f6dffff             -call 0x5250c0
    cpu.esp -= 4;
    sub_5250c0(app, cpu);
    if (cpu.terminate) return;
    // 0052e361  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052e363  7531                   -jne 0x52e396
    if (!cpu.flags.zf)
    {
        goto L_0x0052e396;
    }
    // 0052e365  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0052e367  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0052e369  e8c2090000             -call 0x52ed30
    cpu.esp -= 4;
    sub_52ed30(app, cpu);
    if (cpu.terminate) return;
    // 0052e36e  e8fd090000             -call 0x52ed70
    cpu.esp -= 4;
    sub_52ed70(app, cpu);
    if (cpu.terminate) return;
    // 0052e373  e8680a0000             -call 0x52ede0
    cpu.esp -= 4;
    sub_52ede0(app, cpu);
    if (cpu.terminate) return;
    // 0052e378  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0052e37a  30d2                   +xor dl, dl
    cpu.clear_co();
    cpu.set_szp((cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl))));
    // 0052e37c  e82fd2ffff             -call 0x52b5b0
    cpu.esp -= 4;
    sub_52b5b0(app, cpu);
    if (cpu.terminate) return;
    // 0052e381  881404                 -mov byte ptr [esp + eax], dl
    app->getMemory<x86::reg8>(cpu.esp + cpu.eax * 1) = cpu.dl;
    // 0052e384  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0052e386  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0052e388  e883ffffff             -call 0x52e310
    cpu.esp -= 4;
    sub_52e310(app, cpu);
    if (cpu.terminate) return;
    // 0052e38d  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0052e38f  e86c6dffff             -call 0x525100
    cpu.esp -= 4;
    sub_525100(app, cpu);
    if (cpu.terminate) return;
    // 0052e394  ebc2                   -jmp 0x52e358
    goto L_0x0052e358;
L_0x0052e396:
    // 0052e396  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0052e398  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052e39b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e39c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e39d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e39e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_52e3a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052e3a0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0052e3a1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052e3a2  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 0052e3a4  3a1a                   +cmp bl, byte ptr [edx]
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
    // 0052e3a6  7541                   -jne 0x52e3e9
    if (!cpu.flags.zf)
    {
        goto L_0x0052e3e9;
    }
    // 0052e3a8  833d00b2a00000         +cmp dword ptr [0xa0b200], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10531328) /* 0xa0b200 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052e3af  741f                   -je 0x52e3d0
    if (cpu.flags.zf)
    {
        goto L_0x0052e3d0;
    }
    // 0052e3b1  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0052e3b3  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 0052e3b5  8a9b11b2a000           -mov bl, byte ptr [ebx + 0xa0b211]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(10531345) /* 0xa0b211 */);
    // 0052e3bb  80e301                 -and bl, 1
    cpu.bl &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 0052e3be  81e3ff000000           +and ebx, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 0052e3c4  740a                   -je 0x52e3d0
    if (cpu.flags.zf)
    {
        goto L_0x0052e3d0;
    }
    // 0052e3c6  8a5801                 -mov bl, byte ptr [eax + 1]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0052e3c9  8a4a01                 -mov cl, byte ptr [edx + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 0052e3cc  38cb                   +cmp bl, cl
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
    // 0052e3ce  7505                   -jne 0x52e3d5
    if (!cpu.flags.zf)
    {
        goto L_0x0052e3d5;
    }
L_0x0052e3d0:
    // 0052e3d0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0052e3d2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e3d3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e3d4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052e3d5:
    // 0052e3d5  88d8                   -mov al, bl
    cpu.al = cpu.bl;
    // 0052e3d7  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0052e3dc  88ca                   -mov dl, cl
    cpu.dl = cpu.cl;
    // 0052e3de  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0052e3e4  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0052e3e6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e3e7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e3e8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052e3e9:
    // 0052e3e9  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0052e3eb  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 0052e3ed  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0052e3ef  8a02                   -mov al, byte ptr [edx]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx);
    // 0052e3f1  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0052e3f3  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0052e3f5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e3f6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e3f7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_52e3f8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052e3f8  e9fd090000             -jmp 0x52edfa
    return sub_52edfa(app, cpu);
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_52e400(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052e400  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0052e401  83f803                 +cmp eax, 3
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
    // 0052e404  7604                   -jbe 0x52e40a
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0052e40a;
    }
    // 0052e406  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0052e408  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e409  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052e40a:
    // 0052e40a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0052e40c  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0052e40f  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0052e411  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0052e414  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0052e416  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 0052e418  05586f5600             -add eax, 0x566f58
    (cpu.eax) += x86::reg32(x86::sreg32(5664600 /*0x566f58*/));
    // 0052e41d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e41e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_52e420(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052e420  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0052e421  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052e422  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0052e423  8b0dfc4f5600           -mov ecx, dword ptr [0x564ffc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5656572) /* 0x564ffc */);
    // 0052e429  8b1df84f5600           -mov ebx, dword ptr [0x564ff8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5656568) /* 0x564ff8 */);
    // 0052e42f  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0052e431  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0052e433  e8c8090000             -call 0x52ee00
    cpu.esp -= 4;
    sub_52ee00(app, cpu);
    if (cpu.terminate) return;
    // 0052e438  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e439  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e43a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e43b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_52e440(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052e440  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0052e441  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052e442  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0052e443  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052e444  81ecc8000000           -sub esp, 0xc8
    (cpu.esp) -= x86::reg32(x86::sreg32(200 /*0xc8*/));
    // 0052e44a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0052e44c  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0052e44e  e8ed62fcff             -call 0x4f4740
    cpu.esp -= 4;
    sub_4f4740(app, cpu);
    if (cpu.terminate) return;
    // 0052e453  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0052e455  e80624fcff             -call 0x4f0860
    cpu.esp -= 4;
    sub_4f0860(app, cpu);
    if (cpu.terminate) return;
    // 0052e45a  8b1524725600           -mov edx, dword ptr [0x567224]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5665316) /* 0x567224 */);
    // 0052e460  a120725600             -mov eax, dword ptr [0x567220]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5665312) /* 0x567220 */);
    // 0052e465  8d8c24c4000000         -lea ecx, [esp + 0xc4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(196) /* 0xc4 */);
    // 0052e46c  e8bf13fcff             -call 0x4ef830
    cpu.esp -= 4;
    sub_4ef830(app, cpu);
    if (cpu.terminate) return;
    // 0052e471  8d8424c0000000         -lea eax, [esp + 0xc0]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(192) /* 0xc0 */);
    // 0052e478  8d9c24b8000000         -lea ebx, [esp + 0xb8]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(184) /* 0xb8 */);
    // 0052e47f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0052e480  8d9424c0000000         -lea edx, [esp + 0xc0]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(192) /* 0xc0 */);
    // 0052e487  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0052e489  e80228fcff             -call 0x4f0c90
    cpu.esp -= 4;
    sub_4f0c90(app, cpu);
    if (cpu.terminate) return;
    // 0052e48e  8b8c24b8000000         -mov ecx, dword ptr [esp + 0xb8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(184) /* 0xb8 */);
    // 0052e495  8b9c24bc000000         -mov ebx, dword ptr [esp + 0xbc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(188) /* 0xbc */);
    // 0052e49c  8b1524725600           -mov edx, dword ptr [0x567224]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5665316) /* 0x567224 */);
    // 0052e4a2  a1f8715600             -mov eax, dword ptr [0x5671f8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5665272) /* 0x5671f8 */);
    // 0052e4a7  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0052e4a8  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0052e4aa  8b15fc715600           -mov edx, dword ptr [0x5671fc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5665276) /* 0x5671fc */);
    // 0052e4b0  8b9c24c8000000         -mov ebx, dword ptr [esp + 0xc8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(200) /* 0xc8 */);
    // 0052e4b7  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0052e4b9  8b8c24c4000000         -mov ecx, dword ptr [esp + 0xc4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(196) /* 0xc4 */);
    // 0052e4c0  e87bf0fcff             -call 0x4fd540
    cpu.esp -= 4;
    sub_4fd540(app, cpu);
    if (cpu.terminate) return;
    // 0052e4c5  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0052e4c7  e89462fcff             -call 0x4f4760
    cpu.esp -= 4;
    sub_4f4760(app, cpu);
    if (cpu.terminate) return;
    // 0052e4cc  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0052e4ce  e87d16fcff             -call 0x4efb50
    cpu.esp -= 4;
    sub_4efb50(app, cpu);
    if (cpu.terminate) return;
    // 0052e4d3  81c4c8000000           -add esp, 0xc8
    (cpu.esp) += x86::reg32(x86::sreg32(200 /*0xc8*/));
    // 0052e4d9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e4da  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e4db  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e4dc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e4dd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_52e4e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052e4e0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052e4e1  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0052e4e3  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0052e4e5  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0052e4e7  e86423fcff             -call 0x4f0850
    cpu.esp -= 4;
    sub_4f0850(app, cpu);
    if (cpu.terminate) return;
    // 0052e4ec  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0052e4ee  e84dffffff             -call 0x52e440
    cpu.esp -= 4;
    sub_52e440(app, cpu);
    if (cpu.terminate) return;
    // 0052e4f3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e4f4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_52e500(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052e500  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052e501  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0052e502  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052e503  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0052e506  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0052e50a  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0052e50e  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 0052e510  894c2408               -mov dword ptr [esp + 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 0052e514  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0052e516  7402                   -je 0x52e51a
    if (cpu.flags.zf)
    {
        goto L_0x0052e51a;
    }
    // 0052e518  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
L_0x0052e51a:
    // 0052e51a  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
L_0x0052e51e:
    // 0052e51e  8a02                   -mov al, byte ptr [edx]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx);
    // 0052e520  fec0                   -inc al
    (cpu.al)++;
    // 0052e522  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0052e527  f680f04e560002         +test byte ptr [eax + 0x564ef0], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5656304) /* 0x564ef0 */) & 2 /*0x2*/));
    // 0052e52e  7403                   -je 0x52e533
    if (cpu.flags.zf)
    {
        goto L_0x0052e533;
    }
    // 0052e530  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0052e531  ebeb                   -jmp 0x52e51e
    goto L_0x0052e51e;
L_0x0052e533:
    // 0052e533  8a2a                   -mov ch, byte ptr [edx]
    cpu.ch = app->getMemory<x86::reg8>(cpu.edx);
    // 0052e535  80fd2b                 +cmp ch, 0x2b
    {
        x86::reg8 tmp1 = cpu.ch;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(43 /*0x2b*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0052e538  7405                   -je 0x52e53f
    if (cpu.flags.zf)
    {
        goto L_0x0052e53f;
    }
    // 0052e53a  80fd2d                 +cmp ch, 0x2d
    {
        x86::reg8 tmp1 = cpu.ch;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(45 /*0x2d*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0052e53d  7501                   -jne 0x52e540
    if (!cpu.flags.zf)
    {
        goto L_0x0052e540;
    }
L_0x0052e53f:
    // 0052e53f  42                     -inc edx
    (cpu.edx)++;
L_0x0052e540:
    // 0052e540  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0052e542  752c                   -jne 0x52e570
    if (!cpu.flags.zf)
    {
        goto L_0x0052e570;
    }
    // 0052e544  803a30                 +cmp byte ptr [edx], 0x30
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(48 /*0x30*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0052e547  7514                   -jne 0x52e55d
    if (!cpu.flags.zf)
    {
        goto L_0x0052e55d;
    }
    // 0052e549  8a4a01                 -mov cl, byte ptr [edx + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 0052e54c  80f978                 +cmp cl, 0x78
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(120 /*0x78*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0052e54f  7405                   -je 0x52e556
    if (cpu.flags.zf)
    {
        goto L_0x0052e556;
    }
    // 0052e551  80f958                 +cmp cl, 0x58
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(88 /*0x58*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0052e554  7507                   -jne 0x52e55d
    if (!cpu.flags.zf)
    {
        goto L_0x0052e55d;
    }
L_0x0052e556:
    // 0052e556  be10000000             -mov esi, 0x10
    cpu.esi = 16 /*0x10*/;
    // 0052e55b  eb33                   -jmp 0x52e590
    goto L_0x0052e590;
L_0x0052e55d:
    // 0052e55d  803a30                 +cmp byte ptr [edx], 0x30
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(48 /*0x30*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0052e560  7507                   -jne 0x52e569
    if (!cpu.flags.zf)
    {
        goto L_0x0052e569;
    }
    // 0052e562  be08000000             -mov esi, 8
    cpu.esi = 8 /*0x8*/;
    // 0052e567  eb3c                   -jmp 0x52e5a5
    goto L_0x0052e5a5;
L_0x0052e569:
    // 0052e569  be0a000000             -mov esi, 0xa
    cpu.esi = 10 /*0xa*/;
    // 0052e56e  eb35                   -jmp 0x52e5a5
    goto L_0x0052e5a5;
L_0x0052e570:
    // 0052e570  83fe02                 +cmp esi, 2
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
    // 0052e573  7c05                   -jl 0x52e57a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0052e57a;
    }
    // 0052e575  83fe24                 +cmp esi, 0x24
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(36 /*0x24*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052e578  7e11                   -jle 0x52e58b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0052e58b;
    }
L_0x0052e57a:
    // 0052e57a  b80d000000             -mov eax, 0xd
    cpu.eax = 13 /*0xd*/;
    // 0052e57f  e8fc42fdff             -call 0x502880
    cpu.esp -= 4;
    sub_502880(app, cpu);
    if (cpu.terminate) return;
    // 0052e584  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0052e586  e9c1000000             -jmp 0x52e64c
    goto L_0x0052e64c;
L_0x0052e58b:
    // 0052e58b  83fe10                 +cmp esi, 0x10
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052e58e  7515                   -jne 0x52e5a5
    if (!cpu.flags.zf)
    {
        goto L_0x0052e5a5;
    }
L_0x0052e590:
    // 0052e590  803a30                 +cmp byte ptr [edx], 0x30
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(48 /*0x30*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0052e593  7510                   -jne 0x52e5a5
    if (!cpu.flags.zf)
    {
        goto L_0x0052e5a5;
    }
    // 0052e595  8a7a01                 -mov bh, byte ptr [edx + 1]
    cpu.bh = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 0052e598  80ff78                 +cmp bh, 0x78
    {
        x86::reg8 tmp1 = cpu.bh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(120 /*0x78*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0052e59b  7405                   -je 0x52e5a2
    if (cpu.flags.zf)
    {
        goto L_0x0052e5a2;
    }
    // 0052e59d  80ff58                 +cmp bh, 0x58
    {
        x86::reg8 tmp1 = cpu.bh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(88 /*0x58*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0052e5a0  7503                   -jne 0x52e5a5
    if (!cpu.flags.zf)
    {
        goto L_0x0052e5a5;
    }
L_0x0052e5a2:
    // 0052e5a2  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
L_0x0052e5a5:
    // 0052e5a5  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 0052e5a8  8d2cb500000000         -lea ebp, [esi*4]
    cpu.ebp = x86::reg32(cpu.esi * 4);
    // 0052e5af  30c9                   -xor cl, cl
    cpu.cl ^= x86::reg8(x86::sreg8(cpu.cl));
    // 0052e5b1  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x0052e5b3:
    // 0052e5b3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0052e5b5  8a02                   -mov al, byte ptr [edx]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx);
    // 0052e5b7  e8b4000000             -call 0x52e670
    cpu.esp -= 4;
    sub_52e670(app, cpu);
    if (cpu.terminate) return;
    // 0052e5bc  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0052e5be  39f0                   +cmp eax, esi
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
    // 0052e5c0  7d1a                   -jge 0x52e5dc
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0052e5dc;
    }
    // 0052e5c2  3b9d48b65600           +cmp ebx, dword ptr [ebp + 0x56b648]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(5682760) /* 0x56b648 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052e5c8  7602                   -jbe 0x52e5cc
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0052e5cc;
    }
    // 0052e5ca  b101                   -mov cl, 1
    cpu.cl = 1 /*0x1*/;
L_0x0052e5cc:
    // 0052e5cc  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0052e5ce  0fafde                 -imul ebx, esi
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 0052e5d1  01fb                   -add ebx, edi
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edi));
    // 0052e5d3  39c3                   +cmp ebx, eax
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
    // 0052e5d5  7302                   -jae 0x52e5d9
    if (!cpu.flags.cf)
    {
        goto L_0x0052e5d9;
    }
    // 0052e5d7  b101                   -mov cl, 1
    cpu.cl = 1 /*0x1*/;
L_0x0052e5d9:
    // 0052e5d9  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0052e5da  ebd7                   -jmp 0x52e5b3
    goto L_0x0052e5b3;
L_0x0052e5dc:
    // 0052e5dc  3b1424                 +cmp edx, dword ptr [esp]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052e5df  7504                   -jne 0x52e5e5
    if (!cpu.flags.zf)
    {
        goto L_0x0052e5e5;
    }
    // 0052e5e1  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
L_0x0052e5e5:
    // 0052e5e5  8b7c2404               -mov edi, dword ptr [esp + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0052e5e9  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0052e5eb  7402                   -je 0x52e5ef
    if (cpu.flags.zf)
    {
        goto L_0x0052e5ef;
    }
    // 0052e5ed  8917                   -mov dword ptr [edi], edx
    app->getMemory<x86::reg32>(cpu.edi) = cpu.edx;
L_0x0052e5ef:
    // 0052e5ef  837c240801             +cmp dword ptr [esp + 8], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052e5f4  750f                   -jne 0x52e605
    if (!cpu.flags.zf)
    {
        goto L_0x0052e605;
    }
    // 0052e5f6  81fb00000080           +cmp ebx, 0x80000000
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2147483648 /*0x80000000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052e5fc  7207                   -jb 0x52e605
    if (cpu.flags.cf)
    {
        goto L_0x0052e605;
    }
    // 0052e5fe  7509                   -jne 0x52e609
    if (!cpu.flags.zf)
    {
        goto L_0x0052e609;
    }
    // 0052e600  80fd2d                 +cmp ch, 0x2d
    {
        x86::reg8 tmp1 = cpu.ch;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(45 /*0x2d*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0052e603  7504                   -jne 0x52e609
    if (!cpu.flags.zf)
    {
        goto L_0x0052e609;
    }
L_0x0052e605:
    // 0052e605  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 0052e607  743a                   -je 0x52e643
    if (cpu.flags.zf)
    {
        goto L_0x0052e643;
    }
L_0x0052e609:
    // 0052e609  b80e000000             -mov eax, 0xe
    cpu.eax = 14 /*0xe*/;
    // 0052e60e  e86d42fdff             -call 0x502880
    cpu.esp -= 4;
    sub_502880(app, cpu);
    if (cpu.terminate) return;
    // 0052e613  837c240800             +cmp dword ptr [esp + 8], 0
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
    // 0052e618  750c                   -jne 0x52e626
    if (!cpu.flags.zf)
    {
        goto L_0x0052e626;
    }
    // 0052e61a  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0052e61f  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0052e622  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e623  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e624  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e625  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052e626:
    // 0052e626  80fd2d                 +cmp ch, 0x2d
    {
        x86::reg8 tmp1 = cpu.ch;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(45 /*0x2d*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0052e629  750c                   -jne 0x52e637
    if (!cpu.flags.zf)
    {
        goto L_0x0052e637;
    }
    // 0052e62b  b800000080             -mov eax, 0x80000000
    cpu.eax = 2147483648 /*0x80000000*/;
    // 0052e630  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0052e633  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e634  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e635  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e636  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052e637:
    // 0052e637  b8ffffff7f             -mov eax, 0x7fffffff
    cpu.eax = 2147483647 /*0x7fffffff*/;
    // 0052e63c  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0052e63f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e640  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e641  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e642  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052e643:
    // 0052e643  80fd2d                 +cmp ch, 0x2d
    {
        x86::reg8 tmp1 = cpu.ch;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(45 /*0x2d*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0052e646  7502                   -jne 0x52e64a
    if (!cpu.flags.zf)
    {
        goto L_0x0052e64a;
    }
    // 0052e648  f7db                   -neg ebx
    cpu.ebx = ~cpu.ebx + 1;
L_0x0052e64a:
    // 0052e64a  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x0052e64c:
    // 0052e64c  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0052e64f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e650  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e651  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e652  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_52e654(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052e654  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052e655  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0052e657  e8a4feffff             -call 0x52e500
    cpu.esp -= 4;
    sub_52e500(app, cpu);
    if (cpu.terminate) return;
    // 0052e65c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e65d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_52e660(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052e660  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052e661  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0052e666  e895feffff             -call 0x52e500
    cpu.esp -= 4;
    sub_52e500(app, cpu);
    if (cpu.terminate) return;
    // 0052e66b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e66c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_52e670(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052e670  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0052e671  3c30                   +cmp al, 0x30
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
    // 0052e673  720e                   -jb 0x52e683
    if (cpu.flags.cf)
    {
        goto L_0x0052e683;
    }
    // 0052e675  3c39                   +cmp al, 0x39
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(57 /*0x39*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0052e677  770a                   -ja 0x52e683
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0052e683;
    }
    // 0052e679  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0052e67e  83e830                 -sub eax, 0x30
    (cpu.eax) -= x86::reg32(x86::sreg32(48 /*0x30*/));
    // 0052e681  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e682  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052e683:
    // 0052e683  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0052e688  e85324fcff             -call 0x4f0ae0
    cpu.esp -= 4;
    sub_4f0ae0(app, cpu);
    if (cpu.terminate) return;
    // 0052e68d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0052e68f  3c61                   +cmp al, 0x61
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(97 /*0x61*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0052e691  720d                   -jb 0x52e6a0
    if (cpu.flags.cf)
    {
        goto L_0x0052e6a0;
    }
    // 0052e693  3c69                   +cmp al, 0x69
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
    // 0052e695  7709                   -ja 0x52e6a0
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0052e6a0;
    }
    // 0052e697  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0052e699  88d0                   -mov al, dl
    cpu.al = cpu.dl;
    // 0052e69b  83e857                 -sub eax, 0x57
    (cpu.eax) -= x86::reg32(x86::sreg32(87 /*0x57*/));
    // 0052e69e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e69f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052e6a0:
    // 0052e6a0  3c6a                   +cmp al, 0x6a
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(106 /*0x6a*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0052e6a2  720e                   -jb 0x52e6b2
    if (cpu.flags.cf)
    {
        goto L_0x0052e6b2;
    }
    // 0052e6a4  3c72                   +cmp al, 0x72
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(114 /*0x72*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0052e6a6  770a                   -ja 0x52e6b2
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0052e6b2;
    }
    // 0052e6a8  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0052e6ad  83e857                 -sub eax, 0x57
    (cpu.eax) -= x86::reg32(x86::sreg32(87 /*0x57*/));
    // 0052e6b0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e6b1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052e6b2:
    // 0052e6b2  3c73                   +cmp al, 0x73
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
    // 0052e6b4  720e                   -jb 0x52e6c4
    if (cpu.flags.cf)
    {
        goto L_0x0052e6c4;
    }
    // 0052e6b6  3c7a                   +cmp al, 0x7a
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(122 /*0x7a*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0052e6b8  770a                   -ja 0x52e6c4
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0052e6c4;
    }
    // 0052e6ba  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0052e6bf  83e857                 -sub eax, 0x57
    (cpu.eax) -= x86::reg32(x86::sreg32(87 /*0x57*/));
    // 0052e6c2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e6c3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052e6c4:
    // 0052e6c4  b825000000             -mov eax, 0x25
    cpu.eax = 37 /*0x25*/;
    // 0052e6c9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052e6ca  c3                     -ret 
    cpu.esp += 4;
    return;
}

}
