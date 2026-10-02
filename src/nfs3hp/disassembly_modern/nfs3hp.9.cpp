#include "nfs3hp.h"
#include <lib/thread.h>

namespace nfs3hp
{

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_436e90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00436e90  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00436e91  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00436e92  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00436e93  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00436e94  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00436e95  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00436e97  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00436e9a  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00436e9c  8855fc                 -mov byte ptr [ebp - 4], dl
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.dl;
    // 00436e9f  833d0c4f550000         +cmp dword ptr [0x554f0c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5590796) /* 0x554f0c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00436ea6  7507                   -jne 0x436eaf
    if (!cpu.flags.zf)
    {
        goto L_0x00436eaf;
    }
    // 00436ea8  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 00436eaa  e9f9000000             -jmp 0x436fa8
    goto L_0x00436fa8;
L_0x00436eaf:
    // 00436eaf  69c094040000           -imul eax, eax, 0x494
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(1172 /*0x494*/)));
    // 00436eb5  8b3d044f5500           -mov edi, dword ptr [0x554f04]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5590788) /* 0x554f04 */);
    // 00436ebb  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 00436ebe  8d3438                 -lea esi, [eax + edi]
    cpu.esi = x86::reg32(cpu.eax + cpu.edi * 1);
    // 00436ec1  8b5630                 -mov edx, dword ptr [esi + 0x30]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(48) /* 0x30 */);
    // 00436ec4  8d04d500000000         -lea eax, [edx*8]
    cpu.eax = x86::reg32(cpu.edx * 8);
    // 00436ecb  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00436ecd  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00436ed0  8b4df8                 -mov ecx, dword ptr [ebp - 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00436ed3  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00436ed5  8d4728                 -lea eax, [edi + 0x28]
    cpu.eax = x86::reg32(cpu.edi + x86::reg32(40) /* 0x28 */);
    // 00436ed8  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00436eda  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 00436edd  83c00c                 -add eax, 0xc
    (cpu.eax) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00436ee0  8d0c10                 -lea ecx, [eax + edx]
    cpu.ecx = x86::reg32(cpu.eax + cpu.edx * 1);
    // 00436ee3  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00436ee6  8d5001                 -lea edx, [eax + 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00436ee9  895108                 -mov dword ptr [ecx + 8], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00436eec  8a55fc                 -mov dl, byte ptr [ebp - 4]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00436eef  8854010c               -mov byte ptr [ecx + eax + 0xc], dl
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */ + cpu.eax * 1) = cpu.dl;
    // 00436ef3  837f0c01               +cmp dword ptr [edi + 0xc], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00436ef7  7537                   -jne 0x436f30
    if (!cpu.flags.zf)
    {
        goto L_0x00436f30;
    }
    // 00436ef9  8b17                   -mov edx, dword ptr [edi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi);
    // 00436efb  3b5108                 +cmp edx, dword ptr [ecx + 8]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00436efe  7d07                   -jge 0x436f07
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00436f07;
    }
    // 00436f00  c7410800000000         -mov dword ptr [ecx + 8], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
L_0x00436f07:
    // 00436f07  8b5904                 -mov ebx, dword ptr [ecx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00436f0a  3b5908                 +cmp ebx, dword ptr [ecx + 8]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00436f0d  751a                   -jne 0x436f29
    if (!cpu.flags.zf)
    {
        goto L_0x00436f29;
    }
    // 00436f0f  8d7301                 -lea esi, [ebx + 1]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 00436f12  a1044f5500             -mov eax, dword ptr [0x554f04]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5590788) /* 0x554f04 */);
    // 00436f17  897104                 -mov dword ptr [ecx + 4], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 00436f1a  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00436f1c  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 00436f1e  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00436f21  43                     -inc ebx
    (cpu.ebx)++;
    // 00436f22  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00436f24  f7fb                   +idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00436f26  895104                 -mov dword ptr [ecx + 4], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.edx;
L_0x00436f29:
    // 00436f29  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00436f2c  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 00436f2e  eb6b                   -jmp 0x436f9b
    goto L_0x00436f9b;
L_0x00436f30:
    // 00436f30  8b17                   -mov edx, dword ptr [edi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi);
    // 00436f32  3b5108                 +cmp edx, dword ptr [ecx + 8]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00436f35  753f                   -jne 0x436f76
    if (!cpu.flags.zf)
    {
        goto L_0x00436f76;
    }
    // 00436f37  8b4630                 -mov eax, dword ptr [esi + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(48) /* 0x30 */);
    // 00436f3a  40                     -inc eax
    (cpu.eax)++;
    // 00436f3b  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00436f3d  894630                 -mov dword ptr [esi + 0x30], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(48) /* 0x30 */) = cpu.eax;
    // 00436f40  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00436f43  f77f04                 -idiv dword ptr [edi + 4]
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */));
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00436f46  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00436f48  895630                 -mov dword ptr [esi + 0x30], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(48) /* 0x30 */) = cpu.edx;
    // 00436f4b  e870feffff             -call 0x436dc0
    cpu.esp -= 4;
    sub_436dc0(app, cpu);
    if (cpu.terminate) return;
    // 00436f50  8b75f8                 -mov esi, dword ptr [ebp - 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00436f53  8b3d044f5500           -mov edi, dword ptr [0x554f04]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5590788) /* 0x554f04 */);
    // 00436f59  01fe                   -add esi, edi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edi));
    // 00436f5b  8b4630                 -mov eax, dword ptr [esi + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(48) /* 0x30 */);
    // 00436f5e  8b562c                 -mov edx, dword ptr [esi + 0x2c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(44) /* 0x2c */);
    // 00436f61  39d0                   +cmp eax, edx
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
    // 00436f63  7511                   -jne 0x436f76
    if (!cpu.flags.zf)
    {
        goto L_0x00436f76;
    }
    // 00436f65  8d4201                 -lea eax, [edx + 1]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 00436f68  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00436f6a  89462c                 -mov dword ptr [esi + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 00436f6d  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00436f70  f77f04                 -idiv dword ptr [edi + 4]
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */));
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00436f73  89562c                 -mov dword ptr [esi + 0x2c], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(44) /* 0x2c */) = cpu.edx;
L_0x00436f76:
    // 00436f76  a1044f5500             -mov eax, dword ptr [0x554f04]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5590788) /* 0x554f04 */);
    // 00436f7b  83782000               +cmp dword ptr [eax + 0x20], 0
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
    // 00436f7f  7407                   -je 0x436f88
    if (cpu.flags.zf)
    {
        goto L_0x00436f88;
    }
    // 00436f81  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00436f83  e818020000             -call 0x4371a0
    cpu.esp -= 4;
    sub_4371a0(app, cpu);
    if (cpu.terminate) return;
L_0x00436f88:
    // 00436f88  69d394040000           -imul edx, ebx, 0x494
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(1172 /*0x494*/)));
    // 00436f8e  a1044f5500             -mov eax, dword ptr [0x554f04]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5590788) /* 0x554f04 */);
    // 00436f93  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00436f95  8b502c                 -mov edx, dword ptr [eax + 0x2c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(44) /* 0x2c */);
    // 00436f98  895028                 -mov dword ptr [eax + 0x28], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */) = cpu.edx;
L_0x00436f9b:
    // 00436f9b  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00436f9e  c644010c00             -mov byte ptr [ecx + eax + 0xc], 0
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */ + cpu.eax * 1) = 0 /*0x0*/;
    // 00436fa3  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
L_0x00436fa8:
    // 00436fa8  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00436faa  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00436fac  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00436fad  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00436fae  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00436faf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00436fb0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00436fb1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_436fc0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00436fc0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00436fc1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00436fc2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00436fc3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00436fc4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00436fc5  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00436fc7  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00436fc9  833d0c4f550000         +cmp dword ptr [0x554f0c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5590796) /* 0x554f0c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00436fd0  7507                   -jne 0x436fd9
    if (!cpu.flags.zf)
    {
        goto L_0x00436fd9;
    }
    // 00436fd2  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00436fd4  e99b000000             -jmp 0x437074
    goto L_0x00437074;
L_0x00436fd9:
    // 00436fd9  69cb94040000           -imul ecx, ebx, 0x494
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(1172 /*0x494*/)));
    // 00436fdf  a1044f5500             -mov eax, dword ptr [0x554f04]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5590788) /* 0x554f04 */);
    // 00436fe4  83c028                 -add eax, 0x28
    (cpu.eax) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 00436fe7  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00436fe9  8b5108                 -mov edx, dword ptr [ecx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
L_0x00436fec:
    // 00436fec  3b5104                 +cmp edx, dword ptr [ecx + 4]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00436fef  7428                   -je 0x437019
    if (cpu.flags.zf)
    {
        goto L_0x00437019;
    }
    // 00436ff1  8d04d500000000         -lea eax, [edx*8]
    cpu.eax = x86::reg32(cpu.edx * 8);
    // 00436ff8  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00436ffa  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00436ffd  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00436fff  8b748114               -mov esi, dword ptr [ecx + eax*4 + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */ + cpu.eax * 4);
    // 00437003  3b748110               +cmp esi, dword ptr [ecx + eax*4 + 0x10]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */ + cpu.eax * 4)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00437007  7510                   -jne 0x437019
    if (!cpu.flags.zf)
    {
        goto L_0x00437019;
    }
    // 00437009  4a                     -dec edx
    (cpu.edx)--;
    // 0043700a  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0043700c  7dde                   -jge 0x436fec
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00436fec;
    }
    // 0043700e  a1044f5500             -mov eax, dword ptr [0x554f04]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5590788) /* 0x554f04 */);
    // 00437013  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00437016  4a                     +dec edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00437017  ebd3                   -jmp 0x436fec
    goto L_0x00436fec;
L_0x00437019:
    // 00437019  8d04d500000000         -lea eax, [edx*8]
    cpu.eax = x86::reg32(cpu.edx * 8);
    // 00437020  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00437022  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00437025  8d3402                 -lea esi, [edx + eax]
    cpu.esi = x86::reg32(cpu.edx + cpu.eax * 1);
    // 00437028  c1e602                 -shl esi, 2
    cpu.esi <<= 2 /*0x2*/ % 32;
    // 0043702b  8d410c                 -lea eax, [ecx + 0xc]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 0043702e  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 00437030  8b7008                 -mov esi, dword ptr [eax + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00437033  3b7004                 +cmp esi, dword ptr [eax + 4]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00437036  7508                   -jne 0x437040
    if (!cpu.flags.zf)
    {
        goto L_0x00437040;
    }
    // 00437038  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0043703a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043703b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043703c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043703d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043703e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043703f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00437040:
    // 00437040  4e                     -dec esi
    (cpu.esi)--;
    // 00437041  897008                 -mov dword ptr [eax + 8], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.esi;
    // 00437044  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00437046  7d0b                   -jge 0x437053
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00437053;
    }
    // 00437048  8b35044f5500           -mov esi, dword ptr [0x554f04]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5590788) /* 0x554f04 */);
    // 0043704e  8b36                   -mov esi, dword ptr [esi]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi);
    // 00437050  897008                 -mov dword ptr [eax + 8], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.esi;
L_0x00437053:
    // 00437053  895108                 -mov dword ptr [ecx + 8], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00437056  034008                 -add eax, dword ptr [eax + 8]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */)));
    // 00437059  c6400c00               -mov byte ptr [eax + 0xc], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 0043705d  a1044f5500             -mov eax, dword ptr [0x554f04]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5590788) /* 0x554f04 */);
    // 00437062  83782000               +cmp dword ptr [eax + 0x20], 0
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
    // 00437066  7407                   -je 0x43706f
    if (cpu.flags.zf)
    {
        goto L_0x0043706f;
    }
    // 00437068  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0043706a  e831010000             -call 0x4371a0
    cpu.esp -= 4;
    sub_4371a0(app, cpu);
    if (cpu.terminate) return;
L_0x0043706f:
    // 0043706f  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x00437074:
    // 00437074  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00437075  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00437076  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00437077  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00437078  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00437079  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_437080(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00437080  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00437081  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00437082  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00437083  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00437084  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00437085  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00437086  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00437088  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0043708b  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0043708d  69d394040000           -imul edx, ebx, 0x494
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(1172 /*0x494*/)));
    // 00437093  a1084f5500             -mov eax, dword ptr [0x554f08]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5590792) /* 0x554f08 */);
    // 00437098  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0043709a  83f901                 +cmp ecx, 1
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
    // 0043709d  7576                   -jne 0x437115
    if (!cpu.flags.zf)
    {
        goto L_0x00437115;
    }
    // 0043709f  a1044f5500             -mov eax, dword ptr [0x554f04]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5590788) /* 0x554f04 */);
    // 004370a4  8b7010                 -mov esi, dword ptr [eax + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004370a7  8b540234               -mov edx, dword ptr [edx + eax + 0x34]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(52) /* 0x34 */ + cpu.eax * 1);
    // 004370ab  01ce                   -add esi, ecx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004370ad  8d3c32                 -lea edi, [edx + esi]
    cpu.edi = x86::reg32(cpu.edx + cpu.esi * 1);
    // 004370b0  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004370b2  39fe                   +cmp esi, edi
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
    // 004370b4  7d07                   -jge 0x4370bd
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004370bd;
    }
    // 004370b6  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004370b8  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004370ba  8d4801                 -lea ecx, [eax + 1]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
L_0x004370bd:
    // 004370bd  69fb94040000           -imul edi, ebx, 0x494
    cpu.edi = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(1172 /*0x494*/)));
    // 004370c3  a1084f5500             -mov eax, dword ptr [0x554f08]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5590792) /* 0x554f08 */);
    // 004370c8  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004370cb  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 004370ce  a1044f5500             -mov eax, dword ptr [0x554f04]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5590788) /* 0x554f04 */);
    // 004370d3  83c028                 -add eax, 0x28
    (cpu.eax) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 004370d6  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 004370d8  83c018                 -add eax, 0x18
    (cpu.eax) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 004370db  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004370dd  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004370df  8b55f8                 -mov edx, dword ptr [ebp - 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004370e2  e809340b00             -call 0x4ea4f0
    cpu.esp -= 4;
    sub_4ea4f0(app, cpu);
    if (cpu.terminate) return;
    // 004370e7  39f1                   +cmp ecx, esi
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
    // 004370e9  0f8da0000000           -jge 0x43718f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043718f;
    }
    // 004370ef  a1084f5500             -mov eax, dword ptr [0x554f08]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5590792) /* 0x554f08 */);
    // 004370f4  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004370f7  8d1408                 -lea edx, [eax + ecx]
    cpu.edx = x86::reg32(cpu.eax + cpu.ecx * 1);
    // 004370fa  a1044f5500             -mov eax, dword ptr [0x554f04]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5590788) /* 0x554f04 */);
    // 004370ff  83c028                 -add eax, 0x28
    (cpu.eax) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 00437102  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00437104  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 00437106  29cb                   -sub ebx, ecx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00437108  83c018                 +add eax, 0x18
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(24 /*0x18*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0043710b  e8e0330b00             -call 0x4ea4f0
    cpu.esp -= 4;
    sub_4ea4f0(app, cpu);
    if (cpu.terminate) return;
    // 00437110  e97a000000             -jmp 0x43718f
    goto L_0x0043718f;
L_0x00437115:
    // 00437115  a1044f5500             -mov eax, dword ptr [0x554f04]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5590788) /* 0x554f04 */);
    // 0043711a  8b440228               -mov eax, dword ptr [edx + eax + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(40) /* 0x28 */ + cpu.eax * 1);
    // 0043711e  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00437120  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
L_0x00437123:
    // 00437123  8b3d084f5500           -mov edi, dword ptr [0x554f08]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5590792) /* 0x554f08 */);
    // 00437129  3b0f                   +cmp ecx, dword ptr [edi]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043712b  7d62                   -jge 0x43718f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043718f;
    }
    // 0043712d  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00437130  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00437132  8b35044f5500           -mov esi, dword ptr [0x554f04]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5590788) /* 0x554f04 */);
    // 00437138  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043713a  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0043713d  f77e04                 -idiv dword ptr [esi + 4]
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */));
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00437140  8d04d500000000         -lea eax, [edx*8]
    cpu.eax = x86::reg32(cpu.edx * 8);
    // 00437147  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00437149  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0043714c  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0043714e  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00437151  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 00437154  69c394040000           -imul eax, ebx, 0x494
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(1172 /*0x494*/)));
    // 0043715a  83c628                 -add esi, 0x28
    (cpu.esi) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 0043715d  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 0043715f  8b55f8                 -mov edx, dword ptr [ebp - 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00437162  83c00c                 -add eax, 0xc
    (cpu.eax) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00437165  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00437167  8d700c                 -lea esi, [eax + 0xc]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0043716a  6bc165                 -imul eax, ecx, 0x65
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(101 /*0x65*/)));
    // 0043716d  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00437170  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00437172  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x00437173:
    // 00437173  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00437175  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00437177  3c00                   +cmp al, 0
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
    // 00437179  7410                   -je 0x43718b
    if (cpu.flags.zf)
    {
        goto L_0x0043718b;
    }
    // 0043717b  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0043717e  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00437181  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00437184  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00437187  3c00                   +cmp al, 0
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
    // 00437189  75e8                   -jne 0x437173
    if (!cpu.flags.zf)
    {
        goto L_0x00437173;
    }
L_0x0043718b:
    // 0043718b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043718c  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0043718d  eb94                   -jmp 0x437123
    goto L_0x00437123;
L_0x0043718f:
    // 0043718f  a1084f5500             -mov eax, dword ptr [0x554f08]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5590792) /* 0x554f08 */);
    // 00437194  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00437196  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00437197  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00437198  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00437199  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043719a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043719b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043719c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4371a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004371a0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004371a1  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004371a3  a1044f5500             -mov eax, dword ptr [0x554f04]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5590788) /* 0x554f04 */);
    // 004371a8  83782000               +cmp dword ptr [eax + 0x20], 0
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
    // 004371ac  7404                   -je 0x4371b2
    if (cpu.flags.zf)
    {
        goto L_0x004371b2;
    }
    // 004371ae  83780c01               -cmp dword ptr [eax + 0xc], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
L_0x004371b2:
    // 004371b2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004371b3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4371c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004371c0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004371c1  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004371c3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004371c4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_4371d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004371d0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004371d1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004371d2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004371d3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004371d4  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004371d6  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004371d8  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004371db  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004371dd  f6c201                 +test dl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 1 /*0x1*/));
    // 004371e0  7501                   -jne 0x4371e3
    if (!cpu.flags.zf)
    {
        goto L_0x004371e3;
    }
    // 004371e2  42                     -inc edx
    (cpu.edx)++;
L_0x004371e3:
    // 004371e3  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004371e5  a801                   +test al, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 1 /*0x1*/));
    // 004371e7  7501                   -jne 0x4371ea
    if (!cpu.flags.zf)
    {
        goto L_0x004371ea;
    }
    // 004371e9  40                     -inc eax
    (cpu.eax)++;
L_0x004371ea:
    // 004371ea  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004371ec  0fafd0                 -imul edx, eax
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 004371ef  81e2ffff0000           -and edx, 0xffff
    cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004371f5  0fafd3                 -imul edx, ebx
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 004371f8  81e2ffff0000           -and edx, 0xffff
    cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004371fe  0fafd3                 -imul edx, ebx
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 00437201  81e2ffff0000           -and edx, 0xffff
    cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00437207  0fafd3                 -imul edx, ebx
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 0043720a  81e2ffff0000           -and edx, 0xffff
    cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00437210  0fafd3                 -imul edx, ebx
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 00437213  81e2ffff0000           -and edx, 0xffff
    cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00437219  0fafd3                 -imul edx, ebx
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 0043721c  81e2ffff0000           -and edx, 0xffff
    cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00437222  0fafd3                 -imul edx, ebx
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 00437225  81e2ffff0000           -and edx, 0xffff
    cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0043722b  0fafd3                 -imul edx, ebx
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 0043722e  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00437230  81e1ffff0000           -and ecx, 0xffff
    cpu.ecx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00437236  8915144f5500           -mov dword ptr [0x554f14], edx
    app->getMemory<x86::reg32>(x86::reg32(5590804) /* 0x554f14 */) = cpu.edx;
    // 0043723c  890d104f5500           -mov dword ptr [0x554f10], ecx
    app->getMemory<x86::reg32>(x86::reg32(5590800) /* 0x554f10 */) = cpu.ecx;
    // 00437242  891d184f5500           -mov dword ptr [0x554f18], ebx
    app->getMemory<x86::reg32>(x86::reg32(5590808) /* 0x554f18 */) = cpu.ebx;
    // 00437248  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00437249  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043724a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043724b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043724c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_437250(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00437250  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00437251  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00437252  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00437253  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00437254  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
L_0x00437256:
    // 00437256  8b1508bc6f00           -mov edx, dword ptr [0x6fbc08]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(7322632) /* 0x6fbc08 */);
    // 0043725c  a104bc6f00             -mov eax, dword ptr [0x6fbc04]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7322628) /* 0x6fbc04 */);
    // 00437261  39d0                   +cmp eax, edx
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
    // 00437263  7408                   -je 0x43726d
    if (cpu.flags.zf)
    {
        goto L_0x0043726d;
    }
    // 00437265  3b050cbc6f00           +cmp eax, dword ptr [0x6fbc0c]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(7322636) /* 0x6fbc0c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043726b  751c                   -jne 0x437289
    if (!cpu.flags.zf)
    {
        goto L_0x00437289;
    }
L_0x0043726d:
    // 0043726d  8b1d04bc6f00           -mov ebx, dword ptr [0x6fbc04]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(7322628) /* 0x6fbc04 */);
    // 00437273  43                     -inc ebx
    (cpu.ebx)++;
    // 00437274  891d04bc6f00           -mov dword ptr [0x6fbc04], ebx
    app->getMemory<x86::reg32>(x86::reg32(7322628) /* 0x6fbc04 */) = cpu.ebx;
    // 0043727a  83fb09                 +cmp ebx, 9
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(9 /*0x9*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043727d  7ed7                   -jle 0x437256
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00437256;
    }
    // 0043727f  31ff                   +xor edi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 00437281  893d04bc6f00           -mov dword ptr [0x6fbc04], edi
    app->getMemory<x86::reg32>(x86::reg32(7322628) /* 0x6fbc04 */) = cpu.edi;
    // 00437287  ebcd                   -jmp 0x437256
    goto L_0x00437256;
L_0x00437289:
    // 00437289  8b1504bc6f00           -mov edx, dword ptr [0x6fbc04]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(7322628) /* 0x6fbc04 */);
    // 0043728f  a108bc6f00             -mov eax, dword ptr [0x6fbc08]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7322632) /* 0x6fbc08 */);
    // 00437294  39d0                   +cmp eax, edx
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
    // 00437296  7408                   -je 0x4372a0
    if (cpu.flags.zf)
    {
        goto L_0x004372a0;
    }
    // 00437298  3b050cbc6f00           +cmp eax, dword ptr [0x6fbc0c]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(7322636) /* 0x6fbc0c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043729e  751c                   -jne 0x4372bc
    if (!cpu.flags.zf)
    {
        goto L_0x004372bc;
    }
L_0x004372a0:
    // 004372a0  8b1d08bc6f00           -mov ebx, dword ptr [0x6fbc08]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(7322632) /* 0x6fbc08 */);
    // 004372a6  43                     -inc ebx
    (cpu.ebx)++;
    // 004372a7  891d08bc6f00           -mov dword ptr [0x6fbc08], ebx
    app->getMemory<x86::reg32>(x86::reg32(7322632) /* 0x6fbc08 */) = cpu.ebx;
    // 004372ad  83fb09                 +cmp ebx, 9
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(9 /*0x9*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004372b0  7ed7                   -jle 0x437289
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00437289;
    }
    // 004372b2  31ff                   +xor edi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 004372b4  893d08bc6f00           -mov dword ptr [0x6fbc08], edi
    app->getMemory<x86::reg32>(x86::reg32(7322632) /* 0x6fbc08 */) = cpu.edi;
    // 004372ba  ebcd                   -jmp 0x437289
    goto L_0x00437289;
L_0x004372bc:
    // 004372bc  8b1504bc6f00           -mov edx, dword ptr [0x6fbc04]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(7322628) /* 0x6fbc04 */);
    // 004372c2  a10cbc6f00             -mov eax, dword ptr [0x6fbc0c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7322636) /* 0x6fbc0c */);
    // 004372c7  39d0                   +cmp eax, edx
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
    // 004372c9  7408                   -je 0x4372d3
    if (cpu.flags.zf)
    {
        goto L_0x004372d3;
    }
    // 004372cb  3b0508bc6f00           +cmp eax, dword ptr [0x6fbc08]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(7322632) /* 0x6fbc08 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004372d1  751c                   -jne 0x4372ef
    if (!cpu.flags.zf)
    {
        goto L_0x004372ef;
    }
L_0x004372d3:
    // 004372d3  8b1d0cbc6f00           -mov ebx, dword ptr [0x6fbc0c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(7322636) /* 0x6fbc0c */);
    // 004372d9  43                     -inc ebx
    (cpu.ebx)++;
    // 004372da  891d0cbc6f00           -mov dword ptr [0x6fbc0c], ebx
    app->getMemory<x86::reg32>(x86::reg32(7322636) /* 0x6fbc0c */) = cpu.ebx;
    // 004372e0  83fb09                 +cmp ebx, 9
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(9 /*0x9*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004372e3  7ed7                   -jle 0x4372bc
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004372bc;
    }
    // 004372e5  31ff                   +xor edi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 004372e7  893d0cbc6f00           -mov dword ptr [0x6fbc0c], edi
    app->getMemory<x86::reg32>(x86::reg32(7322636) /* 0x6fbc0c */) = cpu.edi;
    // 004372ed  ebcd                   -jmp 0x4372bc
    goto L_0x004372bc;
