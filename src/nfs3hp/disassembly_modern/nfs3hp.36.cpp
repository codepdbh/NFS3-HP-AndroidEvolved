#include "nfs3hp.h"
#include <lib/thread.h>

namespace nfs3hp
{

/* align: skip 0x00 0x00 */
void Application::sub_4e070c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e070c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e070d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004e070f  e80d000000             -call 0x4e0721
    cpu.esp -= 4;
    sub_4e0721(app, cpu);
    if (cpu.terminate) return;
    // 004e0714  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0715  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4e0716(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e0716  88df                   -mov bh, bl
    cpu.bh = cpu.bl;
    // 004e0718  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e0719  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004e071b  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004e071e  09c3                   -or ebx, eax
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.eax));
    // 004e0720  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0721  a907000000             +test eax, 7
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 7 /*0x7*/));
    // 004e0726  0f85a7000000           -jne 0x4e07d3
    if (!cpu.flags.zf)
    {
        goto L_0x004e07d3;
    }
L_0x004e072c:
    // 004e072c  83fa00                 +cmp edx, 0
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e072f  7c3f                   -jl 0x4e0770
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004e0770;
    }
    // 004e0731  80fbff                 +cmp bl, 0xff
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(255 /*0xff*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004e0734  743b                   -je 0x4e0771
    if (cpu.flags.zf)
    {
        goto L_0x004e0771;
    }
    // 004e0736  38fb                   +cmp bl, bh
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.bh));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004e0738  7537                   -jne 0x4e0771
    if (!cpu.flags.zf)
    {
        goto L_0x004e0771;
    }
    // 004e073a  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e073b  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e073c  dd0424                 -fld qword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.esp)));
    // 004e073f  83ea20                 +sub edx, 0x20
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004e0742  7813                   -js 0x4e0757
    if (cpu.flags.sf)
    {
        goto L_0x004e0757;
    }
L_0x004e0744:
    // 004e0744  dd10                   -fst qword ptr [eax]
    app->getMemory<double>(cpu.eax) = double(cpu.fpu.st(0));
    // 004e0746  dd5008                 -fst qword ptr [eax + 8]
    app->getMemory<double>(cpu.eax + x86::reg32(8) /* 0x8 */) = double(cpu.fpu.st(0));
    // 004e0749  dd5010                 -fst qword ptr [eax + 0x10]
    app->getMemory<double>(cpu.eax + x86::reg32(16) /* 0x10 */) = double(cpu.fpu.st(0));
    // 004e074c  dd5018                 -fst qword ptr [eax + 0x18]
    app->getMemory<double>(cpu.eax + x86::reg32(24) /* 0x18 */) = double(cpu.fpu.st(0));
    // 004e074f  8d4020                 -lea eax, [eax + 0x20]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 004e0752  83ea20                 +sub edx, 0x20
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004e0755  79ed                   -jns 0x4e0744
    if (!cpu.flags.sf)
    {
        goto L_0x004e0744;
    }
L_0x004e0757:
    // 004e0757  83c218                 +add edx, 0x18
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(24 /*0x18*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004e075a  780a                   -js 0x4e0766
    if (cpu.flags.sf)
    {
        goto L_0x004e0766;
    }
L_0x004e075c:
    // 004e075c  dd10                   -fst qword ptr [eax]
    app->getMemory<double>(cpu.eax) = double(cpu.fpu.st(0));
    // 004e075e  8d4008                 -lea eax, [eax + 8]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004e0761  83ea08                 +sub edx, 8
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004e0764  79f6                   -jns 0x4e075c
    if (!cpu.flags.sf)
    {
        goto L_0x004e075c;
    }
L_0x004e0766:
    // 004e0766  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004e0768  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004e076b  83c208                 +add edx, 8
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004e076e  753d                   -jne 0x4e07ad
    if (!cpu.flags.zf)
    {
        goto L_0x004e07ad;
    }
L_0x004e0770:
    // 004e0770  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e0771:
    // 004e0771  83ea20                 +sub edx, 0x20
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004e0774  781f                   -js 0x4e0795
    if (cpu.flags.sf)
    {
        goto L_0x004e0795;
    }
L_0x004e0776:
    // 004e0776  8918                   -mov dword ptr [eax], ebx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ebx;
    // 004e0778  895804                 -mov dword ptr [eax + 4], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 004e077b  895808                 -mov dword ptr [eax + 8], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 004e077e  89580c                 -mov dword ptr [eax + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 004e0781  895810                 -mov dword ptr [eax + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 004e0784  895814                 -mov dword ptr [eax + 0x14], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ebx;
    // 004e0787  895818                 -mov dword ptr [eax + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 004e078a  89581c                 -mov dword ptr [eax + 0x1c], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ebx;
    // 004e078d  8d4020                 -lea eax, [eax + 0x20]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 004e0790  83ea20                 +sub edx, 0x20
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004e0793  79e1                   -jns 0x4e0776
    if (!cpu.flags.sf)
    {
        goto L_0x004e0776;
    }
L_0x004e0795:
    // 004e0795  83c218                 +add edx, 0x18
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(24 /*0x18*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004e0798  780d                   -js 0x4e07a7
    if (cpu.flags.sf)
    {
        goto L_0x004e07a7;
    }
L_0x004e079a:
    // 004e079a  8918                   -mov dword ptr [eax], ebx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ebx;
    // 004e079c  895804                 -mov dword ptr [eax + 4], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 004e079f  8d4008                 -lea eax, [eax + 8]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004e07a2  83ea08                 +sub edx, 8
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004e07a5  79f3                   -jns 0x4e079a
    if (!cpu.flags.sf)
    {
        goto L_0x004e079a;
    }
L_0x004e07a7:
    // 004e07a7  83c208                 +add edx, 8
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004e07aa  7501                   -jne 0x4e07ad
    if (!cpu.flags.zf)
    {
        goto L_0x004e07ad;
    }
    // 004e07ac  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e07ad:
    // 004e07ad  f7c204000000           +test edx, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 4 /*0x4*/));
    // 004e07b3  7405                   -je 0x4e07ba
    if (cpu.flags.zf)
    {
        goto L_0x004e07ba;
    }
    // 004e07b5  8918                   -mov dword ptr [eax], ebx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ebx;
    // 004e07b7  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
L_0x004e07ba:
    // 004e07ba  f7c202000000           +test edx, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 2 /*0x2*/));
    // 004e07c0  7406                   -je 0x4e07c8
    if (cpu.flags.zf)
    {
        goto L_0x004e07c8;
    }
    // 004e07c2  668918                 -mov word ptr [eax], bx
    app->getMemory<x86::reg16>(cpu.eax) = cpu.bx;
    // 004e07c5  8d4002                 -lea eax, [eax + 2]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
L_0x004e07c8:
    // 004e07c8  f7c201000000           +test edx, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 1 /*0x1*/));
    // 004e07ce  7402                   -je 0x4e07d2
    if (cpu.flags.zf)
    {
        goto L_0x004e07d2;
    }
    // 004e07d0  8818                   -mov byte ptr [eax], bl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.bl;
L_0x004e07d2:
    // 004e07d2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e07d3:
    // 004e07d3  a901000000             +test eax, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 1 /*0x1*/));
    // 004e07d8  740d                   -je 0x4e07e7
    if (cpu.flags.zf)
    {
        goto L_0x004e07e7;
    }
    // 004e07da  83fa01                 +cmp edx, 1
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
    // 004e07dd  7c08                   -jl 0x4e07e7
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004e07e7;
    }
    // 004e07df  8818                   -mov byte ptr [eax], bl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.bl;
    // 004e07e1  8d4001                 -lea eax, [eax + 1]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004e07e4  83ea01                 -sub edx, 1
    (cpu.edx) -= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x004e07e7:
    // 004e07e7  a902000000             +test eax, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2 /*0x2*/));
    // 004e07ec  740e                   -je 0x4e07fc
    if (cpu.flags.zf)
    {
        goto L_0x004e07fc;
    }
    // 004e07ee  83fa02                 +cmp edx, 2
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
    // 004e07f1  7c09                   -jl 0x4e07fc
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004e07fc;
    }
    // 004e07f3  668918                 -mov word ptr [eax], bx
    app->getMemory<x86::reg16>(cpu.eax) = cpu.bx;
    // 004e07f6  8d4002                 -lea eax, [eax + 2]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 004e07f9  83ea02                 -sub edx, 2
    (cpu.edx) -= x86::reg32(x86::sreg32(2 /*0x2*/));
L_0x004e07fc:
    // 004e07fc  a904000000             +test eax, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 4 /*0x4*/));
    // 004e0801  740d                   -je 0x4e0810
    if (cpu.flags.zf)
    {
        goto L_0x004e0810;
    }
    // 004e0803  83fa04                 +cmp edx, 4
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e0806  7c08                   -jl 0x4e0810
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004e0810;
    }
    // 004e0808  8918                   -mov dword ptr [eax], ebx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ebx;
    // 004e080a  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004e080d  83ea04                 +sub edx, 4
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
L_0x004e0810:
    // 004e0810  e917ffffff             -jmp 0x4e072c
    goto L_0x004e072c;
}

/* align: skip  */
void Application::sub_4e0721(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004e0721;
    // 004e0716  88df                   -mov bh, bl
    cpu.bh = cpu.bl;
    // 004e0718  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e0719  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004e071b  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004e071e  09c3                   -or ebx, eax
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.eax));
    // 004e0720  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_entry_0x004e0721:
    // 004e0721  a907000000             +test eax, 7
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 7 /*0x7*/));
    // 004e0726  0f85a7000000           -jne 0x4e07d3
    if (!cpu.flags.zf)
    {
        goto L_0x004e07d3;
    }
L_0x004e072c:
    // 004e072c  83fa00                 +cmp edx, 0
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e072f  7c3f                   -jl 0x4e0770
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004e0770;
    }
    // 004e0731  80fbff                 +cmp bl, 0xff
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(255 /*0xff*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004e0734  743b                   -je 0x4e0771
    if (cpu.flags.zf)
    {
        goto L_0x004e0771;
    }
    // 004e0736  38fb                   +cmp bl, bh
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.bh));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004e0738  7537                   -jne 0x4e0771
    if (!cpu.flags.zf)
    {
        goto L_0x004e0771;
    }
    // 004e073a  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e073b  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e073c  dd0424                 -fld qword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.esp)));
    // 004e073f  83ea20                 +sub edx, 0x20
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004e0742  7813                   -js 0x4e0757
    if (cpu.flags.sf)
    {
        goto L_0x004e0757;
    }
L_0x004e0744:
    // 004e0744  dd10                   -fst qword ptr [eax]
    app->getMemory<double>(cpu.eax) = double(cpu.fpu.st(0));
    // 004e0746  dd5008                 -fst qword ptr [eax + 8]
    app->getMemory<double>(cpu.eax + x86::reg32(8) /* 0x8 */) = double(cpu.fpu.st(0));
    // 004e0749  dd5010                 -fst qword ptr [eax + 0x10]
    app->getMemory<double>(cpu.eax + x86::reg32(16) /* 0x10 */) = double(cpu.fpu.st(0));
    // 004e074c  dd5018                 -fst qword ptr [eax + 0x18]
    app->getMemory<double>(cpu.eax + x86::reg32(24) /* 0x18 */) = double(cpu.fpu.st(0));
    // 004e074f  8d4020                 -lea eax, [eax + 0x20]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 004e0752  83ea20                 +sub edx, 0x20
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004e0755  79ed                   -jns 0x4e0744
    if (!cpu.flags.sf)
    {
        goto L_0x004e0744;
    }
L_0x004e0757:
    // 004e0757  83c218                 +add edx, 0x18
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(24 /*0x18*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004e075a  780a                   -js 0x4e0766
    if (cpu.flags.sf)
    {
        goto L_0x004e0766;
    }
L_0x004e075c:
    // 004e075c  dd10                   -fst qword ptr [eax]
    app->getMemory<double>(cpu.eax) = double(cpu.fpu.st(0));
    // 004e075e  8d4008                 -lea eax, [eax + 8]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004e0761  83ea08                 +sub edx, 8
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004e0764  79f6                   -jns 0x4e075c
    if (!cpu.flags.sf)
    {
        goto L_0x004e075c;
    }
L_0x004e0766:
    // 004e0766  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004e0768  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004e076b  83c208                 +add edx, 8
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004e076e  753d                   -jne 0x4e07ad
    if (!cpu.flags.zf)
    {
        goto L_0x004e07ad;
    }
L_0x004e0770:
    // 004e0770  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e0771:
    // 004e0771  83ea20                 +sub edx, 0x20
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004e0774  781f                   -js 0x4e0795
    if (cpu.flags.sf)
    {
        goto L_0x004e0795;
    }
L_0x004e0776:
    // 004e0776  8918                   -mov dword ptr [eax], ebx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ebx;
    // 004e0778  895804                 -mov dword ptr [eax + 4], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 004e077b  895808                 -mov dword ptr [eax + 8], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 004e077e  89580c                 -mov dword ptr [eax + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 004e0781  895810                 -mov dword ptr [eax + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 004e0784  895814                 -mov dword ptr [eax + 0x14], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ebx;
    // 004e0787  895818                 -mov dword ptr [eax + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 004e078a  89581c                 -mov dword ptr [eax + 0x1c], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ebx;
    // 004e078d  8d4020                 -lea eax, [eax + 0x20]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 004e0790  83ea20                 +sub edx, 0x20
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004e0793  79e1                   -jns 0x4e0776
    if (!cpu.flags.sf)
    {
        goto L_0x004e0776;
    }
L_0x004e0795:
    // 004e0795  83c218                 +add edx, 0x18
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(24 /*0x18*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004e0798  780d                   -js 0x4e07a7
    if (cpu.flags.sf)
    {
        goto L_0x004e07a7;
    }
L_0x004e079a:
    // 004e079a  8918                   -mov dword ptr [eax], ebx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ebx;
    // 004e079c  895804                 -mov dword ptr [eax + 4], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 004e079f  8d4008                 -lea eax, [eax + 8]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004e07a2  83ea08                 +sub edx, 8
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004e07a5  79f3                   -jns 0x4e079a
    if (!cpu.flags.sf)
    {
        goto L_0x004e079a;
    }
L_0x004e07a7:
    // 004e07a7  83c208                 +add edx, 8
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004e07aa  7501                   -jne 0x4e07ad
    if (!cpu.flags.zf)
    {
        goto L_0x004e07ad;
    }
    // 004e07ac  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e07ad:
    // 004e07ad  f7c204000000           +test edx, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 4 /*0x4*/));
    // 004e07b3  7405                   -je 0x4e07ba
    if (cpu.flags.zf)
    {
        goto L_0x004e07ba;
    }
    // 004e07b5  8918                   -mov dword ptr [eax], ebx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ebx;
    // 004e07b7  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
L_0x004e07ba:
    // 004e07ba  f7c202000000           +test edx, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 2 /*0x2*/));
    // 004e07c0  7406                   -je 0x4e07c8
    if (cpu.flags.zf)
    {
        goto L_0x004e07c8;
    }
    // 004e07c2  668918                 -mov word ptr [eax], bx
    app->getMemory<x86::reg16>(cpu.eax) = cpu.bx;
    // 004e07c5  8d4002                 -lea eax, [eax + 2]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
L_0x004e07c8:
    // 004e07c8  f7c201000000           +test edx, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 1 /*0x1*/));
    // 004e07ce  7402                   -je 0x4e07d2
    if (cpu.flags.zf)
    {
        goto L_0x004e07d2;
    }
    // 004e07d0  8818                   -mov byte ptr [eax], bl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.bl;
L_0x004e07d2:
    // 004e07d2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e07d3:
    // 004e07d3  a901000000             +test eax, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 1 /*0x1*/));
    // 004e07d8  740d                   -je 0x4e07e7
    if (cpu.flags.zf)
    {
        goto L_0x004e07e7;
    }
    // 004e07da  83fa01                 +cmp edx, 1
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
    // 004e07dd  7c08                   -jl 0x4e07e7
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004e07e7;
    }
    // 004e07df  8818                   -mov byte ptr [eax], bl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.bl;
    // 004e07e1  8d4001                 -lea eax, [eax + 1]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004e07e4  83ea01                 -sub edx, 1
    (cpu.edx) -= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x004e07e7:
    // 004e07e7  a902000000             +test eax, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2 /*0x2*/));
    // 004e07ec  740e                   -je 0x4e07fc
    if (cpu.flags.zf)
    {
        goto L_0x004e07fc;
    }
    // 004e07ee  83fa02                 +cmp edx, 2
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
    // 004e07f1  7c09                   -jl 0x4e07fc
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004e07fc;
    }
    // 004e07f3  668918                 -mov word ptr [eax], bx
    app->getMemory<x86::reg16>(cpu.eax) = cpu.bx;
    // 004e07f6  8d4002                 -lea eax, [eax + 2]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 004e07f9  83ea02                 -sub edx, 2
    (cpu.edx) -= x86::reg32(x86::sreg32(2 /*0x2*/));
L_0x004e07fc:
    // 004e07fc  a904000000             +test eax, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 4 /*0x4*/));
    // 004e0801  740d                   -je 0x4e0810
    if (cpu.flags.zf)
    {
        goto L_0x004e0810;
    }
    // 004e0803  83fa04                 +cmp edx, 4
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e0806  7c08                   -jl 0x4e0810
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004e0810;
    }
    // 004e0808  8918                   -mov dword ptr [eax], ebx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ebx;
    // 004e080a  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004e080d  83ea04                 +sub edx, 4
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
L_0x004e0810:
    // 004e0810  e917ffffff             -jmp 0x4e072c
    goto L_0x004e072c;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4e0820(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e0820  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e0821  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e0822  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e0823  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004e0824  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004e0825  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004e0828  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004e082a  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004e082c  803a00                 +cmp byte ptr [edx], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004e082f  7507                   -jne 0x4e0838
    if (!cpu.flags.zf)
    {
        goto L_0x004e0838;
    }
    // 004e0831  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004e0833  e9ad000000             -jmp 0x4e08e5
    goto L_0x004e08e5;
L_0x004e0838:
    // 004e0838  807a0100               +cmp byte ptr [edx + 1], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004e083c  7525                   -jne 0x4e0863
    if (!cpu.flags.zf)
    {
        goto L_0x004e0863;
    }
    // 004e083e  8a13                   -mov dl, byte ptr [ebx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebx);
L_0x004e0840:
    // 004e0840  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004e0842  3ac2                   +cmp al, dl
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
    // 004e0844  7412                   -je 0x4e0858
    if (cpu.flags.zf)
    {
        goto L_0x004e0858;
    }
    // 004e0846  3c00                   +cmp al, 0
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
    // 004e0848  740c                   -je 0x4e0856
    if (cpu.flags.zf)
    {
        goto L_0x004e0856;
    }
    // 004e084a  46                     -inc esi
    (cpu.esi)++;
    // 004e084b  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004e084d  3ac2                   +cmp al, dl
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
    // 004e084f  7407                   -je 0x4e0858
    if (cpu.flags.zf)
    {
        goto L_0x004e0858;
    }
    // 004e0851  46                     -inc esi
    (cpu.esi)++;
    // 004e0852  3c00                   +cmp al, 0
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
    // 004e0854  75ea                   -jne 0x4e0840
    if (!cpu.flags.zf)
    {
        goto L_0x004e0840;
    }
L_0x004e0856:
    // 004e0856  2bf6                   -sub esi, esi
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.esi));
L_0x004e0858:
    // 004e0858  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004e085a  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004e085d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e085e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e085f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0860  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0861  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0862  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e0863:
    // 004e0863  b9ffffffff             -mov ecx, 0xffffffff
    cpu.ecx = 4294967295 /*0xffffffff*/;
    // 004e0868  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 004e086a  30c0                   +xor al, al
    cpu.clear_co();
    cpu.set_szp((cpu.al ^= x86::reg8(x86::sreg8(cpu.al))));
    // 004e086c  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004e086d  e30b                   -jecxz 0x4e087a
    if (cpu.ecx == 0)
    {
        goto L_0x004e087a;
    }
    // 004e086f  8cda                   -mov edx, ds
    cpu.edx = cpu.ds;
    // 004e0871  8ec2                   -mov es, edx
    cpu.es = cpu.edx;
    // 004e0873  f2ae                   +repne scasb al, byte ptr es:[edi]
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
    // 004e0875  7503                   -jne 0x4e087a
    if (!cpu.flags.zf)
    {
        goto L_0x004e087a;
    }
    // 004e0877  4f                     -dec edi
    (cpu.edi)--;
    // 004e0878  66a989cf               +test ax, 0xcf89
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.ax & 53129 /*0xcf89*/));
    // FakeJmpInstruction
    goto L_0x004e087c;
L_0x004e087a:
    // 004e087a  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
L_0x004e087c:
    // 004e087c  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004e087d  893c24                 -mov dword ptr [esp], edi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edi;
    // 004e0880  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004e0882  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004e0883  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004e0885  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004e0887  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004e0889  49                     -dec ecx
    (cpu.ecx)--;
    // 004e088a  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004e088c  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 004e088e  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 004e0890  49                     -dec ecx
    (cpu.ecx)--;
    // 004e0891  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004e0892  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
L_0x004e0894:
    // 004e0894  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 004e0897  29f1                   -sub ecx, esi
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004e0899  39e9                   +cmp ecx, ebp
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
    // 004e089b  7246                   -jb 0x4e08e3
    if (cpu.flags.cf)
    {
        goto L_0x004e08e3;
    }
    // 004e089d  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 004e089f  8a03                   -mov al, byte ptr [ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx);
    // 004e08a1  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004e08a2  e30b                   -jecxz 0x4e08af
    if (cpu.ecx == 0)
    {
        goto L_0x004e08af;
    }
    // 004e08a4  8cda                   -mov edx, ds
    cpu.edx = cpu.ds;
    // 004e08a6  8ec2                   -mov es, edx
    cpu.es = cpu.edx;
    // 004e08a8  f2ae                   +repne scasb al, byte ptr es:[edi]
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
    // 004e08aa  7503                   -jne 0x4e08af
    if (!cpu.flags.zf)
    {
        goto L_0x004e08af;
    }
    // 004e08ac  4f                     -dec edi
    (cpu.edi)--;
    // 004e08ad  66a989cf               +test ax, 0xcf89
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.ax & 53129 /*0xcf89*/));
    // FakeJmpInstruction
    goto L_0x004e08b1;
L_0x004e08af:
    // 004e08af  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
L_0x004e08b1:
    // 004e08b1  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004e08b2  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004e08b4  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004e08b6  742b                   -je 0x4e08e3
    if (cpu.flags.zf)
    {
        goto L_0x004e08e3;
    }
    // 004e08b8  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 004e08ba  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004e08bc  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004e08be  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004e08bf  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004e08c1  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004e08c3  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004e08c5  f3a6                   +repe cmpsb byte ptr [esi], byte ptr es:[edi]
    while (cpu.ecx)
    {
        {
            x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi);
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
            cpu.esi -= 1;
        }
        else
        {
            cpu.edi += 1;
            cpu.esi += 1;
        }
        --cpu.ecx;
        if (!cpu.flags.zf)
            break;
    }
    // 004e08c7  7405                   -je 0x4e08ce
    if (cpu.flags.zf)
    {
        goto L_0x004e08ce;
    }
    // 004e08c9  19c0                   +sbb eax, eax
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax)) + cpu.flags.cf;
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004e08cb  83d8ff                 -sbb eax, -1
    (cpu.eax) -= x86::reg32(x86::sreg32(-1 /*-0x1*/) + cpu.flags.cf);
L_0x004e08ce:
    // 004e08ce  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004e08cf  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e08d1  750b                   -jne 0x4e08de
    if (!cpu.flags.zf)
    {
        goto L_0x004e08de;
    }
    // 004e08d3  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004e08d5  83c404                 +add esp, 4
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
    // 004e08d8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e08d9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e08da  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e08db  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e08dc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e08dd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e08de:
    // 004e08de  8d7201                 -lea esi, [edx + 1]
    cpu.esi = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 004e08e1  ebb1                   -jmp 0x4e0894
    goto L_0x004e0894;
L_0x004e08e3:
    // 004e08e3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004e08e5:
    // 004e08e5  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004e08e8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e08e9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e08ea  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e08eb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e08ec  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e08ed  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_4e08f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e08f0  81ec04010000           -sub esp, 0x104
    (cpu.esp) -= x86::reg32(x86::sreg32(260 /*0x104*/));
    // 004e08f6  833dc844560002         +cmp dword ptr [0x5644c8], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5653704) /* 0x5644c8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e08fd  7c6e                   -jl 0x4e096d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004e096d;
    }
    // 004e08ff  833dc444560000         +cmp dword ptr [0x5644c4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5653700) /* 0x5644c4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e0906  750a                   -jne 0x4e0912
    if (!cpu.flags.zf)
    {
        goto L_0x004e0912;
    }
    // 004e0908  e8d3a90000             -call 0x4eb2e0
    cpu.esp -= 4;
    sub_4eb2e0(app, cpu);
    if (cpu.terminate) return;
    // 004e090d  a3c4445600             -mov dword ptr [0x5644c4], eax
    app->getMemory<x86::reg32>(x86::reg32(5653700) /* 0x5644c4 */) = cpu.eax;
L_0x004e0912:
    // 004e0912  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004e0913  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e0914  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e0915  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e0916  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e0917  8b1dc4445600           -mov ebx, dword ptr [0x5644c4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5653700) /* 0x5644c4 */);
    // 004e091d  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e091e  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e0924  8d842420010000         -lea eax, [esp + 0x120]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(288) /* 0x120 */);
    // 004e092b  8d9c2414010000         -lea ebx, [esp + 0x114]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(276) /* 0x114 */);
    // 004e0932  8b94241c010000         -mov edx, dword ptr [esp + 0x11c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(284) /* 0x11c */);
    // 004e0939  89842414010000         -mov dword ptr [esp + 0x114], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(276) /* 0x114 */) = cpu.eax;
    // 004e0940  8d442414               -lea eax, [esp + 0x14]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004e0944  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004e0946  e829edffff             -call 0x4df674
    cpu.esp -= 4;
    sub_4df674(app, cpu);
    if (cpu.terminate) return;
    // 004e094b  8d442414               -lea eax, [esp + 0x14]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004e094f  89b42414010000         -mov dword ptr [esp + 0x114], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(276) /* 0x114 */) = cpu.esi;
    // 004e0956  e805010000             -call 0x4e0a60
    cpu.esp -= 4;
    sub_4e0a60(app, cpu);
    if (cpu.terminate) return;
    // 004e095b  8b3dc4445600           -mov edi, dword ptr [0x5644c4]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5653700) /* 0x5644c4 */);
    // 004e0961  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004e0962  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e0968  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0969  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e096a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e096b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e096c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004e096d:
    // 004e096d  81c404010000           -add esp, 0x104
    (cpu.esp) += x86::reg32(x86::sreg32(260 /*0x104*/));
    // 004e0973  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_4e0980(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e0980  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e0981  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e0982  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004e0983  81ec04010000           -sub esp, 0x104
    (cpu.esp) -= x86::reg32(x86::sreg32(260 /*0x104*/));
    // 004e0989  8bb42414010000         -mov esi, dword ptr [esp + 0x114]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(276) /* 0x114 */);
    // 004e0990  8b9c2418010000         -mov ebx, dword ptr [esp + 0x118]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(280) /* 0x118 */);
    // 004e0997  833dc844560002         +cmp dword ptr [0x5644c8], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5653704) /* 0x5644c8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e099e  0f8c8a000000           -jl 0x4e0a2e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004e0a2e;
    }
    // 004e09a4  833dc444560000         +cmp dword ptr [0x5644c4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5653700) /* 0x5644c4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e09ab  0f8487000000           -je 0x4e0a38
    if (cpu.flags.zf)
    {
        goto L_0x004e0a38;
    }
L_0x004e09b1:
    // 004e09b1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004e09b2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e09b3  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e09b4  8b3dc4445600           -mov edi, dword ptr [0x5644c4]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5653700) /* 0x5644c4 */);
    // 004e09ba  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004e09bb  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e09c1  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004e09c3  7c23                   -jl 0x4e09e8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004e09e8;
    }
    // 004e09c5  83fe50                 +cmp esi, 0x50
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(80 /*0x50*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e09c8  7d1e                   -jge 0x4e09e8
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004e09e8;
    }
    // 004e09ca  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004e09cc  7c1a                   -jl 0x4e09e8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004e09e8;
    }
    // 004e09ce  83fb19                 +cmp ebx, 0x19
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(25 /*0x19*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e09d1  7d15                   -jge 0x4e09e8
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004e09e8;
    }
    // 004e09d3  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 004e09da  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004e09dc  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 004e09df  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 004e09e1  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 004e09e3  a3d4445600             -mov dword ptr [0x5644d4], eax
    app->getMemory<x86::reg32>(x86::reg32(5653716) /* 0x5644d4 */) = cpu.eax;
L_0x004e09e8:
    // 004e09e8  8d84242c010000         -lea eax, [esp + 0x12c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(300) /* 0x12c */);
    // 004e09ef  8d9c240c010000         -lea ebx, [esp + 0x10c]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(268) /* 0x10c */);
    // 004e09f6  8b942428010000         -mov edx, dword ptr [esp + 0x128]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(296) /* 0x128 */);
    // 004e09fd  8984240c010000         -mov dword ptr [esp + 0x10c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(268) /* 0x10c */) = cpu.eax;
    // 004e0a04  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004e0a08  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 004e0a0a  e865ecffff             -call 0x4df674
    cpu.esp -= 4;
    sub_4df674(app, cpu);
    if (cpu.terminate) return;
    // 004e0a0f  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004e0a13  89ac240c010000         -mov dword ptr [esp + 0x10c], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(268) /* 0x10c */) = cpu.ebp;
    // 004e0a1a  e841000000             -call 0x4e0a60
    cpu.esp -= 4;
    sub_4e0a60(app, cpu);
    if (cpu.terminate) return;
    // 004e0a1f  a1c4445600             -mov eax, dword ptr [0x5644c4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653700) /* 0x5644c4 */);
    // 004e0a24  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e0a25  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e0a2b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0a2c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0a2d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004e0a2e:
    // 004e0a2e  81c404010000           +add esp, 0x104
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(260 /*0x104*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004e0a34  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0a35  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0a36  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0a37  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e0a38:
    // 004e0a38  e8a3a80000             -call 0x4eb2e0
    cpu.esp -= 4;
    sub_4eb2e0(app, cpu);
    if (cpu.terminate) return;
    // 004e0a3d  a3c4445600             -mov dword ptr [0x5644c4], eax
    app->getMemory<x86::reg32>(x86::reg32(5653700) /* 0x5644c4 */) = cpu.eax;
    // 004e0a42  e96affffff             -jmp 0x4e09b1
    goto L_0x004e09b1;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_4e0a60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 004e0a60  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e0a61  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e0a62  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e0a63  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e0a64  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004e0a65  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004e0a66  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004e0a69  8b35d4445600           -mov esi, dword ptr [0x5644d4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5653716) /* 0x5644d4 */);
    // 004e0a6f  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004e0a71  833dc844560002         +cmp dword ptr [0x5644c8], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5653704) /* 0x5644c8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e0a78  7d10                   -jge 0x4e0a8a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004e0a8a;
    }
L_0x004e0a7a:
    // 004e0a7a  8b35d4445600           -mov esi, dword ptr [0x5644d4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5653716) /* 0x5644d4 */);
    // 004e0a80  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004e0a83  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0a84  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0a85  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0a86  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0a87  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0a88  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0a89  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e0a8a:
    // 004e0a8a  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004e0a8c  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004e0a8e  49                     -dec ecx
    (cpu.ecx)--;
    // 004e0a8f  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004e0a91  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 004e0a93  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 004e0a95  49                     -dec ecx
    (cpu.ecx)--;
    // 004e0a96  30db                   -xor bl, bl
    cpu.bl ^= x86::reg8(x86::sreg8(cpu.bl));
    // 004e0a98  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 004e0a9b  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004e0a9d  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004e0a9f  7ed9                   -jle 0x4e0a7a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004e0a7a;
    }
    // 004e0aa1  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
L_0x004e0aa3:
    // 004e0aa3  80fb0e                 +cmp bl, 0xe
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(14 /*0xe*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004e0aa6  7447                   -je 0x4e0aef
    if (cpu.flags.zf)
    {
        goto L_0x004e0aef;
    }
    // 004e0aa8  8a19                   -mov bl, byte ptr [ecx]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx);
    // 004e0aaa  8b35d4445600           -mov esi, dword ptr [0x5644d4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5653716) /* 0x5644d4 */);
    // 004e0ab0  80fb20                 +cmp bl, 0x20
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
    // 004e0ab3  7247                   -jb 0x4e0afc
    if (cpu.flags.cf)
    {
        goto L_0x004e0afc;
    }
    // 004e0ab5  e856010000             -call 0x4e0c10
    cpu.esp -= 4;
    sub_4e0c10(app, cpu);
    if (cpu.terminate) return;
    // 004e0aba  8b35d4445600           -mov esi, dword ptr [0x5644d4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5653716) /* 0x5644d4 */);
    // 004e0ac0  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 004e0ac2  30f6                   -xor dh, dh
    cpu.dh ^= x86::reg8(x86::sreg8(cpu.dh));
    // 004e0ac4  a0d9445600             -mov al, byte ptr [0x5644d9]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5653721) /* 0x5644d9 */);
    // 004e0ac9  88da                   -mov dl, bl
    cpu.dl = cpu.bl;
    // 004e0acb  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004e0ace  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 004e0ad1  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004e0ad3  8b15d0445600           -mov edx, dword ptr [0x5644d0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5653712) /* 0x5644d0 */);
    // 004e0ad9  8935d4445600           -mov dword ptr [0x5644d4], esi
    app->getMemory<x86::reg32>(x86::reg32(5653716) /* 0x5644d4 */) = cpu.esi;
    // 004e0adf  66894432fe             -mov word ptr [edx + esi - 2], ax
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(-2) /* -0x2 */ + cpu.esi * 1) = cpu.ax;
L_0x004e0ae4:
    // 004e0ae4  8b2c24                 -mov ebp, dword ptr [esp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    // 004e0ae7  47                     -inc edi
    (cpu.edi)++;
    // 004e0ae8  41                     -inc ecx
    (cpu.ecx)++;
    // 004e0ae9  39ef                   +cmp edi, ebp
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e0aeb  7d8d                   -jge 0x4e0a7a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004e0a7a;
    }
    // 004e0aed  ebb4                   -jmp 0x4e0aa3
    goto L_0x004e0aa3;
L_0x004e0aef:
    // 004e0aef  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004e0af1  8a01                   -mov al, byte ptr [ecx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx);
    // 004e0af3  30db                   +xor bl, bl
    cpu.clear_co();
    cpu.set_szp((cpu.bl ^= x86::reg8(x86::sreg8(cpu.bl))));
    // 004e0af5  e856020000             -call 0x4e0d50
    cpu.esp -= 4;
    sub_4e0d50(app, cpu);
    if (cpu.terminate) return;
    // 004e0afa  ebe8                   -jmp 0x4e0ae4
    goto L_0x004e0ae4;
L_0x004e0afc:
    // 004e0afc  88d8                   -mov al, bl
    cpu.al = cpu.bl;
    // 004e0afe  2c08                   -sub al, 8
    (cpu.al) -= x86::reg8(x86::sreg8(8 /*0x8*/));
    // 004e0b00  3c04                   +cmp al, 4
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(4 /*0x4*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004e0b02  77e0                   -ja 0x4e0ae4
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004e0ae4;
    }
    // 004e0b04  25ff000000             +and eax, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 004e0b09  ff2485480a4e00         -jmp dword ptr [eax*4 + 0x4e0a48]
    cpu.ip = app->getMemory<x86::reg32>(5114440 + cpu.eax * 4); goto dynamic_jump;
  case 0x004e0b10:
    // 004e0b10  83fe02                 +cmp esi, 2
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
    // 004e0b13  7ccf                   -jl 0x4e0ae4
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004e0ae4;
    }
    // 004e0b15  83ee02                 -sub esi, 2
    (cpu.esi) -= x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004e0b18  8935d4445600           -mov dword ptr [0x5644d4], esi
    app->getMemory<x86::reg32>(x86::reg32(5653716) /* 0x5644d4 */) = cpu.esi;
    // 004e0b1e  8b2c24                 -mov ebp, dword ptr [esp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    // 004e0b21  47                     -inc edi
    (cpu.edi)++;
    // 004e0b22  41                     -inc ecx
    (cpu.ecx)++;
    // 004e0b23  39ef                   +cmp edi, ebp
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e0b25  0f8d4fffffff           -jge 0x4e0a7a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004e0a7a;
    }
    // 004e0b2b  e973ffffff             -jmp 0x4e0aa3
    goto L_0x004e0aa3;
  case 0x004e0b30:
    // 004e0b30  803dda44560001         +cmp byte ptr [0x5644da], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5653722) /* 0x5644da */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004e0b37  76ab                   -jbe 0x4e0ae4
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004e0ae4;
    }
    // 004e0b39  bda0000000             -mov ebp, 0xa0
    cpu.ebp = 160 /*0xa0*/;
    // 004e0b3e  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004e0b40  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004e0b42  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004e0b45  f7fd                   -idiv ebp
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebp);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004e0b47  0fafe8                 -imul ebp, eax
    cpu.ebp = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebp)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 004e0b4a  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004e0b4c  29ea                   -sub edx, ebp
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 004e0b4e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004e0b50  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004e0b53  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004e0b55  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 004e0b57  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004e0b59  0fb635da445600         -movzx esi, byte ptr [0x5644da]
    cpu.esi = x86::reg32(app->getMemory<x86::reg8>(x86::reg32(5653722) /* 0x5644da */));
    // 004e0b60  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004e0b63  f7fe                   -idiv esi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.esi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004e0b65  40                     -inc eax
    (cpu.eax)++;
    // 004e0b66  0fafc6                 -imul eax, esi
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 004e0b69  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 004e0b6b  8d3428                 -lea esi, [eax + ebp]
    cpu.esi = x86::reg32(cpu.eax + cpu.ebp * 1);
    // 004e0b6e  8935d4445600           -mov dword ptr [0x5644d4], esi
    app->getMemory<x86::reg32>(x86::reg32(5653716) /* 0x5644d4 */) = cpu.esi;
    // 004e0b74  8b2c24                 -mov ebp, dword ptr [esp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    // 004e0b77  47                     -inc edi
    (cpu.edi)++;
    // 004e0b78  41                     -inc ecx
    (cpu.ecx)++;
    // 004e0b79  39ef                   +cmp edi, ebp
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e0b7b  0f8df9feffff           -jge 0x4e0a7a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004e0a7a;
    }
    // 004e0b81  e91dffffff             -jmp 0x4e0aa3
    goto L_0x004e0aa3;
  case 0x004e0b86:
    // 004e0b86  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004e0b88  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004e0b8a  bea0000000             -mov esi, 0xa0
    cpu.esi = 160 /*0xa0*/;
    // 004e0b8f  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004e0b92  f7fe                   -idiv esi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.esi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004e0b94  8d7001                 -lea esi, [eax + 1]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004e0b97  69f6a0000000           -imul esi, esi, 0xa0
    cpu.esi = x86::reg32(x86::sreg64(x86::sreg32(cpu.esi)) * x86::sreg64(x86::sreg32(160 /*0xa0*/)));
    // 004e0b9d  8935d4445600           -mov dword ptr [0x5644d4], esi
    app->getMemory<x86::reg32>(x86::reg32(5653716) /* 0x5644d4 */) = cpu.esi;
    // 004e0ba3  e868000000             -call 0x4e0c10
    cpu.esp -= 4;
    sub_4e0c10(app, cpu);
    if (cpu.terminate) return;
    // 004e0ba8  8b35d4445600           -mov esi, dword ptr [0x5644d4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5653716) /* 0x5644d4 */);
    // 004e0bae  8b2c24                 -mov ebp, dword ptr [esp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    // 004e0bb1  47                     -inc edi
    (cpu.edi)++;
    // 004e0bb2  41                     -inc ecx
    (cpu.ecx)++;
    // 004e0bb3  39ef                   +cmp edi, ebp
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e0bb5  0f8dbffeffff           -jge 0x4e0a7a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004e0a7a;
    }
    // 004e0bbb  e9e3feffff             -jmp 0x4e0aa3
    goto L_0x004e0aa3;
  case 0x004e0bc0:
    // 004e0bc0  0fb635d8445600         -movzx esi, byte ptr [0x5644d8]
    cpu.esi = x86::reg32(app->getMemory<x86::reg8>(x86::reg32(5653720) /* 0x5644d8 */));
    // 004e0bc7  69f6a0000000           -imul esi, esi, 0xa0
    cpu.esi = x86::reg32(x86::sreg64(x86::sreg32(cpu.esi)) * x86::sreg64(x86::sreg32(160 /*0xa0*/)));
    // 004e0bcd  8935d4445600           -mov dword ptr [0x5644d4], esi
    app->getMemory<x86::reg32>(x86::reg32(5653716) /* 0x5644d4 */) = cpu.esi;
    // 004e0bd3  8b2c24                 -mov ebp, dword ptr [esp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    // 004e0bd6  47                     -inc edi
    (cpu.edi)++;
    // 004e0bd7  41                     -inc ecx
    (cpu.ecx)++;
    // 004e0bd8  39ef                   +cmp edi, ebp
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e0bda  0f8d9afeffff           -jge 0x4e0a7a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004e0a7a;
    }
    // 004e0be0  e9befeffff             -jmp 0x4e0aa3
    goto L_0x004e0aa3;
  case 0x004e0be5:
    // 004e0be5  e8b6000000             -call 0x4e0ca0
    cpu.esp -= 4;
    sub_4e0ca0(app, cpu);
    if (cpu.terminate) return;
    // 004e0bea  0fb635d8445600         -movzx esi, byte ptr [0x5644d8]
    cpu.esi = x86::reg32(app->getMemory<x86::reg8>(x86::reg32(5653720) /* 0x5644d8 */));
    // 004e0bf1  69f6a0000000           -imul esi, esi, 0xa0
    cpu.esi = x86::reg32(x86::sreg64(x86::sreg32(cpu.esi)) * x86::sreg64(x86::sreg32(160 /*0xa0*/)));
    // 004e0bf7  8935d4445600           -mov dword ptr [0x5644d4], esi
    app->getMemory<x86::reg32>(x86::reg32(5653716) /* 0x5644d4 */) = cpu.esi;
    // 004e0bfd  8b2c24                 -mov ebp, dword ptr [esp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    // 004e0c00  47                     -inc edi
    (cpu.edi)++;
    // 004e0c01  41                     -inc ecx
    (cpu.ecx)++;
    // 004e0c02  39ef                   +cmp edi, ebp
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e0c04  0f8d70feffff           -jge 0x4e0a7a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004e0a7a;
    }
    // 004e0c0a  e994feffff             -jmp 0x4e0aa3
    goto L_0x004e0aa3;
  default:
    return app->dynamic_call(cpu.ip, cpu);
  }
}

/* align: skip 0x90 */
void Application::sub_4e0c10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e0c10  813dd4445600a00f0000   +cmp dword ptr [0x5644d4], 0xfa0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5653716) /* 0x5644d4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4000 /*0xfa0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e0c1a  7d01                   -jge 0x4e0c1d
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004e0c1d;
    }
    // 004e0c1c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e0c1d:
    // 004e0c1d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004e0c1e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e0c1f  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e0c20  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e0c21  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e0c22  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004e0c24  b919000000             -mov ecx, 0x19
    cpu.ecx = 25 /*0x19*/;
    // 004e0c29  8a15d8445600           -mov dl, byte ptr [0x5644d8]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(5653720) /* 0x5644d8 */);
    // 004e0c2f  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004e0c31  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 004e0c38  49                     -dec ecx
    (cpu.ecx)--;
    // 004e0c39  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004e0c3b  8d1c8d00000000         -lea ebx, [ecx*4]
    cpu.ebx = x86::reg32(cpu.ecx * 4);
    // 004e0c42  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 004e0c45  01cb                   -add ebx, ecx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004e0c47  8b0dd0445600           -mov ecx, dword ptr [0x5644d0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5653712) /* 0x5644d0 */);
    // 004e0c4d  42                     -inc edx
    (cpu.edx)++;
    // 004e0c4e  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004e0c50  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 004e0c57  8b35d0445600           -mov esi, dword ptr [0x5644d0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5653712) /* 0x5644d0 */);
    // 004e0c5d  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004e0c5f  c1e305                 -shl ebx, 5
    cpu.ebx <<= 5 /*0x5*/ % 32;
    // 004e0c62  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 004e0c65  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004e0c67  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 004e0c69  e882980000             -call 0x4ea4f0
    cpu.esp -= 4;
    sub_4ea4f0(app, cpu);
    if (cpu.terminate) return;
    // 004e0c6e  a1d0445600             -mov eax, dword ptr [0x5644d0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653712) /* 0x5644d0 */);
    // 004e0c73  baa0000000             -mov edx, 0xa0
    cpu.edx = 160 /*0xa0*/;
    // 004e0c78  05000f0000             -add eax, 0xf00
    (cpu.eax) += x86::reg32(x86::sreg32(3840 /*0xf00*/));
    // 004e0c7d  bf000f0000             -mov edi, 0xf00
    cpu.edi = 3840 /*0xf00*/;
    // 004e0c82  e885faffff             -call 0x4e070c
    cpu.esp -= 4;
    sub_4e070c(app, cpu);
    if (cpu.terminate) return;
    // 004e0c87  893dd4445600           -mov dword ptr [0x5644d4], edi
    app->getMemory<x86::reg32>(x86::reg32(5653716) /* 0x5644d4 */) = cpu.edi;
    // 004e0c8d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0c8e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0c8f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0c90  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0c91  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0c92  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4e0ca0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e0ca0  833dc844560002         +cmp dword ptr [0x5644c8], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5653704) /* 0x5644c8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e0ca7  7c44                   -jl 0x4e0ced
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004e0ced;
    }
    // 004e0ca9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e0caa  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e0cab  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e0cac  833dc444560000         +cmp dword ptr [0x5644c4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5653700) /* 0x5644c4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e0cb3  7439                   -je 0x4e0cee
    if (cpu.flags.zf)
    {
        goto L_0x004e0cee;
    }
L_0x004e0cb5:
    // 004e0cb5  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e0cb6  8b1dc4445600           -mov ebx, dword ptr [0x5644c4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5653700) /* 0x5644c4 */);
    // 004e0cbc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e0cbd  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e0cc3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004e0cc5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004e0cc6:
    // 004e0cc6  8b15d0445600           -mov edx, dword ptr [0x5644d0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5653712) /* 0x5644d0 */);
    // 004e0ccc  c7040200000000         -mov dword ptr [edx + eax], 0
    app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 1) = 0 /*0x0*/;
    // 004e0cd3  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004e0cd6  3da00f0000             +cmp eax, 0xfa0
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4000 /*0xfa0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e0cdb  7ce9                   -jl 0x4e0cc6
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004e0cc6;
    }
    // 004e0cdd  8b35c4445600           -mov esi, dword ptr [0x5644c4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5653700) /* 0x5644c4 */);
    // 004e0ce3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e0ce4  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e0cea  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0ceb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0cec  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004e0ced:
    // 004e0ced  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e0cee:
    // 004e0cee  e8eda50000             -call 0x4eb2e0
    cpu.esp -= 4;
    sub_4eb2e0(app, cpu);
    if (cpu.terminate) return;
    // 004e0cf3  a3c4445600             -mov dword ptr [0x5644c4], eax
    app->getMemory<x86::reg32>(x86::reg32(5653700) /* 0x5644c4 */) = cpu.eax;
    // 004e0cf8  ebbb                   -jmp 0x4e0cb5
    goto L_0x004e0cb5;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_4e0d00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e0d00  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e0d01  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e0d02  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e0d03  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004e0d05  833dc444560000         +cmp dword ptr [0x5644c4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5653700) /* 0x5644c4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e0d0c  750a                   -jne 0x4e0d18
    if (!cpu.flags.zf)
    {
        goto L_0x004e0d18;
    }
    // 004e0d0e  e8cda50000             -call 0x4eb2e0
    cpu.esp -= 4;
    sub_4eb2e0(app, cpu);
    if (cpu.terminate) return;
    // 004e0d13  a3c4445600             -mov dword ptr [0x5644c4], eax
    app->getMemory<x86::reg32>(x86::reg32(5653700) /* 0x5644c4 */) = cpu.eax;
L_0x004e0d18:
    // 004e0d18  8b0dc4445600           -mov ecx, dword ptr [0x5644c4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5653700) /* 0x5644c4 */);
    // 004e0d1e  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e0d1f  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e0d25  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004e0d27  7c0b                   -jl 0x4e0d34
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004e0d34;
    }
    // 004e0d29  83fb18                 +cmp ebx, 0x18
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(24 /*0x18*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e0d2c  7f06                   -jg 0x4e0d34
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004e0d34;
    }
    // 004e0d2e  881dd8445600           -mov byte ptr [0x5644d8], bl
    app->getMemory<x86::reg8>(x86::reg32(5653720) /* 0x5644d8 */) = cpu.bl;
L_0x004e0d34:
    // 004e0d34  8b1dc4445600           -mov ebx, dword ptr [0x5644c4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5653700) /* 0x5644c4 */);
    // 004e0d3a  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e0d3b  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e0d41  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0d42  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0d43  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0d44  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_4e0d50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e0d50  a2d9445600             -mov byte ptr [0x5644d9], al
    app->getMemory<x86::reg8>(x86::reg32(5653721) /* 0x5644d9 */) = cpu.al;
    // 004e0d55  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void Application::sub_4e0d60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e0d60  83f801                 +cmp eax, 1
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
    // 004e0d63  7d01                   -jge 0x4e0d66
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004e0d66;
    }
    // 004e0d65  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e0d66:
    // 004e0d66  a2da445600             -mov byte ptr [0x5644da], al
    app->getMemory<x86::reg8>(x86::reg32(5653722) /* 0x5644da */) = cpu.al;
    // 004e0d6b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_4e0d70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e0d70  c1e00f                 -shl eax, 0xf
    cpu.eax <<= 15 /*0xf*/ % 32;
    // 004e0d73  0500000b00             -add eax, 0xb0000
    (cpu.eax) += x86::reg32(x86::sreg32(720896 /*0xb0000*/));
    // 004e0d78  a3d0445600             -mov dword ptr [0x5644d0], eax
    app->getMemory<x86::reg32>(x86::reg32(5653712) /* 0x5644d0 */) = cpu.eax;
    // 004e0d7d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4e0d80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e0d80  c60000                 -mov byte ptr [eax], 0
    app->getMemory<x86::reg8>(cpu.eax) = 0 /*0x0*/;
    // 004e0d83  c60200                 -mov byte ptr [edx], 0
    app->getMemory<x86::reg8>(cpu.edx) = 0 /*0x0*/;
    // 004e0d86  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_4e0d88(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e0d88  a1f4445600             -mov eax, dword ptr [0x5644f4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653748) /* 0x5644f4 */);
    // 004e0d8d  0305f0445600           +add eax, dword ptr [0x5644f0]
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5653744) /* 0x5644f0 */)));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004e0d93  a3f0445600             -mov dword ptr [0x5644f0], eax
    app->getMemory<x86::reg32>(x86::reg32(5653744) /* 0x5644f0 */) = cpu.eax;
    // 004e0d98  1305ec445600           +adc eax, dword ptr [0x5644ec]
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5653740) /* 0x5644ec */))) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004e0d9e  a3ec445600             -mov dword ptr [0x5644ec], eax
    app->getMemory<x86::reg32>(x86::reg32(5653740) /* 0x5644ec */) = cpu.eax;
    // 004e0da3  1305e8445600           +adc eax, dword ptr [0x5644e8]
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5653736) /* 0x5644e8 */))) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004e0da9  a3e8445600             -mov dword ptr [0x5644e8], eax
    app->getMemory<x86::reg32>(x86::reg32(5653736) /* 0x5644e8 */) = cpu.eax;
    // 004e0dae  1305e4445600           +adc eax, dword ptr [0x5644e4]
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5653732) /* 0x5644e4 */))) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004e0db4  a3e4445600             -mov dword ptr [0x5644e4], eax
    app->getMemory<x86::reg32>(x86::reg32(5653732) /* 0x5644e4 */) = cpu.eax;
    // 004e0db9  1305e0445600           +adc eax, dword ptr [0x5644e0]
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5653728) /* 0x5644e0 */))) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004e0dbf  ff05f4445600           +inc dword ptr [0x5644f4]
    {
        auto tmp = app->getMemory<x86::reg32>(x86::reg32(5653748) /* 0x5644f4 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004e0dc5  7521                   -jne 0x4e0de8
    if (!cpu.flags.zf)
    {
        goto L_0x004e0de8;
    }
    // 004e0dc7  ff05f0445600           +inc dword ptr [0x5644f0]
    {
        auto tmp = app->getMemory<x86::reg32>(x86::reg32(5653744) /* 0x5644f0 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004e0dcd  7519                   -jne 0x4e0de8
    if (!cpu.flags.zf)
    {
        goto L_0x004e0de8;
    }
    // 004e0dcf  ff05ec445600           +inc dword ptr [0x5644ec]
    {
        auto tmp = app->getMemory<x86::reg32>(x86::reg32(5653740) /* 0x5644ec */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004e0dd5  7511                   -jne 0x4e0de8
    if (!cpu.flags.zf)
    {
        goto L_0x004e0de8;
    }
    // 004e0dd7  ff05e8445600           +inc dword ptr [0x5644e8]
    {
        auto tmp = app->getMemory<x86::reg32>(x86::reg32(5653736) /* 0x5644e8 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004e0ddd  7509                   -jne 0x4e0de8
    if (!cpu.flags.zf)
    {
        goto L_0x004e0de8;
    }
    // 004e0ddf  ff05e4445600           +inc dword ptr [0x5644e4]
    {
        auto tmp = app->getMemory<x86::reg32>(x86::reg32(5653732) /* 0x5644e4 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004e0de5  7501                   -jne 0x4e0de8
    if (!cpu.flags.zf)
    {
        goto L_0x004e0de8;
    }
    // 004e0de7  40                     -inc eax
    (cpu.eax)++;
L_0x004e0de8:
    // 004e0de8  a3e0445600             -mov dword ptr [0x5644e0], eax
    app->getMemory<x86::reg32>(x86::reg32(5653728) /* 0x5644e0 */) = cpu.eax;
    // 004e0ded  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4e0dee(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e0dee  05560e2df2             -add eax, 0xf22d0e56
    (cpu.eax) += x86::reg32(x86::sreg32(4063039062 /*0xf22d0e56*/));
    // 004e0df3  a3e0445600             -mov dword ptr [0x5644e0], eax
    app->getMemory<x86::reg32>(x86::reg32(5653728) /* 0x5644e0 */) = cpu.eax;
    // 004e0df8  0593180496             -add eax, 0x96041893
    (cpu.eax) += x86::reg32(x86::sreg32(2516850835 /*0x96041893*/));
    // 004e0dfd  a3e4445600             -mov dword ptr [0x5644e4], eax
    app->getMemory<x86::reg32>(x86::reg32(5653732) /* 0x5644e4 */) = cpu.eax;
    // 004e0e02  0546b6f33d             -add eax, 0x3df3b646
    (cpu.eax) += x86::reg32(x86::sreg32(1039382086 /*0x3df3b646*/));
    // 004e0e07  a3e8445600             -mov dword ptr [0x5644e8], eax
    app->getMemory<x86::reg32>(x86::reg32(5653736) /* 0x5644e8 */) = cpu.eax;
    // 004e0e0c  056de7dd40             -add eax, 0x40dde76d
    (cpu.eax) += x86::reg32(x86::sreg32(1088284525 /*0x40dde76d*/));
    // 004e0e11  a3ec445600             -mov dword ptr [0x5644ec], eax
    app->getMemory<x86::reg32>(x86::reg32(5653740) /* 0x5644ec */) = cpu.eax;
    // 004e0e16  05e17a3297             -add eax, 0x97327ae1
    (cpu.eax) += x86::reg32(x86::sreg32(2536667873 /*0x97327ae1*/));
    // 004e0e1b  a3f0445600             -mov dword ptr [0x5644f0], eax
    app->getMemory<x86::reg32>(x86::reg32(5653744) /* 0x5644f0 */) = cpu.eax;
    // 004e0e20  05e7fba9d1             -add eax, 0xd1a9fbe7
    (cpu.eax) += x86::reg32(x86::sreg32(3517578215 /*0xd1a9fbe7*/));
    // 004e0e25  a3f4445600             -mov dword ptr [0x5644f4], eax
    app->getMemory<x86::reg32>(x86::reg32(5653748) /* 0x5644f4 */) = cpu.eax;
    // 004e0e2a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4e0e30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e0e30  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e0e31  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e0e32  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004e0e34  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004e0e36  740f                   -je 0x4e0e47
    if (cpu.flags.zf)
    {
        goto L_0x004e0e47;
    }
L_0x004e0e38:
    // 004e0e38  803a00                 +cmp byte ptr [edx], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004e0e3b  740a                   -je 0x4e0e47
    if (cpu.flags.zf)
    {
        goto L_0x004e0e47;
    }
    // 004e0e3d  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004e0e3e  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 004e0e40  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004e0e41  8848ff                 -mov byte ptr [eax - 1], cl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(-1) /* -0x1 */) = cpu.cl;
    // 004e0e44  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004e0e45  75f1                   -jne 0x4e0e38
    if (!cpu.flags.zf)
    {
        goto L_0x004e0e38;
    }
L_0x004e0e47:
    // 004e0e47  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x004e0e49:
    // 004e0e49  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004e0e4b  7407                   -je 0x4e0e54
    if (cpu.flags.zf)
    {
        goto L_0x004e0e54;
    }
    // 004e0e4d  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004e0e4e  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004e0e4f  8850ff                 -mov byte ptr [eax - 1], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(-1) /* -0x1 */) = cpu.dl;
    // 004e0e52  ebf5                   -jmp 0x4e0e49
    goto L_0x004e0e49;
L_0x004e0e54:
    // 004e0e54  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004e0e56  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0e57  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0e58  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4e0e60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e0e60  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e0e61  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e0e62  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e0e63  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e0e64  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004e0e67  8d4c2408               -lea ecx, [esp + 8]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004e0e6b  8d5c2404               -lea ebx, [esp + 4]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004e0e6f  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004e0e71  8b350c445600           -mov esi, dword ptr [0x56440c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5653516) /* 0x56440c */);
    // 004e0e77  89150c445600           -mov dword ptr [0x56440c], edx
    app->getMemory<x86::reg32>(x86::reg32(5653516) /* 0x56440c */) = cpu.edx;
    // 004e0e7d  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004e0e7f  e84c1a0000             -call 0x4e28d0
    cpu.esp -= 4;
    sub_4e28d0(app, cpu);
    if (cpu.terminate) return;
    // 004e0e84  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 004e0e87  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004e0e89  7511                   -jne 0x4e0e9c
    if (!cpu.flags.zf)
    {
        goto L_0x004e0e9c;
    }
    // 004e0e8b  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004e0e8e  89350c445600           -mov dword ptr [0x56440c], esi
    app->getMemory<x86::reg32>(x86::reg32(5653516) /* 0x56440c */) = cpu.esi;
    // 004e0e94  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004e0e97  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0e98  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0e99  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0e9a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0e9b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e0e9c:
    // 004e0e9c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004e0e9e  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004e0ea3  e8f81e0000             -call 0x4e2da0
    cpu.esp -= 4;
    sub_4e2da0(app, cpu);
    if (cpu.terminate) return;
    // 004e0ea8  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 004e0eab  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004e0eae  89350c445600           -mov dword ptr [0x56440c], esi
    app->getMemory<x86::reg32>(x86::reg32(5653516) /* 0x56440c */) = cpu.esi;
    // 004e0eb4  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004e0eb7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0eb8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0eb9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0eba  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0ebb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_4e0ec0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e0ec0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e0ec1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e0ec2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e0ec3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004e0ec4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004e0ec5  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004e0ec8  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004e0eca  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 004e0ecc  b8f4010000             -mov eax, 0x1f4
    cpu.eax = 500 /*0x1f4*/;
    // 004e0ed1  89e1                   -mov ecx, esp
    cpu.ecx = cpu.esp;
    // 004e0ed3  8d5c2404               -lea ebx, [esp + 4]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004e0ed7  8d542408               -lea edx, [esp + 8]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004e0edb  e8e0e80100             -call 0x4ff7c0
    cpu.esp -= 4;
    sub_4ff7c0(app, cpu);
    if (cpu.terminate) return;
    // 004e0ee0  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004e0ee2  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004e0ee4  e8e7190000             -call 0x4e28d0
    cpu.esp -= 4;
    sub_4e28d0(app, cpu);
    if (cpu.terminate) return;
    // 004e0ee9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e0eeb  0f84cc000000           -je 0x4e0fbd
    if (cpu.flags.zf)
    {
        goto L_0x004e0fbd;
    }
    // 004e0ef1  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 004e0ef4  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004e0ef6  0f84c1000000           -je 0x4e0fbd
    if (cpu.flags.zf)
    {
        goto L_0x004e0fbd;
    }
    // 004e0efc  b90e010000             -mov ecx, 0x10e
    cpu.ecx = 270 /*0x10e*/;
    // 004e0f01  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004e0f03  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004e0f06  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004e0f08  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004e0f0a  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004e0f0e  e81de90100             -call 0x4ff830
    cpu.esp -= 4;
    sub_4ff830(app, cpu);
    if (cpu.terminate) return;
    // 004e0f13  8b3560785600           -mov esi, dword ptr [0x567860]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5666912) /* 0x567860 */);
    // 004e0f19  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004e0f1b  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004e0f1d  bb28995400             -mov ebx, 0x549928
    cpu.ebx = 5544232 /*0x549928*/;
    // 004e0f22  e8f9e80100             -call 0x4ff820
    cpu.esp -= 4;
    sub_4ff820(app, cpu);
    if (cpu.terminate) return;
    // 004e0f27  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004e0f29  be38995400             -mov esi, 0x549938
    cpu.esi = 5544248 /*0x549938*/;
    // 004e0f2e  e88de80100             -call 0x4ff7c0
    cpu.esp -= 4;
    sub_4ff7c0(app, cpu);
    if (cpu.terminate) return;
    // 004e0f33  b84b000000             -mov eax, 0x4b
    cpu.eax = 75 /*0x4b*/;
    // 004e0f38  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 004e0f3b  891d90215500           -mov dword ptr [0x552190], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ebx;
    // 004e0f41  a398215500             -mov dword ptr [0x552198], eax
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.eax;
    // 004e0f46  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 004e0f48  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004e0f4a  893594215500           -mov dword ptr [0x552194], esi
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.esi;
    // 004e0f50  e8cb060000             -call 0x4e1620
    cpu.esp -= 4;
    sub_4e1620(app, cpu);
    if (cpu.terminate) return;
    // 004e0f55  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004e0f57  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e0f59  7416                   -je 0x4e0f71
    if (cpu.flags.zf)
    {
        goto L_0x004e0f71;
    }
    // 004e0f5b  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 004e0f5e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004e0f60  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004e0f64  e8771e0000             -call 0x4e2de0
    cpu.esp -= 4;
    sub_4e2de0(app, cpu);
    if (cpu.terminate) return;
    // 004e0f69  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004e0f6c  a3f8435600             -mov dword ptr [0x5643f8], eax
    app->getMemory<x86::reg32>(x86::reg32(5653496) /* 0x5643f8 */) = cpu.eax;
L_0x004e0f71:
    // 004e0f71  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004e0f75  e8261e0000             -call 0x4e2da0
    cpu.esp -= 4;
    sub_4e2da0(app, cpu);
    if (cpu.terminate) return;
    // 004e0f7a  e861e80100             -call 0x4ff7e0
    cpu.esp -= 4;
    sub_4ff7e0(app, cpu);
    if (cpu.terminate) return;
    // 004e0f7f  833d6878560000         +cmp dword ptr [0x567868], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5666920) /* 0x567868 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e0f86  7404                   -je 0x4e0f8c
    if (cpu.flags.zf)
    {
        goto L_0x004e0f8c;
    }
    // 004e0f88  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004e0f8a  750b                   -jne 0x4e0f97
    if (!cpu.flags.zf)
    {
        goto L_0x004e0f97;
    }
L_0x004e0f8c:
    // 004e0f8c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004e0f8e  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004e0f91  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0f92  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0f93  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0f94  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0f95  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0f96  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e0f97:
    // 004e0f97  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 004e0f99  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004e0f9b  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004e0f9d  ff1568785600           -call dword ptr [0x567868]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666920) /* 0x567868 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e0fa3  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004e0fa5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e0fa7  7507                   -jne 0x4e0fb0
    if (!cpu.flags.zf)
    {
        goto L_0x004e0fb0;
    }
    // 004e0fa9  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004e0fab  e8e0080000             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
L_0x004e0fb0:
    // 004e0fb0  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004e0fb2  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004e0fb4  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004e0fb7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0fb8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0fb9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0fba  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0fbb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0fbc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e0fbd:
    // 004e0fbd  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004e0fc1  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004e0fc3  74c7                   -je 0x4e0f8c
    if (cpu.flags.zf)
    {
        goto L_0x004e0f8c;
    }
    // 004e0fc5  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004e0fc7  e8d41d0000             -call 0x4e2da0
    cpu.esp -= 4;
    sub_4e2da0(app, cpu);
    if (cpu.terminate) return;
    // 004e0fcc  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004e0fce  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004e0fd1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0fd2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0fd3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0fd4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0fd5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0fd6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_4e0fe0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e0fe0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e0fe1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e0fe2  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004e0fe4  8b0d0c445600           -mov ecx, dword ptr [0x56440c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5653516) /* 0x56440c */);
    // 004e0fea  891d0c445600           -mov dword ptr [0x56440c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5653516) /* 0x56440c */) = cpu.ebx;
    // 004e0ff0  e8cbfeffff             -call 0x4e0ec0
    cpu.esp -= 4;
    sub_4e0ec0(app, cpu);
    if (cpu.terminate) return;
    // 004e0ff5  890d0c445600           -mov dword ptr [0x56440c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5653516) /* 0x56440c */) = cpu.ecx;
    // 004e0ffb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0ffc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e0ffd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_4e1000(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e1000  83c010                 -add eax, 0x10
    (cpu.eax) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004e1003  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004e1005  7512                   -jne 0x4e1019
    if (!cpu.flags.zf)
    {
        goto L_0x004e1019;
    }
L_0x004e1007:
    // 004e1007  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004e100a  3b5004                 +cmp edx, dword ptr [eax + 4]
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
    // 004e100d  7ff8                   -jg 0x4e1007
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004e1007;
    }
    // 004e100f  6681385342             +cmp word ptr [eax], 0x4253
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.eax);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(16979 /*0x4253*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004e1014  7502                   -jne 0x4e1018
    if (!cpu.flags.zf)
    {
        goto L_0x004e1018;
    }
    // 004e1016  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004e1018:
    // 004e1018  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e1019:
    // 004e1019  8b4014                 -mov eax, dword ptr [eax + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 004e101c  3b5004                 +cmp edx, dword ptr [eax + 4]
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
    // 004e101f  7ff8                   -jg 0x4e1019
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004e1019;
    }
    // 004e1021  6681385342             +cmp word ptr [eax], 0x4253
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.eax);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(16979 /*0x4253*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004e1026  75f0                   -jne 0x4e1018
    if (!cpu.flags.zf)
    {
        goto L_0x004e1018;
    }
    // 004e1028  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004e102a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_4e1030(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e1030  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e1031  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e1032  83c010                 -add eax, 0x10
    (cpu.eax) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004e1035  4a                     -dec edx
    (cpu.edx)--;
    // 004e1036  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004e1038  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004e103a  7c1b                   -jl 0x4e1057
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004e1057;
    }
L_0x004e103c:
    // 004e103c  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004e103e  751b                   -jne 0x4e105b
    if (!cpu.flags.zf)
    {
        goto L_0x004e105b;
    }
L_0x004e1040:
    // 004e1040  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004e1043  8b7004                 -mov esi, dword ptr [eax + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004e1046  39f2                   +cmp edx, esi
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
    // 004e1048  7df6                   -jge 0x4e1040
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004e1040;
    }
    // 004e104a  6681385342             +cmp word ptr [eax], 0x4253
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.eax);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(16979 /*0x4253*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004e104f  7421                   -je 0x4e1072
    if (cpu.flags.zf)
    {
        goto L_0x004e1072;
    }
    // 004e1051  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004e1053  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004e1055  ebe9                   -jmp 0x4e1040
    goto L_0x004e1040;
L_0x004e1057:
    // 004e1057  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004e1059  ebe1                   -jmp 0x4e103c
    goto L_0x004e103c;
L_0x004e105b:
    // 004e105b  8b4014                 -mov eax, dword ptr [eax + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 004e105e  8b5804                 -mov ebx, dword ptr [eax + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004e1061  39da                   +cmp edx, ebx
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
    // 004e1063  7df6                   -jge 0x4e105b
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004e105b;
    }
    // 004e1065  6681385342             +cmp word ptr [eax], 0x4253
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.eax);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(16979 /*0x4253*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004e106a  7406                   -je 0x4e1072
    if (cpu.flags.zf)
    {
        goto L_0x004e1072;
    }
    // 004e106c  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004e106e  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004e1070  ebe9                   -jmp 0x4e105b
    goto L_0x004e105b;
L_0x004e1072:
    // 004e1072  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004e1074  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e1075  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e1076  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_4e1080(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e1080  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e1081  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e1082  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e1083  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004e1084  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004e1086  8b5908                 -mov ebx, dword ptr [ecx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004e1089  29cb                   -sub ebx, ecx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004e108b  8d73f0                 -lea esi, [ebx - 0x10]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(-16) /* -0x10 */);
    // 004e108e  8b7820                 -mov edi, dword ptr [eax + 0x20]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 004e1091  8b5824                 -mov ebx, dword ptr [eax + 0x24]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 004e1094  29fb                   -sub ebx, edi
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.edi));
    // 004e1096  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004e1098  83c010                 -add eax, 0x10
    (cpu.eax) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004e109b  01fb                   -add ebx, edi
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edi));
    // 004e109d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004e109f  39d9                   +cmp ecx, ebx
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
    // 004e10a1  762c                   -jbe 0x4e10cf
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004e10cf;
    }
L_0x004e10a3:
    // 004e10a3  8b5214                 -mov edx, dword ptr [edx + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */);
    // 004e10a6  39d1                   +cmp ecx, edx
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
    // 004e10a8  72f9                   -jb 0x4e10a3
    if (cpu.flags.cf)
    {
        goto L_0x004e10a3;
    }
    // 004e10aa  8b4210                 -mov eax, dword ptr [edx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
L_0x004e10ad:
    // 004e10ad  895114                 -mov dword ptr [ecx + 0x14], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 004e10b0  897104                 -mov dword ptr [ecx + 4], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 004e10b3  894110                 -mov dword ptr [ecx + 0x10], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004e10b6  894a10                 -mov dword ptr [edx + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 004e10b9  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 004e10bc  8a6103                 -mov ah, byte ptr [ecx + 3]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(3) /* 0x3 */);
    // 004e10bf  66c7014642             -mov word ptr [ecx], 0x4246
    app->getMemory<x86::reg16>(cpu.ecx) = 16966 /*0x4246*/;
    // 004e10c4  80cc40                 -or ah, 0x40
    cpu.ah |= x86::reg8(x86::sreg8(64 /*0x40*/));
    // 004e10c7  886103                 -mov byte ptr [ecx + 3], ah
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(3) /* 0x3 */) = cpu.ah;
    // 004e10ca  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e10cb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e10cc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e10cd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e10ce  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e10cf:
    // 004e10cf  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004e10d2  39c1                   +cmp ecx, eax
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
    // 004e10d4  77f9                   -ja 0x4e10cf
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004e10cf;
    }
    // 004e10d6  8b5014                 -mov edx, dword ptr [eax + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 004e10d9  ebd2                   -jmp 0x4e10ad
    goto L_0x004e10ad;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_4e10e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e10e0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e10e1  8b4214                 -mov eax, dword ptr [edx + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */);
    // 004e10e4  8b4a10                 -mov ecx, dword ptr [edx + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 004e10e7  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 004e10ea  894114                 -mov dword ptr [ecx + 0x14], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 004e10ed  8a6203                 -mov ah, byte ptr [edx + 3]
    cpu.ah = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(3) /* 0x3 */);
    // 004e10f0  66c7020000             -mov word ptr [edx], 0
    app->getMemory<x86::reg16>(cpu.edx) = 0 /*0x0*/;
    // 004e10f5  80e4bf                 -and ah, 0xbf
    cpu.ah &= x86::reg8(x86::sreg8(191 /*0xbf*/));
    // 004e10f8  886203                 -mov byte ptr [edx + 3], ah
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(3) /* 0x3 */) = cpu.ah;
    // 004e10fb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e10fc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4e1100(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e1100  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e1101  ba40000000             -mov edx, 0x40
    cpu.edx = 64 /*0x40*/;
    // 004e1106  b8c0f59e00             -mov eax, 0x9ef5c0
    cpu.eax = 10417600 /*0x9ef5c0*/;
    // 004e110b  e8fcf5ffff             -call 0x4e070c
    cpu.esp -= 4;
    sub_4e070c(app, cpu);
    if (cpu.terminate) return;
    // 004e1110  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004e1115  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e1116  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_4e1120(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e1120  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e1121  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004e1122  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004e1123  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004e1125  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004e1127  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 004e1129  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004e112d  66c7004d42             -mov word ptr [eax], 0x424d
    app->getMemory<x86::reg16>(cpu.eax) = 16973 /*0x424d*/;
    // 004e1132  66894802               -mov word ptr [eax + 2], cx
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(2) /* 0x2 */) = cpu.cx;
    // 004e1136  895804                 -mov dword ptr [eax + 4], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 004e1139  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004e113d  8d5510                 -lea edx, [ebp + 0x10]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004e1140  894508                 -mov dword ptr [ebp + 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004e1143  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004e1147  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004e1149  89450c                 -mov dword ptr [ebp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004e114c  f6c502                 +test ch, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 2 /*0x2*/));
    // 004e114f  753b                   -jne 0x4e118c
    if (!cpu.flags.zf)
    {
        goto L_0x004e118c;
    }
L_0x004e1151:
    // 004e1151  f6c504                 +test ch, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 4 /*0x4*/));
    // 004e1154  7415                   -je 0x4e116b
    if (cpu.flags.zf)
    {
        goto L_0x004e116b;
    }
    // 004e1156  8b1d9c215500           -mov ebx, dword ptr [0x55219c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5579164) /* 0x55219c */);
    // 004e115c  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004e115e  7437                   -je 0x4e1197
    if (cpu.flags.zf)
    {
        goto L_0x004e1197;
    }
    // 004e1160  a1a4215500             -mov eax, dword ptr [0x5521a4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5579172) /* 0x5521a4 */);
    // 004e1165  895a04                 -mov dword ptr [edx + 4], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.ebx;
L_0x004e1168:
    // 004e1168  894208                 -mov dword ptr [edx + 8], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = cpu.eax;
L_0x004e116b:
    // 004e116b  f6c508                 +test ch, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 8 /*0x8*/));
    // 004e116e  7407                   -je 0x4e1177
    if (cpu.flags.zf)
    {
        goto L_0x004e1177;
    }
    // 004e1170  c7420c00000000         -mov dword ptr [edx + 0xc], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
L_0x004e1177:
    // 004e1177  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 004e1179  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004e117b  7405                   -je 0x4e1182
    if (cpu.flags.zf)
    {
        goto L_0x004e1182;
    }
    // 004e117d  f6c501                 +test ch, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 1 /*0x1*/));
    // 004e1180  7524                   -jne 0x4e11a6
    if (!cpu.flags.zf)
    {
        goto L_0x004e11a6;
    }
L_0x004e1182:
    // 004e1182  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004e1184  29e8                   +sub eax, ebp
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
    // 004e1186  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e1187  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e1188  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e1189  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x004e118c:
    // 004e118c  b8444e4542             -mov eax, 0x42454e44
    cpu.eax = 1111838276 /*0x42454e44*/;
    // 004e1191  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 004e1193  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 004e1195  ebba                   -jmp 0x4e1151
    goto L_0x004e1151;
L_0x004e1197:
    // 004e1197  a190215500             -mov eax, dword ptr [0x552190]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */);
    // 004e119c  894204                 -mov dword ptr [edx + 4], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004e119f  a198215500             -mov eax, dword ptr [0x552198]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */);
    // 004e11a4  ebc2                   -jmp 0x4e1168
    goto L_0x004e1168;
L_0x004e11a6:
    // 004e11a6  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004e11a8  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x004e11a9:
    // 004e11a9  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004e11ab  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 004e11ad  3c00                   +cmp al, 0
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
    // 004e11af  7410                   -je 0x4e11c1
    if (cpu.flags.zf)
    {
        goto L_0x004e11c1;
    }
    // 004e11b1  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004e11b4  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004e11b7  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 004e11ba  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004e11bd  3c00                   +cmp al, 0
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
    // 004e11bf  75e8                   -jne 0x4e11a9
    if (!cpu.flags.zf)
    {
        goto L_0x004e11a9;
    }
L_0x004e11c1:
    // 004e11c1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e11c2  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004e11c4  49                     -dec ecx
    (cpu.ecx)--;
    // 004e11c5  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004e11c7  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 004e11c9  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 004e11cb  49                     -dec ecx
    (cpu.ecx)--;
    // 004e11cc  41                     -inc ecx
    (cpu.ecx)++;
    // 004e11cd  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004e11cf  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004e11d1  29e8                   -sub eax, ebp
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 004e11d3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e11d4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e11d5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e11d6  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4e11e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e11e0  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 004e11e3  8b0485c0f59e00         -mov eax, dword ptr [eax*4 + 0x9ef5c0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10417600) /* 0x9ef5c0 */ + cpu.eax * 4);
    // 004e11ea  8b4030                 -mov eax, dword ptr [eax + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(48) /* 0x30 */);
    // 004e11ed  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4e11f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e11f0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e11f1  83e20f                 -and edx, 0xf
    cpu.edx &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 004e11f4  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004e11f6  8b1495c0f59e00         -mov edx, dword ptr [edx*4 + 0x9ef5c0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10417600) /* 0x9ef5c0 */ + cpu.edx * 4);
    // 004e11fd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e11ff  7406                   -je 0x4e1207
    if (cpu.flags.zf)
    {
        goto L_0x004e1207;
    }
    // 004e1201  f6423501               +test byte ptr [edx + 0x35], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(53) /* 0x35 */) & 1 /*0x1*/));
    // 004e1205  7507                   -jne 0x4e120e
    if (!cpu.flags.zf)
    {
        goto L_0x004e120e;
    }
L_0x004e1207:
    // 004e1207  8b4230                 -mov eax, dword ptr [edx + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(48) /* 0x30 */);
    // 004e120a  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004e120c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e120d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e120e:
    // 004e120e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004e120f  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004e1211  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004e1213  49                     -dec ecx
    (cpu.ecx)--;
    // 004e1214  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004e1216  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 004e1218  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 004e121a  49                     -dec ecx
    (cpu.ecx)--;
    // 004e121b  41                     -inc ecx
    (cpu.ecx)++;
    // 004e121c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e121d  8b4230                 -mov eax, dword ptr [edx + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(48) /* 0x30 */);
    // 004e1220  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004e1222  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e1223  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_4e1230(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e1230  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e1231  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004e1232  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004e1233  81ec10010000           -sub esp, 0x110
    (cpu.esp) -= x86::reg32(x86::sreg32(272 /*0x110*/));
    // 004e1239  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004e123b  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004e123d  899c2404010000         -mov dword ptr [esp + 0x104], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */) = cpu.ebx;
    // 004e1244  8984240c010000         -mov dword ptr [esp + 0x10c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(268) /* 0x10c */) = cpu.eax;
    // 004e124b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e124d  7c05                   -jl 0x4e1254
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004e1254;
    }
    // 004e124f  83f810                 +cmp eax, 0x10
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e1252  7c47                   -jl 0x4e129b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004e129b;
    }
L_0x004e1254:
    // 004e1254  833d0c44560000         +cmp dword ptr [0x56440c], 0
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
    // 004e125b  7430                   -je 0x4e128d
    if (cpu.flags.zf)
    {
        goto L_0x004e128d;
    }
    // 004e125d  6a10                   -push 0x10
    app->getMemory<x86::reg32>(cpu.esp-4) = 16 /*0x10*/;
    cpu.esp -= 4;
    // 004e125f  bd44995400             -mov ebp, 0x549944
    cpu.ebp = 5544260 /*0x549944*/;
    // 004e1264  b854995400             -mov eax, 0x549954
    cpu.eax = 5544276 /*0x549954*/;
    // 004e1269  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e126a  ba1a010000             -mov edx, 0x11a
    cpu.edx = 282 /*0x11a*/;
    // 004e126f  892d90215500           -mov dword ptr [0x552190], ebp
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ebp;
    // 004e1275  6864995400             -push 0x549964
    app->getMemory<x86::reg32>(cpu.esp-4) = 5544292 /*0x549964*/;
    cpu.esp -= 4;
    // 004e127a  a394215500             -mov dword ptr [0x552194], eax
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.eax;
    // 004e127f  891598215500           -mov dword ptr [0x552198], edx
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.edx;
    // 004e1285  e886fdf1ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004e128a  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
L_0x004e128d:
    // 004e128d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004e128f  81c410010000           -add esp, 0x110
    (cpu.esp) += x86::reg32(x86::sreg32(272 /*0x110*/));
    // 004e1295  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e1296  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e1297  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e1298  c22000                 -ret 0x20
    cpu.esp += 4+32 /*0x20*/;
    return;
L_0x004e129b:
    // 004e129b  83bc242c01000000       +cmp dword ptr [esp + 0x12c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(300) /* 0x12c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e12a3  740a                   -je 0x4e12af
    if (cpu.flags.zf)
    {
        goto L_0x004e12af;
    }
    // 004e12a5  80cc02                 -or ah, 2
    cpu.ah |= x86::reg8(x86::sreg8(2 /*0x2*/));
    // 004e12a8  8984240c010000         -mov dword ptr [esp + 0x10c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(268) /* 0x10c */) = cpu.eax;
L_0x004e12af:
    // 004e12af  83bc243001000000       +cmp dword ptr [esp + 0x130], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(304) /* 0x130 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e12b7  7408                   -je 0x4e12c1
    if (cpu.flags.zf)
    {
        goto L_0x004e12c1;
    }
    // 004e12b9  808c240d01000004       -or byte ptr [esp + 0x10d], 4
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(269) /* 0x10d */) |= x86::reg8(x86::sreg8(4 /*0x4*/));
L_0x004e12c1:
    // 004e12c1  83bc243401000000       +cmp dword ptr [esp + 0x134], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(308) /* 0x134 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e12c9  7408                   -je 0x4e12d3
    if (cpu.flags.zf)
    {
        goto L_0x004e12d3;
    }
    // 004e12cb  808c240d01000001       -or byte ptr [esp + 0x10d], 1
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(269) /* 0x10d */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x004e12d3:
    // 004e12d3  8b842404010000         -mov eax, dword ptr [esp + 0x104]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 004e12da  8b942428010000         -mov edx, dword ptr [esp + 0x128]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(296) /* 0x128 */);
    // 004e12e1  83c050                 -add eax, 0x50
    (cpu.eax) += x86::reg32(x86::sreg32(80 /*0x50*/));
    // 004e12e4  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004e12e6  8b842424010000         -mov eax, dword ptr [esp + 0x124]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(292) /* 0x124 */);
    // 004e12ed  83c218                 -add edx, 0x18
    (cpu.edx) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 004e12f0  48                     -dec eax
    (cpu.eax)--;
    // 004e12f1  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004e12f3  f7d0                   -not eax
    cpu.eax = ~cpu.eax;
    // 004e12f5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004e12f6  21c2                   -and edx, eax
    cpu.edx &= x86::reg32(x86::sreg32(cpu.eax));
    // 004e12f8  68ac995400             -push 0x5499ac
    app->getMemory<x86::reg32>(cpu.esp-4) = 5544364 /*0x5499ac*/;
    cpu.esp -= 4;
    // 004e12fd  83ea10                 -sub edx, 0x10
    (cpu.edx) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004e1300  8b84240c010000         -mov eax, dword ptr [esp + 0x10c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(268) /* 0x10c */);
    // 004e1307  89942410010000         -mov dword ptr [esp + 0x110], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(272) /* 0x110 */) = cpu.edx;
    // 004e130e  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004e1310  8b942430010000         -mov edx, dword ptr [esp + 0x130]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(304) /* 0x130 */);
    // 004e1317  8d6810                 -lea ebp, [eax + 0x10]
    cpu.ebp = x86::reg32(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004e131a  83e918                 -sub ecx, 0x18
    (cpu.ecx) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 004e131d  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004e1321  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004e1323  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e1324  898c240c010000         -mov dword ptr [esp + 0x10c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(268) /* 0x10c */) = cpu.ecx;
    // 004e132b  e860e3ffff             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 004e1330  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004e1333  8b8c2408010000         -mov ecx, dword ptr [esp + 0x108]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(264) /* 0x108 */);
    // 004e133a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e133b  bb40000000             -mov ebx, 0x40
    cpu.ebx = 64 /*0x40*/;
    // 004e1340  8b842410010000         -mov eax, dword ptr [esp + 0x110]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(272) /* 0x110 */);
    // 004e1347  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004e1349  80cc80                 -or ah, 0x80
    cpu.ah |= x86::reg8(x86::sreg8(128 /*0x80*/));
    // 004e134c  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004e134e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e134f  8d54240c               -lea edx, [esp + 0xc]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004e1353  8b842410010000         -mov eax, dword ptr [esp + 0x110]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(272) /* 0x110 */);
    // 004e135a  e8c1fdffff             -call 0x4e1120
    cpu.esp -= 4;
    sub_4e1120(app, cpu);
    if (cpu.terminate) return;
    // 004e135f  8b9c2400010000         -mov ebx, dword ptr [esp + 0x100]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 004e1366  8b842404010000         -mov eax, dword ptr [esp + 0x104]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 004e136d  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e136e  8b942410010000         -mov edx, dword ptr [esp + 0x110]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(272) /* 0x110 */);
    // 004e1375  8b8c240c010000         -mov ecx, dword ptr [esp + 0x10c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(268) /* 0x10c */);
    // 004e137c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e137d  29cb                   -sub ebx, ecx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004e137f  8b8c2430010000         -mov ecx, dword ptr [esp + 0x130]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(304) /* 0x130 */);
    // 004e1386  8b842410010000         -mov eax, dword ptr [esp + 0x110]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(272) /* 0x110 */);
    // 004e138d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e138e  83eb10                 -sub ebx, 0x10
    (cpu.ebx) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004e1391  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004e1393  e888fdffff             -call 0x4e1120
    cpu.esp -= 4;
    sub_4e1120(app, cpu);
    if (cpu.terminate) return;
    // 004e1398  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004e1399  68b4995400             -push 0x5499b4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5544372 /*0x5499b4*/;
    cpu.esp -= 4;
    // 004e139e  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004e13a2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e13a3  e8e8e2ffff             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 004e13a8  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004e13ab  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004e13ad  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004e13af  8b9c240c010000         -mov ebx, dword ptr [esp + 0x10c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(268) /* 0x10c */);
    // 004e13b6  8b842410010000         -mov eax, dword ptr [esp + 0x110]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(272) /* 0x110 */);
    // 004e13bd  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e13be  660d1080               -or ax, 0x8010
    cpu.ax |= x86::reg16(x86::sreg16(32784 /*0x8010*/));
    // 004e13c2  8b8c2430010000         -mov ecx, dword ptr [esp + 0x130]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(304) /* 0x130 */);
    // 004e13c9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e13ca  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004e13cc  8b84240c010000         -mov eax, dword ptr [esp + 0x10c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(268) /* 0x10c */);
    // 004e13d3  e848fdffff             -call 0x4e1120
    cpu.esp -= 4;
    sub_4e1120(app, cpu);
    if (cpu.terminate) return;
    // 004e13d8  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004e13da  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 004e13dd  ba40000000             -mov edx, 0x40
    cpu.edx = 64 /*0x40*/;
    // 004e13e2  89fe                   -mov esi, edi
    cpu.esi = cpu.edi;
    // 004e13e4  892c85c0f59e00         -mov dword ptr [eax*4 + 0x9ef5c0], ebp
    app->getMemory<x86::reg32>(x86::reg32(10417600) /* 0x9ef5c0 */ + cpu.eax * 4) = cpu.ebp;
    // 004e13eb  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004e13ed  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 004e13ef  e818f3ffff             -call 0x4e070c
    cpu.esp -= 4;
    sub_4e070c(app, cpu);
    if (cpu.terminate) return;
    // 004e13f4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x004e13f5:
    // 004e13f5  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004e13f7  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 004e13f9  3c00                   +cmp al, 0
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
    // 004e13fb  7410                   -je 0x4e140d
    if (cpu.flags.zf)
    {
        goto L_0x004e140d;
    }
    // 004e13fd  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004e1400  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004e1403  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 004e1406  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004e1409  3c00                   +cmp al, 0
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
    // 004e140b  75e8                   -jne 0x4e13f5
    if (!cpu.flags.zf)
    {
        goto L_0x004e13f5;
    }
L_0x004e140d:
    // 004e140d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e140e  66c745105342           -mov word ptr [ebp + 0x10], 0x4253
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(16) /* 0x10 */) = 16979 /*0x4253*/;
    // 004e1414  8b842404010000         -mov eax, dword ptr [esp + 0x104]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 004e141b  c74514ffffff7f         -mov dword ptr [ebp + 0x14], 0x7fffffff
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */) = 2147483647 /*0x7fffffff*/;
    // 004e1422  894508                 -mov dword ptr [ebp + 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004e1425  8b842400010000         -mov eax, dword ptr [esp + 0x100]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 004e142c  89450c                 -mov dword ptr [ebp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004e142f  8d4510                 -lea eax, [ebp + 0x10]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004e1432  894520                 -mov dword ptr [ebp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 004e1435  894524                 -mov dword ptr [ebp + 0x24], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 004e1438  8b842420010000         -mov eax, dword ptr [esp + 0x120]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(288) /* 0x120 */);
    // 004e143f  894528                 -mov dword ptr [ebp + 0x28], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 004e1442  8b842424010000         -mov eax, dword ptr [esp + 0x124]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(292) /* 0x124 */);
    // 004e1449  89452c                 -mov dword ptr [ebp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 004e144c  8b842428010000         -mov eax, dword ptr [esp + 0x128]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(296) /* 0x128 */);
    // 004e1453  894530                 -mov dword ptr [ebp + 0x30], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(48) /* 0x30 */) = cpu.eax;
    // 004e1456  8b84240c010000         -mov eax, dword ptr [esp + 0x10c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(268) /* 0x10c */);
    // 004e145d  8b942408010000         -mov edx, dword ptr [esp + 0x108]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(264) /* 0x108 */);
    // 004e1464  894534                 -mov dword ptr [ebp + 0x34], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(52) /* 0x34 */) = cpu.eax;
    // 004e1467  8b84243c010000         -mov eax, dword ptr [esp + 0x13c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(316) /* 0x13c */);
    // 004e146e  8bb42438010000         -mov esi, dword ptr [esp + 0x138]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(312) /* 0x138 */);
    // 004e1475  89453c                 -mov dword ptr [ebp + 0x3c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(60) /* 0x3c */) = cpu.eax;
    // 004e1478  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004e147a  c7453800000000         -mov dword ptr [ebp + 0x38], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(56) /* 0x38 */) = 0 /*0x0*/;
    // 004e1481  e8fafbffff             -call 0x4e1080
    cpu.esp -= 4;
    sub_4e1080(app, cpu);
    if (cpu.terminate) return;
    // 004e1486  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004e1488  7408                   -je 0x4e1492
    if (cpu.flags.zf)
    {
        goto L_0x004e1492;
    }
    // 004e148a  e8519e0000             -call 0x4eb2e0
    cpu.esp -= 4;
    sub_4eb2e0(app, cpu);
    if (cpu.terminate) return;
    // 004e148f  894538                 -mov dword ptr [ebp + 0x38], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(56) /* 0x38 */) = cpu.eax;
L_0x004e1492:
    // 004e1492  8b842408010000         -mov eax, dword ptr [esp + 0x108]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(264) /* 0x108 */);
    // 004e1499  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004e149c  81c410010000           -add esp, 0x110
    (cpu.esp) += x86::reg32(x86::sreg32(272 /*0x110*/));
    // 004e14a2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e14a3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e14a4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e14a5  c22000                 -ret 0x20
    cpu.esp += 4+32 /*0x20*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_4e14b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e14b0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e14b1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e14b2  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 004e14b5  8b0c85c0f59e00         -mov ecx, dword ptr [eax*4 + 0x9ef5c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10417600) /* 0x9ef5c0 */ + cpu.eax * 4);
    // 004e14bc  8b5138                 -mov edx, dword ptr [ecx + 0x38]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(56) /* 0x38 */);
    // 004e14bf  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004e14c1  7514                   -jne 0x4e14d7
    if (!cpu.flags.zf)
    {
        goto L_0x004e14d7;
    }
    // 004e14c3  ba40000000             -mov edx, 0x40
    cpu.edx = 64 /*0x40*/;
    // 004e14c8  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004e14ca  e83df2ffff             -call 0x4e070c
    cpu.esp -= 4;
    sub_4e070c(app, cpu);
    if (cpu.terminate) return;
    // 004e14cf  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004e14d4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e14d5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e14d6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e14d7:
    // 004e14d7  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004e14d9  e8829e0000             -call 0x4eb360
    cpu.esp -= 4;
    sub_4eb360(app, cpu);
    if (cpu.terminate) return;
    // 004e14de  ba40000000             -mov edx, 0x40
    cpu.edx = 64 /*0x40*/;
    // 004e14e3  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004e14e5  e822f2ffff             -call 0x4e070c
    cpu.esp -= 4;
    sub_4e070c(app, cpu);
    if (cpu.terminate) return;
    // 004e14ea  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004e14ef  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e14f0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e14f1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_4e1500(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e1500  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e1501  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e1502  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004e1503  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 004e1508  8b0dc4f59e00           -mov ecx, dword ptr [0x9ef5c4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10417604) /* 0x9ef5c4 */);
    // 004e150e  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004e1513  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004e1515  7412                   -je 0x4e1529
    if (cpu.flags.zf)
    {
        goto L_0x004e1529;
    }
L_0x004e1517:
    // 004e1517  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004e151a  42                     -inc edx
    (cpu.edx)++;
    // 004e151b  83f840                 +cmp eax, 0x40
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(64 /*0x40*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e151e  7d09                   -jge 0x4e1529
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004e1529;
    }
    // 004e1520  83b8c0f59e0000         +cmp dword ptr [eax + 0x9ef5c0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(10417600) /* 0x9ef5c0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e1527  75ee                   -jne 0x4e1517
    if (!cpu.flags.zf)
    {
        goto L_0x004e1517;
    }
L_0x004e1529:
    // 004e1529  833d0c44560000         +cmp dword ptr [0x56440c], 0
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
    // 004e1530  7405                   -je 0x4e1537
    if (cpu.flags.zf)
    {
        goto L_0x004e1537;
    }
    // 004e1532  83fa10                 +cmp edx, 0x10
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
    // 004e1535  7d06                   -jge 0x4e153d
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004e153d;
    }
L_0x004e1537:
    // 004e1537  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004e1539  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e153a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e153b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e153c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e153d:
    // 004e153d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004e153e  bf44995400             -mov edi, 0x549944
    cpu.edi = 5544260 /*0x549944*/;
    // 004e1543  6a10                   -push 0x10
    app->getMemory<x86::reg32>(cpu.esp-4) = 16 /*0x10*/;
    cpu.esp -= 4;
    // 004e1545  bdbc995400             -mov ebp, 0x5499bc
    cpu.ebp = 5544380 /*0x5499bc*/;
    // 004e154a  b8ae010000             -mov eax, 0x1ae
    cpu.eax = 430 /*0x1ae*/;
    // 004e154f  68cc995400             -push 0x5499cc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5544396 /*0x5499cc*/;
    cpu.esp -= 4;
    // 004e1554  893d90215500           -mov dword ptr [0x552190], edi
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edi;
    // 004e155a  892d94215500           -mov dword ptr [0x552194], ebp
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebp;
    // 004e1560  a398215500             -mov dword ptr [0x552198], eax
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.eax;
    // 004e1565  e8a6faf1ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004e156a  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004e156d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e156e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004e1570  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e1571  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e1572  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e1573  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_4e1580(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e1580  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e1581  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e1582  a1f4435600             -mov eax, dword ptr [0x5643f4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653492) /* 0x5643f4 */);
    // 004e1587  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 004e158a  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004e158c  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004e158e  8b0485c0f59e00         -mov eax, dword ptr [eax*4 + 0x9ef5c0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10417600) /* 0x9ef5c0 */ + cpu.eax * 4);
    // 004e1595  e896faffff             -call 0x4e1030
    cpu.esp -= 4;
    sub_4e1030(app, cpu);
    if (cpu.terminate) return;
    // 004e159a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e159c  7403                   -je 0x4e15a1
    if (cpu.flags.zf)
    {
        goto L_0x004e15a1;
    }
    // 004e159e  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
L_0x004e15a1:
    // 004e15a1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e15a2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e15a3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_4e15b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e15b0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e15b1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e15b2  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 004e15b5  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004e15b7  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004e15b9  8b0485c0f59e00         -mov eax, dword ptr [eax*4 + 0x9ef5c0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10417600) /* 0x9ef5c0 */ + cpu.eax * 4);
    // 004e15c0  e86bfaffff             -call 0x4e1030
    cpu.esp -= 4;
    sub_4e1030(app, cpu);
    if (cpu.terminate) return;
    // 004e15c5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e15c7  7403                   -je 0x4e15cc
    if (cpu.flags.zf)
    {
        goto L_0x004e15cc;
    }
    // 004e15c9  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
L_0x004e15cc:
    // 004e15cc  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e15cd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e15ce  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4e15d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e15d0  8b40f4                 -mov eax, dword ptr [eax - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-12) /* -0xc */);
    // 004e15d3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_4e15e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e15e0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e15e1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e15e2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e15e3  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004e15e5  8d5af0                 -lea ebx, [edx - 0x10]
    cpu.ebx = x86::reg32(cpu.edx + x86::reg32(-16) /* -0x10 */);
    // 004e15e8  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004e15ea  668b4b02               -mov cx, word ptr [ebx + 2]
    cpu.cx = app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(2) /* 0x2 */);
    // 004e15ee  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004e15f0  f6c501                 +test ch, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 1 /*0x1*/));
    // 004e15f3  7504                   -jne 0x4e15f9
    if (!cpu.flags.zf)
    {
        goto L_0x004e15f9;
    }
    // 004e15f5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e15f6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e15f7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e15f8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e15f9:
    // 004e15f9  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004e15fb  e8e0fbffff             -call 0x4e11e0
    cpu.esp -= 4;
    sub_4e11e0(app, cpu);
    if (cpu.terminate) return;
    // 004e1600  035304                 -add edx, dword ptr [ebx + 4]
    (cpu.edx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */)));
    // 004e1603  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004e1605  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e1606  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e1607  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e1608  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4e1610(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e1610  668b40f2               -mov ax, word ptr [eax - 0xe]
    cpu.ax = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(-14) /* -0xe */);
    // 004e1614  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004e1619  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_4e1620(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e1620  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e1621  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e1622  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004e1623  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004e1624  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004e1627  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004e162b  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 004e162d  895c2410               -mov dword ptr [esp + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 004e1631  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004e1633  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 004e1636  8b3c85c0f59e00         -mov edi, dword ptr [eax*4 + 0x9ef5c0]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(10417600) /* 0x9ef5c0 */ + cpu.eax * 4);
    // 004e163d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004e163f  8b4f38                 -mov ecx, dword ptr [edi + 0x38]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(56) /* 0x38 */);
    // 004e1642  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004e1646  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004e1648  0f851d010000           -jne 0x4e176b
    if (!cpu.flags.zf)
    {
        goto L_0x004e176b;
    }
L_0x004e164e:
    // 004e164e  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 004e1650  83fd08                 +cmp ebp, 8
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e1653  7d0d                   -jge 0x4e1662
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004e1662;
    }
    // 004e1655  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004e1657  0f8c1a010000           -jl 0x4e1777
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004e1777;
    }
    // 004e165d  b908000000             -mov ecx, 8
    cpu.ecx = 8 /*0x8*/;
L_0x004e1662:
    // 004e1662  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004e1666  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004e166a  e881fbffff             -call 0x4e11f0
    cpu.esp -= 4;
    sub_4e11f0(app, cpu);
    if (cpu.terminate) return;
    // 004e166f  8b5f28                 -mov ebx, dword ptr [edi + 0x28]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(40) /* 0x28 */);
    // 004e1672  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004e1674  4b                     -dec ebx
    (cpu.ebx)--;
    // 004e1675  83c010                 -add eax, 0x10
    (cpu.eax) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004e1678  895c2408               -mov dword ptr [esp + 8], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 004e167c  8d0c03                 -lea ecx, [ebx + eax]
    cpu.ecx = x86::reg32(cpu.ebx + cpu.eax * 1);
    // 004e167f  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004e1681  f7d0                   -not eax
    cpu.eax = ~cpu.eax;
    // 004e1683  21c8                   -and eax, ecx
    cpu.eax &= x86::reg32(x86::sreg32(cpu.ecx));
    // 004e1685  8d48f0                 -lea ecx, [eax - 0x10]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(-16) /* -0x10 */);
    // 004e1688  8b5c2410               -mov ebx, dword ptr [esp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004e168c  8a642410               -mov ah, byte ptr [esp + 0x10]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004e1690  83e310                 -and ebx, 0x10
    cpu.ebx &= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004e1693  f6c420                 +test ah, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 32 /*0x20*/));
    // 004e1696  0f843d010000           -je 0x4e17d9
    if (cpu.flags.zf)
    {
        goto L_0x004e17d9;
    }
    // 004e169c  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004e169e  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004e16a0  e88bf9ffff             -call 0x4e1030
    cpu.esp -= 4;
    sub_4e1030(app, cpu);
    if (cpu.terminate) return;
L_0x004e16a5:
    // 004e16a5  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004e16a7  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004e16a9  0f8474010000           -je 0x4e1823
    if (cpu.flags.zf)
    {
        goto L_0x004e1823;
    }
    // 004e16af  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004e16b1  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004e16b3  e828faffff             -call 0x4e10e0
    cpu.esp -= 4;
    sub_4e10e0(app, cpu);
    if (cpu.terminate) return;
    // 004e16b8  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004e16bb  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004e16bd  83f840                 +cmp eax, 0x40
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(64 /*0x40*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e16c0  7e4c                   -jle 0x4e170e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004e170e;
    }
    // 004e16c2  f644241010             +test byte ptr [esp + 0x10], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */) & 16 /*0x10*/));
    // 004e16c7  0f841a010000           -je 0x4e17e7
    if (cpu.flags.zf)
    {
        goto L_0x004e17e7;
    }
    // 004e16cd  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004e16d1  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 004e16d3  21c8                   -and eax, ecx
    cpu.eax &= x86::reg32(x86::sreg32(cpu.ecx));
    // 004e16d5  893424                 -mov dword ptr [esp], esi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.esi;
    // 004e16d8  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004e16da  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004e16dd  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004e16e0  89700c                 -mov dword ptr [eax + 0xc], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.esi;
    // 004e16e3  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004e16e6  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004e16e9  894608                 -mov dword ptr [esi + 8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004e16ec  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004e16ef  89460c                 -mov dword ptr [esi + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004e16f2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e16f3  8b580c                 -mov ebx, dword ptr [eax + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004e16f6  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e16f7  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004e16f9  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004e16fb  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004e16fd  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004e16ff  e81cfaffff             -call 0x4e1120
    cpu.esp -= 4;
    sub_4e1120(app, cpu);
    if (cpu.terminate) return;
    // 004e1704  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 004e1707  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004e1709  e872f9ffff             -call 0x4e1080
    cpu.esp -= 4;
    sub_4e1080(app, cpu);
    if (cpu.terminate) return;
L_0x004e170e:
    // 004e170e  8b4734                 -mov eax, dword ptr [edi + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(52) /* 0x34 */);
    // 004e1711  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004e1715  2500070000             -and eax, 0x700
    cpu.eax &= x86::reg32(x86::sreg32(1792 /*0x700*/));
    // 004e171a  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 004e171c  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004e1720  89542410               -mov dword ptr [esp + 0x10], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 004e1724  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004e1726  7505                   -jne 0x4e172d
    if (!cpu.flags.zf)
    {
        goto L_0x004e172d;
    }
    // 004e1728  80642411fe             -and byte ptr [esp + 0x11], 0xfe
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(17) /* 0x11 */) &= x86::reg8(x86::sreg8(254 /*0xfe*/));
L_0x004e172d:
    // 004e172d  8b5e08                 -mov ebx, dword ptr [esi + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004e1730  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e1731  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004e1734  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004e1738  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e1739  8b4f30                 -mov ecx, dword ptr [edi + 0x30]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(48) /* 0x30 */);
    // 004e173c  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 004e173e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e173f  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004e1741  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004e1745  83c610                 -add esi, 0x10
    (cpu.esi) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004e1748  e8d3f9ffff             -call 0x4e1120
    cpu.esp -= 4;
    sub_4e1120(app, cpu);
    if (cpu.terminate) return;
    // 004e174d  89742404               -mov dword ptr [esp + 4], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.esi;
L_0x004e1751:
    // 004e1751  8b4f38                 -mov ecx, dword ptr [edi + 0x38]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(56) /* 0x38 */);
    // 004e1754  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004e1756  7407                   -je 0x4e175f
    if (cpu.flags.zf)
    {
        goto L_0x004e175f;
    }
    // 004e1758  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e1759  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004e175f:
    // 004e175f  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004e1763  83c414                 +add esp, 0x14
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(20 /*0x14*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004e1766  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e1767  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e1768  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e1769  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e176a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e176b:
    // 004e176b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e176c  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e1772  e9d7feffff             -jmp 0x4e164e
    goto L_0x004e164e;
L_0x004e1777:
    // 004e1777  8b7738                 -mov esi, dword ptr [edi + 0x38]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(56) /* 0x38 */);
    // 004e177a  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004e177c  7407                   -je 0x4e1785
    if (cpu.flags.zf)
    {
        goto L_0x004e1785;
    }
    // 004e177e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e177f  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004e1785:
    // 004e1785  833d0c44560000         +cmp dword ptr [0x56440c], 0
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
    // 004e178c  7441                   -je 0x4e17cf
    if (cpu.flags.zf)
    {
        goto L_0x004e17cf;
    }
    // 004e178e  b944995400             -mov ecx, 0x549944
    cpu.ecx = 5544260 /*0x549944*/;
    // 004e1793  bb009a5400             -mov ebx, 0x549a00
    cpu.ebx = 5544448 /*0x549a00*/;
    // 004e1798  beae020000             -mov esi, 0x2ae
    cpu.esi = 686 /*0x2ae*/;
    // 004e179d  8b7c2410               -mov edi, dword ptr [esp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004e17a1  890d90215500           -mov dword ptr [0x552190], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ecx;
    // 004e17a7  891d94215500           -mov dword ptr [0x552194], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebx;
    // 004e17ad  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004e17ae  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004e17b0  893598215500           -mov dword ptr [0x552198], esi
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.esi;
    // 004e17b6  e8f5fdffff             -call 0x4e15b0
    cpu.esp -= 4;
    sub_4e15b0(app, cpu);
    if (cpu.terminate) return;
    // 004e17bb  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e17bc  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004e17bd  8b6c2418               -mov ebp, dword ptr [esp + 0x18]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004e17c1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004e17c2  68109a5400             -push 0x549a10
    app->getMemory<x86::reg32>(cpu.esp-4) = 5544464 /*0x549a10*/;
    cpu.esp -= 4;
    // 004e17c7  e844f8f1ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004e17cc  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
L_0x004e17cf:
    // 004e17cf  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004e17d1  83c414                 +add esp, 0x14
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(20 /*0x14*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004e17d4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e17d5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e17d6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e17d7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e17d8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e17d9:
    // 004e17d9  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004e17db  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004e17dd  e81ef8ffff             -call 0x4e1000
    cpu.esp -= 4;
    sub_4e1000(app, cpu);
    if (cpu.terminate) return;
    // 004e17e2  e9befeffff             -jmp 0x4e16a5
    goto L_0x004e16a5;
L_0x004e17e7:
    // 004e17e7  8d4610                 -lea eax, [esi + 0x10]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004e17ea  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004e17ec  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004e17ef  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004e17f2  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 004e17f5  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 004e17f8  8b4e08                 -mov ecx, dword ptr [esi + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004e17fb  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e17fc  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e17fd  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004e17ff  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004e1801  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004e1803  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004e1807  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 004e1809  e812f9ffff             -call 0x4e1120
    cpu.esp -= 4;
    sub_4e1120(app, cpu);
    if (cpu.terminate) return;
    // 004e180e  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 004e1811  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004e1813  e868f8ffff             -call 0x4e1080
    cpu.esp -= 4;
    sub_4e1080(app, cpu);
    if (cpu.terminate) return;
    // 004e1818  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004e181b  894608                 -mov dword ptr [esi + 8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004e181e  e9ebfeffff             -jmp 0x4e170e
    goto L_0x004e170e;
L_0x004e1823:
    // 004e1823  833d0c44560000         +cmp dword ptr [0x56440c], 0
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
    // 004e182a  0f8421ffffff           -je 0x4e1751
    if (cpu.flags.zf)
    {
        goto L_0x004e1751;
    }
    // 004e1830  8b5738                 -mov edx, dword ptr [edi + 0x38]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(56) /* 0x38 */);
    // 004e1833  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004e1835  7407                   -je 0x4e183e
    if (cpu.flags.zf)
    {
        goto L_0x004e183e;
    }
    // 004e1837  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e1838  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004e183e:
    // 004e183e  bb44995400             -mov ebx, 0x549944
    cpu.ebx = 5544260 /*0x549944*/;
    // 004e1843  be009a5400             -mov esi, 0x549a00
    cpu.esi = 5544448 /*0x549a00*/;
    // 004e1848  bfed020000             -mov edi, 0x2ed
    cpu.edi = 749 /*0x2ed*/;
    // 004e184d  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004e1851  891d90215500           -mov dword ptr [0x552190], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ebx;
    // 004e1857  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e1858  893594215500           -mov dword ptr [0x552194], esi
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.esi;
    // 004e185e  893d98215500           -mov dword ptr [0x552198], edi
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.edi;
    // 004e1864  e847fdffff             -call 0x4e15b0
    cpu.esp -= 4;
    sub_4e15b0(app, cpu);
    if (cpu.terminate) return;
    // 004e1869  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e186a  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004e186b  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004e186f  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e1870  686c9a5400             -push 0x549a6c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5544556 /*0x549a6c*/;
    cpu.esp -= 4;
    // 004e1875  e896f7f1ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004e187a  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004e187d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004e187f  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004e1882  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e1883  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e1884  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e1885  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e1886  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_4e1890(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e1890  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e1891  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e1892  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e1893  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e1894  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004e1895  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004e1896  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004e1898  bd01000000             -mov ebp, 1
    cpu.ebp = 1 /*0x1*/;
    // 004e189d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e189f  0f84e1000000           -je 0x4e1986
    if (cpu.flags.zf)
    {
        goto L_0x004e1986;
    }
    // 004e18a5  668b40f2               -mov ax, word ptr [eax - 0xe]
    cpu.ax = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(-14) /* -0xe */);
    // 004e18a9  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 004e18ab  240f                   -and al, 0xf
    cpu.al &= x86::reg8(x86::sreg8(15 /*0xf*/));
    // 004e18ad  8d56f0                 -lea edx, [esi - 0x10]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(-16) /* -0x10 */);
    // 004e18b0  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004e18b5  668b0a                 -mov cx, word ptr [edx]
    cpu.cx = app->getMemory<x86::reg16>(cpu.edx);
    // 004e18b8  8b1c85c0f59e00         -mov ebx, dword ptr [eax*4 + 0x9ef5c0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10417600) /* 0x9ef5c0 */ + cpu.eax * 4);
    // 004e18bf  6681f94d42             +cmp cx, 0x424d
    {
        x86::reg16 tmp1 = cpu.cx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(16973 /*0x424d*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004e18c4  7458                   -je 0x4e191e
    if (cpu.flags.zf)
    {
        goto L_0x004e191e;
    }
    // 004e18c6  833d0c44560000         +cmp dword ptr [0x56440c], 0
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
    // 004e18cd  7446                   -je 0x4e1915
    if (cpu.flags.zf)
    {
        goto L_0x004e1915;
    }
    // 004e18cf  b844995400             -mov eax, 0x549944
    cpu.eax = 5544260 /*0x549944*/;
    // 004e18d4  b9b89a5400             -mov ecx, 0x549ab8
    cpu.ecx = 5544632 /*0x549ab8*/;
    // 004e18d9  bb33030000             -mov ebx, 0x333
    cpu.ebx = 819 /*0x333*/;
    // 004e18de  a390215500             -mov dword ptr [0x552190], eax
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.eax;
    // 004e18e3  890d94215500           -mov dword ptr [0x552194], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ecx;
    // 004e18e9  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 004e18ee  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004e18f0  891d98215500           -mov dword ptr [0x552198], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ebx;
    // 004e18f6  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004e18f8  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 004e18fa  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004e18fc  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 004e1903  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 004e1905  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e1906  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e1907  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e1908  68c49a5400             -push 0x549ac4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5544644 /*0x549ac4*/;
    cpu.esp -= 4;
    // 004e190d  e8fef6f1ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004e1912  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
L_0x004e1915:
    // 004e1915  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004e1917  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e1918  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e1919  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e191a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e191b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e191c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e191d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e191e:
    // 004e191e  8b5338                 -mov edx, dword ptr [ebx + 0x38]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(56) /* 0x38 */);
    // 004e1921  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004e1923  7407                   -je 0x4e192c
    if (cpu.flags.zf)
    {
        goto L_0x004e192c;
    }
    // 004e1925  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e1926  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004e192c:
    // 004e192c  8d4ef0                 -lea ecx, [esi - 0x10]
    cpu.ecx = x86::reg32(cpu.esi + x86::reg32(-16) /* -0x10 */);
    // 004e192f  8b790c                 -mov edi, dword ptr [ecx + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 004e1932  8a6703                 -mov ah, byte ptr [edi + 3]
    cpu.ah = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(3) /* 0x3 */);
    // 004e1935  8b7108                 -mov esi, dword ptr [ecx + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004e1938  f6c440                 +test ah, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 64 /*0x40*/));
    // 004e193b  7417                   -je 0x4e1954
    if (cpu.flags.zf)
    {
        goto L_0x004e1954;
    }
    // 004e193d  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004e193f  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004e1941  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 004e1943  e898f7ffff             -call 0x4e10e0
    cpu.esp -= 4;
    sub_4e10e0(app, cpu);
    if (cpu.terminate) return;
    // 004e1948  8b7f0c                 -mov edi, dword ptr [edi + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */);
    // 004e194b  897108                 -mov dword ptr [ecx + 8], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.esi;
    // 004e194e  894f08                 -mov dword ptr [edi + 8], ecx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 004e1951  894e0c                 -mov dword ptr [esi + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.ecx;
L_0x004e1954:
    // 004e1954  f6460340               +test byte ptr [esi + 3], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(3) /* 0x3 */) & 64 /*0x40*/));
    // 004e1958  7415                   -je 0x4e196f
    if (cpu.flags.zf)
    {
        goto L_0x004e196f;
    }
    // 004e195a  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004e195c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004e195e  e87df7ffff             -call 0x4e10e0
    cpu.esp -= 4;
    sub_4e10e0(app, cpu);
    if (cpu.terminate) return;
    // 004e1963  8b7608                 -mov esi, dword ptr [esi + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004e1966  89790c                 -mov dword ptr [ecx + 0xc], edi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.edi;
    // 004e1969  897108                 -mov dword ptr [ecx + 8], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.esi;
    // 004e196c  894e0c                 -mov dword ptr [esi + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.ecx;
L_0x004e196f:
    // 004e196f  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004e1971  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004e1973  e808f7ffff             -call 0x4e1080
    cpu.esp -= 4;
    sub_4e1080(app, cpu);
    if (cpu.terminate) return;
    // 004e1978  8b7338                 -mov esi, dword ptr [ebx + 0x38]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(56) /* 0x38 */);
    // 004e197b  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004e197d  7407                   -je 0x4e1986
    if (cpu.flags.zf)
    {
        goto L_0x004e1986;
    }
    // 004e197f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e1980  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004e1986:
    // 004e1986  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004e1988  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e1989  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e198a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e198b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e198c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e198d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e198e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4e1990(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e1990  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e1991  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 004e1994  8b1485c0f59e00         -mov edx, dword ptr [eax*4 + 0x9ef5c0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10417600) /* 0x9ef5c0 */ + cpu.eax * 4);
    // 004e199b  8b5208                 -mov edx, dword ptr [edx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004e199e  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004e19a0  741e                   -je 0x4e19c0
    if (cpu.flags.zf)
    {
        goto L_0x004e19c0;
    }
L_0x004e19a2:
    // 004e19a2  8d4210                 -lea eax, [edx + 0x10]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 004e19a5  e8e6feffff             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
    // 004e19aa  8b5208                 -mov edx, dword ptr [edx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004e19ad  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004e19af  75f1                   -jne 0x4e19a2
    if (!cpu.flags.zf)
    {
        goto L_0x004e19a2;
    }
    // 004e19b1  8d8000000000           -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 004e19b7  8d9200000000           -lea edx, [edx]
    cpu.edx = x86::reg32(cpu.edx);
    // 004e19bd  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x004e19c0:
    // 004e19c0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e19c1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_4e19d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e19d0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e19d1  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004e19d5  8b1df4435600           -mov ebx, dword ptr [0x5643f4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5653492) /* 0x5643f4 */);
    // 004e19db  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004e19dd  e83efcffff             -call 0x4e1620
    cpu.esp -= 4;
    sub_4e1620(app, cpu);
    if (cpu.terminate) return;
    // 004e19e2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e19e3  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void Application::sub_4e19f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e19f0  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004e19f4  e897feffff             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
    // 004e19f9  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_4e1a00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e1a00  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004e1a04  e85be10100             -call 0x4ffb64
    cpu.esp -= 4;
    sub_4ffb64(app, cpu);
    if (cpu.terminate) return;
    // 004e1a09  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_4e1a0c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e1a0c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e1a0d  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004e1a11  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004e1a15  8b5c2410               -mov ebx, dword ptr [esp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004e1a19  e8c2e20100             -call 0x4ffce0
    cpu.esp -= 4;
    sub_4ffce0(app, cpu);
    if (cpu.terminate) return;
    // 004e1a1e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e1a1f  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4e1a24(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e1a24  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004e1a28  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004e1a2c  e833ee0100             -call 0x500864
    cpu.esp -= 4;
    sub_500864(app, cpu);
    if (cpu.terminate) return;
    // 004e1a31  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::sub_4e1a34(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e1a34  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004e1a37  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004e1a3b  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004e1a3e  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004e1a40  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e1a41  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004e1a45  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e1a46  e875dcffff             -call 0x4df6c0
    cpu.esp -= 4;
    sub_4df6c0(app, cpu);
    if (cpu.terminate) return;
    // 004e1a4b  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004e1a4e  b8726f5600             -mov eax, 0x566f72
    cpu.eax = 5664626 /*0x566f72*/;
    // 004e1a53  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004e1a55  e816630100             -call 0x4f7d70
    cpu.esp -= 4;
    sub_4f7d70(app, cpu);
    if (cpu.terminate) return;
    // 004e1a5a  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 004e1a5d  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004e1a60  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4e1a64(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e1a64  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004e1a67  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004e1a6b  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004e1a6e  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004e1a70  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e1a71  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004e1a75  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e1a76  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004e1a78  e873eeffff             -call 0x4e08f0
    cpu.esp -= 4;
    sub_4e08f0(app, cpu);
    if (cpu.terminate) return;
    // 004e1a7d  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004e1a80  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 004e1a83  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004e1a86  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4e1a88(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e1a88  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e1a89  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e1a8a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004e1a8b  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004e1a8e  b8726f5600             -mov eax, 0x566f72
    cpu.eax = 5664626 /*0x566f72*/;
    // 004e1a93  ba109b5400             -mov edx, 0x549b10
    cpu.edx = 5544720 /*0x549b10*/;
    // 004e1a98  b9209b5400             -mov ecx, 0x549b20
    cpu.ecx = 5544736 /*0x549b20*/;
    // 004e1a9d  e8ce620100             -call 0x4f7d70
    cpu.esp -= 4;
    sub_4f7d70(app, cpu);
    if (cpu.terminate) return;
    // 004e1aa2  8d442418               -lea eax, [esp + 0x18]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004e1aa6  bb92000000             -mov ebx, 0x92
    cpu.ebx = 146 /*0x92*/;
    // 004e1aab  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004e1aae  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004e1ab0  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004e1ab2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e1ab3  8b742418               -mov esi, dword ptr [esp + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004e1ab7  891590215500           -mov dword ptr [0x552190], edx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edx;
    // 004e1abd  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e1abe  890d94215500           -mov dword ptr [0x552194], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ecx;
    // 004e1ac4  891d98215500           -mov dword ptr [0x552198], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ebx;
    // 004e1aca  e841f5f1ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004e1acf  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004e1ad2  893c24                 -mov dword ptr [esp], edi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edi;
    // 004e1ad5  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004e1ad8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e1ad9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e1ada  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e1adb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4e1adc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e1adc  ff15089ba000           -call dword ptr [0xa09b08]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10525448) /* 0xa09b08 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e1ae2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4e1ae4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e1ae4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e1ae5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e1ae6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004e1ae7  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004e1ae8  83ec30                 -sub esp, 0x30
    (cpu.esp) -= x86::reg32(x86::sreg32(48 /*0x30*/));
    // 004e1aeb  8b6c2448               -mov ebp, dword ptr [esp + 0x48]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 004e1aef  8b7c244c               -mov edi, dword ptr [esp + 0x4c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 004e1af3  8b5c2458               -mov ebx, dword ptr [esp + 0x58]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */);
    // 004e1af7  8b542464               -mov edx, dword ptr [esp + 0x64]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */);
    // 004e1afb  83ff02                 +cmp edi, 2
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e1afe  0f8ff4000000           -jg 0x4e1bf8
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004e1bf8;
    }
L_0x004e1b04:
    // 004e1b04  83fa01                 +cmp edx, 1
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
    // 004e1b07  742e                   -je 0x4e1b37
    if (cpu.flags.zf)
    {
        goto L_0x004e1b37;
    }
    // 004e1b09  b9109b5400             -mov ecx, 0x549b10
    cpu.ecx = 5544720 /*0x549b10*/;
    // 004e1b0e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e1b0f  be349b5400             -mov esi, 0x549b34
    cpu.esi = 5544756 /*0x549b34*/;
    // 004e1b14  b8b0000000             -mov eax, 0xb0
    cpu.eax = 176 /*0xb0*/;
    // 004e1b19  68809b5400             -push 0x549b80
    app->getMemory<x86::reg32>(cpu.esp-4) = 5544832 /*0x549b80*/;
    cpu.esp -= 4;
    // 004e1b1e  890d90215500           -mov dword ptr [0x552190], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ecx;
    // 004e1b24  893594215500           -mov dword ptr [0x552194], esi
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.esi;
    // 004e1b2a  a398215500             -mov dword ptr [0x552198], eax
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.eax;
    // 004e1b2f  e8dcf4f1ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004e1b34  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x004e1b37:
    // 004e1b37  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 004e1b39  8d04dd00000000         -lea eax, [ebx*8]
    cpu.eax = x86::reg32(cpu.ebx * 8);
    // 004e1b40  6800300000             -push 0x3000
    app->getMemory<x86::reg32>(cpu.esp-4) = 12288 /*0x3000*/;
    cpu.esp -= 4;
    // 004e1b45  05204e0000             -add eax, 0x4e20
    (cpu.eax) += x86::reg32(x86::sreg32(20000 /*0x4e20*/));
    // 004e1b4a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e1b4b  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004e1b4d  2eff1524465300         -call dword ptr cs:[0x534624]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457444) /* 0x534624 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e1b54  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004e1b56  0fafd7                 -imul edx, edi
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.edi)));
    // 004e1b59  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004e1b5b  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004e1b5d  0f85c8000000           -jne 0x4e1c2b
    if (!cpu.flags.zf)
    {
        goto L_0x004e1c2b;
    }
    // 004e1b63  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e1b64  8b442448               -mov eax, dword ptr [esp + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 004e1b68  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e1b69  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e1b6a  e831ed0100             -call 0x5008a0
    cpu.esp -= 4;
    sub_5008a0(app, cpu);
    if (cpu.terminate) return;
L_0x004e1b6f:
    // 004e1b6f  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
L_0x004e1b72:
    // 004e1b72  83ff01                 +cmp edi, 1
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e1b75  7531                   -jne 0x4e1ba8
    if (!cpu.flags.zf)
    {
        goto L_0x004e1ba8;
    }
    // 004e1b77  8d4bff                 -lea ecx, [ebx - 1]
    cpu.ecx = x86::reg32(cpu.ebx + x86::reg32(-1) /* -0x1 */);
    // 004e1b7a  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004e1b7c  7c2a                   -jl 0x4e1ba8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004e1ba8;
    }
    // 004e1b7e  8d14cd00000000         -lea edx, [ecx*8]
    cpu.edx = x86::reg32(cpu.ecx * 8);
    // 004e1b85  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 004e1b8c  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 004e1b8e  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
L_0x004e1b90:
    // 004e1b90  d900                   -fld dword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax)));
    // 004e1b92  83e804                 -sub eax, 4
    (cpu.eax) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004e1b95  49                     -dec ecx
    (cpu.ecx)--;
    // 004e1b96  d95a04                 -fstp dword ptr [edx + 4]
    app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004e1b99  83ea08                 -sub edx, 8
    (cpu.edx) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004e1b9c  8b7804                 -mov edi, dword ptr [eax + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004e1b9f  897a08                 -mov dword ptr [edx + 8], edi
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = cpu.edi;
    // 004e1ba2  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004e1ba4  7dea                   -jge 0x4e1b90
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004e1b90;
    }
    // 004e1ba6  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x004e1ba8:
    // 004e1ba8  8b542454               -mov edx, dword ptr [esp + 0x54]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */);
    // 004e1bac  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004e1bae  7e12                   -jle 0x4e1bc2
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004e1bc2;
    }
    // 004e1bb0  8b4c2450               -mov ecx, dword ptr [esp + 0x50]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 004e1bb4  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004e1bb6  8b442450               -mov eax, dword ptr [esp + 0x50]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 004e1bba  29cb                   -sub ebx, ecx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004e1bbc  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004e1bbf  43                     -inc ebx
    (cpu.ebx)++;
    // 004e1bc0  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
L_0x004e1bc2:
    // 004e1bc2  8b7c2460               -mov edi, dword ptr [esp + 0x60]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 004e1bc6  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004e1bc8  0f851a010000           -jne 0x4e1ce8
    if (!cpu.flags.zf)
    {
        goto L_0x004e1ce8;
    }
    // 004e1bce  8b7c245c               -mov edi, dword ptr [esp + 0x5c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(92) /* 0x5c */);
    // 004e1bd2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004e1bd3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e1bd4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e1bd5  e836ed0100             -call 0x500910
    cpu.esp -= 4;
    sub_500910(app, cpu);
    if (cpu.terminate) return;
    // 004e1bda  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
L_0x004e1bdd:
    // 004e1bdd  6800800000             -push 0x8000
    app->getMemory<x86::reg32>(cpu.esp-4) = 32768 /*0x8000*/;
    cpu.esp -= 4;
    // 004e1be2  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004e1be4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e1be5  2eff1528465300         -call dword ptr cs:[0x534628]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457448) /* 0x534628 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e1bec  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004e1bee  83c430                 -add esp, 0x30
    (cpu.esp) += x86::reg32(x86::sreg32(48 /*0x30*/));
    // 004e1bf1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e1bf2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e1bf3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e1bf4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e1bf5  c22400                 -ret 0x24
    cpu.esp += 4+36 /*0x24*/;
    return;
L_0x004e1bf8:
    // 004e1bf8  b9109b5400             -mov ecx, 0x549b10
    cpu.ecx = 5544720 /*0x549b10*/;
    // 004e1bfd  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004e1bfe  be349b5400             -mov esi, 0x549b34
    cpu.esi = 5544756 /*0x549b34*/;
    // 004e1c03  b8aa000000             -mov eax, 0xaa
    cpu.eax = 170 /*0xaa*/;
    // 004e1c08  68489b5400             -push 0x549b48
    app->getMemory<x86::reg32>(cpu.esp-4) = 5544776 /*0x549b48*/;
    cpu.esp -= 4;
    // 004e1c0d  890d90215500           -mov dword ptr [0x552190], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ecx;
    // 004e1c13  893594215500           -mov dword ptr [0x552194], esi
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.esi;
    // 004e1c19  a398215500             -mov dword ptr [0x552198], eax
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.eax;
    // 004e1c1e  e8edf3f1ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004e1c23  83c408                 +add esp, 8
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
    // 004e1c26  e9d9feffff             -jmp 0x4e1b04
    goto L_0x004e1b04;
L_0x004e1c2b:
    // 004e1c2b  83fd02                 +cmp ebp, 2
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e1c2e  7448                   -je 0x4e1c78
    if (cpu.flags.zf)
    {
        goto L_0x004e1c78;
    }
    // 004e1c30  83fd03                 +cmp ebp, 3
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e1c33  0f857c000000           -jne 0x4e1cb5
    if (!cpu.flags.zf)
    {
        goto L_0x004e1cb5;
    }
    // 004e1c39  83ff01                 +cmp edi, 1
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e1c3c  744b                   -je 0x4e1c89
    if (cpu.flags.zf)
    {
        goto L_0x004e1c89;
    }
    // 004e1c3e  83ff02                 +cmp edi, 2
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e1c41  0f852bffffff           -jne 0x4e1b72
    if (!cpu.flags.zf)
    {
        goto L_0x004e1b72;
    }
    // 004e1c47  8b542444               -mov edx, dword ptr [esp + 0x44]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 004e1c4b  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 004e1c4e  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004e1c52  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004e1c54  89542414               -mov dword ptr [esp + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 004e1c58  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004e1c5a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e1c5b  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004e1c5f  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004e1c63  89542410               -mov dword ptr [esp + 0x10], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 004e1c67  89542414               -mov dword ptr [esp + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 004e1c6b  e820ed0100             -call 0x500990
    cpu.esp -= 4;
    sub_500990(app, cpu);
    if (cpu.terminate) return;
    // 004e1c70  83c404                 +add esp, 4
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
    // 004e1c73  e9fafeffff             -jmp 0x4e1b72
    goto L_0x004e1b72;
L_0x004e1c78:
    // 004e1c78  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e1c79  8b6c2448               -mov ebp, dword ptr [esp + 0x48]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 004e1c7d  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004e1c7e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e1c7f  e88cee0100             -call 0x500b10
    cpu.esp -= 4;
    sub_500b10(app, cpu);
    if (cpu.terminate) return;
    // 004e1c84  e9e6feffff             -jmp 0x4e1b6f
    goto L_0x004e1b6f;
L_0x004e1c89:
    // 004e1c89  8b542444               -mov edx, dword ptr [esp + 0x44]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 004e1c8d  895c241c               -mov dword ptr [esp + 0x1c], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.ebx;
    // 004e1c91  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 004e1c95  8d44241c               -lea eax, [esp + 0x1c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004e1c99  89542428               -mov dword ptr [esp + 0x28], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.edx;
    // 004e1c9d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004e1c9f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e1ca0  89542424               -mov dword ptr [esp + 0x24], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.edx;
    // 004e1ca4  89542428               -mov dword ptr [esp + 0x28], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.edx;
    // 004e1ca8  e8e3ee0100             -call 0x500b90
    cpu.esp -= 4;
    sub_500b90(app, cpu);
    if (cpu.terminate) return;
    // 004e1cad  83c404                 +add esp, 4
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
    // 004e1cb0  e9bdfeffff             -jmp 0x4e1b72
    goto L_0x004e1b72;
L_0x004e1cb5:
    // 004e1cb5  ba109b5400             -mov edx, 0x549b10
    cpu.edx = 5544720 /*0x549b10*/;
    // 004e1cba  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004e1cbb  b9349b5400             -mov ecx, 0x549b34
    cpu.ecx = 5544756 /*0x549b34*/;
    // 004e1cc0  b8e0000000             -mov eax, 0xe0
    cpu.eax = 224 /*0xe0*/;
    // 004e1cc5  68b09b5400             -push 0x549bb0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5544880 /*0x549bb0*/;
    cpu.esp -= 4;
    // 004e1cca  891590215500           -mov dword ptr [0x552190], edx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edx;
    // 004e1cd0  890d94215500           -mov dword ptr [0x552194], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ecx;
    // 004e1cd6  a398215500             -mov dword ptr [0x552198], eax
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.eax;
    // 004e1cdb  e830f3f1ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004e1ce0  83c408                 +add esp, 8
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
    // 004e1ce3  e98afeffff             -jmp 0x4e1b72
    goto L_0x004e1b72;
L_0x004e1ce8:
    // 004e1ce8  bd109b5400             -mov ebp, 0x549b10
    cpu.ebp = 5544720 /*0x549b10*/;
    // 004e1ced  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004e1cee  b8349b5400             -mov eax, 0x549b34
    cpu.eax = 5544756 /*0x549b34*/;
    // 004e1cf3  ba01010000             -mov edx, 0x101
    cpu.edx = 257 /*0x101*/;
    // 004e1cf8  68e49b5400             -push 0x549be4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5544932 /*0x549be4*/;
    cpu.esp -= 4;
    // 004e1cfd  892d90215500           -mov dword ptr [0x552190], ebp
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ebp;
    // 004e1d03  a394215500             -mov dword ptr [0x552194], eax
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.eax;
    // 004e1d08  891598215500           -mov dword ptr [0x552198], edx
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.edx;
    // 004e1d0e  e8fdf2f1ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004e1d13  83c408                 +add esp, 8
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
    // 004e1d16  e9c2feffff             -jmp 0x4e1bdd
    goto L_0x004e1bdd;
}

/* align: skip 0x90 */
void Application::sub_4e1d1c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e1d1c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e1d1d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e1d1e  803df89aa00000         +cmp byte ptr [0xa09af8], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(10525432) /* 0xa09af8 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004e1d25  7e1d                   -jle 0x4e1d44
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004e1d44;
    }
L_0x004e1d27:
    // 004e1d27  fe0df89aa000           -dec byte ptr [0xa09af8]
    (app->getMemory<x86::reg8>(x86::reg32(10525432) /* 0xa09af8 */))--;
    // 004e1d2d  8b15049ba000           -mov edx, dword ptr [0xa09b04]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10525444) /* 0xa09b04 */);
    // 004e1d33  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e1d34  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e1d3a  803df89aa00000         +cmp byte ptr [0xa09af8], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(10525432) /* 0xa09af8 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004e1d41  7fe4                   -jg 0x4e1d27
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004e1d27;
    }
    // 004e1d43  90                     -nop 
    ;
L_0x004e1d44:
    // 004e1d44  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e1d45  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e1d46  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4e1d48(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e1d48  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e1d49  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e1d4a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e1d4b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004e1d4c  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004e1d4e  8b15049ba000           -mov edx, dword ptr [0xa09b04]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10525444) /* 0xa09b04 */);
    // 004e1d54  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e1d55  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e1d5b  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004e1d5d  745c                   -je 0x4e1dbb
    if (cpu.flags.zf)
    {
        goto L_0x004e1dbb;
    }
    // 004e1d5f  e80c9d0000             -call 0x4eba70
    cpu.esp -= 4;
    sub_4eba70(app, cpu);
    if (cpu.terminate) return;
    // 004e1d64  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004e1d66  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e1d68  7532                   -jne 0x4e1d9c
    if (!cpu.flags.zf)
    {
        goto L_0x004e1d9c;
    }
    // 004e1d6a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004e1d6b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e1d6c  b9109b5400             -mov ecx, 0x549b10
    cpu.ecx = 5544720 /*0x549b10*/;
    // 004e1d71  be189c5400             -mov esi, 0x549c18
    cpu.esi = 5544984 /*0x549c18*/;
    // 004e1d76  bf24010000             -mov edi, 0x124
    cpu.edi = 292 /*0x124*/;
    // 004e1d7b  682c9c5400             -push 0x549c2c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5545004 /*0x549c2c*/;
    cpu.esp -= 4;
    // 004e1d80  890d90215500           -mov dword ptr [0x552190], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ecx;
    // 004e1d86  893594215500           -mov dword ptr [0x552194], esi
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.esi;
    // 004e1d8c  893d98215500           -mov dword ptr [0x552198], edi
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.edi;
    // 004e1d92  e879f2f1ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004e1d97  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004e1d9a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e1d9b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004e1d9c:
    // 004e1d9c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e1d9d  8b2d08f69e00           -mov ebp, dword ptr [0x9ef608]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(10417672) /* 0x9ef608 */);
    // 004e1da3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004e1da4  ff1520f69e00           -call dword ptr [0x9ef620]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10417696) /* 0x9ef620 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e1daa  a1049ba000             -mov eax, dword ptr [0xa09b04]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10525444) /* 0xa09b04 */);
    // 004e1daf  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e1db0  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e1db6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e1db7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e1db8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e1db9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e1dba  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e1dbb:
    // 004e1dbb  ff1524f69e00           -call dword ptr [0x9ef624]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10417700) /* 0x9ef624 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e1dc1  a1049ba000             -mov eax, dword ptr [0xa09b04]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10525444) /* 0xa09b04 */);
    // 004e1dc6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e1dc7  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e1dcd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e1dce  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e1dcf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e1dd0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e1dd1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4e1dd4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e1dd4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e1dd5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e1dd6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e1dd7  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e1dd8  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004e1dd9  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004e1dda  833d00f69e0000         +cmp dword ptr [0x9ef600], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10417664) /* 0x9ef600 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e1de1  7409                   -je 0x4e1dec
    if (cpu.flags.zf)
    {
        goto L_0x004e1dec;
    }
L_0x004e1de3:
    // 004e1de3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004e1de5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e1de6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e1de7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e1de8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e1de9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e1dea  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e1deb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e1dec:
    // 004e1dec  68609c5400             -push 0x549c60
    app->getMemory<x86::reg32>(cpu.esp-4) = 5545056 /*0x549c60*/;
    cpu.esp -= 4;
    // 004e1df1  2eff158c455300         -call dword ptr cs:[0x53458c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457292) /* 0x53458c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e1df8  a300f69e00             -mov dword ptr [0x9ef600], eax
    app->getMemory<x86::reg32>(x86::reg32(10417664) /* 0x9ef600 */) = cpu.eax;
    // 004e1dfd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e1dff  0f847d020000           -je 0x4e2082
    if (cpu.flags.zf)
    {
        goto L_0x004e2082;
    }
    // 004e1e05  68d89c5400             -push 0x549cd8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5545176 /*0x549cd8*/;
    cpu.esp -= 4;
    // 004e1e0a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e1e0b  2eff1558455300         -call dword ptr cs:[0x534558]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457240) /* 0x534558 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e1e12  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004e1e14  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e1e16  0f84a0020000           -je 0x4e20bc
    if (cpu.flags.zf)
    {
        goto L_0x004e20bc;
    }
    // 004e1e1c  ffd2                   -call edx
    cpu.ip = cpu.edx;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e1e1e  3d03001000             +cmp eax, 0x100003
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1048579 /*0x100003*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e1e23  0f85cc020000           -jne 0x4e20f5
    if (!cpu.flags.zf)
    {
        goto L_0x004e20f5;
    }
    // 004e1e29  68689d5400             -push 0x549d68
    app->getMemory<x86::reg32>(cpu.esp-4) = 5545320 /*0x549d68*/;
    cpu.esp -= 4;
    // 004e1e2e  8b0d00f69e00           -mov ecx, dword ptr [0x9ef600]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10417664) /* 0x9ef600 */);
    // 004e1e34  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e1e35  2eff1558455300         -call dword ptr cs:[0x534558]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457240) /* 0x534558 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e1e3c  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004e1e3e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e1e40  0f84fa020000           -je 0x4e2140
    if (cpu.flags.zf)
    {
        goto L_0x004e2140;
    }
    // 004e1e46  68e41a4e00             -push 0x4e1ae4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5118692 /*0x4e1ae4*/;
    cpu.esp -= 4;
    // 004e1e4b  680c1a4e00             -push 0x4e1a0c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5118476 /*0x4e1a0c*/;
    cpu.esp -= 4;
    // 004e1e50  68341a4e00             -push 0x4e1a34
    app->getMemory<x86::reg32>(cpu.esp-4) = 5118516 /*0x4e1a34*/;
    cpu.esp -= 4;
    // 004e1e55  68dc1a4e00             -push 0x4e1adc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5118684 /*0x4e1adc*/;
    cpu.esp -= 4;
    // 004e1e5a  68641a4e00             -push 0x4e1a64
    app->getMemory<x86::reg32>(cpu.esp-4) = 5118564 /*0x4e1a64*/;
    cpu.esp -= 4;
    // 004e1e5f  68881a4e00             -push 0x4e1a88
    app->getMemory<x86::reg32>(cpu.esp-4) = 5118600 /*0x4e1a88*/;
    cpu.esp -= 4;
    // 004e1e64  68001a4e00             -push 0x4e1a00
    app->getMemory<x86::reg32>(cpu.esp-4) = 5118464 /*0x4e1a00*/;
    cpu.esp -= 4;
    // 004e1e69  68241a4e00             -push 0x4e1a24
    app->getMemory<x86::reg32>(cpu.esp-4) = 5118500 /*0x4e1a24*/;
    cpu.esp -= 4;
    // 004e1e6e  ffd2                   -call edx
    cpu.ip = cpu.edx;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e1e70  68b09d5400             -push 0x549db0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5545392 /*0x549db0*/;
    cpu.esp -= 4;
    // 004e1e75  8b1d00f69e00           -mov ebx, dword ptr [0x9ef600]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10417664) /* 0x9ef600 */);
    // 004e1e7b  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e1e7c  2eff1558455300         -call dword ptr cs:[0x534558]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457240) /* 0x534558 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e1e83  68c49d5400             -push 0x549dc4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5545412 /*0x549dc4*/;
    cpu.esp -= 4;
    // 004e1e88  8b3500f69e00           -mov esi, dword ptr [0x9ef600]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(10417664) /* 0x9ef600 */);
    // 004e1e8e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e1e8f  a31cf69e00             -mov dword ptr [0x9ef61c], eax
    app->getMemory<x86::reg32>(x86::reg32(10417692) /* 0x9ef61c */) = cpu.eax;
    // 004e1e94  2eff1558455300         -call dword ptr cs:[0x534558]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457240) /* 0x534558 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e1e9b  68d89d5400             -push 0x549dd8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5545432 /*0x549dd8*/;
    cpu.esp -= 4;
    // 004e1ea0  8b3d00f69e00           -mov edi, dword ptr [0x9ef600]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(10417664) /* 0x9ef600 */);
    // 004e1ea6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004e1ea7  a320f69e00             -mov dword ptr [0x9ef620], eax
    app->getMemory<x86::reg32>(x86::reg32(10417696) /* 0x9ef620 */) = cpu.eax;
    // 004e1eac  2eff1558455300         -call dword ptr cs:[0x534558]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457240) /* 0x534558 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e1eb3  68ec9d5400             -push 0x549dec
    app->getMemory<x86::reg32>(cpu.esp-4) = 5545452 /*0x549dec*/;
    cpu.esp -= 4;
    // 004e1eb8  8b2d00f69e00           -mov ebp, dword ptr [0x9ef600]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(10417664) /* 0x9ef600 */);
    // 004e1ebe  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004e1ebf  a324f69e00             -mov dword ptr [0x9ef624], eax
    app->getMemory<x86::reg32>(x86::reg32(10417700) /* 0x9ef624 */) = cpu.eax;
    // 004e1ec4  2eff1558455300         -call dword ptr cs:[0x534558]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457240) /* 0x534558 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e1ecb  68089e5400             -push 0x549e08
    app->getMemory<x86::reg32>(cpu.esp-4) = 5545480 /*0x549e08*/;
    cpu.esp -= 4;
    // 004e1ed0  a328f69e00             -mov dword ptr [0x9ef628], eax
    app->getMemory<x86::reg32>(x86::reg32(10417704) /* 0x9ef628 */) = cpu.eax;
    // 004e1ed5  a100f69e00             -mov eax, dword ptr [0x9ef600]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10417664) /* 0x9ef600 */);
    // 004e1eda  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e1edb  2eff1558455300         -call dword ptr cs:[0x534558]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457240) /* 0x534558 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e1ee2  68249e5400             -push 0x549e24
    app->getMemory<x86::reg32>(cpu.esp-4) = 5545508 /*0x549e24*/;
    cpu.esp -= 4;
    // 004e1ee7  8b1500f69e00           -mov edx, dword ptr [0x9ef600]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10417664) /* 0x9ef600 */);
    // 004e1eed  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e1eee  a32cf69e00             -mov dword ptr [0x9ef62c], eax
    app->getMemory<x86::reg32>(x86::reg32(10417708) /* 0x9ef62c */) = cpu.eax;
    // 004e1ef3  2eff1558455300         -call dword ptr cs:[0x534558]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457240) /* 0x534558 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e1efa  683c9e5400             -push 0x549e3c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5545532 /*0x549e3c*/;
    cpu.esp -= 4;
    // 004e1eff  8b0d00f69e00           -mov ecx, dword ptr [0x9ef600]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10417664) /* 0x9ef600 */);
    // 004e1f05  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e1f06  a330f69e00             -mov dword ptr [0x9ef630], eax
    app->getMemory<x86::reg32>(x86::reg32(10417712) /* 0x9ef630 */) = cpu.eax;
    // 004e1f0b  2eff1558455300         -call dword ptr cs:[0x534558]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457240) /* 0x534558 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e1f12  68509e5400             -push 0x549e50
    app->getMemory<x86::reg32>(cpu.esp-4) = 5545552 /*0x549e50*/;
    cpu.esp -= 4;
    // 004e1f17  8b1d00f69e00           -mov ebx, dword ptr [0x9ef600]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10417664) /* 0x9ef600 */);
    // 004e1f1d  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e1f1e  a334f69e00             -mov dword ptr [0x9ef634], eax
    app->getMemory<x86::reg32>(x86::reg32(10417716) /* 0x9ef634 */) = cpu.eax;
    // 004e1f23  2eff1558455300         -call dword ptr cs:[0x534558]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457240) /* 0x534558 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e1f2a  686c9e5400             -push 0x549e6c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5545580 /*0x549e6c*/;
    cpu.esp -= 4;
    // 004e1f2f  8b3500f69e00           -mov esi, dword ptr [0x9ef600]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(10417664) /* 0x9ef600 */);
    // 004e1f35  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e1f36  a338f69e00             -mov dword ptr [0x9ef638], eax
    app->getMemory<x86::reg32>(x86::reg32(10417720) /* 0x9ef638 */) = cpu.eax;
    // 004e1f3b  2eff1558455300         -call dword ptr cs:[0x534558]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457240) /* 0x534558 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e1f42  68849e5400             -push 0x549e84
    app->getMemory<x86::reg32>(cpu.esp-4) = 5545604 /*0x549e84*/;
    cpu.esp -= 4;
    // 004e1f47  8b3d00f69e00           -mov edi, dword ptr [0x9ef600]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(10417664) /* 0x9ef600 */);
    // 004e1f4d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004e1f4e  a33cf69e00             -mov dword ptr [0x9ef63c], eax
    app->getMemory<x86::reg32>(x86::reg32(10417724) /* 0x9ef63c */) = cpu.eax;
    // 004e1f53  2eff1558455300         -call dword ptr cs:[0x534558]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457240) /* 0x534558 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e1f5a  a340f69e00             -mov dword ptr [0x9ef640], eax
    app->getMemory<x86::reg32>(x86::reg32(10417728) /* 0x9ef640 */) = cpu.eax;
    // 004e1f5f  689c9e5400             -push 0x549e9c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5545628 /*0x549e9c*/;
    cpu.esp -= 4;
    // 004e1f64  8b2d00f69e00           -mov ebp, dword ptr [0x9ef600]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(10417664) /* 0x9ef600 */);
    // 004e1f6a  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004e1f6b  2eff1558455300         -call dword ptr cs:[0x534558]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457240) /* 0x534558 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e1f72  68b09e5400             -push 0x549eb0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5545648 /*0x549eb0*/;
    cpu.esp -= 4;
    // 004e1f77  a344f69e00             -mov dword ptr [0x9ef644], eax
    app->getMemory<x86::reg32>(x86::reg32(10417732) /* 0x9ef644 */) = cpu.eax;
    // 004e1f7c  a100f69e00             -mov eax, dword ptr [0x9ef600]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10417664) /* 0x9ef600 */);
    // 004e1f81  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e1f82  2eff1558455300         -call dword ptr cs:[0x534558]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457240) /* 0x534558 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e1f89  68c49e5400             -push 0x549ec4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5545668 /*0x549ec4*/;
    cpu.esp -= 4;
    // 004e1f8e  8b1500f69e00           -mov edx, dword ptr [0x9ef600]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10417664) /* 0x9ef600 */);
    // 004e1f94  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e1f95  a348f69e00             -mov dword ptr [0x9ef648], eax
    app->getMemory<x86::reg32>(x86::reg32(10417736) /* 0x9ef648 */) = cpu.eax;
    // 004e1f9a  2eff1558455300         -call dword ptr cs:[0x534558]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457240) /* 0x534558 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e1fa1  68d89e5400             -push 0x549ed8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5545688 /*0x549ed8*/;
    cpu.esp -= 4;
    // 004e1fa6  8b0d00f69e00           -mov ecx, dword ptr [0x9ef600]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10417664) /* 0x9ef600 */);
    // 004e1fac  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e1fad  a34cf69e00             -mov dword ptr [0x9ef64c], eax
    app->getMemory<x86::reg32>(x86::reg32(10417740) /* 0x9ef64c */) = cpu.eax;
    // 004e1fb2  2eff1558455300         -call dword ptr cs:[0x534558]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457240) /* 0x534558 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e1fb9  8b1d1cf69e00           -mov ebx, dword ptr [0x9ef61c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10417692) /* 0x9ef61c */);
    // 004e1fbf  a350f69e00             -mov dword ptr [0x9ef650], eax
    app->getMemory<x86::reg32>(x86::reg32(10417744) /* 0x9ef650 */) = cpu.eax;
    // 004e1fc4  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004e1fc6  0f847c000000           -je 0x4e2048
    if (cpu.flags.zf)
    {
        goto L_0x004e2048;
    }
    // 004e1fcc  833d20f69e0000         +cmp dword ptr [0x9ef620], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10417696) /* 0x9ef620 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e1fd3  0f846f000000           -je 0x4e2048
    if (cpu.flags.zf)
    {
        goto L_0x004e2048;
    }
    // 004e1fd9  833d24f69e0000         +cmp dword ptr [0x9ef624], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10417700) /* 0x9ef624 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e1fe0  0f8462000000           -je 0x4e2048
    if (cpu.flags.zf)
    {
        goto L_0x004e2048;
    }
    // 004e1fe6  833d28f69e0000         +cmp dword ptr [0x9ef628], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10417704) /* 0x9ef628 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e1fed  7459                   -je 0x4e2048
    if (cpu.flags.zf)
    {
        goto L_0x004e2048;
    }
    // 004e1fef  833d2cf69e0000         +cmp dword ptr [0x9ef62c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10417708) /* 0x9ef62c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e1ff6  7450                   -je 0x4e2048
    if (cpu.flags.zf)
    {
        goto L_0x004e2048;
    }
    // 004e1ff8  833d30f69e0000         +cmp dword ptr [0x9ef630], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10417712) /* 0x9ef630 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e1fff  7447                   -je 0x4e2048
    if (cpu.flags.zf)
    {
        goto L_0x004e2048;
    }
    // 004e2001  833d34f69e0000         +cmp dword ptr [0x9ef634], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10417716) /* 0x9ef634 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e2008  743e                   -je 0x4e2048
    if (cpu.flags.zf)
    {
        goto L_0x004e2048;
    }
    // 004e200a  833d38f69e0000         +cmp dword ptr [0x9ef638], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10417720) /* 0x9ef638 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e2011  7435                   -je 0x4e2048
    if (cpu.flags.zf)
    {
        goto L_0x004e2048;
    }
    // 004e2013  833d3cf69e0000         +cmp dword ptr [0x9ef63c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10417724) /* 0x9ef63c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e201a  742c                   -je 0x4e2048
    if (cpu.flags.zf)
    {
        goto L_0x004e2048;
    }
    // 004e201c  833d40f69e0000         +cmp dword ptr [0x9ef640], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10417728) /* 0x9ef640 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e2023  7423                   -je 0x4e2048
    if (cpu.flags.zf)
    {
        goto L_0x004e2048;
    }
    // 004e2025  833d44f69e0000         +cmp dword ptr [0x9ef644], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10417732) /* 0x9ef644 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e202c  741a                   -je 0x4e2048
    if (cpu.flags.zf)
    {
        goto L_0x004e2048;
    }
    // 004e202e  833d48f69e0000         +cmp dword ptr [0x9ef648], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10417736) /* 0x9ef648 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e2035  7411                   -je 0x4e2048
    if (cpu.flags.zf)
    {
        goto L_0x004e2048;
    }
    // 004e2037  833d4cf69e0000         +cmp dword ptr [0x9ef64c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10417740) /* 0x9ef64c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e203e  7408                   -je 0x4e2048
    if (cpu.flags.zf)
    {
        goto L_0x004e2048;
    }
    // 004e2040  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e2042  0f859bfdffff           -jne 0x4e1de3
    if (!cpu.flags.zf)
    {
        goto L_0x004e1de3;
    }
L_0x004e2048:
    // 004e2048  be109b5400             -mov esi, 0x549b10
    cpu.esi = 5544720 /*0x549b10*/;
    // 004e204d  bf6c9c5400             -mov edi, 0x549c6c
    cpu.edi = 5545068 /*0x549c6c*/;
    // 004e2052  bdad010000             -mov ebp, 0x1ad
    cpu.ebp = 429 /*0x1ad*/;
    // 004e2057  68f09e5400             -push 0x549ef0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5545712 /*0x549ef0*/;
    cpu.esp -= 4;
    // 004e205c  893590215500           -mov dword ptr [0x552190], esi
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.esi;
    // 004e2062  893d94215500           -mov dword ptr [0x552194], edi
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.edi;
    // 004e2068  892d98215500           -mov dword ptr [0x552198], ebp
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ebp;
    // 004e206e  e89deff1ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004e2073  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004e2078  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004e207b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e207c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e207d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e207e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e207f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e2080  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e2081  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e2082:
    // 004e2082  b9109b5400             -mov ecx, 0x549b10
    cpu.ecx = 5544720 /*0x549b10*/;
    // 004e2087  bb6c9c5400             -mov ebx, 0x549c6c
    cpu.ebx = 5545068 /*0x549c6c*/;
    // 004e208c  be53010000             -mov esi, 0x153
    cpu.esi = 339 /*0x153*/;
    // 004e2091  68789c5400             -push 0x549c78
    app->getMemory<x86::reg32>(cpu.esp-4) = 5545080 /*0x549c78*/;
    cpu.esp -= 4;
    // 004e2096  890d90215500           -mov dword ptr [0x552190], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ecx;
    // 004e209c  891d94215500           -mov dword ptr [0x552194], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebx;
    // 004e20a2  893598215500           -mov dword ptr [0x552198], esi
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.esi;
    // 004e20a8  e863eff1ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004e20ad  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004e20b2  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004e20b5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e20b6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e20b7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e20b8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e20b9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e20ba  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e20bb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e20bc:
    // 004e20bc  bd109b5400             -mov ebp, 0x549b10
    cpu.ebp = 5544720 /*0x549b10*/;
    // 004e20c1  b86c9c5400             -mov eax, 0x549c6c
    cpu.eax = 5545068 /*0x549c6c*/;
    // 004e20c6  ba5f010000             -mov edx, 0x15f
    cpu.edx = 351 /*0x15f*/;
    // 004e20cb  68ec9c5400             -push 0x549cec
    app->getMemory<x86::reg32>(cpu.esp-4) = 5545196 /*0x549cec*/;
    cpu.esp -= 4;
    // 004e20d0  892d90215500           -mov dword ptr [0x552190], ebp
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ebp;
    // 004e20d6  a394215500             -mov dword ptr [0x552194], eax
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.eax;
    // 004e20db  891598215500           -mov dword ptr [0x552198], edx
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.edx;
    // 004e20e1  e82aeff1ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004e20e6  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004e20eb  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004e20ee  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e20ef  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e20f0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e20f1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e20f2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e20f3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e20f4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e20f5:
    // 004e20f5  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004e20f7  81e2ffff0000           -and edx, 0xffff
    cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004e20fd  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e20fe  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004e2101  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e2102  6a03                   -push 3
    app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
    // 004e2104  bb109b5400             -mov ebx, 0x549b10
    cpu.ebx = 5544720 /*0x549b10*/;
    // 004e2109  be6c9c5400             -mov esi, 0x549c6c
    cpu.esi = 5545068 /*0x549c6c*/;
    // 004e210e  6a10                   -push 0x10
    app->getMemory<x86::reg32>(cpu.esp-4) = 16 /*0x10*/;
    cpu.esp -= 4;
    // 004e2110  bf69010000             -mov edi, 0x169
    cpu.edi = 361 /*0x169*/;
    // 004e2115  891d90215500           -mov dword ptr [0x552190], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ebx;
    // 004e211b  681c9d5400             -push 0x549d1c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5545244 /*0x549d1c*/;
    cpu.esp -= 4;
    // 004e2120  893594215500           -mov dword ptr [0x552194], esi
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.esi;
    // 004e2126  893d98215500           -mov dword ptr [0x552198], edi
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.edi;
    // 004e212c  e8dfeef1ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004e2131  b8f5ffffff             -mov eax, 0xfffffff5
    cpu.eax = 4294967285 /*0xfffffff5*/;
    // 004e2136  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004e2139  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e213a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e213b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e213c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e213d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e213e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e213f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e2140:
    // 004e2140  b8109b5400             -mov eax, 0x549b10
    cpu.eax = 5544720 /*0x549b10*/;
    // 004e2145  ba6c9c5400             -mov edx, 0x549c6c
    cpu.edx = 5545068 /*0x549c6c*/;
    // 004e214a  b976010000             -mov ecx, 0x176
    cpu.ecx = 374 /*0x176*/;
    // 004e214f  68849d5400             -push 0x549d84
    app->getMemory<x86::reg32>(cpu.esp-4) = 5545348 /*0x549d84*/;
    cpu.esp -= 4;
    // 004e2154  a390215500             -mov dword ptr [0x552190], eax
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.eax;
    // 004e2159  891594215500           -mov dword ptr [0x552194], edx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.edx;
    // 004e215f  890d98215500           -mov dword ptr [0x552198], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ecx;
    // 004e2165  e8a6eef1ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004e216a  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004e216f  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004e2172  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e2173  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e2174  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e2175  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e2176  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e2177  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e2178  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4e217c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e217c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e217d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e217e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e217f  8b1500f69e00           -mov edx, dword ptr [0x9ef600]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10417664) /* 0x9ef600 */);
    // 004e2185  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004e2187  750e                   -jne 0x4e2197
    if (!cpu.flags.zf)
    {
        goto L_0x004e2197;
    }
    // 004e2189  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004e218b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004e218d  891d00f69e00           -mov dword ptr [0x9ef600], ebx
    app->getMemory<x86::reg32>(x86::reg32(10417664) /* 0x9ef600 */) = cpu.ebx;
    // 004e2193  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e2194  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e2195  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e2196  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e2197:
    // 004e2197  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e2198  2eff15dc445300         -call dword ptr cs:[0x5344dc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457116) /* 0x5344dc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e219f  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004e21a1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004e21a3  891d00f69e00           -mov dword ptr [0x9ef600], ebx
    app->getMemory<x86::reg32>(x86::reg32(10417664) /* 0x9ef600 */) = cpu.ebx;
    // 004e21a9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e21aa  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e21ab  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e21ac  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4e21b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e21b0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e21b1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e21b2  833d089ba00000         +cmp dword ptr [0xa09b08], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10525448) /* 0xa09b08 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e21b9  750a                   -jne 0x4e21c5
    if (!cpu.flags.zf)
    {
        goto L_0x004e21c5;
    }
    // 004e21bb  c705089ba000800c5000   -mov dword ptr [0xa09b08], 0x500c80
    app->getMemory<x86::reg32>(x86::reg32(10525448) /* 0xa09b08 */) = 5246080 /*0x500c80*/;
L_0x004e21c5:
    // 004e21c5  e80afcffff             -call 0x4e1dd4
    cpu.esp -= 4;
    sub_4e1dd4(app, cpu);
    if (cpu.terminate) return;
    // 004e21ca  e8a1980000             -call 0x4eba70
    cpu.esp -= 4;
    sub_4eba70(app, cpu);
    if (cpu.terminate) return;
    // 004e21cf  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004e21d1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e21d3  7534                   -jne 0x4e2209
    if (!cpu.flags.zf)
    {
        goto L_0x004e2209;
    }
    // 004e21d5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004e21d6  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e21d7  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e21d8  bb109b5400             -mov ebx, 0x549b10
    cpu.ebx = 5544720 /*0x549b10*/;
    // 004e21dd  be209f5400             -mov esi, 0x549f20
    cpu.esi = 5545760 /*0x549f20*/;
    // 004e21e2  bf2d020000             -mov edi, 0x22d
    cpu.edi = 557 /*0x22d*/;
    // 004e21e7  68289f5400             -push 0x549f28
    app->getMemory<x86::reg32>(cpu.esp-4) = 5545768 /*0x549f28*/;
    cpu.esp -= 4;
    // 004e21ec  891d90215500           -mov dword ptr [0x552190], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ebx;
    // 004e21f2  893594215500           -mov dword ptr [0x552194], esi
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.esi;
    // 004e21f8  893d98215500           -mov dword ptr [0x552198], edi
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.edi;
    // 004e21fe  e80deef1ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004e2203  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004e2206  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e2207  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e2208  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004e2209:
    // 004e2209  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e220a  ff151cf69e00           -call dword ptr [0x9ef61c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10417692) /* 0x9ef61c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e2210  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004e2212  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e2214  7e06                   -jle 0x4e221c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004e221c;
    }
    // 004e2216  81ca00000100           -or edx, 0x10000
    cpu.edx |= x86::reg32(x86::sreg32(65536 /*0x10000*/));
L_0x004e221c:
    // 004e221c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004e221e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e221f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e2220  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4e2224(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e2224  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004e2226  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4e2228(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e2228  66a316f69e00           -mov word ptr [0x9ef616], ax
    app->getMemory<x86::reg16>(x86::reg32(10417686) /* 0x9ef616 */) = cpu.ax;
    // 004e222e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004e2230  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4e2234(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e2234  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e2235  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e2236  8b15049ba000           -mov edx, dword ptr [0xa09b04]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10525444) /* 0xa09b04 */);
    // 004e223c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e223d  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e2243  ff1534f69e00           -call dword ptr [0x9ef634]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10417716) /* 0x9ef634 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e2249  8b0d049ba000           -mov ecx, dword ptr [0xa09b04]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10525444) /* 0xa09b04 */);
    // 004e224f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e2250  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e2256  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e2257  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e2258  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4e225c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e225c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e225d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e225e  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004e225f  8b742414               -mov esi, dword ptr [esp + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004e2263  837c242000             +cmp dword ptr [esp + 0x20], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e2268  0f8593010000           -jne 0x4e2401
    if (!cpu.flags.zf)
    {
        goto L_0x004e2401;
    }
    // 004e226e  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004e2270  7530                   -jne 0x4e22a2
    if (!cpu.flags.zf)
    {
        goto L_0x004e22a2;
    }
    // 004e2272  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004e2273  bb109b5400             -mov ebx, 0x549b10
    cpu.ebx = 5544720 /*0x549b10*/;
    // 004e2278  bf549f5400             -mov edi, 0x549f54
    cpu.edi = 5545812 /*0x549f54*/;
    // 004e227d  bdd9020000             -mov ebp, 0x2d9
    cpu.ebp = 729 /*0x2d9*/;
    // 004e2282  68649f5400             -push 0x549f64
    app->getMemory<x86::reg32>(cpu.esp-4) = 5545828 /*0x549f64*/;
    cpu.esp -= 4;
    // 004e2287  891d90215500           -mov dword ptr [0x552190], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ebx;
    // 004e228d  893d94215500           -mov dword ptr [0x552194], edi
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.edi;
    // 004e2293  892d98215500           -mov dword ptr [0x552198], ebp
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ebp;
    // 004e2299  e872edf1ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004e229e  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004e22a1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004e22a2:
    // 004e22a2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e22a3  8b1d10f69e00           -mov ebx, dword ptr [0x9ef610]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10417680) /* 0x9ef610 */);
    // 004e22a9  ff151cf69e00           -call dword ptr [0x9ef61c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10417692) /* 0x9ef61c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e22af  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e22b1  0f8ea3000000           -jle 0x4e235a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004e235a;
    }
    // 004e22b7  f6c708                 +test bh, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 8 /*0x8*/));
    // 004e22ba  0f84ae000000           -je 0x4e236e
    if (cpu.flags.zf)
    {
        goto L_0x004e236e;
    }
    // 004e22c0  66c70514f69e002256     -mov word ptr [0x9ef614], 0x5622
    app->getMemory<x86::reg16>(x86::reg32(10417684) /* 0x9ef614 */) = 22050 /*0x5622*/;
L_0x004e22c9:
    // 004e22c9  891d08f69e00           -mov dword ptr [0x9ef608], ebx
    app->getMemory<x86::reg32>(x86::reg32(10417672) /* 0x9ef608 */) = cpu.ebx;
    // 004e22cf  803d06f69e0000         +cmp byte ptr [0x9ef606], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(10417670) /* 0x9ef606 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004e22d6  7512                   -jne 0x4e22ea
    if (!cpu.flags.zf)
    {
        goto L_0x004e22ea;
    }
    // 004e22d8  b8b4264e00             -mov eax, 0x4e26b4
    cpu.eax = 5121716 /*0x4e26b4*/;
    // 004e22dd  b501                   -mov ch, 1
    cpu.ch = 1 /*0x1*/;
    // 004e22df  e894070100             -call 0x4f2a78
    cpu.esp -= 4;
    sub_4f2a78(app, cpu);
    if (cpu.terminate) return;
    // 004e22e4  882d06f69e00           -mov byte ptr [0x9ef606], ch
    app->getMemory<x86::reg8>(x86::reg32(10417670) /* 0x9ef606 */) = cpu.ch;
L_0x004e22ea:
    // 004e22ea  a108f69e00             -mov eax, dword ptr [0x9ef608]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10417672) /* 0x9ef608 */);
    // 004e22ef  ba64fb4f00             -mov edx, 0x4ffb64
    cpu.edx = 5241700 /*0x4ffb64*/;
    // 004e22f4  e81fdc0100             -call 0x4fff18
    cpu.esp -= 4;
    sub_4fff18(app, cpu);
    if (cpu.terminate) return;
    // 004e22f9  833d54f69e0000         +cmp dword ptr [0x9ef654], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10417748) /* 0x9ef654 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e2300  740b                   -je 0x4e230d
    if (cpu.flags.zf)
    {
        goto L_0x004e230d;
    }
    // 004e2302  a15ca2a000             -mov eax, dword ptr [0xa0a25c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10527324) /* 0xa0a25c */);
    // 004e2307  ff1554f69e00           -call dword ptr [0x9ef654]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10417748) /* 0x9ef654 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004e230d:
    // 004e230d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e230e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e230f  ff1520f69e00           -call dword ptr [0x9ef620]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10417696) /* 0x9ef620 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e2315  a30cf69e00             -mov dword ptr [0x9ef60c], eax
    app->getMemory<x86::reg32>(x86::reg32(10417676) /* 0x9ef60c */) = cpu.eax;
    // 004e231a  833d0cf69e0000         +cmp dword ptr [0x9ef60c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10417676) /* 0x9ef60c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e2321  7c3c                   -jl 0x4e235f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004e235f;
    }
    // 004e2323  803d04f69e0000         +cmp byte ptr [0x9ef604], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(10417668) /* 0x9ef604 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004e232a  7511                   -jne 0x4e233d
    if (!cpu.flags.zf)
    {
        goto L_0x004e233d;
    }
    // 004e232c  b834224e00             -mov eax, 0x4e2234
    cpu.eax = 5120564 /*0x4e2234*/;
    // 004e2331  e84ac9faff             -call 0x48ec80
    cpu.esp -= 4;
    sub_48ec80(app, cpu);
    if (cpu.terminate) return;
    // 004e2336  c60504f69e0001         -mov byte ptr [0x9ef604], 1
    app->getMemory<x86::reg8>(x86::reg32(10417668) /* 0x9ef604 */) = 1 /*0x1*/;
L_0x004e233d:
    // 004e233d  803d05f69e0000         +cmp byte ptr [0x9ef605], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(10417669) /* 0x9ef605 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004e2344  7512                   -jne 0x4e2358
    if (!cpu.flags.zf)
    {
        goto L_0x004e2358;
    }
    // 004e2346  b8481d4e00             -mov eax, 0x4e1d48
    cpu.eax = 5119304 /*0x4e1d48*/;
    // 004e234b  b601                   -mov dh, 1
    cpu.dh = 1 /*0x1*/;
    // 004e234d  e80ea5feff             -call 0x4cc860
    cpu.esp -= 4;
    sub_4cc860(app, cpu);
    if (cpu.terminate) return;
    // 004e2352  883505f69e00           -mov byte ptr [0x9ef605], dh
    app->getMemory<x86::reg8>(x86::reg32(10417669) /* 0x9ef605 */) = cpu.dh;
L_0x004e2358:
    // 004e2358  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004e235a:
    // 004e235a  a30cf69e00             -mov dword ptr [0x9ef60c], eax
    app->getMemory<x86::reg32>(x86::reg32(10417676) /* 0x9ef60c */) = cpu.eax;
L_0x004e235f:
    // 004e235f  c60507f69e0001         -mov byte ptr [0x9ef607], 1
    app->getMemory<x86::reg8>(x86::reg32(10417671) /* 0x9ef607 */) = 1 /*0x1*/;
    // 004e2366  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004e2368  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e2369  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e236a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e236b  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x004e236e:
    // 004e236e  f6c704                 +test bh, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 4 /*0x4*/));
    // 004e2371  740e                   -je 0x4e2381
    if (cpu.flags.zf)
    {
        goto L_0x004e2381;
    }
    // 004e2373  66c70514f69e00803e     -mov word ptr [0x9ef614], 0x3e80
    app->getMemory<x86::reg16>(x86::reg32(10417684) /* 0x9ef614 */) = 16000 /*0x3e80*/;
    // 004e237c  e948ffffff             -jmp 0x4e22c9
    goto L_0x004e22c9;
L_0x004e2381:
    // 004e2381  f6c710                 +test bh, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 16 /*0x10*/));
    // 004e2384  740e                   -je 0x4e2394
    if (cpu.flags.zf)
    {
        goto L_0x004e2394;
    }
    // 004e2386  66c70514f69e00007d     -mov word ptr [0x9ef614], 0x7d00
    app->getMemory<x86::reg16>(x86::reg32(10417684) /* 0x9ef614 */) = 32000 /*0x7d00*/;
    // 004e238f  e935ffffff             -jmp 0x4e22c9
    goto L_0x004e22c9;
L_0x004e2394:
    // 004e2394  f6c720                 +test bh, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 32 /*0x20*/));
    // 004e2397  740e                   -je 0x4e23a7
    if (cpu.flags.zf)
    {
        goto L_0x004e23a7;
    }
    // 004e2399  66c70514f69e0044ac     -mov word ptr [0x9ef614], 0xac44
    app->getMemory<x86::reg16>(x86::reg32(10417684) /* 0x9ef614 */) = 44100 /*0xac44*/;
    // 004e23a2  e922ffffff             -jmp 0x4e22c9
    goto L_0x004e22c9;
L_0x004e23a7:
    // 004e23a7  f6c702                 +test bh, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 2 /*0x2*/));
    // 004e23aa  740e                   -je 0x4e23ba
    if (cpu.flags.zf)
    {
        goto L_0x004e23ba;
    }
    // 004e23ac  66c70514f69e00112b     -mov word ptr [0x9ef614], 0x2b11
    app->getMemory<x86::reg16>(x86::reg32(10417684) /* 0x9ef614 */) = 11025 /*0x2b11*/;
    // 004e23b5  e90fffffff             -jmp 0x4e22c9
    goto L_0x004e22c9;
L_0x004e23ba:
    // 004e23ba  b8109b5400             -mov eax, 0x549b10
    cpu.eax = 5544720 /*0x549b10*/;
    // 004e23bf  ba549f5400             -mov edx, 0x549f54
    cpu.edx = 5545812 /*0x549f54*/;
    // 004e23c4  b9f7020000             -mov ecx, 0x2f7
    cpu.ecx = 759 /*0x2f7*/;
    // 004e23c9  68989f5400             -push 0x549f98
    app->getMemory<x86::reg32>(cpu.esp-4) = 5545880 /*0x549f98*/;
    cpu.esp -= 4;
    // 004e23ce  bbf8ffffff             -mov ebx, 0xfffffff8
    cpu.ebx = 4294967288 /*0xfffffff8*/;
    // 004e23d3  a390215500             -mov dword ptr [0x552190], eax
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.eax;
    // 004e23d8  891594215500           -mov dword ptr [0x552194], edx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.edx;
    // 004e23de  890d98215500           -mov dword ptr [0x552198], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ecx;
    // 004e23e4  e827ecf1ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004e23e9  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004e23ec  891d0cf69e00           -mov dword ptr [0x9ef60c], ebx
    app->getMemory<x86::reg32>(x86::reg32(10417676) /* 0x9ef60c */) = cpu.ebx;
    // 004e23f2  c60507f69e0001         -mov byte ptr [0x9ef607], 1
    app->getMemory<x86::reg8>(x86::reg32(10417671) /* 0x9ef607 */) = 1 /*0x1*/;
    // 004e23f9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004e23fb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e23fc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e23fd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e23fe  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x004e2401:
    // 004e2401  803d04f69e0000         +cmp byte ptr [0x9ef604], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(10417668) /* 0x9ef604 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004e2408  740f                   -je 0x4e2419
    if (cpu.flags.zf)
    {
        goto L_0x004e2419;
    }
    // 004e240a  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 004e240c  881504f69e00           -mov byte ptr [0x9ef604], dl
    app->getMemory<x86::reg8>(x86::reg32(10417668) /* 0x9ef604 */) = cpu.dl;
    // 004e2412  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004e2414  e867c8faff             -call 0x48ec80
    cpu.esp -= 4;
    sub_48ec80(app, cpu);
    if (cpu.terminate) return;
L_0x004e2419:
    // 004e2419  803d05f69e0000         +cmp byte ptr [0x9ef605], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(10417669) /* 0x9ef605 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004e2420  740f                   -je 0x4e2431
    if (cpu.flags.zf)
    {
        goto L_0x004e2431;
    }
    // 004e2422  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004e2424  30db                   -xor bl, bl
    cpu.bl ^= x86::reg8(x86::sreg8(cpu.bl));
    // 004e2426  e835a4feff             -call 0x4cc860
    cpu.esp -= 4;
    sub_4cc860(app, cpu);
    if (cpu.terminate) return;
    // 004e242b  881d05f69e00           -mov byte ptr [0x9ef605], bl
    app->getMemory<x86::reg8>(x86::reg32(10417669) /* 0x9ef605 */) = cpu.bl;
L_0x004e2431:
    // 004e2431  ff1524f69e00           -call dword ptr [0x9ef624]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10417700) /* 0x9ef624 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e2437  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004e2439  890d0cf69e00           -mov dword ptr [0x9ef60c], ecx
    app->getMemory<x86::reg32>(x86::reg32(10417676) /* 0x9ef60c */) = cpu.ecx;
    // 004e243f  c60507f69e0001         -mov byte ptr [0x9ef607], 1
    app->getMemory<x86::reg8>(x86::reg32(10417671) /* 0x9ef607 */) = 1 /*0x1*/;
    // 004e2446  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004e2448  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e2449  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e244a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e244b  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4e2450(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e2450  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e2451  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e2452  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004e2453  a310f69e00             -mov dword ptr [0x9ef610], eax
    app->getMemory<x86::reg32>(x86::reg32(10417680) /* 0x9ef610 */) = cpu.eax;
    // 004e2458  c705204456001c1d4e00   -mov dword ptr [0x564420], 0x4e1d1c
    app->getMemory<x86::reg32>(x86::reg32(5653536) /* 0x564420 */) = 5119260 /*0x4e1d1c*/;
    // 004e2462  e86df9ffff             -call 0x4e1dd4
    cpu.esp -= 4;
    sub_4e1dd4(app, cpu);
    if (cpu.terminate) return;
    // 004e2467  833dd843560000         +cmp dword ptr [0x5643d8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5653464) /* 0x5643d8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e246e  7459                   -je 0x4e24c9
    if (cpu.flags.zf)
    {
        goto L_0x004e24c9;
    }
    // 004e2470  e8fb950000             -call 0x4eba70
    cpu.esp -= 4;
    sub_4eba70(app, cpu);
    if (cpu.terminate) return;
    // 004e2475  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e2477  0f8482000000           -je 0x4e24ff
    if (cpu.flags.zf)
    {
        goto L_0x004e24ff;
    }
    // 004e247d  685c224e00             -push 0x4e225c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5120604 /*0x4e225c*/;
    cpu.esp -= 4;
    // 004e2482  6800820000             -push 0x8200
    app->getMemory<x86::reg32>(cpu.esp-4) = 33280 /*0x8200*/;
    cpu.esp -= 4;
    // 004e2487  e844a2feff             -call 0x4cc6d0
    cpu.esp -= 4;
    sub_4cc6d0(app, cpu);
    if (cpu.terminate) return;
    // 004e248c  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 004e248e  882507f69e00           -mov byte ptr [0x9ef607], ah
    app->getMemory<x86::reg8>(x86::reg32(10417671) /* 0x9ef607 */) = cpu.ah;
    // 004e2494  b800820000             -mov eax, 0x8200
    cpu.eax = 33280 /*0x8200*/;
    // 004e2499  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004e249b  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004e249d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004e249f  e81ca3feff             -call 0x4cc7c0
    cpu.esp -= 4;
    sub_4cc7c0(app, cpu);
    if (cpu.terminate) return;
    // 004e24a4  803d07f69e0000         +cmp byte ptr [0x9ef607], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(10417671) /* 0x9ef607 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004e24ab  7513                   -jne 0x4e24c0
    if (!cpu.flags.zf)
    {
        goto L_0x004e24c0;
    }
    // 004e24ad  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x004e24af:
    // 004e24af  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004e24b1  e82ad4ffff             -call 0x4df8e0
    cpu.esp -= 4;
    sub_4df8e0(app, cpu);
    if (cpu.terminate) return;
    // 004e24b6  3a1507f69e00           +cmp dl, byte ptr [0x9ef607]
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(x86::reg32(10417671) /* 0x9ef607 */)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004e24bc  74f1                   -je 0x4e24af
    if (cpu.flags.zf)
    {
        goto L_0x004e24af;
    }
    // 004e24be  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x004e24c0:
    // 004e24c0  a10cf69e00             -mov eax, dword ptr [0x9ef60c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10417676) /* 0x9ef60c */);
    // 004e24c5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e24c6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e24c7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e24c8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e24c9:
    // 004e24c9  bd109b5400             -mov ebp, 0x549b10
    cpu.ebp = 5544720 /*0x549b10*/;
    // 004e24ce  b8bc9f5400             -mov eax, 0x549fbc
    cpu.eax = 5545916 /*0x549fbc*/;
    // 004e24d3  ba49030000             -mov edx, 0x349
    cpu.edx = 841 /*0x349*/;
    // 004e24d8  68c89f5400             -push 0x549fc8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5545928 /*0x549fc8*/;
    cpu.esp -= 4;
    // 004e24dd  892d90215500           -mov dword ptr [0x552190], ebp
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ebp;
    // 004e24e3  a394215500             -mov dword ptr [0x552194], eax
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.eax;
    // 004e24e8  891598215500           -mov dword ptr [0x552198], edx
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.edx;
    // 004e24ee  e81debf1ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004e24f3  b8f0ffffff             -mov eax, 0xfffffff0
    cpu.eax = 4294967280 /*0xfffffff0*/;
    // 004e24f8  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004e24fb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e24fc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e24fd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e24fe  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e24ff:
    // 004e24ff  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004e2500  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e2501  bb109b5400             -mov ebx, 0x549b10
    cpu.ebx = 5544720 /*0x549b10*/;
    // 004e2506  bebc9f5400             -mov esi, 0x549fbc
    cpu.esi = 5545916 /*0x549fbc*/;
    // 004e250b  bf51030000             -mov edi, 0x351
    cpu.edi = 849 /*0x351*/;
    // 004e2510  6804a05400             -push 0x54a004
    app->getMemory<x86::reg32>(cpu.esp-4) = 5545988 /*0x54a004*/;
    cpu.esp -= 4;
    // 004e2515  891d90215500           -mov dword ptr [0x552190], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ebx;
    // 004e251b  893594215500           -mov dword ptr [0x552194], esi
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.esi;
    // 004e2521  893d98215500           -mov dword ptr [0x552198], edi
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.edi;
    // 004e2527  e8e4eaf1ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004e252c  b8f0ffffff             -mov eax, 0xfffffff0
    cpu.eax = 4294967280 /*0xfffffff0*/;
    // 004e2531  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004e2534  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e2535  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e2536  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e2537  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e2538  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e2539  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4e253c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e253c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e253d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e253e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e253f  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 004e2541  882507f69e00           -mov byte ptr [0x9ef607], ah
    app->getMemory<x86::reg8>(x86::reg32(10417671) /* 0x9ef607 */) = cpu.ah;
    // 004e2547  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004e254c  b800820000             -mov eax, 0x8200
    cpu.eax = 33280 /*0x8200*/;
    // 004e2551  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004e2553  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004e2555  e866a2feff             -call 0x4cc7c0
    cpu.esp -= 4;
    sub_4cc7c0(app, cpu);
    if (cpu.terminate) return;
    // 004e255a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e255c  7428                   -je 0x4e2586
    if (cpu.flags.zf)
    {
        goto L_0x004e2586;
    }
L_0x004e255e:
    // 004e255e  803d07f69e0000         +cmp byte ptr [0x9ef607], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(10417671) /* 0x9ef607 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004e2565  7416                   -je 0x4e257d
    if (cpu.flags.zf)
    {
        goto L_0x004e257d;
    }
L_0x004e2567:
    // 004e2567  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004e2569  e80efcffff             -call 0x4e217c
    cpu.esp -= 4;
    sub_4e217c(app, cpu);
    if (cpu.terminate) return;
    // 004e256e  890d20445600           -mov dword ptr [0x564420], ecx
    app->getMemory<x86::reg32>(x86::reg32(5653536) /* 0x564420 */) = cpu.ecx;
    // 004e2574  a10cf69e00             -mov eax, dword ptr [0x9ef60c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10417676) /* 0x9ef60c */);
    // 004e2579  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e257a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e257b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e257c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e257d:
    // 004e257d  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004e257f  e85cd3ffff             -call 0x4df8e0
    cpu.esp -= 4;
    sub_4df8e0(app, cpu);
    if (cpu.terminate) return;
    // 004e2584  ebd8                   -jmp 0x4e255e
    goto L_0x004e255e;
L_0x004e2586:
    // 004e2586  803d04f69e0000         +cmp byte ptr [0x9ef604], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(10417668) /* 0x9ef604 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004e258d  740d                   -je 0x4e259c
    if (cpu.flags.zf)
    {
        goto L_0x004e259c;
    }
    // 004e258f  30f6                   -xor dh, dh
    cpu.dh ^= x86::reg8(x86::sreg8(cpu.dh));
    // 004e2591  883504f69e00           -mov byte ptr [0x9ef604], dh
    app->getMemory<x86::reg8>(x86::reg32(10417668) /* 0x9ef604 */) = cpu.dh;
    // 004e2597  e8e4c6faff             -call 0x48ec80
    cpu.esp -= 4;
    sub_48ec80(app, cpu);
    if (cpu.terminate) return;
L_0x004e259c:
    // 004e259c  803d05f69e0000         +cmp byte ptr [0x9ef605], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(10417669) /* 0x9ef605 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004e25a3  740f                   -je 0x4e25b4
    if (cpu.flags.zf)
    {
        goto L_0x004e25b4;
    }
    // 004e25a5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004e25a7  30ff                   -xor bh, bh
    cpu.bh ^= x86::reg8(x86::sreg8(cpu.bh));
    // 004e25a9  e8b2a2feff             -call 0x4cc860
    cpu.esp -= 4;
    sub_4cc860(app, cpu);
    if (cpu.terminate) return;
    // 004e25ae  883d05f69e00           -mov byte ptr [0x9ef605], bh
    app->getMemory<x86::reg8>(x86::reg32(10417669) /* 0x9ef605 */) = cpu.bh;
L_0x004e25b4:
    // 004e25b4  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004e25b6  89150cf69e00           -mov dword ptr [0x9ef60c], edx
    app->getMemory<x86::reg32>(x86::reg32(10417676) /* 0x9ef60c */) = cpu.edx;
    // 004e25bc  eba9                   -jmp 0x4e2567
    goto L_0x004e2567;
}

/* align: skip  */
void Application::sub_4e257c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004e257c;
    // 004e253c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e253d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e253e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e253f  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 004e2541  882507f69e00           -mov byte ptr [0x9ef607], ah
    app->getMemory<x86::reg8>(x86::reg32(10417671) /* 0x9ef607 */) = cpu.ah;
    // 004e2547  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004e254c  b800820000             -mov eax, 0x8200
    cpu.eax = 33280 /*0x8200*/;
    // 004e2551  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004e2553  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004e2555  e866a2feff             -call 0x4cc7c0
    cpu.esp -= 4;
    sub_4cc7c0(app, cpu);
    if (cpu.terminate) return;
    // 004e255a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e255c  7428                   -je 0x4e2586
    if (cpu.flags.zf)
    {
        goto L_0x004e2586;
    }
L_0x004e255e:
    // 004e255e  803d07f69e0000         +cmp byte ptr [0x9ef607], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(10417671) /* 0x9ef607 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004e2565  7416                   -je 0x4e257d
    if (cpu.flags.zf)
    {
        goto L_0x004e257d;
    }
L_0x004e2567:
    // 004e2567  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004e2569  e80efcffff             -call 0x4e217c
    cpu.esp -= 4;
    sub_4e217c(app, cpu);
    if (cpu.terminate) return;
    // 004e256e  890d20445600           -mov dword ptr [0x564420], ecx
    app->getMemory<x86::reg32>(x86::reg32(5653536) /* 0x564420 */) = cpu.ecx;
    // 004e2574  a10cf69e00             -mov eax, dword ptr [0x9ef60c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10417676) /* 0x9ef60c */);
    // 004e2579  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e257a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e257b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_entry_0x004e257c:
    // 004e257c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e257d:
    // 004e257d  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004e257f  e85cd3ffff             -call 0x4df8e0
    cpu.esp -= 4;
    sub_4df8e0(app, cpu);
    if (cpu.terminate) return;
    // 004e2584  ebd8                   -jmp 0x4e255e
    goto L_0x004e255e;
L_0x004e2586:
    // 004e2586  803d04f69e0000         +cmp byte ptr [0x9ef604], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(10417668) /* 0x9ef604 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004e258d  740d                   -je 0x4e259c
    if (cpu.flags.zf)
    {
        goto L_0x004e259c;
    }
    // 004e258f  30f6                   -xor dh, dh
    cpu.dh ^= x86::reg8(x86::sreg8(cpu.dh));
    // 004e2591  883504f69e00           -mov byte ptr [0x9ef604], dh
    app->getMemory<x86::reg8>(x86::reg32(10417668) /* 0x9ef604 */) = cpu.dh;
    // 004e2597  e8e4c6faff             -call 0x48ec80
    cpu.esp -= 4;
    sub_48ec80(app, cpu);
    if (cpu.terminate) return;
L_0x004e259c:
    // 004e259c  803d05f69e0000         +cmp byte ptr [0x9ef605], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(10417669) /* 0x9ef605 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004e25a3  740f                   -je 0x4e25b4
    if (cpu.flags.zf)
    {
        goto L_0x004e25b4;
    }
    // 004e25a5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004e25a7  30ff                   -xor bh, bh
    cpu.bh ^= x86::reg8(x86::sreg8(cpu.bh));
    // 004e25a9  e8b2a2feff             -call 0x4cc860
    cpu.esp -= 4;
    sub_4cc860(app, cpu);
    if (cpu.terminate) return;
    // 004e25ae  883d05f69e00           -mov byte ptr [0x9ef605], bh
    app->getMemory<x86::reg8>(x86::reg32(10417669) /* 0x9ef605 */) = cpu.bh;
L_0x004e25b4:
    // 004e25b4  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004e25b6  89150cf69e00           -mov dword ptr [0x9ef60c], edx
    app->getMemory<x86::reg32>(x86::reg32(10417676) /* 0x9ef60c */) = cpu.edx;
    // 004e25bc  eba9                   -jmp 0x4e2567
    goto L_0x004e2567;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4e25c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e25c0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e25c1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e25c2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e25c3  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004e25c5  c1e204                 -shl edx, 4
    cpu.edx <<= 4 /*0x4*/ % 32;
    // 004e25c8  81c258f69e00           -add edx, 0x9ef658
    (cpu.edx) += x86::reg32(x86::sreg32(10417752 /*0x9ef658*/));
    // 004e25ce  8a5a05                 -mov bl, byte ptr [edx + 5]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5) /* 0x5 */);
    // 004e25d1  84db                   +test bl, bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.bl));
    // 004e25d3  741a                   -je 0x4e25ef
    if (cpu.flags.zf)
    {
        goto L_0x004e25ef;
    }
    // 004e25d5  80fb01                 +cmp bl, 1
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004e25d8  7415                   -je 0x4e25ef
    if (cpu.flags.zf)
    {
        goto L_0x004e25ef;
    }
    // 004e25da  80fb02                 +cmp bl, 2
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(2 /*0x2*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004e25dd  7410                   -je 0x4e25ef
    if (cpu.flags.zf)
    {
        goto L_0x004e25ef;
    }
    // 004e25df  80fb03                 +cmp bl, 3
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(3 /*0x3*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004e25e2  7514                   -jne 0x4e25f8
    if (!cpu.flags.zf)
    {
        goto L_0x004e25f8;
    }
    // 004e25e4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e25e5  ff1550f69e00           -call dword ptr [0x9ef650]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10417744) /* 0x9ef650 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e25eb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e25ec  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e25ed  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e25ee  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e25ef:
    // 004e25ef  e810e00100             -call 0x500604
    cpu.esp -= 4;
    sub_500604(app, cpu);
    if (cpu.terminate) return;
    // 004e25f4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e25f5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e25f6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e25f7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e25f8:
    // 004e25f8  ba109b5400             -mov edx, 0x549b10
    cpu.edx = 5544720 /*0x549b10*/;
    // 004e25fd  b960a05400             -mov ecx, 0x54a060
    cpu.ecx = 5546080 /*0x54a060*/;
    // 004e2602  bba3030000             -mov ebx, 0x3a3
    cpu.ebx = 931 /*0x3a3*/;
    // 004e2607  686ca05400             -push 0x54a06c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5546092 /*0x54a06c*/;
    cpu.esp -= 4;
    // 004e260c  891590215500           -mov dword ptr [0x552190], edx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edx;
    // 004e2612  890d94215500           -mov dword ptr [0x552194], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ecx;
    // 004e2618  891d98215500           -mov dword ptr [0x552198], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ebx;
    // 004e261e  e8ede9f1ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004e2623  b8f9ffffff             -mov eax, 0xfffffff9
    cpu.eax = 4294967289 /*0xfffffff9*/;
    // 004e2628  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004e262b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e262c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e262d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e262e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_4e2630(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e2630  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e2631  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e2632  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004e2633  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004e2635  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004e2637  803df49aa00000         +cmp byte ptr [0xa09af4], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(10525428) /* 0xa09af4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004e263e  7558                   -jne 0x4e2698
    if (!cpu.flags.zf)
    {
        goto L_0x004e2698;
    }
    // 004e2640  803df69aa00000         +cmp byte ptr [0xa09af6], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(10525430) /* 0xa09af6 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004e2647  7455                   -je 0x4e269e
    if (cpu.flags.zf)
    {
        goto L_0x004e269e;
    }
L_0x004e2649:
    // 004e2649  833d089ba00000         +cmp dword ptr [0xa09b08], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10525448) /* 0xa09b08 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e2650  750a                   -jne 0x4e265c
    if (!cpu.flags.zf)
    {
        goto L_0x004e265c;
    }
    // 004e2652  c705089ba000800c5000   -mov dword ptr [0xa09b08], 0x500c80
    app->getMemory<x86::reg32>(x86::reg32(10525448) /* 0xa09b08 */) = 5246080 /*0x500c80*/;
L_0x004e265c:
    // 004e265c  e87f8c0000             -call 0x4eb2e0
    cpu.esp -= 4;
    sub_4eb2e0(app, cpu);
    if (cpu.terminate) return;
    // 004e2661  a3049ba000             -mov dword ptr [0xa09b04], eax
    app->getMemory<x86::reg32>(x86::reg32(10525444) /* 0xa09b04 */) = cpu.eax;
    // 004e2666  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004e2668  893dfc9aa000           -mov dword ptr [0xa09afc], edi
    app->getMemory<x86::reg32>(x86::reg32(10525436) /* 0xa09afc */) = cpu.edi;
    // 004e266e  893d009ba000           -mov dword ptr [0xa09b00], edi
    app->getMemory<x86::reg32>(x86::reg32(10525440) /* 0xa09b00 */) = cpu.edi;
    // 004e2674  c605f59aa0007f         -mov byte ptr [0xa09af5], 0x7f
    app->getMemory<x86::reg8>(x86::reg32(10525429) /* 0xa09af5 */) = 127 /*0x7f*/;
    // 004e267b  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004e267d  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004e267f  e8d0000000             -call 0x4e2754
    cpu.esp -= 4;
    sub_4e2754(app, cpu);
    if (cpu.terminate) return;
    // 004e2684  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004e2686  e8c5fdffff             -call 0x4e2450
    cpu.esp -= 4;
    sub_4e2450(app, cpu);
    if (cpu.terminate) return;
    // 004e268b  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004e268d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e268f  7c16                   -jl 0x4e26a7
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004e26a7;
    }
    // 004e2691  c605f49aa00001         -mov byte ptr [0xa09af4], 1
    app->getMemory<x86::reg8>(x86::reg32(10525428) /* 0xa09af4 */) = 1 /*0x1*/;
L_0x004e2698:
    // 004e2698  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004e269a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e269b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e269c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e269d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e269e:
    // 004e269e  c605f69aa00010         -mov byte ptr [0xa09af6], 0x10
    app->getMemory<x86::reg8>(x86::reg32(10525430) /* 0xa09af6 */) = 16 /*0x10*/;
    // 004e26a5  eba2                   -jmp 0x4e2649
    goto L_0x004e2649;
L_0x004e26a7:
    // 004e26a7  e890feffff             -call 0x4e253c
    cpu.esp -= 4;
    sub_4e253c(app, cpu);
    if (cpu.terminate) return;
    // 004e26ac  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004e26ae  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e26af  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e26b0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e26b1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4e26b4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e26b4  803df49aa00000         +cmp byte ptr [0xa09af4], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(10525428) /* 0xa09af4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004e26bb  0f8482000000           -je 0x4e2743
    if (cpu.flags.zf)
    {
        goto L_0x004e2743;
    }
    // 004e26c1  833d349ba00000         +cmp dword ptr [0xa09b34], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10525492) /* 0xa09b34 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e26c8  0f857b000000           -jne 0x4e2749
    if (!cpu.flags.zf)
    {
        goto L_0x004e2749;
    }
L_0x004e26ce:
    // 004e26ce  833d389ba00000         +cmp dword ptr [0xa09b38], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10525496) /* 0xa09b38 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e26d5  7406                   -je 0x4e26dd
    if (cpu.flags.zf)
    {
        goto L_0x004e26dd;
    }
    // 004e26d7  ff15389ba000           -call dword ptr [0xa09b38]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10525496) /* 0xa09b38 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004e26dd:
    // 004e26dd  833d2c9ba00000         +cmp dword ptr [0xa09b2c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10525484) /* 0xa09b2c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e26e4  7406                   -je 0x4e26ec
    if (cpu.flags.zf)
    {
        goto L_0x004e26ec;
    }
    // 004e26e6  ff152c9ba000           -call dword ptr [0xa09b2c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10525484) /* 0xa09b2c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004e26ec:
    // 004e26ec  833d309ba00000         +cmp dword ptr [0xa09b30], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10525488) /* 0xa09b30 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e26f3  7406                   -je 0x4e26fb
    if (cpu.flags.zf)
    {
        goto L_0x004e26fb;
    }
    // 004e26f5  ff15309ba000           -call dword ptr [0xa09b30]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10525488) /* 0xa09b30 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004e26fb:
    // 004e26fb  833d289ba00000         +cmp dword ptr [0xa09b28], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10525480) /* 0xa09b28 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e2702  7406                   -je 0x4e270a
    if (cpu.flags.zf)
    {
        goto L_0x004e270a;
    }
    // 004e2704  ff15289ba000           -call dword ptr [0xa09b28]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10525480) /* 0xa09b28 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004e270a:
    // 004e270a  e801690000             -call 0x4e9010
    cpu.esp -= 4;
    sub_4e9010(app, cpu);
    if (cpu.terminate) return;
    // 004e270f  833d249ba00000         +cmp dword ptr [0xa09b24], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10525476) /* 0xa09b24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e2716  740b                   -je 0x4e2723
    if (cpu.flags.zf)
    {
        goto L_0x004e2723;
    }
    // 004e2718  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004e271d  ff15249ba000           -call dword ptr [0xa09b24]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10525476) /* 0xa09b24 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004e2723:
    // 004e2723  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e2724  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e2725  e812feffff             -call 0x4e253c
    cpu.esp -= 4;
    sub_4e253c(app, cpu);
    if (cpu.terminate) return;
    // 004e272a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004e272c  30db                   +xor bl, bl
    cpu.clear_co();
    cpu.set_szp((cpu.bl ^= x86::reg8(x86::sreg8(cpu.bl))));
    // 004e272e  a1049ba000             -mov eax, dword ptr [0xa09b04]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10525444) /* 0xa09b04 */);
    // 004e2733  881df49aa000           -mov byte ptr [0xa09af4], bl
    app->getMemory<x86::reg8>(x86::reg32(10525428) /* 0xa09af4 */) = cpu.bl;
    // 004e2739  e8228c0000             -call 0x4eb360
    cpu.esp -= 4;
    sub_4eb360(app, cpu);
    if (cpu.terminate) return;
    // 004e273e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004e2740  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e2741  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e2742  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e2743:
    // 004e2743  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 004e2748  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e2749:
    // 004e2749  ff15349ba000           -call dword ptr [0xa09b34]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10525492) /* 0xa09b34 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e274f  e97affffff             -jmp 0x4e26ce
    goto L_0x004e26ce;
}

/* align: skip  */
void Application::sub_4e2754(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e2754  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e2755  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e2756  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e2757  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004e2758  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004e275a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004e275c  e84ffaffff             -call 0x4e21b0
    cpu.esp -= 4;
    sub_4e21b0(app, cpu);
    if (cpu.terminate) return;
    // 004e2761  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004e2763  83f9ff                 +cmp ecx, -1
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
    // 004e2766  7555                   -jne 0x4e27bd
    if (!cpu.flags.zf)
    {
        goto L_0x004e27bd;
    }
L_0x004e2768:
    // 004e2768  21d0                   -and eax, edx
    cpu.eax &= x86::reg32(x86::sreg32(cpu.edx));
    // 004e276a  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004e276c  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004e276e  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004e2770  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004e2776  81e200ff0000           -and edx, 0xff00
    cpu.edx &= x86::reg32(x86::sreg32(65280 /*0xff00*/));
    // 004e277c  81e60000ff00           -and esi, 0xff0000
    cpu.esi &= x86::reg32(x86::sreg32(16711680 /*0xff0000*/));
    // 004e2782  83f9ff                 +cmp ecx, -1
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
    // 004e2785  7502                   -jne 0x4e2789
    if (!cpu.flags.zf)
    {
        goto L_0x004e2789;
    }
    // 004e2787  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x004e2789:
    // 004e2789  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004e278b  7434                   -je 0x4e27c1
    if (cpu.flags.zf)
    {
        goto L_0x004e27c1;
    }
    // 004e278d  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004e278f  7467                   -je 0x4e27f8
    if (cpu.flags.zf)
    {
        goto L_0x004e27f8;
    }
    // 004e2791  f6c308                 +test bl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 8 /*0x8*/));
    // 004e2794  0f8493000000           -je 0x4e282d
    if (cpu.flags.zf)
    {
        goto L_0x004e282d;
    }
    // 004e279a  b808000000             -mov eax, 8
    cpu.eax = 8 /*0x8*/;
L_0x004e279f:
    // 004e279f  f6c608                 +test dh, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 8 /*0x8*/));
    // 004e27a2  0f84ad000000           -je 0x4e2855
    if (cpu.flags.zf)
    {
        goto L_0x004e2855;
    }
    // 004e27a8  80cc08                 -or ah, 8
    cpu.ah |= x86::reg8(x86::sreg8(8 /*0x8*/));
L_0x004e27ab:
    // 004e27ab  f7c600000200           +test esi, 0x20000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & 131072 /*0x20000*/));
    // 004e27b1  7405                   -je 0x4e27b8
    if (cpu.flags.zf)
    {
        goto L_0x004e27b8;
    }
    // 004e27b3  0d00000200             +or eax, 0x20000
    cpu.clear_co();
    cpu.set_szp((cpu.eax |= x86::reg32(x86::sreg32(131072 /*0x20000*/))));
L_0x004e27b8:
    // 004e27b8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e27b9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e27ba  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e27bb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e27bc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e27bd:
    // 004e27bd  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004e27bf  eba7                   -jmp 0x4e2768
    goto L_0x004e2768;
L_0x004e27c1:
    // 004e27c1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004e27c2  be98a05400             -mov esi, 0x54a098
    cpu.esi = 5546136 /*0x54a098*/;
    // 004e27c7  bfa4a05400             -mov edi, 0x54a0a4
    cpu.edi = 5546148 /*0x54a0a4*/;
    // 004e27cc  bdfc000000             -mov ebp, 0xfc
    cpu.ebp = 252 /*0xfc*/;
    // 004e27d1  68b4a05400             -push 0x54a0b4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5546164 /*0x54a0b4*/;
    cpu.esp -= 4;
    // 004e27d6  893590215500           -mov dword ptr [0x552190], esi
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.esi;
    // 004e27dc  893d94215500           -mov dword ptr [0x552194], edi
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.edi;
    // 004e27e2  892d98215500           -mov dword ptr [0x552198], ebp
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ebp;
    // 004e27e8  e823e8f1ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004e27ed  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004e27f0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004e27f2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e27f3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e27f4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e27f5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e27f6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e27f7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e27f8:
    // 004e27f8  ba98a05400             -mov edx, 0x54a098
    cpu.edx = 5546136 /*0x54a098*/;
    // 004e27fd  b9a4a05400             -mov ecx, 0x54a0a4
    cpu.ecx = 5546148 /*0x54a0a4*/;
    // 004e2802  bb04010000             -mov ebx, 0x104
    cpu.ebx = 260 /*0x104*/;
    // 004e2807  6800a15400             -push 0x54a100
    app->getMemory<x86::reg32>(cpu.esp-4) = 5546240 /*0x54a100*/;
    cpu.esp -= 4;
    // 004e280c  891590215500           -mov dword ptr [0x552190], edx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edx;
    // 004e2812  890d94215500           -mov dword ptr [0x552194], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ecx;
    // 004e2818  891d98215500           -mov dword ptr [0x552198], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ebx;
    // 004e281e  e8ede7f1ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004e2823  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004e2826  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004e2828  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e2829  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e282a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e282b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e282c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e282d:
    // 004e282d  f6c302                 +test bl, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 2 /*0x2*/));
    // 004e2830  740a                   -je 0x4e283c
    if (cpu.flags.zf)
    {
        goto L_0x004e283c;
    }
    // 004e2832  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 004e2837  e963ffffff             -jmp 0x4e279f
    goto L_0x004e279f;
L_0x004e283c:
    // 004e283c  f6c304                 +test bl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 4 /*0x4*/));
    // 004e283f  740a                   -je 0x4e284b
    if (cpu.flags.zf)
    {
        goto L_0x004e284b;
    }
    // 004e2841  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 004e2846  e954ffffff             -jmp 0x4e279f
    goto L_0x004e279f;
L_0x004e284b:
    // 004e284b  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004e2850  e94affffff             -jmp 0x4e279f
    goto L_0x004e279f;
L_0x004e2855:
    // 004e2855  f6c610                 +test dh, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 16 /*0x10*/));
    // 004e2858  7408                   -je 0x4e2862
    if (cpu.flags.zf)
    {
        goto L_0x004e2862;
    }
    // 004e285a  80cc10                 +or ah, 0x10
    cpu.clear_co();
    cpu.set_szp((cpu.ah |= x86::reg8(x86::sreg8(16 /*0x10*/))));
    // 004e285d  e949ffffff             -jmp 0x4e27ab
    goto L_0x004e27ab;
L_0x004e2862:
    // 004e2862  f6c604                 +test dh, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 4 /*0x4*/));
    // 004e2865  7408                   -je 0x4e286f
    if (cpu.flags.zf)
    {
        goto L_0x004e286f;
    }
    // 004e2867  80cc04                 +or ah, 4
    cpu.clear_co();
    cpu.set_szp((cpu.ah |= x86::reg8(x86::sreg8(4 /*0x4*/))));
    // 004e286a  e93cffffff             -jmp 0x4e27ab
    goto L_0x004e27ab;
L_0x004e286f:
    // 004e286f  f6c620                 +test dh, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 32 /*0x20*/));
    // 004e2872  7408                   -je 0x4e287c
    if (cpu.flags.zf)
    {
        goto L_0x004e287c;
    }
    // 004e2874  80cc20                 +or ah, 0x20
    cpu.clear_co();
    cpu.set_szp((cpu.ah |= x86::reg8(x86::sreg8(32 /*0x20*/))));
    // 004e2877  e92fffffff             -jmp 0x4e27ab
    goto L_0x004e27ab;
L_0x004e287c:
    // 004e287c  f6c602                 +test dh, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 2 /*0x2*/));
    // 004e287f  7408                   -je 0x4e2889
    if (cpu.flags.zf)
    {
        goto L_0x004e2889;
    }
    // 004e2881  80cc02                 +or ah, 2
    cpu.clear_co();
    cpu.set_szp((cpu.ah |= x86::reg8(x86::sreg8(2 /*0x2*/))));
    // 004e2884  e922ffffff             -jmp 0x4e27ab
    goto L_0x004e27ab;
L_0x004e2889:
    // 004e2889  80cc01                 +or ah, 1
    cpu.clear_co();
    cpu.set_szp((cpu.ah |= x86::reg8(x86::sreg8(1 /*0x1*/))));
    // 004e288c  e91affffff             -jmp 0x4e27ab
    goto L_0x004e27ab;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4e28a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e28a0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e28a1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e28a2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e28a3  2eff15b0445300         -call dword ptr cs:[0x5344b0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457072) /* 0x5344b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e28aa  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e28ac  7508                   -jne 0x4e28b6
    if (!cpu.flags.zf)
    {
        goto L_0x004e28b6;
    }
    // 004e28ae  e841e70100             -call 0x500ff4
    cpu.esp -= 4;
    sub_500ff4(app, cpu);
    if (cpu.terminate) return;
    // 004e28b3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e28b4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e28b5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e28b6:
    // 004e28b6  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004e28b8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e28b9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e28ba  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4e28c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e28c0  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004e28c2  e9690b0000             -jmp 0x4e3430
    return sub_4e3430(app, cpu);
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_4e28d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e28d0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e28d1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004e28d2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004e28d3  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004e28d6  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004e28da  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004e28dc  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 004e28de  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 004e28e0  ba05020000             -mov edx, 0x205
    cpu.edx = 517 /*0x205*/;
    // 004e28e5  bb48a15400             -mov ebx, 0x54a148
    cpu.ebx = 5546312 /*0x54a148*/;
    // 004e28ea  b858a15400             -mov eax, 0x54a158
    cpu.eax = 5546328 /*0x54a158*/;
    // 004e28ef  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004e28f1  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004e28f5  894c2410               -mov dword ptr [esp + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 004e28f9  891d90215500           -mov dword ptr [0x552190], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ebx;
    // 004e28ff  ba9b000000             -mov edx, 0x9b
    cpu.edx = 155 /*0x9b*/;
    // 004e2904  a394215500             -mov dword ptr [0x552194], eax
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.eax;
    // 004e2909  891598215500           -mov dword ptr [0x552198], edx
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.edx;
    // 004e290f  e8fce60100             -call 0x501010
    cpu.esp -= 4;
    sub_501010(app, cpu);
    if (cpu.terminate) return;
    // 004e2914  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004e2916  7504                   -jne 0x4e291c
    if (!cpu.flags.zf)
    {
        goto L_0x004e291c;
    }
    // 004e2918  8d6c2404               -lea ebp, [esp + 4]
    cpu.ebp = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
L_0x004e291c:
    // 004e291c  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004e291e  7502                   -jne 0x4e2922
    if (!cpu.flags.zf)
    {
        goto L_0x004e2922;
    }
    // 004e2920  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
L_0x004e2922:
    // 004e2922  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004e2926  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004e292a  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004e292c  c70700000000           -mov dword ptr [edi], 0
    app->getMemory<x86::reg32>(cpu.edi) = 0 /*0x0*/;
    // 004e2932  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004e2934  c7450000000000         -mov dword ptr [ebp], 0
    app->getMemory<x86::reg32>(cpu.ebp) = 0 /*0x0*/;
    // 004e293b  e8e00c0000             -call 0x4e3620
    cpu.esp -= 4;
    sub_4e3620(app, cpu);
    if (cpu.terminate) return;
    // 004e2940  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e2942  0f85e8000000           -jne 0x4e2a30
    if (!cpu.flags.zf)
    {
        goto L_0x004e2a30;
    }
    // 004e2948  833d8845560000         +cmp dword ptr [0x564588], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5653896) /* 0x564588 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e294f  0f846f000000           -je 0x4e29c4
    if (cpu.flags.zf)
    {
        goto L_0x004e29c4;
    }
    // 004e2955  803d0445560000         +cmp byte ptr [0x564504], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5653764) /* 0x564504 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004e295c  7466                   -je 0x4e29c4
    if (cpu.flags.zf)
    {
        goto L_0x004e29c4;
    }
    // 004e295e  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004e2962  b804455600             -mov eax, 0x564504
    cpu.eax = 5653764 /*0x564504*/;
    // 004e2967  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004e2969  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004e296b  e8b00c0000             -call 0x4e3620
    cpu.esp -= 4;
    sub_4e3620(app, cpu);
    if (cpu.terminate) return;
    // 004e2970  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e2972  7450                   -je 0x4e29c4
    if (cpu.flags.zf)
    {
        goto L_0x004e29c4;
    }
    // 004e2974  8b1d90455600           -mov ebx, dword ptr [0x564590]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5653904) /* 0x564590 */);
    // 004e297a  8b1584455600           -mov edx, dword ptr [0x564584]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5653892) /* 0x564584 */);
    // 004e2980  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004e2982  e859110000             -call 0x4e3ae0
    cpu.esp -= 4;
    sub_4e3ae0(app, cpu);
    if (cpu.terminate) return;
    // 004e2987  a390455600             -mov dword ptr [0x564590], eax
    app->getMemory<x86::reg32>(x86::reg32(5653904) /* 0x564590 */) = cpu.eax;
    // 004e298c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e298e  7423                   -je 0x4e29b3
    if (cpu.flags.zf)
    {
        goto L_0x004e29b3;
    }
    // 004e2990  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004e2994  a184455600             -mov eax, dword ptr [0x564584]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653892) /* 0x564584 */);
    // 004e2999  ff1588455600           -call dword ptr [0x564588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5653896) /* 0x564588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e299f  894500                 -mov dword ptr [ebp], eax
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.eax;
    // 004e29a2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e29a4  740d                   -je 0x4e29b3
    if (cpu.flags.zf)
    {
        goto L_0x004e29b3;
    }
    // 004e29a6  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004e29a8  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004e29aa  e8b1140000             -call 0x4e3e60
    cpu.esp -= 4;
    sub_4e3e60(app, cpu);
    if (cpu.terminate) return;
    // 004e29af  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e29b1  752c                   -jne 0x4e29df
    if (!cpu.flags.zf)
    {
        goto L_0x004e29df;
    }
L_0x004e29b3:
    // 004e29b3  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004e29b7  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004e29b9  7509                   -jne 0x4e29c4
    if (!cpu.flags.zf)
    {
        goto L_0x004e29c4;
    }
    // 004e29bb  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004e29bd  e81e160000             -call 0x4e3fe0
    cpu.esp -= 4;
    sub_4e3fe0(app, cpu);
    if (cpu.terminate) return;
    // 004e29c2  890e                   -mov dword ptr [esi], ecx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.ecx;
L_0x004e29c4:
    // 004e29c4  837c241000             +cmp dword ptr [esp + 0x10], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e29c9  7509                   -jne 0x4e29d4
    if (!cpu.flags.zf)
    {
        goto L_0x004e29d4;
    }
    // 004e29cb  833d0c44560000         +cmp dword ptr [0x56440c], 0
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
    // 004e29d2  751f                   -jne 0x4e29f3
    if (!cpu.flags.zf)
    {
        goto L_0x004e29f3;
    }
L_0x004e29d4:
    // 004e29d4  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004e29d8  83c414                 +add esp, 0x14
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(20 /*0x14*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004e29db  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e29dc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e29dd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e29de  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e29df:
    // 004e29df  a18c455600             -mov eax, dword ptr [0x56458c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653900) /* 0x56458c */);
    // 004e29e4  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 004e29e9  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004e29eb  894c2410               -mov dword ptr [esp + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 004e29ef  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 004e29f1  ebe1                   -jmp 0x4e29d4
    goto L_0x004e29d4;
L_0x004e29f3:
    // 004e29f3  bf48a15400             -mov edi, 0x54a148
    cpu.edi = 5546312 /*0x54a148*/;
    // 004e29f8  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004e29fc  bd58a15400             -mov ebp, 0x54a158
    cpu.ebp = 5546328 /*0x54a158*/;
    // 004e2a01  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e2a02  b8ba000000             -mov eax, 0xba
    cpu.eax = 186 /*0xba*/;
    // 004e2a07  893d90215500           -mov dword ptr [0x552190], edi
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edi;
    // 004e2a0d  6864a15400             -push 0x54a164
    app->getMemory<x86::reg32>(cpu.esp-4) = 5546340 /*0x54a164*/;
    cpu.esp -= 4;
    // 004e2a12  892d94215500           -mov dword ptr [0x552194], ebp
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebp;
    // 004e2a18  a398215500             -mov dword ptr [0x552198], eax
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.eax;
    // 004e2a1d  e8eee5f1ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004e2a22  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004e2a25  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004e2a29  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004e2a2c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e2a2d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e2a2e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e2a2f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e2a30:
    // 004e2a30  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 004e2a35  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004e2a37  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004e2a39  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004e2a3b  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004e2a3d  894c2414               -mov dword ptr [esp + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 004e2a41  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 004e2a43  e8380f0000             -call 0x4e3980
    cpu.esp -= 4;
    sub_4e3980(app, cpu);
    if (cpu.terminate) return;
    // 004e2a48  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e2a4a  7588                   -jne 0x4e29d4
    if (!cpu.flags.zf)
    {
        goto L_0x004e29d4;
    }
    // 004e2a4c  833d0c44560000         +cmp dword ptr [0x56440c], 0
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
    // 004e2a53  7432                   -je 0x4e2a87
    if (cpu.flags.zf)
    {
        goto L_0x004e2a87;
    }
    // 004e2a55  bd48a15400             -mov ebp, 0x54a148
    cpu.ebp = 5546312 /*0x54a148*/;
    // 004e2a5a  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004e2a5e  b858a15400             -mov eax, 0x54a158
    cpu.eax = 5546328 /*0x54a158*/;
    // 004e2a63  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e2a64  bac1000000             -mov edx, 0xc1
    cpu.edx = 193 /*0xc1*/;
    // 004e2a69  892d90215500           -mov dword ptr [0x552190], ebp
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ebp;
    // 004e2a6f  6888a15400             -push 0x54a188
    app->getMemory<x86::reg32>(cpu.esp-4) = 5546376 /*0x54a188*/;
    cpu.esp -= 4;
    // 004e2a74  a394215500             -mov dword ptr [0x552194], eax
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.eax;
    // 004e2a79  891598215500           -mov dword ptr [0x552198], edx
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.edx;
    // 004e2a7f  e88ce5f1ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004e2a84  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x004e2a87:
    // 004e2a87  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004e2a89  e852150000             -call 0x4e3fe0
    cpu.esp -= 4;
    sub_4e3fe0(app, cpu);
    if (cpu.terminate) return;
    // 004e2a8e  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004e2a90  c70600000000           -mov dword ptr [esi], 0
    app->getMemory<x86::reg32>(cpu.esi) = 0 /*0x0*/;
    // 004e2a96  895c2410               -mov dword ptr [esp + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 004e2a9a  c70700000000           -mov dword ptr [edi], 0
    app->getMemory<x86::reg32>(cpu.edi) = 0 /*0x0*/;
    // 004e2aa0  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004e2aa4  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004e2aa7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e2aa8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e2aa9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e2aaa  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_4e2ab0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e2ab0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e2ab1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004e2ab2  8b7c240c               -mov edi, dword ptr [esp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004e2ab6  8b350c445600           -mov esi, dword ptr [0x56440c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5653516) /* 0x56440c */);
    // 004e2abc  893d0c445600           -mov dword ptr [0x56440c], edi
    app->getMemory<x86::reg32>(x86::reg32(5653516) /* 0x56440c */) = cpu.edi;
    // 004e2ac2  e809feffff             -call 0x4e28d0
    cpu.esp -= 4;
    sub_4e28d0(app, cpu);
    if (cpu.terminate) return;
    // 004e2ac7  89350c445600           -mov dword ptr [0x56440c], esi
    app->getMemory<x86::reg32>(x86::reg32(5653516) /* 0x56440c */) = cpu.esi;
    // 004e2acd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e2ace  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e2acf  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_4e2ae0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e2ae0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e2ae1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004e2ae2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004e2ae3  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004e2ae6  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004e2ae8  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004e2aea  895c2408               -mov dword ptr [esp + 8], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 004e2aee  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004e2af0  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004e2af2  745a                   -je 0x4e2b4e
    if (cpu.flags.zf)
    {
        goto L_0x004e2b4e;
    }
L_0x004e2af4:
    // 004e2af4  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004e2af6  7502                   -jne 0x4e2afa
    if (!cpu.flags.zf)
    {
        goto L_0x004e2afa;
    }
    // 004e2af8  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
L_0x004e2afa:
    // 004e2afa  b948a15400             -mov ecx, 0x54a148
    cpu.ecx = 5546312 /*0x54a148*/;
    // 004e2aff  bbaca15400             -mov ebx, 0x54a1ac
    cpu.ebx = 5546412 /*0x54a1ac*/;
    // 004e2b04  b8df000000             -mov eax, 0xdf
    cpu.eax = 223 /*0xdf*/;
    // 004e2b09  ba32020000             -mov edx, 0x232
    cpu.edx = 562 /*0x232*/;
    // 004e2b0e  890d90215500           -mov dword ptr [0x552190], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ecx;
    // 004e2b14  a398215500             -mov dword ptr [0x552198], eax
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.eax;
    // 004e2b19  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004e2b1b  891d94215500           -mov dword ptr [0x552194], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebx;
    // 004e2b21  e8eae40100             -call 0x501010
    cpu.esp -= 4;
    sub_501010(app, cpu);
    if (cpu.terminate) return;
    // 004e2b26  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 004e2b28  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004e2b2a  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004e2b2c  e8ef0a0000             -call 0x4e3620
    cpu.esp -= 4;
    sub_4e3620(app, cpu);
    if (cpu.terminate) return;
    // 004e2b31  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e2b33  7523                   -jne 0x4e2b58
    if (!cpu.flags.zf)
    {
        goto L_0x004e2b58;
    }
    // 004e2b35  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 004e2b37  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 004e2b39  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
L_0x004e2b3b:
    // 004e2b3b  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004e2b3f  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 004e2b45  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004e2b47  83c40c                 +add esp, 0xc
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
    // 004e2b4a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e2b4b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e2b4c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e2b4d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e2b4e:
    // 004e2b4e  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004e2b52  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004e2b56  eb9c                   -jmp 0x4e2af4
    goto L_0x004e2af4;
L_0x004e2b58:
    // 004e2b58  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004e2b5a  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004e2b5c  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 004e2b5e  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004e2b60  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004e2b62  bd01000000             -mov ebp, 1
    cpu.ebp = 1 /*0x1*/;
    // 004e2b67  e8140e0000             -call 0x4e3980
    cpu.esp -= 4;
    sub_4e3980(app, cpu);
    if (cpu.terminate) return;
    // 004e2b6c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e2b6e  75cb                   -jne 0x4e2b3b
    if (!cpu.flags.zf)
    {
        goto L_0x004e2b3b;
    }
    // 004e2b70  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 004e2b72  e869140000             -call 0x4e3fe0
    cpu.esp -= 4;
    sub_4e3fe0(app, cpu);
    if (cpu.terminate) return;
    // 004e2b77  c70700000000           -mov dword ptr [edi], 0
    app->getMemory<x86::reg32>(cpu.edi) = 0 /*0x0*/;
    // 004e2b7d  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 004e2b7f  c70600000000           -mov dword ptr [esi], 0
    app->getMemory<x86::reg32>(cpu.esi) = 0 /*0x0*/;
    // 004e2b85  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004e2b89  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 004e2b8f  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004e2b91  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004e2b94  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e2b95  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e2b96  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e2b97  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_4e2ba0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e2ba0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e2ba1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004e2ba2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004e2ba3  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004e2ba6  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004e2ba8  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004e2baa  895c2410               -mov dword ptr [esp + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 004e2bae  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 004e2bb0  ba05080000             -mov edx, 0x805
    cpu.edx = 2053 /*0x805*/;
    // 004e2bb5  bb48a15400             -mov ebx, 0x54a148
    cpu.ebx = 5546312 /*0x54a148*/;
    // 004e2bba  b8b8a15400             -mov eax, 0x54a1b8
    cpu.eax = 5546424 /*0x54a1b8*/;
    // 004e2bbf  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004e2bc1  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004e2bc5  894c240c               -mov dword ptr [esp + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 004e2bc9  891d90215500           -mov dword ptr [0x552190], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ebx;
    // 004e2bcf  a394215500             -mov dword ptr [0x552194], eax
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.eax;
    // 004e2bd4  ba41010000             -mov edx, 0x141
    cpu.edx = 321 /*0x141*/;
    // 004e2bd9  b8c8a15400             -mov eax, 0x54a1c8
    cpu.eax = 5546440 /*0x54a1c8*/;
    // 004e2bde  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004e2be2  891598215500           -mov dword ptr [0x552198], edx
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.edx;
    // 004e2be8  e823e40100             -call 0x501010
    cpu.esp -= 4;
    sub_501010(app, cpu);
    if (cpu.terminate) return;
    // 004e2bed  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004e2bef  746d                   -je 0x4e2c5e
    if (cpu.flags.zf)
    {
        goto L_0x004e2c5e;
    }
L_0x004e2bf1:
    // 004e2bf1  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004e2bf3  7502                   -jne 0x4e2bf7
    if (!cpu.flags.zf)
    {
        goto L_0x004e2bf7;
    }
    // 004e2bf5  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
L_0x004e2bf7:
    // 004e2bf7  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004e2bfb  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004e2bff  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004e2c01  c70700000000           -mov dword ptr [edi], 0
    app->getMemory<x86::reg32>(cpu.edi) = 0 /*0x0*/;
    // 004e2c07  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004e2c09  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 004e2c0f  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004e2c11  e80a0a0000             -call 0x4e3620
    cpu.esp -= 4;
    sub_4e3620(app, cpu);
    if (cpu.terminate) return;
    // 004e2c16  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e2c18  754e                   -jne 0x4e2c68
    if (!cpu.flags.zf)
    {
        goto L_0x004e2c68;
    }
    // 004e2c1a  833d8845560000         +cmp dword ptr [0x564588], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5653896) /* 0x564588 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e2c21  7423                   -je 0x4e2c46
    if (cpu.flags.zf)
    {
        goto L_0x004e2c46;
    }
    // 004e2c23  803d0445560000         +cmp byte ptr [0x564504], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5653764) /* 0x564504 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004e2c2a  741a                   -je 0x4e2c46
    if (cpu.flags.zf)
    {
        goto L_0x004e2c46;
    }
    // 004e2c2c  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004e2c30  b804455600             -mov eax, 0x564504
    cpu.eax = 5653764 /*0x564504*/;
    // 004e2c35  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004e2c37  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004e2c39  e8e2090000             -call 0x4e3620
    cpu.esp -= 4;
    sub_4e3620(app, cpu);
    if (cpu.terminate) return;
    // 004e2c3e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e2c40  0f85a0000000           -jne 0x4e2ce6
    if (!cpu.flags.zf)
    {
        goto L_0x004e2ce6;
    }
L_0x004e2c46:
    // 004e2c46  833d0c44560000         +cmp dword ptr [0x56440c], 0
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
    // 004e2c4d  0f8508010000           -jne 0x4e2d5b
    if (!cpu.flags.zf)
    {
        goto L_0x004e2d5b;
    }
L_0x004e2c53:
    // 004e2c53  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004e2c57  83c414                 +add esp, 0x14
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(20 /*0x14*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004e2c5a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e2c5b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e2c5c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e2c5d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e2c5e:
    // 004e2c5e  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004e2c62  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004e2c66  eb89                   -jmp 0x4e2bf1
    goto L_0x004e2bf1;
L_0x004e2c68:
    // 004e2c68  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004e2c6a  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 004e2c6c  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004e2c6e  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004e2c70  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004e2c72  e8090d0000             -call 0x4e3980
    cpu.esp -= 4;
    sub_4e3980(app, cpu);
    if (cpu.terminate) return;
    // 004e2c77  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e2c79  7555                   -jne 0x4e2cd0
    if (!cpu.flags.zf)
    {
        goto L_0x004e2cd0;
    }
    // 004e2c7b  833d0c44560000         +cmp dword ptr [0x56440c], 0
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
    // 004e2c82  742e                   -je 0x4e2cb2
    if (cpu.flags.zf)
    {
        goto L_0x004e2cb2;
    }
    // 004e2c84  b948a15400             -mov ecx, 0x54a148
    cpu.ecx = 5546312 /*0x54a148*/;
    // 004e2c89  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004e2c8a  bbb8a15400             -mov ebx, 0x54a1b8
    cpu.ebx = 5546424 /*0x54a1b8*/;
    // 004e2c8f  b850010000             -mov eax, 0x150
    cpu.eax = 336 /*0x150*/;
    // 004e2c94  68d4a15400             -push 0x54a1d4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5546452 /*0x54a1d4*/;
    cpu.esp -= 4;
    // 004e2c99  890d90215500           -mov dword ptr [0x552190], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ecx;
    // 004e2c9f  891d94215500           -mov dword ptr [0x552194], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebx;
    // 004e2ca5  a398215500             -mov dword ptr [0x552198], eax
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.eax;
    // 004e2caa  e861e3f1ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004e2caf  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x004e2cb2:
    // 004e2cb2  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004e2cb4  e827130000             -call 0x4e3fe0
    cpu.esp -= 4;
    sub_4e3fe0(app, cpu);
    if (cpu.terminate) return;
    // 004e2cb9  c70600000000           -mov dword ptr [esi], 0
    app->getMemory<x86::reg32>(cpu.esi) = 0 /*0x0*/;
    // 004e2cbf  c70700000000           -mov dword ptr [edi], 0
    app->getMemory<x86::reg32>(cpu.edi) = 0 /*0x0*/;
    // 004e2cc5  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004e2cc9  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004e2ccc  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e2ccd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e2cce  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e2ccf  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e2cd0:
    // 004e2cd0  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004e2cd2  e819150000             -call 0x4e41f0
    cpu.esp -= 4;
    sub_4e41f0(app, cpu);
    if (cpu.terminate) return;
    // 004e2cd7  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004e2cdb  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004e2cdf  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004e2ce2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e2ce3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e2ce4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e2ce5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e2ce6:
    // 004e2ce6  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004e2ce8  e803150000             -call 0x4e41f0
    cpu.esp -= 4;
    sub_4e41f0(app, cpu);
    if (cpu.terminate) return;
    // 004e2ced  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004e2cef  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004e2cf1  ff1588455600           -call dword ptr [0x564588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5653896) /* 0x564588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e2cf7  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004e2cfb  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 004e2cfd  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 004e2cff  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004e2d03  a18c455600             -mov eax, dword ptr [0x56458c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653900) /* 0x56458c */);
    // 004e2d08  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004e2d0a  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 004e2d0c  833a00                 +cmp dword ptr [edx], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e2d0f  0f853effffff           -jne 0x4e2c53
    if (!cpu.flags.zf)
    {
        goto L_0x004e2c53;
    }
    // 004e2d15  833d0c44560000         +cmp dword ptr [0x56440c], 0
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
    // 004e2d1c  0f8431ffffff           -je 0x4e2c53
    if (cpu.flags.zf)
    {
        goto L_0x004e2c53;
    }
    // 004e2d22  be48a15400             -mov esi, 0x54a148
    cpu.esi = 5546312 /*0x54a148*/;
    // 004e2d27  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004e2d28  bfb8a15400             -mov edi, 0x54a1b8
    cpu.edi = 5546424 /*0x54a1b8*/;
    // 004e2d2d  b85f010000             -mov eax, 0x15f
    cpu.eax = 351 /*0x15f*/;
    // 004e2d32  68fca15400             -push 0x54a1fc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5546492 /*0x54a1fc*/;
    cpu.esp -= 4;
    // 004e2d37  893590215500           -mov dword ptr [0x552190], esi
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.esi;
    // 004e2d3d  893d94215500           -mov dword ptr [0x552194], edi
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.edi;
    // 004e2d43  a398215500             -mov dword ptr [0x552198], eax
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.eax;
    // 004e2d48  e8c3e2f1ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004e2d4d  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004e2d50  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004e2d54  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004e2d57  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e2d58  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e2d59  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e2d5a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e2d5b:
    // 004e2d5b  bf48a15400             -mov edi, 0x54a148
    cpu.edi = 5546312 /*0x54a148*/;
    // 004e2d60  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004e2d61  b8b8a15400             -mov eax, 0x54a1b8
    cpu.eax = 5546424 /*0x54a1b8*/;
    // 004e2d66  ba62010000             -mov edx, 0x162
    cpu.edx = 354 /*0x162*/;
    // 004e2d6b  68fca15400             -push 0x54a1fc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5546492 /*0x54a1fc*/;
    cpu.esp -= 4;
    // 004e2d70  893d90215500           -mov dword ptr [0x552190], edi
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edi;
    // 004e2d76  a394215500             -mov dword ptr [0x552194], eax
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.eax;
    // 004e2d7b  891598215500           -mov dword ptr [0x552198], edx
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.edx;
    // 004e2d81  e88ae2f1ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004e2d86  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004e2d89  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004e2d8d  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004e2d90  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e2d91  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e2d92  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e2d93  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_4e2da0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e2da0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e2da1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e2da2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e2da3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e2da4  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004e2da6  b948a15400             -mov ecx, 0x54a148
    cpu.ecx = 5546312 /*0x54a148*/;
    // 004e2dab  bb28a25400             -mov ebx, 0x54a228
    cpu.ebx = 5546536 /*0x54a228*/;
    // 004e2db0  be9d010000             -mov esi, 0x19d
    cpu.esi = 413 /*0x19d*/;
    // 004e2db5  b838a25400             -mov eax, 0x54a238
    cpu.eax = 5546552 /*0x54a238*/;
    // 004e2dba  890d90215500           -mov dword ptr [0x552190], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ecx;
    // 004e2dc0  891d94215500           -mov dword ptr [0x552194], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebx;
    // 004e2dc6  893598215500           -mov dword ptr [0x552198], esi
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.esi;
    // 004e2dcc  e83fe20100             -call 0x501010
    cpu.esp -= 4;
    sub_501010(app, cpu);
    if (cpu.terminate) return;
    // 004e2dd1  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004e2dd3  e808120000             -call 0x4e3fe0
    cpu.esp -= 4;
    sub_4e3fe0(app, cpu);
    if (cpu.terminate) return;
    // 004e2dd8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e2dd9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e2dda  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e2ddb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e2ddc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4e2de0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e2de0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e2de1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e2de2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004e2de3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004e2de4  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004e2de6  be48a15400             -mov esi, 0x54a148
    cpu.esi = 5546312 /*0x54a148*/;
    // 004e2deb  bf44a25400             -mov edi, 0x54a244
    cpu.edi = 5546564 /*0x54a244*/;
    // 004e2df0  bdd4010000             -mov ebp, 0x1d4
    cpu.ebp = 468 /*0x1d4*/;
    // 004e2df5  893590215500           -mov dword ptr [0x552190], esi
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.esi;
    // 004e2dfb  893d94215500           -mov dword ptr [0x552194], edi
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.edi;
    // 004e2e01  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004e2e03  892d98215500           -mov dword ptr [0x552198], ebp
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ebp;
    // 004e2e09  e802e20100             -call 0x501010
    cpu.esp -= 4;
    sub_501010(app, cpu);
    if (cpu.terminate) return;
    // 004e2e0e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004e2e10  e8cb0c0000             -call 0x4e3ae0
    cpu.esp -= 4;
    sub_4e3ae0(app, cpu);
    if (cpu.terminate) return;
    // 004e2e15  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e2e16  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e2e17  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e2e18  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e2e19  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_4e2e20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e2e20  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e2e21  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e2e22  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004e2e23  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004e2e24  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004e2e26  be48a15400             -mov esi, 0x54a148
    cpu.esi = 5546312 /*0x54a148*/;
    // 004e2e2b  bf50a25400             -mov edi, 0x54a250
    cpu.edi = 5546576 /*0x54a250*/;
    // 004e2e30  bddd010000             -mov ebp, 0x1dd
    cpu.ebp = 477 /*0x1dd*/;
    // 004e2e35  893590215500           -mov dword ptr [0x552190], esi
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.esi;
    // 004e2e3b  893d94215500           -mov dword ptr [0x552194], edi
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.edi;
    // 004e2e41  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004e2e43  892d98215500           -mov dword ptr [0x552198], ebp
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ebp;
    // 004e2e49  e8c2e10100             -call 0x501010
    cpu.esp -= 4;
    sub_501010(app, cpu);
    if (cpu.terminate) return;
    // 004e2e4e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004e2e50  e86b0e0000             -call 0x4e3cc0
    cpu.esp -= 4;
    sub_4e3cc0(app, cpu);
    if (cpu.terminate) return;
    // 004e2e55  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e2e56  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e2e57  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e2e58  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e2e59  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_4e2e60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e2e60  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e2e61  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e2e62  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e2e63  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004e2e64  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004e2e66  bb48a15400             -mov ebx, 0x54a148
    cpu.ebx = 5546312 /*0x54a148*/;
    // 004e2e6b  be5ca25400             -mov esi, 0x54a25c
    cpu.esi = 5546588 /*0x54a25c*/;
    // 004e2e70  bf19020000             -mov edi, 0x219
    cpu.edi = 537 /*0x219*/;
    // 004e2e75  891d90215500           -mov dword ptr [0x552190], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ebx;
    // 004e2e7b  893594215500           -mov dword ptr [0x552194], esi
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.esi;
    // 004e2e81  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004e2e83  893d98215500           -mov dword ptr [0x552198], edi
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.edi;
    // 004e2e89  e882e10100             -call 0x501010
    cpu.esp -= 4;
    sub_501010(app, cpu);
    if (cpu.terminate) return;
    // 004e2e8e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004e2e90  e8cb0f0000             -call 0x4e3e60
    cpu.esp -= 4;
    sub_4e3e60(app, cpu);
    if (cpu.terminate) return;
    // 004e2e95  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e2e97  7505                   -jne 0x4e2e9e
    if (!cpu.flags.zf)
    {
        goto L_0x004e2e9e;
    }
    // 004e2e99  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e2e9a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e2e9b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e2e9c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e2e9d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e2e9e:
    // 004e2e9e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004e2ea0  e88b100000             -call 0x4e3f30
    cpu.esp -= 4;
    sub_4e3f30(app, cpu);
    if (cpu.terminate) return;
    // 004e2ea5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e2ea6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e2ea7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e2ea8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e2ea9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4e2eb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e2eb0  833d84277a0000         +cmp dword ptr [0x7a2784], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(8005508) /* 0x7a2784 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e2eb7  7406                   -je 0x4e2ebf
    if (cpu.flags.zf)
    {
        goto L_0x004e2ebf;
    }
    // 004e2eb9  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004e2ebe  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e2ebf:
    // 004e2ebf  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 004e2ec0  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004e2ec2  687cd65400             -push 0x54d67c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5559932 /*0x54d67c*/;
    cpu.esp -= 4;
    // 004e2ec7  ff158c455300           -call dword ptr [0x53458c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457292) /* 0x53458c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e2ecd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e2ecf  0f84cf000000           -je 0x4e2fa4
    if (cpu.flags.zf)
    {
        goto L_0x004e2fa4;
    }
    // 004e2ed5  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004e2ed7  a384277a00             -mov dword ptr [0x7a2784], eax
    app->getMemory<x86::reg32>(x86::reg32(8005508) /* 0x7a2784 */) = cpu.eax;
    // 004e2edc  be50d75400             -mov esi, 0x54d750
    cpu.esi = 5560144 /*0x54d750*/;
L_0x004e2ee1:
    // 004e2ee1  ad                     -lodsd eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.esi -= 4;
    }
    else
    {
        cpu.esi += 4;
    }
    // 004e2ee2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e2ee4  7417                   -je 0x4e2efd
    if (cpu.flags.zf)
    {
        goto L_0x004e2efd;
    }
    // 004e2ee6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e2ee7  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e2ee8  ff1558455300           -call dword ptr [0x534558]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457240) /* 0x534558 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e2eee  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e2ef0  0f84a7000000           -je 0x4e2f9d
    if (cpu.flags.zf)
    {
        goto L_0x004e2f9d;
    }
    // 004e2ef6  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004e2ef8  8916                   -mov dword ptr [esi], edx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edx;
    // 004e2efa  ad                     -lodsd eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.esi -= 4;
    }
    else
    {
        cpu.esi += 4;
    }
    // 004e2efb  ebe4                   -jmp 0x4e2ee1
    goto L_0x004e2ee1;
L_0x004e2efd:
    // 004e2efd  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004e2eff  6890d75400             -push 0x54d790
    app->getMemory<x86::reg32>(cpu.esp-4) = 5560208 /*0x54d790*/;
    cpu.esp -= 4;
    // 004e2f04  6888277a00             -push 0x7a2788
    app->getMemory<x86::reg32>(cpu.esp-4) = 8005512 /*0x7a2788*/;
    cpu.esp -= 4;
    // 004e2f09  ff1554d75400           -call dword ptr [0x54d754]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5560148) /* 0x54d754 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e2f0f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e2f11  0f8586000000           -jne 0x4e2f9d
    if (!cpu.flags.zf)
    {
        goto L_0x004e2f9d;
    }
    // 004e2f17  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004e2f1a  8d45fc                 -lea eax, [ebp - 4]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004e2f1d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e2f1e  8d45f8                 -lea eax, [ebp - 8]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004e2f21  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e2f22  ff155cd75400           -call dword ptr [0x54d75c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5560156) /* 0x54d75c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e2f28  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e2f2a  7571                   -jne 0x4e2f9d
    if (!cpu.flags.zf)
    {
        goto L_0x004e2f9d;
    }
    // 004e2f2c  2b65fc                 -sub esp, dword ptr [ebp - 4]
    (cpu.esp) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */)));
    // 004e2f2f  54                     -push esp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esp;
    cpu.esp -= 4;
    // 004e2f30  ff75fc                 -push dword ptr [ebp - 4]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    cpu.esp -= 4;
    // 004e2f33  ff75f8                 -push dword ptr [ebp - 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    cpu.esp -= 4;
    // 004e2f36  ff1564d75400           -call dword ptr [0x54d764]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5560164) /* 0x54d764 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e2f3c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e2f3e  755d                   -jne 0x4e2f9d
    if (!cpu.flags.zf)
    {
        goto L_0x004e2f9d;
    }
L_0x004e2f40:
    // 004e2f40  8b742430               -mov esi, dword ptr [esp + 0x30]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 004e2f44  bf20d75400             -mov edi, 0x54d720
    cpu.edi = 5560096 /*0x54d720*/;
    // 004e2f49  b90a000000             -mov ecx, 0xa
    cpu.ecx = 10 /*0xa*/;
    // 004e2f4e  f366a7                 +repe cmpsw word ptr [esi], word ptr es:[edi]
    while (cpu.ecx)
    {
        {
            x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.esi);
            x86::reg16 tmp2 = x86::reg16(x86::sreg16(app->getMemory<x86::reg16>(cpu.ees + cpu.edi)));
            x86::reg16 result = tmp1 - tmp2;
            cpu.flags.cf = tmp1 < tmp2;
            cpu.flags.of = 1 & (tmp1 >> 15);
            cpu.flags.of ^= 1 & (result >> 15);
            cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
            cpu.set_szp(result);
        }
        if (cpu.flags.df)
        {
            cpu.edi -= 2;
            cpu.esi -= 2;
        }
        else
        {
            cpu.edi += 2;
            cpu.esi += 2;
        }
        --cpu.ecx;
        if (!cpu.flags.zf)
            break;
    }
    // 004e2f51  7510                   -jne 0x4e2f63
    if (!cpu.flags.zf)
    {
        goto L_0x004e2f63;
    }
    // 004e2f53  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 004e2f55  bfa0d75400             -mov edi, 0x54d7a0
    cpu.edi = 5560224 /*0x54d7a0*/;
    // 004e2f5a  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 004e2f5f  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004e2f61  eb21                   -jmp 0x4e2f84
    goto L_0x004e2f84;
L_0x004e2f63:
    // 004e2f63  8b742430               -mov esi, dword ptr [esp + 0x30]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 004e2f67  bf34d75400             -mov edi, 0x54d734
    cpu.edi = 5560116 /*0x54d734*/;
    // 004e2f6c  b90b000000             -mov ecx, 0xb
    cpu.ecx = 11 /*0xb*/;
    // 004e2f71  f366a7                 +repe cmpsw word ptr [esi], word ptr es:[edi]
    while (cpu.ecx)
    {
        {
            x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.esi);
            x86::reg16 tmp2 = x86::reg16(x86::sreg16(app->getMemory<x86::reg16>(cpu.ees + cpu.edi)));
            x86::reg16 result = tmp1 - tmp2;
            cpu.flags.cf = tmp1 < tmp2;
            cpu.flags.of = 1 & (tmp1 >> 15);
            cpu.flags.of ^= 1 & (result >> 15);
            cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
            cpu.set_szp(result);
        }
        if (cpu.flags.df)
        {
            cpu.edi -= 2;
            cpu.esi -= 2;
        }
        else
        {
            cpu.edi += 2;
            cpu.esi += 2;
        }
        --cpu.ecx;
        if (!cpu.flags.zf)
            break;
    }
    // 004e2f74  750e                   -jne 0x4e2f84
    if (!cpu.flags.zf)
    {
        goto L_0x004e2f84;
    }
    // 004e2f76  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 004e2f78  bfb0d75400             -mov edi, 0x54d7b0
    cpu.edi = 5560240 /*0x54d7b0*/;
    // 004e2f7d  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 004e2f82  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
L_0x004e2f84:
    // 004e2f84  83c44c                 +add esp, 0x4c
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(76 /*0x4c*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004e2f87  ff4df8                 +dec dword ptr [ebp - 8]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004e2f8a  75b4                   -jne 0x4e2f40
    if (!cpu.flags.zf)
    {
        goto L_0x004e2f40;
    }
    // 004e2f8c  b8ac2f4e00             -mov eax, 0x4e2fac
    cpu.eax = 5124012 /*0x4e2fac*/;
    // 004e2f91  e88a4c0100             -call 0x4f7c20
    cpu.esp -= 4;
    sub_4f7c20(app, cpu);
    if (cpu.terminate) return;
    // 004e2f96  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004e2f9b  eb07                   -jmp 0x4e2fa4
    goto L_0x004e2fa4;
L_0x004e2f9d:
    // 004e2f9d  e80a000000             -call 0x4e2fac
    cpu.esp -= 4;
    sub_4e2fac(app, cpu);
    if (cpu.terminate) return;
    // 004e2fa2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004e2fa4:
    // 004e2fa4  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004e2fa6  8944241c               -mov dword ptr [esp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 004e2faa  61                     -popal 
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
    // 004e2fab  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4e2fac(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e2fac  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 004e2fad  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004e2faf  a188277a00             -mov eax, dword ptr [0x7a2788]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(8005512) /* 0x7a2788 */);
    // 004e2fb4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e2fb6  740d                   -je 0x4e2fc5
    if (cpu.flags.zf)
    {
        goto L_0x004e2fc5;
    }
    // 004e2fb8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e2fb9  ff1584d75400           -call dword ptr [0x54d784]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5560196) /* 0x54d784 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e2fbf  891d88277a00           -mov dword ptr [0x7a2788], ebx
    app->getMemory<x86::reg32>(x86::reg32(8005512) /* 0x7a2788 */) = cpu.ebx;
L_0x004e2fc5:
    // 004e2fc5  a184277a00             -mov eax, dword ptr [0x7a2784]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(8005508) /* 0x7a2784 */);
    // 004e2fca  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e2fcc  741c                   -je 0x4e2fea
    if (cpu.flags.zf)
    {
        goto L_0x004e2fea;
    }
    // 004e2fce  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e2fcf  ff15dc445300           -call dword ptr [0x5344dc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457116) /* 0x5344dc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e2fd5  891d84277a00           -mov dword ptr [0x7a2784], ebx
    app->getMemory<x86::reg32>(x86::reg32(8005508) /* 0x7a2784 */) = cpu.ebx;
    // 004e2fdb  be50d75400             -mov esi, 0x54d750
    cpu.esi = 5560144 /*0x54d750*/;
L_0x004e2fe0:
    // 004e2fe0  ad                     -lodsd eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.esi -= 4;
    }
    else
    {
        cpu.esi += 4;
    }
    // 004e2fe1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e2fe3  7405                   -je 0x4e2fea
    if (cpu.flags.zf)
    {
        goto L_0x004e2fea;
    }
    // 004e2fe5  891e                   -mov dword ptr [esi], ebx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.ebx;
    // 004e2fe7  ad                     -lodsd eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.esi -= 4;
    }
    else
    {
        cpu.esi += 4;
    }
    // 004e2fe8  ebf6                   -jmp 0x4e2fe0
    goto L_0x004e2fe0;
L_0x004e2fea:
    // 004e2fea  61                     -popal 
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
    // 004e2feb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4e2fec(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e2fec  90                     -nop 
    ;
    // 004e2fed  90                     -nop 
    ;
    // 004e2fee  90                     -nop 
    ;
    // 004e2fef  90                     -nop 
    ;
    // 004e2ff0  90                     -nop 
    ;
    // 004e2ff1  90                     -nop 
    ;
    // 004e2ff2  90                     -nop 
    ;
    // 004e2ff3  90                     -nop 
    ;
    // 004e2ff4  90                     -nop 
    ;
    // 004e2ff5  90                     -nop 
    ;
    // 004e2ff6  90                     -nop 
    ;
    // 004e2ff7  90                     -nop 
    ;
    // 004e2ff8  90                     -nop 
    ;
    // 004e2ff9  90                     -nop 
    ;
    // 004e2ffa  90                     -nop 
    ;
    // 004e2ffb  90                     -nop 
    ;
    // 004e2ffc  90                     -nop 
    ;
    // 004e2ffd  90                     -nop 
    ;
    // 004e2ffe  90                     -nop 
    ;
    // 004e2fff  90                     -nop 
    ;
    // 004e3000  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e3001  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e3002  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e3003  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004e3004  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e3005  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e3006  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004e3008  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e3009  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e300a  ff1598455300           -call dword ptr [0x534598]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457304) /* 0x534598 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e3010  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e3011  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e3012  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4e3000(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004e3000;
    // 004e2fec  90                     -nop 
    ;
    // 004e2fed  90                     -nop 
    ;
    // 004e2fee  90                     -nop 
    ;
    // 004e2fef  90                     -nop 
    ;
    // 004e2ff0  90                     -nop 
    ;
    // 004e2ff1  90                     -nop 
    ;
    // 004e2ff2  90                     -nop 
    ;
    // 004e2ff3  90                     -nop 
    ;
    // 004e2ff4  90                     -nop 
    ;
    // 004e2ff5  90                     -nop 
    ;
    // 004e2ff6  90                     -nop 
    ;
    // 004e2ff7  90                     -nop 
    ;
    // 004e2ff8  90                     -nop 
    ;
    // 004e2ff9  90                     -nop 
    ;
    // 004e2ffa  90                     -nop 
    ;
    // 004e2ffb  90                     -nop 
    ;
    // 004e2ffc  90                     -nop 
    ;
    // 004e2ffd  90                     -nop 
    ;
    // 004e2ffe  90                     -nop 
    ;
    // 004e2fff  90                     -nop 
    ;
L_entry_0x004e3000:
    // 004e3000  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e3001  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e3002  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e3003  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004e3004  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e3005  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e3006  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004e3008  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e3009  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e300a  ff1598455300           -call dword ptr [0x534598]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457304) /* 0x534598 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e3010  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e3011  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e3012  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4e3014(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e3014  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 004e3015  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004e3017  81ec0c020000           -sub esp, 0x20c
    (cpu.esp) -= x86::reg32(x86::sreg32(524 /*0x20c*/));
    // 004e301d  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004e301f  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 004e3021  b904010000             -mov ecx, 0x104
    cpu.ecx = 260 /*0x104*/;
    // 004e3026  e8d5ffffff             -call 0x4e3000
    cpu.esp -= 4;
    sub_4e3000(app, cpu);
    if (cpu.terminate) return;
    // 004e302b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e302d  7440                   -je 0x4e306f
    if (cpu.flags.zf)
    {
        goto L_0x004e306f;
    }
    // 004e302f  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004e3031  8d45fc                 -lea eax, [ebp - 4]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004e3034  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e3035  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004e3037  03460a                 -add eax, dword ptr [esi + 0xa]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(10) /* 0xa */)));
    // 004e303a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e303b  8d460e                 -lea eax, [esi + 0xe]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(14) /* 0xe */);
    // 004e303e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e303f  ff156cd75400           -call dword ptr [0x54d76c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5560172) /* 0x54d76c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e3045  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e3047  7526                   -jne 0x4e306f
    if (!cpu.flags.zf)
    {
        goto L_0x004e306f;
    }
    // 004e3049  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004e304b  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 004e304e  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 004e3051  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e3052  ff75fc                 -push dword ptr [ebp - 4]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    cpu.esp -= 4;
    // 004e3055  ff1574d75400           -call dword ptr [0x54d774]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5560180) /* 0x54d774 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e305b  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004e305d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e305f  0f94c3                 -sete bl
    cpu.bl = cpu.flags.zf;
    // 004e3062  ff75fc                 -push dword ptr [ebp - 4]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    cpu.esp -= 4;
    // 004e3065  ff157cd75400           -call dword ptr [0x54d77c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5560188) /* 0x54d77c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e306b  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004e306d  eb02                   -jmp 0x4e3071
    goto L_0x004e3071;
L_0x004e306f:
    // 004e306f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004e3071:
    // 004e3071  89451c                 -mov dword ptr [ebp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 004e3074  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004e3076  61                     -popal 
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
    // 004e3077  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4e3078(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e3078  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 004e3079  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004e307b  81ec1c010000           -sub esp, 0x11c
    (cpu.esp) -= x86::reg32(x86::sreg32(284 /*0x11c*/));
    // 004e3081  8b7524                 -mov esi, dword ptr [ebp + 0x24]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(36) /* 0x24 */);
    // 004e3084  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004e3087  83c007                 -add eax, 7
    (cpu.eax) += x86::reg32(x86::sreg32(7 /*0x7*/));
    // 004e308a  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 004e308d  83f804                 +cmp eax, 4
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
    // 004e3090  7205                   -jb 0x4e3097
    if (cpu.flags.cf)
    {
        goto L_0x004e3097;
    }
    // 004e3092  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
L_0x004e3097:
    // 004e3097  0faf06                 -imul eax, dword ptr [esi]
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi))));
    // 004e309a  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004e309c  83c003                 -add eax, 3
    (cpu.eax) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004e309f  24fc                   -and al, 0xfc
    cpu.al &= x86::reg8(x86::sreg8(252 /*0xfc*/));
    // 004e30a1  f7db                   -neg ebx
    cpu.ebx = ~cpu.ebx + 1;
    // 004e30a3  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004e30a5  895dec                 -mov dword ptr [ebp - 0x14], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.ebx;
    // 004e30a8  0faf4604               -imul eax, dword ptr [esi + 4]
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */))));
    // 004e30ac  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004e30ae  b936000000             -mov ecx, 0x36
    cpu.ecx = 54 /*0x36*/;
    // 004e30b3  837e0810               +cmp dword ptr [esi + 8], 0x10
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e30b7  7503                   -jne 0x4e30bc
    if (!cpu.flags.zf)
    {
        goto L_0x004e30bc;
    }
    // 004e30b9  83c10c                 -add ecx, 0xc
    (cpu.ecx) += x86::reg32(x86::sreg32(12 /*0xc*/));
L_0x004e30bc:
    // 004e30bc  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004e30be  e839ee0000             -call 0x4f1efc
    cpu.esp -= 4;
    sub_4f1efc(app, cpu);
    if (cpu.terminate) return;
    // 004e30c3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e30c5  0f846d010000           -je 0x4e3238
    if (cpu.flags.zf)
    {
        goto L_0x004e3238;
    }
    // 004e30cb  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 004e30ce  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004e30d0  66c707424d             -mov word ptr [edi], 0x4d42
    app->getMemory<x86::reg16>(cpu.edi) = 19778 /*0x4d42*/;
    // 004e30d5  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004e30d7  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004e30d9  894702                 -mov dword ptr [edi + 2], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(2) /* 0x2 */) = cpu.eax;
    // 004e30dc  c7470600000000         -mov dword ptr [edi + 6], 0
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(6) /* 0x6 */) = 0 /*0x0*/;
    // 004e30e3  894f0a                 -mov dword ptr [edi + 0xa], ecx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(10) /* 0xa */) = cpu.ecx;
    // 004e30e6  c7470e28000000         -mov dword ptr [edi + 0xe], 0x28
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(14) /* 0xe */) = 40 /*0x28*/;
    // 004e30ed  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004e30ef  8945f0                 -mov dword ptr [ebp - 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
    // 004e30f2  894712                 -mov dword ptr [edi + 0x12], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(18) /* 0x12 */) = cpu.eax;
    // 004e30f5  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004e30f8  8945f4                 -mov dword ptr [ebp - 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.eax;
    // 004e30fb  894716                 -mov dword ptr [edi + 0x16], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(22) /* 0x16 */) = cpu.eax;
    // 004e30fe  66c7471a0100           -mov word ptr [edi + 0x1a], 1
    app->getMemory<x86::reg16>(cpu.edi + x86::reg32(26) /* 0x1a */) = 1 /*0x1*/;
    // 004e3104  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004e3107  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 004e310a  83f818                 +cmp eax, 0x18
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(24 /*0x18*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e310d  7308                   -jae 0x4e3117
    if (!cpu.flags.cf)
    {
        goto L_0x004e3117;
    }
    // 004e310f  66c7471c1000           -mov word ptr [edi + 0x1c], 0x10
    app->getMemory<x86::reg16>(cpu.edi + x86::reg32(28) /* 0x1c */) = 16 /*0x10*/;
    // 004e3115  eb06                   -jmp 0x4e311d
    goto L_0x004e311d;
L_0x004e3117:
    // 004e3117  66c7471c1800           -mov word ptr [edi + 0x1c], 0x18
    app->getMemory<x86::reg16>(cpu.edi + x86::reg32(28) /* 0x1c */) = 24 /*0x18*/;
L_0x004e311d:
    // 004e311d  83f810                 +cmp eax, 0x10
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e3120  7409                   -je 0x4e312b
    if (cpu.flags.zf)
    {
        goto L_0x004e312b;
    }
    // 004e3122  c7471e00000000         -mov dword ptr [edi + 0x1e], 0
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(30) /* 0x1e */) = 0 /*0x0*/;
    // 004e3129  eb07                   -jmp 0x4e3132
    goto L_0x004e3132;
L_0x004e312b:
    // 004e312b  c7471e03000000         -mov dword ptr [edi + 0x1e], 3
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(30) /* 0x1e */) = 3 /*0x3*/;
L_0x004e3132:
    // 004e3132  895722                 -mov dword ptr [edi + 0x22], edx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(34) /* 0x22 */) = cpu.edx;
    // 004e3135  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004e3137  894726                 -mov dword ptr [edi + 0x26], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(38) /* 0x26 */) = cpu.eax;
    // 004e313a  89472a                 -mov dword ptr [edi + 0x2a], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(42) /* 0x2a */) = cpu.eax;
    // 004e313d  89472e                 -mov dword ptr [edi + 0x2e], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(46) /* 0x2e */) = cpu.eax;
    // 004e3140  894732                 -mov dword ptr [edi + 0x32], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(50) /* 0x32 */) = cpu.eax;
    // 004e3143  837e0810               +cmp dword ptr [esi + 8], 0x10
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e3147  7515                   -jne 0x4e315e
    if (!cpu.flags.zf)
    {
        goto L_0x004e315e;
    }
    // 004e3149  c7473600f80000         -mov dword ptr [edi + 0x36], 0xf800
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(54) /* 0x36 */) = 63488 /*0xf800*/;
    // 004e3150  c7473ae0070000         -mov dword ptr [edi + 0x3a], 0x7e0
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(58) /* 0x3a */) = 2016 /*0x7e0*/;
    // 004e3157  c7473e1f000000         -mov dword ptr [edi + 0x3e], 0x1f
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(62) /* 0x3e */) = 31 /*0x1f*/;
L_0x004e315e:
    // 004e315e  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004e3161  83c007                 -add eax, 7
    (cpu.eax) += x86::reg32(x86::sreg32(7 /*0x7*/));
    // 004e3164  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 004e3167  0faf45f0               -imul eax, dword ptr [ebp - 0x10]
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */))));
    // 004e316b  8945e8                 -mov dword ptr [ebp - 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.eax;
    // 004e316e  01cf                   -add edi, ecx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004e3170  8b55f4                 -mov edx, dword ptr [ebp - 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
L_0x004e3173:
    // 004e3173  83fa00                 +cmp edx, 0
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e3176  7440                   -je 0x4e31b8
    if (cpu.flags.zf)
    {
        goto L_0x004e31b8;
    }
    // 004e3178  4a                     -dec edx
    (cpu.edx)--;
    // 004e3179  8b75e8                 -mov esi, dword ptr [ebp - 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004e317c  0faff2                 -imul esi, edx
    cpu.esi = x86::reg32(x86::sreg64(x86::sreg32(cpu.esi)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004e317f  037524                 -add esi, dword ptr [ebp + 0x24]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(36) /* 0x24 */)));
    // 004e3182  83c60c                 -add esi, 0xc
    (cpu.esi) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004e3185  8b4df0                 -mov ecx, dword ptr [ebp - 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004e3188  837df818               +cmp dword ptr [ebp - 8], 0x18
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(24 /*0x18*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e318c  740b                   -je 0x4e3199
    if (cpu.flags.zf)
    {
        goto L_0x004e3199;
    }
    // 004e318e  837df820               +cmp dword ptr [ebp - 8], 0x20
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e3192  740c                   -je 0x4e31a0
    if (cpu.flags.zf)
    {
        goto L_0x004e31a0;
    }
    // 004e3194  f366a5                 -rep movsw word ptr es:[edi], word ptr [esi]
    while (cpu.ecx)
    {
        app->getMemory<x86::reg16>(cpu.ees + cpu.edi) = app->getMemory<x86::reg16>(cpu.esi);
        if (cpu.flags.df)
        {
            cpu.edi -= 2;
            cpu.esi -= 2;
        }
        else
        {
            cpu.edi += 2;
            cpu.esi += 2;
        }
        --cpu.ecx;
    }
    // 004e3197  eb16                   -jmp 0x4e31af
    goto L_0x004e31af;
L_0x004e3199:
    // 004e3199  6bc903                 +imul ecx, ecx, 3
    {
        x86::sreg64 tmp = x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(3 /*0x3*/));
        cpu.ecx = static_cast<x86::reg32>(static_cast<x86::sreg32>(tmp));
        cpu.flags.of = cpu.flags.cf = (tmp != x86::sreg64(x86::sreg32(cpu.ecx)));
    }
    // 004e319c  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    }
    // 004e319e  eb0f                   -jmp 0x4e31af
    goto L_0x004e31af;
L_0x004e31a0:
    // 004e31a0  83f900                 +cmp ecx, 0
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e31a3  740a                   -je 0x4e31af
    if (cpu.flags.zf)
    {
        goto L_0x004e31af;
    }
    // 004e31a5  ad                     -lodsd eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.esi -= 4;
    }
    else
    {
        cpu.esi += 4;
    }
    // 004e31a6  66ab                   -stosw word ptr es:[edi], ax
    app->getMemory<x86::reg16>(cpu.ees + cpu.edi) = cpu.ax;
    if (cpu.flags.df)
    {
        cpu.edi -= 2;
    }
    else
    {
        cpu.edi += 2;
    }
    // 004e31a8  c1e810                 +shr eax, 0x10
    {
        x86::reg8 tmp = 16 /*0x10*/ % 32;
        x86::reg32& op = cpu.eax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 004e31ab  aa                     -stosb byte ptr es:[edi], al
    app->getMemory<x86::reg8>(cpu.ees + cpu.edi) = cpu.al;
    if (cpu.flags.df)
    {
        cpu.edi -= 1;
    }
    else
    {
        cpu.edi += 1;
    }
    // 004e31ac  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004e31ad  ebf1                   -jmp 0x4e31a0
    goto L_0x004e31a0;
L_0x004e31af:
    // 004e31af  30c0                   +xor al, al
    cpu.clear_co();
    cpu.set_szp((cpu.al ^= x86::reg8(x86::sreg8(cpu.al))));
    // 004e31b1  8b4dec                 -mov ecx, dword ptr [ebp - 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 004e31b4  f3aa                   -rep stosb byte ptr es:[edi], al
    while (cpu.ecx)
    {
        app->getMemory<x86::reg8>(cpu.ees + cpu.edi) = cpu.al;
        if (cpu.flags.df)
        {
            cpu.edi -= 1;
        }
        else
        {
            cpu.edi += 1;
        }
        --cpu.ecx;
    }
    // 004e31b6  ebbb                   -jmp 0x4e3173
    goto L_0x004e3173;
L_0x004e31b8:
    // 004e31b8  bef4f75300             -mov esi, 0x53f7f4
    cpu.esi = 5502964 /*0x53f7f4*/;
    // 004e31bd  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 004e31bf  e8f4610100             -call 0x4f93b8
    cpu.esp -= 4;
    sub_4f93b8(app, cpu);
    if (cpu.terminate) return;
L_0x004e31c4:
    // 004e31c4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004e31c6  40                     -inc eax
    (cpu.eax)++;
    // 004e31c7  f00fc105e0d16f00       -lock xadd dword ptr [0x6fd1e0], eax
    {
        x86::reg32 previous = app->getMemory<x86::reg32>(x86::reg32(7328224) /* 0x6fd1e0 */);
        x86::reg32 addend = cpu.eax;
        x86::reg32 result = previous + addend;
        cpu.flags.cf = result < previous;
        cpu.flags.of = ((~(previous ^ addend) & (previous ^ result)) >> 31) & 1;
        cpu.set_szp(result);
        cpu.eax = previous;
        app->getMemory<x86::reg32>(x86::reg32(7328224) /* 0x6fd1e0 */) = result;
    }
    // 004e31cf  40                     -inc eax
    (cpu.eax)++;
    // 004e31d0  6880277a00             -push 0x7a2780
    app->getMemory<x86::reg32>(cpu.esp-4) = 8005504 /*0x7a2780*/;
    cpu.esp -= 4;
    // 004e31d5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e31d6  6804f85300             -push 0x53f804
    app->getMemory<x86::reg32>(cpu.esp-4) = 5502980 /*0x53f804*/;
    cpu.esp -= 4;
    // 004e31db  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004e31dc  e8afc4ffff             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 004e31e1  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004e31e4  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004e31e6  e801600100             -call 0x4f91ec
    cpu.esp -= 4;
    sub_4f91ec(app, cpu);
    if (cpu.terminate) return;
    // 004e31eb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e31ed  75d5                   -jne 0x4e31c4
    if (!cpu.flags.zf)
    {
        goto L_0x004e31c4;
    }
    // 004e31ef  a180277a00             -mov eax, dword ptr [0x7a2780]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(8005504) /* 0x7a2780 */);
    // 004e31f4  3d706e6700             +cmp eax, 0x676e70
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(6778480 /*0x676e70*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e31f9  7409                   -je 0x4e3204
    if (cpu.flags.zf)
    {
        goto L_0x004e3204;
    }
    // 004e31fb  3d6a706700             +cmp eax, 0x67706a
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(6778986 /*0x67706a*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e3200  740b                   -je 0x4e320d
    if (cpu.flags.zf)
    {
        goto L_0x004e320d;
    }
    // 004e3202  eb1f                   -jmp 0x4e3223
    goto L_0x004e3223;
L_0x004e3204:
    // 004e3204  b9a0d75400             -mov ecx, 0x54d7a0
    cpu.ecx = 5560224 /*0x54d7a0*/;
    // 004e3209  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 004e320b  eb0a                   -jmp 0x4e3217
    goto L_0x004e3217;
L_0x004e320d:
    // 004e320d  b9b0d75400             -mov ecx, 0x54d7b0
    cpu.ecx = 5560240 /*0x54d7b0*/;
    // 004e3212  bbc0d75400             -mov ebx, 0x54d7c0
    cpu.ebx = 5560256 /*0x54d7c0*/;
L_0x004e3217:
    // 004e3217  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004e321a  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004e321c  e8f3fdffff             -call 0x4e3014
    cpu.esp -= 4;
    sub_4e3014(app, cpu);
    if (cpu.terminate) return;
    // 004e3221  eb0d                   -jmp 0x4e3230
    goto L_0x004e3230;
L_0x004e3223:
    // 004e3223  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004e3226  8b5a02                 -mov ebx, dword ptr [edx + 2]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 004e3229  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004e322b  e8b0b80000             -call 0x4eeae0
    cpu.esp -= 4;
    sub_4eeae0(app, cpu);
    if (cpu.terminate) return;
L_0x004e3230:
    // 004e3230  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004e3233  e8f8ec0000             -call 0x4f1f30
    cpu.esp -= 4;
    sub_4f1f30(app, cpu);
    if (cpu.terminate) return;
L_0x004e3238:
    // 004e3238  8b4524                 -mov eax, dword ptr [ebp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(36) /* 0x24 */);
    // 004e323b  e8f0ec0000             -call 0x4f1f30
    cpu.esp -= 4;
    sub_4f1f30(app, cpu);
    if (cpu.terminate) return;
    // 004e3240  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004e3242  61                     -popal 
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
    // 004e3243  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004e3245  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_4e3248(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e3248  90                     -nop 
    ;
    // 004e3249  90                     -nop 
    ;
    // 004e324a  90                     -nop 
    ;
    // 004e324b  90                     -nop 
    ;
    // 004e324c  90                     -nop 
    ;
    // 004e324d  90                     -nop 
    ;
    // 004e324e  90                     -nop 
    ;
    // 004e324f  90                     -nop 
    ;
    // 004e3250  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e3251  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e3252  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e3253  81ec0c010000           -sub esp, 0x10c
    (cpu.esp) -= x86::reg32(x86::sreg32(268 /*0x10c*/));
    // 004e3259  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004e325b  b27c                   -mov dl, 0x7c
    cpu.dl = 124 /*0x7c*/;
    // 004e325d  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
L_0x004e325f:
    // 004e325f  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004e3261  3ac2                   +cmp al, dl
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
    // 004e3263  7412                   -je 0x4e3277
    if (cpu.flags.zf)
    {
        goto L_0x004e3277;
    }
    // 004e3265  3c00                   +cmp al, 0
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
    // 004e3267  740c                   -je 0x4e3275
    if (cpu.flags.zf)
    {
        goto L_0x004e3275;
    }
    // 004e3269  46                     -inc esi
    (cpu.esi)++;
    // 004e326a  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004e326c  3ac2                   +cmp al, dl
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
    // 004e326e  7407                   -je 0x4e3277
    if (cpu.flags.zf)
    {
        goto L_0x004e3277;
    }
    // 004e3270  46                     -inc esi
    (cpu.esi)++;
    // 004e3271  3c00                   +cmp al, 0
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
    // 004e3273  75ea                   -jne 0x4e325f
    if (!cpu.flags.zf)
    {
        goto L_0x004e325f;
    }
L_0x004e3275:
    // 004e3275  2bf6                   -sub esi, esi
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.esi));
L_0x004e3277:
    // 004e3277  89b42408010000         -mov dword ptr [esp + 0x108], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(264) /* 0x108 */) = cpu.esi;
    // 004e327e  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004e3280  754a                   -jne 0x4e32cc
    if (!cpu.flags.zf)
    {
        goto L_0x004e32cc;
    }
    // 004e3282  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004e3284  7505                   -jne 0x4e328b
    if (!cpu.flags.zf)
    {
        goto L_0x004e328b;
    }
    // 004e3286  b994a25400             -mov ecx, 0x54a294
    cpu.ecx = 5546644 /*0x54a294*/;
L_0x004e328b:
    // 004e328b  8d842408010000         -lea eax, [esp + 0x108]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(264) /* 0x108 */);
    // 004e3292  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e3293  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004e3297  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e3298  6805010000             -push 0x105
    app->getMemory<x86::reg32>(cpu.esp-4) = 261 /*0x105*/;
    cpu.esp -= 4;
    // 004e329d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e329e  2eff1530455300         -call dword ptr cs:[0x534530]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457200) /* 0x534530 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e32a5  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004e32a7  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004e32a9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e32aa  2eff15f8465300         -call dword ptr cs:[0x5346f8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457656) /* 0x5346f8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e32b1  83fe01                 +cmp esi, 1
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
    // 004e32b4  7e16                   -jle 0x4e32cc
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004e32cc;
    }
    // 004e32b6  807c24013a             +cmp byte ptr [esp + 1], 0x3a
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1) /* 0x1 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(58 /*0x3a*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004e32bb  750f                   -jne 0x4e32cc
    if (!cpu.flags.zf)
    {
        goto L_0x004e32cc;
    }
    // 004e32bd  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004e32bf  8a0424                 -mov al, byte ptr [esp]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp);
    // 004e32c2  81c40c010000           -add esp, 0x10c
    (cpu.esp) += x86::reg32(x86::sreg32(268 /*0x10c*/));
    // 004e32c8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e32c9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e32ca  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e32cb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e32cc:
    // 004e32cc  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004e32ce  81c40c010000           -add esp, 0x10c
    (cpu.esp) += x86::reg32(x86::sreg32(268 /*0x10c*/));
    // 004e32d4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e32d5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e32d6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e32d7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4e3250(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004e3250;
    // 004e3248  90                     -nop 
    ;
    // 004e3249  90                     -nop 
    ;
    // 004e324a  90                     -nop 
    ;
    // 004e324b  90                     -nop 
    ;
    // 004e324c  90                     -nop 
    ;
    // 004e324d  90                     -nop 
    ;
    // 004e324e  90                     -nop 
    ;
    // 004e324f  90                     -nop 
    ;
L_entry_0x004e3250:
    // 004e3250  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e3251  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e3252  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e3253  81ec0c010000           -sub esp, 0x10c
    (cpu.esp) -= x86::reg32(x86::sreg32(268 /*0x10c*/));
    // 004e3259  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004e325b  b27c                   -mov dl, 0x7c
    cpu.dl = 124 /*0x7c*/;
    // 004e325d  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
L_0x004e325f:
    // 004e325f  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004e3261  3ac2                   +cmp al, dl
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
    // 004e3263  7412                   -je 0x4e3277
    if (cpu.flags.zf)
    {
        goto L_0x004e3277;
    }
    // 004e3265  3c00                   +cmp al, 0
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
    // 004e3267  740c                   -je 0x4e3275
    if (cpu.flags.zf)
    {
        goto L_0x004e3275;
    }
    // 004e3269  46                     -inc esi
    (cpu.esi)++;
    // 004e326a  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004e326c  3ac2                   +cmp al, dl
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
    // 004e326e  7407                   -je 0x4e3277
    if (cpu.flags.zf)
    {
        goto L_0x004e3277;
    }
    // 004e3270  46                     -inc esi
    (cpu.esi)++;
    // 004e3271  3c00                   +cmp al, 0
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
    // 004e3273  75ea                   -jne 0x4e325f
    if (!cpu.flags.zf)
    {
        goto L_0x004e325f;
    }
L_0x004e3275:
    // 004e3275  2bf6                   -sub esi, esi
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.esi));
L_0x004e3277:
    // 004e3277  89b42408010000         -mov dword ptr [esp + 0x108], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(264) /* 0x108 */) = cpu.esi;
    // 004e327e  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004e3280  754a                   -jne 0x4e32cc
    if (!cpu.flags.zf)
    {
        goto L_0x004e32cc;
    }
    // 004e3282  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004e3284  7505                   -jne 0x4e328b
    if (!cpu.flags.zf)
    {
        goto L_0x004e328b;
    }
    // 004e3286  b994a25400             -mov ecx, 0x54a294
    cpu.ecx = 5546644 /*0x54a294*/;
L_0x004e328b:
    // 004e328b  8d842408010000         -lea eax, [esp + 0x108]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(264) /* 0x108 */);
    // 004e3292  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e3293  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004e3297  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e3298  6805010000             -push 0x105
    app->getMemory<x86::reg32>(cpu.esp-4) = 261 /*0x105*/;
    cpu.esp -= 4;
    // 004e329d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e329e  2eff1530455300         -call dword ptr cs:[0x534530]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457200) /* 0x534530 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e32a5  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004e32a7  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004e32a9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e32aa  2eff15f8465300         -call dword ptr cs:[0x5346f8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457656) /* 0x5346f8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e32b1  83fe01                 +cmp esi, 1
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
    // 004e32b4  7e16                   -jle 0x4e32cc
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004e32cc;
    }
    // 004e32b6  807c24013a             +cmp byte ptr [esp + 1], 0x3a
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1) /* 0x1 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(58 /*0x3a*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004e32bb  750f                   -jne 0x4e32cc
    if (!cpu.flags.zf)
    {
        goto L_0x004e32cc;
    }
    // 004e32bd  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004e32bf  8a0424                 -mov al, byte ptr [esp]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp);
    // 004e32c2  81c40c010000           -add esp, 0x10c
    (cpu.esp) += x86::reg32(x86::sreg32(268 /*0x10c*/));
    // 004e32c8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e32c9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e32ca  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e32cb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e32cc:
    // 004e32cc  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004e32ce  81c40c010000           -add esp, 0x10c
    (cpu.esp) += x86::reg32(x86::sreg32(268 /*0x10c*/));
    // 004e32d4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e32d5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e32d6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e32d7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_4e32e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e32e0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e32e1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e32e2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e32e3  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004e32e6  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004e32e8  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004e32ea  2eff15f4455300         -call dword ptr cs:[0x5345f4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457396) /* 0x5345f4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e32f1  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004e32f5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e32f6  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004e32fa  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e32fb  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004e32ff  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e3300  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004e3304  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e3305  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e3306  2eff1514455300         -call dword ptr cs:[0x534514]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457172) /* 0x534514 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e330d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e330f  740d                   -je 0x4e331e
    if (cpu.flags.zf)
    {
        goto L_0x004e331e;
    }
    // 004e3311  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004e3315  0faf0424               -imul eax, dword ptr [esp]
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp))));
    // 004e3319  0faf442404             -imul eax, dword ptr [esp + 4]
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */))));
L_0x004e331e:
    // 004e331e  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004e3321  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e3322  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e3323  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e3324  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_4e3330(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e3330  e81bffffff             -call 0x4e3250
    cpu.esp -= 4;
    sub_4e3250(app, cpu);
    if (cpu.terminate) return;
    // 004e3335  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e3337  7403                   -je 0x4e333c
    if (cpu.flags.zf)
    {
        goto L_0x004e333c;
    }
    // 004e3339  83e840                 -sub eax, 0x40
    (cpu.eax) -= x86::reg32(x86::sreg32(64 /*0x40*/));
L_0x004e333c:
    // 004e333c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4e3340(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e3340  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e3341  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e3342  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e3343  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004e3345  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004e3347  2eff15f4455300         -call dword ptr cs:[0x5345f4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457396) /* 0x5345f4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e334e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e334f  2eff15d4455300         -call dword ptr cs:[0x5345d4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457364) /* 0x5345d4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e3356  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e3358  7404                   -je 0x4e335e
    if (cpu.flags.zf)
    {
        goto L_0x004e335e;
    }
    // 004e335a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e335b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e335c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e335d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e335e:
    // 004e335e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e335f  ba98a25400             -mov edx, 0x54a298
    cpu.edx = 5546648 /*0x54a298*/;
    // 004e3364  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e3365  b9a4a25400             -mov ecx, 0x54a2a4
    cpu.ecx = 5546660 /*0x54a2a4*/;
    // 004e336a  bee0000000             -mov esi, 0xe0
    cpu.esi = 224 /*0xe0*/;
    // 004e336f  68b4a25400             -push 0x54a2b4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5546676 /*0x54a2b4*/;
    cpu.esp -= 4;
    // 004e3374  891590215500           -mov dword ptr [0x552190], edx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edx;
    // 004e337a  890d94215500           -mov dword ptr [0x552194], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ecx;
    // 004e3380  893598215500           -mov dword ptr [0x552198], esi
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.esi;
    // 004e3386  e885dcf1ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004e338b  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004e338e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e338f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e3390  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e3391  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e3392  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4e33a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e33a0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e33a1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e33a2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e33a3  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004e33a5  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004e33a7  2eff15f4455300         -call dword ptr cs:[0x5345f4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457396) /* 0x5345f4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e33ae  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e33af  68ff010000             -push 0x1ff
    app->getMemory<x86::reg32>(cpu.esp-4) = 511 /*0x1ff*/;
    cpu.esp -= 4;
    // 004e33b4  2eff1500455300         -call dword ptr cs:[0x534500]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457152) /* 0x534500 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e33bb  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004e33bd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e33bf  740b                   -je 0x4e33cc
    if (cpu.flags.zf)
    {
        goto L_0x004e33cc;
    }
    // 004e33c1  3dff010000             +cmp eax, 0x1ff
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(511 /*0x1ff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e33c6  7704                   -ja 0x4e33cc
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004e33cc;
    }
    // 004e33c8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e33c9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e33ca  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e33cb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e33cc:
    // 004e33cc  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e33cd  ba98a25400             -mov edx, 0x54a298
    cpu.edx = 5546648 /*0x54a298*/;
    // 004e33d2  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e33d3  b9d4a25400             -mov ecx, 0x54a2d4
    cpu.ecx = 5546708 /*0x54a2d4*/;
    // 004e33d8  bee9000000             -mov esi, 0xe9
    cpu.esi = 233 /*0xe9*/;
    // 004e33dd  68e4a25400             -push 0x54a2e4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5546724 /*0x54a2e4*/;
    cpu.esp -= 4;
    // 004e33e2  891590215500           -mov dword ptr [0x552190], edx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edx;
    // 004e33e8  890d94215500           -mov dword ptr [0x552194], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ecx;
    // 004e33ee  893598215500           -mov dword ptr [0x552198], esi
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.esi;
    // 004e33f4  e817dcf1ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004e33f9  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004e33fc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e33fd  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e33fe  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e33ff  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e3400  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4e3402(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e3402  90                     -nop 
    ;
    // 004e3403  90                     -nop 
    ;
    // 004e3404  90                     -nop 
    ;
    // 004e3405  90                     -nop 
    ;
    // 004e3406  90                     -nop 
    ;
    // 004e3407  90                     -nop 
    ;
    // 004e3408  90                     -nop 
    ;
    // 004e3409  90                     -nop 
    ;
    // 004e340a  90                     -nop 
    ;
    // 004e340b  90                     -nop 
    ;
    // 004e340c  90                     -nop 
    ;
    // 004e340d  90                     -nop 
    ;
    // 004e340e  90                     -nop 
    ;
    // 004e340f  90                     -nop 
    ;
    // 004e3410  90                     -nop 
    ;
    // 004e3411  90                     -nop 
    ;
    // 004e3412  90                     -nop 
    ;
    // 004e3413  90                     -nop 
    ;
    // 004e3414  90                     -nop 
    ;
    // 004e3415  90                     -nop 
    ;
    // 004e3416  90                     -nop 
    ;
    // 004e3417  90                     -nop 
    ;
    // 004e3418  90                     -nop 
    ;
    // 004e3419  90                     -nop 
    ;
    // 004e341a  90                     -nop 
    ;
    // 004e341b  90                     -nop 
    ;
    // 004e341c  90                     -nop 
    ;
    // 004e341d  90                     -nop 
    ;
    // 004e341e  90                     -nop 
    ;
    // 004e341f  90                     -nop 
    ;
    // 004e3420  90                     -nop 
    ;
    // 004e3421  90                     -nop 
    ;
    // 004e3422  90                     -nop 
    ;
    // 004e3423  90                     -nop 
    ;
    // 004e3424  90                     -nop 
    ;
    // 004e3425  90                     -nop 
    ;
    // 004e3426  90                     -nop 
    ;
    // 004e3427  90                     -nop 
    ;
    // 004e3428  90                     -nop 
    ;
    // 004e3429  90                     -nop 
    ;
    // 004e342a  90                     -nop 
    ;
    // 004e342b  90                     -nop 
    ;
    // 004e342c  90                     -nop 
    ;
    // 004e342d  90                     -nop 
    ;
    // 004e342e  90                     -nop 
    ;
    // 004e342f  90                     -nop 
    ;
    // 004e3430  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e3431  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e3432  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e3433  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e3434  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004e3435  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004e3438  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004e343a  833d9845560000         +cmp dword ptr [0x564598], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5653912) /* 0x564598 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e3441  7458                   -je 0x4e349b
    if (cpu.flags.zf)
    {
        goto L_0x004e349b;
    }
L_0x004e3443:
    // 004e3443  833da045560000         +cmp dword ptr [0x5645a0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5653920) /* 0x5645a0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e344a  7405                   -je 0x4e3451
    if (cpu.flags.zf)
    {
        goto L_0x004e3451;
    }
    // 004e344c  e86f000000             -call 0x4e34c0
    cpu.esp -= 4;
    sub_4e34c0(app, cpu);
    if (cpu.terminate) return;
L_0x004e3451:
    // 004e3451  8b3598455600           -mov esi, dword ptr [0x564598]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5653912) /* 0x564598 */);
    // 004e3457  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e3458  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e345e  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004e3460  7505                   -jne 0x4e3467
    if (!cpu.flags.zf)
    {
        goto L_0x004e3467;
    }
    // 004e3462  bb40000000             -mov ebx, 0x40
    cpu.ebx = 64 /*0x40*/;
L_0x004e3467:
    // 004e3467  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004e3469  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 004e346c  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004e346f  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004e3471  e89adc0100             -call 0x501110
    cpu.esp -= 4;
    sub_501110(app, cpu);
    if (cpu.terminate) return;
    // 004e3476  a3a0455600             -mov dword ptr [0x5645a0], eax
    app->getMemory<x86::reg32>(x86::reg32(5653920) /* 0x5645a0 */) = cpu.eax;
    // 004e347b  891d9c455600           -mov dword ptr [0x56459c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5653916) /* 0x56459c */) = cpu.ebx;
    // 004e3481  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e3483  7522                   -jne 0x4e34a7
    if (!cpu.flags.zf)
    {
        goto L_0x004e34a7;
    }
L_0x004e3485:
    // 004e3485  8b3d98455600           -mov edi, dword ptr [0x564598]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5653912) /* 0x564598 */);
    // 004e348b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004e348c  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e3492  83c404                 +add esp, 4
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
    // 004e3495  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e3496  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e3497  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e3498  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e3499  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e349a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e349b:
    // 004e349b  e8407e0000             -call 0x4eb2e0
    cpu.esp -= 4;
    sub_4eb2e0(app, cpu);
    if (cpu.terminate) return;
    // 004e34a0  a398455600             -mov dword ptr [0x564598], eax
    app->getMemory<x86::reg32>(x86::reg32(5653912) /* 0x564598 */) = cpu.eax;
    // 004e34a5  eb9c                   -jmp 0x4e3443
    goto L_0x004e3443;
L_0x004e34a7:
    // 004e34a7  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 004e34aa  e85dd2ffff             -call 0x4e070c
    cpu.esp -= 4;
    sub_4e070c(app, cpu);
    if (cpu.terminate) return;
    // 004e34af  ba80000000             -mov edx, 0x80
    cpu.edx = 128 /*0x80*/;
    // 004e34b4  b860f79e00             -mov eax, 0x9ef760
    cpu.eax = 10418016 /*0x9ef760*/;
    // 004e34b9  e84ed2ffff             -call 0x4e070c
    cpu.esp -= 4;
    sub_4e070c(app, cpu);
    if (cpu.terminate) return;
    // 004e34be  ebc5                   -jmp 0x4e3485
    goto L_0x004e3485;
}

/* align: skip  */
void Application::sub_4e3430(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004e3430;
    // 004e3402  90                     -nop 
    ;
    // 004e3403  90                     -nop 
    ;
    // 004e3404  90                     -nop 
    ;
    // 004e3405  90                     -nop 
    ;
    // 004e3406  90                     -nop 
    ;
    // 004e3407  90                     -nop 
    ;
    // 004e3408  90                     -nop 
    ;
    // 004e3409  90                     -nop 
    ;
    // 004e340a  90                     -nop 
    ;
    // 004e340b  90                     -nop 
    ;
    // 004e340c  90                     -nop 
    ;
    // 004e340d  90                     -nop 
    ;
    // 004e340e  90                     -nop 
    ;
    // 004e340f  90                     -nop 
    ;
    // 004e3410  90                     -nop 
    ;
    // 004e3411  90                     -nop 
    ;
    // 004e3412  90                     -nop 
    ;
    // 004e3413  90                     -nop 
    ;
    // 004e3414  90                     -nop 
    ;
    // 004e3415  90                     -nop 
    ;
    // 004e3416  90                     -nop 
    ;
    // 004e3417  90                     -nop 
    ;
    // 004e3418  90                     -nop 
    ;
    // 004e3419  90                     -nop 
    ;
    // 004e341a  90                     -nop 
    ;
    // 004e341b  90                     -nop 
    ;
    // 004e341c  90                     -nop 
    ;
    // 004e341d  90                     -nop 
    ;
    // 004e341e  90                     -nop 
    ;
    // 004e341f  90                     -nop 
    ;
    // 004e3420  90                     -nop 
    ;
    // 004e3421  90                     -nop 
    ;
    // 004e3422  90                     -nop 
    ;
    // 004e3423  90                     -nop 
    ;
    // 004e3424  90                     -nop 
    ;
    // 004e3425  90                     -nop 
    ;
    // 004e3426  90                     -nop 
    ;
    // 004e3427  90                     -nop 
    ;
    // 004e3428  90                     -nop 
    ;
    // 004e3429  90                     -nop 
    ;
    // 004e342a  90                     -nop 
    ;
    // 004e342b  90                     -nop 
    ;
    // 004e342c  90                     -nop 
    ;
    // 004e342d  90                     -nop 
    ;
    // 004e342e  90                     -nop 
    ;
    // 004e342f  90                     -nop 
    ;
L_entry_0x004e3430:
    // 004e3430  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e3431  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e3432  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e3433  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e3434  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004e3435  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004e3438  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004e343a  833d9845560000         +cmp dword ptr [0x564598], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5653912) /* 0x564598 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e3441  7458                   -je 0x4e349b
    if (cpu.flags.zf)
    {
        goto L_0x004e349b;
    }
L_0x004e3443:
    // 004e3443  833da045560000         +cmp dword ptr [0x5645a0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5653920) /* 0x5645a0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e344a  7405                   -je 0x4e3451
    if (cpu.flags.zf)
    {
        goto L_0x004e3451;
    }
    // 004e344c  e86f000000             -call 0x4e34c0
    cpu.esp -= 4;
    sub_4e34c0(app, cpu);
    if (cpu.terminate) return;
L_0x004e3451:
    // 004e3451  8b3598455600           -mov esi, dword ptr [0x564598]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5653912) /* 0x564598 */);
    // 004e3457  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e3458  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e345e  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004e3460  7505                   -jne 0x4e3467
    if (!cpu.flags.zf)
    {
        goto L_0x004e3467;
    }
    // 004e3462  bb40000000             -mov ebx, 0x40
    cpu.ebx = 64 /*0x40*/;
L_0x004e3467:
    // 004e3467  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004e3469  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 004e346c  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004e346f  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004e3471  e89adc0100             -call 0x501110
    cpu.esp -= 4;
    sub_501110(app, cpu);
    if (cpu.terminate) return;
    // 004e3476  a3a0455600             -mov dword ptr [0x5645a0], eax
    app->getMemory<x86::reg32>(x86::reg32(5653920) /* 0x5645a0 */) = cpu.eax;
    // 004e347b  891d9c455600           -mov dword ptr [0x56459c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5653916) /* 0x56459c */) = cpu.ebx;
    // 004e3481  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e3483  7522                   -jne 0x4e34a7
    if (!cpu.flags.zf)
    {
        goto L_0x004e34a7;
    }
L_0x004e3485:
    // 004e3485  8b3d98455600           -mov edi, dword ptr [0x564598]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5653912) /* 0x564598 */);
    // 004e348b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004e348c  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e3492  83c404                 +add esp, 4
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
    // 004e3495  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e3496  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e3497  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e3498  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e3499  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e349a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e349b:
    // 004e349b  e8407e0000             -call 0x4eb2e0
    cpu.esp -= 4;
    sub_4eb2e0(app, cpu);
    if (cpu.terminate) return;
    // 004e34a0  a398455600             -mov dword ptr [0x564598], eax
    app->getMemory<x86::reg32>(x86::reg32(5653912) /* 0x564598 */) = cpu.eax;
    // 004e34a5  eb9c                   -jmp 0x4e3443
    goto L_0x004e3443;
L_0x004e34a7:
    // 004e34a7  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 004e34aa  e85dd2ffff             -call 0x4e070c
    cpu.esp -= 4;
    sub_4e070c(app, cpu);
    if (cpu.terminate) return;
    // 004e34af  ba80000000             -mov edx, 0x80
    cpu.edx = 128 /*0x80*/;
    // 004e34b4  b860f79e00             -mov eax, 0x9ef760
    cpu.eax = 10418016 /*0x9ef760*/;
    // 004e34b9  e84ed2ffff             -call 0x4e070c
    cpu.esp -= 4;
    sub_4e070c(app, cpu);
    if (cpu.terminate) return;
    // 004e34be  ebc5                   -jmp 0x4e3485
    goto L_0x004e3485;
}

/* align: skip  */
void Application::sub_4e34c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e34c0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e34c1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e34c2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004e34c3  833da045560000         +cmp dword ptr [0x5645a0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5653920) /* 0x5645a0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e34ca  7504                   -jne 0x4e34d0
    if (!cpu.flags.zf)
    {
        goto L_0x004e34d0;
    }
    // 004e34cc  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e34cd  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e34ce  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e34cf  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e34d0:
    // 004e34d0  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004e34d1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e34d2  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e34d3  8b0d98455600           -mov ecx, dword ptr [0x564598]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5653912) /* 0x564598 */);
    // 004e34d9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e34da  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e34e0  8b1d9c455600           -mov ebx, dword ptr [0x56459c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5653916) /* 0x56459c */);
    // 004e34e6  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004e34e8  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004e34ea  7e24                   -jle 0x4e3510
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004e3510;
    }
    // 004e34ec  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x004e34ee:
    // 004e34ee  a1a0455600             -mov eax, dword ptr [0x5645a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653920) /* 0x5645a0 */);
    // 004e34f3  803c0100               +cmp byte ptr [ecx + eax], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx + cpu.eax * 1);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004e34f7  7409                   -je 0x4e3502
    if (cpu.flags.zf)
    {
        goto L_0x004e3502;
    }
    // 004e34f9  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004e34fb  f7d0                   -not eax
    cpu.eax = ~cpu.eax;
    // 004e34fd  e8de0a0000             -call 0x4e3fe0
    cpu.esp -= 4;
    sub_4e3fe0(app, cpu);
    if (cpu.terminate) return;
L_0x004e3502:
    // 004e3502  8b359c455600           -mov esi, dword ptr [0x56459c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5653916) /* 0x56459c */);
    // 004e3508  42                     -inc edx
    (cpu.edx)++;
    // 004e3509  83c120                 -add ecx, 0x20
    (cpu.ecx) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004e350c  39f2                   +cmp edx, esi
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
    // 004e350e  7cde                   -jl 0x4e34ee
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004e34ee;
    }
L_0x004e3510:
    // 004e3510  a1a0455600             -mov eax, dword ptr [0x5645a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653920) /* 0x5645a0 */);
    // 004e3515  e866dc0100             -call 0x501180
    cpu.esp -= 4;
    sub_501180(app, cpu);
    if (cpu.terminate) return;
    // 004e351a  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004e351c  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004e351e  893da0455600           -mov dword ptr [0x5645a0], edi
    app->getMemory<x86::reg32>(x86::reg32(5653920) /* 0x5645a0 */) = cpu.edi;
    // 004e3524  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004e3526  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e3527  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e3528  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004e3529:
    // 004e3529  8baa60f79e00           -mov ebp, dword ptr [edx + 0x9ef760]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(10418016) /* 0x9ef760 */);
    // 004e352f  39e9                   +cmp ecx, ebp
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
    // 004e3531  740d                   -je 0x4e3540
    if (cpu.flags.zf)
    {
        goto L_0x004e3540;
    }
    // 004e3533  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004e3535  e8267e0000             -call 0x4eb360
    cpu.esp -= 4;
    sub_4eb360(app, cpu);
    if (cpu.terminate) return;
    // 004e353a  898a60f79e00           -mov dword ptr [edx + 0x9ef760], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(10418016) /* 0x9ef760 */) = cpu.ecx;
L_0x004e3540:
    // 004e3540  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004e3543  81fa80000000           +cmp edx, 0x80
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(128 /*0x80*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e3549  75de                   -jne 0x4e3529
    if (!cpu.flags.zf)
    {
        goto L_0x004e3529;
    }
    // 004e354b  a198455600             -mov eax, dword ptr [0x564598]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653912) /* 0x564598 */);
    // 004e3550  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e3551  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e3557  a198455600             -mov eax, dword ptr [0x564598]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653912) /* 0x564598 */);
    // 004e355c  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004e355e  e8fd7d0000             -call 0x4eb360
    cpu.esp -= 4;
    sub_4eb360(app, cpu);
    if (cpu.terminate) return;
    // 004e3563  891598455600           -mov dword ptr [0x564598], edx
    app->getMemory<x86::reg32>(x86::reg32(5653912) /* 0x564598 */) = cpu.edx;
    // 004e3569  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e356a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e356b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e356c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4e3570(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e3570  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e3571  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e3572  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e3573  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e3574  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004e3575  833da045560000         +cmp dword ptr [0x5645a0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5653920) /* 0x5645a0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e357c  744f                   -je 0x4e35cd
    if (cpu.flags.zf)
    {
        goto L_0x004e35cd;
    }
L_0x004e357e:
    // 004e357e  8b0d98455600           -mov ecx, dword ptr [0x564598]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5653912) /* 0x564598 */);
    // 004e3584  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e3585  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e358b  8b359c455600           -mov esi, dword ptr [0x56459c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5653916) /* 0x56459c */);
    // 004e3591  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004e3593  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004e3595  7e19                   -jle 0x4e35b0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004e35b0;
    }
    // 004e3597  8b15a0455600           -mov edx, dword ptr [0x5645a0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5653920) /* 0x5645a0 */);
    // 004e359d  c1e605                 -shl esi, 5
    cpu.esi <<= 5 /*0x5*/ % 32;
    // 004e35a0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004e35a2:
    // 004e35a2  803c0200               +cmp byte ptr [edx + eax], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx + cpu.eax * 1);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004e35a6  7408                   -je 0x4e35b0
    if (cpu.flags.zf)
    {
        goto L_0x004e35b0;
    }
    // 004e35a8  83c020                 -add eax, 0x20
    (cpu.eax) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004e35ab  43                     -inc ebx
    (cpu.ebx)++;
    // 004e35ac  39f0                   +cmp eax, esi
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
    // 004e35ae  7cf2                   -jl 0x4e35a2
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004e35a2;
    }
L_0x004e35b0:
    // 004e35b0  3b1d9c455600           +cmp ebx, dword ptr [0x56459c]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5653916) /* 0x56459c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e35b6  7c1e                   -jl 0x4e35d6
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004e35d6;
    }
L_0x004e35b8:
    // 004e35b8  8b2d98455600           -mov ebp, dword ptr [0x564598]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5653912) /* 0x564598 */);
    // 004e35be  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004e35bf  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e35c5  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004e35c7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e35c8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e35c9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e35ca  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e35cb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e35cc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e35cd:
    // 004e35cd  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004e35cf  e85cfeffff             -call 0x4e3430
    cpu.esp -= 4;
    sub_4e3430(app, cpu);
    if (cpu.terminate) return;
    // 004e35d4  eba8                   -jmp 0x4e357e
    goto L_0x004e357e;
L_0x004e35d6:
    // 004e35d6  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004e35d8  a1a0455600             -mov eax, dword ptr [0x5645a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653920) /* 0x5645a0 */);
    // 004e35dd  c1e605                 -shl esi, 5
    cpu.esi <<= 5 /*0x5*/ % 32;
    // 004e35e0  ba20000000             -mov edx, 0x20
    cpu.edx = 32 /*0x20*/;
    // 004e35e5  01f0                   +add eax, esi
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004e35e7  e820d1ffff             -call 0x4e070c
    cpu.esp -= 4;
    sub_4e070c(app, cpu);
    if (cpu.terminate) return;
    // 004e35ec  a1a0455600             -mov eax, dword ptr [0x5645a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653920) /* 0x5645a0 */);
    // 004e35f1  c6040601               -mov byte ptr [esi + eax], 1
    app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1) = 1 /*0x1*/;
    // 004e35f5  ebc1                   -jmp 0x4e35b8
    goto L_0x004e35b8;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_4e3600(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e3600  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e3601  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e3602  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e3603  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004e3605  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004e3607  2eff15f4455300         -call dword ptr cs:[0x5345f4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457396) /* 0x5345f4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e360e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e360f  2eff15b0445300         -call dword ptr cs:[0x5344b0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457072) /* 0x5344b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e3616  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e3617  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e3618  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e3619  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_4e3620(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e3620  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e3621  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004e3622  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004e3623  81ec2c010000           -sub esp, 0x12c
    (cpu.esp) -= x86::reg32(x86::sreg32(300 /*0x12c*/));
    // 004e3629  8984241c010000         -mov dword ptr [esp + 0x11c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(284) /* 0x11c */) = cpu.eax;
    // 004e3630  89942428010000         -mov dword ptr [esp + 0x128], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(296) /* 0x128 */) = cpu.edx;
    // 004e3637  899c2420010000         -mov dword ptr [esp + 0x120], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(288) /* 0x120 */) = cpu.ebx;
    // 004e363e  898c2418010000         -mov dword ptr [esp + 0x118], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(280) /* 0x118 */) = cpu.ecx;
    // 004e3645  e826ffffff             -call 0x4e3570
    cpu.esp -= 4;
    sub_4e3570(app, cpu);
    if (cpu.terminate) return;
    // 004e364a  bb80000000             -mov ebx, 0x80
    cpu.ebx = 128 /*0x80*/;
    // 004e364f  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 004e3651  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004e3653  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004e3654  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004e3656  8929                   -mov dword ptr [ecx], ebp
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.ebp;
    // 004e3658  2eff15f4455300         -call dword ptr cs:[0x5345f4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457396) /* 0x5345f4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e365f  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004e3661  89ac2424010000         -mov dword ptr [esp + 0x124], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(292) /* 0x124 */) = cpu.ebp;
    // 004e3668  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004e366a  0f8c6c020000           -jl 0x4e38dc
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004e38dc;
    }
    // 004e3670  3b359c455600           +cmp esi, dword ptr [0x56459c]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5653916) /* 0x56459c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e3676  0f8d60020000           -jge 0x4e38dc
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004e38dc;
    }
    // 004e367c  f684242801000001       +test byte ptr [esp + 0x128], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(296) /* 0x128 */) & 1 /*0x1*/));
    // 004e3684  7405                   -je 0x4e368b
    if (cpu.flags.zf)
    {
        goto L_0x004e368b;
    }
    // 004e3686  bf00000080             -mov edi, 0x80000000
    cpu.edi = 2147483648 /*0x80000000*/;
L_0x004e368b:
    // 004e368b  f684242801000002       +test byte ptr [esp + 0x128], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(296) /* 0x128 */) & 2 /*0x2*/));
    // 004e3693  7406                   -je 0x4e369b
    if (cpu.flags.zf)
    {
        goto L_0x004e369b;
    }
    // 004e3695  81cf00000040           -or edi, 0x40000000
    cpu.edi |= x86::reg32(x86::sreg32(1073741824 /*0x40000000*/));
L_0x004e369b:
    // 004e369b  f684242801000004       +test byte ptr [esp + 0x128], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(296) /* 0x128 */) & 4 /*0x4*/));
    // 004e36a3  7408                   -je 0x4e36ad
    if (cpu.flags.zf)
    {
        goto L_0x004e36ad;
    }
    // 004e36a5  808c242401000001       -or byte ptr [esp + 0x124], 1
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(292) /* 0x124 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x004e36ad:
    // 004e36ad  f684242801000008       +test byte ptr [esp + 0x128], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(296) /* 0x128 */) & 8 /*0x8*/));
    // 004e36b5  7408                   -je 0x4e36bf
    if (cpu.flags.zf)
    {
        goto L_0x004e36bf;
    }
    // 004e36b7  808c242401000002       -or byte ptr [esp + 0x124], 2
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(292) /* 0x124 */) |= x86::reg8(x86::sreg8(2 /*0x2*/));
L_0x004e36bf:
    // 004e36bf  8aa42428010000         -mov ah, byte ptr [esp + 0x128]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(296) /* 0x128 */);
    // 004e36c6  f6c410                 +test ah, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 16 /*0x10*/));
    // 004e36c9  0f8423020000           -je 0x4e38f2
    if (cpu.flags.zf)
    {
        goto L_0x004e38f2;
    }
    // 004e36cf  f6c420                 +test ah, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 32 /*0x20*/));
    // 004e36d2  0f8410020000           -je 0x4e38e8
    if (cpu.flags.zf)
    {
        goto L_0x004e38e8;
    }
    // 004e36d8  bd02000000             -mov ebp, 2
    cpu.ebp = 2 /*0x2*/;
L_0x004e36dd:
    // 004e36dd  f684242901000001       +test byte ptr [esp + 0x129], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(297) /* 0x129 */) & 1 /*0x1*/));
    // 004e36e5  7406                   -je 0x4e36ed
    if (cpu.flags.zf)
    {
        goto L_0x004e36ed;
    }
    // 004e36e7  81cb00000020           -or ebx, 0x20000000
    cpu.ebx |= x86::reg32(x86::sreg32(536870912 /*0x20000000*/));
L_0x004e36ed:
    // 004e36ed  f684242901000002       +test byte ptr [esp + 0x129], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(297) /* 0x129 */) & 2 /*0x2*/));
    // 004e36f5  7406                   -je 0x4e36fd
    if (cpu.flags.zf)
    {
        goto L_0x004e36fd;
    }
    // 004e36f7  81cb00000008           -or ebx, 0x8000000
    cpu.ebx |= x86::reg32(x86::sreg32(134217728 /*0x8000000*/));
L_0x004e36fd:
    // 004e36fd  f684242901000004       +test byte ptr [esp + 0x129], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(297) /* 0x129 */) & 4 /*0x4*/));
    // 004e3705  7406                   -je 0x4e370d
    if (cpu.flags.zf)
    {
        goto L_0x004e370d;
    }
    // 004e3707  81cb00000080           -or ebx, 0x80000000
    cpu.ebx |= x86::reg32(x86::sreg32(2147483648 /*0x80000000*/));
L_0x004e370d:
    // 004e370d  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004e370f  a1a0455600             -mov eax, dword ptr [0x5645a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653920) /* 0x5645a0 */);
    // 004e3714  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 004e3717  8b8c2428010000         -mov ecx, dword ptr [esp + 0x128]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(296) /* 0x128 */);
    // 004e371e  894c0208               -mov dword ptr [edx + eax + 8], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */ + cpu.eax * 1) = cpu.ecx;
    // 004e3722  8b84241c010000         -mov eax, dword ptr [esp + 0x11c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(284) /* 0x11c */);
    // 004e3729  e802fcffff             -call 0x4e3330
    cpu.esp -= 4;
    sub_4e3330(app, cpu);
    if (cpu.terminate) return;
    // 004e372e  8b0da0455600           -mov ecx, dword ptr [0x5645a0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5653920) /* 0x5645a0 */);
    // 004e3734  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004e3736  89842414010000         -mov dword ptr [esp + 0x114], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(276) /* 0x114 */) = cpu.eax;
    // 004e373d  884201                 -mov byte ptr [edx + 1], al
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 004e3740  8d148500000000         -lea edx, [eax*4]
    cpu.edx = x86::reg32(cpu.eax * 4);
    // 004e3747  8b8260f79e00           -mov eax, dword ptr [edx + 0x9ef760]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(10418016) /* 0x9ef760 */);
    // 004e374d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e374f  750b                   -jne 0x4e375c
    if (!cpu.flags.zf)
    {
        goto L_0x004e375c;
    }
    // 004e3751  e88a7b0000             -call 0x4eb2e0
    cpu.esp -= 4;
    sub_4eb2e0(app, cpu);
    if (cpu.terminate) return;
    // 004e3756  898260f79e00           -mov dword ptr [edx + 0x9ef760], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(10418016) /* 0x9ef760 */) = cpu.eax;
L_0x004e375c:
    // 004e375c  8b842414010000         -mov eax, dword ptr [esp + 0x114]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(276) /* 0x114 */);
    // 004e3763  8b148560f79e00         -mov edx, dword ptr [eax*4 + 0x9ef760]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10418016) /* 0x9ef760 */ + cpu.eax * 4);
    // 004e376a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e376b  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e3771  8d842410010000         -lea eax, [esp + 0x110]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(272) /* 0x110 */);
    // 004e3778  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e3779  8d842410010000         -lea eax, [esp + 0x110]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(272) /* 0x110 */);
    // 004e3780  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e3781  8d842410010000         -lea eax, [esp + 0x110]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(272) /* 0x110 */);
    // 004e3788  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e3789  8d842410010000         -lea eax, [esp + 0x110]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(272) /* 0x110 */);
    // 004e3790  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e3791  8d442410               -lea eax, [esp + 0x10]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004e3795  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e3796  2eff1514455300         -call dword ptr cs:[0x534514]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457172) /* 0x534514 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e379d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e379f  750b                   -jne 0x4e37ac
    if (!cpu.flags.zf)
    {
        goto L_0x004e37ac;
    }
    // 004e37a1  c784240801000000080000 -mov dword ptr [esp + 0x108], 0x800
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(264) /* 0x108 */) = 2048 /*0x800*/;
L_0x004e37ac:
    // 004e37ac  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004e37ae  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e37af  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004e37b0  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004e37b2  8b9c2434010000         -mov ebx, dword ptr [esp + 0x134]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(308) /* 0x134 */);
    // 004e37b9  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e37ba  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004e37bb  8bbc2434010000         -mov edi, dword ptr [esp + 0x134]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(308) /* 0x134 */);
    // 004e37c2  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004e37c4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004e37c5  c1e305                 -shl ebx, 5
    cpu.ebx <<= 5 /*0x5*/ % 32;
    // 004e37c8  2eff1598445300         -call dword ptr cs:[0x534498]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457048) /* 0x534498 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e37cf  8b2da0455600           -mov ebp, dword ptr [0x5645a0]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5653920) /* 0x5645a0 */);
    // 004e37d5  01dd                   -add ebp, ebx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004e37d7  894504                 -mov dword ptr [ebp + 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004e37da  83f8ff                 +cmp eax, -1
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
    // 004e37dd  0f8469010000           -je 0x4e394c
    if (cpu.flags.zf)
    {
        goto L_0x004e394c;
    }
    // 004e37e3  8b942420010000         -mov edx, dword ptr [esp + 0x120]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(288) /* 0x120 */);
    // 004e37ea  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004e37ec  0f851d010000           -jne 0x4e390f
    if (!cpu.flags.zf)
    {
        goto L_0x004e390f;
    }
L_0x004e37f2:
    // 004e37f2  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004e37f4  8b15a0455600           -mov edx, dword ptr [0x5645a0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5653920) /* 0x5645a0 */);
    // 004e37fa  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 004e37fd  c744020c00400000       -mov dword ptr [edx + eax + 0xc], 0x4000
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */ + cpu.eax * 1) = 16384 /*0x4000*/;
L_0x004e3805:
    // 004e3805  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 004e3807  a1a0455600             -mov eax, dword ptr [0x5645a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653920) /* 0x5645a0 */);
    // 004e380c  c1e705                 -shl edi, 5
    cpu.edi <<= 5 /*0x5*/ % 32;
    // 004e380f  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004e3811  8b6c0704               -mov ebp, dword ptr [edi + eax + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */ + cpu.eax * 1);
    // 004e3815  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004e3816  2eff1524455300         -call dword ptr cs:[0x534524]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457188) /* 0x534524 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e381d  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004e381f  a1a0455600             -mov eax, dword ptr [0x5645a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653920) /* 0x5645a0 */);
    // 004e3824  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 004e3826  8a942429010000         -mov dl, byte ptr [esp + 0x129]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(297) /* 0x129 */);
    // 004e382d  89581c                 -mov dword ptr [eax + 0x1c], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ebx;
    // 004e3830  f6c208                 +test dl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 8 /*0x8*/));
    // 004e3833  0f8476000000           -je 0x4e38af
    if (cpu.flags.zf)
    {
        goto L_0x004e38af;
    }
    // 004e3839  f684242801000002       +test byte ptr [esp + 0x128], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(296) /* 0x128 */) & 2 /*0x2*/));
    // 004e3841  0f84f6000000           -je 0x4e393d
    if (cpu.flags.zf)
    {
        goto L_0x004e393d;
    }
    // 004e3847  bf02000000             -mov edi, 2
    cpu.edi = 2 /*0x2*/;
    // 004e384c  b804000008             -mov eax, 0x8000004
    cpu.eax = 134217732 /*0x8000004*/;
L_0x004e3851:
    // 004e3851  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004e3853  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004e3855  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004e3857  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004e3859  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e385a  a1a0455600             -mov eax, dword ptr [0x5645a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653920) /* 0x5645a0 */);
    // 004e385f  c1e305                 -shl ebx, 5
    cpu.ebx <<= 5 /*0x5*/ % 32;
    // 004e3862  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004e3864  8b540304               -mov edx, dword ptr [ebx + eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */ + cpu.eax * 1);
    // 004e3868  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e3869  2eff159c445300         -call dword ptr cs:[0x53449c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457052) /* 0x53449c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e3870  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004e3872  a1a0455600             -mov eax, dword ptr [0x5645a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653920) /* 0x5645a0 */);
    // 004e3877  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004e3879  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004e387b  895010                 -mov dword ptr [eax + 0x10], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 004e387e  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004e3880  741b                   -je 0x4e389d
    if (cpu.flags.zf)
    {
        goto L_0x004e389d;
    }
    // 004e3882  8b681c                 -mov ebp, dword ptr [eax + 0x1c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004e3885  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004e3886  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004e3888  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004e388a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004e388b  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e388c  2eff1590455300         -call dword ptr cs:[0x534590]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457296) /* 0x534590 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e3893  8b15a0455600           -mov edx, dword ptr [0x5645a0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5653920) /* 0x5645a0 */);
    // 004e3899  89441a14               -mov dword ptr [edx + ebx + 0x14], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */ + cpu.ebx * 1) = cpu.eax;
L_0x004e389d:
    // 004e389d  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004e389f  a1a0455600             -mov eax, dword ptr [0x5645a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653920) /* 0x5645a0 */);
    // 004e38a4  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 004e38a7  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004e38a9  83781400               +cmp dword ptr [eax + 0x14], 0
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
    // 004e38ad  7504                   -jne 0x4e38b3
    if (!cpu.flags.zf)
    {
        goto L_0x004e38b3;
    }
L_0x004e38af:
    // 004e38af  806009f7               -and byte ptr [eax + 9], 0xf7
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(9) /* 0x9 */) &= x86::reg8(x86::sreg8(247 /*0xf7*/));
L_0x004e38b3:
    // 004e38b3  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004e38b5  8b842418010000         -mov eax, dword ptr [esp + 0x118]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(280) /* 0x118 */);
    // 004e38bc  f7d3                   -not ebx
    cpu.ebx = ~cpu.ebx;
    // 004e38be  8930                   -mov dword ptr [eax], esi
    app->getMemory<x86::reg32>(cpu.eax) = cpu.esi;
    // 004e38c0  bd01000000             -mov ebp, 1
    cpu.ebp = 1 /*0x1*/;
    // 004e38c5  8918                   -mov dword ptr [eax], ebx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ebx;
L_0x004e38c7:
    // 004e38c7  8b842414010000         -mov eax, dword ptr [esp + 0x114]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(276) /* 0x114 */);
    // 004e38ce  8b348560f79e00         -mov esi, dword ptr [eax*4 + 0x9ef760]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(10418016) /* 0x9ef760 */ + cpu.eax * 4);
    // 004e38d5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e38d6  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004e38dc:
    // 004e38dc  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004e38de  81c42c010000           +add esp, 0x12c
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(300 /*0x12c*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004e38e4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e38e5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e38e6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e38e7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e38e8:
    // 004e38e8  bd01000000             -mov ebp, 1
    cpu.ebp = 1 /*0x1*/;
    // 004e38ed  e9ebfdffff             -jmp 0x4e36dd
    goto L_0x004e36dd;
L_0x004e38f2:
    // 004e38f2  f6c420                 +test ah, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 32 /*0x20*/));
    // 004e38f5  740c                   -je 0x4e3903
    if (cpu.flags.zf)
    {
        goto L_0x004e3903;
    }
    // 004e38f7  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 004e38fc  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004e38fe  e9dafdffff             -jmp 0x4e36dd
    goto L_0x004e36dd;
L_0x004e3903:
    // 004e3903  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 004e3908  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004e390a  e9cefdffff             -jmp 0x4e36dd
    goto L_0x004e36dd;
L_0x004e390f:
    // 004e390f  8b8c2408010000         -mov ecx, dword ptr [esp + 0x108]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(264) /* 0x108 */);
    // 004e3916  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004e3918  0f84d4feffff           -je 0x4e37f2
    if (cpu.flags.zf)
    {
        goto L_0x004e37f2;
    }
    // 004e391e  39ca                   +cmp edx, ecx
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
    // 004e3920  7613                   -jbe 0x4e3935
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004e3935;
    }
    // 004e3922  8d440aff               -lea eax, [edx + ecx - 1]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(-1) /* -0x1 */ + cpu.ecx * 1);
    // 004e3926  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004e3928  f7f1                   -div ecx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ecx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 004e392a  0fafc1                 +imul eax, ecx
    {
        x86::sreg64 tmp = x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ecx));
        cpu.eax = static_cast<x86::reg32>(static_cast<x86::sreg32>(tmp));
        cpu.flags.of = cpu.flags.cf = (tmp != x86::sreg64(x86::sreg32(cpu.eax)));
    }
    // 004e392d  89450c                 -mov dword ptr [ebp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004e3930  e9d0feffff             -jmp 0x4e3805
    goto L_0x004e3805;
L_0x004e3935:
    // 004e3935  894d0c                 -mov dword ptr [ebp + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 004e3938  e9c8feffff             -jmp 0x4e3805
    goto L_0x004e3805;
L_0x004e393d:
    // 004e393d  bf04000000             -mov edi, 4
    cpu.edi = 4 /*0x4*/;
    // 004e3942  b802000008             -mov eax, 0x8000002
    cpu.eax = 134217730 /*0x8000002*/;
    // 004e3947  e905ffffff             -jmp 0x4e3851
    goto L_0x004e3851;
L_0x004e394c:
    // 004e394c  2eff1534455300         -call dword ptr cs:[0x534534]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457204) /* 0x534534 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e3953  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004e3958  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e3959  6820a35400             -push 0x54a320
    app->getMemory<x86::reg32>(cpu.esp-4) = 5546784 /*0x54a320*/;
    cpu.esp -= 4;
    // 004e395e  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004e3960  6894455600             -push 0x564594
    app->getMemory<x86::reg32>(cpu.esp-4) = 5653908 /*0x564594*/;
    cpu.esp -= 4;
    // 004e3965  e8e6d60100             -call 0x501050
    cpu.esp -= 4;
    sub_501050(app, cpu);
    if (cpu.terminate) return;
    // 004e396a  a1a0455600             -mov eax, dword ptr [0x5645a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653920) /* 0x5645a0 */);
    // 004e396f  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 004e3971  83c410                 +add esp, 0x10
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
    // 004e3974  c6040300               -mov byte ptr [ebx + eax], 0
    app->getMemory<x86::reg8>(cpu.ebx + cpu.eax * 1) = 0 /*0x0*/;
    // 004e3978  e94affffff             -jmp 0x4e38c7
    goto L_0x004e38c7;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4e3980(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e3980  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e3981  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004e3982  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004e3983  83ec20                 -sub esp, 0x20
    (cpu.esp) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004e3986  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004e3988  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 004e398a  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 004e398c  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004e3991  8b0da0455600           -mov ecx, dword ptr [0x5645a0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5653920) /* 0x5645a0 */);
    // 004e3997  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004e3999  89542414               -mov dword ptr [esp + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 004e399d  f7d3                   -not ebx
    cpu.ebx = ~cpu.ebx;
    // 004e399f  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004e39a1  741c                   -je 0x4e39bf
    if (cpu.flags.zf)
    {
        goto L_0x004e39bf;
    }
    // 004e39a3  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004e39a5  7c18                   -jl 0x4e39bf
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004e39bf;
    }
    // 004e39a7  3b1d9c455600           +cmp ebx, dword ptr [0x56459c]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5653916) /* 0x56459c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e39ad  7d10                   -jge 0x4e39bf
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004e39bf;
    }
    // 004e39af  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004e39b1  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 004e39b4  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004e39b8  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004e39ba  803800                 +cmp byte ptr [eax], 0
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
    // 004e39bd  750b                   -jne 0x4e39ca
    if (!cpu.flags.zf)
    {
        goto L_0x004e39ca;
    }
L_0x004e39bf:
    // 004e39bf  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004e39c1  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004e39c4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e39c5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e39c6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e39c7  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x004e39ca:
    // 004e39ca  8a4001                 -mov al, byte ptr [eax + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004e39cd  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004e39d2  8b0c8560f79e00         -mov ecx, dword ptr [eax*4 + 0x9ef760]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10418016) /* 0x9ef760 */ + cpu.eax * 4);
    // 004e39d9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e39da  89442420               -mov dword ptr [esp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 004e39de  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e39e4  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004e39e6  2eff15f4455300         -call dword ptr cs:[0x5345f4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457396) /* 0x5345f4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e39ed  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004e39ef  7410                   -je 0x4e3a01
    if (cpu.flags.zf)
    {
        goto L_0x004e3a01;
    }
    // 004e39f1  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004e39f5  a1a0455600             -mov eax, dword ptr [0x5645a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653920) /* 0x5645a0 */);
    // 004e39fa  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004e39fc  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004e39ff  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
L_0x004e3a01:
    // 004e3a01  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004e3a03  7412                   -je 0x4e3a17
    if (cpu.flags.zf)
    {
        goto L_0x004e3a17;
    }
    // 004e3a05  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004e3a07  8b35a0455600           -mov esi, dword ptr [0x5645a0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5653920) /* 0x5645a0 */);
    // 004e3a0d  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 004e3a10  8b44060c               -mov eax, dword ptr [esi + eax + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */ + cpu.eax * 1);
    // 004e3a14  894500                 -mov dword ptr [ebp], eax
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.eax;
L_0x004e3a17:
    // 004e3a17  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004e3a19  7411                   -je 0x4e3a2c
    if (cpu.flags.zf)
    {
        goto L_0x004e3a2c;
    }
    // 004e3a1b  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004e3a1d  8b1da0455600           -mov ebx, dword ptr [0x5645a0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5653920) /* 0x5645a0 */);
    // 004e3a23  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 004e3a26  8b44031c               -mov eax, dword ptr [ebx + eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */ + cpu.eax * 1);
    // 004e3a2a  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
L_0x004e3a2c:
    // 004e3a2c  837c243000             +cmp dword ptr [esp + 0x30], 0
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
    // 004e3a31  7460                   -je 0x4e3a93
    if (cpu.flags.zf)
    {
        goto L_0x004e3a93;
    }
    // 004e3a33  be40a35400             -mov esi, 0x54a340
    cpu.esi = 5546816 /*0x54a340*/;
    // 004e3a38  8d7c2410               -lea edi, [esp + 0x10]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004e3a3c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x004e3a3d:
    // 004e3a3d  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004e3a3f  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 004e3a41  3c00                   +cmp al, 0
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
    // 004e3a43  7410                   -je 0x4e3a55
    if (cpu.flags.zf)
    {
        goto L_0x004e3a55;
    }
    // 004e3a45  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004e3a48  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004e3a4b  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 004e3a4e  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004e3a51  3c00                   +cmp al, 0
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
    // 004e3a53  75e8                   -jne 0x4e3a3d
    if (!cpu.flags.zf)
    {
        goto L_0x004e3a3d;
    }
L_0x004e3a55:
    // 004e3a55  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e3a56  8a44241c               -mov al, byte ptr [esp + 0x1c]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004e3a5a  0440                   -add al, 0x40
    (cpu.al) += x86::reg8(x86::sreg8(64 /*0x40*/));
    // 004e3a5c  88442410               -mov byte ptr [esp + 0x10], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.al;
    // 004e3a60  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004e3a64  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e3a65  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004e3a69  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e3a6a  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004e3a6e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e3a6f  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004e3a73  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e3a74  8d442420               -lea eax, [esp + 0x20]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004e3a78  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e3a79  2eff1514455300         -call dword ptr cs:[0x534514]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457172) /* 0x534514 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e3a80  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e3a82  742e                   -je 0x4e3ab2
    if (cpu.flags.zf)
    {
        goto L_0x004e3ab2;
    }
    // 004e3a84  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004e3a88  0faf442404             -imul eax, dword ptr [esp + 4]
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */))));
    // 004e3a8d  8b5c2430               -mov ebx, dword ptr [esp + 0x30]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 004e3a91  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
L_0x004e3a93:
    // 004e3a93  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004e3a97  8b3c8560f79e00         -mov edi, dword ptr [eax*4 + 0x9ef760]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(10418016) /* 0x9ef760 */ + cpu.eax * 4);
    // 004e3a9e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004e3a9f  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e3aa5  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004e3aa9  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004e3aac  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e3aad  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e3aae  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e3aaf  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x004e3ab2:
    // 004e3ab2  2eff1534455300         -call dword ptr cs:[0x534534]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457204) /* 0x534534 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e3ab9  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004e3abe  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e3abf  6844a35400             -push 0x54a344
    app->getMemory<x86::reg32>(cpu.esp-4) = 5546820 /*0x54a344*/;
    cpu.esp -= 4;
    // 004e3ac4  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004e3ac6  6894455600             -push 0x564594
    app->getMemory<x86::reg32>(cpu.esp-4) = 5653908 /*0x564594*/;
    cpu.esp -= 4;
    // 004e3acb  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004e3acd  e87ed50100             -call 0x501050
    cpu.esp -= 4;
    sub_501050(app, cpu);
    if (cpu.terminate) return;
    // 004e3ad2  83c410                 +add esp, 0x10
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
    // 004e3ad5  895c2414               -mov dword ptr [esp + 0x14], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ebx;
    // 004e3ad9  ebb8                   -jmp 0x4e3a93
    goto L_0x004e3a93;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_4e3ae0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e3ae0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e3ae1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e3ae2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004e3ae3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004e3ae4  83ec1c                 -sub esp, 0x1c
    (cpu.esp) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004e3ae7  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 004e3ae9  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004e3aeb  8b1da0455600           -mov ebx, dword ptr [0x5645a0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5653920) /* 0x5645a0 */);
    // 004e3af1  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004e3af5  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004e3af7  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004e3af9  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 004e3afb  89542418               -mov dword ptr [esp + 0x18], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 004e3aff  894c240c               -mov dword ptr [esp + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 004e3b03  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004e3b05  7419                   -je 0x4e3b20
    if (cpu.flags.zf)
    {
        goto L_0x004e3b20;
    }
    // 004e3b07  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004e3b09  7c15                   -jl 0x4e3b20
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004e3b20;
    }
    // 004e3b0b  3b0d9c455600           +cmp ecx, dword ptr [0x56459c]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5653916) /* 0x56459c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e3b11  7d0d                   -jge 0x4e3b20
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004e3b20;
    }
    // 004e3b13  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004e3b15  c1e605                 -shl esi, 5
    cpu.esi <<= 5 /*0x5*/ % 32;
    // 004e3b18  8d0433                 -lea eax, [ebx + esi]
    cpu.eax = x86::reg32(cpu.ebx + cpu.esi * 1);
    // 004e3b1b  803800                 +cmp byte ptr [eax], 0
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
    // 004e3b1e  750a                   -jne 0x4e3b2a
    if (!cpu.flags.zf)
    {
        goto L_0x004e3b2a;
    }
L_0x004e3b20:
    // 004e3b20  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004e3b22  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004e3b25  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e3b26  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e3b27  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e3b28  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e3b29  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e3b2a:
    // 004e3b2a  8a4001                 -mov al, byte ptr [eax + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004e3b2d  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004e3b32  8b0c8560f79e00         -mov ecx, dword ptr [eax*4 + 0x9ef760]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10418016) /* 0x9ef760 */ + cpu.eax * 4);
    // 004e3b39  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e3b3a  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004e3b3e  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e3b44  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004e3b46  2eff15f4455300         -call dword ptr cs:[0x5345f4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457396) /* 0x5345f4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e3b4d  a1a0455600             -mov eax, dword ptr [0x5645a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653920) /* 0x5645a0 */);
    // 004e3b52  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 004e3b54  8b5018                 -mov edx, dword ptr [eax + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004e3b57  8b581c                 -mov ebx, dword ptr [eax + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004e3b5a  39da                   +cmp edx, ebx
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
    // 004e3b5c  7e03                   -jle 0x4e3b61
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004e3b61;
    }
    // 004e3b5e  895818                 -mov dword ptr [eax + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.ebx;
L_0x004e3b61:
    // 004e3b61  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004e3b65  a1a0455600             -mov eax, dword ptr [0x5645a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653920) /* 0x5645a0 */);
    // 004e3b6a  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 004e3b6d  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004e3b6f  8b5018                 -mov edx, dword ptr [eax + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004e3b72  8b701c                 -mov esi, dword ptr [eax + 0x1c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004e3b75  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 004e3b77  39f2                   +cmp edx, esi
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
    // 004e3b79  7e05                   -jle 0x4e3b80
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004e3b80;
    }
    // 004e3b7b  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 004e3b7d  2b7818                 -sub edi, dword ptr [eax + 0x18]
    (cpu.edi) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */)));
L_0x004e3b80:
    // 004e3b80  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004e3b84  8b15a0455600           -mov edx, dword ptr [0x5645a0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5653920) /* 0x5645a0 */);
    // 004e3b8a  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 004e3b8d  8b74020c               -mov esi, dword ptr [edx + eax + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */ + cpu.eax * 1);
    // 004e3b91  c644020201             -mov byte ptr [edx + eax + 2], 1
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(2) /* 0x2 */ + cpu.eax * 1) = 1 /*0x1*/;
    // 004e3b96  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004e3b98  0f848c000000           -je 0x4e3c2a
    if (cpu.flags.zf)
    {
        goto L_0x004e3c2a;
    }
    // 004e3b9e  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 004e3ba2  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004e3ba6  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
L_0x004e3ba9:
    // 004e3ba9  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004e3bad  a1a0455600             -mov eax, dword ptr [0x5645a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653920) /* 0x5645a0 */);
    // 004e3bb2  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004e3bb4  80780200               +cmp byte ptr [eax + 2], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004e3bb8  7470                   -je 0x4e3c2a
    if (cpu.flags.zf)
    {
        goto L_0x004e3c2a;
    }
    // 004e3bba  39fe                   +cmp esi, edi
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
    // 004e3bbc  7602                   -jbe 0x4e3bc0
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004e3bc0;
    }
    // 004e3bbe  89fe                   -mov esi, edi
    cpu.esi = cpu.edi;
L_0x004e3bc0:
    // 004e3bc0  8b5c2414               -mov ebx, dword ptr [esp + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004e3bc4  a1a0455600             -mov eax, dword ptr [0x5645a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653920) /* 0x5645a0 */);
    // 004e3bc9  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004e3bcb  8b5014                 -mov edx, dword ptr [eax + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 004e3bce  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004e3bd0  0f8484000000           -je 0x4e3c5a
    if (cpu.flags.zf)
    {
        goto L_0x004e3c5a;
    }
    // 004e3bd6  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004e3bd9  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004e3bdb  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004e3bdd  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004e3bdf  e80c690000             -call 0x4ea4f0
    cpu.esp -= 4;
    sub_4ea4f0(app, cpu);
    if (cpu.terminate) return;
    // 004e3be4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004e3be6  89742404               -mov dword ptr [esp + 4], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 004e3bea  e8f1bcffff             -call 0x4df8e0
    cpu.esp -= 4;
    sub_4df8e0(app, cpu);
    if (cpu.terminate) return;
L_0x004e3bef:
    // 004e3bef  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004e3bf2  8b15a0455600           -mov edx, dword ptr [0x5645a0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5653920) /* 0x5645a0 */);
    // 004e3bf8  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004e3bfa  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004e3bfe  8b4a18                 -mov ecx, dword ptr [edx + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 004e3c01  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004e3c03  894a18                 -mov dword ptr [edx + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 004e3c06  8b5c2418               -mov ebx, dword ptr [esp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004e3c0a  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004e3c0e  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004e3c10  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 004e3c12  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004e3c14  8b4a1c                 -mov ecx, dword ptr [edx + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */);
    // 004e3c17  895c2418               -mov dword ptr [esp + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 004e3c1b  39c8                   +cmp eax, ecx
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
    // 004e3c1d  7e03                   -jle 0x4e3c22
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004e3c22;
    }
    // 004e3c1f  894a18                 -mov dword ptr [edx + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */) = cpu.ecx;
L_0x004e3c22:
    // 004e3c22  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004e3c26  39de                   +cmp esi, ebx
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e3c28  766d                   -jbe 0x4e3c97
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004e3c97;
    }
L_0x004e3c2a:
    // 004e3c2a  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004e3c2e  8b15a0455600           -mov edx, dword ptr [0x5645a0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5653920) /* 0x5645a0 */);
    // 004e3c34  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 004e3c37  c644020200             -mov byte ptr [edx + eax + 2], 0
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(2) /* 0x2 */ + cpu.eax * 1) = 0 /*0x0*/;
    // 004e3c3c  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004e3c40  8b148560f79e00         -mov edx, dword ptr [eax*4 + 0x9ef760]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10418016) /* 0x9ef760 */ + cpu.eax * 4);
    // 004e3c47  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e3c48  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e3c4e  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004e3c52  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004e3c55  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e3c56  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e3c57  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e3c58  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e3c59  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e3c5a:
    // 004e3c5a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e3c5b  8d542408               -lea edx, [esp + 8]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004e3c5f  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e3c60  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e3c61  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004e3c62  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004e3c65  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e3c66  2eff15b0455300         -call dword ptr cs:[0x5345b0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457328) /* 0x5345b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e3c6d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e3c6f  0f857affffff           -jne 0x4e3bef
    if (!cpu.flags.zf)
    {
        goto L_0x004e3bef;
    }
    // 004e3c75  2eff1534455300         -call dword ptr cs:[0x534534]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457204) /* 0x534534 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e3c7c  3de5030000             +cmp eax, 0x3e5
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(997 /*0x3e5*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e3c81  7518                   -jne 0x4e3c9b
    if (!cpu.flags.zf)
    {
        goto L_0x004e3c9b;
    }
    // 004e3c83  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004e3c88  e853bcffff             -call 0x4df8e0
    cpu.esp -= 4;
    sub_4df8e0(app, cpu);
    if (cpu.terminate) return;
L_0x004e3c8d:
    // 004e3c8d  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004e3c8f  0f8514ffffff           -jne 0x4e3ba9
    if (!cpu.flags.zf)
    {
        goto L_0x004e3ba9;
    }
    // 004e3c95  eb93                   -jmp 0x4e3c2a
    goto L_0x004e3c2a;
L_0x004e3c97:
    // 004e3c97  29df                   +sub edi, ebx
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004e3c99  ebf2                   -jmp 0x4e3c8d
    goto L_0x004e3c8d;
L_0x004e3c9b:
    // 004e3c9b  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004e3ca0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e3ca1  686ca35400             -push 0x54a36c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5546860 /*0x54a36c*/;
    cpu.esp -= 4;
    // 004e3ca6  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004e3ca8  6894455600             -push 0x564594
    app->getMemory<x86::reg32>(cpu.esp-4) = 5653908 /*0x564594*/;
    cpu.esp -= 4;
    // 004e3cad  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004e3caf  e89cd30100             -call 0x501050
    cpu.esp -= 4;
    sub_501050(app, cpu);
    if (cpu.terminate) return;
    // 004e3cb4  83c410                 +add esp, 0x10
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
    // 004e3cb7  895c2418               -mov dword ptr [esp + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 004e3cbb  e96affffff             -jmp 0x4e3c2a
    goto L_0x004e3c2a;
}

/* align: skip  */
void Application::sub_4e3cc0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e3cc0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e3cc1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e3cc2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004e3cc3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004e3cc4  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004e3cc7  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 004e3cc9  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004e3ccb  8b0da0455600           -mov ecx, dword ptr [0x5645a0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5653920) /* 0x5645a0 */);
    // 004e3cd1  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004e3cd3  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004e3cd5  f7d3                   -not ebx
    cpu.ebx = ~cpu.ebx;
    // 004e3cd7  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004e3cdb  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004e3cdd  7419                   -je 0x4e3cf8
    if (cpu.flags.zf)
    {
        goto L_0x004e3cf8;
    }
    // 004e3cdf  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004e3ce1  7c15                   -jl 0x4e3cf8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004e3cf8;
    }
    // 004e3ce3  3b1d9c455600           +cmp ebx, dword ptr [0x56459c]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5653916) /* 0x56459c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e3ce9  7d0d                   -jge 0x4e3cf8
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004e3cf8;
    }
    // 004e3ceb  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004e3ced  c1e605                 -shl esi, 5
    cpu.esi <<= 5 /*0x5*/ % 32;
    // 004e3cf0  8d0431                 -lea eax, [ecx + esi]
    cpu.eax = x86::reg32(cpu.ecx + cpu.esi * 1);
    // 004e3cf3  803800                 +cmp byte ptr [eax], 0
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
    // 004e3cf6  750a                   -jne 0x4e3d02
    if (!cpu.flags.zf)
    {
        goto L_0x004e3d02;
    }
L_0x004e3cf8:
    // 004e3cf8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004e3cfa  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004e3cfd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e3cfe  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e3cff  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e3d00  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e3d01  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e3d02:
    // 004e3d02  8a4001                 -mov al, byte ptr [eax + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004e3d05  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004e3d0a  8b148560f79e00         -mov edx, dword ptr [eax*4 + 0x9ef760]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10418016) /* 0x9ef760 */ + cpu.eax * 4);
    // 004e3d11  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e3d12  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004e3d16  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e3d1c  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004e3d1e  2eff15f4455300         -call dword ptr cs:[0x5345f4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457396) /* 0x5345f4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e3d25  a1a0455600             -mov eax, dword ptr [0x5645a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653920) /* 0x5645a0 */);
    // 004e3d2a  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 004e3d2c  8b5018                 -mov edx, dword ptr [eax + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004e3d2f  8b481c                 -mov ecx, dword ptr [eax + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004e3d32  39ca                   +cmp edx, ecx
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
    // 004e3d34  7e03                   -jle 0x4e3d39
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004e3d39;
    }
    // 004e3d36  894818                 -mov dword ptr [eax + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.ecx;
L_0x004e3d39:
    // 004e3d39  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004e3d3b  a1a0455600             -mov eax, dword ptr [0x5645a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653920) /* 0x5645a0 */);
    // 004e3d40  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 004e3d43  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004e3d45  8b5014                 -mov edx, dword ptr [eax + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 004e3d48  8b700c                 -mov esi, dword ptr [eax + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004e3d4b  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004e3d4d  0f857f000000           -jne 0x4e3dd2
    if (!cpu.flags.zf)
    {
        goto L_0x004e3dd2;
    }
L_0x004e3d53:
    // 004e3d53  c1e305                 -shl ebx, 5
    cpu.ebx <<= 5 /*0x5*/ % 32;
    // 004e3d56  895c240c               -mov dword ptr [esp + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebx;
L_0x004e3d5a:
    // 004e3d5a  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004e3d5c  0f84e0000000           -je 0x4e3e42
    if (cpu.flags.zf)
    {
        goto L_0x004e3e42;
    }
    // 004e3d62  39fe                   +cmp esi, edi
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
    // 004e3d64  7602                   -jbe 0x4e3d68
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004e3d68;
    }
    // 004e3d66  89fe                   -mov esi, edi
    cpu.esi = cpu.edi;
L_0x004e3d68:
    // 004e3d68  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004e3d6c  a1a0455600             -mov eax, dword ptr [0x5645a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653920) /* 0x5645a0 */);
    // 004e3d71  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004e3d73  8b5814                 -mov ebx, dword ptr [eax + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 004e3d76  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004e3d78  7472                   -je 0x4e3dec
    if (cpu.flags.zf)
    {
        goto L_0x004e3dec;
    }
    // 004e3d7a  8b4818                 -mov ecx, dword ptr [eax + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004e3d7d  8d140b                 -lea edx, [ebx + ecx]
    cpu.edx = x86::reg32(cpu.ebx + cpu.ecx * 1);
    // 004e3d80  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004e3d82  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004e3d84  e867670000             -call 0x4ea4f0
    cpu.esp -= 4;
    sub_4ea4f0(app, cpu);
    if (cpu.terminate) return;
    // 004e3d89  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004e3d8b  893424                 -mov dword ptr [esp], esi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.esi;
    // 004e3d8e  e84dbbffff             -call 0x4df8e0
    cpu.esp -= 4;
    sub_4df8e0(app, cpu);
    if (cpu.terminate) return;
L_0x004e3d93:
    // 004e3d93  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004e3d97  8b15a0455600           -mov edx, dword ptr [0x5645a0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5653920) /* 0x5645a0 */);
    // 004e3d9d  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004e3d9f  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004e3da2  014218                 -add dword ptr [edx + 0x18], eax
    (app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */)) += x86::reg32(x86::sreg32(cpu.eax));
    // 004e3da5  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004e3da9  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004e3dac  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004e3dae  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 004e3db0  895c2408               -mov dword ptr [esp + 8], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 004e3db4  39c6                   +cmp esi, eax
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
    // 004e3db6  7668                   -jbe 0x4e3e20
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004e3e20;
    }
    // 004e3db8  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
L_0x004e3dba:
    // 004e3dba  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004e3dbe  a1a0455600             -mov eax, dword ptr [0x5645a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653920) /* 0x5645a0 */);
    // 004e3dc3  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004e3dc5  8b5018                 -mov edx, dword ptr [eax + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004e3dc8  3b501c                 +cmp edx, dword ptr [eax + 0x1c]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e3dcb  7e8d                   -jle 0x4e3d5a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004e3d5a;
    }
    // 004e3dcd  89501c                 -mov dword ptr [eax + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 004e3dd0  eb88                   -jmp 0x4e3d5a
    goto L_0x004e3d5a;
L_0x004e3dd2:
    // 004e3dd2  8b5018                 -mov edx, dword ptr [eax + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004e3dd5  8b481c                 -mov ecx, dword ptr [eax + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004e3dd8  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 004e3dda  39ca                   +cmp edx, ecx
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
    // 004e3ddc  0f8e71ffffff           -jle 0x4e3d53
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004e3d53;
    }
    // 004e3de2  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 004e3de4  2b7818                 +sub edi, dword ptr [eax + 0x18]
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004e3de7  e967ffffff             -jmp 0x4e3d53
    goto L_0x004e3d53;
L_0x004e3dec:
    // 004e3dec  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e3ded  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004e3df1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e3df2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e3df3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004e3df4  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004e3df7  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e3df8  2eff1540465300         -call dword ptr cs:[0x534640]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457472) /* 0x534640 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e3dff  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e3e01  7590                   -jne 0x4e3d93
    if (!cpu.flags.zf)
    {
        goto L_0x004e3d93;
    }
    // 004e3e03  2eff1534455300         -call dword ptr cs:[0x534534]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457204) /* 0x534534 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e3e0a  3de5030000             +cmp eax, 0x3e5
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(997 /*0x3e5*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e3e0f  7513                   -jne 0x4e3e24
    if (!cpu.flags.zf)
    {
        goto L_0x004e3e24;
    }
    // 004e3e11  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004e3e16  e8c5baffff             -call 0x4df8e0
    cpu.esp -= 4;
    sub_4df8e0(app, cpu);
    if (cpu.terminate) return;
    // 004e3e1b  e93affffff             -jmp 0x4e3d5a
    goto L_0x004e3d5a;
L_0x004e3e20:
    // 004e3e20  29c7                   +sub edi, eax
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004e3e22  eb96                   -jmp 0x4e3dba
    goto L_0x004e3dba;
L_0x004e3e24:
    // 004e3e24  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004e3e29  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e3e2a  688ca35400             -push 0x54a38c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5546892 /*0x54a38c*/;
    cpu.esp -= 4;
    // 004e3e2f  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004e3e31  6894455600             -push 0x564594
    app->getMemory<x86::reg32>(cpu.esp-4) = 5653908 /*0x564594*/;
    cpu.esp -= 4;
    // 004e3e36  e815d20100             -call 0x501050
    cpu.esp -= 4;
    sub_501050(app, cpu);
    if (cpu.terminate) return;
    // 004e3e3b  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004e3e3e  895c2408               -mov dword ptr [esp + 8], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
L_0x004e3e42:
    // 004e3e42  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004e3e46  8b1c8560f79e00         -mov ebx, dword ptr [eax*4 + 0x9ef760]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10418016) /* 0x9ef760 */ + cpu.eax * 4);
    // 004e3e4d  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e3e4e  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e3e54  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004e3e58  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004e3e5b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e3e5c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e3e5d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e3e5e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e3e5f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4e3e60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e3e60  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e3e61  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e3e62  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004e3e63  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004e3e64  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004e3e67  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 004e3e69  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004e3e6b  8b15a0455600           -mov edx, dword ptr [0x5645a0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5653920) /* 0x5645a0 */);
    // 004e3e71  f7d3                   -not ebx
    cpu.ebx = ~cpu.ebx;
    // 004e3e73  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004e3e75  7419                   -je 0x4e3e90
    if (cpu.flags.zf)
    {
        goto L_0x004e3e90;
    }
    // 004e3e77  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004e3e79  7c15                   -jl 0x4e3e90
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004e3e90;
    }
    // 004e3e7b  3b1d9c455600           +cmp ebx, dword ptr [0x56459c]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5653916) /* 0x56459c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e3e81  7d0d                   -jge 0x4e3e90
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004e3e90;
    }
    // 004e3e83  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004e3e85  c1e605                 -shl esi, 5
    cpu.esi <<= 5 /*0x5*/ % 32;
    // 004e3e88  8d3c32                 -lea edi, [edx + esi]
    cpu.edi = x86::reg32(cpu.edx + cpu.esi * 1);
    // 004e3e8b  803f00                 +cmp byte ptr [edi], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edi);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004e3e8e  750a                   -jne 0x4e3e9a
    if (!cpu.flags.zf)
    {
        goto L_0x004e3e9a;
    }
L_0x004e3e90:
    // 004e3e90  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004e3e92  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004e3e95  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e3e96  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e3e97  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e3e98  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e3e99  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e3e9a:
    // 004e3e9a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e3e9b  0fb67f01               -movzx edi, byte ptr [edi + 1]
    cpu.edi = x86::reg32(app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */));
    // 004e3e9f  8b04bd60f79e00         -mov eax, dword ptr [edi*4 + 0x9ef760]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10418016) /* 0x9ef760 */ + cpu.edi * 4);
    // 004e3ea6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e3ea7  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e3ead  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004e3eaf  2eff15f4455300         -call dword ptr cs:[0x5345f4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457396) /* 0x5345f4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e3eb6  a1a0455600             -mov eax, dword ptr [0x5645a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653920) /* 0x5645a0 */);
    // 004e3ebb  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 004e3ebd  89ee                   -mov esi, ebp
    cpu.esi = cpu.ebp;
    // 004e3ebf  8b501c                 -mov edx, dword ptr [eax + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004e3ec2  896818                 -mov dword ptr [eax + 0x18], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.ebp;
    // 004e3ec5  39d6                   +cmp esi, edx
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e3ec7  7e53                   -jle 0x4e3f1c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004e3f1c;
    }
    // 004e3ec9  895018                 -mov dword ptr [eax + 0x18], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.edx;
L_0x004e3ecc:
    // 004e3ecc  a1a0455600             -mov eax, dword ptr [0x5645a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653920) /* 0x5645a0 */);
    // 004e3ed1  c1e305                 -shl ebx, 5
    cpu.ebx <<= 5 /*0x5*/ % 32;
    // 004e3ed4  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004e3ed6  8b7014                 -mov esi, dword ptr [eax + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 004e3ed9  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004e3edb  7524                   -jne 0x4e3f01
    if (!cpu.flags.zf)
    {
        goto L_0x004e3f01;
    }
    // 004e3edd  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e3ede  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e3edf  8b6818                 -mov ebp, dword ptr [eax + 0x18]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004e3ee2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004e3ee3  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004e3ee6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e3ee7  2eff15f0455300         -call dword ptr cs:[0x5345f0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457392) /* 0x5345f0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e3eee  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 004e3ef3  8b35a0455600           -mov esi, dword ptr [0x5645a0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5653920) /* 0x5645a0 */);
    // 004e3ef9  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 004e3efd  89441e18               -mov dword ptr [esi + ebx + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */ + cpu.ebx * 1) = cpu.eax;
L_0x004e3f01:
    // 004e3f01  8b1cbd60f79e00         -mov ebx, dword ptr [edi*4 + 0x9ef760]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10418016) /* 0x9ef760 */ + cpu.edi * 4);
    // 004e3f08  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e3f09  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e3f0f  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004e3f13  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e3f14  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004e3f17  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e3f18  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e3f19  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e3f1a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e3f1b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e3f1c:
    // 004e3f1c  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004e3f1e  7dac                   -jge 0x4e3ecc
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004e3ecc;
    }
    // 004e3f20  c7401800000000         -mov dword ptr [eax + 0x18], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 004e3f27  eba3                   -jmp 0x4e3ecc
    goto L_0x004e3ecc;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4e3f30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e3f30  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e3f31  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e3f32  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e3f33  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004e3f34  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004e3f36  8b15a0455600           -mov edx, dword ptr [0x5645a0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5653920) /* 0x5645a0 */);
    // 004e3f3c  f7d6                   -not esi
    cpu.esi = ~cpu.esi;
    // 004e3f3e  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004e3f40  7419                   -je 0x4e3f5b
    if (cpu.flags.zf)
    {
        goto L_0x004e3f5b;
    }
    // 004e3f42  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004e3f44  7c15                   -jl 0x4e3f5b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004e3f5b;
    }
    // 004e3f46  3b359c455600           +cmp esi, dword ptr [0x56459c]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5653916) /* 0x56459c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e3f4c  7d0d                   -jge 0x4e3f5b
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004e3f5b;
    }
    // 004e3f4e  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004e3f50  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004e3f52  c1e305                 -shl ebx, 5
    cpu.ebx <<= 5 /*0x5*/ % 32;
    // 004e3f55  803c0300               +cmp byte ptr [ebx + eax], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebx + cpu.eax * 1);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004e3f59  7507                   -jne 0x4e3f62
    if (!cpu.flags.zf)
    {
        goto L_0x004e3f62;
    }
L_0x004e3f5b:
    // 004e3f5b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004e3f5d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e3f5e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e3f5f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e3f60  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e3f61  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e3f62:
    // 004e3f62  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004e3f63  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e3f64  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004e3f66  2eff15f4455300         -call dword ptr cs:[0x5345f4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457396) /* 0x5345f4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e3f6d  a1a0455600             -mov eax, dword ptr [0x5645a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653920) /* 0x5645a0 */);
    // 004e3f72  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004e3f74  8b7814                 -mov edi, dword ptr [eax + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 004e3f77  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004e3f79  7548                   -jne 0x4e3fc3
    if (!cpu.flags.zf)
    {
        goto L_0x004e3fc3;
    }
    // 004e3f7b  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004e3f7d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004e3f7e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004e3f7f  8b6804                 -mov ebp, dword ptr [eax + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004e3f82  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004e3f83  2eff15f0455300         -call dword ptr cs:[0x5345f0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457392) /* 0x5345f0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e3f8a  8b15a0455600           -mov edx, dword ptr [0x5645a0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5653920) /* 0x5645a0 */);
    // 004e3f90  89441a18               -mov dword ptr [edx + ebx + 0x18], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */ + cpu.ebx * 1) = cpu.eax;
    // 004e3f94  83f8ff                 +cmp eax, -1
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
    // 004e3f97  752a                   -jne 0x4e3fc3
    if (!cpu.flags.zf)
    {
        goto L_0x004e3fc3;
    }
    // 004e3f99  2eff1534455300         -call dword ptr cs:[0x534534]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457204) /* 0x534534 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e3fa0  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004e3fa5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004e3fa6  68aca35400             -push 0x54a3ac
    app->getMemory<x86::reg32>(cpu.esp-4) = 5546924 /*0x54a3ac*/;
    cpu.esp -= 4;
    // 004e3fab  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004e3fad  6894455600             -push 0x564594
    app->getMemory<x86::reg32>(cpu.esp-4) = 5653908 /*0x564594*/;
    cpu.esp -= 4;
    // 004e3fb2  e899d00100             -call 0x501050
    cpu.esp -= 4;
    sub_501050(app, cpu);
    if (cpu.terminate) return;
    // 004e3fb7  a1a0455600             -mov eax, dword ptr [0x5645a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653920) /* 0x5645a0 */);
    // 004e3fbc  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004e3fbf  897c0318               -mov dword ptr [ebx + eax + 0x18], edi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */ + cpu.eax * 1) = cpu.edi;
L_0x004e3fc3:
    // 004e3fc3  a1a0455600             -mov eax, dword ptr [0x5645a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653920) /* 0x5645a0 */);
    // 004e3fc8  c1e605                 -shl esi, 5
    cpu.esi <<= 5 /*0x5*/ % 32;
    // 004e3fcb  8b440618               -mov eax, dword ptr [esi + eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */ + cpu.eax * 1);
    // 004e3fcf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e3fd0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e3fd1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e3fd2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e3fd3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e3fd4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e3fd5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void Application::sub_4e3fe0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e3fe0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e3fe1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e3fe2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e3fe3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004e3fe4  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004e3fe6  8b15a0455600           -mov edx, dword ptr [0x5645a0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5653920) /* 0x5645a0 */);
    // 004e3fec  f7d3                   -not ebx
    cpu.ebx = ~cpu.ebx;
    // 004e3fee  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004e3ff0  7419                   -je 0x4e400b
    if (cpu.flags.zf)
    {
        goto L_0x004e400b;
    }
    // 004e3ff2  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004e3ff4  7c15                   -jl 0x4e400b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004e400b;
    }
    // 004e3ff6  3b1d9c455600           +cmp ebx, dword ptr [0x56459c]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5653916) /* 0x56459c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e3ffc  7d0d                   -jge 0x4e400b
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004e400b;
    }
    // 004e3ffe  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004e4000  c1e605                 -shl esi, 5
    cpu.esi <<= 5 /*0x5*/ % 32;
    // 004e4003  8d0432                 -lea eax, [edx + esi]
    cpu.eax = x86::reg32(cpu.edx + cpu.esi * 1);
    // 004e4006  803800                 +cmp byte ptr [eax], 0
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
    // 004e4009  7507                   -jne 0x4e4012
    if (!cpu.flags.zf)
    {
        goto L_0x004e4012;
    }
L_0x004e400b:
    // 004e400b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004e400d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e400e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e400f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e4010  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e4011  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e4012:
    // 004e4012  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004e4013  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e4014  0fb67801               -movzx edi, byte ptr [eax + 1]
    cpu.edi = x86::reg32(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */));
    // 004e4018  8b2cbd60f79e00         -mov ebp, dword ptr [edi*4 + 0x9ef760]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(10418016) /* 0x9ef760 */ + cpu.edi * 4);
    // 004e401f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004e4020  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e4026  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004e4028  2eff15f4455300         -call dword ptr cs:[0x5345f4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457396) /* 0x5345f4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e402f  a1a0455600             -mov eax, dword ptr [0x5645a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653920) /* 0x5645a0 */);
    // 004e4034  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 004e4036  837810ff               +cmp dword ptr [eax + 0x10], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e403a  741c                   -je 0x4e4058
    if (cpu.flags.zf)
    {
        goto L_0x004e4058;
    }
    // 004e403c  8b4814                 -mov ecx, dword ptr [eax + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 004e403f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e4040  2eff1520465300         -call dword ptr cs:[0x534620]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457440) /* 0x534620 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e4047  a1a0455600             -mov eax, dword ptr [0x5645a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653920) /* 0x5645a0 */);
    // 004e404c  8b6c0610               -mov ebp, dword ptr [esi + eax + 0x10]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */ + cpu.eax * 1);
    // 004e4050  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004e4051  2eff1588445300         -call dword ptr cs:[0x534488]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457032) /* 0x534488 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004e4058:
    // 004e4058  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004e405a  a1a0455600             -mov eax, dword ptr [0x5645a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653920) /* 0x5645a0 */);
    // 004e405f  c1e605                 -shl esi, 5
    cpu.esi <<= 5 /*0x5*/ % 32;
    // 004e4062  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 004e4064  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004e4067  83faff                 +cmp edx, -1
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
    // 004e406a  7408                   -je 0x4e4074
    if (cpu.flags.zf)
    {
        goto L_0x004e4074;
    }
    // 004e406c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e406d  2eff1588445300         -call dword ptr cs:[0x534488]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457032) /* 0x534488 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004e4074:
    // 004e4074  8b34bd60f79e00         -mov esi, dword ptr [edi*4 + 0x9ef760]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(10418016) /* 0x9ef760 */ + cpu.edi * 4);
    // 004e407b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004e407c  c1e305                 -shl ebx, 5
    cpu.ebx <<= 5 /*0x5*/ % 32;
    // 004e407f  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e4085  a1a0455600             -mov eax, dword ptr [0x5645a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653920) /* 0x5645a0 */);
    // 004e408a  c6040300               -mov byte ptr [ebx + eax], 0
    app->getMemory<x86::reg8>(cpu.ebx + cpu.eax * 1) = 0 /*0x0*/;
    // 004e408e  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004e4093  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e4094  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e4095  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e4096  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e4097  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e4098  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e4099  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_4e40a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004e40a0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004e40a1  8b15a0455600           -mov edx, dword ptr [0x5645a0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5653920) /* 0x5645a0 */);
    // 004e40a7  f7d0                   -not eax
    cpu.eax = ~cpu.eax;
    // 004e40a9  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004e40ab  7416                   -je 0x4e40c3
    if (cpu.flags.zf)
    {
        goto L_0x004e40c3;
    }
    // 004e40ad  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004e40af  7c12                   -jl 0x4e40c3
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004e40c3;
    }
    // 004e40b1  3b059c455600           +cmp eax, dword ptr [0x56459c]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5653916) /* 0x56459c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004e40b7  7d0a                   -jge 0x4e40c3
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004e40c3;
    }
    // 004e40b9  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 004e40bc  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004e40be  803800                 +cmp byte ptr [eax], 0
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
    // 004e40c1  7504                   -jne 0x4e40c7
    if (!cpu.flags.zf)
    {
        goto L_0x004e40c7;
    }
L_0x004e40c3:
    // 004e40c3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004e40c5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e40c6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004e40c7:
    // 004e40c7  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004e40c8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e40c9  8a4001                 -mov al, byte ptr [eax + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004e40cc  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004e40d1  8b1c8560f79e00         -mov ebx, dword ptr [eax*4 + 0x9ef760]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10418016) /* 0x9ef760 */ + cpu.eax * 4);
    // 004e40d8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004e40d9  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004e40df  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004e40e4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e40e5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e40e6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004e40e7  c3                     -ret 
    cpu.esp += 4;
    return;
}

}
