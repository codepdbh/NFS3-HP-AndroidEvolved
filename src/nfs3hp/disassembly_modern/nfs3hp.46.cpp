#include "nfs3hp.h"
#include <lib/thread.h>

namespace nfs3hp
{

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_5016c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005016c0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005016c1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005016c2  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 005016c4  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 005016c6  c1e104                 -shl ecx, 4
    cpu.ecx <<= 4 /*0x4*/ % 32;
    // 005016c9  81c158f69e00           -add ecx, 0x9ef658
    (cpu.ecx) += x86::reg32(x86::sreg32(10417752 /*0x9ef658*/));
    // 005016cf  8a6104                 -mov ah, byte ptr [ecx + 4]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 005016d2  80fc07                 +cmp ah, 7
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(7 /*0x7*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 005016d5  743c                   -je 0x501713
    if (cpu.flags.zf)
    {
        goto L_0x00501713;
    }
    // 005016d7  80fc09                 +cmp ah, 9
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(9 /*0x9*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 005016da  7434                   -je 0x501710
    if (cpu.flags.zf)
    {
        goto L_0x00501710;
    }
    // 005016dc  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 005016de  0f859f000000           -jne 0x501783
    if (!cpu.flags.zf)
    {
        goto L_0x00501783;
    }
    // 005016e4  80790302               +cmp byte ptr [ecx + 3], 2
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(3) /* 0x3 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(2 /*0x2*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 005016e8  7502                   -jne 0x5016ec
    if (!cpu.flags.zf)
    {
        goto L_0x005016ec;
    }
    // 005016ea  01d2                   -add edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx));
L_0x005016ec:
    // 005016ec  8a6102                 -mov ah, byte ptr [ecx + 2]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(2) /* 0x2 */);
    // 005016ef  80fc10                 +cmp ah, 0x10
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
    // 005016f2  0f8572000000           -jne 0x50176a
    if (!cpu.flags.zf)
    {
        goto L_0x0050176a;
    }
    // 005016f8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 005016fa  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 005016fc  7e12                   -jle 0x501710
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00501710;
    }
    // 005016fe  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
L_0x00501700:
    // 00501700  40                     -inc eax
    (cpu.eax)++;
    // 00501701  66c7010000             -mov word ptr [ecx], 0
    app->getMemory<x86::reg16>(cpu.ecx) = 0 /*0x0*/;
    // 00501706  83c102                 -add ecx, 2
    (cpu.ecx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00501709  39d0                   +cmp eax, edx
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
    // 0050170b  7cf3                   -jl 0x501700
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00501700;
    }
    // 0050170d  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x00501710:
    // 00501710  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00501711  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00501712  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00501713:
    // 00501713  83c21b                 -add edx, 0x1b
    (cpu.edx) += x86::reg32(x86::sreg32(27 /*0x1b*/));
    // 00501716  bb1c000000             -mov ebx, 0x1c
    cpu.ebx = 28 /*0x1c*/;
    // 0050171b  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0050171d  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00501720  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00501722  66c7060000             -mov word ptr [esi], 0
    app->getMemory<x86::reg16>(cpu.esi) = 0 /*0x0*/;
    // 00501727  66c746020000           -mov word ptr [esi + 2], 0
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(2) /* 0x2 */) = 0 /*0x0*/;
    // 0050172d  66c746040000           -mov word ptr [esi + 4], 0
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 00501733  8d148500000000         -lea edx, [eax*4]
    cpu.edx = x86::reg32(cpu.eax * 4);
    // 0050173a  66c746060000           -mov word ptr [esi + 6], 0
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(6) /* 0x6 */) = 0 /*0x0*/;
    // 00501740  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00501742  83c608                 -add esi, 8
    (cpu.esi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00501745  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00501747  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 0050174a  8a7903                 -mov bh, byte ptr [ecx + 3]
    cpu.bh = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(3) /* 0x3 */);
    // 0050174d  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0050174f  80ff02                 +cmp bh, 2
    {
        x86::reg8 tmp1 = cpu.bh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(2 /*0x2*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00501752  7502                   -jne 0x501756
    if (!cpu.flags.zf)
    {
        goto L_0x00501756;
    }
    // 00501754  01d2                   -add edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx));
L_0x00501756:
    // 00501756  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00501758  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0050175a  7eb4                   -jle 0x501710
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00501710;
    }
    // 0050175c  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
L_0x0050175e:
    // 0050175e  40                     -inc eax
    (cpu.eax)++;
    // 0050175f  c60100                 -mov byte ptr [ecx], 0
    app->getMemory<x86::reg8>(cpu.ecx) = 0 /*0x0*/;
    // 00501762  41                     -inc ecx
    (cpu.ecx)++;
    // 00501763  39d0                   +cmp eax, edx
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
    // 00501765  7cf7                   -jl 0x50175e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0050175e;
    }
    // 00501767  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00501768  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00501769  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050176a:
    // 0050176a  80fc08                 +cmp ah, 8
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(8 /*0x8*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0050176d  75a1                   -jne 0x501710
    if (!cpu.flags.zf)
    {
        goto L_0x00501710;
    }
    // 0050176f  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00501771  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00501773  7e9b                   -jle 0x501710
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00501710;
    }
    // 00501775  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x00501777:
    // 00501777  41                     -inc ecx
    (cpu.ecx)++;
    // 00501778  c60000                 -mov byte ptr [eax], 0
    app->getMemory<x86::reg8>(cpu.eax) = 0 /*0x0*/;
    // 0050177b  40                     -inc eax
    (cpu.eax)++;
    // 0050177c  39d1                   +cmp ecx, edx
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
    // 0050177e  7cf7                   -jl 0x501777
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00501777;
    }
    // 00501780  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00501781  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00501782  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00501783:
    // 00501783  bae8e55400             -mov edx, 0x54e5e8
    cpu.edx = 5563880 /*0x54e5e8*/;
    // 00501788  b9f8e55400             -mov ecx, 0x54e5f8
    cpu.ecx = 5563896 /*0x54e5f8*/;
    // 0050178d  bb4a000000             -mov ebx, 0x4a
    cpu.ebx = 74 /*0x4a*/;
    // 00501792  6808e65400             -push 0x54e608
    app->getMemory<x86::reg32>(cpu.esp-4) = 5563912 /*0x54e608*/;
    cpu.esp -= 4;
    // 00501797  891590215500           -mov dword ptr [0x552190], edx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edx;
    // 0050179d  890d94215500           -mov dword ptr [0x552194], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ecx;
    // 005017a3  891d98215500           -mov dword ptr [0x552198], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ebx;
    // 005017a9  e862f8efff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 005017ae  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 005017b1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005017b2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005017b3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_5017b4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005017b4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 005017b6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_5017c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005017c0  c70001000000           -mov dword ptr [eax], 1
    app->getMemory<x86::reg32>(cpu.eax) = 1 /*0x1*/;
    // 005017c6  c7809000000000000000   -mov dword ptr [eax + 0x90], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(144) /* 0x90 */) = 0 /*0x0*/;
    // 005017d0  c7406c0f000000         -mov dword ptr [eax + 0x6c], 0xf
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(108) /* 0x6c */) = 15 /*0xf*/;
    // 005017d7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_5017d8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005017d8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005017d9  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 005017db  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 005017dd  81c298000000           -add edx, 0x98
    (cpu.edx) += x86::reg32(x86::sreg32(152 /*0x98*/));
L_0x005017e3:
    // 005017e3  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 005017e9  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 005017ec  39d0                   +cmp eax, edx
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
    // 005017ee  75f3                   -jne 0x5017e3
    if (!cpu.flags.zf)
    {
        goto L_0x005017e3;
    }
    // 005017f0  c7410400000000         -mov dword ptr [ecx + 4], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 005017f7  c741087f000000         -mov dword ptr [ecx + 8], 0x7f
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = 127 /*0x7f*/;
    // 005017fe  c7410c00000000         -mov dword ptr [ecx + 0xc], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 00501805  c741107f000000         -mov dword ptr [ecx + 0x10], 0x7f
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */) = 127 /*0x7f*/;
    // 0050180c  c74114ffffffff         -mov dword ptr [ecx + 0x14], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */) = 4294967295 /*0xffffffff*/;
    // 00501813  c7411800000000         -mov dword ptr [ecx + 0x18], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 0050181a  c7411c3c000000         -mov dword ptr [ecx + 0x1c], 0x3c
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */) = 60 /*0x3c*/;
    // 00501821  c74120ffffffff         -mov dword ptr [ecx + 0x20], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = 4294967295 /*0xffffffff*/;
    // 00501828  c7412401000000         -mov dword ptr [ecx + 0x24], 1
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(36) /* 0x24 */) = 1 /*0x1*/;
    // 0050182f  c7412800000000         -mov dword ptr [ecx + 0x28], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */) = 0 /*0x0*/;
    // 00501836  c7412c01000000         -mov dword ptr [ecx + 0x2c], 1
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(44) /* 0x2c */) = 1 /*0x1*/;
    // 0050183d  c7413040000000         -mov dword ptr [ecx + 0x30], 0x40
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(48) /* 0x30 */) = 64 /*0x40*/;
    // 00501844  c7413400000000         -mov dword ptr [ecx + 0x34], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(52) /* 0x34 */) = 0 /*0x0*/;
    // 0050184b  c741387f000000         -mov dword ptr [ecx + 0x38], 0x7f
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(56) /* 0x38 */) = 127 /*0x7f*/;
    // 00501852  c7413c00000000         -mov dword ptr [ecx + 0x3c], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(60) /* 0x3c */) = 0 /*0x0*/;
    // 00501859  c7414000000000         -mov dword ptr [ecx + 0x40], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(64) /* 0x40 */) = 0 /*0x0*/;
    // 00501860  c7414400000000         -mov dword ptr [ecx + 0x44], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(68) /* 0x44 */) = 0 /*0x0*/;
    // 00501867  c7414800000000         -mov dword ptr [ecx + 0x48], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(72) /* 0x48 */) = 0 /*0x0*/;
    // 0050186e  c7414c00000000         -mov dword ptr [ecx + 0x4c], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(76) /* 0x4c */) = 0 /*0x0*/;
    // 00501875  c7415400000000         -mov dword ptr [ecx + 0x54], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(84) /* 0x54 */) = 0 /*0x0*/;
    // 0050187c  c7415c00000000         -mov dword ptr [ecx + 0x5c], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(92) /* 0x5c */) = 0 /*0x0*/;
    // 00501883  c741707f000000         -mov dword ptr [ecx + 0x70], 0x7f
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(112) /* 0x70 */) = 127 /*0x7f*/;
    // 0050188a  c7417400000000         -mov dword ptr [ecx + 0x74], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(116) /* 0x74 */) = 0 /*0x0*/;
    // 00501891  c7417800000000         -mov dword ptr [ecx + 0x78], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(120) /* 0x78 */) = 0 /*0x0*/;
    // 00501898  c7417c00000000         -mov dword ptr [ecx + 0x7c], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(124) /* 0x7c */) = 0 /*0x0*/;
    // 0050189f  c7818000000000000000   -mov dword ptr [ecx + 0x80], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(128) /* 0x80 */) = 0 /*0x0*/;
    // 005018a9  c7818400000000000000   -mov dword ptr [ecx + 0x84], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(132) /* 0x84 */) = 0 /*0x0*/;
    // 005018b3  c7818c00000000000000   -mov dword ptr [ecx + 0x8c], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(140) /* 0x8c */) = 0 /*0x0*/;
    // 005018bd  c7818800000000000000   -mov dword ptr [ecx + 0x88], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(136) /* 0x88 */) = 0 /*0x0*/;
    // 005018c7  c7819400000001000000   -mov dword ptr [ecx + 0x94], 1
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(148) /* 0x94 */) = 1 /*0x1*/;
    // 005018d1  c74164a8785600         -mov dword ptr [ecx + 0x64], 0x5678a8
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(100) /* 0x64 */) = 5666984 /*0x5678a8*/;
    // 005018d8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005018d9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_5018dc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005018dc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 005018dd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005018de  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005018df  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 005018e0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005018e1  8b4a48                 -mov ecx, dword ptr [edx + 0x48]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(72) /* 0x48 */);
    // 005018e4  014848                 -add dword ptr [eax + 0x48], ecx
    (app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */)) += x86::reg32(x86::sreg32(cpu.ecx));
    // 005018e7  8b7054                 -mov esi, dword ptr [eax + 0x54]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(84) /* 0x54 */);
    // 005018ea  8b4a54                 -mov ecx, dword ptr [edx + 0x54]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(84) /* 0x54 */);
    // 005018ed  01ce                   -add esi, ecx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ecx));
    // 005018ef  897054                 -mov dword ptr [eax + 0x54], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(84) /* 0x54 */) = cpu.esi;
    // 005018f2  8b785c                 -mov edi, dword ptr [eax + 0x5c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(92) /* 0x5c */);
    // 005018f5  8b4a5c                 -mov ecx, dword ptr [edx + 0x5c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(92) /* 0x5c */);
    // 005018f8  01cf                   -add edi, ecx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ecx));
    // 005018fa  89785c                 -mov dword ptr [eax + 0x5c], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(92) /* 0x5c */) = cpu.edi;
    // 005018fd  8b6874                 -mov ebp, dword ptr [eax + 0x74]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(116) /* 0x74 */);
    // 00501900  8b4a74                 -mov ecx, dword ptr [edx + 0x74]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(116) /* 0x74 */);
    // 00501903  01cd                   -add ebp, ecx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00501905  896874                 -mov dword ptr [eax + 0x74], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(116) /* 0x74 */) = cpu.ebp;
    // 00501908  8b9880000000           -mov ebx, dword ptr [eax + 0x80]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(128) /* 0x80 */);
    // 0050190e  039a80000000           -add ebx, dword ptr [edx + 0x80]
    (cpu.ebx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(128) /* 0x80 */)));
    // 00501914  8b7064                 -mov esi, dword ptr [eax + 0x64]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(100) /* 0x64 */);
    // 00501917  899880000000           -mov dword ptr [eax + 0x80], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(128) /* 0x80 */) = cpu.ebx;
    // 0050191d  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0050191f  7506                   -jne 0x501927
    if (!cpu.flags.zf)
    {
        goto L_0x00501927;
    }
    // 00501921  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00501922  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00501923  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00501924  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00501925  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00501926  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00501927:
    // 00501927  8b5264                 -mov edx, dword ptr [edx + 0x64]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(100) /* 0x64 */);
    // 0050192a  8d3c16                 -lea edi, [esi + edx]
    cpu.edi = x86::reg32(cpu.esi + cpu.edx * 1);
    // 0050192d  897864                 -mov dword ptr [eax + 0x64], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(100) /* 0x64 */) = cpu.edi;
    // 00501930  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00501931  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00501932  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00501933  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00501934  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00501935  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_501938(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00501938  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00501939  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050193a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0050193b  8a3db0785600           -mov bh, byte ptr [0x5678b0]
    cpu.bh = app->getMemory<x86::reg8>(x86::reg32(5666992) /* 0x5678b0 */);
    // 00501941  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
L_0x00501943:
    // 00501943  fec7                   +inc bh
    {
        x86::reg8& tmp = cpu.bh;
        cpu.flags.of = ~(1 & (tmp >> 7));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 7);
        cpu.set_szp(tmp);
    }
    // 00501945  742a                   -je 0x501971
    if (cpu.flags.zf)
    {
        goto L_0x00501971;
    }
L_0x00501947:
    // 00501947  b83c9ba000             -mov eax, 0xa09b3c
    cpu.eax = 10525500 /*0xa09b3c*/;
    // 0050194c  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
L_0x0050194e:
    // 0050194e  3a480c                 +cmp cl, byte ptr [eax + 0xc]
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(12) /* 0xc */)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00501951  7407                   -je 0x50195a
    if (cpu.flags.zf)
    {
        goto L_0x0050195a;
    }
    // 00501953  8a583b                 -mov bl, byte ptr [eax + 0x3b]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(59) /* 0x3b */);
    // 00501956  38fb                   +cmp bl, bh
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
    // 00501958  74e9                   -je 0x501943
    if (cpu.flags.zf)
    {
        goto L_0x00501943;
    }
L_0x0050195a:
    // 0050195a  42                     -inc edx
    (cpu.edx)++;
    // 0050195b  83c060                 -add eax, 0x60
    (cpu.eax) += x86::reg32(x86::sreg32(96 /*0x60*/));
    // 0050195e  83fa10                 +cmp edx, 0x10
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
    // 00501961  7ceb                   -jl 0x50194e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0050194e;
    }
    // 00501963  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00501965  88f8                   -mov al, bh
    cpu.al = cpu.bh;
    // 00501967  883db0785600           -mov byte ptr [0x5678b0], bh
    app->getMemory<x86::reg8>(x86::reg32(5666992) /* 0x5678b0 */) = cpu.bh;
    // 0050196d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050196e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050196f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00501970  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00501971:
    // 00501971  fec7                   +inc bh
    {
        x86::reg8& tmp = cpu.bh;
        cpu.flags.of = ~(1 & (tmp >> 7));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 7);
        cpu.set_szp(tmp);
    }
    // 00501973  ebd2                   -jmp 0x501947
    goto L_0x00501947;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_501978(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00501978  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00501979  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050197a  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0050197b  83ec1c                 -sub esp, 0x1c
    (cpu.esp) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0050197e  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00501982  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00501984  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00501986  8b54242c               -mov edx, dword ptr [esp + 0x2c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0050198a  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0050198d  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 00501990  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 00501994  8b4305                 -mov eax, dword ptr [ebx + 5]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5) /* 0x5 */);
    // 00501997  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 0050199a  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0050199e  8b4306                 -mov eax, dword ptr [ebx + 6]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(6) /* 0x6 */);
    // 005019a1  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 005019a4  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 005019a8  8b4307                 -mov eax, dword ptr [ebx + 7]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(7) /* 0x7 */);
    // 005019ab  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 005019ae  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 005019b2  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 005019b4  e823ffffff             -call 0x5018dc
    cpu.esp -= 4;
    sub_5018dc(app, cpu);
    if (cpu.terminate) return;
    // 005019b9  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 005019bd  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 005019bf  7c05                   -jl 0x5019c6
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x005019c6;
    }
    // 005019c1  83fa7f                 +cmp edx, 0x7f
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(127 /*0x7f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005019c4  7e32                   -jle 0x5019f8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x005019f8;
    }
L_0x005019c6:
    // 005019c6  bb38e65400             -mov ebx, 0x54e638
    cpu.ebx = 5563960 /*0x54e638*/;
    // 005019cb  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 005019cf  bd48e65400             -mov ebp, 0x54e648
    cpu.ebp = 5563976 /*0x54e648*/;
    // 005019d4  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 005019d5  b89e000000             -mov eax, 0x9e
    cpu.eax = 158 /*0x9e*/;
    // 005019da  891d90215500           -mov dword ptr [0x552190], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ebx;
    // 005019e0  6860e65400             -push 0x54e660
    app->getMemory<x86::reg32>(cpu.esp-4) = 5564000 /*0x54e660*/;
    cpu.esp -= 4;
    // 005019e5  892d94215500           -mov dword ptr [0x552194], ebp
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebp;
    // 005019eb  a398215500             -mov dword ptr [0x552198], eax
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.eax;
    // 005019f0  e81bf6efff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 005019f5  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x005019f8:
    // 005019f8  8b4c2418               -mov ecx, dword ptr [esp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 005019fc  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 005019fe  7c05                   -jl 0x501a05
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00501a05;
    }
    // 00501a00  83f97f                 +cmp ecx, 0x7f
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(127 /*0x7f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00501a03  7e32                   -jle 0x501a37
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00501a37;
    }
L_0x00501a05:
    // 00501a05  bd38e65400             -mov ebp, 0x54e638
    cpu.ebp = 5563960 /*0x54e638*/;
    // 00501a0a  8b4c2418               -mov ecx, dword ptr [esp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00501a0e  b848e65400             -mov eax, 0x54e648
    cpu.eax = 5563976 /*0x54e648*/;
    // 00501a13  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00501a14  baa6000000             -mov edx, 0xa6
    cpu.edx = 166 /*0xa6*/;
    // 00501a19  892d90215500           -mov dword ptr [0x552190], ebp
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ebp;
    // 00501a1f  6894e65400             -push 0x54e694
    app->getMemory<x86::reg32>(cpu.esp-4) = 5564052 /*0x54e694*/;
    cpu.esp -= 4;
    // 00501a24  a394215500             -mov dword ptr [0x552194], eax
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.eax;
    // 00501a29  891598215500           -mov dword ptr [0x552198], edx
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.edx;
    // 00501a2f  e8dcf5efff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 00501a34  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x00501a37:
    // 00501a37  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00501a3b  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00501a3d  7c05                   -jl 0x501a44
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00501a44;
    }
    // 00501a3f  83fb7f                 +cmp ebx, 0x7f
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(127 /*0x7f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00501a42  7e32                   -jle 0x501a76
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00501a76;
    }
L_0x00501a44:
    // 00501a44  b838e65400             -mov eax, 0x54e638
    cpu.eax = 5563960 /*0x54e638*/;
    // 00501a49  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00501a4d  ba48e65400             -mov edx, 0x54e648
    cpu.edx = 5563976 /*0x54e648*/;
    // 00501a52  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00501a53  b9ad000000             -mov ecx, 0xad
    cpu.ecx = 173 /*0xad*/;
    // 00501a58  a390215500             -mov dword ptr [0x552190], eax
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.eax;
    // 00501a5d  68c4e65400             -push 0x54e6c4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5564100 /*0x54e6c4*/;
    cpu.esp -= 4;
    // 00501a62  891594215500           -mov dword ptr [0x552194], edx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.edx;
    // 00501a68  890d98215500           -mov dword ptr [0x552198], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ecx;
    // 00501a6e  e89df5efff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 00501a73  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x00501a76:
    // 00501a76  8b4630                 -mov eax, dword ptr [esi + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(48) /* 0x30 */);
    // 00501a79  8b6e34                 -mov ebp, dword ptr [esi + 0x34]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(52) /* 0x34 */);
    // 00501a7c  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 00501a80  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00501a82  7411                   -je 0x501a95
    if (cpu.flags.zf)
    {
        goto L_0x00501a95;
    }
    // 00501a84  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00501a86  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00501a8a  e8510a0200             -call 0x5224e0
    cpu.esp -= 4;
    sub_5224e0(app, cpu);
    if (cpu.terminate) return;
    // 00501a8f  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00501a91  89542414               -mov dword ptr [esp + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.edx;
L_0x00501a95:
    // 00501a95  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00501a99  83f97f                 +cmp ecx, 0x7f
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(127 /*0x7f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00501a9c  0f8eda020000           -jle 0x501d7c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00501d7c;
    }
    // 00501aa2  c74424147f000000       -mov dword ptr [esp + 0x14], 0x7f
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = 127 /*0x7f*/;
L_0x00501aaa:
    // 00501aaa  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00501aae  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00501ab0  7c05                   -jl 0x501ab7
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00501ab7;
    }
    // 00501ab2  83fa7f                 +cmp edx, 0x7f
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(127 /*0x7f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00501ab5  7e32                   -jle 0x501ae9
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00501ae9;
    }
L_0x00501ab7:
    // 00501ab7  bb38e65400             -mov ebx, 0x54e638
    cpu.ebx = 5563960 /*0x54e638*/;
    // 00501abc  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00501ac0  bd48e65400             -mov ebp, 0x54e648
    cpu.ebp = 5563976 /*0x54e648*/;
    // 00501ac5  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00501ac6  b8c3000000             -mov eax, 0xc3
    cpu.eax = 195 /*0xc3*/;
    // 00501acb  891d90215500           -mov dword ptr [0x552190], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ebx;
    // 00501ad1  68f8e65400             -push 0x54e6f8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5564152 /*0x54e6f8*/;
    cpu.esp -= 4;
    // 00501ad6  892d94215500           -mov dword ptr [0x552194], ebp
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebp;
    // 00501adc  a398215500             -mov dword ptr [0x552198], eax
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.eax;
    // 00501ae1  e82af5efff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 00501ae6  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x00501ae9:
    // 00501ae9  89e1                   -mov ecx, esp
    cpu.ecx = cpu.esp;
    // 00501aeb  8b5e18                 -mov ebx, dword ptr [esi + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 00501aee  8b562c                 -mov edx, dword ptr [esi + 0x2c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(44) /* 0x2c */);
    // 00501af1  8b4614                 -mov eax, dword ptr [esi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 00501af4  e873ddffff             -call 0x4ff86c
    cpu.esp -= 4;
    sub_4ff86c(app, cpu);
    if (cpu.terminate) return;
    // 00501af9  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00501afb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00501afd  0f8c70020000           -jl 0x501d73
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00501d73;
    }
    // 00501b03  8d148500000000         -lea edx, [eax*4]
    cpu.edx = x86::reg32(cpu.eax * 4);
    // 00501b0a  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00501b0c  b93c9ba000             -mov ecx, 0xa09b3c
    cpu.ecx = 10525500 /*0xa09b3c*/;
    // 00501b11  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 00501b14  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00501b16  8a8694000000           -mov al, byte ptr [esi + 0x94]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(148) /* 0x94 */);
    // 00501b1c  884137                 -mov byte ptr [ecx + 0x37], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(55) /* 0x37 */) = cpu.al;
    // 00501b1f  668b4640               -mov ax, word ptr [esi + 0x40]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(64) /* 0x40 */);
    // 00501b23  66894110               -mov word ptr [ecx + 0x10], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(16) /* 0x10 */) = cpu.ax;
    // 00501b27  8b542430               -mov edx, dword ptr [esp + 0x30]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 00501b2b  668b461c               -mov ax, word ptr [esi + 0x1c]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 00501b2f  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00501b31  6bc064                 -imul eax, eax, 0x64
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(100 /*0x64*/)));
    // 00501b34  66294110               -sub word ptr [ecx + 0x10], ax
    (app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(16) /* 0x10 */)) -= x86::reg16(x86::sreg16(cpu.ax));
    // 00501b38  83be9000000000         +cmp dword ptr [esi + 0x90], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(144) /* 0x90 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00501b3f  7408                   -je 0x501b49
    if (cpu.flags.zf)
    {
        goto L_0x00501b49;
    }
    // 00501b41  8b442438               -mov eax, dword ptr [esp + 0x38]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 00501b45  66014110               -add word ptr [ecx + 0x10], ax
    (app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(16) /* 0x10 */)) += x86::reg16(x86::sreg16(cpu.ax));
L_0x00501b49:
    // 00501b49  8b4644                 -mov eax, dword ptr [esi + 0x44]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(68) /* 0x44 */);
    // 00501b4c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00501b4e  7409                   -je 0x501b59
    if (cpu.flags.zf)
    {
        goto L_0x00501b59;
    }
    // 00501b50  e88b090200             -call 0x5224e0
    cpu.esp -= 4;
    sub_5224e0(app, cpu);
    if (cpu.terminate) return;
    // 00501b55  66014110               -add word ptr [ecx + 0x10], ax
    (app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(16) /* 0x10 */)) += x86::reg16(x86::sreg16(cpu.ax));
L_0x00501b59:
    // 00501b59  8b4648                 -mov eax, dword ptr [esi + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(72) /* 0x48 */);
    // 00501b5c  89414c                 -mov dword ptr [ecx + 0x4c], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(76) /* 0x4c */) = cpu.eax;
    // 00501b5f  8b4654                 -mov eax, dword ptr [esi + 0x54]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(84) /* 0x54 */);
    // 00501b62  894150                 -mov dword ptr [ecx + 0x50], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(80) /* 0x50 */) = cpu.eax;
    // 00501b65  8b465c                 -mov eax, dword ptr [esi + 0x5c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(92) /* 0x5c */);
    // 00501b68  894154                 -mov dword ptr [ecx + 0x54], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(84) /* 0x54 */) = cpu.eax;
    // 00501b6b  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00501b6d  88410d                 -mov byte ptr [ecx + 0xd], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(13) /* 0xd */) = cpu.al;
    // 00501b70  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00501b74  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 00501b77  894120                 -mov dword ptr [ecx + 0x20], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 00501b7a  8a442418               -mov al, byte ptr [esp + 0x18]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00501b7e  884145                 -mov byte ptr [ecx + 0x45], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(69) /* 0x45 */) = cpu.al;
    // 00501b81  8a6137                 -mov ah, byte ptr [ecx + 0x37]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(55) /* 0x37 */);
    // 00501b84  c7411800000000         -mov dword ptr [ecx + 0x18], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 00501b8b  80fc01                 +cmp ah, 1
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
    // 00501b8e  7417                   -je 0x501ba7
    if (cpu.flags.zf)
    {
        goto L_0x00501ba7;
    }
    // 00501b90  8b4134                 -mov eax, dword ptr [ecx + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(52) /* 0x34 */);
    // 00501b93  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00501b97  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 00501b9a  83ea40                 -sub edx, 0x40
    (cpu.edx) -= x86::reg32(x86::sreg32(64 /*0x40*/));
    // 00501b9d  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00501ba0  83c040                 -add eax, 0x40
    (cpu.eax) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 00501ba3  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
L_0x00501ba7:
    // 00501ba7  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00501bab  03442418               -add eax, dword ptr [esp + 0x18]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */)));
    // 00501baf  83e840                 -sub eax, 0x40
    (cpu.eax) -= x86::reg32(x86::sreg32(64 /*0x40*/));
    // 00501bb2  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 00501bb6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00501bb8  0f8cd1010000           -jl 0x501d8f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00501d8f;
    }
    // 00501bbe  83f87f                 +cmp eax, 0x7f
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(127 /*0x7f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00501bc1  7e08                   -jle 0x501bcb
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00501bcb;
    }
    // 00501bc3  c74424187f000000       -mov dword ptr [esp + 0x18], 0x7f
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = 127 /*0x7f*/;
L_0x00501bcb:
    // 00501bcb  8b4150                 -mov eax, dword ptr [ecx + 0x50]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(80) /* 0x50 */);
    // 00501bce  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00501bd0  740b                   -je 0x501bdd
    if (cpu.flags.zf)
    {
        goto L_0x00501bdd;
    }
    // 00501bd2  03442418               -add eax, dword ptr [esp + 0x18]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */)));
    // 00501bd6  0fbe00                 -movsx eax, byte ptr [eax]
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.eax)));
    // 00501bd9  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
L_0x00501bdd:
    // 00501bdd  8b5e3c                 -mov ebx, dword ptr [esi + 0x3c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(60) /* 0x3c */);
    // 00501be0  8b5638                 -mov edx, dword ptr [esi + 0x38]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(56) /* 0x38 */);
    // 00501be3  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00501be5  7409                   -je 0x501bf0
    if (cpu.flags.zf)
    {
        goto L_0x00501bf0;
    }
    // 00501be7  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00501be9  e8f2080200             -call 0x5224e0
    cpu.esp -= 4;
    sub_5224e0(app, cpu);
    if (cpu.terminate) return;
    // 00501bee  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
L_0x00501bf0:
    // 00501bf0  83fa7f                 +cmp edx, 0x7f
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(127 /*0x7f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00501bf3  0f8ea1010000           -jle 0x501d9a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00501d9a;
    }
    // 00501bf9  ba7f000000             -mov edx, 0x7f
    cpu.edx = 127 /*0x7f*/;
L_0x00501bfe:
    // 00501bfe  0faf542434             -imul edx, dword ptr [esp + 0x34]
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */))));
    // 00501c03  bb7f000000             -mov ebx, 0x7f
    cpu.ebx = 127 /*0x7f*/;
    // 00501c08  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00501c0a  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00501c0d  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00501c0f  884130                 -mov byte ptr [ecx + 0x30], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(48) /* 0x30 */) = cpu.al;
    // 00501c12  8a442414               -mov al, byte ptr [esp + 0x14]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00501c16  884132                 -mov byte ptr [ecx + 0x32], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(50) /* 0x32 */) = cpu.al;
    // 00501c19  8a442418               -mov al, byte ptr [esp + 0x18]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00501c1d  88410f                 -mov byte ptr [ecx + 0xf], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(15) /* 0xf */) = cpu.al;
    // 00501c20  668b4628               -mov ax, word ptr [esi + 0x28]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 00501c24  6bc064                 -imul eax, eax, 0x64
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(100 /*0x64*/)));
    // 00501c27  66894142               -mov word ptr [ecx + 0x42], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(66) /* 0x42 */) = cpu.ax;
    // 00501c2b  8a44240c               -mov al, byte ptr [esp + 0xc]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00501c2f  884133                 -mov byte ptr [ecx + 0x33], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(51) /* 0x33 */) = cpu.al;
    // 00501c32  8b4664                 -mov eax, dword ptr [esi + 0x64]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(100) /* 0x64 */);
    // 00501c35  894148                 -mov dword ptr [ecx + 0x48], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(72) /* 0x48 */) = cpu.eax;
    // 00501c38  8b4670                 -mov eax, dword ptr [esi + 0x70]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(112) /* 0x70 */);
    // 00501c3b  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 00501c3e  c6413500               -mov byte ptr [ecx + 0x35], 0
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(53) /* 0x35 */) = 0 /*0x0*/;
    // 00501c42  894128                 -mov dword ptr [ecx + 0x28], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 00501c45  8a4624                 -mov al, byte ptr [esi + 0x24]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 00501c48  884134                 -mov byte ptr [ecx + 0x34], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(52) /* 0x34 */) = cpu.al;
    // 00501c4b  8a4620                 -mov al, byte ptr [esi + 0x20]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 00501c4e  884136                 -mov byte ptr [ecx + 0x36], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(54) /* 0x36 */) = cpu.al;
    // 00501c51  8b4148                 -mov eax, dword ptr [ecx + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(72) /* 0x48 */);
    // 00501c54  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00501c56  89412c                 -mov dword ptr [ecx + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 00501c59  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00501c5b  0f8c4c010000           -jl 0x501dad
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00501dad;
    }
L_0x00501c61:
    // 00501c61  8b4148                 -mov eax, dword ptr [ecx + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(72) /* 0x48 */);
    // 00501c64  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00501c67  8b5928                 -mov ebx, dword ptr [ecx + 0x28]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */);
    // 00501c6a  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 00501c6d  29da                   -sub edx, ebx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00501c6f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00501c71  8b592c                 -mov ebx, dword ptr [ecx + 0x2c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(44) /* 0x2c */);
    // 00501c74  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00501c77  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00501c79  894124                 -mov dword ptr [ecx + 0x24], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 00501c7c  8b4674                 -mov eax, dword ptr [esi + 0x74]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(116) /* 0x74 */);
    // 00501c7f  894158                 -mov dword ptr [ecx + 0x58], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(88) /* 0x58 */) = cpu.eax;
    // 00501c82  8b8680000000           -mov eax, dword ptr [esi + 0x80]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(128) /* 0x80 */);
    // 00501c88  89415c                 -mov dword ptr [ecx + 0x5c], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(92) /* 0x5c */) = cpu.eax;
    // 00501c8b  8a4678                 -mov al, byte ptr [esi + 0x78]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(120) /* 0x78 */);
    // 00501c8e  88413c                 -mov byte ptr [ecx + 0x3c], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(60) /* 0x3c */) = cpu.al;
    // 00501c91  8a8684000000           -mov al, byte ptr [esi + 0x84]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(132) /* 0x84 */);
    // 00501c97  88413d                 -mov byte ptr [ecx + 0x3d], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(61) /* 0x3d */) = cpu.al;
    // 00501c9a  668b8688000000         -mov ax, word ptr [esi + 0x88]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(136) /* 0x88 */);
    // 00501ca1  66894140               -mov word ptr [ecx + 0x40], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(64) /* 0x40 */) = cpu.ax;
    // 00501ca5  837e7c00               +cmp dword ptr [esi + 0x7c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(124) /* 0x7c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00501ca9  0f840a010000           -je 0x501db9
    if (cpu.flags.zf)
    {
        goto L_0x00501db9;
    }
    // 00501caf  e8d4f0fdff             -call 0x4e0d88
    cpu.esp -= 4;
    sub_4e0d88(app, cpu);
    if (cpu.terminate) return;
    // 00501cb4  8b5e78                 -mov ebx, dword ptr [esi + 0x78]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(120) /* 0x78 */);
    // 00501cb7  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00501cb9  f7f3                   -div ebx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ebx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 00501cbb  88513e                 -mov byte ptr [ecx + 0x3e], dl
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(62) /* 0x3e */) = cpu.dl;
L_0x00501cbe:
    // 00501cbe  83be8c00000000         +cmp dword ptr [esi + 0x8c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(140) /* 0x8c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00501cc5  0f84f7000000           -je 0x501dc2
    if (cpu.flags.zf)
    {
        goto L_0x00501dc2;
    }
    // 00501ccb  e8b8f0fdff             -call 0x4e0d88
    cpu.esp -= 4;
    sub_4e0d88(app, cpu);
    if (cpu.terminate) return;
    // 00501cd0  8b9e84000000           -mov ebx, dword ptr [esi + 0x84]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(132) /* 0x84 */);
    // 00501cd6  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00501cd8  f7f3                   -div ebx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ebx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 00501cda  88513f                 -mov byte ptr [ecx + 0x3f], dl
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(63) /* 0x3f */) = cpu.dl;
L_0x00501cdd:
    // 00501cdd  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00501cdf  e8cc0f0000             -call 0x502cb0
    cpu.esp -= 4;
    sub_502cb0(app, cpu);
    if (cpu.terminate) return;
    // 00501ce4  8a466c                 -mov al, byte ptr [esi + 0x6c]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(108) /* 0x6c */);
    // 00501ce7  88410b                 -mov byte ptr [ecx + 0xb], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(11) /* 0xb */) = cpu.al;
    // 00501cea  8a464c                 -mov al, byte ptr [esi + 0x4c]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(76) /* 0x4c */);
    // 00501ced  884138                 -mov byte ptr [ecx + 0x38], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(56) /* 0x38 */) = cpu.al;
    // 00501cf0  8a442408               -mov al, byte ptr [esp + 8]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00501cf4  884139                 -mov byte ptr [ecx + 0x39], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(57) /* 0x39 */) = cpu.al;
    // 00501cf7  8a4704                 -mov al, byte ptr [edi + 4]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 00501cfa  88410a                 -mov byte ptr [ecx + 0xa], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(10) /* 0xa */) = cpu.al;
    // 00501cfd  668b07                 -mov ax, word ptr [edi]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edi);
    // 00501d00  66894108               -mov word ptr [ecx + 8], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.ax;
    // 00501d04  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00501d06  e895f7ffff             -call 0x5014a0
    cpu.esp -= 4;
    sub_5014a0(app, cpu);
    if (cpu.terminate) return;
    // 00501d0b  807f0b00               +cmp byte ptr [edi + 0xb], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(11) /* 0xb */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00501d0f  0f84b6000000           -je 0x501dcb
    if (cpu.flags.zf)
    {
        goto L_0x00501dcb;
    }
    // 00501d15  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00501d17:
    // 00501d17  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00501d18  8b470c                 -mov eax, dword ptr [edi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */);
    // 00501d1b  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00501d1e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00501d1f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00501d21  668b470c               -mov ax, word ptr [edi + 0xc]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edi + x86::reg32(12) /* 0xc */);
    // 00501d25  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00501d26  8b4135                 -mov eax, dword ptr [ecx + 0x35]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(53) /* 0x35 */);
    // 00501d29  8b3d60a2a000           -mov edi, dword ptr [0xa0a260]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(10527328) /* 0xa0a260 */);
    // 00501d2f  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 00501d32  0fafc7                 -imul eax, edi
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edi)));
    // 00501d35  8b5136                 -mov edx, dword ptr [ecx + 0x36]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(54) /* 0x36 */);
    // 00501d38  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 00501d3b  0fafd0                 -imul edx, eax
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 00501d3e  bb013f0000             -mov ebx, 0x3f01
    cpu.ebx = 16129 /*0x3f01*/;
    // 00501d43  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00501d45  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00501d48  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00501d4a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00501d4b  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00501d4e  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00501d51  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00501d52  8b412e                 -mov eax, dword ptr [ecx + 0x2e]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(46) /* 0x2e */);
    // 00501d55  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 00501d57  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 00501d5a  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 00501d5c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00501d5d  8b4c2430               -mov ecx, dword ptr [esp + 0x30]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 00501d61  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00501d65  e8a6070200             -call 0x522510
    cpu.esp -= 4;
    sub_522510(app, cpu);
    if (cpu.terminate) return;
    // 00501d6a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00501d6c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00501d6e  7c65                   -jl 0x501dd5
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00501dd5;
    }
    // 00501d70  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
L_0x00501d73:
    // 00501d73  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00501d76  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00501d77  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00501d78  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00501d79  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x00501d7c:
    // 00501d7c  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00501d7e  0f8d26fdffff           -jge 0x501aaa
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00501aaa;
    }
    // 00501d84  31ed                   +xor ebp, ebp
    cpu.clear_co();
    cpu.set_szp((cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp))));
    // 00501d86  896c2414               -mov dword ptr [esp + 0x14], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ebp;
    // 00501d8a  e91bfdffff             -jmp 0x501aaa
    goto L_0x00501aaa;
L_0x00501d8f:
    // 00501d8f  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 00501d91  895c2418               -mov dword ptr [esp + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 00501d95  e931feffff             -jmp 0x501bcb
    goto L_0x00501bcb;
L_0x00501d9a:
    // 00501d9a  83fa80                 +cmp edx, -0x80
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-128 /*-0x80*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00501d9d  0f8d5bfeffff           -jge 0x501bfe
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00501bfe;
    }
    // 00501da3  ba80ffffff             -mov edx, 0xffffff80
    cpu.edx = 4294967168 /*0xffffff80*/;
    // 00501da8  e951feffff             -jmp 0x501bfe
    goto L_0x00501bfe;
L_0x00501dad:
    // 00501dad  c7412cffffff7f         -mov dword ptr [ecx + 0x2c], 0x7fffffff
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(44) /* 0x2c */) = 2147483647 /*0x7fffffff*/;
    // 00501db4  e9a8feffff             -jmp 0x501c61
    goto L_0x00501c61;
L_0x00501db9:
    // 00501db9  c6413e00               -mov byte ptr [ecx + 0x3e], 0
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(62) /* 0x3e */) = 0 /*0x0*/;
    // 00501dbd  e9fcfeffff             -jmp 0x501cbe
    goto L_0x00501cbe;
L_0x00501dc2:
    // 00501dc2  c6413f00               -mov byte ptr [ecx + 0x3f], 0
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(63) /* 0x3f */) = 0 /*0x0*/;
    // 00501dc6  e912ffffff             -jmp 0x501cdd
    goto L_0x00501cdd;
L_0x00501dcb:
    // 00501dcb  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00501dd0  e942ffffff             -jmp 0x501d17
    goto L_0x00501d17;
L_0x00501dd5:
    // 00501dd5  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00501dd7  e888ddffff             -call 0x4ffb64
    cpu.esp -= 4;
    sub_4ffb64(app, cpu);
    if (cpu.terminate) return;
    // 00501ddc  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00501dde  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00501de1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00501de2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00501de3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00501de4  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x90 */
void Application::sub_501de8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00501de8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00501de9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00501dea  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00501deb  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00501dec  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00501ded  81eca4010000           -sub esp, 0x1a4
    (cpu.esp) -= x86::reg32(x86::sreg32(420 /*0x1a4*/));
    // 00501df3  8984248c010000         -mov dword ptr [esp + 0x18c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(396) /* 0x18c */) = cpu.eax;
    // 00501dfa  89942484010000         -mov dword ptr [esp + 0x184], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(388) /* 0x184 */) = cpu.edx;
    // 00501e01  baf7ffffff             -mov edx, 0xfffffff7
    cpu.edx = 4294967287 /*0xfffffff7*/;
    // 00501e06  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 00501e08  89942488010000         -mov dword ptr [esp + 0x188], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(392) /* 0x188 */) = cpu.edx;
    // 00501e0f  89ac2498010000         -mov dword ptr [esp + 0x198], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(408) /* 0x198 */) = cpu.ebp;
    // 00501e16  89ac249c010000         -mov dword ptr [esp + 0x19c], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(412) /* 0x19c */) = cpu.ebp;
    // 00501e1d  89ac2494010000         -mov dword ptr [esp + 0x194], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(404) /* 0x194 */) = cpu.ebp;
    // 00501e24  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00501e26  0f8430010000           -je 0x501f5c
    if (cpu.flags.zf)
    {
        goto L_0x00501f5c;
    }
    // 00501e2c  8bbc2484010000         -mov edi, dword ptr [esp + 0x184]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(388) /* 0x184 */);
    // 00501e33  8bb42484010000         -mov esi, dword ptr [esp + 0x184]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(388) /* 0x184 */);
    // 00501e3a  8b7f03                 -mov edi, dword ptr [edi + 3]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(3) /* 0x3 */);
    // 00501e3d  8b7602                 -mov esi, dword ptr [esi + 2]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 00501e40  c1ff18                 -sar edi, 0x18
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (24 /*0x18*/ % 32));
    // 00501e43  c1fe18                 -sar esi, 0x18
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (24 /*0x18*/ % 32));
    // 00501e46  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00501e48  7c05                   -jl 0x501e4f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00501e4f;
    }
    // 00501e4a  83ff7f                 +cmp edi, 0x7f
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(127 /*0x7f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00501e4d  7e2e                   -jle 0x501e7d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00501e7d;
    }
L_0x00501e4f:
    // 00501e4f  b838e65400             -mov eax, 0x54e638
    cpu.eax = 5563960 /*0x54e638*/;
    // 00501e54  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00501e55  ba30e75400             -mov edx, 0x54e730
    cpu.edx = 5564208 /*0x54e730*/;
    // 00501e5a  b9a8010000             -mov ecx, 0x1a8
    cpu.ecx = 424 /*0x1a8*/;
    // 00501e5f  6844e75400             -push 0x54e744
    app->getMemory<x86::reg32>(cpu.esp-4) = 5564228 /*0x54e744*/;
    cpu.esp -= 4;
    // 00501e64  a390215500             -mov dword ptr [0x552190], eax
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.eax;
    // 00501e69  891594215500           -mov dword ptr [0x552194], edx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.edx;
    // 00501e6f  890d98215500           -mov dword ptr [0x552198], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ecx;
    // 00501e75  e896f1efff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 00501e7a  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x00501e7d:
    // 00501e7d  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00501e7f  7c05                   -jl 0x501e86
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00501e86;
    }
    // 00501e81  83fe7f                 +cmp esi, 0x7f
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(127 /*0x7f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00501e84  7e2e                   -jle 0x501eb4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00501eb4;
    }
L_0x00501e86:
    // 00501e86  bb38e65400             -mov ebx, 0x54e638
    cpu.ebx = 5563960 /*0x54e638*/;
    // 00501e8b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00501e8c  b830e75400             -mov eax, 0x54e730
    cpu.eax = 5564208 /*0x54e730*/;
    // 00501e91  bab0010000             -mov edx, 0x1b0
    cpu.edx = 432 /*0x1b0*/;
    // 00501e96  6878e75400             -push 0x54e778
    app->getMemory<x86::reg32>(cpu.esp-4) = 5564280 /*0x54e778*/;
    cpu.esp -= 4;
    // 00501e9b  891d90215500           -mov dword ptr [0x552190], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ebx;
    // 00501ea1  a394215500             -mov dword ptr [0x552194], eax
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.eax;
    // 00501ea6  891598215500           -mov dword ptr [0x552198], edx
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.edx;
    // 00501eac  e85ff1efff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 00501eb1  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x00501eb4:
    // 00501eb4  8b84248c010000         -mov eax, dword ptr [esp + 0x18c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(396) /* 0x18c */);
    // 00501ebb  89842470010000         -mov dword ptr [esp + 0x170], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(368) /* 0x170 */) = cpu.eax;
    // 00501ec2  f6400302               +test byte ptr [eax + 3], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(3) /* 0x3 */) & 2 /*0x2*/));
    // 00501ec6  0f84a1000000           -je 0x501f6d
    if (cpu.flags.zf)
    {
        goto L_0x00501f6d;
    }
    // 00501ecc  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x00501ecf:
    // 00501ecf  89842470010000         -mov dword ptr [esp + 0x170], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(368) /* 0x170 */) = cpu.eax;
    // 00501ed6  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00501ed8  8d942498000000         -lea edx, [esp + 0x98]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(152) /* 0x98 */);
    // 00501edf  e8dcf8ffff             -call 0x5017c0
    cpu.esp -= 4;
    sub_5017c0(app, cpu);
    if (cpu.terminate) return;
    // 00501ee4  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00501ee6  e8edf8ffff             -call 0x5017d8
    cpu.esp -= 4;
    sub_5017d8(app, cpu);
    if (cpu.terminate) return;
    // 00501eeb  e830efffff             -call 0x500e20
    cpu.esp -= 4;
    sub_500e20(app, cpu);
    if (cpu.terminate) return;
    // 00501ef0  e843faffff             -call 0x501938
    cpu.esp -= 4;
    sub_501938(app, cpu);
    if (cpu.terminate) return;
    // 00501ef5  89842480010000         -mov dword ptr [esp + 0x180], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(384) /* 0x180 */) = cpu.eax;
    // 00501efc  8b842498010000         -mov eax, dword ptr [esp + 0x198]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(408) /* 0x198 */);
    // 00501f03  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00501f06  898424a0010000         -mov dword ptr [esp + 0x1a0], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(416) /* 0x1a0 */) = cpu.eax;
L_0x00501f0d:
    // 00501f0d  8d8c247c010000         -lea ecx, [esp + 0x17c]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(380) /* 0x17c */);
    // 00501f14  8d9c2478010000         -lea ebx, [esp + 0x178]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(376) /* 0x178 */);
    // 00501f1b  8d942474010000         -lea edx, [esp + 0x174]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(372) /* 0x174 */);
    // 00501f22  8d842470010000         -lea eax, [esp + 0x170]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(368) /* 0x170 */);
    // 00501f29  e8a20a0200             -call 0x5229d0
    cpu.esp -= 4;
    sub_5229d0(app, cpu);
    if (cpu.terminate) return;
    // 00501f2e  8b942498010000         -mov edx, dword ptr [esp + 0x198]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(408) /* 0x198 */);
    // 00501f35  42                     -inc edx
    (cpu.edx)++;
    // 00501f36  89942490010000         -mov dword ptr [esp + 0x190], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(400) /* 0x190 */) = cpu.edx;
    // 00501f3d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00501f3f  0f841f010000           -je 0x502064
    if (cpu.flags.zf)
    {
        goto L_0x00502064;
    }
    // 00501f45  8b842474010000         -mov eax, dword ptr [esp + 0x174]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(372) /* 0x174 */);
    // 00501f4c  3dfd000000             +cmp eax, 0xfd
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(253 /*0xfd*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00501f51  7522                   -jne 0x501f75
    if (!cpu.flags.zf)
    {
        goto L_0x00501f75;
    }
    // 00501f53  8bac2470010000         -mov ebp, dword ptr [esp + 0x170]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(368) /* 0x170 */);
    // 00501f5a  ebb1                   -jmp 0x501f0d
    goto L_0x00501f0d;
L_0x00501f5c:
    // 00501f5c  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 00501f61  81c4a4010000           -add esp, 0x1a4
    (cpu.esp) += x86::reg32(x86::sreg32(420 /*0x1a4*/));
    // 00501f67  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00501f68  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00501f69  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00501f6a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00501f6b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00501f6c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00501f6d:
    // 00501f6d  83c004                 +add eax, 4
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
    // 00501f70  e95affffff             -jmp 0x501ecf
    goto L_0x00501ecf;
L_0x00501f75:
    // 00501f75  3dfe000000             +cmp eax, 0xfe
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(254 /*0xfe*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00501f7a  0f859e000000           -jne 0x50201e
    if (!cpu.flags.zf)
    {
        goto L_0x0050201e;
    }
    // 00501f80  3b7c2404               +cmp edi, dword ptr [esp + 4]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00501f84  7d13                   -jge 0x501f99
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00501f99;
    }
L_0x00501f86:
    // 00501f86  8d942498000000         -lea edx, [esp + 0x98]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(152) /* 0x98 */);
    // 00501f8d  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00501f8f  e844f8ffff             -call 0x5017d8
    cpu.esp -= 4;
    sub_5017d8(app, cpu);
    if (cpu.terminate) return;
    // 00501f94  e974ffffff             -jmp 0x501f0d
    goto L_0x00501f0d;
L_0x00501f99:
    // 00501f99  3b7c2408               +cmp edi, dword ptr [esp + 8]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00501f9d  7fe7                   -jg 0x501f86
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00501f86;
    }
    // 00501f9f  3b74240c               +cmp esi, dword ptr [esp + 0xc]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00501fa3  7ce1                   -jl 0x501f86
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00501f86;
    }
    // 00501fa5  3b742410               +cmp esi, dword ptr [esp + 0x10]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00501fa9  7fdb                   -jg 0x501f86
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00501f86;
    }
    // 00501fab  8b842494010000         -mov eax, dword ptr [esp + 0x194]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(404) /* 0x194 */);
    // 00501fb2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00501fb3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00501fb4  8d4c2408               -lea ecx, [esp + 8]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00501fb8  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00501fb9  8d8424a4000000         -lea eax, [esp + 0xa4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(164) /* 0xa4 */);
    // 00501fc0  8b9c2490010000         -mov ebx, dword ptr [esp + 0x190]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(400) /* 0x190 */);
    // 00501fc7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00501fc8  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00501fca  8b84249c010000         -mov eax, dword ptr [esp + 0x19c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(412) /* 0x19c */);
    // 00501fd1  e8a2f9ffff             -call 0x501978
    cpu.esp -= 4;
    sub_501978(app, cpu);
    if (cpu.terminate) return;
    // 00501fd6  89842488010000         -mov dword ptr [esp + 0x188], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(392) /* 0x188 */) = cpu.eax;
    // 00501fdd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00501fdf  0f8cf4000000           -jl 0x5020d9
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x005020d9;
    }
    // 00501fe5  8b9424a0010000         -mov edx, dword ptr [esp + 0x1a0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(416) /* 0x1a0 */);
    // 00501fec  89841430010000         -mov dword ptr [esp + edx + 0x130], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(304) /* 0x130 */ + cpu.edx * 1) = cpu.eax;
    // 00501ff3  83c204                 +add edx, 4
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
    // 00501ff6  8b842490010000         -mov eax, dword ptr [esp + 0x190]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(400) /* 0x190 */);
    // 00501ffd  899424a0010000         -mov dword ptr [esp + 0x1a0], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(416) /* 0x1a0 */) = cpu.edx;
    // 00502004  89842498010000         -mov dword ptr [esp + 0x198], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(408) /* 0x198 */) = cpu.eax;
    // 0050200b  8d942498000000         -lea edx, [esp + 0x98]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(152) /* 0x98 */);
    // 00502012  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00502014  e8bff7ffff             -call 0x5017d8
    cpu.esp -= 4;
    sub_5017d8(app, cpu);
    if (cpu.terminate) return;
    // 00502019  e9effeffff             -jmp 0x501f0d
    goto L_0x00501f0d;
L_0x0050201e:
    // 0050201e  83f826                 +cmp eax, 0x26
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(38 /*0x26*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00502021  0f8de6feffff           -jge 0x501f0d
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00501f0d;
    }
    // 00502027  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00502029  8b842478010000         -mov eax, dword ptr [esp + 0x178]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(376) /* 0x178 */);
    // 00502030  890494                 -mov dword ptr [esp + edx*4], eax
    app->getMemory<x86::reg32>(cpu.esp + cpu.edx * 4) = cpu.eax;
    // 00502033  8b84247c010000         -mov eax, dword ptr [esp + 0x17c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(380) /* 0x17c */);
    // 0050203a  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0050203c  89849498000000         -mov dword ptr [esp + edx*4 + 0x98], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(152) /* 0x98 */ + cpu.edx * 4) = cpu.eax;
    // 00502043  83fb24                 +cmp ebx, 0x24
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(36 /*0x24*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00502046  0f85c1feffff           -jne 0x501f0d
    if (!cpu.flags.zf)
    {
        goto L_0x00501f0d;
    }
    // 0050204c  8b842478010000         -mov eax, dword ptr [esp + 0x178]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(376) /* 0x178 */);
    // 00502053  e888040200             -call 0x5224e0
    cpu.esp -= 4;
    sub_5224e0(app, cpu);
    if (cpu.terminate) return;
    // 00502058  89842494010000         -mov dword ptr [esp + 0x194], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(404) /* 0x194 */) = cpu.eax;
    // 0050205f  e9a9feffff             -jmp 0x501f0d
    goto L_0x00501f0d;
L_0x00502064:
    // 00502064  3b7c2404               +cmp edi, dword ptr [esp + 4]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00502068  7c64                   -jl 0x5020ce
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x005020ce;
    }
    // 0050206a  3b7c2408               +cmp edi, dword ptr [esp + 8]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050206e  7f5e                   -jg 0x5020ce
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x005020ce;
    }
    // 00502070  3b74240c               +cmp esi, dword ptr [esp + 0xc]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00502074  7c58                   -jl 0x5020ce
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x005020ce;
    }
    // 00502076  3b742410               +cmp esi, dword ptr [esp + 0x10]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050207a  7f52                   -jg 0x5020ce
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x005020ce;
    }
    // 0050207c  8b8c2494010000         -mov ecx, dword ptr [esp + 0x194]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(404) /* 0x194 */);
    // 00502083  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00502084  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00502085  8d8424a0000000         -lea eax, [esp + 0xa0]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(160) /* 0xa0 */);
    // 0050208c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050208d  8b9c2490010000         -mov ebx, dword ptr [esp + 0x190]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(400) /* 0x190 */);
    // 00502094  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00502096  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00502097  8d4c2410               -lea ecx, [esp + 0x10]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0050209b  8b84249c010000         -mov eax, dword ptr [esp + 0x19c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(412) /* 0x19c */);
    // 005020a2  e8d1f8ffff             -call 0x501978
    cpu.esp -= 4;
    sub_501978(app, cpu);
    if (cpu.terminate) return;
    // 005020a7  89842488010000         -mov dword ptr [esp + 0x188], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(392) /* 0x188 */) = cpu.eax;
    // 005020ae  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005020b0  7c27                   -jl 0x5020d9
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x005020d9;
    }
    // 005020b2  8b9424a0010000         -mov edx, dword ptr [esp + 0x1a0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(416) /* 0x1a0 */);
    // 005020b9  89841430010000         -mov dword ptr [esp + edx + 0x130], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(304) /* 0x130 */ + cpu.edx * 1) = cpu.eax;
    // 005020c0  8b842490010000         -mov eax, dword ptr [esp + 0x190]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(400) /* 0x190 */);
    // 005020c7  89842498010000         -mov dword ptr [esp + 0x198], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(408) /* 0x198 */) = cpu.eax;
L_0x005020ce:
    // 005020ce  8b9c2498010000         -mov ebx, dword ptr [esp + 0x198]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(408) /* 0x198 */);
    // 005020d5  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 005020d7  753e                   -jne 0x502117
    if (!cpu.flags.zf)
    {
        goto L_0x00502117;
    }
L_0x005020d9:
    // 005020d9  8b8c2498010000         -mov ecx, dword ptr [esp + 0x198]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(408) /* 0x198 */);
    // 005020e0  e897edffff             -call 0x500e7c
    cpu.esp -= 4;
    sub_500e7c(app, cpu);
    if (cpu.terminate) return;
    // 005020e5  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 005020e7  7e1b                   -jle 0x502104
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00502104;
    }
    // 005020e9  c1e102                 -shl ecx, 2
    cpu.ecx <<= 2 /*0x2*/ % 32;
    // 005020ec  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x005020ee:
    // 005020ee  8b841430010000         -mov eax, dword ptr [esp + edx + 0x130]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(304) /* 0x130 */ + cpu.edx * 1);
    // 005020f5  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 005020f8  e87375feff             -call 0x4e9670
    cpu.esp -= 4;
    sub_4e9670(app, cpu);
    if (cpu.terminate) return;
    // 005020fd  39ca                   +cmp edx, ecx
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
    // 005020ff  7ced                   -jl 0x5020ee
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x005020ee;
    }
    // 00502101  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x00502104:
    // 00502104  8b842488010000         -mov eax, dword ptr [esp + 0x188]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(392) /* 0x188 */);
    // 0050210b  81c4a4010000           -add esp, 0x1a4
    (cpu.esp) += x86::reg32(x86::sreg32(420 /*0x1a4*/));
    // 00502111  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00502112  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00502113  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00502114  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00502115  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00502116  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00502117:
    // 00502117  83fb01                 +cmp ebx, 1
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
    // 0050211a  753f                   -jne 0x50215b
    if (!cpu.flags.zf)
    {
        goto L_0x0050215b;
    }
    // 0050211c  8b842430010000         -mov eax, dword ptr [esp + 0x130]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(304) /* 0x130 */);
    // 00502123  e874dbffff             -call 0x4ffc9c
    cpu.esp -= 4;
    sub_4ffc9c(app, cpu);
    if (cpu.terminate) return;
    // 00502128  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0050212a  7c17                   -jl 0x502143
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00502143;
    }
    // 0050212c  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0050212e  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00502131  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00502133  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 00502136  053c9ba000             -add eax, 0xa09b3c
    (cpu.eax) += x86::reg32(x86::sreg32(10525500 /*0xa09b3c*/));
    // 0050213b  c6403b00               -mov byte ptr [eax + 0x3b], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(59) /* 0x3b */) = 0 /*0x0*/;
    // 0050213f  c6403a00               -mov byte ptr [eax + 0x3a], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(58) /* 0x3a */) = 0 /*0x0*/;
L_0x00502143:
    // 00502143  e834edffff             -call 0x500e7c
    cpu.esp -= 4;
    sub_500e7c(app, cpu);
    if (cpu.terminate) return;
    // 00502148  8b842488010000         -mov eax, dword ptr [esp + 0x188]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(392) /* 0x188 */);
    // 0050214f  81c4a4010000           -add esp, 0x1a4
    (cpu.esp) += x86::reg32(x86::sreg32(420 /*0x1a4*/));
    // 00502155  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00502156  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00502157  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00502158  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00502159  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050215a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050215b:
    // 0050215b  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0050215d  7e3f                   -jle 0x50219e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0050219e;
    }
    // 0050215f  8d0c9d00000000         -lea ecx, [ebx*4]
    cpu.ecx = x86::reg32(cpu.ebx * 4);
    // 00502166  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00502168:
    // 00502168  8b841430010000         -mov eax, dword ptr [esp + edx + 0x130]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(304) /* 0x130 */ + cpu.edx * 1);
    // 0050216f  e828dbffff             -call 0x4ffc9c
    cpu.esp -= 4;
    sub_4ffc9c(app, cpu);
    if (cpu.terminate) return;
    // 00502174  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00502176  7c1f                   -jl 0x502197
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00502197;
    }
    // 00502178  6bc060                 -imul eax, eax, 0x60
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(96 /*0x60*/)));
    // 0050217b  bb3c9ba000             -mov ebx, 0xa09b3c
    cpu.ebx = 10525500 /*0xa09b3c*/;
    // 00502180  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00502182  8a842480010000         -mov al, byte ptr [esp + 0x180]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(384) /* 0x180 */);
    // 00502189  c6433a00               -mov byte ptr [ebx + 0x3a], 0
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(58) /* 0x3a */) = 0 /*0x0*/;
    // 0050218d  899c249c010000         -mov dword ptr [esp + 0x19c], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(412) /* 0x19c */) = cpu.ebx;
    // 00502194  88433b                 -mov byte ptr [ebx + 0x3b], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(59) /* 0x3b */) = cpu.al;
L_0x00502197:
    // 00502197  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0050219a  39ca                   +cmp edx, ecx
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
    // 0050219c  7cca                   -jl 0x502168
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00502168;
    }
L_0x0050219e:
    // 0050219e  8b84249c010000         -mov eax, dword ptr [esp + 0x19c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(412) /* 0x19c */);
    // 005021a5  c6403a01               -mov byte ptr [eax + 0x3a], 1
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(58) /* 0x3a */) = 1 /*0x1*/;
    // 005021a9  eb98                   -jmp 0x502143
    goto L_0x00502143;
}

/* align: skip 0x90 */
void Application::sub_5021ac(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005021ac  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005021ad  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005021ae  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 005021af  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005021b0  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 005021b3  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 005021b7  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 005021b9  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 005021bb  668b10                 -mov dx, word ptr [eax]
    cpu.dx = app->getMemory<x86::reg16>(cpu.eax);
    // 005021be  bdffffffff             -mov ebp, 0xffffffff
    cpu.ebp = 4294967295 /*0xffffffff*/;
    // 005021c3  6681fa5054             +cmp dx, 0x5450
    {
        x86::reg16 tmp1 = cpu.dx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(21584 /*0x5450*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 005021c8  0f85b2000000           -jne 0x502280
    if (!cpu.flags.zf)
    {
        goto L_0x00502280;
    }
L_0x005021ce:
    // 005021ce  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 005021d2  80780200               +cmp byte ptr [eax + 2], 0
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
    // 005021d6  742d                   -je 0x502205
    if (cpu.flags.zf)
    {
        goto L_0x00502205;
    }
    // 005021d8  b838e65400             -mov eax, 0x54e638
    cpu.eax = 5563960 /*0x54e638*/;
    // 005021dd  baace75400             -mov edx, 0x54e7ac
    cpu.edx = 5564332 /*0x54e7ac*/;
    // 005021e2  b967020000             -mov ecx, 0x267
    cpu.ecx = 615 /*0x267*/;
    // 005021e7  68f4e75400             -push 0x54e7f4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5564404 /*0x54e7f4*/;
    cpu.esp -= 4;
    // 005021ec  a390215500             -mov dword ptr [0x552190], eax
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.eax;
    // 005021f1  891594215500           -mov dword ptr [0x552194], edx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.edx;
    // 005021f7  890d98215500           -mov dword ptr [0x552198], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ecx;
    // 005021fd  e80eeeefff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 00502202  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00502205:
    // 00502205  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00502209  f6400301               +test byte ptr [eax + 3], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(3) /* 0x3 */) & 1 /*0x1*/));
    // 0050220d  742d                   -je 0x50223c
    if (cpu.flags.zf)
    {
        goto L_0x0050223c;
    }
    // 0050220f  bb38e65400             -mov ebx, 0x54e638
    cpu.ebx = 5563960 /*0x54e638*/;
    // 00502214  b8ace75400             -mov eax, 0x54e7ac
    cpu.eax = 5564332 /*0x54e7ac*/;
    // 00502219  ba6f020000             -mov edx, 0x26f
    cpu.edx = 623 /*0x26f*/;
    // 0050221e  682ce85400             -push 0x54e82c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5564460 /*0x54e82c*/;
    cpu.esp -= 4;
    // 00502223  891d90215500           -mov dword ptr [0x552190], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ebx;
    // 00502229  a394215500             -mov dword ptr [0x552194], eax
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.eax;
    // 0050222e  891598215500           -mov dword ptr [0x552198], edx
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.edx;
    // 00502234  e8d7edefff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 00502239  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0050223c:
    // 0050223c  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00502240  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00502243  f6400302               +test byte ptr [eax + 3], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(3) /* 0x3 */) & 2 /*0x2*/));
    // 00502247  746a                   -je 0x5022b3
    if (cpu.flags.zf)
    {
        goto L_0x005022b3;
    }
    // 00502249  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x0050224c:
    // 0050224c  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
L_0x0050224f:
    // 0050224f  8d4c240c               -lea ecx, [esp + 0xc]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00502253  8d5c2408               -lea ebx, [esp + 8]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00502257  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0050225b  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0050225d  e86e070200             -call 0x5229d0
    cpu.esp -= 4;
    sub_5229d0(app, cpu);
    if (cpu.terminate) return;
    // 00502262  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00502264  7452                   -je 0x5022b8
    if (cpu.flags.zf)
    {
        goto L_0x005022b8;
    }
    // 00502266  817c2404fd000000       +cmp dword ptr [esp + 4], 0xfd
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(253 /*0xfd*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050226e  75df                   -jne 0x50224f
    if (!cpu.flags.zf)
    {
        goto L_0x0050224f;
    }
    // 00502270  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00502273  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00502275  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00502277  e804080200             -call 0x522a80
    cpu.esp -= 4;
    sub_522a80(app, cpu);
    if (cpu.terminate) return;
    // 0050227c  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0050227e  ebcf                   -jmp 0x50224f
    goto L_0x0050224f;
L_0x00502280:
    // 00502280  ba38e65400             -mov edx, 0x54e638
    cpu.edx = 5563960 /*0x54e638*/;
    // 00502285  b9ace75400             -mov ecx, 0x54e7ac
    cpu.ecx = 5564332 /*0x54e7ac*/;
    // 0050228a  bb54020000             -mov ebx, 0x254
    cpu.ebx = 596 /*0x254*/;
    // 0050228f  68c4e75400             -push 0x54e7c4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5564356 /*0x54e7c4*/;
    cpu.esp -= 4;
    // 00502294  891590215500           -mov dword ptr [0x552190], edx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edx;
    // 0050229a  890d94215500           -mov dword ptr [0x552194], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ecx;
    // 005022a0  891d98215500           -mov dword ptr [0x552198], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ebx;
    // 005022a6  e865edefff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 005022ab  83c404                 +add esp, 4
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
    // 005022ae  e91bffffff             -jmp 0x5021ce
    goto L_0x005021ce;
L_0x005022b3:
    // 005022b3  83c004                 +add eax, 4
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
    // 005022b6  eb94                   -jmp 0x50224c
    goto L_0x0050224c;
L_0x005022b8:
    // 005022b8  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 005022ba  7c08                   -jl 0x5022c4
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x005022c4;
    }
    // 005022bc  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 005022c0  80480301               -or byte ptr [eax + 3], 1
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(3) /* 0x3 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x005022c4:
    // 005022c4  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 005022c6  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 005022c9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005022ca  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005022cb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005022cc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005022cd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_5022d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005022d0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 005022d1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005022d2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005022d3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 005022d4  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 005022d7  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 005022d9  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 005022db  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 005022de  f6400302               +test byte ptr [eax + 3], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(3) /* 0x3 */) & 2 /*0x2*/));
    // 005022e2  7535                   -jne 0x502319
    if (!cpu.flags.zf)
    {
        goto L_0x00502319;
    }
    // 005022e4  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 005022e6  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x005022e9:
    // 005022e9  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
L_0x005022ec:
    // 005022ec  8d4c240c               -lea ecx, [esp + 0xc]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 005022f0  8d5c2408               -lea ebx, [esp + 8]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 005022f4  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 005022f8  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 005022fa  e8d1060200             -call 0x5229d0
    cpu.esp -= 4;
    sub_5229d0(app, cpu);
    if (cpu.terminate) return;
    // 005022ff  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00502301  741d                   -je 0x502320
    if (cpu.flags.zf)
    {
        goto L_0x00502320;
    }
    // 00502303  817c2404fd000000       +cmp dword ptr [esp + 4], 0xfd
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(253 /*0xfd*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050230b  75df                   -jne 0x5022ec
    if (!cpu.flags.zf)
    {
        goto L_0x005022ec;
    }
    // 0050230d  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00502310  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00502312  e8f1090200             -call 0x522d08
    cpu.esp -= 4;
    sub_522d08(app, cpu);
    if (cpu.terminate) return;
    // 00502317  ebd3                   -jmp 0x5022ec
    goto L_0x005022ec;
L_0x00502319:
    // 00502319  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0050231b  83c008                 +add eax, 8
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
    // 0050231e  ebc9                   -jmp 0x5022e9
    goto L_0x005022e9;
L_0x00502320:
    // 00502320  806703fe               -and byte ptr [edi + 3], 0xfe
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(3) /* 0x3 */) &= x86::reg8(x86::sreg8(254 /*0xfe*/));
    // 00502324  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00502327  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00502328  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00502329  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050232a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050232b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_502330(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00502330  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00502331  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00502332  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00502333  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00502334  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00502337  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00502339  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0050233b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0050233d  0f8499000000           -je 0x5023dc
    if (cpu.flags.zf)
    {
        goto L_0x005023dc;
    }
L_0x00502343:
    // 00502343  6681395054             +cmp word ptr [ecx], 0x5450
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.ecx);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(21584 /*0x5450*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00502348  742d                   -je 0x502377
    if (cpu.flags.zf)
    {
        goto L_0x00502377;
    }
    // 0050234a  bd90e85400             -mov ebp, 0x54e890
    cpu.ebp = 5564560 /*0x54e890*/;
    // 0050234f  b8a0e85400             -mov eax, 0x54e8a0
    cpu.eax = 5564576 /*0x54e8a0*/;
    // 00502354  ba17000000             -mov edx, 0x17
    cpu.edx = 23 /*0x17*/;
    // 00502359  68e4e85400             -push 0x54e8e4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5564644 /*0x54e8e4*/;
    cpu.esp -= 4;
    // 0050235e  892d90215500           -mov dword ptr [0x552190], ebp
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ebp;
    // 00502364  a394215500             -mov dword ptr [0x552194], eax
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.eax;
    // 00502369  891598215500           -mov dword ptr [0x552198], edx
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.edx;
    // 0050236f  e89cecefff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 00502374  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00502377:
    // 00502377  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 0050237a  f6410302               +test byte ptr [ecx + 3], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(3) /* 0x3 */) & 2 /*0x2*/));
    // 0050237e  0f848d000000           -je 0x502411
    if (cpu.flags.zf)
    {
        goto L_0x00502411;
    }
    // 00502384  83c108                 -add ecx, 8
    (cpu.ecx) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x00502387:
    // 00502387  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 0050238a  c7460800000000         -mov dword ptr [esi + 8], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 00502391  c60600                 -mov byte ptr [esi], 0
    app->getMemory<x86::reg8>(cpu.esi) = 0 /*0x0*/;
    // 00502394  c646010f               -mov byte ptr [esi + 1], 0xf
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */) = 15 /*0xf*/;
    // 00502398  c6460200               -mov byte ptr [esi + 2], 0
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */) = 0 /*0x0*/;
    // 0050239c  c6460300               -mov byte ptr [esi + 3], 0
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(3) /* 0x3 */) = 0 /*0x0*/;
    // 005023a0  c6460600               -mov byte ptr [esi + 6], 0
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(6) /* 0x6 */) = 0 /*0x0*/;
    // 005023a4  66c746042256           -mov word ptr [esi + 4], 0x5622
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(4) /* 0x4 */) = 22050 /*0x5622*/;
L_0x005023aa:
    // 005023aa  8d4c240c               -lea ecx, [esp + 0xc]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 005023ae  8d5c2408               -lea ebx, [esp + 8]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 005023b2  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 005023b6  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 005023b8  e813060200             -call 0x5229d0
    cpu.esp -= 4;
    sub_5229d0(app, cpu);
    if (cpu.terminate) return;
    // 005023bd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005023bf  0f84c5000000           -je 0x50248a
    if (cpu.flags.zf)
    {
        goto L_0x0050248a;
    }
    // 005023c5  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 005023c9  83f913                 +cmp ecx, 0x13
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(19 /*0x13*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005023cc  744b                   -je 0x502419
    if (cpu.flags.zf)
    {
        goto L_0x00502419;
    }
    // 005023ce  83f91b                 +cmp ecx, 0x1b
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(27 /*0x1b*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005023d1  754e                   -jne 0x502421
    if (!cpu.flags.zf)
    {
        goto L_0x00502421;
    }
    // 005023d3  8a442408               -mov al, byte ptr [esp + 8]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 005023d7  884601                 -mov byte ptr [esi + 1], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 005023da  ebce                   -jmp 0x5023aa
    goto L_0x005023aa;
L_0x005023dc:
    // 005023dc  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 005023dd  ba90e85400             -mov edx, 0x54e890
    cpu.edx = 5564560 /*0x54e890*/;
    // 005023e2  bba0e85400             -mov ebx, 0x54e8a0
    cpu.ebx = 5564576 /*0x54e8a0*/;
    // 005023e7  bf11000000             -mov edi, 0x11
    cpu.edi = 17 /*0x11*/;
    // 005023ec  68b4e85400             -push 0x54e8b4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5564596 /*0x54e8b4*/;
    cpu.esp -= 4;
    // 005023f1  891590215500           -mov dword ptr [0x552190], edx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edx;
    // 005023f7  891d94215500           -mov dword ptr [0x552194], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebx;
    // 005023fd  893d98215500           -mov dword ptr [0x552198], edi
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.edi;
    // 00502403  e808ecefff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 00502408  83c404                 +add esp, 4
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
    // 0050240b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050240c  e932ffffff             -jmp 0x502343
    goto L_0x00502343;
L_0x00502411:
    // 00502411  83c104                 +add ecx, 4
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
    // 00502414  e96effffff             -jmp 0x502387
    goto L_0x00502387;
L_0x00502419:
    // 00502419  8a442408               -mov al, byte ptr [esp + 8]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0050241d  8806                   -mov byte ptr [esi], al
    app->getMemory<x86::reg8>(cpu.esi) = cpu.al;
    // 0050241f  eb89                   -jmp 0x5023aa
    goto L_0x005023aa;
L_0x00502421:
    // 00502421  81f981000000           +cmp ecx, 0x81
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(129 /*0x81*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00502427  750c                   -jne 0x502435
    if (!cpu.flags.zf)
    {
        goto L_0x00502435;
    }
    // 00502429  8a442408               -mov al, byte ptr [esp + 8]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0050242d  884602                 -mov byte ptr [esi + 2], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */) = cpu.al;
    // 00502430  e975ffffff             -jmp 0x5023aa
    goto L_0x005023aa;
L_0x00502435:
    // 00502435  81f982000000           +cmp ecx, 0x82
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(130 /*0x82*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050243b  750c                   -jne 0x502449
    if (!cpu.flags.zf)
    {
        goto L_0x00502449;
    }
    // 0050243d  8a442408               -mov al, byte ptr [esp + 8]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00502441  884606                 -mov byte ptr [esi + 6], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(6) /* 0x6 */) = cpu.al;
    // 00502444  e961ffffff             -jmp 0x5023aa
    goto L_0x005023aa;
L_0x00502449:
    // 00502449  81f984000000           +cmp ecx, 0x84
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(132 /*0x84*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050244f  750d                   -jne 0x50245e
    if (!cpu.flags.zf)
    {
        goto L_0x0050245e;
    }
    // 00502451  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00502455  66894604               -mov word ptr [esi + 4], ax
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.ax;
    // 00502459  e94cffffff             -jmp 0x5023aa
    goto L_0x005023aa;
L_0x0050245e:
    // 0050245e  81f983000000           +cmp ecx, 0x83
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(131 /*0x83*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00502464  750c                   -jne 0x502472
    if (!cpu.flags.zf)
    {
        goto L_0x00502472;
    }
    // 00502466  8a442408               -mov al, byte ptr [esp + 8]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0050246a  884603                 -mov byte ptr [esi + 3], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(3) /* 0x3 */) = cpu.al;
    // 0050246d  e938ffffff             -jmp 0x5023aa
    goto L_0x005023aa;
L_0x00502472:
    // 00502472  81f985000000           +cmp ecx, 0x85
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(133 /*0x85*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00502478  0f852cffffff           -jne 0x5023aa
    if (!cpu.flags.zf)
    {
        goto L_0x005023aa;
    }
    // 0050247e  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00502482  894608                 -mov dword ptr [esi + 8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00502485  e920ffffff             -jmp 0x5023aa
    goto L_0x005023aa;
L_0x0050248a:
    // 0050248a  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0050248d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050248e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050248f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00502490  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00502491  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_5024a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005024a0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005024a1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005024a2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 005024a3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005024a4  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 005024a6  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 005024a8  8d0c8500000000         -lea ecx, [eax*4]
    cpu.ecx = x86::reg32(cpu.eax * 4);
    // 005024af  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 005024b1  8b0c8d3ca1a000         -mov ecx, dword ptr [ecx*4 + 0xa0a13c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527036) /* 0xa0a13c */ + cpu.ecx * 4);
    // 005024b8  8a5904                 -mov bl, byte ptr [ecx + 4]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 005024bb  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 005024bd  80fb04                 +cmp bl, 4
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(4 /*0x4*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 005024c0  7502                   -jne 0x5024c4
    if (!cpu.flags.zf)
    {
        goto L_0x005024c4;
    }
    // 005024c2  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
L_0x005024c4:
    // 005024c4  e8a7000000             -call 0x502570
    cpu.esp -= 4;
    sub_502570(app, cpu);
    if (cpu.terminate) return;
    // 005024c9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005024cb  0f857b000000           -jne 0x50254c
    if (!cpu.flags.zf)
    {
        goto L_0x0050254c;
    }
    // 005024d1  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 005024d3  0f8c73000000           -jl 0x50254c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0050254c;
    }
    // 005024d9  668b4106               -mov ax, word ptr [ecx + 6]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(6) /* 0x6 */);
    // 005024dd  39c6                   +cmp esi, eax
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
    // 005024df  7d6b                   -jge 0x50254c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0050254c;
    }
    // 005024e1  8a4104                 -mov al, byte ptr [ecx + 4]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 005024e4  8d1cb500000000         -lea ebx, [esi*4]
    cpu.ebx = x86::reg32(cpu.esi * 4);
    // 005024eb  3c04                   +cmp al, 4
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
    // 005024ed  7567                   -jne 0x502556
    if (!cpu.flags.zf)
    {
        goto L_0x00502556;
    }
    // 005024ef  8b5c1f14               -mov ebx, dword ptr [edi + ebx + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(20) /* 0x14 */ + cpu.ebx * 1);
L_0x005024f3:
    // 005024f3  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 005024f5  7455                   -je 0x50254c
    if (cpu.flags.zf)
    {
        goto L_0x0050254c;
    }
    // 005024f7  66813b5054             +cmp word ptr [ebx], 0x5450
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.ebx);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(21584 /*0x5450*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 005024fc  742d                   -je 0x50252b
    if (cpu.flags.zf)
    {
        goto L_0x0050252b;
    }
    // 005024fe  bd10e95400             -mov ebp, 0x54e910
    cpu.ebp = 5564688 /*0x54e910*/;
    // 00502503  b820e95400             -mov eax, 0x54e920
    cpu.eax = 5564704 /*0x54e920*/;
    // 00502508  6834e95400             -push 0x54e934
    app->getMemory<x86::reg32>(cpu.esp-4) = 5564724 /*0x54e934*/;
    cpu.esp -= 4;
    // 0050250d  892d90215500           -mov dword ptr [0x552190], ebp
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ebp;
    // 00502513  bd25000000             -mov ebp, 0x25
    cpu.ebp = 37 /*0x25*/;
    // 00502518  a394215500             -mov dword ptr [0x552194], eax
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.eax;
    // 0050251d  892d98215500           -mov dword ptr [0x552198], ebp
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ebp;
    // 00502523  e8e8eaefff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 00502528  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0050252b:
    // 0050252b  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0050252d  e89efdffff             -call 0x5022d0
    cpu.esp -= 4;
    sub_5022d0(app, cpu);
    if (cpu.terminate) return;
    // 00502532  8a6104                 -mov ah, byte ptr [ecx + 4]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00502535  c1e602                 -shl esi, 2
    cpu.esi <<= 2 /*0x2*/ % 32;
    // 00502538  80fc04                 +cmp ah, 4
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(4 /*0x4*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0050253b  751f                   -jne 0x50255c
    if (!cpu.flags.zf)
    {
        goto L_0x0050255c;
    }
    // 0050253d  c744371400000000       -mov dword ptr [edi + esi + 0x14], 0
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(20) /* 0x14 */ + cpu.esi * 1) = 0 /*0x0*/;
    // 00502545  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00502547  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00502548  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00502549  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050254a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050254b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050254c:
    // 0050254c  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 00502551  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00502552  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00502553  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00502554  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00502555  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00502556:
    // 00502556  8b5c190c               -mov ebx, dword ptr [ecx + ebx + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */ + cpu.ebx * 1);
    // 0050255a  eb97                   -jmp 0x5024f3
    goto L_0x005024f3;
L_0x0050255c:
    // 0050255c  c744310c00000000       -mov dword ptr [ecx + esi + 0xc], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */ + cpu.esi * 1) = 0 /*0x0*/;
    // 00502564  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00502566  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00502567  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00502568  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00502569  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050256a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_502570(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00502570  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00502571  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00502573  7c28                   -jl 0x50259d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0050259d;
    }
    // 00502575  83f818                 +cmp eax, 0x18
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
    // 00502578  7d23                   -jge 0x50259d
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0050259d;
    }
    // 0050257a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0050257c  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0050257f  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00502581  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00502584  83b83ca1a00000         +cmp dword ptr [eax + 0xa0a13c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(10527036) /* 0xa0a13c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050258b  7410                   -je 0x50259d
    if (cpu.flags.zf)
    {
        goto L_0x0050259d;
    }
    // 0050258d  80b844a1a00000         +cmp byte ptr [eax + 0xa0a144], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(10527044) /* 0xa0a144 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00502594  740e                   -je 0x5025a4
    if (cpu.flags.zf)
    {
        goto L_0x005025a4;
    }
    // 00502596  b8eeffffff             -mov eax, 0xffffffee
    cpu.eax = 4294967278 /*0xffffffee*/;
    // 0050259b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050259c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050259d:
    // 0050259d  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 005025a2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005025a3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005025a4:
    // 005025a4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 005025a6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005025a7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_5025b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005025b0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005025b1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 005025b2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005025b3  8b0d3ca1a000           -mov ecx, dword ptr [0xa0a13c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10527036) /* 0xa0a13c */);
    // 005025b9  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 005025bb  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 005025bd  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 005025bf  7414                   -je 0x5025d5
    if (cpu.flags.zf)
    {
        goto L_0x005025d5;
    }
L_0x005025c1:
    // 005025c1  83c00c                 -add eax, 0xc
    (cpu.eax) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 005025c4  42                     -inc edx
    (cpu.edx)++;
    // 005025c5  3d20010000             +cmp eax, 0x120
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(288 /*0x120*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005025ca  7d0f                   -jge 0x5025db
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x005025db;
    }
    // 005025cc  83b83ca1a00000         +cmp dword ptr [eax + 0xa0a13c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(10527036) /* 0xa0a13c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005025d3  75ec                   -jne 0x5025c1
    if (!cpu.flags.zf)
    {
        goto L_0x005025c1;
    }
L_0x005025d5:
    // 005025d5  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 005025d7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005025d8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005025d9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005025da  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005025db:
    // 005025db  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 005025dc  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005025dd  be60e95400             -mov esi, 0x54e960
    cpu.esi = 5564768 /*0x54e960*/;
    // 005025e2  bf70e95400             -mov edi, 0x54e970
    cpu.edi = 5564784 /*0x54e970*/;
    // 005025e7  bd10000000             -mov ebp, 0x10
    cpu.ebp = 16 /*0x10*/;
    // 005025ec  6880e95400             -push 0x54e980
    app->getMemory<x86::reg32>(cpu.esp-4) = 5564800 /*0x54e980*/;
    cpu.esp -= 4;
    // 005025f1  893590215500           -mov dword ptr [0x552190], esi
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.esi;
    // 005025f7  893d94215500           -mov dword ptr [0x552194], edi
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.edi;
    // 005025fd  892d98215500           -mov dword ptr [0x552198], ebp
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ebp;
    // 00502603  e808eaefff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 00502608  b8f7ffffff             -mov eax, 0xfffffff7
    cpu.eax = 4294967287 /*0xfffffff7*/;
    // 0050260d  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00502610  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00502611  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00502612  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00502613  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00502614  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00502615  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_502620(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00502620  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00502621  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00502622  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00502623  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00502624  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00502625  81ec100c0000           -sub esp, 0xc10
    (cpu.esp) -= x86::reg32(x86::sreg32(3088 /*0xc10*/));
    // 0050262b  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0050262d  899424040c0000         -mov dword ptr [esp + 0xc04], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(3076) /* 0xc04 */) = cpu.edx;
    // 00502634  ba07000000             -mov edx, 7
    cpu.edx = 7 /*0x7*/;
    // 00502639  bbffffffff             -mov ebx, 0xffffffff
    cpu.ebx = 4294967295 /*0xffffffff*/;
    // 0050263e  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00502640  899424000c0000         -mov dword ptr [esp + 0xc00], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(3072) /* 0xc00 */) = cpu.edx;
L_0x00502647:
    // 00502647  83c10c                 -add ecx, 0xc
    (cpu.ecx) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0050264a  895c0cf4               -mov dword ptr [esp + ecx - 0xc], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(-12) /* -0xc */ + cpu.ecx * 1) = cpu.ebx;
    // 0050264e  81f9000c0000           +cmp ecx, 0xc00
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3072 /*0xc00*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00502654  75f1                   -jne 0x502647
    if (!cpu.flags.zf)
    {
        goto L_0x00502647;
    }
    // 00502656  8a6604                 -mov ah, byte ptr [esi + 4]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00502659  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
    // 0050265b  80fc04                 +cmp ah, 4
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(4 /*0x4*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0050265e  753c                   -jne 0x50269c
    if (!cpu.flags.zf)
    {
        goto L_0x0050269c;
    }
L_0x00502660:
    // 00502660  8d4614                 -lea eax, [esi + 0x14]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 00502663  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00502665  8984240c0c0000         -mov dword ptr [esp + 0xc0c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(3084) /* 0xc0c */) = cpu.eax;
    // 0050266c  8d450c                 -lea eax, [ebp + 0xc]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0050266f  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00502671  898424080c0000         -mov dword ptr [esp + 0xc08], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(3080) /* 0xc08 */) = cpu.eax;
L_0x00502678:
    // 00502678  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0050267a  668b4606               -mov ax, word ptr [esi + 6]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(6) /* 0x6 */);
    // 0050267e  39c7                   +cmp edi, eax
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
    // 00502680  0f8db9000000           -jge 0x50273f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0050273f;
    }
    // 00502686  807e0404               +cmp byte ptr [esi + 4], 4
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(4) /* 0x4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(4 /*0x4*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0050268a  754a                   -jne 0x5026d6
    if (!cpu.flags.zf)
    {
        goto L_0x005026d6;
    }
    // 0050268c  8d040e                 -lea eax, [esi + ecx]
    cpu.eax = x86::reg32(cpu.esi + cpu.ecx * 1);
    // 0050268f  8b4014                 -mov eax, dword ptr [eax + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 00502692  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00502694  7550                   -jne 0x5026e6
    if (!cpu.flags.zf)
    {
        goto L_0x005026e6;
    }
L_0x00502696:
    // 00502696  83c104                 +add ecx, 4
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
    // 00502699  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0050269a  ebdc                   -jmp 0x502678
    goto L_0x00502678;
L_0x0050269c:
    // 0050269c  80fc02                 +cmp ah, 2
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
    // 0050269f  74bf                   -je 0x502660
    if (cpu.flags.zf)
    {
        goto L_0x00502660;
    }
    // 005026a1  c70594215500c4e95400   -mov dword ptr [0x552194], 0x54e9c4
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = 5564868 /*0x54e9c4*/;
    // 005026ab  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 005026ad  8a4604                 -mov al, byte ptr [esi + 4]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 005026b0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 005026b1  bfb4e95400             -mov edi, 0x54e9b4
    cpu.edi = 5564852 /*0x54e9b4*/;
    // 005026b6  ba1b000000             -mov edx, 0x1b
    cpu.edx = 27 /*0x1b*/;
    // 005026bb  68d8e95400             -push 0x54e9d8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5564888 /*0x54e9d8*/;
    cpu.esp -= 4;
    // 005026c0  893d90215500           -mov dword ptr [0x552190], edi
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edi;
    // 005026c6  891598215500           -mov dword ptr [0x552198], edx
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.edx;
    // 005026cc  e83fe9efff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 005026d1  83c408                 +add esp, 8
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
    // 005026d4  eb8a                   -jmp 0x502660
    goto L_0x00502660;
L_0x005026d6:
    // 005026d6  8d0429                 -lea eax, [ecx + ebp]
    cpu.eax = x86::reg32(cpu.ecx + cpu.ebp * 1);
    // 005026d9  8b400c                 -mov eax, dword ptr [eax + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 005026dc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005026de  7506                   -jne 0x5026e6
    if (!cpu.flags.zf)
    {
        goto L_0x005026e6;
    }
    // 005026e0  83c104                 +add ecx, 4
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
    // 005026e3  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 005026e4  eb92                   -jmp 0x502678
    goto L_0x00502678;
L_0x005026e6:
    // 005026e6  807e0404               +cmp byte ptr [esi + 4], 4
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(4) /* 0x4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(4 /*0x4*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 005026ea  753d                   -jne 0x502729
    if (!cpu.flags.zf)
    {
        goto L_0x00502729;
    }
    // 005026ec  8d040e                 -lea eax, [esi + ecx]
    cpu.eax = x86::reg32(cpu.esi + cpu.ecx * 1);
    // 005026ef  8b9c240c0c0000         -mov ebx, dword ptr [esp + 0xc0c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(3084) /* 0xc0c */);
    // 005026f6  8b5014                 -mov edx, dword ptr [eax + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 005026f9  01cb                   -add ebx, ecx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 005026fb  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 005026fd  895814                 -mov dword ptr [eax + 0x14], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ebx;
L_0x00502700:
    // 00502700  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00502702  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 00502704  8b9424040c0000         -mov edx, dword ptr [esp + 0xc04]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(3076) /* 0xc04 */);
    // 0050270b  e89cfaffff             -call 0x5021ac
    cpu.esp -= 4;
    sub_5021ac(app, cpu);
    if (cpu.terminate) return;
    // 00502710  83f807                 +cmp eax, 7
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
    // 00502713  7481                   -je 0x502696
    if (cpu.flags.zf)
    {
        goto L_0x00502696;
    }
    // 00502715  c78424000c000008000000 -mov dword ptr [esp + 0xc00], 8
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(3072) /* 0xc00 */) = 8 /*0x8*/;
    // 00502720  83c104                 +add ecx, 4
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
    // 00502723  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00502724  e94fffffff             -jmp 0x502678
    goto L_0x00502678;
L_0x00502729:
    // 00502729  8d0429                 -lea eax, [ecx + ebp]
    cpu.eax = x86::reg32(cpu.ecx + cpu.ebp * 1);
    // 0050272c  8b9c24080c0000         -mov ebx, dword ptr [esp + 0xc08]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(3080) /* 0xc08 */);
    // 00502733  8b500c                 -mov edx, dword ptr [eax + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00502736  01cb                   -add ebx, ecx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00502738  01d3                   +add ebx, edx
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
    // 0050273a  89580c                 -mov dword ptr [eax + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 0050273d  ebc1                   -jmp 0x502700
    goto L_0x00502700;
L_0x0050273f:
    // 0050273f  8b8424000c0000         -mov eax, dword ptr [esp + 0xc00]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(3072) /* 0xc00 */);
    // 00502746  81c4100c0000           -add esp, 0xc10
    (cpu.esp) += x86::reg32(x86::sreg32(3088 /*0xc10*/));
    // 0050274c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050274d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050274e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050274f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00502750  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00502751  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_502760(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00502760  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00502761  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00502762  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00502763  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00502764  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00502765  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00502766  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00502768  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0050276b  ff1568775600           -call dword ptr [0x567768]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666664) /* 0x567768 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00502771  8a610d                 -mov ah, byte ptr [ecx + 0xd]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(13) /* 0xd */);
    // 00502774  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 00502776  f6c410                 +test ah, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 16 /*0x10*/));
    // 00502779  0f847a000000           -je 0x5027f9
    if (cpu.flags.zf)
    {
        goto L_0x005027f9;
    }
    // 0050277f  88e7                   -mov bh, ah
    cpu.bh = cpu.ah;
    // 00502781  80e7ef                 -and bh, 0xef
    cpu.bh &= x86::reg8(x86::sreg8(239 /*0xef*/));
    // 00502784  8a410c                 -mov al, byte ptr [ecx + 0xc]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00502787  88790d                 -mov byte ptr [ecx + 0xd], bh
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(13) /* 0xd */) = cpu.bh;
    // 0050278a  a802                   +test al, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 2 /*0x2*/));
    // 0050278c  0f84a2000000           -je 0x502834
    if (cpu.flags.zf)
    {
        goto L_0x00502834;
    }
    // 00502792  8b7908                 -mov edi, dword ptr [ecx + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00502795  8b5f08                 -mov ebx, dword ptr [edi + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 00502798  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0050279a  0f8494000000           -je 0x502834
    if (cpu.flags.zf)
    {
        goto L_0x00502834;
    }
    // 005027a0  8b7104                 -mov esi, dword ptr [ecx + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 005027a3  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 005027a5  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 005027a7  0f8487000000           -je 0x502834
    if (cpu.flags.zf)
    {
        goto L_0x00502834;
    }
L_0x005027ad:
    // 005027ad  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 005027af  0f857f000000           -jne 0x502834
    if (!cpu.flags.zf)
    {
        goto L_0x00502834;
    }
    // 005027b5  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 005027b7  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 005027b9  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 005027bc  e8ff6e0000             -call 0x5096c0
    cpu.esp -= 4;
    sub_5096c0(app, cpu);
    if (cpu.terminate) return;
    // 005027c1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 005027c3  83f8ff                 +cmp eax, -1
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
    // 005027c6  750d                   -jne 0x5027d5
    if (!cpu.flags.zf)
    {
        goto L_0x005027d5;
    }
    // 005027c8  8a590c                 -mov bl, byte ptr [ecx + 0xc]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 005027cb  80cb20                 +or bl, 0x20
    cpu.clear_co();
    cpu.set_szp((cpu.bl |= x86::reg8(x86::sreg8(32 /*0x20*/))));
    // 005027ce  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 005027d0  88590c                 -mov byte ptr [ecx + 0xc], bl
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.bl;
    // 005027d3  eb1c                   -jmp 0x5027f1
    goto L_0x005027f1;
L_0x005027d5:
    // 005027d5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005027d7  7518                   -jne 0x5027f1
    if (!cpu.flags.zf)
    {
        goto L_0x005027f1;
    }
    // 005027d9  b80c000000             -mov eax, 0xc
    cpu.eax = 12 /*0xc*/;
    // 005027de  e89d000000             -call 0x502880
    cpu.esp -= 4;
    sub_502880(app, cpu);
    if (cpu.terminate) return;
    // 005027e3  8a610c                 -mov ah, byte ptr [ecx + 0xc]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 005027e6  80cc20                 -or ah, 0x20
    cpu.ah |= x86::reg8(x86::sreg8(32 /*0x20*/));
    // 005027e9  bdffffffff             -mov ebp, 0xffffffff
    cpu.ebp = 4294967295 /*0xffffffff*/;
    // 005027ee  88610c                 -mov byte ptr [ecx + 0xc], ah
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.ah;
L_0x005027f1:
    // 005027f1  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 005027f3  29d6                   +sub esi, edx
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
    // 005027f5  75b6                   -jne 0x5027ad
    if (!cpu.flags.zf)
    {
        goto L_0x005027ad;
    }
    // 005027f7  eb3b                   -jmp 0x502834
    goto L_0x00502834;
L_0x005027f9:
    // 005027f9  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 005027fc  83780800               +cmp dword ptr [eax + 8], 0
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
    // 00502800  7432                   -je 0x502834
    if (cpu.flags.zf)
    {
        goto L_0x00502834;
    }
    // 00502802  80610cef               -and byte ptr [ecx + 0xc], 0xef
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */) &= x86::reg8(x86::sreg8(239 /*0xef*/));
    // 00502806  f6410d20               +test byte ptr [ecx + 0xd], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(13) /* 0xd */) & 32 /*0x20*/));
    // 0050280a  7528                   -jne 0x502834
    if (!cpu.flags.zf)
    {
        goto L_0x00502834;
    }
    // 0050280c  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0050280f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00502811  7411                   -je 0x502824
    if (cpu.flags.zf)
    {
        goto L_0x00502824;
    }
    // 00502813  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00502815  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0050281a  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
    // 0050281c  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0050281f  e8bc000000             -call 0x5028e0
    cpu.esp -= 4;
    sub_5028e0(app, cpu);
    if (cpu.terminate) return;
L_0x00502824:
    // 00502824  83f8ff                 +cmp eax, -1
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
    // 00502827  750b                   -jne 0x502834
    if (!cpu.flags.zf)
    {
        goto L_0x00502834;
    }
    // 00502829  8a590c                 -mov bl, byte ptr [ecx + 0xc]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 0050282c  80cb20                 -or bl, 0x20
    cpu.bl |= x86::reg8(x86::sreg8(32 /*0x20*/));
    // 0050282f  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00502831  88590c                 -mov byte ptr [ecx + 0xc], bl
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.bl;
L_0x00502834:
    // 00502834  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00502837  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0050283a  c7410400000000         -mov dword ptr [ecx + 4], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 00502841  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 00502843  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00502845  7518                   -jne 0x50285f
    if (!cpu.flags.zf)
    {
        goto L_0x0050285f;
    }
    // 00502847  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 0050284a  f6401001               +test byte ptr [eax + 0x10], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(16) /* 0x10 */) & 1 /*0x1*/));
    // 0050284e  740f                   -je 0x50285f
    if (cpu.flags.zf)
    {
        goto L_0x0050285f;
    }
    // 00502850  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00502853  e828050200             -call 0x522d80
    cpu.esp -= 4;
    sub_522d80(app, cpu);
    if (cpu.terminate) return;
    // 00502858  83f8ff                 +cmp eax, -1
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
    // 0050285b  7502                   -jne 0x50285f
    if (!cpu.flags.zf)
    {
        goto L_0x0050285f;
    }
    // 0050285d  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
L_0x0050285f:
    // 0050285f  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00502862  ff156c775600           -call dword ptr [0x56776c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666668) /* 0x56776c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00502868  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0050286a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050286b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050286c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050286d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050286e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050286f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00502870  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_502880(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00502880  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00502881  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00502883  ff1564775600           -call dword ptr [0x567764]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666660) /* 0x567764 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00502889  895004                 -mov dword ptr [eax + 4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0050288c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050288d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_502890(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00502890  b80d000000             -mov eax, 0xd
    cpu.eax = 13 /*0xd*/;
    // 00502895  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00502896  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00502898  ff1564775600           -call dword ptr [0x567764]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666660) /* 0x567764 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050289e  895004                 -mov dword ptr [eax + 4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 005028a1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005028a2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_5028a4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005028a4  b80e000000             -mov eax, 0xe
    cpu.eax = 14 /*0xe*/;
    // 005028a9  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 005028aa  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 005028ac  ff1564775600           -call dword ptr [0x567764]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666660) /* 0x567764 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005028b2  895004                 -mov dword ptr [eax + 4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 005028b5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005028b6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_5028b8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005028b8  b809000000             -mov eax, 9
    cpu.eax = 9 /*0x9*/;
    // 005028bd  e8beffffff             -call 0x502880
    cpu.esp -= 4;
    sub_502880(app, cpu);
    if (cpu.terminate) return;
    // 005028c2  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 005028c7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_5028c8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005028c8  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 005028c9  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 005028cb  ff1564775600           -call dword ptr [0x567764]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666660) /* 0x567764 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005028d1  895008                 -mov dword ptr [eax + 8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 005028d4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005028d5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_5028e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005028e0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005028e1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005028e2  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 005028e4  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 005028e6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005028e8  7c08                   -jl 0x5028f2
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x005028f2;
    }
    // 005028ea  3b0594ad5600           +cmp eax, dword ptr [0x56ad94]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5680532) /* 0x56ad94 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005028f0  7612                   -jbe 0x502904
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00502904;
    }
L_0x005028f2:
    // 005028f2  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 005028f7  e884ffffff             -call 0x502880
    cpu.esp -= 4;
    sub_502880(app, cpu);
    if (cpu.terminate) return;
    // 005028fc  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00502901  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00502902  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00502903  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00502904:
    // 00502904  ff1568775600           -call dword ptr [0x567768]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666664) /* 0x567768 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050290a  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0050290c  e8cf040200             -call 0x522de0
    cpu.esp -= 4;
    sub_522de0(app, cpu);
    if (cpu.terminate) return;
    // 00502911  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00502913  7e10                   -jle 0x502925
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00502925;
    }
    // 00502915  a880                   +test al, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 128 /*0x80*/));
    // 00502917  750c                   -jne 0x502925
    if (!cpu.flags.zf)
    {
        goto L_0x00502925;
    }
    // 00502919  80cc80                 -or ah, 0x80
    cpu.ah |= x86::reg8(x86::sreg8(128 /*0x80*/));
    // 0050291c  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0050291e  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00502920  e813050200             -call 0x522e38
    cpu.esp -= 4;
    sub_522e38(app, cpu);
    if (cpu.terminate) return;
L_0x00502925:
    // 00502925  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00502926  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00502928  8b15bcac5600           -mov edx, dword ptr [0x56acbc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5680316) /* 0x56acbc */);
    // 0050292e  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050292f  8b04b2                 -mov eax, dword ptr [edx + esi*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.esi * 4);
    // 00502932  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00502933  2eff15f0455300         -call dword ptr cs:[0x5345f0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457392) /* 0x5345f0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050293a  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0050293c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0050293e  ff156c775600           -call dword ptr [0x56776c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666668) /* 0x56776c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00502944  83f9ff                 +cmp ecx, -1
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
    // 00502947  7505                   -jne 0x50294e
    if (!cpu.flags.zf)
    {
        goto L_0x0050294e;
    }
    // 00502949  e8a6e6ffff             -call 0x500ff4
    cpu.esp -= 4;
    sub_500ff4(app, cpu);
    if (cpu.terminate) return;
L_0x0050294e:
    // 0050294e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00502950  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00502951  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00502952  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_502960(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00502960  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00502961  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00502962  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00502963  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00502965  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00502967  7c08                   -jl 0x502971
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00502971;
    }
    // 00502969  3b0594ad5600           +cmp eax, dword ptr [0x56ad94]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5680532) /* 0x56ad94 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050296f  7613                   -jbe 0x502984
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00502984;
    }
L_0x00502971:
    // 00502971  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 00502976  e805ffffff             -call 0x502880
    cpu.esp -= 4;
    sub_502880(app, cpu);
    if (cpu.terminate) return;
    // 0050297b  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00502980  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00502981  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00502982  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00502983  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00502984:
    // 00502984  8b15bcac5600           -mov edx, dword ptr [0x56acbc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5680316) /* 0x56acbc */);
    // 0050298a  8b149a                 -mov edx, dword ptr [edx + ebx*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + cpu.ebx * 4);
    // 0050298d  ff1568775600           -call dword ptr [0x567768]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666664) /* 0x567768 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00502993  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00502995  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00502997  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00502999  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0050299a  2eff15f0455300         -call dword ptr cs:[0x5345f0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457392) /* 0x5345f0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005029a1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 005029a3  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 005029a5  ff156c775600           -call dword ptr [0x56776c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666668) /* 0x56776c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005029ab  83faff                 +cmp edx, -1
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
    // 005029ae  7505                   -jne 0x5029b5
    if (!cpu.flags.zf)
    {
        goto L_0x005029b5;
    }
    // 005029b0  e83fe6ffff             -call 0x500ff4
    cpu.esp -= 4;
    sub_500ff4(app, cpu);
    if (cpu.terminate) return;
L_0x005029b5:
    // 005029b5  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 005029b7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005029b8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005029b9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005029ba  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_5029c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005029c0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 005029c1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005029c2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 005029c3  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 005029c5  e8b6690000             -call 0x509380
    cpu.esp -= 4;
    sub_509380(app, cpu);
    if (cpu.terminate) return;
    // 005029ca  837a1400               +cmp dword ptr [edx + 0x14], 0
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
    // 005029ce  7526                   -jne 0x5029f6
    if (!cpu.flags.zf)
    {
        goto L_0x005029f6;
    }
    // 005029d0  8a620d                 -mov ah, byte ptr [edx + 0xd]
    cpu.ah = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(13) /* 0xd */);
    // 005029d3  f6c402                 +test ah, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 2 /*0x2*/));
    // 005029d6  7409                   -je 0x5029e1
    if (cpu.flags.zf)
    {
        goto L_0x005029e1;
    }
    // 005029d8  c7421486000000         -mov dword ptr [edx + 0x14], 0x86
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */) = 134 /*0x86*/;
    // 005029df  eb15                   -jmp 0x5029f6
    goto L_0x005029f6;
L_0x005029e1:
    // 005029e1  f6c404                 +test ah, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 4 /*0x4*/));
    // 005029e4  7409                   -je 0x5029ef
    if (cpu.flags.zf)
    {
        goto L_0x005029ef;
    }
    // 005029e6  c7421401000000         -mov dword ptr [edx + 0x14], 1
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */) = 1 /*0x1*/;
    // 005029ed  eb07                   -jmp 0x5029f6
    goto L_0x005029f6;
L_0x005029ef:
    // 005029ef  c7421400100000         -mov dword ptr [edx + 0x14], 0x1000
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */) = 4096 /*0x1000*/;
L_0x005029f6:
    // 005029f6  8b4214                 -mov eax, dword ptr [edx + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */);
    // 005029f9  e8024fffff             -call 0x4f7900
    cpu.esp -= 4;
    sub_4f7900(app, cpu);
    if (cpu.terminate) return;
    // 005029fe  8b5a08                 -mov ebx, dword ptr [edx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00502a01  894308                 -mov dword ptr [ebx + 8], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00502a04  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00502a07  83780800               +cmp dword ptr [eax + 8], 0
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
    // 00502a0b  7523                   -jne 0x502a30
    if (!cpu.flags.zf)
    {
        goto L_0x00502a30;
    }
    // 00502a0d  8a4a0d                 -mov cl, byte ptr [edx + 0xd]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(13) /* 0xd */);
    // 00502a10  80e1f8                 -and cl, 0xf8
    cpu.cl &= x86::reg8(x86::sreg8(248 /*0xf8*/));
    // 00502a13  884a0d                 -mov byte ptr [edx + 0xd], cl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(13) /* 0xd */) = cpu.cl;
    // 00502a16  88cd                   -mov ch, cl
    cpu.ch = cpu.cl;
    // 00502a18  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00502a1b  80cd04                 +or ch, 4
    cpu.clear_co();
    cpu.set_szp((cpu.ch |= x86::reg8(x86::sreg8(4 /*0x4*/))));
    // 00502a1e  8d5a18                 -lea ebx, [edx + 0x18]
    cpu.ebx = x86::reg32(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 00502a21  886a0d                 -mov byte ptr [edx + 0xd], ch
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(13) /* 0xd */) = cpu.ch;
    // 00502a24  895808                 -mov dword ptr [eax + 8], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 00502a27  c7421401000000         -mov dword ptr [edx + 0x14], 1
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */) = 1 /*0x1*/;
    // 00502a2e  eb04                   -jmp 0x502a34
    goto L_0x00502a34;
L_0x00502a30:
    // 00502a30  804a0c08               -or byte ptr [edx + 0xc], 8
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */) |= x86::reg8(x86::sreg8(8 /*0x8*/));
L_0x00502a34:
    // 00502a34  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00502a37  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00502a3a  c7420400000000         -mov dword ptr [edx + 4], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 00502a41  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 00502a43  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00502a44  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00502a45  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00502a46  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_502a50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00502a50  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00502a51  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00502a52  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00502a55  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00502a57  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00502a59  7c08                   -jl 0x502a63
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00502a63;
    }
    // 00502a5b  3b0594ad5600           +cmp eax, dword ptr [0x56ad94]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5680532) /* 0x56ad94 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00502a61  7611                   -jbe 0x502a74
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00502a74;
    }
L_0x00502a63:
    // 00502a63  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 00502a68  e813feffff             -call 0x502880
    cpu.esp -= 4;
    sub_502880(app, cpu);
    if (cpu.terminate) return;
    // 00502a6d  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00502a72  eb6e                   -jmp 0x502ae2
    goto L_0x00502ae2;
L_0x00502a74:
    // 00502a74  ff1568775600           -call dword ptr [0x567768]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666664) /* 0x567768 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00502a7a  833dd877560000         +cmp dword ptr [0x5677d8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5666776) /* 0x5677d8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00502a81  7424                   -je 0x502aa7
    if (cpu.flags.zf)
    {
        goto L_0x00502aa7;
    }
    // 00502a83  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00502a85  ff15b0775600           -call dword ptr [0x5677b0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666736) /* 0x5677b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00502a8b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00502a8d  7418                   -je 0x502aa7
    if (cpu.flags.zf)
    {
        goto L_0x00502aa7;
    }
    // 00502a8f  ff15d8775600           -call dword ptr [0x5677d8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666776) /* 0x5677d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00502a95  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00502a97  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00502a99  ff156c775600           -call dword ptr [0x56776c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666668) /* 0x56776c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00502a9f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00502aa1  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00502aa4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00502aa5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00502aa6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00502aa7:
    // 00502aa7  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00502aa9  8d4c2404               -lea ecx, [esp + 4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00502aad  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00502aae  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00502aaf  a1bcac5600             -mov eax, dword ptr [0x56acbc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5680316) /* 0x56acbc */);
    // 00502ab4  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00502ab5  8b04b0                 -mov eax, dword ptr [eax + esi*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + cpu.esi * 4);
    // 00502ab8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00502ab9  2eff15b0455300         -call dword ptr cs:[0x5345b0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457328) /* 0x5345b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00502ac0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00502ac2  7513                   -jne 0x502ad7
    if (!cpu.flags.zf)
    {
        goto L_0x00502ad7;
    }
    // 00502ac4  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00502ac6  ff156c775600           -call dword ptr [0x56776c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666668) /* 0x56776c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00502acc  e823e5ffff             -call 0x500ff4
    cpu.esp -= 4;
    sub_500ff4(app, cpu);
    if (cpu.terminate) return;
    // 00502ad1  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00502ad4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00502ad5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00502ad6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00502ad7:
    // 00502ad7  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00502ad9  ff156c775600           -call dword ptr [0x56776c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666668) /* 0x56776c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00502adf  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
L_0x00502ae2:
    // 00502ae2  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00502ae5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00502ae6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00502ae7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_502af0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00502af0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00502af1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00502af2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00502af3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00502af4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00502af5  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00502af7  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 00502afa  ff1568775600           -call dword ptr [0x567768]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666664) /* 0x567768 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00502b00  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00502b03  8b580c                 -mov ebx, dword ptr [eax + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00502b06  83fb01                 +cmp ebx, 1
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
    // 00502b09  741e                   -je 0x502b29
    if (cpu.flags.zf)
    {
        goto L_0x00502b29;
    }
    // 00502b0b  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00502b0d  7413                   -je 0x502b22
    if (cpu.flags.zf)
    {
        goto L_0x00502b22;
    }
    // 00502b0f  8b4210                 -mov eax, dword ptr [edx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00502b12  ff156c775600           -call dword ptr [0x56776c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666668) /* 0x56776c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00502b18  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00502b1d  e98e000000             -jmp 0x502bb0
    goto L_0x00502bb0;
L_0x00502b22:
    // 00502b22  c7400c01000000         -mov dword ptr [eax + 0xc], 1
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = 1 /*0x1*/;
L_0x00502b29:
    // 00502b29  f6420c01               +test byte ptr [edx + 0xc], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */) & 1 /*0x1*/));
    // 00502b2d  7515                   -jne 0x502b44
    if (!cpu.flags.zf)
    {
        goto L_0x00502b44;
    }
    // 00502b2f  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 00502b34  e847fdffff             -call 0x502880
    cpu.esp -= 4;
    sub_502880(app, cpu);
    if (cpu.terminate) return;
    // 00502b39  804a0c20               +or byte ptr [edx + 0xc], 0x20
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */) |= x86::reg8(x86::sreg8(32 /*0x20*/))));
    // 00502b3d  bbffffffff             -mov ebx, 0xffffffff
    cpu.ebx = 4294967295 /*0xffffffff*/;
    // 00502b42  eb20                   -jmp 0x502b64
    goto L_0x00502b64;
L_0x00502b44:
    // 00502b44  8b7204                 -mov esi, dword ptr [edx + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00502b47  4e                     -dec esi
    (cpu.esi)--;
    // 00502b48  897204                 -mov dword ptr [edx + 4], esi
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 00502b4b  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00502b4d  7d0b                   -jge 0x502b5a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00502b5a;
    }
    // 00502b4f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00502b51  e862000000             -call 0x502bb8
    cpu.esp -= 4;
    sub_502bb8(app, cpu);
    if (cpu.terminate) return;
    // 00502b56  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00502b58  eb0a                   -jmp 0x502b64
    goto L_0x00502b64;
L_0x00502b5a:
    // 00502b5a  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 00502b5c  40                     -inc eax
    (cpu.eax)++;
    // 00502b5d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00502b5f  8a58ff                 -mov bl, byte ptr [eax - 1]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(-1) /* -0x1 */);
    // 00502b62  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
L_0x00502b64:
    // 00502b64  f6420c40               +test byte ptr [edx + 0xc], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */) & 64 /*0x40*/));
    // 00502b68  753b                   -jne 0x502ba5
    if (!cpu.flags.zf)
    {
        goto L_0x00502ba5;
    }
    // 00502b6a  83fb0d                 +cmp ebx, 0xd
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(13 /*0xd*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00502b6d  7523                   -jne 0x502b92
    if (!cpu.flags.zf)
    {
        goto L_0x00502b92;
    }
    // 00502b6f  8b6a04                 -mov ebp, dword ptr [edx + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00502b72  4d                     -dec ebp
    (cpu.ebp)--;
    // 00502b73  896a04                 -mov dword ptr [edx + 4], ebp
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 00502b76  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00502b78  7d0b                   -jge 0x502b85
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00502b85;
    }
    // 00502b7a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00502b7c  e837000000             -call 0x502bb8
    cpu.esp -= 4;
    sub_502bb8(app, cpu);
    if (cpu.terminate) return;
    // 00502b81  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00502b83  eb0d                   -jmp 0x502b92
    goto L_0x00502b92;
L_0x00502b85:
    // 00502b85  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 00502b87  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 00502b89  40                     -inc eax
    (cpu.eax)++;
    // 00502b8a  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00502b90  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
L_0x00502b92:
    // 00502b92  83fb1a                 +cmp ebx, 0x1a
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(26 /*0x1a*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00502b95  750e                   -jne 0x502ba5
    if (!cpu.flags.zf)
    {
        goto L_0x00502ba5;
    }
    // 00502b97  8a6a0c                 -mov ch, byte ptr [edx + 0xc]
    cpu.ch = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00502b9a  80cd10                 -or ch, 0x10
    cpu.ch |= x86::reg8(x86::sreg8(16 /*0x10*/));
    // 00502b9d  bbffffffff             -mov ebx, 0xffffffff
    cpu.ebx = 4294967295 /*0xffffffff*/;
    // 00502ba2  886a0c                 -mov byte ptr [edx + 0xc], ch
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */) = cpu.ch;
L_0x00502ba5:
    // 00502ba5  8b4210                 -mov eax, dword ptr [edx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00502ba8  ff156c775600           -call dword ptr [0x56776c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666668) /* 0x56776c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00502bae  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x00502bb0:
    // 00502bb0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00502bb1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00502bb2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00502bb3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00502bb4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00502bb5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_502bb8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00502bb8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00502bb9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00502bba  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00502bbb  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00502bbd  e826000000             -call 0x502be8
    cpu.esp -= 4;
    sub_502be8(app, cpu);
    if (cpu.terminate) return;
    // 00502bc2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00502bc4  7509                   -jne 0x502bcf
    if (!cpu.flags.zf)
    {
        goto L_0x00502bcf;
    }
    // 00502bc6  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00502bcb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00502bcc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00502bcd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00502bce  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00502bcf:
    // 00502bcf  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00502bd2  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 00502bd4  4b                     -dec ebx
    (cpu.ebx)--;
    // 00502bd5  41                     -inc ecx
    (cpu.ecx)++;
    // 00502bd6  895a04                 -mov dword ptr [edx + 4], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 00502bd9  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 00502bdb  8a41ff                 -mov al, byte ptr [ecx - 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(-1) /* -0x1 */);
    // 00502bde  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00502be3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00502be4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00502be5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00502be6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_502be8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00502be8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00502be9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00502bea  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00502beb  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00502bec  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00502bee  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00502bf1  83780800               +cmp dword ptr [eax + 8], 0
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
    // 00502bf5  7507                   -jne 0x502bfe
    if (!cpu.flags.zf)
    {
        goto L_0x00502bfe;
    }
    // 00502bf7  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00502bf9  e8c2fdffff             -call 0x5029c0
    cpu.esp -= 4;
    sub_5029c0(app, cpu);
    if (cpu.terminate) return;
L_0x00502bfe:
    // 00502bfe  8a610d                 -mov ah, byte ptr [ecx + 0xd]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(13) /* 0xd */);
    // 00502c01  f6c420                 +test ah, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 32 /*0x20*/));
    // 00502c04  740f                   -je 0x502c15
    if (cpu.flags.zf)
    {
        goto L_0x00502c15;
    }
    // 00502c06  f6c406                 +test ah, 6
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 6 /*0x6*/));
    // 00502c09  740a                   -je 0x502c15
    if (cpu.flags.zf)
    {
        goto L_0x00502c15;
    }
    // 00502c0b  b800200000             -mov eax, 0x2000
    cpu.eax = 8192 /*0x2000*/;
    // 00502c10  e8432c0100             -call 0x515858
    cpu.esp -= 4;
    sub_515858(app, cpu);
    if (cpu.terminate) return;
L_0x00502c15:
    // 00502c15  8a710c                 -mov dh, byte ptr [ecx + 0xc]
    cpu.dh = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00502c18  80e6fb                 -and dh, 0xfb
    cpu.dh &= x86::reg8(x86::sreg8(251 /*0xfb*/));
    // 00502c1b  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00502c1e  88710c                 -mov byte ptr [ecx + 0xc], dh
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.dh;
    // 00502c21  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00502c24  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 00502c26  8b410c                 -mov eax, dword ptr [ecx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00502c29  2500240000             -and eax, 0x2400
    cpu.eax &= x86::reg32(x86::sreg32(9216 /*0x2400*/));
    // 00502c2e  3d00240000             +cmp eax, 0x2400
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(9216 /*0x2400*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00502c33  7523                   -jne 0x502c58
    if (!cpu.flags.zf)
    {
        goto L_0x00502c58;
    }
    // 00502c35  8b5910                 -mov ebx, dword ptr [ecx + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00502c38  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00502c3a  751c                   -jne 0x502c58
    if (!cpu.flags.zf)
    {
        goto L_0x00502c58;
    }
    // 00502c3c  895904                 -mov dword ptr [ecx + 4], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 00502c3f  e81c020200             -call 0x522e60
    cpu.esp -= 4;
    sub_522e60(app, cpu);
    if (cpu.terminate) return;
    // 00502c44  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00502c46  83f8ff                 +cmp eax, -1
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
    // 00502c49  742a                   -je 0x502c75
    if (cpu.flags.zf)
    {
        goto L_0x00502c75;
    }
    // 00502c4b  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 00502c4d  8810                   -mov byte ptr [eax], dl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.dl;
    // 00502c4f  c7410401000000         -mov dword ptr [ecx + 4], 1
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = 1 /*0x1*/;
    // 00502c56  eb42                   -jmp 0x502c9a
    goto L_0x00502c9a;
L_0x00502c58:
    // 00502c58  f6410d04               +test byte ptr [ecx + 0xd], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(13) /* 0xd */) & 4 /*0x4*/));
    // 00502c5c  7407                   -je 0x502c65
    if (cpu.flags.zf)
    {
        goto L_0x00502c65;
    }
    // 00502c5e  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00502c63  eb03                   -jmp 0x502c68
    goto L_0x00502c68;
L_0x00502c65:
    // 00502c65  8b5914                 -mov ebx, dword ptr [ecx + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
L_0x00502c68:
    // 00502c68  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 00502c6a  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00502c6d  e8defdffff             -call 0x502a50
    cpu.esp -= 4;
    sub_502a50(app, cpu);
    if (cpu.terminate) return;
    // 00502c72  894104                 -mov dword ptr [ecx + 4], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.eax;
L_0x00502c75:
    // 00502c75  8b7104                 -mov esi, dword ptr [ecx + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00502c78  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00502c7a  7f1e                   -jg 0x502c9a
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00502c9a;
    }
    // 00502c7c  750c                   -jne 0x502c8a
    if (!cpu.flags.zf)
    {
        goto L_0x00502c8a;
    }
    // 00502c7e  80490c10               -or byte ptr [ecx + 0xc], 0x10
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */) |= x86::reg8(x86::sreg8(16 /*0x10*/));
    // 00502c82  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00502c85  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00502c86  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00502c87  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00502c88  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00502c89  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00502c8a:
    // 00502c8a  8a790c                 -mov bh, byte ptr [ecx + 0xc]
    cpu.bh = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00502c8d  c7410400000000         -mov dword ptr [ecx + 4], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 00502c94  80cf20                 -or bh, 0x20
    cpu.bh |= x86::reg8(x86::sreg8(32 /*0x20*/));
    // 00502c97  88790c                 -mov byte ptr [ecx + 0xc], bh
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.bh;
L_0x00502c9a:
    // 00502c9a  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00502c9d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00502c9e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00502c9f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00502ca0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00502ca1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_502cb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00502cb0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00502cb1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00502cb2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00502cb3  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00502cb5  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00502cb8  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00502cba  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 00502cbd  053c9ba000             -add eax, 0xa09b3c
    (cpu.eax) += x86::reg32(x86::sreg32(10525500 /*0xa09b3c*/));
    // 00502cc2  8b500e                 -mov edx, dword ptr [eax + 0xe]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(14) /* 0xe */);
    // 00502cc5  668b5842               -mov bx, word ptr [eax + 0x42]
    cpu.bx = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(66) /* 0x42 */);
    // 00502cc9  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00502ccc  6685db                 +test bx, bx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.bx & cpu.bx));
    // 00502ccf  7424                   -je 0x502cf5
    if (cpu.flags.zf)
    {
        goto L_0x00502cf5;
    }
    // 00502cd1  8b4854                 -mov ecx, dword ptr [eax + 0x54]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(84) /* 0x54 */);
    // 00502cd4  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00502cd6  7446                   -je 0x502d1e
    if (cpu.flags.zf)
    {
        goto L_0x00502d1e;
    }
    // 00502cd8  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00502cda  8b5854                 -mov ebx, dword ptr [eax + 0x54]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(84) /* 0x54 */);
    // 00502cdd  8a4833                 -mov cl, byte ptr [eax + 0x33]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(51) /* 0x33 */);
    // 00502ce0  0fbe0c19               -movsx ecx, byte ptr [ecx + ebx]
    cpu.ecx = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.ecx + cpu.ebx * 1)));
L_0x00502ce4:
    // 00502ce4  8b5840                 -mov ebx, dword ptr [eax + 0x40]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(64) /* 0x40 */);
    // 00502ce7  83e940                 -sub ecx, 0x40
    (cpu.ecx) -= x86::reg32(x86::sreg32(64 /*0x40*/));
    // 00502cea  c1fb10                 -sar ebx, 0x10
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (16 /*0x10*/ % 32));
    // 00502ced  0fafcb                 -imul ecx, ebx
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 00502cf0  c1f906                 -sar ecx, 6
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (6 /*0x6*/ % 32));
    // 00502cf3  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
L_0x00502cf5:
    // 00502cf5  8b585c                 -mov ebx, dword ptr [eax + 0x5c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(92) /* 0x5c */);
    // 00502cf8  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00502cfa  741a                   -je 0x502d16
    if (cpu.flags.zf)
    {
        goto L_0x00502d16;
    }
    // 00502cfc  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00502cfe  8a483f                 -mov cl, byte ptr [eax + 0x3f]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(63) /* 0x3f */);
    // 00502d01  0fbe0c19               -movsx ecx, byte ptr [ecx + ebx]
    cpu.ecx = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.ecx + cpu.ebx * 1)));
    // 00502d05  8b583e                 -mov ebx, dword ptr [eax + 0x3e]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(62) /* 0x3e */);
    // 00502d08  83e940                 -sub ecx, 0x40
    (cpu.ecx) -= x86::reg32(x86::sreg32(64 /*0x40*/));
    // 00502d0b  c1fb10                 -sar ebx, 0x10
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (16 /*0x10*/ % 32));
    // 00502d0e  0fafcb                 -imul ecx, ebx
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 00502d11  c1f906                 -sar ecx, 6
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (6 /*0x6*/ % 32));
    // 00502d14  01ca                   +add edx, ecx
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
L_0x00502d16:
    // 00502d16  66895012               -mov word ptr [eax + 0x12], dx
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(18) /* 0x12 */) = cpu.dx;
    // 00502d1a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00502d1b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00502d1c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00502d1d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00502d1e:
    // 00502d1e  8a4833                 -mov cl, byte ptr [eax + 0x33]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(51) /* 0x33 */);
    // 00502d21  ebc1                   -jmp 0x502ce4
    goto L_0x00502ce4;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_502d30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00502d30  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00502d31  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00502d32  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00502d33  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00502d36  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00502d38  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00502d3a  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00502d3c  c1e204                 -shl edx, 4
    cpu.edx <<= 4 /*0x4*/ % 32;
    // 00502d3f  81c258f69e00           -add edx, 0x9ef658
    (cpu.edx) += x86::reg32(x86::sreg32(10417752 /*0x9ef658*/));
    // 00502d45  8a5a05                 -mov bl, byte ptr [edx + 5]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5) /* 0x5 */);
    // 00502d48  84db                   +test bl, bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.bl));
    // 00502d4a  743b                   -je 0x502d87
    if (cpu.flags.zf)
    {
        goto L_0x00502d87;
    }
    // 00502d4c  80fb01                 +cmp bl, 1
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
    // 00502d4f  7436                   -je 0x502d87
    if (cpu.flags.zf)
    {
        goto L_0x00502d87;
    }
    // 00502d51  80fb02                 +cmp bl, 2
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
    // 00502d54  7431                   -je 0x502d87
    if (cpu.flags.zf)
    {
        goto L_0x00502d87;
    }
    // 00502d56  80fb03                 +cmp bl, 3
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
    // 00502d59  7554                   -jne 0x502daf
    if (!cpu.flags.zf)
    {
        goto L_0x00502daf;
    }
    // 00502d5b  e830010200             -call 0x522e90
    cpu.esp -= 4;
    sub_522e90(app, cpu);
    if (cpu.terminate) return;
    // 00502d60  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00502d62  668b02                 -mov ax, word ptr [edx]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edx);
    // 00502d65  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00502d68  db0424                 -fild dword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp))));
    // 00502d6b  dec9                   -fmulp st(1)
    cpu.fpu.st(1) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00502d6d  e8e4cffdff             -call 0x4dfd56
    cpu.esp -= 4;
    sub_4dfd56(app, cpu);
    if (cpu.terminate) return;
    // 00502d72  db1c24                 -fistp dword ptr [esp]
    app->getMemory<x86::reg32>(cpu.esp) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 00502d75  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    // 00502d78  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00502d79  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00502d7a  ff154cf69e00           -call dword ptr [0x9ef64c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10417740) /* 0x9ef64c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00502d80:
    // 00502d80  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00502d83  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00502d84  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00502d85  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00502d86  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00502d87:
    // 00502d87  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00502d88  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00502d8a  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00502d8c  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00502d8e  668b3d14f69e00         -mov di, word ptr [0x9ef614]
    cpu.di = app->getMemory<x86::reg16>(x86::reg32(10417684) /* 0x9ef614 */);
    // 00502d95  668b32                 -mov si, word ptr [edx]
    cpu.si = app->getMemory<x86::reg16>(cpu.edx);
    // 00502d98  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00502d9a  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00502d9c  e86f010200             -call 0x522f10
    cpu.esp -= 4;
    sub_522f10(app, cpu);
    if (cpu.terminate) return;
    // 00502da1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00502da3  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00502da5  e8a6010200             -call 0x522f50
    cpu.esp -= 4;
    sub_522f50(app, cpu);
    if (cpu.terminate) return;
    // 00502daa  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00502dac  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00502dad  ebd1                   -jmp 0x502d80
    goto L_0x00502d80;
L_0x00502daf:
    // 00502daf  ba0cea5400             -mov edx, 0x54ea0c
    cpu.edx = 5564940 /*0x54ea0c*/;
    // 00502db4  b91cea5400             -mov ecx, 0x54ea1c
    cpu.ecx = 5564956 /*0x54ea1c*/;
    // 00502db9  bb22000000             -mov ebx, 0x22
    cpu.ebx = 34 /*0x22*/;
    // 00502dbe  6830ea5400             -push 0x54ea30
    app->getMemory<x86::reg32>(cpu.esp-4) = 5564976 /*0x54ea30*/;
    cpu.esp -= 4;
    // 00502dc3  891590215500           -mov dword ptr [0x552190], edx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edx;
    // 00502dc9  890d94215500           -mov dword ptr [0x552194], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ecx;
    // 00502dcf  891d98215500           -mov dword ptr [0x552198], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ebx;
    // 00502dd5  e836e2efff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 00502dda  b8f9ffffff             -mov eax, 0xfffffff9
    cpu.eax = 4294967289 /*0xfffffff9*/;
    // 00502ddf  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00502de2  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00502de5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00502de6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00502de7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00502de8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_502df0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00502df0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00502df1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00502df2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00502df3  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00502df6  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00502df8  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00502dfa  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00502dfc  89fe                   -mov esi, edi
    cpu.esi = cpu.edi;
    // 00502dfe  c1e604                 -shl esi, 4
    cpu.esi <<= 4 /*0x4*/ % 32;
    // 00502e01  81c658f69e00           -add esi, 0x9ef658
    (cpu.esi) += x86::reg32(x86::sreg32(10417752 /*0x9ef658*/));
    // 00502e07  c6460600               -mov byte ptr [esi + 6], 0
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(6) /* 0x6 */) = 0 /*0x0*/;
    // 00502e0b  8a5e05                 -mov bl, byte ptr [esi + 5]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(5) /* 0x5 */);
    // 00502e0e  6689460a               -mov word ptr [esi + 0xa], ax
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(10) /* 0xa */) = cpu.ax;
    // 00502e12  80fb03                 +cmp bl, 3
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
    // 00502e15  7442                   -je 0x502e59
    if (cpu.flags.zf)
    {
        goto L_0x00502e59;
    }
    // 00502e17  80fb01                 +cmp bl, 1
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
    // 00502e1a  7448                   -je 0x502e64
    if (cpu.flags.zf)
    {
        goto L_0x00502e64;
    }
    // 00502e1c  84db                   +test bl, bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.bl));
    // 00502e1e  0f8581000000           -jne 0x502ea5
    if (!cpu.flags.zf)
    {
        goto L_0x00502ea5;
    }
L_0x00502e24:
    // 00502e24  8d34bd00000000         -lea esi, [edi*4]
    cpu.esi = x86::reg32(cpu.edi * 4);
    // 00502e2b  29fe                   -sub esi, edi
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.edi));
    // 00502e2d  c1e605                 -shl esi, 5
    cpu.esi <<= 5 /*0x5*/ % 32;
    // 00502e30  8d4c2404               -lea ecx, [esp + 4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00502e34  8b966a9ba000           -mov edx, dword ptr [esi + 0xa09b6a]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(10525546) /* 0xa09b6a */);
    // 00502e3a  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 00502e3c  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 00502e3f  e86cf60100             -call 0x5224b0
    cpu.esp -= 4;
    sub_5224b0(app, cpu);
    if (cpu.terminate) return;
L_0x00502e44:
    // 00502e44  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00502e48  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 00502e4b  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00502e4d  e852d8ffff             -call 0x5006a4
    cpu.esp -= 4;
    sub_5006a4(app, cpu);
    if (cpu.terminate) return;
L_0x00502e52:
    // 00502e52  83c408                 +add esp, 8
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
    // 00502e55  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00502e56  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00502e57  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00502e58  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00502e59:
    // 00502e59  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00502e5a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00502e5b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00502e5c  ff1544f69e00           -call dword ptr [0x9ef644]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10417732) /* 0x9ef644 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00502e62  ebee                   -jmp 0x502e52
    goto L_0x00502e52;
L_0x00502e64:
    // 00502e64  8b5606                 -mov edx, dword ptr [esi + 6]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(6) /* 0x6 */);
    // 00502e67  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 00502e6a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00502e6b  8b5605                 -mov edx, dword ptr [esi + 5]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5) /* 0x5 */);
    // 00502e6e  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 00502e71  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 00502e73  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00502e74  8d148d00000000         -lea edx, [ecx*4]
    cpu.edx = x86::reg32(cpu.ecx * 4);
    // 00502e7b  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00502e7d  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 00502e80  8d5c2408               -lea ebx, [esp + 8]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00502e84  8b926a9ba000           -mov edx, dword ptr [edx + 0xa09b6a]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(10525546) /* 0xa09b6a */);
    // 00502e8a  8d4c240c               -lea ecx, [esp + 0xc]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00502e8e  c1fa18                 +sar edx, 0x18
    {
        x86::reg8 tmp = 24 /*0x18*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (x86::sreg32(op) >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = 0;
            cpu.set_szp((op = x86::reg32(x86::sreg32(op) >> tmp)));
        }
    }
    // 00502e91  e88af40100             -call 0x522320
    cpu.esp -= 4;
    sub_522320(app, cpu);
    if (cpu.terminate) return;
    // 00502e96  8a0424                 -mov al, byte ptr [esp]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp);
    // 00502e99  884608                 -mov byte ptr [esi + 8], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.al;
    // 00502e9c  8a442404               -mov al, byte ptr [esp + 4]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00502ea0  884609                 -mov byte ptr [esi + 9], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(9) /* 0x9 */) = cpu.al;
    // 00502ea3  eb9f                   -jmp 0x502e44
    goto L_0x00502e44;
L_0x00502ea5:
    // 00502ea5  80fb02                 +cmp bl, 2
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
    // 00502ea8  0f8476ffffff           -je 0x502e24
    if (cpu.flags.zf)
    {
        goto L_0x00502e24;
    }
    // 00502eae  ba64ea5400             -mov edx, 0x54ea64
    cpu.edx = 5565028 /*0x54ea64*/;
    // 00502eb3  b974ea5400             -mov ecx, 0x54ea74
    cpu.ecx = 5565044 /*0x54ea74*/;
    // 00502eb8  bb29000000             -mov ebx, 0x29
    cpu.ebx = 41 /*0x29*/;
    // 00502ebd  6888ea5400             -push 0x54ea88
    app->getMemory<x86::reg32>(cpu.esp-4) = 5565064 /*0x54ea88*/;
    cpu.esp -= 4;
    // 00502ec2  891590215500           -mov dword ptr [0x552190], edx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edx;
    // 00502ec8  890d94215500           -mov dword ptr [0x552194], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ecx;
    // 00502ece  891d98215500           -mov dword ptr [0x552198], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ebx;
    // 00502ed4  e837e1efff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 00502ed9  83c404                 +add esp, 4
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
    // 00502edc  e963ffffff             -jmp 0x502e44
    goto L_0x00502e44;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_502ef0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00502ef0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00502ef1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00502ef2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00502ef3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00502ef4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00502ef5  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00502ef8  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00502efa  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 00502efc  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00502efe  c1e604                 -shl esi, 4
    cpu.esi <<= 4 /*0x4*/ % 32;
    // 00502f01  81c658f69e00           -add esi, 0x9ef658
    (cpu.esi) += x86::reg32(x86::sreg32(10417752 /*0x9ef658*/));
    // 00502f07  8a6605                 -mov ah, byte ptr [esi + 5]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(5) /* 0x5 */);
    // 00502f0a  c6460601               -mov byte ptr [esi + 6], 1
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(6) /* 0x6 */) = 1 /*0x1*/;
    // 00502f0e  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 00502f10  7405                   -je 0x502f17
    if (cpu.flags.zf)
    {
        goto L_0x00502f17;
    }
    // 00502f12  80fc02                 +cmp ah, 2
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
    // 00502f15  7539                   -jne 0x502f50
    if (!cpu.flags.zf)
    {
        goto L_0x00502f50;
    }
L_0x00502f17:
    // 00502f17  8d04bd00000000         -lea eax, [edi*4]
    cpu.eax = x86::reg32(cpu.edi * 4);
    // 00502f1e  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 00502f20  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 00502f23  8d4c2404               -lea ecx, [esp + 4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00502f27  8b906a9ba000           -mov edx, dword ptr [eax + 0xa09b6a]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(10525546) /* 0xa09b6a */);
    // 00502f2d  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 00502f2f  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 00502f32  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00502f34  e8b7f30100             -call 0x5222f0
    cpu.esp -= 4;
    sub_5222f0(app, cpu);
    if (cpu.terminate) return;
L_0x00502f39:
    // 00502f39  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00502f3d  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 00502f40  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00502f42  e85dd7ffff             -call 0x5006a4
    cpu.esp -= 4;
    sub_5006a4(app, cpu);
    if (cpu.terminate) return;
    // 00502f47  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00502f4a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00502f4b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00502f4c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00502f4d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00502f4e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00502f4f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00502f50:
    // 00502f50  8d6ac0                 -lea ebp, [edx - 0x40]
    cpu.ebp = x86::reg32(cpu.edx + x86::reg32(-64) /* -0x40 */);
    // 00502f53  c1e508                 -shl ebp, 8
    cpu.ebp <<= 8 /*0x8*/ % 32;
    // 00502f56  80fc01                 +cmp ah, 1
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
    // 00502f59  7435                   -je 0x502f90
    if (cpu.flags.zf)
    {
        goto L_0x00502f90;
    }
    // 00502f5b  80fc03                 +cmp ah, 3
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(3 /*0x3*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00502f5e  7476                   -je 0x502fd6
    if (cpu.flags.zf)
    {
        goto L_0x00502fd6;
    }
    // 00502f60  bac0ea5400             -mov edx, 0x54eac0
    cpu.edx = 5565120 /*0x54eac0*/;
    // 00502f65  b9ccea5400             -mov ecx, 0x54eacc
    cpu.ecx = 5565132 /*0x54eacc*/;
    // 00502f6a  bb2e000000             -mov ebx, 0x2e
    cpu.ebx = 46 /*0x2e*/;
    // 00502f6f  68d4ea5400             -push 0x54ead4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5565140 /*0x54ead4*/;
    cpu.esp -= 4;
    // 00502f74  891590215500           -mov dword ptr [0x552190], edx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edx;
    // 00502f7a  890d94215500           -mov dword ptr [0x552194], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ecx;
    // 00502f80  891d98215500           -mov dword ptr [0x552198], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ebx;
    // 00502f86  e885e0efff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 00502f8b  83c404                 +add esp, 4
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
    // 00502f8e  eba9                   -jmp 0x502f39
    goto L_0x00502f39;
L_0x00502f90:
    // 00502f90  8b4606                 -mov eax, dword ptr [esi + 6]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(6) /* 0x6 */);
    // 00502f93  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 00502f96  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00502f97  8b4605                 -mov eax, dword ptr [esi + 5]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5) /* 0x5 */);
    // 00502f9a  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 00502f9d  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00502f9f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00502fa0  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00502fa7  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00502fa9  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 00502fac  8d4c240c               -lea ecx, [esp + 0xc]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00502fb0  8b906a9ba000           -mov edx, dword ptr [eax + 0xa09b6a]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(10525546) /* 0xa09b6a */);
    // 00502fb6  8d5c2408               -lea ebx, [esp + 8]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00502fba  c1fa18                 +sar edx, 0x18
    {
        x86::reg8 tmp = 24 /*0x18*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (x86::sreg32(op) >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = 0;
            cpu.set_szp((op = x86::reg32(x86::sreg32(op) >> tmp)));
        }
    }
    // 00502fbd  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00502fbf  e85cf30100             -call 0x522320
    cpu.esp -= 4;
    sub_522320(app, cpu);
    if (cpu.terminate) return;
    // 00502fc4  8a0424                 -mov al, byte ptr [esp]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp);
    // 00502fc7  884608                 -mov byte ptr [esi + 8], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.al;
    // 00502fca  8a442404               -mov al, byte ptr [esp + 4]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00502fce  884609                 -mov byte ptr [esi + 9], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(9) /* 0x9 */) = cpu.al;
    // 00502fd1  e963ffffff             -jmp 0x502f39
    goto L_0x00502f39;
L_0x00502fd6:
    // 00502fd6  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00502fd8  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00502fd9  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00502fda  ff1544f69e00           -call dword ptr [0x9ef644]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10417732) /* 0x9ef644 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00502fe0  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00502fe3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00502fe4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00502fe5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00502fe6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00502fe7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00502fe8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_502ff0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00502ff0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00502ff1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00502ff2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00502ff3  83f81e                 +cmp eax, 0x1e
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(30 /*0x1e*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00502ff6  7315                   -jae 0x50300d
    if (!cpu.flags.cf)
    {
        goto L_0x0050300d;
    }
    // 00502ff8  83f805                 +cmp eax, 5
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5 /*0x5*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00502ffb  0f8398000000           -jae 0x503099
    if (!cpu.flags.cf)
    {
        goto L_0x00503099;
    }
    // 00503001  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00503003  0f855d000000           -jne 0x503066
    if (!cpu.flags.zf)
    {
        goto L_0x00503066;
    }
    // 00503009  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050300a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050300b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050300c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050300d:
    // 0050300d  7611                   -jbe 0x503020
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00503020;
    }
    // 0050300f  83f864                 +cmp eax, 0x64
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(100 /*0x64*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00503012  7344                   -jae 0x503058
    if (!cpu.flags.cf)
    {
        goto L_0x00503058;
    }
    // 00503014  83f828                 +cmp eax, 0x28
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(40 /*0x28*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00503017  724d                   -jb 0x503066
    if (cpu.flags.cf)
    {
        goto L_0x00503066;
    }
    // 00503019  7605                   -jbe 0x503020
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00503020;
    }
    // 0050301b  83f832                 +cmp eax, 0x32
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
    // 0050301e  7546                   -jne 0x503066
    if (!cpu.flags.zf)
    {
        goto L_0x00503066;
    }
L_0x00503020:
    // 00503020  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00503021  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00503022  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00503023  bab8305200             -mov edx, 0x5230b8
    cpu.edx = 5386424 /*0x5230b8*/;
    // 00503028  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0050302a  b9dc305200             -mov ecx, 0x5230dc
    cpu.ecx = 5386460 /*0x5230dc*/;
    // 0050302f  66a114f69e00           -mov ax, word ptr [0x9ef614]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(10417684) /* 0x9ef614 */);
    // 00503035  bb18315200             -mov ebx, 0x523118
    cpu.ebx = 5386520 /*0x523118*/;
    // 0050303a  e81d020200             -call 0x52325c
    cpu.esp -= 4;
    sub_52325c(app, cpu);
    if (cpu.terminate) return;
    // 0050303f  8915606a9f00           -mov dword ptr [0x9f6a60], edx
    app->getMemory<x86::reg32>(x86::reg32(10447456) /* 0x9f6a60 */) = cpu.edx;
    // 00503045  890d646a9f00           -mov dword ptr [0x9f6a64], ecx
    app->getMemory<x86::reg32>(x86::reg32(10447460) /* 0x9f6a64 */) = cpu.ecx;
    // 0050304b  891d686a9f00           -mov dword ptr [0x9f6a68], ebx
    app->getMemory<x86::reg32>(x86::reg32(10447464) /* 0x9f6a68 */) = cpu.ebx;
    // 00503051  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00503052  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00503053  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00503054  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00503055  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00503056  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00503057  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00503058:
    // 00503058  76c6                   -jbe 0x503020
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00503020;
    }
    // 0050305a  83f86e                 +cmp eax, 0x6e
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(110 /*0x6e*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050305d  7207                   -jb 0x503066
    if (cpu.flags.cf)
    {
        goto L_0x00503066;
    }
    // 0050305f  76bf                   -jbe 0x503020
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00503020;
    }
    // 00503061  83f878                 +cmp eax, 0x78
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(120 /*0x78*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
L_0x00503064:
    // 00503064  74ba                   -je 0x503020
    if (cpu.flags.zf)
    {
        goto L_0x00503020;
    }
L_0x00503066:
    // 00503066  be00eb5400             -mov esi, 0x54eb00
    cpu.esi = 5565184 /*0x54eb00*/;
    // 0050306b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0050306c  bf10eb5400             -mov edi, 0x54eb10
    cpu.edi = 5565200 /*0x54eb10*/;
    // 00503071  bd24000000             -mov ebp, 0x24
    cpu.ebp = 36 /*0x24*/;
    // 00503076  6820eb5400             -push 0x54eb20
    app->getMemory<x86::reg32>(cpu.esp-4) = 5565216 /*0x54eb20*/;
    cpu.esp -= 4;
    // 0050307b  893590215500           -mov dword ptr [0x552190], esi
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.esi;
    // 00503081  893d94215500           -mov dword ptr [0x552194], edi
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.edi;
    // 00503087  892d98215500           -mov dword ptr [0x552198], ebp
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ebp;
    // 0050308d  e87edfefff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 00503092  83c408                 +add esp, 8
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
    // 00503095  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00503096  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00503097  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00503098  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00503099:
    // 00503099  7685                   -jbe 0x503020
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00503020;
    }
    // 0050309b  83f80a                 +cmp eax, 0xa
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(10 /*0xa*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050309e  72c6                   -jb 0x503066
    if (cpu.flags.cf)
    {
        goto L_0x00503066;
    }
    // 005030a0  0f867affffff           -jbe 0x503020
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00503020;
    }
    // 005030a6  83f814                 +cmp eax, 0x14
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
    // 005030a9  ebb9                   -jmp 0x503064
    goto L_0x00503064;
}

/* align: skip 0x90 */
void Application::sub_5030ac(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005030ac  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 005030ae  c70554f69e00f02f5000   -mov dword ptr [0x9ef654], 0x502ff0
    app->getMemory<x86::reg32>(x86::reg32(10417748) /* 0x9ef654 */) = 5255152 /*0x502ff0*/;
    // 005030b8  803df49aa00000         +cmp byte ptr [0xa09af4], 0
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
    // 005030bf  7506                   -jne 0x5030c7
    if (!cpu.flags.zf)
    {
        goto L_0x005030c7;
    }
    // 005030c1  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 005030c4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 005030c6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005030c7:
    // 005030c7  e824ffffff             -call 0x502ff0
    cpu.esp -= 4;
    sub_502ff0(app, cpu);
    if (cpu.terminate) return;
    // 005030cc  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 005030ce  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_5030c4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x005030c4;
    // 005030ac  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 005030ae  c70554f69e00f02f5000   -mov dword ptr [0x9ef654], 0x502ff0
    app->getMemory<x86::reg32>(x86::reg32(10417748) /* 0x9ef654 */) = 5255152 /*0x502ff0*/;
    // 005030b8  803df49aa00000         +cmp byte ptr [0xa09af4], 0
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
    // 005030bf  7506                   -jne 0x5030c7
    if (!cpu.flags.zf)
    {
        goto L_0x005030c7;
    }
    // 005030c1  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_entry_0x005030c4:
    // 005030c4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 005030c6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005030c7:
    // 005030c7  e824ffffff             -call 0x502ff0
    cpu.esp -= 4;
    sub_502ff0(app, cpu);
    if (cpu.terminate) return;
    // 005030cc  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 005030ce  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_5030d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005030d0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005030d1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005030d2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 005030d3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005030d4  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 005030d7  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 005030d9  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 005030db  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 005030dd  8a25f49aa000           -mov ah, byte ptr [0xa09af4]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(10525428) /* 0xa09af4 */);
    // 005030e3  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 005030e5  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 005030e7  0f84f3000000           -je 0x5031e0
    if (cpu.flags.zf)
    {
        goto L_0x005031e0;
    }
    // 005030ed  83fd01                 +cmp ebp, 1
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005030f0  0f8df7000000           -jge 0x5031ed
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x005031ed;
    }
    // 005030f6  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 005030f8  0f8cef000000           -jl 0x5031ed
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x005031ed;
    }
L_0x005030fe:
    // 005030fe  83f97f                 +cmp ecx, 0x7f
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(127 /*0x7f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00503101  0f8e19010000           -jle 0x503220
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00503220;
    }
L_0x00503107:
    // 00503107  bb4ceb5400             -mov ebx, 0x54eb4c
    cpu.ebx = 5565260 /*0x54eb4c*/;
    // 0050310c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050310d  bf5ceb5400             -mov edi, 0x54eb5c
    cpu.edi = 5565276 /*0x54eb5c*/;
    // 00503112  b83d000000             -mov eax, 0x3d
    cpu.eax = 61 /*0x3d*/;
    // 00503117  6890eb5400             -push 0x54eb90
    app->getMemory<x86::reg32>(cpu.esp-4) = 5565328 /*0x54eb90*/;
    cpu.esp -= 4;
    // 0050311c  891d90215500           -mov dword ptr [0x552190], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ebx;
    // 00503122  893d94215500           -mov dword ptr [0x552194], edi
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.edi;
    // 00503128  a398215500             -mov dword ptr [0x552198], eax
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.eax;
    // 0050312d  e8dedeefff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 00503132  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x00503135:
    // 00503135  e8e6dcffff             -call 0x500e20
    cpu.esp -= 4;
    sub_500e20(app, cpu);
    if (cpu.terminate) return;
    // 0050313a  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0050313c  e85bcbffff             -call 0x4ffc9c
    cpu.esp -= 4;
    sub_4ffc9c(app, cpu);
    if (cpu.terminate) return;
    // 00503141  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00503143  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00503145  0f8ce2000000           -jl 0x50322d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0050322d;
    }
    // 0050314b  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0050314e  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00503150  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 00503153  053c9ba000             -add eax, 0xa09b3c
    (cpu.eax) += x86::reg32(x86::sreg32(10525500 /*0xa09b3c*/));
    // 00503158  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0050315a  8a583b                 -mov bl, byte ptr [eax + 0x3b]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(59) /* 0x3b */);
    // 0050315d  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 00503161  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 00503163  8b7c2404               -mov edi, dword ptr [esp + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00503167  c1e304                 -shl ebx, 4
    cpu.ebx <<= 4 /*0x4*/ % 32;
    // 0050316a  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0050316c  0f84cd000000           -je 0x50323f
    if (cpu.flags.zf)
    {
        goto L_0x0050323f;
    }
    // 00503172  be3c9ba000             -mov esi, 0xa09b3c
    cpu.esi = 10525500 /*0xa09b3c*/;
    // 00503177  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 0050317a  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
L_0x0050317c:
    // 0050317c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0050317e  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00503182  8a463b                 -mov al, byte ptr [esi + 0x3b]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(59) /* 0x3b */);
    // 00503185  39d8                   +cmp eax, ebx
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
    // 00503187  753f                   -jne 0x5031c8
    if (!cpu.flags.zf)
    {
        goto L_0x005031c8;
    }
    // 00503189  807e0c01               +cmp byte ptr [esi + 0xc], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(12) /* 0xc */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0050318d  7539                   -jne 0x5031c8
    if (!cpu.flags.zf)
    {
        goto L_0x005031c8;
    }
    // 0050318f  833e00                 +cmp dword ptr [esi], 0
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
    // 00503192  7c34                   -jl 0x5031c8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x005031c8;
    }
    // 00503194  8d142e                 -lea edx, [esi + ebp]
    cpu.edx = x86::reg32(cpu.esi + cpu.ebp * 1);
    // 00503197  884a39                 -mov byte ptr [edx + 0x39], cl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(57) /* 0x39 */) = cpu.cl;
    // 0050319a  8b5235                 -mov edx, dword ptr [edx + 0x35]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(53) /* 0x35 */);
    // 0050319d  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 005031a0  0fafd1                 -imul edx, ecx
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 005031a3  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 005031a6  0faf9060a2a000         -imul edx, dword ptr [eax + 0xa0a260]
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(10527328) /* 0xa0a260 */))));
    // 005031ad  b9013f0000             -mov ecx, 0x3f01
    cpu.ecx = 16129 /*0x3f01*/;
    // 005031b2  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 005031b4  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 005031b7  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 005031b9  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 005031bb  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 005031bd  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 005031bf  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 005031c1  e84a010200             -call 0x523310
    cpu.esp -= 4;
    sub_523310(app, cpu);
    if (cpu.terminate) return;
    // 005031c6  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
L_0x005031c8:
    // 005031c8  47                     -inc edi
    (cpu.edi)++;
    // 005031c9  83c660                 -add esi, 0x60
    (cpu.esi) += x86::reg32(x86::sreg32(96 /*0x60*/));
    // 005031cc  83ff10                 +cmp edi, 0x10
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005031cf  7cab                   -jl 0x50317c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0050317c;
    }
    // 005031d1  e8a6dcffff             -call 0x500e7c
    cpu.esp -= 4;
    sub_500e7c(app, cpu);
    if (cpu.terminate) return;
    // 005031d6  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 005031d8  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 005031db  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005031dc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005031dd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005031de  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005031df  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005031e0:
    // 005031e0  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 005031e5  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 005031e8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005031e9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005031ea  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005031eb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005031ec  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005031ed:
    // 005031ed  bb4ceb5400             -mov ebx, 0x54eb4c
    cpu.ebx = 5565260 /*0x54eb4c*/;
    // 005031f2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005031f3  bf5ceb5400             -mov edi, 0x54eb5c
    cpu.edi = 5565276 /*0x54eb5c*/;
    // 005031f8  b83a000000             -mov eax, 0x3a
    cpu.eax = 58 /*0x3a*/;
    // 005031fd  6868eb5400             -push 0x54eb68
    app->getMemory<x86::reg32>(cpu.esp-4) = 5565288 /*0x54eb68*/;
    cpu.esp -= 4;
    // 00503202  891d90215500           -mov dword ptr [0x552190], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ebx;
    // 00503208  893d94215500           -mov dword ptr [0x552194], edi
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.edi;
    // 0050320e  a398215500             -mov dword ptr [0x552198], eax
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.eax;
    // 00503213  e8f8ddefff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 00503218  83c408                 +add esp, 8
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
    // 0050321b  e9defeffff             -jmp 0x5030fe
    goto L_0x005030fe;
L_0x00503220:
    // 00503220  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00503222  0f8cdffeffff           -jl 0x503107
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00503107;
    }
    // 00503228  e908ffffff             -jmp 0x503135
    goto L_0x00503135;
L_0x0050322d:
    // 0050322d  e84adcffff             -call 0x500e7c
    cpu.esp -= 4;
    sub_500e7c(app, cpu);
    if (cpu.terminate) return;
    // 00503232  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 00503237  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0050323a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050323b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050323c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050323d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050323e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050323f:
    // 0050323f  884c2839               -mov byte ptr [eax + ebp + 0x39], cl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(57) /* 0x39 */ + cpu.ebp * 1) = cpu.cl;
    // 00503243  8b442835               -mov eax, dword ptr [eax + ebp + 0x35]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(53) /* 0x35 */ + cpu.ebp * 1);
    // 00503247  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 0050324a  0fafc1                 -imul eax, ecx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 0050324d  8b9360a2a000           -mov edx, dword ptr [ebx + 0xa0a260]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(10527328) /* 0xa0a260 */);
    // 00503253  0fafd0                 -imul edx, eax
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 00503256  b9013f0000             -mov ecx, 0x3f01
    cpu.ecx = 16129 /*0x3f01*/;
    // 0050325b  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0050325d  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00503260  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00503262  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00503264  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00503266  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00503268  e8a3000200             -call 0x523310
    cpu.esp -= 4;
    sub_523310(app, cpu);
    if (cpu.terminate) return;
    // 0050326d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0050326f  e808dcffff             -call 0x500e7c
    cpu.esp -= 4;
    sub_500e7c(app, cpu);
    if (cpu.terminate) return;
    // 00503274  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00503276  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00503279  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050327a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050327b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050327c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050327d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_503280(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00503280  92                     -xchg edx, eax
    {
        x86::reg32 tmp = cpu.edx;
        cpu.edx = cpu.eax;
        cpu.eax = tmp;
    }
    // 00503281  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00503282  a907000000             +test eax, 7
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 7 /*0x7*/));
    // 00503287  0f8504010000           -jne 0x503391
    if (!cpu.flags.zf)
    {
        goto L_0x00503391;
    }
L_0x0050328d:
    // 0050328d  81eb80000000           +sub ebx, 0x80
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
    // 00503293  787d                   -js 0x503312
    if (cpu.flags.sf)
    {
        goto L_0x00503312;
    }
L_0x00503295:
    // 00503295  df2a                   -fild qword ptr [edx]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.edx))));
    // 00503297  df6a20                 -fild qword ptr [edx + 0x20]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.edx + x86::reg32(32) /* 0x20 */))));
    // 0050329a  df6a40                 -fild qword ptr [edx + 0x40]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.edx + x86::reg32(64) /* 0x40 */))));
    // 0050329d  df6a60                 -fild qword ptr [edx + 0x60]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.edx + x86::reg32(96) /* 0x60 */))));
    // 005032a0  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 005032a2  df6a10                 -fild qword ptr [edx + 0x10]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.edx + x86::reg32(16) /* 0x10 */))));
    // 005032a5  df6a08                 -fild qword ptr [edx + 8]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.edx + x86::reg32(8) /* 0x8 */))));
    // 005032a8  df6a18                 -fild qword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.edx + x86::reg32(24) /* 0x18 */))));
    // 005032ab  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 005032ad  df38                   -fistp qword ptr [eax]
    app->getMemory<x86::reg64>(cpu.eax) = x86::reg64(x86::sreg64(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 005032af  df7808                 -fistp qword ptr [eax + 8]
    app->getMemory<x86::reg64>(cpu.eax + x86::reg32(8) /* 0x8 */) = x86::reg64(x86::sreg64(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 005032b2  df7810                 -fistp qword ptr [eax + 0x10]
    app->getMemory<x86::reg64>(cpu.eax + x86::reg32(16) /* 0x10 */) = x86::reg64(x86::sreg64(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 005032b5  df7818                 -fistp qword ptr [eax + 0x18]
    app->getMemory<x86::reg64>(cpu.eax + x86::reg32(24) /* 0x18 */) = x86::reg64(x86::sreg64(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 005032b8  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 005032ba  df6a30                 -fild qword ptr [edx + 0x30]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.edx + x86::reg32(48) /* 0x30 */))));
    // 005032bd  df6a28                 -fild qword ptr [edx + 0x28]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.edx + x86::reg32(40) /* 0x28 */))));
    // 005032c0  df6a38                 -fild qword ptr [edx + 0x38]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.edx + x86::reg32(56) /* 0x38 */))));
    // 005032c3  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 005032c5  df7820                 -fistp qword ptr [eax + 0x20]
    app->getMemory<x86::reg64>(cpu.eax + x86::reg32(32) /* 0x20 */) = x86::reg64(x86::sreg64(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 005032c8  df7828                 -fistp qword ptr [eax + 0x28]
    app->getMemory<x86::reg64>(cpu.eax + x86::reg32(40) /* 0x28 */) = x86::reg64(x86::sreg64(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 005032cb  df7830                 -fistp qword ptr [eax + 0x30]
    app->getMemory<x86::reg64>(cpu.eax + x86::reg32(48) /* 0x30 */) = x86::reg64(x86::sreg64(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 005032ce  df7838                 -fistp qword ptr [eax + 0x38]
    app->getMemory<x86::reg64>(cpu.eax + x86::reg32(56) /* 0x38 */) = x86::reg64(x86::sreg64(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 005032d1  df6a50                 -fild qword ptr [edx + 0x50]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.edx + x86::reg32(80) /* 0x50 */))));
    // 005032d4  df6a48                 -fild qword ptr [edx + 0x48]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.edx + x86::reg32(72) /* 0x48 */))));
    // 005032d7  df6a58                 -fild qword ptr [edx + 0x58]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.edx + x86::reg32(88) /* 0x58 */))));
    // 005032da  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 005032dc  df7840                 -fistp qword ptr [eax + 0x40]
    app->getMemory<x86::reg64>(cpu.eax + x86::reg32(64) /* 0x40 */) = x86::reg64(x86::sreg64(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 005032df  df7848                 -fistp qword ptr [eax + 0x48]
    app->getMemory<x86::reg64>(cpu.eax + x86::reg32(72) /* 0x48 */) = x86::reg64(x86::sreg64(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 005032e2  df7850                 -fistp qword ptr [eax + 0x50]
    app->getMemory<x86::reg64>(cpu.eax + x86::reg32(80) /* 0x50 */) = x86::reg64(x86::sreg64(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 005032e5  df7858                 -fistp qword ptr [eax + 0x58]
    app->getMemory<x86::reg64>(cpu.eax + x86::reg32(88) /* 0x58 */) = x86::reg64(x86::sreg64(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 005032e8  df6a70                 -fild qword ptr [edx + 0x70]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.edx + x86::reg32(112) /* 0x70 */))));
    // 005032eb  df6a68                 -fild qword ptr [edx + 0x68]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.edx + x86::reg32(104) /* 0x68 */))));
    // 005032ee  df6a78                 -fild qword ptr [edx + 0x78]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.edx + x86::reg32(120) /* 0x78 */))));
    // 005032f1  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 005032f3  df7860                 -fistp qword ptr [eax + 0x60]
    app->getMemory<x86::reg64>(cpu.eax + x86::reg32(96) /* 0x60 */) = x86::reg64(x86::sreg64(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 005032f6  df7868                 -fistp qword ptr [eax + 0x68]
    app->getMemory<x86::reg64>(cpu.eax + x86::reg32(104) /* 0x68 */) = x86::reg64(x86::sreg64(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 005032f9  df7870                 -fistp qword ptr [eax + 0x70]
    app->getMemory<x86::reg64>(cpu.eax + x86::reg32(112) /* 0x70 */) = x86::reg64(x86::sreg64(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 005032fc  df7878                 -fistp qword ptr [eax + 0x78]
    app->getMemory<x86::reg64>(cpu.eax + x86::reg32(120) /* 0x78 */) = x86::reg64(x86::sreg64(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 005032ff  81c280000000           -add edx, 0x80
    (cpu.edx) += x86::reg32(x86::sreg32(128 /*0x80*/));
    // 00503305  0580000000             -add eax, 0x80
    (cpu.eax) += x86::reg32(x86::sreg32(128 /*0x80*/));
    // 0050330a  81eb80000000           +sub ebx, 0x80
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
    // 00503310  7983                   -jns 0x503295
    if (!cpu.flags.sf)
    {
        goto L_0x00503295;
    }
L_0x00503312:
    // 00503312  83c360                 +add ebx, 0x60
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
    // 00503315  7825                   -js 0x50333c
    if (cpu.flags.sf)
    {
        goto L_0x0050333c;
    }
L_0x00503317:
    // 00503317  df2a                   -fild qword ptr [edx]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.edx))));
    // 00503319  df6a08                 -fild qword ptr [edx + 8]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.edx + x86::reg32(8) /* 0x8 */))));
    // 0050331c  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0050331e  df38                   -fistp qword ptr [eax]
    app->getMemory<x86::reg64>(cpu.eax) = x86::reg64(x86::sreg64(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 00503320  df7808                 -fistp qword ptr [eax + 8]
    app->getMemory<x86::reg64>(cpu.eax + x86::reg32(8) /* 0x8 */) = x86::reg64(x86::sreg64(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 00503323  df6a10                 -fild qword ptr [edx + 0x10]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.edx + x86::reg32(16) /* 0x10 */))));
    // 00503326  df6a18                 -fild qword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.edx + x86::reg32(24) /* 0x18 */))));
    // 00503329  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0050332b  df7810                 -fistp qword ptr [eax + 0x10]
    app->getMemory<x86::reg64>(cpu.eax + x86::reg32(16) /* 0x10 */) = x86::reg64(x86::sreg64(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 0050332e  df7818                 -fistp qword ptr [eax + 0x18]
    app->getMemory<x86::reg64>(cpu.eax + x86::reg32(24) /* 0x18 */) = x86::reg64(x86::sreg64(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 00503331  83c220                 -add edx, 0x20
    (cpu.edx) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00503334  83c020                 -add eax, 0x20
    (cpu.eax) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00503337  83eb20                 +sub ebx, 0x20
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
    // 0050333a  79db                   -jns 0x503317
    if (!cpu.flags.sf)
    {
        goto L_0x00503317;
    }
L_0x0050333c:
    // 0050333c  83c318                 +add ebx, 0x18
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
    // 0050333f  780f                   -js 0x503350
    if (cpu.flags.sf)
    {
        goto L_0x00503350;
    }
L_0x00503341:
    // 00503341  df2a                   -fild qword ptr [edx]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.edx))));
    // 00503343  df38                   -fistp qword ptr [eax]
    app->getMemory<x86::reg64>(cpu.eax) = x86::reg64(x86::sreg64(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 00503345  83c208                 -add edx, 8
    (cpu.edx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00503348  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0050334b  83eb08                 +sub ebx, 8
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
    // 0050334e  79f1                   -jns 0x503341
    if (!cpu.flags.sf)
    {
        goto L_0x00503341;
    }
L_0x00503350:
    // 00503350  83c308                 +add ebx, 8
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
    // 00503353  7502                   -jne 0x503357
    if (!cpu.flags.zf)
    {
        goto L_0x00503357;
    }
    // 00503355  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00503356  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00503357:
    // 00503357  83fb04                 +cmp ebx, 4
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
    // 0050335a  720d                   -jb 0x503369
    if (cpu.flags.cf)
    {
        goto L_0x00503369;
    }
    // 0050335c  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 0050335e  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00503361  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 00503363  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00503366  83eb04                 -sub ebx, 4
    (cpu.ebx) -= x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00503369:
    // 00503369  83fb02                 +cmp ebx, 2
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
    // 0050336c  720f                   -jb 0x50337d
    if (cpu.flags.cf)
    {
        goto L_0x0050337d;
    }
    // 0050336e  668b0a                 -mov cx, word ptr [edx]
    cpu.cx = app->getMemory<x86::reg16>(cpu.edx);
    // 00503371  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00503374  668908                 -mov word ptr [eax], cx
    app->getMemory<x86::reg16>(cpu.eax) = cpu.cx;
    // 00503377  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0050337a  83eb02                 -sub ebx, 2
    (cpu.ebx) -= x86::reg32(x86::sreg32(2 /*0x2*/));
L_0x0050337d:
    // 0050337d  83fb01                 +cmp ebx, 1
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
    // 00503380  720d                   -jb 0x50338f
    if (cpu.flags.cf)
    {
        goto L_0x0050338f;
    }
    // 00503382  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 00503384  83c201                 -add edx, 1
    (cpu.edx) += x86::reg32(x86::sreg32(1 /*0x1*/));
    // 00503387  8808                   -mov byte ptr [eax], cl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.cl;
    // 00503389  83c001                 -add eax, 1
    (cpu.eax) += x86::reg32(x86::sreg32(1 /*0x1*/));
    // 0050338c  83eb01                 -sub ebx, 1
    (cpu.ebx) -= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x0050338f:
    // 0050338f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00503390  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00503391:
    // 00503391  a901000000             +test eax, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 1 /*0x1*/));
    // 00503396  7412                   -je 0x5033aa
    if (cpu.flags.zf)
    {
        goto L_0x005033aa;
    }
    // 00503398  83fb01                 +cmp ebx, 1
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
    // 0050339b  7c0d                   -jl 0x5033aa
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x005033aa;
    }
    // 0050339d  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 0050339f  83c201                 -add edx, 1
    (cpu.edx) += x86::reg32(x86::sreg32(1 /*0x1*/));
    // 005033a2  8808                   -mov byte ptr [eax], cl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.cl;
    // 005033a4  83c001                 -add eax, 1
    (cpu.eax) += x86::reg32(x86::sreg32(1 /*0x1*/));
    // 005033a7  83eb01                 -sub ebx, 1
    (cpu.ebx) -= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x005033aa:
    // 005033aa  a902000000             +test eax, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2 /*0x2*/));
    // 005033af  7414                   -je 0x5033c5
    if (cpu.flags.zf)
    {
        goto L_0x005033c5;
    }
    // 005033b1  83fb02                 +cmp ebx, 2
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
    // 005033b4  7c0f                   -jl 0x5033c5
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x005033c5;
    }
    // 005033b6  668b0a                 -mov cx, word ptr [edx]
    cpu.cx = app->getMemory<x86::reg16>(cpu.edx);
    // 005033b9  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 005033bc  668908                 -mov word ptr [eax], cx
    app->getMemory<x86::reg16>(cpu.eax) = cpu.cx;
    // 005033bf  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 005033c2  83eb02                 -sub ebx, 2
    (cpu.ebx) -= x86::reg32(x86::sreg32(2 /*0x2*/));
L_0x005033c5:
    // 005033c5  a904000000             +test eax, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 4 /*0x4*/));
    // 005033ca  7412                   -je 0x5033de
    if (cpu.flags.zf)
    {
        goto L_0x005033de;
    }
    // 005033cc  83fb04                 +cmp ebx, 4
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
    // 005033cf  7c0d                   -jl 0x5033de
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x005033de;
    }
    // 005033d1  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 005033d3  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 005033d6  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 005033d8  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 005033db  83eb04                 +sub ebx, 4
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
L_0x005033de:
    // 005033de  e9aafeffff             -jmp 0x50328d
    goto L_0x0050328d;
}

/* align: skip  */
void Application::sub_503281(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00503281;
    // 00503280  92                     -xchg edx, eax
    {
        x86::reg32 tmp = cpu.edx;
        cpu.edx = cpu.eax;
        cpu.eax = tmp;
    }
L_entry_0x00503281:
    // 00503281  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00503282  a907000000             +test eax, 7
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 7 /*0x7*/));
    // 00503287  0f8504010000           -jne 0x503391
    if (!cpu.flags.zf)
    {
        goto L_0x00503391;
    }
L_0x0050328d:
    // 0050328d  81eb80000000           +sub ebx, 0x80
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
    // 00503293  787d                   -js 0x503312
    if (cpu.flags.sf)
    {
        goto L_0x00503312;
    }
L_0x00503295:
    // 00503295  df2a                   -fild qword ptr [edx]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.edx))));
    // 00503297  df6a20                 -fild qword ptr [edx + 0x20]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.edx + x86::reg32(32) /* 0x20 */))));
    // 0050329a  df6a40                 -fild qword ptr [edx + 0x40]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.edx + x86::reg32(64) /* 0x40 */))));
    // 0050329d  df6a60                 -fild qword ptr [edx + 0x60]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.edx + x86::reg32(96) /* 0x60 */))));
    // 005032a0  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 005032a2  df6a10                 -fild qword ptr [edx + 0x10]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.edx + x86::reg32(16) /* 0x10 */))));
    // 005032a5  df6a08                 -fild qword ptr [edx + 8]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.edx + x86::reg32(8) /* 0x8 */))));
    // 005032a8  df6a18                 -fild qword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.edx + x86::reg32(24) /* 0x18 */))));
    // 005032ab  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 005032ad  df38                   -fistp qword ptr [eax]
    app->getMemory<x86::reg64>(cpu.eax) = x86::reg64(x86::sreg64(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 005032af  df7808                 -fistp qword ptr [eax + 8]
    app->getMemory<x86::reg64>(cpu.eax + x86::reg32(8) /* 0x8 */) = x86::reg64(x86::sreg64(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 005032b2  df7810                 -fistp qword ptr [eax + 0x10]
    app->getMemory<x86::reg64>(cpu.eax + x86::reg32(16) /* 0x10 */) = x86::reg64(x86::sreg64(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 005032b5  df7818                 -fistp qword ptr [eax + 0x18]
    app->getMemory<x86::reg64>(cpu.eax + x86::reg32(24) /* 0x18 */) = x86::reg64(x86::sreg64(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 005032b8  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 005032ba  df6a30                 -fild qword ptr [edx + 0x30]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.edx + x86::reg32(48) /* 0x30 */))));
    // 005032bd  df6a28                 -fild qword ptr [edx + 0x28]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.edx + x86::reg32(40) /* 0x28 */))));
    // 005032c0  df6a38                 -fild qword ptr [edx + 0x38]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.edx + x86::reg32(56) /* 0x38 */))));
    // 005032c3  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 005032c5  df7820                 -fistp qword ptr [eax + 0x20]
    app->getMemory<x86::reg64>(cpu.eax + x86::reg32(32) /* 0x20 */) = x86::reg64(x86::sreg64(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 005032c8  df7828                 -fistp qword ptr [eax + 0x28]
    app->getMemory<x86::reg64>(cpu.eax + x86::reg32(40) /* 0x28 */) = x86::reg64(x86::sreg64(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 005032cb  df7830                 -fistp qword ptr [eax + 0x30]
    app->getMemory<x86::reg64>(cpu.eax + x86::reg32(48) /* 0x30 */) = x86::reg64(x86::sreg64(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 005032ce  df7838                 -fistp qword ptr [eax + 0x38]
    app->getMemory<x86::reg64>(cpu.eax + x86::reg32(56) /* 0x38 */) = x86::reg64(x86::sreg64(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 005032d1  df6a50                 -fild qword ptr [edx + 0x50]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.edx + x86::reg32(80) /* 0x50 */))));
    // 005032d4  df6a48                 -fild qword ptr [edx + 0x48]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.edx + x86::reg32(72) /* 0x48 */))));
    // 005032d7  df6a58                 -fild qword ptr [edx + 0x58]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.edx + x86::reg32(88) /* 0x58 */))));
    // 005032da  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 005032dc  df7840                 -fistp qword ptr [eax + 0x40]
    app->getMemory<x86::reg64>(cpu.eax + x86::reg32(64) /* 0x40 */) = x86::reg64(x86::sreg64(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 005032df  df7848                 -fistp qword ptr [eax + 0x48]
    app->getMemory<x86::reg64>(cpu.eax + x86::reg32(72) /* 0x48 */) = x86::reg64(x86::sreg64(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 005032e2  df7850                 -fistp qword ptr [eax + 0x50]
    app->getMemory<x86::reg64>(cpu.eax + x86::reg32(80) /* 0x50 */) = x86::reg64(x86::sreg64(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 005032e5  df7858                 -fistp qword ptr [eax + 0x58]
    app->getMemory<x86::reg64>(cpu.eax + x86::reg32(88) /* 0x58 */) = x86::reg64(x86::sreg64(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 005032e8  df6a70                 -fild qword ptr [edx + 0x70]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.edx + x86::reg32(112) /* 0x70 */))));
    // 005032eb  df6a68                 -fild qword ptr [edx + 0x68]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.edx + x86::reg32(104) /* 0x68 */))));
    // 005032ee  df6a78                 -fild qword ptr [edx + 0x78]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.edx + x86::reg32(120) /* 0x78 */))));
    // 005032f1  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 005032f3  df7860                 -fistp qword ptr [eax + 0x60]
    app->getMemory<x86::reg64>(cpu.eax + x86::reg32(96) /* 0x60 */) = x86::reg64(x86::sreg64(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 005032f6  df7868                 -fistp qword ptr [eax + 0x68]
    app->getMemory<x86::reg64>(cpu.eax + x86::reg32(104) /* 0x68 */) = x86::reg64(x86::sreg64(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 005032f9  df7870                 -fistp qword ptr [eax + 0x70]
    app->getMemory<x86::reg64>(cpu.eax + x86::reg32(112) /* 0x70 */) = x86::reg64(x86::sreg64(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 005032fc  df7878                 -fistp qword ptr [eax + 0x78]
    app->getMemory<x86::reg64>(cpu.eax + x86::reg32(120) /* 0x78 */) = x86::reg64(x86::sreg64(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 005032ff  81c280000000           -add edx, 0x80
    (cpu.edx) += x86::reg32(x86::sreg32(128 /*0x80*/));
    // 00503305  0580000000             -add eax, 0x80
    (cpu.eax) += x86::reg32(x86::sreg32(128 /*0x80*/));
    // 0050330a  81eb80000000           +sub ebx, 0x80
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
    // 00503310  7983                   -jns 0x503295
    if (!cpu.flags.sf)
    {
        goto L_0x00503295;
    }
L_0x00503312:
    // 00503312  83c360                 +add ebx, 0x60
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
    // 00503315  7825                   -js 0x50333c
    if (cpu.flags.sf)
    {
        goto L_0x0050333c;
    }
L_0x00503317:
    // 00503317  df2a                   -fild qword ptr [edx]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.edx))));
    // 00503319  df6a08                 -fild qword ptr [edx + 8]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.edx + x86::reg32(8) /* 0x8 */))));
    // 0050331c  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0050331e  df38                   -fistp qword ptr [eax]
    app->getMemory<x86::reg64>(cpu.eax) = x86::reg64(x86::sreg64(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 00503320  df7808                 -fistp qword ptr [eax + 8]
    app->getMemory<x86::reg64>(cpu.eax + x86::reg32(8) /* 0x8 */) = x86::reg64(x86::sreg64(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 00503323  df6a10                 -fild qword ptr [edx + 0x10]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.edx + x86::reg32(16) /* 0x10 */))));
    // 00503326  df6a18                 -fild qword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.edx + x86::reg32(24) /* 0x18 */))));
    // 00503329  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0050332b  df7810                 -fistp qword ptr [eax + 0x10]
    app->getMemory<x86::reg64>(cpu.eax + x86::reg32(16) /* 0x10 */) = x86::reg64(x86::sreg64(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 0050332e  df7818                 -fistp qword ptr [eax + 0x18]
    app->getMemory<x86::reg64>(cpu.eax + x86::reg32(24) /* 0x18 */) = x86::reg64(x86::sreg64(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 00503331  83c220                 -add edx, 0x20
    (cpu.edx) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00503334  83c020                 -add eax, 0x20
    (cpu.eax) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00503337  83eb20                 +sub ebx, 0x20
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
    // 0050333a  79db                   -jns 0x503317
    if (!cpu.flags.sf)
    {
        goto L_0x00503317;
    }
L_0x0050333c:
    // 0050333c  83c318                 +add ebx, 0x18
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
    // 0050333f  780f                   -js 0x503350
    if (cpu.flags.sf)
    {
        goto L_0x00503350;
    }
L_0x00503341:
    // 00503341  df2a                   -fild qword ptr [edx]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.edx))));
    // 00503343  df38                   -fistp qword ptr [eax]
    app->getMemory<x86::reg64>(cpu.eax) = x86::reg64(x86::sreg64(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 00503345  83c208                 -add edx, 8
    (cpu.edx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00503348  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0050334b  83eb08                 +sub ebx, 8
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
    // 0050334e  79f1                   -jns 0x503341
    if (!cpu.flags.sf)
    {
        goto L_0x00503341;
    }
L_0x00503350:
    // 00503350  83c308                 +add ebx, 8
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
    // 00503353  7502                   -jne 0x503357
    if (!cpu.flags.zf)
    {
        goto L_0x00503357;
    }
    // 00503355  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00503356  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00503357:
    // 00503357  83fb04                 +cmp ebx, 4
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
    // 0050335a  720d                   -jb 0x503369
    if (cpu.flags.cf)
    {
        goto L_0x00503369;
    }
    // 0050335c  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 0050335e  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00503361  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 00503363  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00503366  83eb04                 -sub ebx, 4
    (cpu.ebx) -= x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00503369:
    // 00503369  83fb02                 +cmp ebx, 2
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
    // 0050336c  720f                   -jb 0x50337d
    if (cpu.flags.cf)
    {
        goto L_0x0050337d;
    }
    // 0050336e  668b0a                 -mov cx, word ptr [edx]
    cpu.cx = app->getMemory<x86::reg16>(cpu.edx);
    // 00503371  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00503374  668908                 -mov word ptr [eax], cx
    app->getMemory<x86::reg16>(cpu.eax) = cpu.cx;
    // 00503377  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0050337a  83eb02                 -sub ebx, 2
    (cpu.ebx) -= x86::reg32(x86::sreg32(2 /*0x2*/));
L_0x0050337d:
    // 0050337d  83fb01                 +cmp ebx, 1
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
    // 00503380  720d                   -jb 0x50338f
    if (cpu.flags.cf)
    {
        goto L_0x0050338f;
    }
    // 00503382  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 00503384  83c201                 -add edx, 1
    (cpu.edx) += x86::reg32(x86::sreg32(1 /*0x1*/));
    // 00503387  8808                   -mov byte ptr [eax], cl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.cl;
    // 00503389  83c001                 -add eax, 1
    (cpu.eax) += x86::reg32(x86::sreg32(1 /*0x1*/));
    // 0050338c  83eb01                 -sub ebx, 1
    (cpu.ebx) -= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x0050338f:
    // 0050338f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00503390  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00503391:
    // 00503391  a901000000             +test eax, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 1 /*0x1*/));
    // 00503396  7412                   -je 0x5033aa
    if (cpu.flags.zf)
    {
        goto L_0x005033aa;
    }
    // 00503398  83fb01                 +cmp ebx, 1
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
    // 0050339b  7c0d                   -jl 0x5033aa
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x005033aa;
    }
    // 0050339d  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 0050339f  83c201                 -add edx, 1
    (cpu.edx) += x86::reg32(x86::sreg32(1 /*0x1*/));
    // 005033a2  8808                   -mov byte ptr [eax], cl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.cl;
    // 005033a4  83c001                 -add eax, 1
    (cpu.eax) += x86::reg32(x86::sreg32(1 /*0x1*/));
    // 005033a7  83eb01                 -sub ebx, 1
    (cpu.ebx) -= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x005033aa:
    // 005033aa  a902000000             +test eax, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2 /*0x2*/));
    // 005033af  7414                   -je 0x5033c5
    if (cpu.flags.zf)
    {
        goto L_0x005033c5;
    }
    // 005033b1  83fb02                 +cmp ebx, 2
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
    // 005033b4  7c0f                   -jl 0x5033c5
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x005033c5;
    }
    // 005033b6  668b0a                 -mov cx, word ptr [edx]
    cpu.cx = app->getMemory<x86::reg16>(cpu.edx);
    // 005033b9  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 005033bc  668908                 -mov word ptr [eax], cx
    app->getMemory<x86::reg16>(cpu.eax) = cpu.cx;
    // 005033bf  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 005033c2  83eb02                 -sub ebx, 2
    (cpu.ebx) -= x86::reg32(x86::sreg32(2 /*0x2*/));
L_0x005033c5:
    // 005033c5  a904000000             +test eax, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 4 /*0x4*/));
    // 005033ca  7412                   -je 0x5033de
    if (cpu.flags.zf)
    {
        goto L_0x005033de;
    }
    // 005033cc  83fb04                 +cmp ebx, 4
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
    // 005033cf  7c0d                   -jl 0x5033de
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x005033de;
    }
    // 005033d1  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 005033d3  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 005033d6  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 005033d8  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 005033db  83eb04                 +sub ebx, 4
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
L_0x005033de:
    // 005033de  e9aafeffff             -jmp 0x50328d
    goto L_0x0050328d;
}

/* align: skip 0x00 */
void Application::sub_5033e4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005033e4  92                     -xchg edx, eax
    {
        x86::reg32 tmp = cpu.edx;
        cpu.edx = cpu.eax;
        cpu.eax = tmp;
    }
    // 005033e5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005033e6  a907000000             +test eax, 7
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 7 /*0x7*/));
    // 005033eb  0f8526010000           -jne 0x503517
    if (!cpu.flags.zf)
    {
        goto L_0x00503517;
    }
L_0x005033f1:
    // 005033f1  81eb80000000           +sub ebx, 0x80
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
    // 005033f7  0f8895000000           -js 0x503492
    if (cpu.flags.sf)
    {
        goto L_0x00503492;
    }
L_0x005033fd:
    // 005033fd  0f6f02                 -movq mm0, qword ptr [edx]
    cpu.mmx.mm0 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.edx));
    // 00503400  0f6f6220               -movq mm4, qword ptr [edx + 0x20]
    cpu.mmx.mm4 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.edx + x86::reg32(32) /* 0x20 */));
    // 00503404  0f6f6a40               -movq mm5, qword ptr [edx + 0x40]
    cpu.mmx.mm5 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.edx + x86::reg32(64) /* 0x40 */));
    // 00503408  0f6f7260               -movq mm6, qword ptr [edx + 0x60]
    cpu.mmx.mm6 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.edx + x86::reg32(96) /* 0x60 */));
    // 0050340c  0f6f4a08               -movq mm1, qword ptr [edx + 8]
    cpu.mmx.mm1 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.edx + x86::reg32(8) /* 0x8 */));
    // 00503410  0f6f5210               -movq mm2, qword ptr [edx + 0x10]
    cpu.mmx.mm2 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.edx + x86::reg32(16) /* 0x10 */));
    // 00503414  0f6f5a18               -movq mm3, qword ptr [edx + 0x18]
    cpu.mmx.mm3 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.edx + x86::reg32(24) /* 0x18 */));
    // 00503418  0f7f00                 -movq qword ptr [eax], mm0
    app->getMemory<x86::reg64>(cpu.eax) = cpu.mmx.mm0;
    // 0050341b  0f7f4808               -movq qword ptr [eax + 8], mm1
    app->getMemory<x86::reg64>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.mmx.mm1;
    // 0050341f  0f7f5010               -movq qword ptr [eax + 0x10], mm2
    app->getMemory<x86::reg64>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.mmx.mm2;
    // 00503423  0f7f5818               -movq qword ptr [eax + 0x18], mm3
    app->getMemory<x86::reg64>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.mmx.mm3;
    // 00503427  0f6f4a28               -movq mm1, qword ptr [edx + 0x28]
    cpu.mmx.mm1 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.edx + x86::reg32(40) /* 0x28 */));
    // 0050342b  0f6f5230               -movq mm2, qword ptr [edx + 0x30]
    cpu.mmx.mm2 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.edx + x86::reg32(48) /* 0x30 */));
    // 0050342f  0f6f5a38               -movq mm3, qword ptr [edx + 0x38]
    cpu.mmx.mm3 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.edx + x86::reg32(56) /* 0x38 */));
    // 00503433  0f7f6020               -movq qword ptr [eax + 0x20], mm4
    app->getMemory<x86::reg64>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.mmx.mm4;
    // 00503437  0f7f4828               -movq qword ptr [eax + 0x28], mm1
    app->getMemory<x86::reg64>(cpu.eax + x86::reg32(40) /* 0x28 */) = cpu.mmx.mm1;
    // 0050343b  0f7f5030               -movq qword ptr [eax + 0x30], mm2
    app->getMemory<x86::reg64>(cpu.eax + x86::reg32(48) /* 0x30 */) = cpu.mmx.mm2;
    // 0050343f  0f7f5838               -movq qword ptr [eax + 0x38], mm3
    app->getMemory<x86::reg64>(cpu.eax + x86::reg32(56) /* 0x38 */) = cpu.mmx.mm3;
    // 00503443  0f6f4a48               -movq mm1, qword ptr [edx + 0x48]
    cpu.mmx.mm1 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.edx + x86::reg32(72) /* 0x48 */));
    // 00503447  0f6f5250               -movq mm2, qword ptr [edx + 0x50]
    cpu.mmx.mm2 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.edx + x86::reg32(80) /* 0x50 */));
    // 0050344b  0f6f5a58               -movq mm3, qword ptr [edx + 0x58]
    cpu.mmx.mm3 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.edx + x86::reg32(88) /* 0x58 */));
    // 0050344f  0f7f6840               -movq qword ptr [eax + 0x40], mm5
    app->getMemory<x86::reg64>(cpu.eax + x86::reg32(64) /* 0x40 */) = cpu.mmx.mm5;
    // 00503453  0f7f4848               -movq qword ptr [eax + 0x48], mm1
    app->getMemory<x86::reg64>(cpu.eax + x86::reg32(72) /* 0x48 */) = cpu.mmx.mm1;
    // 00503457  0f7f5050               -movq qword ptr [eax + 0x50], mm2
    app->getMemory<x86::reg64>(cpu.eax + x86::reg32(80) /* 0x50 */) = cpu.mmx.mm2;
    // 0050345b  0f7f5858               -movq qword ptr [eax + 0x58], mm3
    app->getMemory<x86::reg64>(cpu.eax + x86::reg32(88) /* 0x58 */) = cpu.mmx.mm3;
    // 0050345f  0f6f4a68               -movq mm1, qword ptr [edx + 0x68]
    cpu.mmx.mm1 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.edx + x86::reg32(104) /* 0x68 */));
    // 00503463  0f6f5270               -movq mm2, qword ptr [edx + 0x70]
    cpu.mmx.mm2 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.edx + x86::reg32(112) /* 0x70 */));
    // 00503467  0f6f5a78               -movq mm3, qword ptr [edx + 0x78]
    cpu.mmx.mm3 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.edx + x86::reg32(120) /* 0x78 */));
    // 0050346b  0f7f7060               -movq qword ptr [eax + 0x60], mm6
    app->getMemory<x86::reg64>(cpu.eax + x86::reg32(96) /* 0x60 */) = cpu.mmx.mm6;
    // 0050346f  0f7f4868               -movq qword ptr [eax + 0x68], mm1
    app->getMemory<x86::reg64>(cpu.eax + x86::reg32(104) /* 0x68 */) = cpu.mmx.mm1;
    // 00503473  0f7f5070               -movq qword ptr [eax + 0x70], mm2
    app->getMemory<x86::reg64>(cpu.eax + x86::reg32(112) /* 0x70 */) = cpu.mmx.mm2;
    // 00503477  0f7f5878               -movq qword ptr [eax + 0x78], mm3
    app->getMemory<x86::reg64>(cpu.eax + x86::reg32(120) /* 0x78 */) = cpu.mmx.mm3;
    // 0050347b  81c280000000           -add edx, 0x80
    (cpu.edx) += x86::reg32(x86::sreg32(128 /*0x80*/));
    // 00503481  0580000000             -add eax, 0x80
    (cpu.eax) += x86::reg32(x86::sreg32(128 /*0x80*/));
    // 00503486  81eb80000000           +sub ebx, 0x80
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
    // 0050348c  0f896bffffff           -jns 0x5033fd
    if (!cpu.flags.sf)
    {
        goto L_0x005033fd;
    }
L_0x00503492:
    // 00503492  83c360                 +add ebx, 0x60
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
    // 00503495  7829                   -js 0x5034c0
    if (cpu.flags.sf)
    {
        goto L_0x005034c0;
    }
L_0x00503497:
    // 00503497  0f6f02                 -movq mm0, qword ptr [edx]
    cpu.mmx.mm0 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.edx));
    // 0050349a  0f6f4a08               -movq mm1, qword ptr [edx + 8]
    cpu.mmx.mm1 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.edx + x86::reg32(8) /* 0x8 */));
    // 0050349e  0f6f5210               -movq mm2, qword ptr [edx + 0x10]
    cpu.mmx.mm2 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.edx + x86::reg32(16) /* 0x10 */));
    // 005034a2  0f6f5a18               -movq mm3, qword ptr [edx + 0x18]
    cpu.mmx.mm3 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.edx + x86::reg32(24) /* 0x18 */));
    // 005034a6  0f7f00                 -movq qword ptr [eax], mm0
    app->getMemory<x86::reg64>(cpu.eax) = cpu.mmx.mm0;
    // 005034a9  0f7f4808               -movq qword ptr [eax + 8], mm1
    app->getMemory<x86::reg64>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.mmx.mm1;
    // 005034ad  0f7f5010               -movq qword ptr [eax + 0x10], mm2
    app->getMemory<x86::reg64>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.mmx.mm2;
    // 005034b1  0f7f5818               -movq qword ptr [eax + 0x18], mm3
    app->getMemory<x86::reg64>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.mmx.mm3;
    // 005034b5  83c220                 -add edx, 0x20
    (cpu.edx) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 005034b8  83c020                 -add eax, 0x20
    (cpu.eax) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 005034bb  83eb20                 +sub ebx, 0x20
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
    // 005034be  79d7                   -jns 0x503497
    if (!cpu.flags.sf)
    {
        goto L_0x00503497;
    }
L_0x005034c0:
    // 005034c0  83c318                 +add ebx, 0x18
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
    // 005034c3  7811                   -js 0x5034d6
    if (cpu.flags.sf)
    {
        goto L_0x005034d6;
    }
L_0x005034c5:
    // 005034c5  0f6f02                 -movq mm0, qword ptr [edx]
    cpu.mmx.mm0 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.edx));
    // 005034c8  0f7f00                 -movq qword ptr [eax], mm0
    app->getMemory<x86::reg64>(cpu.eax) = cpu.mmx.mm0;
    // 005034cb  83c208                 -add edx, 8
    (cpu.edx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 005034ce  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 005034d1  83eb08                 +sub ebx, 8
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
    // 005034d4  79ef                   -jns 0x5034c5
    if (!cpu.flags.sf)
    {
        goto L_0x005034c5;
    }
L_0x005034d6:
    // 005034d6  83c308                 +add ebx, 8
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
    // 005034d9  7502                   -jne 0x5034dd
    if (!cpu.flags.zf)
    {
        goto L_0x005034dd;
    }
    // 005034db  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005034dc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005034dd:
    // 005034dd  83fb04                 +cmp ebx, 4
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
    // 005034e0  720d                   -jb 0x5034ef
    if (cpu.flags.cf)
    {
        goto L_0x005034ef;
    }
    // 005034e2  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 005034e4  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 005034e7  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 005034e9  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 005034ec  83eb04                 -sub ebx, 4
    (cpu.ebx) -= x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x005034ef:
    // 005034ef  83fb02                 +cmp ebx, 2
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
    // 005034f2  720f                   -jb 0x503503
    if (cpu.flags.cf)
    {
        goto L_0x00503503;
    }
    // 005034f4  668b0a                 -mov cx, word ptr [edx]
    cpu.cx = app->getMemory<x86::reg16>(cpu.edx);
    // 005034f7  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 005034fa  668908                 -mov word ptr [eax], cx
    app->getMemory<x86::reg16>(cpu.eax) = cpu.cx;
    // 005034fd  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00503500  83eb02                 -sub ebx, 2
    (cpu.ebx) -= x86::reg32(x86::sreg32(2 /*0x2*/));
L_0x00503503:
    // 00503503  83fb01                 +cmp ebx, 1
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
    // 00503506  720d                   -jb 0x503515
    if (cpu.flags.cf)
    {
        goto L_0x00503515;
    }
    // 00503508  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 0050350a  83c201                 -add edx, 1
    (cpu.edx) += x86::reg32(x86::sreg32(1 /*0x1*/));
    // 0050350d  8808                   -mov byte ptr [eax], cl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.cl;
    // 0050350f  83c001                 -add eax, 1
    (cpu.eax) += x86::reg32(x86::sreg32(1 /*0x1*/));
    // 00503512  83eb01                 -sub ebx, 1
    (cpu.ebx) -= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x00503515:
    // 00503515  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00503516  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00503517:
    // 00503517  a901000000             +test eax, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 1 /*0x1*/));
    // 0050351c  7412                   -je 0x503530
    if (cpu.flags.zf)
    {
        goto L_0x00503530;
    }
    // 0050351e  83fb01                 +cmp ebx, 1
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
    // 00503521  7c0d                   -jl 0x503530
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00503530;
    }
    // 00503523  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 00503525  83c201                 -add edx, 1
    (cpu.edx) += x86::reg32(x86::sreg32(1 /*0x1*/));
    // 00503528  8808                   -mov byte ptr [eax], cl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.cl;
    // 0050352a  83c001                 -add eax, 1
    (cpu.eax) += x86::reg32(x86::sreg32(1 /*0x1*/));
    // 0050352d  83eb01                 -sub ebx, 1
    (cpu.ebx) -= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x00503530:
    // 00503530  a902000000             +test eax, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2 /*0x2*/));
    // 00503535  7414                   -je 0x50354b
    if (cpu.flags.zf)
    {
        goto L_0x0050354b;
    }
    // 00503537  83fb02                 +cmp ebx, 2
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
    // 0050353a  7c0f                   -jl 0x50354b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0050354b;
    }
    // 0050353c  668b0a                 -mov cx, word ptr [edx]
    cpu.cx = app->getMemory<x86::reg16>(cpu.edx);
    // 0050353f  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00503542  668908                 -mov word ptr [eax], cx
    app->getMemory<x86::reg16>(cpu.eax) = cpu.cx;
    // 00503545  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00503548  83eb02                 -sub ebx, 2
    (cpu.ebx) -= x86::reg32(x86::sreg32(2 /*0x2*/));
L_0x0050354b:
    // 0050354b  a904000000             +test eax, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 4 /*0x4*/));
    // 00503550  7412                   -je 0x503564
    if (cpu.flags.zf)
    {
        goto L_0x00503564;
    }
    // 00503552  83fb04                 +cmp ebx, 4
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
    // 00503555  7c0d                   -jl 0x503564
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00503564;
    }
    // 00503557  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 00503559  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0050355c  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 0050355e  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00503561  83eb04                 +sub ebx, 4
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
L_0x00503564:
    // 00503564  e988feffff             -jmp 0x5033f1
    goto L_0x005033f1;
}

/* align: skip  */
void Application::sub_5033e5(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x005033e5;
    // 005033e4  92                     -xchg edx, eax
    {
        x86::reg32 tmp = cpu.edx;
        cpu.edx = cpu.eax;
        cpu.eax = tmp;
    }
L_entry_0x005033e5:
    // 005033e5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005033e6  a907000000             +test eax, 7
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 7 /*0x7*/));
    // 005033eb  0f8526010000           -jne 0x503517
    if (!cpu.flags.zf)
    {
        goto L_0x00503517;
    }
L_0x005033f1:
    // 005033f1  81eb80000000           +sub ebx, 0x80
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
    // 005033f7  0f8895000000           -js 0x503492
    if (cpu.flags.sf)
    {
        goto L_0x00503492;
    }
L_0x005033fd:
    // 005033fd  0f6f02                 -movq mm0, qword ptr [edx]
    cpu.mmx.mm0 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.edx));
    // 00503400  0f6f6220               -movq mm4, qword ptr [edx + 0x20]
    cpu.mmx.mm4 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.edx + x86::reg32(32) /* 0x20 */));
    // 00503404  0f6f6a40               -movq mm5, qword ptr [edx + 0x40]
    cpu.mmx.mm5 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.edx + x86::reg32(64) /* 0x40 */));
    // 00503408  0f6f7260               -movq mm6, qword ptr [edx + 0x60]
    cpu.mmx.mm6 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.edx + x86::reg32(96) /* 0x60 */));
    // 0050340c  0f6f4a08               -movq mm1, qword ptr [edx + 8]
    cpu.mmx.mm1 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.edx + x86::reg32(8) /* 0x8 */));
    // 00503410  0f6f5210               -movq mm2, qword ptr [edx + 0x10]
    cpu.mmx.mm2 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.edx + x86::reg32(16) /* 0x10 */));
    // 00503414  0f6f5a18               -movq mm3, qword ptr [edx + 0x18]
    cpu.mmx.mm3 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.edx + x86::reg32(24) /* 0x18 */));
    // 00503418  0f7f00                 -movq qword ptr [eax], mm0
    app->getMemory<x86::reg64>(cpu.eax) = cpu.mmx.mm0;
    // 0050341b  0f7f4808               -movq qword ptr [eax + 8], mm1
    app->getMemory<x86::reg64>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.mmx.mm1;
    // 0050341f  0f7f5010               -movq qword ptr [eax + 0x10], mm2
    app->getMemory<x86::reg64>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.mmx.mm2;
    // 00503423  0f7f5818               -movq qword ptr [eax + 0x18], mm3
    app->getMemory<x86::reg64>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.mmx.mm3;
    // 00503427  0f6f4a28               -movq mm1, qword ptr [edx + 0x28]
    cpu.mmx.mm1 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.edx + x86::reg32(40) /* 0x28 */));
    // 0050342b  0f6f5230               -movq mm2, qword ptr [edx + 0x30]
    cpu.mmx.mm2 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.edx + x86::reg32(48) /* 0x30 */));
    // 0050342f  0f6f5a38               -movq mm3, qword ptr [edx + 0x38]
    cpu.mmx.mm3 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.edx + x86::reg32(56) /* 0x38 */));
    // 00503433  0f7f6020               -movq qword ptr [eax + 0x20], mm4
    app->getMemory<x86::reg64>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.mmx.mm4;
    // 00503437  0f7f4828               -movq qword ptr [eax + 0x28], mm1
    app->getMemory<x86::reg64>(cpu.eax + x86::reg32(40) /* 0x28 */) = cpu.mmx.mm1;
    // 0050343b  0f7f5030               -movq qword ptr [eax + 0x30], mm2
    app->getMemory<x86::reg64>(cpu.eax + x86::reg32(48) /* 0x30 */) = cpu.mmx.mm2;
    // 0050343f  0f7f5838               -movq qword ptr [eax + 0x38], mm3
    app->getMemory<x86::reg64>(cpu.eax + x86::reg32(56) /* 0x38 */) = cpu.mmx.mm3;
    // 00503443  0f6f4a48               -movq mm1, qword ptr [edx + 0x48]
    cpu.mmx.mm1 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.edx + x86::reg32(72) /* 0x48 */));
    // 00503447  0f6f5250               -movq mm2, qword ptr [edx + 0x50]
    cpu.mmx.mm2 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.edx + x86::reg32(80) /* 0x50 */));
    // 0050344b  0f6f5a58               -movq mm3, qword ptr [edx + 0x58]
    cpu.mmx.mm3 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.edx + x86::reg32(88) /* 0x58 */));
    // 0050344f  0f7f6840               -movq qword ptr [eax + 0x40], mm5
    app->getMemory<x86::reg64>(cpu.eax + x86::reg32(64) /* 0x40 */) = cpu.mmx.mm5;
    // 00503453  0f7f4848               -movq qword ptr [eax + 0x48], mm1
    app->getMemory<x86::reg64>(cpu.eax + x86::reg32(72) /* 0x48 */) = cpu.mmx.mm1;
    // 00503457  0f7f5050               -movq qword ptr [eax + 0x50], mm2
    app->getMemory<x86::reg64>(cpu.eax + x86::reg32(80) /* 0x50 */) = cpu.mmx.mm2;
    // 0050345b  0f7f5858               -movq qword ptr [eax + 0x58], mm3
    app->getMemory<x86::reg64>(cpu.eax + x86::reg32(88) /* 0x58 */) = cpu.mmx.mm3;
    // 0050345f  0f6f4a68               -movq mm1, qword ptr [edx + 0x68]
    cpu.mmx.mm1 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.edx + x86::reg32(104) /* 0x68 */));
    // 00503463  0f6f5270               -movq mm2, qword ptr [edx + 0x70]
    cpu.mmx.mm2 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.edx + x86::reg32(112) /* 0x70 */));
    // 00503467  0f6f5a78               -movq mm3, qword ptr [edx + 0x78]
    cpu.mmx.mm3 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.edx + x86::reg32(120) /* 0x78 */));
    // 0050346b  0f7f7060               -movq qword ptr [eax + 0x60], mm6
    app->getMemory<x86::reg64>(cpu.eax + x86::reg32(96) /* 0x60 */) = cpu.mmx.mm6;
    // 0050346f  0f7f4868               -movq qword ptr [eax + 0x68], mm1
    app->getMemory<x86::reg64>(cpu.eax + x86::reg32(104) /* 0x68 */) = cpu.mmx.mm1;
    // 00503473  0f7f5070               -movq qword ptr [eax + 0x70], mm2
    app->getMemory<x86::reg64>(cpu.eax + x86::reg32(112) /* 0x70 */) = cpu.mmx.mm2;
    // 00503477  0f7f5878               -movq qword ptr [eax + 0x78], mm3
    app->getMemory<x86::reg64>(cpu.eax + x86::reg32(120) /* 0x78 */) = cpu.mmx.mm3;
    // 0050347b  81c280000000           -add edx, 0x80
    (cpu.edx) += x86::reg32(x86::sreg32(128 /*0x80*/));
    // 00503481  0580000000             -add eax, 0x80
    (cpu.eax) += x86::reg32(x86::sreg32(128 /*0x80*/));
    // 00503486  81eb80000000           +sub ebx, 0x80
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
    // 0050348c  0f896bffffff           -jns 0x5033fd
    if (!cpu.flags.sf)
    {
        goto L_0x005033fd;
    }
L_0x00503492:
    // 00503492  83c360                 +add ebx, 0x60
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
    // 00503495  7829                   -js 0x5034c0
    if (cpu.flags.sf)
    {
        goto L_0x005034c0;
    }
L_0x00503497:
    // 00503497  0f6f02                 -movq mm0, qword ptr [edx]
    cpu.mmx.mm0 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.edx));
    // 0050349a  0f6f4a08               -movq mm1, qword ptr [edx + 8]
    cpu.mmx.mm1 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.edx + x86::reg32(8) /* 0x8 */));
    // 0050349e  0f6f5210               -movq mm2, qword ptr [edx + 0x10]
    cpu.mmx.mm2 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.edx + x86::reg32(16) /* 0x10 */));
    // 005034a2  0f6f5a18               -movq mm3, qword ptr [edx + 0x18]
    cpu.mmx.mm3 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.edx + x86::reg32(24) /* 0x18 */));
    // 005034a6  0f7f00                 -movq qword ptr [eax], mm0
    app->getMemory<x86::reg64>(cpu.eax) = cpu.mmx.mm0;
    // 005034a9  0f7f4808               -movq qword ptr [eax + 8], mm1
    app->getMemory<x86::reg64>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.mmx.mm1;
    // 005034ad  0f7f5010               -movq qword ptr [eax + 0x10], mm2
    app->getMemory<x86::reg64>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.mmx.mm2;
    // 005034b1  0f7f5818               -movq qword ptr [eax + 0x18], mm3
    app->getMemory<x86::reg64>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.mmx.mm3;
    // 005034b5  83c220                 -add edx, 0x20
    (cpu.edx) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 005034b8  83c020                 -add eax, 0x20
    (cpu.eax) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 005034bb  83eb20                 +sub ebx, 0x20
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
    // 005034be  79d7                   -jns 0x503497
    if (!cpu.flags.sf)
    {
        goto L_0x00503497;
    }
L_0x005034c0:
    // 005034c0  83c318                 +add ebx, 0x18
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
    // 005034c3  7811                   -js 0x5034d6
    if (cpu.flags.sf)
    {
        goto L_0x005034d6;
    }
L_0x005034c5:
    // 005034c5  0f6f02                 -movq mm0, qword ptr [edx]
    cpu.mmx.mm0 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.edx));
    // 005034c8  0f7f00                 -movq qword ptr [eax], mm0
    app->getMemory<x86::reg64>(cpu.eax) = cpu.mmx.mm0;
    // 005034cb  83c208                 -add edx, 8
    (cpu.edx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 005034ce  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 005034d1  83eb08                 +sub ebx, 8
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
    // 005034d4  79ef                   -jns 0x5034c5
    if (!cpu.flags.sf)
    {
        goto L_0x005034c5;
    }
L_0x005034d6:
    // 005034d6  83c308                 +add ebx, 8
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
    // 005034d9  7502                   -jne 0x5034dd
    if (!cpu.flags.zf)
    {
        goto L_0x005034dd;
    }
    // 005034db  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005034dc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005034dd:
    // 005034dd  83fb04                 +cmp ebx, 4
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
    // 005034e0  720d                   -jb 0x5034ef
    if (cpu.flags.cf)
    {
        goto L_0x005034ef;
    }
    // 005034e2  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 005034e4  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 005034e7  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 005034e9  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 005034ec  83eb04                 -sub ebx, 4
    (cpu.ebx) -= x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x005034ef:
    // 005034ef  83fb02                 +cmp ebx, 2
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
    // 005034f2  720f                   -jb 0x503503
    if (cpu.flags.cf)
    {
        goto L_0x00503503;
    }
    // 005034f4  668b0a                 -mov cx, word ptr [edx]
    cpu.cx = app->getMemory<x86::reg16>(cpu.edx);
    // 005034f7  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 005034fa  668908                 -mov word ptr [eax], cx
    app->getMemory<x86::reg16>(cpu.eax) = cpu.cx;
    // 005034fd  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00503500  83eb02                 -sub ebx, 2
    (cpu.ebx) -= x86::reg32(x86::sreg32(2 /*0x2*/));
L_0x00503503:
    // 00503503  83fb01                 +cmp ebx, 1
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
    // 00503506  720d                   -jb 0x503515
    if (cpu.flags.cf)
    {
        goto L_0x00503515;
    }
    // 00503508  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 0050350a  83c201                 -add edx, 1
    (cpu.edx) += x86::reg32(x86::sreg32(1 /*0x1*/));
    // 0050350d  8808                   -mov byte ptr [eax], cl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.cl;
    // 0050350f  83c001                 -add eax, 1
    (cpu.eax) += x86::reg32(x86::sreg32(1 /*0x1*/));
    // 00503512  83eb01                 -sub ebx, 1
    (cpu.ebx) -= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x00503515:
    // 00503515  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00503516  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00503517:
    // 00503517  a901000000             +test eax, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 1 /*0x1*/));
    // 0050351c  7412                   -je 0x503530
    if (cpu.flags.zf)
    {
        goto L_0x00503530;
    }
    // 0050351e  83fb01                 +cmp ebx, 1
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
    // 00503521  7c0d                   -jl 0x503530
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00503530;
    }
    // 00503523  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 00503525  83c201                 -add edx, 1
    (cpu.edx) += x86::reg32(x86::sreg32(1 /*0x1*/));
    // 00503528  8808                   -mov byte ptr [eax], cl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.cl;
    // 0050352a  83c001                 -add eax, 1
    (cpu.eax) += x86::reg32(x86::sreg32(1 /*0x1*/));
    // 0050352d  83eb01                 -sub ebx, 1
    (cpu.ebx) -= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x00503530:
    // 00503530  a902000000             +test eax, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2 /*0x2*/));
    // 00503535  7414                   -je 0x50354b
    if (cpu.flags.zf)
    {
        goto L_0x0050354b;
    }
    // 00503537  83fb02                 +cmp ebx, 2
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
    // 0050353a  7c0f                   -jl 0x50354b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0050354b;
    }
    // 0050353c  668b0a                 -mov cx, word ptr [edx]
    cpu.cx = app->getMemory<x86::reg16>(cpu.edx);
    // 0050353f  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00503542  668908                 -mov word ptr [eax], cx
    app->getMemory<x86::reg16>(cpu.eax) = cpu.cx;
    // 00503545  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00503548  83eb02                 -sub ebx, 2
    (cpu.ebx) -= x86::reg32(x86::sreg32(2 /*0x2*/));
L_0x0050354b:
    // 0050354b  a904000000             +test eax, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 4 /*0x4*/));
    // 00503550  7412                   -je 0x503564
    if (cpu.flags.zf)
    {
        goto L_0x00503564;
    }
    // 00503552  83fb04                 +cmp ebx, 4
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
    // 00503555  7c0d                   -jl 0x503564
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00503564;
    }
    // 00503557  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 00503559  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0050355c  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 0050355e  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00503561  83eb04                 +sub ebx, 4
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
L_0x00503564:
    // 00503564  e988feffff             -jmp 0x5033f1
    goto L_0x005033f1;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_50356c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050356c  92                     -xchg edx, eax
    {
        x86::reg32 tmp = cpu.edx;
        cpu.edx = cpu.eax;
        cpu.eax = tmp;
    }
    // 0050356d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050356e  a903000000             +test eax, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 3 /*0x3*/));
    // 00503573  0f8599000000           -jne 0x503612
    if (!cpu.flags.zf)
    {
        goto L_0x00503612;
    }
L_0x00503579:
    // 00503579  83eb20                 +sub ebx, 0x20
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
    // 0050357c  7839                   -js 0x5035b7
    if (cpu.flags.sf)
    {
        goto L_0x005035b7;
    }
L_0x0050357e:
    // 0050357e  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 00503580  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 00503582  8b4a04                 -mov ecx, dword ptr [edx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00503585  894804                 -mov dword ptr [eax + 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 00503588  8b4a08                 -mov ecx, dword ptr [edx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0050358b  894808                 -mov dword ptr [eax + 8], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 0050358e  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00503591  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00503594  8b4a10                 -mov ecx, dword ptr [edx + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00503597  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 0050359a  8b4a14                 -mov ecx, dword ptr [edx + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */);
    // 0050359d  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 005035a0  8b4a18                 -mov ecx, dword ptr [edx + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 005035a3  894818                 -mov dword ptr [eax + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 005035a6  8b4a1c                 -mov ecx, dword ptr [edx + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */);
    // 005035a9  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 005035ac  83c220                 -add edx, 0x20
    (cpu.edx) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 005035af  83c020                 -add eax, 0x20
    (cpu.eax) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 005035b2  83eb20                 +sub ebx, 0x20
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
    // 005035b5  79c7                   -jns 0x50357e
    if (!cpu.flags.sf)
    {
        goto L_0x0050357e;
    }
L_0x005035b7:
    // 005035b7  83c318                 +add ebx, 0x18
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
    // 005035ba  7815                   -js 0x5035d1
    if (cpu.flags.sf)
    {
        goto L_0x005035d1;
    }
L_0x005035bc:
    // 005035bc  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 005035be  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 005035c0  8b4a04                 -mov ecx, dword ptr [edx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 005035c3  894804                 -mov dword ptr [eax + 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 005035c6  83c208                 -add edx, 8
    (cpu.edx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 005035c9  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 005035cc  83eb08                 +sub ebx, 8
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
    // 005035cf  79eb                   -jns 0x5035bc
    if (!cpu.flags.sf)
    {
        goto L_0x005035bc;
    }
L_0x005035d1:
    // 005035d1  83c308                 +add ebx, 8
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
    // 005035d4  7502                   -jne 0x5035d8
    if (!cpu.flags.zf)
    {
        goto L_0x005035d8;
    }
    // 005035d6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005035d7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005035d8:
    // 005035d8  83fb04                 +cmp ebx, 4
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
    // 005035db  720d                   -jb 0x5035ea
    if (cpu.flags.cf)
    {
        goto L_0x005035ea;
    }
    // 005035dd  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 005035df  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 005035e2  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 005035e4  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 005035e7  83eb04                 -sub ebx, 4
    (cpu.ebx) -= x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x005035ea:
    // 005035ea  83fb02                 +cmp ebx, 2
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
    // 005035ed  720f                   -jb 0x5035fe
    if (cpu.flags.cf)
    {
        goto L_0x005035fe;
    }
    // 005035ef  668b0a                 -mov cx, word ptr [edx]
    cpu.cx = app->getMemory<x86::reg16>(cpu.edx);
    // 005035f2  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 005035f5  668908                 -mov word ptr [eax], cx
    app->getMemory<x86::reg16>(cpu.eax) = cpu.cx;
    // 005035f8  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 005035fb  83eb02                 -sub ebx, 2
    (cpu.ebx) -= x86::reg32(x86::sreg32(2 /*0x2*/));
L_0x005035fe:
    // 005035fe  83fb01                 +cmp ebx, 1
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
    // 00503601  720d                   -jb 0x503610
    if (cpu.flags.cf)
    {
        goto L_0x00503610;
    }
    // 00503603  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 00503605  83c201                 -add edx, 1
    (cpu.edx) += x86::reg32(x86::sreg32(1 /*0x1*/));
    // 00503608  8808                   -mov byte ptr [eax], cl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.cl;
    // 0050360a  83c001                 -add eax, 1
    (cpu.eax) += x86::reg32(x86::sreg32(1 /*0x1*/));
    // 0050360d  83eb01                 -sub ebx, 1
    (cpu.ebx) -= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x00503610:
    // 00503610  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00503611  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00503612:
    // 00503612  a901000000             +test eax, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 1 /*0x1*/));
    // 00503617  7412                   -je 0x50362b
    if (cpu.flags.zf)
    {
        goto L_0x0050362b;
    }
    // 00503619  83fb01                 +cmp ebx, 1
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
    // 0050361c  7c0d                   -jl 0x50362b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0050362b;
    }
    // 0050361e  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 00503620  83c201                 -add edx, 1
    (cpu.edx) += x86::reg32(x86::sreg32(1 /*0x1*/));
    // 00503623  8808                   -mov byte ptr [eax], cl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.cl;
    // 00503625  83c001                 -add eax, 1
    (cpu.eax) += x86::reg32(x86::sreg32(1 /*0x1*/));
    // 00503628  83eb01                 -sub ebx, 1
    (cpu.ebx) -= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x0050362b:
    // 0050362b  a902000000             +test eax, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2 /*0x2*/));
    // 00503630  7414                   -je 0x503646
    if (cpu.flags.zf)
    {
        goto L_0x00503646;
    }
    // 00503632  83fb02                 +cmp ebx, 2
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
    // 00503635  7c0f                   -jl 0x503646
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00503646;
    }
    // 00503637  668b0a                 -mov cx, word ptr [edx]
    cpu.cx = app->getMemory<x86::reg16>(cpu.edx);
    // 0050363a  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0050363d  668908                 -mov word ptr [eax], cx
    app->getMemory<x86::reg16>(cpu.eax) = cpu.cx;
    // 00503640  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00503643  83eb02                 -sub ebx, 2
    (cpu.ebx) -= x86::reg32(x86::sreg32(2 /*0x2*/));
L_0x00503646:
    // 00503646  a904000000             +test eax, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 4 /*0x4*/));
    // 0050364b  7412                   -je 0x50365f
    if (cpu.flags.zf)
    {
        goto L_0x0050365f;
    }
    // 0050364d  83fb04                 +cmp ebx, 4
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
    // 00503650  7c0d                   -jl 0x50365f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0050365f;
    }
    // 00503652  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 00503654  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00503657  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 00503659  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0050365c  83eb04                 +sub ebx, 4
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
L_0x0050365f:
    // 0050365f  e915ffffff             -jmp 0x503579
    goto L_0x00503579;
}

/* align: skip  */
void Application::sub_50356d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x0050356d;
    // 0050356c  92                     -xchg edx, eax
    {
        x86::reg32 tmp = cpu.edx;
        cpu.edx = cpu.eax;
        cpu.eax = tmp;
    }
L_entry_0x0050356d:
    // 0050356d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050356e  a903000000             +test eax, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 3 /*0x3*/));
    // 00503573  0f8599000000           -jne 0x503612
    if (!cpu.flags.zf)
    {
        goto L_0x00503612;
    }
L_0x00503579:
    // 00503579  83eb20                 +sub ebx, 0x20
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
    // 0050357c  7839                   -js 0x5035b7
    if (cpu.flags.sf)
    {
        goto L_0x005035b7;
    }
L_0x0050357e:
    // 0050357e  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 00503580  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 00503582  8b4a04                 -mov ecx, dword ptr [edx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00503585  894804                 -mov dword ptr [eax + 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 00503588  8b4a08                 -mov ecx, dword ptr [edx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0050358b  894808                 -mov dword ptr [eax + 8], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 0050358e  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00503591  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00503594  8b4a10                 -mov ecx, dword ptr [edx + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00503597  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 0050359a  8b4a14                 -mov ecx, dword ptr [edx + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */);
    // 0050359d  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 005035a0  8b4a18                 -mov ecx, dword ptr [edx + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 005035a3  894818                 -mov dword ptr [eax + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 005035a6  8b4a1c                 -mov ecx, dword ptr [edx + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */);
    // 005035a9  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 005035ac  83c220                 -add edx, 0x20
    (cpu.edx) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 005035af  83c020                 -add eax, 0x20
    (cpu.eax) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 005035b2  83eb20                 +sub ebx, 0x20
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
    // 005035b5  79c7                   -jns 0x50357e
    if (!cpu.flags.sf)
    {
        goto L_0x0050357e;
    }
L_0x005035b7:
    // 005035b7  83c318                 +add ebx, 0x18
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
    // 005035ba  7815                   -js 0x5035d1
    if (cpu.flags.sf)
    {
        goto L_0x005035d1;
    }
L_0x005035bc:
    // 005035bc  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 005035be  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 005035c0  8b4a04                 -mov ecx, dword ptr [edx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 005035c3  894804                 -mov dword ptr [eax + 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 005035c6  83c208                 -add edx, 8
    (cpu.edx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 005035c9  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 005035cc  83eb08                 +sub ebx, 8
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
    // 005035cf  79eb                   -jns 0x5035bc
    if (!cpu.flags.sf)
    {
        goto L_0x005035bc;
    }
L_0x005035d1:
    // 005035d1  83c308                 +add ebx, 8
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
    // 005035d4  7502                   -jne 0x5035d8
    if (!cpu.flags.zf)
    {
        goto L_0x005035d8;
    }
    // 005035d6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005035d7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005035d8:
    // 005035d8  83fb04                 +cmp ebx, 4
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
    // 005035db  720d                   -jb 0x5035ea
    if (cpu.flags.cf)
    {
        goto L_0x005035ea;
    }
    // 005035dd  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 005035df  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 005035e2  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 005035e4  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 005035e7  83eb04                 -sub ebx, 4
    (cpu.ebx) -= x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x005035ea:
    // 005035ea  83fb02                 +cmp ebx, 2
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
    // 005035ed  720f                   -jb 0x5035fe
    if (cpu.flags.cf)
    {
        goto L_0x005035fe;
    }
    // 005035ef  668b0a                 -mov cx, word ptr [edx]
    cpu.cx = app->getMemory<x86::reg16>(cpu.edx);
    // 005035f2  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 005035f5  668908                 -mov word ptr [eax], cx
    app->getMemory<x86::reg16>(cpu.eax) = cpu.cx;
    // 005035f8  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 005035fb  83eb02                 -sub ebx, 2
    (cpu.ebx) -= x86::reg32(x86::sreg32(2 /*0x2*/));
L_0x005035fe:
    // 005035fe  83fb01                 +cmp ebx, 1
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
    // 00503601  720d                   -jb 0x503610
    if (cpu.flags.cf)
    {
        goto L_0x00503610;
    }
    // 00503603  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 00503605  83c201                 -add edx, 1
    (cpu.edx) += x86::reg32(x86::sreg32(1 /*0x1*/));
    // 00503608  8808                   -mov byte ptr [eax], cl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.cl;
    // 0050360a  83c001                 -add eax, 1
    (cpu.eax) += x86::reg32(x86::sreg32(1 /*0x1*/));
    // 0050360d  83eb01                 -sub ebx, 1
    (cpu.ebx) -= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x00503610:
    // 00503610  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00503611  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00503612:
    // 00503612  a901000000             +test eax, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 1 /*0x1*/));
    // 00503617  7412                   -je 0x50362b
    if (cpu.flags.zf)
    {
        goto L_0x0050362b;
    }
    // 00503619  83fb01                 +cmp ebx, 1
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
    // 0050361c  7c0d                   -jl 0x50362b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0050362b;
    }
    // 0050361e  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 00503620  83c201                 -add edx, 1
    (cpu.edx) += x86::reg32(x86::sreg32(1 /*0x1*/));
    // 00503623  8808                   -mov byte ptr [eax], cl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.cl;
    // 00503625  83c001                 -add eax, 1
    (cpu.eax) += x86::reg32(x86::sreg32(1 /*0x1*/));
    // 00503628  83eb01                 -sub ebx, 1
    (cpu.ebx) -= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x0050362b:
    // 0050362b  a902000000             +test eax, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2 /*0x2*/));
    // 00503630  7414                   -je 0x503646
    if (cpu.flags.zf)
    {
        goto L_0x00503646;
    }
    // 00503632  83fb02                 +cmp ebx, 2
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
    // 00503635  7c0f                   -jl 0x503646
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00503646;
    }
    // 00503637  668b0a                 -mov cx, word ptr [edx]
    cpu.cx = app->getMemory<x86::reg16>(cpu.edx);
    // 0050363a  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0050363d  668908                 -mov word ptr [eax], cx
    app->getMemory<x86::reg16>(cpu.eax) = cpu.cx;
    // 00503640  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00503643  83eb02                 -sub ebx, 2
    (cpu.ebx) -= x86::reg32(x86::sreg32(2 /*0x2*/));
L_0x00503646:
    // 00503646  a904000000             +test eax, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 4 /*0x4*/));
    // 0050364b  7412                   -je 0x50365f
    if (cpu.flags.zf)
    {
        goto L_0x0050365f;
    }
    // 0050364d  83fb04                 +cmp ebx, 4
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
    // 00503650  7c0d                   -jl 0x50365f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0050365f;
    }
    // 00503652  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 00503654  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00503657  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 00503659  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0050365c  83eb04                 +sub ebx, 4
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
L_0x0050365f:
    // 0050365f  e915ffffff             -jmp 0x503579
    goto L_0x00503579;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_503670(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00503670  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00503671  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00503672  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00503673  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00503674  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00503677  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00503679  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0050367b  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0050367d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0050367f  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00503684  81e6ffff0000           -and esi, 0xffff
    cpu.esi &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0050368a  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0050368c  0fafde                 -imul ebx, esi
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 0050368f  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00503691  c1ef10                 -shr edi, 0x10
    cpu.edi >>= 16 /*0x10*/ % 32;
    // 00503694  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00503698  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0050369a  0fafc7                 -imul eax, edi
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edi)));
    // 0050369d  c1ed10                 -shr ebp, 0x10
    cpu.ebp >>= 16 /*0x10*/ % 32;
    // 005036a0  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 005036a4  0fafd5                 -imul edx, ebp
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ebp)));
    // 005036a7  0fafef                 -imul ebp, edi
    cpu.ebp = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebp)) * x86::sreg64(x86::sreg32(cpu.edi)));
    // 005036aa  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 005036ac  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 005036ae  c1ee10                 -shr esi, 0x10
    cpu.esi >>= 16 /*0x10*/ % 32;
    // 005036b1  81e7ffff0000           -and edi, 0xffff
    cpu.edi &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 005036b7  01f7                   -add edi, esi
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.esi));
    // 005036b9  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 005036bb  81e6ffff0000           -and esi, 0xffff
    cpu.esi &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 005036c1  01fe                   -add esi, edi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edi));
    // 005036c3  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 005036c5  c1e710                 -shl edi, 0x10
    cpu.edi <<= 16 /*0x10*/ % 32;
    // 005036c8  c1ee10                 -shr esi, 0x10
    cpu.esi >>= 16 /*0x10*/ % 32;
    // 005036cb  01fb                   -add ebx, edi
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edi));
    // 005036cd  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 005036cf  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 005036d2  c1e710                 -shl edi, 0x10
    cpu.edi <<= 16 /*0x10*/ % 32;
    // 005036d5  c1ea10                 -shr edx, 0x10
    cpu.edx >>= 16 /*0x10*/ % 32;
    // 005036d8  01fb                   -add ebx, edi
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edi));
    // 005036da  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 005036dc  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 005036df  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 005036e1  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 005036e3  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 005036e5  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 005036e7  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 005036eb  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 005036ec  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 005036ed  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 005036ef  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 005036f2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005036f3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005036f4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005036f5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005036f6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_503700(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00503700  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00503701  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00503702  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00503703  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00503706  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00503708  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0050370a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0050370c  7c23                   -jl 0x503731
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00503731;
    }
L_0x0050370e:
    // 0050370e  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00503710  7d05                   -jge 0x503717
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00503717;
    }
    // 00503712  80f301                 -xor bl, 1
    cpu.bl ^= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00503715  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
L_0x00503717:
    // 00503717  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 00503719  e852ffffff             -call 0x503670
    cpu.esp -= 4;
    sub_503670(app, cpu);
    if (cpu.terminate) return;
    // 0050371e  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00503720  7518                   -jne 0x50373a
    if (!cpu.flags.zf)
    {
        goto L_0x0050373a;
    }
    // 00503722  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 00503724  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 00503726  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00503727  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00503728  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0050372a  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0050372d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050372e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050372f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00503730  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00503731:
    // 00503731  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00503736  f7d8                   +neg eax
    {
        x86::reg32 tmp1 = 0;
        x86::reg32& tmp2 = cpu.eax;
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp2 = result;
        cpu.set_szp(tmp2);
    }
    // 00503738  ebd4                   -jmp 0x50370e
    goto L_0x0050370e;
L_0x0050373a:
    // 0050373a  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0050373e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0050373f  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00503743  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00503744  8d742408               -lea esi, [esp + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00503748  e853030000             -call 0x503aa0
    cpu.esp -= 4;
    sub_503aa0(app, cpu);
    if (cpu.terminate) return;
    // 0050374d  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 0050374f  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 00503751  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00503752  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00503753  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00503755  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00503758  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00503759  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050375a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050375b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_503760(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00503760  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00503761  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00503762  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00503763  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00503764  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00503765  8b7c2420               -mov edi, dword ptr [esp + 0x20]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00503769  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0050376d  bb20000000             -mov ebx, 0x20
    cpu.ebx = 32 /*0x20*/;
    // 00503772  8b4c2418               -mov ecx, dword ptr [esp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00503776  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00503778:
    // 00503778  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0050377a  4b                     -dec ebx
    (cpu.ebx)--;
    // 0050377b  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 0050377d  c1ee1f                 -shr esi, 0x1f
    cpu.esi >>= 31 /*0x1f*/ % 32;
    // 00503780  01d2                   -add edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00503782  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 00503784  01c9                   -add ecx, ecx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00503786  39f8                   +cmp eax, edi
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
    // 00503788  7203                   -jb 0x50378d
    if (cpu.flags.cf)
    {
        goto L_0x0050378d;
    }
    // 0050378a  42                     -inc edx
    (cpu.edx)++;
    // 0050378b  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
L_0x0050378d:
    // 0050378d  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0050378f  75e7                   -jne 0x503778
    if (!cpu.flags.zf)
    {
        goto L_0x00503778;
    }
    // 00503791  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00503793  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00503794  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00503795  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00503796  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00503797  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00503798  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_5037a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005037a0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 005037a1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005037a2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 005037a3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005037a4  8b4c241c               -mov ecx, dword ptr [esp + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 005037a8  8b5c2418               -mov ebx, dword ptr [esp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 005037ac  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 005037ae  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 005037b0  7c28                   -jl 0x5037da
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x005037da;
    }
L_0x005037b2:
    // 005037b2  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 005037b4  7d05                   -jge 0x5037bb
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x005037bb;
    }
    // 005037b6  80f201                 -xor dl, 1
    cpu.dl ^= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 005037b9  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
L_0x005037bb:
    // 005037bb  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005037bc  8b6c241c               -mov ebp, dword ptr [esp + 0x1c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 005037c0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005037c1  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 005037c5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 005037c6  e895ffffff             -call 0x503760
    cpu.esp -= 4;
    sub_503760(app, cpu);
    if (cpu.terminate) return;
    // 005037cb  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 005037cd  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 005037cf  7402                   -je 0x5037d3
    if (cpu.flags.zf)
    {
        goto L_0x005037d3;
    }
    // 005037d1  f7d8                   +neg eax
    {
        x86::reg32 tmp1 = 0;
        x86::reg32& tmp2 = cpu.eax;
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp2 = result;
        cpu.set_szp(tmp2);
    }
L_0x005037d3:
    // 005037d3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005037d4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005037d5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005037d6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005037d7  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x005037da:
    // 005037da  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 005037db  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005037dc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 005037dd  8b7c2420               -mov edi, dword ptr [esp + 0x20]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 005037e1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 005037e2  8d742424               -lea esi, [esp + 0x24]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 005037e6  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 005037eb  e8b0020000             -call 0x503aa0
    cpu.esp -= 4;
    sub_503aa0(app, cpu);
    if (cpu.terminate) return;
    // 005037f0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005037f1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005037f2  ebbe                   -jmp 0x5037b2
    goto L_0x005037b2;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_503800(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00503800  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00503801  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00503802  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00503803  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00503804  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00503805  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00503806  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00503809  8b54243c               -mov edx, dword ptr [esp + 0x3c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 0050380d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0050380e  8b4c243c               -mov ecx, dword ptr [esp + 0x3c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00503812  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00503813  8b5c243c               -mov ebx, dword ptr [esp + 0x3c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00503817  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00503818  8d74241c               -lea esi, [esp + 0x1c]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0050381c  e83fffffff             -call 0x503760
    cpu.esp -= 4;
    sub_503760(app, cpu);
    if (cpu.terminate) return;
    // 00503821  e84afeffff             -call 0x503670
    cpu.esp -= 4;
    sub_503670(app, cpu);
    if (cpu.terminate) return;
    // 00503826  8b742414               -mov esi, dword ptr [esp + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0050382a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050382b  8b7c2414               -mov edi, dword ptr [esp + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0050382f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00503830  8d742408               -lea esi, [esp + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00503834  e867020000             -call 0x503aa0
    cpu.esp -= 4;
    sub_503aa0(app, cpu);
    if (cpu.terminate) return;
    // 00503839  8b6c2404               -mov ebp, dword ptr [esp + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0050383d  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0050383e  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00503842  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00503843  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00503844  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00503845  8d742418               -lea esi, [esp + 0x18]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00503849  e872000000             -call 0x5038c0
    cpu.esp -= 4;
    sub_5038c0(app, cpu);
    if (cpu.terminate) return;
    // 0050384e  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00503852  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00503855  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00503856  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00503857  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00503858  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00503859  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050385a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050385b  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_503860(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00503860  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00503861  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00503862  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00503863  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00503864  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00503865  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00503866  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00503869  8b54243c               -mov edx, dword ptr [esp + 0x3c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 0050386d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0050386e  8b4c243c               -mov ecx, dword ptr [esp + 0x3c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00503872  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00503873  8b5c243c               -mov ebx, dword ptr [esp + 0x3c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00503877  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00503878  8d74241c               -lea esi, [esp + 0x1c]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0050387c  e81fffffff             -call 0x5037a0
    cpu.esp -= 4;
    sub_5037a0(app, cpu);
    if (cpu.terminate) return;
    // 00503881  e87afeffff             -call 0x503700
    cpu.esp -= 4;
    sub_503700(app, cpu);
    if (cpu.terminate) return;
    // 00503886  8b742414               -mov esi, dword ptr [esp + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0050388a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050388b  8b7c2414               -mov edi, dword ptr [esp + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0050388f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00503890  8d742408               -lea esi, [esp + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00503894  e807020000             -call 0x503aa0
    cpu.esp -= 4;
    sub_503aa0(app, cpu);
    if (cpu.terminate) return;
    // 00503899  8b6c2404               -mov ebp, dword ptr [esp + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0050389d  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0050389e  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 005038a2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 005038a3  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005038a4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 005038a5  8d742418               -lea esi, [esp + 0x18]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 005038a9  e812000000             -call 0x5038c0
    cpu.esp -= 4;
    sub_5038c0(app, cpu);
    if (cpu.terminate) return;
    // 005038ae  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 005038b2  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 005038b5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005038b6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005038b7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005038b8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005038b9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005038ba  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005038bb  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_5038c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005038c0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 005038c1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 005038c2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 005038c3  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 005038c6  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 005038c8  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 005038cc  03442420               -add eax, dword ptr [esp + 0x20]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 005038d0  8b5c2424               -mov ebx, dword ptr [esp + 0x24]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 005038d4  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 005038d7  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 005038db  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 005038dd  8b742418               -mov esi, dword ptr [esp + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 005038e1  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 005038e5  3b3424                 +cmp esi, dword ptr [esp]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005038e8  7711                   -ja 0x5038fb
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x005038fb;
    }
    // 005038ea  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 005038ec  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 005038ee  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 005038ef  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 005038f0  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 005038f2  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 005038f5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005038f6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005038f7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005038f8  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x005038fb:
    // 005038fb  ff442404               -inc dword ptr [esp + 4]
    (app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */))++;
    // 005038ff  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 00503901  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00503903  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00503904  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00503905  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00503907  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0050390a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050390b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050390c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050390d  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip  */
void Application::sub_503910(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00503910  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00503911  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00503912  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00503913  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00503916  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0050391a  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0050391c  83f820                 +cmp eax, 0x20
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
    // 0050391f  7d46                   -jge 0x503967
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00503967;
    }
    // 00503921  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00503923  7458                   -je 0x50397d
    if (cpu.flags.zf)
    {
        goto L_0x0050397d;
    }
    // 00503925  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00503926  8b5c2424               -mov ebx, dword ptr [esp + 0x24]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0050392a  88c1                   -mov cl, al
    cpu.cl = cpu.al;
    // 0050392c  d3e3                   -shl ebx, cl
    cpu.ebx <<= cpu.cl % 32;
    // 0050392e  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 00503932  8b5c2428               -mov ebx, dword ptr [esp + 0x28]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00503936  d3e3                   -shl ebx, cl
    cpu.ebx <<= cpu.cl % 32;
    // 00503938  b920000000             -mov ecx, 0x20
    cpu.ecx = 32 /*0x20*/;
    // 0050393d  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0050393f  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00503943  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 00503945  09c3                   -or ebx, eax
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.eax));
    // 00503947  895c2408               -mov dword ptr [esp + 8], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 0050394b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0050394c:
    // 0050394c  8d7c2408               -lea edi, [esp + 8]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00503950  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
L_0x00503952:
    // 00503952  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00503953  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00503954  8d742408               -lea esi, [esp + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00503958  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0050395a  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0050395b  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0050395c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0050395e  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00503961  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00503962  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00503963  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00503964  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x00503967:
    // 00503967  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00503969  83e820                 -sub eax, 0x20
    (cpu.eax) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0050396c  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 0050396f  88c1                   -mov cl, al
    cpu.cl = cpu.al;
    // 00503971  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00503975  d3e0                   +shl eax, cl
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
    // 00503977  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0050397b  ebcf                   -jmp 0x50394c
    goto L_0x0050394c;
L_0x0050397d:
    // 0050397d  8d7c2408               -lea edi, [esp + 8]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00503981  8d742420               -lea esi, [esp + 0x20]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00503985  ebcb                   -jmp 0x503952
    goto L_0x00503952;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_503990(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00503990  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00503991  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00503992  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00503993  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00503996  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0050399a  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0050399c  83f820                 +cmp eax, 0x20
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
    // 0050399f  7d4a                   -jge 0x5039eb
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x005039eb;
    }
    // 005039a1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005039a3  745c                   -je 0x503a01
    if (cpu.flags.zf)
    {
        goto L_0x00503a01;
    }
    // 005039a5  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 005039a6  b920000000             -mov ecx, 0x20
    cpu.ecx = 32 /*0x20*/;
    // 005039ab  8b5c2428               -mov ebx, dword ptr [esp + 0x28]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 005039af  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 005039b1  8b742424               -mov esi, dword ptr [esp + 0x24]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 005039b5  d3e3                   -shl ebx, cl
    cpu.ebx <<= cpu.cl % 32;
    // 005039b7  88c1                   -mov cl, al
    cpu.cl = cpu.al;
    // 005039b9  d3ee                   -shr esi, cl
    cpu.esi >>= cpu.cl % 32;
    // 005039bb  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 005039bd  09d9                   -or ecx, ebx
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.ebx));
    // 005039bf  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 005039c3  88c1                   -mov cl, al
    cpu.cl = cpu.al;
    // 005039c5  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 005039c9  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 005039cb  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 005039cf  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x005039d0:
    // 005039d0  8d7c2408               -lea edi, [esp + 8]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 005039d4  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
L_0x005039d6:
    // 005039d6  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 005039d7  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 005039d8  8d742408               -lea esi, [esp + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 005039dc  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 005039de  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 005039df  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 005039e0  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 005039e2  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 005039e5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005039e6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005039e7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005039e8  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x005039eb:
    // 005039eb  83e820                 -sub eax, 0x20
    (cpu.eax) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 005039ee  88c1                   -mov cl, al
    cpu.cl = cpu.al;
    // 005039f0  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 005039f4  d3f8                   -sar eax, cl
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (cpu.cl % 32));
    // 005039f6  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 005039f8  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 005039fb  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 005039ff  ebcf                   -jmp 0x5039d0
    goto L_0x005039d0;
L_0x00503a01:
    // 00503a01  8d7c2408               -lea edi, [esp + 8]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00503a05  8d742420               -lea esi, [esp + 0x20]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00503a09  ebcb                   -jmp 0x5039d6
    goto L_0x005039d6;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_503a10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00503a10  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00503a11  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00503a12  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00503a13  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00503a16  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00503a1a  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00503a1c  83f820                 +cmp eax, 0x20
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
    // 00503a1f  7d48                   -jge 0x503a69
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00503a69;
    }
    // 00503a21  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00503a23  7460                   -je 0x503a85
    if (cpu.flags.zf)
    {
        goto L_0x00503a85;
    }
    // 00503a25  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00503a26  b920000000             -mov ecx, 0x20
    cpu.ecx = 32 /*0x20*/;
    // 00503a2b  8b5c2428               -mov ebx, dword ptr [esp + 0x28]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00503a2f  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00503a31  8b742424               -mov esi, dword ptr [esp + 0x24]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00503a35  d3e3                   -shl ebx, cl
    cpu.ebx <<= cpu.cl % 32;
    // 00503a37  88c1                   -mov cl, al
    cpu.cl = cpu.al;
    // 00503a39  d3ee                   -shr esi, cl
    cpu.esi >>= cpu.cl % 32;
    // 00503a3b  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00503a3d  09d9                   -or ecx, ebx
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.ebx));
    // 00503a3f  894c240c               -mov dword ptr [esp + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00503a43  88c1                   -mov cl, al
    cpu.cl = cpu.al;
    // 00503a45  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00503a49  d3f8                   -sar eax, cl
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (cpu.cl % 32));
    // 00503a4b  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00503a4f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00503a50:
    // 00503a50  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 00503a52  8d742408               -lea esi, [esp + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00503a56  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00503a57  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00503a58  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 00503a5a  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00503a5c  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00503a5d  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00503a5e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00503a60  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00503a63  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00503a64  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00503a65  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00503a66  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x00503a69:
    // 00503a69  83e820                 -sub eax, 0x20
    (cpu.eax) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00503a6c  88c1                   -mov cl, al
    cpu.cl = cpu.al;
    // 00503a6e  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00503a72  d3f8                   -sar eax, cl
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (cpu.cl % 32));
    // 00503a74  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00503a78  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00503a7c  c1f81f                 +sar eax, 0x1f
    {
        x86::reg8 tmp = 31 /*0x1f*/ % 32;
        x86::reg32& op = cpu.eax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (x86::sreg32(op) >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = 0;
            cpu.set_szp((op = x86::reg32(x86::sreg32(op) >> tmp)));
        }
    }
    // 00503a7f  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00503a83  ebcb                   -jmp 0x503a50
    goto L_0x00503a50;
L_0x00503a85:
    // 00503a85  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 00503a87  8d742420               -lea esi, [esp + 0x20]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00503a8b  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00503a8c  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00503a8d  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 00503a8f  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00503a91  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00503a92  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00503a93  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00503a95  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00503a98  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00503a99  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00503a9a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00503a9b  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_503aa0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00503aa0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00503aa1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00503aa2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00503aa3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00503aa4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00503aa5  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00503aa8  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00503aaa  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00503aae  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00503ab1  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00503ab3  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00503ab7  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00503ab9  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00503abb  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 00503abe  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00503ac2  f7d3                   -not ebx
    cpu.ebx = ~cpu.ebx;
    // 00503ac4  8d7101                 -lea esi, [ecx + 1]
    cpu.esi = x86::reg32(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 00503ac7  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 00503acb  893424                 -mov dword ptr [esp], esi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.esi;
    // 00503ace  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00503ad0  7413                   -je 0x503ae5
    if (cpu.flags.zf)
    {
        goto L_0x00503ae5;
    }
    // 00503ad2  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 00503ad4  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00503ad6  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00503ad7  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00503ad8  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00503ada  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00503add  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00503ade  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00503adf  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00503ae0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00503ae1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00503ae2  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00503ae5:
    // 00503ae5  8d6b01                 -lea ebp, [ebx + 1]
    cpu.ebp = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 00503ae8  896c2404               -mov dword ptr [esp + 4], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 00503aec  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 00503aee  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00503af0  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00503af1  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00503af2  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00503af4  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00503af7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00503af8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00503af9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00503afa  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00503afb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00503afc  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x90 */
void Application::sub_503b00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00503b00  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00503b01  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00503b02  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00503b03  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00503b06  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00503b08  83fa20                 +cmp edx, 0x20
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
    // 00503b0b  7d29                   -jge 0x503b36
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00503b36;
    }
    // 00503b0d  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00503b0f  7433                   -je 0x503b44
    if (cpu.flags.zf)
    {
        goto L_0x00503b44;
    }
    // 00503b11  88d1                   -mov cl, dl
    cpu.cl = cpu.dl;
    // 00503b13  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00503b15  d3e6                   -shl esi, cl
    cpu.esi <<= cpu.cl % 32;
    // 00503b17  b920000000             -mov ecx, 0x20
    cpu.ecx = 32 /*0x20*/;
    // 00503b1c  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00503b1e  d3f8                   -sar eax, cl
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (cpu.cl % 32));
    // 00503b20  893424                 -mov dword ptr [esp], esi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.esi;
L_0x00503b23:
    // 00503b23  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00503b27  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 00503b29  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00503b2b  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00503b2c  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00503b2d  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00503b2f  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00503b32  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00503b33  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00503b34  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00503b35  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00503b36:
    // 00503b36  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00503b38  83ea20                 -sub edx, 0x20
    (cpu.edx) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00503b3b  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 00503b3e  88d1                   -mov cl, dl
    cpu.cl = cpu.dl;
    // 00503b40  d3e0                   +shl eax, cl
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
    // 00503b42  ebdf                   -jmp 0x503b23
    goto L_0x00503b23;
L_0x00503b44:
    // 00503b44  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00503b47  c1f81f                 -sar eax, 0x1f
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (31 /*0x1f*/ % 32));
    // 00503b4a  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00503b4e  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 00503b50  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00503b52  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00503b53  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00503b54  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00503b56  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00503b59  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00503b5a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00503b5b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00503b5c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_503b60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00503b60  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00503b61  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00503b62  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00503b63  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00503b64  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00503b67  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00503b69  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00503b6b  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00503b6c  8d742404               -lea esi, [esp + 4]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00503b70  ba10000000             -mov edx, 0x10
    cpu.edx = 16 /*0x10*/;
    // 00503b75  e886ffffff             -call 0x503b00
    cpu.esp -= 4;
    sub_503b00(app, cpu);
    if (cpu.terminate) return;
    // 00503b7a  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00503b7e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00503b7f  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00503b83  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00503b84  ba10000000             -mov edx, 0x10
    cpu.edx = 16 /*0x10*/;
    // 00503b89  e8d2fcffff             -call 0x503860
    cpu.esp -= 4;
    sub_503860(app, cpu);
    if (cpu.terminate) return;
    // 00503b8e  8d742408               -lea esi, [esp + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00503b92  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00503b93  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 00503b95  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00503b97  e864ffffff             -call 0x503b00
    cpu.esp -= 4;
    sub_503b00(app, cpu);
    if (cpu.terminate) return;
    // 00503b9c  8b7c2410               -mov edi, dword ptr [esp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00503ba0  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00503ba1  8b6c2410               -mov ebp, dword ptr [esp + 0x10]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00503ba5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00503ba6  e8f5fbffff             -call 0x5037a0
    cpu.esp -= 4;
    sub_5037a0(app, cpu);
    if (cpu.terminate) return;
    // 00503bab  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00503bae  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00503baf  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00503bb0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00503bb1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00503bb2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_503bc0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00503bc0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00503bc1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00503bc2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00503bc3  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00503bc5  8b1d00505600           -mov ebx, dword ptr [0x565000]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5656576) /* 0x565000 */);
    // 00503bcb  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00503bcd  39d9                   +cmp ecx, ebx
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
    // 00503bcf  0f8ca2000000           -jl 0x503c77
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00503c77;
    }
    // 00503bd5  3b0d08505600           +cmp ecx, dword ptr [0x565008]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5656584) /* 0x565008 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00503bdb  0f8d96000000           -jge 0x503c77
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00503c77;
    }
    // 00503be1  3b1504505600           +cmp edx, dword ptr [0x565004]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5656580) /* 0x565004 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00503be7  0f8c8a000000           -jl 0x503c77
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00503c77;
    }
    // 00503bed  3b150c505600           +cmp edx, dword ptr [0x56500c]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5656588) /* 0x56500c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00503bf3  0f8d7e000000           -jge 0x503c77
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00503c77;
    }
    // 00503bf9  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00503c00  8b1520505600           -mov edx, dword ptr [0x565020]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5656608) /* 0x565020 */);
    // 00503c06  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00503c08  8b1524505600           -mov edx, dword ptr [0x565024]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5656612) /* 0x565024 */);
    // 00503c0e  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00503c10  8b1c8a                 -mov ebx, dword ptr [edx + ecx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + cpu.ecx * 4);
    // 00503c13  8b1514505600           -mov edx, dword ptr [0x565014]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5656596) /* 0x565014 */);
    // 00503c19  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00503c1b  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00503c1d  a010505600             -mov al, byte ptr [0x565010]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5656592) /* 0x565010 */);
    // 00503c22  3c0f                   +cmp al, 0xf
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(15 /*0xf*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00503c24  7355                   -jae 0x503c7b
    if (!cpu.flags.cf)
    {
        goto L_0x00503c7b;
    }
    // 00503c26  3c04                   +cmp al, 4
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
    // 00503c28  0f836c000000           -jae 0x503c9a
    if (!cpu.flags.cf)
    {
        goto L_0x00503c9a;
    }
L_0x00503c2e:
    // 00503c2e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00503c2f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00503c30  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00503c32  beb8eb5400             -mov esi, 0x54ebb8
    cpu.esi = 5565368 /*0x54ebb8*/;
    // 00503c37  a010505600             -mov al, byte ptr [0x565010]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5656592) /* 0x565010 */);
    // 00503c3c  bfc8eb5400             -mov edi, 0x54ebc8
    cpu.edi = 5565384 /*0x54ebc8*/;
    // 00503c41  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00503c42  bd89000000             -mov ebp, 0x89
    cpu.ebp = 137 /*0x89*/;
    // 00503c47  893590215500           -mov dword ptr [0x552190], esi
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.esi;
    // 00503c4d  68d4eb5400             -push 0x54ebd4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5565396 /*0x54ebd4*/;
    cpu.esp -= 4;
    // 00503c52  893d94215500           -mov dword ptr [0x552194], edi
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.edi;
    // 00503c58  892d98215500           -mov dword ptr [0x552198], ebp
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ebp;
    // 00503c5e  e8add3efff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 00503c63  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00503c66  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00503c67  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00503c68:
    // 00503c68  f6c101                 +test cl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 1 /*0x1*/));
    // 00503c6b  743b                   -je 0x503ca8
    if (cpu.flags.zf)
    {
        goto L_0x00503ca8;
    }
    // 00503c6d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00503c6f  8a02                   -mov al, byte ptr [edx]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx);
    // 00503c71  c1f804                 -sar eax, 4
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (4 /*0x4*/ % 32));
    // 00503c74  83e00f                 +and eax, 0xf
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/))));
L_0x00503c77:
    // 00503c77  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00503c78  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00503c79  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00503c7a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00503c7b:
    // 00503c7b  7608                   -jbe 0x503c85
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00503c85;
    }
    // 00503c7d  3c18                   +cmp al, 0x18
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
    // 00503c7f  730d                   -jae 0x503c8e
    if (!cpu.flags.cf)
    {
        goto L_0x00503c8e;
    }
    // 00503c81  3c10                   +cmp al, 0x10
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
    // 00503c83  75a9                   -jne 0x503c2e
    if (!cpu.flags.zf)
    {
        goto L_0x00503c2e;
    }
L_0x00503c85:
    // 00503c85  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00503c87  668b02                 -mov ax, word ptr [edx]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edx);
    // 00503c8a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00503c8b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00503c8c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00503c8d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00503c8e:
    // 00503c8e  7623                   -jbe 0x503cb3
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00503cb3;
    }
    // 00503c90  3c20                   +cmp al, 0x20
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
    // 00503c92  759a                   -jne 0x503c2e
    if (!cpu.flags.zf)
    {
        goto L_0x00503c2e;
    }
    // 00503c94  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 00503c96  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00503c97  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00503c98  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00503c99  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00503c9a:
    // 00503c9a  76cc                   -jbe 0x503c68
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00503c68;
    }
    // 00503c9c  3c08                   +cmp al, 8
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(8 /*0x8*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00503c9e  758e                   -jne 0x503c2e
    if (!cpu.flags.zf)
    {
        goto L_0x00503c2e;
    }
    // 00503ca0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00503ca2  8a02                   -mov al, byte ptr [edx]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx);
    // 00503ca4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00503ca5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00503ca6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00503ca7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00503ca8:
    // 00503ca8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00503caa  8a02                   -mov al, byte ptr [edx]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx);
    // 00503cac  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00503caf  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00503cb0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00503cb1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00503cb2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00503cb3:
    // 00503cb3  b903000000             -mov ecx, 3
    cpu.ecx = 3 /*0x3*/;
    // 00503cb8  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00503cba  8b4401fc               -mov eax, dword ptr [ecx + eax - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-4) /* -0x4 */ + cpu.eax * 1);
    // 00503cbe  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 00503cc0  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 00503cc7  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 00503cc9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00503cca  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00503ccb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00503ccc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_503cd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00503cd0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00503cd1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00503cd2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00503cd3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00503cd4  81ec80000000           -sub esp, 0x80
    (cpu.esp) -= x86::reg32(x86::sreg32(128 /*0x80*/));
    // 00503cda  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00503cdc  8954247c               -mov dword ptr [esp + 0x7c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(124) /* 0x7c */) = cpu.edx;
    // 00503ce0  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 00503ce2  ff05e4435600           -inc dword ptr [0x5643e4]
    (app->getMemory<x86::reg32>(x86::reg32(5653476) /* 0x5643e4 */))++;
    // 00503ce8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00503cea  7505                   -jne 0x503cf1
    if (!cpu.flags.zf)
    {
        goto L_0x00503cf1;
    }
    // 00503cec  bdd0389f00             -mov ebp, 0x9f38d0
    cpu.ebp = 10434768 /*0x9f38d0*/;
L_0x00503cf1:
    // 00503cf1  833d6443560007         +cmp dword ptr [0x564364], 7
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5653348) /* 0x564364 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(7 /*0x7*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00503cf8  0f8529010000           -jne 0x503e27
    if (!cpu.flags.zf)
    {
        goto L_0x00503e27;
    }
    // 00503cfe  837d1c08               +cmp dword ptr [ebp + 0x1c], 8
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00503d02  0f8f1f010000           -jg 0x503e27
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00503e27;
    }
    // 00503d08  8b44247c               -mov eax, dword ptr [esp + 0x7c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(124) /* 0x7c */);
    // 00503d0c  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 00503d0e  48                     -dec eax
    (cpu.eax)--;
    // 00503d0f  8bbd3c040000           -mov edi, dword ptr [ebp + 0x43c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(1084) /* 0x43c */);
    // 00503d15  89442478               -mov dword ptr [esp + 0x78], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(120) /* 0x78 */) = cpu.eax;
    // 00503d19  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00503d1b  0f8411010000           -je 0x503e32
    if (cpu.flags.zf)
    {
        goto L_0x00503e32;
    }
    // 00503d21  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x00503d26:
    // 00503d26  89442470               -mov dword ptr [esp + 0x70], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(112) /* 0x70 */) = cpu.eax;
    // 00503d2a  8b44247c               -mov eax, dword ptr [esp + 0x7c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(124) /* 0x7c */);
    // 00503d2e  8d5530                 -lea edx, [ebp + 0x30]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(48) /* 0x30 */);
    // 00503d31  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00503d34  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00503d36  8d1c02                 -lea ebx, [edx + eax]
    cpu.ebx = x86::reg32(cpu.edx + cpu.eax * 1);
    // 00503d39  0514a8a000             -add eax, 0xa0a814
    (cpu.eax) += x86::reg32(x86::sreg32(10528788 /*0xa0a814*/));
    // 00503d3e  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00503d40  7e2e                   -jle 0x503d70
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00503d70;
    }
    // 00503d42  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
L_0x00503d44:
    // 00503d44  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00503d46  8a5801                 -mov bl, byte ptr [eax + 1]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00503d49  0fb67802               -movzx edi, byte ptr [eax + 2]
    cpu.edi = x86::reg32(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */));
    // 00503d4d  c1e308                 -shl ebx, 8
    cpu.ebx <<= 8 /*0x8*/ % 32;
    // 00503d50  09df                   -or edi, ebx
    cpu.edi |= x86::reg32(x86::sreg32(cpu.ebx));
    // 00503d52  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00503d54  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 00503d56  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00503d59  c1e310                 -shl ebx, 0x10
    cpu.ebx <<= 16 /*0x10*/ % 32;
    // 00503d5c  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00503d5f  09fb                   -or ebx, edi
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.edi));
    // 00503d61  41                     -inc ecx
    (cpu.ecx)++;
    // 00503d62  895afc                 -mov dword ptr [edx - 4], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */) = cpu.ebx;
    // 00503d65  39f1                   +cmp ecx, esi
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
    // 00503d67  7cdb                   -jl 0x503d44
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00503d44;
    }
    // 00503d69  8d8000000000           -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 00503d6f  90                     -nop 
    ;
L_0x00503d70:
    // 00503d70  8b852e040000           -mov eax, dword ptr [ebp + 0x42e]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(1070) /* 0x42e */);
    // 00503d76  8b54247c               -mov edx, dword ptr [esp + 0x7c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(124) /* 0x7c */);
    // 00503d7a  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00503d7d  39d0                   +cmp eax, edx
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
    // 00503d7f  7e0b                   -jle 0x503d8c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00503d8c;
    }
    // 00503d81  8b44247c               -mov eax, dword ptr [esp + 0x7c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(124) /* 0x7c */);
    // 00503d85  66898530040000         -mov word ptr [ebp + 0x430], ax
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(1072) /* 0x430 */) = cpu.ax;
L_0x00503d8c:
    // 00503d8c  8b8530040000           -mov eax, dword ptr [ebp + 0x430]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(1072) /* 0x430 */);
    // 00503d92  8b4c2478               -mov ecx, dword ptr [esp + 0x78]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 00503d96  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00503d99  39c8                   +cmp eax, ecx
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
    // 00503d9b  7d0b                   -jge 0x503da8
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00503da8;
    }
    // 00503d9d  8b442478               -mov eax, dword ptr [esp + 0x78]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 00503da1  66898532040000         -mov word ptr [ebp + 0x432], ax
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(1074) /* 0x432 */) = cpu.ax;
L_0x00503da8:
    // 00503da8  837c247000             +cmp dword ptr [esp + 0x70], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(112) /* 0x70 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00503dad  740c                   -je 0x503dbb
    if (cpu.flags.zf)
    {
        goto L_0x00503dbb;
    }
    // 00503daf  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00503db1  e81a09ffff             -call 0x4f46d0
    cpu.esp -= 4;
    sub_4f46d0(app, cpu);
    if (cpu.terminate) return;
    // 00503db6  e8d56ffeff             -call 0x4ead90
    cpu.esp -= 4;
    sub_4ead90(app, cpu);
    if (cpu.terminate) return;
L_0x00503dbb:
    // 00503dbb  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00503dbd  e89e91feff             -call 0x4ecf60
    cpu.esp -= 4;
    sub_4ecf60(app, cpu);
    if (cpu.terminate) return;
    // 00503dc2  80bd5d04000000         +cmp byte ptr [ebp + 0x45d], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(1117) /* 0x45d */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00503dc9  7555                   -jne 0x503e20
    if (!cpu.flags.zf)
    {
        goto L_0x00503e20;
    }
    // 00503dcb  8b44247c               -mov eax, dword ptr [esp + 0x7c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(124) /* 0x7c */);
    // 00503dcf  8d5530                 -lea edx, [ebp + 0x30]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(48) /* 0x30 */);
    // 00503dd2  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00503dd5  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00503dd7  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00503dd9  0514a8a000             -add eax, 0xa0a814
    (cpu.eax) += x86::reg32(x86::sreg32(10528788 /*0xa0a814*/));
    // 00503dde  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00503de0  7e3e                   -jle 0x503e20
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00503e20;
    }
L_0x00503de2:
    // 00503de2  8a1a                   -mov bl, byte ptr [edx]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx);
    // 00503de4  885802                 -mov byte ptr [eax + 2], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */) = cpu.bl;
    // 00503de7  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 00503de9  c1eb08                 -shr ebx, 8
    cpu.ebx >>= 8 /*0x8*/ % 32;
    // 00503dec  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00503df2  895c2474               -mov dword ptr [esp + 0x74], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */) = cpu.ebx;
    // 00503df6  8a5c2474               -mov bl, byte ptr [esp + 0x74]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(116) /* 0x74 */);
    // 00503dfa  885801                 -mov byte ptr [eax + 1], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */) = cpu.bl;
    // 00503dfd  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 00503dff  c1eb10                 -shr ebx, 0x10
    cpu.ebx >>= 16 /*0x10*/ % 32;
    // 00503e02  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00503e08  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00503e0b  895c2474               -mov dword ptr [esp + 0x74], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */) = cpu.ebx;
    // 00503e0f  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00503e12  8a5c2474               -mov bl, byte ptr [esp + 0x74]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(116) /* 0x74 */);
    // 00503e16  41                     -inc ecx
    (cpu.ecx)++;
    // 00503e17  8858fc                 -mov byte ptr [eax - 4], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.bl;
    // 00503e1a  39f1                   +cmp ecx, esi
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
    // 00503e1c  7cc4                   -jl 0x503de2
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00503de2;
    }
    // 00503e1e  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x00503e20:
    // 00503e20  837c247000             +cmp dword ptr [esp + 0x70], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(112) /* 0x70 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00503e25  7512                   -jne 0x503e39
    if (!cpu.flags.zf)
    {
        goto L_0x00503e39;
    }
L_0x00503e27:
    // 00503e27  81c480000000           -add esp, 0x80
    (cpu.esp) += x86::reg32(x86::sreg32(128 /*0x80*/));
    // 00503e2d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00503e2e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00503e2f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00503e30  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00503e31  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00503e32:
    // 00503e32  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00503e34  e9edfeffff             -jmp 0x503d26
    goto L_0x00503d26;
L_0x00503e39:
    // 00503e39  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00503e3b  e8c008ffff             -call 0x4f4700
    cpu.esp -= 4;
    sub_4f4700(app, cpu);
    if (cpu.terminate) return;
    // 00503e40  81c480000000           -add esp, 0x80
    (cpu.esp) += x86::reg32(x86::sreg32(128 /*0x80*/));
    // 00503e46  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00503e47  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00503e48  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00503e49  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00503e4a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_503e50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00503e50  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00503e51  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00503e52  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00503e54  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00503e56  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00503e58  8d14b500000000         -lea edx, [esi*4]
    cpu.edx = x86::reg32(cpu.esi * 4);
    // 00503e5f  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00503e61  81c214a8a000           -add edx, 0xa0a814
    (cpu.edx) += x86::reg32(x86::sreg32(10528788 /*0xa0a814*/));
    // 00503e67  e8f1030000             -call 0x50425d
    cpu.esp -= 4;
    sub_50425d(app, cpu);
    if (cpu.terminate) return;
    // 00503e6c  b8d0389f00             -mov eax, 0x9f38d0
    cpu.eax = 10434768 /*0x9f38d0*/;
    // 00503e71  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00503e73  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00503e75  e856feffff             -call 0x503cd0
    cpu.esp -= 4;
    sub_503cd0(app, cpu);
    if (cpu.terminate) return;
    // 00503e7a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00503e7b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00503e7c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_503e80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00503e80  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00503e81  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00503e82  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00503e84  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00503e86  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00503e88  8d1c9500000000         -lea ebx, [edx*4]
    cpu.ebx = x86::reg32(cpu.edx * 4);
    // 00503e8f  8d148d00000000         -lea edx, [ecx*4]
    cpu.edx = x86::reg32(cpu.ecx * 4);
    // 00503e96  81c214a8a000           -add edx, 0xa0a814
    (cpu.edx) += x86::reg32(x86::sreg32(10528788 /*0xa0a814*/));
    // 00503e9c  e84f66feff             -call 0x4ea4f0
    cpu.esp -= 4;
    sub_4ea4f0(app, cpu);
    if (cpu.terminate) return;
    // 00503ea1  b8d0389f00             -mov eax, 0x9f38d0
    cpu.eax = 10434768 /*0x9f38d0*/;
    // 00503ea6  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00503ea8  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00503eaa  e821feffff             -call 0x503cd0
    cpu.esp -= 4;
    sub_503cd0(app, cpu);
    if (cpu.terminate) return;
    // 00503eaf  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00503eb0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00503eb1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_503ec0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00503ec0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00503ec1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00503ec2  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00503ec4  b914a8a000             -mov ecx, 0xa0a814
    cpu.ecx = 10528788 /*0xa0a814*/;
    // 00503ec9  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00503ecc  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00503ece  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00503ed0  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00503ed2  7e2c                   -jle 0x503f00
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00503f00;
    }
    // 00503ed4  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
L_0x00503ed6:
    // 00503ed6  43                     -inc ebx
    (cpu.ebx)++;
    // 00503ed7  8a4802                 -mov cl, byte ptr [eax + 2]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 00503eda  884bff                 -mov byte ptr [ebx - 1], cl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(-1) /* -0x1 */) = cpu.cl;
    // 00503edd  43                     -inc ebx
    (cpu.ebx)++;
    // 00503ede  8a4801                 -mov cl, byte ptr [eax + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00503ee1  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00503ee4  884bff                 -mov byte ptr [ebx - 1], cl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(-1) /* -0x1 */) = cpu.cl;
    // 00503ee7  43                     -inc ebx
    (cpu.ebx)++;
    // 00503ee8  8a48fc                 -mov cl, byte ptr [eax - 4]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(-4) /* -0x4 */);
    // 00503eeb  42                     -inc edx
    (cpu.edx)++;
    // 00503eec  884bff                 -mov byte ptr [ebx - 1], cl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(-1) /* -0x1 */) = cpu.cl;
    // 00503eef  39f2                   +cmp edx, esi
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
    // 00503ef1  7ce3                   -jl 0x503ed6
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00503ed6;
    }
    // 00503ef3  8d8000000000           -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 00503ef9  8d9200000000           -lea edx, [edx]
    cpu.edx = x86::reg32(cpu.edx);
    // 00503eff  90                     -nop 
    ;
L_0x00503f00:
    // 00503f00  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00503f01  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00503f02  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_503f10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00503f10  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00503f11  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00503f12  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00503f14  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00503f16  b914a8a000             -mov ecx, 0xa0a814
    cpu.ecx = 10528788 /*0xa0a814*/;
    // 00503f1b  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00503f1e  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00503f20  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00503f22  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00503f24  7e1a                   -jle 0x503f40
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00503f40;
    }
L_0x00503f26:
    // 00503f26  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00503f29  8b19                   -mov ebx, dword ptr [ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx);
    // 00503f2b  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00503f2e  40                     -inc eax
    (cpu.eax)++;
    // 00503f2f  895afc                 -mov dword ptr [edx - 4], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */) = cpu.ebx;
    // 00503f32  39f0                   +cmp eax, esi
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
    // 00503f34  7cf0                   -jl 0x503f26
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00503f26;
    }
    // 00503f36  8d8000000000           -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 00503f3c  8d542200               -lea edx, [edx]
    cpu.edx = x86::reg32(cpu.edx);
L_0x00503f40:
    // 00503f40  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00503f41  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00503f42  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_503f50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00503f50  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00503f51  ba00ec5400             -mov edx, 0x54ec00
    cpu.edx = 5565440 /*0x54ec00*/;
    // 00503f56  b910ec5400             -mov ecx, 0x54ec10
    cpu.ecx = 5565456 /*0x54ec10*/;
    // 00503f5b  bb17010000             -mov ebx, 0x117
    cpu.ebx = 279 /*0x117*/;
    // 00503f60  6820ec5400             -push 0x54ec20
    app->getMemory<x86::reg32>(cpu.esp-4) = 5565472 /*0x54ec20*/;
    cpu.esp -= 4;
    // 00503f65  891590215500           -mov dword ptr [0x552190], edx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edx;
    // 00503f6b  890d94215500           -mov dword ptr [0x552194], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ecx;
    // 00503f71  891d98215500           -mov dword ptr [0x552198], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ebx;
    // 00503f77  e894d0efff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 00503f7c  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00503f7f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00503f80  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_503f90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00503f90  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00503f91  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00503f92  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00503f93  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00503f94  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00503f97  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00503f9b  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00503f9f  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00503fa3  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 00503fa5  8d148500000000         -lea edx, [eax*4]
    cpu.edx = x86::reg32(cpu.eax * 4);
    // 00503fac  49                     -dec ecx
    (cpu.ecx)--;
    // 00503fad  8b7c240c               -mov edi, dword ptr [esp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00503fb1  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00503fb3  01f9                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 00503fb5  8d3407                 -lea esi, [edi + eax]
    cpu.esi = x86::reg32(cpu.edi + cpu.eax * 1);
    // 00503fb8  81c214a8a000           -add edx, 0xa0a814
    (cpu.edx) += x86::reg32(x86::sreg32(10528788 /*0xa0a814*/));
    // 00503fbe  89742410               -mov dword ptr [esp + 0x10], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.esi;
L_0x00503fc2:
    // 00503fc2  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00503fc6  41                     -inc ecx
    (cpu.ecx)++;
    // 00503fc7  39c1                   +cmp ecx, eax
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
    // 00503fc9  0f84cf000000           -je 0x50409e
    if (cpu.flags.zf)
    {
        goto L_0x0050409e;
    }
    // 00503fcf  0fb62b                 -movzx ebp, byte ptr [ebx]
    cpu.ebp = x86::reg32(app->getMemory<x86::reg8>(cpu.ebx));
    // 00503fd2  8d04ad00000000         -lea eax, [ebp*4]
    cpu.eax = x86::reg32(cpu.ebp * 4);
    // 00503fd9  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00503fdd  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00503fdf  c1f804                 -sar eax, 4
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (4 /*0x4*/ % 32));
    // 00503fe2  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00503fe5  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00503fe9  0b0424                 -or eax, dword ptr [esp]
    cpu.eax |= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp)));
    // 00503fec  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00503fef  0fb67b01               -movzx edi, byte ptr [ebx + 1]
    cpu.edi = x86::reg32(app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(1) /* 0x1 */));
    // 00503ff3  8a0424                 -mov al, byte ptr [esp]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp);
    // 00503ff6  0fb67302               -movzx esi, byte ptr [ebx + 2]
    cpu.esi = x86::reg32(app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(2) /* 0x2 */));
    // 00503ffa  884202                 -mov byte ptr [edx + 2], al
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(2) /* 0x2 */) = cpu.al;
    // 00503ffd  8d04bd00000000         -lea eax, [edi*4]
    cpu.eax = x86::reg32(cpu.edi * 4);
    // 00504004  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00504008  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0050400a  c1f804                 -sar eax, 4
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (4 /*0x4*/ % 32));
    // 0050400d  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00504010  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00504014  0b0424                 -or eax, dword ptr [esp]
    cpu.eax |= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp)));
    // 00504017  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0050401a  8a0424                 -mov al, byte ptr [esp]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp);
    // 0050401d  884201                 -mov byte ptr [edx + 1], al
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00504020  8d04b500000000         -lea eax, [esi*4]
    cpu.eax = x86::reg32(cpu.esi * 4);
    // 00504027  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0050402a  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0050402c  c1f804                 -sar eax, 4
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (4 /*0x4*/ % 32));
    // 0050402f  43                     -inc ebx
    (cpu.ebx)++;
    // 00504030  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00504034  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00504037  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0050403a  0b442404               -or eax, dword ptr [esp + 4]
    cpu.eax |= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 0050403e  43                     -inc ebx
    (cpu.ebx)++;
    // 0050403f  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00504042  c642ffff               -mov byte ptr [edx - 1], 0xff
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-1) /* -0x1 */) = 255 /*0xff*/;
    // 00504046  8a0424                 -mov al, byte ptr [esp]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp);
    // 00504049  43                     -inc ebx
    (cpu.ebx)++;
    // 0050404a  8842fc                 -mov byte ptr [edx - 4], al
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-4) /* -0x4 */) = cpu.al;
    // 0050404d  81fdff000000           +cmp ebp, 0xff
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(255 /*0xff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00504053  7e34                   -jle 0x504089
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00504089;
    }
L_0x00504055:
    // 00504055  be00ec5400             -mov esi, 0x54ec00
    cpu.esi = 5565440 /*0x54ec00*/;
    // 0050405a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050405b  bf70ec5400             -mov edi, 0x54ec70
    cpu.edi = 5565552 /*0x54ec70*/;
    // 00504060  bd2d010000             -mov ebp, 0x12d
    cpu.ebp = 301 /*0x12d*/;
    // 00504065  687cec5400             -push 0x54ec7c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5565564 /*0x54ec7c*/;
    cpu.esp -= 4;
    // 0050406a  893590215500           -mov dword ptr [0x552190], esi
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.esi;
    // 00504070  893d94215500           -mov dword ptr [0x552194], edi
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.edi;
    // 00504076  892d98215500           -mov dword ptr [0x552198], ebp
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ebp;
    // 0050407c  e88fcfefff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 00504081  83c408                 +add esp, 8
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
    // 00504084  e939ffffff             -jmp 0x503fc2
    goto L_0x00503fc2;
L_0x00504089:
    // 00504089  81ffff000000           +cmp edi, 0xff
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
    // 0050408f  7fc4                   -jg 0x504055
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00504055;
    }
    // 00504091  81feff000000           +cmp esi, 0xff
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(255 /*0xff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00504097  7fbc                   -jg 0x504055
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00504055;
    }
    // 00504099  e924ffffff             -jmp 0x503fc2
    goto L_0x00503fc2;
L_0x0050409e:
    // 0050409e  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 005040a2  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 005040a6  b8d0389f00             -mov eax, 0x9f38d0
    cpu.eax = 10434768 /*0x9f38d0*/;
    // 005040ab  e820fcffff             -call 0x503cd0
    cpu.esp -= 4;
    sub_503cd0(app, cpu);
    if (cpu.terminate) return;
    // 005040b0  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 005040b3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005040b4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005040b5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005040b6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005040b7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_5040b8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005040b8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005040b9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005040ba  f7c202000000           +test edx, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 2 /*0x2*/));
    // 005040c0  7423                   -je 0x5040e5
    if (cpu.flags.zf)
    {
        goto L_0x005040e5;
    }
    // 005040c2  83fb01                 +cmp ebx, 1
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
    // 005040c5  7c1e                   -jl 0x5040e5
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x005040e5;
    }
    // 005040c7  668b08                 -mov cx, word ptr [eax]
    cpu.cx = app->getMemory<x86::reg16>(cpu.eax);
    // 005040ca  8d4002                 -lea eax, [eax + 2]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 005040cd  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 005040cf  81e1c0ff0000           -and ecx, 0xffc0
    cpu.ecx &= x86::reg32(x86::sreg32(65472 /*0xffc0*/));
    // 005040d5  d1e9                   -shr ecx, 1
    cpu.ecx >>= 1 /*0x1*/ % 32;
    // 005040d7  83e61f                 -and esi, 0x1f
    cpu.esi &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 005040da  09f1                   -or ecx, esi
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.esi));
    // 005040dc  83eb01                 -sub ebx, 1
    (cpu.ebx) -= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 005040df  66890a                 -mov word ptr [edx], cx
    app->getMemory<x86::reg16>(cpu.edx) = cpu.cx;
    // 005040e2  8d5202                 -lea edx, [edx + 2]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(2) /* 0x2 */);
L_0x005040e5:
    // 005040e5  83eb02                 +sub ebx, 2
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 005040e8  7821                   -js 0x50410b
    if (cpu.flags.sf)
    {
        goto L_0x0050410b;
    }
L_0x005040ea:
    // 005040ea  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 005040ec  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 005040ef  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 005040f1  81e1c0ffc0ff           -and ecx, 0xffc0ffc0
    cpu.ecx &= x86::reg32(x86::sreg32(4290838464 /*0xffc0ffc0*/));
    // 005040f7  d1e9                   -shr ecx, 1
    cpu.ecx >>= 1 /*0x1*/ % 32;
    // 005040f9  81e61f001f00           -and esi, 0x1f001f
    cpu.esi &= x86::reg32(x86::sreg32(2031647 /*0x1f001f*/));
    // 005040ff  09f1                   -or ecx, esi
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.esi));
    // 00504101  83eb02                 +sub ebx, 2
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00504104  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 00504106  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00504109  79df                   -jns 0x5040ea
    if (!cpu.flags.sf)
    {
        goto L_0x005040ea;
    }
L_0x0050410b:
    // 0050410b  83c301                 +add ebx, 1
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0050410e  7820                   -js 0x504130
    if (cpu.flags.sf)
    {
        goto L_0x00504130;
    }
L_0x00504110:
    // 00504110  668b08                 -mov cx, word ptr [eax]
    cpu.cx = app->getMemory<x86::reg16>(cpu.eax);
    // 00504113  8d4002                 -lea eax, [eax + 2]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 00504116  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00504118  81e1c0ff0000           -and ecx, 0xffc0
    cpu.ecx &= x86::reg32(x86::sreg32(65472 /*0xffc0*/));
    // 0050411e  d1e9                   -shr ecx, 1
    cpu.ecx >>= 1 /*0x1*/ % 32;
    // 00504120  83e61f                 -and esi, 0x1f
    cpu.esi &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00504123  09f1                   -or ecx, esi
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.esi));
    // 00504125  83eb01                 +sub ebx, 1
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00504128  66890a                 -mov word ptr [edx], cx
    app->getMemory<x86::reg16>(cpu.edx) = cpu.cx;
    // 0050412b  8d5202                 -lea edx, [edx + 2]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 0050412e  79e0                   -jns 0x504110
    if (!cpu.flags.sf)
    {
        goto L_0x00504110;
    }
L_0x00504130:
    // 00504130  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00504131  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00504132  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_504133(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00504133  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00504134  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00504135  f7c202000000           +test edx, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 2 /*0x2*/));
    // 0050413b  7423                   -je 0x504160
    if (cpu.flags.zf)
    {
        goto L_0x00504160;
    }
    // 0050413d  83fb01                 +cmp ebx, 1
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
    // 00504140  7c1e                   -jl 0x504160
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00504160;
    }
    // 00504142  668b08                 -mov cx, word ptr [eax]
    cpu.cx = app->getMemory<x86::reg16>(cpu.eax);
    // 00504145  8d4002                 -lea eax, [eax + 2]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 00504148  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0050414a  81e1e07f0000           -and ecx, 0x7fe0
    cpu.ecx &= x86::reg32(x86::sreg32(32736 /*0x7fe0*/));
    // 00504150  01c9                   -add ecx, ecx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00504152  83e61f                 -and esi, 0x1f
    cpu.esi &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00504155  09f1                   -or ecx, esi
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.esi));
    // 00504157  83eb01                 -sub ebx, 1
    (cpu.ebx) -= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 0050415a  66890a                 -mov word ptr [edx], cx
    app->getMemory<x86::reg16>(cpu.edx) = cpu.cx;
    // 0050415d  8d5202                 -lea edx, [edx + 2]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(2) /* 0x2 */);
L_0x00504160:
    // 00504160  83eb02                 +sub ebx, 2
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00504163  7821                   -js 0x504186
    if (cpu.flags.sf)
    {
        goto L_0x00504186;
    }
L_0x00504165:
    // 00504165  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 00504167  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0050416a  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0050416c  81e1e07fe07f           -and ecx, 0x7fe07fe0
    cpu.ecx &= x86::reg32(x86::sreg32(2145419232 /*0x7fe07fe0*/));
    // 00504172  01c9                   -add ecx, ecx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00504174  81e61f001f00           -and esi, 0x1f001f
    cpu.esi &= x86::reg32(x86::sreg32(2031647 /*0x1f001f*/));
    // 0050417a  09f1                   -or ecx, esi
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.esi));
    // 0050417c  83eb02                 +sub ebx, 2
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0050417f  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 00504181  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00504184  79df                   -jns 0x504165
    if (!cpu.flags.sf)
    {
        goto L_0x00504165;
    }
L_0x00504186:
    // 00504186  83c301                 +add ebx, 1
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00504189  7820                   -js 0x5041ab
    if (cpu.flags.sf)
    {
        goto L_0x005041ab;
    }
L_0x0050418b:
    // 0050418b  668b08                 -mov cx, word ptr [eax]
    cpu.cx = app->getMemory<x86::reg16>(cpu.eax);
    // 0050418e  8d4002                 -lea eax, [eax + 2]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 00504191  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00504193  81e1e07f0000           -and ecx, 0x7fe0
    cpu.ecx &= x86::reg32(x86::sreg32(32736 /*0x7fe0*/));
    // 00504199  01c9                   -add ecx, ecx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0050419b  83e61f                 -and esi, 0x1f
    cpu.esi &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 0050419e  09f1                   -or ecx, esi
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.esi));
    // 005041a0  83eb01                 +sub ebx, 1
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 005041a3  66890a                 -mov word ptr [edx], cx
    app->getMemory<x86::reg16>(cpu.edx) = cpu.cx;
    // 005041a6  8d5202                 -lea edx, [edx + 2]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 005041a9  79e0                   -jns 0x50418b
    if (!cpu.flags.sf)
    {
        goto L_0x0050418b;
    }
L_0x005041ab:
    // 005041ab  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005041ac  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005041ad  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_5041ae(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005041ae  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005041af  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005041b0  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 005041b1  8b3d90835600           -mov edi, dword ptr [0x568390]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5669776) /* 0x568390 */);
    // 005041b7  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x005041b9:
    // 005041b9  8a08                   -mov cl, byte ptr [eax]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax);
    // 005041bb  83eb01                 +sub ebx, 1
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 005041be  8d4001                 -lea eax, [eax + 1]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 005041c1  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 005041c4  8b348f                 -mov esi, dword ptr [edi + ecx*4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edi + cpu.ecx * 4);
    // 005041c7  8972fc                 -mov dword ptr [edx - 4], esi
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */) = cpu.esi;
    // 005041ca  7fed                   -jg 0x5041b9
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x005041b9;
    }
    // 005041cc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005041cd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005041ce  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005041cf  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_5041d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005041d0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005041d1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005041d2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 005041d3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005041d4  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 005041d6  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 005041d8  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 005041da  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 005041dc  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 005041de  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 005041e0  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 005041e2  83ed04                 -sub ebp, 4
    (cpu.ebp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 005041e5  f7c702000000           +test edi, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & 2 /*0x2*/));
    // 005041eb  754e                   -jne 0x50423b
    if (!cpu.flags.zf)
    {
        goto L_0x0050423b;
    }
    // 005041ed  83fd00                 +cmp ebp, 0
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005041f0  7849                   -js 0x50423b
    if (cpu.flags.sf)
    {
        goto L_0x0050423b;
    }
    // 005041f2  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 005041f5  8a1e                   -mov bl, byte ptr [esi]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esi);
    // 005041f7  8a4e03                 -mov cl, byte ptr [esi + 3]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(3) /* 0x3 */);
    // 005041fa  8a5602                 -mov dl, byte ptr [esi + 2]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */);
L_0x005041fd:
    // 005041fd  8b044512aca000         -mov eax, dword ptr [eax*2 + 0xa0ac12]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10529810) /* 0xa0ac12 */ + cpu.eax * 2);
    // 00504204  8d7604                 -lea esi, [esi + 4]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00504207  8b0c4d12aca000         -mov ecx, dword ptr [ecx*2 + 0xa0ac12]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10529810) /* 0xa0ac12 */ + cpu.ecx * 2);
    // 0050420e  8d7f08                 -lea edi, [edi + 8]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 00504211  668b045d14aca000       -mov ax, word ptr [ebx*2 + 0xa0ac14]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(10529812) /* 0xa0ac14 */ + cpu.ebx * 2);
    // 00504219  8a1e                   -mov bl, byte ptr [esi]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esi);
    // 0050421b  668b0c5514aca000       -mov cx, word ptr [edx*2 + 0xa0ac14]
    cpu.cx = app->getMemory<x86::reg16>(x86::reg32(10529812) /* 0xa0ac14 */ + cpu.edx * 2);
    // 00504223  8a5602                 -mov dl, byte ptr [esi + 2]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 00504226  8947f8                 -mov dword ptr [edi - 8], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 00504229  894ffc                 -mov dword ptr [edi - 4], ecx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
    // 0050422c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0050422e  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00504230  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00504233  83ed04                 +sub ebp, 4
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00504236  8a4e03                 -mov cl, byte ptr [esi + 3]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(3) /* 0x3 */);
    // 00504239  79c2                   -jns 0x5041fd
    if (!cpu.flags.sf)
    {
        goto L_0x005041fd;
    }
L_0x0050423b:
    // 0050423b  83c503                 +add ebp, 3
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0050423e  7818                   -js 0x504258
    if (cpu.flags.sf)
    {
        goto L_0x00504258;
    }
L_0x00504240:
    // 00504240  8a16                   -mov dl, byte ptr [esi]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi);
    // 00504242  8d7601                 -lea esi, [esi + 1]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00504245  668b045514aca000       -mov ax, word ptr [edx*2 + 0xa0ac14]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(10529812) /* 0xa0ac14 */ + cpu.edx * 2);
    // 0050424d  668907                 -mov word ptr [edi], ax
    app->getMemory<x86::reg16>(cpu.edi) = cpu.ax;
    // 00504250  8d7f02                 -lea edi, [edi + 2]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(2) /* 0x2 */);
    // 00504253  83ed01                 +sub ebp, 1
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00504256  79e8                   -jns 0x504240
    if (!cpu.flags.sf)
    {
        goto L_0x00504240;
    }
L_0x00504258:
    // 00504258  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00504259  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050425a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050425b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050425c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_50425d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0050425d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050425e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050425f  8d70ff                 -lea esi, [eax - 1]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(-1) /* -0x1 */);
    // 00504262  83eb04                 +sub ebx, 4
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
    // 00504265  783f                   -js 0x5042a6
    if (cpu.flags.sf)
    {
        goto L_0x005042a6;
    }
L_0x00504267:
    // 00504267  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00504269  8b4e03                 -mov ecx, dword ptr [esi + 3]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(3) /* 0x3 */);
    // 0050426c  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 0050426e  0fc9                   -bswap ecx
    {
        x86::reg32& tmp = cpu.ecx;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 00504270  0d000000ff             -or eax, 0xff000000
    cpu.eax |= x86::reg32(x86::sreg32(4278190080 /*0xff000000*/));
    // 00504275  81c9000000ff           -or ecx, 0xff000000
    cpu.ecx |= x86::reg32(x86::sreg32(4278190080 /*0xff000000*/));
    // 0050427b  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 0050427d  894a04                 -mov dword ptr [edx + 4], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 00504280  8b4606                 -mov eax, dword ptr [esi + 6]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(6) /* 0x6 */);
    // 00504283  8b4e09                 -mov ecx, dword ptr [esi + 9]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(9) /* 0x9 */);
    // 00504286  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 00504288  0fc9                   -bswap ecx
    {
        x86::reg32& tmp = cpu.ecx;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 0050428a  0d000000ff             -or eax, 0xff000000
    cpu.eax |= x86::reg32(x86::sreg32(4278190080 /*0xff000000*/));
    // 0050428f  81c9000000ff           -or ecx, 0xff000000
    cpu.ecx |= x86::reg32(x86::sreg32(4278190080 /*0xff000000*/));
    // 00504295  894208                 -mov dword ptr [edx + 8], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00504298  894a0c                 -mov dword ptr [edx + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 0050429b  83eb04                 +sub ebx, 4
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
    // 0050429e  8d760c                 -lea esi, [esi + 0xc]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(12) /* 0xc */);
    // 005042a1  8d5210                 -lea edx, [edx + 0x10]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 005042a4  79c1                   -jns 0x504267
    if (!cpu.flags.sf)
    {
        goto L_0x00504267;
    }
L_0x005042a6:
    // 005042a6  83c303                 +add ebx, 3
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 005042a9  7816                   -js 0x5042c1
    if (cpu.flags.sf)
    {
        goto L_0x005042c1;
    }
L_0x005042ab:
    // 005042ab  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 005042ad  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 005042af  0d000000ff             -or eax, 0xff000000
    cpu.eax |= x86::reg32(x86::sreg32(4278190080 /*0xff000000*/));
    // 005042b4  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 005042b6  83eb01                 +sub ebx, 1
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 005042b9  8d7603                 -lea esi, [esi + 3]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(3) /* 0x3 */);
    // 005042bc  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 005042bf  79ea                   -jns 0x5042ab
    if (!cpu.flags.sf)
    {
        goto L_0x005042ab;
    }
L_0x005042c1:
    // 005042c1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005042c2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005042c3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_5042c4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005042c4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005042c5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005042c6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 005042c7  83eb02                 +sub ebx, 2
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 005042ca  782f                   -js 0x5042fb
    if (cpu.flags.sf)
    {
        goto L_0x005042fb;
    }
L_0x005042cc:
    // 005042cc  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 005042ce  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 005042d0  81e7007c007c           -and edi, 0x7c007c00
    cpu.edi &= x86::reg32(x86::sreg32(2080406528 /*0x7c007c00*/));
    // 005042d6  c1ef0a                 -shr edi, 0xa
    cpu.edi >>= 10 /*0xa*/ % 32;
    // 005042d9  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 005042db  81e6e083e083           -and esi, 0x83e083e0
    cpu.esi &= x86::reg32(x86::sreg32(2212529120 /*0x83e083e0*/));
    // 005042e1  09f7                   -or edi, esi
    cpu.edi |= x86::reg32(x86::sreg32(cpu.esi));
    // 005042e3  81e11f001f00           -and ecx, 0x1f001f
    cpu.ecx &= x86::reg32(x86::sreg32(2031647 /*0x1f001f*/));
    // 005042e9  c1e10a                 -shl ecx, 0xa
    cpu.ecx <<= 10 /*0xa*/ % 32;
    // 005042ec  09cf                   -or edi, ecx
    cpu.edi |= x86::reg32(x86::sreg32(cpu.ecx));
    // 005042ee  893a                   -mov dword ptr [edx], edi
    app->getMemory<x86::reg32>(cpu.edx) = cpu.edi;
    // 005042f0  83eb02                 +sub ebx, 2
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 005042f3  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 005042f6  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 005042f9  79d1                   -jns 0x5042cc
    if (!cpu.flags.sf)
    {
        goto L_0x005042cc;
    }
L_0x005042fb:
    // 005042fb  83c301                 +add ebx, 1
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 005042fe  7831                   -js 0x504331
    if (cpu.flags.sf)
    {
        goto L_0x00504331;
    }
L_0x00504300:
    // 00504300  668b08                 -mov cx, word ptr [eax]
    cpu.cx = app->getMemory<x86::reg16>(cpu.eax);
    // 00504303  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 00504305  81e7007c007c           -and edi, 0x7c007c00
    cpu.edi &= x86::reg32(x86::sreg32(2080406528 /*0x7c007c00*/));
    // 0050430b  c1ef0a                 -shr edi, 0xa
    cpu.edi >>= 10 /*0xa*/ % 32;
    // 0050430e  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00504310  81e6e083e083           -and esi, 0x83e083e0
    cpu.esi &= x86::reg32(x86::sreg32(2212529120 /*0x83e083e0*/));
    // 00504316  09f7                   -or edi, esi
    cpu.edi |= x86::reg32(x86::sreg32(cpu.esi));
    // 00504318  81e11f001f00           -and ecx, 0x1f001f
    cpu.ecx &= x86::reg32(x86::sreg32(2031647 /*0x1f001f*/));
    // 0050431e  c1e10a                 -shl ecx, 0xa
    cpu.ecx <<= 10 /*0xa*/ % 32;
    // 00504321  09cf                   -or edi, ecx
    cpu.edi |= x86::reg32(x86::sreg32(cpu.ecx));
    // 00504323  66893a                 -mov word ptr [edx], di
    app->getMemory<x86::reg16>(cpu.edx) = cpu.di;
    // 00504326  83eb01                 +sub ebx, 1
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00504329  8d4002                 -lea eax, [eax + 2]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 0050432c  8d5202                 -lea edx, [edx + 2]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 0050432f  79cf                   -jns 0x504300
    if (!cpu.flags.sf)
    {
        goto L_0x00504300;
    }
L_0x00504331:
    // 00504331  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00504332  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00504333  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00504334  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_504335(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00504335  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00504336  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00504337  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00504338  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00504339  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0050433b  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0050433d  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 0050433f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00504341  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00504343  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00504345  83ed04                 -sub ebp, 4
    (cpu.ebp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00504348  f7c702000000           +test edi, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & 2 /*0x2*/));
    // 0050434e  754e                   -jne 0x50439e
    if (!cpu.flags.zf)
    {
        goto L_0x0050439e;
    }
    // 00504350  83fd00                 +cmp ebp, 0
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00504353  7849                   -js 0x50439e
    if (cpu.flags.sf)
    {
        goto L_0x0050439e;
    }
    // 00504355  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00504357  8a5e01                 -mov bl, byte ptr [esi + 1]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
L_0x0050435a:
    // 0050435a  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0050435c  c1e904                 -shr ecx, 4
    cpu.ecx >>= 4 /*0x4*/ % 32;
    // 0050435f  8b144d12aca000         -mov edx, dword ptr [ecx*2 + 0xa0ac12]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10529810) /* 0xa0ac12 */ + cpu.ecx * 2);
    // 00504366  8d7602                 -lea esi, [esi + 2]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 00504369  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0050436b  c1e904                 -shr ecx, 4
    cpu.ecx >>= 4 /*0x4*/ % 32;
    // 0050436e  8b0c4d12aca000         -mov ecx, dword ptr [ecx*2 + 0xa0ac12]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10529810) /* 0xa0ac12 */ + cpu.ecx * 2);
    // 00504375  8d7f08                 -lea edi, [edi + 8]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 00504378  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 0050437b  668b144514aca000       -mov dx, word ptr [eax*2 + 0xa0ac14]
    cpu.dx = app->getMemory<x86::reg16>(x86::reg32(10529812) /* 0xa0ac14 */ + cpu.eax * 2);
    // 00504383  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00504385  83e30f                 -and ebx, 0xf
    cpu.ebx &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00504388  668b0c5d14aca000       -mov cx, word ptr [ebx*2 + 0xa0ac14]
    cpu.cx = app->getMemory<x86::reg16>(x86::reg32(10529812) /* 0xa0ac14 */ + cpu.ebx * 2);
    // 00504390  8a5e01                 -mov bl, byte ptr [esi + 1]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00504393  8957f8                 -mov dword ptr [edi - 8], edx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(-8) /* -0x8 */) = cpu.edx;
    // 00504396  894ffc                 -mov dword ptr [edi - 4], ecx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
    // 00504399  83ed04                 +sub ebp, 4
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0050439c  79bc                   -jns 0x50435a
    if (!cpu.flags.sf)
    {
        goto L_0x0050435a;
    }
L_0x0050439e:
    // 0050439e  83c502                 +add ebp, 2
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 005043a1  7827                   -js 0x5043ca
    if (cpu.flags.sf)
    {
        goto L_0x005043ca;
    }
L_0x005043a3:
    // 005043a3  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 005043a5  c1e904                 -shr ecx, 4
    cpu.ecx >>= 4 /*0x4*/ % 32;
    // 005043a8  8b144d12aca000         -mov edx, dword ptr [ecx*2 + 0xa0ac12]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10529810) /* 0xa0ac12 */ + cpu.ecx * 2);
    // 005043af  8d7601                 -lea esi, [esi + 1]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 005043b2  8d7f04                 -lea edi, [edi + 4]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 005043b5  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 005043b8  668b144514aca000       -mov dx, word ptr [eax*2 + 0xa0ac14]
    cpu.dx = app->getMemory<x86::reg16>(x86::reg32(10529812) /* 0xa0ac14 */ + cpu.eax * 2);
    // 005043c0  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 005043c2  8957fc                 -mov dword ptr [edi - 4], edx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 005043c5  83ed02                 +sub ebp, 2
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 005043c8  79d9                   -jns 0x5043a3
    if (!cpu.flags.sf)
    {
        goto L_0x005043a3;
    }
L_0x005043ca:
    // 005043ca  83c501                 +add ebp, 1
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 005043cd  780e                   -js 0x5043dd
    if (cpu.flags.sf)
    {
        goto L_0x005043dd;
    }
    // 005043cf  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 005043d2  668b144514aca000       -mov dx, word ptr [eax*2 + 0xa0ac14]
    cpu.dx = app->getMemory<x86::reg16>(x86::reg32(10529812) /* 0xa0ac14 */ + cpu.eax * 2);
    // 005043da  668917                 -mov word ptr [edi], dx
    app->getMemory<x86::reg16>(cpu.edi) = cpu.dx;
L_0x005043dd:
    // 005043dd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005043de  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005043df  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005043e0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005043e1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_5043f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005043f0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 005043f1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005043f2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 005043f3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 005043f4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005043f5  8b15187e5600           -mov edx, dword ptr [0x567e18]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5668376) /* 0x567e18 */);
    // 005043fb  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 005043fd  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 005043ff  750a                   -jne 0x50440b
    if (!cpu.flags.zf)
    {
        goto L_0x0050440b;
    }
    // 00504401  c705187e5600404c5000   -mov dword ptr [0x567e18], 0x504c40
    app->getMemory<x86::reg32>(x86::reg32(5668376) /* 0x567e18 */) = 5262400 /*0x504c40*/;
L_0x0050440b:
    // 0050440b  68a0ec5400             -push 0x54eca0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5565600 /*0x54eca0*/;
    cpu.esp -= 4;
    // 00504410  2eff158c455300         -call dword ptr cs:[0x53458c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457292) /* 0x53458c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00504417  a3347e5600             -mov dword ptr [0x567e34], eax
    app->getMemory<x86::reg32>(x86::reg32(5668404) /* 0x567e34 */) = cpu.eax;
    // 0050441c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0050441e  7508                   -jne 0x504428
    if (!cpu.flags.zf)
    {
        goto L_0x00504428;
    }
    // 00504420  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00504422  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00504423  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00504424  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00504425  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00504426  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00504427  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00504428:
    // 00504428  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00504429  68acec5400             -push 0x54ecac
    app->getMemory<x86::reg32>(cpu.esp-4) = 5565612 /*0x54ecac*/;
    cpu.esp -= 4;
    // 0050442e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0050442f  2eff1558455300         -call dword ptr cs:[0x534558]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457240) /* 0x534558 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00504436  68bcec5400             -push 0x54ecbc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5565628 /*0x54ecbc*/;
    cpu.esp -= 4;
    // 0050443b  8b1d347e5600           -mov ebx, dword ptr [0x567e34]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5668404) /* 0x567e34 */);
    // 00504441  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00504442  a370a2a000             -mov dword ptr [0xa0a270], eax
    app->getMemory<x86::reg32>(x86::reg32(10527344) /* 0xa0a270 */) = cpu.eax;
    // 00504447  2eff1558455300         -call dword ptr cs:[0x534558]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457240) /* 0x534558 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050444e  68d4ec5400             -push 0x54ecd4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5565652 /*0x54ecd4*/;
    cpu.esp -= 4;
    // 00504453  8b35347e5600           -mov esi, dword ptr [0x567e34]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5668404) /* 0x567e34 */);
    // 00504459  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050445a  a374a2a000             -mov dword ptr [0xa0a274], eax
    app->getMemory<x86::reg32>(x86::reg32(10527348) /* 0xa0a274 */) = cpu.eax;
    // 0050445f  2eff1558455300         -call dword ptr cs:[0x534558]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457240) /* 0x534558 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00504466  68e8ec5400             -push 0x54ece8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5565672 /*0x54ece8*/;
    cpu.esp -= 4;
    // 0050446b  8b3d347e5600           -mov edi, dword ptr [0x567e34]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5668404) /* 0x567e34 */);
    // 00504471  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00504472  a378a2a000             -mov dword ptr [0xa0a278], eax
    app->getMemory<x86::reg32>(x86::reg32(10527352) /* 0xa0a278 */) = cpu.eax;
    // 00504477  2eff1558455300         -call dword ptr cs:[0x534558]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457240) /* 0x534558 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050447e  68fcec5400             -push 0x54ecfc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5565692 /*0x54ecfc*/;
    cpu.esp -= 4;
    // 00504483  8b2d347e5600           -mov ebp, dword ptr [0x567e34]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5668404) /* 0x567e34 */);
    // 00504489  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0050448a  a37ca2a000             -mov dword ptr [0xa0a27c], eax
    app->getMemory<x86::reg32>(x86::reg32(10527356) /* 0xa0a27c */) = cpu.eax;
    // 0050448f  2eff1558455300         -call dword ptr cs:[0x534558]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457240) /* 0x534558 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00504496  680ced5400             -push 0x54ed0c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5565708 /*0x54ed0c*/;
    cpu.esp -= 4;
    // 0050449b  a380a2a000             -mov dword ptr [0xa0a280], eax
    app->getMemory<x86::reg32>(x86::reg32(10527360) /* 0xa0a280 */) = cpu.eax;
    // 005044a0  a1347e5600             -mov eax, dword ptr [0x567e34]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5668404) /* 0x567e34 */);
    // 005044a5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 005044a6  2eff1558455300         -call dword ptr cs:[0x534558]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457240) /* 0x534558 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005044ad  6820ed5400             -push 0x54ed20
    app->getMemory<x86::reg32>(cpu.esp-4) = 5565728 /*0x54ed20*/;
    cpu.esp -= 4;
    // 005044b2  8b15347e5600           -mov edx, dword ptr [0x567e34]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5668404) /* 0x567e34 */);
    // 005044b8  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 005044b9  a384a2a000             -mov dword ptr [0xa0a284], eax
    app->getMemory<x86::reg32>(x86::reg32(10527364) /* 0xa0a284 */) = cpu.eax;
    // 005044be  2eff1558455300         -call dword ptr cs:[0x534558]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457240) /* 0x534558 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005044c5  6834ed5400             -push 0x54ed34
    app->getMemory<x86::reg32>(cpu.esp-4) = 5565748 /*0x54ed34*/;
    cpu.esp -= 4;
    // 005044ca  8b0d347e5600           -mov ecx, dword ptr [0x567e34]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5668404) /* 0x567e34 */);
    // 005044d0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005044d1  a388a2a000             -mov dword ptr [0xa0a288], eax
    app->getMemory<x86::reg32>(x86::reg32(10527368) /* 0xa0a288 */) = cpu.eax;
    // 005044d6  2eff1558455300         -call dword ptr cs:[0x534558]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457240) /* 0x534558 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005044dd  684ced5400             -push 0x54ed4c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5565772 /*0x54ed4c*/;
    cpu.esp -= 4;
    // 005044e2  8b1d347e5600           -mov ebx, dword ptr [0x567e34]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5668404) /* 0x567e34 */);
    // 005044e8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 005044e9  a38ca2a000             -mov dword ptr [0xa0a28c], eax
    app->getMemory<x86::reg32>(x86::reg32(10527372) /* 0xa0a28c */) = cpu.eax;
    // 005044ee  2eff1558455300         -call dword ptr cs:[0x534558]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457240) /* 0x534558 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005044f5  6860ed5400             -push 0x54ed60
    app->getMemory<x86::reg32>(cpu.esp-4) = 5565792 /*0x54ed60*/;
    cpu.esp -= 4;
    // 005044fa  8b35347e5600           -mov esi, dword ptr [0x567e34]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5668404) /* 0x567e34 */);
    // 00504500  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00504501  a390a2a000             -mov dword ptr [0xa0a290], eax
    app->getMemory<x86::reg32>(x86::reg32(10527376) /* 0xa0a290 */) = cpu.eax;
    // 00504506  2eff1558455300         -call dword ptr cs:[0x534558]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457240) /* 0x534558 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050450d  6880ed5400             -push 0x54ed80
    app->getMemory<x86::reg32>(cpu.esp-4) = 5565824 /*0x54ed80*/;
    cpu.esp -= 4;
    // 00504512  8b3d347e5600           -mov edi, dword ptr [0x567e34]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5668404) /* 0x567e34 */);
    // 00504518  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00504519  a394a2a000             -mov dword ptr [0xa0a294], eax
    app->getMemory<x86::reg32>(x86::reg32(10527380) /* 0xa0a294 */) = cpu.eax;
    // 0050451e  2eff1558455300         -call dword ptr cs:[0x534558]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457240) /* 0x534558 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00504525  6898ed5400             -push 0x54ed98
    app->getMemory<x86::reg32>(cpu.esp-4) = 5565848 /*0x54ed98*/;
    cpu.esp -= 4;
    // 0050452a  8b2d347e5600           -mov ebp, dword ptr [0x567e34]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5668404) /* 0x567e34 */);
    // 00504530  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00504531  a398a2a000             -mov dword ptr [0xa0a298], eax
    app->getMemory<x86::reg32>(x86::reg32(10527384) /* 0xa0a298 */) = cpu.eax;
    // 00504536  2eff1558455300         -call dword ptr cs:[0x534558]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457240) /* 0x534558 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050453d  68aced5400             -push 0x54edac
    app->getMemory<x86::reg32>(cpu.esp-4) = 5565868 /*0x54edac*/;
    cpu.esp -= 4;
    // 00504542  a39ca2a000             -mov dword ptr [0xa0a29c], eax
    app->getMemory<x86::reg32>(x86::reg32(10527388) /* 0xa0a29c */) = cpu.eax;
    // 00504547  a1347e5600             -mov eax, dword ptr [0x567e34]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5668404) /* 0x567e34 */);
    // 0050454c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0050454d  2eff1558455300         -call dword ptr cs:[0x534558]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457240) /* 0x534558 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00504554  a3a0a2a000             -mov dword ptr [0xa0a2a0], eax
    app->getMemory<x86::reg32>(x86::reg32(10527392) /* 0xa0a2a0 */) = cpu.eax;
    // 00504559  68c0ed5400             -push 0x54edc0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5565888 /*0x54edc0*/;
    cpu.esp -= 4;
    // 0050455e  8b15347e5600           -mov edx, dword ptr [0x567e34]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5668404) /* 0x567e34 */);
    // 00504564  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00504565  2eff1558455300         -call dword ptr cs:[0x534558]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457240) /* 0x534558 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050456c  68d0ed5400             -push 0x54edd0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5565904 /*0x54edd0*/;
    cpu.esp -= 4;
    // 00504571  8b0d347e5600           -mov ecx, dword ptr [0x567e34]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5668404) /* 0x567e34 */);
    // 00504577  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00504578  a3a4a2a000             -mov dword ptr [0xa0a2a4], eax
    app->getMemory<x86::reg32>(x86::reg32(10527396) /* 0xa0a2a4 */) = cpu.eax;
    // 0050457d  2eff1558455300         -call dword ptr cs:[0x534558]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457240) /* 0x534558 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00504584  68e0ed5400             -push 0x54ede0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5565920 /*0x54ede0*/;
    cpu.esp -= 4;
    // 00504589  8b1d347e5600           -mov ebx, dword ptr [0x567e34]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5668404) /* 0x567e34 */);
    // 0050458f  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00504590  a3a8a2a000             -mov dword ptr [0xa0a2a8], eax
    app->getMemory<x86::reg32>(x86::reg32(10527400) /* 0xa0a2a8 */) = cpu.eax;
    // 00504595  2eff1558455300         -call dword ptr cs:[0x534558]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457240) /* 0x534558 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050459c  68f4ed5400             -push 0x54edf4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5565940 /*0x54edf4*/;
    cpu.esp -= 4;
    // 005045a1  8b35347e5600           -mov esi, dword ptr [0x567e34]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5668404) /* 0x567e34 */);
    // 005045a7  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005045a8  a3aca2a000             -mov dword ptr [0xa0a2ac], eax
    app->getMemory<x86::reg32>(x86::reg32(10527404) /* 0xa0a2ac */) = cpu.eax;
    // 005045ad  2eff1558455300         -call dword ptr cs:[0x534558]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457240) /* 0x534558 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005045b4  6804ee5400             -push 0x54ee04
    app->getMemory<x86::reg32>(cpu.esp-4) = 5565956 /*0x54ee04*/;
    cpu.esp -= 4;
    // 005045b9  8b3d347e5600           -mov edi, dword ptr [0x567e34]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5668404) /* 0x567e34 */);
    // 005045bf  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 005045c0  a3b0a2a000             -mov dword ptr [0xa0a2b0], eax
    app->getMemory<x86::reg32>(x86::reg32(10527408) /* 0xa0a2b0 */) = cpu.eax;
    // 005045c5  2eff1558455300         -call dword ptr cs:[0x534558]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457240) /* 0x534558 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005045cc  6814ee5400             -push 0x54ee14
    app->getMemory<x86::reg32>(cpu.esp-4) = 5565972 /*0x54ee14*/;
    cpu.esp -= 4;
    // 005045d1  8b2d347e5600           -mov ebp, dword ptr [0x567e34]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5668404) /* 0x567e34 */);
    // 005045d7  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005045d8  a3b4a2a000             -mov dword ptr [0xa0a2b4], eax
    app->getMemory<x86::reg32>(x86::reg32(10527412) /* 0xa0a2b4 */) = cpu.eax;
    // 005045dd  2eff1558455300         -call dword ptr cs:[0x534558]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457240) /* 0x534558 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005045e4  6828ee5400             -push 0x54ee28
    app->getMemory<x86::reg32>(cpu.esp-4) = 5565992 /*0x54ee28*/;
    cpu.esp -= 4;
    // 005045e9  a3b8a2a000             -mov dword ptr [0xa0a2b8], eax
    app->getMemory<x86::reg32>(x86::reg32(10527416) /* 0xa0a2b8 */) = cpu.eax;
    // 005045ee  a1347e5600             -mov eax, dword ptr [0x567e34]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5668404) /* 0x567e34 */);
    // 005045f3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 005045f4  2eff1558455300         -call dword ptr cs:[0x534558]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457240) /* 0x534558 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005045fb  683cee5400             -push 0x54ee3c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5566012 /*0x54ee3c*/;
    cpu.esp -= 4;
    // 00504600  8b15347e5600           -mov edx, dword ptr [0x567e34]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5668404) /* 0x567e34 */);
    // 00504606  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00504607  a3bca2a000             -mov dword ptr [0xa0a2bc], eax
    app->getMemory<x86::reg32>(x86::reg32(10527420) /* 0xa0a2bc */) = cpu.eax;
    // 0050460c  2eff1558455300         -call dword ptr cs:[0x534558]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457240) /* 0x534558 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00504613  6850ee5400             -push 0x54ee50
    app->getMemory<x86::reg32>(cpu.esp-4) = 5566032 /*0x54ee50*/;
    cpu.esp -= 4;
    // 00504618  8b0d347e5600           -mov ecx, dword ptr [0x567e34]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5668404) /* 0x567e34 */);
    // 0050461e  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050461f  a3c0a2a000             -mov dword ptr [0xa0a2c0], eax
    app->getMemory<x86::reg32>(x86::reg32(10527424) /* 0xa0a2c0 */) = cpu.eax;
    // 00504624  2eff1558455300         -call dword ptr cs:[0x534558]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457240) /* 0x534558 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050462b  686cee5400             -push 0x54ee6c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5566060 /*0x54ee6c*/;
    cpu.esp -= 4;
    // 00504630  8b1d347e5600           -mov ebx, dword ptr [0x567e34]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5668404) /* 0x567e34 */);
    // 00504636  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00504637  a3c4a2a000             -mov dword ptr [0xa0a2c4], eax
    app->getMemory<x86::reg32>(x86::reg32(10527428) /* 0xa0a2c4 */) = cpu.eax;
    // 0050463c  2eff1558455300         -call dword ptr cs:[0x534558]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457240) /* 0x534558 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00504643  687cee5400             -push 0x54ee7c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5566076 /*0x54ee7c*/;
    cpu.esp -= 4;
    // 00504648  8b35347e5600           -mov esi, dword ptr [0x567e34]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5668404) /* 0x567e34 */);
    // 0050464e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050464f  a3c8a2a000             -mov dword ptr [0xa0a2c8], eax
    app->getMemory<x86::reg32>(x86::reg32(10527432) /* 0xa0a2c8 */) = cpu.eax;
    // 00504654  2eff1558455300         -call dword ptr cs:[0x534558]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457240) /* 0x534558 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050465b  6890ee5400             -push 0x54ee90
    app->getMemory<x86::reg32>(cpu.esp-4) = 5566096 /*0x54ee90*/;
    cpu.esp -= 4;
    // 00504660  8b3d347e5600           -mov edi, dword ptr [0x567e34]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5668404) /* 0x567e34 */);
    // 00504666  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00504667  a3cca2a000             -mov dword ptr [0xa0a2cc], eax
    app->getMemory<x86::reg32>(x86::reg32(10527436) /* 0xa0a2cc */) = cpu.eax;
    // 0050466c  2eff1558455300         -call dword ptr cs:[0x534558]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457240) /* 0x534558 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00504673  68a0ee5400             -push 0x54eea0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5566112 /*0x54eea0*/;
    cpu.esp -= 4;
    // 00504678  8b2d347e5600           -mov ebp, dword ptr [0x567e34]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5668404) /* 0x567e34 */);
    // 0050467e  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0050467f  a3d0a2a000             -mov dword ptr [0xa0a2d0], eax
    app->getMemory<x86::reg32>(x86::reg32(10527440) /* 0xa0a2d0 */) = cpu.eax;
    // 00504684  2eff1558455300         -call dword ptr cs:[0x534558]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457240) /* 0x534558 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050468b  a3d4a2a000             -mov dword ptr [0xa0a2d4], eax
    app->getMemory<x86::reg32>(x86::reg32(10527444) /* 0xa0a2d4 */) = cpu.eax;
    // 00504690  68b4ee5400             -push 0x54eeb4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5566132 /*0x54eeb4*/;
    cpu.esp -= 4;
    // 00504695  a1347e5600             -mov eax, dword ptr [0x567e34]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5668404) /* 0x567e34 */);
    // 0050469a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0050469b  2eff1558455300         -call dword ptr cs:[0x534558]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457240) /* 0x534558 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005046a2  68ccee5400             -push 0x54eecc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5566156 /*0x54eecc*/;
    cpu.esp -= 4;
    // 005046a7  8b15347e5600           -mov edx, dword ptr [0x567e34]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5668404) /* 0x567e34 */);
    // 005046ad  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 005046ae  a3d8a2a000             -mov dword ptr [0xa0a2d8], eax
    app->getMemory<x86::reg32>(x86::reg32(10527448) /* 0xa0a2d8 */) = cpu.eax;
    // 005046b3  2eff1558455300         -call dword ptr cs:[0x534558]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457240) /* 0x534558 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005046ba  68e4ee5400             -push 0x54eee4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5566180 /*0x54eee4*/;
    cpu.esp -= 4;
    // 005046bf  8b0d347e5600           -mov ecx, dword ptr [0x567e34]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5668404) /* 0x567e34 */);
    // 005046c5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005046c6  a3dca2a000             -mov dword ptr [0xa0a2dc], eax
    app->getMemory<x86::reg32>(x86::reg32(10527452) /* 0xa0a2dc */) = cpu.eax;
    // 005046cb  2eff1558455300         -call dword ptr cs:[0x534558]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457240) /* 0x534558 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005046d2  6800ef5400             -push 0x54ef00
    app->getMemory<x86::reg32>(cpu.esp-4) = 5566208 /*0x54ef00*/;
    cpu.esp -= 4;
    // 005046d7  8b1d347e5600           -mov ebx, dword ptr [0x567e34]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5668404) /* 0x567e34 */);
    // 005046dd  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 005046de  a3e0a2a000             -mov dword ptr [0xa0a2e0], eax
    app->getMemory<x86::reg32>(x86::reg32(10527456) /* 0xa0a2e0 */) = cpu.eax;
    // 005046e3  2eff1558455300         -call dword ptr cs:[0x534558]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457240) /* 0x534558 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005046ea  6810ef5400             -push 0x54ef10
    app->getMemory<x86::reg32>(cpu.esp-4) = 5566224 /*0x54ef10*/;
    cpu.esp -= 4;
    // 005046ef  8b35347e5600           -mov esi, dword ptr [0x567e34]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5668404) /* 0x567e34 */);
    // 005046f5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005046f6  a3e4a2a000             -mov dword ptr [0xa0a2e4], eax
    app->getMemory<x86::reg32>(x86::reg32(10527460) /* 0xa0a2e4 */) = cpu.eax;
    // 005046fb  2eff1558455300         -call dword ptr cs:[0x534558]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457240) /* 0x534558 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00504702  6824ef5400             -push 0x54ef24
    app->getMemory<x86::reg32>(cpu.esp-4) = 5566244 /*0x54ef24*/;
    cpu.esp -= 4;
    // 00504707  8b3d347e5600           -mov edi, dword ptr [0x567e34]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5668404) /* 0x567e34 */);
    // 0050470d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050470e  a3e8a2a000             -mov dword ptr [0xa0a2e8], eax
    app->getMemory<x86::reg32>(x86::reg32(10527464) /* 0xa0a2e8 */) = cpu.eax;
    // 00504713  2eff1558455300         -call dword ptr cs:[0x534558]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457240) /* 0x534558 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050471a  6834ef5400             -push 0x54ef34
    app->getMemory<x86::reg32>(cpu.esp-4) = 5566260 /*0x54ef34*/;
    cpu.esp -= 4;
    // 0050471f  8b2d347e5600           -mov ebp, dword ptr [0x567e34]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5668404) /* 0x567e34 */);
    // 00504725  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00504726  a3eca2a000             -mov dword ptr [0xa0a2ec], eax
    app->getMemory<x86::reg32>(x86::reg32(10527468) /* 0xa0a2ec */) = cpu.eax;
    // 0050472b  2eff1558455300         -call dword ptr cs:[0x534558]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457240) /* 0x534558 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00504732  6844ef5400             -push 0x54ef44
    app->getMemory<x86::reg32>(cpu.esp-4) = 5566276 /*0x54ef44*/;
    cpu.esp -= 4;
    // 00504737  a3f0a2a000             -mov dword ptr [0xa0a2f0], eax
    app->getMemory<x86::reg32>(x86::reg32(10527472) /* 0xa0a2f0 */) = cpu.eax;
    // 0050473c  a1347e5600             -mov eax, dword ptr [0x567e34]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5668404) /* 0x567e34 */);
    // 00504741  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00504742  2eff1558455300         -call dword ptr cs:[0x534558]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457240) /* 0x534558 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00504749  6854ef5400             -push 0x54ef54
    app->getMemory<x86::reg32>(cpu.esp-4) = 5566292 /*0x54ef54*/;
    cpu.esp -= 4;
    // 0050474e  8b15347e5600           -mov edx, dword ptr [0x567e34]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5668404) /* 0x567e34 */);
    // 00504754  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00504755  a3f4a2a000             -mov dword ptr [0xa0a2f4], eax
    app->getMemory<x86::reg32>(x86::reg32(10527476) /* 0xa0a2f4 */) = cpu.eax;
    // 0050475a  2eff1558455300         -call dword ptr cs:[0x534558]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457240) /* 0x534558 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00504761  6864ef5400             -push 0x54ef64
    app->getMemory<x86::reg32>(cpu.esp-4) = 5566308 /*0x54ef64*/;
    cpu.esp -= 4;
    // 00504766  8b0d347e5600           -mov ecx, dword ptr [0x567e34]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5668404) /* 0x567e34 */);
    // 0050476c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050476d  a3f8a2a000             -mov dword ptr [0xa0a2f8], eax
    app->getMemory<x86::reg32>(x86::reg32(10527480) /* 0xa0a2f8 */) = cpu.eax;
    // 00504772  2eff1558455300         -call dword ptr cs:[0x534558]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457240) /* 0x534558 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00504779  687cef5400             -push 0x54ef7c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5566332 /*0x54ef7c*/;
    cpu.esp -= 4;
    // 0050477e  8b1d347e5600           -mov ebx, dword ptr [0x567e34]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5668404) /* 0x567e34 */);
    // 00504784  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00504785  a3fca2a000             -mov dword ptr [0xa0a2fc], eax
    app->getMemory<x86::reg32>(x86::reg32(10527484) /* 0xa0a2fc */) = cpu.eax;
    // 0050478a  2eff1558455300         -call dword ptr cs:[0x534558]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457240) /* 0x534558 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00504791  6890ef5400             -push 0x54ef90
    app->getMemory<x86::reg32>(cpu.esp-4) = 5566352 /*0x54ef90*/;
    cpu.esp -= 4;
    // 00504796  8b35347e5600           -mov esi, dword ptr [0x567e34]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5668404) /* 0x567e34 */);
    // 0050479c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050479d  a300a3a000             -mov dword ptr [0xa0a300], eax
    app->getMemory<x86::reg32>(x86::reg32(10527488) /* 0xa0a300 */) = cpu.eax;
    // 005047a2  2eff1558455300         -call dword ptr cs:[0x534558]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457240) /* 0x534558 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005047a9  68a4ef5400             -push 0x54efa4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5566372 /*0x54efa4*/;
    cpu.esp -= 4;
    // 005047ae  8b3d347e5600           -mov edi, dword ptr [0x567e34]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5668404) /* 0x567e34 */);
    // 005047b4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 005047b5  a304a3a000             -mov dword ptr [0xa0a304], eax
    app->getMemory<x86::reg32>(x86::reg32(10527492) /* 0xa0a304 */) = cpu.eax;
    // 005047ba  2eff1558455300         -call dword ptr cs:[0x534558]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457240) /* 0x534558 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005047c1  a308a3a000             -mov dword ptr [0xa0a308], eax
    app->getMemory<x86::reg32>(x86::reg32(10527496) /* 0xa0a308 */) = cpu.eax;
    // 005047c6  68b4ef5400             -push 0x54efb4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5566388 /*0x54efb4*/;
    cpu.esp -= 4;
    // 005047cb  8b2d347e5600           -mov ebp, dword ptr [0x567e34]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5668404) /* 0x567e34 */);
    // 005047d1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005047d2  2eff1558455300         -call dword ptr cs:[0x534558]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457240) /* 0x534558 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005047d9  68c4ef5400             -push 0x54efc4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5566404 /*0x54efc4*/;
    cpu.esp -= 4;
    // 005047de  a30ca3a000             -mov dword ptr [0xa0a30c], eax
    app->getMemory<x86::reg32>(x86::reg32(10527500) /* 0xa0a30c */) = cpu.eax;
    // 005047e3  a1347e5600             -mov eax, dword ptr [0x567e34]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5668404) /* 0x567e34 */);
    // 005047e8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 005047e9  2eff1558455300         -call dword ptr cs:[0x534558]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457240) /* 0x534558 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005047f0  68e0ef5400             -push 0x54efe0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5566432 /*0x54efe0*/;
    cpu.esp -= 4;
    // 005047f5  8b15347e5600           -mov edx, dword ptr [0x567e34]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5668404) /* 0x567e34 */);
    // 005047fb  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 005047fc  a310a3a000             -mov dword ptr [0xa0a310], eax
    app->getMemory<x86::reg32>(x86::reg32(10527504) /* 0xa0a310 */) = cpu.eax;
    // 00504801  2eff1558455300         -call dword ptr cs:[0x534558]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457240) /* 0x534558 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00504808  68f4ef5400             -push 0x54eff4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5566452 /*0x54eff4*/;
    cpu.esp -= 4;
    // 0050480d  8b0d347e5600           -mov ecx, dword ptr [0x567e34]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5668404) /* 0x567e34 */);
    // 00504813  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00504814  a314a3a000             -mov dword ptr [0xa0a314], eax
    app->getMemory<x86::reg32>(x86::reg32(10527508) /* 0xa0a314 */) = cpu.eax;
    // 00504819  2eff1558455300         -call dword ptr cs:[0x534558]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457240) /* 0x534558 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00504820  6808f05400             -push 0x54f008
    app->getMemory<x86::reg32>(cpu.esp-4) = 5566472 /*0x54f008*/;
    cpu.esp -= 4;
    // 00504825  8b1d347e5600           -mov ebx, dword ptr [0x567e34]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5668404) /* 0x567e34 */);
    // 0050482b  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0050482c  a318a3a000             -mov dword ptr [0xa0a318], eax
    app->getMemory<x86::reg32>(x86::reg32(10527512) /* 0xa0a318 */) = cpu.eax;
    // 00504831  2eff1558455300         -call dword ptr cs:[0x534558]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457240) /* 0x534558 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00504838  681cf05400             -push 0x54f01c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5566492 /*0x54f01c*/;
    cpu.esp -= 4;
    // 0050483d  8b35347e5600           -mov esi, dword ptr [0x567e34]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5668404) /* 0x567e34 */);
    // 00504843  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00504844  a31ca3a000             -mov dword ptr [0xa0a31c], eax
    app->getMemory<x86::reg32>(x86::reg32(10527516) /* 0xa0a31c */) = cpu.eax;
    // 00504849  2eff1558455300         -call dword ptr cs:[0x534558]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457240) /* 0x534558 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00504850  6838f05400             -push 0x54f038
    app->getMemory<x86::reg32>(cpu.esp-4) = 5566520 /*0x54f038*/;
    cpu.esp -= 4;
    // 00504855  8b3d347e5600           -mov edi, dword ptr [0x567e34]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5668404) /* 0x567e34 */);
    // 0050485b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050485c  a320a3a000             -mov dword ptr [0xa0a320], eax
    app->getMemory<x86::reg32>(x86::reg32(10527520) /* 0xa0a320 */) = cpu.eax;
    // 00504861  2eff1558455300         -call dword ptr cs:[0x534558]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457240) /* 0x534558 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00504868  6850f05400             -push 0x54f050
    app->getMemory<x86::reg32>(cpu.esp-4) = 5566544 /*0x54f050*/;
    cpu.esp -= 4;
    // 0050486d  8b2d347e5600           -mov ebp, dword ptr [0x567e34]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5668404) /* 0x567e34 */);
    // 00504873  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00504874  a324a3a000             -mov dword ptr [0xa0a324], eax
    app->getMemory<x86::reg32>(x86::reg32(10527524) /* 0xa0a324 */) = cpu.eax;
    // 00504879  2eff1558455300         -call dword ptr cs:[0x534558]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457240) /* 0x534558 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00504880  6864f05400             -push 0x54f064
    app->getMemory<x86::reg32>(cpu.esp-4) = 5566564 /*0x54f064*/;
    cpu.esp -= 4;
    // 00504885  a328a3a000             -mov dword ptr [0xa0a328], eax
    app->getMemory<x86::reg32>(x86::reg32(10527528) /* 0xa0a328 */) = cpu.eax;
    // 0050488a  a1347e5600             -mov eax, dword ptr [0x567e34]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5668404) /* 0x567e34 */);
    // 0050488f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00504890  2eff1558455300         -call dword ptr cs:[0x534558]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457240) /* 0x534558 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00504897  6878f05400             -push 0x54f078
    app->getMemory<x86::reg32>(cpu.esp-4) = 5566584 /*0x54f078*/;
    cpu.esp -= 4;
    // 0050489c  8b15347e5600           -mov edx, dword ptr [0x567e34]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5668404) /* 0x567e34 */);
    // 005048a2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 005048a3  a32ca3a000             -mov dword ptr [0xa0a32c], eax
    app->getMemory<x86::reg32>(x86::reg32(10527532) /* 0xa0a32c */) = cpu.eax;
    // 005048a8  2eff1558455300         -call dword ptr cs:[0x534558]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457240) /* 0x534558 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005048af  6888f05400             -push 0x54f088
    app->getMemory<x86::reg32>(cpu.esp-4) = 5566600 /*0x54f088*/;
    cpu.esp -= 4;
    // 005048b4  8b0d347e5600           -mov ecx, dword ptr [0x567e34]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5668404) /* 0x567e34 */);
    // 005048ba  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005048bb  a330a3a000             -mov dword ptr [0xa0a330], eax
    app->getMemory<x86::reg32>(x86::reg32(10527536) /* 0xa0a330 */) = cpu.eax;
    // 005048c0  2eff1558455300         -call dword ptr cs:[0x534558]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457240) /* 0x534558 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005048c7  689cf05400             -push 0x54f09c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5566620 /*0x54f09c*/;
    cpu.esp -= 4;
    // 005048cc  8b1d347e5600           -mov ebx, dword ptr [0x567e34]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5668404) /* 0x567e34 */);
    // 005048d2  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 005048d3  a334a3a000             -mov dword ptr [0xa0a334], eax
    app->getMemory<x86::reg32>(x86::reg32(10527540) /* 0xa0a334 */) = cpu.eax;
    // 005048d8  2eff1558455300         -call dword ptr cs:[0x534558]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457240) /* 0x534558 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005048df  68b4f05400             -push 0x54f0b4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5566644 /*0x54f0b4*/;
    cpu.esp -= 4;
    // 005048e4  8b35347e5600           -mov esi, dword ptr [0x567e34]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5668404) /* 0x567e34 */);
    // 005048ea  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005048eb  a338a3a000             -mov dword ptr [0xa0a338], eax
    app->getMemory<x86::reg32>(x86::reg32(10527544) /* 0xa0a338 */) = cpu.eax;
    // 005048f0  2eff1558455300         -call dword ptr cs:[0x534558]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457240) /* 0x534558 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005048f7  a33ca3a000             -mov dword ptr [0xa0a33c], eax
    app->getMemory<x86::reg32>(x86::reg32(10527548) /* 0xa0a33c */) = cpu.eax;
    // 005048fc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005048fd  68ccf05400             -push 0x54f0cc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5566668 /*0x54f0cc*/;
    cpu.esp -= 4;
    // 00504902  8b3d347e5600           -mov edi, dword ptr [0x567e34]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5668404) /* 0x567e34 */);
    // 00504908  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00504909  2eff1558455300         -call dword ptr cs:[0x534558]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457240) /* 0x534558 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00504910  68dcf05400             -push 0x54f0dc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5566684 /*0x54f0dc*/;
    cpu.esp -= 4;
    // 00504915  8b2d347e5600           -mov ebp, dword ptr [0x567e34]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5668404) /* 0x567e34 */);
    // 0050491b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0050491c  a340a3a000             -mov dword ptr [0xa0a340], eax
    app->getMemory<x86::reg32>(x86::reg32(10527552) /* 0xa0a340 */) = cpu.eax;
    // 00504921  2eff1558455300         -call dword ptr cs:[0x534558]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457240) /* 0x534558 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00504928  68e8f05400             -push 0x54f0e8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5566696 /*0x54f0e8*/;
    cpu.esp -= 4;
    // 0050492d  a344a3a000             -mov dword ptr [0xa0a344], eax
    app->getMemory<x86::reg32>(x86::reg32(10527556) /* 0xa0a344 */) = cpu.eax;
    // 00504932  a1347e5600             -mov eax, dword ptr [0x567e34]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5668404) /* 0x567e34 */);
    // 00504937  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00504938  2eff1558455300         -call dword ptr cs:[0x534558]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457240) /* 0x534558 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050493f  6800f15400             -push 0x54f100
    app->getMemory<x86::reg32>(cpu.esp-4) = 5566720 /*0x54f100*/;
    cpu.esp -= 4;
    // 00504944  8b15347e5600           -mov edx, dword ptr [0x567e34]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5668404) /* 0x567e34 */);
    // 0050494a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0050494b  a348a3a000             -mov dword ptr [0xa0a348], eax
    app->getMemory<x86::reg32>(x86::reg32(10527560) /* 0xa0a348 */) = cpu.eax;
    // 00504950  2eff1558455300         -call dword ptr cs:[0x534558]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457240) /* 0x534558 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00504957  6814f15400             -push 0x54f114
    app->getMemory<x86::reg32>(cpu.esp-4) = 5566740 /*0x54f114*/;
    cpu.esp -= 4;
    // 0050495c  8b0d347e5600           -mov ecx, dword ptr [0x567e34]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5668404) /* 0x567e34 */);
    // 00504962  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00504963  a34ca3a000             -mov dword ptr [0xa0a34c], eax
    app->getMemory<x86::reg32>(x86::reg32(10527564) /* 0xa0a34c */) = cpu.eax;
    // 00504968  2eff1558455300         -call dword ptr cs:[0x534558]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457240) /* 0x534558 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050496f  682cf15400             -push 0x54f12c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5566764 /*0x54f12c*/;
    cpu.esp -= 4;
    // 00504974  8b1d347e5600           -mov ebx, dword ptr [0x567e34]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5668404) /* 0x567e34 */);
    // 0050497a  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0050497b  a350a3a000             -mov dword ptr [0xa0a350], eax
    app->getMemory<x86::reg32>(x86::reg32(10527568) /* 0xa0a350 */) = cpu.eax;
    // 00504980  2eff1558455300         -call dword ptr cs:[0x534558]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457240) /* 0x534558 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00504987  a354a3a000             -mov dword ptr [0xa0a354], eax
    app->getMemory<x86::reg32>(x86::reg32(10527572) /* 0xa0a354 */) = cpu.eax;
    // 0050498c  a104a3a000             -mov eax, dword ptr [0xa0a304]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10527492) /* 0xa0a304 */);
    // 00504991  a370a7a000             -mov dword ptr [0xa0a770], eax
    app->getMemory<x86::reg32>(x86::reg32(10528624) /* 0xa0a770 */) = cpu.eax;
    // 00504996  a36ca7a000             -mov dword ptr [0xa0a76c], eax
    app->getMemory<x86::reg32>(x86::reg32(10528620) /* 0xa0a76c */) = cpu.eax;
    // 0050499b  a108a3a000             -mov eax, dword ptr [0xa0a308]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10527496) /* 0xa0a308 */);
    // 005049a0  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 005049a5  a358a7a000             -mov dword ptr [0xa0a758], eax
    app->getMemory<x86::reg32>(x86::reg32(10528600) /* 0xa0a758 */) = cpu.eax;
    // 005049aa  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 005049ac  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005049ad  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005049ae  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005049af  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005049b0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005049b1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_5049c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005049c0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 005049c1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005049c2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 005049c3  8b15347e5600           -mov edx, dword ptr [0x567e34]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5668404) /* 0x567e34 */);
    // 005049c9  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 005049cb  750c                   -jne 0x5049d9
    if (!cpu.flags.zf)
    {
        goto L_0x005049d9;
    }
    // 005049cd  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 005049cf  891d347e5600           -mov dword ptr [0x567e34], ebx
    app->getMemory<x86::reg32>(x86::reg32(5668404) /* 0x567e34 */) = cpu.ebx;
    // 005049d5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005049d6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005049d7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005049d8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005049d9:
    // 005049d9  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 005049da  2eff15dc445300         -call dword ptr cs:[0x5344dc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457116) /* 0x5344dc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005049e1  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 005049e3  891d347e5600           -mov dword ptr [0x567e34], ebx
    app->getMemory<x86::reg32>(x86::reg32(5668404) /* 0x567e34 */) = cpu.ebx;
    // 005049e9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005049ea  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005049eb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005049ec  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_5049f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005049f0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 005049f1  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 005049f4  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 005049f6  c1f802                 -sar eax, 2
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (2 /*0x2*/ % 32));
    // 005049f9  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 005049fc  db0424                 -fild dword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp))));
    // 005049ff  dc0548f15400           -fadd qword ptr [0x54f148]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(x86::reg32(5566792) /* 0x54f148 */));
    // 00504a05  dd0550f15400           -fld qword ptr [0x54f150]
    cpu.fpu.push(x86::Float(app->getMemory<double>(x86::reg32(5566800) /* 0x54f150 */)));
    // 00504a0b  e822e90100             -call 0x523332
    cpu.esp -= 4;
    sub_523332(app, cpu);
    if (cpu.terminate) return;
    // 00504a10  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00504a12  ba08000000             -mov edx, 8
    cpu.edx = 8 /*0x8*/;
    // 00504a17  83e003                 -and eax, 3
    cpu.eax &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 00504a1a  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00504a1c  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 00504a1f  db0424                 -fild dword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp))));
    // 00504a22  def9                   -fdivp st(1)
    cpu.fpu.st(1) /= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00504a24  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00504a27  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00504a28  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_504a30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00504a30  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00504a31  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00504a32  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00504a33  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00504a34  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00504a37  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00504a39  b83f000000             -mov eax, 0x3f
    cpu.eax = 63 /*0x3f*/;
    // 00504a3e  e8adffffff             -call 0x5049f0
    cpu.esp -= 4;
    sub_5049f0(app, cpu);
    if (cpu.terminate) return;
    // 00504a43  d84c2420               -fmul dword ptr [esp + 0x20]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(32) /* 0x20 */));
    // 00504a47  d9e0                   -fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
    // 00504a49  d9e8                   -fld1 
    cpu.fpu.push(1.0);
    // 00504a4b  d9ea                   -fldl2e 
    cpu.fpu.push(1.4426950408889634);
    // 00504a4d  d8ca                   -fmul st(2)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(2));
    // 00504a4f  ddd2                   -fst st(2)
    cpu.fpu.st(2) = x86::Float(cpu.fpu.st(0));
    // 00504a51  d9f8                   -fprem 
    cpu.fpu.st(0) = cpu.fpu.rem(cpu.fpu.st(0), cpu.fpu.st(1));
    // 00504a53  d9f0                   -f2xm1 
    cpu.fpu.st(0) = cpu.fpu.f2xm1(cpu.fpu.st(0));
    // 00504a55  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00504a57  d9fd                   -fscale 
    cpu.fpu.st(0) = cpu.fpu.scale(cpu.fpu.st(0), cpu.fpu.st(1));
    // 00504a59  ddd9                   -fstp st(1)
    cpu.fpu.st(1) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00504a5b  d9e8                   -fld1 
    cpu.fpu.push(1.0);
    // 00504a5d  dee1                   -fsubrp st(1)
    cpu.fpu.st(1) = cpu.fpu.st(0) - x86::Float(cpu.fpu.st(1));
    cpu.fpu.pop();
    // 00504a5f  d9e8                   -fld1 
    cpu.fpu.push(1.0);
    // 00504a61  def1                   -fdivrp st(1)
    cpu.fpu.st(1) = cpu.fpu.st(0) / x86::Float(cpu.fpu.st(1));
    cpu.fpu.pop();
    // 00504a63  bf0000803f             -mov edi, 0x3f800000
    cpu.edi = 1065353216 /*0x3f800000*/;
    // 00504a68  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00504a6a  d95c2408               -fstp dword ptr [esp + 8]
    app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x00504a6e:
    // 00504a6e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00504a70  e87bffffff             -call 0x5049f0
    cpu.esp -= 4;
    sub_5049f0(app, cpu);
    if (cpu.terminate) return;
    // 00504a75  d84c2420               -fmul dword ptr [esp + 0x20]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(32) /* 0x20 */));
    // 00504a79  d9e0                   -fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
    // 00504a7b  d9e8                   -fld1 
    cpu.fpu.push(1.0);
    // 00504a7d  d9ea                   -fldl2e 
    cpu.fpu.push(1.4426950408889634);
    // 00504a7f  d8ca                   -fmul st(2)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(2));
    // 00504a81  ddd2                   -fst st(2)
    cpu.fpu.st(2) = x86::Float(cpu.fpu.st(0));
    // 00504a83  d9f8                   -fprem 
    cpu.fpu.st(0) = cpu.fpu.rem(cpu.fpu.st(0), cpu.fpu.st(1));
    // 00504a85  d9f0                   -f2xm1 
    cpu.fpu.st(0) = cpu.fpu.f2xm1(cpu.fpu.st(0));
    // 00504a87  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00504a89  d9fd                   -fscale 
    cpu.fpu.st(0) = cpu.fpu.scale(cpu.fpu.st(0), cpu.fpu.st(1));
    // 00504a8b  ddd9                   -fstp st(1)
    cpu.fpu.st(1) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00504a8d  d9e8                   -fld1 
    cpu.fpu.push(1.0);
    // 00504a8f  dee1                   -fsubrp st(1)
    cpu.fpu.st(1) = cpu.fpu.st(0) - x86::Float(cpu.fpu.st(1));
    cpu.fpu.pop();
    // 00504a91  d84c2408               -fmul dword ptr [esp + 8]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */));
    // 00504a95  d95c2404               -fstp dword ptr [esp + 4]
    app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00504a99  817c24040000803f       +cmp dword ptr [esp + 4], 0x3f800000
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1065353216 /*0x3f800000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00504aa1  7f3a                   -jg 0x504add
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00504add;
    }
    // 00504aa3  d9ee                   +fldz 
    cpu.fpu.push(0.0);
    // 00504aa5  d85c2404               +fcomp dword ptr [esp + 4]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    cpu.fpu.pop();
    // 00504aa9  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00504aab  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 00504aac  7606                   -jbe 0x504ab4
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00504ab4;
    }
    // 00504aae  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00504ab0  89742404               -mov dword ptr [esp + 4], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.esi;
L_0x00504ab4:
    // 00504ab4  d9442404               -fld dword ptr [esp + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 00504ab8  d80d58f15400           -fmul dword ptr [0x54f158]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5566808) /* 0x54f158 */));
    // 00504abe  41                     -inc ecx
    (cpu.ecx)++;
    // 00504abf  42                     -inc edx
    (cpu.edx)++;
    // 00504ac0  d9542404               -fst dword ptr [esp + 4]
    app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    // 00504ac4  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00504ac7  db1c24                 -fistp dword ptr [esp]
    app->getMemory<x86::reg32>(cpu.esp) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 00504aca  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00504acb  8841ff                 -mov byte ptr [ecx - 1], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(-1) /* -0x1 */) = cpu.al;
    // 00504ace  83fa40                 +cmp edx, 0x40
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
    // 00504ad1  7c9b                   -jl 0x504a6e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00504a6e;
    }
    // 00504ad3  83c40c                 +add esp, 0xc
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
    // 00504ad6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00504ad7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00504ad8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00504ad9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00504ada  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00504add:
    // 00504add  897c2404               -mov dword ptr [esp + 4], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 00504ae1  ebd1                   -jmp 0x504ab4
    goto L_0x00504ab4;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_504af0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00504af0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00504af1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00504af2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00504af3  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00504af5  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00504af7  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00504af9  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 00504afb  ff15c4a2a000           -call dword ptr [0xa0a2c4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10527428) /* 0xa0a2c4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00504b01  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00504b03  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00504b05  6a05                   -push 5
    app->getMemory<x86::reg32>(cpu.esp-4) = 5 /*0x5*/;
    cpu.esp -= 4;
    // 00504b07  6a09                   -push 9
    app->getMemory<x86::reg32>(cpu.esp-4) = 9 /*0x9*/;
    cpu.esp -= 4;
    // 00504b09  6a05                   -push 5
    app->getMemory<x86::reg32>(cpu.esp-4) = 5 /*0x5*/;
    cpu.esp -= 4;
    // 00504b0b  6a09                   -push 9
    app->getMemory<x86::reg32>(cpu.esp-4) = 9 /*0x9*/;
    cpu.esp -= 4;
    // 00504b0d  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00504b0f  ff151ca3a000           -call dword ptr [0xa0a31c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10527516) /* 0xa0a31c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00504b15  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00504b19  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00504b1a  8b4c2418               -mov ecx, dword ptr [esp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00504b1e  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00504b1f  8b5c2418               -mov ebx, dword ptr [esp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00504b23  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00504b24  ff1564a7a000           -call dword ptr [0xa0a764]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10528612) /* 0xa0a764 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00504b2a  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00504b2c  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00504b2e  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 00504b30  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 00504b32  ff15c4a2a000           -call dword ptr [0xa0a2c4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10527428) /* 0xa0a2c4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00504b38  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00504b3a  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00504b3c  6a0d                   -push 0xd
    app->getMemory<x86::reg32>(cpu.esp-4) = 13 /*0xd*/;
    cpu.esp -= 4;
    // 00504b3e  6a09                   -push 9
    app->getMemory<x86::reg32>(cpu.esp-4) = 9 /*0x9*/;
    cpu.esp -= 4;
    // 00504b40  6a0d                   -push 0xd
    app->getMemory<x86::reg32>(cpu.esp-4) = 13 /*0xd*/;
    cpu.esp -= 4;
    // 00504b42  6a09                   -push 9
    app->getMemory<x86::reg32>(cpu.esp-4) = 9 /*0x9*/;
    cpu.esp -= 4;
    // 00504b44  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00504b46  8b742434               -mov esi, dword ptr [esp + 0x34]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00504b4a  ff151ca3a000           -call dword ptr [0xa0a31c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10527516) /* 0xa0a31c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00504b50  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00504b51  8b7c2418               -mov edi, dword ptr [esp + 0x18]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00504b55  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00504b56  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00504b57  ff1564a7a000           -call dword ptr [0xa0a764]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10528612) /* 0xa0a764 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00504b5d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00504b5e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00504b5f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00504b60  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_504b70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00504b70  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00504b71  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00504b72  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00504b73  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00504b75  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00504b77  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00504b79  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 00504b7b  ff15c4a2a000           -call dword ptr [0xa0a2c4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10527428) /* 0xa0a2c4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00504b81  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00504b83  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00504b85  6a05                   -push 5
    app->getMemory<x86::reg32>(cpu.esp-4) = 5 /*0x5*/;
    cpu.esp -= 4;
    // 00504b87  6a09                   -push 9
    app->getMemory<x86::reg32>(cpu.esp-4) = 9 /*0x9*/;
    cpu.esp -= 4;
    // 00504b89  6a05                   -push 5
    app->getMemory<x86::reg32>(cpu.esp-4) = 5 /*0x5*/;
    cpu.esp -= 4;
    // 00504b8b  6a09                   -push 9
    app->getMemory<x86::reg32>(cpu.esp-4) = 9 /*0x9*/;
    cpu.esp -= 4;
    // 00504b8d  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00504b8f  ff151ca3a000           -call dword ptr [0xa0a31c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10527516) /* 0xa0a31c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00504b95  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00504b99  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00504b9a  8b4c2418               -mov ecx, dword ptr [esp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00504b9e  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00504b9f  8b5c2418               -mov ebx, dword ptr [esp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00504ba3  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00504ba4  ff155ca7a000           -call dword ptr [0xa0a75c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10528604) /* 0xa0a75c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00504baa  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00504bac  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00504bae  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 00504bb0  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 00504bb2  ff15c4a2a000           -call dword ptr [0xa0a2c4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10527428) /* 0xa0a2c4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00504bb8  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00504bba  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00504bbc  6a0d                   -push 0xd
    app->getMemory<x86::reg32>(cpu.esp-4) = 13 /*0xd*/;
    cpu.esp -= 4;
    // 00504bbe  6a09                   -push 9
    app->getMemory<x86::reg32>(cpu.esp-4) = 9 /*0x9*/;
    cpu.esp -= 4;
    // 00504bc0  6a0d                   -push 0xd
    app->getMemory<x86::reg32>(cpu.esp-4) = 13 /*0xd*/;
    cpu.esp -= 4;
    // 00504bc2  6a09                   -push 9
    app->getMemory<x86::reg32>(cpu.esp-4) = 9 /*0x9*/;
    cpu.esp -= 4;
    // 00504bc4  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00504bc6  8b742434               -mov esi, dword ptr [esp + 0x34]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00504bca  ff151ca3a000           -call dword ptr [0xa0a31c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10527516) /* 0xa0a31c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00504bd0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00504bd1  8b7c2418               -mov edi, dword ptr [esp + 0x18]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00504bd5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00504bd6  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00504bd7  ff155ca7a000           -call dword ptr [0xa0a75c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10528604) /* 0xa0a75c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00504bdd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00504bde  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00504bdf  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00504be0  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_504bf0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00504bf0  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_504c00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00504c00  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00504c01  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00504c03  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00504c05  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00504c07  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00504c0b  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00504c0c  8b4c241c               -mov ecx, dword ptr [esp + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00504c10  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00504c11  8b5c241c               -mov ebx, dword ptr [esp + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00504c15  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00504c16  ff153ca3a000           -call dword ptr [0xa0a33c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10527548) /* 0xa0a33c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00504c1c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00504c1d  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_504c20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00504c20  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00504c21  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00504c23  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00504c25  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00504c27  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00504c2b  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00504c2c  8b4c241c               -mov ecx, dword ptr [esp + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00504c30  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00504c31  8b5c241c               -mov ebx, dword ptr [esp + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00504c35  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00504c36  ff153ca3a000           -call dword ptr [0xa0a33c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10527548) /* 0xa0a33c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00504c3c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00504c3d  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_504c40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00504c40  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00504c44  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00504c45  685cf15400             -push 0x54f15c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5566812 /*0x54f15c*/;
    cpu.esp -= 4;
    // 00504c4a  e871aafdff             -call 0x4df6c0
    cpu.esp -= 4;
    sub_4df6c0(app, cpu);
    if (cpu.terminate) return;
    // 00504c4f  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00504c52  b8726f5600             -mov eax, 0x566f72
    cpu.eax = 5664626 /*0x566f72*/;
    // 00504c57  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00504c5b  e81031ffff             -call 0x4f7d70
    cpu.esp -= 4;
    sub_4f7d70(app, cpu);
    if (cpu.terminate) return;
    // 00504c60  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00504c62  7403                   -je 0x504c67
    if (cpu.flags.zf)
    {
        goto L_0x00504c67;
    }
    // 00504c64  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00504c67:
    // 00504c67  b80a000000             -mov eax, 0xa
    cpu.eax = 10 /*0xa*/;
    // 00504c6c  e893b0fdff             -call 0x4dfd04
    cpu.esp -= 4;
    sub_4dfd04(app, cpu);
    if (cpu.terminate) return;
    // 00504c71  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_504c80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00504c80  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00504c81  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00504c82  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00504c83  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00504c84  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00504c85  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00504c86  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00504c89  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00504c8c  b9247f5600             -mov ecx, 0x567f24
    cpu.ecx = 5668644 /*0x567f24*/;
    // 00504c91  8b1d7ca7a000           -mov ebx, dword ptr [0xa0a77c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10528636) /* 0xa0a77c */);
    // 00504c97  8b1578a7a000           -mov edx, dword ptr [0xa0a778]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10528632) /* 0xa0a778 */);
    // 00504c9d  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 00504c9f  c1e314                 -shl ebx, 0x14
    cpu.ebx <<= 20 /*0x14*/ % 32;
    // 00504ca2  83fa01                 +cmp edx, 1
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
    // 00504ca5  0f8534010000           -jne 0x504ddf
    if (!cpu.flags.zf)
    {
        goto L_0x00504ddf;
    }
    // 00504cab  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x00504cad:
    // 00504cad  a3dc7d5600             -mov dword ptr [0x567ddc], eax
    app->getMemory<x86::reg32>(x86::reg32(5668316) /* 0x567ddc */) = cpu.eax;
    // 00504cb2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00504cb4  7506                   -jne 0x504cbc
    if (!cpu.flags.zf)
    {
        goto L_0x00504cbc;
    }
    // 00504cb6  8b2d88a7a000           -mov ebp, dword ptr [0xa0a788]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(10528648) /* 0xa0a788 */);
L_0x00504cbc:
    // 00504cbc  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00504cbe  0f8522010000           -jne 0x504de6
    if (!cpu.flags.zf)
    {
        goto L_0x00504de6;
    }
L_0x00504cc4:
    // 00504cc4  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
L_0x00504cc9:
    // 00504cc9  8b7904                 -mov edi, dword ptr [ecx + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00504ccc  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 00504cce  0fafc7                 -imul eax, edi
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edi)));
    // 00504cd1  8b7908                 -mov edi, dword ptr [ecx + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00504cd4  c1ff03                 -sar edi, 3
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (3 /*0x3*/ % 32));
    // 00504cd7  0faff8                 -imul edi, eax
    cpu.edi = x86::reg32(x86::sreg64(x86::sreg32(cpu.edi)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 00504cda  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00504cdc  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00504cdf  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00504ce1  f7ff                   -idiv edi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.edi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00504ce3  894114                 -mov dword ptr [ecx + 0x14], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 00504ce6  8139c0030000           +cmp dword ptr [ecx], 0x3c0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(960 /*0x3c0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00504cec  7507                   -jne 0x504cf5
    if (!cpu.flags.zf)
    {
        goto L_0x00504cf5;
    }
    // 00504cee  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00504cf0  7503                   -jne 0x504cf5
    if (!cpu.flags.zf)
    {
        goto L_0x00504cf5;
    }
    // 00504cf2  896914                 -mov dword ptr [ecx + 0x14], ebp
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */) = cpu.ebp;
L_0x00504cf5:
    // 00504cf5  813920030000           +cmp dword ptr [ecx], 0x320
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(800 /*0x320*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00504cfb  7e10                   -jle 0x504d0d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00504d0d;
    }
    // 00504cfd  833ddc7d560000         +cmp dword ptr [0x567ddc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5668316) /* 0x567ddc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00504d04  7407                   -je 0x504d0d
    if (cpu.flags.zf)
    {
        goto L_0x00504d0d;
    }
    // 00504d06  c7411400000000         -mov dword ptr [ecx + 0x14], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */) = 0 /*0x0*/;
L_0x00504d0d:
    // 00504d0d  83791000               +cmp dword ptr [ecx + 0x10], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00504d11  0f84d6000000           -je 0x504ded
    if (cpu.flags.zf)
    {
        goto L_0x00504ded;
    }
    // 00504d17  8b5114                 -mov edx, dword ptr [ecx + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 00504d1a  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00504d1c  0f8ecb000000           -jle 0x504ded
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00504ded;
    }
    // 00504d22  8d42ff                 -lea eax, [edx - 1]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 00504d25  8b7914                 -mov edi, dword ptr [ecx + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 00504d28  894118                 -mov dword ptr [ecx + 0x18], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 00504d2b  83ff03                 +cmp edi, 3
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
    // 00504d2e  7e07                   -jle 0x504d37
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00504d37;
    }
    // 00504d30  c7411403000000         -mov dword ptr [ecx + 0x14], 3
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */) = 3 /*0x3*/;
L_0x00504d37:
    // 00504d37  83791803               +cmp dword ptr [ecx + 0x18], 3
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00504d3b  7e07                   -jle 0x504d44
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00504d44;
    }
    // 00504d3d  c7411803000000         -mov dword ptr [ecx + 0x18], 3
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */) = 3 /*0x3*/;
L_0x00504d44:
    // 00504d44  46                     -inc esi
    (cpu.esi)++;
    // 00504d45  83c128                 -add ecx, 0x28
    (cpu.ecx) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 00504d48  83fe10                 +cmp esi, 0x10
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
    // 00504d4b  0f8e78ffffff           -jle 0x504cc9
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00504cc9;
    }
    // 00504d51  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 00504d54  a178a7a000             -mov eax, dword ptr [0xa0a778]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10528632) /* 0xa0a778 */);
    // 00504d59  89416c                 -mov dword ptr [ecx + 0x6c], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(108) /* 0x6c */) = cpu.eax;
    // 00504d5c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00504d5e  7538                   -jne 0x504d98
    if (!cpu.flags.zf)
    {
        goto L_0x00504d98;
    }
    // 00504d60  a180a7a000             -mov eax, dword ptr [0xa0a780]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10528640) /* 0xa0a780 */);
    // 00504d65  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00504d67  c1f908                 -sar ecx, 8
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (8 /*0x8*/ % 32));
    // 00504d6a  83f901                 +cmp ecx, 1
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
    // 00504d6d  750a                   -jne 0x504d79
    if (!cpu.flags.zf)
    {
        goto L_0x00504d79;
    }
    // 00504d6f  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 00504d72  c7416c02000000         -mov dword ptr [ecx + 0x6c], 2
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(108) /* 0x6c */) = 2 /*0x2*/;
L_0x00504d79:
    // 00504d79  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00504d7b  751b                   -jne 0x504d98
    if (!cpu.flags.zf)
    {
        goto L_0x00504d98;
    }
    // 00504d7d  833d7ca7a00006         +cmp dword ptr [0xa0a77c], 6
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10528636) /* 0xa0a77c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(6 /*0x6*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00504d84  7c12                   -jl 0x504d98
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00504d98;
    }
    // 00504d86  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00504d88  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00504d8b  891df47d5600           -mov dword ptr [0x567df4], ebx
    app->getMemory<x86::reg32>(x86::reg32(5668340) /* 0x567df4 */) = cpu.ebx;
    // 00504d91  c7406c03000000         -mov dword ptr [eax + 0x6c], 3
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(108) /* 0x6c */) = 3 /*0x3*/;
L_0x00504d98:
    // 00504d98  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00504d9a  ff152ca3a000           -call dword ptr [0xa0a32c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10527532) /* 0xa0a32c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00504da0  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00504da2  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00504da4  ff1528a3a000           -call dword ptr [0xa0a328]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10527528) /* 0xa0a328 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00504daa  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00504dac  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00504dae  ff1528a3a000           -call dword ptr [0xa0a328]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10527528) /* 0xa0a328 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00504db4  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00504db6  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00504db9  895870                 -mov dword ptr [eax + 0x70], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(112) /* 0x70 */) = cpu.ebx;
    // 00504dbc  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00504dbe  7e0b                   -jle 0x504dcb
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00504dcb;
    }
    // 00504dc0  8d430f                 -lea eax, [ebx + 0xf]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(15) /* 0xf */);
    // 00504dc3  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 00504dc6  24f0                   -and al, 0xf0
    cpu.al &= x86::reg8(x86::sreg8(240 /*0xf0*/));
    // 00504dc8  894170                 -mov dword ptr [ecx + 0x70], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(112) /* 0x70 */) = cpu.eax;
L_0x00504dcb:
    // 00504dcb  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00504dce  c7407401000000         -mov dword ptr [eax + 0x74], 1
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(116) /* 0x74 */) = 1 /*0x1*/;
    // 00504dd5  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00504dd8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00504dd9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00504dda  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00504ddb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00504ddc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00504ddd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00504dde  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00504ddf:
    // 00504ddf  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00504de1  e9c7feffff             -jmp 0x504cad
    goto L_0x00504cad;
L_0x00504de6:
    // 00504de6  01db                   +add ebx, ebx
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
    // 00504de8  e9d7feffff             -jmp 0x504cc4
    goto L_0x00504cc4;
L_0x00504ded:
    // 00504ded  c7411800000000         -mov dword ptr [ecx + 0x18], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 00504df4  8b4118                 -mov eax, dword ptr [ecx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 00504df7  894114                 -mov dword ptr [ecx + 0x14], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 00504dfa  e945ffffff             -jmp 0x504d44
    goto L_0x00504d44;
}

/* align: skip 0x90 */
void Application::sub_504e00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00504e00  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00504e01  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00504e02  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00504e03  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00504e04  8b15387e5600           -mov edx, dword ptr [0x567e38]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5668408) /* 0x567e38 */);
    // 00504e0a  bd387e5600             -mov ebp, 0x567e38
    cpu.ebp = 5668408 /*0x567e38*/;
    // 00504e0f  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00504e11  7407                   -je 0x504e1a
    if (cpu.flags.zf)
    {
        goto L_0x00504e1a;
    }
L_0x00504e13:
    // 00504e13  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00504e15  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00504e16  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00504e17  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00504e18  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00504e19  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00504e1a:
    // 00504e1a  bb80000000             -mov ebx, 0x80
    cpu.ebx = 128 /*0x80*/;
    // 00504e1f  b958464433             -mov ecx, 0x33444658
    cpu.ecx = 860112472 /*0x33444658*/;
    // 00504e24  be68000000             -mov esi, 0x68
    cpu.esi = 104 /*0x68*/;
    // 00504e29  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00504e2b  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 00504e30  e80bb8fdff             -call 0x4e0640
    cpu.esp -= 4;
    sub_4e0640(app, cpu);
    if (cpu.terminate) return;
    // 00504e35  bb80000000             -mov ebx, 0x80
    cpu.ebx = 128 /*0x80*/;
    // 00504e3a  b800010000             -mov eax, 0x100
    cpu.eax = 256 /*0x100*/;
    // 00504e3f  890d387e5600           -mov dword ptr [0x567e38], ecx
    app->getMemory<x86::reg32>(x86::reg32(5668408) /* 0x567e38 */) = cpu.ecx;
    // 00504e45  8935407e5600           -mov dword ptr [0x567e40], esi
    app->getMemory<x86::reg32>(x86::reg32(5668416) /* 0x567e40 */) = cpu.esi;
    // 00504e4b  893d487e5600           -mov dword ptr [0x567e48], edi
    app->getMemory<x86::reg32>(x86::reg32(5668424) /* 0x567e48 */) = cpu.edi;
    // 00504e51  893d507e5600           -mov dword ptr [0x567e50], edi
    app->getMemory<x86::reg32>(x86::reg32(5668432) /* 0x567e50 */) = cpu.edi;
    // 00504e57  893d547e5600           -mov dword ptr [0x567e54], edi
    app->getMemory<x86::reg32>(x86::reg32(5668436) /* 0x567e54 */) = cpu.edi;
    // 00504e5d  893d5c7e5600           -mov dword ptr [0x567e5c], edi
    app->getMemory<x86::reg32>(x86::reg32(5668444) /* 0x567e5c */) = cpu.edi;
    // 00504e63  893d607e5600           -mov dword ptr [0x567e60], edi
    app->getMemory<x86::reg32>(x86::reg32(5668448) /* 0x567e60 */) = cpu.edi;
    // 00504e69  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 00504e6e  be10000000             -mov esi, 0x10
    cpu.esi = 16 /*0x10*/;
    // 00504e73  bffc7e5600             -mov edi, 0x567efc
    cpu.edi = 5668604 /*0x567efc*/;
    // 00504e78  891d3c7e5600           -mov dword ptr [0x567e3c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5668412) /* 0x567e3c */) = cpu.ebx;
    // 00504e7e  a34c7e5600             -mov dword ptr [0x567e4c], eax
    app->getMemory<x86::reg32>(x86::reg32(5668428) /* 0x567e4c */) = cpu.eax;
    // 00504e83  bb00010000             -mov ebx, 0x100
    cpu.ebx = 256 /*0x100*/;
    // 00504e88  8a25447e5600           -mov ah, byte ptr [0x567e44]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(5668420) /* 0x567e44 */);
    // 00504e8e  890d6c7e5600           -mov dword ptr [0x567e6c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5668460) /* 0x567e6c */) = cpu.ecx;
    // 00504e94  8935747e5600           -mov dword ptr [0x567e74], esi
    app->getMemory<x86::reg32>(x86::reg32(5668468) /* 0x567e74 */) = cpu.esi;
    // 00504e9a  893d787e5600           -mov dword ptr [0x567e78], edi
    app->getMemory<x86::reg32>(x86::reg32(5668472) /* 0x567e78 */) = cpu.edi;
    // 00504ea0  be60f15400             -mov esi, 0x54f160
    cpu.esi = 5566816 /*0x54f160*/;
    // 00504ea5  80cc0e                 -or ah, 0xe
    cpu.ah |= x86::reg8(x86::sreg8(14 /*0xe*/));
    // 00504ea8  891d587e5600           -mov dword ptr [0x567e58], ebx
    app->getMemory<x86::reg32>(x86::reg32(5668440) /* 0x567e58 */) = cpu.ebx;
    // 00504eae  8d7d4c                 -lea edi, [ebp + 0x4c]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(76) /* 0x4c */);
    // 00504eb1  bbe47e5600             -mov ebx, 0x567ee4
    cpu.ebx = 5668580 /*0x567ee4*/;
    // 00504eb6  8825447e5600           -mov byte ptr [0x567e44], ah
    app->getMemory<x86::reg8>(x86::reg32(5668420) /* 0x567e44 */) = cpu.ah;
    // 00504ebc  88e2                   -mov dl, ah
    cpu.dl = cpu.ah;
    // 00504ebe  b809000000             -mov eax, 9
    cpu.eax = 9 /*0x9*/;
    // 00504ec3  80e2fe                 -and dl, 0xfe
    cpu.dl &= x86::reg8(x86::sreg8(254 /*0xfe*/));
    // 00504ec6  891d707e5600           -mov dword ptr [0x567e70], ebx
    app->getMemory<x86::reg32>(x86::reg32(5668464) /* 0x567e70 */) = cpu.ebx;
    // 00504ecc  8815447e5600           -mov byte ptr [0x567e44], dl
    app->getMemory<x86::reg8>(x86::reg32(5668420) /* 0x567e44 */) = cpu.dl;
    // 00504ed2  bab87e5600             -mov edx, 0x567eb8
    cpu.edx = 5668536 /*0x567eb8*/;
    // 00504ed7  a3647e5600             -mov dword ptr [0x567e64], eax
    app->getMemory<x86::reg32>(x86::reg32(5668452) /* 0x567e64 */) = cpu.eax;
    // 00504edc  8915687e5600           -mov dword ptr [0x567e68], edx
    app->getMemory<x86::reg32>(x86::reg32(5668456) /* 0x567e68 */) = cpu.edx;
    // 00504ee2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x00504ee3:
    // 00504ee3  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00504ee5  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00504ee7  3c00                   +cmp al, 0
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
    // 00504ee9  7410                   -je 0x504efb
    if (cpu.flags.zf)
    {
        goto L_0x00504efb;
    }
    // 00504eeb  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00504eee  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00504ef1  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00504ef4  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00504ef7  3c00                   +cmp al, 0
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
    // 00504ef9  75e8                   -jne 0x504ee3
    if (!cpu.flags.zf)
    {
        goto L_0x00504ee3;
    }
L_0x00504efb:
    // 00504efb  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00504efc  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00504efe  8a35d87d5600           -mov dh, byte ptr [0x567dd8]
    cpu.dh = app->getMemory<x86::reg8>(x86::reg32(5668312) /* 0x567dd8 */);
    // 00504f04  a3a47e5600             -mov dword ptr [0x567ea4], eax
    app->getMemory<x86::reg32>(x86::reg32(5668516) /* 0x567ea4 */) = cpu.eax;
    // 00504f09  f6c601                 +test dh, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 1 /*0x1*/));
    // 00504f0c  0f856d000000           -jne 0x504f7f
    if (!cpu.flags.zf)
    {
        goto L_0x00504f7f;
    }
    // 00504f12  e8d9f4ffff             -call 0x5043f0
    cpu.esp -= 4;
    sub_5043f0(app, cpu);
    if (cpu.terminate) return;
    // 00504f17  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00504f19  0f84f4feffff           -je 0x504e13
    if (cpu.flags.zf)
    {
        goto L_0x00504e13;
    }
    // 00504f1f  833d70a2a00000         +cmp dword ptr [0xa0a270], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10527344) /* 0xa0a270 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00504f26  744b                   -je 0x504f73
    if (cpu.flags.zf)
    {
        goto L_0x00504f73;
    }
    // 00504f28  833d78a2a00000         +cmp dword ptr [0xa0a278], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10527352) /* 0xa0a278 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00504f2f  7442                   -je 0x504f73
    if (cpu.flags.zf)
    {
        goto L_0x00504f73;
    }
    // 00504f31  833d74a2a00000         +cmp dword ptr [0xa0a274], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10527348) /* 0xa0a274 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00504f38  7439                   -je 0x504f73
    if (cpu.flags.zf)
    {
        goto L_0x00504f73;
    }
    // 00504f3a  6874a7a000             -push 0xa0a774
    app->getMemory<x86::reg32>(cpu.esp-4) = 10528628 /*0xa0a774*/;
    cpu.esp -= 4;
    // 00504f3f  ff1578a2a000           -call dword ptr [0xa0a278]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10527352) /* 0xa0a278 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00504f45  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00504f47  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00504f49  7406                   -je 0x504f51
    if (cpu.flags.zf)
    {
        goto L_0x00504f51;
    }
    // 00504f4b  8b3d74a7a000           -mov edi, dword ptr [0xa0a774]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(10528628) /* 0xa0a774 */);
L_0x00504f51:
    // 00504f51  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00504f53  7e1e                   -jle 0x504f73
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00504f73;
    }
    // 00504f55  ff1570a2a000           -call dword ptr [0xa0a270]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10527344) /* 0xa0a270 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00504f5b  6874a7a000             -push 0xa0a774
    app->getMemory<x86::reg32>(cpu.esp-4) = 10528628 /*0xa0a774*/;
    cpu.esp -= 4;
    // 00504f60  ff1574a2a000           -call dword ptr [0xa0a274]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10527348) /* 0xa0a274 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00504f66  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00504f68  e813fdffff             -call 0x504c80
    cpu.esp -= 4;
    sub_504c80(app, cpu);
    if (cpu.terminate) return;
    // 00504f6d  ff157ca2a000           -call dword ptr [0xa0a27c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10527356) /* 0xa0a27c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00504f73:
    // 00504f73  e848faffff             -call 0x5049c0
    cpu.esp -= 4;
    sub_5049c0(app, cpu);
    if (cpu.terminate) return;
    // 00504f78  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00504f7a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00504f7b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00504f7c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00504f7d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00504f7e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00504f7f:
    // 00504f7f  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00504f81  e8fafcffff             -call 0x504c80
    cpu.esp -= 4;
    sub_504c80(app, cpu);
    if (cpu.terminate) return;
    // 00504f86  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00504f88  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00504f89  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00504f8a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00504f8b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00504f8c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_504f90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00504f90  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00504f91  83ec50                 -sub esp, 0x50
    (cpu.esp) -= x86::reg32(x86::sreg32(80 /*0x50*/));
    // 00504f94  b86cf15400             -mov eax, 0x54f16c
    cpu.eax = 5566828 /*0x54f16c*/;
    // 00504f99  e8329b0000             -call 0x50ead0
    cpu.esp -= 4;
    sub_50ead0(app, cpu);
    if (cpu.terminate) return;
    // 00504f9e  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00504fa0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00504fa2  0f85cb000000           -jne 0x505073
    if (!cpu.flags.zf)
    {
        goto L_0x00505073;
    }
    // 00504fa8  e843f4ffff             -call 0x5043f0
    cpu.esp -= 4;
    sub_5043f0(app, cpu);
    if (cpu.terminate) return;
    // 00504fad  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00504faf  0f84b7000000           -je 0x50506c
    if (cpu.flags.zf)
    {
        goto L_0x0050506c;
    }
    // 00504fb5  833d70a2a00000         +cmp dword ptr [0xa0a270], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10527344) /* 0xa0a270 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00504fbc  0f84a5000000           -je 0x505067
    if (cpu.flags.zf)
    {
        goto L_0x00505067;
    }
    // 00504fc2  833d78a2a00000         +cmp dword ptr [0xa0a278], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10527352) /* 0xa0a278 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00504fc9  0f8498000000           -je 0x505067
    if (cpu.flags.zf)
    {
        goto L_0x00505067;
    }
    // 00504fcf  833d74a2a00000         +cmp dword ptr [0xa0a274], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10527348) /* 0xa0a274 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00504fd6  0f848b000000           -je 0x505067
    if (cpu.flags.zf)
    {
        goto L_0x00505067;
    }
    // 00504fdc  6874a7a000             -push 0xa0a774
    app->getMemory<x86::reg32>(cpu.esp-4) = 10528628 /*0xa0a774*/;
    cpu.esp -= 4;
    // 00504fe1  ff1578a2a000           -call dword ptr [0xa0a278]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10527352) /* 0xa0a278 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00504fe7  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00504fe9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00504feb  7406                   -je 0x504ff3
    if (cpu.flags.zf)
    {
        goto L_0x00504ff3;
    }
    // 00504fed  8b1d74a7a000           -mov ebx, dword ptr [0xa0a774]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10528628) /* 0xa0a774 */);
L_0x00504ff3:
    // 00504ff3  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00504ff5  0f8e6c000000           -jle 0x505067
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00505067;
    }
    // 00504ffb  ff1570a2a000           -call dword ptr [0xa0a270]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10527344) /* 0xa0a270 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00505001  6874a7a000             -push 0xa0a774
    app->getMemory<x86::reg32>(cpu.esp-4) = 10528628 /*0xa0a774*/;
    cpu.esp -= 4;
    // 00505006  ff1574a2a000           -call dword ptr [0xa0a274]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10527348) /* 0xa0a274 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050500c  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0050500e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00505010  744f                   -je 0x505061
    if (cpu.flags.zf)
    {
        goto L_0x00505061;
    }
    // 00505012  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00505014  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00505015  ff1538a3a000           -call dword ptr [0xa0a338]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10527544) /* 0xa0a338 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050501b  8a1424                 -mov dl, byte ptr [esp]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp);
    // 0050501e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00505020  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 00505022  7414                   -je 0x505038
    if (cpu.flags.zf)
    {
        goto L_0x00505038;
    }
L_0x00505024:
    // 00505024  8a1404                 -mov dl, byte ptr [esp + eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + cpu.eax * 1);
    // 00505027  fec2                   -inc dl
    (cpu.dl)++;
    // 00505029  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0050502f  f682f04e560020         +test byte ptr [edx + 0x564ef0], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5656304) /* 0x564ef0 */) & 32 /*0x20*/));
    // 00505036  7444                   -je 0x50507c
    if (cpu.flags.zf)
    {
        goto L_0x0050507c;
    }
L_0x00505038:
    // 00505038  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 0050503a  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0050503c  ba78f15400             -mov edx, 0x54f178
    cpu.edx = 5566840 /*0x54f178*/;
    // 00505041  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00505043  e8c892feff             -call 0x4ee310
    cpu.esp -= 4;
    sub_4ee310(app, cpu);
    if (cpu.terminate) return;
    // 00505048  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0050504a  7c3b                   -jl 0x505087
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00505087;
    }
    // 0050504c  ba80f15400             -mov edx, 0x54f180
    cpu.edx = 5566848 /*0x54f180*/;
    // 00505051  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00505053  e8b892feff             -call 0x4ee310
    cpu.esp -= 4;
    sub_4ee310(app, cpu);
    if (cpu.terminate) return;
    // 00505058  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0050505a  7e2f                   -jle 0x50508b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0050508b;
    }
    // 0050505c  bb5f000000             -mov ebx, 0x5f
    cpu.ebx = 95 /*0x5f*/;
L_0x00505061:
    // 00505061  ff157ca2a000           -call dword ptr [0xa0a27c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10527356) /* 0xa0a27c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00505067:
    // 00505067  e854f9ffff             -call 0x5049c0
    cpu.esp -= 4;
    sub_5049c0(app, cpu);
    if (cpu.terminate) return;
L_0x0050506c:
    // 0050506c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0050506e  83c450                 +add esp, 0x50
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(80 /*0x50*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00505071  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00505072  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00505073:
    // 00505073  e8b8b3feff             -call 0x4f0430
    cpu.esp -= 4;
    sub_4f0430(app, cpu);
    if (cpu.terminate) return;
    // 00505078  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0050507a  ebf0                   -jmp 0x50506c
    goto L_0x0050506c;
L_0x0050507c:
    // 0050507c  8a740401               -mov dh, byte ptr [esp + eax + 1]
    cpu.dh = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1) /* 0x1 */ + cpu.eax * 1);
    // 00505080  40                     -inc eax
    (cpu.eax)++;
    // 00505081  84f6                   +test dh, dh
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & cpu.dh));
    // 00505083  759f                   -jne 0x505024
    if (!cpu.flags.zf)
    {
        goto L_0x00505024;
    }
    // 00505085  ebb1                   -jmp 0x505038
    goto L_0x00505038;
L_0x00505087:
    // 00505087  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 00505089  ebd6                   -jmp 0x505061
    goto L_0x00505061;
L_0x0050508b:
    // 0050508b  bb64000000             -mov ebx, 0x64
    cpu.ebx = 100 /*0x64*/;
    // 00505090  ff157ca2a000           -call dword ptr [0xa0a27c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10527356) /* 0xa0a27c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00505096  e825f9ffff             -call 0x5049c0
    cpu.esp -= 4;
    sub_5049c0(app, cpu);
    if (cpu.terminate) return;
    // 0050509b  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0050509d  83c450                 -add esp, 0x50
    (cpu.esp) += x86::reg32(x86::sreg32(80 /*0x50*/));
    // 005050a0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005050a1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_5050b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005050b0  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 005050b4  8b1574a7a000           -mov edx, dword ptr [0xa0a774]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10528628) /* 0xa0a774 */);
    // 005050ba  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 005050bc  39d1                   +cmp ecx, edx
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
    // 005050be  7c03                   -jl 0x5050c3
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x005050c3;
    }
    // 005050c0  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x005050c3:
    // 005050c3  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005050c4  ff1580a2a000           -call dword ptr [0xa0a280]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10527360) /* 0xa0a280 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005050ca  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 005050cf  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_5050e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005050e0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005050e1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 005050e2  e8b9010000             -call 0x5052a0
    cpu.esp -= 4;
    sub_5052a0(app, cpu);
    if (cpu.terminate) return;
    // 005050e7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005050e8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005050e9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_5050f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005050f0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 005050f1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005050f2  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 005050f5  8a25d87d5600           -mov ah, byte ptr [0x567dd8]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(5668312) /* 0x567dd8 */);
    // 005050fb  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 005050fd  f6c401                 +test ah, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 1 /*0x1*/));
    // 00505100  7547                   -jne 0x505149
    if (!cpu.flags.zf)
    {
        goto L_0x00505149;
    }
    // 00505102  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00505104  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00505106:
    // 00505106  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00505109  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0050510c  db0424                 -fild dword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp))));
    // 0050510f  40                     -inc eax
    (cpu.eax)++;
    // 00505110  d99a54a3a000           -fstp dword ptr [edx + 0xa0a354]
    app->getMemory<float>(cpu.edx + x86::reg32(10527572) /* 0xa0a354 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00505116  3d00010000             +cmp eax, 0x100
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(256 /*0x100*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050511b  7ce9                   -jl 0x505106
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00505106;
    }
    // 0050511d  833d187e560000         +cmp dword ptr [0x567e18], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5668376) /* 0x567e18 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00505124  742b                   -je 0x505151
    if (cpu.flags.zf)
    {
        goto L_0x00505151;
    }
L_0x00505126:
    // 00505126  8b35247e5600           -mov esi, dword ptr [0x567e24]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5668388) /* 0x567e24 */);
    // 0050512c  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0050512e  7510                   -jne 0x505140
    if (!cpu.flags.zf)
    {
        goto L_0x00505140;
    }
    // 00505130  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00505131  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00505132  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00505133  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00505134  2eff1594445300         -call dword ptr cs:[0x534494]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457044) /* 0x534494 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050513b  a3247e5600             -mov dword ptr [0x567e24], eax
    app->getMemory<x86::reg32>(x86::reg32(5668388) /* 0x567e24 */) = cpu.eax;
L_0x00505140:
    // 00505140  e8abf2ffff             -call 0x5043f0
    cpu.esp -= 4;
    sub_5043f0(app, cpu);
    if (cpu.terminate) return;
    // 00505145  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00505147  7514                   -jne 0x50515d
    if (!cpu.flags.zf)
    {
        goto L_0x0050515d;
    }
L_0x00505149:
    // 00505149  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0050514b  83c404                 +add esp, 4
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
    // 0050514e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050514f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00505150  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00505151:
    // 00505151  c705187e5600404c5000   -mov dword ptr [0x567e18], 0x504c40
    app->getMemory<x86::reg32>(x86::reg32(5668376) /* 0x567e18 */) = 5262400 /*0x504c40*/;
    // 0050515b  ebc9                   -jmp 0x505126
    goto L_0x00505126;
L_0x0050515d:
    // 0050515d  ff1570a2a000           -call dword ptr [0xa0a270]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10527344) /* 0xa0a270 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00505163  6874a7a000             -push 0xa0a774
    app->getMemory<x86::reg32>(cpu.esp-4) = 10528628 /*0xa0a774*/;
    cpu.esp -= 4;
    // 00505168  ff1574a2a000           -call dword ptr [0xa0a274]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10527348) /* 0xa0a274 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050516e  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00505170  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00505172  74d5                   -je 0x505149
    if (cpu.flags.zf)
    {
        goto L_0x00505149;
    }
    // 00505174  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00505176  e835ffffff             -call 0x5050b0
    cpu.esp -= 4;
    sub_5050b0(app, cpu);
    if (cpu.terminate) return;
    // 0050517b  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0050517d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0050517f  74c8                   -je 0x505149
    if (cpu.flags.zf)
    {
        goto L_0x00505149;
    }
    // 00505181  b8387e5600             -mov eax, 0x567e38
    cpu.eax = 5668408 /*0x567e38*/;
    // 00505186  8b1d74a7a000           -mov ebx, dword ptr [0xa0a774]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10528628) /* 0xa0a774 */);
    // 0050518c  e8effaffff             -call 0x504c80
    cpu.esp -= 4;
    sub_504c80(app, cpu);
    if (cpu.terminate) return;
    // 00505191  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00505193  74b4                   -je 0x505149
    if (cpu.flags.zf)
    {
        goto L_0x00505149;
    }
    // 00505195  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00505196  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 0050519b  b8e0505000             -mov eax, 0x5050e0
    cpu.eax = 5263584 /*0x5050e0*/;
    // 005051a0  893dd87d5600           -mov dword ptr [0x567dd8], edi
    app->getMemory<x86::reg32>(x86::reg32(5668312) /* 0x567dd8 */) = cpu.edi;
    // 005051a6  e8752affff             -call 0x4f7c20
    cpu.esp -= 4;
    sub_4f7c20(app, cpu);
    if (cpu.terminate) return;
    // 005051ab  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005051ac  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 005051ae  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 005051b1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005051b2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005051b3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_5051c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005051c0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 005051c1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005051c2  8b152c7e5600           -mov edx, dword ptr [0x567e2c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5668396) /* 0x567e2c */);
    // 005051c8  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 005051ca  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 005051cc  7512                   -jne 0x5051e0
    if (!cpu.flags.zf)
    {
        goto L_0x005051e0;
    }
    // 005051ce  833ddc7d560000         +cmp dword ptr [0x567ddc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5668316) /* 0x567ddc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005051d5  7509                   -jne 0x5051e0
    if (!cpu.flags.zf)
    {
        goto L_0x005051e0;
    }
    // 005051d7  833df47d560000         +cmp dword ptr [0x567df4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5668340) /* 0x567df4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005051de  7505                   -jne 0x5051e5
    if (!cpu.flags.zf)
    {
        goto L_0x005051e5;
    }
L_0x005051e0:
    // 005051e0  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 005051e2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005051e3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005051e4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005051e5:
    // 005051e5  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 005051e6  682c7e5600             -push 0x567e2c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5668396 /*0x567e2c*/;
    cpu.esp -= 4;
    // 005051eb  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 005051ec  e895ec0200             -call 0x533e86
    cpu.esp -= 4;
    sub_533e86(app, cpu);
    if (cpu.terminate) return;
    // 005051f1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005051f3  75eb                   -jne 0x5051e0
    if (!cpu.flags.zf)
    {
        goto L_0x005051e0;
    }
    // 005051f5  833d287e560000         +cmp dword ptr [0x567e28], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5668392) /* 0x567e28 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005051fc  7426                   -je 0x505224
    if (cpu.flags.zf)
    {
        goto L_0x00505224;
    }
    // 005051fe  ba10000000             -mov edx, 0x10
    cpu.edx = 16 /*0x10*/;
L_0x00505203:
    // 00505203  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00505204  8b2dec7d5600           -mov ebp, dword ptr [0x567dec]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5668332) /* 0x567dec */);
    // 0050520a  a12c7e5600             -mov eax, dword ptr [0x567e2c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5668396) /* 0x567e2c */);
    // 0050520f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00505210  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 00505212  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00505213  ff5150                 -call dword ptr [ecx + 0x50]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(80) /* 0x50 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00505216  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00505218  7511                   -jne 0x50522b
    if (!cpu.flags.zf)
    {
        goto L_0x0050522b;
    }
    // 0050521a  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0050521f  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00505221  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00505222  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00505223  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00505224:
    // 00505224  ba11000000             -mov edx, 0x11
    cpu.edx = 17 /*0x11*/;
    // 00505229  ebd8                   -jmp 0x505203
    goto L_0x00505203;
L_0x0050522b:
    // 0050522b  a12c7e5600             -mov eax, dword ptr [0x567e2c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5668396) /* 0x567e2c */);
    // 00505230  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00505231  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00505233  ff5208                 -call dword ptr [edx + 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00505236  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00505238  a32c7e5600             -mov dword ptr [0x567e2c], eax
    app->getMemory<x86::reg32>(x86::reg32(5668396) /* 0x567e2c */) = cpu.eax;
    // 0050523d  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0050523f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00505240  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00505241  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_505250(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00505250  8b152c7e5600           -mov edx, dword ptr [0x567e2c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5668396) /* 0x567e2c */);
    // 00505256  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00505258  7506                   -jne 0x505260
    if (!cpu.flags.zf)
    {
        goto L_0x00505260;
    }
    // 0050525a  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0050525f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00505260:
    // 00505260  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00505262  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00505263  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 00505265  ff5208                 -call dword ptr [edx + 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00505268  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0050526a  890d2c7e5600           -mov dword ptr [0x567e2c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5668396) /* 0x567e2c */) = cpu.ecx;
    // 00505270  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00505275  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void Application::sub_505280(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00505280  f605d87d560002         +test byte ptr [0x567dd8], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(5668312) /* 0x567dd8 */) & 2 /*0x2*/));
    // 00505287  7501                   -jne 0x50528a
    if (!cpu.flags.zf)
    {
        goto L_0x0050528a;
    }
    // 00505289  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0050528a:
    // 0050528a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0050528b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050528c  ff1584a2a000           -call dword ptr [0xa0a284]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10527364) /* 0xa0a284 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00505292  8025d87d5600fd         -and byte ptr [0x567dd8], 0xfd
    app->getMemory<x86::reg8>(x86::reg32(5668312) /* 0x567dd8 */) &= x86::reg8(x86::sreg8(253 /*0xfd*/));
    // 00505299  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050529a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050529b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_5052a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005052a0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 005052a1  8b15d87d5600           -mov edx, dword ptr [0x567dd8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5668312) /* 0x567dd8 */);
    // 005052a7  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 005052ac  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 005052ae  7450                   -je 0x505300
    if (cpu.flags.zf)
    {
        goto L_0x00505300;
    }
    // 005052b0  f605d87d560002         +test byte ptr [0x567dd8], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(5668312) /* 0x567dd8 */) & 2 /*0x2*/));
    // 005052b7  754b                   -jne 0x505304
    if (!cpu.flags.zf)
    {
        goto L_0x00505304;
    }
L_0x005052b9:
    // 005052b9  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 005052ba  833d207e560000         +cmp dword ptr [0x567e20], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5668384) /* 0x567e20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005052c1  740a                   -je 0x5052cd
    if (cpu.flags.zf)
    {
        goto L_0x005052cd;
    }
    // 005052c3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005052c4  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 005052c6  8935207e5600           -mov dword ptr [0x567e20], esi
    app->getMemory<x86::reg32>(x86::reg32(5668384) /* 0x567e20 */) = cpu.esi;
    // 005052cc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x005052cd:
    // 005052cd  8b3d247e5600           -mov edi, dword ptr [0x567e24]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5668388) /* 0x567e24 */);
    // 005052d3  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 005052d5  740f                   -je 0x5052e6
    if (cpu.flags.zf)
    {
        goto L_0x005052e6;
    }
    // 005052d7  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 005052d8  2eff1588445300         -call dword ptr cs:[0x534488]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457032) /* 0x534488 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005052df  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 005052e1  a3247e5600             -mov dword ptr [0x567e24], eax
    app->getMemory<x86::reg32>(x86::reg32(5668388) /* 0x567e24 */) = cpu.eax;
L_0x005052e6:
    // 005052e6  ff157ca2a000           -call dword ptr [0xa0a27c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10527356) /* 0xa0a27c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005052ec  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 005052ee  e8cdf6ffff             -call 0x5049c0
    cpu.esp -= 4;
    sub_5049c0(app, cpu);
    if (cpu.terminate) return;
    // 005052f3  8915187e5600           -mov dword ptr [0x567e18], edx
    app->getMemory<x86::reg32>(x86::reg32(5668376) /* 0x567e18 */) = cpu.edx;
    // 005052f9  8915d87d5600           -mov dword ptr [0x567dd8], edx
    app->getMemory<x86::reg32>(x86::reg32(5668312) /* 0x567dd8 */) = cpu.edx;
    // 005052ff  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00505300:
    // 00505300  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00505302  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00505303  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00505304:
    // 00505304  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00505306  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00505308  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0050530a  e861020000             -call 0x505570
    cpu.esp -= 4;
    sub_505570(app, cpu);
    if (cpu.terminate) return;
    // 0050530f  e83cffffff             -call 0x505250
    cpu.esp -= 4;
    sub_505250(app, cpu);
    if (cpu.terminate) return;
    // 00505314  eba3                   -jmp 0x5052b9
    goto L_0x005052b9;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void Application::sub_505320(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00505320  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00505321  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00505322  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00505323  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00505324  8b6c2418               -mov ebp, dword ptr [esp + 0x18]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00505328  8b74241c               -mov esi, dword ptr [esp + 0x1c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0050532c  e84fffffff             -call 0x505280
    cpu.esp -= 4;
    sub_505280(app, cpu);
    if (cpu.terminate) return;
    // 00505331  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00505333  0f8492010000           -je 0x5054cb
    if (cpu.flags.zf)
    {
        goto L_0x005054cb;
    }
    // 00505339  833ddc7d560000         +cmp dword ptr [0x567ddc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5668316) /* 0x567ddc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00505340  0f848e010000           -je 0x5054d4
    if (cpu.flags.zf)
    {
        goto L_0x005054d4;
    }
    // 00505346  833d287e560000         +cmp dword ptr [0x567e28], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5668392) /* 0x567e28 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050534d  0f8481010000           -je 0x5054d4
    if (cpu.flags.zf)
    {
        goto L_0x005054d4;
    }
    // 00505353  bfff000000             -mov edi, 0xff
    cpu.edi = 255 /*0xff*/;
L_0x00505358:
    // 00505358  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0050535a  7418                   -je 0x505374
    if (cpu.flags.zf)
    {
        goto L_0x00505374;
    }
    // 0050535c  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00505360  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00505367  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00505369  3b2cc5147f5600         +cmp ebp, dword ptr [eax*8 + 0x567f14]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5668628) /* 0x567f14 */ + cpu.eax * 8)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00505370  7e02                   -jle 0x505374
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00505374;
    }
    // 00505372  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x00505374:
    // 00505374  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00505375  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00505376  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00505378  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0050537a  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0050537c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0050537d  a1ec7d5600             -mov eax, dword ptr [0x567dec]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5668332) /* 0x567dec */);
    // 00505382  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00505383  ff1588a2a000           -call dword ptr [0xa0a288]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10527368) /* 0xa0a288 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00505389  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0050538b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0050538d  7528                   -jne 0x5053b7
    if (!cpu.flags.zf)
    {
        goto L_0x005053b7;
    }
    // 0050538f  81ffff000000           +cmp edi, 0xff
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
    // 00505395  7520                   -jne 0x5053b7
    if (!cpu.flags.zf)
    {
        goto L_0x005053b7;
    }
    // 00505397  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00505398  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00505399  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0050539a  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0050539b  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0050539f  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 005053a0  8b0485cc815600         -mov eax, dword ptr [eax*4 + 0x5681cc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5669324) /* 0x5681cc */ + cpu.eax * 4);
    // 005053a7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 005053a8  8b15ec7d5600           -mov edx, dword ptr [0x567dec]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5668332) /* 0x567dec */);
    // 005053ae  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 005053af  ff1588a2a000           -call dword ptr [0xa0a288]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10527368) /* 0xa0a288 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005053b5  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x005053b7:
    // 005053b7  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 005053b9  0f840c010000           -je 0x5054cb
    if (cpu.flags.zf)
    {
        goto L_0x005054cb;
    }
    // 005053bf  833ddc7d560000         +cmp dword ptr [0x567ddc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5668316) /* 0x567ddc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005053c6  0f8418010000           -je 0x5054e4
    if (cpu.flags.zf)
    {
        goto L_0x005054e4;
    }
    // 005053cc  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 005053d0  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 005053d7  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 005053d9  8b14c5fc7e5600         -mov edx, dword ptr [eax*8 + 0x567efc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5668604) /* 0x567efc */ + cpu.eax * 8);
    // 005053e0  8b04c5007f5600         -mov eax, dword ptr [eax*8 + 0x567f00]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5668608) /* 0x567f00 */ + cpu.eax * 8);
    // 005053e7  8915fc7d5600           -mov dword ptr [0x567dfc], edx
    app->getMemory<x86::reg32>(x86::reg32(5668348) /* 0x567dfc */) = cpu.edx;
L_0x005053ed:
    // 005053ed  a3007e5600             -mov dword ptr [0x567e00], eax
    app->getMemory<x86::reg32>(x86::reg32(5668352) /* 0x567e00 */) = cpu.eax;
    // 005053f2  e839040000             -call 0x505830
    cpu.esp -= 4;
    sub_505830(app, cpu);
    if (cpu.terminate) return;
    // 005053f7  6a10                   -push 0x10
    app->getMemory<x86::reg32>(cpu.esp-4) = 16 /*0x10*/;
    cpu.esp -= 4;
    // 005053f9  ff1594a2a000           -call dword ptr [0xa0a294]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10527380) /* 0xa0a294 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005053ff  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00505401  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00505403  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00505405  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00505407  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00505409  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0050540b  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0050540d  ff151ca3a000           -call dword ptr [0xa0a31c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10527516) /* 0xa0a31c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00505413  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00505415  6a03                   -push 3
    app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
    // 00505417  ff1544a3a000           -call dword ptr [0xa0a344]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10527556) /* 0xa0a344 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050541d  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0050541f  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00505421  e80a070000             -call 0x505b30
    cpu.esp -= 4;
    sub_505b30(app, cpu);
    if (cpu.terminate) return;
    // 00505426  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00505428  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 0050542a  e801070000             -call 0x505b30
    cpu.esp -= 4;
    sub_505b30(app, cpu);
    if (cpu.terminate) return;
    // 0050542f  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00505431  6a07                   -push 7
    app->getMemory<x86::reg32>(cpu.esp-4) = 7 /*0x7*/;
    cpu.esp -= 4;
    // 00505433  e8f8060000             -call 0x505b30
    cpu.esp -= 4;
    sub_505b30(app, cpu);
    if (cpu.terminate) return;
    // 00505438  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0050543a  6a06                   -push 6
    app->getMemory<x86::reg32>(cpu.esp-4) = 6 /*0x6*/;
    cpu.esp -= 4;
    // 0050543c  e8ef060000             -call 0x505b30
    cpu.esp -= 4;
    sub_505b30(app, cpu);
    if (cpu.terminate) return;
    // 00505441  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00505443  6a0a                   -push 0xa
    app->getMemory<x86::reg32>(cpu.esp-4) = 10 /*0xa*/;
    cpu.esp -= 4;
    // 00505445  e8e6060000             -call 0x505b30
    cpu.esp -= 4;
    sub_505b30(app, cpu);
    if (cpu.terminate) return;
    // 0050544a  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0050544c  6a0b                   -push 0xb
    app->getMemory<x86::reg32>(cpu.esp-4) = 11 /*0xb*/;
    cpu.esp -= 4;
    // 0050544e  e8dd060000             -call 0x505b30
    cpu.esp -= 4;
    sub_505b30(app, cpu);
    if (cpu.terminate) return;
    // 00505453  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00505455  6a03                   -push 3
    app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
    // 00505457  e8d4060000             -call 0x505b30
    cpu.esp -= 4;
    sub_505b30(app, cpu);
    if (cpu.terminate) return;
    // 0050545c  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0050545e  6a0c                   -push 0xc
    app->getMemory<x86::reg32>(cpu.esp-4) = 12 /*0xc*/;
    cpu.esp -= 4;
    // 00505460  e8cb060000             -call 0x505b30
    cpu.esp -= 4;
    sub_505b30(app, cpu);
    if (cpu.terminate) return;
    // 00505465  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00505467  6a05                   -push 5
    app->getMemory<x86::reg32>(cpu.esp-4) = 5 /*0x5*/;
    cpu.esp -= 4;
    // 00505469  e8c2060000             -call 0x505b30
    cpu.esp -= 4;
    sub_505b30(app, cpu);
    if (cpu.terminate) return;
    // 0050546e  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00505470  6a0e                   -push 0xe
    app->getMemory<x86::reg32>(cpu.esp-4) = 14 /*0xe*/;
    cpu.esp -= 4;
    // 00505472  e8b9060000             -call 0x505b30
    cpu.esp -= 4;
    sub_505b30(app, cpu);
    if (cpu.terminate) return;
    // 00505477  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 00505479  6a0f                   -push 0xf
    app->getMemory<x86::reg32>(cpu.esp-4) = 15 /*0xf*/;
    cpu.esp -= 4;
    // 0050547b  e8b0060000             -call 0x505b30
    cpu.esp -= 4;
    sub_505b30(app, cpu);
    if (cpu.terminate) return;
    // 00505480  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00505482  6a68                   -push 0x68
    app->getMemory<x86::reg32>(cpu.esp-4) = 104 /*0x68*/;
    cpu.esp -= 4;
    // 00505484  e8a7060000             -call 0x505b30
    cpu.esp -= 4;
    sub_505b30(app, cpu);
    if (cpu.terminate) return;
    // 00505489  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0050548b  6a0d                   -push 0xd
    app->getMemory<x86::reg32>(cpu.esp-4) = 13 /*0xd*/;
    cpu.esp -= 4;
    // 0050548d  e89e060000             -call 0x505b30
    cpu.esp -= 4;
    sub_505b30(app, cpu);
    if (cpu.terminate) return;
    // 00505492  ba0000803f             -mov edx, 0x3f800000
    cpu.edx = 1065353216 /*0x3f800000*/;
    // 00505497  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00505498  6a65                   -push 0x65
    app->getMemory<x86::reg32>(cpu.esp-4) = 101 /*0x65*/;
    cpu.esp -= 4;
    // 0050549a  e891060000             -call 0x505b30
    cpu.esp -= 4;
    sub_505b30(app, cpu);
    if (cpu.terminate) return;
    // 0050549f  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 005054a1  6a18                   -push 0x18
    app->getMemory<x86::reg32>(cpu.esp-4) = 24 /*0x18*/;
    cpu.esp -= 4;
    // 005054a3  e888060000             -call 0x505b30
    cpu.esp -= 4;
    sub_505b30(app, cpu);
    if (cpu.terminate) return;
    // 005054a8  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 005054aa  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 005054ab  6a08                   -push 8
    app->getMemory<x86::reg32>(cpu.esp-4) = 8 /*0x8*/;
    cpu.esp -= 4;
    // 005054ad  e87e060000             -call 0x505b30
    cpu.esp -= 4;
    sub_505b30(app, cpu);
    if (cpu.terminate) return;
    // 005054b2  83fe01                 +cmp esi, 1
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
    // 005054b5  7c43                   -jl 0x5054fa
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x005054fa;
    }
    // 005054b7  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
L_0x005054bc:
    // 005054bc  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 005054bd  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 005054bf  e86c060000             -call 0x505b30
    cpu.esp -= 4;
    sub_505b30(app, cpu);
    if (cpu.terminate) return;
    // 005054c4  800dd87d560002         +or byte ptr [0x567dd8], 2
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(x86::reg32(5668312) /* 0x567dd8 */) |= x86::reg8(x86::sreg8(2 /*0x2*/))));
L_0x005054cb:
    // 005054cb  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 005054cd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005054ce  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005054cf  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005054d0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005054d1  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x005054d4:
    // 005054d4  8b7c2414               -mov edi, dword ptr [esp + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 005054d8  8b3cbdcc815600         -mov edi, dword ptr [edi*4 + 0x5681cc]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5669324) /* 0x5681cc */ + cpu.edi * 4);
    // 005054df  e974feffff             -jmp 0x505358
    goto L_0x00505358;
L_0x005054e4:
    // 005054e4  ff154ca3a000           -call dword ptr [0xa0a34c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10527564) /* 0xa0a34c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005054ea  a3fc7d5600             -mov dword ptr [0x567dfc], eax
    app->getMemory<x86::reg32>(x86::reg32(5668348) /* 0x567dfc */) = cpu.eax;
    // 005054ef  ff1550a3a000           -call dword ptr [0xa0a350]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10527568) /* 0xa0a350 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005054f5  e9f3feffff             -jmp 0x5053ed
    goto L_0x005053ed;
L_0x005054fa:
    // 005054fa  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 005054fc  ebbe                   -jmp 0x5054bc
    goto L_0x005054bc;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_505500(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00505500  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00505501  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00505502  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00505506  833d1882560000         +cmp dword ptr [0x568218], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5669400) /* 0x568218 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050550d  750a                   -jne 0x505519
    if (!cpu.flags.zf)
    {
        goto L_0x00505519;
    }
L_0x0050550f:
    // 0050550f  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00505514  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00505515  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00505516  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x00505519:
    // 00505519  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0050551b  c1ea08                 -shr edx, 8
    cpu.edx >>= 8 /*0x8*/ % 32;
    // 0050551e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0050551f  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00505524  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00505525  8b5c2420               -mov ebx, dword ptr [esp + 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00505529  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0050552a  e8f1fdffff             -call 0x505320
    cpu.esp -= 4;
    sub_505320(app, cpu);
    if (cpu.terminate) return;
    // 0050552f  a3f87d5600             -mov dword ptr [0x567df8], eax
    app->getMemory<x86::reg32>(x86::reg32(5668344) /* 0x567df8 */) = cpu.eax;
    // 00505534  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00505536  7527                   -jne 0x50555f
    if (!cpu.flags.zf)
    {
        goto L_0x0050555f;
    }
    // 00505538  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x0050553d:
    // 0050553d  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00505541  8b35247e5600           -mov esi, dword ptr [0x567e24]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5668388) /* 0x567e24 */);
    // 00505547  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 00505549  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0050554b  74c2                   -je 0x50550f
    if (cpu.flags.zf)
    {
        goto L_0x0050550f;
    }
    // 0050554d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0050554e  2eff15e8455300         -call dword ptr cs:[0x5345e8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457384) /* 0x5345e8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00505555  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0050555a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050555b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050555c  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x0050555f:
    // 0050555f  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00505561  ebda                   -jmp 0x50553d
    goto L_0x0050553d;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_505570(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00505570  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00505571  833d147e560000         +cmp dword ptr [0x567e14], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5668372) /* 0x567e14 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00505578  0f85a1000000           -jne 0x50561f
    if (!cpu.flags.zf)
    {
        goto L_0x0050561f;
    }
L_0x0050557e:
    // 0050557e  e83dfcffff             -call 0x5051c0
    cpu.esp -= 4;
    sub_5051c0(app, cpu);
    if (cpu.terminate) return;
    // 00505583  8b0dec7d5600           -mov ecx, dword ptr [0x567dec]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5668332) /* 0x567dec */);
    // 00505589  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0050558b  7408                   -je 0x505595
    if (cpu.flags.zf)
    {
        goto L_0x00505595;
    }
    // 0050558d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050558e  2eff1588475300         -call dword ptr cs:[0x534788]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457800) /* 0x534788 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00505595:
    // 00505595  833d207e560000         +cmp dword ptr [0x567e20], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5668384) /* 0x567e20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0050559c  0f848d000000           -je 0x50562f
    if (cpu.flags.zf)
    {
        goto L_0x0050562f;
    }
    // 005055a2  833dec7d560000         +cmp dword ptr [0x567dec], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5668332) /* 0x567dec */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005055a9  0f8480000000           -je 0x50562f
    if (cpu.flags.zf)
    {
        goto L_0x0050562f;
    }
    // 005055af  833d247e560000         +cmp dword ptr [0x567e24], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5668388) /* 0x567e24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005055b6  7477                   -je 0x50562f
    if (cpu.flags.zf)
    {
        goto L_0x0050562f;
    }
    // 005055b8  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 005055b9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005055ba  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 005055bb  6800555000             -push 0x505500
    app->getMemory<x86::reg32>(cpu.esp-4) = 5264640 /*0x505500*/;
    cpu.esp -= 4;
    // 005055c0  6865040000             -push 0x465
    app->getMemory<x86::reg32>(cpu.esp-4) = 1125 /*0x465*/;
    cpu.esp -= 4;
    // 005055c5  ff15207e5600           -call dword ptr [0x567e20]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5668384) /* 0x567e20 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005055cb  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 005055cf  8b742418               -mov esi, dword ptr [esp + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 005055d3  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 005055d6  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 005055d8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 005055d9  8b7c2418               -mov edi, dword ptr [esp + 0x18]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 005055dd  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 005055de  6865040000             -push 0x465
    app->getMemory<x86::reg32>(cpu.esp-4) = 1125 /*0x465*/;
    cpu.esp -= 4;
    // 005055e3  8b2dec7d5600           -mov ebp, dword ptr [0x567dec]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5668332) /* 0x567dec */);
    // 005055e9  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 005055ee  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005055ef  891d18825600           -mov dword ptr [0x568218], ebx
    app->getMemory<x86::reg32>(x86::reg32(5669400) /* 0x568218 */) = cpu.ebx;
    // 005055f5  2eff1568475300         -call dword ptr cs:[0x534768]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457768) /* 0x534768 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005055fc  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 005055fe  a1247e5600             -mov eax, dword ptr [0x567e24]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5668388) /* 0x567e24 */);
    // 00505603  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00505604  2eff1534465300         -call dword ptr cs:[0x534634]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457460) /* 0x534634 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050560b  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0050560d  a1f87d5600             -mov eax, dword ptr [0x567df8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5668344) /* 0x567df8 */);
    // 00505612  891518825600           -mov dword ptr [0x568218], edx
    app->getMemory<x86::reg32>(x86::reg32(5669400) /* 0x568218 */) = cpu.edx;
    // 00505618  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00505619  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050561a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050561b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050561c  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x0050561f:
    // 0050561f  ff15147e5600           -call dword ptr [0x567e14]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5668372) /* 0x567e14 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00505625  a3ec7d5600             -mov dword ptr [0x567dec], eax
    app->getMemory<x86::reg32>(x86::reg32(5668332) /* 0x567dec */) = cpu.eax;
    // 0050562a  e94fffffff             -jmp 0x50557e
    goto L_0x0050557e;
L_0x0050562f:
    // 0050562f  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00505633  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00505634  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00505638  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00505639  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0050563d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0050563e  e8ddfcffff             -call 0x505320
    cpu.esp -= 4;
    sub_505320(app, cpu);
    if (cpu.terminate) return;
    // 00505643  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00505644  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_505650(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00505650  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00505651  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00505652  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00505653  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00505654  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00505657  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0050565b  8b7c2424               -mov edi, dword ptr [esp + 0x24]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0050565f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00505660  db0424                 -fild dword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp))));
    // 00505663  d91c24                 -fstp dword ptr [esp]
    app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00505666  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00505667  2d0000803f             -sub eax, 0x3f800000
    (cpu.eax) -= x86::reg32(x86::sreg32(1065353216 /*0x3f800000*/));
    // 0050566c  c1f817                 -sar eax, 0x17
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (23 /*0x17*/ % 32));
    // 0050566f  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00505671  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00505673  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00505675  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00505677  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00505678  db0424                 -fild dword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp))));
    // 0050567b  d91c24                 -fstp dword ptr [esp]
    app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0050567e  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050567f  2d0000803f             -sub eax, 0x3f800000
    (cpu.eax) -= x86::reg32(x86::sreg32(1065353216 /*0x3f800000*/));
    // 00505684  c1f817                 -sar eax, 0x17
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (23 /*0x17*/ % 32));
    // 00505687  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00505689  39c2                   +cmp edx, eax
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
    // 0050568b  7e02                   -jle 0x50568f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0050568f;
    }
    // 0050568d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x0050568f:
    // 0050568f  8b542430               -mov edx, dword ptr [esp + 0x30]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 00505693  0fb6b81c825600         -movzx edi, byte ptr [eax + 0x56821c]
    cpu.edi = x86::reg32(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5669404) /* 0x56821c */));
    // 0050569a  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0050569c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0050569e  0f8cab000000           -jl 0x50574f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0050574f;
    }
L_0x005056a4:
    // 005056a4  8a801c825600           -mov al, byte ptr [eax + 0x56821c]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5669404) /* 0x56821c */);
    // 005056aa  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 005056af  29eb                   -sub ebx, ebp
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 005056b1  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 005056b5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 005056b7  8a8328825600           -mov al, byte ptr [ebx + 0x568228]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5669416) /* 0x568228 */);
    // 005056bd  8b542428               -mov edx, dword ptr [esp + 0x28]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 005056c1  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 005056c5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 005056c7  8a822c825600           -mov al, byte ptr [edx + 0x56822c]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5669420) /* 0x56822c */);
    // 005056cd  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 005056ce  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 005056d2  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005056d3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 005056d4  8b5c2410               -mov ebx, dword ptr [esp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 005056d8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 005056d9  ff1520a3a000           -call dword ptr [0xa0a320]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10527520) /* 0xa0a320 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005056df  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 005056e1  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 005056e3  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 005056e5  ff1528a3a000           -call dword ptr [0xa0a328]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10527528) /* 0xa0a328 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005056eb  8b1568a7a000           -mov edx, dword ptr [0xa0a768]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10528616) /* 0xa0a768 */);
    // 005056f1  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 005056f3  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 005056f5  250000e0ff             -and eax, 0xffe00000
    cpu.eax &= x86::reg32(x86::sreg32(4292870144 /*0xffe00000*/));
    // 005056fa  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 005056fd  031d68a7a000           -add ebx, dword ptr [0xa0a768]
    (cpu.ebx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(10528616) /* 0xa0a768 */)));
    // 00505703  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00505705  4b                     -dec ebx
    (cpu.ebx)--;
    // 00505706  ff1528a3a000           -call dword ptr [0xa0a328]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10527528) /* 0xa0a328 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050570c  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0050570e  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 00505711  81e30000e0ff           -and ebx, 0xffe00000
    cpu.ebx &= x86::reg32(x86::sreg32(4292870144 /*0xffe00000*/));
    // 00505717  39d3                   +cmp ebx, edx
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
    // 00505719  740f                   -je 0x50572a
    if (cpu.flags.zf)
    {
        goto L_0x0050572a;
    }
    // 0050571b  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0050571d  ff1528a3a000           -call dword ptr [0xa0a328]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10527528) /* 0xa0a328 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00505723  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00505725  a368a7a000             -mov dword ptr [0xa0a768], eax
    app->getMemory<x86::reg32>(x86::reg32(10528616) /* 0xa0a768 */) = cpu.eax;
L_0x0050572a:
    // 0050572a  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0050572c  ff152ca3a000           -call dword ptr [0xa0a32c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10527532) /* 0xa0a32c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00505732  83c00f                 -add eax, 0xf
    (cpu.eax) += x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00505735  8b0d68a7a000           -mov ecx, dword ptr [0xa0a768]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10528616) /* 0xa0a768 */);
    // 0050573b  24f0                   -and al, 0xf0
    cpu.al &= x86::reg8(x86::sreg8(240 /*0xf0*/));
    // 0050573d  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0050573f  39e8                   +cmp eax, ebp
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
    // 00505741  7d13                   -jge 0x505756
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00505756;
    }
L_0x00505743:
    // 00505743  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00505745  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00505748  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00505749  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050574a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050574b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050574c  c21400                 -ret 0x14
    cpu.esp += 4+20 /*0x14*/;
    return;
L_0x0050574f:
    // 0050574f  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00505751  e94effffff             -jmp 0x5056a4
    goto L_0x005056a4;
L_0x00505756:
    // 00505756  b820000000             -mov eax, 0x20
    cpu.eax = 32 /*0x20*/;
    // 0050575b  e8a021ffff             -call 0x4f7900
    cpu.esp -= 4;
    sub_4f7900(app, cpu);
    if (cpu.terminate) return;
    // 00505760  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00505762  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00505764  74dd                   -je 0x505743
    if (cpu.flags.zf)
    {
        goto L_0x00505743;
    }
    // 00505766  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0050576a  897804                 -mov dword ptr [eax + 4], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 0050576d  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 0050576f  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00505773  8b5c2428               -mov ebx, dword ptr [esp + 0x28]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00505777  895008                 -mov dword ptr [eax + 8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0050577a  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0050577c  8a932c825600           -mov dl, byte ptr [ebx + 0x56822c]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5669420) /* 0x56822c */);
    // 00505782  c7401000000000         -mov dword ptr [eax + 0x10], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
    // 00505789  c7401803000000         -mov dword ptr [eax + 0x18], 3
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = 3 /*0x3*/;
    // 00505790  8b1d68a7a000           -mov ebx, dword ptr [0xa0a768]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10528616) /* 0xa0a768 */);
    // 00505796  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00505799  01eb                   -add ebx, ebp
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0050579b  8b1568a7a000           -mov edx, dword ptr [0xa0a768]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10528616) /* 0xa0a768 */);
    // 005057a1  891d68a7a000           -mov dword ptr [0xa0a768], ebx
    app->getMemory<x86::reg32>(x86::reg32(10528616) /* 0xa0a768 */) = cpu.ebx;
    // 005057a7  895014                 -mov dword ptr [eax + 0x14], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 005057aa  8b150c7e5600           -mov edx, dword ptr [0x567e0c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5668364) /* 0x567e0c */);
    // 005057b0  a30c7e5600             -mov dword ptr [0x567e0c], eax
    app->getMemory<x86::reg32>(x86::reg32(5668364) /* 0x567e0c */) = cpu.eax;
    // 005057b5  89501c                 -mov dword ptr [eax + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 005057b8  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 005057ba  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 005057bd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005057be  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005057bf  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005057c0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005057c1  c21400                 -ret 0x14
    cpu.esp += 4+20 /*0x14*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_5057d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005057d0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 005057d1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005057d2  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 005057d6  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 005057da  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005057dc  750f                   -jne 0x5057ed
    if (!cpu.flags.zf)
    {
        goto L_0x005057ed;
    }
    // 005057de  8b742414               -mov esi, dword ptr [esp + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 005057e2  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 005057e4  752a                   -jne 0x505810
    if (!cpu.flags.zf)
    {
        goto L_0x00505810;
    }
    // 005057e6  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 005057e8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005057e9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005057ea  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x005057ed:
    // 005057ed  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 005057ee  8b5318                 -mov edx, dword ptr [ebx + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 005057f1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 005057f2  8b4b14                 -mov ecx, dword ptr [ebx + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 005057f5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005057f6  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 005057f8  894310                 -mov dword ptr [ebx + 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 005057fb  ff1524a3a000           -call dword ptr [0xa0a324]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10527524) /* 0xa0a324 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00505801  8b742414               -mov esi, dword ptr [esp + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00505805  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00505807  7507                   -jne 0x505810
    if (!cpu.flags.zf)
    {
        goto L_0x00505810;
    }
    // 00505809  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0050580b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050580c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050580d  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x00505810:
    // 00505810  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00505811  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00505813  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00505815  ff1598a2a000           -call dword ptr [0xa0a298]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10527384) /* 0xa0a298 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050581b  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0050581d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050581e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050581f  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_505830(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00505830  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00505832  ff1528a3a000           -call dword ptr [0xa0a328]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10527528) /* 0xa0a328 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00505838  8b150c7e5600           -mov edx, dword ptr [0x567e0c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5668364) /* 0x567e0c */);
    // 0050583e  a368a7a000             -mov dword ptr [0xa0a768], eax
    app->getMemory<x86::reg32>(x86::reg32(10528616) /* 0xa0a768 */) = cpu.eax;
    // 00505843  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00505845  7419                   -je 0x505860
    if (cpu.flags.zf)
    {
        goto L_0x00505860;
    }
L_0x00505847:
    // 00505847  a10c7e5600             -mov eax, dword ptr [0x567e0c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5668364) /* 0x567e0c */);
    // 0050584c  8b501c                 -mov edx, dword ptr [eax + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0050584f  e89c21ffff             -call 0x4f79f0
    cpu.esp -= 4;
    sub_4f79f0(app, cpu);
    if (cpu.terminate) return;
    // 00505854  89150c7e5600           -mov dword ptr [0x567e0c], edx
    app->getMemory<x86::reg32>(x86::reg32(5668364) /* 0x567e0c */) = cpu.edx;
    // 0050585a  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0050585c  75e9                   -jne 0x505847
    if (!cpu.flags.zf)
    {
        goto L_0x00505847;
    }
    // 0050585e  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x00505860:
    // 00505860  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00505865  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void Application::sub_505870(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00505870  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00505871  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00505872  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00505873  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00505877  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00505879  7514                   -jne 0x50588f
    if (!cpu.flags.zf)
    {
        goto L_0x0050588f;
    }
    // 0050587b  833d3882560000         +cmp dword ptr [0x568238], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5669432) /* 0x568238 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00505882  755c                   -jne 0x5058e0
    if (!cpu.flags.zf)
    {
        goto L_0x005058e0;
    }
L_0x00505884:
    // 00505884  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00505889  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050588a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050588b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050588c  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x0050588f:
    // 0050588f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00505890  8b7818                 -mov edi, dword ptr [eax + 0x18]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 00505893  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00505894  8b6814                 -mov ebp, dword ptr [eax + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 00505897  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00505898  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0050589a  ff1530a3a000           -call dword ptr [0xa0a330]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10527536) /* 0xa0a330 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005058a0  833d3882560001         +cmp dword ptr [0x568238], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5669432) /* 0x568238 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005058a7  74db                   -je 0x505884
    if (cpu.flags.zf)
    {
        goto L_0x00505884;
    }
    // 005058a9  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 005058ab  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 005058ad  8b15107e5600           -mov edx, dword ptr [0x567e10]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5668368) /* 0x567e10 */);
    // 005058b3  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 005058b4  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 005058b6  6a03                   -push 3
    app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
    // 005058b8  ff15bca2a000           -call dword ptr [0xa0a2bc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10527420) /* 0xa0a2bc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005058be  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 005058c0  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 005058c2  8b0d107e5600           -mov ecx, dword ptr [0x567e10]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5668368) /* 0x567e10 */);
    // 005058c8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005058c9  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 005058cb  6a03                   -push 3
    app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
    // 005058cd  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 005058d2  ff15c0a2a000           -call dword ptr [0xa0a2c0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10527424) /* 0xa0a2c0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005058d8  891d38825600           -mov dword ptr [0x568238], ebx
    app->getMemory<x86::reg32>(x86::reg32(5669432) /* 0x568238 */) = cpu.ebx;
    // 005058de  eba4                   -jmp 0x505884
    goto L_0x00505884;
L_0x005058e0:
    // 005058e0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005058e1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 005058e2  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 005058e4  8b0d107e5600           -mov ecx, dword ptr [0x567e10]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5668368) /* 0x567e10 */);
    // 005058ea  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005058eb  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 005058ec  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 005058ee  ff15bca2a000           -call dword ptr [0xa0a2bc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10527420) /* 0xa0a2bc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005058f4  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 005058f6  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 005058f8  8b1d107e5600           -mov ebx, dword ptr [0x567e10]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5668368) /* 0x567e10 */);
    // 005058fe  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 005058ff  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00505901  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00505903  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00505905  ff15c0a2a000           -call dword ptr [0xa0a2c0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10527424) /* 0xa0a2c0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050590b  893538825600           -mov dword ptr [0x568238], esi
    app->getMemory<x86::reg32>(x86::reg32(5669432) /* 0x568238 */) = cpu.esi;
    // 00505911  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00505912  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00505917  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00505918  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00505919  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0050591a  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_505920(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00505920  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00505924  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00505926  7505                   -jne 0x50592d
    if (!cpu.flags.zf)
    {
        goto L_0x0050592d;
    }
    // 00505928  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x0050592d:
    // 0050592d  48                     -dec eax
    (cpu.eax)--;
    // 0050592e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0050592f  a3e87d5600             -mov dword ptr [0x567de8], eax
    app->getMemory<x86::reg32>(x86::reg32(5668328) /* 0x567de8 */) = cpu.eax;
    // 00505934  ff159ca2a000           -call dword ptr [0xa0a29c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10527388) /* 0xa0a29c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050593a  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0050593f  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_505950(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00505950  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00505952  66a1e47d5600           -mov ax, word ptr [0x567de4]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(5668324) /* 0x567de4 */);
    // 00505958  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00505959  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0050595b  8b15e07d5600           -mov edx, dword ptr [0x567de0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5668320) /* 0x567de0 */);
    // 00505961  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00505962  ff15a0a2a000           -call dword ptr [0xa0a2a0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10527392) /* 0xa0a2a0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00505968  8d8000000000           -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 0050596e  8bd2                   -mov edx, edx
    cpu.edx = cpu.edx;
    // 00505970  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_505980(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00505980  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00505981  bb00093d00             -mov ebx, 0x3d0900
    cpu.ebx = 4000000 /*0x3d0900*/;
L_0x00505986:
    // 00505986  ff1554a3a000           -call dword ptr [0xa0a354]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10527572) /* 0xa0a354 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0050598c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0050598e  7403                   -je 0x505993
    if (cpu.flags.zf)
    {
        goto L_0x00505993;
    }
    // 00505990  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00505991  75f3                   -jne 0x505986
    if (!cpu.flags.zf)
    {
        goto L_0x00505986;
    }
L_0x00505993:
    // 00505993  8b15f07d5600           -mov edx, dword ptr [0x567df0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5668336) /* 0x567df0 */);
    // 00505999  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0050599a  ff15a4a2a000           -call dword ptr [0xa0a2a4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10527396) /* 0xa0a2a4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005059a0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005059a1  8d8000000000           -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 005059a7  8d9200000000           -lea edx, [edx]
    cpu.edx = x86::reg32(cpu.edx);
    // 005059ad  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 005059b0  c3                     -ret 
    cpu.esp += 4;
    return;
}

}