L_0x004372ef:
    // 004372ef  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004372f0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004372f1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004372f2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004372f3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_437300(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00437300  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00437301  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00437302  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00437303  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00437304  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00437306  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00437308  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0043730a  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0043730c  6683fb0d               +cmp bx, 0xd
    {
        x86::reg16 tmp1 = cpu.bx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(13 /*0xd*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00437310  7527                   -jne 0x437339
    if (!cpu.flags.zf)
    {
        goto L_0x00437339;
    }
L_0x00437312:
    // 00437312  0fbfdf                 -movsx ebx, di
    cpu.ebx = x86::reg32(static_cast<x86::sreg16>(cpu.di));
    // 00437315  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00437317  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00437319  e8529f0200             -call 0x461270
    cpu.esp -= 4;
    sub_461270(app, cpu);
    if (cpu.terminate) return;
    // 0043731e  8b1d04bc6f00           -mov ebx, dword ptr [0x6fbc04]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(7322628) /* 0x6fbc04 */);
    // 00437324  3b1d08bc6f00           +cmp ebx, dword ptr [0x6fbc08]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(7322632) /* 0x6fbc08 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043732a  74e6                   -je 0x437312
    if (cpu.flags.zf)
    {
        goto L_0x00437312;
    }
    // 0043732c  3b1d0cbc6f00           +cmp ebx, dword ptr [0x6fbc0c]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(7322636) /* 0x6fbc0c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00437332  74de                   -je 0x437312
    if (cpu.flags.zf)
    {
        goto L_0x00437312;
    }
    // 00437334  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00437335  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00437336  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00437337  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00437338  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00437339:
    // 00437339  0fbfdb                 -movsx ebx, bx
    cpu.ebx = x86::reg32(static_cast<x86::sreg16>(cpu.bx));
    // 0043733c  e82f9f0200             -call 0x461270
    cpu.esp -= 4;
    sub_461270(app, cpu);
    if (cpu.terminate) return;
    // 00437341  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00437342  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00437343  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00437344  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00437345  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void Application::sub_437350(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00437350  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00437351  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00437352  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00437354  0fbfdb                 -movsx ebx, bx
    cpu.ebx = x86::reg32(static_cast<x86::sreg16>(cpu.bx));
    // 00437357  8b0d04bc6f00           -mov ecx, dword ptr [0x6fbc04]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(7322628) /* 0x6fbc04 */);
    // 0043735d  e83eb10200             -call 0x4624a0
    cpu.esp -= 4;
    sub_4624a0(app, cpu);
    if (cpu.terminate) return;
    // 00437362  8b1504bc6f00           -mov edx, dword ptr [0x6fbc04]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(7322628) /* 0x6fbc04 */);
    // 00437368  39d1                   +cmp ecx, edx
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
    // 0043736a  7416                   -je 0x437382
    if (cpu.flags.zf)
    {
        goto L_0x00437382;
    }
    // 0043736c  3b1508bc6f00           +cmp edx, dword ptr [0x6fbc08]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(7322632) /* 0x6fbc08 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00437372  7408                   -je 0x43737c
    if (cpu.flags.zf)
    {
        goto L_0x0043737c;
    }
    // 00437374  3b150cbc6f00           +cmp edx, dword ptr [0x6fbc0c]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(7322636) /* 0x6fbc0c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043737a  7506                   -jne 0x437382
    if (!cpu.flags.zf)
    {
        goto L_0x00437382;
    }
L_0x0043737c:
    // 0043737c  890d04bc6f00           -mov dword ptr [0x6fbc04], ecx
    app->getMemory<x86::reg32>(x86::reg32(7322628) /* 0x6fbc04 */) = cpu.ecx;
L_0x00437382:
    // 00437382  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00437383  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00437384  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_437390(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00437390  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00437391  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00437392  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00437393  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00437394  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00437396  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00437398  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0043739a  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0043739c  6683fb0d               +cmp bx, 0xd
    {
        x86::reg16 tmp1 = cpu.bx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(13 /*0xd*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004373a0  7527                   -jne 0x4373c9
    if (!cpu.flags.zf)
    {
        goto L_0x004373c9;
    }
L_0x004373a2:
    // 004373a2  0fbfdf                 -movsx ebx, di
    cpu.ebx = x86::reg32(static_cast<x86::sreg16>(cpu.di));
    // 004373a5  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004373a7  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004373a9  e8c29e0200             -call 0x461270
    cpu.esp -= 4;
    sub_461270(app, cpu);
    if (cpu.terminate) return;
    // 004373ae  8b1d08bc6f00           -mov ebx, dword ptr [0x6fbc08]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(7322632) /* 0x6fbc08 */);
    // 004373b4  3b1d04bc6f00           +cmp ebx, dword ptr [0x6fbc04]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(7322628) /* 0x6fbc04 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004373ba  74e6                   -je 0x4373a2
    if (cpu.flags.zf)
    {
        goto L_0x004373a2;
    }
    // 004373bc  3b1d0cbc6f00           +cmp ebx, dword ptr [0x6fbc0c]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(7322636) /* 0x6fbc0c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004373c2  74de                   -je 0x4373a2
    if (cpu.flags.zf)
    {
        goto L_0x004373a2;
    }
    // 004373c4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004373c5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004373c6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004373c7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004373c8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004373c9:
    // 004373c9  0fbfdb                 -movsx ebx, bx
    cpu.ebx = x86::reg32(static_cast<x86::sreg16>(cpu.bx));
    // 004373cc  e89f9e0200             -call 0x461270
    cpu.esp -= 4;
    sub_461270(app, cpu);
    if (cpu.terminate) return;
    // 004373d1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004373d2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004373d3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004373d4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004373d5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void Application::sub_4373e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004373e0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004373e1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004373e2  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004373e4  0fbfdb                 -movsx ebx, bx
    cpu.ebx = x86::reg32(static_cast<x86::sreg16>(cpu.bx));
    // 004373e7  8b0d08bc6f00           -mov ecx, dword ptr [0x6fbc08]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(7322632) /* 0x6fbc08 */);
    // 004373ed  e8aeb00200             -call 0x4624a0
    cpu.esp -= 4;
    sub_4624a0(app, cpu);
    if (cpu.terminate) return;
    // 004373f2  8b1508bc6f00           -mov edx, dword ptr [0x6fbc08]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(7322632) /* 0x6fbc08 */);
    // 004373f8  39d1                   +cmp ecx, edx
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
    // 004373fa  7416                   -je 0x437412
    if (cpu.flags.zf)
    {
        goto L_0x00437412;
    }
    // 004373fc  3b1504bc6f00           +cmp edx, dword ptr [0x6fbc04]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(7322628) /* 0x6fbc04 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00437402  7408                   -je 0x43740c
    if (cpu.flags.zf)
    {
        goto L_0x0043740c;
    }
    // 00437404  3b150cbc6f00           +cmp edx, dword ptr [0x6fbc0c]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(7322636) /* 0x6fbc0c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043740a  7506                   -jne 0x437412
    if (!cpu.flags.zf)
    {
        goto L_0x00437412;
    }
L_0x0043740c:
    // 0043740c  890d08bc6f00           -mov dword ptr [0x6fbc08], ecx
    app->getMemory<x86::reg32>(x86::reg32(7322632) /* 0x6fbc08 */) = cpu.ecx;
L_0x00437412:
    // 00437412  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00437413  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00437414  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_437420(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00437420  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00437421  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00437422  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00437423  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00437424  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00437426  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00437428  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0043742a  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0043742c  6683fb0d               +cmp bx, 0xd
    {
        x86::reg16 tmp1 = cpu.bx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(13 /*0xd*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00437430  7527                   -jne 0x437459
    if (!cpu.flags.zf)
    {
        goto L_0x00437459;
    }
L_0x00437432:
    // 00437432  0fbfdf                 -movsx ebx, di
    cpu.ebx = x86::reg32(static_cast<x86::sreg16>(cpu.di));
    // 00437435  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00437437  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00437439  e8329e0200             -call 0x461270
    cpu.esp -= 4;
    sub_461270(app, cpu);
    if (cpu.terminate) return;
    // 0043743e  8b1d0cbc6f00           -mov ebx, dword ptr [0x6fbc0c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(7322636) /* 0x6fbc0c */);
    // 00437444  3b1d04bc6f00           +cmp ebx, dword ptr [0x6fbc04]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(7322628) /* 0x6fbc04 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043744a  74e6                   -je 0x437432
    if (cpu.flags.zf)
    {
        goto L_0x00437432;
    }
    // 0043744c  3b1d08bc6f00           +cmp ebx, dword ptr [0x6fbc08]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(7322632) /* 0x6fbc08 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00437452  74de                   -je 0x437432
    if (cpu.flags.zf)
    {
        goto L_0x00437432;
    }
    // 00437454  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00437455  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00437456  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00437457  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00437458  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00437459:
    // 00437459  0fbfdb                 -movsx ebx, bx
    cpu.ebx = x86::reg32(static_cast<x86::sreg16>(cpu.bx));
    // 0043745c  e80f9e0200             -call 0x461270
    cpu.esp -= 4;
    sub_461270(app, cpu);
    if (cpu.terminate) return;
    // 00437461  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00437462  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00437463  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00437464  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00437465  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void Application::sub_437470(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00437470  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00437471  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00437472  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00437474  0fbfdb                 -movsx ebx, bx
    cpu.ebx = x86::reg32(static_cast<x86::sreg16>(cpu.bx));
    // 00437477  8b0d0cbc6f00           -mov ecx, dword ptr [0x6fbc0c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(7322636) /* 0x6fbc0c */);
    // 0043747d  e81eb00200             -call 0x4624a0
    cpu.esp -= 4;
    sub_4624a0(app, cpu);
    if (cpu.terminate) return;
    // 00437482  8b150cbc6f00           -mov edx, dword ptr [0x6fbc0c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(7322636) /* 0x6fbc0c */);
    // 00437488  39d1                   +cmp ecx, edx
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
    // 0043748a  7416                   -je 0x4374a2
    if (cpu.flags.zf)
    {
        goto L_0x004374a2;
    }
    // 0043748c  3b1504bc6f00           +cmp edx, dword ptr [0x6fbc04]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(7322628) /* 0x6fbc04 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00437492  7408                   -je 0x43749c
    if (cpu.flags.zf)
    {
        goto L_0x0043749c;
    }
    // 00437494  3b1508bc6f00           +cmp edx, dword ptr [0x6fbc08]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(7322632) /* 0x6fbc08 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043749a  7506                   -jne 0x4374a2
    if (!cpu.flags.zf)
    {
        goto L_0x004374a2;
    }
L_0x0043749c:
    // 0043749c  890d0cbc6f00           -mov dword ptr [0x6fbc0c], ecx
    app->getMemory<x86::reg32>(x86::reg32(7322636) /* 0x6fbc0c */) = cpu.ecx;
L_0x004374a2:
    // 004374a2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004374a3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004374a4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_4374b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004374b0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004374b1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004374b2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004374b3  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004374b5  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004374b7  a104bc6f00             -mov eax, dword ptr [0x6fbc04]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7322628) /* 0x6fbc04 */);
    // 004374bc  a314395f00             -mov dword ptr [0x5f3914], eax
    app->getMemory<x86::reg32>(x86::reg32(6240532) /* 0x5f3914 */) = cpu.eax;
    // 004374c1  a10cbc6f00             -mov eax, dword ptr [0x6fbc0c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7322636) /* 0x6fbc0c */);
    // 004374c6  a318395f00             -mov dword ptr [0x5f3918], eax
    app->getMemory<x86::reg32>(x86::reg32(6240536) /* 0x5f3918 */) = cpu.eax;
    // 004374cb  a108bc6f00             -mov eax, dword ptr [0x6fbc08]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7322632) /* 0x6fbc08 */);
    // 004374d0  a310395f00             -mov dword ptr [0x5f3910], eax
    app->getMemory<x86::reg32>(x86::reg32(6240528) /* 0x5f3910 */) = cpu.eax;
    // 004374d5  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004374d7  e838010000             -call 0x437614
    cpu.esp -= 4;
    sub_437614(app, cpu);
    if (cpu.terminate) return;
    // 004374dc  eb14                   -jmp 0x4374f2
    goto L_0x004374f2;
    // 004374de  90                     -nop 
    ;
    // 004374df  90                     -nop 
    ;
    // 004374e0  90                     -nop 
    ;
    // 004374e1  90                     -nop 
    ;
    // 004374e2  90                     -nop 
    ;
    // 004374e3  90                     -nop 
    ;
    // 004374e4  90                     -nop 
    ;
    // 004374e5  90                     -nop 
    ;
    // 004374e6  90                     -nop 
    ;
    // 004374e7  90                     -nop 
    ;
    // 004374e8  90                     -nop 
    ;
    // 004374e9  90                     -nop 
    ;
    // 004374ea  90                     -nop 
    ;
    // 004374eb  90                     -nop 
    ;
    // 004374ec  90                     -nop 
    ;
    // 004374ed  90                     -nop 
    ;
    // 004374ee  90                     -nop 
    ;
    // 004374ef  90                     -nop 
    ;
    // 004374f0  90                     -nop 
    ;
    // 004374f1  90                     -nop 
    ;
L_0x004374f2:
    // 004374f2  ba9c745300             -mov edx, 0x53749c
    cpu.edx = 5469340 /*0x53749c*/;
    // 004374f7  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004374f9  e842b50000             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 004374fe  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00437500  7407                   -je 0x437509
    if (cpu.flags.zf)
    {
        goto L_0x00437509;
    }
    // 00437502  c7403000734300         -mov dword ptr [eax + 0x30], 0x437300
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(48) /* 0x30 */) = 4420352 /*0x437300*/;
L_0x00437509:
    // 00437509  baac745300             -mov edx, 0x5374ac
    cpu.edx = 5469356 /*0x5374ac*/;
    // 0043750e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00437510  e82bb50000             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 00437515  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00437517  7407                   -je 0x437520
    if (cpu.flags.zf)
    {
        goto L_0x00437520;
    }
    // 00437519  c7403050734300         -mov dword ptr [eax + 0x30], 0x437350
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(48) /* 0x30 */) = 4420432 /*0x437350*/;
L_0x00437520:
    // 00437520  babc745300             -mov edx, 0x5374bc
    cpu.edx = 5469372 /*0x5374bc*/;
    // 00437525  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00437527  e814b50000             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 0043752c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043752e  7407                   -je 0x437537
    if (cpu.flags.zf)
    {
        goto L_0x00437537;
    }
    // 00437530  c7403090734300         -mov dword ptr [eax + 0x30], 0x437390
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(48) /* 0x30 */) = 4420496 /*0x437390*/;
L_0x00437537:
    // 00437537  bacc745300             -mov edx, 0x5374cc
    cpu.edx = 5469388 /*0x5374cc*/;
    // 0043753c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0043753e  e8fdb40000             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 00437543  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00437545  7407                   -je 0x43754e
    if (cpu.flags.zf)
    {
        goto L_0x0043754e;
    }
    // 00437547  c74030e0734300         -mov dword ptr [eax + 0x30], 0x4373e0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(48) /* 0x30 */) = 4420576 /*0x4373e0*/;
L_0x0043754e:
    // 0043754e  badc745300             -mov edx, 0x5374dc
    cpu.edx = 5469404 /*0x5374dc*/;
    // 00437553  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00437555  e8e6b40000             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 0043755a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043755c  7407                   -je 0x437565
    if (cpu.flags.zf)
    {
        goto L_0x00437565;
    }
    // 0043755e  c7403020744300         -mov dword ptr [eax + 0x30], 0x437420
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(48) /* 0x30 */) = 4420640 /*0x437420*/;
L_0x00437565:
    // 00437565  bae8745300             -mov edx, 0x5374e8
    cpu.edx = 5469416 /*0x5374e8*/;
    // 0043756a  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0043756c  e8cfb40000             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 00437571  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00437573  7407                   -je 0x43757c
    if (cpu.flags.zf)
    {
        goto L_0x0043757c;
    }
    // 00437575  c7403070744300         -mov dword ptr [eax + 0x30], 0x437470
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(48) /* 0x30 */) = 4420720 /*0x437470*/;
L_0x0043757c:
    // 0043757c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0043757e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043757f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00437580  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00437581  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_437590(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00437590  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00437591  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00437592  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00437594  8b5018                 -mov edx, dword ptr [eax + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 00437597  8b4016                 -mov eax, dword ptr [eax + 0x16]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(22) /* 0x16 */);
    // 0043759a  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0043759d  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004375a0  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004375a2  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 004375a9  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004375ab  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 004375ae  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004375b0  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004375b3  05e04e6000             -add eax, 0x604ee0
    (cpu.eax) += x86::reg32(x86::sreg32(6311648 /*0x604ee0*/));
    // 004375b8  833805                 +cmp dword ptr [eax], 5
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5 /*0x5*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004375bb  7534                   -jne 0x4375f1
    if (!cpu.flags.zf)
    {
        goto L_0x004375f1;
    }
    // 004375bd  baf4745300             -mov edx, 0x5374f4
    cpu.edx = 5469428 /*0x5374f4*/;
    // 004375c2  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004375c5  e8f6b30000             -call 0x4429c0
    cpu.esp -= 4;
    sub_4429c0(app, cpu);
    if (cpu.terminate) return;
    // 004375ca  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004375cc  7423                   -je 0x4375f1
    if (cpu.flags.zf)
    {
        goto L_0x004375f1;
    }
    // 004375ce  a114395f00             -mov eax, dword ptr [0x5f3914]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6240532) /* 0x5f3914 */);
    // 004375d3  a304bc6f00             -mov dword ptr [0x6fbc04], eax
    app->getMemory<x86::reg32>(x86::reg32(7322628) /* 0x6fbc04 */) = cpu.eax;
    // 004375d8  a118395f00             -mov eax, dword ptr [0x5f3918]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6240536) /* 0x5f3918 */);
    // 004375dd  a30cbc6f00             -mov dword ptr [0x6fbc0c], eax
    app->getMemory<x86::reg32>(x86::reg32(7322636) /* 0x6fbc0c */) = cpu.eax;
    // 004375e2  a110395f00             -mov eax, dword ptr [0x5f3910]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6240528) /* 0x5f3910 */);
    // 004375e7  a308bc6f00             -mov dword ptr [0x6fbc08], eax
    app->getMemory<x86::reg32>(x86::reg32(7322632) /* 0x6fbc08 */) = cpu.eax;
    // 004375ec  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004375ee  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004375ef  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004375f0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004375f1:
    // 004375f1  e85afcffff             -call 0x437250
    cpu.esp -= 4;
    sub_437250(app, cpu);
    if (cpu.terminate) return;
    // 004375f6  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004375f8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004375f9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004375fa  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_437600(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00437600  c705689c550001000000   -mov dword ptr [0x559c68], 1
    app->getMemory<x86::reg32>(x86::reg32(5610600) /* 0x559c68 */) = 1 /*0x1*/;
    // 0043760a  e805000000             -call 0x437614
    cpu.esp -= 4;
    sub_437614(app, cpu);
    if (cpu.terminate) return;
    // 0043760f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00437611  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_437612(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00437612  90                     -nop 
    ;
    // 00437613  90                     -nop 
    ;
    // 00437614  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00437616  740a                   -je 0x437622
    if (cpu.flags.zf)
    {
        goto L_0x00437622;
    }
    // 00437618  833d3492550000         +cmp dword ptr [0x559234], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5607988) /* 0x559234 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043761f  7401                   -je 0x437622
    if (cpu.flags.zf)
    {
        goto L_0x00437622;
    }
    // 00437621  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00437622:
    // 00437622  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 00437623  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00437625  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00437627  ba98a95300             -mov edx, 0x53a998
    cpu.edx = 5482904 /*0x53a998*/;
    // 0043762c  e80fb40000             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 00437631  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00437633  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00437635  7406                   -je 0x43763d
    if (cpu.flags.zf)
    {
        goto L_0x0043763d;
    }
    // 00437637  66814f040110           -or word ptr [edi + 4], 0x1001
    app->getMemory<x86::reg16>(cpu.edi + x86::reg32(4) /* 0x4 */) |= x86::reg16(x86::sreg16(4097 /*0x1001*/));
L_0x0043763d:
    // 0043763d  833d6c277a0000         +cmp dword ptr [0x7a276c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(8005484) /* 0x7a276c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00437644  7548                   -jne 0x43768e
    if (!cpu.flags.zf)
    {
        goto L_0x0043768e;
    }
    // 00437646  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00437648  ba90a95300             -mov edx, 0x53a990
    cpu.edx = 5482896 /*0x53a990*/;
    // 0043764d  e8eeb30000             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 00437652  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00437654  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00437656  ba4c715300             -mov edx, 0x53714c
    cpu.edx = 5468492 /*0x53714c*/;
    // 0043765b  e8e0b30000             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 00437660  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00437662  750a                   -jne 0x43766e
    if (!cpu.flags.zf)
    {
        goto L_0x0043766e;
    }
    // 00437664  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00437666  7424                   -je 0x43768c
    if (cpu.flags.zf)
    {
        goto L_0x0043768c;
    }
    // 00437668  80480401               +or byte ptr [eax + 4], 1
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/))));
    // 0043766c  eb1e                   -jmp 0x43768c
    goto L_0x0043768c;
L_0x0043766e:
    // 0043766e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00437670  7406                   -je 0x437678
    if (cpu.flags.zf)
    {
        goto L_0x00437678;
    }
    // 00437672  668148040110           -or word ptr [eax + 4], 0x1001
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(4) /* 0x4 */) |= x86::reg16(x86::sreg16(4097 /*0x1001*/));
L_0x00437678:
    // 00437678  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0043767a  7406                   -je 0x437682
    if (cpu.flags.zf)
    {
        goto L_0x00437682;
    }
    // 0043767c  66814e040110           -or word ptr [esi + 4], 0x1001
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(4) /* 0x4 */) |= x86::reg16(x86::sreg16(4097 /*0x1001*/));
L_0x00437682:
    // 00437682  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00437684  7406                   -je 0x43768c
    if (cpu.flags.zf)
    {
        goto L_0x0043768c;
    }
    // 00437686  66816704feef           +and word ptr [edi + 4], 0xeffe
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg16>(cpu.edi + x86::reg32(4) /* 0x4 */) &= x86::reg16(x86::sreg16(61438 /*0xeffe*/))));
L_0x0043768c:
    // 0043768c  eb6b                   -jmp 0x4376f9
    goto L_0x004376f9;
L_0x0043768e:
    // 0043768e  833db0d36f0001         +cmp dword ptr [0x6fd3b0], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(7328688) /* 0x6fd3b0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00437695  7e14                   -jle 0x4376ab
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004376ab;
    }
    // 00437697  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00437699  ba94745300             -mov edx, 0x537494
    cpu.edx = 5469332 /*0x537494*/;
    // 0043769e  e89db30000             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 004376a3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004376a5  7404                   -je 0x4376ab
    if (cpu.flags.zf)
    {
        goto L_0x004376ab;
    }
    // 004376a7  80480401               -or byte ptr [eax + 4], 1
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x004376ab:
    // 004376ab  833d6829660000         +cmp dword ptr [0x662968], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(6695272) /* 0x662968 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004376b2  7445                   -je 0x4376f9
    if (cpu.flags.zf)
    {
        goto L_0x004376f9;
    }
    // 004376b4  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004376b6  ba4c715300             -mov edx, 0x53714c
    cpu.edx = 5468492 /*0x53714c*/;
    // 004376bb  e880b30000             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 004376c0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004376c2  7435                   -je 0x4376f9
    if (cpu.flags.zf)
    {
        goto L_0x004376f9;
    }
    // 004376c4  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004376c6  e8c5790900             -call 0x4cf090
    cpu.esp -= 4;
    sub_4cf090(app, cpu);
    if (cpu.terminate) return;
    // 004376cb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004376cd  7504                   -jne 0x4376d3
    if (!cpu.flags.zf)
    {
        goto L_0x004376d3;
    }
    // 004376cf  80490401               -or byte ptr [ecx + 4], 1
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x004376d3:
    // 004376d3  833db8d36f0001         +cmp dword ptr [0x6fd3b8], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(7328696) /* 0x6fd3b8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004376da  7410                   -je 0x4376ec
    if (cpu.flags.zf)
    {
        goto L_0x004376ec;
    }
    // 004376dc  833db8d36f0002         +cmp dword ptr [0x6fd3b8], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(7328696) /* 0x6fd3b8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004376e3  7407                   -je 0x4376ec
    if (cpu.flags.zf)
    {
        goto L_0x004376ec;
    }
    // 004376e5  b8f2000000             -mov eax, 0xf2
    cpu.eax = 242 /*0xf2*/;
    // 004376ea  eb05                   -jmp 0x4376f1
    goto L_0x004376f1;
L_0x004376ec:
    // 004376ec  b8f1000000             -mov eax, 0xf1
    cpu.eax = 241 /*0xf1*/;
L_0x004376f1:
    // 004376f1  e85aa10900             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 004376f6  89413c                 -mov dword ptr [ecx + 0x3c], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(60) /* 0x3c */) = cpu.eax;
L_0x004376f9:
    // 004376f9  61                     -popal 
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
    // 004376fa  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_437614(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00437614;
    // 00437612  90                     -nop 
    ;
    // 00437613  90                     -nop 
    ;
L_entry_0x00437614:
    // 00437614  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00437616  740a                   -je 0x437622
    if (cpu.flags.zf)
    {
        goto L_0x00437622;
    }
    // 00437618  833d3492550000         +cmp dword ptr [0x559234], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5607988) /* 0x559234 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043761f  7401                   -je 0x437622
    if (cpu.flags.zf)
    {
        goto L_0x00437622;
    }
    // 00437621  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00437622:
    // 00437622  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 00437623  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00437625  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00437627  ba98a95300             -mov edx, 0x53a998
    cpu.edx = 5482904 /*0x53a998*/;
    // 0043762c  e80fb40000             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 00437631  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00437633  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00437635  7406                   -je 0x43763d
    if (cpu.flags.zf)
    {
        goto L_0x0043763d;
    }
    // 00437637  66814f040110           -or word ptr [edi + 4], 0x1001
    app->getMemory<x86::reg16>(cpu.edi + x86::reg32(4) /* 0x4 */) |= x86::reg16(x86::sreg16(4097 /*0x1001*/));
L_0x0043763d:
    // 0043763d  833d6c277a0000         +cmp dword ptr [0x7a276c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(8005484) /* 0x7a276c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00437644  7548                   -jne 0x43768e
    if (!cpu.flags.zf)
    {
        goto L_0x0043768e;
    }
    // 00437646  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00437648  ba90a95300             -mov edx, 0x53a990
    cpu.edx = 5482896 /*0x53a990*/;
    // 0043764d  e8eeb30000             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 00437652  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00437654  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00437656  ba4c715300             -mov edx, 0x53714c
    cpu.edx = 5468492 /*0x53714c*/;
    // 0043765b  e8e0b30000             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 00437660  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00437662  750a                   -jne 0x43766e
    if (!cpu.flags.zf)
    {
        goto L_0x0043766e;
    }
    // 00437664  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00437666  7424                   -je 0x43768c
    if (cpu.flags.zf)
    {
        goto L_0x0043768c;
    }
    // 00437668  80480401               +or byte ptr [eax + 4], 1
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/))));
    // 0043766c  eb1e                   -jmp 0x43768c
    goto L_0x0043768c;
L_0x0043766e:
    // 0043766e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00437670  7406                   -je 0x437678
    if (cpu.flags.zf)
    {
        goto L_0x00437678;
    }
    // 00437672  668148040110           -or word ptr [eax + 4], 0x1001
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(4) /* 0x4 */) |= x86::reg16(x86::sreg16(4097 /*0x1001*/));
L_0x00437678:
    // 00437678  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0043767a  7406                   -je 0x437682
    if (cpu.flags.zf)
    {
        goto L_0x00437682;
    }
    // 0043767c  66814e040110           -or word ptr [esi + 4], 0x1001
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(4) /* 0x4 */) |= x86::reg16(x86::sreg16(4097 /*0x1001*/));
L_0x00437682:
    // 00437682  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00437684  7406                   -je 0x43768c
    if (cpu.flags.zf)
    {
        goto L_0x0043768c;
    }
    // 00437686  66816704feef           +and word ptr [edi + 4], 0xeffe
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg16>(cpu.edi + x86::reg32(4) /* 0x4 */) &= x86::reg16(x86::sreg16(61438 /*0xeffe*/))));
L_0x0043768c:
    // 0043768c  eb6b                   -jmp 0x4376f9
    goto L_0x004376f9;
L_0x0043768e:
    // 0043768e  833db0d36f0001         +cmp dword ptr [0x6fd3b0], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(7328688) /* 0x6fd3b0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00437695  7e14                   -jle 0x4376ab
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004376ab;
    }
    // 00437697  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00437699  ba94745300             -mov edx, 0x537494
    cpu.edx = 5469332 /*0x537494*/;
    // 0043769e  e89db30000             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 004376a3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004376a5  7404                   -je 0x4376ab
    if (cpu.flags.zf)
    {
        goto L_0x004376ab;
    }
    // 004376a7  80480401               -or byte ptr [eax + 4], 1
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x004376ab:
    // 004376ab  833d6829660000         +cmp dword ptr [0x662968], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(6695272) /* 0x662968 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004376b2  7445                   -je 0x4376f9
    if (cpu.flags.zf)
    {
        goto L_0x004376f9;
    }
    // 004376b4  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004376b6  ba4c715300             -mov edx, 0x53714c
    cpu.edx = 5468492 /*0x53714c*/;
    // 004376bb  e880b30000             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 004376c0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004376c2  7435                   -je 0x4376f9
    if (cpu.flags.zf)
    {
        goto L_0x004376f9;
    }
    // 004376c4  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004376c6  e8c5790900             -call 0x4cf090
    cpu.esp -= 4;
    sub_4cf090(app, cpu);
    if (cpu.terminate) return;
    // 004376cb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004376cd  7504                   -jne 0x4376d3
    if (!cpu.flags.zf)
    {
        goto L_0x004376d3;
    }
    // 004376cf  80490401               -or byte ptr [ecx + 4], 1
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x004376d3:
    // 004376d3  833db8d36f0001         +cmp dword ptr [0x6fd3b8], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(7328696) /* 0x6fd3b8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004376da  7410                   -je 0x4376ec
    if (cpu.flags.zf)
    {
        goto L_0x004376ec;
    }
    // 004376dc  833db8d36f0002         +cmp dword ptr [0x6fd3b8], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(7328696) /* 0x6fd3b8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004376e3  7407                   -je 0x4376ec
    if (cpu.flags.zf)
    {
        goto L_0x004376ec;
    }
    // 004376e5  b8f2000000             -mov eax, 0xf2
    cpu.eax = 242 /*0xf2*/;
    // 004376ea  eb05                   -jmp 0x4376f1
    goto L_0x004376f1;
L_0x004376ec:
    // 004376ec  b8f1000000             -mov eax, 0xf1
    cpu.eax = 241 /*0xf1*/;
L_0x004376f1:
    // 004376f1  e85aa10900             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 004376f6  89413c                 -mov dword ptr [ecx + 0x3c], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(60) /* 0x3c */) = cpu.eax;
L_0x004376f9:
    // 004376f9  61                     -popal 
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
    // 004376fa  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4376fc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004376fc  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 004376fd  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004376ff  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00437702  ba848f5300             -mov edx, 0x538f84
    cpu.edx = 5476228 /*0x538f84*/;
    // 00437707  e834b30000             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 0043770c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043770e  7429                   -je 0x437739
    if (cpu.flags.zf)
    {
        goto L_0x00437739;
    }
    // 00437710  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00437712  db05d0d16f00           -fild dword ptr [0x6fd1d0]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(7328208) /* 0x6fd1d0 */))));
    // 00437718  dc0d00765300           -fmul qword ptr [0x537600]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5469696) /* 0x537600 */));
    // 0043771e  d95dfc                 -fstp dword ptr [ebp - 4]
    app->getMemory<float>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00437721  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00437723  ff75fc                 -push dword ptr [ebp - 4]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    cpu.esp -= 4;
    // 00437726  e825520300             -call 0x46c950
    cpu.esp -= 4;
    sub_46c950(app, cpu);
    if (cpu.terminate) return;
    // 0043772b  c7422c58774300         -mov dword ptr [edx + 0x2c], 0x437758
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(44) /* 0x2c */) = 4421464 /*0x437758*/;
    // 00437732  c7427840774300         -mov dword ptr [edx + 0x78], 0x437740
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(120) /* 0x78 */) = 4421440 /*0x437740*/;
L_0x00437739:
    // 00437739  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0043773b  61                     -popal 
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
    // 0043773c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_43773e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043773e  90                     -nop 
    ;
    // 0043773f  90                     -nop 
    ;
    // 00437740  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00437741  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00437743  e868520300             -call 0x46c9b0
    cpu.esp -= 4;
    sub_46c9b0(app, cpu);
    if (cpu.terminate) return;
    // 00437748  dc0d98755300           -fmul qword ptr [0x537598]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5469592) /* 0x537598 */));
    // 0043774e  db1dd0d16f00           -fistp dword ptr [0x6fd1d0]
    app->getMemory<x86::reg32>(x86::reg32(7328208) /* 0x6fd1d0 */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 00437754  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00437755  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_437756(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00437756  90                     -nop 
    ;
    // 00437757  90                     -nop 
    ;
    // 00437758  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 00437759  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0043775b  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0043775d  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0043775f  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00437761  741b                   -je 0x43777e
    if (cpu.flags.zf)
    {
        goto L_0x0043777e;
    }
    // 00437763  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00437765  b001                   -mov al, 1
    cpu.al = 1 /*0x1*/;
    // 00437767  8b0da4c17900           -mov ecx, dword ptr [0x79c1a4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(7979428) /* 0x79c1a4 */);
    // 0043776d  2b0c8550476600         -sub ecx, dword ptr [eax*4 + 0x664750]
    (cpu.ecx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(6702928) /* 0x664750 */ + cpu.eax * 4)));
    // 00437774  83f930                 +cmp ecx, 0x30
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(48 /*0x30*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00437777  7205                   -jb 0x43777e
    if (cpu.flags.cf)
    {
        goto L_0x0043777e;
    }
    // 00437779  e8520afeff             -call 0x4181d0
    cpu.esp -= 4;
    sub_4181d0(app, cpu);
    if (cpu.terminate) return;
L_0x0043777e:
    // 0043777e  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00437780  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00437782  e859530300             -call 0x46cae0
    cpu.esp -= 4;
    sub_46cae0(app, cpu);
    if (cpu.terminate) return;
    // 00437787  89451c                 -mov dword ptr [ebp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 0043778a  61                     -popal 
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
    // 0043778b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_43778c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043778c  e82fb20000             -call 0x4429c0
    cpu.esp -= 4;
    sub_4429c0(app, cpu);
    if (cpu.terminate) return;
    // 00437791  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00437792  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00437794  7515                   -jne 0x4377ab
    if (!cpu.flags.zf)
    {
        goto L_0x004377ab;
    }
    // 00437796  833d543a7a0000         +cmp dword ptr [0x7a3a54], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(8010324) /* 0x7a3a54 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043779d  750a                   -jne 0x4377a9
    if (!cpu.flags.zf)
    {
        goto L_0x004377a9;
    }
    // 0043779f  a184466600             -mov eax, dword ptr [0x664684]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6702724) /* 0x664684 */);
    // 004377a4  a3d4d16f00             -mov dword ptr [0x6fd1d4], eax
    app->getMemory<x86::reg32>(x86::reg32(7328212) /* 0x6fd1d4 */) = cpu.eax;
L_0x004377a9:
    // 004377a9  eb14                   -jmp 0x4377bf
    goto L_0x004377bf;
L_0x004377ab:
    // 004377ab  a188466600             -mov eax, dword ptr [0x664688]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6702728) /* 0x664688 */);
    // 004377b0  a3d8d16f00             -mov dword ptr [0x6fd1d8], eax
    app->getMemory<x86::reg32>(x86::reg32(7328216) /* 0x6fd1d8 */) = cpu.eax;
    // 004377b5  a184466600             -mov eax, dword ptr [0x664684]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6702724) /* 0x664684 */);
    // 004377ba  a3d4d16f00             -mov dword ptr [0x6fd1d4], eax
    app->getMemory<x86::reg32>(x86::reg32(7328212) /* 0x6fd1d4 */) = cpu.eax;
L_0x004377bf:
    // 004377bf  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004377c0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4377c2(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004377c2  90                     -nop 
    ;
    // 004377c3  90                     -nop 
    ;
    // 004377c4  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 004377c5  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004377c7  a1d8d16f00             -mov eax, dword ptr [0x6fd1d8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7328216) /* 0x6fd1d8 */);
    // 004377cc  a388466600             -mov dword ptr [0x664688], eax
    app->getMemory<x86::reg32>(x86::reg32(6702728) /* 0x664688 */) = cpu.eax;
    // 004377d1  a1d4d16f00             -mov eax, dword ptr [0x6fd1d4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7328212) /* 0x6fd1d4 */);
    // 004377d6  a384466600             -mov dword ptr [0x664684], eax
    app->getMemory<x86::reg32>(x86::reg32(6702724) /* 0x664684 */) = cpu.eax;
    // 004377db  8b0d543a7a00           -mov ecx, dword ptr [0x7a3a54]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(8010324) /* 0x7a3a54 */);
    // 004377e1  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004377e3  7506                   -jne 0x4377eb
    if (!cpu.flags.zf)
    {
        goto L_0x004377eb;
    }
    // 004377e5  890dd4d16f00           -mov dword ptr [0x6fd1d4], ecx
    app->getMemory<x86::reg32>(x86::reg32(7328212) /* 0x6fd1d4 */) = cpu.ecx;
