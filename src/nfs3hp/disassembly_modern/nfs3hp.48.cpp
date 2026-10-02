#include "nfs3hp.h"
#include <lib/thread.h>

namespace nfs3hp
{

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_50d510(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050d510  83f830                 +cmp eax, 0x30
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(48 /*0x30*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050d513  7c09                   -jl 0x50d51e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0050d51e;
    }
    // 0050d515  83f839                 +cmp eax, 0x39
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
    // 0050d518  7f04                   -jg 0x50d51e
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0050d51e;
    }
    // 0050d51a  83e830                 -sub eax, 0x30
    (cpu.eax) -= x86::reg32(x86::sreg32(48 /*0x30*/));
    // 0050d51d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050d51e:
    // 0050d51e  e8bd35feff             -call 0x4f0ae0
    cpu.esp -= 4;
    sub_4f0ae0(app, cpu);
    if (cpu.terminate) return;
    // 0050d523  83f861                 +cmp eax, 0x61
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
    // 0050d526  7c09                   -jl 0x50d531
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0050d531;
    }
    // 0050d528  83f866                 +cmp eax, 0x66
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(102 /*0x66*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050d52b  7f04                   -jg 0x50d531
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0050d531;
    }
    // 0050d52d  83e857                 -sub eax, 0x57
    (cpu.eax) -= x86::reg32(x86::sreg32(87 /*0x57*/));
    // 0050d530  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050d531:
    // 0050d531  b810000000             -mov eax, 0x10
    cpu.eax = 16 /*0x10*/;
    // 0050d536  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_50d538(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050d538  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0050d539  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0050d53a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0050d53c  8b400c                 -mov eax, dword ptr [eax + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0050d53f  8d58ff                 -lea ebx, [eax - 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(-1) /* -0x1 */);
    // 0050d542  895a0c                 -mov dword ptr [edx + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 0050d545  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0050d547  740d                   -je 0x50d556
    if (cpu.flags.zf)
    {
        goto L_0x0050d556;
    }
    // 0050d549  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0050d54b  e8f0f0ffff             -call 0x50c640
    cpu.esp -= 4;
    sub_50c640(app, cpu);
    if (cpu.terminate) return;
    // 0050d550  f6421002               +test byte ptr [edx + 0x10], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */) & 2 /*0x2*/));
    // 0050d554  7405                   -je 0x50d55b
    if (cpu.flags.zf)
    {
        goto L_0x0050d55b;
    }
L_0x0050d556:
    // 0050d556  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
L_0x0050d55b:
    // 0050d55b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050d55c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050d55d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_50d560(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050d560  92                     -xchg edx, eax
    {
        x86::reg32 tmp = cpu.edx;
        cpu.edx = cpu.eax;
        cpu.eax = tmp;
    }
    // 0050d561  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050d562  a907000000             +test eax, 7
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 7 /*0x7*/));
    // 0050d567  0f8504010000           -jne 0x50d671
    if (!cpu.flags.zf)
    {
        goto L_0x0050d671;
    }
L_0x0050d56d:
    // 0050d56d  81eb80000000           +sub ebx, 0x80
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(128 /*0x80*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0050d573  787d                   -js 0x50d5f2
    if (cpu.flags.sf)
    {
        goto L_0x0050d5f2;
    }
L_0x0050d575:
    // 0050d575  dd02                   -fld qword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.edx)));
    // 0050d577  dd4220                 -fld qword ptr [edx + 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.edx + x86::reg32(32) /* 0x20 */)));
    // 0050d57a  dd4240                 -fld qword ptr [edx + 0x40]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.edx + x86::reg32(64) /* 0x40 */)));
    // 0050d57d  dd4260                 -fld qword ptr [edx + 0x60]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.edx + x86::reg32(96) /* 0x60 */)));
    // 0050d580  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 0050d582  dd4210                 -fld qword ptr [edx + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.edx + x86::reg32(16) /* 0x10 */)));
    // 0050d585  dd4208                 -fld qword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 0050d588  dd4218                 -fld qword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 0050d58b  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 0050d58d  dd18                   -fstp qword ptr [eax]
    app->getMemory<double>(cpu.eax) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0050d58f  dd5808                 -fstp qword ptr [eax + 8]
    app->getMemory<double>(cpu.eax + x86::reg32(8) /* 0x8 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0050d592  dd5810                 -fstp qword ptr [eax + 0x10]
    app->getMemory<double>(cpu.eax + x86::reg32(16) /* 0x10 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0050d595  dd5818                 -fstp qword ptr [eax + 0x18]
    app->getMemory<double>(cpu.eax + x86::reg32(24) /* 0x18 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0050d598  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0050d59a  dd4230                 -fld qword ptr [edx + 0x30]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.edx + x86::reg32(48) /* 0x30 */)));
    // 0050d59d  dd4228                 -fld qword ptr [edx + 0x28]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.edx + x86::reg32(40) /* 0x28 */)));
    // 0050d5a0  dd4238                 -fld qword ptr [edx + 0x38]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.edx + x86::reg32(56) /* 0x38 */)));
    // 0050d5a3  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 0050d5a5  dd5820                 -fstp qword ptr [eax + 0x20]
    app->getMemory<double>(cpu.eax + x86::reg32(32) /* 0x20 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0050d5a8  dd5828                 -fstp qword ptr [eax + 0x28]
    app->getMemory<double>(cpu.eax + x86::reg32(40) /* 0x28 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0050d5ab  dd5830                 -fstp qword ptr [eax + 0x30]
    app->getMemory<double>(cpu.eax + x86::reg32(48) /* 0x30 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0050d5ae  dd5838                 -fstp qword ptr [eax + 0x38]
    app->getMemory<double>(cpu.eax + x86::reg32(56) /* 0x38 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0050d5b1  dd4250                 -fld qword ptr [edx + 0x50]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.edx + x86::reg32(80) /* 0x50 */)));
    // 0050d5b4  dd4248                 -fld qword ptr [edx + 0x48]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.edx + x86::reg32(72) /* 0x48 */)));
    // 0050d5b7  dd4258                 -fld qword ptr [edx + 0x58]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.edx + x86::reg32(88) /* 0x58 */)));
    // 0050d5ba  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 0050d5bc  dd5840                 -fstp qword ptr [eax + 0x40]
    app->getMemory<double>(cpu.eax + x86::reg32(64) /* 0x40 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0050d5bf  dd5848                 -fstp qword ptr [eax + 0x48]
    app->getMemory<double>(cpu.eax + x86::reg32(72) /* 0x48 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0050d5c2  dd5850                 -fstp qword ptr [eax + 0x50]
    app->getMemory<double>(cpu.eax + x86::reg32(80) /* 0x50 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0050d5c5  dd5858                 -fstp qword ptr [eax + 0x58]
    app->getMemory<double>(cpu.eax + x86::reg32(88) /* 0x58 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0050d5c8  dd4270                 -fld qword ptr [edx + 0x70]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.edx + x86::reg32(112) /* 0x70 */)));
    // 0050d5cb  dd4268                 -fld qword ptr [edx + 0x68]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.edx + x86::reg32(104) /* 0x68 */)));
    // 0050d5ce  dd4278                 -fld qword ptr [edx + 0x78]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.edx + x86::reg32(120) /* 0x78 */)));
    // 0050d5d1  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 0050d5d3  dd5860                 -fstp qword ptr [eax + 0x60]
    app->getMemory<double>(cpu.eax + x86::reg32(96) /* 0x60 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0050d5d6  dd5868                 -fstp qword ptr [eax + 0x68]
    app->getMemory<double>(cpu.eax + x86::reg32(104) /* 0x68 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0050d5d9  dd5870                 -fstp qword ptr [eax + 0x70]
    app->getMemory<double>(cpu.eax + x86::reg32(112) /* 0x70 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0050d5dc  dd5878                 -fstp qword ptr [eax + 0x78]
    app->getMemory<double>(cpu.eax + x86::reg32(120) /* 0x78 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0050d5df  81c280000000           -add edx, 0x80
    (cpu.edx) += x86::reg32(x86::sreg32(128 /*0x80*/));
    // 0050d5e5  0580000000             -add eax, 0x80
    (cpu.eax) += x86::reg32(x86::sreg32(128 /*0x80*/));
    // 0050d5ea  81eb80000000           +sub ebx, 0x80
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(128 /*0x80*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0050d5f0  7983                   -jns 0x50d575
    if (!cpu.flags.sf)
    {
        goto L_0x0050d575;
    }
L_0x0050d5f2:
    // 0050d5f2  83c360                 +add ebx, 0x60
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(96 /*0x60*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0050d5f5  7825                   -js 0x50d61c
    if (cpu.flags.sf)
    {
        goto L_0x0050d61c;
    }
L_0x0050d5f7:
    // 0050d5f7  dd02                   -fld qword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.edx)));
    // 0050d5f9  dd4208                 -fld qword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 0050d5fc  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0050d5fe  dd18                   -fstp qword ptr [eax]
    app->getMemory<double>(cpu.eax) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0050d600  dd5808                 -fstp qword ptr [eax + 8]
    app->getMemory<double>(cpu.eax + x86::reg32(8) /* 0x8 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0050d603  dd4210                 -fld qword ptr [edx + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.edx + x86::reg32(16) /* 0x10 */)));
    // 0050d606  dd4218                 -fld qword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.edx + x86::reg32(24) /* 0x18 */)));
    // 0050d609  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0050d60b  dd5810                 -fstp qword ptr [eax + 0x10]
    app->getMemory<double>(cpu.eax + x86::reg32(16) /* 0x10 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0050d60e  dd5818                 -fstp qword ptr [eax + 0x18]
    app->getMemory<double>(cpu.eax + x86::reg32(24) /* 0x18 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0050d611  83c220                 -add edx, 0x20
    (cpu.edx) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0050d614  83c020                 -add eax, 0x20
    (cpu.eax) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0050d617  83eb20                 +sub ebx, 0x20
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0050d61a  79db                   -jns 0x50d5f7
    if (!cpu.flags.sf)
    {
        goto L_0x0050d5f7;
    }
L_0x0050d61c:
    // 0050d61c  83c318                 +add ebx, 0x18
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(24 /*0x18*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0050d61f  780f                   -js 0x50d630
    if (cpu.flags.sf)
    {
        goto L_0x0050d630;
    }
L_0x0050d621:
    // 0050d621  dd02                   -fld qword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.edx)));
    // 0050d623  dd18                   -fstp qword ptr [eax]
    app->getMemory<double>(cpu.eax) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0050d625  83c208                 -add edx, 8
    (cpu.edx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0050d628  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0050d62b  83eb08                 +sub ebx, 8
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0050d62e  79f1                   -jns 0x50d621
    if (!cpu.flags.sf)
    {
        goto L_0x0050d621;
    }
L_0x0050d630:
    // 0050d630  83c308                 +add ebx, 8
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0050d633  7502                   -jne 0x50d637
    if (!cpu.flags.zf)
    {
        goto L_0x0050d637;
    }
    // 0050d635  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050d636  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050d637:
    // 0050d637  83fb04                 +cmp ebx, 4
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
    // 0050d63a  720d                   -jb 0x50d649
    if (cpu.flags.cf)
    {
        goto L_0x0050d649;
    }
    // 0050d63c  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 0050d63e  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0050d641  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 0050d643  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0050d646  83eb04                 -sub ebx, 4
    (cpu.ebx) -= x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0050d649:
    // 0050d649  83fb02                 +cmp ebx, 2
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
    // 0050d64c  720f                   -jb 0x50d65d
    if (cpu.flags.cf)
    {
        goto L_0x0050d65d;
    }
    // 0050d64e  668b0a                 -mov cx, word ptr [edx]
    cpu.cx = app->getMemory<x86::reg16>(cpu.edx);
    // 0050d651  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0050d654  668908                 -mov word ptr [eax], cx
    app->getMemory<x86::reg16>(cpu.eax) = cpu.cx;
    // 0050d657  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0050d65a  83eb02                 -sub ebx, 2
    (cpu.ebx) -= x86::reg32(x86::sreg32(2 /*0x2*/));
L_0x0050d65d:
    // 0050d65d  83fb01                 +cmp ebx, 1
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
    // 0050d660  720d                   -jb 0x50d66f
    if (cpu.flags.cf)
    {
        goto L_0x0050d66f;
    }
    // 0050d662  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 0050d664  83c201                 -add edx, 1
    (cpu.edx) += x86::reg32(x86::sreg32(1 /*0x1*/));
    // 0050d667  8808                   -mov byte ptr [eax], cl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.cl;
    // 0050d669  83c001                 -add eax, 1
    (cpu.eax) += x86::reg32(x86::sreg32(1 /*0x1*/));
    // 0050d66c  83eb01                 -sub ebx, 1
    (cpu.ebx) -= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x0050d66f:
    // 0050d66f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050d670  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050d671:
    // 0050d671  a901000000             +test eax, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 1 /*0x1*/));
    // 0050d676  7412                   -je 0x50d68a
    if (cpu.flags.zf)
    {
        goto L_0x0050d68a;
    }
    // 0050d678  83fb01                 +cmp ebx, 1
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
    // 0050d67b  7c0d                   -jl 0x50d68a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0050d68a;
    }
    // 0050d67d  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 0050d67f  83c201                 -add edx, 1
    (cpu.edx) += x86::reg32(x86::sreg32(1 /*0x1*/));
    // 0050d682  8808                   -mov byte ptr [eax], cl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.cl;
    // 0050d684  83c001                 -add eax, 1
    (cpu.eax) += x86::reg32(x86::sreg32(1 /*0x1*/));
    // 0050d687  83eb01                 -sub ebx, 1
    (cpu.ebx) -= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x0050d68a:
    // 0050d68a  a902000000             +test eax, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2 /*0x2*/));
    // 0050d68f  7414                   -je 0x50d6a5
    if (cpu.flags.zf)
    {
        goto L_0x0050d6a5;
    }
    // 0050d691  83fb02                 +cmp ebx, 2
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
    // 0050d694  7c0f                   -jl 0x50d6a5
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0050d6a5;
    }
    // 0050d696  668b0a                 -mov cx, word ptr [edx]
    cpu.cx = app->getMemory<x86::reg16>(cpu.edx);
    // 0050d699  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0050d69c  668908                 -mov word ptr [eax], cx
    app->getMemory<x86::reg16>(cpu.eax) = cpu.cx;
    // 0050d69f  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0050d6a2  83eb02                 -sub ebx, 2
    (cpu.ebx) -= x86::reg32(x86::sreg32(2 /*0x2*/));
L_0x0050d6a5:
    // 0050d6a5  a904000000             +test eax, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 4 /*0x4*/));
    // 0050d6aa  7412                   -je 0x50d6be
    if (cpu.flags.zf)
    {
        goto L_0x0050d6be;
    }
    // 0050d6ac  83fb04                 +cmp ebx, 4
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
    // 0050d6af  7c0d                   -jl 0x50d6be
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0050d6be;
    }
    // 0050d6b1  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 0050d6b3  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0050d6b6  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 0050d6b8  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0050d6bb  83eb04                 +sub ebx, 4
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
L_0x0050d6be:
    // 0050d6be  e9aafeffff             -jmp 0x50d56d
    goto L_0x0050d56d;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_50d6d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050d6d0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_50d6e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050d6e0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050d6e1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050d6e2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050d6e3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0050d6e4  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0050d6e7  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0050d6e9  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0050d6eb  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
L_0x0050d6ed:
    // 0050d6ed  80790300               +cmp byte ptr [ecx + 3], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(3) /* 0x3 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0050d6f1  750f                   -jne 0x50d702
    if (!cpu.flags.zf)
    {
        goto L_0x0050d702;
    }
    // 0050d6f3  46                     -inc esi
    (cpu.esi)++;
    // 0050d6f4  83c104                 +add ecx, 4
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0050d6f7  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0050d6f8  75f3                   -jne 0x50d6ed
    if (!cpu.flags.zf)
    {
        goto L_0x0050d6ed;
    }
    // 0050d6fa  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0050d6fd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050d6fe  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050d6ff  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050d700  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050d701  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050d702:
    // 0050d702  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0050d704  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0050d709  e892ecffff             -call 0x50c3a0
    cpu.esp -= 4;
    sub_50c3a0(app, cpu);
    if (cpu.terminate) return;
    // 0050d70e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0050d710  a9000000ff             +test eax, 0xff000000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 4278190080 /*0xff000000*/));
    // 0050d715  0f84a8000000           -je 0x50d7c3
    if (cpu.flags.zf)
    {
        goto L_0x0050d7c3;
    }
    // 0050d71b  b6ff                   -mov dh, 0xff
    cpu.dh = 255 /*0xff*/;
    // 0050d71d  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0050d71f  8a5903                 -mov bl, byte ptr [ecx + 3]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(3) /* 0x3 */);
    // 0050d722  c1ed10                 -shr ebp, 0x10
    cpu.ebp >>= 16 /*0x10*/ % 32;
    // 0050d725  c1e808                 -shr eax, 8
    cpu.eax >>= 8 /*0x8*/ % 32;
    // 0050d728  28de                   -sub dh, bl
    (cpu.dh) -= x86::reg8(x86::sreg8(cpu.bl));
    // 0050d72a  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0050d72f  8a5902                 -mov bl, byte ptr [ecx + 2]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(2) /* 0x2 */);
    // 0050d732  81e5ff000000           -and ebp, 0xff
    cpu.ebp &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0050d738  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0050d73b  8a39                   -mov bh, byte ptr [ecx]
    cpu.bh = app->getMemory<x86::reg8>(cpu.ecx);
    // 0050d73d  8a0424                 -mov al, byte ptr [esp]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp);
    // 0050d740  892c24                 -mov dword ptr [esp], ebp
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebp;
    // 0050d743  887c240c               -mov byte ptr [esp + 0xc], bh
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.bh;
    // 0050d747  8a3c24                 -mov bh, byte ptr [esp]
    cpu.bh = app->getMemory<x86::reg8>(cpu.esp);
    // 0050d74a  88442410               -mov byte ptr [esp + 0x10], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.al;
    // 0050d74e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0050d750  88f8                   -mov al, bh
    cpu.al = cpu.bh;
    // 0050d752  88742404               -mov byte ptr [esp + 4], dh
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.dh;
    // 0050d756  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0050d759  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0050d75b  8b2c24                 -mov ebp, dword ptr [esp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    // 0050d75e  8a442404               -mov al, byte ptr [esp + 4]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0050d762  0fafe8                 -imul ebp, eax
    cpu.ebp = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebp)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 0050d765  8a7101                 -mov dh, byte ptr [ecx + 1]
    cpu.dh = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 0050d768  c1fd08                 -sar ebp, 8
    cpu.ebp = x86::reg32(x86::sreg32(cpu.ebp) >> (8 /*0x8*/ % 32));
    // 0050d76b  88542408               -mov byte ptr [esp + 8], dl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.dl;
    // 0050d76f  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0050d775  01eb                   -add ebx, ebp
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0050d777  0fb66c2410             -movzx ebp, byte ptr [esp + 0x10]
    cpu.ebp = x86::reg32(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */));
    // 0050d77c  0fafe8                 -imul ebp, eax
    cpu.ebp = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebp)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 0050d77f  c1fd08                 -sar ebp, 8
    cpu.ebp = x86::reg32(x86::sreg32(cpu.ebp) >> (8 /*0x8*/ % 32));
    // 0050d782  88f2                   -mov dl, dh
    cpu.dl = cpu.dh;
    // 0050d784  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0050d78a  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0050d78c  0fb66c2408             -movzx ebp, byte ptr [esp + 8]
    cpu.ebp = x86::reg32(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */));
    // 0050d791  0fafc5                 -imul eax, ebp
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebp)));
    // 0050d794  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 0050d797  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0050d79a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0050d79c  8b2c24                 -mov ebp, dword ptr [esp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    // 0050d79f  8a44240c               -mov al, byte ptr [esp + 0xc]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0050d7a3  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0050d7a5  8844240c               -mov byte ptr [esp + 0xc], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.al;
    // 0050d7a9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0050d7ab  88d8                   -mov al, bl
    cpu.al = cpu.bl;
    // 0050d7ad  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0050d7af  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0050d7b1  c1e310                 -shl ebx, 0x10
    cpu.ebx <<= 16 /*0x10*/ % 32;
    // 0050d7b4  88d0                   -mov al, dl
    cpu.al = cpu.dl;
    // 0050d7b6  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0050d7b8  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 0050d7bb  8a54240c               -mov dl, byte ptr [esp + 0xc]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0050d7bf  09d8                   -or eax, ebx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ebx));
    // 0050d7c1  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
L_0x0050d7c3:
    // 0050d7c3  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0050d7c5  e8961ffeff             -call 0x4ef760
    cpu.esp -= 4;
    sub_4ef760(app, cpu);
    if (cpu.terminate) return;
    // 0050d7ca  8806                   -mov byte ptr [esi], al
    app->getMemory<x86::reg8>(cpu.esi) = cpu.al;
    // 0050d7cc  46                     -inc esi
    (cpu.esi)++;
    // 0050d7cd  83c104                 +add ecx, 4
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0050d7d0  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0050d7d1  0f8516ffffff           -jne 0x50d6ed
    if (!cpu.flags.zf)
    {
        goto L_0x0050d6ed;
    }
    // 0050d7d7  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0050d7da  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050d7db  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050d7dc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050d7dd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050d7de  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_50d7e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050d7e0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050d7e1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050d7e2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050d7e3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0050d7e4  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0050d7e6  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0050d7e8  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
L_0x0050d7ea:
    // 0050d7ea  8b1f                   -mov ebx, dword ptr [edi]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi);
    // 0050d7ec  81fb00000010           +cmp ebx, 0x10000000
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(268435456 /*0x10000000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050d7f2  7273                   -jb 0x50d867
    if (cpu.flags.cf)
    {
        goto L_0x0050d867;
    }
    // 0050d7f4  81fb000000fc           +cmp ebx, 0xfc000000
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4227858432 /*0xfc000000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050d7fa  7348                   -jae 0x50d844
    if (!cpu.flags.cf)
    {
        goto L_0x0050d844;
    }
    // 0050d7fc  668b06                 -mov ax, word ptr [esi]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi);
    // 0050d7ff  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0050d801  25007c0000             -and eax, 0x7c00
    cpu.eax &= x86::reg32(x86::sreg32(31744 /*0x7c00*/));
    // 0050d806  c1e011                 -shl eax, 0x11
    cpu.eax <<= 17 /*0x11*/ % 32;
    // 0050d809  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0050d80b  81e2e0030000           -and edx, 0x3e0
    cpu.edx &= x86::reg32(x86::sreg32(992 /*0x3e0*/));
    // 0050d811  c1e209                 -shl edx, 9
    cpu.edx <<= 9 /*0x9*/ % 32;
    // 0050d814  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0050d816  83e11f                 -and ecx, 0x1f
    cpu.ecx &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 0050d819  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0050d81b  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0050d81d  c1e918                 -shr ecx, 0x18
    cpu.ecx >>= 24 /*0x18*/ % 32;
    // 0050d820  81f1ff000000           -xor ecx, 0xff
    cpu.ecx ^= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0050d826  f7e1                   -mul ecx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.ecx);
    // 0050d828  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0050d82b  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0050d82d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0050d82f  c1ea05                 -shr edx, 5
    cpu.edx >>= 5 /*0x5*/ % 32;
    // 0050d832  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0050d838  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0050d83a  c1e80b                 -shr eax, 0xb
    cpu.eax >>= 11 /*0xb*/ % 32;
    // 0050d83d  2500ff0000             -and eax, 0xff00
    cpu.eax &= x86::reg32(x86::sreg32(65280 /*0xff00*/));
    // 0050d842  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
L_0x0050d844:
    // 0050d844  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0050d846  81e30000f800           -and ebx, 0xf80000
    cpu.ebx &= x86::reg32(x86::sreg32(16252928 /*0xf80000*/));
    // 0050d84c  c1eb09                 -shr ebx, 9
    cpu.ebx >>= 9 /*0x9*/ % 32;
    // 0050d84f  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0050d851  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 0050d854  81e200f80000           -and edx, 0xf800
    cpu.edx &= x86::reg32(x86::sreg32(63488 /*0xf800*/));
    // 0050d85a  c1ea06                 -shr edx, 6
    cpu.edx >>= 6 /*0x6*/ % 32;
    // 0050d85d  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 0050d860  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0050d862  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0050d864  66891e                 -mov word ptr [esi], bx
    app->getMemory<x86::reg16>(cpu.esi) = cpu.bx;
L_0x0050d867:
    // 0050d867  8d7602                 -lea esi, [esi + 2]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 0050d86a  83c704                 +add edi, 4
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0050d86d  4d                     +dec ebp
    {
        x86::reg32& tmp = cpu.ebp;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0050d86e  0f8576ffffff           -jne 0x50d7ea
    if (!cpu.flags.zf)
    {
        goto L_0x0050d7ea;
    }
    // 0050d874  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050d875  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050d876  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050d877  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050d878  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_50d880(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050d880  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050d881  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050d882  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050d883  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0050d884  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0050d886  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0050d888  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
L_0x0050d88a:
    // 0050d88a  8b1f                   -mov ebx, dword ptr [edi]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi);
    // 0050d88c  81fb00000010           +cmp ebx, 0x10000000
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(268435456 /*0x10000000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050d892  726b                   -jb 0x50d8ff
    if (cpu.flags.cf)
    {
        goto L_0x0050d8ff;
    }
    // 0050d894  81fb000000fc           +cmp ebx, 0xfc000000
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4227858432 /*0xfc000000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050d89a  7340                   -jae 0x50d8dc
    if (!cpu.flags.cf)
    {
        goto L_0x0050d8dc;
    }
    // 0050d89c  668b06                 -mov ax, word ptr [esi]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi);
    // 0050d89f  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0050d8a1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0050d8a3  83f1ff                 -xor ecx, 0xffffffff
    cpu.ecx ^= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0050d8a6  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 0050d8a9  88d0                   -mov al, dl
    cpu.al = cpu.dl;
    // 0050d8ab  81e2e0070000           -and edx, 0x7e0
    cpu.edx &= x86::reg32(x86::sreg32(2016 /*0x7e0*/));
    // 0050d8b1  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 0050d8b4  251f0000f8             -and eax, 0xf800001f
    cpu.eax &= x86::reg32(x86::sreg32(4160749599 /*0xf800001f*/));
    // 0050d8b9  c1e918                 -shr ecx, 0x18
    cpu.ecx >>= 24 /*0x18*/ % 32;
    // 0050d8bc  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0050d8be  f7e1                   -mul ecx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.ecx);
    // 0050d8c0  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0050d8c3  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0050d8c5  c1e905                 -shr ecx, 5
    cpu.ecx >>= 5 /*0x5*/ % 32;
    // 0050d8c8  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0050d8ca  c1e80b                 -shr eax, 0xb
    cpu.eax >>= 11 /*0xb*/ % 32;
    // 0050d8cd  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0050d8d3  2500ff0000             -and eax, 0xff00
    cpu.eax &= x86::reg32(x86::sreg32(65280 /*0xff00*/));
    // 0050d8d8  01cb                   -add ebx, ecx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0050d8da  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
L_0x0050d8dc:
    // 0050d8dc  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0050d8de  81e30000f800           -and ebx, 0xf80000
    cpu.ebx &= x86::reg32(x86::sreg32(16252928 /*0xf80000*/));
    // 0050d8e4  c1eb08                 -shr ebx, 8
    cpu.ebx >>= 8 /*0x8*/ % 32;
    // 0050d8e7  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0050d8e9  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 0050d8ec  81e200fc0000           -and edx, 0xfc00
    cpu.edx &= x86::reg32(x86::sreg32(64512 /*0xfc00*/));
    // 0050d8f2  c1ea05                 -shr edx, 5
    cpu.edx >>= 5 /*0x5*/ % 32;
    // 0050d8f5  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 0050d8f8  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0050d8fa  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0050d8fc  66891e                 -mov word ptr [esi], bx
    app->getMemory<x86::reg16>(cpu.esi) = cpu.bx;
L_0x0050d8ff:
    // 0050d8ff  8d7602                 -lea esi, [esi + 2]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 0050d902  83c704                 +add edi, 4
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0050d905  4d                     +dec ebp
    {
        x86::reg32& tmp = cpu.ebp;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0050d906  7582                   -jne 0x50d88a
    if (!cpu.flags.zf)
    {
        goto L_0x0050d88a;
    }
    // 0050d908  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050d909  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050d90a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050d90b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050d90c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_50d910(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050d910  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050d911  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050d912  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050d913  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0050d914  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0050d917  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
L_0x0050d919:
    // 0050d919  80780300               +cmp byte ptr [eax + 3], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(3) /* 0x3 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0050d91d  7511                   -jne 0x50d930
    if (!cpu.flags.zf)
    {
        goto L_0x0050d930;
    }
L_0x0050d91f:
    // 0050d91f  83c203                 -add edx, 3
    (cpu.edx) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0050d922  83c004                 +add eax, 4
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
    // 0050d925  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0050d926  75f1                   -jne 0x50d919
    if (!cpu.flags.zf)
    {
        goto L_0x0050d919;
    }
    // 0050d928  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0050d92b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050d92c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050d92d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050d92e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050d92f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050d930:
    // 0050d930  8a4801                 -mov cl, byte ptr [eax + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0050d933  b3ff                   -mov bl, 0xff
    cpu.bl = 255 /*0xff*/;
    // 0050d935  8a6a02                 -mov ch, byte ptr [edx + 2]
    cpu.ch = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 0050d938  8a7803                 -mov bh, byte ptr [eax + 3]
    cpu.bh = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(3) /* 0x3 */);
    // 0050d93b  886c2410               -mov byte ptr [esp + 0x10], ch
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ch;
    // 0050d93f  28fb                   -sub bl, bh
    (cpu.bl) -= x86::reg8(x86::sreg8(cpu.bh));
    // 0050d941  0fb6742410             -movzx esi, byte ptr [esp + 0x10]
    cpu.esi = x86::reg32(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */));
    // 0050d946  885c240c               -mov byte ptr [esp + 0xc], bl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.bl;
    // 0050d94a  893424                 -mov dword ptr [esp], esi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.esi;
    // 0050d94d  0fb674240c             -movzx esi, byte ptr [esp + 0xc]
    cpu.esi = x86::reg32(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */));
    // 0050d952  8b2c24                 -mov ebp, dword ptr [esp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    // 0050d955  0fafee                 -imul ebp, esi
    cpu.ebp = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebp)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 0050d958  8a5802                 -mov bl, byte ptr [eax + 2]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 0050d95b  c1fd08                 -sar ebp, 8
    cpu.ebp = x86::reg32(x86::sreg32(cpu.ebp) >> (8 /*0x8*/ % 32));
    // 0050d95e  8a38                   -mov bh, byte ptr [eax]
    cpu.bh = app->getMemory<x86::reg8>(cpu.eax);
    // 0050d960  892c24                 -mov dword ptr [esp], ebp
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebp;
    // 0050d963  0fb6eb                 -movzx ebp, bl
    cpu.ebp = x86::reg32(cpu.bl);
    // 0050d966  8a6a01                 -mov ch, byte ptr [edx + 1]
    cpu.ch = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 0050d969  032c24                 -add ebp, dword ptr [esp]
    (cpu.ebp) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp)));
    // 0050d96c  886c2408               -mov byte ptr [esp + 8], ch
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ch;
    // 0050d970  892c24                 -mov dword ptr [esp], ebp
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebp;
    // 0050d973  0fb66c2408             -movzx ebp, byte ptr [esp + 8]
    cpu.ebp = x86::reg32(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */));
    // 0050d978  0fafee                 -imul ebp, esi
    cpu.ebp = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebp)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 0050d97b  8a2a                   -mov ch, byte ptr [edx]
    cpu.ch = app->getMemory<x86::reg8>(cpu.edx);
    // 0050d97d  886c2404               -mov byte ptr [esp + 4], ch
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ch;
    // 0050d981  c1fd08                 -sar ebp, 8
    cpu.ebp = x86::reg32(x86::sreg32(cpu.ebp) >> (8 /*0x8*/ % 32));
    // 0050d984  8a1c24                 -mov bl, byte ptr [esp]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esp);
    // 0050d987  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0050d98d  01e9                   -add ecx, ebp
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0050d98f  0fb66c2404             -movzx ebp, byte ptr [esp + 4]
    cpu.ebp = x86::reg32(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */));
    // 0050d994  0faff5                 -imul esi, ebp
    cpu.esi = x86::reg32(x86::sreg64(x86::sreg32(cpu.esi)) * x86::sreg64(x86::sreg32(cpu.ebp)));
    // 0050d997  c1fe08                 -sar esi, 8
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (8 /*0x8*/ % 32));
    // 0050d99a  893424                 -mov dword ptr [esp], esi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.esi;
    // 0050d99d  8b2c24                 -mov ebp, dword ptr [esp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    // 0050d9a0  0fb6f7                 -movzx esi, bh
    cpu.esi = x86::reg32(cpu.bh);
    // 0050d9a3  01f5                   +add ebp, esi
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0050d9a5  892c24                 -mov dword ptr [esp], ebp
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebp;
    // 0050d9a8  884a01                 -mov byte ptr [edx + 1], cl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */) = cpu.cl;
    // 0050d9ab  8a3c24                 -mov bh, byte ptr [esp]
    cpu.bh = app->getMemory<x86::reg8>(cpu.esp);
    // 0050d9ae  885a02                 -mov byte ptr [edx + 2], bl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(2) /* 0x2 */) = cpu.bl;
    // 0050d9b1  883a                   -mov byte ptr [edx], bh
    app->getMemory<x86::reg8>(cpu.edx) = cpu.bh;
    // 0050d9b3  e967ffffff             -jmp 0x50d91f
    goto L_0x0050d91f;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_50d9c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050d9c0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050d9c1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050d9c2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050d9c3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0050d9c4  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0050d9c7  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
L_0x0050d9c9:
    // 0050d9c9  80780300               +cmp byte ptr [eax + 3], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(3) /* 0x3 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0050d9cd  7511                   -jne 0x50d9e0
    if (!cpu.flags.zf)
    {
        goto L_0x0050d9e0;
    }
L_0x0050d9cf:
    // 0050d9cf  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0050d9d2  83c004                 +add eax, 4
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
    // 0050d9d5  4e                     +dec esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0050d9d6  75f1                   -jne 0x50d9c9
    if (!cpu.flags.zf)
    {
        goto L_0x0050d9c9;
    }
    // 0050d9d8  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0050d9db  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050d9dc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050d9dd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050d9de  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050d9df  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050d9e0:
    // 0050d9e0  8a5802                 -mov bl, byte ptr [eax + 2]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 0050d9e3  8a7801                 -mov bh, byte ptr [eax + 1]
    cpu.bh = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0050d9e6  887c2414               -mov byte ptr [esp + 0x14], bh
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.bh;
    // 0050d9ea  8a38                   -mov bh, byte ptr [eax]
    cpu.bh = app->getMemory<x86::reg8>(cpu.eax);
    // 0050d9ec  887c2410               -mov byte ptr [esp + 0x10], bh
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.bh;
    // 0050d9f0  807a0300               +cmp byte ptr [edx + 3], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(3) /* 0x3 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0050d9f4  0f84a1000000           -je 0x50da9b
    if (cpu.flags.zf)
    {
        goto L_0x0050da9b;
    }
    // 0050d9fa  b7ff                   -mov bh, 0xff
    cpu.bh = 255 /*0xff*/;
    // 0050d9fc  2a7803                 -sub bh, byte ptr [eax + 3]
    (cpu.bh) -= x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(3) /* 0x3 */)));
    // 0050d9ff  8a4a02                 -mov cl, byte ptr [edx + 2]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 0050da02  8a2a                   -mov ch, byte ptr [edx]
    cpu.ch = app->getMemory<x86::reg8>(cpu.edx);
    // 0050da04  887c2408               -mov byte ptr [esp + 8], bh
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.bh;
    // 0050da08  886c240c               -mov byte ptr [esp + 0xc], ch
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ch;
    // 0050da0c  0fb6f9                 -movzx edi, cl
    cpu.edi = x86::reg32(cpu.cl);
    // 0050da0f  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0050da11  8a4c2408               -mov cl, byte ptr [esp + 8]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0050da15  0faff9                 -imul edi, ecx
    cpu.edi = x86::reg32(x86::sreg64(x86::sreg32(cpu.edi)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 0050da18  8a7a01                 -mov bh, byte ptr [edx + 1]
    cpu.bh = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 0050da1b  0fb6eb                 -movzx ebp, bl
    cpu.ebp = x86::reg32(cpu.bl);
    // 0050da1e  c1ff08                 -sar edi, 8
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (8 /*0x8*/ % 32));
    // 0050da21  01fd                   -add ebp, edi
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.edi));
    // 0050da23  896c2404               -mov dword ptr [esp + 4], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 0050da27  8a5c2404               -mov bl, byte ptr [esp + 4]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0050da2b  0fb6ff                 -movzx edi, bh
    cpu.edi = x86::reg32(cpu.bh);
    // 0050da2e  0faff9                 -imul edi, ecx
    cpu.edi = x86::reg32(x86::sreg64(x86::sreg32(cpu.edi)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 0050da31  0fb66c2414             -movzx ebp, byte ptr [esp + 0x14]
    cpu.ebp = x86::reg32(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(20) /* 0x14 */));
    // 0050da36  c1ff08                 -sar edi, 8
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (8 /*0x8*/ % 32));
    // 0050da39  01fd                   -add ebp, edi
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.edi));
    // 0050da3b  0fb67c240c             -movzx edi, byte ptr [esp + 0xc]
    cpu.edi = x86::reg32(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */));
    // 0050da40  0faff9                 -imul edi, ecx
    cpu.edi = x86::reg32(x86::sreg64(x86::sreg32(cpu.edi)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 0050da43  c1ff08                 -sar edi, 8
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (8 /*0x8*/ % 32));
    // 0050da46  896c2404               -mov dword ptr [esp + 4], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 0050da4a  893c24                 -mov dword ptr [esp], edi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edi;
    // 0050da4d  0fb67c2410             -movzx edi, byte ptr [esp + 0x10]
    cpu.edi = x86::reg32(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */));
    // 0050da52  8b2c24                 -mov ebp, dword ptr [esp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    // 0050da55  01fd                   -add ebp, edi
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.edi));
    // 0050da57  892c24                 -mov dword ptr [esp], ebp
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebp;
    // 0050da5a  0fb67a03               -movzx edi, byte ptr [edx + 3]
    cpu.edi = x86::reg32(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(3) /* 0x3 */));
    // 0050da5e  bdff000000             -mov ebp, 0xff
    cpu.ebp = 255 /*0xff*/;
    // 0050da63  29fd                   -sub ebp, edi
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.edi));
    // 0050da65  0fafcd                 -imul ecx, ebp
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(cpu.ebp)));
    // 0050da68  8a7c2404               -mov bh, byte ptr [esp + 4]
    cpu.bh = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0050da6c  bfff000000             -mov edi, 0xff
    cpu.edi = 255 /*0xff*/;
    // 0050da71  c1f908                 -sar ecx, 8
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (8 /*0x8*/ % 32));
    // 0050da74  887c2414               -mov byte ptr [esp + 0x14], bh
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.bh;
    // 0050da78  29cf                   +sub edi, ecx
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0050da7a  8a3c24                 -mov bh, byte ptr [esp]
    cpu.bh = app->getMemory<x86::reg8>(cpu.esp);
    // 0050da7d  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0050da7f  887c2410               -mov byte ptr [esp + 0x10], bh
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.bh;
L_0x0050da83:
    // 0050da83  884a03                 -mov byte ptr [edx + 3], cl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(3) /* 0x3 */) = cpu.cl;
    // 0050da86  885a02                 -mov byte ptr [edx + 2], bl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(2) /* 0x2 */) = cpu.bl;
    // 0050da89  8a5c2414               -mov bl, byte ptr [esp + 0x14]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0050da8d  885a01                 -mov byte ptr [edx + 1], bl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */) = cpu.bl;
    // 0050da90  8a5c2410               -mov bl, byte ptr [esp + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0050da94  881a                   -mov byte ptr [edx], bl
    app->getMemory<x86::reg8>(cpu.edx) = cpu.bl;
    // 0050da96  e934ffffff             -jmp 0x50d9cf
    goto L_0x0050d9cf;
L_0x0050da9b:
    // 0050da9b  8a4803                 -mov cl, byte ptr [eax + 3]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(3) /* 0x3 */);
    // 0050da9e  ebe3                   -jmp 0x50da83
    goto L_0x0050da83;
}

/* align: skip  */
void Application::sub_50daa0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050daa0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050daa1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050daa2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050daa3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0050daa4  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0050daa6  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0050daa8  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
L_0x0050daaa:
    // 0050daaa  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0050daac  8a5d00                 -mov bl, byte ptr [ebp]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebp);
    // 0050daaf  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 0050dab6  8b1d20b0a000           -mov ebx, dword ptr [0xa0b020]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10530848) /* 0xa0b020 */);
    // 0050dabc  8b1c03                 -mov ebx, dword ptr [ebx + eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + cpu.eax * 1);
    // 0050dabf  45                     -inc ebp
    (cpu.ebp)++;
    // 0050dac0  81fb00000010           +cmp ebx, 0x10000000
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(268435456 /*0x10000000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050dac6  7250                   -jb 0x50db18
    if (cpu.flags.cf)
    {
        goto L_0x0050db18;
    }
    // 0050dac8  81fb000000fc           +cmp ebx, 0xfc000000
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4227858432 /*0xfc000000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050dace  7345                   -jae 0x50db15
    if (!cpu.flags.cf)
    {
        goto L_0x0050db15;
    }
    // 0050dad0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0050dad2  668b06                 -mov ax, word ptr [esi]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi);
    // 0050dad5  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0050dad7  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0050dad9  83f1ff                 -xor ecx, 0xffffffff
    cpu.ecx ^= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 0050dadc  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 0050dadf  88d0                   -mov al, dl
    cpu.al = cpu.dl;
    // 0050dae1  81e2e0070000           -and edx, 0x7e0
    cpu.edx &= x86::reg32(x86::sreg32(2016 /*0x7e0*/));
    // 0050dae7  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 0050daea  251f0000f8             -and eax, 0xf800001f
    cpu.eax &= x86::reg32(x86::sreg32(4160749599 /*0xf800001f*/));
    // 0050daef  c1e918                 -shr ecx, 0x18
    cpu.ecx >>= 24 /*0x18*/ % 32;
    // 0050daf2  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0050daf4  f7e1                   -mul ecx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.ecx);
    // 0050daf6  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 0050daf9  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0050dafb  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 0050dafe  81e200f80000           -and edx, 0xf800
    cpu.edx &= x86::reg32(x86::sreg32(63488 /*0xf800*/));
    // 0050db04  c1e908                 -shr ecx, 8
    cpu.ecx >>= 8 /*0x8*/ % 32;
    // 0050db07  25e0070000             -and eax, 0x7e0
    cpu.eax &= x86::reg32(x86::sreg32(2016 /*0x7e0*/));
    // 0050db0c  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0050db0e  83e11f                 -and ecx, 0x1f
    cpu.ecx &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 0050db11  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0050db13  01cb                   +add ebx, ecx
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
L_0x0050db15:
    // 0050db15  66891e                 -mov word ptr [esi], bx
    app->getMemory<x86::reg16>(cpu.esi) = cpu.bx;
L_0x0050db18:
    // 0050db18  8d7602                 -lea esi, [esi + 2]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 0050db1b  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0050db1c  758c                   -jne 0x50daaa
    if (!cpu.flags.zf)
    {
        goto L_0x0050daaa;
    }
    // 0050db1e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050db1f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050db20  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050db21  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050db22  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_50db30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050db30  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050db31  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050db32  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050db33  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0050db34  81ec00040000           -sub esp, 0x400
    (cpu.esp) -= x86::reg32(x86::sreg32(1024 /*0x400*/));
    // 0050db3a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0050db3c  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0050db3e  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0050db40  83e07f                 -and eax, 0x7f
    cpu.eax &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 0050db43  8a80546d5600           -mov al, byte ptr [eax + 0x566d54]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5664084) /* 0x566d54 */);
    // 0050db49  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0050db4b  b97d000000             -mov ecx, 0x7d
    cpu.ecx = 125 /*0x7d*/;
    // 0050db50  8915c0885600           -mov dword ptr [0x5688c0], edx
    app->getMemory<x86::reg32>(x86::reg32(5671104) /* 0x5688c0 */) = cpu.edx;
    // 0050db56  890dc8885600           -mov dword ptr [0x5688c8], ecx
    app->getMemory<x86::reg32>(x86::reg32(5671112) /* 0x5688c8 */) = cpu.ecx;
    // 0050db5c  83f808                 +cmp eax, 8
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050db5f  752c                   -jne 0x50db8d
    if (!cpu.flags.zf)
    {
        goto L_0x0050db8d;
    }
    // 0050db61  803d1050560010         +cmp byte ptr [0x565010], 0x10
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5656592) /* 0x565010 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(16 /*0x10*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0050db68  7523                   -jne 0x50db8d
    if (!cpu.flags.zf)
    {
        goto L_0x0050db8d;
    }
    // 0050db6a  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0050db6c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0050db6e  bda0da5000             -mov ebp, 0x50daa0
    cpu.ebp = 5298848 /*0x50daa0*/;
    // 0050db73  e8b8ccffff             -call 0x50a830
    cpu.esp -= 4;
    sub_50a830(app, cpu);
    if (cpu.terminate) return;
    // 0050db78  a320b0a000             -mov dword ptr [0xa0b020], eax
    app->getMemory<x86::reg32>(x86::reg32(10530848) /* 0xa0b020 */) = cpu.eax;
    // 0050db7d  b87b000000             -mov eax, 0x7b
    cpu.eax = 123 /*0x7b*/;
    // 0050db82  892dc0885600           -mov dword ptr [0x5688c0], ebp
    app->getMemory<x86::reg32>(x86::reg32(5671104) /* 0x5688c0 */) = cpu.ebp;
    // 0050db88  a3c8885600             -mov dword ptr [0x5688c8], eax
    app->getMemory<x86::reg32>(x86::reg32(5671112) /* 0x5688c8 */) = cpu.eax;
L_0x0050db8d:
    // 0050db8d  b9a8885600             -mov ecx, 0x5688a8
    cpu.ecx = 5671080 /*0x5688a8*/;
    // 0050db92  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0050db94  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0050db96  e815d5ffff             -call 0x50b0b0
    cpu.esp -= 4;
    sub_50b0b0(app, cpu);
    if (cpu.terminate) return;
    // 0050db9b  81c400040000           -add esp, 0x400
    (cpu.esp) += x86::reg32(x86::sreg32(1024 /*0x400*/));
    // 0050dba1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050dba2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050dba3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050dba4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050dba5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void Application::sub_50dbb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050dbb0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0050dbb1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0050dbb2  8b580c                 -mov ebx, dword ptr [eax + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0050dbb5  8b500c                 -mov edx, dword ptr [eax + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0050dbb8  c1e304                 -shl ebx, 4
    cpu.ebx <<= 4 /*0x4*/ % 32;
    // 0050dbbb  c1e214                 -shl edx, 0x14
    cpu.edx <<= 20 /*0x14*/ % 32;
    // 0050dbbe  c1fb14                 -sar ebx, 0x14
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (20 /*0x14*/ % 32));
    // 0050dbc1  c1fa14                 -sar edx, 0x14
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (20 /*0x14*/ % 32));
    // 0050dbc4  e867ffffff             -call 0x50db30
    cpu.esp -= 4;
    sub_50db30(app, cpu);
    if (cpu.terminate) return;
    // 0050dbc9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050dbca  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050dbcb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_50dbd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050dbd0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050dbd1  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0050dbd4  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 0050dbd7  29cb                   -sub ebx, ecx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0050dbd9  8b4806                 -mov ecx, dword ptr [eax + 6]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6) /* 0x6 */);
    // 0050dbdc  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 0050dbdf  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0050dbe1  e84affffff             -call 0x50db30
    cpu.esp -= 4;
    sub_50db30(app, cpu);
    if (cpu.terminate) return;
    // 0050dbe6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050dbe7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_50dbf0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050dbf0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_50dc00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050dc00  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0050dc02  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0050dc04  740c                   -je 0x50dc12
    if (cpu.flags.zf)
    {
        goto L_0x0050dc12;
    }
L_0x0050dc06:
    // 0050dc06  4a                     -dec edx
    (cpu.edx)--;
    // 0050dc07  83faff                 +cmp edx, -1
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
    // 0050dc0a  7406                   -je 0x50dc12
    if (cpu.flags.zf)
    {
        goto L_0x0050dc12;
    }
    // 0050dc0c  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0050dc0e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0050dc10  75f4                   -jne 0x50dc06
    if (!cpu.flags.zf)
    {
        goto L_0x0050dc06;
    }
L_0x0050dc12:
    // 0050dc12  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_50dc20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050dc20  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0050dc21  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050dc22  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050dc23  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050dc24  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0050dc25  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0050dc27  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0050dc29  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0050dc2b  7441                   -je 0x50dc6e
    if (cpu.flags.zf)
    {
        goto L_0x0050dc6e;
    }
    // 0050dc2d  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax);
    // 0050dc2f  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0050dc31  763b                   -jbe 0x50dc6e
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0050dc6e;
    }
    // 0050dc33  8b7808                 -mov edi, dword ptr [eax + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0050dc36  39fa                   +cmp edx, edi
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
    // 0050dc38  743c                   -je 0x50dc76
    if (cpu.flags.zf)
    {
        goto L_0x0050dc76;
    }
    // 0050dc3a  8b2f                   -mov ebp, dword ptr [edi]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edi);
    // 0050dc3c  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0050dc3e  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0050dc40  740b                   -je 0x50dc4d
    if (cpu.flags.zf)
    {
        goto L_0x0050dc4d;
    }
L_0x0050dc42:
    // 0050dc42  3b10                   +cmp edx, dword ptr [eax]
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
    // 0050dc44  7407                   -je 0x50dc4d
    if (cpu.flags.zf)
    {
        goto L_0x0050dc4d;
    }
    // 0050dc46  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0050dc48  833800                 +cmp dword ptr [eax], 0
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
    // 0050dc4b  75f5                   -jne 0x50dc42
    if (!cpu.flags.zf)
    {
        goto L_0x0050dc42;
    }
L_0x0050dc4d:
    // 0050dc4d  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax);
    // 0050dc4f  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0050dc51  7417                   -je 0x50dc6a
    if (cpu.flags.zf)
    {
        goto L_0x0050dc6a;
    }
    // 0050dc53  39f2                   +cmp edx, esi
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
    // 0050dc55  7513                   -jne 0x50dc6a
    if (!cpu.flags.zf)
    {
        goto L_0x0050dc6a;
    }
    // 0050dc57  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0050dc5c  2919                   -sub dword ptr [ecx], ebx
    (app->getMemory<x86::reg32>(cpu.ecx)) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0050dc5e  8b36                   -mov esi, dword ptr [esi]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi);
    // 0050dc60  8930                   -mov dword ptr [eax], esi
    app->getMemory<x86::reg32>(cpu.eax) = cpu.esi;
    // 0050dc62  3b510c                 +cmp edx, dword ptr [ecx + 0xc]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050dc65  7503                   -jne 0x50dc6a
    if (!cpu.flags.zf)
    {
        goto L_0x0050dc6a;
    }
    // 0050dc67  89410c                 -mov dword ptr [ecx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.eax;
L_0x0050dc6a:
    // 0050dc6a  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0050dc6c  7544                   -jne 0x50dcb2
    if (!cpu.flags.zf)
    {
        goto L_0x0050dcb2;
    }
L_0x0050dc6e:
    // 0050dc6e  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0050dc70  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050dc71  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050dc72  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050dc73  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050dc74  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050dc75  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050dc76:
    // 0050dc76  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0050dc7b  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0050dc7d  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0050dc7f  8b710c                 -mov esi, dword ptr [ecx + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 0050dc82  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 0050dc84  39f7                   +cmp edi, esi
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
    // 0050dc86  7519                   -jne 0x50dca1
    if (!cpu.flags.zf)
    {
        goto L_0x0050dca1;
    }
    // 0050dc88  c7410800000000         -mov dword ptr [ecx + 8], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 0050dc8f  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 0050dc92  89410c                 -mov dword ptr [ecx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0050dc95  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0050dc97  7519                   -jne 0x50dcb2
    if (!cpu.flags.zf)
    {
        goto L_0x0050dcb2;
    }
    // 0050dc99  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0050dc9b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050dc9c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050dc9d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050dc9e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050dc9f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050dca0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050dca1:
    // 0050dca1  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 0050dca3  894108                 -mov dword ptr [ecx + 8], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0050dca6  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0050dca8  7508                   -jne 0x50dcb2
    if (!cpu.flags.zf)
    {
        goto L_0x0050dcb2;
    }
    // 0050dcaa  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0050dcac  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050dcad  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050dcae  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050dcaf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050dcb0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050dcb1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050dcb2:
    // 0050dcb2  c70200000000           -mov dword ptr [edx], 0
    app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 0050dcb8  80490401               -or byte ptr [ecx + 4], 1
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 0050dcbc  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0050dcbe  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050dcbf  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050dcc0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050dcc1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050dcc2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050dcc3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_50dcd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050dcd0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050dcd1  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0050dcd3  e808d6fdff             -call 0x4eb2e0
    cpu.esp -= 4;
    sub_4eb2e0(app, cpu);
    if (cpu.terminate) return;
    // 0050dcd8  c70100000000           -mov dword ptr [ecx], 0
    app->getMemory<x86::reg32>(cpu.ecx) = 0 /*0x0*/;
    // 0050dcde  c7410402000000         -mov dword ptr [ecx + 4], 2
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = 2 /*0x2*/;
    // 0050dce5  c7410800000000         -mov dword ptr [ecx + 8], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 0050dcec  c7410c00000000         -mov dword ptr [ecx + 0xc], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 0050dcf3  894118                 -mov dword ptr [ecx + 0x18], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 0050dcf6  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0050dcf8  740f                   -je 0x50dd09
    if (cpu.flags.zf)
    {
        goto L_0x0050dd09;
    }
    // 0050dcfa  895110                 -mov dword ptr [ecx + 0x10], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 0050dcfd  8b5118                 -mov edx, dword ptr [ecx + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 0050dd00  895914                 -mov dword ptr [ecx + 0x14], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */) = cpu.ebx;
    // 0050dd03  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0050dd05  7416                   -je 0x50dd1d
    if (cpu.flags.zf)
    {
        goto L_0x0050dd1d;
    }
    // 0050dd07  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050dd08  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050dd09:
    // 0050dd09  baf0db5000             -mov edx, 0x50dbf0
    cpu.edx = 5299184 /*0x50dbf0*/;
    // 0050dd0e  895110                 -mov dword ptr [ecx + 0x10], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 0050dd11  8b5118                 -mov edx, dword ptr [ecx + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 0050dd14  895914                 -mov dword ptr [ecx + 0x14], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */) = cpu.ebx;
    // 0050dd17  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0050dd19  7402                   -je 0x50dd1d
    if (cpu.flags.zf)
    {
        goto L_0x0050dd1d;
    }
    // 0050dd1b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050dd1c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050dd1d:
    // 0050dd1d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050dd1e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050dd1f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050dd20  bec4fb5400             -mov esi, 0x54fbc4
    cpu.esi = 5569476 /*0x54fbc4*/;
    // 0050dd25  bbb8fb5400             -mov ebx, 0x54fbb8
    cpu.ebx = 5569464 /*0x54fbb8*/;
    // 0050dd2a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050dd2b  bf8b000000             -mov edi, 0x8b
    cpu.edi = 139 /*0x8b*/;
    // 0050dd30  891d90215500           -mov dword ptr [0x552190], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ebx;
    // 0050dd36  68ccfb5400             -push 0x54fbcc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5569484 /*0x54fbcc*/;
    cpu.esp -= 4;
    // 0050dd3b  893594215500           -mov dword ptr [0x552194], esi
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.esi;
    // 0050dd41  893d98215500           -mov dword ptr [0x552198], edi
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.edi;
    // 0050dd47  e8c432efff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 0050dd4c  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0050dd4f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050dd50  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050dd51  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050dd52  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_50dd60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050dd60  8b4918                 -mov ecx, dword ptr [ecx + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 0050dd63  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 0050dd69  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 0050dd70  c7400800000000         -mov dword ptr [eax + 8], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 0050dd77  c7400c00000000         -mov dword ptr [eax + 0xc], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 0050dd7e  894818                 -mov dword ptr [eax + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 0050dd81  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0050dd83  740e                   -je 0x50dd93
    if (cpu.flags.zf)
    {
        goto L_0x0050dd93;
    }
    // 0050dd85  895010                 -mov dword ptr [eax + 0x10], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 0050dd88  8b5018                 -mov edx, dword ptr [eax + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0050dd8b  895814                 -mov dword ptr [eax + 0x14], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ebx;
    // 0050dd8e  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0050dd90  7414                   -je 0x50dda6
    if (cpu.flags.zf)
    {
        goto L_0x0050dda6;
    }
    // 0050dd92  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050dd93:
    // 0050dd93  baf0db5000             -mov edx, 0x50dbf0
    cpu.edx = 5299184 /*0x50dbf0*/;
    // 0050dd98  895010                 -mov dword ptr [eax + 0x10], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 0050dd9b  8b5018                 -mov edx, dword ptr [eax + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0050dd9e  895814                 -mov dword ptr [eax + 0x14], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ebx;
    // 0050dda1  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0050dda3  7401                   -je 0x50dda6
    if (cpu.flags.zf)
    {
        goto L_0x0050dda6;
    }
    // 0050dda5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050dda6:
    // 0050dda6  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050dda7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0050dda8  bbf4fb5400             -mov ebx, 0x54fbf4
    cpu.ebx = 5569524 /*0x54fbf4*/;
    // 0050ddad  b9b8fb5400             -mov ecx, 0x54fbb8
    cpu.ecx = 5569464 /*0x54fbb8*/;
    // 0050ddb2  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0050ddb3  bec7000000             -mov esi, 0xc7
    cpu.esi = 199 /*0xc7*/;
    // 0050ddb8  890d90215500           -mov dword ptr [0x552190], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ecx;
    // 0050ddbe  68ccfb5400             -push 0x54fbcc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5569484 /*0x54fbcc*/;
    cpu.esp -= 4;
    // 0050ddc3  891d94215500           -mov dword ptr [0x552194], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebx;
    // 0050ddc9  893598215500           -mov dword ptr [0x552198], esi
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.esi;
    // 0050ddcf  e83c32efff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 0050ddd4  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0050ddd7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050ddd8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_50dde0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050dde0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0050dde1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0050dde3  83781800               +cmp dword ptr [eax + 0x18], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050dde7  740f                   -je 0x50ddf8
    if (cpu.flags.zf)
    {
        goto L_0x0050ddf8;
    }
    // 0050dde9  f6420402               +test byte ptr [edx + 4], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(4) /* 0x4 */) & 2 /*0x2*/));
    // 0050dded  754e                   -jne 0x50de3d
    if (!cpu.flags.zf)
    {
        goto L_0x0050de3d;
    }
    // 0050ddef  c7421800000000         -mov dword ptr [edx + 0x18], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 0050ddf6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050ddf7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050ddf8:
    // 0050ddf8  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050ddf9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050ddfa  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0050ddfb  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0050ddfc  be00fc5400             -mov esi, 0x54fc00
    cpu.esi = 5569536 /*0x54fc00*/;
    // 0050de01  bbb8fb5400             -mov ebx, 0x54fbb8
    cpu.ebx = 5569464 /*0x54fbb8*/;
    // 0050de06  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050de07  bff0000000             -mov edi, 0xf0
    cpu.edi = 240 /*0xf0*/;
    // 0050de0c  891d90215500           -mov dword ptr [0x552190], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ebx;
    // 0050de12  68ccfb5400             -push 0x54fbcc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5569484 /*0x54fbcc*/;
    cpu.esp -= 4;
    // 0050de17  893594215500           -mov dword ptr [0x552194], esi
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.esi;
    // 0050de1d  893d98215500           -mov dword ptr [0x552198], edi
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.edi;
    // 0050de23  e8e831efff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 0050de28  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0050de2b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050de2c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050de2d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050de2e  f6420402               +test byte ptr [edx + 4], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(4) /* 0x4 */) & 2 /*0x2*/));
    // 0050de32  7509                   -jne 0x50de3d
    if (!cpu.flags.zf)
    {
        goto L_0x0050de3d;
    }
    // 0050de34  c7421800000000         -mov dword ptr [edx + 0x18], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 0050de3b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050de3c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050de3d:
    // 0050de3d  8b4218                 -mov eax, dword ptr [edx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 0050de40  e81bd5fdff             -call 0x4eb360
    cpu.esp -= 4;
    sub_4eb360(app, cpu);
    if (cpu.terminate) return;
    // 0050de45  c7421800000000         -mov dword ptr [edx + 0x18], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 0050de4c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050de4d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_50de50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050de50  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0050de51  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050de52  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050de53  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0050de54  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0050de56  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0050de58  8b5018                 -mov edx, dword ptr [eax + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0050de5b  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0050de5c  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050de62  837b1800               +cmp dword ptr [ebx + 0x18], 0
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
    // 0050de66  742c                   -je 0x50de94
    if (cpu.flags.zf)
    {
        goto L_0x0050de94;
    }
L_0x0050de68:
    // 0050de68  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0050de6a  7419                   -je 0x50de85
    if (cpu.flags.zf)
    {
        goto L_0x0050de85;
    }
    // 0050de6c  8b4308                 -mov eax, dword ptr [ebx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 0050de6f  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 0050de71  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 0050de73  897308                 -mov dword ptr [ebx + 8], esi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.esi;
    // 0050de76  42                     -inc edx
    (cpu.edx)++;
    // 0050de77  8913                   -mov dword ptr [ebx], edx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
    // 0050de79  833e00                 +cmp dword ptr [esi], 0
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
    // 0050de7c  7503                   -jne 0x50de81
    if (!cpu.flags.zf)
    {
        goto L_0x0050de81;
    }
    // 0050de7e  89730c                 -mov dword ptr [ebx + 0xc], esi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.esi;
L_0x0050de81:
    // 0050de81  804b0401               -or byte ptr [ebx + 4], 1
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x0050de85:
    // 0050de85  8b7318                 -mov esi, dword ptr [ebx + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 0050de88  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050de89  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050de8f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050de90  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050de91  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050de92  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050de93  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050de94:
    // 0050de94  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050de95  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0050de96  bd08fc5400             -mov ebp, 0x54fc08
    cpu.ebp = 5569544 /*0x54fc08*/;
    // 0050de9b  bfb8fb5400             -mov edi, 0x54fbb8
    cpu.edi = 5569464 /*0x54fbb8*/;
    // 0050dea0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0050dea1  b828010000             -mov eax, 0x128
    cpu.eax = 296 /*0x128*/;
    // 0050dea6  893d90215500           -mov dword ptr [0x552190], edi
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edi;
    // 0050deac  68ccfb5400             -push 0x54fbcc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5569484 /*0x54fbcc*/;
    cpu.esp -= 4;
    // 0050deb1  892d94215500           -mov dword ptr [0x552194], ebp
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebp;
    // 0050deb7  a398215500             -mov dword ptr [0x552198], eax
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.eax;
    // 0050debc  e84f31efff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 0050dec1  83c40c                 +add esp, 0xc
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
    // 0050dec4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050dec5  eba1                   -jmp 0x50de68
    goto L_0x0050de68;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_50ded0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050ded0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0050ded1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050ded2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050ded3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0050ded4  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0050ded6  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0050ded8  8b5018                 -mov edx, dword ptr [eax + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0050dedb  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0050dedc  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050dee2  837b1800               +cmp dword ptr [ebx + 0x18], 0
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
    // 0050dee6  742f                   -je 0x50df17
    if (cpu.flags.zf)
    {
        goto L_0x0050df17;
    }
L_0x0050dee8:
    // 0050dee8  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0050deea  741c                   -je 0x50df08
    if (cpu.flags.zf)
    {
        goto L_0x0050df08;
    }
    // 0050deec  8b430c                 -mov eax, dword ptr [ebx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 0050deef  c70600000000           -mov dword ptr [esi], 0
    app->getMemory<x86::reg32>(cpu.esi) = 0 /*0x0*/;
    // 0050def5  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 0050def7  89730c                 -mov dword ptr [ebx + 0xc], esi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.esi;
    // 0050defa  42                     -inc edx
    (cpu.edx)++;
    // 0050defb  8913                   -mov dword ptr [ebx], edx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
    // 0050defd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0050deff  7549                   -jne 0x50df4a
    if (!cpu.flags.zf)
    {
        goto L_0x0050df4a;
    }
    // 0050df01  897308                 -mov dword ptr [ebx + 8], esi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.esi;
    // 0050df04  804b0401               -or byte ptr [ebx + 4], 1
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x0050df08:
    // 0050df08  8b4b18                 -mov ecx, dword ptr [ebx + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 0050df0b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050df0c  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050df12  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050df13  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050df14  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050df15  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050df16  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050df17:
    // 0050df17  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050df18  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0050df19  bd10fc5400             -mov ebp, 0x54fc10
    cpu.ebp = 5569552 /*0x54fc10*/;
    // 0050df1e  bfb8fb5400             -mov edi, 0x54fbb8
    cpu.edi = 5569464 /*0x54fbb8*/;
    // 0050df23  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0050df24  b83c010000             -mov eax, 0x13c
    cpu.eax = 316 /*0x13c*/;
    // 0050df29  893d90215500           -mov dword ptr [0x552190], edi
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edi;
    // 0050df2f  68ccfb5400             -push 0x54fbcc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5569484 /*0x54fbcc*/;
    cpu.esp -= 4;
    // 0050df34  892d94215500           -mov dword ptr [0x552194], ebp
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebp;
    // 0050df3a  a398215500             -mov dword ptr [0x552198], eax
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.eax;
    // 0050df3f  e8cc30efff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 0050df44  83c40c                 +add esp, 0xc
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
    // 0050df47  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050df48  eb9e                   -jmp 0x50dee8
    goto L_0x0050dee8;
L_0x0050df4a:
    // 0050df4a  8930                   -mov dword ptr [eax], esi
    app->getMemory<x86::reg32>(cpu.eax) = cpu.esi;
    // 0050df4c  804b0401               -or byte ptr [ebx + 4], 1
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 0050df50  8b4b18                 -mov ecx, dword ptr [ebx + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 0050df53  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050df54  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050df5a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050df5b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050df5c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050df5d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050df5e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_50df60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050df60  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0050df61  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050df62  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0050df63  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050df64  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0050df65  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0050df67  8b5018                 -mov edx, dword ptr [eax + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0050df6a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0050df6b  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050df71  837b1800               +cmp dword ptr [ebx + 0x18], 0
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
    // 0050df75  743c                   -je 0x50dfb3
    if (cpu.flags.zf)
    {
        goto L_0x0050dfb3;
    }
L_0x0050df77:
    // 0050df77  8b7308                 -mov esi, dword ptr [ebx + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 0050df7a  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0050df7c  741a                   -je 0x50df98
    if (cpu.flags.zf)
    {
        goto L_0x0050df98;
    }
    // 0050df7e  3b730c                 +cmp esi, dword ptr [ebx + 0xc]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050df81  7564                   -jne 0x50dfe7
    if (!cpu.flags.zf)
    {
        goto L_0x0050dfe7;
    }
    // 0050df83  c7430c00000000         -mov dword ptr [ebx + 0xc], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 0050df8a  8b430c                 -mov eax, dword ptr [ebx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
L_0x0050df8d:
    // 0050df8d  894308                 -mov dword ptr [ebx + 8], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0050df90  ff0b                   -dec dword ptr [ebx]
    (app->getMemory<x86::reg32>(cpu.ebx))--;
    // 0050df92  c70600000000           -mov dword ptr [esi], 0
    app->getMemory<x86::reg32>(cpu.esi) = 0 /*0x0*/;
L_0x0050df98:
    // 0050df98  8a6304                 -mov ah, byte ptr [ebx + 4]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0050df9b  8b4b18                 -mov ecx, dword ptr [ebx + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 0050df9e  80cc01                 -or ah, 1
    cpu.ah |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 0050dfa1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050dfa2  886304                 -mov byte ptr [ebx + 4], ah
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.ah;
    // 0050dfa5  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050dfab  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0050dfad  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050dfae  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050dfaf  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050dfb0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050dfb1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050dfb2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050dfb3:
    // 0050dfb3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050dfb4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0050dfb5  bf18fc5400             -mov edi, 0x54fc18
    cpu.edi = 5569560 /*0x54fc18*/;
    // 0050dfba  beb8fb5400             -mov esi, 0x54fbb8
    cpu.esi = 5569464 /*0x54fbb8*/;
    // 0050dfbf  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050dfc0  bd7b010000             -mov ebp, 0x17b
    cpu.ebp = 379 /*0x17b*/;
    // 0050dfc5  893590215500           -mov dword ptr [0x552190], esi
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.esi;
    // 0050dfcb  68ccfb5400             -push 0x54fbcc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5569484 /*0x54fbcc*/;
    cpu.esp -= 4;
    // 0050dfd0  893d94215500           -mov dword ptr [0x552194], edi
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.edi;
    // 0050dfd6  892d98215500           -mov dword ptr [0x552198], ebp
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ebp;
    // 0050dfdc  e82f30efff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 0050dfe1  83c40c                 +add esp, 0xc
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
    // 0050dfe4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050dfe5  eb90                   -jmp 0x50df77
    goto L_0x0050df77;
L_0x0050dfe7:
    // 0050dfe7  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0050dfe9  eba2                   -jmp 0x50df8d
    goto L_0x0050df8d;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_50dff0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050dff0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0050dff1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050dff2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0050dff3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050dff4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050dff5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0050dff6  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0050dff8  8b5018                 -mov edx, dword ptr [eax + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0050dffb  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0050dffc  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050e002  837b1800               +cmp dword ptr [ebx + 0x18], 0
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
    // 0050e006  7424                   -je 0x50e02c
    if (cpu.flags.zf)
    {
        goto L_0x0050e02c;
    }
L_0x0050e008:
    // 0050e008  8b730c                 -mov esi, dword ptr [ebx + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 0050e00b  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0050e00d  745b                   -je 0x50e06a
    if (cpu.flags.zf)
    {
        goto L_0x0050e06a;
    }
    // 0050e00f  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 0050e011  48                     -dec eax
    (cpu.eax)--;
    // 0050e012  8b5308                 -mov edx, dword ptr [ebx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 0050e015  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 0050e017  39d6                   +cmp esi, edx
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
    // 0050e019  746b                   -je 0x50e086
    if (cpu.flags.zf)
    {
        goto L_0x0050e086;
    }
    // 0050e01b  89530c                 -mov dword ptr [ebx + 0xc], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.edx;
L_0x0050e01e:
    // 0050e01e  8b430c                 -mov eax, dword ptr [ebx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 0050e021  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0050e023  39ce                   +cmp esi, ecx
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
    // 0050e025  7437                   -je 0x50e05e
    if (cpu.flags.zf)
    {
        goto L_0x0050e05e;
    }
    // 0050e027  894b0c                 -mov dword ptr [ebx + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 0050e02a  ebf2                   -jmp 0x50e01e
    goto L_0x0050e01e;
L_0x0050e02c:
    // 0050e02c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0050e02d  bf20fc5400             -mov edi, 0x54fc20
    cpu.edi = 5569568 /*0x54fc20*/;
    // 0050e032  beb8fb5400             -mov esi, 0x54fbb8
    cpu.esi = 5569464 /*0x54fbb8*/;
    // 0050e037  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050e038  bd90010000             -mov ebp, 0x190
    cpu.ebp = 400 /*0x190*/;
    // 0050e03d  893590215500           -mov dword ptr [0x552190], esi
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.esi;
    // 0050e043  68ccfb5400             -push 0x54fbcc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5569484 /*0x54fbcc*/;
    cpu.esp -= 4;
    // 0050e048  893d94215500           -mov dword ptr [0x552194], edi
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.edi;
    // 0050e04e  892d98215500           -mov dword ptr [0x552198], ebp
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ebp;
    // 0050e054  e8b72fefff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 0050e059  83c40c                 +add esp, 0xc
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
    // 0050e05c  ebaa                   -jmp 0x50e008
    goto L_0x0050e008;
L_0x0050e05e:
    // 0050e05e  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
L_0x0050e064:
    // 0050e064  c70600000000           -mov dword ptr [esi], 0
    app->getMemory<x86::reg32>(cpu.esi) = 0 /*0x0*/;
L_0x0050e06a:
    // 0050e06a  8a6304                 -mov ah, byte ptr [ebx + 4]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0050e06d  8b7b18                 -mov edi, dword ptr [ebx + 0x18]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 0050e070  80cc01                 +or ah, 1
    cpu.clear_co();
    cpu.set_szp((cpu.ah |= x86::reg8(x86::sreg8(1 /*0x1*/))));
    // 0050e073  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050e074  886304                 -mov byte ptr [ebx + 4], ah
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.ah;
    // 0050e077  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050e07d  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0050e07f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e080  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e081  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e082  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e083  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e084  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e085  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050e086:
    // 0050e086  c7430800000000         -mov dword ptr [ebx + 8], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 0050e08d  8b4308                 -mov eax, dword ptr [ebx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 0050e090  89430c                 -mov dword ptr [ebx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0050e093  ebcf                   -jmp 0x50e064
    goto L_0x0050e064;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_50e0a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050e0a0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0050e0a1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050e0a2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050e0a3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0050e0a4  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0050e0a6  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0050e0a8  8b5018                 -mov edx, dword ptr [eax + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0050e0ab  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0050e0ac  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050e0b2  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0050e0b4  750f                   -jne 0x50e0c5
    if (!cpu.flags.zf)
    {
        goto L_0x0050e0c5;
    }
    // 0050e0b6  8b7318                 -mov esi, dword ptr [ebx + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 0050e0b9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050e0ba  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050e0c0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e0c1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e0c2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e0c3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e0c4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050e0c5:
    // 0050e0c5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050e0c6  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0050e0c8  8b5314                 -mov edx, dword ptr [ebx + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 0050e0cb  ff5310                 -call dword ptr [ebx + 0x10]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050e0ce  8b4b18                 -mov ecx, dword ptr [ebx + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 0050e0d1  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0050e0d3  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0050e0d5  752f                   -jne 0x50e106
    if (!cpu.flags.zf)
    {
        goto L_0x0050e106;
    }
    // 0050e0d7  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0050e0d8  b82cfc5400             -mov eax, 0x54fc2c
    cpu.eax = 5569580 /*0x54fc2c*/;
    // 0050e0dd  beb8fb5400             -mov esi, 0x54fbb8
    cpu.esi = 5569464 /*0x54fbb8*/;
    // 0050e0e2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0050e0e3  bad8010000             -mov edx, 0x1d8
    cpu.edx = 472 /*0x1d8*/;
    // 0050e0e8  893590215500           -mov dword ptr [0x552190], esi
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.esi;
    // 0050e0ee  68ccfb5400             -push 0x54fbcc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5569484 /*0x54fbcc*/;
    cpu.esp -= 4;
    // 0050e0f3  a394215500             -mov dword ptr [0x552194], eax
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.eax;
    // 0050e0f8  891598215500           -mov dword ptr [0x552198], edx
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.edx;
    // 0050e0fe  e80d2fefff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 0050e103  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
L_0x0050e106:
    // 0050e106  ff03                   -inc dword ptr [ebx]
    (app->getMemory<x86::reg32>(cpu.ebx))++;
    // 0050e108  8b4b08                 -mov ecx, dword ptr [ebx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 0050e10b  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0050e10d  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0050e10f  7414                   -je 0x50e125
    if (cpu.flags.zf)
    {
        goto L_0x0050e125;
    }
L_0x0050e111:
    // 0050e111  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0050e113  8b5314                 -mov edx, dword ptr [ebx + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 0050e116  ff5310                 -call dword ptr [ebx + 0x10]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050e119  39f8                   +cmp eax, edi
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
    // 0050e11b  7308                   -jae 0x50e125
    if (!cpu.flags.cf)
    {
        goto L_0x0050e125;
    }
    // 0050e11d  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0050e11f  8b09                   -mov ecx, dword ptr [ecx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx);
    // 0050e121  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0050e123  75ec                   -jne 0x50e111
    if (!cpu.flags.zf)
    {
        goto L_0x0050e111;
    }
L_0x0050e125:
    // 0050e125  894d00                 -mov dword ptr [ebp], ecx
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.ecx;
    // 0050e128  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0050e12a  751e                   -jne 0x50e14a
    if (!cpu.flags.zf)
    {
        goto L_0x0050e14a;
    }
    // 0050e12c  896b08                 -mov dword ptr [ebx + 8], ebp
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.ebp;
L_0x0050e12f:
    // 0050e12f  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0050e131  7503                   -jne 0x50e136
    if (!cpu.flags.zf)
    {
        goto L_0x0050e136;
    }
    // 0050e133  896b0c                 -mov dword ptr [ebx + 0xc], ebp
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.ebp;
L_0x0050e136:
    // 0050e136  804b0401               +or byte ptr [ebx + 4], 1
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/))));
    // 0050e13a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e13b  8b7318                 -mov esi, dword ptr [ebx + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 0050e13e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050e13f  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050e145  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e146  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e147  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e148  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e149  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050e14a:
    // 0050e14a  892e                   -mov dword ptr [esi], ebp
    app->getMemory<x86::reg32>(cpu.esi) = cpu.ebp;
    // 0050e14c  ebe1                   -jmp 0x50e12f
    goto L_0x0050e12f;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_50e150(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050e150  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0050e151  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050e152  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050e153  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050e154  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0050e155  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0050e157  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0050e159  8b5018                 -mov edx, dword ptr [eax + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0050e15c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0050e15d  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050e163  837b1800               +cmp dword ptr [ebx + 0x18], 0
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
    // 0050e167  7416                   -je 0x50e17f
    if (cpu.flags.zf)
    {
        goto L_0x0050e17f;
    }
L_0x0050e169:
    // 0050e169  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0050e16b  7543                   -jne 0x50e1b0
    if (!cpu.flags.zf)
    {
        goto L_0x0050e1b0;
    }
    // 0050e16d  8b4b18                 -mov ecx, dword ptr [ebx + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 0050e170  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050e171  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050e177  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0050e179  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e17a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e17b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e17c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e17d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e17e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050e17f:
    // 0050e17f  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0050e180  b834fc5400             -mov eax, 0x54fc34
    cpu.eax = 5569588 /*0x54fc34*/;
    // 0050e185  bdb8fb5400             -mov ebp, 0x54fbb8
    cpu.ebp = 5569464 /*0x54fbb8*/;
    // 0050e18a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0050e18b  ba1c020000             -mov edx, 0x21c
    cpu.edx = 540 /*0x21c*/;
    // 0050e190  892d90215500           -mov dword ptr [0x552190], ebp
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ebp;
    // 0050e196  68ccfb5400             -push 0x54fbcc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5569484 /*0x54fbcc*/;
    cpu.esp -= 4;
    // 0050e19b  a394215500             -mov dword ptr [0x552194], eax
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.eax;
    // 0050e1a0  891598215500           -mov dword ptr [0x552198], edx
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.edx;
    // 0050e1a6  e8652eefff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 0050e1ab  83c40c                 +add esp, 0xc
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
    // 0050e1ae  ebb9                   -jmp 0x50e169
    goto L_0x0050e169;
L_0x0050e1b0:
    // 0050e1b0  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0050e1b2  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0050e1b4  e867faffff             -call 0x50dc20
    cpu.esp -= 4;
    sub_50dc20(app, cpu);
    if (cpu.terminate) return;
    // 0050e1b9  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0050e1bb  8b4b18                 -mov ecx, dword ptr [ebx + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 0050e1be  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050e1bf  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050e1c5  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0050e1c7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e1c8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e1c9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e1ca  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e1cb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e1cc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_50e1d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050e1d0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0050e1d1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0050e1d3  83781800               +cmp dword ptr [eax + 0x18], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050e1d7  7404                   -je 0x50e1dd
    if (cpu.flags.zf)
    {
        goto L_0x0050e1dd;
    }
    // 0050e1d9  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 0050e1db  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e1dc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050e1dd:
    // 0050e1dd  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050e1de  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050e1df  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0050e1e0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0050e1e1  be3cfc5400             -mov esi, 0x54fc3c
    cpu.esi = 5569596 /*0x54fc3c*/;
    // 0050e1e6  bbb8fb5400             -mov ebx, 0x54fbb8
    cpu.ebx = 5569464 /*0x54fbb8*/;
    // 0050e1eb  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050e1ec  bf45020000             -mov edi, 0x245
    cpu.edi = 581 /*0x245*/;
    // 0050e1f1  891d90215500           -mov dword ptr [0x552190], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ebx;
    // 0050e1f7  68ccfb5400             -push 0x54fbcc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5569484 /*0x54fbcc*/;
    cpu.esp -= 4;
    // 0050e1fc  893594215500           -mov dword ptr [0x552194], esi
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.esi;
    // 0050e202  893d98215500           -mov dword ptr [0x552198], edi
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.edi;
    // 0050e208  e8032eefff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 0050e20d  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0050e210  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e211  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e212  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e213  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 0050e215  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e216  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_50e220(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050e220  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0050e221  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050e222  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050e223  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050e224  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0050e225  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0050e228  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0050e22a  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0050e22c  8b5018                 -mov edx, dword ptr [eax + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0050e22f  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0050e230  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050e236  8b4f18                 -mov ecx, dword ptr [edi + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */);
    // 0050e239  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0050e23b  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0050e23d  744d                   -je 0x50e28c
    if (cpu.flags.zf)
    {
        goto L_0x0050e28c;
    }
L_0x0050e23f:
    // 0050e23f  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0050e241  742f                   -je 0x50e272
    if (cpu.flags.zf)
    {
        goto L_0x0050e272;
    }
    // 0050e243  8b7710                 -mov esi, dword ptr [edi + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(16) /* 0x10 */);
    // 0050e246  8b4f08                 -mov ecx, dword ptr [edi + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 0050e249  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0050e24b  0f856c000000           -jne 0x50e2bd
    if (!cpu.flags.zf)
    {
        goto L_0x0050e2bd;
    }
    // 0050e251  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0050e253:
    // 0050e253  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0050e256  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0050e258  7414                   -je 0x50e26e
    if (cpu.flags.zf)
    {
        goto L_0x0050e26e;
    }
L_0x0050e25a:
    // 0050e25a  39e9                   +cmp ecx, ebp
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
    // 0050e25c  7410                   -je 0x50e26e
    if (cpu.flags.zf)
    {
        goto L_0x0050e26e;
    }
    // 0050e25e  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0050e260  7464                   -je 0x50e2c6
    if (cpu.flags.zf)
    {
        goto L_0x0050e2c6;
    }
    // 0050e262  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0050e264  8b5714                 -mov edx, dword ptr [edi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(20) /* 0x14 */);
    // 0050e267  ffd6                   -call esi
    cpu.ip = cpu.esi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050e269  3b0424                 +cmp eax, dword ptr [esp]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050e26c  7658                   -jbe 0x50e2c6
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0050e2c6;
    }
L_0x0050e26e:
    // 0050e26e  39e9                   +cmp ecx, ebp
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
    // 0050e270  7405                   -je 0x50e277
    if (cpu.flags.zf)
    {
        goto L_0x0050e277;
    }
L_0x0050e272:
    // 0050e272  bbffffffff             -mov ebx, 0xffffffff
    cpu.ebx = 4294967295 /*0xffffffff*/;
L_0x0050e277:
    // 0050e277  8b4f18                 -mov ecx, dword ptr [edi + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */);
    // 0050e27a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050e27b  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050e281  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0050e283  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0050e286  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e287  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e288  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e289  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e28a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e28b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050e28c:
    // 0050e28c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050e28d  b844fc5400             -mov eax, 0x54fc44
    cpu.eax = 5569604 /*0x54fc44*/;
    // 0050e292  beb8fb5400             -mov esi, 0x54fbb8
    cpu.esi = 5569464 /*0x54fbb8*/;
    // 0050e297  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0050e298  ba71020000             -mov edx, 0x271
    cpu.edx = 625 /*0x271*/;
    // 0050e29d  893590215500           -mov dword ptr [0x552190], esi
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.esi;
    // 0050e2a3  68ccfb5400             -push 0x54fbcc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5569484 /*0x54fbcc*/;
    cpu.esp -= 4;
    // 0050e2a8  a394215500             -mov dword ptr [0x552194], eax
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.eax;
    // 0050e2ad  891598215500           -mov dword ptr [0x552198], edx
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.edx;
    // 0050e2b3  e8582defff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 0050e2b8  83c40c                 +add esp, 0xc
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
    // 0050e2bb  eb82                   -jmp 0x50e23f
    goto L_0x0050e23f;
L_0x0050e2bd:
    // 0050e2bd  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0050e2bf  8b5714                 -mov edx, dword ptr [edi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(20) /* 0x14 */);
    // 0050e2c2  ffd6                   -call esi
    cpu.ip = cpu.esi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050e2c4  eb8d                   -jmp 0x50e253
    goto L_0x0050e253;
L_0x0050e2c6:
    // 0050e2c6  8b09                   -mov ecx, dword ptr [ecx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx);
    // 0050e2c8  43                     -inc ebx
    (cpu.ebx)++;
    // 0050e2c9  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0050e2cb  758d                   -jne 0x50e25a
    if (!cpu.flags.zf)
    {
        goto L_0x0050e25a;
    }
    // 0050e2cd  eb9f                   -jmp 0x50e26e
    goto L_0x0050e26e;
}

/* align: skip 0x90 */
void Application::sub_50e2d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050e2d0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0050e2d1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050e2d2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0050e2d3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050e2d4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0050e2d5  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0050e2d7  8b5018                 -mov edx, dword ptr [eax + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0050e2da  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0050e2db  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050e2e1  8b4b18                 -mov ecx, dword ptr [ebx + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 0050e2e4  beffffffff             -mov esi, 0xffffffff
    cpu.esi = 4294967295 /*0xffffffff*/;
    // 0050e2e9  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0050e2eb  7418                   -je 0x50e305
    if (cpu.flags.zf)
    {
        goto L_0x0050e305;
    }
L_0x0050e2ed:
    // 0050e2ed  837b0800               +cmp dword ptr [ebx + 8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050e2f1  7545                   -jne 0x50e338
    if (!cpu.flags.zf)
    {
        goto L_0x0050e338;
    }
    // 0050e2f3  8b4b18                 -mov ecx, dword ptr [ebx + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 0050e2f6  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050e2f7  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050e2fd  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0050e2ff  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e300  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e301  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e302  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e303  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e304  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050e305:
    // 0050e305  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050e306  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0050e307  bd50fc5400             -mov ebp, 0x54fc50
    cpu.ebp = 5569616 /*0x54fc50*/;
    // 0050e30c  bfb8fb5400             -mov edi, 0x54fbb8
    cpu.edi = 5569464 /*0x54fbb8*/;
    // 0050e311  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0050e312  b8b9020000             -mov eax, 0x2b9
    cpu.eax = 697 /*0x2b9*/;
    // 0050e317  893d90215500           -mov dword ptr [0x552190], edi
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edi;
    // 0050e31d  68ccfb5400             -push 0x54fbcc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5569484 /*0x54fbcc*/;
    cpu.esp -= 4;
    // 0050e322  892d94215500           -mov dword ptr [0x552194], ebp
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebp;
    // 0050e328  a398215500             -mov dword ptr [0x552198], eax
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.eax;
    // 0050e32d  e8de2cefff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 0050e332  83c40c                 +add esp, 0xc
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
    // 0050e335  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e336  ebb5                   -jmp 0x50e2ed
    goto L_0x0050e2ed;
L_0x0050e338:
    // 0050e338  8b5314                 -mov edx, dword ptr [ebx + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 0050e33b  8b4308                 -mov eax, dword ptr [ebx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 0050e33e  ff5310                 -call dword ptr [ebx + 0x10]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050e341  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0050e343  8b4b18                 -mov ecx, dword ptr [ebx + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 0050e346  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050e347  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050e34d  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0050e34f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e350  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e351  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e352  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e353  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e354  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_50e360(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050e360  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0050e361  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050e362  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0050e363  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050e364  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0050e365  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0050e367  8b5018                 -mov edx, dword ptr [eax + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0050e36a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0050e36b  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050e371  8b4b18                 -mov ecx, dword ptr [ebx + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 0050e374  beffffffff             -mov esi, 0xffffffff
    cpu.esi = 4294967295 /*0xffffffff*/;
    // 0050e379  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0050e37b  7418                   -je 0x50e395
    if (cpu.flags.zf)
    {
        goto L_0x0050e395;
    }
L_0x0050e37d:
    // 0050e37d  837b0800               +cmp dword ptr [ebx + 8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050e381  7545                   -jne 0x50e3c8
    if (!cpu.flags.zf)
    {
        goto L_0x0050e3c8;
    }
    // 0050e383  8b4b18                 -mov ecx, dword ptr [ebx + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 0050e386  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050e387  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050e38d  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0050e38f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e390  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e391  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e392  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e393  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e394  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050e395:
    // 0050e395  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050e396  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0050e397  bd60fc5400             -mov ebp, 0x54fc60
    cpu.ebp = 5569632 /*0x54fc60*/;
    // 0050e39c  bfb8fb5400             -mov edi, 0x54fbb8
    cpu.edi = 5569464 /*0x54fbb8*/;
    // 0050e3a1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0050e3a2  b8c4020000             -mov eax, 0x2c4
    cpu.eax = 708 /*0x2c4*/;
    // 0050e3a7  893d90215500           -mov dword ptr [0x552190], edi
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edi;
    // 0050e3ad  68ccfb5400             -push 0x54fbcc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5569484 /*0x54fbcc*/;
    cpu.esp -= 4;
    // 0050e3b2  892d94215500           -mov dword ptr [0x552194], ebp
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebp;
    // 0050e3b8  a398215500             -mov dword ptr [0x552198], eax
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.eax;
    // 0050e3bd  e84e2cefff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 0050e3c2  83c40c                 +add esp, 0xc
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
    // 0050e3c5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e3c6  ebb5                   -jmp 0x50e37d
    goto L_0x0050e37d;
L_0x0050e3c8:
    // 0050e3c8  8b5314                 -mov edx, dword ptr [ebx + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 0050e3cb  8b4308                 -mov eax, dword ptr [ebx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 0050e3ce  ff5310                 -call dword ptr [ebx + 0x10]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050e3d1  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0050e3d3  8b4b18                 -mov ecx, dword ptr [ebx + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 0050e3d6  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050e3d7  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050e3dd  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0050e3df  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e3e0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e3e1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e3e2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e3e3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e3e4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_50e3f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050e3f0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050e3f1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050e3f2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050e3f3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0050e3f4  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0050e3f6  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0050e3f8  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 0050e3fa  8b5018                 -mov edx, dword ptr [eax + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0050e3fd  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0050e3fe  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050e404  837d1800               +cmp dword ptr [ebp + 0x18], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050e408  742c                   -je 0x50e436
    if (cpu.flags.zf)
    {
        goto L_0x0050e436;
    }
L_0x0050e40a:
    // 0050e40a  8b5d08                 -mov ebx, dword ptr [ebp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0050e40d  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0050e40f  7414                   -je 0x50e425
    if (cpu.flags.zf)
    {
        goto L_0x0050e425;
    }
L_0x0050e411:
    // 0050e411  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0050e413  7410                   -je 0x50e425
    if (cpu.flags.zf)
    {
        goto L_0x0050e425;
    }
    // 0050e415  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0050e417  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0050e419  ffd7                   -call edi
    cpu.ip = cpu.edi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050e41b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0050e41d  7506                   -jne 0x50e425
    if (!cpu.flags.zf)
    {
        goto L_0x0050e425;
    }
    // 0050e41f  8b1b                   -mov ebx, dword ptr [ebx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx);
    // 0050e421  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0050e423  75ec                   -jne 0x50e411
    if (!cpu.flags.zf)
    {
        goto L_0x0050e411;
    }
L_0x0050e425:
    // 0050e425  8b4d18                 -mov ecx, dword ptr [ebp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 0050e428  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050e429  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050e42f  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0050e431  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e432  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e433  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e434  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e435  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050e436:
    // 0050e436  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0050e437  b870fc5400             -mov eax, 0x54fc70
    cpu.eax = 5569648 /*0x54fc70*/;
    // 0050e43c  bbb8fb5400             -mov ebx, 0x54fbb8
    cpu.ebx = 5569464 /*0x54fbb8*/;
    // 0050e441  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0050e442  ba03030000             -mov edx, 0x303
    cpu.edx = 771 /*0x303*/;
    // 0050e447  891d90215500           -mov dword ptr [0x552190], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ebx;
    // 0050e44d  68ccfb5400             -push 0x54fbcc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5569484 /*0x54fbcc*/;
    cpu.esp -= 4;
    // 0050e452  a394215500             -mov dword ptr [0x552194], eax
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.eax;
    // 0050e457  891598215500           -mov dword ptr [0x552198], edx
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.edx;
    // 0050e45d  e8ae2befff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 0050e462  83c40c                 +add esp, 0xc
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
    // 0050e465  eba3                   -jmp 0x50e40a
    goto L_0x0050e40a;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_50e470(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050e470  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0050e471  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050e472  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050e473  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0050e474  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0050e476  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0050e478  8b5018                 -mov edx, dword ptr [eax + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0050e47b  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0050e47c  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050e482  837b1800               +cmp dword ptr [ebx + 0x18], 0
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
    // 0050e486  741e                   -je 0x50e4a6
    if (cpu.flags.zf)
    {
        goto L_0x0050e4a6;
    }
L_0x0050e488:
    // 0050e488  8b5308                 -mov edx, dword ptr [ebx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 0050e48b  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0050e48d  7459                   -je 0x50e4e8
    if (cpu.flags.zf)
    {
        goto L_0x0050e4e8;
    }
    // 0050e48f  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0050e491  7746                   -ja 0x50e4d9
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0050e4d9;
    }
    // 0050e493  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
L_0x0050e495:
    // 0050e495  8b4b18                 -mov ecx, dword ptr [ebx + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 0050e498  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050e499  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050e49f  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0050e4a1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e4a2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e4a3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e4a4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e4a5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050e4a6:
    // 0050e4a6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050e4a7  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0050e4a8  bd78fc5400             -mov ebp, 0x54fc78
    cpu.ebp = 5569656 /*0x54fc78*/;
    // 0050e4ad  bfb8fb5400             -mov edi, 0x54fbb8
    cpu.edi = 5569464 /*0x54fbb8*/;
    // 0050e4b2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0050e4b3  b80f030000             -mov eax, 0x30f
    cpu.eax = 783 /*0x30f*/;
    // 0050e4b8  893d90215500           -mov dword ptr [0x552190], edi
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edi;
    // 0050e4be  68ccfb5400             -push 0x54fbcc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5569484 /*0x54fbcc*/;
    cpu.esp -= 4;
    // 0050e4c3  892d94215500           -mov dword ptr [0x552194], ebp
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebp;
    // 0050e4c9  a398215500             -mov dword ptr [0x552198], eax
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.eax;
    // 0050e4ce  e83d2befff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 0050e4d3  83c40c                 +add esp, 0xc
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
    // 0050e4d6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e4d7  ebaf                   -jmp 0x50e488
    goto L_0x0050e488;
L_0x0050e4d9:
    // 0050e4d9  8d56ff                 -lea edx, [esi - 1]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(-1) /* -0x1 */);
    // 0050e4dc  8b4308                 -mov eax, dword ptr [ebx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 0050e4df  e81cf7ffff             -call 0x50dc00
    cpu.esp -= 4;
    sub_50dc00(app, cpu);
    if (cpu.terminate) return;
    // 0050e4e4  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0050e4e6  ebad                   -jmp 0x50e495
    goto L_0x0050e495;
L_0x0050e4e8:
    // 0050e4e8  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0050e4ea  8b4b18                 -mov ecx, dword ptr [ebx + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 0050e4ed  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050e4ee  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050e4f4  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0050e4f6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e4f7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e4f8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e4f9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e4fa  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_50e500(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050e500  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0050e501  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050e502  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050e503  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050e504  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0050e505  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0050e507  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0050e509  8b5018                 -mov edx, dword ptr [eax + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0050e50c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0050e50d  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050e513  837e1800               +cmp dword ptr [esi + 0x18], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050e517  742f                   -je 0x50e548
    if (cpu.flags.zf)
    {
        goto L_0x0050e548;
    }
L_0x0050e519:
    // 0050e519  8b5e08                 -mov ebx, dword ptr [esi + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0050e51c  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0050e51e  7412                   -je 0x50e532
    if (cpu.flags.zf)
    {
        goto L_0x0050e532;
    }
L_0x0050e520:
    // 0050e520  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0050e522  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0050e525  ff5610                 -call dword ptr [esi + 0x10]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050e528  39f8                   +cmp eax, edi
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
    // 0050e52a  7306                   -jae 0x50e532
    if (!cpu.flags.cf)
    {
        goto L_0x0050e532;
    }
    // 0050e52c  8b1b                   -mov ebx, dword ptr [ebx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx);
    // 0050e52e  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0050e530  75ee                   -jne 0x50e520
    if (!cpu.flags.zf)
    {
        goto L_0x0050e520;
    }
L_0x0050e532:
    // 0050e532  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0050e534  7543                   -jne 0x50e579
    if (!cpu.flags.zf)
    {
        goto L_0x0050e579;
    }
L_0x0050e536:
    // 0050e536  8b5618                 -mov edx, dword ptr [esi + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 0050e539  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0050e53a  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050e540  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0050e542  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e543  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e544  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e545  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e546  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e547  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050e548:
    // 0050e548  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050e549  bd84fc5400             -mov ebp, 0x54fc84
    cpu.ebp = 5569668 /*0x54fc84*/;
    // 0050e54e  bbb8fb5400             -mov ebx, 0x54fbb8
    cpu.ebx = 5569464 /*0x54fbb8*/;
    // 0050e553  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0050e554  b821030000             -mov eax, 0x321
    cpu.eax = 801 /*0x321*/;
    // 0050e559  891d90215500           -mov dword ptr [0x552190], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ebx;
    // 0050e55f  68ccfb5400             -push 0x54fbcc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5569484 /*0x54fbcc*/;
    cpu.esp -= 4;
    // 0050e564  892d94215500           -mov dword ptr [0x552194], ebp
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebp;
    // 0050e56a  a398215500             -mov dword ptr [0x552198], eax
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.eax;
    // 0050e56f  e89c2aefff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 0050e574  83c40c                 +add esp, 0xc
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
    // 0050e577  eba0                   -jmp 0x50e519
    goto L_0x0050e519;
L_0x0050e579:
    // 0050e579  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0050e57b  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0050e57e  ff5610                 -call dword ptr [esi + 0x10]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050e581  39f8                   +cmp eax, edi
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
    // 0050e583  74b1                   -je 0x50e536
    if (cpu.flags.zf)
    {
        goto L_0x0050e536;
    }
    // 0050e585  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0050e587  8b5618                 -mov edx, dword ptr [esi + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 0050e58a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0050e58b  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050e591  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0050e593  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e594  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e595  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e596  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e597  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e598  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_50e5a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050e5a0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050e5a1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050e5a2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050e5a3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0050e5a4  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0050e5a6  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0050e5a8  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0050e5aa  8b5018                 -mov edx, dword ptr [eax + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0050e5ad  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0050e5ae  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050e5b4  837d1800               +cmp dword ptr [ebp + 0x18], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050e5b8  7430                   -je 0x50e5ea
    if (cpu.flags.zf)
    {
        goto L_0x0050e5ea;
    }
L_0x0050e5ba:
    // 0050e5ba  8b5d08                 -mov ebx, dword ptr [ebp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0050e5bd  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0050e5bf  7414                   -je 0x50e5d5
    if (cpu.flags.zf)
    {
        goto L_0x0050e5d5;
    }
L_0x0050e5c1:
    // 0050e5c1  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0050e5c3  7410                   -je 0x50e5d5
    if (cpu.flags.zf)
    {
        goto L_0x0050e5d5;
    }
    // 0050e5c5  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0050e5c7  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0050e5c9  ffd6                   -call esi
    cpu.ip = cpu.esi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050e5cb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0050e5cd  7506                   -jne 0x50e5d5
    if (!cpu.flags.zf)
    {
        goto L_0x0050e5d5;
    }
    // 0050e5cf  8b1b                   -mov ebx, dword ptr [ebx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx);
    // 0050e5d1  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0050e5d3  75ec                   -jne 0x50e5c1
    if (!cpu.flags.zf)
    {
        goto L_0x0050e5c1;
    }
L_0x0050e5d5:
    // 0050e5d5  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0050e5d7  7542                   -jne 0x50e61b
    if (!cpu.flags.zf)
    {
        goto L_0x0050e61b;
    }
L_0x0050e5d9:
    // 0050e5d9  8b7d18                 -mov edi, dword ptr [ebp + 0x18]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 0050e5dc  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050e5dd  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050e5e3  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0050e5e5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e5e6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e5e7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e5e8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e5e9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050e5ea:
    // 0050e5ea  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0050e5eb  b894fc5400             -mov eax, 0x54fc94
    cpu.eax = 5569684 /*0x54fc94*/;
    // 0050e5f0  bbb8fb5400             -mov ebx, 0x54fbb8
    cpu.ebx = 5569464 /*0x54fbb8*/;
    // 0050e5f5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0050e5f6  ba6a030000             -mov edx, 0x36a
    cpu.edx = 874 /*0x36a*/;
    // 0050e5fb  891d90215500           -mov dword ptr [0x552190], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ebx;
    // 0050e601  68ccfb5400             -push 0x54fbcc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5569484 /*0x54fbcc*/;
    cpu.esp -= 4;
    // 0050e606  a394215500             -mov dword ptr [0x552194], eax
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.eax;
    // 0050e60b  891598215500           -mov dword ptr [0x552198], edx
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.edx;
    // 0050e611  e8fa29efff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 0050e616  83c40c                 +add esp, 0xc
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
    // 0050e619  eb9f                   -jmp 0x50e5ba
    goto L_0x0050e5ba;
L_0x0050e61b:
    // 0050e61b  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0050e61d  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0050e61f  e8fcf5ffff             -call 0x50dc20
    cpu.esp -= 4;
    sub_50dc20(app, cpu);
    if (cpu.terminate) return;
    // 0050e624  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0050e626  75b1                   -jne 0x50e5d9
    if (!cpu.flags.zf)
    {
        goto L_0x0050e5d9;
    }
    // 0050e628  b9b8fb5400             -mov ecx, 0x54fbb8
    cpu.ecx = 5569464 /*0x54fbb8*/;
    // 0050e62d  bb94fc5400             -mov ebx, 0x54fc94
    cpu.ebx = 5569684 /*0x54fc94*/;
    // 0050e632  be73030000             -mov esi, 0x373
    cpu.esi = 883 /*0x373*/;
    // 0050e637  689cfc5400             -push 0x54fc9c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5569692 /*0x54fc9c*/;
    cpu.esp -= 4;
    // 0050e63c  890d90215500           -mov dword ptr [0x552190], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ecx;
    // 0050e642  891d94215500           -mov dword ptr [0x552194], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebx;
    // 0050e648  893598215500           -mov dword ptr [0x552198], esi
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.esi;
    // 0050e64e  e8bd29efff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 0050e653  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0050e656  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0050e658  8b7d18                 -mov edi, dword ptr [ebp + 0x18]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 0050e65b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050e65c  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050e662  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0050e664  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e665  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e666  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e667  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e668  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_50e670(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050e670  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0050e671  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050e672  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050e673  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050e674  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0050e675  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0050e677  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0050e679  8b5018                 -mov edx, dword ptr [eax + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0050e67c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0050e67d  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050e683  837b1800               +cmp dword ptr [ebx + 0x18], 0
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
    // 0050e687  7427                   -je 0x50e6b0
    if (cpu.flags.zf)
    {
        goto L_0x0050e6b0;
    }
L_0x0050e689:
    // 0050e689  8b5308                 -mov edx, dword ptr [ebx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 0050e68c  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0050e68e  0f8497000000           -je 0x50e72b
    if (cpu.flags.zf)
    {
        goto L_0x0050e72b;
    }
    // 0050e694  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0050e696  7749                   -ja 0x50e6e1
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0050e6e1;
    }
    // 0050e698  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
L_0x0050e69a:
    // 0050e69a  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0050e69c  7552                   -jne 0x50e6f0
    if (!cpu.flags.zf)
    {
        goto L_0x0050e6f0;
    }
L_0x0050e69e:
    // 0050e69e  8b6b18                 -mov ebp, dword ptr [ebx + 0x18]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 0050e6a1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0050e6a2  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050e6a8  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0050e6aa  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e6ab  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e6ac  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e6ad  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e6ae  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e6af  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050e6b0:
    // 0050e6b0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0050e6b1  bdd0fc5400             -mov ebp, 0x54fcd0
    cpu.ebp = 5569744 /*0x54fcd0*/;
    // 0050e6b6  bfb8fb5400             -mov edi, 0x54fbb8
    cpu.edi = 5569464 /*0x54fbb8*/;
    // 0050e6bb  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0050e6bc  b87f030000             -mov eax, 0x37f
    cpu.eax = 895 /*0x37f*/;
    // 0050e6c1  893d90215500           -mov dword ptr [0x552190], edi
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edi;
    // 0050e6c7  68ccfb5400             -push 0x54fbcc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5569484 /*0x54fbcc*/;
    cpu.esp -= 4;
    // 0050e6cc  892d94215500           -mov dword ptr [0x552194], ebp
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebp;
    // 0050e6d2  a398215500             -mov dword ptr [0x552198], eax
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.eax;
    // 0050e6d7  e83429efff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 0050e6dc  83c40c                 +add esp, 0xc
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
    // 0050e6df  eba8                   -jmp 0x50e689
    goto L_0x0050e689;
L_0x0050e6e1:
    // 0050e6e1  8d56ff                 -lea edx, [esi - 1]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(-1) /* -0x1 */);
    // 0050e6e4  8b4308                 -mov eax, dword ptr [ebx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 0050e6e7  e814f5ffff             -call 0x50dc00
    cpu.esp -= 4;
    sub_50dc00(app, cpu);
    if (cpu.terminate) return;
    // 0050e6ec  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0050e6ee  ebaa                   -jmp 0x50e69a
    goto L_0x0050e69a;
L_0x0050e6f0:
    // 0050e6f0  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0050e6f2  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0050e6f4  e827f5ffff             -call 0x50dc20
    cpu.esp -= 4;
    sub_50dc20(app, cpu);
    if (cpu.terminate) return;
    // 0050e6f9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0050e6fb  75a1                   -jne 0x50e69e
    if (!cpu.flags.zf)
    {
        goto L_0x0050e69e;
    }
    // 0050e6fd  b9b8fb5400             -mov ecx, 0x54fbb8
    cpu.ecx = 5569464 /*0x54fbb8*/;
    // 0050e702  bed0fc5400             -mov esi, 0x54fcd0
    cpu.esi = 5569744 /*0x54fcd0*/;
    // 0050e707  bf8b030000             -mov edi, 0x38b
    cpu.edi = 907 /*0x38b*/;
    // 0050e70c  68dcfc5400             -push 0x54fcdc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5569756 /*0x54fcdc*/;
    cpu.esp -= 4;
    // 0050e711  890d90215500           -mov dword ptr [0x552190], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ecx;
    // 0050e717  893594215500           -mov dword ptr [0x552194], esi
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.esi;
    // 0050e71d  893d98215500           -mov dword ptr [0x552198], edi
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.edi;
    // 0050e723  e8e828efff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 0050e728  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0050e72b:
    // 0050e72b  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0050e72d  8b6b18                 -mov ebp, dword ptr [ebx + 0x18]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 0050e730  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0050e731  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050e737  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0050e739  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e73a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e73b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e73c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e73d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e73e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_50e740(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050e740  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050e741  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050e742  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050e743  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0050e744  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0050e746  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0050e748  8b5018                 -mov edx, dword ptr [eax + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0050e74b  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0050e74c  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050e752  837e1800               +cmp dword ptr [esi + 0x18], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050e756  752f                   -jne 0x50e787
    if (!cpu.flags.zf)
    {
        goto L_0x0050e787;
    }
    // 0050e758  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050e759  b814fd5400             -mov eax, 0x54fd14
    cpu.eax = 5569812 /*0x54fd14*/;
    // 0050e75e  bdb8fb5400             -mov ebp, 0x54fbb8
    cpu.ebp = 5569464 /*0x54fbb8*/;
    // 0050e763  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0050e764  ba9a030000             -mov edx, 0x39a
    cpu.edx = 922 /*0x39a*/;
    // 0050e769  892d90215500           -mov dword ptr [0x552190], ebp
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ebp;
    // 0050e76f  68ccfb5400             -push 0x54fbcc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5569484 /*0x54fbcc*/;
    cpu.esp -= 4;
    // 0050e774  a394215500             -mov dword ptr [0x552194], eax
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.eax;
    // 0050e779  891598215500           -mov dword ptr [0x552198], edx
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.edx;
    // 0050e77f  e88c28efff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 0050e784  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
L_0x0050e787:
    // 0050e787  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0050e789  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0050e78b  e870f4ffff             -call 0x50dc00
    cpu.esp -= 4;
    sub_50dc00(app, cpu);
    if (cpu.terminate) return;
    // 0050e790  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0050e792  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0050e794  7511                   -jne 0x50e7a7
    if (!cpu.flags.zf)
    {
        goto L_0x0050e7a7;
    }
L_0x0050e796:
    // 0050e796  8b6e18                 -mov ebp, dword ptr [esi + 0x18]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 0050e799  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0050e79a  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050e7a0  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0050e7a2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e7a3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e7a4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e7a5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e7a6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050e7a7:
    // 0050e7a7  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0050e7a9  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0050e7ab  e870f4ffff             -call 0x50dc20
    cpu.esp -= 4;
    sub_50dc20(app, cpu);
    if (cpu.terminate) return;
    // 0050e7b0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0050e7b2  75e2                   -jne 0x50e796
    if (!cpu.flags.zf)
    {
        goto L_0x0050e796;
    }
    // 0050e7b4  b9b8fb5400             -mov ecx, 0x54fbb8
    cpu.ecx = 5569464 /*0x54fbb8*/;
    // 0050e7b9  bb14fd5400             -mov ebx, 0x54fd14
    cpu.ebx = 5569812 /*0x54fd14*/;
    // 0050e7be  bfa0030000             -mov edi, 0x3a0
    cpu.edi = 928 /*0x3a0*/;
    // 0050e7c3  6820fd5400             -push 0x54fd20
    app->getMemory<x86::reg32>(cpu.esp-4) = 5569824 /*0x54fd20*/;
    cpu.esp -= 4;
    // 0050e7c8  890d90215500           -mov dword ptr [0x552190], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ecx;
    // 0050e7ce  891d94215500           -mov dword ptr [0x552194], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebx;
    // 0050e7d4  893d98215500           -mov dword ptr [0x552198], edi
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.edi;
    // 0050e7da  e83128efff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 0050e7df  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0050e7e2  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0050e7e4  8b6e18                 -mov ebp, dword ptr [esi + 0x18]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 0050e7e7  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0050e7e8  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050e7ee  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0050e7f0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e7f1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e7f2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e7f3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e7f4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_50e800(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050e800  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0050e801  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050e802  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050e803  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050e804  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0050e805  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0050e807  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0050e809  8b5018                 -mov edx, dword ptr [eax + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0050e80c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0050e80d  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050e813  837e1800               +cmp dword ptr [esi + 0x18], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050e817  7431                   -je 0x50e84a
    if (cpu.flags.zf)
    {
        goto L_0x0050e84a;
    }
L_0x0050e819:
    // 0050e819  8b5e08                 -mov ebx, dword ptr [esi + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0050e81c  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0050e81e  7412                   -je 0x50e832
    if (cpu.flags.zf)
    {
        goto L_0x0050e832;
    }
L_0x0050e820:
    // 0050e820  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0050e822  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0050e825  ff5610                 -call dword ptr [esi + 0x10]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050e828  39f8                   +cmp eax, edi
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
    // 0050e82a  7306                   -jae 0x50e832
    if (!cpu.flags.cf)
    {
        goto L_0x0050e832;
    }
    // 0050e82c  8b1b                   -mov ebx, dword ptr [ebx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx);
    // 0050e82e  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0050e830  75ee                   -jne 0x50e820
    if (!cpu.flags.zf)
    {
        goto L_0x0050e820;
    }
L_0x0050e832:
    // 0050e832  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0050e834  7545                   -jne 0x50e87b
    if (!cpu.flags.zf)
    {
        goto L_0x0050e87b;
    }
L_0x0050e836:
    // 0050e836  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x0050e838:
    // 0050e838  8b7e18                 -mov edi, dword ptr [esi + 0x18]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 0050e83b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050e83c  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050e842  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0050e844  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e845  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e846  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e847  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e848  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e849  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050e84a:
    // 0050e84a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050e84b  bd58fd5400             -mov ebp, 0x54fd58
    cpu.ebp = 5569880 /*0x54fd58*/;
    // 0050e850  bbb8fb5400             -mov ebx, 0x54fbb8
    cpu.ebx = 5569464 /*0x54fbb8*/;
    // 0050e855  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0050e856  b8ac030000             -mov eax, 0x3ac
    cpu.eax = 940 /*0x3ac*/;
    // 0050e85b  891d90215500           -mov dword ptr [0x552190], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ebx;
    // 0050e861  68ccfb5400             -push 0x54fbcc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5569484 /*0x54fbcc*/;
    cpu.esp -= 4;
    // 0050e866  892d94215500           -mov dword ptr [0x552194], ebp
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebp;
    // 0050e86c  a398215500             -mov dword ptr [0x552198], eax
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.eax;
    // 0050e871  e89a27efff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 0050e876  83c40c                 +add esp, 0xc
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
    // 0050e879  eb9e                   -jmp 0x50e819
    goto L_0x0050e819;
L_0x0050e87b:
    // 0050e87b  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0050e87d  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0050e880  ff5610                 -call dword ptr [esi + 0x10]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050e883  39f8                   +cmp eax, edi
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
    // 0050e885  75af                   -jne 0x50e836
    if (!cpu.flags.zf)
    {
        goto L_0x0050e836;
    }
    // 0050e887  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0050e889  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0050e88b  e890f3ffff             -call 0x50dc20
    cpu.esp -= 4;
    sub_50dc20(app, cpu);
    if (cpu.terminate) return;
    // 0050e890  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0050e892  75a4                   -jne 0x50e838
    if (!cpu.flags.zf)
    {
        goto L_0x0050e838;
    }
    // 0050e894  bab8fb5400             -mov edx, 0x54fbb8
    cpu.edx = 5569464 /*0x54fbb8*/;
    // 0050e899  b958fd5400             -mov ecx, 0x54fd58
    cpu.ecx = 5569880 /*0x54fd58*/;
    // 0050e89e  bbb5030000             -mov ebx, 0x3b5
    cpu.ebx = 949 /*0x3b5*/;
    // 0050e8a3  6868fd5400             -push 0x54fd68
    app->getMemory<x86::reg32>(cpu.esp-4) = 5569896 /*0x54fd68*/;
    cpu.esp -= 4;
    // 0050e8a8  891590215500           -mov dword ptr [0x552190], edx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edx;
    // 0050e8ae  890d94215500           -mov dword ptr [0x552194], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ecx;
    // 0050e8b4  891d98215500           -mov dword ptr [0x552198], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ebx;
    // 0050e8ba  e85127efff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 0050e8bf  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0050e8c2  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0050e8c4  8b7e18                 -mov edi, dword ptr [esi + 0x18]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 0050e8c7  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050e8c8  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050e8ce  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0050e8d0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e8d1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e8d2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e8d3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e8d4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e8d5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void Application::sub_50e8e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050e8e0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050e8e1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050e8e2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050e8e3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0050e8e4  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0050e8e7  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0050e8e9  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0050e8eb  8b5018                 -mov edx, dword ptr [eax + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0050e8ee  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0050e8ef  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050e8f5  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0050e8f8  83e001                 -and eax, 1
    cpu.eax &= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 0050e8fb  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0050e8fe  8a6604                 -mov ah, byte ptr [esi + 4]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0050e901  8b4e18                 -mov ecx, dword ptr [esi + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 0050e904  80e4fe                 -and ah, 0xfe
    cpu.ah &= x86::reg8(x86::sreg8(254 /*0xfe*/));
    // 0050e907  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050e908  886604                 -mov byte ptr [esi + 4], ah
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.ah;
    // 0050e90b  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050e911  8b4618                 -mov eax, dword ptr [esi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 0050e914  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0050e916  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0050e918  7458                   -je 0x50e972
    if (cpu.flags.zf)
    {
        goto L_0x0050e972;
    }
L_0x0050e91a:
    // 0050e91a  8b4e08                 -mov ecx, dword ptr [esi + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0050e91d  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0050e91f  7422                   -je 0x50e943
    if (cpu.flags.zf)
    {
        goto L_0x0050e943;
    }
L_0x0050e921:
    // 0050e921  8a5604                 -mov dl, byte ptr [esi + 4]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0050e924  f6c201                 +test dl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 1 /*0x1*/));
    // 0050e927  751a                   -jne 0x50e943
    if (!cpu.flags.zf)
    {
        goto L_0x0050e943;
    }
    // 0050e929  f6c201                 +test dl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 1 /*0x1*/));
    // 0050e92c  750f                   -jne 0x50e93d
    if (!cpu.flags.zf)
    {
        goto L_0x0050e93d;
    }
    // 0050e92e  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0050e930  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0050e932  ffd5                   -call ebp
    cpu.ip = cpu.ebp;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050e934  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0050e936  7504                   -jne 0x50e93c
    if (!cpu.flags.zf)
    {
        goto L_0x0050e93c;
    }
    // 0050e938  804e0401               -or byte ptr [esi + 4], 1
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x0050e93c:
    // 0050e93c  47                     -inc edi
    (cpu.edi)++;
L_0x0050e93d:
    // 0050e93d  8b09                   -mov ecx, dword ptr [ecx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx);
    // 0050e93f  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0050e941  75de                   -jne 0x50e921
    if (!cpu.flags.zf)
    {
        goto L_0x0050e921;
    }
L_0x0050e943:
    // 0050e943  8b5618                 -mov edx, dword ptr [esi + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 0050e946  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0050e947  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050e94d  f6460401               +test byte ptr [esi + 4], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(4) /* 0x4 */) & 1 /*0x1*/));
    // 0050e951  7453                   -je 0x50e9a6
    if (cpu.flags.zf)
    {
        goto L_0x0050e9a6;
    }
L_0x0050e953:
    // 0050e953  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0050e956  8b4e04                 -mov ecx, dword ptr [esi + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0050e959  8b5e18                 -mov ebx, dword ptr [esi + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 0050e95c  09c1                   -or ecx, eax
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.eax));
    // 0050e95e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0050e95f  894e04                 -mov dword ptr [esi + 4], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 0050e962  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050e968  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0050e96a  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0050e96d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e96e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e96f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e970  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e971  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050e972:
    // 0050e972  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050e973  b9a4fd5400             -mov ecx, 0x54fda4
    cpu.ecx = 5569956 /*0x54fda4*/;
    // 0050e978  bab8fb5400             -mov edx, 0x54fbb8
    cpu.edx = 5569464 /*0x54fbb8*/;
    // 0050e97d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050e97e  b8f6030000             -mov eax, 0x3f6
    cpu.eax = 1014 /*0x3f6*/;
    // 0050e983  891590215500           -mov dword ptr [0x552190], edx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edx;
    // 0050e989  68ccfb5400             -push 0x54fbcc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5569484 /*0x54fbcc*/;
    cpu.esp -= 4;
    // 0050e98e  890d94215500           -mov dword ptr [0x552194], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ecx;
    // 0050e994  a398215500             -mov dword ptr [0x552198], eax
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.eax;
    // 0050e999  e87226efff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 0050e99e  83c40c                 +add esp, 0xc
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
    // 0050e9a1  e974ffffff             -jmp 0x50e91a
    goto L_0x0050e91a;
L_0x0050e9a6:
    // 0050e9a6  bfffffffff             -mov edi, 0xffffffff
    cpu.edi = 4294967295 /*0xffffffff*/;
    // 0050e9ab  eba6                   -jmp 0x50e953
    goto L_0x0050e953;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_50e9b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050e9b0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050e9b1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050e9b2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050e9b3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0050e9b4  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0050e9b6  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0050e9b8  8b5018                 -mov edx, dword ptr [eax + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0050e9bb  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0050e9bc  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050e9c2  837e1800               +cmp dword ptr [esi + 0x18], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050e9c6  741c                   -je 0x50e9e4
    if (cpu.flags.zf)
    {
        goto L_0x0050e9e4;
    }
L_0x0050e9c8:
    // 0050e9c8  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0050e9ca  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0050e9cc  e80fffffff             -call 0x50e8e0
    cpu.esp -= 4;
    sub_50e8e0(app, cpu);
    if (cpu.terminate) return;
    // 0050e9d1  8b4e18                 -mov ecx, dword ptr [esi + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 0050e9d4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050e9d5  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0050e9d7  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050e9dd  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0050e9df  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e9e0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e9e1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e9e2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050e9e3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050e9e4:
    // 0050e9e4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050e9e5  b8b0fd5400             -mov eax, 0x54fdb0
    cpu.eax = 5569968 /*0x54fdb0*/;
    // 0050e9ea  bdb8fb5400             -mov ebp, 0x54fbb8
    cpu.ebp = 5569464 /*0x54fbb8*/;
    // 0050e9ef  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0050e9f0  ba14040000             -mov edx, 0x414
    cpu.edx = 1044 /*0x414*/;
    // 0050e9f5  892d90215500           -mov dword ptr [0x552190], ebp
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ebp;
    // 0050e9fb  68ccfb5400             -push 0x54fbcc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5569484 /*0x54fbcc*/;
    cpu.esp -= 4;
    // 0050ea00  a394215500             -mov dword ptr [0x552194], eax
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.eax;
    // 0050ea05  891598215500           -mov dword ptr [0x552198], edx
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.edx;
    // 0050ea0b  e80026efff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 0050ea10  83c40c                 +add esp, 0xc
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
    // 0050ea13  ebb3                   -jmp 0x50e9c8
    goto L_0x0050e9c8;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_50ea20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050ea20  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050ea21  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0050ea22  8b5018                 -mov edx, dword ptr [eax + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0050ea25  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0050ea26  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050ea2c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0050ea2e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050ea2f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050ea30  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_50ea40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050ea40  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050ea41  8b5018                 -mov edx, dword ptr [eax + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0050ea44  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0050ea45  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050ea4b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050ea4c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_50ea4e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050ea4e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0050ea4f  dd442408               -fld qword ptr [esp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 0050ea53  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 0050ea55  e8fc12fdff             -call 0x4dfd56
    cpu.esp -= 4;
    sub_4dfd56(app, cpu);
    if (cpu.terminate) return;
    // 0050ea5a  dce9                   -fsub st(1), st(0)
    cpu.fpu.st(1) -= x86::Float(cpu.fpu.st(0));
    // 0050ea5c  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0050ea60  dd18                   -fstp qword ptr [eax]
    app->getMemory<double>(cpu.eax) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0050ea62  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050ea63  9b                     -wait 
    /*nothing*/;
    // 0050ea64  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 */
void Application::sub_50ea68(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050ea68  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050ea69  9c                     -pushfd 
    cpu.esp -= 4;
    app->getMemory<x86::reg32>(cpu.esp) = cpu.flags.eflags;
    // 0050ea6a  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0050ea6b  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0050ea6d  83ec20                 -sub esp, 0x20
    (cpu.esp) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0050ea70  9c                     -pushfd 
    cpu.esp -= 4;
    app->getMemory<x86::reg32>(cpu.esp) = cpu.flags.eflags;
    // 0050ea71  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050ea72  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0050ea74  3500002000             -xor eax, 0x200000
    cpu.eax ^= x86::reg32(x86::sreg32(2097152 /*0x200000*/));
    // 0050ea79  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0050ea7a  9d                     -popfd 
    cpu.flags.eflags = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050ea7b  9c                     -pushfd 
    cpu.esp -= 4;
    app->getMemory<x86::reg32>(cpu.esp) = cpu.flags.eflags;
    // 0050ea7c  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050ea7d  31c8                   -xor eax, ecx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0050ea7f  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0050ea81  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050ea82  9d                     -popfd 
    cpu.flags.eflags = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050ea83  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050ea84  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_50ea85(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050ea85  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0050ea86  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0050ea88  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0050ea89  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050ea8a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0050ea8b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050ea8c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050ea8d  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0050ea90  0fa2                   -cpuid 
    cpu.cpuid();
    // 0050ea92  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0050ea95  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 0050ea97  895e04                 -mov dword ptr [esi + 4], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 0050ea9a  895608                 -mov dword ptr [esi + 8], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0050ea9d  894e0c                 -mov dword ptr [esi + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 0050eaa0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050eaa1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050eaa2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050eaa3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050eaa4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050eaa5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050eaa6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_50eaa7(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050eaa7  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0050eaa8  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0050eaa9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0050eaab  9e                     -sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 0050eaac  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 0050eab1  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 0050eab6  f6f3                   -div bl
    {
        x86::reg16 tmp = cpu.ax;
        x86::reg8 d = cpu.bl;
        cpu.ax /= d;
        cpu.ah = tmp % d;
    }
    // 0050eab8  9f                     -lahf 
    cpu.ah = 0x02 | (cpu.flags.lo & 0xD7);
    // 0050eab9  80fc02                 +cmp ah, 2
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(2 /*0x2*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0050eabc  b800000000             -mov eax, 0
    cpu.eax = 0 /*0x0*/;
    // 0050eac1  7505                   -jne 0x50eac8
    if (!cpu.flags.zf)
    {
        goto L_0x0050eac8;
    }
    // 0050eac3  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x0050eac8:
    // 0050eac8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050eac9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050eaca  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_50ead0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050ead0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0050ead1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050ead2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0050ead3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050ead4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050ead5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0050ead6  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0050ead8  8b3554b1a000           -mov esi, dword ptr [0xa0b154]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(10531156) /* 0xa0b154 */);
    // 0050eade  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0050eae0  743f                   -je 0x50eb21
    if (cpu.flags.zf)
    {
        goto L_0x0050eb21;
    }
    // 0050eae2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0050eae4  743b                   -je 0x50eb21
    if (cpu.flags.zf)
    {
        goto L_0x0050eb21;
    }
    // 0050eae6  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0050eae8  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 0050eae9  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 0050eaeb  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 0050eaed  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0050eaef  49                     -dec ecx
    (cpu.ecx)--;
    // 0050eaf0  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0050eaf2  f2ae                   +repne scasb al, byte ptr es:[edi]
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
    // 0050eaf4  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 0050eaf6  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0050eaf7  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 0050eaf8  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0050eafa  eb1f                   -jmp 0x50eb1b
    goto L_0x0050eb1b;
L_0x0050eafc:
    // 0050eafc  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 0050eafe  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0050eb00  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0050eb02  e809520100             -call 0x523d10
    cpu.esp -= 4;
    sub_523d10(app, cpu);
    if (cpu.terminate) return;
    // 0050eb07  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0050eb09  750d                   -jne 0x50eb18
    if (!cpu.flags.zf)
    {
        goto L_0x0050eb18;
    }
    // 0050eb0b  803c393d               +cmp byte ptr [ecx + edi], 0x3d
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx + cpu.edi * 1);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(61 /*0x3d*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0050eb0f  7507                   -jne 0x50eb18
    if (!cpu.flags.zf)
    {
        goto L_0x0050eb18;
    }
    // 0050eb11  8d4701                 -lea eax, [edi + 1]
    cpu.eax = x86::reg32(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 0050eb14  01c8                   +add eax, ecx
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0050eb16  eb0b                   -jmp 0x50eb23
    goto L_0x0050eb23;
L_0x0050eb18:
    // 0050eb18  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0050eb1b:
    // 0050eb1b  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 0050eb1d  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0050eb1f  75db                   -jne 0x50eafc
    if (!cpu.flags.zf)
    {
        goto L_0x0050eafc;
    }
L_0x0050eb21:
    // 0050eb21  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0050eb23:
    // 0050eb23  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050eb24  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050eb25  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050eb26  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050eb27  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050eb28  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050eb29  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_50eb30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050eb30  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0050eb31  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050eb32  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0050eb33  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0050eb36  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0050eb38  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0050eb3a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0050eb3b  2eff1538455300         -call dword ptr cs:[0x534538]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457208) /* 0x534538 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050eb42  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0050eb44  668b0424               -mov ax, word ptr [esp]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esp);
    // 0050eb48  2d6c070000             -sub eax, 0x76c
    (cpu.eax) -= x86::reg32(x86::sreg32(1900 /*0x76c*/));
    // 0050eb4d  894314                 -mov dword ptr [ebx + 0x14], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0050eb50  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0050eb52  668b442402             -mov ax, word ptr [esp + 2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(2) /* 0x2 */);
    // 0050eb57  48                     -dec eax
    (cpu.eax)--;
    // 0050eb58  894310                 -mov dword ptr [ebx + 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0050eb5b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0050eb5d  668b442406             -mov ax, word ptr [esp + 6]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(6) /* 0x6 */);
    // 0050eb62  89430c                 -mov dword ptr [ebx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0050eb65  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0050eb67  668b442408             -mov ax, word ptr [esp + 8]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0050eb6c  894308                 -mov dword ptr [ebx + 8], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0050eb6f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0050eb71  668b44240a             -mov ax, word ptr [esp + 0xa]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(10) /* 0xa */);
    // 0050eb76  894304                 -mov dword ptr [ebx + 4], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0050eb79  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0050eb7b  668b44240c             -mov ax, word ptr [esp + 0xc]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0050eb80  c74320ffffffff         -mov dword ptr [ebx + 0x20], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */) = 4294967295 /*0xffffffff*/;
    // 0050eb87  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 0050eb89  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0050eb8b  668b44240e             -mov ax, word ptr [esp + 0xe]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(14) /* 0xe */);
    // 0050eb90  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0050eb93  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050eb94  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050eb95  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050eb96  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_50eba0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050eba0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0050eba1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050eba2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0050eba3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050eba4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050eba5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0050eba6  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0050eba9  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0050ebab  b90c000000             -mov ecx, 0xc
    cpu.ecx = 12 /*0xc*/;
    // 0050ebb0  8b5510                 -mov edx, dword ptr [ebp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0050ebb3  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0050ebb6  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0050ebb9  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0050ebbb  bb48215500             -mov ebx, 0x552148
    cpu.ebx = 5579080 /*0x552148*/;
    // 0050ebc0  8b7d14                 -mov edi, dword ptr [ebp + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 0050ebc3  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0050ebc5  81ffa17efbf4           +cmp edi, 0xf4fb7ea1
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4110122657 /*0xf4fb7ea1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050ebcb  7d0a                   -jge 0x50ebd7
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0050ebd7;
    }
    // 0050ebcd  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0050ebd2  e96e010000             -jmp 0x50ed45
    goto L_0x0050ed45;
L_0x0050ebd7:
    // 0050ebd7  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0050ebda  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0050ebdc  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0050ebdf  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0050ebe1  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0050ebe3  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0050ebe5  7d08                   -jge 0x50ebef
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0050ebef;
    }
L_0x0050ebe7:
    // 0050ebe7  83c60c                 -add esi, 0xc
    (cpu.esi) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0050ebea  4f                     -dec edi
    (cpu.edi)--;
    // 0050ebeb  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0050ebed  7cf8                   -jl 0x50ebe7
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0050ebe7;
    }
L_0x0050ebef:
    // 0050ebef  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0050ebf1  7d0f                   -jge 0x50ec02
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0050ec02;
    }
    // 0050ebf3  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0050ebf8  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0050ebfb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050ebfc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050ebfd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050ebfe  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050ebff  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050ec00  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050ec01  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050ec02:
    // 0050ec02  8d876c070000           -lea eax, [edi + 0x76c]
    cpu.eax = x86::reg32(cpu.edi + x86::reg32(1900) /* 0x76c */);
    // 0050ec08  e8e3740000             -call 0x5160f0
    cpu.esp -= 4;
    sub_5160f0(app, cpu);
    if (cpu.terminate) return;
    // 0050ec0d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0050ec0f  7405                   -je 0x50ec16
    if (cpu.flags.zf)
    {
        goto L_0x0050ec16;
    }
    // 0050ec11  bb62215500             -mov ebx, 0x552162
    cpu.ebx = 5579106 /*0x552162*/;
L_0x0050ec16:
    // 0050ec16  8d5703                 -lea edx, [edi + 3]
    cpu.edx = x86::reg32(cpu.edi + x86::reg32(3) /* 0x3 */);
    // 0050ec19  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0050ec1b  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0050ec1e  c1e202                 +shl edx, 2
    {
        x86::reg8 tmp = 2 /*0x2*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 0050ec21  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0050ec23  c1f802                 -sar eax, 2
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (2 /*0x2*/ % 32));
    // 0050ec26  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0050ec28  8d04fd00000000         -lea eax, [edi*8]
    cpu.eax = x86::reg32(cpu.edi * 8);
    // 0050ec2f  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 0050ec31  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0050ec34  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 0050ec36  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0050ec38  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0050ec3b  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0050ec3d  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0050ec3f  b864000000             -mov eax, 0x64
    cpu.eax = 100 /*0x64*/;
    // 0050ec44  8d5763                 -lea edx, [edi + 0x63]
    cpu.edx = x86::reg32(cpu.edi + x86::reg32(99) /* 0x63 */);
    // 0050ec47  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0050ec4a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0050ec4c  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0050ec4f  f73c24                 -idiv dword ptr [esp]
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(app->getMemory<x86::reg32>(cpu.esp));
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0050ec52  8d972b010000           -lea edx, [edi + 0x12b]
    cpu.edx = x86::reg32(cpu.edi + x86::reg32(299) /* 0x12b */);
    // 0050ec58  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0050ec5a  bf90010000             -mov edi, 0x190
    cpu.edi = 400 /*0x190*/;
    // 0050ec5f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0050ec61  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0050ec64  f7ff                   -idiv edi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.edi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0050ec66  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0050ec68  0fbf0473               -movsx eax, word ptr [ebx + esi*2]
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.ebx + cpu.esi * 2)));
    // 0050ec6c  8b550c                 -mov edx, dword ptr [ebp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0050ec6f  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0050ec71  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0050ec73  8d78ff                 -lea edi, [eax - 1]
    cpu.edi = x86::reg32(cpu.eax + x86::reg32(-1) /* -0x1 */);
    // 0050ec76  8b5508                 -mov edx, dword ptr [ebp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0050ec79  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0050ec7b  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0050ec7e  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0050ec80  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0050ec83  8b5504                 -mov edx, dword ptr [ebp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 0050ec86  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0050ec88  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0050ec8a  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0050ec8d  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0050ec8f  8b7500                 -mov esi, dword ptr [ebp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp);
    // 0050ec92  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0050ec95  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0050ec97  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0050ec99  7d0b                   -jge 0x50eca6
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0050eca6;
    }
L_0x0050ec9b:
    // 0050ec9b  81c680510100           -add esi, 0x15180
    (cpu.esi) += x86::reg32(x86::sreg32(86400 /*0x15180*/));
    // 0050eca1  4f                     -dec edi
    (cpu.edi)--;
    // 0050eca2  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0050eca4  7cf5                   -jl 0x50ec9b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0050ec9b;
    }
L_0x0050eca6:
    // 0050eca6  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 0050eca8  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0050ecaa  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0050ecac  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0050ecae  e8ed720000             -call 0x515fa0
    cpu.esp -= 4;
    sub_515fa0(app, cpu);
    if (cpu.terminate) return;
    // 0050ecb3  e8746f0000             -call 0x515c2c
    cpu.esp -= 4;
    sub_515c2c(app, cpu);
    if (cpu.terminate) return;
    // 0050ecb8  8b1d948b5600           -mov ebx, dword ptr [0x568b94]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5671828) /* 0x568b94 */);
    // 0050ecbe  8b4d20                 -mov ecx, dword ptr [ebp + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 0050ecc1  01de                   -add esi, ebx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0050ecc3  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0050ecc5  7d07                   -jge 0x50ecce
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0050ecce;
    }
    // 0050ecc7  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0050ecc9  e8a2750000             -call 0x516270
    cpu.esp -= 4;
    sub_516270(app, cpu);
    if (cpu.terminate) return;
L_0x0050ecce:
    // 0050ecce  837d2000               +cmp dword ptr [ebp + 0x20], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050ecd2  7e06                   -jle 0x50ecda
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0050ecda;
    }
    // 0050ecd4  2b359c8b5600           -sub esi, dword ptr [0x568b9c]
    (cpu.esi) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5671836) /* 0x568b9c */)));
L_0x0050ecda:
    // 0050ecda  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0050ecdc  7d09                   -jge 0x50ece7
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0050ece7;
    }
    // 0050ecde  4f                     -dec edi
    (cpu.edi)--;
    // 0050ecdf  81c680510100           +add esi, 0x15180
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(86400 /*0x15180*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0050ece5  ebf3                   -jmp 0x50ecda
    goto L_0x0050ecda;
L_0x0050ece7:
    // 0050ece7  81ffde630000           +cmp edi, 0x63de
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(25566 /*0x63de*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050eced  7d0f                   -jge 0x50ecfe
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0050ecfe;
    }
    // 0050ecef  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0050ecf4  83c404                 +add esp, 4
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
    // 0050ecf7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050ecf8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050ecf9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050ecfa  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050ecfb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050ecfc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050ecfd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050ecfe:
    // 0050ecfe  7523                   -jne 0x50ed23
    if (!cpu.flags.zf)
    {
        goto L_0x0050ed23;
    }
    // 0050ed00  8b1d948b5600           -mov ebx, dword ptr [0x568b94]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5671828) /* 0x568b94 */);
    // 0050ed06  81ee80510100           -sub esi, 0x15180
    (cpu.esi) -= x86::reg32(x86::sreg32(86400 /*0x15180*/));
    // 0050ed0c  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0050ed0e  7e04                   -jle 0x50ed14
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0050ed14;
    }
    // 0050ed10  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0050ed12  7d2f                   -jge 0x50ed43
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0050ed43;
    }
L_0x0050ed14:
    // 0050ed14  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0050ed19  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0050ed1c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050ed1d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050ed1e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050ed1f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050ed20  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050ed21  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050ed22  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050ed23:
    // 0050ed23  8d87219cffff           -lea eax, [edi - 0x63df]
    cpu.eax = x86::reg32(cpu.edi + x86::reg32(-25567) /* -0x63df */);
    // 0050ed29  8d3cc500000000         -lea edi, [eax*8]
    cpu.edi = x86::reg32(cpu.eax * 8);
    // 0050ed30  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0050ed32  c1e705                 -shl edi, 5
    cpu.edi <<= 5 /*0x5*/ % 32;
    // 0050ed35  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0050ed37  c1e707                 -shl edi, 7
    cpu.edi <<= 7 /*0x7*/ % 32;
    // 0050ed3a  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0050ed3c  c1e702                 -shl edi, 2
    cpu.edi <<= 2 /*0x2*/ % 32;
    // 0050ed3f  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0050ed41  01fe                   -add esi, edi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edi));
L_0x0050ed43:
    // 0050ed43  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x0050ed45:
    // 0050ed45  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0050ed48  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050ed49  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050ed4a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050ed4b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050ed4c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050ed4d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050ed4e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_50ed50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050ed50  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050ed51  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050ed52  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050ed53  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0050ed54  81ec44050000           -sub esp, 0x544
    (cpu.esp) -= x86::reg32(x86::sreg32(1348 /*0x544*/));
    // 0050ed5a  899424c4040000         -mov dword ptr [esp + 0x4c4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1220) /* 0x4c4 */) = cpu.edx;
    // 0050ed61  899424d4040000         -mov dword ptr [esp + 0x4d4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1236) /* 0x4d4 */) = cpu.edx;
    // 0050ed68  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0050ed6a  899424cc040000         -mov dword ptr [esp + 0x4cc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1228) /* 0x4cc */) = cpu.edx;
    // 0050ed71  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0050ed73  0f8437120000           -je 0x50ffb0
    if (cpu.flags.zf)
    {
        goto L_0x0050ffb0;
    }
    // 0050ed79  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0050ed7b  8a08                   -mov cl, byte ptr [eax]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax);
    // 0050ed7d  8a5001                 -mov dl, byte ptr [eax + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0050ed80  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 0050ed83  09ca                   -or edx, ecx
    cpu.edx |= x86::reg32(x86::sreg32(cpu.ecx));
    // 0050ed85  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0050ed88  89942434050000         -mov dword ptr [esp + 0x534], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.edx;
    // 0050ed8f  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0050ed91  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0050ed93  89842430050000         -mov dword ptr [esp + 0x530], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */) = cpu.eax;
    // 0050ed9a  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 0050ed9c  8b842434050000         -mov eax, dword ptr [esp + 0x534]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 0050eda3  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0050eda5  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 0050eda8  8b8c2430050000         -mov ecx, dword ptr [esp + 0x530]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0050edaf  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 0050edb1  c1e610                 -shl esi, 0x10
    cpu.esi <<= 16 /*0x10*/ % 32;
    // 0050edb4  89942434050000         -mov dword ptr [esp + 0x534], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.edx;
    // 0050edbb  8b942430050000         -mov edx, dword ptr [esp + 0x530]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0050edc2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0050edc4  83c102                 -add ecx, 2
    (cpu.ecx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0050edc7  8a4201                 -mov al, byte ptr [edx + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 0050edca  8b942434050000         -mov edx, dword ptr [esp + 0x534]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 0050edd1  c1ee10                 -shr esi, 0x10
    cpu.esi >>= 16 /*0x10*/ % 32;
    // 0050edd4  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 0050edd7  89b424c8040000         -mov dword ptr [esp + 0x4c8], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1224) /* 0x4c8 */) = cpu.esi;
    // 0050edde  09d0                   -or eax, edx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edx));
    // 0050ede0  898c2430050000         -mov dword ptr [esp + 0x530], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */) = cpu.ecx;
    // 0050ede7  89842434050000         -mov dword ptr [esp + 0x534], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.eax;
    // 0050edee  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0050edf0  8aa424c9040000         -mov ah, byte ptr [esp + 0x4c9]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1225) /* 0x4c9 */);
    // 0050edf7  c1e610                 -shl esi, 0x10
    cpu.esi <<= 16 /*0x10*/ % 32;
    // 0050edfa  f6c401                 +test ah, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 1 /*0x1*/));
    // 0050edfd  0f85e8010000           -jne 0x50efeb
    if (!cpu.flags.zf)
    {
        goto L_0x0050efeb;
    }
L_0x0050ee03:
    // 0050ee03  8a9424c9040000         -mov dl, byte ptr [esp + 0x4c9]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1225) /* 0x4c9 */);
    // 0050ee0a  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
    // 0050ee0c  83ef08                 -sub edi, 8
    (cpu.edi) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0050ee0f  80e2fe                 -and dl, 0xfe
    cpu.dl &= x86::reg8(x86::sreg8(254 /*0xfe*/));
    // 0050ee12  c1ed18                 -shr ebp, 0x18
    cpu.ebp >>= 24 /*0x18*/ % 32;
    // 0050ee15  c1e608                 -shl esi, 8
    cpu.esi <<= 8 /*0x8*/ % 32;
    // 0050ee18  889424c9040000         -mov byte ptr [esp + 0x4c9], dl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1225) /* 0x4c9 */) = cpu.dl;
    // 0050ee1f  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0050ee21  0f8c39020000           -jl 0x50f060
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0050f060;
    }
L_0x0050ee27:
    // 0050ee27  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0050ee29  83ef10                 -sub edi, 0x10
    (cpu.edi) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0050ee2c  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 0050ee2f  c1e610                 -shl esi, 0x10
    cpu.esi <<= 16 /*0x10*/ % 32;
    // 0050ee32  898424cc040000         -mov dword ptr [esp + 0x4cc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1228) /* 0x4cc */) = cpu.eax;
    // 0050ee39  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0050ee3b  0f8c7d020000           -jl 0x50f0be
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0050f0be;
    }
L_0x0050ee41:
    // 0050ee41  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0050ee43  8b8c24cc040000         -mov ecx, dword ptr [esp + 0x4cc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1228) /* 0x4cc */);
    // 0050ee4a  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 0050ee4d  09c1                   -or ecx, eax
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.eax));
    // 0050ee4f  898c24cc040000         -mov dword ptr [esp + 0x4cc], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1228) /* 0x4cc */) = cpu.ecx;
    // 0050ee56  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0050ee58  0f85be020000           -jne 0x50f11c
    if (!cpu.flags.zf)
    {
        goto L_0x0050f11c;
    }
L_0x0050ee5e:
    // 0050ee5e  8d842400010000         -lea eax, [esp + 0x100]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 0050ee65  8d9c2400020000         -lea ebx, [esp + 0x200]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(512) /* 0x200 */);
    // 0050ee6c  89842400050000         -mov dword ptr [esp + 0x500], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1280) /* 0x500 */) = cpu.eax;
L_0x0050ee73:
    // 0050ee73  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0050ee75  c1e818                 -shr eax, 0x18
    cpu.eax >>= 24 /*0x18*/ % 32;
    // 0050ee78  8a0403                 -mov al, byte ptr [ebx + eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + cpu.eax * 1);
    // 0050ee7b  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0050ee80  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0050ee82  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0050ee84  0f8cce000000           -jl 0x50ef58
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0050ef58;
    }
L_0x0050ee8a:
    // 0050ee8a  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0050ee8c  8b8c2400050000         -mov ecx, dword ptr [esp + 0x500]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1280) /* 0x500 */);
    // 0050ee93  c1ea18                 -shr edx, 0x18
    cpu.edx >>= 24 /*0x18*/ % 32;
    // 0050ee96  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0050ee98  8a22                   -mov ah, byte ptr [edx]
    cpu.ah = app->getMemory<x86::reg8>(cpu.edx);
    // 0050ee9a  88c1                   -mov cl, al
    cpu.cl = cpu.al;
    // 0050ee9c  8b9424d4040000         -mov edx, dword ptr [esp + 0x4d4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1236) /* 0x4d4 */);
    // 0050eea3  d3e6                   -shl esi, cl
    cpu.esi <<= cpu.cl % 32;
    // 0050eea5  8822                   -mov byte ptr [edx], ah
    app->getMemory<x86::reg8>(cpu.edx) = cpu.ah;
    // 0050eea7  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0050eea9  8bac24d4040000         -mov ebp, dword ptr [esp + 0x4d4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1236) /* 0x4d4 */);
    // 0050eeb0  c1ea18                 -shr edx, 0x18
    cpu.edx >>= 24 /*0x18*/ % 32;
    // 0050eeb3  45                     -inc ebp
    (cpu.ebp)++;
    // 0050eeb4  8d0413                 -lea eax, [ebx + edx]
    cpu.eax = x86::reg32(cpu.ebx + cpu.edx * 1);
    // 0050eeb7  89ac24d4040000         -mov dword ptr [esp + 0x4d4], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1236) /* 0x4d4 */) = cpu.ebp;
    // 0050eebe  8a00                   -mov al, byte ptr [eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax);
    // 0050eec0  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0050eec5  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0050eec7  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0050eec9  0f8c89000000           -jl 0x50ef58
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0050ef58;
    }
    // 0050eecf  03942400050000         -add edx, dword ptr [esp + 0x500]
    (cpu.edx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1280) /* 0x500 */)));
    // 0050eed6  8a22                   -mov ah, byte ptr [edx]
    cpu.ah = app->getMemory<x86::reg8>(cpu.edx);
    // 0050eed8  88c1                   -mov cl, al
    cpu.cl = cpu.al;
    // 0050eeda  d3e6                   -shl esi, cl
    cpu.esi <<= cpu.cl % 32;
    // 0050eedc  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0050eede  45                     -inc ebp
    (cpu.ebp)++;
    // 0050eedf  c1ea18                 -shr edx, 0x18
    cpu.edx >>= 24 /*0x18*/ % 32;
    // 0050eee2  8865ff                 -mov byte ptr [ebp - 1], ah
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-1) /* -0x1 */) = cpu.ah;
    // 0050eee5  8d0413                 -lea eax, [ebx + edx]
    cpu.eax = x86::reg32(cpu.ebx + cpu.edx * 1);
    // 0050eee8  89ac24d4040000         -mov dword ptr [esp + 0x4d4], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1236) /* 0x4d4 */) = cpu.ebp;
    // 0050eeef  8a00                   -mov al, byte ptr [eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax);
    // 0050eef1  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0050eef6  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0050eef8  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0050eefa  7c5c                   -jl 0x50ef58
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0050ef58;
    }
    // 0050eefc  03942400050000         -add edx, dword ptr [esp + 0x500]
    (cpu.edx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1280) /* 0x500 */)));
    // 0050ef03  8a22                   -mov ah, byte ptr [edx]
    cpu.ah = app->getMemory<x86::reg8>(cpu.edx);
    // 0050ef05  88c1                   -mov cl, al
    cpu.cl = cpu.al;
    // 0050ef07  d3e6                   -shl esi, cl
    cpu.esi <<= cpu.cl % 32;
    // 0050ef09  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0050ef0b  45                     -inc ebp
    (cpu.ebp)++;
    // 0050ef0c  c1ea18                 -shr edx, 0x18
    cpu.edx >>= 24 /*0x18*/ % 32;
    // 0050ef0f  8865ff                 -mov byte ptr [ebp - 1], ah
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-1) /* -0x1 */) = cpu.ah;
    // 0050ef12  8d0413                 -lea eax, [ebx + edx]
    cpu.eax = x86::reg32(cpu.ebx + cpu.edx * 1);
    // 0050ef15  89ac24d4040000         -mov dword ptr [esp + 0x4d4], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1236) /* 0x4d4 */) = cpu.ebp;
    // 0050ef1c  8a00                   -mov al, byte ptr [eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax);
    // 0050ef1e  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0050ef23  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0050ef25  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0050ef27  7c2f                   -jl 0x50ef58
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0050ef58;
    }
    // 0050ef29  03942400050000         -add edx, dword ptr [esp + 0x500]
    (cpu.edx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1280) /* 0x500 */)));
    // 0050ef30  8a22                   -mov ah, byte ptr [edx]
    cpu.ah = app->getMemory<x86::reg8>(cpu.edx);
    // 0050ef32  88c1                   -mov cl, al
    cpu.cl = cpu.al;
    // 0050ef34  d3e6                   -shl esi, cl
    cpu.esi <<= cpu.cl % 32;
    // 0050ef36  886500                 -mov byte ptr [ebp], ah
    app->getMemory<x86::reg8>(cpu.ebp) = cpu.ah;
    // 0050ef39  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0050ef3b  45                     -inc ebp
    (cpu.ebp)++;
    // 0050ef3c  c1e818                 -shr eax, 0x18
    cpu.eax >>= 24 /*0x18*/ % 32;
    // 0050ef3f  89ac24d4040000         -mov dword ptr [esp + 0x4d4], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1236) /* 0x4d4 */) = cpu.ebp;
    // 0050ef46  8a0403                 -mov al, byte ptr [ebx + eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + cpu.eax * 1);
    // 0050ef49  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0050ef4e  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0050ef50  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0050ef52  0f8d32ffffff           -jge 0x50ee8a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0050ee8a;
    }
L_0x0050ef58:
    // 0050ef58  83c710                 -add edi, 0x10
    (cpu.edi) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0050ef5b  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0050ef5d  0f8c420b0000           -jl 0x50faa5
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0050faa5;
    }
    // 0050ef63  8b842400050000         -mov eax, dword ptr [esp + 0x500]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1280) /* 0x500 */);
    // 0050ef6a  c1ee18                 -shr esi, 0x18
    cpu.esi >>= 24 /*0x18*/ % 32;
    // 0050ef6d  8b9424d4040000         -mov edx, dword ptr [esp + 0x4d4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1236) /* 0x4d4 */);
    // 0050ef74  8a0406                 -mov al, byte ptr [esi + eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1);
    // 0050ef77  8802                   -mov byte ptr [edx], al
    app->getMemory<x86::reg8>(cpu.edx) = cpu.al;
    // 0050ef79  8b942430050000         -mov edx, dword ptr [esp + 0x530]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0050ef80  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0050ef82  8a02                   -mov al, byte ptr [edx]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx);
    // 0050ef84  8b942434050000         -mov edx, dword ptr [esp + 0x534]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 0050ef8b  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 0050ef8e  09d0                   -or eax, edx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edx));
    // 0050ef90  89842434050000         -mov dword ptr [esp + 0x534], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.eax;
    // 0050ef97  8b842430050000         -mov eax, dword ptr [esp + 0x530]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0050ef9e  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0050efa0  8a5001                 -mov dl, byte ptr [eax + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0050efa3  8b842434050000         -mov eax, dword ptr [esp + 0x534]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 0050efaa  b910000000             -mov ecx, 0x10
    cpu.ecx = 16 /*0x10*/;
    // 0050efaf  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 0050efb2  29f9                   -sub ecx, edi
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edi));
    // 0050efb4  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 0050efb6  8b8424d4040000         -mov eax, dword ptr [esp + 0x4d4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1236) /* 0x4d4 */);
    // 0050efbd  89942434050000         -mov dword ptr [esp + 0x534], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.edx;
    // 0050efc4  8b942430050000         -mov edx, dword ptr [esp + 0x530]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0050efcb  40                     -inc eax
    (cpu.eax)++;
    // 0050efcc  8bb42434050000         -mov esi, dword ptr [esp + 0x534]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 0050efd3  898424d4040000         -mov dword ptr [esp + 0x4d4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1236) /* 0x4d4 */) = cpu.eax;
    // 0050efda  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0050efdd  d3e6                   +shl esi, cl
    {
        x86::reg8 tmp = cpu.cl % 32;
        x86::reg32& op = cpu.esi;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 0050efdf  89942430050000         -mov dword ptr [esp + 0x530], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */) = cpu.edx;
    // 0050efe6  e988feffff             -jmp 0x50ee73
    goto L_0x0050ee73;
L_0x0050efeb:
    // 0050efeb  8b842434050000         -mov eax, dword ptr [esp + 0x534]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 0050eff2  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0050eff4  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 0050eff7  8a11                   -mov dl, byte ptr [ecx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx);
    // 0050eff9  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 0050effb  89942434050000         -mov dword ptr [esp + 0x534], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.edx;
    // 0050f002  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0050f004  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 0050f007  8a4101                 -mov al, byte ptr [ecx + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 0050f00a  09d0                   -or eax, edx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edx));
    // 0050f00c  8d7102                 -lea esi, [ecx + 2]
    cpu.esi = x86::reg32(cpu.ecx + x86::reg32(2) /* 0x2 */);
    // 0050f00f  89842434050000         -mov dword ptr [esp + 0x534], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.eax;
    // 0050f016  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0050f018  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 0050f01b  8a16                   -mov dl, byte ptr [esi]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi);
    // 0050f01d  89b42430050000         -mov dword ptr [esp + 0x530], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */) = cpu.esi;
    // 0050f024  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 0050f026  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 0050f028  89942434050000         -mov dword ptr [esp + 0x534], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.edx;
    // 0050f02f  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0050f032  8b842434050000         -mov eax, dword ptr [esp + 0x534]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 0050f039  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0050f03b  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 0050f03e  8a5601                 -mov dl, byte ptr [esi + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0050f041  89bc2430050000         -mov dword ptr [esp + 0x530], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */) = cpu.edi;
    // 0050f048  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 0050f04a  bf08000000             -mov edi, 8
    cpu.edi = 8 /*0x8*/;
    // 0050f04f  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0050f051  89942434050000         -mov dword ptr [esp + 0x534], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.edx;
    // 0050f058  c1e608                 +shl esi, 8
    {
        x86::reg8 tmp = 8 /*0x8*/ % 32;
        x86::reg32& op = cpu.esi;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 0050f05b  e9a3fdffff             -jmp 0x50ee03
    goto L_0x0050ee03;
L_0x0050f060:
    // 0050f060  8b842430050000         -mov eax, dword ptr [esp + 0x530]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0050f067  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0050f069  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 0050f06b  8b842434050000         -mov eax, dword ptr [esp + 0x534]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 0050f072  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 0050f075  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 0050f077  8b842430050000         -mov eax, dword ptr [esp + 0x530]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0050f07e  89942434050000         -mov dword ptr [esp + 0x534], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.edx;
    // 0050f085  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0050f087  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0050f089  8a5001                 -mov dl, byte ptr [eax + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0050f08c  8b842434050000         -mov eax, dword ptr [esp + 0x534]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 0050f093  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0050f095  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 0050f098  83c710                 -add edi, 0x10
    (cpu.edi) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0050f09b  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 0050f09d  8b842430050000         -mov eax, dword ptr [esp + 0x530]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0050f0a4  89942434050000         -mov dword ptr [esp + 0x534], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.edx;
    // 0050f0ab  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0050f0ad  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0050f0b0  d3e6                   +shl esi, cl
    {
        x86::reg8 tmp = cpu.cl % 32;
        x86::reg32& op = cpu.esi;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 0050f0b2  89842430050000         -mov dword ptr [esp + 0x530], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */) = cpu.eax;
    // 0050f0b9  e969fdffff             -jmp 0x50ee27
    goto L_0x0050ee27;
L_0x0050f0be:
    // 0050f0be  8b842430050000         -mov eax, dword ptr [esp + 0x530]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0050f0c5  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0050f0c7  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 0050f0c9  8b842434050000         -mov eax, dword ptr [esp + 0x534]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 0050f0d0  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 0050f0d3  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 0050f0d5  89942434050000         -mov dword ptr [esp + 0x534], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.edx;
    // 0050f0dc  8b942430050000         -mov edx, dword ptr [esp + 0x530]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0050f0e3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0050f0e5  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0050f0e7  8a4201                 -mov al, byte ptr [edx + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 0050f0ea  8b942434050000         -mov edx, dword ptr [esp + 0x534]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 0050f0f1  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0050f0f3  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 0050f0f6  83c710                 -add edi, 0x10
    (cpu.edi) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0050f0f9  09d0                   -or eax, edx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edx));
    // 0050f0fb  8b942430050000         -mov edx, dword ptr [esp + 0x530]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0050f102  89842434050000         -mov dword ptr [esp + 0x534], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.eax;
    // 0050f109  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0050f10b  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0050f10e  d3e6                   +shl esi, cl
    {
        x86::reg8 tmp = cpu.cl % 32;
        x86::reg32& op = cpu.esi;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 0050f110  89942430050000         -mov dword ptr [esp + 0x530], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */) = cpu.edx;
    // 0050f117  e925fdffff             -jmp 0x50ee41
    goto L_0x0050ee41;
L_0x0050f11c:
    // 0050f11c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0050f11e  83ef08                 -sub edi, 8
    (cpu.edi) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0050f121  c1e818                 -shr eax, 0x18
    cpu.eax >>= 24 /*0x18*/ % 32;
    // 0050f124  c1e608                 -shl esi, 8
    cpu.esi <<= 8 /*0x8*/ % 32;
    // 0050f127  88842440050000         -mov byte ptr [esp + 0x540], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1344) /* 0x540 */) = cpu.al;
    // 0050f12e  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0050f130  0f8ce4030000           -jl 0x50f51a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0050f51a;
    }
L_0x0050f136:
    // 0050f136  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0050f13b  ba0f000000             -mov edx, 0xf
    cpu.edx = 15 /*0xf*/;
    // 0050f140  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 0050f145  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 0050f147  898424d8040000         -mov dword ptr [esp + 0x4d8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1240) /* 0x4d8 */) = cpu.eax;
    // 0050f14e  89942418050000         -mov dword ptr [esp + 0x518], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1304) /* 0x518 */) = cpu.edx;
    // 0050f155  898c241c050000         -mov dword ptr [esp + 0x51c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1308) /* 0x51c */) = cpu.ecx;
    // 0050f15c  89ac24e4040000         -mov dword ptr [esp + 0x4e4], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1252) /* 0x4e4 */) = cpu.ebp;
L_0x0050f163:
    // 0050f163  01ed                   -add ebp, ebp
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0050f165  8b9c24e4040000         -mov ebx, dword ptr [esp + 0x4e4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1252) /* 0x4e4 */);
    // 0050f16c  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0050f16e  8b94241c050000         -mov edx, dword ptr [esp + 0x51c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1308) /* 0x51c */);
    // 0050f175  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0050f177  89841480040000         -mov dword ptr [esp + edx + 0x480], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1152) /* 0x480 */ + cpu.edx * 1) = cpu.eax;
    // 0050f17e  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0050f180  0f8cf2030000           -jl 0x50f578
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0050f578;
    }
    // 0050f186  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0050f188  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 0050f18b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0050f18d  0f84be040000           -je 0x50f651
    if (cpu.flags.zf)
    {
        goto L_0x0050f651;
    }
    // 0050f193  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
L_0x0050f198:
    // 0050f198  01f6                   -add esi, esi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.esi));
    // 0050f19a  40                     -inc eax
    (cpu.eax)++;
    // 0050f19b  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0050f19d  7df9                   -jge 0x50f198
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0050f198;
    }
    // 0050f19f  8d50ff                 -lea edx, [eax - 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(-1) /* -0x1 */);
    // 0050f1a2  29d7                   -sub edi, edx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0050f1a4  01f6                   -add esi, esi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.esi));
    // 0050f1a6  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0050f1a8  0f8c40040000           -jl 0x50f5ee
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0050f5ee;
    }
L_0x0050f1ae:
    // 0050f1ae  8b942434050000         -mov edx, dword ptr [esp + 0x534]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 0050f1b5  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 0050f1b8  89942410050000         -mov dword ptr [esp + 0x510], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1296) /* 0x510 */) = cpu.edx;
    // 0050f1bf  8b942430050000         -mov edx, dword ptr [esp + 0x530]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0050f1c6  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0050f1c9  89942428050000         -mov dword ptr [esp + 0x528], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1320) /* 0x528 */) = cpu.edx;
    // 0050f1d0  83f810                 +cmp eax, 0x10
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
    // 0050f1d3  0f8ec5050000           -jle 0x50f79e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0050f79e;
    }
    // 0050f1d9  b920000000             -mov ecx, 0x20
    cpu.ecx = 32 /*0x20*/;
    // 0050f1de  8d58f0                 -lea ebx, [eax - 0x10]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(-16) /* -0x10 */);
    // 0050f1e1  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0050f1e3  29d9                   -sub ecx, ebx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0050f1e5  d3ea                   -shr edx, cl
    cpu.edx >>= cpu.cl % 32;
    // 0050f1e7  88d9                   -mov cl, bl
    cpu.cl = cpu.bl;
    // 0050f1e9  29df                   -sub edi, ebx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0050f1eb  d3e6                   -shl esi, cl
    cpu.esi <<= cpu.cl % 32;
    // 0050f1ed  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0050f1ef  0f8cd9040000           -jl 0x50f6ce
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0050f6ce;
    }
L_0x0050f1f5:
    // 0050f1f5  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0050f1f7  83ef10                 -sub edi, 0x10
    (cpu.edi) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0050f1fa  c1e610                 -shl esi, 0x10
    cpu.esi <<= 16 /*0x10*/ % 32;
    // 0050f1fd  c1eb10                 -shr ebx, 0x10
    cpu.ebx >>= 16 /*0x10*/ % 32;
    // 0050f200  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0050f202  0f8c1e050000           -jl 0x50f726
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0050f726;
    }
L_0x0050f208:
    // 0050f208  88c1                   -mov cl, al
    cpu.cl = cpu.al;
    // 0050f20a  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0050f20d  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0050f212  09da                   -or edx, ebx
    cpu.edx |= x86::reg32(x86::sreg32(cpu.ebx));
L_0x0050f214:
    // 0050f214  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 0050f216  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
L_0x0050f218:
    // 0050f218  83ea04                 -sub edx, 4
    (cpu.edx) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0050f21b  8b9c24e4040000         -mov ebx, dword ptr [esp + 0x4e4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1252) /* 0x4e4 */);
    // 0050f222  8b84241c050000         -mov eax, dword ptr [esp + 0x51c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1308) /* 0x51c */);
    // 0050f229  01d5                   -add ebp, edx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.edx));
    // 0050f22b  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0050f22d  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0050f22f  89940400040000         -mov dword ptr [esp + eax + 0x400], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1024) /* 0x400 */ + cpu.eax * 1) = cpu.edx;
    // 0050f236  899c24e4040000         -mov dword ptr [esp + 0x4e4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1252) /* 0x4e4 */) = cpu.ebx;
    // 0050f23d  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0050f23f  7413                   -je 0x50f254
    if (cpu.flags.zf)
    {
        goto L_0x0050f254;
    }
    // 0050f241  8a8c2418050000         -mov cl, byte ptr [esp + 0x518]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1304) /* 0x518 */);
    // 0050f248  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0050f24a  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 0050f24c  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0050f24e  81e1ffff0000           -and ecx, 0xffff
    cpu.ecx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
L_0x0050f254:
    // 0050f254  8b84241c050000         -mov eax, dword ptr [esp + 0x51c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1308) /* 0x51c */);
    // 0050f25b  898c0440040000         -mov dword ptr [esp + eax + 0x440], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1088) /* 0x440 */ + cpu.eax * 1) = cpu.ecx;
    // 0050f262  8b842418050000         -mov eax, dword ptr [esp + 0x518]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1304) /* 0x518 */);
    // 0050f269  48                     -dec eax
    (cpu.eax)--;
    // 0050f26a  8b9c241c050000         -mov ebx, dword ptr [esp + 0x51c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1308) /* 0x51c */);
    // 0050f271  89842418050000         -mov dword ptr [esp + 0x518], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1304) /* 0x518 */) = cpu.eax;
    // 0050f278  8b8424d8040000         -mov eax, dword ptr [esp + 0x4d8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1240) /* 0x4d8 */);
    // 0050f27f  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0050f282  40                     -inc eax
    (cpu.eax)++;
    // 0050f283  899c241c050000         -mov dword ptr [esp + 0x51c], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1308) /* 0x51c */) = cpu.ebx;
    // 0050f28a  898424d8040000         -mov dword ptr [esp + 0x4d8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1240) /* 0x4d8 */) = cpu.eax;
    // 0050f291  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0050f293  0f84cafeffff           -je 0x50f163
    if (cpu.flags.zf)
    {
        goto L_0x0050f163;
    }
    // 0050f299  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0050f29b  0f85c2feffff           -jne 0x50f163
    if (!cpu.flags.zf)
    {
        goto L_0x0050f163;
    }
    // 0050f2a1  48                     -dec eax
    (cpu.eax)--;
    // 0050f2a2  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 0050f2a7  898424dc040000         -mov dword ptr [esp + 0x4dc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1244) /* 0x4dc */) = cpu.eax;
    // 0050f2ae  89948440040000         -mov dword ptr [esp + eax*4 + 0x440], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1088) /* 0x440 */ + cpu.eax * 4) = cpu.edx;
    // 0050f2b5  ba10000000             -mov edx, 0x10
    cpu.edx = 16 /*0x10*/;
    // 0050f2ba  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
L_0x0050f2bc:
    // 0050f2bc  83c010                 +add eax, 0x10
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0050f2bf  8948f4                 -mov dword ptr [eax - 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-12) /* -0xc */) = cpu.ecx;
    // 0050f2c2  8948f8                 -mov dword ptr [eax - 8], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-8) /* -0x8 */) = cpu.ecx;
    // 0050f2c5  8948fc                 -mov dword ptr [eax - 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
    // 0050f2c8  8948f0                 -mov dword ptr [eax - 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-16) /* -0x10 */) = cpu.ecx;
    // 0050f2cb  4a                     +dec edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0050f2cc  75ee                   -jne 0x50f2bc
    if (!cpu.flags.zf)
    {
        goto L_0x0050f2bc;
    }
    // 0050f2ce  8b9c24e4040000         -mov ebx, dword ptr [esp + 0x4e4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1252) /* 0x4e4 */);
    // 0050f2d5  b0ff                   -mov al, 0xff
    cpu.al = 255 /*0xff*/;
    // 0050f2d7  899424e0040000         -mov dword ptr [esp + 0x4e0], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1248) /* 0x4e0 */) = cpu.edx;
    // 0050f2de  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0050f2e0  0f8efc000000           -jle 0x50f3e2
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0050f3e2;
    }
L_0x0050f2e6:
    // 0050f2e6  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0050f2e8  0f8c30050000           -jl 0x50f81e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0050f81e;
    }
    // 0050f2ee  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0050f2f0  c1ea10                 -shr edx, 0x10
    cpu.edx >>= 16 /*0x10*/ % 32;
    // 0050f2f3  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0050f2f5  0f84f7050000           -je 0x50f8f2
    if (cpu.flags.zf)
    {
        goto L_0x0050f8f2;
    }
    // 0050f2fb  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
L_0x0050f300:
    // 0050f300  01f6                   -add esi, esi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.esi));
    // 0050f302  42                     -inc edx
    (cpu.edx)++;
    // 0050f303  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0050f305  7df9                   -jge 0x50f300
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0050f300;
    }
    // 0050f307  8d4aff                 -lea ecx, [edx - 1]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 0050f30a  29cf                   -sub edi, ecx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0050f30c  01f6                   -add esi, esi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.esi));
    // 0050f30e  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0050f310  0f8c7e050000           -jl 0x50f894
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0050f894;
    }
L_0x0050f316:
    // 0050f316  8b8c2430050000         -mov ecx, dword ptr [esp + 0x530]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0050f31d  8bac2434050000         -mov ebp, dword ptr [esp + 0x534]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 0050f324  83c102                 -add ecx, 2
    (cpu.ecx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0050f327  c1e508                 -shl ebp, 8
    cpu.ebp <<= 8 /*0x8*/ % 32;
    // 0050f32a  898c242c050000         -mov dword ptr [esp + 0x52c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1324) /* 0x52c */) = cpu.ecx;
    // 0050f331  83fa10                 +cmp edx, 0x10
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
    // 0050f334  0f8ecf060000           -jle 0x50fa09
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0050fa09;
    }
    // 0050f33a  8d4af0                 -lea ecx, [edx - 0x10]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(-16) /* -0x10 */);
    // 0050f33d  898c240c050000         -mov dword ptr [esp + 0x50c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1292) /* 0x50c */) = cpu.ecx;
    // 0050f344  b920000000             -mov ecx, 0x20
    cpu.ecx = 32 /*0x20*/;
    // 0050f349  2b8c240c050000         -sub ecx, dword ptr [esp + 0x50c]
    (cpu.ecx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1292) /* 0x50c */)));
    // 0050f350  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0050f352  d3eb                   -shr ebx, cl
    cpu.ebx >>= cpu.cl % 32;
    // 0050f354  8a8c240c050000         -mov cl, byte ptr [esp + 0x50c]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1292) /* 0x50c */);
    // 0050f35b  d3e6                   -shl esi, cl
    cpu.esi <<= cpu.cl % 32;
    // 0050f35d  2bbc240c050000         -sub edi, dword ptr [esp + 0x50c]
    (cpu.edi) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1292) /* 0x50c */)));
    // 0050f364  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0050f366  0f8c03060000           -jl 0x50f96f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0050f96f;
    }
L_0x0050f36c:
    // 0050f36c  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0050f36e  83ef10                 -sub edi, 0x10
    (cpu.edi) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0050f371  c1e910                 -shr ecx, 0x10
    cpu.ecx >>= 16 /*0x10*/ % 32;
    // 0050f374  c1e610                 -shl esi, 0x10
    cpu.esi <<= 16 /*0x10*/ % 32;
    // 0050f377  898c24e8040000         -mov dword ptr [esp + 0x4e8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1256) /* 0x4e8 */) = cpu.ecx;
    // 0050f37e  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0050f380  0f8c29060000           -jl 0x50f9af
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0050f9af;
    }
L_0x0050f386:
    // 0050f386  8b8c24e8040000         -mov ecx, dword ptr [esp + 0x4e8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1256) /* 0x4e8 */);
    // 0050f38d  c1e310                 -shl ebx, 0x10
    cpu.ebx <<= 16 /*0x10*/ % 32;
    // 0050f390  09cb                   -or ebx, ecx
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.ecx));
L_0x0050f392:
    // 0050f392  88d1                   -mov cl, dl
    cpu.cl = cpu.dl;
    // 0050f394  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0050f399  d3e2                   -shl edx, cl
    cpu.edx <<= cpu.cl % 32;
    // 0050f39b  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
L_0x0050f39d:
    // 0050f39d  83eb04                 -sub ebx, 4
    (cpu.ebx) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0050f3a0  43                     -inc ebx
    (cpu.ebx)++;
    // 0050f3a1  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x0050f3a3:
    // 0050f3a3  fec0                   -inc al
    (cpu.al)++;
    // 0050f3a5  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0050f3a7  88c2                   -mov dl, al
    cpu.dl = cpu.al;
    // 0050f3a9  3a0c14                 +cmp cl, byte ptr [esp + edx]
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.esp + cpu.edx * 1)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0050f3ac  7501                   -jne 0x50f3af
    if (!cpu.flags.zf)
    {
        goto L_0x0050f3af;
    }
    // 0050f3ae  4b                     -dec ebx
    (cpu.ebx)--;
L_0x0050f3af:
    // 0050f3af  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0050f3b1  75f0                   -jne 0x50f3a3
    if (!cpu.flags.zf)
    {
        goto L_0x0050f3a3;
    }
    // 0050f3b3  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0050f3b5  88c2                   -mov dl, al
    cpu.dl = cpu.al;
    // 0050f3b7  c6041401               -mov byte ptr [esp + edx], 1
    app->getMemory<x86::reg8>(cpu.esp + cpu.edx * 1) = 1 /*0x1*/;
    // 0050f3bb  8b9424e0040000         -mov edx, dword ptr [esp + 0x4e0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1248) /* 0x4e0 */);
    // 0050f3c2  8b8c24e4040000         -mov ecx, dword ptr [esp + 0x4e4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1252) /* 0x4e4 */);
    // 0050f3c9  8d6a01                 -lea ebp, [edx + 1]
    cpu.ebp = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 0050f3cc  88841400030000         -mov byte ptr [esp + edx + 0x300], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(768) /* 0x300 */ + cpu.edx * 1) = cpu.al;
    // 0050f3d3  89ac24e0040000         -mov dword ptr [esp + 0x4e0], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1248) /* 0x4e0 */) = cpu.ebp;
    // 0050f3da  39cd                   +cmp ebp, ecx
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
    // 0050f3dc  0f8c04ffffff           -jl 0x50f2e6
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0050f2e6;
    }
L_0x0050f3e2:
    // 0050f3e2  8d942400020000         -lea edx, [esp + 0x200]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(512) /* 0x200 */);
    // 0050f3e9  bb40404040             -mov ebx, 0x40404040
    cpu.ebx = 1077952576 /*0x40404040*/;
    // 0050f3ee  b910000000             -mov ecx, 0x10
    cpu.ecx = 16 /*0x10*/;
L_0x0050f3f3:
    // 0050f3f3  83c210                 +add edx, 0x10
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0050f3f6  895af4                 -mov dword ptr [edx - 0xc], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-12) /* -0xc */) = cpu.ebx;
    // 0050f3f9  895af8                 -mov dword ptr [edx - 8], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-8) /* -0x8 */) = cpu.ebx;
    // 0050f3fc  895afc                 -mov dword ptr [edx - 4], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */) = cpu.ebx;
    // 0050f3ff  895af0                 -mov dword ptr [edx - 0x10], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-16) /* -0x10 */) = cpu.ebx;
    // 0050f402  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0050f403  75ee                   -jne 0x50f3f3
    if (!cpu.flags.zf)
    {
        goto L_0x0050f3f3;
    }
    // 0050f405  8d842400030000         -lea eax, [esp + 0x300]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(768) /* 0x300 */);
    // 0050f40c  8d9c2400010000         -lea ebx, [esp + 0x100]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 0050f413  8d942400020000         -lea edx, [esp + 0x200]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(512) /* 0x200 */);
    // 0050f41a  898424fc040000         -mov dword ptr [esp + 0x4fc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1276) /* 0x4fc */) = cpu.eax;
    // 0050f421  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0050f426  8b8c24dc040000         -mov ecx, dword ptr [esp + 0x4dc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1244) /* 0x4dc */);
    // 0050f42d  898424ec040000         -mov dword ptr [esp + 0x4ec], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1260) /* 0x4ec */) = cpu.eax;
    // 0050f434  39c1                   +cmp ecx, eax
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
    // 0050f436  0f8c22faffff           -jl 0x50ee5e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0050ee5e;
    }
    // 0050f43c  b907000000             -mov ecx, 7
    cpu.ecx = 7 /*0x7*/;
    // 0050f441  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 0050f446  898c2424050000         -mov dword ptr [esp + 0x524], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1316) /* 0x524 */) = cpu.ecx;
    // 0050f44d  89842420050000         -mov dword ptr [esp + 0x520], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1312) /* 0x520 */) = cpu.eax;
L_0x0050f454:
    // 0050f454  8b842420050000         -mov eax, dword ptr [esp + 0x520]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1312) /* 0x520 */);
    // 0050f45b  8b840400040000         -mov eax, dword ptr [esp + eax + 0x400]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1024) /* 0x400 */ + cpu.eax * 1);
    // 0050f462  8bac24ec040000         -mov ebp, dword ptr [esp + 0x4ec]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1260) /* 0x4ec */);
    // 0050f469  898424f0040000         -mov dword ptr [esp + 0x4f0], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1264) /* 0x4f0 */) = cpu.eax;
    // 0050f470  83fd09                 +cmp ebp, 9
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(9 /*0x9*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050f473  0f8de5f9ffff           -jge 0x50ee5e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0050ee5e;
    }
    // 0050f479  8a8c2424050000         -mov cl, byte ptr [esp + 0x524]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1316) /* 0x524 */);
    // 0050f480  bd01000000             -mov ebp, 1
    cpu.ebp = 1 /*0x1*/;
    // 0050f485  d3e5                   -shl ebp, cl
    cpu.ebp <<= cpu.cl % 32;
L_0x0050f487:
    // 0050f487  8b8424f0040000         -mov eax, dword ptr [esp + 0x4f0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1264) /* 0x4f0 */);
    // 0050f48e  48                     -dec eax
    (cpu.eax)--;
    // 0050f48f  898424f0040000         -mov dword ptr [esp + 0x4f0], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1264) /* 0x4f0 */) = cpu.eax;
    // 0050f496  83f8ff                 +cmp eax, -1
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
    // 0050f499  0f84c3050000           -je 0x50fa62
    if (cpu.flags.zf)
    {
        goto L_0x0050fa62;
    }
    // 0050f49f  8b8c24fc040000         -mov ecx, dword ptr [esp + 0x4fc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1276) /* 0x4fc */);
    // 0050f4a6  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0050f4a8  8a01                   -mov al, byte ptr [ecx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx);
    // 0050f4aa  41                     -inc ecx
    (cpu.ecx)++;
    // 0050f4ab  898424f4040000         -mov dword ptr [esp + 0x4f4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1268) /* 0x4f4 */) = cpu.eax;
    // 0050f4b2  8b8424ec040000         -mov eax, dword ptr [esp + 0x4ec]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1260) /* 0x4ec */);
    // 0050f4b9  898c24fc040000         -mov dword ptr [esp + 0x4fc], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1276) /* 0x4fc */) = cpu.ecx;
    // 0050f4c0  898424f8040000         -mov dword ptr [esp + 0x4f8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1272) /* 0x4f8 */) = cpu.eax;
    // 0050f4c7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0050f4c9  8b8c24f4040000         -mov ecx, dword ptr [esp + 0x4f4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1268) /* 0x4f4 */);
    // 0050f4d0  8a842440050000         -mov al, byte ptr [esp + 0x540]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1344) /* 0x540 */);
    // 0050f4d7  39c8                   +cmp eax, ecx
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
    // 0050f4d9  7519                   -jne 0x50f4f4
    if (!cpu.flags.zf)
    {
        goto L_0x0050f4f4;
    }
    // 0050f4db  8b8424ec040000         -mov eax, dword ptr [esp + 0x4ec]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1260) /* 0x4ec */);
    // 0050f4e2  898424d0040000         -mov dword ptr [esp + 0x4d0], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1232) /* 0x4d0 */) = cpu.eax;
    // 0050f4e9  c78424f804000060000000 -mov dword ptr [esp + 0x4f8], 0x60
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1272) /* 0x4f8 */) = 96 /*0x60*/;
L_0x0050f4f4:
    // 0050f4f4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0050f4f6  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0050f4f8  7e8d                   -jle 0x50f487
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0050f487;
    }
L_0x0050f4fa:
    // 0050f4fa  43                     -inc ebx
    (cpu.ebx)++;
    // 0050f4fb  8a8c24f4040000         -mov cl, byte ptr [esp + 0x4f4]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1268) /* 0x4f4 */);
    // 0050f502  42                     -inc edx
    (cpu.edx)++;
    // 0050f503  884bff                 -mov byte ptr [ebx - 1], cl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(-1) /* -0x1 */) = cpu.cl;
    // 0050f506  8a8c24f8040000         -mov cl, byte ptr [esp + 0x4f8]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1272) /* 0x4f8 */);
    // 0050f50d  40                     -inc eax
    (cpu.eax)++;
    // 0050f50e  884aff                 -mov byte ptr [edx - 1], cl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-1) /* -0x1 */) = cpu.cl;
    // 0050f511  39e8                   +cmp eax, ebp
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
    // 0050f513  7ce5                   -jl 0x50f4fa
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0050f4fa;
    }
    // 0050f515  e96dffffff             -jmp 0x50f487
    goto L_0x0050f487;
L_0x0050f51a:
    // 0050f51a  8b842430050000         -mov eax, dword ptr [esp + 0x530]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0050f521  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0050f523  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 0050f525  8b842434050000         -mov eax, dword ptr [esp + 0x534]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 0050f52c  8b9c2430050000         -mov ebx, dword ptr [esp + 0x530]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0050f533  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 0050f536  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0050f538  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 0050f53a  8b842430050000         -mov eax, dword ptr [esp + 0x530]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0050f541  89942434050000         -mov dword ptr [esp + 0x534], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.edx;
    // 0050f548  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0050f54a  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0050f54c  8a5001                 -mov dl, byte ptr [eax + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0050f54f  8b842434050000         -mov eax, dword ptr [esp + 0x534]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 0050f556  83c302                 -add ebx, 2
    (cpu.ebx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0050f559  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 0050f55c  83c710                 -add edi, 0x10
    (cpu.edi) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0050f55f  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 0050f561  899c2430050000         -mov dword ptr [esp + 0x530], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */) = cpu.ebx;
    // 0050f568  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0050f56a  89942434050000         -mov dword ptr [esp + 0x534], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.edx;
    // 0050f571  d3e6                   +shl esi, cl
    {
        x86::reg8 tmp = cpu.cl % 32;
        x86::reg32& op = cpu.esi;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 0050f573  e9befbffff             -jmp 0x50f136
    goto L_0x0050f136;
L_0x0050f578:
    // 0050f578  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0050f57a  83ef03                 -sub edi, 3
    (cpu.edi) -= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0050f57d  c1e603                 -shl esi, 3
    cpu.esi <<= 3 /*0x3*/ % 32;
    // 0050f580  c1ea1d                 -shr edx, 0x1d
    cpu.edx >>= 29 /*0x1d*/ % 32;
    // 0050f583  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0050f585  0f8d8dfcffff           -jge 0x50f218
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0050f218;
    }
    // 0050f58b  8b842430050000         -mov eax, dword ptr [esp + 0x530]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0050f592  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0050f594  8a08                   -mov cl, byte ptr [eax]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax);
    // 0050f596  8b842434050000         -mov eax, dword ptr [esp + 0x534]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 0050f59d  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 0050f5a0  09c1                   -or ecx, eax
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.eax));
    // 0050f5a2  8b842430050000         -mov eax, dword ptr [esp + 0x530]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0050f5a9  898c2434050000         -mov dword ptr [esp + 0x534], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.ecx;
    // 0050f5b0  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0050f5b2  8a4801                 -mov cl, byte ptr [eax + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0050f5b5  8b842434050000         -mov eax, dword ptr [esp + 0x534]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 0050f5bc  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 0050f5bf  09c1                   -or ecx, eax
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.eax));
    // 0050f5c1  898c2434050000         -mov dword ptr [esp + 0x534], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.ecx;
    // 0050f5c8  8b842430050000         -mov eax, dword ptr [esp + 0x530]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0050f5cf  8bb42434050000         -mov esi, dword ptr [esp + 0x534]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 0050f5d6  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0050f5d8  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0050f5db  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0050f5dd  89842430050000         -mov dword ptr [esp + 0x530], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */) = cpu.eax;
    // 0050f5e4  83c710                 -add edi, 0x10
    (cpu.edi) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0050f5e7  d3e6                   +shl esi, cl
    {
        x86::reg8 tmp = cpu.cl % 32;
        x86::reg32& op = cpu.esi;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 0050f5e9  e92afcffff             -jmp 0x50f218
    goto L_0x0050f218;
L_0x0050f5ee:
    // 0050f5ee  8b942430050000         -mov edx, dword ptr [esp + 0x530]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0050f5f5  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0050f5f7  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 0050f5f9  8b942434050000         -mov edx, dword ptr [esp + 0x534]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 0050f600  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 0050f603  09d1                   -or ecx, edx
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.edx));
    // 0050f605  8b942430050000         -mov edx, dword ptr [esp + 0x530]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0050f60c  898c2434050000         -mov dword ptr [esp + 0x534], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.ecx;
    // 0050f613  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0050f615  8a4a01                 -mov cl, byte ptr [edx + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 0050f618  8b942434050000         -mov edx, dword ptr [esp + 0x534]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 0050f61f  8b9c2430050000         -mov ebx, dword ptr [esp + 0x530]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0050f626  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 0050f629  83c302                 -add ebx, 2
    (cpu.ebx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0050f62c  09d1                   -or ecx, edx
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.edx));
    // 0050f62e  899c2430050000         -mov dword ptr [esp + 0x530], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */) = cpu.ebx;
    // 0050f635  898c2434050000         -mov dword ptr [esp + 0x534], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.ecx;
    // 0050f63c  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0050f63e  8bb42434050000         -mov esi, dword ptr [esp + 0x534]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 0050f645  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0050f647  83c710                 -add edi, 0x10
    (cpu.edi) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0050f64a  d3e6                   +shl esi, cl
    {
        x86::reg8 tmp = cpu.cl % 32;
        x86::reg32& op = cpu.esi;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 0050f64c  e95dfbffff             -jmp 0x50f1ae
    goto L_0x0050f1ae;
L_0x0050f651:
    // 0050f651  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
L_0x0050f656:
    // 0050f656  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0050f658  40                     -inc eax
    (cpu.eax)++;
    // 0050f659  4f                     -dec edi
    (cpu.edi)--;
    // 0050f65a  c1ea1f                 -shr edx, 0x1f
    cpu.edx >>= 31 /*0x1f*/ % 32;
    // 0050f65d  01f6                   -add esi, esi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.esi));
    // 0050f65f  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0050f661  7c09                   -jl 0x50f66c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0050f66c;
    }
    // 0050f663  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0050f665  74ef                   -je 0x50f656
    if (cpu.flags.zf)
    {
        goto L_0x0050f656;
    }
    // 0050f667  e942fbffff             -jmp 0x50f1ae
    goto L_0x0050f1ae;
L_0x0050f66c:
    // 0050f66c  8b9c2430050000         -mov ebx, dword ptr [esp + 0x530]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0050f673  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0050f675  8a0b                   -mov cl, byte ptr [ebx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ebx);
    // 0050f677  8b9c2434050000         -mov ebx, dword ptr [esp + 0x534]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 0050f67e  c1e308                 -shl ebx, 8
    cpu.ebx <<= 8 /*0x8*/ % 32;
    // 0050f681  09d9                   -or ecx, ebx
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.ebx));
    // 0050f683  898c2434050000         -mov dword ptr [esp + 0x534], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.ecx;
    // 0050f68a  8b8c2430050000         -mov ecx, dword ptr [esp + 0x530]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0050f691  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0050f693  8a5901                 -mov bl, byte ptr [ecx + 1]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 0050f696  8b8c2434050000         -mov ecx, dword ptr [esp + 0x534]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 0050f69d  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 0050f6a0  09cb                   -or ebx, ecx
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.ecx));
    // 0050f6a2  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0050f6a4  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 0050f6a6  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0050f6a8  d3e6                   -shl esi, cl
    cpu.esi <<= cpu.cl % 32;
    // 0050f6aa  8b8c2430050000         -mov ecx, dword ptr [esp + 0x530]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0050f6b1  899c2434050000         -mov dword ptr [esp + 0x534], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.ebx;
    // 0050f6b8  83c102                 -add ecx, 2
    (cpu.ecx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0050f6bb  83c710                 -add edi, 0x10
    (cpu.edi) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0050f6be  898c2430050000         -mov dword ptr [esp + 0x530], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */) = cpu.ecx;
    // 0050f6c5  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0050f6c7  748d                   -je 0x50f656
    if (cpu.flags.zf)
    {
        goto L_0x0050f656;
    }
    // 0050f6c9  e9e0faffff             -jmp 0x50f1ae
    goto L_0x0050f1ae;
L_0x0050f6ce:
    // 0050f6ce  8b9c2430050000         -mov ebx, dword ptr [esp + 0x530]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0050f6d5  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0050f6d7  8a0b                   -mov cl, byte ptr [ebx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ebx);
    // 0050f6d9  8b9c2410050000         -mov ebx, dword ptr [esp + 0x510]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1296) /* 0x510 */);
    // 0050f6e0  09cb                   -or ebx, ecx
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.ecx));
    // 0050f6e2  8b8c2430050000         -mov ecx, dword ptr [esp + 0x530]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0050f6e9  899c2434050000         -mov dword ptr [esp + 0x534], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.ebx;
    // 0050f6f0  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0050f6f2  8a5901                 -mov bl, byte ptr [ecx + 1]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 0050f6f5  8b8c2434050000         -mov ecx, dword ptr [esp + 0x534]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 0050f6fc  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 0050f6ff  09cb                   -or ebx, ecx
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.ecx));
    // 0050f701  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0050f703  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 0050f705  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0050f707  899c2434050000         -mov dword ptr [esp + 0x534], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.ebx;
    // 0050f70e  d3e6                   -shl esi, cl
    cpu.esi <<= cpu.cl % 32;
    // 0050f710  8b8c2428050000         -mov ecx, dword ptr [esp + 0x528]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1320) /* 0x528 */);
    // 0050f717  83c710                 +add edi, 0x10
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0050f71a  898c2430050000         -mov dword ptr [esp + 0x530], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */) = cpu.ecx;
    // 0050f721  e9cffaffff             -jmp 0x50f1f5
    goto L_0x0050f1f5;
L_0x0050f726:
    // 0050f726  8bb42430050000         -mov esi, dword ptr [esp + 0x530]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0050f72d  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0050f72f  8a0e                   -mov cl, byte ptr [esi]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi);
    // 0050f731  898c240c050000         -mov dword ptr [esp + 0x50c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1292) /* 0x50c */) = cpu.ecx;
    // 0050f738  8b8c2434050000         -mov ecx, dword ptr [esp + 0x534]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 0050f73f  8bb4240c050000         -mov esi, dword ptr [esp + 0x50c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1292) /* 0x50c */);
    // 0050f746  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 0050f749  09ce                   -or esi, ecx
    cpu.esi |= x86::reg32(x86::sreg32(cpu.ecx));
    // 0050f74b  89b42434050000         -mov dword ptr [esp + 0x534], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.esi;
    // 0050f752  8bb42430050000         -mov esi, dword ptr [esp + 0x530]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0050f759  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0050f75b  8a4e01                 -mov cl, byte ptr [esi + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0050f75e  898c240c050000         -mov dword ptr [esp + 0x50c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1292) /* 0x50c */) = cpu.ecx;
    // 0050f765  8b8c2434050000         -mov ecx, dword ptr [esp + 0x534]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 0050f76c  8bb4240c050000         -mov esi, dword ptr [esp + 0x50c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1292) /* 0x50c */);
    // 0050f773  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 0050f776  09ce                   -or esi, ecx
    cpu.esi |= x86::reg32(x86::sreg32(cpu.ecx));
    // 0050f778  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0050f77a  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0050f77c  89b42434050000         -mov dword ptr [esp + 0x534], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.esi;
    // 0050f783  d3e6                   -shl esi, cl
    cpu.esi <<= cpu.cl % 32;
    // 0050f785  8b8c2430050000         -mov ecx, dword ptr [esp + 0x530]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0050f78c  83c102                 -add ecx, 2
    (cpu.ecx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0050f78f  83c710                 +add edi, 0x10
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0050f792  898c2430050000         -mov dword ptr [esp + 0x530], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */) = cpu.ecx;
    // 0050f799  e96afaffff             -jmp 0x50f208
    goto L_0x0050f208;
L_0x0050f79e:
    // 0050f79e  b920000000             -mov ecx, 0x20
    cpu.ecx = 32 /*0x20*/;
    // 0050f7a3  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0050f7a5  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0050f7a7  d3ea                   -shr edx, cl
    cpu.edx >>= cpu.cl % 32;
    // 0050f7a9  88c1                   -mov cl, al
    cpu.cl = cpu.al;
    // 0050f7ab  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0050f7ad  d3e6                   -shl esi, cl
    cpu.esi <<= cpu.cl % 32;
    // 0050f7af  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0050f7b1  7c0c                   -jl 0x50f7bf
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0050f7bf;
    }
    // 0050f7b3  88c1                   -mov cl, al
    cpu.cl = cpu.al;
    // 0050f7b5  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0050f7ba  e955faffff             -jmp 0x50f214
    goto L_0x0050f214;
L_0x0050f7bf:
    // 0050f7bf  8b9c2430050000         -mov ebx, dword ptr [esp + 0x530]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0050f7c6  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0050f7c8  8a0b                   -mov cl, byte ptr [ebx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ebx);
    // 0050f7ca  8b9c2410050000         -mov ebx, dword ptr [esp + 0x510]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1296) /* 0x510 */);
    // 0050f7d1  09cb                   -or ebx, ecx
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.ecx));
    // 0050f7d3  8b8c2430050000         -mov ecx, dword ptr [esp + 0x530]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0050f7da  899c2434050000         -mov dword ptr [esp + 0x534], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.ebx;
    // 0050f7e1  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0050f7e3  8a5901                 -mov bl, byte ptr [ecx + 1]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 0050f7e6  8b8c2434050000         -mov ecx, dword ptr [esp + 0x534]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 0050f7ed  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 0050f7f0  09cb                   -or ebx, ecx
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.ecx));
    // 0050f7f2  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0050f7f4  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 0050f7f6  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0050f7f8  899c2434050000         -mov dword ptr [esp + 0x534], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.ebx;
    // 0050f7ff  d3e6                   -shl esi, cl
    cpu.esi <<= cpu.cl % 32;
    // 0050f801  8b8c2428050000         -mov ecx, dword ptr [esp + 0x528]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1320) /* 0x528 */);
    // 0050f808  83c710                 +add edi, 0x10
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0050f80b  898c2430050000         -mov dword ptr [esp + 0x530], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */) = cpu.ecx;
    // 0050f812  88c1                   -mov cl, al
    cpu.cl = cpu.al;
    // 0050f814  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0050f819  e9f6f9ffff             -jmp 0x50f214
    goto L_0x0050f214;
L_0x0050f81e:
    // 0050f81e  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0050f820  83ef03                 -sub edi, 3
    (cpu.edi) -= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0050f823  c1e603                 -shl esi, 3
    cpu.esi <<= 3 /*0x3*/ % 32;
    // 0050f826  c1eb1d                 -shr ebx, 0x1d
    cpu.ebx >>= 29 /*0x1d*/ % 32;
    // 0050f829  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0050f82b  0f8d6cfbffff           -jge 0x50f39d
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0050f39d;
    }
    // 0050f831  8b942430050000         -mov edx, dword ptr [esp + 0x530]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0050f838  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0050f83a  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 0050f83c  8b942434050000         -mov edx, dword ptr [esp + 0x534]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 0050f843  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 0050f846  09d1                   -or ecx, edx
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.edx));
    // 0050f848  8b942430050000         -mov edx, dword ptr [esp + 0x530]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0050f84f  898c2434050000         -mov dword ptr [esp + 0x534], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.ecx;
    // 0050f856  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0050f858  8a4a01                 -mov cl, byte ptr [edx + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 0050f85b  8b942434050000         -mov edx, dword ptr [esp + 0x534]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 0050f862  8bac2430050000         -mov ebp, dword ptr [esp + 0x530]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0050f869  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 0050f86c  83c502                 -add ebp, 2
    (cpu.ebp) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0050f86f  09d1                   -or ecx, edx
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.edx));
    // 0050f871  89ac2430050000         -mov dword ptr [esp + 0x530], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */) = cpu.ebp;
    // 0050f878  898c2434050000         -mov dword ptr [esp + 0x534], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.ecx;
    // 0050f87f  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0050f881  8bb42434050000         -mov esi, dword ptr [esp + 0x534]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 0050f888  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0050f88a  83c710                 -add edi, 0x10
    (cpu.edi) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0050f88d  d3e6                   +shl esi, cl
    {
        x86::reg8 tmp = cpu.cl % 32;
        x86::reg32& op = cpu.esi;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 0050f88f  e909fbffff             -jmp 0x50f39d
    goto L_0x0050f39d;
L_0x0050f894:
    // 0050f894  8b9c2430050000         -mov ebx, dword ptr [esp + 0x530]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0050f89b  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0050f89d  8a0b                   -mov cl, byte ptr [ebx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ebx);
    // 0050f89f  8b9c2434050000         -mov ebx, dword ptr [esp + 0x534]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 0050f8a6  c1e308                 -shl ebx, 8
    cpu.ebx <<= 8 /*0x8*/ % 32;
    // 0050f8a9  09d9                   -or ecx, ebx
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.ebx));
    // 0050f8ab  898c2434050000         -mov dword ptr [esp + 0x534], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.ecx;
    // 0050f8b2  8b8c2430050000         -mov ecx, dword ptr [esp + 0x530]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0050f8b9  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0050f8bb  8a5901                 -mov bl, byte ptr [ecx + 1]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 0050f8be  8b8c2434050000         -mov ecx, dword ptr [esp + 0x534]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 0050f8c5  8bac2430050000         -mov ebp, dword ptr [esp + 0x530]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0050f8cc  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 0050f8cf  83c502                 -add ebp, 2
    (cpu.ebp) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0050f8d2  09cb                   -or ebx, ecx
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.ecx));
    // 0050f8d4  89ac2430050000         -mov dword ptr [esp + 0x530], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */) = cpu.ebp;
    // 0050f8db  899c2434050000         -mov dword ptr [esp + 0x534], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.ebx;
    // 0050f8e2  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0050f8e4  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 0050f8e6  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0050f8e8  83c710                 -add edi, 0x10
    (cpu.edi) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0050f8eb  d3e6                   +shl esi, cl
    {
        x86::reg8 tmp = cpu.cl % 32;
        x86::reg32& op = cpu.esi;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 0050f8ed  e924faffff             -jmp 0x50f316
    goto L_0x0050f316;
L_0x0050f8f2:
    // 0050f8f2  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
L_0x0050f8f7:
    // 0050f8f7  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
    // 0050f8f9  42                     -inc edx
    (cpu.edx)++;
    // 0050f8fa  4f                     -dec edi
    (cpu.edi)--;
    // 0050f8fb  c1ed1f                 -shr ebp, 0x1f
    cpu.ebp >>= 31 /*0x1f*/ % 32;
    // 0050f8fe  01f6                   -add esi, esi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.esi));
    // 0050f900  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0050f902  7c09                   -jl 0x50f90d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0050f90d;
    }
    // 0050f904  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0050f906  74ef                   -je 0x50f8f7
    if (cpu.flags.zf)
    {
        goto L_0x0050f8f7;
    }
    // 0050f908  e909faffff             -jmp 0x50f316
    goto L_0x0050f316;
L_0x0050f90d:
    // 0050f90d  8b8c2430050000         -mov ecx, dword ptr [esp + 0x530]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0050f914  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0050f916  8a19                   -mov bl, byte ptr [ecx]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx);
    // 0050f918  8b8c2434050000         -mov ecx, dword ptr [esp + 0x534]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 0050f91f  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 0050f922  09cb                   -or ebx, ecx
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.ecx));
    // 0050f924  8b8c2430050000         -mov ecx, dword ptr [esp + 0x530]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0050f92b  899c2434050000         -mov dword ptr [esp + 0x534], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.ebx;
    // 0050f932  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0050f934  8a5901                 -mov bl, byte ptr [ecx + 1]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 0050f937  8b8c2434050000         -mov ecx, dword ptr [esp + 0x534]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 0050f93e  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 0050f941  09cb                   -or ebx, ecx
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.ecx));
    // 0050f943  899c2434050000         -mov dword ptr [esp + 0x534], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.ebx;
    // 0050f94a  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0050f94c  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 0050f94e  8b9c2430050000         -mov ebx, dword ptr [esp + 0x530]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0050f955  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0050f957  83c710                 -add edi, 0x10
    (cpu.edi) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0050f95a  83c302                 -add ebx, 2
    (cpu.ebx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0050f95d  d3e6                   -shl esi, cl
    cpu.esi <<= cpu.cl % 32;
    // 0050f95f  899c2430050000         -mov dword ptr [esp + 0x530], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */) = cpu.ebx;
    // 0050f966  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0050f968  748d                   -je 0x50f8f7
    if (cpu.flags.zf)
    {
        goto L_0x0050f8f7;
    }
    // 0050f96a  e9a7f9ffff             -jmp 0x50f316
    goto L_0x0050f316;
L_0x0050f96f:
    // 0050f96f  8bb42430050000         -mov esi, dword ptr [esp + 0x530]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0050f976  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0050f978  8a0e                   -mov cl, byte ptr [esi]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi);
    // 0050f97a  09e9                   -or ecx, ebp
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.ebp));
    // 0050f97c  0fb67601               -movzx esi, byte ptr [esi + 1]
    cpu.esi = x86::reg32(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */));
    // 0050f980  898c2434050000         -mov dword ptr [esp + 0x534], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.ecx;
    // 0050f987  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 0050f98a  09ce                   -or esi, ecx
    cpu.esi |= x86::reg32(x86::sreg32(cpu.ecx));
    // 0050f98c  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0050f98e  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0050f990  89b42434050000         -mov dword ptr [esp + 0x534], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.esi;
    // 0050f997  d3e6                   -shl esi, cl
    cpu.esi <<= cpu.cl % 32;
    // 0050f999  8b8c242c050000         -mov ecx, dword ptr [esp + 0x52c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1324) /* 0x52c */);
    // 0050f9a0  83c710                 +add edi, 0x10
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0050f9a3  898c2430050000         -mov dword ptr [esp + 0x530], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */) = cpu.ecx;
    // 0050f9aa  e9bdf9ffff             -jmp 0x50f36c
    goto L_0x0050f36c;
L_0x0050f9af:
    // 0050f9af  8b8c2434050000         -mov ecx, dword ptr [esp + 0x534]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 0050f9b6  8bb42430050000         -mov esi, dword ptr [esp + 0x530]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0050f9bd  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 0050f9c0  0fb636                 -movzx esi, byte ptr [esi]
    cpu.esi = x86::reg32(app->getMemory<x86::reg8>(cpu.esi));
    // 0050f9c3  09ce                   -or esi, ecx
    cpu.esi |= x86::reg32(x86::sreg32(cpu.ecx));
    // 0050f9c5  8bac2430050000         -mov ebp, dword ptr [esp + 0x530]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0050f9cc  89b42434050000         -mov dword ptr [esp + 0x534], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.esi;
    // 0050f9d3  83c502                 -add ebp, 2
    (cpu.ebp) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0050f9d6  8b8c2434050000         -mov ecx, dword ptr [esp + 0x534]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 0050f9dd  8bb42430050000         -mov esi, dword ptr [esp + 0x530]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0050f9e4  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 0050f9e7  0fb67601               -movzx esi, byte ptr [esi + 1]
    cpu.esi = x86::reg32(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */));
    // 0050f9eb  89ac2430050000         -mov dword ptr [esp + 0x530], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */) = cpu.ebp;
    // 0050f9f2  09ce                   -or esi, ecx
    cpu.esi |= x86::reg32(x86::sreg32(cpu.ecx));
    // 0050f9f4  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0050f9f6  89b42434050000         -mov dword ptr [esp + 0x534], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.esi;
    // 0050f9fd  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0050f9ff  83c710                 -add edi, 0x10
    (cpu.edi) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0050fa02  d3e6                   +shl esi, cl
    {
        x86::reg8 tmp = cpu.cl % 32;
        x86::reg32& op = cpu.esi;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 0050fa04  e97df9ffff             -jmp 0x50f386
    goto L_0x0050f386;
L_0x0050fa09:
    // 0050fa09  b920000000             -mov ecx, 0x20
    cpu.ecx = 32 /*0x20*/;
    // 0050fa0e  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0050fa10  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0050fa12  d3eb                   -shr ebx, cl
    cpu.ebx >>= cpu.cl % 32;
    // 0050fa14  88d1                   -mov cl, dl
    cpu.cl = cpu.dl;
    // 0050fa16  29d7                   -sub edi, edx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0050fa18  d3e6                   -shl esi, cl
    cpu.esi <<= cpu.cl % 32;
    // 0050fa1a  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0050fa1c  0f8d70f9ffff           -jge 0x50f392
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0050f392;
    }
    // 0050fa22  8bb42430050000         -mov esi, dword ptr [esp + 0x530]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0050fa29  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0050fa2b  8a0e                   -mov cl, byte ptr [esi]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi);
    // 0050fa2d  09e9                   -or ecx, ebp
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.ebp));
    // 0050fa2f  0fb67601               -movzx esi, byte ptr [esi + 1]
    cpu.esi = x86::reg32(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */));
    // 0050fa33  898c2434050000         -mov dword ptr [esp + 0x534], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.ecx;
    // 0050fa3a  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 0050fa3d  09ce                   -or esi, ecx
    cpu.esi |= x86::reg32(x86::sreg32(cpu.ecx));
    // 0050fa3f  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0050fa41  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0050fa43  89b42434050000         -mov dword ptr [esp + 0x534], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.esi;
    // 0050fa4a  d3e6                   -shl esi, cl
    cpu.esi <<= cpu.cl % 32;
    // 0050fa4c  8b8c242c050000         -mov ecx, dword ptr [esp + 0x52c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1324) /* 0x52c */);
    // 0050fa53  83c710                 +add edi, 0x10
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0050fa56  898c2430050000         -mov dword ptr [esp + 0x530], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */) = cpu.ecx;
    // 0050fa5d  e930f9ffff             -jmp 0x50f392
    goto L_0x0050f392;
L_0x0050fa62:
    // 0050fa62  8bac2420050000         -mov ebp, dword ptr [esp + 0x520]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1312) /* 0x520 */);
    // 0050fa69  8b842424050000         -mov eax, dword ptr [esp + 0x524]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1316) /* 0x524 */);
    // 0050fa70  8b8c24ec040000         -mov ecx, dword ptr [esp + 0x4ec]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1260) /* 0x4ec */);
    // 0050fa77  83c504                 -add ebp, 4
    (cpu.ebp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0050fa7a  48                     -dec eax
    (cpu.eax)--;
    // 0050fa7b  41                     -inc ecx
    (cpu.ecx)++;
    // 0050fa7c  89ac2420050000         -mov dword ptr [esp + 0x520], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1312) /* 0x520 */) = cpu.ebp;
    // 0050fa83  89842424050000         -mov dword ptr [esp + 0x524], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1316) /* 0x524 */) = cpu.eax;
    // 0050fa8a  8bac24dc040000         -mov ebp, dword ptr [esp + 0x4dc]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1244) /* 0x4dc */);
    // 0050fa91  898c24ec040000         -mov dword ptr [esp + 0x4ec], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1260) /* 0x4ec */) = cpu.ecx;
    // 0050fa98  39e9                   +cmp ecx, ebp
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
    // 0050fa9a  0f8eb4f9ffff           -jle 0x50f454
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0050f454;
    }
    // 0050faa0  e9b9f3ffff             -jmp 0x50ee5e
    goto L_0x0050ee5e;
L_0x0050faa5:
    // 0050faa5  83ef10                 -sub edi, 0x10
    (cpu.edi) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0050faa8  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0050faaa  83f860                 +cmp eax, 0x60
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(96 /*0x60*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050faad  7468                   -je 0x50fb17
    if (cpu.flags.zf)
    {
        goto L_0x0050fb17;
    }
    // 0050faaf  b808000000             -mov eax, 8
    cpu.eax = 8 /*0x8*/;
    // 0050fab4  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0050fab6  b920000000             -mov ecx, 0x20
    cpu.ecx = 32 /*0x20*/;
    // 0050fabb  c1ea10                 -shr edx, 0x10
    cpu.edx >>= 16 /*0x10*/ % 32;
L_0x0050fabe:
    // 0050fabe  40                     -inc eax
    (cpu.eax)++;
    // 0050fabf  8bac0c44040000         -mov ebp, dword ptr [esp + ecx + 0x444]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1092) /* 0x444 */ + cpu.ecx * 1);
    // 0050fac6  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0050fac9  39ea                   +cmp edx, ebp
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050facb  73f1                   -jae 0x50fabe
    if (!cpu.flags.cf)
    {
        goto L_0x0050fabe;
    }
L_0x0050facd:
    // 0050facd  b920000000             -mov ecx, 0x20
    cpu.ecx = 32 /*0x20*/;
    // 0050fad2  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0050fad4  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0050fad6  d3ea                   -shr edx, cl
    cpu.edx >>= cpu.cl % 32;
    // 0050fad8  88c1                   -mov cl, al
    cpu.cl = cpu.al;
    // 0050fada  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0050fadc  d3e6                   -shl esi, cl
    cpu.esi <<= cpu.cl % 32;
    // 0050fade  8b8c8480040000         -mov ecx, dword ptr [esp + eax*4 + 0x480]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1152) /* 0x480 */ + cpu.eax * 4);
    // 0050fae5  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0050fae7  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0050fae9  8a942440050000         -mov dl, byte ptr [esp + 0x540]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1344) /* 0x540 */);
    // 0050faf0  8a840400030000         -mov al, byte ptr [esp + eax + 0x300]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(768) /* 0x300 */ + cpu.eax * 1);
    // 0050faf7  38d0                   +cmp al, dl
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
    // 0050faf9  7425                   -je 0x50fb20
    if (cpu.flags.zf)
    {
        goto L_0x0050fb20;
    }
    // 0050fafb  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0050fafd  7c21                   -jl 0x50fb20
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0050fb20;
    }
    // 0050faff  8b9424d4040000         -mov edx, dword ptr [esp + 0x4d4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1236) /* 0x4d4 */);
    // 0050fb06  8802                   -mov byte ptr [edx], al
    app->getMemory<x86::reg8>(cpu.edx) = cpu.al;
    // 0050fb08  8d4201                 -lea eax, [edx + 1]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 0050fb0b  898424d4040000         -mov dword ptr [esp + 0x4d4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1236) /* 0x4d4 */) = cpu.eax;
    // 0050fb12  e95cf3ffff             -jmp 0x50ee73
    goto L_0x0050ee73;
L_0x0050fb17:
    // 0050fb17  8b8424d0040000         -mov eax, dword ptr [esp + 0x4d0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1232) /* 0x4d0 */);
    // 0050fb1e  ebad                   -jmp 0x50facd
    goto L_0x0050facd;
L_0x0050fb20:
    // 0050fb20  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0050fb22  7c21                   -jl 0x50fb45
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0050fb45;
    }
L_0x0050fb24:
    // 0050fb24  3a842440050000         +cmp al, byte ptr [esp + 0x540]
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1344) /* 0x540 */)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0050fb2b  747b                   -je 0x50fba8
    if (cpu.flags.zf)
    {
        goto L_0x0050fba8;
    }
    // 0050fb2d  8b9424d4040000         -mov edx, dword ptr [esp + 0x4d4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1236) /* 0x4d4 */);
    // 0050fb34  8d6a01                 -lea ebp, [edx + 1]
    cpu.ebp = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 0050fb37  8802                   -mov byte ptr [edx], al
    app->getMemory<x86::reg8>(cpu.edx) = cpu.al;
    // 0050fb39  89ac24d4040000         -mov dword ptr [esp + 0x4d4], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1236) /* 0x4d4 */) = cpu.ebp;
    // 0050fb40  e92ef3ffff             -jmp 0x50ee73
    goto L_0x0050ee73;
L_0x0050fb45:
    // 0050fb45  8b942430050000         -mov edx, dword ptr [esp + 0x530]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0050fb4c  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0050fb4e  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 0050fb50  8b942434050000         -mov edx, dword ptr [esp + 0x534]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 0050fb57  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 0050fb5a  09d1                   -or ecx, edx
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.edx));
    // 0050fb5c  8b942430050000         -mov edx, dword ptr [esp + 0x530]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0050fb63  898c2434050000         -mov dword ptr [esp + 0x534], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.ecx;
    // 0050fb6a  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0050fb6c  8a4a01                 -mov cl, byte ptr [edx + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 0050fb6f  8b942434050000         -mov edx, dword ptr [esp + 0x534]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 0050fb76  8bac2430050000         -mov ebp, dword ptr [esp + 0x530]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0050fb7d  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 0050fb80  83c502                 -add ebp, 2
    (cpu.ebp) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0050fb83  09d1                   -or ecx, edx
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.edx));
    // 0050fb85  89ac2430050000         -mov dword ptr [esp + 0x530], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */) = cpu.ebp;
    // 0050fb8c  898c2434050000         -mov dword ptr [esp + 0x534], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.ecx;
    // 0050fb93  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0050fb95  8bb42434050000         -mov esi, dword ptr [esp + 0x534]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 0050fb9c  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0050fb9e  83c710                 -add edi, 0x10
    (cpu.edi) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0050fba1  d3e6                   +shl esi, cl
    {
        x86::reg8 tmp = cpu.cl % 32;
        x86::reg32& op = cpu.esi;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 0050fba3  e97cffffff             -jmp 0x50fb24
    goto L_0x0050fb24;
L_0x0050fba8:
    // 0050fba8  8b9424d4040000         -mov edx, dword ptr [esp + 0x4d4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1236) /* 0x4d4 */);
    // 0050fbaf  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0050fbb1  0f8cf7000000           -jl 0x50fcae
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0050fcae;
    }
    // 0050fbb7  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0050fbb9  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 0050fbbc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0050fbbe  0f84c9010000           -je 0x50fd8d
    if (cpu.flags.zf)
    {
        goto L_0x0050fd8d;
    }
    // 0050fbc4  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
L_0x0050fbc9:
    // 0050fbc9  01f6                   -add esi, esi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.esi));
    // 0050fbcb  40                     -inc eax
    (cpu.eax)++;
    // 0050fbcc  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0050fbce  7df9                   -jge 0x50fbc9
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0050fbc9;
    }
    // 0050fbd0  8d48ff                 -lea ecx, [eax - 1]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(-1) /* -0x1 */);
    // 0050fbd3  29cf                   -sub edi, ecx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0050fbd5  01f6                   -add esi, esi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.esi));
    // 0050fbd7  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0050fbd9  0f8c5a010000           -jl 0x50fd39
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0050fd39;
    }
L_0x0050fbdf:
    // 0050fbdf  8b8c2434050000         -mov ecx, dword ptr [esp + 0x534]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 0050fbe6  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 0050fbe9  898c2414050000         -mov dword ptr [esp + 0x514], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1300) /* 0x514 */) = cpu.ecx;
    // 0050fbf0  8b8c2430050000         -mov ecx, dword ptr [esp + 0x530]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0050fbf7  83c102                 -add ecx, 2
    (cpu.ecx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0050fbfa  898c24c0040000         -mov dword ptr [esp + 0x4c0], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1216) /* 0x4c0 */) = cpu.ecx;
    // 0050fc01  83f810                 +cmp eax, 0x10
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
    // 0050fc04  0f8ec6020000           -jle 0x50fed0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0050fed0;
    }
    // 0050fc0a  8d48f0                 -lea ecx, [eax - 0x10]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(-16) /* -0x10 */);
    // 0050fc0d  898c240c050000         -mov dword ptr [esp + 0x50c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1292) /* 0x50c */) = cpu.ecx;
    // 0050fc14  b920000000             -mov ecx, 0x20
    cpu.ecx = 32 /*0x20*/;
    // 0050fc19  2b8c240c050000         -sub ecx, dword ptr [esp + 0x50c]
    (cpu.ecx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1292) /* 0x50c */)));
    // 0050fc20  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
    // 0050fc22  d3ed                   -shr ebp, cl
    cpu.ebp >>= cpu.cl % 32;
    // 0050fc24  8a8c240c050000         -mov cl, byte ptr [esp + 0x50c]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1292) /* 0x50c */);
    // 0050fc2b  d3e6                   -shl esi, cl
    cpu.esi <<= cpu.cl % 32;
    // 0050fc2d  2bbc240c050000         -sub edi, dword ptr [esp + 0x50c]
    (cpu.edi) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1292) /* 0x50c */)));
    // 0050fc34  89ac2404050000         -mov dword ptr [esp + 0x504], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1284) /* 0x504 */) = cpu.ebp;
    // 0050fc3b  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0050fc3d  0f8cd6010000           -jl 0x50fe19
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0050fe19;
    }
L_0x0050fc43:
    // 0050fc43  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0050fc45  83ef10                 -sub edi, 0x10
    (cpu.edi) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0050fc48  c1e910                 -shr ecx, 0x10
    cpu.ecx >>= 16 /*0x10*/ % 32;
    // 0050fc4b  c1e610                 -shl esi, 0x10
    cpu.esi <<= 16 /*0x10*/ % 32;
    // 0050fc4e  898c2408050000         -mov dword ptr [esp + 0x508], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1288) /* 0x508 */) = cpu.ecx;
    // 0050fc55  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0050fc57  0f8c11020000           -jl 0x50fe6e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0050fe6e;
    }
L_0x0050fc5d:
    // 0050fc5d  8b8c2404050000         -mov ecx, dword ptr [esp + 0x504]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1284) /* 0x504 */);
    // 0050fc64  8bac2408050000         -mov ebp, dword ptr [esp + 0x508]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1288) /* 0x508 */);
    // 0050fc6b  c1e110                 -shl ecx, 0x10
    cpu.ecx <<= 16 /*0x10*/ % 32;
    // 0050fc6e  09cd                   -or ebp, ecx
    cpu.ebp |= x86::reg32(x86::sreg32(cpu.ecx));
    // 0050fc70  88c1                   -mov cl, al
    cpu.cl = cpu.al;
    // 0050fc72  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0050fc77  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 0050fc79  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
L_0x0050fc7b:
    // 0050fc7b  83e804                 -sub eax, 4
    (cpu.eax) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0050fc7e  89842404050000         -mov dword ptr [esp + 0x504], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1284) /* 0x504 */) = cpu.eax;
L_0x0050fc85:
    // 0050fc85  8bac2404050000         -mov ebp, dword ptr [esp + 0x504]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1284) /* 0x504 */);
    // 0050fc8c  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0050fc8e  0f84c7020000           -je 0x50ff5b
    if (cpu.flags.zf)
    {
        goto L_0x0050ff5b;
    }
    // 0050fc94  8a4aff                 -mov cl, byte ptr [edx - 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 0050fc97  8d042a                 -lea eax, [edx + ebp]
    cpu.eax = x86::reg32(cpu.edx + cpu.ebp * 1);
L_0x0050fc9a:
    // 0050fc9a  42                     -inc edx
    (cpu.edx)++;
    // 0050fc9b  884aff                 -mov byte ptr [edx - 1], cl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-1) /* -0x1 */) = cpu.cl;
    // 0050fc9e  39c2                   +cmp edx, eax
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
    // 0050fca0  72f8                   -jb 0x50fc9a
    if (cpu.flags.cf)
    {
        goto L_0x0050fc9a;
    }
    // 0050fca2  899424d4040000         -mov dword ptr [esp + 0x4d4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1236) /* 0x4d4 */) = cpu.edx;
    // 0050fca9  e9c5f1ffff             -jmp 0x50ee73
    goto L_0x0050ee73;
L_0x0050fcae:
    // 0050fcae  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0050fcb0  83ef03                 -sub edi, 3
    (cpu.edi) -= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0050fcb3  c1e81d                 -shr eax, 0x1d
    cpu.eax >>= 29 /*0x1d*/ % 32;
    // 0050fcb6  c1e603                 -shl esi, 3
    cpu.esi <<= 3 /*0x3*/ % 32;
    // 0050fcb9  89842404050000         -mov dword ptr [esp + 0x504], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1284) /* 0x504 */) = cpu.eax;
    // 0050fcc0  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0050fcc2  7c0a                   -jl 0x50fcce
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0050fcce;
    }
    // 0050fcc4  83ac240405000004       +sub dword ptr [esp + 0x504], 4
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1284) /* 0x504 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0050fccc  ebb7                   -jmp 0x50fc85
    goto L_0x0050fc85;
L_0x0050fcce:
    // 0050fcce  8b8c2430050000         -mov ecx, dword ptr [esp + 0x530]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0050fcd5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0050fcd7  8a01                   -mov al, byte ptr [ecx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx);
    // 0050fcd9  8b8c2434050000         -mov ecx, dword ptr [esp + 0x534]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 0050fce0  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 0050fce3  09c8                   -or eax, ecx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ecx));
    // 0050fce5  89842434050000         -mov dword ptr [esp + 0x534], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.eax;
    // 0050fcec  8b842430050000         -mov eax, dword ptr [esp + 0x530]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0050fcf3  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0050fcf5  8a4801                 -mov cl, byte ptr [eax + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0050fcf8  8b842434050000         -mov eax, dword ptr [esp + 0x534]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 0050fcff  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 0050fd02  09c1                   -or ecx, eax
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.eax));
    // 0050fd04  898c2434050000         -mov dword ptr [esp + 0x534], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.ecx;
    // 0050fd0b  8b842430050000         -mov eax, dword ptr [esp + 0x530]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0050fd12  8bb42434050000         -mov esi, dword ptr [esp + 0x534]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 0050fd19  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0050fd1b  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0050fd1e  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0050fd20  89842430050000         -mov dword ptr [esp + 0x530], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */) = cpu.eax;
    // 0050fd27  83c710                 -add edi, 0x10
    (cpu.edi) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0050fd2a  d3e6                   -shl esi, cl
    cpu.esi <<= cpu.cl % 32;
    // 0050fd2c  83ac240405000004       +sub dword ptr [esp + 0x504], 4
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1284) /* 0x504 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0050fd34  e94cffffff             -jmp 0x50fc85
    goto L_0x0050fc85;
L_0x0050fd39:
    // 0050fd39  8bb42430050000         -mov esi, dword ptr [esp + 0x530]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0050fd40  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0050fd42  8a0e                   -mov cl, byte ptr [esi]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi);
    // 0050fd44  8bb42434050000         -mov esi, dword ptr [esp + 0x534]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 0050fd4b  8bac2430050000         -mov ebp, dword ptr [esp + 0x530]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0050fd52  c1e608                 -shl esi, 8
    cpu.esi <<= 8 /*0x8*/ % 32;
    // 0050fd55  83c502                 -add ebp, 2
    (cpu.ebp) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0050fd58  09f1                   -or ecx, esi
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.esi));
    // 0050fd5a  8bb42430050000         -mov esi, dword ptr [esp + 0x530]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0050fd61  898c2434050000         -mov dword ptr [esp + 0x534], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.ecx;
    // 0050fd68  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 0050fd6b  0fb67601               -movzx esi, byte ptr [esi + 1]
    cpu.esi = x86::reg32(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */));
    // 0050fd6f  89ac2430050000         -mov dword ptr [esp + 0x530], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */) = cpu.ebp;
    // 0050fd76  09ce                   -or esi, ecx
    cpu.esi |= x86::reg32(x86::sreg32(cpu.ecx));
    // 0050fd78  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0050fd7a  89b42434050000         -mov dword ptr [esp + 0x534], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.esi;
    // 0050fd81  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0050fd83  83c710                 -add edi, 0x10
    (cpu.edi) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0050fd86  d3e6                   +shl esi, cl
    {
        x86::reg8 tmp = cpu.cl % 32;
        x86::reg32& op = cpu.esi;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 0050fd88  e952feffff             -jmp 0x50fbdf
    goto L_0x0050fbdf;
L_0x0050fd8d:
    // 0050fd8d  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 0050fd92  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
L_0x0050fd94:
    // 0050fd94  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0050fd96  40                     -inc eax
    (cpu.eax)++;
    // 0050fd97  4f                     -dec edi
    (cpu.edi)--;
    // 0050fd98  c1e91f                 -shr ecx, 0x1f
    cpu.ecx >>= 31 /*0x1f*/ % 32;
    // 0050fd9b  01f6                   -add esi, esi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.esi));
    // 0050fd9d  898c2438050000         -mov dword ptr [esp + 0x538], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1336) /* 0x538 */) = cpu.ecx;
    // 0050fda4  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0050fda6  7c0e                   -jl 0x50fdb6
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0050fdb6;
    }
    // 0050fda8  3bac2438050000         +cmp ebp, dword ptr [esp + 0x538]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1336) /* 0x538 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050fdaf  74e3                   -je 0x50fd94
    if (cpu.flags.zf)
    {
        goto L_0x0050fd94;
    }
    // 0050fdb1  e929feffff             -jmp 0x50fbdf
    goto L_0x0050fbdf;
L_0x0050fdb6:
    // 0050fdb6  8b8c2434050000         -mov ecx, dword ptr [esp + 0x534]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 0050fdbd  8bb42430050000         -mov esi, dword ptr [esp + 0x530]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0050fdc4  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 0050fdc7  0fb636                 -movzx esi, byte ptr [esi]
    cpu.esi = x86::reg32(app->getMemory<x86::reg8>(cpu.esi));
    // 0050fdca  09ce                   -or esi, ecx
    cpu.esi |= x86::reg32(x86::sreg32(cpu.ecx));
    // 0050fdcc  89b42434050000         -mov dword ptr [esp + 0x534], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.esi;
    // 0050fdd3  8b8c2434050000         -mov ecx, dword ptr [esp + 0x534]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 0050fdda  8bb42430050000         -mov esi, dword ptr [esp + 0x530]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0050fde1  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 0050fde4  0fb67601               -movzx esi, byte ptr [esi + 1]
    cpu.esi = x86::reg32(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */));
    // 0050fde8  09ce                   -or esi, ecx
    cpu.esi |= x86::reg32(x86::sreg32(cpu.ecx));
    // 0050fdea  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0050fdec  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0050fdee  89b42434050000         -mov dword ptr [esp + 0x534], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.esi;
    // 0050fdf5  d3e6                   -shl esi, cl
    cpu.esi <<= cpu.cl % 32;
    // 0050fdf7  8b8c2430050000         -mov ecx, dword ptr [esp + 0x530]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0050fdfe  83c102                 -add ecx, 2
    (cpu.ecx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0050fe01  83c710                 -add edi, 0x10
    (cpu.edi) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0050fe04  898c2430050000         -mov dword ptr [esp + 0x530], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */) = cpu.ecx;
    // 0050fe0b  3bac2438050000         +cmp ebp, dword ptr [esp + 0x538]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1336) /* 0x538 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050fe12  7480                   -je 0x50fd94
    if (cpu.flags.zf)
    {
        goto L_0x0050fd94;
    }
    // 0050fe14  e9c6fdffff             -jmp 0x50fbdf
    goto L_0x0050fbdf;
L_0x0050fe19:
    // 0050fe19  8bb42430050000         -mov esi, dword ptr [esp + 0x530]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0050fe20  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0050fe22  8a0e                   -mov cl, byte ptr [esi]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi);
    // 0050fe24  8bb42414050000         -mov esi, dword ptr [esp + 0x514]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1300) /* 0x514 */);
    // 0050fe2b  09ce                   -or esi, ecx
    cpu.esi |= x86::reg32(x86::sreg32(cpu.ecx));
    // 0050fe2d  89b42434050000         -mov dword ptr [esp + 0x534], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.esi;
    // 0050fe34  8b8c2434050000         -mov ecx, dword ptr [esp + 0x534]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 0050fe3b  8bb42430050000         -mov esi, dword ptr [esp + 0x530]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0050fe42  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 0050fe45  0fb67601               -movzx esi, byte ptr [esi + 1]
    cpu.esi = x86::reg32(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */));
    // 0050fe49  09ce                   -or esi, ecx
    cpu.esi |= x86::reg32(x86::sreg32(cpu.ecx));
    // 0050fe4b  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0050fe4d  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0050fe4f  89b42434050000         -mov dword ptr [esp + 0x534], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.esi;
    // 0050fe56  d3e6                   -shl esi, cl
    cpu.esi <<= cpu.cl % 32;
    // 0050fe58  8b8c24c0040000         -mov ecx, dword ptr [esp + 0x4c0]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1216) /* 0x4c0 */);
    // 0050fe5f  83c710                 +add edi, 0x10
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0050fe62  898c2430050000         -mov dword ptr [esp + 0x530], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */) = cpu.ecx;
    // 0050fe69  e9d5fdffff             -jmp 0x50fc43
    goto L_0x0050fc43;
L_0x0050fe6e:
    // 0050fe6e  8b8c2434050000         -mov ecx, dword ptr [esp + 0x534]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 0050fe75  8bb42430050000         -mov esi, dword ptr [esp + 0x530]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0050fe7c  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 0050fe7f  0fb636                 -movzx esi, byte ptr [esi]
    cpu.esi = x86::reg32(app->getMemory<x86::reg8>(cpu.esi));
    // 0050fe82  09ce                   -or esi, ecx
    cpu.esi |= x86::reg32(x86::sreg32(cpu.ecx));
    // 0050fe84  89b42434050000         -mov dword ptr [esp + 0x534], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.esi;
    // 0050fe8b  8bb42430050000         -mov esi, dword ptr [esp + 0x530]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0050fe92  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0050fe94  8a4e01                 -mov cl, byte ptr [esi + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0050fe97  8bb42434050000         -mov esi, dword ptr [esp + 0x534]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 0050fe9e  8bac2430050000         -mov ebp, dword ptr [esp + 0x530]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0050fea5  c1e608                 -shl esi, 8
    cpu.esi <<= 8 /*0x8*/ % 32;
    // 0050fea8  83c502                 -add ebp, 2
    (cpu.ebp) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0050feab  09f1                   -or ecx, esi
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.esi));
    // 0050fead  89ac2430050000         -mov dword ptr [esp + 0x530], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */) = cpu.ebp;
    // 0050feb4  898c2434050000         -mov dword ptr [esp + 0x534], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.ecx;
    // 0050febb  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0050febd  8bb42434050000         -mov esi, dword ptr [esp + 0x534]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 0050fec4  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0050fec6  83c710                 -add edi, 0x10
    (cpu.edi) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0050fec9  d3e6                   +shl esi, cl
    {
        x86::reg8 tmp = cpu.cl % 32;
        x86::reg32& op = cpu.esi;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 0050fecb  e98dfdffff             -jmp 0x50fc5d
    goto L_0x0050fc5d;
L_0x0050fed0:
    // 0050fed0  b920000000             -mov ecx, 0x20
    cpu.ecx = 32 /*0x20*/;
    // 0050fed5  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
    // 0050fed7  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0050fed9  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0050fedb  d3ed                   -shr ebp, cl
    cpu.ebp >>= cpu.cl % 32;
    // 0050fedd  88c1                   -mov cl, al
    cpu.cl = cpu.al;
    // 0050fedf  89ac2404050000         -mov dword ptr [esp + 0x504], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1284) /* 0x504 */) = cpu.ebp;
    // 0050fee6  d3e6                   -shl esi, cl
    cpu.esi <<= cpu.cl % 32;
    // 0050fee8  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0050feea  7c15                   -jl 0x50ff01
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0050ff01;
    }
L_0x0050feec:
    // 0050feec  88c1                   -mov cl, al
    cpu.cl = cpu.al;
    // 0050feee  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0050fef3  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 0050fef5  03842404050000         +add eax, dword ptr [esp + 0x504]
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1284) /* 0x504 */)));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0050fefc  e97afdffff             -jmp 0x50fc7b
    goto L_0x0050fc7b;
L_0x0050ff01:
    // 0050ff01  8bb42430050000         -mov esi, dword ptr [esp + 0x530]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0050ff08  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0050ff0a  8a0e                   -mov cl, byte ptr [esi]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi);
    // 0050ff0c  8bb42414050000         -mov esi, dword ptr [esp + 0x514]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1300) /* 0x514 */);
    // 0050ff13  09ce                   -or esi, ecx
    cpu.esi |= x86::reg32(x86::sreg32(cpu.ecx));
    // 0050ff15  89b42434050000         -mov dword ptr [esp + 0x534], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.esi;
    // 0050ff1c  8bb42430050000         -mov esi, dword ptr [esp + 0x530]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0050ff23  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0050ff25  8a4e01                 -mov cl, byte ptr [esi + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0050ff28  8bb42434050000         -mov esi, dword ptr [esp + 0x534]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 0050ff2f  c1e608                 -shl esi, 8
    cpu.esi <<= 8 /*0x8*/ % 32;
    // 0050ff32  09f1                   -or ecx, esi
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.esi));
    // 0050ff34  898c2434050000         -mov dword ptr [esp + 0x534], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.ecx;
    // 0050ff3b  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0050ff3d  8bb42434050000         -mov esi, dword ptr [esp + 0x534]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 0050ff44  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0050ff46  d3e6                   -shl esi, cl
    cpu.esi <<= cpu.cl % 32;
    // 0050ff48  8b8c24c0040000         -mov ecx, dword ptr [esp + 0x4c0]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1216) /* 0x4c0 */);
    // 0050ff4f  83c710                 +add edi, 0x10
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0050ff52  898c2430050000         -mov dword ptr [esp + 0x530], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */) = cpu.ecx;
    // 0050ff59  eb91                   -jmp 0x50feec
    goto L_0x0050feec;
L_0x0050ff5b:
    // 0050ff5b  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
    // 0050ff5d  4f                     -dec edi
    (cpu.edi)--;
    // 0050ff5e  c1ed1f                 -shr ebp, 0x1f
    cpu.ebp >>= 31 /*0x1f*/ % 32;
    // 0050ff61  01f6                   -add esi, esi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.esi));
    // 0050ff63  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0050ff65  7c5b                   -jl 0x50ffc2
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0050ffc2;
    }
L_0x0050ff67:
    // 0050ff67  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0050ff69  0f84b1000000           -je 0x510020
    if (cpu.flags.zf)
    {
        goto L_0x00510020;
    }
    // 0050ff6f  8bbc24c4040000         -mov edi, dword ptr [esp + 0x4c4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1220) /* 0x4c4 */);
    // 0050ff76  8b9c24cc040000         -mov ebx, dword ptr [esp + 0x4cc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1228) /* 0x4cc */);
    // 0050ff7d  8bb424c8040000         -mov esi, dword ptr [esp + 0x4c8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1224) /* 0x4c8 */);
    // 0050ff84  01df                   -add edi, ebx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0050ff86  81fefb320000           +cmp esi, 0x32fb
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(13051 /*0x32fb*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050ff8c  0f851e010000           -jne 0x5100b0
    if (!cpu.flags.zf)
    {
        goto L_0x005100b0;
    }
    // 0050ff92  8b8424c4040000         -mov eax, dword ptr [esp + 0x4c4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1220) /* 0x4c4 */);
    // 0050ff99  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 0050ff9b  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0050ff9d  39c7                   +cmp edi, eax
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050ff9f  760f                   -jbe 0x50ffb0
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0050ffb0;
    }
L_0x0050ffa1:
    // 0050ffa1  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0050ffa3  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 0050ffa5  40                     -inc eax
    (cpu.eax)++;
    // 0050ffa6  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0050ffa8  8848ff                 -mov byte ptr [eax - 1], cl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(-1) /* -0x1 */) = cpu.cl;
    // 0050ffab  39d8                   +cmp eax, ebx
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
    // 0050ffad  72f2                   -jb 0x50ffa1
    if (cpu.flags.cf)
    {
        goto L_0x0050ffa1;
    }
    // 0050ffaf  90                     -nop 
    ;
L_0x0050ffb0:
    // 0050ffb0  8b8424cc040000         -mov eax, dword ptr [esp + 0x4cc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1228) /* 0x4cc */);
    // 0050ffb7  81c444050000           -add esp, 0x544
    (cpu.esp) += x86::reg32(x86::sreg32(1348 /*0x544*/));
    // 0050ffbd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050ffbe  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050ffbf  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050ffc0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050ffc1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050ffc2:
    // 0050ffc2  8b842430050000         -mov eax, dword ptr [esp + 0x530]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0050ffc9  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0050ffcb  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 0050ffcd  8b842434050000         -mov eax, dword ptr [esp + 0x534]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 0050ffd4  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 0050ffd7  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 0050ffd9  8b842430050000         -mov eax, dword ptr [esp + 0x530]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0050ffe0  89942434050000         -mov dword ptr [esp + 0x534], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.edx;
    // 0050ffe7  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0050ffe9  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0050ffeb  8a5001                 -mov dl, byte ptr [eax + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0050ffee  8b842434050000         -mov eax, dword ptr [esp + 0x534]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 0050fff5  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0050fff7  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 0050fffa  83c710                 -add edi, 0x10
    (cpu.edi) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0050fffd  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 0050ffff  8b842430050000         -mov eax, dword ptr [esp + 0x530]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 00510006  89942434050000         -mov dword ptr [esp + 0x534], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.edx;
    // 0051000d  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0051000f  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00510012  d3e6                   +shl esi, cl
    {
        x86::reg8 tmp = cpu.cl % 32;
        x86::reg32& op = cpu.esi;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 00510014  89842430050000         -mov dword ptr [esp + 0x530], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */) = cpu.eax;
    // 0051001b  e947ffffff             -jmp 0x50ff67
    goto L_0x0050ff67;
L_0x00510020:
    // 00510020  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00510022  83ef08                 -sub edi, 8
    (cpu.edi) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00510025  c1e818                 -shr eax, 0x18
    cpu.eax >>= 24 /*0x18*/ % 32;
    // 00510028  c1e608                 -shl esi, 8
    cpu.esi <<= 8 /*0x8*/ % 32;
    // 0051002b  8884243c050000         -mov byte ptr [esp + 0x53c], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1340) /* 0x53c */) = cpu.al;
    // 00510032  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00510034  7c1f                   -jl 0x510055
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00510055;
    }
L_0x00510036:
    // 00510036  8b9424d4040000         -mov edx, dword ptr [esp + 0x4d4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1236) /* 0x4d4 */);
    // 0051003d  8a84243c050000         -mov al, byte ptr [esp + 0x53c]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1340) /* 0x53c */);
    // 00510044  8d4a01                 -lea ecx, [edx + 1]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 00510047  8802                   -mov byte ptr [edx], al
    app->getMemory<x86::reg8>(cpu.edx) = cpu.al;
    // 00510049  898c24d4040000         -mov dword ptr [esp + 0x4d4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1236) /* 0x4d4 */) = cpu.ecx;
    // 00510050  e91eeeffff             -jmp 0x50ee73
    goto L_0x0050ee73;
L_0x00510055:
    // 00510055  8b842430050000         -mov eax, dword ptr [esp + 0x530]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0051005c  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0051005e  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 00510060  8b842434050000         -mov eax, dword ptr [esp + 0x534]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 00510067  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 0051006a  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 0051006c  8b842430050000         -mov eax, dword ptr [esp + 0x530]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 00510073  89942434050000         -mov dword ptr [esp + 0x534], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.edx;
    // 0051007a  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0051007c  8a5001                 -mov dl, byte ptr [eax + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0051007f  8b842434050000         -mov eax, dword ptr [esp + 0x534]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 00510086  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 00510089  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0051008b  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 0051008d  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0051008f  89942434050000         -mov dword ptr [esp + 0x534], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.edx;
    // 00510096  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00510098  8b942430050000         -mov edx, dword ptr [esp + 0x530]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 0051009f  83c710                 -add edi, 0x10
    (cpu.edi) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 005100a2  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 005100a5  d3e6                   +shl esi, cl
    {
        x86::reg8 tmp = cpu.cl % 32;
        x86::reg32& op = cpu.esi;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 005100a7  89942430050000         -mov dword ptr [esp + 0x530], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */) = cpu.edx;
    // 005100ae  eb86                   -jmp 0x510036
    goto L_0x00510036;
L_0x005100b0:
    // 005100b0  81fefb340000           +cmp esi, 0x34fb
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(13563 /*0x34fb*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005100b6  0f85f4feffff           -jne 0x50ffb0
    if (!cpu.flags.zf)
    {
        goto L_0x0050ffb0;
    }
    // 005100bc  8b8424c4040000         -mov eax, dword ptr [esp + 0x4c4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1220) /* 0x4c4 */);
    // 005100c3  89fe                   -mov esi, edi
    cpu.esi = cpu.edi;
    // 005100c5  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 005100c7  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 005100c9  39c7                   +cmp edi, eax
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005100cb  0f86dffeffff           -jbe 0x50ffb0
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0050ffb0;
    }
L_0x005100d1:
    // 005100d1  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 005100d3  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 005100d5  01d9                   -add ecx, ebx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 005100d7  40                     -inc eax
    (cpu.eax)++;
    // 005100d8  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 005100da  8850ff                 -mov byte ptr [eax - 1], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(-1) /* -0x1 */) = cpu.dl;
    // 005100dd  39f0                   +cmp eax, esi
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
    // 005100df  72f0                   -jb 0x5100d1
    if (cpu.flags.cf)
    {
        goto L_0x005100d1;
    }
    // 005100e1  8b8424cc040000         -mov eax, dword ptr [esp + 0x4cc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1228) /* 0x4cc */);
    // 005100e8  81c444050000           -add esp, 0x544
    (cpu.esp) += x86::reg32(x86::sreg32(1348 /*0x544*/));
    // 005100ee  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005100ef  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005100f0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005100f1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005100f2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_510110(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 00510110  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00510111  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00510112  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00510113  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00510114  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00510115  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00510118  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0051011a  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 0051011c  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 00510121  88642410               -mov byte ptr [esp + 0x10], ah
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ah;
    // 00510125  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00510127  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0051012b  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0051012d  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 0051012f  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 00510131  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 00510138  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 0051013a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0051013c  8d4502                 -lea eax, [ebp + 2]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(2) /* 0x2 */);
    // 0051013f  81fa314b0000           +cmp edx, 0x4b31
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(19249 /*0x4b31*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00510145  0f8498000000           -je 0x5101e3
    if (cpu.flags.zf)
    {
        goto L_0x005101e3;
    }
    // 0051014b  b903000000             -mov ecx, 3
    cpu.ecx = 3 /*0x3*/;
    // 00510150  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00510152  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 00510154  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 00510156  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 0051015d  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 0051015f  83c505                 -add ebp, 5
    (cpu.ebp) += x86::reg32(x86::sreg32(5 /*0x5*/));
L_0x00510162:
    // 00510162  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00510166  892c24                 -mov dword ptr [esp], ebp
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebp;
    // 00510169  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0051016d  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00510171  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00510173  7e61                   -jle 0x5101d6
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x005101d6;
    }
L_0x00510175:
    // 00510175  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00510178  8a00                   -mov al, byte ptr [eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax);
    // 0051017a  88c4                   -mov ah, al
    cpu.ah = cpu.al;
    // 0051017c  80e43f                 -and ah, 0x3f
    cpu.ah &= x86::reg8(x86::sreg8(63 /*0x3f*/));
    // 0051017f  0fb6ec                 -movzx ebp, ah
    cpu.ebp = x86::reg32(cpu.ah);
    // 00510182  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 00510185  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0051018a  43                     -inc ebx
    (cpu.ebx)++;
    // 0051018b  c1f806                 -sar eax, 6
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (6 /*0x6*/ % 32));
    // 0051018e  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 00510191  83f803                 +cmp eax, 3
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
    // 00510194  7739                   -ja 0x5101cf
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x005101cf;
    }
    // 00510196  ff248500015100         -jmp dword ptr [eax*4 + 0x510100]
    cpu.ip = app->getMemory<x86::reg32>(5308672 + cpu.eax * 4); goto dynamic_jump;
  case 0x0051019d:
    // 0051019d  8b7c240c               -mov edi, dword ptr [esp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 005101a1  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 005101a3  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 005101a5  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 005101a9  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 005101aa  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 005101ac  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 005101af  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 005101b1  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 005101b3  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 005101b6  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 005101b8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005101b9  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 005101bd  8d3c2b                 -lea edi, [ebx + ebp]
    cpu.edi = x86::reg32(cpu.ebx + cpu.ebp * 1);
    // 005101c0  29ea                   -sub edx, ebp
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 005101c2  893c24                 -mov dword ptr [esp], edi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edi;
    // 005101c5  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 005101c7  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 005101cb  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
L_0x005101cf:
    // 005101cf  837c240800             +cmp dword ptr [esp + 8], 0
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
    // 005101d4  7f9f                   -jg 0x510175
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00510175;
    }
L_0x005101d6:
    // 005101d6  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 005101da  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 005101dd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005101de  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005101df  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005101e0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005101e1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005101e2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005101e3:
    // 005101e3  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 005101e8  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 005101ea  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 005101ec  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 005101ee  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 005101f5  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 005101f7  83c504                 +add ebp, 4
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
    // 005101fa  e963ffffff             -jmp 0x510162
    goto L_0x00510162;
  case 0x005101ff:
    // 005101ff  8d4b01                 -lea ecx, [ebx + 1]
    cpu.ecx = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 00510202  8a03                   -mov al, byte ptr [ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx);
    // 00510204  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 00510207  88442410               -mov byte ptr [esp + 0x10], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.al;
  [[fallthrough]];
  case 0x0051020b:
    // 0051020b  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0051020f  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00510211  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 00510213  8a542410               -mov dl, byte ptr [esp + 0x10]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00510217  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0051021b  e82004fdff             -call 0x4e0640
    cpu.esp -= 4;
    sub_4e0640(app, cpu);
    if (cpu.terminate) return;
    // 00510220  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00510224  29ee                   -sub esi, ebp
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 00510226  01eb                   +add ebx, ebp
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00510228  89742408               -mov dword ptr [esp + 8], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.esi;
    // 0051022c  895c240c               -mov dword ptr [esp + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 00510230  eb9d                   -jmp 0x5101cf
    goto L_0x005101cf;
  case 0x00510232:
    // 00510232  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00510236  8d7301                 -lea esi, [ebx + 1]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 00510239  8a23                   -mov ah, byte ptr [ebx]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebx);
    // 0051023b  893424                 -mov dword ptr [esp], esi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.esi;
    // 0051023e  8d7a01                 -lea edi, [edx + 1]
    cpu.edi = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 00510241  8822                   -mov byte ptr [edx], ah
    app->getMemory<x86::reg8>(cpu.edx) = cpu.ah;
    // 00510243  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00510247  80e4f0                 -and ah, 0xf0
    cpu.ah &= x86::reg8(x86::sreg8(240 /*0xf0*/));
    // 0051024a  897c240c               -mov dword ptr [esp + 0xc], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edi;
    // 0051024e  29ea                   -sub edx, ebp
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 00510250  4d                     -dec ebp
    (cpu.ebp)--;
    // 00510251  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00510255  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00510257  0f8e72ffffff           -jle 0x5101cf
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x005101cf;
    }
L_0x0051025d:
    // 0051025d  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 00510260  8a02                   -mov al, byte ptr [edx]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx);
    // 00510262  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00510264  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00510266  88c2                   -mov dl, al
    cpu.dl = cpu.al;
    // 00510268  88e1                   -mov cl, ah
    cpu.cl = cpu.ah;
    // 0051026a  c1fa04                 -sar edx, 4
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (4 /*0x4*/ % 32));
    // 0051026d  09ca                   -or edx, ecx
    cpu.edx |= x86::reg32(x86::sreg32(cpu.ecx));
    // 0051026f  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00510273  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00510277  4d                     -dec ebp
    (cpu.ebp)--;
    // 00510278  8811                   -mov byte ptr [ecx], dl
    app->getMemory<x86::reg8>(cpu.ecx) = cpu.dl;
    // 0051027a  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 0051027d  43                     -inc ebx
    (cpu.ebx)++;
    // 0051027e  41                     -inc ecx
    (cpu.ecx)++;
    // 0051027f  895c240c               -mov dword ptr [esp + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 00510283  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 00510286  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00510288  7e0e                   -jle 0x510298
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00510298;
    }
    // 0051028a  240f                   -and al, 0xf
    cpu.al &= x86::reg8(x86::sreg8(15 /*0xf*/));
    // 0051028c  8d7301                 -lea esi, [ebx + 1]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 0051028f  4d                     -dec ebp
    (cpu.ebp)--;
    // 00510290  08e0                   -or al, ah
    cpu.al |= x86::reg8(x86::sreg8(cpu.ah));
    // 00510292  8974240c               -mov dword ptr [esp + 0xc], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.esi;
    // 00510296  8803                   -mov byte ptr [ebx], al
    app->getMemory<x86::reg8>(cpu.ebx) = cpu.al;
L_0x00510298:
    // 00510298  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0051029a  7fc1                   -jg 0x51025d
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0051025d;
    }
    // 0051029c  e92effffff             -jmp 0x5101cf
    goto L_0x005101cf;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_5102a4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005102a4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005102a5  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 005102a7  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 005102aa  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005102ab  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005102ac  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 005102ad  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 005102af  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 005102b1  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 005102b3  c745fc00000000         -mov dword ptr [ebp - 4], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = 0 /*0x0*/;
    // 005102ba  09db                   +or ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx |= x86::reg32(x86::sreg32(cpu.ebx))));
    // 005102bc  0f84dc000000           -je 0x51039e
    if (cpu.flags.zf)
    {
        return sub_51039e(app, cpu);
    }
    // 005102c2  668b03                 -mov ax, word ptr [ebx]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ebx);
    // 005102c5  8d5b02                 -lea ebx, [ebx + 2]
    cpu.ebx = x86::reg32(cpu.ebx + x86::reg32(2) /* 0x2 */);
    // 005102c8  2401                   +and al, 1
    cpu.clear_co();
    cpu.set_szp((cpu.al &= x86::reg8(x86::sreg8(1 /*0x1*/))));
    // 005102ca  7403                   -je 0x5102cf
    if (cpu.flags.zf)
    {
        goto L_0x005102cf;
    }
    // 005102cc  8d5b03                 -lea ebx, [ebx + 3]
    cpu.ebx = x86::reg32(cpu.ebx + x86::reg32(3) /* 0x3 */);
L_0x005102cf:
    // 005102cf  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 005102d1  8a03                   -mov al, byte ptr [ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx);
    // 005102d3  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 005102d6  8a6301                 -mov ah, byte ptr [ebx + 1]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 005102d9  8a4302                 -mov al, byte ptr [ebx + 2]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(2) /* 0x2 */);
    // 005102dc  8d5b03                 -lea ebx, [ebx + 3]
    cpu.ebx = x86::reg32(cpu.ebx + x86::reg32(3) /* 0x3 */);
    // 005102df  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 005102e2  83f900                 +cmp ecx, 0
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
    // 005102e5  0f84b3000000           -je 0x51039e
    if (cpu.flags.zf)
    {
        return sub_51039e(app, cpu);
    }
    // 005102eb  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 005102ed  eb48                   -jmp 0x510337
    return sub_510337(app, cpu);
}

/* align: skip 0x90 */
void Application::sub_5102f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
L_0x005102f0:
    // 005102f0  8d7302                 -lea esi, [ebx + 2]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(2) /* 0x2 */);
    // 005102f3  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    // 005102f5  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 005102f7  88d5                   -mov ch, dl
    cpu.ch = cpu.dl;
    // 005102f9  88f1                   -mov cl, dh
    cpu.cl = cpu.dh;
    // 005102fb  83e21c                 -and edx, 0x1c
    cpu.edx &= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 005102fe  c0ed05                 -shr ch, 5
    cpu.ch >>= 5 /*0x5*/ % 32;
    // 00510301  c1ea02                 -shr edx, 2
    cpu.edx >>= 2 /*0x2*/ % 32;
    // 00510304  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 00510306  8d740fff               -lea esi, [edi + ecx - 1]
    cpu.esi = x86::reg32(cpu.edi + x86::reg32(-1) /* -0x1 */ + cpu.ecx * 1);
    // 0051030a  8d4a03                 -lea ecx, [edx + 3]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(3) /* 0x3 */);
    // 0051030d  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0051030f  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00510311  0a0b                   +or cl, byte ptr [ebx]
    cpu.clear_co();
    cpu.set_szp((cpu.cl |= x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ebx)))));
    // 00510313  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 00510315  7828                   -js 0x51033f
    if (cpu.flags.sf)
    {
        goto L_0x0051033f;
    }
L_0x00510317:
    // 00510317  83e103                 +and ecx, 3
    cpu.clear_co();
    cpu.set_szp((cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/))));
    // 0051031a  75d4                   -jne 0x5102f0
    if (!cpu.flags.zf)
    {
        goto L_0x005102f0;
    }
    // 0051031c  8d5b02                 -lea ebx, [ebx + 2]
    cpu.ebx = x86::reg32(cpu.ebx + x86::reg32(2) /* 0x2 */);
    // 0051031f  88d5                   -mov ch, dl
    cpu.ch = cpu.dl;
    // 00510321  88f1                   -mov cl, dh
    cpu.cl = cpu.dh;
    // 00510323  83e21c                 -and edx, 0x1c
    cpu.edx &= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00510326  c0ed05                 -shr ch, 5
    cpu.ch >>= 5 /*0x5*/ % 32;
    // 00510329  c1ea02                 -shr edx, 2
    cpu.edx >>= 2 /*0x2*/ % 32;
    // 0051032c  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0051032e  8d740fff               -lea esi, [edi + ecx - 1]
    cpu.esi = x86::reg32(cpu.edi + x86::reg32(-1) /* -0x1 */ + cpu.ecx * 1);
    // 00510332  8d4a03                 -lea ecx, [edx + 3]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(3) /* 0x3 */);
    // 00510335  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00510337  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00510339  0a0b                   +or cl, byte ptr [ebx]
    cpu.clear_co();
    cpu.set_szp((cpu.cl |= x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ebx)))));
    // 0051033b  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 0051033d  79d8                   -jns 0x510317
    if (!cpu.flags.sf)
    {
        goto L_0x00510317;
    }
L_0x0051033f:
    // 0051033f  00c9                   +add cl, cl
    {
        x86::reg8& tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.cl));
        x86::reg8 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) == (1 & (tmp2 >> 7));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00510341  7831                   -js 0x510374
    if (cpu.flags.sf)
    {
        goto L_0x00510374;
    }
    // 00510343  88f1                   -mov cl, dh
    cpu.cl = cpu.dh;
    // 00510345  8d7303                 -lea esi, [ebx + 3]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(3) /* 0x3 */);
    // 00510348  c1e906                 -shr ecx, 6
    cpu.ecx >>= 6 /*0x6*/ % 32;
    // 0051034b  83e103                 -and ecx, 3
    cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0051034e  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00510350  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00510352  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00510354  c1e910                 -shr ecx, 0x10
    cpu.ecx >>= 16 /*0x10*/ % 32;
    // 00510357  88f5                   -mov ch, dh
    cpu.ch = cpu.dh;
    // 00510359  80e53f                 -and ch, 0x3f
    cpu.ch &= x86::reg8(x86::sreg8(63 /*0x3f*/));
    // 0051035c  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0051035e  8d740fff               -lea esi, [edi + ecx - 1]
    cpu.esi = x86::reg32(cpu.edi + x86::reg32(-1) /* -0x1 */ + cpu.ecx * 1);
    // 00510362  83e23f                 -and edx, 0x3f
    cpu.edx &= x86::reg32(x86::sreg32(63 /*0x3f*/));
    // 00510365  8d4a04                 -lea ecx, [edx + 4]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00510368  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0051036a  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0051036c  0a0b                   +or cl, byte ptr [ebx]
    cpu.clear_co();
    cpu.set_szp((cpu.cl |= x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ebx)))));
    // 0051036e  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 00510370  79a5                   -jns 0x510317
    if (!cpu.flags.sf)
    {
        goto L_0x00510317;
    }
    // 00510372  ebcb                   -jmp 0x51033f
    goto L_0x0051033f;
L_0x00510374:
    // 00510374  00c9                   +add cl, cl
    {
        x86::reg8& tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.cl));
        x86::reg8 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) == (1 & (tmp2 >> 7));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00510376  7930                   -jns 0x5103a8
    if (!cpu.flags.sf)
    {
        goto L_0x005103a8;
    }
    // 00510378  80fafc                 +cmp dl, 0xfc
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(252 /*0xfc*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0051037b  7317                   -jae 0x510394
    if (!cpu.flags.cf)
    {
        goto L_0x00510394;
    }
    // 0051037d  83e21f                 -and edx, 0x1f
    cpu.edx &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00510380  8d7301                 -lea esi, [ebx + 1]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 00510383  8d4a01                 -lea ecx, [edx + 1]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 00510386  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00510388  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0051038a  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0051038c  0a0e                   +or cl, byte ptr [esi]
    cpu.clear_co();
    cpu.set_szp((cpu.cl |= x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.esi)))));
    // 0051038e  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 00510390  7985                   -jns 0x510317
    if (!cpu.flags.sf)
    {
        goto L_0x00510317;
    }
    // 00510392  ebab                   -jmp 0x51033f
    goto L_0x0051033f;
L_0x00510394:
    // 00510394  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00510396  8d7301                 -lea esi, [ebx + 1]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 00510399  83e103                 -and ecx, 3
    cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0051039c  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0051039e  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 005103a1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005103a2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005103a3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005103a4  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 005103a6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005103a7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005103a8:
    // 005103a8  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 005103aa  8d7304                 -lea esi, [ebx + 4]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 005103ad  83e103                 -and ecx, 3
    cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 005103b0  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    // 005103b2  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 005103b4  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 005103b6  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 005103b8  83e110                 -and ecx, 0x10
    cpu.ecx &= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 005103bb  c1e808                 -shr eax, 8
    cpu.eax >>= 8 /*0x8*/ % 32;
    // 005103be  c1e10c                 -shl ecx, 0xc
    cpu.ecx <<= 12 /*0xc*/ % 32;
    // 005103c1  88e1                   -mov cl, ah
    cpu.cl = cpu.ah;
    // 005103c3  88c5                   -mov ch, al
    cpu.ch = cpu.al;
    // 005103c5  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 005103c7  8d740fff               -lea esi, [edi + ecx - 1]
    cpu.esi = x86::reg32(cpu.edi + x86::reg32(-1) /* -0x1 */ + cpu.ecx * 1);
    // 005103cb  c1c208                 -rol edx, 8
    {
        x86::reg32& op = cpu.edx;
        x86::reg32 shift = 8 /*0x8*/ % 32;
        while (shift)
        {
            x86::reg32 cf = (op & 0x80000000);
            op = op << 1 | cf >> 31;
            shift--;
        }
    }
    // 005103ce  c0ee02                 -shr dh, 2
    cpu.dh >>= 2 /*0x2*/ % 32;
    // 005103d1  81e2ff030000           -and edx, 0x3ff
    cpu.edx &= x86::reg32(x86::sreg32(1023 /*0x3ff*/));
    // 005103d7  83f9fc                 +cmp ecx, -4
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-4 /*-0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005103da  7d24                   -jge 0x510400
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00510400;
    }
    // 005103dc  8d4a05                 -lea ecx, [edx + 5]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(5) /* 0x5 */);
    // 005103df  8d5205                 -lea edx, [edx + 5]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(5) /* 0x5 */);
    // 005103e2  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 005103e5  83e203                 -and edx, 3
    cpu.edx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 005103e8  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 005103ea  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 005103ec  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    // 005103ee  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 005103f0  0a0b                   +or cl, byte ptr [ebx]
    cpu.clear_co();
    cpu.set_szp((cpu.cl |= x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ebx)))));
    // 005103f2  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 005103f4  0f891dffffff           -jns 0x510317
    if (!cpu.flags.sf)
    {
        goto L_0x00510317;
    }
    // 005103fa  e940ffffff             -jmp 0x51033f
    goto L_0x0051033f;
    // 005103ff  90                     -nop 
    ;
L_0x00510400:
    // 00510400  8d4a05                 -lea ecx, [edx + 5]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(5) /* 0x5 */);
    // 00510403  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00510405  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00510407  0a0b                   +or cl, byte ptr [ebx]
    cpu.clear_co();
    cpu.set_szp((cpu.cl |= x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ebx)))));
    // 00510409  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 0051040b  0f8906ffffff           -jns 0x510317
    if (!cpu.flags.sf)
    {
        goto L_0x00510317;
    }
    // 00510411  e929ffffff             -jmp 0x51033f
    goto L_0x0051033f;
}

/* align: skip  */
void Application::sub_51039e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x0051039e;
L_0x005102f0:
    // 005102f0  8d7302                 -lea esi, [ebx + 2]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(2) /* 0x2 */);
    // 005102f3  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    // 005102f5  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 005102f7  88d5                   -mov ch, dl
    cpu.ch = cpu.dl;
    // 005102f9  88f1                   -mov cl, dh
    cpu.cl = cpu.dh;
    // 005102fb  83e21c                 -and edx, 0x1c
    cpu.edx &= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 005102fe  c0ed05                 -shr ch, 5
    cpu.ch >>= 5 /*0x5*/ % 32;
    // 00510301  c1ea02                 -shr edx, 2
    cpu.edx >>= 2 /*0x2*/ % 32;
    // 00510304  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 00510306  8d740fff               -lea esi, [edi + ecx - 1]
    cpu.esi = x86::reg32(cpu.edi + x86::reg32(-1) /* -0x1 */ + cpu.ecx * 1);
    // 0051030a  8d4a03                 -lea ecx, [edx + 3]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(3) /* 0x3 */);
    // 0051030d  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0051030f  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00510311  0a0b                   +or cl, byte ptr [ebx]
    cpu.clear_co();
    cpu.set_szp((cpu.cl |= x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ebx)))));
    // 00510313  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 00510315  7828                   -js 0x51033f
    if (cpu.flags.sf)
    {
        goto L_0x0051033f;
    }
L_0x00510317:
    // 00510317  83e103                 +and ecx, 3
    cpu.clear_co();
    cpu.set_szp((cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/))));
    // 0051031a  75d4                   -jne 0x5102f0
    if (!cpu.flags.zf)
    {
        goto L_0x005102f0;
    }
    // 0051031c  8d5b02                 -lea ebx, [ebx + 2]
    cpu.ebx = x86::reg32(cpu.ebx + x86::reg32(2) /* 0x2 */);
    // 0051031f  88d5                   -mov ch, dl
    cpu.ch = cpu.dl;
    // 00510321  88f1                   -mov cl, dh
    cpu.cl = cpu.dh;
    // 00510323  83e21c                 -and edx, 0x1c
    cpu.edx &= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00510326  c0ed05                 -shr ch, 5
    cpu.ch >>= 5 /*0x5*/ % 32;
    // 00510329  c1ea02                 -shr edx, 2
    cpu.edx >>= 2 /*0x2*/ % 32;
    // 0051032c  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0051032e  8d740fff               -lea esi, [edi + ecx - 1]
    cpu.esi = x86::reg32(cpu.edi + x86::reg32(-1) /* -0x1 */ + cpu.ecx * 1);
    // 00510332  8d4a03                 -lea ecx, [edx + 3]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(3) /* 0x3 */);
    // 00510335  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00510337  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00510339  0a0b                   +or cl, byte ptr [ebx]
    cpu.clear_co();
    cpu.set_szp((cpu.cl |= x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ebx)))));
    // 0051033b  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 0051033d  79d8                   -jns 0x510317
    if (!cpu.flags.sf)
    {
        goto L_0x00510317;
    }
L_0x0051033f:
    // 0051033f  00c9                   +add cl, cl
    {
        x86::reg8& tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.cl));
        x86::reg8 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) == (1 & (tmp2 >> 7));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00510341  7831                   -js 0x510374
    if (cpu.flags.sf)
    {
        goto L_0x00510374;
    }
    // 00510343  88f1                   -mov cl, dh
    cpu.cl = cpu.dh;
    // 00510345  8d7303                 -lea esi, [ebx + 3]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(3) /* 0x3 */);
    // 00510348  c1e906                 -shr ecx, 6
    cpu.ecx >>= 6 /*0x6*/ % 32;
    // 0051034b  83e103                 -and ecx, 3
    cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0051034e  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00510350  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00510352  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00510354  c1e910                 -shr ecx, 0x10
    cpu.ecx >>= 16 /*0x10*/ % 32;
    // 00510357  88f5                   -mov ch, dh
    cpu.ch = cpu.dh;
    // 00510359  80e53f                 -and ch, 0x3f
    cpu.ch &= x86::reg8(x86::sreg8(63 /*0x3f*/));
    // 0051035c  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0051035e  8d740fff               -lea esi, [edi + ecx - 1]
    cpu.esi = x86::reg32(cpu.edi + x86::reg32(-1) /* -0x1 */ + cpu.ecx * 1);
    // 00510362  83e23f                 -and edx, 0x3f
    cpu.edx &= x86::reg32(x86::sreg32(63 /*0x3f*/));
    // 00510365  8d4a04                 -lea ecx, [edx + 4]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00510368  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0051036a  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0051036c  0a0b                   +or cl, byte ptr [ebx]
    cpu.clear_co();
    cpu.set_szp((cpu.cl |= x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ebx)))));
    // 0051036e  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 00510370  79a5                   -jns 0x510317
    if (!cpu.flags.sf)
    {
        goto L_0x00510317;
    }
    // 00510372  ebcb                   -jmp 0x51033f
    goto L_0x0051033f;
L_0x00510374:
    // 00510374  00c9                   +add cl, cl
    {
        x86::reg8& tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.cl));
        x86::reg8 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) == (1 & (tmp2 >> 7));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00510376  7930                   -jns 0x5103a8
    if (!cpu.flags.sf)
    {
        goto L_0x005103a8;
    }
    // 00510378  80fafc                 +cmp dl, 0xfc
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(252 /*0xfc*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0051037b  7317                   -jae 0x510394
    if (!cpu.flags.cf)
    {
        goto L_0x00510394;
    }
    // 0051037d  83e21f                 -and edx, 0x1f
    cpu.edx &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00510380  8d7301                 -lea esi, [ebx + 1]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 00510383  8d4a01                 -lea ecx, [edx + 1]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 00510386  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00510388  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0051038a  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0051038c  0a0e                   +or cl, byte ptr [esi]
    cpu.clear_co();
    cpu.set_szp((cpu.cl |= x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.esi)))));
    // 0051038e  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 00510390  7985                   -jns 0x510317
    if (!cpu.flags.sf)
    {
        goto L_0x00510317;
    }
    // 00510392  ebab                   -jmp 0x51033f
    goto L_0x0051033f;
L_0x00510394:
    // 00510394  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00510396  8d7301                 -lea esi, [ebx + 1]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 00510399  83e103                 -and ecx, 3
    cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0051039c  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
L_entry_0x0051039e:
    // 0051039e  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 005103a1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005103a2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005103a3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005103a4  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 005103a6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005103a7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005103a8:
    // 005103a8  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 005103aa  8d7304                 -lea esi, [ebx + 4]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 005103ad  83e103                 -and ecx, 3
    cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 005103b0  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    // 005103b2  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 005103b4  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 005103b6  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 005103b8  83e110                 -and ecx, 0x10
    cpu.ecx &= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 005103bb  c1e808                 -shr eax, 8
    cpu.eax >>= 8 /*0x8*/ % 32;
    // 005103be  c1e10c                 -shl ecx, 0xc
    cpu.ecx <<= 12 /*0xc*/ % 32;
    // 005103c1  88e1                   -mov cl, ah
    cpu.cl = cpu.ah;
    // 005103c3  88c5                   -mov ch, al
    cpu.ch = cpu.al;
    // 005103c5  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 005103c7  8d740fff               -lea esi, [edi + ecx - 1]
    cpu.esi = x86::reg32(cpu.edi + x86::reg32(-1) /* -0x1 */ + cpu.ecx * 1);
    // 005103cb  c1c208                 -rol edx, 8
    {
        x86::reg32& op = cpu.edx;
        x86::reg32 shift = 8 /*0x8*/ % 32;
        while (shift)
        {
            x86::reg32 cf = (op & 0x80000000);
            op = op << 1 | cf >> 31;
            shift--;
        }
    }
    // 005103ce  c0ee02                 -shr dh, 2
    cpu.dh >>= 2 /*0x2*/ % 32;
    // 005103d1  81e2ff030000           -and edx, 0x3ff
    cpu.edx &= x86::reg32(x86::sreg32(1023 /*0x3ff*/));
    // 005103d7  83f9fc                 +cmp ecx, -4
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-4 /*-0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005103da  7d24                   -jge 0x510400
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00510400;
    }
    // 005103dc  8d4a05                 -lea ecx, [edx + 5]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(5) /* 0x5 */);
    // 005103df  8d5205                 -lea edx, [edx + 5]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(5) /* 0x5 */);
    // 005103e2  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 005103e5  83e203                 -and edx, 3
    cpu.edx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 005103e8  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 005103ea  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 005103ec  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    // 005103ee  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 005103f0  0a0b                   +or cl, byte ptr [ebx]
    cpu.clear_co();
    cpu.set_szp((cpu.cl |= x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ebx)))));
    // 005103f2  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 005103f4  0f891dffffff           -jns 0x510317
    if (!cpu.flags.sf)
    {
        goto L_0x00510317;
    }
    // 005103fa  e940ffffff             -jmp 0x51033f
    goto L_0x0051033f;
    // 005103ff  90                     -nop 
    ;
L_0x00510400:
    // 00510400  8d4a05                 -lea ecx, [edx + 5]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(5) /* 0x5 */);
    // 00510403  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00510405  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00510407  0a0b                   +or cl, byte ptr [ebx]
    cpu.clear_co();
    cpu.set_szp((cpu.cl |= x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ebx)))));
    // 00510409  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 0051040b  0f8906ffffff           -jns 0x510317
    if (!cpu.flags.sf)
    {
        goto L_0x00510317;
    }
    // 00510411  e929ffffff             -jmp 0x51033f
    goto L_0x0051033f;
}

/* align: skip  */
void Application::sub_510337(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00510337;
L_0x005102f0:
    // 005102f0  8d7302                 -lea esi, [ebx + 2]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(2) /* 0x2 */);
    // 005102f3  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    // 005102f5  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 005102f7  88d5                   -mov ch, dl
    cpu.ch = cpu.dl;
    // 005102f9  88f1                   -mov cl, dh
    cpu.cl = cpu.dh;
    // 005102fb  83e21c                 -and edx, 0x1c
    cpu.edx &= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 005102fe  c0ed05                 -shr ch, 5
    cpu.ch >>= 5 /*0x5*/ % 32;
    // 00510301  c1ea02                 -shr edx, 2
    cpu.edx >>= 2 /*0x2*/ % 32;
    // 00510304  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 00510306  8d740fff               -lea esi, [edi + ecx - 1]
    cpu.esi = x86::reg32(cpu.edi + x86::reg32(-1) /* -0x1 */ + cpu.ecx * 1);
    // 0051030a  8d4a03                 -lea ecx, [edx + 3]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(3) /* 0x3 */);
    // 0051030d  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0051030f  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00510311  0a0b                   +or cl, byte ptr [ebx]
    cpu.clear_co();
    cpu.set_szp((cpu.cl |= x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ebx)))));
    // 00510313  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 00510315  7828                   -js 0x51033f
    if (cpu.flags.sf)
    {
        goto L_0x0051033f;
    }
L_0x00510317:
    // 00510317  83e103                 +and ecx, 3
    cpu.clear_co();
    cpu.set_szp((cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/))));
    // 0051031a  75d4                   -jne 0x5102f0
    if (!cpu.flags.zf)
    {
        goto L_0x005102f0;
    }
    // 0051031c  8d5b02                 -lea ebx, [ebx + 2]
    cpu.ebx = x86::reg32(cpu.ebx + x86::reg32(2) /* 0x2 */);
    // 0051031f  88d5                   -mov ch, dl
    cpu.ch = cpu.dl;
    // 00510321  88f1                   -mov cl, dh
    cpu.cl = cpu.dh;
    // 00510323  83e21c                 -and edx, 0x1c
    cpu.edx &= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00510326  c0ed05                 -shr ch, 5
    cpu.ch >>= 5 /*0x5*/ % 32;
    // 00510329  c1ea02                 -shr edx, 2
    cpu.edx >>= 2 /*0x2*/ % 32;
    // 0051032c  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0051032e  8d740fff               -lea esi, [edi + ecx - 1]
    cpu.esi = x86::reg32(cpu.edi + x86::reg32(-1) /* -0x1 */ + cpu.ecx * 1);
    // 00510332  8d4a03                 -lea ecx, [edx + 3]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(3) /* 0x3 */);
    // 00510335  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
L_entry_0x00510337:
    // 00510337  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00510339  0a0b                   +or cl, byte ptr [ebx]
    cpu.clear_co();
    cpu.set_szp((cpu.cl |= x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ebx)))));
    // 0051033b  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 0051033d  79d8                   -jns 0x510317
    if (!cpu.flags.sf)
    {
        goto L_0x00510317;
    }
L_0x0051033f:
    // 0051033f  00c9                   +add cl, cl
    {
        x86::reg8& tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.cl));
        x86::reg8 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) == (1 & (tmp2 >> 7));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00510341  7831                   -js 0x510374
    if (cpu.flags.sf)
    {
        goto L_0x00510374;
    }
    // 00510343  88f1                   -mov cl, dh
    cpu.cl = cpu.dh;
    // 00510345  8d7303                 -lea esi, [ebx + 3]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(3) /* 0x3 */);
    // 00510348  c1e906                 -shr ecx, 6
    cpu.ecx >>= 6 /*0x6*/ % 32;
    // 0051034b  83e103                 -and ecx, 3
    cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0051034e  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00510350  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00510352  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00510354  c1e910                 -shr ecx, 0x10
    cpu.ecx >>= 16 /*0x10*/ % 32;
    // 00510357  88f5                   -mov ch, dh
    cpu.ch = cpu.dh;
    // 00510359  80e53f                 -and ch, 0x3f
    cpu.ch &= x86::reg8(x86::sreg8(63 /*0x3f*/));
    // 0051035c  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0051035e  8d740fff               -lea esi, [edi + ecx - 1]
    cpu.esi = x86::reg32(cpu.edi + x86::reg32(-1) /* -0x1 */ + cpu.ecx * 1);
    // 00510362  83e23f                 -and edx, 0x3f
    cpu.edx &= x86::reg32(x86::sreg32(63 /*0x3f*/));
    // 00510365  8d4a04                 -lea ecx, [edx + 4]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00510368  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0051036a  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0051036c  0a0b                   +or cl, byte ptr [ebx]
    cpu.clear_co();
    cpu.set_szp((cpu.cl |= x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ebx)))));
    // 0051036e  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 00510370  79a5                   -jns 0x510317
    if (!cpu.flags.sf)
    {
        goto L_0x00510317;
    }
    // 00510372  ebcb                   -jmp 0x51033f
    goto L_0x0051033f;
L_0x00510374:
    // 00510374  00c9                   +add cl, cl
    {
        x86::reg8& tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.cl));
        x86::reg8 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) == (1 & (tmp2 >> 7));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00510376  7930                   -jns 0x5103a8
    if (!cpu.flags.sf)
    {
        goto L_0x005103a8;
    }
    // 00510378  80fafc                 +cmp dl, 0xfc
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(252 /*0xfc*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0051037b  7317                   -jae 0x510394
    if (!cpu.flags.cf)
    {
        goto L_0x00510394;
    }
    // 0051037d  83e21f                 -and edx, 0x1f
    cpu.edx &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00510380  8d7301                 -lea esi, [ebx + 1]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 00510383  8d4a01                 -lea ecx, [edx + 1]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 00510386  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00510388  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0051038a  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0051038c  0a0e                   +or cl, byte ptr [esi]
    cpu.clear_co();
    cpu.set_szp((cpu.cl |= x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.esi)))));
    // 0051038e  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 00510390  7985                   -jns 0x510317
    if (!cpu.flags.sf)
    {
        goto L_0x00510317;
    }
    // 00510392  ebab                   -jmp 0x51033f
    goto L_0x0051033f;
L_0x00510394:
    // 00510394  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00510396  8d7301                 -lea esi, [ebx + 1]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 00510399  83e103                 -and ecx, 3
    cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0051039c  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0051039e  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 005103a1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005103a2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005103a3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005103a4  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 005103a6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005103a7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005103a8:
    // 005103a8  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 005103aa  8d7304                 -lea esi, [ebx + 4]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 005103ad  83e103                 -and ecx, 3
    cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 005103b0  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    // 005103b2  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 005103b4  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 005103b6  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 005103b8  83e110                 -and ecx, 0x10
    cpu.ecx &= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 005103bb  c1e808                 -shr eax, 8
    cpu.eax >>= 8 /*0x8*/ % 32;
    // 005103be  c1e10c                 -shl ecx, 0xc
    cpu.ecx <<= 12 /*0xc*/ % 32;
    // 005103c1  88e1                   -mov cl, ah
    cpu.cl = cpu.ah;
    // 005103c3  88c5                   -mov ch, al
    cpu.ch = cpu.al;
    // 005103c5  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 005103c7  8d740fff               -lea esi, [edi + ecx - 1]
    cpu.esi = x86::reg32(cpu.edi + x86::reg32(-1) /* -0x1 */ + cpu.ecx * 1);
    // 005103cb  c1c208                 -rol edx, 8
    {
        x86::reg32& op = cpu.edx;
        x86::reg32 shift = 8 /*0x8*/ % 32;
        while (shift)
        {
            x86::reg32 cf = (op & 0x80000000);
            op = op << 1 | cf >> 31;
            shift--;
        }
    }
    // 005103ce  c0ee02                 -shr dh, 2
    cpu.dh >>= 2 /*0x2*/ % 32;
    // 005103d1  81e2ff030000           -and edx, 0x3ff
    cpu.edx &= x86::reg32(x86::sreg32(1023 /*0x3ff*/));
    // 005103d7  83f9fc                 +cmp ecx, -4
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-4 /*-0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005103da  7d24                   -jge 0x510400
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00510400;
    }
    // 005103dc  8d4a05                 -lea ecx, [edx + 5]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(5) /* 0x5 */);
    // 005103df  8d5205                 -lea edx, [edx + 5]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(5) /* 0x5 */);
    // 005103e2  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 005103e5  83e203                 -and edx, 3
    cpu.edx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 005103e8  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 005103ea  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 005103ec  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    // 005103ee  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 005103f0  0a0b                   +or cl, byte ptr [ebx]
    cpu.clear_co();
    cpu.set_szp((cpu.cl |= x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ebx)))));
    // 005103f2  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 005103f4  0f891dffffff           -jns 0x510317
    if (!cpu.flags.sf)
    {
        goto L_0x00510317;
    }
    // 005103fa  e940ffffff             -jmp 0x51033f
    goto L_0x0051033f;
    // 005103ff  90                     -nop 
    ;
L_0x00510400:
    // 00510400  8d4a05                 -lea ecx, [edx + 5]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(5) /* 0x5 */);
    // 00510403  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00510405  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00510407  0a0b                   +or cl, byte ptr [ebx]
    cpu.clear_co();
    cpu.set_szp((cpu.cl |= x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ebx)))));
    // 00510409  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 0051040b  0f8906ffffff           -jns 0x510317
    if (!cpu.flags.sf)
    {
        goto L_0x00510317;
    }
    // 00510411  e929ffffff             -jmp 0x51033f
    goto L_0x0051033f;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_510420(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00510420  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00510421  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00510422  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00510423  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00510424  83ec20                 -sub esp, 0x20
    (cpu.esp) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00510427  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00510429  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0051042b  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 00510430  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00510432  8b4401fc               -mov eax, dword ptr [ecx + eax - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-4) /* -0x4 */ + cpu.eax * 1);
    // 00510436  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 00510438  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 0051043f  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 00510441  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 00510446  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00510448  66890424               -mov word ptr [esp], ax
    app->getMemory<x86::reg16>(cpu.esp) = cpu.ax;
    // 0051044c  8d4302                 -lea eax, [ebx + 2]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(2) /* 0x2 */);
    // 0051044f  8b4401fc               -mov eax, dword ptr [ecx + eax - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-4) /* -0x4 */ + cpu.eax * 1);
    // 00510453  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 00510455  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 0051045c  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 0051045e  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 00510460  6689442402             -mov word ptr [esp + 2], ax
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(2) /* 0x2 */) = cpu.ax;
    // 00510465  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00510467  81e5e0070000           -and ebp, 0x7e0
    cpu.ebp &= x86::reg32(x86::sreg32(2016 /*0x7e0*/));
    // 0051046d  83e11f                 -and ecx, 0x1f
    cpu.ecx &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00510470  896c2418               -mov dword ptr [esp + 0x18], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.ebp;
    // 00510474  894c240c               -mov dword ptr [esp + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00510478  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0051047a  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0051047c  81e500f80000           -and ebp, 0xf800
    cpu.ebp &= x86::reg32(x86::sreg32(63488 /*0xf800*/));
    // 00510482  83e11f                 -and ecx, 0x1f
    cpu.ecx &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00510485  896c2410               -mov dword ptr [esp + 0x10], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ebp;
    // 00510489  894c241c               -mov dword ptr [esp + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 0051048d  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0051048f  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00510491  81e500f80000           -and ebp, 0xf800
    cpu.ebp &= x86::reg32(x86::sreg32(63488 /*0xf800*/));
    // 00510497  81e1e0070000           -and ecx, 0x7e0
    cpu.ecx &= x86::reg32(x86::sreg32(2016 /*0x7e0*/));
    // 0051049d  896c2414               -mov dword ptr [esp + 0x14], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ebp;
    // 005104a1  39c2                   +cmp edx, eax
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
    // 005104a3  0f8631020000           -jbe 0x5106da
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x005106da;
    }
    // 005104a9  8d04ad00000000         -lea eax, [ebp*4]
    cpu.eax = x86::reg32(cpu.ebp * 4);
    // 005104b0  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 005104b2  8b6c2410               -mov ebp, dword ptr [esp + 0x10]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 005104b6  69ed56550000           -imul ebp, ebp, 0x5556
    cpu.ebp = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebp)) * x86::sreg64(x86::sreg32(21846 /*0x5556*/)));
    // 005104bc  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 005104be  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 005104c0  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 005104c3  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 005104c5  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 005104c7  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 005104ca  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 005104cc  01d5                   -add ebp, edx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.edx));
    // 005104ce  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 005104d2  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 005104d9  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 005104db  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 005104dd  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 005104df  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 005104e2  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 005104e4  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 005104e6  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 005104e9  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 005104eb  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 005104ef  69c156550000           -imul eax, ecx, 0x5556
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(21846 /*0x5556*/)));
    // 005104f5  03442408               -add eax, dword ptr [esp + 8]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 005104f9  c1ed10                 -shr ebp, 0x10
    cpu.ebp >>= 16 /*0x10*/ % 32;
    // 005104fc  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 005104ff  81e500f80000           -and ebp, 0xf800
    cpu.ebp &= x86::reg32(x86::sreg32(63488 /*0xf800*/));
    // 00510505  25e0070000             -and eax, 0x7e0
    cpu.eax &= x86::reg32(x86::sreg32(2016 /*0x7e0*/));
    // 0051050a  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0051050e  09c5                   -or ebp, eax
    cpu.ebp |= x86::reg32(x86::sreg32(cpu.eax));
    // 00510510  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00510517  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00510519  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 0051051b  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0051051d  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00510520  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00510522  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00510524  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 00510527  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00510529  6954240c56550000       -imul edx, dword ptr [esp + 0xc], 0x5556
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */))) * x86::sreg64(x86::sreg32(21846 /*0x5556*/)));
    // 00510531  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00510533  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 00510536  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00510539  09e8                   -or eax, ebp
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ebp));
    // 0051053b  6689442404             -mov word ptr [esp + 4], ax
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ax;
    // 00510540  696c241456550000       -imul ebp, dword ptr [esp + 0x14], 0x5556
    cpu.ebp = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */))) * x86::sreg64(x86::sreg32(21846 /*0x5556*/)));
    // 00510548  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0051054c  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00510553  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00510555  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 00510557  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00510559  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0051055c  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0051055e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00510560  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 00510563  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00510565  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00510569  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0051056b  69ea56550000           -imul ebp, edx, 0x5556
    cpu.ebp = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(21846 /*0x5556*/)));
    // 00510571  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 00510574  2500f80000             -and eax, 0xf800
    cpu.eax &= x86::reg32(x86::sreg32(63488 /*0xf800*/));
    // 00510579  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0051057d  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 00510584  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00510586  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 00510588  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0051058a  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0051058d  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0051058f  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00510591  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 00510594  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00510596  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00510598  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 0051059b  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0051059f  25e0070000             -and eax, 0x7e0
    cpu.eax &= x86::reg32(x86::sreg32(2016 /*0x7e0*/));
    // 005105a4  09c1                   -or ecx, eax
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.eax));
    // 005105a6  696c241c56550000       -imul ebp, dword ptr [esp + 0x1c], 0x5556
    cpu.ebp = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */))) * x86::sreg64(x86::sreg32(21846 /*0x5556*/)));
    // 005105ae  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 005105b2  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 005105b9  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 005105bb  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 005105bd  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 005105bf  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 005105c2  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 005105c4  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 005105c6  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 005105c9  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 005105cb  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 005105cd  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 005105d0  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 005105d3  09c8                   -or eax, ecx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ecx));
    // 005105d5  6689442406             -mov word ptr [esp + 6], ax
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(6) /* 0x6 */) = cpu.ax;
L_0x005105da:
    // 005105da  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 005105dc  8a4304                 -mov al, byte ptr [ebx + 4]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 005105df  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 005105e1  83e203                 -and edx, 3
    cpu.edx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 005105e4  668b1454               -mov dx, word ptr [esp + edx*2]
    cpu.dx = app->getMemory<x86::reg16>(cpu.esp + cpu.edx * 2);
    // 005105e8  668916                 -mov word ptr [esi], dx
    app->getMemory<x86::reg16>(cpu.esi) = cpu.dx;
    // 005105eb  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 005105ed  c1ea02                 -shr edx, 2
    cpu.edx >>= 2 /*0x2*/ % 32;
    // 005105f0  83e203                 -and edx, 3
    cpu.edx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 005105f3  668b1454               -mov dx, word ptr [esp + edx*2]
    cpu.dx = app->getMemory<x86::reg16>(cpu.esp + cpu.edx * 2);
    // 005105f7  66895602               -mov word ptr [esi + 2], dx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(2) /* 0x2 */) = cpu.dx;
    // 005105fb  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 005105fd  c1ea04                 -shr edx, 4
    cpu.edx >>= 4 /*0x4*/ % 32;
    // 00510600  83e203                 -and edx, 3
    cpu.edx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 00510603  668b1454               -mov dx, word ptr [esp + edx*2]
    cpu.dx = app->getMemory<x86::reg16>(cpu.esp + cpu.edx * 2);
    // 00510607  c1e806                 -shr eax, 6
    cpu.eax >>= 6 /*0x6*/ % 32;
    // 0051060a  66895604               -mov word ptr [esi + 4], dx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.dx;
    // 0051060e  668b0444               -mov ax, word ptr [esp + eax*2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esp + cpu.eax * 2);
    // 00510612  66894606               -mov word ptr [esi + 6], ax
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(6) /* 0x6 */) = cpu.ax;
    // 00510616  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00510618  8a4305                 -mov al, byte ptr [ebx + 5]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5) /* 0x5 */);
    // 0051061b  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0051061d  83e203                 -and edx, 3
    cpu.edx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 00510620  01fe                   -add esi, edi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edi));
    // 00510622  668b1454               -mov dx, word ptr [esp + edx*2]
    cpu.dx = app->getMemory<x86::reg16>(cpu.esp + cpu.edx * 2);
    // 00510626  668916                 -mov word ptr [esi], dx
    app->getMemory<x86::reg16>(cpu.esi) = cpu.dx;
    // 00510629  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0051062b  c1ea02                 -shr edx, 2
    cpu.edx >>= 2 /*0x2*/ % 32;
    // 0051062e  83e203                 -and edx, 3
    cpu.edx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 00510631  668b1454               -mov dx, word ptr [esp + edx*2]
    cpu.dx = app->getMemory<x86::reg16>(cpu.esp + cpu.edx * 2);
    // 00510635  66895602               -mov word ptr [esi + 2], dx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(2) /* 0x2 */) = cpu.dx;
    // 00510639  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0051063b  c1ea04                 -shr edx, 4
    cpu.edx >>= 4 /*0x4*/ % 32;
    // 0051063e  83e203                 -and edx, 3
    cpu.edx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 00510641  668b1454               -mov dx, word ptr [esp + edx*2]
    cpu.dx = app->getMemory<x86::reg16>(cpu.esp + cpu.edx * 2);
    // 00510645  c1e806                 -shr eax, 6
    cpu.eax >>= 6 /*0x6*/ % 32;
    // 00510648  66895604               -mov word ptr [esi + 4], dx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.dx;
    // 0051064c  668b0444               -mov ax, word ptr [esp + eax*2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esp + cpu.eax * 2);
    // 00510650  66894606               -mov word ptr [esi + 6], ax
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(6) /* 0x6 */) = cpu.ax;
    // 00510654  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00510656  8a4306                 -mov al, byte ptr [ebx + 6]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(6) /* 0x6 */);
    // 00510659  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0051065b  83e203                 -and edx, 3
    cpu.edx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0051065e  01fe                   -add esi, edi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edi));
    // 00510660  668b1454               -mov dx, word ptr [esp + edx*2]
    cpu.dx = app->getMemory<x86::reg16>(cpu.esp + cpu.edx * 2);
    // 00510664  668916                 -mov word ptr [esi], dx
    app->getMemory<x86::reg16>(cpu.esi) = cpu.dx;
    // 00510667  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00510669  c1ea02                 -shr edx, 2
    cpu.edx >>= 2 /*0x2*/ % 32;
    // 0051066c  83e203                 -and edx, 3
    cpu.edx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0051066f  668b1454               -mov dx, word ptr [esp + edx*2]
    cpu.dx = app->getMemory<x86::reg16>(cpu.esp + cpu.edx * 2);
    // 00510673  66895602               -mov word ptr [esi + 2], dx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(2) /* 0x2 */) = cpu.dx;
    // 00510677  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00510679  c1ea04                 -shr edx, 4
    cpu.edx >>= 4 /*0x4*/ % 32;
    // 0051067c  83e203                 -and edx, 3
    cpu.edx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0051067f  668b1454               -mov dx, word ptr [esp + edx*2]
    cpu.dx = app->getMemory<x86::reg16>(cpu.esp + cpu.edx * 2);
    // 00510683  c1e806                 -shr eax, 6
    cpu.eax >>= 6 /*0x6*/ % 32;
    // 00510686  66895604               -mov word ptr [esi + 4], dx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.dx;
    // 0051068a  668b0444               -mov ax, word ptr [esp + eax*2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esp + cpu.eax * 2);
    // 0051068e  66894606               -mov word ptr [esi + 6], ax
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(6) /* 0x6 */) = cpu.ax;
    // 00510692  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00510694  8a4307                 -mov al, byte ptr [ebx + 7]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(7) /* 0x7 */);
    // 00510697  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00510699  83e203                 -and edx, 3
    cpu.edx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0051069c  668b1454               -mov dx, word ptr [esp + edx*2]
    cpu.dx = app->getMemory<x86::reg16>(cpu.esp + cpu.edx * 2);
    // 005106a0  66891437               -mov word ptr [edi + esi], dx
    app->getMemory<x86::reg16>(cpu.edi + cpu.esi * 1) = cpu.dx;
    // 005106a4  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 005106a6  c1ea02                 -shr edx, 2
    cpu.edx >>= 2 /*0x2*/ % 32;
    // 005106a9  83e203                 -and edx, 3
    cpu.edx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 005106ac  668b1454               -mov dx, word ptr [esp + edx*2]
    cpu.dx = app->getMemory<x86::reg16>(cpu.esp + cpu.edx * 2);
    // 005106b0  6689543702             -mov word ptr [edi + esi + 2], dx
    app->getMemory<x86::reg16>(cpu.edi + x86::reg32(2) /* 0x2 */ + cpu.esi * 1) = cpu.dx;
    // 005106b5  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 005106b7  c1ea04                 -shr edx, 4
    cpu.edx >>= 4 /*0x4*/ % 32;
    // 005106ba  83e203                 -and edx, 3
    cpu.edx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 005106bd  668b1454               -mov dx, word ptr [esp + edx*2]
    cpu.dx = app->getMemory<x86::reg16>(cpu.esp + cpu.edx * 2);
    // 005106c1  c1e806                 -shr eax, 6
    cpu.eax >>= 6 /*0x6*/ % 32;
    // 005106c4  6689543704             -mov word ptr [edi + esi + 4], dx
    app->getMemory<x86::reg16>(cpu.edi + x86::reg32(4) /* 0x4 */ + cpu.esi * 1) = cpu.dx;
    // 005106c9  668b0444               -mov ax, word ptr [esp + eax*2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esp + cpu.eax * 2);
    // 005106cd  6689443706             -mov word ptr [edi + esi + 6], ax
    app->getMemory<x86::reg16>(cpu.edi + x86::reg32(6) /* 0x6 */ + cpu.esi * 1) = cpu.ax;
    // 005106d2  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 005106d5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005106d6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005106d7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005106d8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005106d9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005106da:
    // 005106da  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 005106de  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 005106e0  c1e00f                 -shl eax, 0xf
    cpu.eax <<= 15 /*0xf*/ % 32;
    // 005106e3  c1e20f                 -shl edx, 0xf
    cpu.edx <<= 15 /*0xf*/ % 32;
    // 005106e6  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 005106e8  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 005106ec  c1e10f                 -shl ecx, 0xf
    cpu.ecx <<= 15 /*0xf*/ % 32;
    // 005106ef  c1e00f                 -shl eax, 0xf
    cpu.eax <<= 15 /*0xf*/ % 32;
    // 005106f2  c1ea10                 -shr edx, 0x10
    cpu.edx >>= 16 /*0x10*/ % 32;
    // 005106f5  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 005106f7  81e200f80000           -and edx, 0xf800
    cpu.edx &= x86::reg32(x86::sreg32(63488 /*0xf800*/));
    // 005106fd  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 00510700  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00510702  25e0070000             -and eax, 0x7e0
    cpu.eax &= x86::reg32(x86::sreg32(2016 /*0x7e0*/));
    // 00510707  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0051070b  09c1                   -or ecx, eax
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.eax));
    // 0051070d  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00510711  c1e20f                 -shl edx, 0xf
    cpu.edx <<= 15 /*0xf*/ % 32;
    // 00510714  c1e00f                 -shl eax, 0xf
    cpu.eax <<= 15 /*0xf*/ % 32;
    // 00510717  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00510719  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 0051071c  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 0051071f  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00510721  09c8                   +or eax, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.eax |= x86::reg32(x86::sreg32(cpu.ecx))));
    // 00510723  6689542406             -mov word ptr [esp + 6], dx
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(6) /* 0x6 */) = cpu.dx;
    // 00510728  6689442404             -mov word ptr [esp + 4], ax
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ax;
    // 0051072d  e9a8feffff             -jmp 0x5105da
    goto L_0x005105da;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_510740(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00510740  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00510741  b903000000             -mov ecx, 3
    cpu.ecx = 3 /*0x3*/;
    // 00510746  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00510749  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0051074b  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 0051074d  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0051074f  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 00510756  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 00510758  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00510759  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_510760(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00510760  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00510761  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00510762  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00510763  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00510764  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00510767  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00510769  b903000000             -mov ecx, 3
    cpu.ecx = 3 /*0x3*/;
    // 0051076e  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00510771  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00510773  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 00510775  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 00510777  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 0051077e  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 00510780  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 00510785  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00510787  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0051078b  8d4706                 -lea eax, [edi + 6]
    cpu.eax = x86::reg32(cpu.edi + x86::reg32(6) /* 0x6 */);
    // 0051078e  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00510790  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00510792  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 00510794  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 00510796  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 0051079d  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 0051079f  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 005107a3  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 005107a5  7466                   -je 0x51080d
    if (cpu.flags.zf)
    {
        goto L_0x0051080d;
    }
    // 005107a7  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 005107a9  83c708                 -add edi, 8
    (cpu.edi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 005107ac  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 005107b0  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 005107b2  7e59                   -jle 0x51080d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0051080d;
    }
    // 005107b4  8d2c00                 -lea ebp, [eax + eax]
    cpu.ebp = x86::reg32(cpu.eax + cpu.eax * 1);
    // 005107b7  8d0c8500000000         -lea ecx, [eax*4]
    cpu.ecx = x86::reg32(cpu.eax * 4);
    // 005107be  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 005107c0  01c9                   -add ecx, ecx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 005107c2  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 005107c5  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 005107c9  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
L_0x005107cc:
    // 005107cc  8b5c2410               -mov ebx, dword ptr [esp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 005107d0  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 005107d2  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 005107d4  7e1c                   -jle 0x5107f2
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x005107f2;
    }
L_0x005107d6:
    // 005107d6  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 005107d8  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 005107da  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 005107dc  e83ffcffff             -call 0x510420
    cpu.esp -= 4;
    sub_510420(app, cpu);
    if (cpu.terminate) return;
    // 005107e1  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 005107e4  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 005107e8  83c608                 -add esi, 8
    (cpu.esi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 005107eb  83c708                 -add edi, 8
    (cpu.edi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 005107ee  39c1                   +cmp ecx, eax
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
    // 005107f0  7ce4                   -jl 0x5107d6
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x005107d6;
    }
L_0x005107f2:
    // 005107f2  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 005107f6  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 005107f9  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 005107fd  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00510801  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00510803  01ce                   -add esi, ecx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00510805  895c240c               -mov dword ptr [esp + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 00510809  39d3                   +cmp ebx, edx
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
    // 0051080b  7cbf                   -jl 0x5107cc
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x005107cc;
    }
L_0x0051080d:
    // 0051080d  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00510811  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00510814  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00510815  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00510816  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00510817  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00510818  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_510820(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00510820  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00510821  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
L_0x00510822:
    // 00510822  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00510824  8b0d40b0a000           -mov ecx, dword ptr [0xa0b040]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10530880) /* 0xa0b040 */);
    // 0051082a  88c2                   -mov dl, al
    cpu.dl = cpu.al;
    // 0051082c  803c1100               +cmp byte ptr [ecx + edx], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx + cpu.edx * 1);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00510830  7513                   -jne 0x510845
    if (!cpu.flags.zf)
    {
        goto L_0x00510845;
    }
    // 00510832  8b1530b0a000           -mov edx, dword ptr [0xa0b030]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10530864) /* 0xa0b030 */);
    // 00510838  42                     -inc edx
    (cpu.edx)++;
    // 00510839  8842ff                 -mov byte ptr [edx - 1], al
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-1) /* -0x1 */) = cpu.al;
    // 0051083c  891530b0a000           -mov dword ptr [0xa0b030], edx
    app->getMemory<x86::reg32>(x86::reg32(10530864) /* 0xa0b030 */) = cpu.edx;
    // 00510842  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00510843  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00510844  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00510845:
    // 00510845  a134b0a000             -mov eax, dword ptr [0xa0b034]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10530868) /* 0xa0b034 */);
    // 0051084a  8a0402                 -mov al, byte ptr [edx + eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + cpu.eax * 1);
    // 0051084d  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00510852  e8c9ffffff             -call 0x510820
    cpu.esp -= 4;
    sub_510820(app, cpu);
    if (cpu.terminate) return;
    // 00510857  a13cb0a000             -mov eax, dword ptr [0xa0b03c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10530876) /* 0xa0b03c */);
    // 0051085c  8a0402                 -mov al, byte ptr [edx + eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + cpu.eax * 1);
    // 0051085f  25ff000000             +and eax, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 00510864  ebbc                   -jmp 0x510822
    goto L_0x00510822;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void Application::sub_510870(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00510870  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00510871  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00510872  81ec04030000           -sub esp, 0x304
    (cpu.esp) -= x86::reg32(x86::sreg32(772 /*0x304*/));
    // 00510878  891530b0a000           -mov dword ptr [0xa0b030], edx
    app->getMemory<x86::reg32>(x86::reg32(10530864) /* 0xa0b030 */) = cpu.edx;
    // 0051087e  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00510880  89942400030000         -mov dword ptr [esp + 0x300], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(768) /* 0x300 */) = cpu.edx;
    // 00510887  8d942400020000         -lea edx, [esp + 0x200]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(512) /* 0x200 */);
    // 0051088e  891540b0a000           -mov dword ptr [0xa0b040], edx
    app->getMemory<x86::reg32>(x86::reg32(10530880) /* 0xa0b040 */) = cpu.edx;
    // 00510894  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00510896  891534b0a000           -mov dword ptr [0xa0b034], edx
    app->getMemory<x86::reg32>(x86::reg32(10530868) /* 0xa0b034 */) = cpu.edx;
    // 0051089c  8d942400010000         -lea edx, [esp + 0x100]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 005108a3  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 005108a5  89153cb0a000           -mov dword ptr [0xa0b03c], edx
    app->getMemory<x86::reg32>(x86::reg32(10530876) /* 0xa0b03c */) = cpu.edx;
    // 005108ab  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005108ad  0f8444010000           -je 0x5109f7
    if (cpu.flags.zf)
    {
        goto L_0x005109f7;
    }
    // 005108b3  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 005108b5  8d4801                 -lea ecx, [eax + 1]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 005108b8  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 005108ba  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 005108bc  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 005108bf  8a01                   -mov al, byte ptr [ecx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx);
    // 005108c1  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 005108c3  41                     -inc ecx
    (cpu.ecx)++;
    // 005108c4  81fafb470000           +cmp edx, 0x47fb
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(18427 /*0x47fb*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005108ca  0f84cf000000           -je 0x51099f
    if (cpu.flags.zf)
    {
        goto L_0x0051099f;
    }
L_0x005108d0:
    // 005108d0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005108d1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 005108d3  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 005108d5  8a01                   -mov al, byte ptr [ecx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx);
    // 005108d7  8a5101                 -mov dl, byte ptr [ecx + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 005108da  89842404030000         -mov dword ptr [esp + 0x304], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(772) /* 0x304 */) = cpu.eax;
    // 005108e1  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 005108e4  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 005108e6  89842404030000         -mov dword ptr [esp + 0x304], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(772) /* 0x304 */) = cpu.eax;
    // 005108ed  41                     -inc ecx
    (cpu.ecx)++;
    // 005108ee  8b942404030000         -mov edx, dword ptr [esp + 0x304]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(772) /* 0x304 */);
    // 005108f5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 005108f7  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 005108fa  8a4101                 -mov al, byte ptr [ecx + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 005108fd  41                     -inc ecx
    (cpu.ecx)++;
    // 005108fe  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00510900  41                     -inc ecx
    (cpu.ecx)++;
    // 00510901  89942404030000         -mov dword ptr [esp + 0x304], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(772) /* 0x304 */) = cpu.edx;
    // 00510908  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0051090a:
    // 0051090a  a140b0a000             -mov eax, dword ptr [0xa0b040]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10530880) /* 0xa0b040 */);
    // 0051090f  8d3410                 -lea esi, [eax + edx]
    cpu.esi = x86::reg32(cpu.eax + cpu.edx * 1);
    // 00510912  42                     -inc edx
    (cpu.edx)++;
    // 00510913  c60600                 -mov byte ptr [esi], 0
    app->getMemory<x86::reg8>(cpu.esi) = 0 /*0x0*/;
    // 00510916  81fa00010000           +cmp edx, 0x100
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(256 /*0x100*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051091c  7cec                   -jl 0x51090a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0051090a;
    }
    // 0051091e  41                     -inc ecx
    (cpu.ecx)++;
    // 0051091f  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00510921  8a51ff                 -mov dl, byte ptr [ecx - 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(-1) /* -0x1 */);
    // 00510924  41                     -inc ecx
    (cpu.ecx)++;
    // 00510925  c6040201               -mov byte ptr [edx + eax], 1
    app->getMemory<x86::reg8>(cpu.edx + cpu.eax * 1) = 1 /*0x1*/;
    // 00510929  0fb669ff               -movzx ebp, byte ptr [ecx - 1]
    cpu.ebp = x86::reg32(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(-1) /* -0x1 */));
    // 0051092d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0051092f  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00510931  7e38                   -jle 0x51096b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0051096b;
    }
    // 00510933  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00510934  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
L_0x00510935:
    // 00510935  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00510937  8b1d34b0a000           -mov ebx, dword ptr [0xa0b034]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10530868) /* 0xa0b034 */);
    // 0051093d  8a11                   -mov dl, byte ptr [ecx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx);
    // 0051093f  8d7101                 -lea esi, [ecx + 1]
    cpu.esi = x86::reg32(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 00510942  8d3c13                 -lea edi, [ebx + edx]
    cpu.edi = x86::reg32(cpu.ebx + cpu.edx * 1);
    // 00510945  8d4e01                 -lea ecx, [esi + 1]
    cpu.ecx = x86::reg32(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00510948  8a1e                   -mov bl, byte ptr [esi]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esi);
    // 0051094a  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0051094c  881f                   -mov byte ptr [edi], bl
    app->getMemory<x86::reg8>(cpu.edi) = cpu.bl;
    // 0051094e  8b3d3cb0a000           -mov edi, dword ptr [0xa0b03c]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(10530876) /* 0xa0b03c */);
    // 00510954  8a1e                   -mov bl, byte ptr [esi]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esi);
    // 00510956  881c3a                 -mov byte ptr [edx + edi], bl
    app->getMemory<x86::reg8>(cpu.edx + cpu.edi * 1) = cpu.bl;
    // 00510959  8b1d40b0a000           -mov ebx, dword ptr [0xa0b040]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10530880) /* 0xa0b040 */);
    // 0051095f  40                     -inc eax
    (cpu.eax)++;
    // 00510960  41                     -inc ecx
    (cpu.ecx)++;
    // 00510961  c6041aff               -mov byte ptr [edx + ebx], 0xff
    app->getMemory<x86::reg8>(cpu.edx + cpu.ebx * 1) = 255 /*0xff*/;
    // 00510965  39e8                   +cmp eax, ebp
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
    // 00510967  7ccc                   -jl 0x510935
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00510935;
    }
    // 00510969  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051096a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0051096b:
    // 0051096b  890d38b0a000           -mov dword ptr [0xa0b038], ecx
    app->getMemory<x86::reg32>(x86::reg32(10530872) /* 0xa0b038 */) = cpu.ecx;
    // 00510971  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00510972:
    // 00510972  8b0d38b0a000           -mov ecx, dword ptr [0xa0b038]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10530872) /* 0xa0b038 */);
    // 00510978  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0051097a  a140b0a000             -mov eax, dword ptr [0xa0b040]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10530880) /* 0xa0b040 */);
    // 0051097f  8a11                   -mov dl, byte ptr [ecx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx);
    // 00510981  8a0402                 -mov al, byte ptr [edx + eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + cpu.eax * 1);
    // 00510984  41                     -inc ecx
    (cpu.ecx)++;
    // 00510985  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 00510987  751e                   -jne 0x5109a7
    if (!cpu.flags.zf)
    {
        goto L_0x005109a7;
    }
    // 00510989  a130b0a000             -mov eax, dword ptr [0xa0b030]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10530864) /* 0xa0b030 */);
    // 0051098e  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0051098f  890d38b0a000           -mov dword ptr [0xa0b038], ecx
    app->getMemory<x86::reg32>(x86::reg32(10530872) /* 0xa0b038 */) = cpu.ecx;
    // 00510995  8850ff                 -mov byte ptr [eax - 1], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(-1) /* -0x1 */) = cpu.dl;
    // 00510998  a330b0a000             -mov dword ptr [0xa0b030], eax
    app->getMemory<x86::reg32>(x86::reg32(10530864) /* 0xa0b030 */) = cpu.eax;
    // 0051099d  ebd3                   -jmp 0x510972
    goto L_0x00510972;
L_0x0051099f:
    // 0051099f  83c103                 +add ecx, 3
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 005109a2  e929ffffff             -jmp 0x5108d0
    goto L_0x005108d0;
L_0x005109a7:
    // 005109a7  890d38b0a000           -mov dword ptr [0xa0b038], ecx
    app->getMemory<x86::reg32>(x86::reg32(10530872) /* 0xa0b038 */) = cpu.ecx;
    // 005109ad  7c1f                   -jl 0x5109ce
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x005109ce;
    }
    // 005109af  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 005109b1  8a11                   -mov dl, byte ptr [ecx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx);
    // 005109b3  41                     -inc ecx
    (cpu.ecx)++;
    // 005109b4  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 005109b6  743f                   -je 0x5109f7
    if (cpu.flags.zf)
    {
        goto L_0x005109f7;
    }
    // 005109b8  a130b0a000             -mov eax, dword ptr [0xa0b030]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10530864) /* 0xa0b030 */);
    // 005109bd  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 005109be  890d38b0a000           -mov dword ptr [0xa0b038], ecx
    app->getMemory<x86::reg32>(x86::reg32(10530872) /* 0xa0b038 */) = cpu.ecx;
    // 005109c4  8850ff                 -mov byte ptr [eax - 1], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(-1) /* -0x1 */) = cpu.dl;
    // 005109c7  a330b0a000             -mov dword ptr [0xa0b030], eax
    app->getMemory<x86::reg32>(x86::reg32(10530864) /* 0xa0b030 */) = cpu.eax;
    // 005109cc  eba4                   -jmp 0x510972
    goto L_0x00510972;
L_0x005109ce:
    // 005109ce  a134b0a000             -mov eax, dword ptr [0xa0b034]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10530868) /* 0xa0b034 */);
    // 005109d3  8a0402                 -mov al, byte ptr [edx + eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + cpu.eax * 1);
    // 005109d6  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 005109db  e840feffff             -call 0x510820
    cpu.esp -= 4;
    sub_510820(app, cpu);
    if (cpu.terminate) return;
    // 005109e0  a13cb0a000             -mov eax, dword ptr [0xa0b03c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10530876) /* 0xa0b03c */);
    // 005109e5  8a0402                 -mov al, byte ptr [edx + eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + cpu.eax * 1);
    // 005109e8  25ff000000             +and eax, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 005109ed  e82efeffff             -call 0x510820
    cpu.esp -= 4;
    sub_510820(app, cpu);
    if (cpu.terminate) return;
    // 005109f2  e97bffffff             -jmp 0x510972
    goto L_0x00510972;
L_0x005109f7:
    // 005109f7  8b842400030000         -mov eax, dword ptr [esp + 0x300]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(768) /* 0x300 */);
    // 005109fe  890d38b0a000           -mov dword ptr [0xa0b038], ecx
    app->getMemory<x86::reg32>(x86::reg32(10530872) /* 0xa0b038 */) = cpu.ecx;
    // 00510a04  81c404030000           -add esp, 0x304
    (cpu.esp) += x86::reg32(x86::sreg32(772 /*0x304*/));
    // 00510a0a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00510a0b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00510a0c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_510a10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00510a10  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00510a11  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00510a12  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00510a13  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00510a14  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00510a16  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00510a18  7d09                   -jge 0x510a23
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00510a23;
    }
L_0x00510a1a:
    // 00510a1a  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x00510a1c:
    // 00510a1c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00510a1e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00510a1f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00510a20  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00510a21  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00510a22  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00510a23:
    // 00510a23  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00510a28  e87730feff             -call 0x4f3aa4
    cpu.esp -= 4;
    sub_4f3aa4(app, cpu);
    if (cpu.terminate) return;
    // 00510a2d  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00510a2f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00510a31  74e7                   -je 0x510a1a
    if (cpu.flags.zf)
    {
        goto L_0x00510a1a;
    }
    // 00510a33  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00510a35  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00510a37:
    // 00510a37  0fbe5916               -movsx ebx, byte ptr [ecx + 0x16]
    cpu.ebx = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(22) /* 0x16 */)));
    // 00510a3b  39d8                   +cmp eax, ebx
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
    // 00510a3d  7ddb                   -jge 0x510a1a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00510a1a;
    }
    // 00510a3f  8b19                   -mov ebx, dword ptr [ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx);
    // 00510a41  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00510a43  3b7304                 +cmp esi, dword ptr [ebx + 4]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00510a46  74d4                   -je 0x510a1c
    if (cpu.flags.zf)
    {
        goto L_0x00510a1c;
    }
    // 00510a48  83c22c                 +add edx, 0x2c
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(44 /*0x2c*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00510a4b  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00510a4c  ebe9                   -jmp 0x510a37
    goto L_0x00510a37;
}

/* align: skip 0x00 0x00 */
void Application::sub_510a50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00510a50  8b5e14                 -mov ebx, dword ptr [esi + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 00510a53  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 00510a56  8b4e04                 -mov ecx, dword ptr [esi + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00510a59  8b561c                 -mov edx, dword ptr [esi + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 00510a5c  09d9                   -or ecx, ebx
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.ebx));
    // 00510a5e  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 00510a60  8b7e08                 -mov edi, dword ptr [esi + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00510a63  8b6e18                 -mov ebp, dword ptr [esi + 0x18]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 00510a66  09ca                   -or edx, ecx
    cpu.edx |= x86::reg32(x86::sreg32(cpu.ecx));
    // 00510a68  09ef                   -or edi, ebp
    cpu.edi |= x86::reg32(x86::sreg32(cpu.ebp));
    // 00510a6a  8b4e10                 -mov ecx, dword ptr [esi + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 00510a6d  09fa                   -or edx, edi
    cpu.edx |= x86::reg32(x86::sreg32(cpu.edi));
    // 00510a6f  09ca                   +or edx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.edx |= x86::reg32(x86::sreg32(cpu.ecx))));
    // 00510a71  0f8410010000           -je 0x510b87
    if (cpu.flags.zf)
    {
        goto L_0x00510b87;
    }
    // 00510a77  8b4e04                 -mov ecx, dword ptr [esi + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00510a7a  8b561c                 -mov edx, dword ptr [esi + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 00510a7d  8d3c03                 -lea edi, [ebx + eax]
    cpu.edi = x86::reg32(cpu.ebx + cpu.eax * 1);
    // 00510a80  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00510a82  8d0411                 -lea eax, [ecx + edx]
    cpu.eax = x86::reg32(cpu.ecx + cpu.edx * 1);
    // 00510a85  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00510a87  891de8cd5600           -mov dword ptr [0x56cde8], ebx
    app->getMemory<x86::reg32>(x86::reg32(5688808) /* 0x56cde8 */) = cpu.ebx;
    // 00510a8d  890deccd5600           -mov dword ptr [0x56cdec], ecx
    app->getMemory<x86::reg32>(x86::reg32(5688812) /* 0x56cdec */) = cpu.ecx;
    // 00510a93  8d2c38                 -lea ebp, [eax + edi]
    cpu.ebp = x86::reg32(cpu.eax + cpu.edi * 1);
    // 00510a96  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 00510a98  db05e8cd5600           -fild dword ptr [0x56cde8]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5688808) /* 0x56cde8 */))));
    // 00510a9e  db05eccd5600           -fild dword ptr [0x56cdec]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5688812) /* 0x56cdec */))));
    // 00510aa4  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 00510aa6  d80d00ce5600           -fmul dword ptr [0x56ce00]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5688832) /* 0x56ce00 */));
    // 00510aac  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 00510aae  dcc1                   -fadd st(1), st(0)
    cpu.fpu.st(1) += x86::Float(cpu.fpu.st(0));
    // 00510ab0  d80dfccd5600           -fmul dword ptr [0x56cdfc]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5688828) /* 0x56cdfc */));
    // 00510ab6  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00510ab8  d80d04ce5600           -fmul dword ptr [0x56ce04]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5688836) /* 0x56ce04 */));
    // 00510abe  f72df8cd5600           -imul dword ptr [0x56cdf8]
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5688824) /* 0x56cdf8 */))));
    // 00510ac4  dcc1                   -fadd st(1), st(0)
    cpu.fpu.st(1) += x86::Float(cpu.fpu.st(0));
    // 00510ac6  deea                   -fsubp st(2)
    cpu.fpu.st(2) -= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00510ac8  d80508ce5600           -fadd dword ptr [0x56ce08]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5688840) /* 0x56ce08 */));
    // 00510ace  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00510ad0  d80508ce5600           -fadd dword ptr [0x56ce08]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5688840) /* 0x56ce08 */));
    // 00510ad6  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00510ad9  8b5e18                 -mov ebx, dword ptr [esi + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 00510adc  d1e2                   -shl edx, 1
    cpu.edx <<= 1 /*0x1*/ % 32;
    // 00510ade  dd1df0cd5600           -fstp qword ptr [0x56cdf0]
    app->getMemory<double>(x86::reg32(5688816) /* 0x56cdf0 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00510ae4  dd1de8cd5600           -fstp qword ptr [0x56cde8]
    app->getMemory<double>(x86::reg32(5688808) /* 0x56cde8 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00510aea  8b0de8cd5600           -mov ecx, dword ptr [0x56cde8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5688808) /* 0x56cde8 */);
    // 00510af0  8b3df0cd5600           -mov edi, dword ptr [0x56cdf0]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5688816) /* 0x56cdf0 */);
    // 00510af6  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00510af8  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 00510afa  01ef                   -add edi, ebp
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00510afc  890deccd5600           -mov dword ptr [0x56cdec], ecx
    app->getMemory<x86::reg32>(x86::reg32(5688812) /* 0x56cdec */) = cpu.ecx;
    // 00510b02  8915f0cd5600           -mov dword ptr [0x56cdf0], edx
    app->getMemory<x86::reg32>(x86::reg32(5688816) /* 0x56cdf0 */) = cpu.edx;
    // 00510b08  893df4cd5600           -mov dword ptr [0x56cdf4], edi
    app->getMemory<x86::reg32>(x86::reg32(5688820) /* 0x56cdf4 */) = cpu.edi;
    // 00510b0e  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 00510b10  8b5610                 -mov edx, dword ptr [esi + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 00510b13  8d3418                 -lea esi, [eax + ebx]
    cpu.esi = x86::reg32(cpu.eax + cpu.ebx * 1);
    // 00510b16  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00510b18  8d1c11                 -lea ebx, [ecx + edx]
    cpu.ebx = x86::reg32(cpu.ecx + cpu.edx * 1);
    // 00510b1b  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00510b1d  f72df8cd5600           -imul dword ptr [0x56cdf8]
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5688824) /* 0x56cdf8 */))));
    // 00510b23  d1e2                   -shl edx, 1
    cpu.edx <<= 1 /*0x1*/ % 32;
    // 00510b25  8b3de4cd5600           -mov edi, dword ptr [0x56cde4]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5688804) /* 0x56cde4 */);
    // 00510b2b  01d6                   -add esi, edx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edx));
    // 00510b2d  8b2deccd5600           -mov ebp, dword ptr [0x56cdec]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5688812) /* 0x56cdec */);
    // 00510b33  8d0411                 -lea eax, [ecx + edx]
    cpu.eax = x86::reg32(cpu.ecx + cpu.edx * 1);
    // 00510b36  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00510b38  8d1433                 -lea edx, [ebx + esi]
    cpu.edx = x86::reg32(cpu.ebx + cpu.esi * 1);
    // 00510b3b  29f3                   -sub ebx, esi
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00510b3d  8d3429                 -lea esi, [ecx + ebp]
    cpu.esi = x86::reg32(cpu.ecx + cpu.ebp * 1);
    // 00510b40  29e9                   -sub ecx, ebp
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 00510b42  8b2de8cd5600           -mov ebp, dword ptr [0x56cde8]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5688808) /* 0x56cde8 */);
    // 00510b48  897748                 -mov dword ptr [edi + 0x48], esi
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(72) /* 0x48 */) = cpu.esi;
    // 00510b4b  8b35f0cd5600           -mov esi, dword ptr [0x56cdf0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5688816) /* 0x56cdf0 */);
    // 00510b51  898fb4000000           -mov dword ptr [edi + 0xb4], ecx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(180) /* 0xb4 */) = cpu.ecx;
    // 00510b57  8d0c2b                 -lea ecx, [ebx + ebp]
    cpu.ecx = x86::reg32(cpu.ebx + cpu.ebp * 1);
    // 00510b5a  29eb                   -sub ebx, ebp
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 00510b5c  8b2df4cd5600           -mov ebp, dword ptr [0x56cdf4]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5688820) /* 0x56cdf4 */);
    // 00510b62  894f6c                 -mov dword ptr [edi + 0x6c], ecx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(108) /* 0x6c */) = cpu.ecx;
    // 00510b65  899f90000000           -mov dword ptr [edi + 0x90], ebx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(144) /* 0x90 */) = cpu.ebx;
    // 00510b6b  8d1c30                 -lea ebx, [eax + esi]
    cpu.ebx = x86::reg32(cpu.eax + cpu.esi * 1);
    // 00510b6e  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00510b70  8d0c2a                 -lea ecx, [edx + ebp]
    cpu.ecx = x86::reg32(cpu.edx + cpu.ebp * 1);
    // 00510b73  29ea                   -sub edx, ebp
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 00510b75  890f                   -mov dword ptr [edi], ecx
    app->getMemory<x86::reg32>(cpu.edi) = cpu.ecx;
    // 00510b77  895f24                 -mov dword ptr [edi + 0x24], ebx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(36) /* 0x24 */) = cpu.ebx;
    // 00510b7a  8987d8000000           -mov dword ptr [edi + 0xd8], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(216) /* 0xd8 */) = cpu.eax;
    // 00510b80  8997fc000000           -mov dword ptr [edi + 0xfc], edx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(252) /* 0xfc */) = cpu.edx;
    // 00510b86  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00510b87:
    // 00510b87  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00510b89  8b3de4cd5600           -mov edi, dword ptr [0x56cde4]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5688804) /* 0x56cde4 */);
    // 00510b8f  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 00510b91  894724                 -mov dword ptr [edi + 0x24], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 00510b94  894748                 -mov dword ptr [edi + 0x48], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(72) /* 0x48 */) = cpu.eax;
    // 00510b97  89476c                 -mov dword ptr [edi + 0x6c], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(108) /* 0x6c */) = cpu.eax;
    // 00510b9a  898790000000           -mov dword ptr [edi + 0x90], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(144) /* 0x90 */) = cpu.eax;
    // 00510ba0  8987b4000000           -mov dword ptr [edi + 0xb4], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(180) /* 0xb4 */) = cpu.eax;
    // 00510ba6  8987d8000000           -mov dword ptr [edi + 0xd8], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(216) /* 0xd8 */) = cpu.eax;
    // 00510bac  8987fc000000           -mov dword ptr [edi + 0xfc], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(252) /* 0xfc */) = cpu.eax;
    // 00510bb2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_510bb3(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00510bb3  8b5e14                 -mov ebx, dword ptr [esi + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 00510bb6  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 00510bb9  8b4e04                 -mov ecx, dword ptr [esi + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00510bbc  8b561c                 -mov edx, dword ptr [esi + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 00510bbf  8d3c03                 -lea edi, [ebx + eax]
    cpu.edi = x86::reg32(cpu.ebx + cpu.eax * 1);
    // 00510bc2  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00510bc4  8d0411                 -lea eax, [ecx + edx]
    cpu.eax = x86::reg32(cpu.ecx + cpu.edx * 1);
    // 00510bc7  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00510bc9  891de8cd5600           -mov dword ptr [0x56cde8], ebx
    app->getMemory<x86::reg32>(x86::reg32(5688808) /* 0x56cde8 */) = cpu.ebx;
    // 00510bcf  890deccd5600           -mov dword ptr [0x56cdec], ecx
    app->getMemory<x86::reg32>(x86::reg32(5688812) /* 0x56cdec */) = cpu.ecx;
    // 00510bd5  8d2c38                 -lea ebp, [eax + edi]
    cpu.ebp = x86::reg32(cpu.eax + cpu.edi * 1);
    // 00510bd8  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 00510bda  db05e8cd5600           -fild dword ptr [0x56cde8]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5688808) /* 0x56cde8 */))));
    // 00510be0  db05eccd5600           -fild dword ptr [0x56cdec]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5688812) /* 0x56cdec */))));
    // 00510be6  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 00510be8  d80d00ce5600           -fmul dword ptr [0x56ce00]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5688832) /* 0x56ce00 */));
    // 00510bee  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 00510bf0  dcc1                   -fadd st(1), st(0)
    cpu.fpu.st(1) += x86::Float(cpu.fpu.st(0));
    // 00510bf2  d80dfccd5600           -fmul dword ptr [0x56cdfc]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5688828) /* 0x56cdfc */));
    // 00510bf8  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00510bfa  d80d04ce5600           -fmul dword ptr [0x56ce04]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5688836) /* 0x56ce04 */));
    // 00510c00  f72df8cd5600           -imul dword ptr [0x56cdf8]
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5688824) /* 0x56cdf8 */))));
    // 00510c06  dcc1                   -fadd st(1), st(0)
    cpu.fpu.st(1) += x86::Float(cpu.fpu.st(0));
    // 00510c08  deea                   -fsubp st(2)
    cpu.fpu.st(2) -= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00510c0a  d80508ce5600           -fadd dword ptr [0x56ce08]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5688840) /* 0x56ce08 */));
    // 00510c10  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00510c12  d80508ce5600           -fadd dword ptr [0x56ce08]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5688840) /* 0x56ce08 */));
    // 00510c18  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00510c1b  8b5e18                 -mov ebx, dword ptr [esi + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 00510c1e  d1e2                   -shl edx, 1
    cpu.edx <<= 1 /*0x1*/ % 32;
    // 00510c20  dd1df0cd5600           -fstp qword ptr [0x56cdf0]
    app->getMemory<double>(x86::reg32(5688816) /* 0x56cdf0 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00510c26  dd1de8cd5600           -fstp qword ptr [0x56cde8]
    app->getMemory<double>(x86::reg32(5688808) /* 0x56cde8 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00510c2c  8b0de8cd5600           -mov ecx, dword ptr [0x56cde8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5688808) /* 0x56cde8 */);
    // 00510c32  8b3df0cd5600           -mov edi, dword ptr [0x56cdf0]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5688816) /* 0x56cdf0 */);
    // 00510c38  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00510c3a  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 00510c3c  01ef                   -add edi, ebp
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00510c3e  890deccd5600           -mov dword ptr [0x56cdec], ecx
    app->getMemory<x86::reg32>(x86::reg32(5688812) /* 0x56cdec */) = cpu.ecx;
    // 00510c44  8915f0cd5600           -mov dword ptr [0x56cdf0], edx
    app->getMemory<x86::reg32>(x86::reg32(5688816) /* 0x56cdf0 */) = cpu.edx;
    // 00510c4a  893df4cd5600           -mov dword ptr [0x56cdf4], edi
    app->getMemory<x86::reg32>(x86::reg32(5688820) /* 0x56cdf4 */) = cpu.edi;
    // 00510c50  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 00510c52  8b5610                 -mov edx, dword ptr [esi + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 00510c55  8d3418                 -lea esi, [eax + ebx]
    cpu.esi = x86::reg32(cpu.eax + cpu.ebx * 1);
    // 00510c58  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00510c5a  8d1c11                 -lea ebx, [ecx + edx]
    cpu.ebx = x86::reg32(cpu.ecx + cpu.edx * 1);
    // 00510c5d  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00510c5f  f72df8cd5600           -imul dword ptr [0x56cdf8]
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5688824) /* 0x56cdf8 */))));
    // 00510c65  d1e2                   -shl edx, 1
    cpu.edx <<= 1 /*0x1*/ % 32;
    // 00510c67  8b3de4cd5600           -mov edi, dword ptr [0x56cde4]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5688804) /* 0x56cde4 */);
    // 00510c6d  01d6                   -add esi, edx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edx));
    // 00510c6f  8b2deccd5600           -mov ebp, dword ptr [0x56cdec]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5688812) /* 0x56cdec */);
    // 00510c75  8d0411                 -lea eax, [ecx + edx]
    cpu.eax = x86::reg32(cpu.ecx + cpu.edx * 1);
    // 00510c78  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00510c7a  8d1433                 -lea edx, [ebx + esi]
    cpu.edx = x86::reg32(cpu.ebx + cpu.esi * 1);
    // 00510c7d  29f3                   -sub ebx, esi
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00510c7f  8d3429                 -lea esi, [ecx + ebp]
    cpu.esi = x86::reg32(cpu.ecx + cpu.ebp * 1);
    // 00510c82  29e9                   -sub ecx, ebp
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 00510c84  8b2de8cd5600           -mov ebp, dword ptr [0x56cde8]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5688808) /* 0x56cde8 */);
    // 00510c8a  897708                 -mov dword ptr [edi + 8], esi
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */) = cpu.esi;
    // 00510c8d  8b35f0cd5600           -mov esi, dword ptr [0x56cdf0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5688816) /* 0x56cdf0 */);
    // 00510c93  894f14                 -mov dword ptr [edi + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00510c96  8d0c2b                 -lea ecx, [ebx + ebp]
    cpu.ecx = x86::reg32(cpu.ebx + cpu.ebp * 1);
    // 00510c99  29eb                   -sub ebx, ebp
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 00510c9b  8b2df4cd5600           -mov ebp, dword ptr [0x56cdf4]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5688820) /* 0x56cdf4 */);
    // 00510ca1  894f0c                 -mov dword ptr [edi + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00510ca4  895f10                 -mov dword ptr [edi + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 00510ca7  8d1c30                 -lea ebx, [eax + esi]
    cpu.ebx = x86::reg32(cpu.eax + cpu.esi * 1);
    // 00510caa  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00510cac  8d0c2a                 -lea ecx, [edx + ebp]
    cpu.ecx = x86::reg32(cpu.edx + cpu.ebp * 1);
    // 00510caf  29ea                   -sub edx, ebp
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 00510cb1  890f                   -mov dword ptr [edi], ecx
    app->getMemory<x86::reg32>(cpu.edi) = cpu.ecx;
    // 00510cb3  895f04                 -mov dword ptr [edi + 4], ebx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 00510cb6  894718                 -mov dword ptr [edi + 0x18], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 00510cb9  89571c                 -mov dword ptr [edi + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 00510cbc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_510cbd(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00510cbd  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00510cbe  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00510cbf  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00510cc0  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00510cc1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00510cc2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00510cc3  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 00510cc6  8915e0cd5600           -mov dword ptr [0x56cde0], edx
    app->getMemory<x86::reg32>(x86::reg32(5688800) /* 0x56cde0 */) = cpu.edx;
    // 00510ccc  be2ccf5600             -mov esi, 0x56cf2c
    cpu.esi = 5689132 /*0x56cf2c*/;
    // 00510cd1  c705e4cd56000cce5600   -mov dword ptr [0x56cde4], 0x56ce0c
    app->getMemory<x86::reg32>(x86::reg32(5688804) /* 0x56cde4 */) = 5688844 /*0x56ce0c*/;
    // 00510cdb  e870fdffff             -call 0x510a50
    cpu.esp -= 4;
    sub_510a50(app, cpu);
    if (cpu.terminate) return;
    // 00510ce0  be4ccf5600             -mov esi, 0x56cf4c
    cpu.esi = 5689164 /*0x56cf4c*/;
    // 00510ce5  c705e4cd560010ce5600   -mov dword ptr [0x56cde4], 0x56ce10
    app->getMemory<x86::reg32>(x86::reg32(5688804) /* 0x56cde4 */) = 5688848 /*0x56ce10*/;
    // 00510cef  e85cfdffff             -call 0x510a50
    cpu.esp -= 4;
    sub_510a50(app, cpu);
    if (cpu.terminate) return;
    // 00510cf4  be6ccf5600             -mov esi, 0x56cf6c
    cpu.esi = 5689196 /*0x56cf6c*/;
    // 00510cf9  c705e4cd560014ce5600   -mov dword ptr [0x56cde4], 0x56ce14
    app->getMemory<x86::reg32>(x86::reg32(5688804) /* 0x56cde4 */) = 5688852 /*0x56ce14*/;
    // 00510d03  e848fdffff             -call 0x510a50
    cpu.esp -= 4;
    sub_510a50(app, cpu);
    if (cpu.terminate) return;
    // 00510d08  be8ccf5600             -mov esi, 0x56cf8c
    cpu.esi = 5689228 /*0x56cf8c*/;
    // 00510d0d  c705e4cd560018ce5600   -mov dword ptr [0x56cde4], 0x56ce18
    app->getMemory<x86::reg32>(x86::reg32(5688804) /* 0x56cde4 */) = 5688856 /*0x56ce18*/;
    // 00510d17  e834fdffff             -call 0x510a50
    cpu.esp -= 4;
    sub_510a50(app, cpu);
    if (cpu.terminate) return;
    // 00510d1c  beaccf5600             -mov esi, 0x56cfac
    cpu.esi = 5689260 /*0x56cfac*/;
    // 00510d21  c705e4cd56001cce5600   -mov dword ptr [0x56cde4], 0x56ce1c
    app->getMemory<x86::reg32>(x86::reg32(5688804) /* 0x56cde4 */) = 5688860 /*0x56ce1c*/;
    // 00510d2b  e820fdffff             -call 0x510a50
    cpu.esp -= 4;
    sub_510a50(app, cpu);
    if (cpu.terminate) return;
    // 00510d30  becccf5600             -mov esi, 0x56cfcc
    cpu.esi = 5689292 /*0x56cfcc*/;
    // 00510d35  c705e4cd560020ce5600   -mov dword ptr [0x56cde4], 0x56ce20
    app->getMemory<x86::reg32>(x86::reg32(5688804) /* 0x56cde4 */) = 5688864 /*0x56ce20*/;
    // 00510d3f  e80cfdffff             -call 0x510a50
    cpu.esp -= 4;
    sub_510a50(app, cpu);
    if (cpu.terminate) return;
    // 00510d44  beeccf5600             -mov esi, 0x56cfec
    cpu.esi = 5689324 /*0x56cfec*/;
    // 00510d49  c705e4cd560024ce5600   -mov dword ptr [0x56cde4], 0x56ce24
    app->getMemory<x86::reg32>(x86::reg32(5688804) /* 0x56cde4 */) = 5688868 /*0x56ce24*/;
    // 00510d53  e8f8fcffff             -call 0x510a50
    cpu.esp -= 4;
    sub_510a50(app, cpu);
    if (cpu.terminate) return;
    // 00510d58  be0cd05600             -mov esi, 0x56d00c
    cpu.esi = 5689356 /*0x56d00c*/;
    // 00510d5d  c705e4cd560028ce5600   -mov dword ptr [0x56cde4], 0x56ce28
    app->getMemory<x86::reg32>(x86::reg32(5688804) /* 0x56cde4 */) = 5688872 /*0x56ce28*/;
    // 00510d67  e8e4fcffff             -call 0x510a50
    cpu.esp -= 4;
    sub_510a50(app, cpu);
    if (cpu.terminate) return;
    // 00510d6c  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00510d6d  be0cce5600             -mov esi, 0x56ce0c
    cpu.esi = 5688844 /*0x56ce0c*/;
    // 00510d72  a3e4cd5600             -mov dword ptr [0x56cde4], eax
    app->getMemory<x86::reg32>(x86::reg32(5688804) /* 0x56cde4 */) = cpu.eax;
    // 00510d77  e837feffff             -call 0x510bb3
    cpu.esp -= 4;
    sub_510bb3(app, cpu);
    if (cpu.terminate) return;
    // 00510d7c  a1e4cd5600             -mov eax, dword ptr [0x56cde4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5688804) /* 0x56cde4 */);
    // 00510d81  8b15e0cd5600           -mov edx, dword ptr [0x56cde0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5688800) /* 0x56cde0 */);
    // 00510d87  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00510d89  be30ce5600             -mov esi, 0x56ce30
    cpu.esi = 5688880 /*0x56ce30*/;
    // 00510d8e  a3e4cd5600             -mov dword ptr [0x56cde4], eax
    app->getMemory<x86::reg32>(x86::reg32(5688804) /* 0x56cde4 */) = cpu.eax;
    // 00510d93  e81bfeffff             -call 0x510bb3
    cpu.esp -= 4;
    sub_510bb3(app, cpu);
    if (cpu.terminate) return;
    // 00510d98  a1e4cd5600             -mov eax, dword ptr [0x56cde4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5688804) /* 0x56cde4 */);
    // 00510d9d  8b15e0cd5600           -mov edx, dword ptr [0x56cde0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5688800) /* 0x56cde0 */);
    // 00510da3  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00510da5  be54ce5600             -mov esi, 0x56ce54
    cpu.esi = 5688916 /*0x56ce54*/;
    // 00510daa  a3e4cd5600             -mov dword ptr [0x56cde4], eax
    app->getMemory<x86::reg32>(x86::reg32(5688804) /* 0x56cde4 */) = cpu.eax;
    // 00510daf  e8fffdffff             -call 0x510bb3
    cpu.esp -= 4;
    sub_510bb3(app, cpu);
    if (cpu.terminate) return;
    // 00510db4  a1e4cd5600             -mov eax, dword ptr [0x56cde4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5688804) /* 0x56cde4 */);
    // 00510db9  8b15e0cd5600           -mov edx, dword ptr [0x56cde0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5688800) /* 0x56cde0 */);
    // 00510dbf  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00510dc1  be78ce5600             -mov esi, 0x56ce78
    cpu.esi = 5688952 /*0x56ce78*/;
    // 00510dc6  a3e4cd5600             -mov dword ptr [0x56cde4], eax
    app->getMemory<x86::reg32>(x86::reg32(5688804) /* 0x56cde4 */) = cpu.eax;
    // 00510dcb  e8e3fdffff             -call 0x510bb3
    cpu.esp -= 4;
    sub_510bb3(app, cpu);
    if (cpu.terminate) return;
    // 00510dd0  a1e4cd5600             -mov eax, dword ptr [0x56cde4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5688804) /* 0x56cde4 */);
    // 00510dd5  8b15e0cd5600           -mov edx, dword ptr [0x56cde0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5688800) /* 0x56cde0 */);
    // 00510ddb  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00510ddd  be9cce5600             -mov esi, 0x56ce9c
    cpu.esi = 5688988 /*0x56ce9c*/;
    // 00510de2  a3e4cd5600             -mov dword ptr [0x56cde4], eax
    app->getMemory<x86::reg32>(x86::reg32(5688804) /* 0x56cde4 */) = cpu.eax;
    // 00510de7  e8c7fdffff             -call 0x510bb3
    cpu.esp -= 4;
    sub_510bb3(app, cpu);
    if (cpu.terminate) return;
    // 00510dec  a1e4cd5600             -mov eax, dword ptr [0x56cde4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5688804) /* 0x56cde4 */);
    // 00510df1  8b15e0cd5600           -mov edx, dword ptr [0x56cde0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5688800) /* 0x56cde0 */);
    // 00510df7  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00510df9  bec0ce5600             -mov esi, 0x56cec0
    cpu.esi = 5689024 /*0x56cec0*/;
    // 00510dfe  a3e4cd5600             -mov dword ptr [0x56cde4], eax
    app->getMemory<x86::reg32>(x86::reg32(5688804) /* 0x56cde4 */) = cpu.eax;
    // 00510e03  e8abfdffff             -call 0x510bb3
    cpu.esp -= 4;
    sub_510bb3(app, cpu);
    if (cpu.terminate) return;
    // 00510e08  a1e4cd5600             -mov eax, dword ptr [0x56cde4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5688804) /* 0x56cde4 */);
    // 00510e0d  8b15e0cd5600           -mov edx, dword ptr [0x56cde0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5688800) /* 0x56cde0 */);
    // 00510e13  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00510e15  bee4ce5600             -mov esi, 0x56cee4
    cpu.esi = 5689060 /*0x56cee4*/;
    // 00510e1a  a3e4cd5600             -mov dword ptr [0x56cde4], eax
    app->getMemory<x86::reg32>(x86::reg32(5688804) /* 0x56cde4 */) = cpu.eax;
    // 00510e1f  e88ffdffff             -call 0x510bb3
    cpu.esp -= 4;
    sub_510bb3(app, cpu);
    if (cpu.terminate) return;
    // 00510e24  a1e4cd5600             -mov eax, dword ptr [0x56cde4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5688804) /* 0x56cde4 */);
    // 00510e29  8b15e0cd5600           -mov edx, dword ptr [0x56cde0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5688800) /* 0x56cde0 */);
    // 00510e2f  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00510e31  be08cf5600             -mov esi, 0x56cf08
    cpu.esi = 5689096 /*0x56cf08*/;
    // 00510e36  a3e4cd5600             -mov dword ptr [0x56cde4], eax
    app->getMemory<x86::reg32>(x86::reg32(5688804) /* 0x56cde4 */) = cpu.eax;
    // 00510e3b  e873fdffff             -call 0x510bb3
    cpu.esp -= 4;
    sub_510bb3(app, cpu);
    if (cpu.terminate) return;
    // 00510e40  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00510e41  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00510e42  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00510e43  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00510e44  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00510e45  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_510e48(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00510e48  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00510e49  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00510e4a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00510e4b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00510e4c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00510e4d  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00510e4e  8b3548259f00           -mov esi, dword ptr [0x9f2548]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(10429768) /* 0x9f2548 */);
    // 00510e54  8b3d3c259f00           -mov edi, dword ptr [0x9f253c]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(10429756) /* 0x9f253c */);
    // 00510e5a  8b2d44259f00           -mov ebp, dword ptr [0x9f2544]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(10429764) /* 0x9f2544 */);
    // 00510e60  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00510e62  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 00510e65  bb30cf5600             -mov ebx, 0x56cf30
    cpu.ebx = 5689136 /*0x56cf30*/;
    // 00510e6a  f72d380c9f00           -imul dword ptr [0x9f0c38]
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(10423352) /* 0x9f0c38 */))));
    // 00510e70  a32ccf5600             -mov dword ptr [0x56cf2c], eax
    app->getMemory<x86::reg32>(x86::reg32(5689132) /* 0x56cf2c */) = cpu.eax;
    // 00510e75  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00510e77  c1e708                 -shl edi, 8
    cpu.edi <<= 8 /*0x8*/ % 32;
    // 00510e7a  83ed08                 -sub ebp, 8
    (cpu.ebp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00510e7d  83fd10                 +cmp ebp, 0x10
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
    // 00510e80  7d14                   -jge 0x510e96
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00510e96;
    }
    // 00510e82  668b06                 -mov ax, word ptr [esi]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi);
    // 00510e85  b910000000             -mov ecx, 0x10
    cpu.ecx = 16 /*0x10*/;
    // 00510e8a  29e9                   -sub ecx, ebp
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 00510e8c  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00510e8f  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 00510e91  09c7                   -or edi, eax
    cpu.edi |= x86::reg32(x86::sreg32(cpu.eax));
    // 00510e93  83c510                 -add ebp, 0x10
    (cpu.ebp) += x86::reg32(x86::sreg32(16 /*0x10*/));
L_0x00510e96:
    // 00510e96  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00510e98  b907000000             -mov ecx, 7
    cpu.ecx = 7 /*0x7*/;
L_0x00510e9d:
    // 00510e9d  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 00510e9f  894304                 -mov dword ptr [ebx + 4], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00510ea2  894308                 -mov dword ptr [ebx + 8], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00510ea5  89430c                 -mov dword ptr [ebx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00510ea8  894310                 -mov dword ptr [ebx + 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00510eab  894314                 -mov dword ptr [ebx + 0x14], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 00510eae  894318                 -mov dword ptr [ebx + 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 00510eb1  89431c                 -mov dword ptr [ebx + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 00510eb4  894320                 -mov dword ptr [ebx + 0x20], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 00510eb7  83c324                 +add ebx, 0x24
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(36 /*0x24*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00510eba  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00510ebb  75e0                   -jne 0x510e9d
    if (!cpu.flags.zf)
    {
        goto L_0x00510e9d;
    }
    // 00510ebd  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
L_0x00510ec2:
    // 00510ec2  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00510ec4  c1e817                 -shr eax, 0x17
    cpu.eax >>= 23 /*0x17*/ % 32;
    // 00510ec7  8b148538199f00         -mov edx, dword ptr [eax*4 + 0x9f1938]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10426680) /* 0x9f1938 */ + cpu.eax * 4);
    // 00510ece  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00510ed0  80fa09                 +cmp dl, 9
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(9 /*0x9*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00510ed3  0f8eb9000000           -jle 0x510f92
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00510f92;
    }
    // 00510ed9  80fa20                 +cmp dl, 0x20
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(32 /*0x20*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00510edc  7362                   -jae 0x510f40
    if (!cpu.flags.cf)
    {
        goto L_0x00510f40;
    }
    // 00510ede  80fa10                 +cmp dl, 0x10
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
    // 00510ee1  7330                   -jae 0x510f13
    if (!cpu.flags.cf)
    {
        goto L_0x00510f13;
    }
    // 00510ee3  c1e709                 -shl edi, 9
    cpu.edi <<= 9 /*0x9*/ % 32;
    // 00510ee6  83ed09                 -sub ebp, 9
    (cpu.ebp) -= x86::reg32(x86::sreg32(9 /*0x9*/));
    // 00510ee9  83fd10                 +cmp ebp, 0x10
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
    // 00510eec  7d14                   -jge 0x510f02
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00510f02;
    }
    // 00510eee  668b06                 -mov ax, word ptr [esi]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi);
    // 00510ef1  b910000000             -mov ecx, 0x10
    cpu.ecx = 16 /*0x10*/;
    // 00510ef6  29e9                   -sub ecx, ebp
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 00510ef8  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00510efb  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 00510efd  09c7                   -or edi, eax
    cpu.edi |= x86::reg32(x86::sreg32(cpu.eax));
    // 00510eff  83c510                 -add ebp, 0x10
    (cpu.ebp) += x86::reg32(x86::sreg32(16 /*0x10*/));
L_0x00510f02:
    // 00510f02  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00510f04  c1e818                 +shr eax, 0x18
    {
        x86::reg8 tmp = 24 /*0x18*/ % 32;
        x86::reg32& op = cpu.eax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 00510f07  8b148538119f00         -mov edx, dword ptr [eax*4 + 0x9f1138]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10424632) /* 0x9f1138 */ + cpu.eax * 4);
    // 00510f0e  e97f000000             -jmp 0x510f92
    goto L_0x00510f92;
L_0x00510f13:
    // 00510f13  c1e706                 -shl edi, 6
    cpu.edi <<= 6 /*0x6*/ % 32;
    // 00510f16  83ed06                 -sub ebp, 6
    (cpu.ebp) -= x86::reg32(x86::sreg32(6 /*0x6*/));
    // 00510f19  83fd10                 +cmp ebp, 0x10
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
    // 00510f1c  7d14                   -jge 0x510f32
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00510f32;
    }
    // 00510f1e  668b06                 -mov ax, word ptr [esi]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi);
    // 00510f21  b910000000             -mov ecx, 0x10
    cpu.ecx = 16 /*0x10*/;
    // 00510f26  29e9                   -sub ecx, ebp
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 00510f28  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00510f2b  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 00510f2d  09c7                   -or edi, eax
    cpu.edi |= x86::reg32(x86::sreg32(cpu.eax));
    // 00510f2f  83c510                 -add ebp, 0x10
    (cpu.ebp) += x86::reg32(x86::sreg32(16 /*0x10*/));
L_0x00510f32:
    // 00510f32  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00510f34  c1e818                 +shr eax, 0x18
    {
        x86::reg8 tmp = 24 /*0x18*/ % 32;
        x86::reg32& op = cpu.eax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 00510f37  8b148538159f00         -mov edx, dword ptr [eax*4 + 0x9f1538]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10425656) /* 0x9f1538 */ + cpu.eax * 4);
    // 00510f3e  eb52                   -jmp 0x510f92
    goto L_0x00510f92;
L_0x00510f40:
    // 00510f40  80fa30                 +cmp dl, 0x30
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
    // 00510f43  732c                   -jae 0x510f71
    if (!cpu.flags.cf)
    {
        goto L_0x00510f71;
    }
    // 00510f45  c1e706                 -shl edi, 6
    cpu.edi <<= 6 /*0x6*/ % 32;
    // 00510f48  83ed06                 -sub ebp, 6
    (cpu.ebp) -= x86::reg32(x86::sreg32(6 /*0x6*/));
    // 00510f4b  83fd10                 +cmp ebp, 0x10
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
    // 00510f4e  7d14                   -jge 0x510f64
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00510f64;
    }
    // 00510f50  668b06                 -mov ax, word ptr [esi]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi);
    // 00510f53  b910000000             -mov ecx, 0x10
    cpu.ecx = 16 /*0x10*/;
    // 00510f58  29e9                   -sub ecx, ebp
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 00510f5a  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00510f5d  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 00510f5f  09c7                   -or edi, eax
    cpu.edi |= x86::reg32(x86::sreg32(cpu.eax));
    // 00510f61  83c510                 -add ebp, 0x10
    (cpu.ebp) += x86::reg32(x86::sreg32(16 /*0x10*/));
L_0x00510f64:
    // 00510f64  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00510f66  81e20000ffff           -and edx, 0xffff0000
    cpu.edx &= x86::reg32(x86::sreg32(4294901760 /*0xffff0000*/));
    // 00510f6c  83ca10                 +or edx, 0x10
    cpu.clear_co();
    cpu.set_szp((cpu.edx |= x86::reg32(x86::sreg32(16 /*0x10*/))));
    // 00510f6f  eb21                   -jmp 0x510f92
    goto L_0x00510f92;
L_0x00510f71:
    // 00510f71  c1e702                 -shl edi, 2
    cpu.edi <<= 2 /*0x2*/ % 32;
    // 00510f74  83ed02                 -sub ebp, 2
    (cpu.ebp) -= x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00510f77  83fd10                 +cmp ebp, 0x10
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
    // 00510f7a  7d61                   -jge 0x510fdd
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00510fdd;
    }
    // 00510f7c  668b06                 -mov ax, word ptr [esi]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi);
    // 00510f7f  b910000000             -mov ecx, 0x10
    cpu.ecx = 16 /*0x10*/;
    // 00510f84  29e9                   -sub ecx, ebp
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 00510f86  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00510f89  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 00510f8b  09c7                   -or edi, eax
    cpu.edi |= x86::reg32(x86::sreg32(cpu.eax));
    // 00510f8d  83c510                 +add ebp, 0x10
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00510f90  eb4b                   -jmp 0x510fdd
    goto L_0x00510fdd;
L_0x00510f92:
    // 00510f92  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00510f94  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00510f96  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 00510f99  88d1                   -mov cl, dl
    cpu.cl = cpu.dl;
    // 00510f9b  83e03f                 -and eax, 0x3f
    cpu.eax &= x86::reg32(x86::sreg32(63 /*0x3f*/));
    // 00510f9e  29cd                   -sub ebp, ecx
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00510fa0  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00510fa2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00510fa4  d3e7                   -shl edi, cl
    cpu.edi <<= cpu.cl % 32;
    // 00510fa6  83fd10                 +cmp ebp, 0x10
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
    // 00510fa9  7d14                   -jge 0x510fbf
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00510fbf;
    }
    // 00510fab  668b06                 -mov ax, word ptr [esi]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi);
    // 00510fae  b910000000             -mov ecx, 0x10
    cpu.ecx = 16 /*0x10*/;
    // 00510fb3  29e9                   -sub ecx, ebp
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 00510fb5  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00510fb8  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 00510fba  09c7                   -or edi, eax
    cpu.edi |= x86::reg32(x86::sreg32(cpu.eax));
    // 00510fbc  83c510                 -add ebp, 0x10
    (cpu.ebp) += x86::reg32(x86::sreg32(16 /*0x10*/));
L_0x00510fbf:
    // 00510fbf  8b0c9dcc885600         -mov ecx, dword ptr [ebx*4 + 0x5688cc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5671116) /* 0x5688cc */ + cpu.ebx * 4);
    // 00510fc6  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00510fc8  c1f816                 -sar eax, 0x16
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (22 /*0x16*/ % 32));
    // 00510fcb  43                     -inc ebx
    (cpu.ebx)++;
    // 00510fcc  f7a9380c9f00           +imul dword ptr [ecx + 0x9f0c38]
    {
        cpu.edx_eax = x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(10423352) /* 0x9f0c38 */)));
        cpu.flags.of = cpu.flags.cf = (static_cast<x86::sreg64>(cpu.edx_eax) != x86::sreg64(static_cast<x86::sreg32>(cpu.eax)));
    }
    // 00510fd2  89812ccf5600           -mov dword ptr [ecx + 0x56cf2c], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5689132) /* 0x56cf2c */) = cpu.eax;
    // 00510fd8  e9e5feffff             -jmp 0x510ec2
    goto L_0x00510ec2;
L_0x00510fdd:
    // 00510fdd  893548259f00           -mov dword ptr [0x9f2548], esi
    app->getMemory<x86::reg32>(x86::reg32(10429768) /* 0x9f2548 */) = cpu.esi;
    // 00510fe3  893d3c259f00           -mov dword ptr [0x9f253c], edi
    app->getMemory<x86::reg32>(x86::reg32(10429756) /* 0x9f253c */) = cpu.edi;
    // 00510fe9  892d44259f00           -mov dword ptr [0x9f2544], ebp
    app->getMemory<x86::reg32>(x86::reg32(10429764) /* 0x9f2544 */) = cpu.ebp;
    // 00510fef  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00510ff1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00510ff2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00510ff3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00510ff4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00510ff5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00510ff6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00510ff7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_510ff8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00510ff8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00510ff9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00510ffa  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00510ffb  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00510ffc  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00510ffe  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00511000  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 00511002  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00511004  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00511006  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00511008  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0051100a  8a4602                 -mov al, byte ptr [esi + 2]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 0051100d  8a5f02                 -mov bl, byte ptr [edi + 2]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(2) /* 0x2 */);
    // 00511010  8a4e06                 -mov cl, byte ptr [esi + 6]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(6) /* 0x6 */);
    // 00511013  8a9702010000           -mov dl, byte ptr [edi + 0x102]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(258) /* 0x102 */);
    // 00511019  8a80380d9f00           -mov al, byte ptr [eax + 0x9f0d38]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(10423608) /* 0x9f0d38 */);
    // 0051101f  8a9b380d9f00           -mov bl, byte ptr [ebx + 0x9f0d38]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(10423608) /* 0x9f0d38 */);
    // 00511025  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 00511028  8a89380d9f00           -mov cl, byte ptr [ecx + 0x9f0d38]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(10423608) /* 0x9f0d38 */);
    // 0051102e  c1e308                 -shl ebx, 8
    cpu.ebx <<= 8 /*0x8*/ % 32;
    // 00511031  8a92380d9f00           -mov dl, byte ptr [edx + 0x9f0d38]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(10423608) /* 0x9f0d38 */);
    // 00511037  09c8                   -or eax, ecx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ecx));
    // 00511039  09d3                   -or ebx, edx
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.edx));
    // 0051103b  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 0051103e  09d8                   -or eax, ebx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ebx));
    // 00511040  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00511042  894500                 -mov dword ptr [ebp], eax
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.eax;
    // 00511045  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00511047  8a460a                 -mov al, byte ptr [esi + 0xa]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(10) /* 0xa */);
    // 0051104a  8a5f06                 -mov bl, byte ptr [edi + 6]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(6) /* 0x6 */);
    // 0051104d  8a4e0e                 -mov cl, byte ptr [esi + 0xe]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(14) /* 0xe */);
    // 00511050  8a9706010000           -mov dl, byte ptr [edi + 0x106]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(262) /* 0x106 */);
    // 00511056  8a80380d9f00           -mov al, byte ptr [eax + 0x9f0d38]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(10423608) /* 0x9f0d38 */);
    // 0051105c  8a9b380d9f00           -mov bl, byte ptr [ebx + 0x9f0d38]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(10423608) /* 0x9f0d38 */);
    // 00511062  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 00511065  8a89380d9f00           -mov cl, byte ptr [ecx + 0x9f0d38]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(10423608) /* 0x9f0d38 */);
    // 0051106b  c1e308                 -shl ebx, 8
    cpu.ebx <<= 8 /*0x8*/ % 32;
    // 0051106e  8a92380d9f00           -mov dl, byte ptr [edx + 0x9f0d38]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(10423608) /* 0x9f0d38 */);
    // 00511074  09c8                   -or eax, ecx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ecx));
    // 00511076  09d3                   -or ebx, edx
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.edx));
    // 00511078  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 0051107b  09d8                   -or eax, ebx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ebx));
    // 0051107d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0051107f  894504                 -mov dword ptr [ebp + 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00511082  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00511084  8a4612                 -mov al, byte ptr [esi + 0x12]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(18) /* 0x12 */);
    // 00511087  8a5f0a                 -mov bl, byte ptr [edi + 0xa]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(10) /* 0xa */);
    // 0051108a  8a4e16                 -mov cl, byte ptr [esi + 0x16]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(22) /* 0x16 */);
    // 0051108d  8a970a010000           -mov dl, byte ptr [edi + 0x10a]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(266) /* 0x10a */);
    // 00511093  8a80380d9f00           -mov al, byte ptr [eax + 0x9f0d38]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(10423608) /* 0x9f0d38 */);
    // 00511099  8a9b380d9f00           -mov bl, byte ptr [ebx + 0x9f0d38]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(10423608) /* 0x9f0d38 */);
    // 0051109f  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 005110a2  8a89380d9f00           -mov cl, byte ptr [ecx + 0x9f0d38]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(10423608) /* 0x9f0d38 */);
    // 005110a8  c1e308                 -shl ebx, 8
    cpu.ebx <<= 8 /*0x8*/ % 32;
    // 005110ab  8a92380d9f00           -mov dl, byte ptr [edx + 0x9f0d38]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(10423608) /* 0x9f0d38 */);
    // 005110b1  09c8                   -or eax, ecx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ecx));
    // 005110b3  09d3                   -or ebx, edx
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.edx));
    // 005110b5  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 005110b8  09d8                   -or eax, ebx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ebx));
    // 005110ba  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 005110bc  894508                 -mov dword ptr [ebp + 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 005110bf  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 005110c1  8a461a                 -mov al, byte ptr [esi + 0x1a]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(26) /* 0x1a */);
    // 005110c4  8a5f0e                 -mov bl, byte ptr [edi + 0xe]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(14) /* 0xe */);
    // 005110c7  8a4e1e                 -mov cl, byte ptr [esi + 0x1e]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(30) /* 0x1e */);
    // 005110ca  8a970e010000           -mov dl, byte ptr [edi + 0x10e]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(270) /* 0x10e */);
    // 005110d0  8a80380d9f00           -mov al, byte ptr [eax + 0x9f0d38]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(10423608) /* 0x9f0d38 */);
    // 005110d6  8a9b380d9f00           -mov bl, byte ptr [ebx + 0x9f0d38]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(10423608) /* 0x9f0d38 */);
    // 005110dc  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 005110df  8a89380d9f00           -mov cl, byte ptr [ecx + 0x9f0d38]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(10423608) /* 0x9f0d38 */);
    // 005110e5  c1e308                 -shl ebx, 8
    cpu.ebx <<= 8 /*0x8*/ % 32;
    // 005110e8  8a92380d9f00           -mov dl, byte ptr [edx + 0x9f0d38]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(10423608) /* 0x9f0d38 */);
    // 005110ee  09c8                   -or eax, ecx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ecx));
    // 005110f0  09d3                   -or ebx, edx
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.edx));
    // 005110f2  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 005110f5  09d8                   -or eax, ebx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ebx));
    // 005110f7  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 005110f9  89450c                 -mov dword ptr [ebp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 005110fc  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 005110fe  8a4622                 -mov al, byte ptr [esi + 0x22]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(34) /* 0x22 */);
    // 00511101  8a5f12                 -mov bl, byte ptr [edi + 0x12]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(18) /* 0x12 */);
    // 00511104  8a4e26                 -mov cl, byte ptr [esi + 0x26]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(38) /* 0x26 */);
    // 00511107  8a9712010000           -mov dl, byte ptr [edi + 0x112]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(274) /* 0x112 */);
    // 0051110d  8a80380d9f00           -mov al, byte ptr [eax + 0x9f0d38]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(10423608) /* 0x9f0d38 */);
    // 00511113  8a9b380d9f00           -mov bl, byte ptr [ebx + 0x9f0d38]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(10423608) /* 0x9f0d38 */);
    // 00511119  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 0051111c  8a89380d9f00           -mov cl, byte ptr [ecx + 0x9f0d38]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(10423608) /* 0x9f0d38 */);
    // 00511122  c1e308                 -shl ebx, 8
    cpu.ebx <<= 8 /*0x8*/ % 32;
    // 00511125  8a92380d9f00           -mov dl, byte ptr [edx + 0x9f0d38]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(10423608) /* 0x9f0d38 */);
    // 0051112b  09c8                   -or eax, ecx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ecx));
    // 0051112d  09d3                   -or ebx, edx
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.edx));
    // 0051112f  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 00511132  09d8                   -or eax, ebx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ebx));
    // 00511134  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00511136  894510                 -mov dword ptr [ebp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00511139  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0051113b  8a462a                 -mov al, byte ptr [esi + 0x2a]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(42) /* 0x2a */);
    // 0051113e  8a5f16                 -mov bl, byte ptr [edi + 0x16]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(22) /* 0x16 */);
    // 00511141  8a4e2e                 -mov cl, byte ptr [esi + 0x2e]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(46) /* 0x2e */);
    // 00511144  8a9716010000           -mov dl, byte ptr [edi + 0x116]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(278) /* 0x116 */);
    // 0051114a  8a80380d9f00           -mov al, byte ptr [eax + 0x9f0d38]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(10423608) /* 0x9f0d38 */);
    // 00511150  8a9b380d9f00           -mov bl, byte ptr [ebx + 0x9f0d38]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(10423608) /* 0x9f0d38 */);
    // 00511156  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 00511159  8a89380d9f00           -mov cl, byte ptr [ecx + 0x9f0d38]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(10423608) /* 0x9f0d38 */);
    // 0051115f  c1e308                 -shl ebx, 8
    cpu.ebx <<= 8 /*0x8*/ % 32;
    // 00511162  8a92380d9f00           -mov dl, byte ptr [edx + 0x9f0d38]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(10423608) /* 0x9f0d38 */);
    // 00511168  09c8                   -or eax, ecx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ecx));
    // 0051116a  09d3                   -or ebx, edx
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.edx));
    // 0051116c  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 0051116f  09d8                   -or eax, ebx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ebx));
    // 00511171  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00511173  894514                 -mov dword ptr [ebp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 00511176  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00511178  8a4632                 -mov al, byte ptr [esi + 0x32]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(50) /* 0x32 */);
    // 0051117b  8a5f1a                 -mov bl, byte ptr [edi + 0x1a]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(26) /* 0x1a */);
    // 0051117e  8a4e36                 -mov cl, byte ptr [esi + 0x36]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(54) /* 0x36 */);
    // 00511181  8a971a010000           -mov dl, byte ptr [edi + 0x11a]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(282) /* 0x11a */);
    // 00511187  8a80380d9f00           -mov al, byte ptr [eax + 0x9f0d38]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(10423608) /* 0x9f0d38 */);
    // 0051118d  8a9b380d9f00           -mov bl, byte ptr [ebx + 0x9f0d38]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(10423608) /* 0x9f0d38 */);
    // 00511193  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 00511196  8a89380d9f00           -mov cl, byte ptr [ecx + 0x9f0d38]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(10423608) /* 0x9f0d38 */);
    // 0051119c  c1e308                 -shl ebx, 8
    cpu.ebx <<= 8 /*0x8*/ % 32;
    // 0051119f  8a92380d9f00           -mov dl, byte ptr [edx + 0x9f0d38]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(10423608) /* 0x9f0d38 */);
    // 005111a5  09c8                   -or eax, ecx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ecx));
    // 005111a7  09d3                   -or ebx, edx
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.edx));
    // 005111a9  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 005111ac  09d8                   -or eax, ebx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ebx));
    // 005111ae  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 005111b0  894518                 -mov dword ptr [ebp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 005111b3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 005111b5  8a463a                 -mov al, byte ptr [esi + 0x3a]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(58) /* 0x3a */);
    // 005111b8  8a5f1e                 -mov bl, byte ptr [edi + 0x1e]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(30) /* 0x1e */);
    // 005111bb  8a4e3e                 -mov cl, byte ptr [esi + 0x3e]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(62) /* 0x3e */);
    // 005111be  8a971e010000           -mov dl, byte ptr [edi + 0x11e]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(286) /* 0x11e */);
    // 005111c4  8a80380d9f00           -mov al, byte ptr [eax + 0x9f0d38]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(10423608) /* 0x9f0d38 */);
    // 005111ca  8a9b380d9f00           -mov bl, byte ptr [ebx + 0x9f0d38]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(10423608) /* 0x9f0d38 */);
    // 005111d0  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 005111d3  8a89380d9f00           -mov cl, byte ptr [ecx + 0x9f0d38]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(10423608) /* 0x9f0d38 */);
    // 005111d9  c1e308                 -shl ebx, 8
    cpu.ebx <<= 8 /*0x8*/ % 32;
    // 005111dc  8a92380d9f00           -mov dl, byte ptr [edx + 0x9f0d38]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(10423608) /* 0x9f0d38 */);
    // 005111e2  09c8                   -or eax, ecx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ecx));
    // 005111e4  09d3                   -or ebx, edx
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.edx));
    // 005111e6  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 005111e9  09d8                   -or eax, ebx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ebx));
    // 005111eb  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 005111ed  89451c                 -mov dword ptr [ebp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 005111f0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 005111f2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005111f3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005111f4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005111f5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005111f6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_511200(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00511200  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00511201  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00511203  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00511206  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00511208  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0051120b  83c034                 -add eax, 0x34
    (cpu.eax) += x86::reg32(x86::sreg32(52 /*0x34*/));
    // 0051120e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051120f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_511210(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00511210  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00511211  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00511213  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00511216  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00511218  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0051121b  8d5034                 -lea edx, [eax + 0x34]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(52) /* 0x34 */);
    // 0051121e  e86d2b0100             -call 0x523d90
    cpu.esp -= 4;
    sub_523d90(app, cpu);
    if (cpu.terminate) return;
    // 00511223  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00511225  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00511226  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_511228(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00511228  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00511229  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0051122a  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0051122b  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0051122e  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00511230  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00511232  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 00511236  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 00511238  803df49aa00000         +cmp byte ptr [0xa09af4], 0
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
    // 0051123f  7439                   -je 0x51127a
    if (cpu.flags.zf)
    {
        goto L_0x0051127a;
    }
    // 00511241  8b1544b0a000           -mov edx, dword ptr [0xa0b044]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10530884) /* 0xa0b044 */);
    // 00511247  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00511249  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0051124b  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0051124d  7412                   -je 0x511261
    if (cpu.flags.zf)
    {
        goto L_0x00511261;
    }
L_0x0051124f:
    // 0051124f  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00511252  43                     -inc ebx
    (cpu.ebx)++;
    // 00511253  83f940                 +cmp ecx, 0x40
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(64 /*0x40*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00511256  7d29                   -jge 0x511281
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00511281;
    }
    // 00511258  83b944b0a00000         +cmp dword ptr [ecx + 0xa0b044], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(10530884) /* 0xa0b044 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051125f  75ee                   -jne 0x51124f
    if (!cpu.flags.zf)
    {
        goto L_0x0051124f;
    }
L_0x00511261:
    // 00511261  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00511263  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00511265  e8262b0100             -call 0x523d90
    cpu.esp -= 4;
    sub_523d90(app, cpu);
    if (cpu.terminate) return;
    // 0051126a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051126c  7d1a                   -jge 0x511288
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00511288;
    }
    // 0051126e  b8faffffff             -mov eax, 0xfffffffa
    cpu.eax = 4294967290 /*0xfffffffa*/;
L_0x00511273:
    // 00511273  83c408                 +add esp, 8
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
    // 00511276  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00511277  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00511278  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00511279  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0051127a:
    // 0051127a  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 0051127f  ebf2                   -jmp 0x511273
    goto L_0x00511273;
L_0x00511281:
    // 00511281  b8f7ffffff             -mov eax, 0xfffffff7
    cpu.eax = 4294967287 /*0xfffffff7*/;
    // 00511286  ebeb                   -jmp 0x511273
    goto L_0x00511273;
L_0x00511288:
    // 00511288  e8032b0100             -call 0x523d90
    cpu.esp -= 4;
    sub_523d90(app, cpu);
    if (cpu.terminate) return;
    // 0051128d  893424                 -mov dword ptr [esp], esi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.esi;
    // 00511290  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00511292  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00511294  e8f72a0100             -call 0x523d90
    cpu.esp -= 4;
    sub_523d90(app, cpu);
    if (cpu.terminate) return;
    // 00511299  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0051129b  89b144b0a000           -mov dword ptr [ecx + 0xa0b044], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(10530884) /* 0xa0b044 */) = cpu.esi;
    // 005112a1  b90c000000             -mov ecx, 0xc
    cpu.ecx = 12 /*0xc*/;
    // 005112a6  8d47cc                 -lea eax, [edi - 0x34]
    cpu.eax = x86::reg32(cpu.edi + x86::reg32(-52) /* -0x34 */);
    // 005112a9  f7f1                   -div ecx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ecx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 005112ab  66894608               -mov word ptr [esi + 8], ax
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.ax;
    // 005112af  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 005112b2  896e20                 -mov dword ptr [esi + 0x20], ebp
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */) = cpu.ebp;
    // 005112b5  894618                 -mov dword ptr [esi + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 005112b8  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 005112bc  89461c                 -mov dword ptr [esi + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 005112bf  c706ffffffff           -mov dword ptr [esi], 0xffffffff
    app->getMemory<x86::reg32>(cpu.esi) = 4294967295 /*0xffffffff*/;
    // 005112c5  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 005112c7  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 005112ca  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005112cb  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005112cc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005112cd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_5112d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005112d0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005112d1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 005112d2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005112d3  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 005112d6  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 005112da  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 005112de  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 005112e0  894c240c               -mov dword ptr [esp + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 005112e4  803df49aa00000         +cmp byte ptr [0xa09af4], 0
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
    // 005112eb  750c                   -jne 0x5112f9
    if (!cpu.flags.zf)
    {
        goto L_0x005112f9;
    }
    // 005112ed  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 005112f2  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 005112f5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005112f6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005112f7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005112f8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005112f9:
    // 005112f9  8b7c2408               -mov edi, dword ptr [esp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 005112fd  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 005112ff  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00511304  e8872c0100             -call 0x523f90
    cpu.esp -= 4;
    sub_523f90(app, cpu);
    if (cpu.terminate) return;
    // 00511309  89e1                   -mov ecx, esp
    cpu.ecx = cpu.esp;
    // 0051130b  8b3cbd44b0a000         -mov edi, dword ptr [edi*4 + 0xa0b044]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(10530884) /* 0xa0b044 */ + cpu.edi * 4);
    // 00511312  e809fbfeff             -call 0x500e20
    cpu.esp -= 4;
    sub_500e20(app, cpu);
    if (cpu.terminate) return;
    // 00511317  8b5b03                 -mov ebx, dword ptr [ebx + 3]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(3) /* 0x3 */);
    // 0051131a  8b4500                 -mov eax, dword ptr [ebp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp);
    // 0051131d  c1fb18                 -sar ebx, 0x18
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (24 /*0x18*/ % 32));
    // 00511320  e847e5feff             -call 0x4ff86c
    cpu.esp -= 4;
    sub_4ff86c(app, cpu);
    if (cpu.terminate) return;
    // 00511325  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00511327  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00511329  0f8c7d010000           -jl 0x5114ac
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x005114ac;
    }
    // 0051132f  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00511332  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 00511334  66c7470a0000           -mov word ptr [edi + 0xa], 0
    app->getMemory<x86::reg16>(cpu.edi + x86::reg32(10) /* 0xa */) = 0 /*0x0*/;
    // 0051133a  66c7470e0000           -mov word ptr [edi + 0xe], 0
    app->getMemory<x86::reg16>(cpu.edi + x86::reg32(14) /* 0xe */) = 0 /*0x0*/;
    // 00511340  c7471000000000         -mov dword ptr [edi + 0x10], 0
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
    // 00511347  c7470400000000         -mov dword ptr [edi + 4], 0
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 0051134e  c7471400000000         -mov dword ptr [edi + 0x14], 0
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(20) /* 0x14 */) = 0 /*0x0*/;
    // 00511355  66c7470cffff           -mov word ptr [edi + 0xc], 0xffff
    app->getMemory<x86::reg16>(cpu.edi + x86::reg32(12) /* 0xc */) = 65535 /*0xffff*/;
    // 0051135b  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0051135f  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00511361  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00511363  894724                 -mov dword ptr [edi + 0x24], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 00511366  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0051136d  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0051136f  b93c9ba000             -mov ecx, 0xa09b3c
    cpu.ecx = 10525500 /*0xa09b3c*/;
    // 00511374  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 00511377  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00511379  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0051137d  c6410aff               -mov byte ptr [ecx + 0xa], 0xff
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(10) /* 0xa */) = 255 /*0xff*/;
    // 00511381  8a4007                 -mov al, byte ptr [eax + 7]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(7) /* 0x7 */);
    // 00511384  88410f                 -mov byte ptr [ecx + 0xf], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(15) /* 0xf */) = cpu.al;
    // 00511387  668b4504               -mov ax, word ptr [ebp + 4]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 0051138b  66894110               -mov word ptr [ecx + 0x10], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(16) /* 0x10 */) = cpu.ax;
    // 0051138f  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00511393  c7411800000000         -mov dword ptr [ecx + 0x18], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 0051139a  8b4005                 -mov eax, dword ptr [eax + 5]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5) /* 0x5 */);
    // 0051139d  c7412400000000         -mov dword ptr [ecx + 0x24], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(36) /* 0x24 */) = 0 /*0x0*/;
    // 005113a4  c7412cffffff7f         -mov dword ptr [ecx + 0x2c], 0x7fffffff
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(44) /* 0x2c */) = 2147483647 /*0x7fffffff*/;
    // 005113ab  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 005113ae  c7412800007f00         -mov dword ptr [ecx + 0x28], 0x7f0000
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */) = 8323072 /*0x7f0000*/;
    // 005113b5  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 005113b8  894120                 -mov dword ptr [ecx + 0x20], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 005113bb  8a4507                 -mov al, byte ptr [ebp + 7]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(7) /* 0x7 */);
    // 005113be  884130                 -mov byte ptr [ecx + 0x30], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(48) /* 0x30 */) = cpu.al;
    // 005113c1  8a4508                 -mov al, byte ptr [ebp + 8]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 005113c4  884132                 -mov byte ptr [ecx + 0x32], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(50) /* 0x32 */) = cpu.al;
    // 005113c7  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 005113cb  8a4009                 -mov al, byte ptr [eax + 9]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(9) /* 0x9 */);
    // 005113ce  c6413401               -mov byte ptr [ecx + 0x34], 1
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(52) /* 0x34 */) = 1 /*0x1*/;
    // 005113d2  c6413500               -mov byte ptr [ecx + 0x35], 0
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(53) /* 0x35 */) = 0 /*0x0*/;
    // 005113d6  c6413600               -mov byte ptr [ecx + 0x36], 0
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(54) /* 0x36 */) = 0 /*0x0*/;
    // 005113da  c6413701               -mov byte ptr [ecx + 0x37], 1
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(55) /* 0x37 */) = 1 /*0x1*/;
    // 005113de  884133                 -mov byte ptr [ecx + 0x33], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(51) /* 0x33 */) = cpu.al;
    // 005113e1  8a4509                 -mov al, byte ptr [ebp + 9]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(9) /* 0x9 */);
    // 005113e4  884138                 -mov byte ptr [ecx + 0x38], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(56) /* 0x38 */) = cpu.al;
    // 005113e7  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 005113eb  8a400a                 -mov al, byte ptr [eax + 0xa]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(10) /* 0xa */);
    // 005113ee  884139                 -mov byte ptr [ecx + 0x39], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(57) /* 0x39 */) = cpu.al;
    // 005113f1  660fbe450a             -movsx ax, byte ptr [ebp + 0xa]
    cpu.ax = x86::reg16(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(10) /* 0xa */)));
    // 005113f6  6bc064                 -imul eax, eax, 0x64
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(100 /*0x64*/)));
    // 005113f9  c6413b00               -mov byte ptr [ecx + 0x3b], 0
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(59) /* 0x3b */) = 0 /*0x0*/;
    // 005113fd  66894142               -mov word ptr [ecx + 0x42], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(66) /* 0x42 */) = cpu.ax;
    // 00511401  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00511405  c6413a00               -mov byte ptr [ecx + 0x3a], 0
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(58) /* 0x3a */) = 0 /*0x0*/;
    // 00511409  8a4007                 -mov al, byte ptr [eax + 7]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(7) /* 0x7 */);
    // 0051140c  c7414800000000         -mov dword ptr [ecx + 0x48], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(72) /* 0x48 */) = 0 /*0x0*/;
    // 00511413  c7414c00000000         -mov dword ptr [ecx + 0x4c], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(76) /* 0x4c */) = 0 /*0x0*/;
    // 0051141a  c7415000000000         -mov dword ptr [ecx + 0x50], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(80) /* 0x50 */) = 0 /*0x0*/;
    // 00511421  c7415400000000         -mov dword ptr [ecx + 0x54], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(84) /* 0x54 */) = 0 /*0x0*/;
    // 00511428  c7415800000000         -mov dword ptr [ecx + 0x58], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(88) /* 0x58 */) = 0 /*0x0*/;
    // 0051142f  884145                 -mov byte ptr [ecx + 0x45], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(69) /* 0x45 */) = cpu.al;
    // 00511432  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00511434  c7415c00000000         -mov dword ptr [ecx + 0x5c], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(92) /* 0x5c */) = 0 /*0x0*/;
    // 0051143b  e87018ffff             -call 0x502cb0
    cpu.esp -= 4;
    sub_502cb0(app, cpu);
    if (cpu.terminate) return;
    // 00511440  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00511442  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00511446  e85500ffff             -call 0x5014a0
    cpu.esp -= 4;
    sub_5014a0(app, cpu);
    if (cpu.terminate) return;
    // 0051144b  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0051144e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0051144f  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 00511452  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00511453  8b4135                 -mov eax, dword ptr [ecx + 0x35]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(53) /* 0x35 */);
    // 00511456  8b1d60a2a000           -mov ebx, dword ptr [0xa0a260]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10527328) /* 0xa0a260 */);
    // 0051145c  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 0051145f  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 00511462  8b5136                 -mov edx, dword ptr [ecx + 0x36]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(54) /* 0x36 */);
    // 00511465  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 00511468  0fafd0                 -imul edx, eax
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 0051146b  bb013f0000             -mov ebx, 0x3f01
    cpu.ebx = 16129 /*0x3f01*/;
    // 00511470  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00511472  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00511475  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00511477  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00511478  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0051147b  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0051147e  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00511480  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00511481  8b412e                 -mov eax, dword ptr [ecx + 0x2e]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(46) /* 0x2e */);
    // 00511484  8b590c                 -mov ebx, dword ptr [ecx + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00511487  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 0051148a  c1fb18                 -sar ebx, 0x18
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (24 /*0x18*/ % 32));
    // 0051148d  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0051148f  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00511493  e8fc280100             -call 0x523d94
    cpu.esp -= 4;
    sub_523d94(app, cpu);
    if (cpu.terminate) return;
    // 00511498  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0051149a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051149c  7c1f                   -jl 0x5114bd
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x005114bd;
    }
    // 0051149e  e8d9f9feff             -call 0x500e7c
    cpu.esp -= 4;
    sub_500e7c(app, cpu);
    if (cpu.terminate) return;
    // 005114a3  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 005114a5  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 005114a8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005114a9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005114aa  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005114ab  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005114ac:
    // 005114ac  e8cbf9feff             -call 0x500e7c
    cpu.esp -= 4;
    sub_500e7c(app, cpu);
    if (cpu.terminate) return;
    // 005114b1  b8f7ffffff             -mov eax, 0xfffffff7
    cpu.eax = 4294967287 /*0xfffffff7*/;
    // 005114b6  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 005114b9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005114ba  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005114bb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005114bc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005114bd:
    // 005114bd  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 005114bf  e8a0e6feff             -call 0x4ffb64
    cpu.esp -= 4;
    sub_4ffb64(app, cpu);
    if (cpu.terminate) return;
    // 005114c4  e8b3f9feff             -call 0x500e7c
    cpu.esp -= 4;
    sub_500e7c(app, cpu);
    if (cpu.terminate) return;
    // 005114c9  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 005114cb  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 005114ce  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005114cf  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005114d0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005114d1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_5114d4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005114d4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 005114d5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005114d6  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005114d7  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 005114d9  803df49aa00000         +cmp byte ptr [0xa09af4], 0
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
    // 005114e0  0f8484000000           -je 0x51156a
    if (cpu.flags.zf)
    {
        goto L_0x0051156a;
    }
    // 005114e6  8b148544b0a000         -mov edx, dword ptr [eax*4 + 0xa0b044]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10530884) /* 0xa0b044 */ + cpu.eax * 4);
    // 005114ed  833a00                 +cmp dword ptr [edx], 0
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
    // 005114f0  0f8c7d000000           -jl 0x511573
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00511573;
    }
L_0x005114f6:
    // 005114f6  e825f9feff             -call 0x500e20
    cpu.esp -= 4;
    sub_500e20(app, cpu);
    if (cpu.terminate) return;
    // 005114fb  0fbf4208               -movsx eax, word ptr [edx + 8]
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 005114ff  0fbf5a0e               -movsx ebx, word ptr [edx + 0xe]
    cpu.ebx = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.edx + x86::reg32(14) /* 0xe */)));
    // 00511503  48                     -dec eax
    (cpu.eax)--;
    // 00511504  39c3                   +cmp ebx, eax
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
    // 00511506  0f8d9e000000           -jge 0x5115aa
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x005115aa;
    }
    // 0051150c  0fbf420a               -movsx eax, word ptr [edx + 0xa]
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.edx + x86::reg32(10) /* 0xa */)));
    // 00511510  0fbf5a0e               -movsx ebx, word ptr [edx + 0xe]
    cpu.ebx = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.edx + x86::reg32(14) /* 0xe */)));
    // 00511514  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00511516  0fbf5a08               -movsx ebx, word ptr [edx + 8]
    cpu.ebx = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 0051151a  39d8                   +cmp eax, ebx
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
    // 0051151c  7c06                   -jl 0x511524
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00511524;
    }
    // 0051151e  0fbf5a08               -movsx ebx, word ptr [edx + 8]
    cpu.ebx = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00511522  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
L_0x00511524:
    // 00511524  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00511526  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00511529  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0051152b  8d1c8500000000         -lea ebx, [eax*4]
    cpu.ebx = x86::reg32(cpu.eax * 4);
    // 00511532  8d4228                 -lea eax, [edx + 0x28]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(40) /* 0x28 */);
    // 00511535  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00511537  8b5904                 -mov ebx, dword ptr [ecx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0051153a  895804                 -mov dword ptr [eax + 4], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 0051153d  8b590c                 -mov ebx, dword ptr [ecx + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00511540  895808                 -mov dword ptr [eax + 8], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 00511543  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00511546  8918                   -mov dword ptr [eax], ebx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ebx;
    // 00511548  668b420e               -mov ax, word ptr [edx + 0xe]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edx + x86::reg32(14) /* 0xe */);
    // 0051154c  66ff420e               -inc word ptr [edx + 0xe]
    (app->getMemory<x86::reg16>(cpu.edx + x86::reg32(14) /* 0xe */))++;
    // 00511550  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00511553  014210                 -add dword ptr [edx + 0x10], eax
    (app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */)) += x86::reg32(x86::sreg32(cpu.eax));
    // 00511556  8b4a04                 -mov ecx, dword ptr [edx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00511559  8b4204                 -mov eax, dword ptr [edx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0051155c  ff4204                 -inc dword ptr [edx + 4]
    (app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */))++;
    // 0051155f  e818f9feff             -call 0x500e7c
    cpu.esp -= 4;
    sub_500e7c(app, cpu);
    if (cpu.terminate) return;
    // 00511564  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00511566  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00511567  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00511568  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00511569  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0051156a:
    // 0051156a  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 0051156f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00511570  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00511571  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00511572  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00511573:
    // 00511573  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00511574  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00511575  bec0fd5400             -mov esi, 0x54fdc0
    cpu.esi = 5569984 /*0x54fdc0*/;
    // 0051157a  bfd0fd5400             -mov edi, 0x54fdd0
    cpu.edi = 5570000 /*0x54fdd0*/;
    // 0051157f  bdc1000000             -mov ebp, 0xc1
    cpu.ebp = 193 /*0xc1*/;
    // 00511584  68e4fd5400             -push 0x54fde4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5570020 /*0x54fde4*/;
    cpu.esp -= 4;
    // 00511589  893590215500           -mov dword ptr [0x552190], esi
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.esi;
    // 0051158f  893d94215500           -mov dword ptr [0x552194], edi
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.edi;
    // 00511595  892d98215500           -mov dword ptr [0x552198], ebp
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ebp;
    // 0051159b  e870faeeff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 005115a0  83c404                 +add esp, 4
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
    // 005115a3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005115a4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005115a5  e94cffffff             -jmp 0x5114f6
    goto L_0x005114f6;
L_0x005115aa:
    // 005115aa  e8cdf8feff             -call 0x500e7c
    cpu.esp -= 4;
    sub_500e7c(app, cpu);
    if (cpu.terminate) return;
    // 005115af  b8f3ffffff             -mov eax, 0xfffffff3
    cpu.eax = 4294967283 /*0xfffffff3*/;
    // 005115b4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005115b5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005115b6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005115b7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_5115b8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005115b8  803df49aa00000         +cmp byte ptr [0xa09af4], 0
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
    // 005115bf  741e                   -je 0x5115df
    if (cpu.flags.zf)
    {
        goto L_0x005115df;
    }
    // 005115c1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 005115c2  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005115c3  8b148544b0a000         -mov edx, dword ptr [eax*4 + 0xa0b044]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10530884) /* 0xa0b044 */ + cpu.eax * 4);
    // 005115ca  833a00                 +cmp dword ptr [edx], 0
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
    // 005115cd  7c16                   -jl 0x5115e5
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x005115e5;
    }
    // 005115cf  0fbf4a08               -movsx ecx, word ptr [edx + 8]
    cpu.ecx = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 005115d3  0fbf420e               -movsx eax, word ptr [edx + 0xe]
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.edx + x86::reg32(14) /* 0xe */)));
    // 005115d7  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 005115d9  8d41ff                 -lea eax, [ecx - 1]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(-1) /* -0x1 */);
    // 005115dc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005115dd  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005115de  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005115df:
    // 005115df  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 005115e4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005115e5:
    // 005115e5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 005115e6  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005115e7  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 005115e8  bbc0fd5400             -mov ebx, 0x54fdc0
    cpu.ebx = 5569984 /*0x54fdc0*/;
    // 005115ed  be20fe5400             -mov esi, 0x54fe20
    cpu.esi = 5570080 /*0x54fe20*/;
    // 005115f2  bff3000000             -mov edi, 0xf3
    cpu.edi = 243 /*0xf3*/;
    // 005115f7  6838fe5400             -push 0x54fe38
    app->getMemory<x86::reg32>(cpu.esp-4) = 5570104 /*0x54fe38*/;
    cpu.esp -= 4;
    // 005115fc  891d90215500           -mov dword ptr [0x552190], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ebx;
    // 00511602  893594215500           -mov dword ptr [0x552194], esi
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.esi;
    // 00511608  893d98215500           -mov dword ptr [0x552198], edi
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.edi;
    // 0051160e  e8fdf9eeff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 00511613  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00511616  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00511617  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00511618  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00511619  0fbf4a08               -movsx ecx, word ptr [edx + 8]
    cpu.ecx = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 0051161d  0fbf420e               -movsx eax, word ptr [edx + 0xe]
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.edx + x86::reg32(14) /* 0xe */)));
    // 00511621  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00511623  8d41ff                 -lea eax, [ecx - 1]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(-1) /* -0x1 */);
    // 00511626  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00511627  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00511628  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_51162c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051162c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0051162d  8b148544b0a000         -mov edx, dword ptr [eax*4 + 0xa0b044]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10530884) /* 0xa0b044 */ + cpu.eax * 4);
    // 00511634  833a00                 +cmp dword ptr [edx], 0
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
    // 00511637  7c08                   -jl 0x511641
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00511641;
    }
    // 00511639  8b4210                 -mov eax, dword ptr [edx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 0051163c  034214                 -add eax, dword ptr [edx + 0x14]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */)));
    // 0051163f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00511640  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00511641:
    // 00511641  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00511642  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00511643  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00511644  bbc0fd5400             -mov ebx, 0x54fdc0
    cpu.ebx = 5569984 /*0x54fdc0*/;
    // 00511649  be78fe5400             -mov esi, 0x54fe78
    cpu.esi = 5570168 /*0x54fe78*/;
    // 0051164e  bf04010000             -mov edi, 0x104
    cpu.edi = 260 /*0x104*/;
    // 00511653  689cfe5400             -push 0x54fe9c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5570204 /*0x54fe9c*/;
    cpu.esp -= 4;
    // 00511658  891d90215500           -mov dword ptr [0x552190], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ebx;
    // 0051165e  893594215500           -mov dword ptr [0x552194], esi
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.esi;
    // 00511664  893d98215500           -mov dword ptr [0x552198], edi
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.edi;
    // 0051166a  e8a1f9eeff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 0051166f  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00511672  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00511673  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00511674  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00511675  8b4210                 -mov eax, dword ptr [edx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00511678  034214                 -add eax, dword ptr [edx + 0x14]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */)));
    // 0051167b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051167c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_511680(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00511680  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00511681  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00511683  803df49aa00000         +cmp byte ptr [0xa09af4], 0
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
    // 0051168a  7507                   -jne 0x511693
    if (!cpu.flags.zf)
    {
        goto L_0x00511693;
    }
    // 0051168c  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 00511691  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00511692  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00511693:
    // 00511693  e888f7feff             -call 0x500e20
    cpu.esp -= 4;
    sub_500e20(app, cpu);
    if (cpu.terminate) return;
    // 00511698  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0051169a  e88dffffff             -call 0x51162c
    cpu.esp -= 4;
    sub_51162c(app, cpu);
    if (cpu.terminate) return;
    // 0051169f  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 005116a1  e8d6f7feff             -call 0x500e7c
    cpu.esp -= 4;
    sub_500e7c(app, cpu);
    if (cpu.terminate) return;
    // 005116a6  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 005116a8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005116a9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_5116ac(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005116ac  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 005116ad  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 005116af  803df49aa00000         +cmp byte ptr [0xa09af4], 0
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
    // 005116b6  7418                   -je 0x5116d0
    if (cpu.flags.zf)
    {
        goto L_0x005116d0;
    }
    // 005116b8  8b049544b0a000         -mov eax, dword ptr [edx*4 + 0xa0b044]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10530884) /* 0xa0b044 */ + cpu.edx * 4);
    // 005116bf  833800                 +cmp dword ptr [eax], 0
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
    // 005116c2  7c13                   -jl 0x5116d7
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x005116d7;
    }
    // 005116c4  8b049544b0a000         -mov eax, dword ptr [edx*4 + 0xa0b044]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10530884) /* 0xa0b044 */ + cpu.edx * 4);
    // 005116cb  8b4014                 -mov eax, dword ptr [eax + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 005116ce  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005116cf  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005116d0:
    // 005116d0  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 005116d5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005116d6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005116d7:
    // 005116d7  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 005116d8  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005116d9  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 005116da  bbc0fd5400             -mov ebx, 0x54fdc0
    cpu.ebx = 5569984 /*0x54fdc0*/;
    // 005116df  bee4fe5400             -mov esi, 0x54fee4
    cpu.esi = 5570276 /*0x54fee4*/;
    // 005116e4  bf23010000             -mov edi, 0x123
    cpu.edi = 291 /*0x123*/;
    // 005116e9  680cff5400             -push 0x54ff0c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5570316 /*0x54ff0c*/;
    cpu.esp -= 4;
    // 005116ee  891d90215500           -mov dword ptr [0x552190], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ebx;
    // 005116f4  893594215500           -mov dword ptr [0x552194], esi
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.esi;
    // 005116fa  893d98215500           -mov dword ptr [0x552198], edi
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.edi;
    // 00511700  e80bf9eeff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 00511705  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00511708  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00511709  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051170a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051170b  8b049544b0a000         -mov eax, dword ptr [edx*4 + 0xa0b044]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10530884) /* 0xa0b044 */ + cpu.edx * 4);
    // 00511712  8b4014                 -mov eax, dword ptr [eax + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 00511715  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00511716  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_511718(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00511718  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00511719  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0051171a  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0051171d  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 00511720  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 00511724  803df49aa00000         +cmp byte ptr [0xa09af4], 0
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
    // 0051172b  0f8492000000           -je 0x5117c3
    if (cpu.flags.zf)
    {
        goto L_0x005117c3;
    }
    // 00511731  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00511732  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00511733  8b148544b0a000         -mov edx, dword ptr [eax*4 + 0xa0b044]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10530884) /* 0xa0b044 */ + cpu.eax * 4);
    // 0051173a  833a00                 +cmp dword ptr [edx], 0
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
    // 0051173d  0f8c8d000000           -jl 0x5117d0
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x005117d0;
    }
L_0x00511743:
    // 00511743  e8d8f6feff             -call 0x500e20
    cpu.esp -= 4;
    sub_500e20(app, cpu);
    if (cpu.terminate) return;
    // 00511748  0fbf5a0a               -movsx ebx, word ptr [edx + 0xa]
    cpu.ebx = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.edx + x86::reg32(10) /* 0xa */)));
    // 0051174c  0fbf4a0a               -movsx ecx, word ptr [edx + 0xa]
    cpu.ecx = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.edx + x86::reg32(10) /* 0xa */)));
    // 00511750  0fbf420e               -movsx eax, word ptr [edx + 0xe]
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.edx + x86::reg32(14) /* 0xe */)));
    // 00511754  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 00511758  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 0051175a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051175c  7e54                   -jle 0x5117b2
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x005117b2;
    }
    // 0051175e  8d4228                 -lea eax, [edx + 0x28]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(40) /* 0x28 */);
    // 00511761  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
L_0x00511765:
    // 00511765  6bf10c                 -imul esi, ecx, 0xc
    cpu.esi = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(12 /*0xc*/)));
    // 00511768  03742410               -add esi, dword ptr [esp + 0x10]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 0051176c  8b7c2408               -mov edi, dword ptr [esp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00511770  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00511772  39f8                   +cmp eax, edi
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
    // 00511774  0f8c89000000           -jl 0x511803
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00511803;
    }
    // 0051177a  3b44240c               +cmp eax, dword ptr [esp + 0xc]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051177e  0f8f7f000000           -jg 0x511803
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00511803;
    }
    // 00511784  668b420e               -mov ax, word ptr [edx + 0xe]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edx + x86::reg32(14) /* 0xe */);
    // 00511788  66ff4a0e               -dec word ptr [edx + 0xe]
    (app->getMemory<x86::reg16>(cpu.edx + x86::reg32(14) /* 0xe */))--;
    // 0051178c  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0051178f  294210                 -sub dword ptr [edx + 0x10], eax
    (app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */)) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00511792  837a1c00               +cmp dword ptr [edx + 0x1c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00511796  7406                   -je 0x51179e
    if (cpu.flags.zf)
    {
        goto L_0x0051179e;
    }
    // 00511798  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0051179b  ff521c                 -call dword ptr [edx + 0x1c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0051179e:
    // 0051179e  41                     -inc ecx
    (cpu.ecx)++;
    // 0051179f  0fbf4208               -movsx eax, word ptr [edx + 8]
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 005117a3  39c1                   +cmp ecx, eax
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
    // 005117a5  7c02                   -jl 0x5117a9
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x005117a9;
    }
    // 005117a7  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x005117a9:
    // 005117a9  8b742414               -mov esi, dword ptr [esp + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 005117ad  45                     -inc ebp
    (cpu.ebp)++;
    // 005117ae  39f5                   +cmp ebp, esi
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005117b0  7cb3                   -jl 0x511765
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00511765;
    }
L_0x005117b2:
    // 005117b2  e8c5f6feff             -call 0x500e7c
    cpu.esp -= 4;
    sub_500e7c(app, cpu);
    if (cpu.terminate) return;
    // 005117b7  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 005117b9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005117ba  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005117bb  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 005117bd  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 005117c0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005117c1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005117c2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005117c3:
    // 005117c3  b9f6ffffff             -mov ecx, 0xfffffff6
    cpu.ecx = 4294967286 /*0xfffffff6*/;
    // 005117c8  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 005117ca  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 005117cd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005117ce  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005117cf  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005117d0:
    // 005117d0  bbc0fd5400             -mov ebx, 0x54fdc0
    cpu.ebx = 5569984 /*0x54fdc0*/;
    // 005117d5  be5cff5400             -mov esi, 0x54ff5c
    cpu.esi = 5570396 /*0x54ff5c*/;
    // 005117da  bf3d010000             -mov edi, 0x13d
    cpu.edi = 317 /*0x13d*/;
    // 005117df  6870ff5400             -push 0x54ff70
    app->getMemory<x86::reg32>(cpu.esp-4) = 5570416 /*0x54ff70*/;
    cpu.esp -= 4;
    // 005117e4  891d90215500           -mov dword ptr [0x552190], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ebx;
    // 005117ea  893594215500           -mov dword ptr [0x552194], esi
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.esi;
    // 005117f0  893d98215500           -mov dword ptr [0x552198], edi
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.edi;
    // 005117f6  e815f8eeff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 005117fb  83c404                 +add esp, 4
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
    // 005117fe  e940ffffff             -jmp 0x511743
    goto L_0x00511743;
L_0x00511803:
    // 00511803  6bfb0c                 -imul edi, ebx, 0xc
    cpu.edi = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(12 /*0xc*/)));
    // 00511806  8d7c3a28               -lea edi, [edx + edi + 0x28]
    cpu.edi = x86::reg32(cpu.edx + x86::reg32(40) /* 0x28 */ + cpu.edi * 1);
    // 0051180a  43                     -inc ebx
    (cpu.ebx)++;
    // 0051180b  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0051180c  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0051180d  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0051180e  0fbf4208               -movsx eax, word ptr [edx + 8]
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00511812  39c3                   +cmp ebx, eax
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
    // 00511814  7c88                   -jl 0x51179e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0051179e;
    }
    // 00511816  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 00511818  eb84                   -jmp 0x51179e
    goto L_0x0051179e;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_51181c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0051181c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0051181d  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0051181e  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00511820  803df49aa00000         +cmp byte ptr [0xa09af4], 0
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
    // 00511827  7467                   -je 0x511890
    if (cpu.flags.zf)
    {
        goto L_0x00511890;
    }
    // 00511829  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0051182a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0051182b  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0051182c  8b0cb544b0a000         -mov ecx, dword ptr [esi*4 + 0xa0b044]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10530884) /* 0xa0b044 */ + cpu.esi * 4);
    // 00511833  833900                 +cmp dword ptr [ecx], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00511836  7c60                   -jl 0x511898
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00511898;
    }
L_0x00511838:
    // 00511838  e8e3f5feff             -call 0x500e20
    cpu.esp -= 4;
    sub_500e20(app, cpu);
    if (cpu.terminate) return;
    // 0051183d  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 0051183f  e82c7efdff             -call 0x4e9670
    cpu.esp -= 4;
    sub_4e9670(app, cpu);
    if (cpu.terminate) return;
    // 00511844  bbffffff7f             -mov ebx, 0x7fffffff
    cpu.ebx = 2147483647 /*0x7fffffff*/;
    // 00511849  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0051184b  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0051184d  e8c6feffff             -call 0x511718
    cpu.esp -= 4;
    sub_511718(app, cpu);
    if (cpu.terminate) return;
    // 00511852  83791c00               +cmp dword ptr [ecx + 0x1c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00511856  7425                   -je 0x51187d
    if (cpu.flags.zf)
    {
        goto L_0x0051187d;
    }
    // 00511858  6683790c00             +cmp word ptr [ecx + 0xc], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(12) /* 0xc */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0051185d  7c1e                   -jl 0x51187d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0051187d;
    }
    // 0051185f  0fbf710c               -movsx esi, word ptr [ecx + 0xc]
    cpu.esi = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(12) /* 0xc */)));
    // 00511863  8d04b500000000         -lea eax, [esi*4]
    cpu.eax = x86::reg32(cpu.esi * 4);
    // 0051186a  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0051186c  8d348500000000         -lea esi, [eax*4]
    cpu.esi = x86::reg32(cpu.eax * 4);
    // 00511873  8d4128                 -lea eax, [ecx + 0x28]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(40) /* 0x28 */);
    // 00511876  8b440608               -mov eax, dword ptr [esi + eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */ + cpu.eax * 1);
    // 0051187a  ff511c                 -call dword ptr [ecx + 0x1c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0051187d:
    // 0051187d  c701ffffffff           -mov dword ptr [ecx], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ecx) = 4294967295 /*0xffffffff*/;
    // 00511883  e8f4f5feff             -call 0x500e7c
    cpu.esp -= 4;
    sub_500e7c(app, cpu);
    if (cpu.terminate) return;
    // 00511888  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0051188a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051188b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051188c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051188d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051188e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051188f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00511890:
    // 00511890  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 00511895  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00511896  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00511897  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00511898:
    // 00511898  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00511899  bbc0fd5400             -mov ebx, 0x54fdc0
    cpu.ebx = 5569984 /*0x54fdc0*/;
    // 0051189e  bfacff5400             -mov edi, 0x54ffac
    cpu.edi = 5570476 /*0x54ffac*/;
    // 005118a3  bd78010000             -mov ebp, 0x178
    cpu.ebp = 376 /*0x178*/;
    // 005118a8  68bcff5400             -push 0x54ffbc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5570492 /*0x54ffbc*/;
    cpu.esp -= 4;
    // 005118ad  891d90215500           -mov dword ptr [0x552190], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ebx;
    // 005118b3  893d94215500           -mov dword ptr [0x552194], edi
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.edi;
    // 005118b9  892d98215500           -mov dword ptr [0x552198], ebp
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ebp;
    // 005118bf  e84cf7eeff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 005118c4  83c404                 +add esp, 4
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
    // 005118c7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005118c8  e96bffffff             -jmp 0x511838
    goto L_0x00511838;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_5118d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005118d0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 005118d1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 005118d3  803df49aa00000         +cmp byte ptr [0xa09af4], 0
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
    // 005118da  7507                   -jne 0x5118e3
    if (!cpu.flags.zf)
    {
        goto L_0x005118e3;
    }
    // 005118dc  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 005118e1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005118e2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005118e3:
    // 005118e3  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005118e4  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 005118e6  e8a5240100             -call 0x523d90
    cpu.esp -= 4;
    sub_523d90(app, cpu);
    if (cpu.terminate) return;
    // 005118eb  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 005118ed  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 005118ef  890c9544b0a000         -mov dword ptr [edx*4 + 0xa0b044], ecx
    app->getMemory<x86::reg32>(x86::reg32(10530884) /* 0xa0b044 */ + cpu.edx * 4) = cpu.ecx;
    // 005118f6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005118f7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005118f8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_5118fc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005118fc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 005118fd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005118fe  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00511900  8b148544b0a000         -mov edx, dword ptr [eax*4 + 0xa0b044]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10530884) /* 0xa0b044 */ + cpu.eax * 4);
    // 00511907  66837a0c00             +cmp word ptr [edx + 0xc], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.edx + x86::reg32(12) /* 0xc */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0051190c  7c21                   -jl 0x51192f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0051192f;
    }
    // 0051190e  0fbf5a0c               -movsx ebx, word ptr [edx + 0xc]
    cpu.ebx = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00511912  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 00511919  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0051191b  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0051191e  8d5a28                 -lea ebx, [edx + 0x28]
    cpu.ebx = x86::reg32(cpu.edx + x86::reg32(40) /* 0x28 */);
    // 00511921  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00511923  66c7420cffff           -mov word ptr [edx + 0xc], 0xffff
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(12) /* 0xc */) = 65535 /*0xffff*/;
    // 00511929  837a1c00               +cmp dword ptr [edx + 0x1c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051192d  755a                   -jne 0x511989
    if (!cpu.flags.zf)
    {
        goto L_0x00511989;
    }
L_0x0051192f:
    // 0051192f  66837a0e00             +cmp word ptr [edx + 0xe], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.edx + x86::reg32(14) /* 0xe */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00511934  745b                   -je 0x511991
    if (cpu.flags.zf)
    {
        goto L_0x00511991;
    }
    // 00511936  668b420a               -mov ax, word ptr [edx + 0xa]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edx + x86::reg32(10) /* 0xa */);
    // 0051193a  6689420c               -mov word ptr [edx + 0xc], ax
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(12) /* 0xc */) = cpu.ax;
    // 0051193e  0fbf5a0a               -movsx ebx, word ptr [edx + 0xa]
    cpu.ebx = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.edx + x86::reg32(10) /* 0xa */)));
    // 00511942  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 00511949  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0051194b  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0051194e  8d5a28                 -lea ebx, [edx + 0x28]
    cpu.ebx = x86::reg32(cpu.edx + x86::reg32(40) /* 0x28 */);
    // 00511951  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00511953  8b5804                 -mov ebx, dword ptr [eax + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00511956  8919                   -mov dword ptr [ecx], ebx
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.ebx;
    // 00511958  668b5a0e               -mov bx, word ptr [edx + 0xe]
    cpu.bx = app->getMemory<x86::reg16>(cpu.edx + x86::reg32(14) /* 0xe */);
    // 0051195c  66ff4a0e               -dec word ptr [edx + 0xe]
    (app->getMemory<x86::reg16>(cpu.edx + x86::reg32(14) /* 0xe */))--;
    // 00511960  668b5a0a               -mov bx, word ptr [edx + 0xa]
    cpu.bx = app->getMemory<x86::reg16>(cpu.edx + x86::reg32(10) /* 0xa */);
    // 00511964  66ff420a               -inc word ptr [edx + 0xa]
    (app->getMemory<x86::reg16>(cpu.edx + x86::reg32(10) /* 0xa */))++;
    // 00511968  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0051196b  014a14                 -add dword ptr [edx + 0x14], ecx
    (app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */)) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0051196e  294a10                 -sub dword ptr [edx + 0x10], ecx
    (app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */)) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00511971  0fbf4a0a               -movsx ecx, word ptr [edx + 0xa]
    cpu.ecx = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.edx + x86::reg32(10) /* 0xa */)));
    // 00511975  0fbf5a08               -movsx ebx, word ptr [edx + 8]
    cpu.ebx = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 00511979  39d9                   +cmp ecx, ebx
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
    // 0051197b  7c06                   -jl 0x511983
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00511983;
    }
    // 0051197d  66c7420a0000           -mov word ptr [edx + 0xa], 0
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(10) /* 0xa */) = 0 /*0x0*/;
L_0x00511983:
    // 00511983  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00511986  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00511987  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00511988  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00511989:
    // 00511989  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0051198c  ff521c                 -call dword ptr [edx + 0x1c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051198f  eb9e                   -jmp 0x51192f
    goto L_0x0051192f;
L_0x00511991:
    // 00511991  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00511993  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00511994  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00511995  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_511998(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00511998  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00511999  8b0c8544b0a000         -mov ecx, dword ptr [eax*4 + 0xa0b044]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10530884) /* 0xa0b044 */ + cpu.eax * 4);
    // 005119a0  295114                 -sub dword ptr [ecx + 0x14], edx
    (app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */)) -= x86::reg32(x86::sreg32(cpu.edx));
    // 005119a3  83792000               +cmp dword ptr [ecx + 0x20], 0
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
    // 005119a7  7502                   -jne 0x5119ab
    if (!cpu.flags.zf)
    {
        goto L_0x005119ab;
    }
    // 005119a9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005119aa  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005119ab:
    // 005119ab  ff5120                 -call dword ptr [ecx + 0x20]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005119ae  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005119af  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_5119b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005119b0  c700ffffffff           -mov dword ptr [eax], 0xffffffff
    app->getMemory<x86::reg32>(cpu.eax) = 4294967295 /*0xffffffff*/;
    // 005119b6  c6400600               -mov byte ptr [eax + 6], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(6) /* 0x6 */) = 0 /*0x0*/;
    // 005119ba  66c740040000           -mov word ptr [eax + 4], 0
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 005119c0  c640077f               -mov byte ptr [eax + 7], 0x7f
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(7) /* 0x7 */) = 127 /*0x7f*/;
    // 005119c4  c6400840               -mov byte ptr [eax + 8], 0x40
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(8) /* 0x8 */) = 64 /*0x40*/;
    // 005119c8  c6400900               -mov byte ptr [eax + 9], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(9) /* 0x9 */) = 0 /*0x0*/;
    // 005119cc  c6400a00               -mov byte ptr [eax + 0xa], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(10) /* 0xa */) = 0 /*0x0*/;
    // 005119d0  c6400b00               -mov byte ptr [eax + 0xb], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(11) /* 0xb */) = 0 /*0x0*/;
    // 005119d4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 005119d6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_5119d8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005119d8  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005119d9  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 005119da  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005119db  83ec1c                 -sub esp, 0x1c
    (cpu.esp) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 005119de  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 005119e2  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 005119e4  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 005119e6  894c2414               -mov dword ptr [esp + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 005119ea  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 005119ec  e8bfffffff             -call 0x5119b0
    cpu.esp -= 4;
    sub_5119b0(app, cpu);
    if (cpu.terminate) return;
    // 005119f1  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 005119f5  ba10000000             -mov edx, 0x10
    cpu.edx = 16 /*0x10*/;
    // 005119fa  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 005119fd  89542418               -mov dword ptr [esp + 0x18], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 00511a01  8a5003                 -mov dl, byte ptr [eax + 3]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(3) /* 0x3 */);
    // 00511a04  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 00511a06  f6c202                 +test dl, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 2 /*0x2*/));
    // 00511a09  7557                   -jne 0x511a62
    if (!cpu.flags.zf)
    {
        goto L_0x00511a62;
    }
    // 00511a0b  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00511a0e:
    // 00511a0e  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00511a11  8a7602                 -mov dh, byte ptr [esi + 2]
    cpu.dh = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 00511a14  80e6fc                 -and dh, 0xfc
    cpu.dh &= x86::reg8(x86::sreg8(252 /*0xfc*/));
    // 00511a17  66c7062256             -mov word ptr [esi], 0x5622
    app->getMemory<x86::reg16>(cpu.esi) = 22050 /*0x5622*/;
    // 00511a1c  88f3                   -mov bl, dh
    cpu.bl = cpu.dh;
    // 00511a1e  887602                 -mov byte ptr [esi + 2], dh
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */) = cpu.dh;
    // 00511a21  80cb01                 -or bl, 1
    cpu.bl |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00511a24  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00511a28  885e02                 -mov byte ptr [esi + 2], bl
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */) = cpu.bl;
    // 00511a2b  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
L_0x00511a31:
    // 00511a31  8d4c240c               -lea ecx, [esp + 0xc]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00511a35  8d5c2408               -lea ebx, [esp + 8]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00511a39  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00511a3d  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00511a3f  e88c0f0100             -call 0x5229d0
    cpu.esp -= 4;
    sub_5229d0(app, cpu);
    if (cpu.terminate) return;
    // 00511a44  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00511a46  0f84cb000000           -je 0x511b17
    if (cpu.flags.zf)
    {
        goto L_0x00511b17;
    }
    // 00511a4c  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00511a50  81fb81000000           +cmp ebx, 0x81
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(129 /*0x81*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00511a56  750f                   -jne 0x511a67
    if (!cpu.flags.zf)
    {
        goto L_0x00511a67;
    }
    // 00511a58  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00511a5c  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 00511a60  ebcf                   -jmp 0x511a31
    goto L_0x00511a31;
L_0x00511a62:
    // 00511a62  83c008                 +add eax, 8
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00511a65  eba7                   -jmp 0x511a0e
    goto L_0x00511a0e;
L_0x00511a67:
    // 00511a67  81fb83000000           +cmp ebx, 0x83
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(131 /*0x83*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00511a6d  7506                   -jne 0x511a75
    if (!cpu.flags.zf)
    {
        goto L_0x00511a75;
    }
    // 00511a6f  8b6c2408               -mov ebp, dword ptr [esp + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00511a73  ebbc                   -jmp 0x511a31
    goto L_0x00511a31;
L_0x00511a75:
    // 00511a75  81fb91000000           +cmp ebx, 0x91
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(145 /*0x91*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00511a7b  7509                   -jne 0x511a86
    if (!cpu.flags.zf)
    {
        goto L_0x00511a86;
    }
    // 00511a7d  8a442408               -mov al, byte ptr [esp + 8]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00511a81  88470b                 -mov byte ptr [edi + 0xb], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(11) /* 0xb */) = cpu.al;
    // 00511a84  ebab                   -jmp 0x511a31
    goto L_0x00511a31;
L_0x00511a86:
    // 00511a86  81fb82000000           +cmp ebx, 0x82
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(130 /*0x82*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00511a8c  7517                   -jne 0x511aa5
    if (!cpu.flags.zf)
    {
        goto L_0x00511aa5;
    }
    // 00511a8e  8a5602                 -mov dl, byte ptr [esi + 2]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 00511a91  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00511a95  80e2fc                 -and dl, 0xfc
    cpu.dl &= x86::reg8(x86::sreg8(252 /*0xfc*/));
    // 00511a98  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 00511a9a  885602                 -mov byte ptr [esi + 2], dl
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */) = cpu.dl;
    // 00511a9d  2403                   -and al, 3
    cpu.al &= x86::reg8(x86::sreg8(3 /*0x3*/));
    // 00511a9f  66094602               +or word ptr [esi + 2], ax
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg16>(cpu.esi + x86::reg32(2) /* 0x2 */) |= x86::reg16(x86::sreg16(cpu.ax))));
    // 00511aa3  eb8c                   -jmp 0x511a31
    goto L_0x00511a31;
L_0x00511aa5:
    // 00511aa5  81fb84000000           +cmp ebx, 0x84
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(132 /*0x84*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00511aab  750c                   -jne 0x511ab9
    if (!cpu.flags.zf)
    {
        goto L_0x00511ab9;
    }
    // 00511aad  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00511ab1  668906                 -mov word ptr [esi], ax
    app->getMemory<x86::reg16>(cpu.esi) = cpu.ax;
    // 00511ab4  e978ffffff             -jmp 0x511a31
    goto L_0x00511a31;
L_0x00511ab9:
    // 00511ab9  81fb85000000           +cmp ebx, 0x85
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(133 /*0x85*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00511abf  750f                   -jne 0x511ad0
    if (!cpu.flags.zf)
    {
        goto L_0x00511ad0;
    }
    // 00511ac1  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00511ac5  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00511ac9  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 00511acb  e961ffffff             -jmp 0x511a31
    goto L_0x00511a31;
L_0x00511ad0:
    // 00511ad0  83fb13                 +cmp ebx, 0x13
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(19 /*0x13*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00511ad3  750c                   -jne 0x511ae1
    if (!cpu.flags.zf)
    {
        goto L_0x00511ae1;
    }
    // 00511ad5  8a442408               -mov al, byte ptr [esp + 8]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00511ad9  884709                 -mov byte ptr [edi + 9], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(9) /* 0x9 */) = cpu.al;
    // 00511adc  e950ffffff             -jmp 0x511a31
    goto L_0x00511a31;
L_0x00511ae1:
    // 00511ae1  83fb0a                 +cmp ebx, 0xa
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
    // 00511ae4  750c                   -jne 0x511af2
    if (!cpu.flags.zf)
    {
        goto L_0x00511af2;
    }
    // 00511ae6  8a442408               -mov al, byte ptr [esp + 8]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00511aea  88470a                 -mov byte ptr [edi + 0xa], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(10) /* 0xa */) = cpu.al;
    // 00511aed  e93fffffff             -jmp 0x511a31
    goto L_0x00511a31;
L_0x00511af2:
    // 00511af2  83fb05                 +cmp ebx, 5
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
    // 00511af5  750b                   -jne 0x511b02
    if (!cpu.flags.zf)
    {
        goto L_0x00511b02;
    }
    // 00511af7  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00511afb  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 00511afd  e92fffffff             -jmp 0x511a31
    goto L_0x00511a31;
L_0x00511b02:
    // 00511b02  83fb06                 +cmp ebx, 6
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
    // 00511b05  0f8526ffffff           -jne 0x511a31
    if (!cpu.flags.zf)
    {
        goto L_0x00511a31;
    }
    // 00511b0b  8a442408               -mov al, byte ptr [esp + 8]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00511b0f  884706                 -mov byte ptr [edi + 6], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(6) /* 0x6 */) = cpu.al;
    // 00511b12  e91affffff             -jmp 0x511a31
    goto L_0x00511a31;
L_0x00511b17:
    // 00511b17  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00511b19  7466                   -je 0x511b81
    if (cpu.flags.zf)
    {
        goto L_0x00511b81;
    }
    // 00511b1b  83fd05                 +cmp ebp, 5
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5 /*0x5*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00511b1e  741c                   -je 0x511b3c
    if (cpu.flags.zf)
    {
        goto L_0x00511b3c;
    }
    // 00511b20  83fd07                 +cmp ebp, 7
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(7 /*0x7*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00511b23  7422                   -je 0x511b47
    if (cpu.flags.zf)
    {
        goto L_0x00511b47;
    }
    // 00511b25  83fd09                 +cmp ebp, 9
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(9 /*0x9*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00511b28  7528                   -jne 0x511b52
    if (!cpu.flags.zf)
    {
        goto L_0x00511b52;
    }
    // 00511b2a  6683660203             -and word ptr [esi + 2], 3
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(2) /* 0x2 */) &= x86::reg16(x86::sreg16(3 /*0x3*/));
    // 00511b2f  804e0210               -or byte ptr [esi + 2], 0x10
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */) |= x86::reg8(x86::sreg8(16 /*0x10*/));
L_0x00511b33:
    // 00511b33  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00511b35  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00511b38  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00511b39  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00511b3a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00511b3b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00511b3c:
    // 00511b3c  6683660203             -and word ptr [esi + 2], 3
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(2) /* 0x2 */) &= x86::reg16(x86::sreg16(3 /*0x3*/));
    // 00511b41  804e0218               +or byte ptr [esi + 2], 0x18
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */) |= x86::reg8(x86::sreg8(24 /*0x18*/))));
    // 00511b45  ebec                   -jmp 0x511b33
    goto L_0x00511b33;
L_0x00511b47:
    // 00511b47  6683660203             -and word ptr [esi + 2], 3
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(2) /* 0x2 */) &= x86::reg16(x86::sreg16(3 /*0x3*/));
    // 00511b4c  804e020c               +or byte ptr [esi + 2], 0xc
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */) |= x86::reg8(x86::sreg8(12 /*0xc*/))));
    // 00511b50  ebe1                   -jmp 0x511b33
    goto L_0x00511b33;
L_0x00511b52:
    // 00511b52  b8f4ff5400             -mov eax, 0x54fff4
    cpu.eax = 5570548 /*0x54fff4*/;
    // 00511b57  ba04005500             -mov edx, 0x550004
    cpu.edx = 5570564 /*0x550004*/;
    // 00511b5c  b964000000             -mov ecx, 0x64
    cpu.ecx = 100 /*0x64*/;
    // 00511b61  6814005500             -push 0x550014
    app->getMemory<x86::reg32>(cpu.esp-4) = 5570580 /*0x550014*/;
    cpu.esp -= 4;
    // 00511b66  a390215500             -mov dword ptr [0x552190], eax
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.eax;
    // 00511b6b  891594215500           -mov dword ptr [0x552194], edx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.edx;
    // 00511b71  890d98215500           -mov dword ptr [0x552198], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ecx;
    // 00511b77  e894f4eeff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 00511b7c  83c404                 +add esp, 4
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
    // 00511b7f  ebb2                   -jmp 0x511b33
    goto L_0x00511b33;
L_0x00511b81:
    // 00511b81  8b4c2418               -mov ecx, dword ptr [esp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00511b85  83f910                 +cmp ecx, 0x10
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
    // 00511b88  7417                   -je 0x511ba1
    if (cpu.flags.zf)
    {
        goto L_0x00511ba1;
    }
    // 00511b8a  83f908                 +cmp ecx, 8
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00511b8d  7520                   -jne 0x511baf
    if (!cpu.flags.zf)
    {
        goto L_0x00511baf;
    }
    // 00511b8f  6683660203             -and word ptr [esi + 2], 3
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(2) /* 0x2 */) &= x86::reg16(x86::sreg16(3 /*0x3*/));
    // 00511b94  804e0208               -or byte ptr [esi + 2], 8
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */) |= x86::reg8(x86::sreg8(8 /*0x8*/));
    // 00511b98  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00511b9a  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00511b9d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00511b9e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00511b9f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00511ba0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00511ba1:
    // 00511ba1  6683660203             -and word ptr [esi + 2], 3
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(2) /* 0x2 */) &= x86::reg16(x86::sreg16(3 /*0x3*/));
    // 00511ba6  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00511ba8  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00511bab  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00511bac  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00511bad  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00511bae  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00511baf:
    // 00511baf  bef4ff5400             -mov esi, 0x54fff4
    cpu.esi = 5570548 /*0x54fff4*/;
    // 00511bb4  bf04005500             -mov edi, 0x550004
    cpu.edi = 5570564 /*0x550004*/;
    // 00511bb9  bd77000000             -mov ebp, 0x77
    cpu.ebp = 119 /*0x77*/;
    // 00511bbe  6840005500             -push 0x550040
    app->getMemory<x86::reg32>(cpu.esp-4) = 5570624 /*0x550040*/;
    cpu.esp -= 4;
    // 00511bc3  893590215500           -mov dword ptr [0x552190], esi
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.esi;
    // 00511bc9  893d94215500           -mov dword ptr [0x552194], edi
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.edi;
    // 00511bcf  892d98215500           -mov dword ptr [0x552198], ebp
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ebp;
    // 00511bd5  e836f4eeff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 00511bda  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00511bdd  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00511bdf  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00511be2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00511be3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00511be4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00511be5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_511bf0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00511bf0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00511bf1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00511bf2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00511bf3  668b5802               -mov bx, word ptr [eax + 2]
    cpu.bx = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 00511bf7  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00511bf9  30ff                   -xor bh, bh
    cpu.bh ^= x86::reg8(x86::sreg8(cpu.bh));
    // 00511bfb  668b08                 -mov cx, word ptr [eax]
    cpu.cx = app->getMemory<x86::reg16>(cpu.eax);
    // 00511bfe  80e303                 -and bl, 3
    cpu.bl &= x86::reg8(x86::sreg8(3 /*0x3*/));
    // 00511c01  81e3ffff0000           -and ebx, 0xffff
    cpu.ebx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00511c07  0fafcb                 -imul ecx, ebx
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 00511c0a  668b5802               -mov bx, word ptr [eax + 2]
    cpu.bx = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 00511c0e  80e3fc                 -and bl, 0xfc
    cpu.bl &= x86::reg8(x86::sreg8(252 /*0xfc*/));
    // 00511c11  6683fb0c               +cmp bx, 0xc
    {
        x86::reg16 tmp1 = cpu.bx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(12 /*0xc*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00511c15  7425                   -je 0x511c3c
    if (cpu.flags.zf)
    {
        goto L_0x00511c3c;
    }
    // 00511c17  6683fb10               +cmp bx, 0x10
    {
        x86::reg16 tmp1 = cpu.bx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(16 /*0x10*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00511c1b  7426                   -je 0x511c43
    if (cpu.flags.zf)
    {
        goto L_0x00511c43;
    }
    // 00511c1d  6683fb08               +cmp bx, 8
    {
        x86::reg16 tmp1 = cpu.bx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(8 /*0x8*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00511c21  7427                   -je 0x511c4a
    if (cpu.flags.zf)
    {
        goto L_0x00511c4a;
    }
    // 00511c23  66f74002fcff           +test word ptr [eax + 2], 0xfffc
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(app->getMemory<x86::reg16>(cpu.eax + x86::reg32(2) /* 0x2 */) & 65532 /*0xfffc*/));
    // 00511c29  7526                   -jne 0x511c51
    if (!cpu.flags.zf)
    {
        goto L_0x00511c51;
    }
    // 00511c2b  ba00020000             -mov edx, 0x200
    cpu.edx = 512 /*0x200*/;
L_0x00511c30:
    // 00511c30  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00511c32  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00511c35  c1f808                 +sar eax, 8
    {
        x86::reg8 tmp = 8 /*0x8*/ % 32;
        x86::reg32& op = cpu.eax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (x86::sreg32(op) >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = 0;
            cpu.set_szp((op = x86::reg32(x86::sreg32(op) >> tmp)));
        }
    }
    // 00511c38  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00511c39  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00511c3a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00511c3b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00511c3c:
    // 00511c3c  ba88000000             -mov edx, 0x88
    cpu.edx = 136 /*0x88*/;
    // 00511c41  ebed                   -jmp 0x511c30
    goto L_0x00511c30;
L_0x00511c43:
    // 00511c43  ba33000000             -mov edx, 0x33
    cpu.edx = 51 /*0x33*/;
    // 00511c48  ebe6                   -jmp 0x511c30
    goto L_0x00511c30;
L_0x00511c4a:
    // 00511c4a  ba00010000             -mov edx, 0x100
    cpu.edx = 256 /*0x100*/;
    // 00511c4f  ebdf                   -jmp 0x511c30
    goto L_0x00511c30;
L_0x00511c51:
    // 00511c51  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00511c52  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00511c53  bb6c005500             -mov ebx, 0x55006c
    cpu.ebx = 5570668 /*0x55006c*/;
    // 00511c58  be7c005500             -mov esi, 0x55007c
    cpu.esi = 5570684 /*0x55007c*/;
    // 00511c5d  bf1c000000             -mov edi, 0x1c
    cpu.edi = 28 /*0x1c*/;
    // 00511c62  668b4002               -mov ax, word ptr [eax + 2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 00511c66  891d90215500           -mov dword ptr [0x552190], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ebx;
    // 00511c6c  893594215500           -mov dword ptr [0x552194], esi
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.esi;
    // 00511c72  893d98215500           -mov dword ptr [0x552198], edi
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.edi;
    // 00511c78  66c1e802               -shr ax, 2
    cpu.ax >>= 2 /*0x2*/ % 32;
    // 00511c7c  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00511c81  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00511c82  6898005500             -push 0x550098
    app->getMemory<x86::reg32>(cpu.esp-4) = 5570712 /*0x550098*/;
    cpu.esp -= 4;
    // 00511c87  e884f3eeff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 00511c8c  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00511c8f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00511c90  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00511c91  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00511c93  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00511c96  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 00511c99  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00511c9a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00511c9b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00511c9c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_511ca0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00511ca0  803df49aa00000         +cmp byte ptr [0xa09af4], 0
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
    // 00511ca7  7506                   -jne 0x511caf
    if (!cpu.flags.zf)
    {
        goto L_0x00511caf;
    }
    // 00511ca9  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 00511cae  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00511caf:
    // 00511caf  e8f01dfeff             -call 0x4f3aa4
    cpu.esp -= 4;
    sub_4f3aa4(app, cpu);
    if (cpu.terminate) return;
    // 00511cb4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00511cb6  7506                   -jne 0x511cbe
    if (!cpu.flags.zf)
    {
        goto L_0x00511cbe;
    }
    // 00511cb8  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 00511cbd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00511cbe:
    // 00511cbe  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00511cc1  e80ae1fbff             -call 0x4cfdd0
    cpu.esp -= 4;
    sub_4cfdd0(app, cpu);
    if (cpu.terminate) return;
    // 00511cc6  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00511cc8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_511cd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00511cd0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00511cd1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00511cd2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00511cd3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00511cd4  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00511cd7  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00511cd9  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00511cdb  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00511cdd  eb01                   -jmp 0x511ce0
    goto L_0x00511ce0;
L_0x00511cdf:
    // 00511cdf  42                     -inc edx
    (cpu.edx)++;
L_0x00511ce0:
    // 00511ce0  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00511ce2  8a0b                   -mov cl, byte ptr [ebx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ebx);
    // 00511ce4  40                     -inc eax
    (cpu.eax)++;
    // 00511ce5  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 00511ce7  75f6                   -jne 0x511cdf
    if (!cpu.flags.zf)
    {
        goto L_0x00511cdf;
    }
    // 00511ce9  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00511ceb  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00511cef  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00511cf0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00511cf1  a1bcac5600             -mov eax, dword ptr [0x56acbc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5680316) /* 0x56acbc */);
    // 00511cf6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00511cf7  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00511cfa  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00511cfb  2eff1540465300         -call dword ptr cs:[0x534640]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457472) /* 0x534640 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00511d02  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00511d04  e983d6feff             -jmp 0x4ff38c
    return sub_4ff38c(app, cpu);
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_511d0c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00511d0c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00511d0d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00511d0e  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00511d10  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00511d12  8cda                   -mov edx, ds
    cpu.edx = cpu.ds;
    // 00511d14  e877240100             -call 0x524190
    cpu.esp -= 4;
    sub_524190(app, cpu);
    if (cpu.terminate) return;
    // 00511d19  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00511d1b  7509                   -jne 0x511d26
    if (!cpu.flags.zf)
    {
        goto L_0x00511d26;
    }
    // 00511d1d  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00511d1f  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00511d21  e8aaffffff             -call 0x511cd0
    cpu.esp -= 4;
    sub_511cd0(app, cpu);
    if (cpu.terminate) return;
L_0x00511d26:
    // 00511d26  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00511d27  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00511d28  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_511d30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00511d30  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00511d31  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00511d32  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00511d34  833dd089560000         +cmp dword ptr [0x5689d0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5671376) /* 0x5689d0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00511d3b  7424                   -je 0x511d61
    if (cpu.flags.zf)
    {
        goto L_0x00511d61;
    }
L_0x00511d3d:
    // 00511d3d  833dcc89560000         +cmp dword ptr [0x5689cc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5671372) /* 0x5689cc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00511d44  750a                   -jne 0x511d50
    if (!cpu.flags.zf)
    {
        goto L_0x00511d50;
    }
    // 00511d46  e89595fdff             -call 0x4eb2e0
    cpu.esp -= 4;
    sub_4eb2e0(app, cpu);
    if (cpu.terminate) return;
    // 00511d4b  a3cc895600             -mov dword ptr [0x5689cc], eax
    app->getMemory<x86::reg32>(x86::reg32(5671372) /* 0x5689cc */) = cpu.eax;
L_0x00511d50:
    // 00511d50  833dd089560000         +cmp dword ptr [0x5689d0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5671376) /* 0x5689d0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00511d57  745c                   -je 0x511db5
    if (cpu.flags.zf)
    {
        goto L_0x00511db5;
    }
    // 00511d59  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00511d5e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00511d5f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00511d60  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00511d61:
    // 00511d61  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00511d62  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00511d63  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00511d64  bedc005500             -mov esi, 0x5500dc
    cpu.esi = 5570780 /*0x5500dc*/;
    // 00511d69  bfec005500             -mov edi, 0x5500ec
    cpu.edi = 5570796 /*0x5500ec*/;
    // 00511d6e  bd64000000             -mov ebp, 0x64
    cpu.ebp = 100 /*0x64*/;
    // 00511d73  c1e006                 -shl eax, 6
    cpu.eax <<= 6 /*0x6*/ % 32;
    // 00511d76  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00511d78  893590215500           -mov dword ptr [0x552190], esi
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.esi;
    // 00511d7e  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00511d81  893d94215500           -mov dword ptr [0x552194], edi
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.edi;
    // 00511d87  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00511d89  b8f8005500             -mov eax, 0x5500f8
    cpu.eax = 5570808 /*0x5500f8*/;
    // 00511d8e  892d98215500           -mov dword ptr [0x552198], ebp
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ebp;
    // 00511d94  e887f8fcff             -call 0x4e1620
    cpu.esp -= 4;
    sub_4e1620(app, cpu);
    if (cpu.terminate) return;
    // 00511d99  a3d0895600             -mov dword ptr [0x5689d0], eax
    app->getMemory<x86::reg32>(x86::reg32(5671376) /* 0x5689d0 */) = cpu.eax;
    // 00511d9e  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00511da0  890d90b0a000           -mov dword ptr [0xa0b090], ecx
    app->getMemory<x86::reg32>(x86::reg32(10530960) /* 0xa0b090 */) = cpu.ecx;
    // 00511da6  a398b0a000             -mov dword ptr [0xa0b098], eax
    app->getMemory<x86::reg32>(x86::reg32(10530968) /* 0xa0b098 */) = cpu.eax;
    // 00511dab  a394b0a000             -mov dword ptr [0xa0b094], eax
    app->getMemory<x86::reg32>(x86::reg32(10530964) /* 0xa0b094 */) = cpu.eax;
    // 00511db0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00511db1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00511db2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00511db3  eb88                   -jmp 0x511d3d
    goto L_0x00511d3d;
L_0x00511db5:
    // 00511db5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00511db7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00511db8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00511db9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_511dc0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00511dc0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00511dc1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00511dc2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00511dc3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00511dc4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00511dc5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00511dc6  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00511dc8  81ec10010000           -sub esp, 0x110
    (cpu.esp) -= x86::reg32(x86::sreg32(272 /*0x110*/));
    // 00511dce  833dd089560000         +cmp dword ptr [0x5689d0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5671376) /* 0x5689d0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00511dd5  0f849c020000           -je 0x512077
    if (cpu.flags.zf)
    {
        goto L_0x00512077;
    }
    // 00511ddb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00511ddd  0f8494020000           -je 0x512077
    if (cpu.flags.zf)
    {
        goto L_0x00512077;
    }
    // 00511de3  ba04015500             -mov edx, 0x550104
    cpu.edx = 5570820 /*0x550104*/;
    // 00511de8  e8fbc1fdff             -call 0x4edfe8
    cpu.esp -= 4;
    sub_4edfe8(app, cpu);
    if (cpu.terminate) return;
L_0x00511ded:
    // 00511ded  8b15d0895600           -mov edx, dword ptr [0x5689d0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5671376) /* 0x5689d0 */);
    // 00511df3  8945f4                 -mov dword ptr [ebp - 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.eax;
    // 00511df6  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00511df8  8955fc                 -mov dword ptr [ebp - 4], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 00511dfb  890dd0895600           -mov dword ptr [0x5689d0], ecx
    app->getMemory<x86::reg32>(x86::reg32(5671376) /* 0x5689d0 */) = cpu.ecx;
    // 00511e01  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00511e03  0f8449030000           -je 0x512152
    if (cpu.flags.zf)
    {
        goto L_0x00512152;
    }
    // 00511e09  8b1d90b0a000           -mov ebx, dword ptr [0xa0b090]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10530960) /* 0xa0b090 */);
    // 00511e0f  a198b0a000             -mov eax, dword ptr [0xa0b098]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10530968) /* 0xa0b098 */);
    // 00511e14  39d8                   +cmp eax, ebx
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
    // 00511e16  0f8d62020000           -jge 0x51207e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0051207e;
    }
L_0x00511e1c:
    // 00511e1c  a398b0a000             -mov dword ptr [0xa0b098], eax
    app->getMemory<x86::reg32>(x86::reg32(10530968) /* 0xa0b098 */) = cpu.eax;
L_0x00511e21:
    // 00511e21  8b3598b0a000           -mov esi, dword ptr [0xa0b098]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(10530968) /* 0xa0b098 */);
    // 00511e27  4e                     -dec esi
    (cpu.esi)--;
    // 00511e28  893598b0a000           -mov dword ptr [0xa0b098], esi
    app->getMemory<x86::reg32>(x86::reg32(10530968) /* 0xa0b098 */) = cpu.esi;
    // 00511e2e  83feff                 +cmp esi, -1
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
    // 00511e31  0f8413030000           -je 0x51214a
    if (cpu.flags.zf)
    {
        goto L_0x0051214a;
    }
    // 00511e37  a194b0a000             -mov eax, dword ptr [0xa0b094]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10530964) /* 0xa0b094 */);
    // 00511e3c  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00511e3f  c1e006                 -shl eax, 6
    cpu.eax <<= 6 /*0x6*/ % 32;
    // 00511e42  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00511e44  8955f8                 -mov dword ptr [ebp - 8], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.edx;
    // 00511e47  8b1594b0a000           -mov edx, dword ptr [0xa0b094]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10530964) /* 0xa0b094 */);
    // 00511e4d  42                     -inc edx
    (cpu.edx)++;
    // 00511e4e  8b1d90b0a000           -mov ebx, dword ptr [0xa0b090]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10530960) /* 0xa0b090 */);
    // 00511e54  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00511e56  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00511e59  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00511e5b  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00511e5e  891594b0a000           -mov dword ptr [0xa0b094], edx
    app->getMemory<x86::reg32>(x86::reg32(10530964) /* 0xa0b094 */) = cpu.edx;
    // 00511e64  80780900               +cmp byte ptr [eax + 9], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(9) /* 0x9 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00511e68  0f8421020000           -je 0x51208f
    if (cpu.flags.zf)
    {
        goto L_0x0051208f;
    }
    // 00511e6e  8b55f8                 -mov edx, dword ptr [ebp - 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00511e71  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00511e73  8a4209                 -mov al, byte ptr [edx + 9]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(9) /* 0x9 */);
    // 00511e76  8a5a0a                 -mov bl, byte ptr [edx + 0xa]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(10) /* 0xa */);
    // 00511e79  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00511e7a  f6c308                 +test bl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 8 /*0x8*/));
    // 00511e7d  0f8402020000           -je 0x512085
    if (cpu.flags.zf)
    {
        goto L_0x00512085;
    }
    // 00511e83  b808015500             -mov eax, 0x550108
    cpu.eax = 5570824 /*0x550108*/;
L_0x00511e88:
    // 00511e88  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00511e89  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00511e8c  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 00511e8e  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00511e8f  6818015500             -push 0x550118
    app->getMemory<x86::reg32>(cpu.esp-4) = 5570840 /*0x550118*/;
    cpu.esp -= 4;
    // 00511e94  8d85f0feffff           -lea eax, [ebp - 0x110]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-272) /* -0x110 */);
    // 00511e9a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00511e9b  e8f0d7fcff             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 00511ea0  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
L_0x00511ea3:
    // 00511ea3  8dbdf0feffff           -lea edi, [ebp - 0x110]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-272) /* -0x110 */);
    // 00511ea9  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00511eae  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00511eb0  49                     -dec ecx
    (cpu.ecx)--;
    // 00511eb1  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00511eb3  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00511eb5  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00511eb7  49                     -dec ecx
    (cpu.ecx)--;
    // 00511eb8  8d85f0feffff           -lea eax, [ebp - 0x110]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-272) /* -0x110 */);
    // 00511ebe  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00511ec0  8b4df4                 -mov ecx, dword ptr [ebp - 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00511ec3  e808cdfdff             -call 0x4eebd0
    cpu.esp -= 4;
    sub_4eebd0(app, cpu);
    if (cpu.terminate) return;
    // 00511ec8  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00511ecb  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00511ece  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 00511ed0  8945f0                 -mov dword ptr [ebp - 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
    // 00511ed3  8a7df0                 -mov bh, byte ptr [ebp - 0x10]
    cpu.bh = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00511ed6  80ff20                 +cmp bh, 0x20
    {
        x86::reg8 tmp1 = cpu.bh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(32 /*0x20*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00511ed9  0f83e2010000           -jae 0x5120c1
    if (!cpu.flags.cf)
    {
        goto L_0x005120c1;
    }
L_0x00511edf:
    // 00511edf  c645f05f               -mov byte ptr [ebp - 0x10], 0x5f
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = 95 /*0x5f*/;
L_0x00511ee3:
    // 00511ee3  8a45f1                 -mov al, byte ptr [ebp - 0xf]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-15) /* -0xf */);
    // 00511ee6  3c20                   +cmp al, 0x20
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(32 /*0x20*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00511ee8  0f83e1010000           -jae 0x5120cf
    if (!cpu.flags.cf)
    {
        goto L_0x005120cf;
    }
L_0x00511eee:
    // 00511eee  c645f15f               -mov byte ptr [ebp - 0xf], 0x5f
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-15) /* -0xf */) = 95 /*0x5f*/;
L_0x00511ef2:
    // 00511ef2  8a75f2                 -mov dh, byte ptr [ebp - 0xe]
    cpu.dh = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-14) /* -0xe */);
    // 00511ef5  80fe20                 +cmp dh, 0x20
    {
        x86::reg8 tmp1 = cpu.dh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(32 /*0x20*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00511ef8  0f83de010000           -jae 0x5120dc
    if (!cpu.flags.cf)
    {
        goto L_0x005120dc;
    }
L_0x00511efe:
    // 00511efe  c645f25f               -mov byte ptr [ebp - 0xe], 0x5f
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-14) /* -0xe */) = 95 /*0x5f*/;
L_0x00511f02:
    // 00511f02  8a4df3                 -mov cl, byte ptr [ebp - 0xd]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-13) /* -0xd */);
    // 00511f05  80f920                 +cmp cl, 0x20
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(32 /*0x20*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00511f08  0f83dc010000           -jae 0x5120ea
    if (!cpu.flags.cf)
    {
        goto L_0x005120ea;
    }
L_0x00511f0e:
    // 00511f0e  c645f35f               -mov byte ptr [ebp - 0xd], 0x5f
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-13) /* -0xd */) = 95 /*0x5f*/;
L_0x00511f12:
    // 00511f12  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00511f15  f6400a02               +test byte ptr [eax + 0xa], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(10) /* 0xa */) & 2 /*0x2*/));
    // 00511f19  0f84d9010000           -je 0x5120f8
    if (cpu.flags.zf)
    {
        goto L_0x005120f8;
    }
    // 00511f1f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00511f21  8a45f3                 -mov al, byte ptr [ebp - 0xd]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-13) /* -0xd */);
    // 00511f24  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00511f25  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00511f27  8a45f2                 -mov al, byte ptr [ebp - 0xe]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-14) /* -0xe */);
    // 00511f2a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00511f2b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00511f2d  8a45f1                 -mov al, byte ptr [ebp - 0xf]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-15) /* -0xf */);
    // 00511f30  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00511f31  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00511f33  8a45f0                 -mov al, byte ptr [ebp - 0x10]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00511f36  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00511f37  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00511f3a  8b5804                 -mov ebx, dword ptr [eax + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00511f3d  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00511f3e  6838015500             -push 0x550138
    app->getMemory<x86::reg32>(cpu.esp-4) = 5570872 /*0x550138*/;
    cpu.esp -= 4;
    // 00511f43  8d85f0feffff           -lea eax, [ebp - 0x110]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-272) /* -0x110 */);
    // 00511f49  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00511f4a  e841d7fcff             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 00511f4f  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
L_0x00511f52:
    // 00511f52  8dbdf0feffff           -lea edi, [ebp - 0x110]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-272) /* -0x110 */);
    // 00511f58  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00511f5d  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00511f5f  49                     -dec ecx
    (cpu.ecx)--;
    // 00511f60  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00511f62  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00511f64  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00511f66  49                     -dec ecx
    (cpu.ecx)--;
    // 00511f67  8d85f0feffff           -lea eax, [ebp - 0x110]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-272) /* -0x110 */);
    // 00511f6d  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00511f6f  8b4df4                 -mov ecx, dword ptr [ebp - 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00511f72  e859ccfdff             -call 0x4eebd0
    cpu.esp -= 4;
    sub_4eebd0(app, cpu);
    if (cpu.terminate) return;
    // 00511f77  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00511f7a  f6400a01               +test byte ptr [eax + 0xa], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(10) /* 0xa */) & 1 /*0x1*/));
    // 00511f7e  0f847e000000           -je 0x512002
    if (cpu.flags.zf)
    {
        goto L_0x00512002;
    }
    // 00511f84  8b55f8                 -mov edx, dword ptr [ebp - 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00511f87  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00511f89  8a4208                 -mov al, byte ptr [edx + 8]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00511f8c  ba35000000             -mov edx, 0x35
    cpu.edx = 53 /*0x35*/;
    // 00511f91  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00511f93  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00511f95  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00511f97  7e09                   -jle 0x511fa2
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00511fa2;
    }
    // 00511f99  83fa35                 +cmp edx, 0x35
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(53 /*0x35*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00511f9c  0f8d76010000           -jge 0x512118
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00512118;
    }
L_0x00511fa2:
    // 00511fa2  8b75f8                 -mov esi, dword ptr [ebp - 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00511fa5  b835000000             -mov eax, 0x35
    cpu.eax = 53 /*0x35*/;
    // 00511faa  0fb67608               -movzx esi, byte ptr [esi + 8]
    cpu.esi = x86::reg32(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */));
    // 00511fae  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00511fb0  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00511fb2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00511fb4  0f8e57010000           -jle 0x512111
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00512111;
    }
L_0x00511fba:
    // 00511fba  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00511fbd  83c00b                 -add eax, 0xb
    (cpu.eax) += x86::reg32(x86::sreg32(11 /*0xb*/));
    // 00511fc0  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00511fc2  8a50fd                 -mov dl, byte ptr [eax - 3]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(-3) /* -0x3 */);
    // 00511fc5  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00511fc7  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00511fc9  8d85f0feffff           -lea eax, [ebp - 0x110]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-272) /* -0x110 */);
    // 00511fcf  8dbdf0feffff           -lea edi, [ebp - 0x110]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-272) /* -0x110 */);
    // 00511fd5  e856eefcff             -call 0x4e0e30
    cpu.esp -= 4;
    sub_4e0e30(app, cpu);
    if (cpu.terminate) return;
    // 00511fda  30db                   -xor bl, bl
    cpu.bl ^= x86::reg8(x86::sreg8(cpu.bl));
    // 00511fdc  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00511fe1  889c2ef0feffff         -mov byte ptr [esi + ebp - 0x110], bl
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(-272) /* -0x110 */ + cpu.ebp * 1) = cpu.bl;
    // 00511fe8  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00511fea  49                     -dec ecx
    (cpu.ecx)--;
    // 00511feb  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00511fed  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00511fef  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00511ff1  49                     -dec ecx
    (cpu.ecx)--;
    // 00511ff2  8d85f0feffff           -lea eax, [ebp - 0x110]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-272) /* -0x110 */);
    // 00511ff8  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00511ffa  8b4df4                 -mov ecx, dword ptr [ebp - 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00511ffd  e8cecbfdff             -call 0x4eebd0
    cpu.esp -= 4;
    sub_4eebd0(app, cpu);
    if (cpu.terminate) return;
L_0x00512002:
    // 00512002  8b4df4                 -mov ecx, dword ptr [ebp - 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00512005  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0051200a  b858015500             -mov eax, 0x550158
    cpu.eax = 5570904 /*0x550158*/;
    // 0051200f  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00512011  e8bacbfdff             -call 0x4eebd0
    cpu.esp -= 4;
    sub_4eebd0(app, cpu);
    if (cpu.terminate) return;
    // 00512016  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00512019  f6400a04               +test byte ptr [eax + 0xa], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(10) /* 0xa */) & 4 /*0x4*/));
    // 0051201d  0f84ff000000           -je 0x512122
    if (cpu.flags.zf)
    {
        goto L_0x00512122;
    }
    // 00512023  8d700b                 -lea esi, [eax + 0xb]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(11) /* 0xb */);
    // 00512026  bf03000000             -mov edi, 3
    cpu.edi = 3 /*0x3*/;
L_0x0051202b:
    // 0051202b  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0051202e  8a4008                 -mov al, byte ptr [eax + 8]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00512031  88c4                   -mov ah, al
    cpu.ah = cpu.al;
    // 00512033  8b55f8                 -mov edx, dword ptr [ebp - 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00512036  fecc                   -dec ah
    (cpu.ah)--;
    // 00512038  886208                 -mov byte ptr [edx + 8], ah
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(8) /* 0x8 */) = cpu.ah;
    // 0051203b  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 0051203d  0f84df000000           -je 0x512122
    if (cpu.flags.zf)
    {
        goto L_0x00512122;
    }
    // 00512043  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00512045  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0051204a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051204b  685c015500             -push 0x55015c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5570908 /*0x55015c*/;
    cpu.esp -= 4;
    // 00512050  8d85f0feffff           -lea eax, [ebp - 0x110]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-272) /* -0x110 */);
    // 00512056  8b4df4                 -mov ecx, dword ptr [ebp - 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00512059  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051205a  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0051205f  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00512061  e82ad6fcff             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 00512066  83c40c                 +add esp, 0xc
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
    // 00512069  8d85f0feffff           -lea eax, [ebp - 0x110]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-272) /* -0x110 */);
    // 0051206f  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00512070  e85bcbfdff             -call 0x4eebd0
    cpu.esp -= 4;
    sub_4eebd0(app, cpu);
    if (cpu.terminate) return;
    // 00512075  ebb4                   -jmp 0x51202b
    goto L_0x0051202b;
L_0x00512077:
    // 00512077  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00512079  e96ffdffff             -jmp 0x511ded
    goto L_0x00511ded;
L_0x0051207e:
    // 0051207e  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00512080  e997fdffff             -jmp 0x511e1c
    goto L_0x00511e1c;
L_0x00512085:
    // 00512085  b810015500             -mov eax, 0x550110
    cpu.eax = 5570832 /*0x550110*/;
    // 0051208a  e9f9fdffff             -jmp 0x511e88
    goto L_0x00511e88;
L_0x0051208f:
    // 0051208f  f6400a08               +test byte ptr [eax + 0xa], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(10) /* 0xa */) & 8 /*0x8*/));
    // 00512093  7425                   -je 0x5120ba
    if (cpu.flags.zf)
    {
        goto L_0x005120ba;
    }
    // 00512095  b808015500             -mov eax, 0x550108
    cpu.eax = 5570824 /*0x550108*/;
L_0x0051209a:
    // 0051209a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051209b  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0051209e  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 005120a0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 005120a1  6828015500             -push 0x550128
    app->getMemory<x86::reg32>(cpu.esp-4) = 5570856 /*0x550128*/;
    cpu.esp -= 4;
    // 005120a6  8d85f0feffff           -lea eax, [ebp - 0x110]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-272) /* -0x110 */);
    // 005120ac  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 005120ad  e8ded5fcff             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 005120b2  83c410                 +add esp, 0x10
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
    // 005120b5  e9e9fdffff             -jmp 0x511ea3
    goto L_0x00511ea3;
L_0x005120ba:
    // 005120ba  b810015500             -mov eax, 0x550110
    cpu.eax = 5570832 /*0x550110*/;
    // 005120bf  ebd9                   -jmp 0x51209a
    goto L_0x0051209a;
L_0x005120c1:
    // 005120c1  80ff7f                 +cmp bh, 0x7f
    {
        x86::reg8 tmp1 = cpu.bh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(127 /*0x7f*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 005120c4  0f8715feffff           -ja 0x511edf
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00511edf;
    }
    // 005120ca  e914feffff             -jmp 0x511ee3
    goto L_0x00511ee3;
L_0x005120cf:
    // 005120cf  3c7f                   +cmp al, 0x7f
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(127 /*0x7f*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 005120d1  0f8717feffff           -ja 0x511eee
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00511eee;
    }
    // 005120d7  e916feffff             -jmp 0x511ef2
    goto L_0x00511ef2;
L_0x005120dc:
    // 005120dc  80fe7f                 +cmp dh, 0x7f
    {
        x86::reg8 tmp1 = cpu.dh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(127 /*0x7f*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 005120df  0f8719feffff           -ja 0x511efe
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00511efe;
    }
    // 005120e5  e918feffff             -jmp 0x511f02
    goto L_0x00511f02;
L_0x005120ea:
    // 005120ea  80f97f                 +cmp cl, 0x7f
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(127 /*0x7f*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 005120ed  0f871bfeffff           -ja 0x511f0e
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00511f0e;
    }
    // 005120f3  e91afeffff             -jmp 0x511f12
    goto L_0x00511f12;
L_0x005120f8:
    // 005120f8  6848015500             -push 0x550148
    app->getMemory<x86::reg32>(cpu.esp-4) = 5570888 /*0x550148*/;
    cpu.esp -= 4;
    // 005120fd  8d85f0feffff           -lea eax, [ebp - 0x110]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-272) /* -0x110 */);
    // 00512103  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00512104  e887d5fcff             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 00512109  83c408                 +add esp, 8
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
    // 0051210c  e941feffff             -jmp 0x511f52
    goto L_0x00511f52;
L_0x00512111:
    // 00512111  31c6                   +xor esi, eax
    cpu.clear_co();
    cpu.set_szp((cpu.esi ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00512113  e9a2feffff             -jmp 0x511fba
    goto L_0x00511fba;
L_0x00512118:
    // 00512118  be35000000             -mov esi, 0x35
    cpu.esi = 53 /*0x35*/;
    // 0051211d  e998feffff             -jmp 0x511fba
    goto L_0x00511fba;
L_0x00512122:
    // 00512122  bf64015500             -mov edi, 0x550164
    cpu.edi = 5570916 /*0x550164*/;
    // 00512127  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0051212c  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0051212e  49                     -dec ecx
    (cpu.ecx)--;
    // 0051212f  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00512131  f2ae                   +repne scasb al, byte ptr es:[edi]
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
    // 00512133  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00512135  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00512136  b864015500             -mov eax, 0x550164
    cpu.eax = 5570916 /*0x550164*/;
    // 0051213b  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0051213d  8b4df4                 -mov ecx, dword ptr [ebp - 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00512140  e88bcafdff             -call 0x4eebd0
    cpu.esp -= 4;
    sub_4eebd0(app, cpu);
    if (cpu.terminate) return;
    // 00512145  e9d7fcffff             -jmp 0x511e21
    goto L_0x00511e21;
L_0x0051214a:
    // 0051214a  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0051214d  e8aebffdff             -call 0x4ee100
    cpu.esp -= 4;
    sub_4ee100(app, cpu);
    if (cpu.terminate) return;
L_0x00512152:
    // 00512152  8b75fc                 -mov esi, dword ptr [ebp - 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00512155  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00512157  7407                   -je 0x512160
    if (cpu.flags.zf)
    {
        goto L_0x00512160;
    }
    // 00512159  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0051215b  e830f7fcff             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
L_0x00512160:
    // 00512160  837df400               +cmp dword ptr [ebp - 0xc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00512164  740e                   -je 0x512174
    if (cpu.flags.zf)
    {
        goto L_0x00512174;
    }
    // 00512166  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0051216b  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0051216d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051216e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051216f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00512170  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00512171  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00512172  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00512173  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00512174:
    // 00512174  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00512176  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00512178  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00512179  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051217a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051217b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051217c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051217d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051217e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_512180(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00512180  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00512181  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00512182  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00512183  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00512185  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00512188  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0051218b  8955f8                 -mov dword ptr [ebp - 8], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.edx;
    // 0051218e  895df4                 -mov dword ptr [ebp - 0xc], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.ebx;
    // 00512191  894df0                 -mov dword ptr [ebp - 0x10], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.ecx;
    // 00512194  833dd089560000         +cmp dword ptr [0x5689d0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5671376) /* 0x5689d0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0051219b  751a                   -jne 0x5121b7
    if (!cpu.flags.zf)
    {
        goto L_0x005121b7;
    }
L_0x0051219d:
    // 0051219d  833dd089560000         +cmp dword ptr [0x5689d0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5671376) /* 0x5689d0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005121a4  0f84f4010000           -je 0x51239e
    if (cpu.flags.zf)
    {
        goto L_0x0051239e;
    }
    // 005121aa  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 005121af  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 005121b1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005121b2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005121b3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005121b4  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x005121b7:
    // 005121b7  8b0dcc895600           -mov ecx, dword ptr [0x5689cc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5671372) /* 0x5689cc */);
    // 005121bd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005121be  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005121c4  8b1594b0a000           -mov edx, dword ptr [0xa0b094]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10530964) /* 0xa0b094 */);
    // 005121ca  8b1d98b0a000           -mov ebx, dword ptr [0xa0b098]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10530968) /* 0xa0b098 */);
    // 005121d0  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 005121d2  8b3590b0a000           -mov esi, dword ptr [0xa0b090]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(10530960) /* 0xa0b090 */);
    // 005121d8  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 005121da  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 005121dd  f7fe                   -idiv esi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.esi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 005121df  8b35d0895600           -mov esi, dword ptr [0x5689d0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5671376) /* 0x5689d0 */);
    // 005121e5  c1e206                 -shl edx, 6
    cpu.edx <<= 6 /*0x6*/ % 32;
    // 005121e8  8b3d90b0a000           -mov edi, dword ptr [0xa0b090]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(10530960) /* 0xa0b090 */);
    // 005121ee  01d6                   -add esi, edx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edx));
    // 005121f0  39fb                   +cmp ebx, edi
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
    // 005121f2  0f8565010000           -jne 0x51235d
    if (!cpu.flags.zf)
    {
        goto L_0x0051235d;
    }
    // 005121f8  8b1594b0a000           -mov edx, dword ptr [0xa0b094]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10530964) /* 0xa0b094 */);
    // 005121fe  42                     -inc edx
    (cpu.edx)++;
    // 005121ff  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00512201  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00512204  f7ff                   -idiv edi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.edi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00512206  891594b0a000           -mov dword ptr [0xa0b094], edx
    app->getMemory<x86::reg32>(x86::reg32(10530964) /* 0xa0b094 */) = cpu.edx;
L_0x0051220c:
    // 0051220c  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0051220f  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00512211  0f845d010000           -je 0x512374
    if (cpu.flags.zf)
    {
        goto L_0x00512374;
    }
    // 00512217  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00512219  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0051221b  49                     -dec ecx
    (cpu.ecx)--;
    // 0051221c  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0051221e  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00512220  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00512222  49                     -dec ecx
    (cpu.ecx)--;
    // 00512223  83f935                 +cmp ecx, 0x35
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(53 /*0x35*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00512226  0f833e010000           -jae 0x51236a
    if (!cpu.flags.cf)
    {
        goto L_0x0051236a;
    }
    // 0051222c  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0051222e  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00512230  49                     -dec ecx
    (cpu.ecx)--;
    // 00512231  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00512233  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00512235  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00512237  49                     -dec ecx
    (cpu.ecx)--;
    // 00512238  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
L_0x0051223a:
    // 0051223a  88df                   -mov bh, bl
    cpu.bh = cpu.bl;
L_0x0051223c:
    // 0051223c  837df400               +cmp dword ptr [ebp - 0xc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00512240  0f8435010000           -je 0x51237b
    if (cpu.flags.zf)
    {
        goto L_0x0051237b;
    }
    // 00512246  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00512248  ba35000000             -mov edx, 0x35
    cpu.edx = 53 /*0x35*/;
    // 0051224d  88f8                   -mov al, bh
    cpu.al = cpu.bh;
    // 0051224f  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00512251  8b7df0                 -mov edi, dword ptr [ebp - 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00512254  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00512256  39fa                   +cmp edx, edi
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
    // 00512258  7e02                   -jle 0x51225c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0051225c;
    }
    // 0051225a  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
L_0x0051225c:
    // 0051225c  884608                 -mov byte ptr [esi + 8], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.al;
L_0x0051225f:
    // 0051225f  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 00512262  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00512264  7405                   -je 0x51226b
    if (cpu.flags.zf)
    {
        goto L_0x0051226b;
    }
    // 00512266  b808000000             -mov eax, 8
    cpu.eax = 8 /*0x8*/;
L_0x0051226b:
    // 0051226b  88460a                 -mov byte ptr [esi + 0xa], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(10) /* 0xa */) = cpu.al;
    // 0051226e  a1a4c17900             -mov eax, dword ptr [0x79c1a4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7979428) /* 0x79c1a4 */);
    // 00512273  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 00512275  8a4514                 -mov al, byte ptr [ebp + 0x14]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 00512278  8b55f4                 -mov edx, dword ptr [ebp - 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0051227b  884609                 -mov byte ptr [esi + 9], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(9) /* 0x9 */) = cpu.al;
    // 0051227e  8d460b                 -lea eax, [esi + 0xb]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(11) /* 0xb */);
    // 00512281  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00512283  742b                   -je 0x5122b0
    if (cpu.flags.zf)
    {
        goto L_0x005122b0;
    }
    // 00512285  807e0800               +cmp byte ptr [esi + 8], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00512289  7425                   -je 0x5122b0
    if (cpu.flags.zf)
    {
        goto L_0x005122b0;
    }
    // 0051228b  8a760a                 -mov dh, byte ptr [esi + 0xa]
    cpu.dh = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(10) /* 0xa */);
    // 0051228e  8b4df4                 -mov ecx, dword ptr [ebp - 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00512291  80ce04                 -or dh, 4
    cpu.dh |= x86::reg8(x86::sreg8(4 /*0x4*/));
    // 00512294  8a5e08                 -mov bl, byte ptr [esi + 8]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00512297  88760a                 -mov byte ptr [esi + 0xa], dh
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(10) /* 0xa */) = cpu.dh;
    // 0051229a  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 0051229c  84db                   +test bl, bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.bl));
    // 0051229e  7610                   -jbe 0x5122b0
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x005122b0;
    }
L_0x005122a0:
    // 005122a0  8a31                   -mov dh, byte ptr [ecx]
    cpu.dh = app->getMemory<x86::reg8>(cpu.ecx);
    // 005122a2  8830                   -mov byte ptr [eax], dh
    app->getMemory<x86::reg8>(cpu.eax) = cpu.dh;
    // 005122a4  fec2                   -inc dl
    (cpu.dl)++;
    // 005122a6  41                     -inc ecx
    (cpu.ecx)++;
    // 005122a7  8a7608                 -mov dh, byte ptr [esi + 8]
    cpu.dh = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 005122aa  40                     -inc eax
    (cpu.eax)++;
    // 005122ab  38f2                   +cmp dl, dh
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.dh));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 005122ad  72f1                   -jb 0x5122a0
    if (cpu.flags.cf)
    {
        goto L_0x005122a0;
    }
    // 005122af  90                     -nop 
    ;
L_0x005122b0:
    // 005122b0  8b4dfc                 -mov ecx, dword ptr [ebp - 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 005122b3  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 005122b5  742c                   -je 0x5122e3
    if (cpu.flags.zf)
    {
        goto L_0x005122e3;
    }
    // 005122b7  84ff                   +test bh, bh
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & cpu.bh));
    // 005122b9  7428                   -je 0x5122e3
    if (cpu.flags.zf)
    {
        goto L_0x005122e3;
    }
    // 005122bb  804e0a01               -or byte ptr [esi + 0xa], 1
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(10) /* 0xa */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 005122bf  30db                   -xor bl, bl
    cpu.bl ^= x86::reg8(x86::sreg8(cpu.bl));
    // 005122c1  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 005122c3  84ff                   +test bh, bh
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & cpu.bh));
    // 005122c5  7619                   -jbe 0x5122e0
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x005122e0;
    }
L_0x005122c7:
    // 005122c7  40                     -inc eax
    (cpu.eax)++;
    // 005122c8  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 005122ca  42                     -inc edx
    (cpu.edx)++;
    // 005122cb  fec3                   -inc bl
    (cpu.bl)++;
    // 005122cd  8848ff                 -mov byte ptr [eax - 1], cl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(-1) /* -0x1 */) = cpu.cl;
    // 005122d0  38fb                   +cmp bl, bh
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
    // 005122d2  72f3                   -jb 0x5122c7
    if (cpu.flags.cf)
    {
        goto L_0x005122c7;
    }
    // 005122d4  8d8000000000           -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 005122da  8d9200000000           -lea edx, [edx]
    cpu.edx = x86::reg32(cpu.edx);
L_0x005122e0:
    // 005122e0  c60000                 -mov byte ptr [eax], 0
    app->getMemory<x86::reg8>(cpu.eax) = 0 /*0x0*/;
L_0x005122e3:
    // 005122e3  8b5df8                 -mov ebx, dword ptr [ebp - 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 005122e6  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 005122e8  0f8496000000           -je 0x512384
    if (cpu.flags.zf)
    {
        goto L_0x00512384;
    }
    // 005122ee  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 005122f0  8a7e0a                 -mov bh, byte ptr [esi + 0xa]
    cpu.bh = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(10) /* 0xa */);
    // 005122f3  894604                 -mov dword ptr [esi + 4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 005122f6  80cf02                 -or bh, 2
    cpu.bh |= x86::reg8(x86::sreg8(2 /*0x2*/));
    // 005122f9  887e0a                 -mov byte ptr [esi + 0xa], bh
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(10) /* 0xa */) = cpu.bh;
L_0x005122fc:
    // 005122fc  833dd489560000         +cmp dword ptr [0x5689d4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5671380) /* 0x5689d4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00512303  7447                   -je 0x51234c
    if (cpu.flags.zf)
    {
        goto L_0x0051234c;
    }
    // 00512305  8b45f0                 -mov eax, dword ptr [ebp - 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00512308  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0051230b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051230c  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0051230e  0f8478000000           -je 0x51238c
    if (cpu.flags.zf)
    {
        goto L_0x0051238c;
    }
    // 00512314  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x00512316:
    // 00512316  8b4df8                 -mov ecx, dword ptr [ebp - 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00512319  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051231a  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0051231c  7475                   -je 0x512393
    if (cpu.flags.zf)
    {
        goto L_0x00512393;
    }
    // 0051231e  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
L_0x00512320:
    // 00512320  8b5d10                 -mov ebx, dword ptr [ebp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 00512323  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00512324  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00512326  746f                   -je 0x512397
    if (cpu.flags.zf)
    {
        goto L_0x00512397;
    }
    // 00512328  b808015500             -mov eax, 0x550108
    cpu.eax = 5570824 /*0x550108*/;
L_0x0051232d:
    // 0051232d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051232e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00512330  8a4514                 -mov al, byte ptr [ebp + 0x14]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 00512333  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00512334  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00512336  a0d8895600             -mov al, byte ptr [0x5689d8]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5671384) /* 0x5689d8 */);
    // 0051233b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0051233c  8b3e                   -mov edi, dword ptr [esi]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi);
    // 0051233e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0051233f  686c015500             -push 0x55016c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5570924 /*0x55016c*/;
    cpu.esp -= 4;
    // 00512344  e8a7e5fcff             -call 0x4e08f0
    cpu.esp -= 4;
    sub_4e08f0(app, cpu);
    if (cpu.terminate) return;
    // 00512349  83c420                 +add esp, 0x20
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
L_0x0051234c:
    // 0051234c  a1cc895600             -mov eax, dword ptr [0x5689cc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5671372) /* 0x5689cc */);
    // 00512351  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00512352  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00512358  e940feffff             -jmp 0x51219d
    goto L_0x0051219d;
L_0x0051235d:
    // 0051235d  8d4301                 -lea eax, [ebx + 1]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 00512360  a398b0a000             -mov dword ptr [0xa0b098], eax
    app->getMemory<x86::reg32>(x86::reg32(10530968) /* 0xa0b098 */) = cpu.eax;
    // 00512365  e9a2feffff             -jmp 0x51220c
    goto L_0x0051220c;
L_0x0051236a:
    // 0051236a  bb35000000             -mov ebx, 0x35
    cpu.ebx = 53 /*0x35*/;
    // 0051236f  e9c6feffff             -jmp 0x51223a
    goto L_0x0051223a;
L_0x00512374:
    // 00512374  30ff                   +xor bh, bh
    cpu.clear_co();
    cpu.set_szp((cpu.bh ^= x86::reg8(x86::sreg8(cpu.bh))));
    // 00512376  e9c1feffff             -jmp 0x51223c
    goto L_0x0051223c;
L_0x0051237b:
    // 0051237b  c6460800               -mov byte ptr [esi + 8], 0
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 0051237f  e9dbfeffff             -jmp 0x51225f
    goto L_0x0051225f;
L_0x00512384:
    // 00512384  895e04                 -mov dword ptr [esi + 4], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 00512387  e970ffffff             -jmp 0x5122fc
    goto L_0x005122fc;
L_0x0051238c:
    // 0051238c  b868015500             -mov eax, 0x550168
    cpu.eax = 5570920 /*0x550168*/;
    // 00512391  eb83                   -jmp 0x512316
    goto L_0x00512316;
L_0x00512393:
    // 00512393  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00512395  eb89                   -jmp 0x512320
    goto L_0x00512320;
L_0x00512397:
    // 00512397  b810015500             -mov eax, 0x550110
    cpu.eax = 5570832 /*0x550110*/;
    // 0051239c  eb8f                   -jmp 0x51232d
    goto L_0x0051232d;
L_0x0051239e:
    // 0051239e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 005123a0  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 005123a2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005123a3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005123a4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005123a5  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_5123b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005123b0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005123b1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005123b2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 005123b3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005123b4  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 005123b7  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 005123bb  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 005123bf  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 005123c1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 005123c3  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 005123c5  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 005123c7  7e17                   -jle 0x5123e0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x005123e0;
    }
    // 005123c9  8b7c2408               -mov edi, dword ptr [esp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 005123cd  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
L_0x005123cf:
    // 005123cf  8b1e                   -mov ebx, dword ptr [esi]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi);
    // 005123d1  83c608                 -add esi, 8
    (cpu.esi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 005123d4  40                     -inc eax
    (cpu.eax)++;
    // 005123d5  01dd                   -add ebp, ebx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.ebx));
    // 005123d7  39f8                   +cmp eax, edi
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
    // 005123d9  7cf4                   -jl 0x5123cf
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x005123cf;
    }
    // 005123db  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 005123de  8bc9                   -mov ecx, ecx
    cpu.ecx = cpu.ecx;
L_0x005123e0:
    // 005123e0  b894015500             -mov eax, 0x550194
    cpu.eax = 5570964 /*0x550194*/;
    // 005123e5  baa0015500             -mov edx, 0x5501a0
    cpu.edx = 5570976 /*0x5501a0*/;
    // 005123ea  bb2d000000             -mov ebx, 0x2d
    cpu.ebx = 45 /*0x2d*/;
    // 005123ef  a390215500             -mov dword ptr [0x552190], eax
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.eax;
    // 005123f4  891594215500           -mov dword ptr [0x552194], edx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.edx;
    // 005123fa  891d98215500           -mov dword ptr [0x552198], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ebx;
    // 00512400  b8ac015500             -mov eax, 0x5501ac
    cpu.eax = 5570988 /*0x5501ac*/;
    // 00512405  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00512407  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00512409  e812f2fcff             -call 0x4e1620
    cpu.esp -= 4;
    sub_4e1620(app, cpu);
    if (cpu.terminate) return;
    // 0051240e  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00512411  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00512413  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00512417  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00512419  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0051241b  7e23                   -jle 0x512440
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00512440;
    }
L_0x0051241d:
    // 0051241d  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0051241f  8b19                   -mov ebx, dword ptr [ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx);
    // 00512421  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00512424  83c108                 -add ecx, 8
    (cpu.ecx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00512427  e8c480fdff             -call 0x4ea4f0
    cpu.esp -= 4;
    sub_4ea4f0(app, cpu);
    if (cpu.terminate) return;
    // 0051242c  47                     -inc edi
    (cpu.edi)++;
    // 0051242d  8b51f8                 -mov edx, dword ptr [ecx - 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-8) /* -0x8 */);
    // 00512430  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00512434  01d6                   -add esi, edx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edx));
    // 00512436  39df                   +cmp edi, ebx
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
    // 00512438  7ce3                   -jl 0x51241d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0051241d;
    }
    // 0051243a  8d8000000000           -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x00512440:
    // 00512440  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00512444  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 00512447  8b4904                 -mov ecx, dword ptr [ecx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0051244a  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0051244e  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 00512450  ff5108                 -call dword ptr [ecx + 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00512453  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00512455  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00512458  e833f4fcff             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
    // 0051245d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0051245f  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00512462  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00512463  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00512464  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00512465  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00512466  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_512470(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00512470  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00512471  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00512472  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00512473  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00512474  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00512477  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0051247b  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0051247f  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00512481  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00512483  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 00512485  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00512487  7e17                   -jle 0x5124a0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x005124a0;
    }
    // 00512489  8b7c2408               -mov edi, dword ptr [esp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0051248d  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x0051248f:
    // 0051248f  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 00512491  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00512494  46                     -inc esi
    (cpu.esi)++;
    // 00512495  01dd                   -add ebp, ebx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00512497  39fe                   +cmp esi, edi
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
    // 00512499  7cf4                   -jl 0x51248f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0051248f;
    }
    // 0051249b  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 0051249e  8bc9                   -mov ecx, ecx
    cpu.ecx = cpu.ecx;
L_0x005124a0:
    // 005124a0  b894015500             -mov eax, 0x550194
    cpu.eax = 5570964 /*0x550194*/;
    // 005124a5  bab4015500             -mov edx, 0x5501b4
    cpu.edx = 5570996 /*0x5501b4*/;
    // 005124aa  bb4a000000             -mov ebx, 0x4a
    cpu.ebx = 74 /*0x4a*/;
    // 005124af  a390215500             -mov dword ptr [0x552190], eax
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.eax;
    // 005124b4  891594215500           -mov dword ptr [0x552194], edx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.edx;
    // 005124ba  891d98215500           -mov dword ptr [0x552198], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ebx;
    // 005124c0  b8c4015500             -mov eax, 0x5501c4
    cpu.eax = 5571012 /*0x5501c4*/;
    // 005124c5  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 005124c7  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 005124c9  e852f1fcff             -call 0x4e1620
    cpu.esp -= 4;
    sub_4e1620(app, cpu);
    if (cpu.terminate) return;
    // 005124ce  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 005124d1  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 005124d3  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 005124d7  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 005124d9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005124db  7e23                   -jle 0x512500
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00512500;
    }
L_0x005124dd:
    // 005124dd  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 005124df  8b19                   -mov ebx, dword ptr [ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx);
    // 005124e1  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 005124e4  83c108                 -add ecx, 8
    (cpu.ecx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 005124e7  e80480fdff             -call 0x4ea4f0
    cpu.esp -= 4;
    sub_4ea4f0(app, cpu);
    if (cpu.terminate) return;
    // 005124ec  47                     -inc edi
    (cpu.edi)++;
    // 005124ed  8b51f8                 -mov edx, dword ptr [ecx - 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-8) /* -0x8 */);
    // 005124f0  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 005124f4  01d6                   -add esi, edx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edx));
    // 005124f6  39df                   +cmp edi, ebx
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
    // 005124f8  7ce3                   -jl 0x5124dd
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x005124dd;
    }
    // 005124fa  8d8000000000           -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x00512500:
    // 00512500  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00512504  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00512506  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 00512509  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 0051250b  ff5120                 -call dword ptr [ecx + 0x20]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0051250e  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00512510  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00512513  e878f3fcff             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
    // 00512518  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0051251a  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0051251d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051251e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051251f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00512520  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00512521  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_512530(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00512530  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00512531  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00512532  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00512533  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00512535  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00512537  8b5c2410               -mov ebx, dword ptr [esp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0051253b  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0051253d  7c59                   -jl 0x512598
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00512598;
    }
    // 0051253f  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00512541  e88abcffff             -call 0x50e1d0
    cpu.esp -= 4;
    sub_50e1d0(app, cpu);
    if (cpu.terminate) return;
    // 00512546  39c2                   +cmp edx, eax
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
    // 00512548  734e                   -jae 0x512598
    if (!cpu.flags.cf)
    {
        goto L_0x00512598;
    }
    // 0051254a  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0051254c  89531c                 -mov dword ptr [ebx + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 0051254f  e81cbfffff             -call 0x50e470
    cpu.esp -= 4;
    sub_50e470(app, cpu);
    if (cpu.terminate) return;
    // 00512554  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00512556  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00512558  752d                   -jne 0x512587
    if (!cpu.flags.zf)
    {
        goto L_0x00512587;
    }
    // 0051255a  ba94015500             -mov edx, 0x550194
    cpu.edx = 5570964 /*0x550194*/;
    // 0051255f  b8cc015500             -mov eax, 0x5501cc
    cpu.eax = 5571020 /*0x5501cc*/;
    // 00512564  68e0015500             -push 0x5501e0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5571040 /*0x5501e0*/;
    cpu.esp -= 4;
    // 00512569  891590215500           -mov dword ptr [0x552190], edx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edx;
    // 0051256f  ba63000000             -mov edx, 0x63
    cpu.edx = 99 /*0x63*/;
    // 00512574  a394215500             -mov dword ptr [0x552194], eax
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.eax;
    // 00512579  891598215500           -mov dword ptr [0x552198], edx
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.edx;
    // 0051257f  e88ceaeeff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 00512584  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00512587:
    // 00512587  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00512588  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0051258a  8b550c                 -mov edx, dword ptr [ebp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0051258d  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 0051258f  ff5504                 -call dword ptr [ebp + 4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00512592  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00512593  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00512594  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00512595  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00512598:
    // 00512598  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0051259a  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0051259c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0051259e  e80dfeffff             -call 0x5123b0
    cpu.esp -= 4;
    sub_5123b0(app, cpu);
    if (cpu.terminate) return;
    // 005125a3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005125a4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005125a5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005125a6  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_5125b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005125b0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005125b1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 005125b2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005125b3  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 005125b5  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 005125b7  8b5c2410               -mov ebx, dword ptr [esp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 005125bb  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 005125bd  7c59                   -jl 0x512618
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00512618;
    }
    // 005125bf  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 005125c1  e80abcffff             -call 0x50e1d0
    cpu.esp -= 4;
    sub_50e1d0(app, cpu);
    if (cpu.terminate) return;
    // 005125c6  39c2                   +cmp edx, eax
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
    // 005125c8  734e                   -jae 0x512618
    if (!cpu.flags.cf)
    {
        goto L_0x00512618;
    }
    // 005125ca  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 005125cc  89531c                 -mov dword ptr [ebx + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 005125cf  e89cbeffff             -call 0x50e470
    cpu.esp -= 4;
    sub_50e470(app, cpu);
    if (cpu.terminate) return;
    // 005125d4  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 005125d6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005125d8  752d                   -jne 0x512607
    if (!cpu.flags.zf)
    {
        goto L_0x00512607;
    }
    // 005125da  ba94015500             -mov edx, 0x550194
    cpu.edx = 5570964 /*0x550194*/;
    // 005125df  b8f4015500             -mov eax, 0x5501f4
    cpu.eax = 5571060 /*0x5501f4*/;
    // 005125e4  68e0015500             -push 0x5501e0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5571040 /*0x5501e0*/;
    cpu.esp -= 4;
    // 005125e9  891590215500           -mov dword ptr [0x552190], edx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edx;
    // 005125ef  ba78000000             -mov edx, 0x78
    cpu.edx = 120 /*0x78*/;
    // 005125f4  a394215500             -mov dword ptr [0x552194], eax
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.eax;
    // 005125f9  891598215500           -mov dword ptr [0x552198], edx
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.edx;
    // 005125ff  e80ceaeeff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 00512604  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00512607:
    // 00512607  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00512608  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0051260a  8b550c                 -mov edx, dword ptr [ebp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0051260d  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 0051260f  ff5508                 -call dword ptr [ebp + 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00512612  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00512613  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00512614  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00512615  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00512618:
    // 00512618  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0051261a  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0051261c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0051261e  e84dfeffff             -call 0x512470
    cpu.esp -= 4;
    sub_512470(app, cpu);
    if (cpu.terminate) return;
    // 00512623  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00512624  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00512625  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00512626  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_512630(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00512630  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00512631  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00512633  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00512635  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00512636  e895bbffff             -call 0x50e1d0
    cpu.esp -= 4;
    sub_50e1d0(app, cpu);
    if (cpu.terminate) return;
    // 0051263b  48                     -dec eax
    (cpu.eax)--;
    // 0051263c  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0051263e  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00512640  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00512642  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00512644  e8e7feffff             -call 0x512530
    cpu.esp -= 4;
    sub_512530(app, cpu);
    if (cpu.terminate) return;
    // 00512649  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051264a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_512650(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00512650  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00512651  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00512653  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00512655  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00512657  e854ffffff             -call 0x5125b0
    cpu.esp -= 4;
    sub_5125b0(app, cpu);
    if (cpu.terminate) return;
    // 0051265c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_512660(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00512660  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00512661  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00512662  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00512663  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00512664  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00512666  ba94015500             -mov edx, 0x550194
    cpu.edx = 5570964 /*0x550194*/;
    // 0051266b  bb08025500             -mov ebx, 0x550208
    cpu.ebx = 5571080 /*0x550208*/;
    // 00512670  be9a000000             -mov esi, 0x9a
    cpu.esi = 154 /*0x9a*/;
    // 00512675  b8c4015500             -mov eax, 0x5501c4
    cpu.eax = 5571012 /*0x5501c4*/;
    // 0051267a  891590215500           -mov dword ptr [0x552190], edx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edx;
    // 00512680  891d94215500           -mov dword ptr [0x552194], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebx;
    // 00512686  ba20000000             -mov edx, 0x20
    cpu.edx = 32 /*0x20*/;
    // 0051268b  8b1df4435600           -mov ebx, dword ptr [0x5643f4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5653492) /* 0x5643f4 */);
    // 00512691  893598215500           -mov dword ptr [0x552198], esi
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.esi;
    // 00512697  e884effcff             -call 0x4e1620
    cpu.esp -= 4;
    sub_4e1620(app, cpu);
    if (cpu.terminate) return;
    // 0051269c  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0051269e  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 005126a0  894130                 -mov dword ptr [ecx + 0x30], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(48) /* 0x30 */) = cpu.eax;
    // 005126a3  e828b6ffff             -call 0x50dcd0
    cpu.esp -= 4;
    sub_50dcd0(app, cpu);
    if (cpu.terminate) return;
    // 005126a8  83793000               +cmp dword ptr [ecx + 0x30], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(48) /* 0x30 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005126ac  740a                   -je 0x5126b8
    if (cpu.flags.zf)
    {
        goto L_0x005126b8;
    }
    // 005126ae  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 005126b3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005126b4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005126b5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005126b6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005126b7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005126b8:
    // 005126b8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 005126ba  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005126bb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005126bc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005126bd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005126be  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_5126c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005126c0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005126c1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 005126c2  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 005126c4  8b4830                 -mov ecx, dword ptr [eax + 0x30]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(48) /* 0x30 */);
    // 005126c7  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 005126c9  7503                   -jne 0x5126ce
    if (!cpu.flags.zf)
    {
        goto L_0x005126ce;
    }
    // 005126cb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005126cc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005126cd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005126ce:
    // 005126ce  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 005126d0  e80bb7ffff             -call 0x50dde0
    cpu.esp -= 4;
    sub_50dde0(app, cpu);
    if (cpu.terminate) return;
    // 005126d5  8b4230                 -mov eax, dword ptr [edx + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(48) /* 0x30 */);
    // 005126d8  e8b3f1fcff             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
    // 005126dd  c7423000000000         -mov dword ptr [edx + 0x30], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(48) /* 0x30 */) = 0 /*0x0*/;
    // 005126e4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005126e5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005126e6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_5126f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005126f0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005126f1  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 005126f4  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 005126f8  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 005126fb  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 005126fd  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00512702  8b4830                 -mov ecx, dword ptr [eax + 0x30]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(48) /* 0x30 */);
    // 00512705  e846ffffff             -call 0x512650
    cpu.esp -= 4;
    sub_512650(app, cpu);
    if (cpu.terminate) return;
    // 0051270a  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0051270d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051270e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_512710(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00512710  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00512711  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00512712  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00512713  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00512715  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00512717  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00512719  ba94015500             -mov edx, 0x550194
    cpu.edx = 5570964 /*0x550194*/;
    // 0051271e  bb18025500             -mov ebx, 0x550218
    cpu.ebx = 5571096 /*0x550218*/;
    // 00512723  b8f4000000             -mov eax, 0xf4
    cpu.eax = 244 /*0xf4*/;
    // 00512728  891590215500           -mov dword ptr [0x552190], edx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edx;
    // 0051272e  891d94215500           -mov dword ptr [0x552194], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebx;
    // 00512734  a398215500             -mov dword ptr [0x552198], eax
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.eax;
    // 00512739  ba10000000             -mov edx, 0x10
    cpu.edx = 16 /*0x10*/;
    // 0051273e  b8c4015500             -mov eax, 0x5501c4
    cpu.eax = 5571012 /*0x5501c4*/;
    // 00512743  8b1df4435600           -mov ebx, dword ptr [0x5643f4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5653492) /* 0x5643f4 */);
    // 00512749  e8d2eefcff             -call 0x4e1620
    cpu.esp -= 4;
    sub_4e1620(app, cpu);
    if (cpu.terminate) return;
    // 0051274e  897004                 -mov dword ptr [eax + 4], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 00512751  897808                 -mov dword ptr [eax + 8], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edi;
    // 00512754  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00512757  8b5d30                 -mov ebx, dword ptr [ebp + 0x30]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(48) /* 0x30 */);
    // 0051275a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0051275c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0051275e  e8edb6ffff             -call 0x50de50
    cpu.esp -= 4;
    sub_50de50(app, cpu);
    if (cpu.terminate) return;
    // 00512763  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00512768  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00512769  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051276a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0051276b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_512770(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00512770  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00512772  7406                   -je 0x51277a
    if (cpu.flags.zf)
    {
        goto L_0x0051277a;
    }
    // 00512774  83782400               +cmp dword ptr [eax + 0x24], 0
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
    // 00512778  7503                   -jne 0x51277d
    if (!cpu.flags.zf)
    {
        goto L_0x0051277d;
    }
L_0x0051277a:
    // 0051277a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0051277c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0051277d:
    // 0051277d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0051277e  8b4830                 -mov ecx, dword ptr [eax + 0x30]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(48) /* 0x30 */);
    // 00512781  e8aafeffff             -call 0x512630
    cpu.esp -= 4;
    sub_512630(app, cpu);
    if (cpu.terminate) return;
    // 00512786  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00512787  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_512790(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00512790  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00512791  8b711c                 -mov esi, dword ptr [ecx + 0x1c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */);
    // 00512794  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00512795  4e                     -dec esi
    (cpu.esi)--;
    // 00512796  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00512798  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0051279a  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0051279c  e88ffdffff             -call 0x512530
    cpu.esp -= 4;
    sub_512530(app, cpu);
    if (cpu.terminate) return;
    // 005127a1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005127a2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_5127b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005127b0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005127b1  8b711c                 -mov esi, dword ptr [ecx + 0x1c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */);
    // 005127b4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005127b5  46                     -inc esi
    (cpu.esi)++;
    // 005127b6  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 005127b8  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 005127ba  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 005127bc  e8effdffff             -call 0x5125b0
    cpu.esp -= 4;
    sub_5125b0(app, cpu);
    if (cpu.terminate) return;
    // 005127c1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005127c2  c3                     -ret 
    cpu.esp += 4;
    return;
}

}