L_0x004377eb:
    // 004377eb  b8208a5300             -mov eax, 0x538a20
    cpu.eax = 5474848 /*0x538a20*/;
    // 004377f0  e80c000000             -call 0x437801
    cpu.esp -= 4;
    sub_437801(app, cpu);
    if (cpu.terminate) return;
    // 004377f5  b82c8a5300             -mov eax, 0x538a2c
    cpu.eax = 5474860 /*0x538a2c*/;
    // 004377fa  e802000000             -call 0x437801
    cpu.esp -= 4;
    sub_437801(app, cpu);
    if (cpu.terminate) return;
    // 004377ff  61                     -popal 
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
    // 00437800  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4377c4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004377c4;
    // 004377c2  90                     -nop 
    ;
    // 004377c3  90                     -nop 
    ;
L_entry_0x004377c4:
    // 004377c4  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 004377c5  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004377c7  a1d8d16f00             -mov eax, dword ptr [0x6fd1d8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7328216) /* 0x6fd1d8 */);
    // 004377cc  a388466600             -mov dword ptr [0x664688], eax
    app->getMemory<x86::reg32>(x86::reg32(6702728) /* 0x664688 */) = cpu.eax;
    // 004377d1  a1d4d16f00             -mov eax, dword ptr [0x6fd1d4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7328212) /* 0x6fd1d4 */);
    // 004377d6  a384466600             -mov dword ptr [0x664684], eax
    app->getMemory<x86::reg32>(x86::reg32(6702724) /* 0x664684 */) = cpu.eax;
    // 004377db  8b0d543a7a00           -mov ecx, dword ptr [0x7a3a54]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(8010324) /* 0x7a3a54 */);
    // 004377e1  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004377e3  7506                   -jne 0x4377eb
    if (!cpu.flags.zf)
    {
        goto L_0x004377eb;
    }
    // 004377e5  890dd4d16f00           -mov dword ptr [0x6fd1d4], ecx
    app->getMemory<x86::reg32>(x86::reg32(7328212) /* 0x6fd1d4 */) = cpu.ecx;
L_0x004377eb:
    // 004377eb  b8208a5300             -mov eax, 0x538a20
    cpu.eax = 5474848 /*0x538a20*/;
    // 004377f0  e80c000000             -call 0x437801
    cpu.esp -= 4;
    sub_437801(app, cpu);
    if (cpu.terminate) return;
    // 004377f5  b82c8a5300             -mov eax, 0x538a2c
    cpu.eax = 5474860 /*0x538a2c*/;
    // 004377fa  e802000000             -call 0x437801
    cpu.esp -= 4;
    sub_437801(app, cpu);
    if (cpu.terminate) return;
    // 004377ff  61                     -popal 
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
    // 00437800  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_437801(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00437801  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00437803  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00437805  e836b20000             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 0043780a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043780c  740e                   -je 0x43781c
    if (cpu.flags.zf)
    {
        goto L_0x0043781c;
    }
    // 0043780e  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00437810  7406                   -je 0x437818
    if (cpu.flags.zf)
    {
        goto L_0x00437818;
    }
    // 00437812  806004fe               +and byte ptr [eax + 4], 0xfe
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) &= x86::reg8(x86::sreg8(254 /*0xfe*/))));
    // 00437816  eb04                   -jmp 0x43781c
    goto L_0x0043781c;
L_0x00437818:
    // 00437818  80480401               -or byte ptr [eax + 4], 1
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x0043781c:
    // 0043781c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_43781e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043781e  90                     -nop 
    ;
    // 0043781f  90                     -nop 
    ;
    // 00437820  a1285c5500             -mov eax, dword ptr [0x555c28]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5594152) /* 0x555c28 */);
    // 00437825  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00437828  8b805c575500           -mov eax, dword ptr [eax + 0x55575c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5592924) /* 0x55575c */);
    // 0043782e  e825a70b00             -call 0x4f1f58
    cpu.esp -= 4;
    sub_4f1f58(app, cpu);
    if (cpu.terminate) return;
    // 00437833  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00437835  0f847da90000           -je 0x4421b8
    if (cpu.flags.zf)
    {
        return sub_4421b8(app, cpu);
    }
    // 0043783b  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0043783d  e8ceae0b00             -call 0x4f2710
    cpu.esp -= 4;
    sub_4f2710(app, cpu);
    if (cpu.terminate) return;
    // 00437842  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00437844  0f846ea90000           -je 0x4421b8
    if (cpu.flags.zf)
    {
        return sub_4421b8(app, cpu);
    }
    // 0043784a  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
    // 0043784f  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00437851  b830945400             -mov eax, 0x549430
    cpu.eax = 5542960 /*0x549430*/;
    // 00437856  e8c59d0a00             -call 0x4e1620
    cpu.esp -= 4;
    sub_4e1620(app, cpu);
    if (cpu.terminate) return;
    // 0043785b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043785d  0f8455a90000           -je 0x4421b8
    if (cpu.flags.zf)
    {
        return sub_4421b8(app, cpu);
    }
    // 00437863  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00437865  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00437867  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00437869  e8b2ad0b00             -call 0x4f2620
    cpu.esp -= 4;
    sub_4f2620(app, cpu);
    if (cpu.terminate) return;
    // 0043786e  a1285c5500             -mov eax, dword ptr [0x555c28]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5594152) /* 0x555c28 */);
    // 00437873  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00437876  8b9060575500           -mov edx, dword ptr [eax + 0x555760]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5592928) /* 0x555760 */);
    // 0043787c  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0043787e  e85d790b00             -call 0x4ef1e0
    cpu.esp -= 4;
    sub_4ef1e0(app, cpu);
    if (cpu.terminate) return;
    // 00437883  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00437885  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00437887  668b4606               -mov ax, word ptr [esi + 6]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(6) /* 0x6 */);
    // 0043788b  bb40010000             -mov ebx, 0x140
    cpu.ebx = 320 /*0x140*/;
    // 00437890  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00437892  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 00437894  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00437896  668b4604               -mov ax, word ptr [esi + 4]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0043789a  ba60020000             -mov edx, 0x260
    cpu.edx = 608 /*0x260*/;
    // 0043789f  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004378a1  d1ea                   +shr edx, 1
    {
        x86::reg32 tmp = 1 /*0x1*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 004378a3  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004378a5  e8467b0b00             -call 0x4ef3f0
    cpu.esp -= 4;
    sub_4ef3f0(app, cpu);
    if (cpu.terminate) return;
    // 004378aa  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004378ac  e8df9f0a00             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
    // 004378b1  e902a90000             -jmp 0x4421b8
    return sub_4421b8(app, cpu);
}

/* align: skip  */
void Application::sub_437820(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00437820;
    // 0043781e  90                     -nop 
    ;
    // 0043781f  90                     -nop 
    ;
L_entry_0x00437820:
    // 00437820  a1285c5500             -mov eax, dword ptr [0x555c28]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5594152) /* 0x555c28 */);
    // 00437825  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00437828  8b805c575500           -mov eax, dword ptr [eax + 0x55575c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5592924) /* 0x55575c */);
    // 0043782e  e825a70b00             -call 0x4f1f58
    cpu.esp -= 4;
    sub_4f1f58(app, cpu);
    if (cpu.terminate) return;
    // 00437833  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00437835  0f847da90000           -je 0x4421b8
    if (cpu.flags.zf)
    {
        return sub_4421b8(app, cpu);
    }
    // 0043783b  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0043783d  e8ceae0b00             -call 0x4f2710
    cpu.esp -= 4;
    sub_4f2710(app, cpu);
    if (cpu.terminate) return;
    // 00437842  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00437844  0f846ea90000           -je 0x4421b8
    if (cpu.flags.zf)
    {
        return sub_4421b8(app, cpu);
    }
    // 0043784a  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
    // 0043784f  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00437851  b830945400             -mov eax, 0x549430
    cpu.eax = 5542960 /*0x549430*/;
    // 00437856  e8c59d0a00             -call 0x4e1620
    cpu.esp -= 4;
    sub_4e1620(app, cpu);
    if (cpu.terminate) return;
    // 0043785b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043785d  0f8455a90000           -je 0x4421b8
    if (cpu.flags.zf)
    {
        return sub_4421b8(app, cpu);
    }
    // 00437863  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00437865  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00437867  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00437869  e8b2ad0b00             -call 0x4f2620
    cpu.esp -= 4;
    sub_4f2620(app, cpu);
    if (cpu.terminate) return;
    // 0043786e  a1285c5500             -mov eax, dword ptr [0x555c28]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5594152) /* 0x555c28 */);
    // 00437873  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00437876  8b9060575500           -mov edx, dword ptr [eax + 0x555760]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5592928) /* 0x555760 */);
    // 0043787c  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0043787e  e85d790b00             -call 0x4ef1e0
    cpu.esp -= 4;
    sub_4ef1e0(app, cpu);
    if (cpu.terminate) return;
    // 00437883  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00437885  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00437887  668b4606               -mov ax, word ptr [esi + 6]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(6) /* 0x6 */);
    // 0043788b  bb40010000             -mov ebx, 0x140
    cpu.ebx = 320 /*0x140*/;
    // 00437890  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00437892  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 00437894  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00437896  668b4604               -mov ax, word ptr [esi + 4]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0043789a  ba60020000             -mov edx, 0x260
    cpu.edx = 608 /*0x260*/;
    // 0043789f  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004378a1  d1ea                   +shr edx, 1
    {
        x86::reg32 tmp = 1 /*0x1*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 004378a3  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004378a5  e8467b0b00             -call 0x4ef3f0
    cpu.esp -= 4;
    sub_4ef3f0(app, cpu);
    if (cpu.terminate) return;
    // 004378aa  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004378ac  e8df9f0a00             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
    // 004378b1  e902a90000             -jmp 0x4421b8
    return sub_4421b8(app, cpu);
}

/* align: skip  */
void Application::sub_4378b6(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004378b6  90                     -nop 
    ;
    // 004378b7  90                     -nop 
    ;
    // 004378b8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004378b9  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004378ba  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004378bc  ba4c715300             -mov edx, 0x53714c
    cpu.edx = 5468492 /*0x53714c*/;
    // 004378c1  e8fab00000             -call 0x4429c0
    cpu.esp -= 4;
    sub_4429c0(app, cpu);
    if (cpu.terminate) return;
    // 004378c6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004378c8  750c                   -jne 0x4378d6
    if (!cpu.flags.zf)
    {
        goto L_0x004378d6;
    }
    // 004378ca  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004378cc  ba54715300             -mov edx, 0x537154
    cpu.edx = 5468500 /*0x537154*/;
    // 004378d1  e8eab00000             -call 0x4429c0
    cpu.esp -= 4;
    sub_4429c0(app, cpu);
    if (cpu.terminate) return;
L_0x004378d6:
    // 004378d6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004378d7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004378d8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4378b8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004378b8;
    // 004378b6  90                     -nop 
    ;
    // 004378b7  90                     -nop 
    ;
L_entry_0x004378b8:
    // 004378b8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004378b9  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004378ba  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004378bc  ba4c715300             -mov edx, 0x53714c
    cpu.edx = 5468492 /*0x53714c*/;
    // 004378c1  e8fab00000             -call 0x4429c0
    cpu.esp -= 4;
    sub_4429c0(app, cpu);
    if (cpu.terminate) return;
    // 004378c6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004378c8  750c                   -jne 0x4378d6
    if (!cpu.flags.zf)
    {
        goto L_0x004378d6;
    }
    // 004378ca  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004378cc  ba54715300             -mov edx, 0x537154
    cpu.edx = 5468500 /*0x537154*/;
    // 004378d1  e8eab00000             -call 0x4429c0
    cpu.esp -= 4;
    sub_4429c0(app, cpu);
    if (cpu.terminate) return;
L_0x004378d6:
    // 004378d6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004378d7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004378d8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4378da(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004378da  90                     -nop 
    ;
    // 004378db  90                     -nop 
    ;
    // 004378dc  90                     -nop 
    ;
    // 004378dd  90                     -nop 
    ;
    // 004378de  90                     -nop 
    ;
    // 004378df  90                     -nop 
    ;
    // 004378e0  90                     -nop 
    ;
    // 004378e1  90                     -nop 
    ;
    // 004378e2  90                     -nop 
    ;
    // 004378e3  90                     -nop 
    ;
    // 004378e4  90                     -nop 
    ;
    // 004378e5  90                     -nop 
    ;
    // 004378e6  90                     -nop 
    ;
    // 004378e7  90                     -nop 
    ;
    // 004378e8  90                     -nop 
    ;
    // 004378e9  90                     -nop 
    ;
    // 004378ea  90                     -nop 
    ;
    // 004378eb  90                     -nop 
    ;
    // 004378ec  90                     -nop 
    ;
    // 004378ed  90                     -nop 
    ;
    // 004378ee  90                     -nop 
    ;
    // 004378ef  90                     -nop 
    ;
    // 004378f0  90                     -nop 
    ;
    // 004378f1  90                     -nop 
    ;
    // 004378f2  90                     -nop 
    ;
    // 004378f3  90                     -nop 
    ;
    // 004378f4  90                     -nop 
    ;
    // 004378f5  90                     -nop 
    ;
    // 004378f6  90                     -nop 
    ;
    // 004378f7  90                     -nop 
    ;
    // 004378f8  90                     -nop 
    ;
    // 004378f9  90                     -nop 
    ;
    // 004378fa  90                     -nop 
    ;
    // 004378fb  90                     -nop 
    ;
    // 004378fc  90                     -nop 
    ;
    // 004378fd  90                     -nop 
    ;
    // 004378fe  90                     -nop 
    ;
    // 004378ff  90                     -nop 
    ;
    // 00437900  90                     -nop 
    ;
    // 00437901  90                     -nop 
    ;
    // 00437902  90                     -nop 
    ;
    // 00437903  90                     -nop 
    ;
    // 00437904  90                     -nop 
    ;
    // 00437905  90                     -nop 
    ;
    // 00437906  90                     -nop 
    ;
    // 00437907  90                     -nop 
    ;
    // 00437908  90                     -nop 
    ;
    // 00437909  90                     -nop 
    ;
    // 0043790a  90                     -nop 
    ;
    // 0043790b  90                     -nop 
    ;
    // 0043790c  90                     -nop 
    ;
    // 0043790d  90                     -nop 
    ;
    // 0043790e  90                     -nop 
    ;
    // 0043790f  90                     -nop 
    ;
    // 00437910  90                     -nop 
    ;
    // 00437911  90                     -nop 
    ;
    // 00437912  90                     -nop 
    ;
    // 00437913  90                     -nop 
    ;
    // 00437914  90                     -nop 
    ;
    // 00437915  90                     -nop 
    ;
    // 00437916  90                     -nop 
    ;
    // 00437917  90                     -nop 
    ;
    // 00437918  90                     -nop 
    ;
    // 00437919  90                     -nop 
    ;
    // 0043791a  90                     -nop 
    ;
    // 0043791b  90                     -nop 
    ;
    // 0043791c  90                     -nop 
    ;
    // 0043791d  90                     -nop 
    ;
    // 0043791e  90                     -nop 
    ;
    // 0043791f  90                     -nop 
    ;
    // 00437920  90                     -nop 
    ;
    // 00437921  90                     -nop 
    ;
    // 00437922  90                     -nop 
    ;
    // 00437923  90                     -nop 
    ;
    // 00437924  90                     -nop 
    ;
    // 00437925  90                     -nop 
    ;
    // 00437926  90                     -nop 
    ;
    // 00437927  90                     -nop 
    ;
    // 00437928  90                     -nop 
    ;
    // 00437929  90                     -nop 
    ;
    // 0043792a  90                     -nop 
    ;
    // 0043792b  90                     -nop 
    ;
    // 0043792c  90                     -nop 
    ;
    // 0043792d  90                     -nop 
    ;
    // 0043792e  90                     -nop 
    ;
    // 0043792f  90                     -nop 
    ;
    // 00437930  90                     -nop 
    ;
    // 00437931  90                     -nop 
    ;
    // 00437932  90                     -nop 
    ;
    // 00437933  90                     -nop 
    ;
    // 00437934  90                     -nop 
    ;
    // 00437935  90                     -nop 
    ;
    // 00437936  90                     -nop 
    ;
    // 00437937  90                     -nop 
    ;
    // 00437938  90                     -nop 
    ;
    // 00437939  90                     -nop 
    ;
    // 0043793a  90                     -nop 
    ;
    // 0043793b  90                     -nop 
    ;
    // 0043793c  90                     -nop 
    ;
    // 0043793d  90                     -nop 
    ;
    // 0043793e  90                     -nop 
    ;
    // 0043793f  90                     -nop 
    ;
    // 00437940  90                     -nop 
    ;
    // 00437941  90                     -nop 
    ;
    // 00437942  90                     -nop 
    ;
    // 00437943  90                     -nop 
    ;
    // 00437944  90                     -nop 
    ;
    // 00437945  90                     -nop 
    ;
    // 00437946  90                     -nop 
    ;
    // 00437947  90                     -nop 
    ;
    // 00437948  90                     -nop 
    ;
    // 00437949  90                     -nop 
    ;
    // 0043794a  90                     -nop 
    ;
    // 0043794b  90                     -nop 
    ;
    // 0043794c  90                     -nop 
    ;
    // 0043794d  90                     -nop 
    ;
    // 0043794e  90                     -nop 
    ;
    // 0043794f  90                     -nop 
    ;
    // 00437950  90                     -nop 
    ;
    // 00437951  90                     -nop 
    ;
    // 00437952  90                     -nop 
    ;
    // 00437953  90                     -nop 
    ;
    // 00437954  90                     -nop 
    ;
    // 00437955  90                     -nop 
    ;
    // 00437956  90                     -nop 
    ;
    // 00437957  90                     -nop 
    ;
    // 00437958  90                     -nop 
    ;
    // 00437959  90                     -nop 
    ;
    // 0043795a  90                     -nop 
    ;
    // 0043795b  90                     -nop 
    ;
    // 0043795c  90                     -nop 
    ;
    // 0043795d  90                     -nop 
    ;
    // 0043795e  90                     -nop 
    ;
    // 0043795f  90                     -nop 
    ;
    // 00437960  90                     -nop 
    ;
    // 00437961  90                     -nop 
    ;
    // 00437962  90                     -nop 
    ;
    // 00437963  90                     -nop 
    ;
    // 00437964  90                     -nop 
    ;
    // 00437965  90                     -nop 
    ;
    // 00437966  90                     -nop 
    ;
    // 00437967  90                     -nop 
    ;
    // 00437968  90                     -nop 
    ;
    // 00437969  90                     -nop 
    ;
    // 0043796a  90                     -nop 
    ;
    // 0043796b  90                     -nop 
    ;
    // 0043796c  90                     -nop 
    ;
    // 0043796d  90                     -nop 
    ;
    // 0043796e  90                     -nop 
    ;
    // 0043796f  90                     -nop 
    ;
    // 00437970  90                     -nop 
    ;
    // 00437971  90                     -nop 
    ;
    // 00437972  90                     -nop 
    ;
    // 00437973  90                     -nop 
    ;
    // 00437974  90                     -nop 
    ;
    // 00437975  90                     -nop 
    ;
    // 00437976  90                     -nop 
    ;
    // 00437977  90                     -nop 
    ;
    // 00437978  90                     -nop 
    ;
    // 00437979  90                     -nop 
    ;
    // 0043797a  90                     -nop 
    ;
    // 0043797b  90                     -nop 
    ;
    // 0043797c  90                     -nop 
    ;
    // 0043797d  90                     -nop 
    ;
    // 0043797e  90                     -nop 
    ;
    // 0043797f  90                     -nop 
    ;
    // 00437980  90                     -nop 
    ;
    // 00437981  90                     -nop 
    ;
    // 00437982  90                     -nop 
    ;
    // 00437983  90                     -nop 
    ;
    // 00437984  90                     -nop 
    ;
    // 00437985  90                     -nop 
    ;
    // 00437986  90                     -nop 
    ;
    // 00437987  90                     -nop 
    ;
    // 00437988  90                     -nop 
    ;
    // 00437989  90                     -nop 
    ;
    // 0043798a  90                     -nop 
    ;
    // 0043798b  90                     -nop 
    ;
    // 0043798c  90                     -nop 
    ;
    // 0043798d  90                     -nop 
    ;
    // 0043798e  90                     -nop 
    ;
    // 0043798f  90                     -nop 
    ;
    // 00437990  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00437991  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00437992  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00437994  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00437996  e815500300             -call 0x46c9b0
    cpu.esp -= 4;
    sub_46c9b0(app, cpu);
    if (cpu.terminate) return;
    // 0043799b  dc0d78755300           +fmul qword ptr [0x537578]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5469560) /* 0x537578 */));
    // 004379a1  eb03                   -jmp 0x4379a6
    return sub_4379a6(app, cpu);
}

/* align: skip 0x90 */
void Application::sub_4379a4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004379a4  90                     -nop 
    ;
    // 004379a5  90                     -nop 
    ;
    // 004379a6  db1de8bb6f00           -fistp dword ptr [0x6fbbe8]
    app->getMemory<x86::reg32>(x86::reg32(7322600) /* 0x6fbbe8 */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 004379ac  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004379ad  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004379ae  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4379a6(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004379a6;
    // 004379a4  90                     -nop 
    ;
    // 004379a5  90                     -nop 
    ;
L_entry_0x004379a6:
    // 004379a6  db1de8bb6f00           -fistp dword ptr [0x6fbbe8]
    app->getMemory<x86::reg32>(x86::reg32(7322600) /* 0x6fbbe8 */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 004379ac  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004379ad  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004379ae  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4379b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004379b0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004379b1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004379b2  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004379b4  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004379b6  e8f54f0300             -call 0x46c9b0
    cpu.esp -= 4;
    sub_46c9b0(app, cpu);
    if (cpu.terminate) return;
    // 004379bb  dc0d80755300           +fmul qword ptr [0x537580]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5469568) /* 0x537580 */));
    // 004379c1  eb03                   -jmp 0x4379c6
    return sub_4379c6(app, cpu);
}

/* align: skip 0x90 */
void Application::sub_4379c4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004379c4  90                     -nop 
    ;
    // 004379c5  90                     -nop 
    ;
    // 004379c6  db1df0bb6f00           -fistp dword ptr [0x6fbbf0]
    app->getMemory<x86::reg32>(x86::reg32(7322608) /* 0x6fbbf0 */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 004379cc  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004379cd  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004379ce  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4379c6(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004379c6;
    // 004379c4  90                     -nop 
    ;
    // 004379c5  90                     -nop 
    ;
L_entry_0x004379c6:
    // 004379c6  db1df0bb6f00           -fistp dword ptr [0x6fbbf0]
    app->getMemory<x86::reg32>(x86::reg32(7322608) /* 0x6fbbf0 */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 004379cc  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004379cd  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004379ce  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4379d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004379d0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004379d1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004379d2  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004379d4  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004379d7  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004379d9  e8d24f0300             -call 0x46c9b0
    cpu.esp -= 4;
    sub_46c9b0(app, cpu);
    if (cpu.terminate) return;
    // 004379de  8b1534925500           -mov edx, dword ptr [0x559234]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5607988) /* 0x559234 */);
    // 004379e4  d95dfc                 -fstp dword ptr [ebp - 4]
    app->getMemory<float>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004379e7  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004379e9  7519                   -jne 0x437a04
    if (!cpu.flags.zf)
    {
        goto L_0x00437a04;
    }
    // 004379eb  d945fc                 +fld dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-4) /* -0x4 */)));
    // 004379ee  dc0d88755300           +fmul qword ptr [0x537588]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5469576) /* 0x537588 */));
    // 004379f4  eb03                   -jmp 0x4379f9
    goto L_0x004379f9;
    // 004379f6  90                     -nop 
    ;
    // 004379f7  90                     -nop 
    ;
    // 004379f8  90                     -nop 
    ;
L_0x004379f9:
    // 004379f9  db1df4bb6f00           -fistp dword ptr [0x6fbbf4]
    app->getMemory<x86::reg32>(x86::reg32(7322612) /* 0x6fbbf4 */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 004379ff  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00437a01  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00437a02  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00437a03  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00437a04:
    // 00437a04  d945fc                 +fld dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-4) /* -0x4 */)));
    // 00437a07  dc0d88755300           +fmul qword ptr [0x537588]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5469576) /* 0x537588 */));
    // 00437a0d  eb03                   -jmp 0x437a12
    return sub_437a12(app, cpu);
}

/* align: skip 0x90 */
void Application::sub_437a10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00437a10  90                     -nop 
    ;
    // 00437a11  90                     -nop 
    ;
    // 00437a12  db1d20295500           -fistp dword ptr [0x552920]
    app->getMemory<x86::reg32>(x86::reg32(5581088) /* 0x552920 */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 00437a18  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00437a1a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00437a1b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00437a1c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_437a12(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00437a12;
    // 00437a10  90                     -nop 
    ;
    // 00437a11  90                     -nop 
    ;
L_entry_0x00437a12:
    // 00437a12  db1d20295500           -fistp dword ptr [0x552920]
    app->getMemory<x86::reg32>(x86::reg32(5581088) /* 0x552920 */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 00437a18  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00437a1a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00437a1b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00437a1c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_437a20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00437a20  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00437a21  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00437a22  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00437a24  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00437a27  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00437a29  e8824f0300             -call 0x46c9b0
    cpu.esp -= 4;
    sub_46c9b0(app, cpu);
    if (cpu.terminate) return;
    // 00437a2e  8b1534925500           -mov edx, dword ptr [0x559234]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5607988) /* 0x559234 */);
    // 00437a34  d95dfc                 -fstp dword ptr [ebp - 4]
    app->getMemory<float>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00437a37  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00437a39  7519                   -jne 0x437a54
    if (!cpu.flags.zf)
    {
        goto L_0x00437a54;
    }
    // 00437a3b  d945fc                 +fld dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-4) /* -0x4 */)));
    // 00437a3e  dc0d90755300           +fmul qword ptr [0x537590]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5469584) /* 0x537590 */));
    // 00437a44  eb03                   -jmp 0x437a49
    goto L_0x00437a49;
    // 00437a46  90                     -nop 
    ;
    // 00437a47  90                     -nop 
    ;
    // 00437a48  90                     -nop 
    ;
L_0x00437a49:
    // 00437a49  db1df8bb6f00           -fistp dword ptr [0x6fbbf8]
    app->getMemory<x86::reg32>(x86::reg32(7322616) /* 0x6fbbf8 */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 00437a4f  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00437a51  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00437a52  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00437a53  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00437a54:
    // 00437a54  d945fc                 +fld dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-4) /* -0x4 */)));
    // 00437a57  dc0d90755300           +fmul qword ptr [0x537590]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5469584) /* 0x537590 */));
    // 00437a5d  eb03                   -jmp 0x437a62
    return sub_437a62(app, cpu);
}

/* align: skip 0x90 */
void Application::sub_437a60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00437a60  90                     -nop 
    ;
    // 00437a61  90                     -nop 
    ;
    // 00437a62  db1d24295500           -fistp dword ptr [0x552924]
    app->getMemory<x86::reg32>(x86::reg32(5581092) /* 0x552924 */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 00437a68  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00437a6a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00437a6b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00437a6c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_437a62(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00437a62;
    // 00437a60  90                     -nop 
    ;
    // 00437a61  90                     -nop 
    ;
L_entry_0x00437a62:
    // 00437a62  db1d24295500           -fistp dword ptr [0x552924]
    app->getMemory<x86::reg32>(x86::reg32(5581092) /* 0x552924 */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 00437a68  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00437a6a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00437a6b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00437a6c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_437a70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00437a70  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00437a71  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00437a72  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00437a74  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00437a76  e8354f0300             -call 0x46c9b0
    cpu.esp -= 4;
    sub_46c9b0(app, cpu);
    if (cpu.terminate) return;
    // 00437a7b  dc0d98755300           +fmul qword ptr [0x537598]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5469592) /* 0x537598 */));
    // 00437a81  eb03                   -jmp 0x437a86
    return sub_437a86(app, cpu);
}

/* align: skip 0x90 */
void Application::sub_437a84(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00437a84  90                     -nop 
    ;
    // 00437a85  90                     -nop 
    ;
    // 00437a86  db1dfcbb6f00           -fistp dword ptr [0x6fbbfc]
    app->getMemory<x86::reg32>(x86::reg32(7322620) /* 0x6fbbfc */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 00437a8c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00437a8d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00437a8e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_437a86(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00437a86;
    // 00437a84  90                     -nop 
    ;
    // 00437a85  90                     -nop 
    ;
L_entry_0x00437a86:
    // 00437a86  db1dfcbb6f00           -fistp dword ptr [0x6fbbfc]
    app->getMemory<x86::reg32>(x86::reg32(7322620) /* 0x6fbbfc */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 00437a8c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00437a8d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00437a8e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_437a90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00437a90  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00437a91  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00437a92  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00437a93  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00437a94  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00437a95  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00437a97  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00437a99  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00437a9b  ba0f000000             -mov edx, 0xf
    cpu.edx = 15 /*0xf*/;
    // 00437aa0  e8bb2b0100             -call 0x44a660
    cpu.esp -= 4;
    sub_44a660(app, cpu);
    if (cpu.terminate) return;
    // 00437aa5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00437aa7  0f8446030000           -je 0x437df3
    if (cpu.flags.zf)
    {
        goto L_0x00437df3;
    }
    // 00437aad  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00437aaf  0f8479020000           -je 0x437d2e
    if (cpu.flags.zf)
    {
        goto L_0x00437d2e;
    }
    // 00437ab5  3b353c4f5500           +cmp esi, dword ptr [0x554f3c]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5590844) /* 0x554f3c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00437abb  7559                   -jne 0x437b16
    if (!cpu.flags.zf)
    {
        goto L_0x00437b16;
    }
    // 00437abd  8b0d244f5500           -mov ecx, dword ptr [0x554f24]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5590820) /* 0x554f24 */);
    // 00437ac3  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00437ac5  752d                   -jne 0x437af4
    if (!cpu.flags.zf)
    {
        goto L_0x00437af4;
    }
    // 00437ac7  833d3492550000         +cmp dword ptr [0x559234], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5607988) /* 0x559234 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00437ace  751a                   -jne 0x437aea
    if (!cpu.flags.zf)
    {
        goto L_0x00437aea;
    }
    // 00437ad0  bbffffffff             -mov ebx, 0xffffffff
    cpu.ebx = 4294967295 /*0xffffffff*/;
    // 00437ad5  ba05000000             -mov edx, 5
    cpu.edx = 5 /*0x5*/;
    // 00437ada  a1384f5500             -mov eax, dword ptr [0x554f38]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5590840) /* 0x554f38 */);
    // 00437adf  e83c190b00             -call 0x4e9420
    cpu.esp -= 4;
    sub_4e9420(app, cpu);
    if (cpu.terminate) return;
    // 00437ae4  890d384f5500           -mov dword ptr [0x554f38], ecx
    app->getMemory<x86::reg32>(x86::reg32(5590840) /* 0x554f38 */) = cpu.ecx;
L_0x00437aea:
    // 00437aea  c705244f550001000000   -mov dword ptr [0x554f24], 1
    app->getMemory<x86::reg32>(x86::reg32(5590820) /* 0x554f24 */) = 1 /*0x1*/;
L_0x00437af4:
    // 00437af4  833d3492550000         +cmp dword ptr [0x559234], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5607988) /* 0x559234 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00437afb  0f8583020000           -jne 0x437d84
    if (!cpu.flags.zf)
    {
        goto L_0x00437d84;
    }
    // 00437b01  b80a000000             -mov eax, 0xa
    cpu.eax = 10 /*0xa*/;
    // 00437b06  8b15e8bb6f00           -mov edx, dword ptr [0x6fbbe8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(7322600) /* 0x6fbbe8 */);
    // 00437b0c  e85ff90a00             -call 0x4e7470
    cpu.esp -= 4;
    sub_4e7470(app, cpu);
    if (cpu.terminate) return;
    // 00437b11  e96e020000             -jmp 0x437d84
    goto L_0x00437d84;
L_0x00437b16:
    // 00437b16  3b35404f5500           +cmp esi, dword ptr [0x554f40]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5590848) /* 0x554f40 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00437b1c  755a                   -jne 0x437b78
    if (!cpu.flags.zf)
    {
        goto L_0x00437b78;
    }
    // 00437b1e  833d204f550000         +cmp dword ptr [0x554f20], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5590816) /* 0x554f20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00437b25  752f                   -jne 0x437b56
    if (!cpu.flags.zf)
    {
        goto L_0x00437b56;
    }
    // 00437b27  833d3492550000         +cmp dword ptr [0x559234], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5607988) /* 0x559234 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00437b2e  751c                   -jne 0x437b4c
    if (!cpu.flags.zf)
    {
        goto L_0x00437b4c;
    }
    // 00437b30  bbffffffff             -mov ebx, 0xffffffff
    cpu.ebx = 4294967295 /*0xffffffff*/;
    // 00437b35  ba05000000             -mov edx, 5
    cpu.edx = 5 /*0x5*/;
    // 00437b3a  a1384f5500             -mov eax, dword ptr [0x554f38]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5590840) /* 0x554f38 */);
    // 00437b3f  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00437b41  e8da180b00             -call 0x4e9420
    cpu.esp -= 4;
    sub_4e9420(app, cpu);
    if (cpu.terminate) return;
    // 00437b46  890d384f5500           -mov dword ptr [0x554f38], ecx
    app->getMemory<x86::reg32>(x86::reg32(5590840) /* 0x554f38 */) = cpu.ecx;
L_0x00437b4c:
    // 00437b4c  c705204f550001000000   -mov dword ptr [0x554f20], 1
    app->getMemory<x86::reg32>(x86::reg32(5590816) /* 0x554f20 */) = 1 /*0x1*/;
L_0x00437b56:
    // 00437b56  833d3492550000         +cmp dword ptr [0x559234], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5607988) /* 0x559234 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00437b5d  0f8521020000           -jne 0x437d84
    if (!cpu.flags.zf)
    {
        goto L_0x00437d84;
    }
    // 00437b63  b80a000000             -mov eax, 0xa
    cpu.eax = 10 /*0xa*/;
    // 00437b68  8b15f0bb6f00           -mov edx, dword ptr [0x6fbbf0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(7322608) /* 0x6fbbf0 */);
    // 00437b6e  e8fdf80a00             -call 0x4e7470
    cpu.esp -= 4;
    sub_4e7470(app, cpu);
    if (cpu.terminate) return;
    // 00437b73  e90c020000             -jmp 0x437d84
    goto L_0x00437d84;
L_0x00437b78:
    // 00437b78  3b35444f5500           +cmp esi, dword ptr [0x554f44]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5590852) /* 0x554f44 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00437b7e  0f8587000000           -jne 0x437c0b
    if (!cpu.flags.zf)
    {
        goto L_0x00437c0b;
    }
    // 00437b84  833d284f550000         +cmp dword ptr [0x554f28], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5590824) /* 0x554f28 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00437b8b  7554                   -jne 0x437be1
    if (!cpu.flags.zf)
    {
        goto L_0x00437be1;
    }
    // 00437b8d  833d3492550000         +cmp dword ptr [0x559234], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5607988) /* 0x559234 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00437b94  7510                   -jne 0x437ba6
    if (!cpu.flags.zf)
    {
        goto L_0x00437ba6;
    }
    // 00437b96  b80a000000             -mov eax, 0xa
    cpu.eax = 10 /*0xa*/;
    // 00437b9b  8b15f0bb6f00           -mov edx, dword ptr [0x6fbbf0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(7322608) /* 0x6fbbf0 */);
    // 00437ba1  e8caf80a00             -call 0x4e7470
    cpu.esp -= 4;
    sub_4e7470(app, cpu);
    if (cpu.terminate) return;
L_0x00437ba6:
    // 00437ba6  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00437bab  8b1534925500           -mov edx, dword ptr [0x559234]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5607988) /* 0x559234 */);
    // 00437bb1  a3284f5500             -mov dword ptr [0x554f28], eax
    app->getMemory<x86::reg32>(x86::reg32(5590824) /* 0x554f28 */) = cpu.eax;
    // 00437bb6  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00437bb8  7527                   -jne 0x437be1
    if (!cpu.flags.zf)
    {
        goto L_0x00437be1;
    }
    // 00437bba  833d384f550000         +cmp dword ptr [0x554f38], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5590840) /* 0x554f38 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00437bc1  751e                   -jne 0x437be1
    if (!cpu.flags.zf)
    {
        goto L_0x00437be1;
    }
    // 00437bc3  6a40                   -push 0x40
    app->getMemory<x86::reg32>(cpu.esp-4) = 64 /*0x40*/;
    cpu.esp -= 4;
    // 00437bc5  ba07000000             -mov edx, 7
    cpu.edx = 7 /*0x7*/;
    // 00437bca  8b0df4bb6f00           -mov ecx, dword ptr [0x6fbbf4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(7322612) /* 0x6fbbf4 */);
    // 00437bd0  a124115700             -mov eax, dword ptr [0x571124]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5706020) /* 0x571124 */);
    // 00437bd5  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00437bd7  e8d406feff             -call 0x4182b0
    cpu.esp -= 4;
    sub_4182b0(app, cpu);
    if (cpu.terminate) return;
    // 00437bdc  a3384f5500             -mov dword ptr [0x554f38], eax
    app->getMemory<x86::reg32>(x86::reg32(5590840) /* 0x554f38 */) = cpu.eax;
L_0x00437be1:
    // 00437be1  833d3492550000         +cmp dword ptr [0x559234], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5607988) /* 0x559234 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00437be8  0f8596010000           -jne 0x437d84
    if (!cpu.flags.zf)
    {
        goto L_0x00437d84;
    }
    // 00437bee  a1384f5500             -mov eax, dword ptr [0x554f38]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5590840) /* 0x554f38 */);
    // 00437bf3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00437bf5  0f8489010000           -je 0x437d84
    if (cpu.flags.zf)
    {
        goto L_0x00437d84;
    }
    // 00437bfb  8b15f4bb6f00           -mov edx, dword ptr [0x6fbbf4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(7322612) /* 0x6fbbf4 */);
    // 00437c01  e8f6190b00             -call 0x4e95fc
    cpu.esp -= 4;
    sub_4e95fc(app, cpu);
    if (cpu.terminate) return;
    // 00437c06  e979010000             -jmp 0x437d84
    goto L_0x00437d84;
L_0x00437c0b:
    // 00437c0b  3b35484f5500           +cmp esi, dword ptr [0x554f48]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5590856) /* 0x554f48 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00437c11  0f8587000000           -jne 0x437c9e
    if (!cpu.flags.zf)
    {
        goto L_0x00437c9e;
    }
    // 00437c17  833d2c4f550000         +cmp dword ptr [0x554f2c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5590828) /* 0x554f2c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00437c1e  7554                   -jne 0x437c74
    if (!cpu.flags.zf)
    {
        goto L_0x00437c74;
    }
    // 00437c20  833d3492550000         +cmp dword ptr [0x559234], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5607988) /* 0x559234 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00437c27  7510                   -jne 0x437c39
    if (!cpu.flags.zf)
    {
        goto L_0x00437c39;
    }
    // 00437c29  b80a000000             -mov eax, 0xa
    cpu.eax = 10 /*0xa*/;
    // 00437c2e  8b15f0bb6f00           -mov edx, dword ptr [0x6fbbf0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(7322608) /* 0x6fbbf0 */);
    // 00437c34  e837f80a00             -call 0x4e7470
    cpu.esp -= 4;
    sub_4e7470(app, cpu);
    if (cpu.terminate) return;
L_0x00437c39:
    // 00437c39  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00437c3e  8b1534925500           -mov edx, dword ptr [0x559234]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5607988) /* 0x559234 */);
    // 00437c44  a32c4f5500             -mov dword ptr [0x554f2c], eax
    app->getMemory<x86::reg32>(x86::reg32(5590828) /* 0x554f2c */) = cpu.eax;
    // 00437c49  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00437c4b  7527                   -jne 0x437c74
    if (!cpu.flags.zf)
    {
        goto L_0x00437c74;
    }
    // 00437c4d  833d384f550000         +cmp dword ptr [0x554f38], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5590840) /* 0x554f38 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00437c54  751e                   -jne 0x437c74
    if (!cpu.flags.zf)
    {
        goto L_0x00437c74;
    }
    // 00437c56  6a40                   -push 0x40
    app->getMemory<x86::reg32>(cpu.esp-4) = 64 /*0x40*/;
    cpu.esp -= 4;
    // 00437c58  ba07000000             -mov edx, 7
    cpu.edx = 7 /*0x7*/;
    // 00437c5d  8b0df8bb6f00           -mov ecx, dword ptr [0x6fbbf8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(7322616) /* 0x6fbbf8 */);
    // 00437c63  a124115700             -mov eax, dword ptr [0x571124]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5706020) /* 0x571124 */);
    // 00437c68  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00437c6a  e84106feff             -call 0x4182b0
    cpu.esp -= 4;
    sub_4182b0(app, cpu);
    if (cpu.terminate) return;
    // 00437c6f  a3384f5500             -mov dword ptr [0x554f38], eax
    app->getMemory<x86::reg32>(x86::reg32(5590840) /* 0x554f38 */) = cpu.eax;
L_0x00437c74:
    // 00437c74  833d3492550000         +cmp dword ptr [0x559234], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5607988) /* 0x559234 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00437c7b  0f8503010000           -jne 0x437d84
    if (!cpu.flags.zf)
    {
        goto L_0x00437d84;
    }
    // 00437c81  a1384f5500             -mov eax, dword ptr [0x554f38]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5590840) /* 0x554f38 */);
    // 00437c86  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00437c88  0f84f6000000           -je 0x437d84
    if (cpu.flags.zf)
    {
        goto L_0x00437d84;
    }
    // 00437c8e  8b15f8bb6f00           -mov edx, dword ptr [0x6fbbf8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(7322616) /* 0x6fbbf8 */);
    // 00437c94  e863190b00             -call 0x4e95fc
    cpu.esp -= 4;
    sub_4e95fc(app, cpu);
    if (cpu.terminate) return;
    // 00437c99  e9e6000000             -jmp 0x437d84
    goto L_0x00437d84;
L_0x00437c9e:
    // 00437c9e  3b354c4f5500           +cmp esi, dword ptr [0x554f4c]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5590860) /* 0x554f4c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00437ca4  0f85da000000           -jne 0x437d84
    if (!cpu.flags.zf)
    {
        goto L_0x00437d84;
    }
    // 00437caa  833d304f550000         +cmp dword ptr [0x554f30], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5590832) /* 0x554f30 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00437cb1  7554                   -jne 0x437d07
    if (!cpu.flags.zf)
    {
        goto L_0x00437d07;
    }
    // 00437cb3  833d3492550000         +cmp dword ptr [0x559234], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5607988) /* 0x559234 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00437cba  7510                   -jne 0x437ccc
    if (!cpu.flags.zf)
    {
        goto L_0x00437ccc;
    }
    // 00437cbc  b80a000000             -mov eax, 0xa
    cpu.eax = 10 /*0xa*/;
    // 00437cc1  8b15f0bb6f00           -mov edx, dword ptr [0x6fbbf0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(7322608) /* 0x6fbbf0 */);
    // 00437cc7  e8a4f70a00             -call 0x4e7470
    cpu.esp -= 4;
    sub_4e7470(app, cpu);
    if (cpu.terminate) return;
L_0x00437ccc:
    // 00437ccc  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00437cd1  8b1534925500           -mov edx, dword ptr [0x559234]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5607988) /* 0x559234 */);
    // 00437cd7  a3304f5500             -mov dword ptr [0x554f30], eax
    app->getMemory<x86::reg32>(x86::reg32(5590832) /* 0x554f30 */) = cpu.eax;
    // 00437cdc  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00437cde  7527                   -jne 0x437d07
    if (!cpu.flags.zf)
    {
        goto L_0x00437d07;
    }
    // 00437ce0  833d384f550000         +cmp dword ptr [0x554f38], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5590840) /* 0x554f38 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00437ce7  751e                   -jne 0x437d07
    if (!cpu.flags.zf)
    {
        goto L_0x00437d07;
    }
    // 00437ce9  6a40                   -push 0x40
    app->getMemory<x86::reg32>(cpu.esp-4) = 64 /*0x40*/;
    cpu.esp -= 4;
    // 00437ceb  ba07000000             -mov edx, 7
    cpu.edx = 7 /*0x7*/;
    // 00437cf0  8b0dfcbb6f00           -mov ecx, dword ptr [0x6fbbfc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(7322620) /* 0x6fbbfc */);
    // 00437cf6  a124115700             -mov eax, dword ptr [0x571124]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5706020) /* 0x571124 */);
    // 00437cfb  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00437cfd  e8ae05feff             -call 0x4182b0
    cpu.esp -= 4;
    sub_4182b0(app, cpu);
    if (cpu.terminate) return;
    // 00437d02  a3384f5500             -mov dword ptr [0x554f38], eax
    app->getMemory<x86::reg32>(x86::reg32(5590840) /* 0x554f38 */) = cpu.eax;
L_0x00437d07:
    // 00437d07  833d3492550000         +cmp dword ptr [0x559234], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5607988) /* 0x559234 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00437d0e  0f8570000000           -jne 0x437d84
    if (!cpu.flags.zf)
    {
        goto L_0x00437d84;
    }
    // 00437d14  a1384f5500             -mov eax, dword ptr [0x554f38]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5590840) /* 0x554f38 */);
    // 00437d19  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00437d1b  0f8463000000           -je 0x437d84
    if (cpu.flags.zf)
    {
        goto L_0x00437d84;
    }
    // 00437d21  8b15fcbb6f00           -mov edx, dword ptr [0x6fbbfc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(7322620) /* 0x6fbbfc */);
    // 00437d27  e8d0180b00             -call 0x4e95fc
    cpu.esp -= 4;
    sub_4e95fc(app, cpu);
    if (cpu.terminate) return;
    // 00437d2c  eb56                   -jmp 0x437d84
    goto L_0x00437d84;
L_0x00437d2e:
    // 00437d2e  3b353c4f5500           +cmp esi, dword ptr [0x554f3c]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5590844) /* 0x554f3c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00437d34  750a                   -jne 0x437d40
    if (!cpu.flags.zf)
    {
        goto L_0x00437d40;
    }
    // 00437d36  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 00437d38  890d244f5500           -mov dword ptr [0x554f24], ecx
    app->getMemory<x86::reg32>(x86::reg32(5590820) /* 0x554f24 */) = cpu.ecx;
    // 00437d3e  eb44                   -jmp 0x437d84
    goto L_0x00437d84;
L_0x00437d40:
    // 00437d40  3b35404f5500           +cmp esi, dword ptr [0x554f40]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5590848) /* 0x554f40 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00437d46  7509                   -jne 0x437d51
    if (!cpu.flags.zf)
    {
        goto L_0x00437d51;
    }
    // 00437d48  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00437d4a  a3204f5500             -mov dword ptr [0x554f20], eax
    app->getMemory<x86::reg32>(x86::reg32(5590816) /* 0x554f20 */) = cpu.eax;
    // 00437d4f  eb33                   -jmp 0x437d84
    goto L_0x00437d84;
L_0x00437d51:
    // 00437d51  3b35444f5500           +cmp esi, dword ptr [0x554f44]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5590852) /* 0x554f44 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00437d57  750a                   -jne 0x437d63
    if (!cpu.flags.zf)
    {
        goto L_0x00437d63;
    }
    // 00437d59  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 00437d5b  890d284f5500           -mov dword ptr [0x554f28], ecx
    app->getMemory<x86::reg32>(x86::reg32(5590824) /* 0x554f28 */) = cpu.ecx;
    // 00437d61  eb21                   -jmp 0x437d84
    goto L_0x00437d84;
L_0x00437d63:
    // 00437d63  3b35484f5500           +cmp esi, dword ptr [0x554f48]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5590856) /* 0x554f48 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00437d69  7509                   -jne 0x437d74
    if (!cpu.flags.zf)
    {
        goto L_0x00437d74;
    }
    // 00437d6b  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00437d6d  a32c4f5500             -mov dword ptr [0x554f2c], eax
    app->getMemory<x86::reg32>(x86::reg32(5590828) /* 0x554f2c */) = cpu.eax;
    // 00437d72  eb10                   -jmp 0x437d84
    goto L_0x00437d84;
L_0x00437d74:
    // 00437d74  3b354c4f5500           +cmp esi, dword ptr [0x554f4c]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5590860) /* 0x554f4c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00437d7a  7508                   -jne 0x437d84
    if (!cpu.flags.zf)
    {
        goto L_0x00437d84;
    }
    // 00437d7c  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00437d7e  890d304f5500           -mov dword ptr [0x554f30], ecx
    app->getMemory<x86::reg32>(x86::reg32(5590832) /* 0x554f30 */) = cpu.ecx;
L_0x00437d84:
    // 00437d84  833d244f550000         +cmp dword ptr [0x554f24], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5590820) /* 0x554f24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00437d8b  0f8559000000           -jne 0x437dea
    if (!cpu.flags.zf)
    {
        goto L_0x00437dea;
    }
    // 00437d91  833d204f550000         +cmp dword ptr [0x554f20], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5590816) /* 0x554f20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00437d98  7550                   -jne 0x437dea
    if (!cpu.flags.zf)
    {
        goto L_0x00437dea;
    }
    // 00437d9a  833d284f550000         +cmp dword ptr [0x554f28], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5590824) /* 0x554f28 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00437da1  7547                   -jne 0x437dea
    if (!cpu.flags.zf)
    {
        goto L_0x00437dea;
    }
    // 00437da3  833d2c4f550000         +cmp dword ptr [0x554f2c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5590828) /* 0x554f2c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00437daa  753e                   -jne 0x437dea
    if (!cpu.flags.zf)
    {
        goto L_0x00437dea;
    }
    // 00437dac  833d304f550000         +cmp dword ptr [0x554f30], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5590832) /* 0x554f30 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00437db3  7535                   -jne 0x437dea
    if (!cpu.flags.zf)
    {
        goto L_0x00437dea;
    }
    // 00437db5  833d3492550000         +cmp dword ptr [0x559234], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5607988) /* 0x559234 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00437dbc  752c                   -jne 0x437dea
    if (!cpu.flags.zf)
    {
        goto L_0x00437dea;
    }
    // 00437dbe  b80a000000             -mov eax, 0xa
    cpu.eax = 10 /*0xa*/;
    // 00437dc3  8b15e8bb6f00           -mov edx, dword ptr [0x6fbbe8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(7322600) /* 0x6fbbe8 */);
    // 00437dc9  bbffffffff             -mov ebx, 0xffffffff
    cpu.ebx = 4294967295 /*0xffffffff*/;
    // 00437dce  e89df60a00             -call 0x4e7470
    cpu.esp -= 4;
    sub_4e7470(app, cpu);
    if (cpu.terminate) return;
    // 00437dd3  ba05000000             -mov edx, 5
    cpu.edx = 5 /*0x5*/;
    // 00437dd8  a1384f5500             -mov eax, dword ptr [0x554f38]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5590840) /* 0x554f38 */);
    // 00437ddd  e83e160b00             -call 0x4e9420
    cpu.esp -= 4;
    sub_4e9420(app, cpu);
    if (cpu.terminate) return;
    // 00437de2  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00437de4  8915384f5500           -mov dword ptr [0x554f38], edx
    app->getMemory<x86::reg32>(x86::reg32(5590840) /* 0x554f38 */) = cpu.edx;
L_0x00437dea:
    // 00437dea  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00437dec  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00437dee  e8ed4c0300             -call 0x46cae0
    cpu.esp -= 4;
    sub_46cae0(app, cpu);
    if (cpu.terminate) return;
L_0x00437df3:
    // 00437df3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00437df4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00437df5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00437df6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00437df7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00437df8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_437e00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00437e00  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00437e01  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00437e02  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00437e03  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00437e04  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00437e05  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00437e07  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00437e0a  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00437e0c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00437e0e  0f844f020000           -je 0x438063
    if (cpu.flags.zf)
    {
        goto L_0x00438063;
    }
    // 00437e14  833d3492550000         +cmp dword ptr [0x559234], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5607988) /* 0x559234 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00437e1b  740a                   -je 0x437e27
    if (cpu.flags.zf)
    {
        goto L_0x00437e27;
    }
    // 00437e1d  689a99193f             -push 0x3f19999a
    app->getMemory<x86::reg32>(cpu.esp-4) = 1058642330 /*0x3f19999a*/;
    cpu.esp -= 4;
    // 00437e22  e809970100             -call 0x451530
    cpu.esp -= 4;
    sub_451530(app, cpu);
    if (cpu.terminate) return;
L_0x00437e27:
    // 00437e27  e8c47cfdff             -call 0x40faf0
    cpu.esp -= 4;
    sub_40faf0(app, cpu);
    if (cpu.terminate) return;
    // 00437e2c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00437e2e  7509                   -jne 0x437e39
    if (!cpu.flags.zf)
    {
        goto L_0x00437e39;
    }
    // 00437e30  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00437e32  6689156a635500         -mov word ptr [0x55636a], dx
    app->getMemory<x86::reg16>(x86::reg32(5596010) /* 0x55636a */) = cpu.dx;
L_0x00437e39:
    // 00437e39  833d3492550000         +cmp dword ptr [0x559234], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5607988) /* 0x559234 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00437e40  751d                   -jne 0x437e5f
    if (!cpu.flags.zf)
    {
        goto L_0x00437e5f;
    }
    // 00437e42  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00437e44  e8cbf7ffff             -call 0x437614
    cpu.esp -= 4;
    sub_437614(app, cpu);
    if (cpu.terminate) return;
    // 00437e49  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00437e4b  e8acf8ffff             -call 0x4376fc
    cpu.esp -= 4;
    sub_4376fc(app, cpu);
    if (cpu.terminate) return;
    // 00437e50  a1d0d16f00             -mov eax, dword ptr [0x6fd1d0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7328208) /* 0x6fd1d0 */);
    // 00437e55  a380466600             -mov dword ptr [0x664680], eax
    app->getMemory<x86::reg32>(x86::reg32(6702720) /* 0x664680 */) = cpu.eax;
    // 00437e5a  eb03                   -jmp 0x437e5f
    goto L_0x00437e5f;
    // 00437e5c  90                     -nop 
    ;
    // 00437e5d  90                     -nop 
    ;
    // 00437e5e  90                     -nop 
    ;
L_0x00437e5f:
    // 00437e5f  baa8755300             -mov edx, 0x5375a8
    cpu.edx = 5469608 /*0x5375a8*/;
    // 00437e64  a100bc6f00             -mov eax, dword ptr [0x6fbc00]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7322624) /* 0x6fbc00 */);
    // 00437e69  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00437e6b  a370395f00             -mov dword ptr [0x5f3970], eax
    app->getMemory<x86::reg32>(x86::reg32(6240624) /* 0x5f3970 */) = cpu.eax;
    // 00437e70  893d204f5500           -mov dword ptr [0x554f20], edi
    app->getMemory<x86::reg32>(x86::reg32(5590816) /* 0x554f20 */) = cpu.edi;
    // 00437e76  893d244f5500           -mov dword ptr [0x554f24], edi
    app->getMemory<x86::reg32>(x86::reg32(5590820) /* 0x554f24 */) = cpu.edi;
    // 00437e7c  893d284f5500           -mov dword ptr [0x554f28], edi
    app->getMemory<x86::reg32>(x86::reg32(5590824) /* 0x554f28 */) = cpu.edi;
    // 00437e82  a1e4bb6f00             -mov eax, dword ptr [0x6fbbe4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7322596) /* 0x6fbbe4 */);
    // 00437e87  893d2c4f5500           -mov dword ptr [0x554f2c], edi
    app->getMemory<x86::reg32>(x86::reg32(5590828) /* 0x554f2c */) = cpu.edi;
    // 00437e8d  a368395f00             -mov dword ptr [0x5f3968], eax
    app->getMemory<x86::reg32>(x86::reg32(6240616) /* 0x5f3968 */) = cpu.eax;
    // 00437e92  a1ecbb6f00             -mov eax, dword ptr [0x6fbbec]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7322604) /* 0x6fbbec */);
    // 00437e97  893d304f5500           -mov dword ptr [0x554f30], edi
    app->getMemory<x86::reg32>(x86::reg32(5590832) /* 0x554f30 */) = cpu.edi;
    // 00437e9d  a364395f00             -mov dword ptr [0x5f3964], eax
    app->getMemory<x86::reg32>(x86::reg32(6240612) /* 0x5f3964 */) = cpu.eax;
    // 00437ea2  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00437ea4  893d384f5500           -mov dword ptr [0x554f38], edi
    app->getMemory<x86::reg32>(x86::reg32(5590840) /* 0x554f38 */) = cpu.edi;
    // 00437eaa  e891ab0000             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 00437eaf  a33c4f5500             -mov dword ptr [0x554f3c], eax
    app->getMemory<x86::reg32>(x86::reg32(5590844) /* 0x554f3c */) = cpu.eax;
    // 00437eb4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00437eb6  742e                   -je 0x437ee6
    if (cpu.flags.zf)
    {
        goto L_0x00437ee6;
    }
    // 00437eb8  db05e8bb6f00           -fild dword ptr [0x6fbbe8]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(7322600) /* 0x6fbbe8 */))));
    // 00437ebe  dc0d00765300           -fmul qword ptr [0x537600]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5469696) /* 0x537600 */));
    // 00437ec4  ba90794300             -mov edx, 0x437990
    cpu.edx = 4422032 /*0x437990*/;
    // 00437ec9  c7402c907a4300         -mov dword ptr [eax + 0x2c], 0x437a90
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(44) /* 0x2c */) = 4422288 /*0x437a90*/;
    // 00437ed0  d95df4                 -fstp dword ptr [ebp - 0xc]
    app->getMemory<float>(cpu.ebp + x86::reg32(-12) /* -0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00437ed3  e8e84b0300             -call 0x46cac0
    cpu.esp -= 4;
    sub_46cac0(app, cpu);
    if (cpu.terminate) return;
    // 00437ed8  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00437ed9  a13c4f5500             -mov eax, dword ptr [0x554f3c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5590844) /* 0x554f3c */);
    // 00437ede  ff75f4                 -push dword ptr [ebp - 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    cpu.esp -= 4;
    // 00437ee1  e86a4a0300             -call 0x46c950
    cpu.esp -= 4;
    sub_46c950(app, cpu);
    if (cpu.terminate) return;
L_0x00437ee6:
    // 00437ee6  bab8755300             -mov edx, 0x5375b8
    cpu.edx = 5469624 /*0x5375b8*/;
    // 00437eeb  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00437eed  e84eab0000             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 00437ef2  a3404f5500             -mov dword ptr [0x554f40], eax
    app->getMemory<x86::reg32>(x86::reg32(5590848) /* 0x554f40 */) = cpu.eax;
    // 00437ef7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00437ef9  742f                   -je 0x437f2a
    if (cpu.flags.zf)
    {
        goto L_0x00437f2a;
    }
    // 00437efb  db05f0bb6f00           -fild dword ptr [0x6fbbf0]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(7322608) /* 0x6fbbf0 */))));
    // 00437f01  dc0d00765300           -fmul qword ptr [0x537600]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5469696) /* 0x537600 */));
    // 00437f07  bab0794300             -mov edx, 0x4379b0
    cpu.edx = 4422064 /*0x4379b0*/;
    // 00437f0c  c7402c907a4300         -mov dword ptr [eax + 0x2c], 0x437a90
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(44) /* 0x2c */) = 4422288 /*0x437a90*/;
    // 00437f13  d95df0                 -fstp dword ptr [ebp - 0x10]
    app->getMemory<float>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00437f16  e8a54b0300             -call 0x46cac0
    cpu.esp -= 4;
    sub_46cac0(app, cpu);
    if (cpu.terminate) return;
    // 00437f1b  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00437f1d  a1404f5500             -mov eax, dword ptr [0x554f40]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5590848) /* 0x554f40 */);
    // 00437f22  ff75f0                 -push dword ptr [ebp - 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    cpu.esp -= 4;
    // 00437f25  e8264a0300             -call 0x46c950
    cpu.esp -= 4;
    sub_46c950(app, cpu);
    if (cpu.terminate) return;
L_0x00437f2a:
    // 00437f2a  bac8755300             -mov edx, 0x5375c8
    cpu.edx = 5469640 /*0x5375c8*/;
    // 00437f2f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00437f31  e80aab0000             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 00437f36  a3444f5500             -mov dword ptr [0x554f44], eax
    app->getMemory<x86::reg32>(x86::reg32(5590852) /* 0x554f44 */) = cpu.eax;
    // 00437f3b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00437f3d  7445                   -je 0x437f84
    if (cpu.flags.zf)
    {
        goto L_0x00437f84;
    }
    // 00437f3f  c7402c907a4300         -mov dword ptr [eax + 0x2c], 0x437a90
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(44) /* 0x2c */) = 4422288 /*0x437a90*/;
    // 00437f46  833d3492550000         +cmp dword ptr [0x559234], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5607988) /* 0x559234 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00437f4d  7508                   -jne 0x437f57
    if (!cpu.flags.zf)
    {
        goto L_0x00437f57;
    }
    // 00437f4f  db05f4bb6f00           +fild dword ptr [0x6fbbf4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(7322612) /* 0x6fbbf4 */))));
    // 00437f55  eb06                   -jmp 0x437f5d
    goto L_0x00437f5d;
L_0x00437f57:
    // 00437f57  db0520295500           -fild dword ptr [0x552920]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5581088) /* 0x552920 */))));
L_0x00437f5d:
    // 00437f5d  dc0d00765300           -fmul qword ptr [0x537600]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5469696) /* 0x537600 */));
    // 00437f63  d95df8                 -fstp dword ptr [ebp - 8]
    app->getMemory<float>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00437f66  bad0794300             -mov edx, 0x4379d0
    cpu.edx = 4422096 /*0x4379d0*/;
    // 00437f6b  a1444f5500             -mov eax, dword ptr [0x554f44]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5590852) /* 0x554f44 */);
    // 00437f70  e84b4b0300             -call 0x46cac0
    cpu.esp -= 4;
    sub_46cac0(app, cpu);
    if (cpu.terminate) return;
    // 00437f75  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00437f77  a1444f5500             -mov eax, dword ptr [0x554f44]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5590852) /* 0x554f44 */);
    // 00437f7c  ff75f8                 -push dword ptr [ebp - 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    cpu.esp -= 4;
    // 00437f7f  e8cc490300             -call 0x46c950
    cpu.esp -= 4;
    sub_46c950(app, cpu);
    if (cpu.terminate) return;
L_0x00437f84:
    // 00437f84  bad8755300             -mov edx, 0x5375d8
    cpu.edx = 5469656 /*0x5375d8*/;
    // 00437f89  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00437f8b  e8b0aa0000             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 00437f90  a3484f5500             -mov dword ptr [0x554f48], eax
    app->getMemory<x86::reg32>(x86::reg32(5590856) /* 0x554f48 */) = cpu.eax;
    // 00437f95  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00437f97  7446                   -je 0x437fdf
    if (cpu.flags.zf)
    {
        goto L_0x00437fdf;
    }
    // 00437f99  8b1534925500           -mov edx, dword ptr [0x559234]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5607988) /* 0x559234 */);
    // 00437f9f  c7402c907a4300         -mov dword ptr [eax + 0x2c], 0x437a90
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(44) /* 0x2c */) = 4422288 /*0x437a90*/;
    // 00437fa6  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00437fa8  7508                   -jne 0x437fb2
    if (!cpu.flags.zf)
    {
        goto L_0x00437fb2;
    }
    // 00437faa  db05f8bb6f00           +fild dword ptr [0x6fbbf8]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(7322616) /* 0x6fbbf8 */))));
    // 00437fb0  eb06                   -jmp 0x437fb8
    goto L_0x00437fb8;
L_0x00437fb2:
    // 00437fb2  db0524295500           -fild dword ptr [0x552924]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5581092) /* 0x552924 */))));
L_0x00437fb8:
    // 00437fb8  dc0d00765300           -fmul qword ptr [0x537600]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5469696) /* 0x537600 */));
    // 00437fbe  d95dfc                 -fstp dword ptr [ebp - 4]
    app->getMemory<float>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00437fc1  ba207a4300             -mov edx, 0x437a20
    cpu.edx = 4422176 /*0x437a20*/;
    // 00437fc6  a1484f5500             -mov eax, dword ptr [0x554f48]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5590856) /* 0x554f48 */);
    // 00437fcb  e8f04a0300             -call 0x46cac0
    cpu.esp -= 4;
    sub_46cac0(app, cpu);
    if (cpu.terminate) return;
    // 00437fd0  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00437fd2  a1484f5500             -mov eax, dword ptr [0x554f48]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5590856) /* 0x554f48 */);
    // 00437fd7  ff75fc                 -push dword ptr [ebp - 4]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    cpu.esp -= 4;
    // 00437fda  e871490300             -call 0x46c950
    cpu.esp -= 4;
    sub_46c950(app, cpu);
    if (cpu.terminate) return;
L_0x00437fdf:
    // 00437fdf  baec755300             -mov edx, 0x5375ec
    cpu.edx = 5469676 /*0x5375ec*/;
    // 00437fe4  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00437fe6  e855aa0000             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 00437feb  a34c4f5500             -mov dword ptr [0x554f4c], eax
    app->getMemory<x86::reg32>(x86::reg32(5590860) /* 0x554f4c */) = cpu.eax;
    // 00437ff0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00437ff2  742f                   -je 0x438023
    if (cpu.flags.zf)
    {
        goto L_0x00438023;
    }
    // 00437ff4  db05fcbb6f00           -fild dword ptr [0x6fbbfc]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(7322620) /* 0x6fbbfc */))));
    // 00437ffa  dc0d00765300           -fmul qword ptr [0x537600]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5469696) /* 0x537600 */));
    // 00438000  ba707a4300             -mov edx, 0x437a70
    cpu.edx = 4422256 /*0x437a70*/;
    // 00438005  c7402c907a4300         -mov dword ptr [eax + 0x2c], 0x437a90
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(44) /* 0x2c */) = 4422288 /*0x437a90*/;
    // 0043800c  d95df0                 -fstp dword ptr [ebp - 0x10]
    app->getMemory<float>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0043800f  e8ac4a0300             -call 0x46cac0
    cpu.esp -= 4;
    sub_46cac0(app, cpu);
    if (cpu.terminate) return;
    // 00438014  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00438016  a14c4f5500             -mov eax, dword ptr [0x554f4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5590860) /* 0x554f4c */);
    // 0043801b  ff75f0                 -push dword ptr [ebp - 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    cpu.esp -= 4;
    // 0043801e  e82d490300             -call 0x46c950
    cpu.esp -= 4;
    sub_46c950(app, cpu);
    if (cpu.terminate) return;
L_0x00438023:
    // 00438023  833d3492550000         +cmp dword ptr [0x559234], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5607988) /* 0x559234 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043802a  7510                   -jne 0x43803c
    if (!cpu.flags.zf)
    {
        goto L_0x0043803c;
    }
    // 0043802c  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00438031  8b15e8bb6f00           -mov edx, dword ptr [0x6fbbe8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(7322600) /* 0x6fbbe8 */);
    // 00438037  e834f40a00             -call 0x4e7470
    cpu.esp -= 4;
    sub_4e7470(app, cpu);
    if (cpu.terminate) return;
L_0x0043803c:
    // 0043803c  b910000000             -mov ecx, 0x10
    cpu.ecx = 16 /*0x10*/;
    // 00438041  a124295500             -mov eax, dword ptr [0x552924]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5581092) /* 0x552924 */);
    // 00438046  bf20395f00             -mov edi, 0x5f3920
    cpu.edi = 6240544 /*0x5f3920*/;
    // 0043804b  bed0bb6f00             -mov esi, 0x6fbbd0
    cpu.esi = 7322576 /*0x6fbbd0*/;
    // 00438050  a36c395f00             -mov dword ptr [0x5f396c], eax
    app->getMemory<x86::reg32>(x86::reg32(6240620) /* 0x5f396c */) = cpu.eax;
    // 00438055  a120295500             -mov eax, dword ptr [0x552920]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5581088) /* 0x552920 */);
    // 0043805a  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0043805c  a360395f00             -mov dword ptr [0x5f3960], eax
    app->getMemory<x86::reg32>(x86::reg32(6240608) /* 0x5f3960 */) = cpu.eax;
    // 00438061  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00438063:
    // 00438063  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00438065  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438066  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438067  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438068  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438069  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043806a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_438070(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00438070  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00438071  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00438072  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00438073  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00438074  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00438075  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00438076  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00438078  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0043807a  833d3492550000         +cmp dword ptr [0x559234], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5607988) /* 0x559234 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00438081  7510                   -jne 0x438093
    if (!cpu.flags.zf)
    {
        goto L_0x00438093;
    }
    // 00438083  b80a000000             -mov eax, 0xa
    cpu.eax = 10 /*0xa*/;
    // 00438088  8b15e8bb6f00           -mov edx, dword ptr [0x6fbbe8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(7322600) /* 0x6fbbe8 */);
    // 0043808e  e8ddf30a00             -call 0x4e7470
    cpu.esp -= 4;
    sub_4e7470(app, cpu);
    if (cpu.terminate) return;
L_0x00438093:
    // 00438093  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00438095  891d404f5500           -mov dword ptr [0x554f40], ebx
    app->getMemory<x86::reg32>(x86::reg32(5590848) /* 0x554f40 */) = cpu.ebx;
    // 0043809b  891d444f5500           -mov dword ptr [0x554f44], ebx
    app->getMemory<x86::reg32>(x86::reg32(5590852) /* 0x554f44 */) = cpu.ebx;
    // 004380a1  891d484f5500           -mov dword ptr [0x554f48], ebx
    app->getMemory<x86::reg32>(x86::reg32(5590856) /* 0x554f48 */) = cpu.ebx;
    // 004380a7  891d4c4f5500           -mov dword ptr [0x554f4c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5590860) /* 0x554f4c */) = cpu.ebx;
    // 004380ad  891d204f5500           -mov dword ptr [0x554f20], ebx
    app->getMemory<x86::reg32>(x86::reg32(5590816) /* 0x554f20 */) = cpu.ebx;
    // 004380b3  891d244f5500           -mov dword ptr [0x554f24], ebx
    app->getMemory<x86::reg32>(x86::reg32(5590820) /* 0x554f24 */) = cpu.ebx;
    // 004380b9  891d284f5500           -mov dword ptr [0x554f28], ebx
    app->getMemory<x86::reg32>(x86::reg32(5590824) /* 0x554f28 */) = cpu.ebx;
    // 004380bf  891d2c4f5500           -mov dword ptr [0x554f2c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5590828) /* 0x554f2c */) = cpu.ebx;
    // 004380c5  891d304f5500           -mov dword ptr [0x554f30], ebx
    app->getMemory<x86::reg32>(x86::reg32(5590832) /* 0x554f30 */) = cpu.ebx;
    // 004380cb  891d3c4f5500           -mov dword ptr [0x554f3c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5590844) /* 0x554f3c */) = cpu.ebx;
    // 004380d1  833d3492550000         +cmp dword ptr [0x559234], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5607988) /* 0x559234 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004380d8  745c                   -je 0x438136
    if (cpu.flags.zf)
    {
        goto L_0x00438136;
    }
    // 004380da  803d0929550000         +cmp byte ptr [0x552909], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5581065) /* 0x552909 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004380e1  7414                   -je 0x4380f7
    if (cpu.flags.zf)
    {
        goto L_0x004380f7;
    }
    // 004380e3  a120295500             -mov eax, dword ptr [0x552920]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5581088) /* 0x552920 */);
    // 004380e8  a3f4bb6f00             -mov dword ptr [0x6fbbf4], eax
    app->getMemory<x86::reg32>(x86::reg32(7322612) /* 0x6fbbf4 */) = cpu.eax;
    // 004380ed  a124295500             -mov eax, dword ptr [0x552924]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5581092) /* 0x552924 */);
    // 004380f2  a3f8bb6f00             -mov dword ptr [0x6fbbf8], eax
    app->getMemory<x86::reg32>(x86::reg32(7322616) /* 0x6fbbf8 */) = cpu.eax;
L_0x004380f7:
    // 004380f7  803d90e8550000         +cmp byte ptr [0x55e890], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5630096) /* 0x55e890 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004380fe  7536                   -jne 0x438136
    if (!cpu.flags.zf)
    {
        goto L_0x00438136;
    }
    // 00438100  8b35f0bb6f00           -mov esi, dword ptr [0x6fbbf0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(7322608) /* 0x6fbbf0 */);
    // 00438106  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00438108  742c                   -je 0x438136
    if (cpu.flags.zf)
    {
        goto L_0x00438136;
    }
    // 0043810a  833de4bb6f0002         +cmp dword ptr [0x6fbbe4], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(7322596) /* 0x6fbbe4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00438111  7e0e                   -jle 0x438121
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00438121;
    }
    // 00438113  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00438118  a1acd46f00             -mov eax, dword ptr [0x6fd4ac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7328940) /* 0x6fd4ac */);
    // 0043811d  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0043811f  eb09                   -jmp 0x43812a
    goto L_0x0043812a;
L_0x00438121:
    // 00438121  a1acd46f00             -mov eax, dword ptr [0x6fd4ac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7328940) /* 0x6fd4ac */);
    // 00438126  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00438128  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x0043812a:
    // 0043812a  e89186fdff             -call 0x4107c0
    cpu.esp -= 4;
    sub_4107c0(app, cpu);
    if (cpu.terminate) return;
    // 0043812f  c60590e8550001         -mov byte ptr [0x55e890], 1
    app->getMemory<x86::reg8>(x86::reg32(5630096) /* 0x55e890 */) = 1 /*0x1*/;
L_0x00438136:
    // 00438136  0fbf511a               -movsx edx, word ptr [ecx + 0x1a]
    cpu.edx = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(26) /* 0x1a */)));
    // 0043813a  0fbf4118               -movsx eax, word ptr [ecx + 0x18]
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(24) /* 0x18 */)));
    // 0043813e  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00438140  69c0bc000000           -imul eax, eax, 0xbc
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(188 /*0xbc*/)));
    // 00438146  05e04e6000             -add eax, 0x604ee0
    (cpu.eax) += x86::reg32(x86::sreg32(6311648 /*0x604ee0*/));
    // 0043814b  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0043814d  8b4610                 -mov eax, dword ptr [esi + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 00438150  e863f7ffff             -call 0x4378b8
    cpu.esp -= 4;
    sub_4378b8(app, cpu);
    if (cpu.terminate) return;
    // 00438155  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00438157  740d                   -je 0x438166
    if (cpu.flags.zf)
    {
        goto L_0x00438166;
    }
    // 00438159  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0043815b  a3344f5500             -mov dword ptr [0x554f34], eax
    app->getMemory<x86::reg32>(x86::reg32(5590836) /* 0x554f34 */) = cpu.eax;
    // 00438160  40                     -inc eax
    (cpu.eax)++;
    // 00438161  a291255500             -mov byte ptr [0x552591], al
    app->getMemory<x86::reg8>(x86::reg32(5580177) /* 0x552591 */) = cpu.al;
L_0x00438166:
    // 00438166  833e05                 +cmp dword ptr [esi], 5
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5 /*0x5*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00438169  0f8599000000           -jne 0x438208
    if (!cpu.flags.zf)
    {
        goto L_0x00438208;
    }
    // 0043816f  ba08765300             -mov edx, 0x537608
    cpu.edx = 5469704 /*0x537608*/;
    // 00438174  8b4610                 -mov eax, dword ptr [esi + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 00438177  e844a80000             -call 0x4429c0
    cpu.esp -= 4;
    sub_4429c0(app, cpu);
    if (cpu.terminate) return;
    // 0043817c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043817e  0f8484000000           -je 0x438208
    if (cpu.flags.zf)
    {
        goto L_0x00438208;
    }
    // 00438184  a160395f00             -mov eax, dword ptr [0x5f3960]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6240608) /* 0x5f3960 */);
    // 00438189  a320295500             -mov dword ptr [0x552920], eax
    app->getMemory<x86::reg32>(x86::reg32(5581088) /* 0x552920 */) = cpu.eax;
    // 0043818e  a16c395f00             -mov eax, dword ptr [0x5f396c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6240620) /* 0x5f396c */);
    // 00438193  a324295500             -mov dword ptr [0x552924], eax
    app->getMemory<x86::reg32>(x86::reg32(5581092) /* 0x552924 */) = cpu.eax;
    // 00438198  be20395f00             -mov esi, 0x5f3920
    cpu.esi = 6240544 /*0x5f3920*/;
    // 0043819d  bfd0bb6f00             -mov edi, 0x6fbbd0
    cpu.edi = 7322576 /*0x6fbbd0*/;
    // 004381a2  b910000000             -mov ecx, 0x10
    cpu.ecx = 16 /*0x10*/;
    // 004381a7  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004381a9  833d3492550000         +cmp dword ptr [0x559234], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5607988) /* 0x559234 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004381b0  7531                   -jne 0x4381e3
    if (!cpu.flags.zf)
    {
        goto L_0x004381e3;
    }
    // 004381b2  a180466600             -mov eax, dword ptr [0x664680]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6702720) /* 0x664680 */);
    // 004381b7  a3d0d16f00             -mov dword ptr [0x6fd1d0], eax
    app->getMemory<x86::reg32>(x86::reg32(7328208) /* 0x6fd1d0 */) = cpu.eax;
    // 004381bc  eb07                   -jmp 0x4381c5
    goto L_0x004381c5;
    // 004381be  90                     -nop 
    ;
    // 004381bf  90                     -nop 
    ;
    // 004381c0  90                     -nop 
    ;
    // 004381c1  90                     -nop 
    ;
    // 004381c2  90                     -nop 
    ;
    // 004381c3  90                     -nop 
    ;
    // 004381c4  90                     -nop 
    ;
L_0x004381c5:
    // 004381c5  833d344f550000         +cmp dword ptr [0x554f34], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5590836) /* 0x554f34 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004381cc  7415                   -je 0x4381e3
    if (cpu.flags.zf)
    {
        goto L_0x004381e3;
    }
    // 004381ce  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004381d3  a1ecbb6f00             -mov eax, dword ptr [0x6fbbec]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7322604) /* 0x6fbbec */);
    // 004381d8  890d344f5500           -mov dword ptr [0x554f34], ecx
    app->getMemory<x86::reg32>(x86::reg32(5590836) /* 0x554f34 */) = cpu.ecx;
    // 004381de  e8bd81fdff             -call 0x4103a0
    cpu.esp -= 4;
    sub_4103a0(app, cpu);
    if (cpu.terminate) return;
L_0x004381e3:
    // 004381e3  bbffffffff             -mov ebx, 0xffffffff
    cpu.ebx = 4294967295 /*0xffffffff*/;
    // 004381e8  ba05000000             -mov edx, 5
    cpu.edx = 5 /*0x5*/;
    // 004381ed  a1384f5500             -mov eax, dword ptr [0x554f38]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5590840) /* 0x554f38 */);
    // 004381f2  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004381f4  e827120b00             -call 0x4e9420
    cpu.esp -= 4;
    sub_4e9420(app, cpu);
    if (cpu.terminate) return;
    // 004381f9  893d384f5500           -mov dword ptr [0x554f38], edi
    app->getMemory<x86::reg32>(x86::reg32(5590840) /* 0x554f38 */) = cpu.edi;
    // 004381ff  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00438201  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438202  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438203  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438204  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438205  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438206  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438207  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00438208:
    // 00438208  bbffffffff             -mov ebx, 0xffffffff
    cpu.ebx = 4294967295 /*0xffffffff*/;
    // 0043820d  ba05000000             -mov edx, 5
    cpu.edx = 5 /*0x5*/;
    // 00438212  a1384f5500             -mov eax, dword ptr [0x554f38]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5590840) /* 0x554f38 */);
    // 00438217  e804120b00             -call 0x4e9420
    cpu.esp -= 4;
    sub_4e9420(app, cpu);
    if (cpu.terminate) return;
    // 0043821c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0043821e  8b1534925500           -mov edx, dword ptr [0x559234]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5607988) /* 0x559234 */);
    // 00438224  a3384f5500             -mov dword ptr [0x554f38], eax
    app->getMemory<x86::reg32>(x86::reg32(5590840) /* 0x554f38 */) = cpu.eax;
    // 00438229  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0043822b  7526                   -jne 0x438253
    if (!cpu.flags.zf)
    {
        goto L_0x00438253;
    }
    // 0043822d  833d344f550000         +cmp dword ptr [0x554f34], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5590836) /* 0x554f34 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00438234  7509                   -jne 0x43823f
    if (!cpu.flags.zf)
    {
        goto L_0x0043823f;
    }
    // 00438236  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00438238  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438239  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043823a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043823b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043823c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043823d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043823e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0043823f:
    // 0043823f  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00438244  a3344f5500             -mov dword ptr [0x554f34], eax
    app->getMemory<x86::reg32>(x86::reg32(5590836) /* 0x554f34 */) = cpu.eax;
    // 00438249  a1ecbb6f00             -mov eax, dword ptr [0x6fbbec]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7322604) /* 0x6fbbec */);
    // 0043824e  e84d81fdff             -call 0x4103a0
    cpu.esp -= 4;
    sub_4103a0(app, cpu);
    if (cpu.terminate) return;
L_0x00438253:
    // 00438253  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00438255  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438256  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438257  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438258  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438259  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043825a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043825b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_438260(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00438260  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00438261  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00438262  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00438263  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00438264  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00438265  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00438266  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00438268  a170395f00             -mov eax, dword ptr [0x5f3970]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6240624) /* 0x5f3970 */);
    // 0043826d  8b1500bc6f00           -mov edx, dword ptr [0x6fbc00]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(7322624) /* 0x6fbc00 */);
    // 00438273  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00438275  39d0                   +cmp eax, edx
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
    // 00438277  7473                   -je 0x4382ec
    if (cpu.flags.zf)
    {
        goto L_0x004382ec;
    }
    // 00438279  b8e6010000             -mov eax, 0x1e6
    cpu.eax = 486 /*0x1e6*/;
    // 0043827e  891570395f00           -mov dword ptr [0x5f3970], edx
    app->getMemory<x86::reg32>(x86::reg32(6240624) /* 0x5f3970 */) = cpu.edx;
    // 00438284  e857c90000             -call 0x444be0
    cpu.esp -= 4;
    sub_444be0(app, cpu);
    if (cpu.terminate) return;
    // 00438289  e872dc0000             -call 0x445f00
    cpu.esp -= 4;
    sub_445f00(app, cpu);
    if (cpu.terminate) return;
    // 0043828e  e88d0e0a00             -call 0x4d9120
    cpu.esp -= 4;
    sub_4d9120(app, cpu);
    if (cpu.terminate) return;
    // 00438293  e8182c0100             -call 0x44aeb0
    cpu.esp -= 4;
    sub_44aeb0(app, cpu);
    if (cpu.terminate) return;
    // 00438298  e853220100             -call 0x44a4f0
    cpu.esp -= 4;
    sub_44a4f0(app, cpu);
    if (cpu.terminate) return;
    // 0043829d  e80eb60000             -call 0x4438b0
    cpu.esp -= 4;
    sub_4438b0(app, cpu);
    if (cpu.terminate) return;
    // 004382a2  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 004382a4  7405                   -je 0x4382ab
    if (cpu.flags.zf)
    {
        goto L_0x004382ab;
    }
    // 004382a6  e8a5dc0000             -call 0x445f50
    cpu.esp -= 4;
    sub_445f50(app, cpu);
    if (cpu.terminate) return;
L_0x004382ab:
    // 004382ab  e8900e0a00             -call 0x4d9140
    cpu.esp -= 4;
    sub_4d9140(app, cpu);
    if (cpu.terminate) return;
    // 004382b0  e81b87fdff             -call 0x4109d0
    cpu.esp -= 4;
    sub_4109d0(app, cpu);
    if (cpu.terminate) return;
    // 004382b5  e8e687fdff             -call 0x410aa0
    cpu.esp -= 4;
    sub_410aa0(app, cpu);
    if (cpu.terminate) return;
    // 004382ba  e86188fdff             -call 0x410b20
    cpu.esp -= 4;
    sub_410b20(app, cpu);
    if (cpu.terminate) return;
    // 004382bf  e8ec7bfdff             -call 0x40feb0
    cpu.esp -= 4;
    sub_40feb0(app, cpu);
    if (cpu.terminate) return;
    // 004382c4  a100bc6f00             -mov eax, dword ptr [0x6fbc00]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7322624) /* 0x6fbc00 */);
    // 004382c9  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004382ce  e81d7afdff             -call 0x40fcf0
    cpu.esp -= 4;
    sub_40fcf0(app, cpu);
    if (cpu.terminate) return;
    // 004382d3  e808b4fdff             -call 0x4136e0
    cpu.esp -= 4;
    sub_4136e0(app, cpu);
    if (cpu.terminate) return;
    // 004382d8  e85380fdff             -call 0x410330
    cpu.esp -= 4;
    sub_410330(app, cpu);
    if (cpu.terminate) return;
    // 004382dd  a1ecbb6f00             -mov eax, dword ptr [0x6fbbec]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7322604) /* 0x6fbbec */);
    // 004382e2  e8b980fdff             -call 0x4103a0
    cpu.esp -= 4;
    sub_4103a0(app, cpu);
    if (cpu.terminate) return;
    // 004382e7  e824dc0000             -call 0x445f10
    cpu.esp -= 4;
    sub_445f10(app, cpu);
    if (cpu.terminate) return;
L_0x004382ec:
    // 004382ec  a1e4bb6f00             -mov eax, dword ptr [0x6fbbe4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7322596) /* 0x6fbbe4 */);
    // 004382f1  3b0568395f00           +cmp eax, dword ptr [0x5f3968]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(6240616) /* 0x5f3968 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004382f7  7416                   -je 0x43830f
    if (cpu.flags.zf)
    {
        goto L_0x0043830f;
    }
    // 004382f9  c705344f550001000000   -mov dword ptr [0x554f34], 1
    app->getMemory<x86::reg32>(x86::reg32(5590836) /* 0x554f34 */) = 1 /*0x1*/;
    // 00438303  a368395f00             -mov dword ptr [0x5f3968], eax
    app->getMemory<x86::reg32>(x86::reg32(6240616) /* 0x5f3968 */) = cpu.eax;
    // 00438308  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0043830a  e89180fdff             -call 0x4103a0
    cpu.esp -= 4;
    sub_4103a0(app, cpu);
    if (cpu.terminate) return;
L_0x0043830f:
    // 0043830f  a1ecbb6f00             -mov eax, dword ptr [0x6fbbec]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7322604) /* 0x6fbbec */);
    // 00438314  3b0564395f00           +cmp eax, dword ptr [0x5f3964]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(6240612) /* 0x5f3964 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043831a  7419                   -je 0x438335
    if (cpu.flags.zf)
    {
        goto L_0x00438335;
    }
    // 0043831c  c705344f550001000000   -mov dword ptr [0x554f34], 1
    app->getMemory<x86::reg32>(x86::reg32(5590836) /* 0x554f34 */) = 1 /*0x1*/;
    // 00438326  a364395f00             -mov dword ptr [0x5f3964], eax
    app->getMemory<x86::reg32>(x86::reg32(6240612) /* 0x5f3964 */) = cpu.eax;
    // 0043832b  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00438330  e86b80fdff             -call 0x4103a0
    cpu.esp -= 4;
    sub_4103a0(app, cpu);
    if (cpu.terminate) return;
L_0x00438335:
    // 00438335  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00438337  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438338  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438339  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043833a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043833b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043833c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043833d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_43833e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043833e  90                     -nop 
    ;
    // 0043833f  90                     -nop 
    ;
    // 00438340  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00438341  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00438343  e858a60100             -call 0x4529a0
    cpu.esp -= 4;
    sub_4529a0(app, cpu);
    if (cpu.terminate) return;
    // 00438348  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438349  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_438340(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00438340;
    // 0043833e  90                     -nop 
    ;
    // 0043833f  90                     -nop 
    ;
L_entry_0x00438340:
    // 00438340  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00438341  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00438343  e858a60100             -call 0x4529a0
    cpu.esp -= 4;
    sub_4529a0(app, cpu);
    if (cpu.terminate) return;
    // 00438348  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438349  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_438350(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00438350  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00438351  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00438352  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00438353  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00438354  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00438355  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00438357  81ec2c010000           -sub esp, 0x12c
    (cpu.esp) -= x86::reg32(x86::sreg32(300 /*0x12c*/));
    // 0043835d  81edaa010000           -sub ebp, 0x1aa
    (cpu.ebp) -= x86::reg32(x86::sreg32(426 /*0x1aa*/));
    // 00438363  8d7d7e                 -lea edi, [ebp + 0x7e]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 00438366  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00438368  ba64765300             -mov edx, 0x537664
    cpu.edx = 5469796 /*0x537664*/;
    // 0043836d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0043836e:
    // 0043836e  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00438370  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00438372  3c00                   +cmp al, 0
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
    // 00438374  7410                   -je 0x438386
    if (cpu.flags.zf)
    {
        goto L_0x00438386;
    }
    // 00438376  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00438379  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0043837c  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0043837f  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00438382  3c00                   +cmp al, 0
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
    // 00438384  75e8                   -jne 0x43836e
    if (!cpu.flags.zf)
    {
        goto L_0x0043836e;
    }
L_0x00438386:
    // 00438386  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438387  8d457e                 -lea eax, [ebp + 0x7e]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 0043838a  be58765300             -mov esi, 0x537658
    cpu.esi = 5469784 /*0x537658*/;
    // 0043838f  8d7d7e                 -lea edi, [ebp + 0x7e]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 00438392  e8a9ffffff             -call 0x438340
    cpu.esp -= 4;
    sub_438340(app, cpu);
    if (cpu.terminate) return;
    // 00438397  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00438398  2bc9                   +sub ecx, ecx
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
    // 0043839a  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0043839b  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 0043839d  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0043839f  4f                     -dec edi
    (cpu.edi)--;
L_0x004383a0:
    // 004383a0  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004383a2  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 004383a4  3c00                   +cmp al, 0
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
    // 004383a6  7410                   -je 0x4383b8
    if (cpu.flags.zf)
    {
        goto L_0x004383b8;
    }
    // 004383a8  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004383ab  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004383ae  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 004383b1  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004383b4  3c00                   +cmp al, 0
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
    // 004383b6  75e8                   -jne 0x4383a0
    if (!cpu.flags.zf)
    {
        goto L_0x004383a0;
    }
L_0x004383b8:
    // 004383b8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004383b9  8d457e                 -lea eax, [ebp + 0x7e]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 004383bc  e8275c0b00             -call 0x4edfe8
    cpu.esp -= 4;
    sub_4edfe8(app, cpu);
    if (cpu.terminate) return;
    // 004383c1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004383c3  7412                   -je 0x4383d7
    if (cpu.flags.zf)
    {
        goto L_0x004383d7;
    }
    // 004383c5  e8365d0b00             -call 0x4ee100
    cpu.esp -= 4;
    sub_4ee100(app, cpu);
    if (cpu.terminate) return;
    // 004383ca  8d457e                 -lea eax, [ebp + 0x7e]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 004383cd  e80e5f0b00             -call 0x4ee2e0
    cpu.esp -= 4;
    sub_4ee2e0(app, cpu);
    if (cpu.terminate) return;
    // 004383d2  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x004383d7:
    // 004383d7  8da5aa010000           -lea esp, [ebp + 0x1aa]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(426) /* 0x1aa */);
    // 004383dd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004383de  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004383df  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004383e0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004383e1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004383e2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4383f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004383f0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004383f1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004383f2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004383f3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004383f4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004383f5  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004383f7  81ec34010000           -sub esp, 0x134
    (cpu.esp) -= x86::reg32(x86::sreg32(308 /*0x134*/));
    // 004383fd  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 00438400  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 00438402  895dfc                 -mov dword ptr [ebp - 4], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ebx;
    // 00438405  eb0a                   -jmp 0x438411
    goto L_0x00438411;
L_0x00438407:
    // 00438407  837dfc00               +cmp dword ptr [ebp - 4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043840b  0f8587000000           -jne 0x438498
    if (!cpu.flags.zf)
    {
        goto L_0x00438498;
    }
L_0x00438411:
    // 00438411  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00438412  6868765300             -push 0x537668
    app->getMemory<x86::reg32>(cpu.esp-4) = 5469800 /*0x537668*/;
    cpu.esp -= 4;
    // 00438417  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00438418  e873720a00             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 0043841d  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00438420  8b75f8                 -mov esi, dword ptr [ebp - 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00438423  8dbdccfeffff           -lea edi, [ebp - 0x134]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-308) /* -0x134 */);
    // 00438429  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0043842a:
    // 0043842a  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0043842c  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0043842e  3c00                   +cmp al, 0
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
    // 00438430  7410                   -je 0x438442
    if (cpu.flags.zf)
    {
        goto L_0x00438442;
    }
    // 00438432  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00438435  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00438438  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0043843b  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0043843e  3c00                   +cmp al, 0
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
    // 00438440  75e8                   -jne 0x43842a
    if (!cpu.flags.zf)
    {
        goto L_0x0043842a;
    }
L_0x00438442:
    // 00438442  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438443  8d85ccfeffff           -lea eax, [ebp - 0x134]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-308) /* -0x134 */);
    // 00438449  8dbdccfeffff           -lea edi, [ebp - 0x134]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-308) /* -0x134 */);
    // 0043844f  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00438451  e8eafeffff             -call 0x438340
    cpu.esp -= 4;
    sub_438340(app, cpu);
    if (cpu.terminate) return;
    // 00438456  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00438457  2bc9                   +sub ecx, ecx
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
    // 00438459  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0043845a  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 0043845c  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0043845e  4f                     -dec edi
    (cpu.edi)--;
L_0x0043845f:
    // 0043845f  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00438461  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00438463  3c00                   +cmp al, 0
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
    // 00438465  7410                   -je 0x438477
    if (cpu.flags.zf)
    {
        goto L_0x00438477;
    }
    // 00438467  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0043846a  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0043846d  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00438470  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00438473  3c00                   +cmp al, 0
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
    // 00438475  75e8                   -jne 0x43845f
    if (!cpu.flags.zf)
    {
        goto L_0x0043845f;
    }
L_0x00438477:
    // 00438477  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438478  8d85ccfeffff           -lea eax, [ebp - 0x134]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-308) /* -0x134 */);
    // 0043847e  43                     -inc ebx
    (cpu.ebx)++;
    // 0043847f  e8ccfeffff             -call 0x438350
    cpu.esp -= 4;
    sub_438350(app, cpu);
    if (cpu.terminate) return;
    // 00438484  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00438486  0f857bffffff           -jne 0x438407
    if (!cpu.flags.zf)
    {
        goto L_0x00438407;
    }
    // 0043848c  c745fc01000000         -mov dword ptr [ebp - 4], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = 1 /*0x1*/;
    // 00438493  e96fffffff             -jmp 0x438407
    goto L_0x00438407;
L_0x00438498:
    // 00438498  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0043849a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043849b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043849c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043849d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043849e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043849f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4384a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004384a0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004384a1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004384a2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004384a3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004384a4  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004384a6  81ec2c010000           -sub esp, 0x12c
    (cpu.esp) -= x86::reg32(x86::sreg32(300 /*0x12c*/));
    // 004384ac  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004384ae  beb4287a00             -mov esi, 0x7a28b4
    cpu.esi = 8005812 /*0x7a28b4*/;
    // 004384b3  8dbdd4feffff           -lea edi, [ebp - 0x12c]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-300) /* -0x12c */);
    // 004384b9  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x004384ba:
    // 004384ba  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004384bc  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 004384be  3c00                   +cmp al, 0
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
    // 004384c0  7410                   -je 0x4384d2
    if (cpu.flags.zf)
    {
        goto L_0x004384d2;
    }
    // 004384c2  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004384c5  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004384c8  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 004384cb  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004384ce  3c00                   +cmp al, 0
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
    // 004384d0  75e8                   -jne 0x4384ba
    if (!cpu.flags.zf)
    {
        goto L_0x004384ba;
    }
L_0x004384d2:
    // 004384d2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004384d3  8d85d4feffff           -lea eax, [ebp - 0x12c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-300) /* -0x12c */);
    // 004384d9  e862feffff             -call 0x438340
    cpu.esp -= 4;
    sub_438340(app, cpu);
    if (cpu.terminate) return;
    // 004384de  8d85d4feffff           -lea eax, [ebp - 0x12c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-300) /* -0x12c */);
    // 004384e4  e807ffffff             -call 0x4383f0
    cpu.esp -= 4;
    sub_4383f0(app, cpu);
    if (cpu.terminate) return;
    // 004384e9  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004384eb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004384ec  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004384ed  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004384ee  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004384ef  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4384f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004384f0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004384f1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004384f2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004384f3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004384f4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004384f5  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004384f7  81ec34010000           -sub esp, 0x134
    (cpu.esp) -= x86::reg32(x86::sreg32(308 /*0x134*/));
    // 004384fd  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 00438500  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 00438502  895dfc                 -mov dword ptr [ebp - 4], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ebx;
    // 00438505  eb0a                   -jmp 0x438511
    goto L_0x00438511;
L_0x00438507:
    // 00438507  837dfc00               +cmp dword ptr [ebp - 4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043850b  0f8587000000           -jne 0x438598
    if (!cpu.flags.zf)
    {
        goto L_0x00438598;
    }
L_0x00438511:
    // 00438511  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00438512  6870765300             -push 0x537670
    app->getMemory<x86::reg32>(cpu.esp-4) = 5469808 /*0x537670*/;
    cpu.esp -= 4;
    // 00438517  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00438518  e873710a00             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 0043851d  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00438520  8b75f8                 -mov esi, dword ptr [ebp - 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00438523  8dbdccfeffff           -lea edi, [ebp - 0x134]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-308) /* -0x134 */);
    // 00438529  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0043852a:
    // 0043852a  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0043852c  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0043852e  3c00                   +cmp al, 0
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
    // 00438530  7410                   -je 0x438542
    if (cpu.flags.zf)
    {
        goto L_0x00438542;
    }
    // 00438532  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00438535  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00438538  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0043853b  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0043853e  3c00                   +cmp al, 0
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
    // 00438540  75e8                   -jne 0x43852a
    if (!cpu.flags.zf)
    {
        goto L_0x0043852a;
    }
L_0x00438542:
    // 00438542  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438543  8d85ccfeffff           -lea eax, [ebp - 0x134]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-308) /* -0x134 */);
    // 00438549  8dbdccfeffff           -lea edi, [ebp - 0x134]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-308) /* -0x134 */);
    // 0043854f  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00438551  e8eafdffff             -call 0x438340
    cpu.esp -= 4;
    sub_438340(app, cpu);
    if (cpu.terminate) return;
    // 00438556  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00438557  2bc9                   +sub ecx, ecx
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
    // 00438559  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0043855a  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 0043855c  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0043855e  4f                     -dec edi
    (cpu.edi)--;
L_0x0043855f:
    // 0043855f  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00438561  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00438563  3c00                   +cmp al, 0
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
    // 00438565  7410                   -je 0x438577
    if (cpu.flags.zf)
    {
        goto L_0x00438577;
    }
    // 00438567  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0043856a  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0043856d  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00438570  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00438573  3c00                   +cmp al, 0
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
    // 00438575  75e8                   -jne 0x43855f
    if (!cpu.flags.zf)
    {
        goto L_0x0043855f;
    }
L_0x00438577:
    // 00438577  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438578  8d85ccfeffff           -lea eax, [ebp - 0x134]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-308) /* -0x134 */);
    // 0043857e  43                     -inc ebx
    (cpu.ebx)++;
    // 0043857f  e8ccfdffff             -call 0x438350
    cpu.esp -= 4;
    sub_438350(app, cpu);
    if (cpu.terminate) return;
    // 00438584  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00438586  0f857bffffff           -jne 0x438507
    if (!cpu.flags.zf)
    {
        goto L_0x00438507;
    }
    // 0043858c  c745fc01000000         -mov dword ptr [ebp - 4], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = 1 /*0x1*/;
    // 00438593  e96fffffff             -jmp 0x438507
    goto L_0x00438507;
L_0x00438598:
    // 00438598  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0043859a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043859b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043859c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043859d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043859e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043859f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4385a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004385a0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004385a1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004385a2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004385a3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004385a4  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004385a6  81ec2c010000           -sub esp, 0x12c
    (cpu.esp) -= x86::reg32(x86::sreg32(300 /*0x12c*/));
    // 004385ac  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004385ae  beb4287a00             -mov esi, 0x7a28b4
    cpu.esi = 8005812 /*0x7a28b4*/;
    // 004385b3  8dbdd4feffff           -lea edi, [ebp - 0x12c]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-300) /* -0x12c */);
    // 004385b9  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x004385ba:
    // 004385ba  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004385bc  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 004385be  3c00                   +cmp al, 0
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
    // 004385c0  7410                   -je 0x4385d2
    if (cpu.flags.zf)
    {
        goto L_0x004385d2;
    }
    // 004385c2  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004385c5  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004385c8  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 004385cb  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004385ce  3c00                   +cmp al, 0
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
    // 004385d0  75e8                   -jne 0x4385ba
    if (!cpu.flags.zf)
    {
        goto L_0x004385ba;
    }
L_0x004385d2:
    // 004385d2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004385d3  8d85d4feffff           -lea eax, [ebp - 0x12c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-300) /* -0x12c */);
    // 004385d9  e862fdffff             -call 0x438340
    cpu.esp -= 4;
    sub_438340(app, cpu);
    if (cpu.terminate) return;
    // 004385de  8d85d4feffff           -lea eax, [ebp - 0x12c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-300) /* -0x12c */);
    // 004385e4  e807ffffff             -call 0x4384f0
    cpu.esp -= 4;
    sub_4384f0(app, cpu);
    if (cpu.terminate) return;
    // 004385e9  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004385eb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004385ec  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004385ed  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004385ee  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004385ef  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4385f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004385f0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004385f1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004385f2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004385f3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004385f4  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004385f6  81ec2c010000           -sub esp, 0x12c
    (cpu.esp) -= x86::reg32(x86::sreg32(300 /*0x12c*/));
    // 004385fc  81edaa010000           -sub ebp, 0x1aa
    (cpu.ebp) -= x86::reg32(x86::sreg32(426 /*0x1aa*/));
    // 00438602  8d7d7e                 -lea edi, [ebp + 0x7e]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 00438605  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00438607  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x00438608:
    // 00438608  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0043860a  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0043860c  3c00                   +cmp al, 0
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
    // 0043860e  7410                   -je 0x438620
    if (cpu.flags.zf)
    {
        goto L_0x00438620;
    }
    // 00438610  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00438613  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00438616  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00438619  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0043861c  3c00                   +cmp al, 0
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
    // 0043861e  75e8                   -jne 0x438608
    if (!cpu.flags.zf)
    {
        goto L_0x00438608;
    }
L_0x00438620:
    // 00438620  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438621  8d457e                 -lea eax, [ebp + 0x7e]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 00438624  be78765300             -mov esi, 0x537678
    cpu.esi = 5469816 /*0x537678*/;
    // 00438629  8d7d7e                 -lea edi, [ebp + 0x7e]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 0043862c  e80ffdffff             -call 0x438340
    cpu.esp -= 4;
    sub_438340(app, cpu);
    if (cpu.terminate) return;
    // 00438631  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00438632  2bc9                   +sub ecx, ecx
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
    // 00438634  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00438635  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 00438637  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00438639  4f                     -dec edi
    (cpu.edi)--;
L_0x0043863a:
    // 0043863a  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0043863c  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0043863e  3c00                   +cmp al, 0
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
    // 00438640  7410                   -je 0x438652
    if (cpu.flags.zf)
    {
        goto L_0x00438652;
    }
    // 00438642  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00438645  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00438648  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0043864b  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0043864e  3c00                   +cmp al, 0
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
    // 00438650  75e8                   -jne 0x43863a
    if (!cpu.flags.zf)
    {
        goto L_0x0043863a;
    }
L_0x00438652:
    // 00438652  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438653  8d7d7e                 -lea edi, [ebp + 0x7e]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 00438656  8b3495544f5500         -mov esi, dword ptr [edx*4 + 0x554f54]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5590868) /* 0x554f54 */ + cpu.edx * 4);
    // 0043865d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0043865e  2bc9                   +sub ecx, ecx
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
    // 00438660  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00438661  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 00438663  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00438665  4f                     -dec edi
    (cpu.edi)--;
L_0x00438666:
    // 00438666  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00438668  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0043866a  3c00                   +cmp al, 0
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
    // 0043866c  7410                   -je 0x43867e
    if (cpu.flags.zf)
    {
        goto L_0x0043867e;
    }
    // 0043866e  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00438671  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00438674  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00438677  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0043867a  3c00                   +cmp al, 0
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
    // 0043867c  75e8                   -jne 0x438666
    if (!cpu.flags.zf)
    {
        goto L_0x00438666;
    }
L_0x0043867e:
    // 0043867e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043867f  ba80765300             -mov edx, 0x537680
    cpu.edx = 5469824 /*0x537680*/;
    // 00438684  8d457e                 -lea eax, [ebp + 0x7e]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 00438687  e85c590b00             -call 0x4edfe8
    cpu.esp -= 4;
    sub_4edfe8(app, cpu);
    if (cpu.terminate) return;
    // 0043868c  8da5aa010000           -lea esp, [ebp + 0x1aa]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(426) /* 0x1aa */);
    // 00438692  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438693  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438694  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438695  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438696  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_4386a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004386a0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004386a1  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004386a3  e8585a0b00             -call 0x4ee100
    cpu.esp -= 4;
    sub_4ee100(app, cpu);
    if (cpu.terminate) return;
    // 004386a8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004386a9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_4386b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004386b0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004386b1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004386b2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004386b3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004386b4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004386b5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004386b6  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004386b8  81ec2c010000           -sub esp, 0x12c
    (cpu.esp) -= x86::reg32(x86::sreg32(300 /*0x12c*/));
    // 004386be  81edaa010000           -sub ebp, 0x1aa
    (cpu.ebp) -= x86::reg32(x86::sreg32(426 /*0x1aa*/));
    // 004386c4  8d7d7e                 -lea edi, [ebp + 0x7e]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 004386c7  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004386c9  ba5c000000             -mov edx, 0x5c
    cpu.edx = 92 /*0x5c*/;
    // 004386ce  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x004386cf:
    // 004386cf  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004386d1  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 004386d3  3c00                   +cmp al, 0
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
    // 004386d5  7410                   -je 0x4386e7
    if (cpu.flags.zf)
    {
        goto L_0x004386e7;
    }
    // 004386d7  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004386da  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004386dd  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 004386e0  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004386e3  3c00                   +cmp al, 0
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
    // 004386e5  75e8                   -jne 0x4386cf
    if (!cpu.flags.zf)
    {
        goto L_0x004386cf;
    }
L_0x004386e7:
    // 004386e7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004386e8  8d457e                 -lea eax, [ebp + 0x7e]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 004386eb  be84765300             -mov esi, 0x537684
    cpu.esi = 5469828 /*0x537684*/;
    // 004386f0  e8fb5b0b00             -call 0x4ee2f0
    cpu.esp -= 4;
    sub_4ee2f0(app, cpu);
    if (cpu.terminate) return;
    // 004386f5  8d457e                 -lea eax, [ebp + 0x7e]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 004386f8  8d7d7e                 -lea edi, [ebp + 0x7e]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 004386fb  e840fcffff             -call 0x438340
    cpu.esp -= 4;
    sub_438340(app, cpu);
    if (cpu.terminate) return;
    // 00438700  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00438701  2bc9                   +sub ecx, ecx
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
    // 00438703  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00438704  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 00438706  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00438708  4f                     -dec edi
    (cpu.edi)--;
L_0x00438709:
    // 00438709  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0043870b  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0043870d  3c00                   +cmp al, 0
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
    // 0043870f  7410                   -je 0x438721
    if (cpu.flags.zf)
    {
        goto L_0x00438721;
    }
    // 00438711  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00438714  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00438717  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0043871a  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0043871d  3c00                   +cmp al, 0
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
    // 0043871f  75e8                   -jne 0x438709
    if (!cpu.flags.zf)
    {
        goto L_0x00438709;
    }
L_0x00438721:
    // 00438721  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438722  68c03a5f00             -push 0x5f3ac0
    app->getMemory<x86::reg32>(cpu.esp-4) = 6240960 /*0x5f3ac0*/;
    cpu.esp -= 4;
    // 00438727  8d457e                 -lea eax, [ebp + 0x7e]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 0043872a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0043872b  2eff15cc445300         -call dword ptr cs:[0x5344cc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457100) /* 0x5344cc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00438732  a3784f5500             -mov dword ptr [0x554f78], eax
    app->getMemory<x86::reg32>(x86::reg32(5590904) /* 0x554f78 */) = cpu.eax;
    // 00438737  83f8ff                 +cmp eax, -1
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
    // 0043873a  7517                   -jne 0x438753
    if (!cpu.flags.zf)
    {
        goto L_0x00438753;
    }
    // 0043873c  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0043873e  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00438740  8915784f5500           -mov dword ptr [0x554f78], edx
    app->getMemory<x86::reg32>(x86::reg32(5590904) /* 0x554f78 */) = cpu.edx;
    // 00438746  e983000000             -jmp 0x4387ce
    goto L_0x004387ce;
L_0x0043874b:
    // 0043874b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043874d  0f8563000000           -jne 0x4387b6
    if (!cpu.flags.zf)
    {
        goto L_0x004387b6;
    }
L_0x00438753:
    // 00438753  f605c03a5f0010         +test byte ptr [0x5f3ac0], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(6240960) /* 0x5f3ac0 */) & 16 /*0x10*/));
    // 0043875a  7438                   -je 0x438794
    if (cpu.flags.zf)
    {
        goto L_0x00438794;
    }
    // 0043875c  baec3a5f00             -mov edx, 0x5f3aec
    cpu.edx = 6241004 /*0x5f3aec*/;
    // 00438761  b888765300             -mov eax, 0x537688
    cpu.eax = 5469832 /*0x537688*/;
    // 00438766  e8a55b0b00             -call 0x4ee310
    cpu.esp -= 4;
    sub_4ee310(app, cpu);
    if (cpu.terminate) return;
    // 0043876b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043876d  7425                   -je 0x438794
    if (cpu.flags.zf)
    {
        goto L_0x00438794;
    }
    // 0043876f  baec3a5f00             -mov edx, 0x5f3aec
    cpu.edx = 6241004 /*0x5f3aec*/;
    // 00438774  b88c765300             -mov eax, 0x53768c
    cpu.eax = 5469836 /*0x53768c*/;
    // 00438779  e8925b0b00             -call 0x4ee310
    cpu.esp -= 4;
    sub_4ee310(app, cpu);
    if (cpu.terminate) return;
    // 0043877e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00438780  7412                   -je 0x438794
    if (cpu.flags.zf)
    {
        goto L_0x00438794;
    }
    // 00438782  b8ec3a5f00             -mov eax, 0x5f3aec
    cpu.eax = 6241004 /*0x5f3aec*/;
    // 00438787  8da5aa010000           -lea esp, [ebp + 0x1aa]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(426) /* 0x1aa */);
    // 0043878d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043878e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043878f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438790  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438791  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438792  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438793  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00438794:
    // 00438794  68c03a5f00             -push 0x5f3ac0
    app->getMemory<x86::reg32>(cpu.esp-4) = 6240960 /*0x5f3ac0*/;
    cpu.esp -= 4;
    // 00438799  8b0d784f5500           -mov ecx, dword ptr [0x554f78]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5590904) /* 0x554f78 */);
    // 0043879f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004387a0  2eff15d0445300         -call dword ptr cs:[0x5344d0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457104) /* 0x5344d0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004387a7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004387a9  7507                   -jne 0x4387b2
    if (!cpu.flags.zf)
    {
        goto L_0x004387b2;
    }
    // 004387ab  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004387b0  eb99                   -jmp 0x43874b
    goto L_0x0043874b;
L_0x004387b2:
    // 004387b2  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004387b4  eb95                   -jmp 0x43874b
    goto L_0x0043874b;
L_0x004387b6:
    // 004387b6  8b1d784f5500           -mov ebx, dword ptr [0x554f78]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5590904) /* 0x554f78 */);
    // 004387bc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004387bd  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004387bf  2eff15c8445300         -call dword ptr cs:[0x5344c8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457096) /* 0x5344c8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004387c6  8935784f5500           -mov dword ptr [0x554f78], esi
    app->getMemory<x86::reg32>(x86::reg32(5590904) /* 0x554f78 */) = cpu.esi;
    // 004387cc  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004387ce:
    // 004387ce  8da5aa010000           -lea esp, [ebp + 0x1aa]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(426) /* 0x1aa */);
    // 004387d4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004387d5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004387d6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004387d7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004387d8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004387d9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004387da  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_4387e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004387e0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004387e1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004387e2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004387e3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004387e4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004387e5  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004387e7  833d784f550000         +cmp dword ptr [0x554f78], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5590904) /* 0x554f78 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004387ee  0f8465000000           -je 0x438859
    if (cpu.flags.zf)
    {
        goto L_0x00438859;
    }
L_0x004387f4:
    // 004387f4  68c03a5f00             -push 0x5f3ac0
    app->getMemory<x86::reg32>(cpu.esp-4) = 6240960 /*0x5f3ac0*/;
    cpu.esp -= 4;
    // 004387f9  8b0d784f5500           -mov ecx, dword ptr [0x554f78]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5590904) /* 0x554f78 */);
    // 004387ff  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00438800  2eff15d0445300         -call dword ptr cs:[0x5344d0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457104) /* 0x5344d0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00438807  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00438809  7438                   -je 0x438843
    if (cpu.flags.zf)
    {
        goto L_0x00438843;
    }
    // 0043880b  f605c03a5f0010         +test byte ptr [0x5f3ac0], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(6240960) /* 0x5f3ac0 */) & 16 /*0x10*/));
    // 00438812  74e0                   -je 0x4387f4
    if (cpu.flags.zf)
    {
        goto L_0x004387f4;
    }
    // 00438814  baec3a5f00             -mov edx, 0x5f3aec
    cpu.edx = 6241004 /*0x5f3aec*/;
    // 00438819  b888765300             -mov eax, 0x537688
    cpu.eax = 5469832 /*0x537688*/;
    // 0043881e  e8ed5a0b00             -call 0x4ee310
    cpu.esp -= 4;
    sub_4ee310(app, cpu);
    if (cpu.terminate) return;
    // 00438823  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00438825  74cd                   -je 0x4387f4
    if (cpu.flags.zf)
    {
        goto L_0x004387f4;
    }
    // 00438827  baec3a5f00             -mov edx, 0x5f3aec
    cpu.edx = 6241004 /*0x5f3aec*/;
    // 0043882c  b88c765300             -mov eax, 0x53768c
    cpu.eax = 5469836 /*0x53768c*/;
    // 00438831  e8da5a0b00             -call 0x4ee310
    cpu.esp -= 4;
    sub_4ee310(app, cpu);
    if (cpu.terminate) return;
    // 00438836  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00438838  7502                   -jne 0x43883c
    if (!cpu.flags.zf)
    {
        goto L_0x0043883c;
    }
    // 0043883a  ebb8                   -jmp 0x4387f4
    goto L_0x004387f4;
L_0x0043883c:
    // 0043883c  b8ec3a5f00             -mov eax, 0x5f3aec
    cpu.eax = 6241004 /*0x5f3aec*/;
    // 00438841  eb18                   -jmp 0x43885b
    goto L_0x0043885b;
L_0x00438843:
    // 00438843  8b1d784f5500           -mov ebx, dword ptr [0x554f78]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5590904) /* 0x554f78 */);
    // 00438849  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0043884a  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0043884c  2eff15c8445300         -call dword ptr cs:[0x5344c8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457096) /* 0x5344c8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00438853  8935784f5500           -mov dword ptr [0x554f78], esi
    app->getMemory<x86::reg32>(x86::reg32(5590904) /* 0x554f78 */) = cpu.esi;
L_0x00438859:
    // 00438859  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0043885b:
    // 0043885b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043885c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043885d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043885e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043885f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438860  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_438870(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00438870  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00438871  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00438872  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00438873  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00438874  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00438875  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00438876  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00438878  81ec2c010000           -sub esp, 0x12c
    (cpu.esp) -= x86::reg32(x86::sreg32(300 /*0x12c*/));
    // 0043887e  81edaa010000           -sub ebp, 0x1aa
    (cpu.ebp) -= x86::reg32(x86::sreg32(426 /*0x1aa*/));
    // 00438884  8d7d7e                 -lea edi, [ebp + 0x7e]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 00438887  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00438889  ba5c000000             -mov edx, 0x5c
    cpu.edx = 92 /*0x5c*/;
    // 0043888e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0043888f:
    // 0043888f  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00438891  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00438893  3c00                   +cmp al, 0
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
    // 00438895  7410                   -je 0x4388a7
    if (cpu.flags.zf)
    {
        goto L_0x004388a7;
    }
    // 00438897  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0043889a  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0043889d  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 004388a0  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004388a3  3c00                   +cmp al, 0
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
    // 004388a5  75e8                   -jne 0x43888f
    if (!cpu.flags.zf)
    {
        goto L_0x0043888f;
    }
L_0x004388a7:
    // 004388a7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004388a8  8d457e                 -lea eax, [ebp + 0x7e]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 004388ab  be84765300             -mov esi, 0x537684
    cpu.esi = 5469828 /*0x537684*/;
    // 004388b0  e83b5a0b00             -call 0x4ee2f0
    cpu.esp -= 4;
    sub_4ee2f0(app, cpu);
    if (cpu.terminate) return;
    // 004388b5  8d457e                 -lea eax, [ebp + 0x7e]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 004388b8  8d7d7e                 -lea edi, [ebp + 0x7e]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 004388bb  e880faffff             -call 0x438340
    cpu.esp -= 4;
    sub_438340(app, cpu);
    if (cpu.terminate) return;
    // 004388c0  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004388c1  2bc9                   +sub ecx, ecx
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
    // 004388c3  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004388c4  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 004388c6  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 004388c8  4f                     -dec edi
    (cpu.edi)--;
L_0x004388c9:
    // 004388c9  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004388cb  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 004388cd  3c00                   +cmp al, 0
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
    // 004388cf  7410                   -je 0x4388e1
    if (cpu.flags.zf)
    {
        goto L_0x004388e1;
    }
    // 004388d1  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004388d4  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004388d7  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 004388da  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004388dd  3c00                   +cmp al, 0
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
    // 004388df  75e8                   -jne 0x4388c9
    if (!cpu.flags.zf)
    {
        goto L_0x004388c9;
    }
L_0x004388e1:
    // 004388e1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004388e2  6880395f00             -push 0x5f3980
    app->getMemory<x86::reg32>(cpu.esp-4) = 6240640 /*0x5f3980*/;
    cpu.esp -= 4;
    // 004388e7  8d457e                 -lea eax, [ebp + 0x7e]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 004388ea  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004388eb  2eff15cc445300         -call dword ptr cs:[0x5344cc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457100) /* 0x5344cc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004388f2  a37c4f5500             -mov dword ptr [0x554f7c], eax
    app->getMemory<x86::reg32>(x86::reg32(5590908) /* 0x554f7c */) = cpu.eax;
    // 004388f7  83f8ff                 +cmp eax, -1
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
    // 004388fa  7510                   -jne 0x43890c
    if (!cpu.flags.zf)
    {
        goto L_0x0043890c;
    }
    // 004388fc  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004388fe  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00438900  89157c4f5500           -mov dword ptr [0x554f7c], edx
    app->getMemory<x86::reg32>(x86::reg32(5590908) /* 0x554f7c */) = cpu.edx;
    // 00438906  eb59                   -jmp 0x438961
    goto L_0x00438961;
L_0x00438908:
    // 00438908  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043890a  753d                   -jne 0x438949
    if (!cpu.flags.zf)
    {
        goto L_0x00438949;
    }
L_0x0043890c:
    // 0043890c  f60580395f0010         +test byte ptr [0x5f3980], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(6240640) /* 0x5f3980 */) & 16 /*0x10*/));
    // 00438913  7512                   -jne 0x438927
    if (!cpu.flags.zf)
    {
        goto L_0x00438927;
    }
    // 00438915  b8ac395f00             -mov eax, 0x5f39ac
    cpu.eax = 6240684 /*0x5f39ac*/;
    // 0043891a  8da5aa010000           -lea esp, [ebp + 0x1aa]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(426) /* 0x1aa */);
    // 00438920  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438921  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438922  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438923  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438924  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438925  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438926  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00438927:
    // 00438927  6880395f00             -push 0x5f3980
    app->getMemory<x86::reg32>(cpu.esp-4) = 6240640 /*0x5f3980*/;
    cpu.esp -= 4;
    // 0043892c  8b0d7c4f5500           -mov ecx, dword ptr [0x554f7c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5590908) /* 0x554f7c */);
    // 00438932  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00438933  2eff15d0445300         -call dword ptr cs:[0x5344d0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457104) /* 0x5344d0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0043893a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043893c  7507                   -jne 0x438945
    if (!cpu.flags.zf)
    {
        goto L_0x00438945;
    }
    // 0043893e  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00438943  ebc3                   -jmp 0x438908
    goto L_0x00438908;
L_0x00438945:
    // 00438945  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00438947  ebbf                   -jmp 0x438908
    goto L_0x00438908;
L_0x00438949:
    // 00438949  8b1d7c4f5500           -mov ebx, dword ptr [0x554f7c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5590908) /* 0x554f7c */);
    // 0043894f  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00438950  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00438952  2eff15c8445300         -call dword ptr cs:[0x5344c8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457096) /* 0x5344c8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00438959  89357c4f5500           -mov dword ptr [0x554f7c], esi
    app->getMemory<x86::reg32>(x86::reg32(5590908) /* 0x554f7c */) = cpu.esi;
    // 0043895f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00438961:
    // 00438961  8da5aa010000           -lea esp, [ebp + 0x1aa]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(426) /* 0x1aa */);
    // 00438967  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438968  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438969  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043896a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043896b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043896c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043896d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_438970(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00438970  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00438971  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00438972  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00438973  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00438974  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00438975  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00438977  833d7c4f550000         +cmp dword ptr [0x554f7c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5590908) /* 0x554f7c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043897e  743d                   -je 0x4389bd
    if (cpu.flags.zf)
    {
        goto L_0x004389bd;
    }
L_0x00438980:
    // 00438980  6880395f00             -push 0x5f3980
    app->getMemory<x86::reg32>(cpu.esp-4) = 6240640 /*0x5f3980*/;
    cpu.esp -= 4;
    // 00438985  8b0d7c4f5500           -mov ecx, dword ptr [0x554f7c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5590908) /* 0x554f7c */);
    // 0043898b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0043898c  2eff15d0445300         -call dword ptr cs:[0x5344d0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457104) /* 0x5344d0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00438993  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00438995  7410                   -je 0x4389a7
    if (cpu.flags.zf)
    {
        goto L_0x004389a7;
    }
    // 00438997  f60580395f0010         +test byte ptr [0x5f3980], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(6240640) /* 0x5f3980 */) & 16 /*0x10*/));
    // 0043899e  75e0                   -jne 0x438980
    if (!cpu.flags.zf)
    {
        goto L_0x00438980;
    }
    // 004389a0  b8ac395f00             -mov eax, 0x5f39ac
    cpu.eax = 6240684 /*0x5f39ac*/;
    // 004389a5  eb18                   -jmp 0x4389bf
    goto L_0x004389bf;
L_0x004389a7:
    // 004389a7  8b1d7c4f5500           -mov ebx, dword ptr [0x554f7c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5590908) /* 0x554f7c */);
    // 004389ad  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004389ae  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004389b0  2eff15c8445300         -call dword ptr cs:[0x5344c8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457096) /* 0x5344c8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004389b7  89357c4f5500           -mov dword ptr [0x554f7c], esi
    app->getMemory<x86::reg32>(x86::reg32(5590908) /* 0x554f7c */) = cpu.esi;
L_0x004389bd:
    // 004389bd  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004389bf:
    // 004389bf  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004389c0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004389c1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004389c2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004389c3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004389c4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_4389d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004389d0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004389d1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004389d2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004389d3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004389d4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004389d5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004389d6  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004389d8  81ec2c010000           -sub esp, 0x12c
    (cpu.esp) -= x86::reg32(x86::sreg32(300 /*0x12c*/));
    // 004389de  81edaa010000           -sub ebp, 0x1aa
    (cpu.ebp) -= x86::reg32(x86::sreg32(426 /*0x1aa*/));
    // 004389e4  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004389e6  e885feffff             -call 0x438870
    cpu.esp -= 4;
    sub_438870(app, cpu);
    if (cpu.terminate) return;
L_0x004389eb:
    // 004389eb  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004389ed  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004389ef  746c                   -je 0x438a5d
    if (cpu.flags.zf)
    {
        goto L_0x00438a5d;
    }
    // 004389f1  8d7d7e                 -lea edi, [ebp + 0x7e]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 004389f4  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004389f6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x004389f7:
    // 004389f7  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004389f9  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 004389fb  3c00                   +cmp al, 0
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
    // 004389fd  7410                   -je 0x438a0f
    if (cpu.flags.zf)
    {
        goto L_0x00438a0f;
    }
    // 004389ff  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00438a02  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00438a05  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00438a08  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00438a0b  3c00                   +cmp al, 0
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
    // 00438a0d  75e8                   -jne 0x4389f7
    if (!cpu.flags.zf)
    {
        goto L_0x004389f7;
    }
L_0x00438a0f:
    // 00438a0f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438a10  8d457e                 -lea eax, [ebp + 0x7e]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 00438a13  8d7d7e                 -lea edi, [ebp + 0x7e]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 00438a16  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00438a18  e823f9ffff             -call 0x438340
    cpu.esp -= 4;
    sub_438340(app, cpu);
    if (cpu.terminate) return;
    // 00438a1d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00438a1e  2bc9                   +sub ecx, ecx
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
    // 00438a20  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00438a21  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 00438a23  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00438a25  4f                     -dec edi
    (cpu.edi)--;
L_0x00438a26:
    // 00438a26  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00438a28  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00438a2a  3c00                   +cmp al, 0
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
    // 00438a2c  7410                   -je 0x438a3e
    if (cpu.flags.zf)
    {
        goto L_0x00438a3e;
    }
    // 00438a2e  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00438a31  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00438a34  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00438a37  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00438a3a  3c00                   +cmp al, 0
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
    // 00438a3c  75e8                   -jne 0x438a26
    if (!cpu.flags.zf)
    {
        goto L_0x00438a26;
    }
L_0x00438a3e:
    // 00438a3e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438a3f  ba80010000             -mov edx, 0x180
    cpu.edx = 384 /*0x180*/;
    // 00438a44  8d457e                 -lea eax, [ebp + 0x7e]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 00438a47  e874590b00             -call 0x4ee3c0
    cpu.esp -= 4;
    sub_4ee3c0(app, cpu);
    if (cpu.terminate) return;
    // 00438a4c  8d457e                 -lea eax, [ebp + 0x7e]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 00438a4f  e88c580b00             -call 0x4ee2e0
    cpu.esp -= 4;
    sub_4ee2e0(app, cpu);
    if (cpu.terminate) return;
    // 00438a54  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00438a56  e815ffffff             -call 0x438970
    cpu.esp -= 4;
    sub_438970(app, cpu);
    if (cpu.terminate) return;
    // 00438a5b  eb8e                   -jmp 0x4389eb
    goto L_0x004389eb;
L_0x00438a5d:
    // 00438a5d  ba80010000             -mov edx, 0x180
    cpu.edx = 384 /*0x180*/;
    // 00438a62  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00438a64  e857590b00             -call 0x4ee3c0
    cpu.esp -= 4;
    sub_4ee3c0(app, cpu);
    if (cpu.terminate) return;
    // 00438a69  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00438a6b  e890590b00             -call 0x4ee400
    cpu.esp -= 4;
    sub_4ee400(app, cpu);
    if (cpu.terminate) return;
    // 00438a70  85c0                   -test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00438a72  8da5aa010000           -lea esp, [ebp + 0x1aa]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(426) /* 0x1aa */);
    // 00438a78  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438a79  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438a7a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438a7b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438a7c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438a7d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438a7e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_438a80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00438a80  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00438a81  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00438a82  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00438a84  8b15704f5500           -mov edx, dword ptr [0x554f70]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5590896) /* 0x554f70 */);
    // 00438a8a  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 00438a8c  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00438a8e  7505                   -jne 0x438a95
    if (!cpu.flags.zf)
    {
        goto L_0x00438a95;
    }
    // 00438a90  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00438a92  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438a93  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438a94  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00438a95:
    // 00438a95  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00438a97  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438a98  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438a99  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_438aa0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00438aa0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00438aa1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00438aa2  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00438aa4  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00438aa6  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00438aa8  7505                   -jne 0x438aaf
    if (!cpu.flags.zf)
    {
        goto L_0x00438aaf;
    }
    // 00438aaa  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00438aac  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438aad  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438aae  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00438aaf:
    // 00438aaf  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 00438ab1  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 00438ab3  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00438ab5  7505                   -jne 0x438abc
    if (!cpu.flags.zf)
    {
        goto L_0x00438abc;
    }
    // 00438ab7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00438ab9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438aba  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438abb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00438abc:
    // 00438abc  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00438abe  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438abf  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438ac0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_438ad0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00438ad0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00438ad1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00438ad2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00438ad3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00438ad4  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00438ad6  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00438ad8  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00438ada  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
    // 00438adf  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00438ae1  e85a7b0a00             -call 0x4e0640
    cpu.esp -= 4;
    sub_4e0640(app, cpu);
    if (cpu.terminate) return;
    // 00438ae6  8931                   -mov dword ptr [ecx], esi
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.esi;
    // 00438ae8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438ae9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438aea  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438aeb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438aec  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_438af0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00438af0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00438af1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00438af2  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00438af4  8b15704f5500           -mov edx, dword ptr [0x554f70]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5590896) /* 0x554f70 */);
    // 00438afa  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00438afc  7504                   -jne 0x438b02
    if (!cpu.flags.zf)
    {
        goto L_0x00438b02;
    }
    // 00438afe  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00438b00  eb02                   -jmp 0x438b04
    goto L_0x00438b04;
L_0x00438b02:
    // 00438b02  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x00438b04:
    // 00438b04  8915cc3c5f00           -mov dword ptr [0x5f3ccc], edx
    app->getMemory<x86::reg32>(x86::reg32(6241484) /* 0x5f3ccc */) = cpu.edx;
    // 00438b0a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438b0b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438b0c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_438b10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00438b10  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00438b11  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00438b12  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00438b14  8b15cc3c5f00           -mov edx, dword ptr [0x5f3ccc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6241484) /* 0x5f3ccc */);
    // 00438b1a  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00438b1c  7504                   -jne 0x438b22
    if (!cpu.flags.zf)
    {
        goto L_0x00438b22;
    }
    // 00438b1e  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00438b20  eb13                   -jmp 0x438b35
    goto L_0x00438b35;
L_0x00438b22:
    // 00438b22  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 00438b24  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00438b26  750b                   -jne 0x438b33
    if (!cpu.flags.zf)
    {
        goto L_0x00438b33;
    }
    // 00438b28  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00438b2a  8915cc3c5f00           -mov dword ptr [0x5f3ccc], edx
    app->getMemory<x86::reg32>(x86::reg32(6241484) /* 0x5f3ccc */) = cpu.edx;
    // 00438b30  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438b31  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438b32  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00438b33:
    // 00438b33  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x00438b35:
    // 00438b35  8915cc3c5f00           -mov dword ptr [0x5f3ccc], edx
    app->getMemory<x86::reg32>(x86::reg32(6241484) /* 0x5f3ccc */) = cpu.edx;
    // 00438b3b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438b3c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438b3d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_438b40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00438b40  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00438b41  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00438b42  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00438b43  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00438b45  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00438b47  e8a4ffffff             -call 0x438af0
    cpu.esp -= 4;
    sub_438af0(app, cpu);
    if (cpu.terminate) return;
    // 00438b4c  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00438b4e:
    // 00438b4e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00438b50  740c                   -je 0x438b5e
    if (cpu.flags.zf)
    {
        goto L_0x00438b5e;
    }
    // 00438b52  39ca                   +cmp edx, ecx
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
    // 00438b54  7408                   -je 0x438b5e
    if (cpu.flags.zf)
    {
        goto L_0x00438b5e;
    }
    // 00438b56  e8b5ffffff             -call 0x438b10
    cpu.esp -= 4;
    sub_438b10(app, cpu);
    if (cpu.terminate) return;
    // 00438b5b  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00438b5c  ebf0                   -jmp 0x438b4e
    goto L_0x00438b4e;
L_0x00438b5e:
    // 00438b5e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438b5f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438b60  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438b61  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_438b70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00438b70  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00438b71  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00438b72  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00438b74  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00438b76  e875ffffff             -call 0x438af0
    cpu.esp -= 4;
    sub_438af0(app, cpu);
    if (cpu.terminate) return;
L_0x00438b7b:
    // 00438b7b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00438b7d  740b                   -je 0x438b8a
    if (cpu.flags.zf)
    {
        goto L_0x00438b8a;
    }
    // 00438b7f  3b10                   +cmp edx, dword ptr [eax]
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
    // 00438b81  7407                   -je 0x438b8a
    if (cpu.flags.zf)
    {
        goto L_0x00438b8a;
    }
    // 00438b83  e888ffffff             -call 0x438b10
    cpu.esp -= 4;
    sub_438b10(app, cpu);
    if (cpu.terminate) return;
    // 00438b88  ebf1                   -jmp 0x438b7b
    goto L_0x00438b7b;
L_0x00438b8a:
    // 00438b8a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438b8b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438b8c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_438b90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00438b90  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00438b91  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00438b92  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00438b93  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00438b94  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00438b96  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00438b98  e853ffffff             -call 0x438af0
    cpu.esp -= 4;
    sub_438af0(app, cpu);
    if (cpu.terminate) return;
    // 00438b9d  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00438b9f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00438ba1  750b                   -jne 0x438bae
    if (!cpu.flags.zf)
    {
        goto L_0x00438bae;
    }
    // 00438ba3  8915704f5500           -mov dword ptr [0x554f70], edx
    app->getMemory<x86::reg32>(x86::reg32(5590896) /* 0x554f70 */) = cpu.edx;
    // 00438ba9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438baa  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438bab  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438bac  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438bad  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00438bae:
    // 00438bae  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x00438bb0:
    // 00438bb0  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00438bb2  740b                   -je 0x438bbf
    if (cpu.flags.zf)
    {
        goto L_0x00438bbf;
    }
    // 00438bb4  e857ffffff             -call 0x438b10
    cpu.esp -= 4;
    sub_438b10(app, cpu);
    if (cpu.terminate) return;
    // 00438bb9  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00438bbb  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00438bbd  ebf1                   -jmp 0x438bb0
    goto L_0x00438bb0;
L_0x00438bbf:
    // 00438bbf  8913                   -mov dword ptr [ebx], edx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
    // 00438bc1  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 00438bc3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438bc4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438bc5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438bc6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438bc7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_438bd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00438bd0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00438bd1  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00438bd3  a1c83c5f00             -mov eax, dword ptr [0x5f3cc8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6241480) /* 0x5f3cc8 */);
    // 00438bd8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438bd9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_438be0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00438be0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00438be1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00438be2  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00438be4  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00438be7  8d45fc                 -lea eax, [ebp - 4]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00438bea  e891feffff             -call 0x438a80
    cpu.esp -= 4;
    sub_438a80(app, cpu);
    if (cpu.terminate) return;
    // 00438bef  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00438bf1:
    // 00438bf1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00438bf3  740b                   -je 0x438c00
    if (cpu.flags.zf)
    {
        goto L_0x00438c00;
    }
    // 00438bf5  8d45fc                 -lea eax, [ebp - 4]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00438bf8  e8a3feffff             -call 0x438aa0
    cpu.esp -= 4;
    sub_438aa0(app, cpu);
    if (cpu.terminate) return;
    // 00438bfd  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00438bfe  ebf1                   -jmp 0x438bf1
    goto L_0x00438bf1;
L_0x00438c00:
    // 00438c00  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00438c02  8915c83c5f00           -mov dword ptr [0x5f3cc8], edx
    app->getMemory<x86::reg32>(x86::reg32(6241480) /* 0x5f3cc8 */) = cpu.edx;
    // 00438c08  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00438c0a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438c0b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438c0c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_438c10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00438c10  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00438c11  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00438c12  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00438c13  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00438c15  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00438c17  a1704f5500             -mov eax, dword ptr [0x554f70]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5590896) /* 0x554f70 */);
    // 00438c1c  39d0                   +cmp eax, edx
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
    // 00438c1e  750b                   -jne 0x438c2b
    if (!cpu.flags.zf)
    {
        goto L_0x00438c2b;
    }
    // 00438c20  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 00438c22  a3704f5500             -mov dword ptr [0x554f70], eax
    app->getMemory<x86::reg32>(x86::reg32(5590896) /* 0x554f70 */) = cpu.eax;
    // 00438c27  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438c28  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438c29  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438c2a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00438c2b:
    // 00438c2b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00438c2d  7412                   -je 0x438c41
    if (cpu.flags.zf)
    {
        goto L_0x00438c41;
    }
    // 00438c2f  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 00438c31  39ca                   +cmp edx, ecx
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
    // 00438c33  7508                   -jne 0x438c3d
    if (!cpu.flags.zf)
    {
        goto L_0x00438c3d;
    }
    // 00438c35  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 00438c37  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 00438c39  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438c3a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438c3b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438c3c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00438c3d:
    // 00438c3d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00438c3f  ebea                   -jmp 0x438c2b
    goto L_0x00438c2b;
L_0x00438c41:
    // 00438c41  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438c42  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438c43  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438c44  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_438c50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00438c50  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00438c51  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00438c52  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00438c53  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00438c54  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00438c55  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00438c57  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00438c5a  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00438c5c  8b7520                 -mov esi, dword ptr [ebp + 0x20]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 00438c5f  c70600000000           -mov dword ptr [esi], 0
    app->getMemory<x86::reg32>(cpu.esi) = 0 /*0x0*/;
    // 00438c65  837d1800               +cmp dword ptr [ebp + 0x18], 0
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
    // 00438c69  7508                   -jne 0x438c73
    if (!cpu.flags.zf)
    {
        goto L_0x00438c73;
    }
    // 00438c6b  89751c                 -mov dword ptr [ebp + 0x1c], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */) = cpu.esi;
    // 00438c6e  897518                 -mov dword ptr [ebp + 0x18], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */) = cpu.esi;
    // 00438c71  eb32                   -jmp 0x438ca5
    goto L_0x00438ca5;
L_0x00438c73:
    // 00438c73  8d4d18                 -lea ecx, [ebp + 0x18]
    cpu.ecx = x86::reg32(cpu.ebp + x86::reg32(24) /* 0x18 */);
L_0x00438c76:
    // 00438c76  8b39                   -mov edi, dword ptr [ecx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx);
    // 00438c78  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00438c7a  7429                   -je 0x438ca5
    if (cpu.flags.zf)
    {
        goto L_0x00438ca5;
    }
    // 00438c7c  8d5710                 -lea edx, [edi + 0x10]
    cpu.edx = x86::reg32(cpu.edi + x86::reg32(16) /* 0x10 */);
    // 00438c7f  8d4610                 -lea eax, [esi + 0x10]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 00438c82  e889560b00             -call 0x4ee310
    cpu.esp -= 4;
    sub_4ee310(app, cpu);
    if (cpu.terminate) return;
    // 00438c87  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00438c89  7d08                   -jge 0x438c93
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00438c93;
    }
    // 00438c8b  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 00438c8d  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 00438c8f  8931                   -mov dword ptr [ecx], esi
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.esi;
    // 00438c91  eb12                   -jmp 0x438ca5
    goto L_0x00438ca5;
L_0x00438c93:
    // 00438c93  8b09                   -mov ecx, dword ptr [ecx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx);
    // 00438c95  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 00438c97  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00438c99  75db                   -jne 0x438c76
    if (!cpu.flags.zf)
    {
        goto L_0x00438c76;
    }
    // 00438c9b  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 00438c9d  8b451c                 -mov eax, dword ptr [ebp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 00438ca0  8930                   -mov dword ptr [eax], esi
    app->getMemory<x86::reg32>(cpu.eax) = cpu.esi;
    // 00438ca2  89751c                 -mov dword ptr [ebp + 0x1c], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */) = cpu.esi;
L_0x00438ca5:
    // 00438ca5  8d7df8                 -lea edi, [ebp - 8]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00438ca8  8d7518                 -lea esi, [ebp + 0x18]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 00438cab  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00438cac  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00438cad  8d75f8                 -lea esi, [ebp - 8]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00438cb0  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00438cb2  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00438cb3  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00438cb4  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00438cb6  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00438cb8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438cb9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438cba  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438cbb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438cbc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438cbd  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_438cc0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00438cc0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00438cc1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00438cc2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00438cc3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00438cc4  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00438cc6  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00438cc9  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00438ccb  837d1400               +cmp dword ptr [ebp + 0x14], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00438ccf  7508                   -jne 0x438cd9
    if (!cpu.flags.zf)
    {
        goto L_0x00438cd9;
    }
    // 00438cd1  8d7df8                 -lea edi, [ebp - 8]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00438cd4  8d751c                 -lea esi, [ebp + 0x1c]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 00438cd7  eb32                   -jmp 0x438d0b
    goto L_0x00438d0b;
L_0x00438cd9:
    // 00438cd9  8b5d1c                 -mov ebx, dword ptr [ebp + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 00438cdc  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00438cde  751a                   -jne 0x438cfa
    if (!cpu.flags.zf)
    {
        goto L_0x00438cfa;
    }
    // 00438ce0  8d7df8                 -lea edi, [ebp - 8]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00438ce3  8d7514                 -lea esi, [ebp + 0x14]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 00438ce6  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00438ce7  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00438ce8  8d75f8                 -lea esi, [ebp - 8]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00438ceb  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00438ced  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00438cee  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00438cef  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00438cf1  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00438cf3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438cf4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438cf5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438cf6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438cf7  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x00438cfa:
    // 00438cfa  8b7518                 -mov esi, dword ptr [ebp + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 00438cfd  8b4520                 -mov eax, dword ptr [ebp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 00438d00  8d7df8                 -lea edi, [ebp - 8]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00438d03  891e                   -mov dword ptr [esi], ebx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.ebx;
    // 00438d05  8d7514                 -lea esi, [ebp + 0x14]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 00438d08  894518                 -mov dword ptr [ebp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */) = cpu.eax;
L_0x00438d0b:
    // 00438d0b  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00438d0c  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00438d0d  8d75f8                 -lea esi, [ebp - 8]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00438d10  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00438d12  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00438d13  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00438d14  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00438d16  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00438d18  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438d19  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438d1a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438d1b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438d1c  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x90 */
void Application::sub_438d20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00438d20  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00438d21  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00438d22  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00438d23  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00438d24  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00438d26  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00438d29  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00438d2b  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
L_0x00438d2e:
    // 00438d2e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00438d30  740f                   -je 0x438d41
    if (cpu.flags.zf)
    {
        goto L_0x00438d41;
    }
    // 00438d32  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 00438d34  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00438d36  7505                   -jne 0x438d3d
    if (!cpu.flags.zf)
    {
        goto L_0x00438d3d;
    }
    // 00438d38  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 00438d3b  eb04                   -jmp 0x438d41
    goto L_0x00438d41;
L_0x00438d3d:
    // 00438d3d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00438d3f  ebed                   -jmp 0x438d2e
    goto L_0x00438d2e;
L_0x00438d41:
    // 00438d41  8d75f8                 -lea esi, [ebp - 8]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00438d44  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00438d46  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00438d47  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00438d48  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00438d4a  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00438d4c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438d4d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438d4e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438d4f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438d50  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_438d60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00438d60  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00438d61  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00438d62  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00438d63  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00438d64  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00438d65  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00438d67  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00438d6a  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00438d6c  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00438d6e  8b35704f5500           -mov esi, dword ptr [0x554f70]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5590896) /* 0x554f70 */);
    // 00438d74  894df8                 -mov dword ptr [ebp - 8], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.ecx;
    // 00438d77  894dfc                 -mov dword ptr [ebp - 4], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
L_0x00438d7a:
    // 00438d7a  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00438d7c  7431                   -je 0x438daf
    if (cpu.flags.zf)
    {
        goto L_0x00438daf;
    }
    // 00438d7e  8a9e80030000           -mov bl, byte ptr [esi + 0x380]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(896) /* 0x380 */);
    // 00438d84  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00438d86  f6c310                 +test bl, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 16 /*0x10*/));
    // 00438d89  7420                   -je 0x438dab
    if (cpu.flags.zf)
    {
        goto L_0x00438dab;
    }
    // 00438d8b  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00438d8d  e87efeffff             -call 0x438c10
    cpu.esp -= 4;
    sub_438c10(app, cpu);
    if (cpu.terminate) return;
    // 00438d92  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00438d93  8b75fc                 -mov esi, dword ptr [ebp - 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00438d96  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00438d97  8b7df8                 -mov edi, dword ptr [ebp - 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00438d9a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00438d9b  8d75f8                 -lea esi, [ebp - 8]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00438d9e  e8adfeffff             -call 0x438c50
    cpu.esp -= 4;
    sub_438c50(app, cpu);
    if (cpu.terminate) return;
    // 00438da3  8b35704f5500           -mov esi, dword ptr [0x554f70]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5590896) /* 0x554f70 */);
    // 00438da9  ebcf                   -jmp 0x438d7a
    goto L_0x00438d7a;
L_0x00438dab:
    // 00438dab  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00438dad  ebcb                   -jmp 0x438d7a
    goto L_0x00438d7a;
L_0x00438daf:
    // 00438daf  8d75f8                 -lea esi, [ebp - 8]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00438db2  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00438db4  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00438db5  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00438db6  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00438db8  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00438dba  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438dbb  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438dbc  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438dbd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438dbe  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438dbf  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_438dc0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00438dc0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00438dc1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00438dc2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00438dc3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00438dc4  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00438dc6  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00438dc9  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00438dcb  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00438dcd  8b35704f5500           -mov esi, dword ptr [0x554f70]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5590896) /* 0x554f70 */);
    // 00438dd3  894df8                 -mov dword ptr [ebp - 8], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.ecx;
    // 00438dd6  894dfc                 -mov dword ptr [ebp - 4], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
L_0x00438dd9:
    // 00438dd9  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00438ddb  7434                   -je 0x438e11
    if (cpu.flags.zf)
    {
        goto L_0x00438e11;
    }
    // 00438ddd  8bbe88030000           -mov edi, dword ptr [esi + 0x388]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(904) /* 0x388 */);
    // 00438de3  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00438de5  81ffff000000           +cmp edi, 0xff
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(255 /*0xff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00438deb  7520                   -jne 0x438e0d
    if (!cpu.flags.zf)
    {
        goto L_0x00438e0d;
    }
    // 00438ded  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00438def  e81cfeffff             -call 0x438c10
    cpu.esp -= 4;
    sub_438c10(app, cpu);
    if (cpu.terminate) return;
    // 00438df4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00438df5  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00438df8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00438df9  8b4df8                 -mov ecx, dword ptr [ebp - 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00438dfc  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00438dfd  8d75f8                 -lea esi, [ebp - 8]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00438e00  e84bfeffff             -call 0x438c50
    cpu.esp -= 4;
    sub_438c50(app, cpu);
    if (cpu.terminate) return;
    // 00438e05  8b35704f5500           -mov esi, dword ptr [0x554f70]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5590896) /* 0x554f70 */);
    // 00438e0b  ebcc                   -jmp 0x438dd9
    goto L_0x00438dd9;
L_0x00438e0d:
    // 00438e0d  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00438e0f  ebc8                   -jmp 0x438dd9
    goto L_0x00438dd9;
L_0x00438e11:
    // 00438e11  8d75f8                 -lea esi, [ebp - 8]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00438e14  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00438e16  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00438e17  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00438e18  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00438e1a  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00438e1c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438e1d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438e1e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438e1f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438e20  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_438e30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00438e30  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00438e31  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00438e32  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00438e33  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00438e34  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00438e35  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00438e37  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00438e3a  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00438e3c  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00438e3e  8b35704f5500           -mov esi, dword ptr [0x554f70]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5590896) /* 0x554f70 */);
    // 00438e44  894df8                 -mov dword ptr [ebp - 8], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.ecx;
    // 00438e47  894dfc                 -mov dword ptr [ebp - 4], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
L_0x00438e4a:
    // 00438e4a  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00438e4c  7444                   -je 0x438e92
    if (cpu.flags.zf)
    {
        goto L_0x00438e92;
    }
    // 00438e4e  8bbe88030000           -mov edi, dword ptr [esi + 0x388]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(904) /* 0x388 */);
    // 00438e54  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00438e56  81ffff000000           +cmp edi, 0xff
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(255 /*0xff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00438e5c  7430                   -je 0x438e8e
    if (cpu.flags.zf)
    {
        goto L_0x00438e8e;
    }
    // 00438e5e  8a9e80030000           -mov bl, byte ptr [esi + 0x380]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(896) /* 0x380 */);
    // 00438e64  f6c310                 +test bl, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 16 /*0x10*/));
    // 00438e67  7525                   -jne 0x438e8e
    if (!cpu.flags.zf)
    {
        goto L_0x00438e8e;
    }
    // 00438e69  f6c308                 +test bl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 8 /*0x8*/));
    // 00438e6c  7520                   -jne 0x438e8e
    if (!cpu.flags.zf)
    {
        goto L_0x00438e8e;
    }
    // 00438e6e  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00438e70  e89bfdffff             -call 0x438c10
    cpu.esp -= 4;
    sub_438c10(app, cpu);
    if (cpu.terminate) return;
    // 00438e75  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00438e76  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00438e79  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00438e7a  8b4df8                 -mov ecx, dword ptr [ebp - 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00438e7d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00438e7e  8d75f8                 -lea esi, [ebp - 8]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00438e81  e8cafdffff             -call 0x438c50
    cpu.esp -= 4;
    sub_438c50(app, cpu);
    if (cpu.terminate) return;
    // 00438e86  8b35704f5500           -mov esi, dword ptr [0x554f70]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5590896) /* 0x554f70 */);
    // 00438e8c  ebbc                   -jmp 0x438e4a
    goto L_0x00438e4a;
L_0x00438e8e:
    // 00438e8e  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00438e90  ebb8                   -jmp 0x438e4a
    goto L_0x00438e4a;
L_0x00438e92:
    // 00438e92  8d75f8                 -lea esi, [ebp - 8]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00438e95  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00438e97  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00438e98  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00438e99  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00438e9b  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00438e9d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438e9e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438e9f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438ea0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438ea1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438ea2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_438eb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00438eb0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00438eb1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00438eb2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00438eb3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00438eb4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00438eb5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00438eb6  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00438eb8  83ec20                 -sub esp, 0x20
    (cpu.esp) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00438ebb  e8300b0000             -call 0x4399f0
    cpu.esp -= 4;
    sub_4399f0(app, cpu);
    if (cpu.terminate) return;
    // 00438ec0  833d704f550000         +cmp dword ptr [0x554f70], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5590896) /* 0x554f70 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00438ec7  7475                   -je 0x438f3e
    if (cpu.flags.zf)
    {
        goto L_0x00438f3e;
    }
    // 00438ec9  8d75e0                 -lea esi, [ebp - 0x20]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 00438ecc  e85fffffff             -call 0x438e30
    cpu.esp -= 4;
    sub_438e30(app, cpu);
    if (cpu.terminate) return;
    // 00438ed1  8d75f0                 -lea esi, [ebp - 0x10]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00438ed4  e887feffff             -call 0x438d60
    cpu.esp -= 4;
    sub_438d60(app, cpu);
    if (cpu.terminate) return;
    // 00438ed9  8b4df4                 -mov ecx, dword ptr [ebp - 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00438edc  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00438edd  8b5df0                 -mov ebx, dword ptr [ebp - 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00438ee0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00438ee1  8b75e4                 -mov esi, dword ptr [ebp - 0x1c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 00438ee4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00438ee5  8b7de0                 -mov edi, dword ptr [ebp - 0x20]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 00438ee8  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00438ee9  8d75e0                 -lea esi, [ebp - 0x20]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 00438eec  e8cffdffff             -call 0x438cc0
    cpu.esp -= 4;
    sub_438cc0(app, cpu);
    if (cpu.terminate) return;
    // 00438ef1  8d75f8                 -lea esi, [ebp - 8]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00438ef4  e8c7feffff             -call 0x438dc0
    cpu.esp -= 4;
    sub_438dc0(app, cpu);
    if (cpu.terminate) return;
    // 00438ef9  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00438efc  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00438efd  8b55f8                 -mov edx, dword ptr [ebp - 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00438f00  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00438f01  8b4de4                 -mov ecx, dword ptr [ebp - 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 00438f04  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00438f05  8b5de0                 -mov ebx, dword ptr [ebp - 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 00438f08  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00438f09  8d75e0                 -lea esi, [ebp - 0x20]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 00438f0c  e8affdffff             -call 0x438cc0
    cpu.esp -= 4;
    sub_438cc0(app, cpu);
    if (cpu.terminate) return;
    // 00438f11  8d75e8                 -lea esi, [ebp - 0x18]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00438f14  a1704f5500             -mov eax, dword ptr [0x554f70]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5590896) /* 0x554f70 */);
    // 00438f19  e802feffff             -call 0x438d20
    cpu.esp -= 4;
    sub_438d20(app, cpu);
    if (cpu.terminate) return;
    // 00438f1e  8b75ec                 -mov esi, dword ptr [ebp - 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00438f21  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00438f22  8b7de8                 -mov edi, dword ptr [ebp - 0x18]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00438f25  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00438f26  8b45e4                 -mov eax, dword ptr [ebp - 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 00438f29  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00438f2a  8b55e0                 -mov edx, dword ptr [ebp - 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 00438f2d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00438f2e  8d75e0                 -lea esi, [ebp - 0x20]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 00438f31  e88afdffff             -call 0x438cc0
    cpu.esp -= 4;
    sub_438cc0(app, cpu);
    if (cpu.terminate) return;
    // 00438f36  8b45e0                 -mov eax, dword ptr [ebp - 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 00438f39  a3704f5500             -mov dword ptr [0x554f70], eax
    app->getMemory<x86::reg32>(x86::reg32(5590896) /* 0x554f70 */) = cpu.eax;
L_0x00438f3e:
    // 00438f3e  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00438f40  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438f41  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438f42  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438f43  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438f44  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438f45  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438f46  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_438f60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 00438f60  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00438f61  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00438f62  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00438f64  e8e70a0000             -call 0x439a50
    cpu.esp -= 4;
    sub_439a50(app, cpu);
    if (cpu.terminate) return;
    // 00438f69  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00438f6b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00438f6d  7443                   -je 0x438fb2
    if (cpu.flags.zf)
    {
        goto L_0x00438fb2;
    }
    // 00438f6f  83fa03                 +cmp edx, 3
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
    // 00438f72  773c                   -ja 0x438fb0
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00438fb0;
    }
    // 00438f74  ff2495488f4300         -jmp dword ptr [edx*4 + 0x438f48]
    cpu.ip = app->getMemory<x86::reg32>(4427592 + cpu.edx * 4); goto dynamic_jump;
  case 0x00438f7b:
    // 00438f7b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00438f7d  8a818f030000           -mov al, byte ptr [ecx + 0x38f]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(911) /* 0x38f */);
    // 00438f83  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438f84  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438f85  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00438f86:
    // 00438f86  8a8090030000           -mov al, byte ptr [eax + 0x390]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(912) /* 0x390 */);
    // 00438f8c  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00438f91  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438f92  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438f93  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00438f94:
    // 00438f94  8a8091030000           -mov al, byte ptr [eax + 0x391]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(913) /* 0x391 */);
    // 00438f9a  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00438f9f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438fa0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438fa1  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00438fa2:
    // 00438fa2  8a8092030000           -mov al, byte ptr [eax + 0x392]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(914) /* 0x392 */);
    // 00438fa8  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00438fad  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438fae  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438faf  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00438fb0:
    // 00438fb0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00438fb2:
    // 00438fb2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438fb3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438fb4  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_438fc0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00438fc0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00438fc1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00438fc2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00438fc3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00438fc4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00438fc5  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00438fc7  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00438fca  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00438fcc  8955f8                 -mov dword ptr [ebp - 8], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.edx;
    // 00438fcf  8d45f4                 -lea eax, [ebp - 0xc]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00438fd2  e8a9faffff             -call 0x438a80
    cpu.esp -= 4;
    sub_438a80(app, cpu);
    if (cpu.terminate) return;
    // 00438fd7  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x00438fd9:
    // 00438fd9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00438fdb  0f8454000000           -je 0x439035
    if (cpu.flags.zf)
    {
        goto L_0x00439035;
    }
    // 00438fe1  051c030000             -add eax, 0x31c
    (cpu.eax) += x86::reg32(x86::sreg32(796 /*0x31c*/));
    // 00438fe6  e8a5090000             -call 0x439990
    cpu.esp -= 4;
    sub_439990(app, cpu);
    if (cpu.terminate) return;
    // 00438feb  e840070000             -call 0x439730
    cpu.esp -= 4;
    sub_439730(app, cpu);
    if (cpu.terminate) return;
    // 00438ff0  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00438ff2  83f801                 +cmp eax, 1
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
    // 00438ff5  7209                   -jb 0x439000
    if (cpu.flags.cf)
    {
        goto L_0x00439000;
    }
    // 00438ff7  7617                   -jbe 0x439010
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00439010;
    }
    // 00438ff9  83f802                 +cmp eax, 2
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
    // 00438ffc  741e                   -je 0x43901c
    if (cpu.flags.zf)
    {
        goto L_0x0043901c;
    }
    // 00438ffe  eb26                   -jmp 0x439026
    goto L_0x00439026;
L_0x00439000:
    // 00439000  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00439002  7522                   -jne 0x439026
    if (!cpu.flags.zf)
    {
        goto L_0x00439026;
    }
    // 00439004  f6c101                 +test cl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 1 /*0x1*/));
    // 00439007  741d                   -je 0x439026
    if (cpu.flags.zf)
    {
        goto L_0x00439026;
    }
    // 00439009  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0043900e  eb16                   -jmp 0x439026
    goto L_0x00439026;
L_0x00439010:
    // 00439010  f6c102                 +test cl, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 2 /*0x2*/));
    // 00439013  7411                   -je 0x439026
    if (cpu.flags.zf)
    {
        goto L_0x00439026;
    }
    // 00439015  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0043901a  eb0a                   -jmp 0x439026
    goto L_0x00439026;
L_0x0043901c:
    // 0043901c  f6c104                 +test cl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 4 /*0x4*/));
    // 0043901f  7405                   -je 0x439026
    if (cpu.flags.zf)
    {
        goto L_0x00439026;
    }
    // 00439021  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x00439026:
    // 00439026  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00439028  7401                   -je 0x43902b
    if (cpu.flags.zf)
    {
        goto L_0x0043902b;
    }
    // 0043902a  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
L_0x0043902b:
    // 0043902b  8d45f4                 -lea eax, [ebp - 0xc]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0043902e  e86dfaffff             -call 0x438aa0
    cpu.esp -= 4;
    sub_438aa0(app, cpu);
    if (cpu.terminate) return;
    // 00439033  eba4                   -jmp 0x438fd9
    goto L_0x00438fd9;
L_0x00439035:
    // 00439035  8d04f500000000         -lea eax, [esi*8]
    cpu.eax = x86::reg32(cpu.esi * 8);
    // 0043903c  8d7808                 -lea edi, [eax + 8]
    cpu.edi = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0043903f  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00439041  b890765300             -mov eax, 0x537690
    cpu.eax = 5469840 /*0x537690*/;
    // 00439046  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00439048  e8d3850a00             -call 0x4e1620
    cpu.esp -= 4;
    sub_4e1620(app, cpu);
    if (cpu.terminate) return;
    // 0043904d  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 0043904f  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00439051  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 00439054  e8e7750a00             -call 0x4e0640
    cpu.esp -= 4;
    sub_4e0640(app, cpu);
    if (cpu.terminate) return;
    // 00439059  8d45f4                 -lea eax, [ebp - 0xc]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0043905c  e81ffaffff             -call 0x438a80
    cpu.esp -= 4;
    sub_438a80(app, cpu);
    if (cpu.terminate) return;
    // 00439061  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
L_0x00439063:
    // 00439063  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00439065  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00439067  0f846a000000           -je 0x4390d7
    if (cpu.flags.zf)
    {
        goto L_0x004390d7;
    }
    // 0043906d  8d831c030000           -lea eax, [ebx + 0x31c]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(796) /* 0x31c */);
    // 00439073  e818090000             -call 0x439990
    cpu.esp -= 4;
    sub_439990(app, cpu);
    if (cpu.terminate) return;
    // 00439078  e8b3060000             -call 0x439730
    cpu.esp -= 4;
    sub_439730(app, cpu);
    if (cpu.terminate) return;
    // 0043907d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0043907f  83f801                 +cmp eax, 1
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
    // 00439082  7209                   -jb 0x43908d
    if (cpu.flags.cf)
    {
        goto L_0x0043908d;
    }
    // 00439084  7617                   -jbe 0x43909d
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0043909d;
    }
    // 00439086  83f802                 +cmp eax, 2
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
    // 00439089  741e                   -je 0x4390a9
    if (cpu.flags.zf)
    {
        goto L_0x004390a9;
    }
    // 0043908b  eb26                   -jmp 0x4390b3
    goto L_0x004390b3;
L_0x0043908d:
    // 0043908d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043908f  7522                   -jne 0x4390b3
    if (!cpu.flags.zf)
    {
        goto L_0x004390b3;
    }
    // 00439091  f6c101                 +test cl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 1 /*0x1*/));
    // 00439094  741d                   -je 0x4390b3
    if (cpu.flags.zf)
    {
        goto L_0x004390b3;
    }
    // 00439096  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0043909b  eb16                   -jmp 0x4390b3
    goto L_0x004390b3;
L_0x0043909d:
    // 0043909d  f6c102                 +test cl, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 2 /*0x2*/));
    // 004390a0  7411                   -je 0x4390b3
    if (cpu.flags.zf)
    {
        goto L_0x004390b3;
    }
    // 004390a2  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004390a7  eb0a                   -jmp 0x4390b3
    goto L_0x004390b3;
L_0x004390a9:
    // 004390a9  f6c104                 +test cl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 4 /*0x4*/));
    // 004390ac  7405                   -je 0x4390b3
    if (cpu.flags.zf)
    {
        goto L_0x004390b3;
    }
    // 004390ae  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x004390b3:
    // 004390b3  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004390b5  7416                   -je 0x4390cd
    if (cpu.flags.zf)
    {
        goto L_0x004390cd;
    }
    // 004390b7  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004390ba  8d04fd00000000         -lea eax, [edi*8]
    cpu.eax = x86::reg32(cpu.edi * 8);
    // 004390c1  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004390c3  83c310                 +add ebx, 0x10
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004390c6  c6400400               -mov byte ptr [eax + 4], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004390ca  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004390cb  8918                   -mov dword ptr [eax], ebx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ebx;
L_0x004390cd:
    // 004390cd  8d45f4                 -lea eax, [ebp - 0xc]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004390d0  e8cbf9ffff             -call 0x438aa0
    cpu.esp -= 4;
    sub_438aa0(app, cpu);
    if (cpu.terminate) return;
    // 004390d5  eb8c                   -jmp 0x439063
    goto L_0x00439063;
L_0x004390d7:
    // 004390d7  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004390da  8930                   -mov dword ptr [eax], esi
    app->getMemory<x86::reg32>(cpu.eax) = cpu.esi;
    // 004390dc  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004390df  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004390e1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004390e2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004390e3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004390e4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004390e5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004390e6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_4390f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004390f0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004390f1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004390f2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004390f3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004390f4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004390f5  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004390f7  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004390fa  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004390fc  e84f090000             -call 0x439a50
    cpu.esp -= 4;
    sub_439a50(app, cpu);
    if (cpu.terminate) return;
    // 00439101  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00439103  0f84b1000000           -je 0x4391ba
    if (cpu.flags.zf)
    {
        goto L_0x004391ba;
    }
    // 00439109  f6808003000008         +test byte ptr [eax + 0x380], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(896) /* 0x380 */) & 8 /*0x8*/));
    // 00439110  0f85a2000000           -jne 0x4391b8
    if (!cpu.flags.zf)
    {
        goto L_0x004391b8;
    }
    // 00439116  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00439118  e8f3040000             -call 0x439610
    cpu.esp -= 4;
    sub_439610(app, cpu);
    if (cpu.terminate) return;
    // 0043911d  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0043911f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00439121  e85a050000             -call 0x439680
    cpu.esp -= 4;
    sub_439680(app, cpu);
    if (cpu.terminate) return;
    // 00439126  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00439128  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0043912a  e8b1040000             -call 0x4395e0
    cpu.esp -= 4;
    sub_4395e0(app, cpu);
    if (cpu.terminate) return;
    // 0043912f  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00439131  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 00439134  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00439136  e8f5050000             -call 0x439730
    cpu.esp -= 4;
    sub_439730(app, cpu);
    if (cpu.terminate) return;
    // 0043913b  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0043913d  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00439142  f6c202                 +test dl, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 2 /*0x2*/));
    // 00439145  7406                   -je 0x43914d
    if (cpu.flags.zf)
    {
        goto L_0x0043914d;
    }
    // 00439147  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00439149  7502                   -jne 0x43914d
    if (!cpu.flags.zf)
    {
        goto L_0x0043914d;
    }
    // 0043914b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0043914d:
    // 0043914d  f6c204                 +test dl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 4 /*0x4*/));
    // 00439150  7408                   -je 0x43915a
    if (cpu.flags.zf)
    {
        goto L_0x0043915a;
    }
    // 00439152  837dfc00               +cmp dword ptr [ebp - 4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00439156  7402                   -je 0x43915a
    if (cpu.flags.zf)
    {
        goto L_0x0043915a;
    }
    // 00439158  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0043915a:
    // 0043915a  f6c202                 +test dl, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 2 /*0x2*/));
    // 0043915d  7406                   -je 0x439165
    if (cpu.flags.zf)
    {
        goto L_0x00439165;
    }
    // 0043915f  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00439161  7502                   -jne 0x439165
    if (!cpu.flags.zf)
    {
        goto L_0x00439165;
    }
    // 00439163  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00439165:
    // 00439165  f6c204                 +test dl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 4 /*0x4*/));
    // 00439168  7406                   -je 0x439170
    if (cpu.flags.zf)
    {
        goto L_0x00439170;
    }
    // 0043916a  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0043916c  7402                   -je 0x439170
    if (cpu.flags.zf)
    {
        goto L_0x00439170;
    }
    // 0043916e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00439170:
    // 00439170  f6c220                 +test dl, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 32 /*0x20*/));
    // 00439173  7406                   -je 0x43917b
    if (cpu.flags.zf)
    {
        goto L_0x0043917b;
    }
    // 00439175  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00439177  7502                   -jne 0x43917b
    if (!cpu.flags.zf)
    {
        goto L_0x0043917b;
    }
    // 00439179  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0043917b:
    // 0043917b  f6c240                 +test dl, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 64 /*0x40*/));
    // 0043917e  7406                   -je 0x439186
    if (cpu.flags.zf)
    {
        goto L_0x00439186;
    }
    // 00439180  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00439182  7402                   -je 0x439186
    if (cpu.flags.zf)
    {
        goto L_0x00439186;
    }
    // 00439184  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00439186:
    // 00439186  f7c200000080           +test edx, 0x80000000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 2147483648 /*0x80000000*/));
    // 0043918c  752c                   -jne 0x4391ba
    if (!cpu.flags.zf)
    {
        goto L_0x004391ba;
    }
    // 0043918e  f7c200000010           +test edx, 0x10000000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 268435456 /*0x10000000*/));
    // 00439194  7406                   -je 0x43919c
    if (cpu.flags.zf)
    {
        goto L_0x0043919c;
    }
    // 00439196  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00439198  7402                   -je 0x43919c
    if (cpu.flags.zf)
    {
        goto L_0x0043919c;
    }
    // 0043919a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0043919c:
    // 0043919c  f7c200000020           +test edx, 0x20000000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 536870912 /*0x20000000*/));
    // 004391a2  7407                   -je 0x4391ab
    if (cpu.flags.zf)
    {
        goto L_0x004391ab;
    }
    // 004391a4  83f901                 +cmp ecx, 1
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
    // 004391a7  7402                   -je 0x4391ab
    if (cpu.flags.zf)
    {
        goto L_0x004391ab;
    }
    // 004391a9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004391ab:
    // 004391ab  f7c200000040           +test edx, 0x40000000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 1073741824 /*0x40000000*/));
    // 004391b1  7407                   -je 0x4391ba
    if (cpu.flags.zf)
    {
        goto L_0x004391ba;
    }
    // 004391b3  83f902                 +cmp ecx, 2
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004391b6  7402                   -je 0x4391ba
    if (cpu.flags.zf)
    {
        goto L_0x004391ba;
    }
L_0x004391b8:
    // 004391b8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004391ba:
    // 004391ba  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004391bc  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004391bd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004391be  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004391bf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004391c0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004391c1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_4391d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004391d0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004391d1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004391d2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004391d3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004391d4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004391d5  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004391d7  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004391da  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 004391dd  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004391df  e8ecf9ffff             -call 0x438bd0
    cpu.esp -= 4;
    sub_438bd0(app, cpu);
    if (cpu.terminate) return;
    // 004391e4  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 004391e7  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004391ea  8d5008                 -lea edx, [eax + 8]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004391ed  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004391ef  b890765300             -mov eax, 0x537690
    cpu.eax = 5469840 /*0x537690*/;
    // 004391f4  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004391f6  e825840a00             -call 0x4e1620
    cpu.esp -= 4;
    sub_4e1620(app, cpu);
    if (cpu.terminate) return;
    // 004391fb  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004391fd  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x004391ff:
    // 004391ff  3b4df8                 +cmp ecx, dword ptr [ebp - 8]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00439202  7d34                   -jge 0x439238
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00439238;
    }
    // 00439204  f645fc01               +test byte ptr [ebp - 4], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-4) /* -0x4 */) & 1 /*0x1*/));
    // 00439208  750e                   -jne 0x439218
    if (!cpu.flags.zf)
    {
        goto L_0x00439218;
    }
    // 0043920a  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0043920d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0043920f  e8dcfeffff             -call 0x4390f0
    cpu.esp -= 4;
    sub_4390f0(app, cpu);
    if (cpu.terminate) return;
    // 00439214  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00439216  741d                   -je 0x439235
    if (cpu.flags.zf)
    {
        goto L_0x00439235;
    }
L_0x00439218:
    // 00439218  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0043921a  e831080000             -call 0x439a50
    cpu.esp -= 4;
    sub_439a50(app, cpu);
    if (cpu.terminate) return;
    // 0043921f  f6808003000008         +test byte ptr [eax + 0x380], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(896) /* 0x380 */) & 8 /*0x8*/));
    // 00439226  750d                   -jne 0x439235
    if (!cpu.flags.zf)
    {
        goto L_0x00439235;
    }
    // 00439228  43                     -inc ebx
    (cpu.ebx)++;
    // 00439229  83c010                 +add eax, 0x10
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
    // 0043922c  c644defc00             -mov byte ptr [esi + ebx*8 - 4], 0
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(-4) /* -0x4 */ + cpu.ebx * 8) = 0 /*0x0*/;
    // 00439231  8944def8               -mov dword ptr [esi + ebx*8 - 8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-8) /* -0x8 */ + cpu.ebx * 8) = cpu.eax;
L_0x00439235:
    // 00439235  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00439236  ebc7                   -jmp 0x4391ff
    goto L_0x004391ff;
L_0x00439238:
    // 00439238  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0043923a  891f                   -mov dword ptr [edi], ebx
    app->getMemory<x86::reg32>(cpu.edi) = cpu.ebx;
    // 0043923c  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0043923e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043923f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439240  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439241  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439242  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439243  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_439250(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00439250  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00439251  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00439253  3df4010000             +cmp eax, 0x1f4
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
    // 00439258  7c10                   -jl 0x43926a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0043926a;
    }
    // 0043925a  3d57020000             +cmp eax, 0x257
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(599 /*0x257*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043925f  7f09                   -jg 0x43926a
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0043926a;
    }
    // 00439261  8b048544c95500         -mov eax, dword ptr [eax*4 + 0x55c944]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5622084) /* 0x55c944 */ + cpu.eax * 4);
    // 00439268  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439269  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0043926a:
    // 0043926a  83f832                 +cmp eax, 0x32
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(50 /*0x32*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043926d  7c0e                   -jl 0x43927d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0043927d;
    }
    // 0043926f  3df3010000             +cmp eax, 0x1f3
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(499 /*0x1f3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00439274  7f07                   -jg 0x43927d
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0043927d;
    }
    // 00439276  b8804f5500             -mov eax, 0x554f80
    cpu.eax = 5590912 /*0x554f80*/;
    // 0043927b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043927c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0043927d:
    // 0043927d  e8ce070000             -call 0x439a50
    cpu.esp -= 4;
    sub_439a50(app, cpu);
    if (cpu.terminate) return;
    // 00439282  83c010                 -add eax, 0x10
    (cpu.eax) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00439285  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439286  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_439290(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00439290  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00439291  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00439293  e8b8070000             -call 0x439a50
    cpu.esp -= 4;
    sub_439a50(app, cpu);
    if (cpu.terminate) return;
    // 00439298  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043929a  7405                   -je 0x4392a1
    if (cpu.flags.zf)
    {
        goto L_0x004392a1;
    }
    // 0043929c  0515030000             -add eax, 0x315
    (cpu.eax) += x86::reg32(x86::sreg32(789 /*0x315*/));
L_0x004392a1:
    // 004392a1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004392a2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4392b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004392b0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004392b1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004392b2  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004392b4  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004392b6  e895070000             -call 0x439a50
    cpu.esp -= 4;
    sub_439a50(app, cpu);
    if (cpu.terminate) return;
    // 004392bb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004392bd  7408                   -je 0x4392c7
    if (cpu.flags.zf)
    {
        goto L_0x004392c7;
    }
    // 004392bf  0510010000             -add eax, 0x110
    (cpu.eax) += x86::reg32(x86::sreg32(272 /*0x110*/));
    // 004392c4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004392c5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004392c6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004392c7:
    // 004392c7  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 004392ce  81faf3010000           +cmp edx, 0x1f3
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(499 /*0x1f3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004392d4  7f09                   -jg 0x4392df
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004392df;
    }
    // 004392d6  8b80b0cf5500           -mov eax, dword ptr [eax + 0x55cfb0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5623728) /* 0x55cfb0 */);
    // 004392dc  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004392dd  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004392de  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004392df:
    // 004392df  81fa57020000           +cmp edx, 0x257
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(599 /*0x257*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004392e5  7f09                   -jg 0x4392f0
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004392f0;
    }
    // 004392e7  8b802cc95500           -mov eax, dword ptr [eax + 0x55c92c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5622060) /* 0x55c92c */);
    // 004392ed  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004392ee  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004392ef  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004392f0:
    // 004392f0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004392f2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004392f3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004392f4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_439300(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00439300  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00439301  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00439302  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00439304  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00439306  e845070000             -call 0x439a50
    cpu.esp -= 4;
    sub_439a50(app, cpu);
    if (cpu.terminate) return;
    // 0043930b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043930d  740a                   -je 0x439319
    if (cpu.flags.zf)
    {
        goto L_0x00439319;
    }
L_0x0043930f:
    // 0043930f  ba94765300             -mov edx, 0x537694
    cpu.edx = 5469844 /*0x537694*/;
    // 00439314  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00439316  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439317  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439318  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00439319:
    // 00439319  83fa32                 +cmp edx, 0x32
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(50 /*0x32*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043931c  7c08                   -jl 0x439326
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00439326;
    }
    // 0043931e  81faf3010000           +cmp edx, 0x1f3
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(499 /*0x1f3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00439324  7ee9                   -jle 0x43930f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0043930f;
    }
L_0x00439326:
    // 00439326  81faf4010000           +cmp edx, 0x1f4
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(500 /*0x1f4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043932c  7c08                   -jl 0x439336
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00439336;
    }
    // 0043932e  81fa57020000           +cmp edx, 0x257
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(599 /*0x257*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00439334  7ed9                   -jle 0x43930f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0043930f;
    }
L_0x00439336:
    // 00439336  81fa58020000           +cmp edx, 0x258
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(600 /*0x258*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043933c  7c14                   -jl 0x439352
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00439352;
    }
    // 0043933e  81fabb020000           +cmp edx, 0x2bb
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(699 /*0x2bb*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00439344  7f0c                   -jg 0x439352
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00439352;
    }
    // 00439346  8b14955cc75500         -mov edx, dword ptr [edx*4 + 0x55c75c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5621596) /* 0x55c75c */ + cpu.edx * 4);
    // 0043934d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043934f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439350  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439351  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00439352:
    // 00439352  ba90765300             -mov edx, 0x537690
    cpu.edx = 5469840 /*0x537690*/;
    // 00439357  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00439359  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043935a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043935b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_439360(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00439360  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00439361  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00439362  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00439363  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00439364  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00439365  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00439367  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00439369  e8e2060000             -call 0x439a50
    cpu.esp -= 4;
    sub_439a50(app, cpu);
    if (cpu.terminate) return;
    // 0043936e  beb4287a00             -mov esi, 0x7a28b4
    cpu.esi = 8005812 /*0x7a28b4*/;
    // 00439373  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00439375  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00439377  c60200                 -mov byte ptr [edx], 0
    app->getMemory<x86::reg8>(cpu.edx) = 0 /*0x0*/;
    // 0043937a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0043937b:
    // 0043937b  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0043937d  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0043937f  3c00                   +cmp al, 0
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
    // 00439381  7410                   -je 0x439393
    if (cpu.flags.zf)
    {
        goto L_0x00439393;
    }
    // 00439383  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00439386  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00439389  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0043938c  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0043938f  3c00                   +cmp al, 0
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
    // 00439391  75e8                   -jne 0x43937b
    if (!cpu.flags.zf)
    {
        goto L_0x0043937b;
    }
L_0x00439393:
    // 00439393  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439394  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00439396  8db110010000           -lea esi, [ecx + 0x110]
    cpu.esi = x86::reg32(cpu.ecx + x86::reg32(272) /* 0x110 */);
    // 0043939c  e89fefffff             -call 0x438340
    cpu.esp -= 4;
    sub_438340(app, cpu);
    if (cpu.terminate) return;
    // 004393a1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004393a2  2bc9                   +sub ecx, ecx
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
    // 004393a4  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004393a5  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 004393a7  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 004393a9  4f                     -dec edi
    (cpu.edi)--;
L_0x004393aa:
    // 004393aa  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004393ac  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 004393ae  3c00                   +cmp al, 0
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
    // 004393b0  7410                   -je 0x4393c2
    if (cpu.flags.zf)
    {
        goto L_0x004393c2;
    }
    // 004393b2  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004393b5  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004393b8  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 004393bb  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004393be  3c00                   +cmp al, 0
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
    // 004393c0  75e8                   -jne 0x4393aa
    if (!cpu.flags.zf)
    {
        goto L_0x004393aa;
    }
L_0x004393c2:
    // 004393c2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004393c3  be98765300             -mov esi, 0x537698
    cpu.esi = 5469848 /*0x537698*/;
    // 004393c8  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004393c9  2bc9                   +sub ecx, ecx
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
    // 004393cb  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004393cc  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 004393ce  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 004393d0  4f                     -dec edi
    (cpu.edi)--;
L_0x004393d1:
    // 004393d1  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004393d3  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 004393d5  3c00                   +cmp al, 0
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
    // 004393d7  7410                   -je 0x4393e9
    if (cpu.flags.zf)
    {
        goto L_0x004393e9;
    }
    // 004393d9  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004393dc  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004393df  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 004393e2  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004393e5  3c00                   +cmp al, 0
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
    // 004393e7  75e8                   -jne 0x4393d1
    if (!cpu.flags.zf)
    {
        goto L_0x004393d1;
    }
L_0x004393e9:
    // 004393e9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004393ea  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004393ec  e80fffffff             -call 0x439300
    cpu.esp -= 4;
    sub_439300(app, cpu);
    if (cpu.terminate) return;
    // 004393f1  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004393f3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004393f4  2bc9                   +sub ecx, ecx
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
    // 004393f6  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004393f7  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 004393f9  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 004393fb  4f                     -dec edi
    (cpu.edi)--;
L_0x004393fc:
    // 004393fc  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004393fe  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00439400  3c00                   +cmp al, 0
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
    // 00439402  7410                   -je 0x439414
    if (cpu.flags.zf)
    {
        goto L_0x00439414;
    }
    // 00439404  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00439407  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0043940a  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0043940d  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00439410  3c00                   +cmp al, 0
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
    // 00439412  75e8                   -jne 0x4393fc
    if (!cpu.flags.zf)
    {
        goto L_0x004393fc;
    }
L_0x00439414:
    // 00439414  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439415  be9c765300             -mov esi, 0x53769c
    cpu.esi = 5469852 /*0x53769c*/;
    // 0043941a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0043941b  2bc9                   +sub ecx, ecx
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
    // 0043941d  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0043941e  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 00439420  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00439422  4f                     -dec edi
    (cpu.edi)--;
L_0x00439423:
    // 00439423  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00439425  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00439427  3c00                   +cmp al, 0
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
    // 00439429  7410                   -je 0x43943b
    if (cpu.flags.zf)
    {
        goto L_0x0043943b;
    }
    // 0043942b  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0043942e  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00439431  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00439434  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00439437  3c00                   +cmp al, 0
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
    // 00439439  75e8                   -jne 0x439423
    if (!cpu.flags.zf)
    {
        goto L_0x00439423;
    }
L_0x0043943b:
    // 0043943b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043943c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043943d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043943e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043943f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439440  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439441  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_439450(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00439450  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00439451  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00439452  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00439453  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00439454  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00439455  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00439457  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00439459  e8f2050000             -call 0x439a50
    cpu.esp -= 4;
    sub_439a50(app, cpu);
    if (cpu.terminate) return;
    // 0043945e  beb4287a00             -mov esi, 0x7a28b4
    cpu.esi = 8005812 /*0x7a28b4*/;
    // 00439463  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00439465  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00439467  c60200                 -mov byte ptr [edx], 0
    app->getMemory<x86::reg8>(cpu.edx) = 0 /*0x0*/;
    // 0043946a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0043946b:
    // 0043946b  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0043946d  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0043946f  3c00                   +cmp al, 0
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
    // 00439471  7410                   -je 0x439483
    if (cpu.flags.zf)
    {
        goto L_0x00439483;
    }
    // 00439473  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00439476  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00439479  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0043947c  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0043947f  3c00                   +cmp al, 0
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
    // 00439481  75e8                   -jne 0x43946b
    if (!cpu.flags.zf)
    {
        goto L_0x0043946b;
    }
L_0x00439483:
    // 00439483  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439484  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00439486  8db110010000           -lea esi, [ecx + 0x110]
    cpu.esi = x86::reg32(cpu.ecx + x86::reg32(272) /* 0x110 */);
    // 0043948c  e8afeeffff             -call 0x438340
    cpu.esp -= 4;
    sub_438340(app, cpu);
    if (cpu.terminate) return;
    // 00439491  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00439492  2bc9                   +sub ecx, ecx
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
    // 00439494  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00439495  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 00439497  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00439499  4f                     -dec edi
    (cpu.edi)--;
L_0x0043949a:
    // 0043949a  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0043949c  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0043949e  3c00                   +cmp al, 0
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
    // 004394a0  7410                   -je 0x4394b2
    if (cpu.flags.zf)
    {
        goto L_0x004394b2;
    }
    // 004394a2  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004394a5  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004394a8  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 004394ab  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004394ae  3c00                   +cmp al, 0
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
    // 004394b0  75e8                   -jne 0x43949a
    if (!cpu.flags.zf)
    {
        goto L_0x0043949a;
    }
L_0x004394b2:
    // 004394b2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004394b3  be98765300             -mov esi, 0x537698
    cpu.esi = 5469848 /*0x537698*/;
    // 004394b8  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004394b9  2bc9                   +sub ecx, ecx
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
    // 004394bb  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004394bc  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 004394be  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 004394c0  4f                     -dec edi
    (cpu.edi)--;
L_0x004394c1:
    // 004394c1  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004394c3  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 004394c5  3c00                   +cmp al, 0
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
    // 004394c7  7410                   -je 0x4394d9
    if (cpu.flags.zf)
    {
        goto L_0x004394d9;
    }
    // 004394c9  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004394cc  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004394cf  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 004394d2  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004394d5  3c00                   +cmp al, 0
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
    // 004394d7  75e8                   -jne 0x4394c1
    if (!cpu.flags.zf)
    {
        goto L_0x004394c1;
    }
L_0x004394d9:
    // 004394d9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004394da  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004394dc  e81ffeffff             -call 0x439300
    cpu.esp -= 4;
    sub_439300(app, cpu);
    if (cpu.terminate) return;
    // 004394e1  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004394e3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004394e4  2bc9                   +sub ecx, ecx
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
    // 004394e6  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004394e7  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 004394e9  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 004394eb  4f                     -dec edi
    (cpu.edi)--;
L_0x004394ec:
    // 004394ec  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004394ee  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 004394f0  3c00                   +cmp al, 0
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
    // 004394f2  7410                   -je 0x439504
    if (cpu.flags.zf)
    {
        goto L_0x00439504;
    }
    // 004394f4  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004394f7  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004394fa  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 004394fd  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00439500  3c00                   +cmp al, 0
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
    // 00439502  75e8                   -jne 0x4394ec
    if (!cpu.flags.zf)
    {
        goto L_0x004394ec;
    }
L_0x00439504:
    // 00439504  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439505  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439506  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439507  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439508  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439509  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043950a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_439510(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00439510  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00439511  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00439513  e838050000             -call 0x439a50
    cpu.esp -= 4;
    sub_439a50(app, cpu);
    if (cpu.terminate) return;
    // 00439518  0594030000             -add eax, 0x394
    (cpu.eax) += x86::reg32(x86::sreg32(916 /*0x394*/));
    // 0043951d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043951e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_439520(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00439520  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00439521  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00439523  e828050000             -call 0x439a50
    cpu.esp -= 4;
    sub_439a50(app, cpu);
    if (cpu.terminate) return;
    // 00439528  051c030000             -add eax, 0x31c
    (cpu.eax) += x86::reg32(x86::sreg32(796 /*0x31c*/));
    // 0043952d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043952e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_439530(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00439530  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00439531  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00439532  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00439534  e857040000             -call 0x439990
    cpu.esp -= 4;
    sub_439990(app, cpu);
    if (cpu.terminate) return;
    // 00439539  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0043953b  e830000000             -call 0x439570
    cpu.esp -= 4;
    sub_439570(app, cpu);
    if (cpu.terminate) return;
    // 00439540  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00439542  7405                   -je 0x439549
    if (cpu.flags.zf)
    {
        goto L_0x00439549;
    }
    // 00439544  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00439546  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439547  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439548  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00439549:
    // 00439549  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043954b  e830010000             -call 0x439680
    cpu.esp -= 4;
    sub_439680(app, cpu);
    if (cpu.terminate) return;
    // 00439550  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00439552  7405                   -je 0x439559
    if (cpu.flags.zf)
    {
        goto L_0x00439559;
    }
    // 00439554  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00439556  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439557  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439558  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00439559:
    // 00439559  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0043955e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043955f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439560  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_439570(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00439570  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00439571  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00439573  e8d8040000             -call 0x439a50
    cpu.esp -= 4;
    sub_439a50(app, cpu);
    if (cpu.terminate) return;
    // 00439578  8b8080030000           -mov eax, dword ptr [eax + 0x380]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(896) /* 0x380 */);
    // 0043957e  83e040                 -and eax, 0x40
    cpu.eax &= x86::reg32(x86::sreg32(64 /*0x40*/));
    // 00439581  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439582  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_439590(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00439590  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00439591  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00439593  e8f8030000             -call 0x439990
    cpu.esp -= 4;
    sub_439990(app, cpu);
    if (cpu.terminate) return;
    // 00439598  e8d3ffffff             -call 0x439570
    cpu.esp -= 4;
    sub_439570(app, cpu);
    if (cpu.terminate) return;
    // 0043959d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043959e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4395a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004395a0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004395a1  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004395a3  e8a8040000             -call 0x439a50
    cpu.esp -= 4;
    sub_439a50(app, cpu);
    if (cpu.terminate) return;
    // 004395a8  8b8080030000           -mov eax, dword ptr [eax + 0x380]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(896) /* 0x380 */);
    // 004395ae  83e008                 -and eax, 8
    cpu.eax &= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004395b1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004395b2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4395c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004395c0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004395c1  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004395c3  e888040000             -call 0x439a50
    cpu.esp -= 4;
    sub_439a50(app, cpu);
    if (cpu.terminate) return;
    // 004395c8  8b8080030000           -mov eax, dword ptr [eax + 0x380]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(896) /* 0x380 */);
    // 004395ce  83e004                 -and eax, 4
    cpu.eax &= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004395d1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004395d2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4395e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004395e0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004395e1  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004395e3  e868040000             -call 0x439a50
    cpu.esp -= 4;
    sub_439a50(app, cpu);
    if (cpu.terminate) return;
    // 004395e8  8b8080030000           -mov eax, dword ptr [eax + 0x380]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(896) /* 0x380 */);
    // 004395ee  83e002                 -and eax, 2
    cpu.eax &= x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004395f1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004395f2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_439600(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00439600  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00439601  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00439603  e888030000             -call 0x439990
    cpu.esp -= 4;
    sub_439990(app, cpu);
    if (cpu.terminate) return;
    // 00439608  e8d3ffffff             -call 0x4395e0
    cpu.esp -= 4;
    sub_4395e0(app, cpu);
    if (cpu.terminate) return;
    // 0043960d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043960e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_439610(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00439610  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00439611  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00439613  e808ffffff             -call 0x439520
    cpu.esp -= 4;
    sub_439520(app, cpu);
    if (cpu.terminate) return;
    // 00439618  e803000000             -call 0x439620
    cpu.esp -= 4;
    sub_439620(app, cpu);
    if (cpu.terminate) return;
    // 0043961d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043961e  c3                     -ret 
    cpu.esp += 4;
    return;
}

}
