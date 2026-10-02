#include "voodoo2a.h"
#include <lib/thread.h>

namespace voodoo2a
{

/* align: skip 0x8d 0x40 0x00 */
void sub_aa8c08(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa8c08  e9a7270000             -jmp 0xaab3b4
    return sub_aab3b4(app, cpu);
}

/* align: skip 0x8d 0x40 0x00 */
void sub_aa8c10(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa8c10  e9f7280000             -jmp 0xaab50c
    return sub_aab50c(app, cpu);
}

/* align: skip 0x8d 0x40 0x00 */
void sub_aa8c18(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa8c18  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aa8c19  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aa8c1a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00aa8c1b  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00aa8c1d  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00aa8c1f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00aa8c21  89357048ab00           -mov dword ptr [0xab4870], esi
    app->getMemory<x86::reg32>(x86::reg32(11225200) /* 0xab4870 */) = cpu.esi;
    // 00aa8c27  e8d00b0000             -call 0xaa97fc
    cpu.esp -= 4;
    sub_aa97fc(app, cpu);
    if (cpu.terminate) return;
    // 00aa8c2c  a37c48ab00             -mov dword ptr [0xab487c], eax
    app->getMemory<x86::reg32>(x86::reg32(11225212) /* 0xab487c */) = cpu.eax;
    // 00aa8c31  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aa8c33  7511                   -jne 0xaa8c46
    if (!cpu.flags.zf)
    {
        goto L_0x00aa8c46;
    }
    // 00aa8c35  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00aa8c37  0f8505020000           -jne 0xaa8e42
    if (!cpu.flags.zf)
    {
        goto L_0x00aa8e42;
    }
    // 00aa8c3d  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00aa8c3f  2eff158013ab00         -call dword ptr cs:[0xab1380]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11211648) /* 0xab1380 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00aa8c46:
    // 00aa8c46  e8f5280000             -call 0xaab540
    cpu.esp -= 4;
    sub_aab540(app, cpu);
    if (cpu.terminate) return;
    // 00aa8c4b  2eff15b413ab00         -call dword ptr cs:[0xab13b4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11211700) /* 0xab13b4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa8c52  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00aa8c54  a37d37ab00             -mov dword ptr [0xab377d], eax
    app->getMemory<x86::reg32>(x86::reg32(11220861) /* 0xab377d */) = cpu.eax;
    // 00aa8c59  8915a44eab00           -mov dword ptr [0xab4ea4], edx
    app->getMemory<x86::reg32>(x86::reg32(11226788) /* 0xab4ea4 */) = cpu.edx;
    // 00aa8c5f  2eff15e013ab00         -call dword ptr cs:[0xab13e0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11211744) /* 0xab13e0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa8c66  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00aa8c68  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00aa8c6a  a28337ab00             -mov byte ptr [0xab3783], al
    app->getMemory<x86::reg8>(x86::reg32(11220867) /* 0xab3783 */) = cpu.al;
    // 00aa8c6f  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 00aa8c72  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00aa8c77  6804010000             -push 0x104
    app->getMemory<x86::reg32>(cpu.esp-4) = 260 /*0x104*/;
    cpu.esp -= 4;
    // 00aa8c7c  66a38537ab00           -mov word ptr [0xab3785], ax
    app->getMemory<x86::reg16>(x86::reg32(11220869) /* 0xab3785 */) = cpu.ax;
    // 00aa8c82  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00aa8c84  81e2ffff0000           -and edx, 0xffff
    cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00aa8c8a  66a18537ab00           -mov ax, word ptr [0xab3785]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(11220869) /* 0xab3785 */);
    // 00aa8c90  688048ab00             -push 0xab4880
    app->getMemory<x86::reg32>(cpu.esp-4) = 11225216 /*0xab4880*/;
    cpu.esp -= 4;
    // 00aa8c95  a38737ab00             -mov dword ptr [0xab3787], eax
    app->getMemory<x86::reg32>(x86::reg32(11220871) /* 0xab3787 */) = cpu.eax;
    // 00aa8c9a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00aa8c9c  c1fa08                 -sar edx, 8
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (8 /*0x8*/ % 32));
    // 00aa8c9f  88d8                   -mov al, bl
    cpu.al = cpu.bl;
    // 00aa8ca1  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00aa8ca7  a38b37ab00             -mov dword ptr [0xab378b], eax
    app->getMemory<x86::reg32>(x86::reg32(11220875) /* 0xab378b */) = cpu.eax;
    // 00aa8cac  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00aa8cae  88158437ab00           -mov byte ptr [0xab3784], dl
    app->getMemory<x86::reg8>(x86::reg32(11220868) /* 0xab3784 */) = cpu.dl;
    // 00aa8cb4  88d0                   -mov al, dl
    cpu.al = cpu.dl;
    // 00aa8cb6  8b158b37ab00           -mov edx, dword ptr [0xab378b]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11220875) /* 0xab378b */);
    // 00aa8cbc  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00aa8cbe  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 00aa8cc1  bb8048ab00             -mov ebx, 0xab4880
    cpu.ebx = 11225216 /*0xab4880*/;
    // 00aa8cc6  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 00aa8cc8  a38f37ab00             -mov dword ptr [0xab378f], eax
    app->getMemory<x86::reg32>(x86::reg32(11220879) /* 0xab378f */) = cpu.eax;
    // 00aa8ccd  89159337ab00           -mov dword ptr [0xab3793], edx
    app->getMemory<x86::reg32>(x86::reg32(11220883) /* 0xab3793 */) = cpu.edx;
    // 00aa8cd3  2eff15c813ab00         -call dword ptr cs:[0xab13c8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11211720) /* 0xab13c8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa8cda  ba8449ab00             -mov edx, 0xab4984
    cpu.edx = 11225476 /*0xab4984*/;
    // 00aa8cdf  891d4437ab00           -mov dword ptr [0xab3744], ebx
    app->getMemory<x86::reg32>(x86::reg32(11220804) /* 0xab3744 */) = cpu.ebx;
    // 00aa8ce5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00aa8ce7  bb08020000             -mov ebx, 0x208
    cpu.ebx = 520 /*0x208*/;
    // 00aa8cec  b98449ab00             -mov ecx, 0xab4984
    cpu.ecx = 11225476 /*0xab4984*/;
    // 00aa8cf1  e8fa280000             -call 0xaab5f0
    cpu.esp -= 4;
    sub_aab5f0(app, cpu);
    if (cpu.terminate) return;
    // 00aa8cf6  890d5037ab00           -mov dword ptr [0xab3750], ecx
    app->getMemory<x86::reg32>(x86::reg32(11220816) /* 0xab3750 */) = cpu.ecx;
    // 00aa8cfc  2eff159c13ab00         -call dword ptr cs:[0xab139c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11211676) /* 0xab139c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa8d03  e888290000             -call 0xaab690
    cpu.esp -= 4;
    sub_aab690(app, cpu);
    if (cpu.terminate) return;
    // 00aa8d08  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00aa8d0a  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 00aa8d0c  a37448ab00             -mov dword ptr [0xab4874], eax
    app->getMemory<x86::reg32>(x86::reg32(11225204) /* 0xab4874 */) = cpu.eax;
    // 00aa8d11  80fb22                 +cmp bl, 0x22
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
    // 00aa8d14  751e                   -jne 0xaa8d34
    if (!cpu.flags.zf)
    {
        goto L_0x00aa8d34;
    }
    // 00aa8d16  8a7801                 -mov bh, byte ptr [eax + 1]
    cpu.bh = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00aa8d19  40                     -inc eax
    (cpu.eax)++;
    // 00aa8d1a  38df                   +cmp bh, bl
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
    // 00aa8d1c  740e                   -je 0xaa8d2c
    if (cpu.flags.zf)
    {
        goto L_0x00aa8d2c;
    }
L_0x00aa8d1e:
    // 00aa8d1e  803800                 +cmp byte ptr [eax], 0
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
    // 00aa8d21  7409                   -je 0xaa8d2c
    if (cpu.flags.zf)
    {
        goto L_0x00aa8d2c;
    }
    // 00aa8d23  8a5001                 -mov dl, byte ptr [eax + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00aa8d26  40                     -inc eax
    (cpu.eax)++;
    // 00aa8d27  80fa22                 +cmp dl, 0x22
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
    // 00aa8d2a  75f2                   -jne 0xaa8d1e
    if (!cpu.flags.zf)
    {
        goto L_0x00aa8d1e;
    }
L_0x00aa8d2c:
    // 00aa8d2c  803800                 +cmp byte ptr [eax], 0
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
    // 00aa8d2f  741e                   -je 0xaa8d4f
    if (cpu.flags.zf)
    {
        goto L_0x00aa8d4f;
    }
    // 00aa8d31  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00aa8d32  eb1b                   -jmp 0xaa8d4f
    goto L_0x00aa8d4f;
L_0x00aa8d34:
    // 00aa8d34  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 00aa8d36  fec2                   -inc dl
    (cpu.dl)++;
    // 00aa8d38  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00aa8d3e  f6827835ab0002         +test byte ptr [edx + 0xab3578], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(11220344) /* 0xab3578 */) & 2 /*0x2*/));
    // 00aa8d45  7508                   -jne 0xaa8d4f
    if (!cpu.flags.zf)
    {
        goto L_0x00aa8d4f;
    }
    // 00aa8d47  803800                 +cmp byte ptr [eax], 0
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
    // 00aa8d4a  7403                   -je 0xaa8d4f
    if (cpu.flags.zf)
    {
        goto L_0x00aa8d4f;
    }
    // 00aa8d4c  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00aa8d4d  ebe5                   -jmp 0xaa8d34
    goto L_0x00aa8d34;
L_0x00aa8d4f:
    // 00aa8d4f  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 00aa8d51  fec2                   -inc dl
    (cpu.dl)++;
    // 00aa8d53  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00aa8d59  f6827835ab0002         +test byte ptr [edx + 0xab3578], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(11220344) /* 0xab3578 */) & 2 /*0x2*/));
    // 00aa8d60  7403                   -je 0xaa8d65
    if (cpu.flags.zf)
    {
        goto L_0x00aa8d65;
    }
    // 00aa8d62  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00aa8d63  ebea                   -jmp 0xaa8d4f
    goto L_0x00aa8d4f;
L_0x00aa8d65:
    // 00aa8d65  a34037ab00             -mov dword ptr [0xab3740], eax
    app->getMemory<x86::reg32>(x86::reg32(11220800) /* 0xab3740 */) = cpu.eax;
    // 00aa8d6a  2eff15a013ab00         -call dword ptr cs:[0xab13a0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11211680) /* 0xab13a0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa8d71  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aa8d73  0f847d000000           -je 0xaa8df6
    if (cpu.flags.zf)
    {
        goto L_0x00aa8df6;
    }
    // 00aa8d79  e862290000             -call 0xaab6e0
    cpu.esp -= 4;
    sub_aab6e0(app, cpu);
    if (cpu.terminate) return;
    // 00aa8d7e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00aa8d80  668b18                 -mov bx, word ptr [eax]
    cpu.bx = app->getMemory<x86::reg16>(cpu.eax);
    // 00aa8d83  a37848ab00             -mov dword ptr [0xab4878], eax
    app->getMemory<x86::reg32>(x86::reg32(11225208) /* 0xab4878 */) = cpu.eax;
    // 00aa8d88  6683fb22               +cmp bx, 0x22
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
    // 00aa8d8c  752a                   -jne 0xaa8db8
    if (!cpu.flags.zf)
    {
        goto L_0x00aa8db8;
    }
    // 00aa8d8e  668b4802               -mov cx, word ptr [eax + 2]
    cpu.cx = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 00aa8d92  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00aa8d95  6639d9                 +cmp cx, bx
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
    // 00aa8d98  7413                   -je 0xaa8dad
    if (cpu.flags.zf)
    {
        goto L_0x00aa8dad;
    }
L_0x00aa8d9a:
    // 00aa8d9a  66833800               +cmp word ptr [eax], 0
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
    // 00aa8d9e  740d                   -je 0xaa8dad
    if (cpu.flags.zf)
    {
        goto L_0x00aa8dad;
    }
    // 00aa8da0  668b5802               -mov bx, word ptr [eax + 2]
    cpu.bx = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 00aa8da4  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00aa8da7  6683fb22               +cmp bx, 0x22
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
    // 00aa8dab  75ed                   -jne 0xaa8d9a
    if (!cpu.flags.zf)
    {
        goto L_0x00aa8d9a;
    }
L_0x00aa8dad:
    // 00aa8dad  66833800               +cmp word ptr [eax], 0
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
    // 00aa8db1  7427                   -je 0xaa8dda
    if (cpu.flags.zf)
    {
        goto L_0x00aa8dda;
    }
    // 00aa8db3  83c002                 +add eax, 2
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
    // 00aa8db6  eb22                   -jmp 0xaa8dda
    goto L_0x00aa8dda;
L_0x00aa8db8:
    // 00aa8db8  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
L_0x00aa8dbd:
    // 00aa8dbd  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 00aa8dbf  fec2                   -inc dl
    (cpu.dl)++;
    // 00aa8dc1  81e2ff000000           +and edx, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 00aa8dc7  849a7835ab00           -test byte ptr [edx + 0xab3578], bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(11220344) /* 0xab3578 */) & cpu.bl));
    // 00aa8dcd  750b                   -jne 0xaa8dda
    if (!cpu.flags.zf)
    {
        goto L_0x00aa8dda;
    }
    // 00aa8dcf  66833800               +cmp word ptr [eax], 0
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
    // 00aa8dd3  7405                   -je 0xaa8dda
    if (cpu.flags.zf)
    {
        goto L_0x00aa8dda;
    }
    // 00aa8dd5  83c002                 +add eax, 2
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
    // 00aa8dd8  ebe3                   -jmp 0xaa8dbd
    goto L_0x00aa8dbd;
L_0x00aa8dda:
    // 00aa8dda  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
L_0x00aa8ddf:
    // 00aa8ddf  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 00aa8de1  fec2                   -inc dl
    (cpu.dl)++;
    // 00aa8de3  81e2ff000000           +and edx, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 00aa8de9  849a7835ab00           -test byte ptr [edx + 0xab3578], bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(11220344) /* 0xab3578 */) & cpu.bl));
    // 00aa8def  740a                   -je 0xaa8dfb
    if (cpu.flags.zf)
    {
        goto L_0x00aa8dfb;
    }
    // 00aa8df1  83c002                 +add eax, 2
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
    // 00aa8df4  ebe9                   -jmp 0xaa8ddf
    goto L_0x00aa8ddf;
L_0x00aa8df6:
    // 00aa8df6  b82827ab00             -mov eax, 0xab2728
    cpu.eax = 11216680 /*0xab2728*/;
L_0x00aa8dfb:
    // 00aa8dfb  a34c37ab00             -mov dword ptr [0xab374c], eax
    app->getMemory<x86::reg32>(x86::reg32(11220812) /* 0xab374c */) = cpu.eax;
    // 00aa8e00  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00aa8e02  7439                   -je 0xaa8e3d
    if (cpu.flags.zf)
    {
        goto L_0x00aa8e3d;
    }
    // 00aa8e04  6804010000             -push 0x104
    app->getMemory<x86::reg32>(cpu.esp-4) = 260 /*0x104*/;
    cpu.esp -= 4;
    // 00aa8e09  688c4bab00             -push 0xab4b8c
    app->getMemory<x86::reg32>(cpu.esp-4) = 11225996 /*0xab4b8c*/;
    cpu.esp -= 4;
    // 00aa8e0e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00aa8e0f  be8c4bab00             -mov esi, 0xab4b8c
    cpu.esi = 11225996 /*0xab4b8c*/;
    // 00aa8e14  bb08020000             -mov ebx, 0x208
    cpu.ebx = 520 /*0x208*/;
    // 00aa8e19  2eff15c813ab00         -call dword ptr cs:[0xab13c8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11211720) /* 0xab13c8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa8e20  ba904cab00             -mov edx, 0xab4c90
    cpu.edx = 11226256 /*0xab4c90*/;
    // 00aa8e25  89354837ab00           -mov dword ptr [0xab3748], esi
    app->getMemory<x86::reg32>(x86::reg32(11220808) /* 0xab3748 */) = cpu.esi;
    // 00aa8e2b  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00aa8e2d  bf904cab00             -mov edi, 0xab4c90
    cpu.edi = 11226256 /*0xab4c90*/;
    // 00aa8e32  e8b9270000             -call 0xaab5f0
    cpu.esp -= 4;
    sub_aab5f0(app, cpu);
    if (cpu.terminate) return;
    // 00aa8e37  893d5437ab00           -mov dword ptr [0xab3754], edi
    app->getMemory<x86::reg32>(x86::reg32(11220820) /* 0xab3754 */) = cpu.edi;
L_0x00aa8e3d:
    // 00aa8e3d  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x00aa8e42:
    // 00aa8e42  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa8e43  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa8e44  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa8e45  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void sub_aa8e48(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa8e48  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aa8e49  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aa8e4a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aa8e4b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00aa8e4c  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00aa8e4e  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00aa8e50  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00aa8e52  2eff15d013ab00         -call dword ptr cs:[0xab13d0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11211728) /* 0xab13d0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa8e59  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00aa8e5b  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00aa8e5d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00aa8e5f  e8b4fdffff             -call 0xaa8c18
    cpu.esp -= 4;
    sub_aa8c18(app, cpu);
    if (cpu.terminate) return;
    // 00aa8e64  ba6037ab00             -mov edx, 0xab3760
    cpu.edx = 11220832 /*0xab3760*/;
    // 00aa8e69  ff15a836ab00           -call dword ptr [0xab36a8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11220648) /* 0xab36a8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa8e6f  e89c280000             -call 0xaab710
    cpu.esp -= 4;
    sub_aab710(app, cpu);
    if (cpu.terminate) return;
    // 00aa8e74  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00aa8e76  e8452d0000             -call 0xaabbc0
    cpu.esp -= 4;
    sub_aabbc0(app, cpu);
    if (cpu.terminate) return;
    // 00aa8e7b  b821000000             -mov eax, 0x21
    cpu.eax = 33 /*0x21*/;
    // 00aa8e80  e8a7000000             -call 0xaa8f2c
    cpu.esp -= 4;
    sub_aa8f2c(app, cpu);
    if (cpu.terminate) return;
    // 00aa8e85  ff15e836ab00           -call dword ptr [0xab36e8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11220712) /* 0xab36e8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa8e8b  b8ff000000             -mov eax, 0xff
    cpu.eax = 255 /*0xff*/;
    // 00aa8e90  e897000000             -call 0xaa8f2c
    cpu.esp -= 4;
    sub_aa8f2c(app, cpu);
    if (cpu.terminate) return;
    // 00aa8e95  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa8e96  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa8e97  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa8e98  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa8e99  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void sub_aa8e9c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa8e9c  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00aa8e9e  833d7048ab0000         +cmp dword ptr [0xab4870], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(11225200) /* 0xab4870 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00aa8ea5  7418                   -je 0xaa8ebf
    if (cpu.flags.zf)
    {
        goto L_0x00aa8ebf;
    }
    // 00aa8ea7  833df036ab0000         +cmp dword ptr [0xab36f0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(11220720) /* 0xab36f0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00aa8eae  7426                   -je 0xaa8ed6
    if (cpu.flags.zf)
    {
        goto L_0x00aa8ed6;
    }
    // 00aa8eb0  baff000000             -mov edx, 0xff
    cpu.edx = 255 /*0xff*/;
    // 00aa8eb5  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00aa8eb7  ff15f036ab00           -call dword ptr [0xab36f0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11220720) /* 0xab36f0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa8ebd  eb17                   -jmp 0xaa8ed6
    goto L_0x00aa8ed6;
L_0x00aa8ebf:
    // 00aa8ebf  e8482d0000             -call 0xaabc0c
    cpu.esp -= 4;
    sub_aabc0c(app, cpu);
    if (cpu.terminate) return;
    // 00aa8ec4  ba0f000000             -mov edx, 0xf
    cpu.edx = 15 /*0xf*/;
    // 00aa8ec9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00aa8ecb  e8ac000000             -call 0xaa8f7c
    cpu.esp -= 4;
    sub_aa8f7c(app, cpu);
    if (cpu.terminate) return;
    // 00aa8ed0  ff15e436ab00           -call dword ptr [0xab36e4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11220708) /* 0xab36e4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00aa8ed6:
    // 00aa8ed6  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aa8ed7  2eff158013ab00         -call dword ptr cs:[0xab1380]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11211648) /* 0xab1380 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa8ede  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
    // 00aa8ee0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aa8ee1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aa8ee2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aa8ee3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aa8ee4  8b157448ab00           -mov edx, dword ptr [0xab4874]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11225204) /* 0xab4874 */);
    // 00aa8eea  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00aa8eec  740f                   -je 0xaa8efd
    if (cpu.flags.zf)
    {
        goto L_0x00aa8efd;
    }
    // 00aa8eee  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00aa8ef0  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00aa8ef2  e8a9eeffff             -call 0xaa7da0
    cpu.esp -= 4;
    sub_aa7da0(app, cpu);
    if (cpu.terminate) return;
    // 00aa8ef7  891d7448ab00           -mov dword ptr [0xab4874], ebx
    app->getMemory<x86::reg32>(x86::reg32(11225204) /* 0xab4874 */) = cpu.ebx;
L_0x00aa8efd:
    // 00aa8efd  8b0d7848ab00           -mov ecx, dword ptr [0xab4878]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11225208) /* 0xab4878 */);
    // 00aa8f03  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00aa8f05  740f                   -je 0xaa8f16
    if (cpu.flags.zf)
    {
        goto L_0x00aa8f16;
    }
    // 00aa8f07  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00aa8f09  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00aa8f0b  e890eeffff             -call 0xaa7da0
    cpu.esp -= 4;
    sub_aa7da0(app, cpu);
    if (cpu.terminate) return;
    // 00aa8f10  89357848ab00           -mov dword ptr [0xab4878], esi
    app->getMemory<x86::reg32>(x86::reg32(11225208) /* 0xab4878 */) = cpu.esi;
L_0x00aa8f16:
    // 00aa8f16  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa8f17  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa8f18  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa8f19  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa8f1a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void sub_aa8f20(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa8f20  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00aa8f21  833800                 +cmp dword ptr [eax], 0
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
    // 00aa8f24  7404                   -je 0xaa8f2a
    if (cpu.flags.zf)
    {
        goto L_0x00aa8f2a;
    }
    // 00aa8f26  1e                     -push ds
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.ds;
    cpu.esp -= 4;
    // 00aa8f27  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00aa8f28  ff10                   -call dword ptr [eax]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00aa8f2a:
    // 00aa8f2a  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00aa8f2b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_aa8f2c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa8f2c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aa8f2d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aa8f2e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aa8f2f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aa8f30  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00aa8f31  be743dab00             -mov esi, 0xab3d74
    cpu.esi = 11222388 /*0xab3d74*/;
    // 00aa8f36  88c6                   -mov dh, al
    cpu.dh = cpu.al;
L_0x00aa8f38:
    // 00aa8f38  b8443dab00             -mov eax, 0xab3d44
    cpu.eax = 11222340 /*0xab3d44*/;
    // 00aa8f3d  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00aa8f3f  88f2                   -mov dl, dh
    cpu.dl = cpu.dh;
    // 00aa8f41  39c6                   +cmp esi, eax
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
    // 00aa8f43  761a                   -jbe 0xaa8f5f
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00aa8f5f;
    }
L_0x00aa8f45:
    // 00aa8f45  803802                 +cmp byte ptr [eax], 2
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
    // 00aa8f48  740b                   -je 0xaa8f55
    if (cpu.flags.zf)
    {
        goto L_0x00aa8f55;
    }
    // 00aa8f4a  8a6801                 -mov ch, byte ptr [eax + 1]
    cpu.ch = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00aa8f4d  38ea                   +cmp dl, ch
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
    // 00aa8f4f  7204                   -jb 0xaa8f55
    if (cpu.flags.cf)
    {
        goto L_0x00aa8f55;
    }
    // 00aa8f51  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00aa8f53  88ea                   -mov dl, ch
    cpu.dl = cpu.ch;
L_0x00aa8f55:
    // 00aa8f55  83c006                 -add eax, 6
    (cpu.eax) += x86::reg32(x86::sreg32(6 /*0x6*/));
    // 00aa8f58  3d743dab00             +cmp eax, 0xab3d74
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(11222388 /*0xab3d74*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00aa8f5d  72e6                   -jb 0xaa8f45
    if (cpu.flags.cf)
    {
        goto L_0x00aa8f45;
    }
L_0x00aa8f5f:
    // 00aa8f5f  81fb743dab00           +cmp ebx, 0xab3d74
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(11222388 /*0xab3d74*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00aa8f65  740d                   -je 0xaa8f74
    if (cpu.flags.zf)
    {
        goto L_0x00aa8f74;
    }
    // 00aa8f67  8d4302                 -lea eax, [ebx + 2]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(2) /* 0x2 */);
    // 00aa8f6a  e8b1ffffff             -call 0xaa8f20
    cpu.esp -= 4;
    sub_aa8f20(app, cpu);
    if (cpu.terminate) return;
    // 00aa8f6f  c60302                 -mov byte ptr [ebx], 2
    app->getMemory<x86::reg8>(cpu.ebx) = 2 /*0x2*/;
    // 00aa8f72  ebc4                   -jmp 0xaa8f38
    goto L_0x00aa8f38;
L_0x00aa8f74:
    // 00aa8f74  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00aa8f75  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa8f76  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa8f77  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa8f78  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa8f79  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void sub_aa8f7c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa8f7c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aa8f7d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aa8f7e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aa8f7f  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00aa8f80  be443dab00             -mov esi, 0xab3d44
    cpu.esi = 11222340 /*0xab3d44*/;
    // 00aa8f85  88c1                   -mov cl, al
    cpu.cl = cpu.al;
    // 00aa8f87  88d6                   -mov dh, dl
    cpu.dh = cpu.dl;
L_0x00aa8f89:
    // 00aa8f89  b81a3dab00             -mov eax, 0xab3d1a
    cpu.eax = 11222298 /*0xab3d1a*/;
    // 00aa8f8e  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00aa8f90  88ca                   -mov dl, cl
    cpu.dl = cpu.cl;
    // 00aa8f92  39c6                   +cmp esi, eax
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
    // 00aa8f94  761a                   -jbe 0xaa8fb0
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00aa8fb0;
    }
L_0x00aa8f96:
    // 00aa8f96  803802                 +cmp byte ptr [eax], 2
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
    // 00aa8f99  740b                   -je 0xaa8fa6
    if (cpu.flags.zf)
    {
        goto L_0x00aa8fa6;
    }
    // 00aa8f9b  8a6801                 -mov ch, byte ptr [eax + 1]
    cpu.ch = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00aa8f9e  38ea                   +cmp dl, ch
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
    // 00aa8fa0  7704                   -ja 0xaa8fa6
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00aa8fa6;
    }
    // 00aa8fa2  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00aa8fa4  88ea                   -mov dl, ch
    cpu.dl = cpu.ch;
L_0x00aa8fa6:
    // 00aa8fa6  83c006                 -add eax, 6
    (cpu.eax) += x86::reg32(x86::sreg32(6 /*0x6*/));
    // 00aa8fa9  3d443dab00             +cmp eax, 0xab3d44
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(11222340 /*0xab3d44*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00aa8fae  72e6                   -jb 0xaa8f96
    if (cpu.flags.cf)
    {
        goto L_0x00aa8f96;
    }
L_0x00aa8fb0:
    // 00aa8fb0  81fb443dab00           +cmp ebx, 0xab3d44
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(11222340 /*0xab3d44*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00aa8fb6  7412                   -je 0xaa8fca
    if (cpu.flags.zf)
    {
        goto L_0x00aa8fca;
    }
    // 00aa8fb8  3a7301                 +cmp dh, byte ptr [ebx + 1]
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
    // 00aa8fbb  7208                   -jb 0xaa8fc5
    if (cpu.flags.cf)
    {
        goto L_0x00aa8fc5;
    }
    // 00aa8fbd  8d4302                 -lea eax, [ebx + 2]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(2) /* 0x2 */);
    // 00aa8fc0  e85bffffff             -call 0xaa8f20
    cpu.esp -= 4;
    sub_aa8f20(app, cpu);
    if (cpu.terminate) return;
L_0x00aa8fc5:
    // 00aa8fc5  c60302                 -mov byte ptr [ebx], 2
    app->getMemory<x86::reg8>(cpu.ebx) = 2 /*0x2*/;
    // 00aa8fc8  ebbf                   -jmp 0xaa8f89
    goto L_0x00aa8f89;
L_0x00aa8fca:
    // 00aa8fca  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00aa8fcb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa8fcc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa8fcd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa8fce  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void sub_aa8fd0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa8fd0  09c9                   +or ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx |= x86::reg32(x86::sreg32(cpu.ecx))));
    // 00aa8fd2  742c                   -je 0xaa9000
    if (cpu.flags.zf)
    {
        goto L_0x00aa9000;
    }
    // 00aa8fd4  3810                   -cmp byte ptr [eax], dl
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
L_0x00aa8fd6:
    // 00aa8fd6  a803                   +test al, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 3 /*0x3*/));
    // 00aa8fd8  7409                   -je 0xaa8fe3
    if (cpu.flags.zf)
    {
        goto L_0x00aa8fe3;
    }
    // 00aa8fda  8810                   -mov byte ptr [eax], dl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.dl;
    // 00aa8fdc  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00aa8fdd  c1ca08                 +ror edx, 8
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
    // 00aa8fe0  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00aa8fe1  75f3                   -jne 0xaa8fd6
    if (!cpu.flags.zf)
    {
        goto L_0x00aa8fd6;
    }
L_0x00aa8fe3:
    // 00aa8fe3  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aa8fe4  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00aa8fe7  e81b000000             -call 0xaa9007
    cpu.esp -= 4;
    sub_aa9007(app, cpu);
    if (cpu.terminate) return;
    // 00aa8fec  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa8fed  83e103                 +and ecx, 3
    cpu.clear_co();
    cpu.set_szp((cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/))));
    // 00aa8ff0  740e                   -je 0xaa9000
    if (cpu.flags.zf)
    {
        goto L_0x00aa9000;
    }
    // 00aa8ff2  8810                   -mov byte ptr [eax], dl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.dl;
    // 00aa8ff4  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00aa8ff5  7409                   -je 0xaa9000
    if (cpu.flags.zf)
    {
        goto L_0x00aa9000;
    }
    // 00aa8ff7  887001                 -mov byte ptr [eax + 1], dh
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */) = cpu.dh;
    // 00aa8ffa  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00aa8ffb  7403                   -je 0xaa9000
    if (cpu.flags.zf)
    {
        goto L_0x00aa9000;
    }
    // 00aa8ffd  885002                 -mov byte ptr [eax + 2], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */) = cpu.dl;
L_0x00aa9000:
    // 00aa9000  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void sub_aa9002(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa9002  90                     -nop 
    ;
    // 00aa9003  90                     -nop 
    ;
    // 00aa9004  90                     -nop 
    ;
    // 00aa9005  90                     -nop 
    ;
    // 00aa9006  90                     -nop 
    ;
    // 00aa9007  09c9                   +or ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx |= x86::reg32(x86::sreg32(cpu.ecx))));
    // 00aa9009  7467                   -je 0xaa9072
    if (cpu.flags.zf)
    {
        goto L_0x00aa9072;
    }
L_0x00aa900b:
    // 00aa900b  a81f                   +test al, 0x1f
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 31 /*0x1f*/));
    // 00aa900d  7408                   -je 0xaa9017
    if (cpu.flags.zf)
    {
        goto L_0x00aa9017;
    }
    // 00aa900f  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 00aa9011  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00aa9014  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00aa9015  75f4                   -jne 0xaa900b
    if (!cpu.flags.zf)
    {
        goto L_0x00aa900b;
    }
L_0x00aa9017:
    // 00aa9017  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aa9018  c1e902                 +shr ecx, 2
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
    // 00aa901b  743a                   -je 0xaa9057
    if (cpu.flags.zf)
    {
        goto L_0x00aa9057;
    }
    // 00aa901d  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00aa901e  7429                   -je 0xaa9049
    if (cpu.flags.zf)
    {
        goto L_0x00aa9049;
    }
L_0x00aa9020:
    // 00aa9020  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 00aa9022  895004                 -mov dword ptr [eax + 4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00aa9025  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00aa9026  895008                 -mov dword ptr [eax + 8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00aa9029  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00aa902c  7418                   -je 0xaa9046
    if (cpu.flags.zf)
    {
        goto L_0x00aa9046;
    }
    // 00aa902e  385020                 +cmp byte ptr [eax + 0x20], dl
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
    // 00aa9031  895010                 -mov dword ptr [eax + 0x10], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 00aa9034  895014                 -mov dword ptr [eax + 0x14], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 00aa9037  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00aa9038  895018                 -mov dword ptr [eax + 0x18], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 00aa903b  89501c                 -mov dword ptr [eax + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 00aa903e  8d4020                 -lea eax, [eax + 0x20]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 00aa9041  75dd                   -jne 0xaa9020
    if (!cpu.flags.zf)
    {
        goto L_0x00aa9020;
    }
    // 00aa9043  8d40f0                 -lea eax, [eax - 0x10]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(-16) /* -0x10 */);
L_0x00aa9046:
    // 00aa9046  8d4010                 -lea eax, [eax + 0x10]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(16) /* 0x10 */);
L_0x00aa9049:
    // 00aa9049  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 00aa904b  895004                 -mov dword ptr [eax + 4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00aa904e  895008                 -mov dword ptr [eax + 8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00aa9051  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00aa9054  8d4010                 -lea eax, [eax + 0x10]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(16) /* 0x10 */);
L_0x00aa9057:
    // 00aa9057  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa9058  83e103                 +and ecx, 3
    cpu.clear_co();
    cpu.set_szp((cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/))));
    // 00aa905b  7415                   -je 0xaa9072
    if (cpu.flags.zf)
    {
        goto L_0x00aa9072;
    }
    // 00aa905d  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 00aa905f  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00aa9062  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00aa9063  740d                   -je 0xaa9072
    if (cpu.flags.zf)
    {
        goto L_0x00aa9072;
    }
    // 00aa9065  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 00aa9067  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00aa906a  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00aa906b  7405                   -je 0xaa9072
    if (cpu.flags.zf)
    {
        goto L_0x00aa9072;
    }
    // 00aa906d  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 00aa906f  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
L_0x00aa9072:
    // 00aa9072  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_aa9007(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00aa9007;
    // 00aa9002  90                     -nop 
    ;
    // 00aa9003  90                     -nop 
    ;
    // 00aa9004  90                     -nop 
    ;
    // 00aa9005  90                     -nop 
    ;
    // 00aa9006  90                     -nop 
    ;
L_entry_0x00aa9007:
    // 00aa9007  09c9                   +or ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx |= x86::reg32(x86::sreg32(cpu.ecx))));
    // 00aa9009  7467                   -je 0xaa9072
    if (cpu.flags.zf)
    {
        goto L_0x00aa9072;
    }
L_0x00aa900b:
    // 00aa900b  a81f                   +test al, 0x1f
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 31 /*0x1f*/));
    // 00aa900d  7408                   -je 0xaa9017
    if (cpu.flags.zf)
    {
        goto L_0x00aa9017;
    }
    // 00aa900f  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 00aa9011  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00aa9014  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00aa9015  75f4                   -jne 0xaa900b
    if (!cpu.flags.zf)
    {
        goto L_0x00aa900b;
    }
L_0x00aa9017:
    // 00aa9017  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aa9018  c1e902                 +shr ecx, 2
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
    // 00aa901b  743a                   -je 0xaa9057
    if (cpu.flags.zf)
    {
        goto L_0x00aa9057;
    }
    // 00aa901d  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00aa901e  7429                   -je 0xaa9049
    if (cpu.flags.zf)
    {
        goto L_0x00aa9049;
    }
L_0x00aa9020:
    // 00aa9020  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 00aa9022  895004                 -mov dword ptr [eax + 4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00aa9025  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00aa9026  895008                 -mov dword ptr [eax + 8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00aa9029  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00aa902c  7418                   -je 0xaa9046
    if (cpu.flags.zf)
    {
        goto L_0x00aa9046;
    }
    // 00aa902e  385020                 +cmp byte ptr [eax + 0x20], dl
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
    // 00aa9031  895010                 -mov dword ptr [eax + 0x10], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 00aa9034  895014                 -mov dword ptr [eax + 0x14], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 00aa9037  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00aa9038  895018                 -mov dword ptr [eax + 0x18], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 00aa903b  89501c                 -mov dword ptr [eax + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 00aa903e  8d4020                 -lea eax, [eax + 0x20]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 00aa9041  75dd                   -jne 0xaa9020
    if (!cpu.flags.zf)
    {
        goto L_0x00aa9020;
    }
    // 00aa9043  8d40f0                 -lea eax, [eax - 0x10]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(-16) /* -0x10 */);
L_0x00aa9046:
    // 00aa9046  8d4010                 -lea eax, [eax + 0x10]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(16) /* 0x10 */);
L_0x00aa9049:
    // 00aa9049  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 00aa904b  895004                 -mov dword ptr [eax + 4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00aa904e  895008                 -mov dword ptr [eax + 8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00aa9051  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00aa9054  8d4010                 -lea eax, [eax + 0x10]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(16) /* 0x10 */);
L_0x00aa9057:
    // 00aa9057  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa9058  83e103                 +and ecx, 3
    cpu.clear_co();
    cpu.set_szp((cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/))));
    // 00aa905b  7415                   -je 0xaa9072
    if (cpu.flags.zf)
    {
        goto L_0x00aa9072;
    }
    // 00aa905d  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 00aa905f  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00aa9062  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00aa9063  740d                   -je 0xaa9072
    if (cpu.flags.zf)
    {
        goto L_0x00aa9072;
    }
    // 00aa9065  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 00aa9067  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00aa906a  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00aa906b  7405                   -je 0xaa9072
    if (cpu.flags.zf)
    {
        goto L_0x00aa9072;
    }
    // 00aa906d  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 00aa906f  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
L_0x00aa9072:
    // 00aa9072  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_aa9080(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa9080  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aa9081  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aa9082  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00aa9084  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00aa9086  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00aa9088  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00aa908a  763c                   -jbe 0xaa90c8
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00aa90c8;
    }
L_0x00aa908c:
    // 00aa908c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00aa908e  e8dd2c0000             -call 0xaabd70
    cpu.esp -= 4;
    sub_aabd70(app, cpu);
    if (cpu.terminate) return;
    // 00aa9093  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aa9095  7531                   -jne 0xaa90c8
    if (!cpu.flags.zf)
    {
        goto L_0x00aa90c8;
    }
    // 00aa9097  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00aa9099  e8d22c0000             -call 0xaabd70
    cpu.esp -= 4;
    sub_aabd70(app, cpu);
    if (cpu.terminate) return;
    // 00aa909e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aa90a0  7526                   -jne 0xaa90c8
    if (!cpu.flags.zf)
    {
        goto L_0x00aa90c8;
    }
    // 00aa90a2  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00aa90a4  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00aa90a6  e8052d0000             -call 0xaabdb0
    cpu.esp -= 4;
    sub_aabdb0(app, cpu);
    if (cpu.terminate) return;
    // 00aa90ab  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00aa90ad  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aa90af  753d                   -jne 0xaa90ee
    if (!cpu.flags.zf)
    {
        goto L_0x00aa90ee;
    }
    // 00aa90b1  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00aa90b3  e8582d0000             -call 0xaabe10
    cpu.esp -= 4;
    sub_aabe10(app, cpu);
    if (cpu.terminate) return;
    // 00aa90b8  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00aa90ba  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00aa90bc  4b                     -dec ebx
    (cpu.ebx)--;
    // 00aa90bd  e84e2d0000             -call 0xaabe10
    cpu.esp -= 4;
    sub_aabe10(app, cpu);
    if (cpu.terminate) return;
    // 00aa90c2  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00aa90c4  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00aa90c6  77c4                   -ja 0xaa908c
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00aa908c;
    }
L_0x00aa90c8:
    // 00aa90c8  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00aa90ca  7620                   -jbe 0xaa90ec
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00aa90ec;
    }
    // 00aa90cc  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00aa90ce  e89d2c0000             -call 0xaabd70
    cpu.esp -= 4;
    sub_aabd70(app, cpu);
    if (cpu.terminate) return;
    // 00aa90d3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aa90d5  750b                   -jne 0xaa90e2
    if (!cpu.flags.zf)
    {
        goto L_0x00aa90e2;
    }
    // 00aa90d7  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00aa90d9  e8922c0000             -call 0xaabd70
    cpu.esp -= 4;
    sub_aabd70(app, cpu);
    if (cpu.terminate) return;
    // 00aa90de  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aa90e0  740a                   -je 0xaa90ec
    if (cpu.flags.zf)
    {
        goto L_0x00aa90ec;
    }
L_0x00aa90e2:
    // 00aa90e2  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00aa90e4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00aa90e6  8a11                   -mov dl, byte ptr [ecx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx);
    // 00aa90e8  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00aa90ea  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
L_0x00aa90ec:
    // 00aa90ec  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x00aa90ee:
    // 00aa90ee  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa90ef  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa90f0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_aa9100(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa9100  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aa9101  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aa9102  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00aa9103  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00aa9104  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 00aa9106  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aa9108  0f849a000000           -je 0xaa91a8
    if (cpu.flags.zf)
    {
        goto L_0x00aa91a8;
    }
    // 00aa910e  8d480b                 -lea ecx, [eax + 0xb]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(11) /* 0xb */);
    // 00aa9111  39c1                   +cmp ecx, eax
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
    // 00aa9113  0f828f000000           -jb 0xaa91a8
    if (cpu.flags.cf)
    {
        goto L_0x00aa91a8;
    }
    // 00aa9119  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00aa911b  80e1f8                 -and cl, 0xf8
    cpu.cl &= x86::reg8(x86::sreg8(248 /*0xf8*/));
    // 00aa911e  8b4314                 -mov eax, dword ptr [ebx + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 00aa9121  83f910                 +cmp ecx, 0x10
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
    // 00aa9124  7305                   -jae 0xaa912b
    if (!cpu.flags.cf)
    {
        goto L_0x00aa912b;
    }
    // 00aa9126  b910000000             -mov ecx, 0x10
    cpu.ecx = 16 /*0x10*/;
L_0x00aa912b:
    // 00aa912b  39c1                   +cmp ecx, eax
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
    // 00aa912d  0f8775000000           -ja 0xaa91a8
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00aa91a8;
    }
    // 00aa9133  8b5f10                 -mov ebx, dword ptr [edi + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(16) /* 0x10 */);
    // 00aa9136  8b470c                 -mov eax, dword ptr [edi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */);
    // 00aa9139  39d9                   +cmp ecx, ebx
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
    // 00aa913b  7705                   -ja 0xaa9142
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00aa9142;
    }
    // 00aa913d  8b4728                 -mov eax, dword ptr [edi + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(40) /* 0x28 */);
    // 00aa9140  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x00aa9142:
    // 00aa9142  8d7720                 -lea esi, [edi + 0x20]
    cpu.esi = x86::reg32(cpu.edi + x86::reg32(32) /* 0x20 */);
L_0x00aa9145:
    // 00aa9145  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00aa9147  39d1                   +cmp ecx, edx
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
    // 00aa9149  7612                   -jbe 0xaa915d
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00aa915d;
    }
    // 00aa914b  39da                   +cmp edx, ebx
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
    // 00aa914d  7602                   -jbe 0xaa9151
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00aa9151;
    }
    // 00aa914f  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
L_0x00aa9151:
    // 00aa9151  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00aa9154  39f0                   +cmp eax, esi
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
    // 00aa9156  75ed                   -jne 0xaa9145
    if (!cpu.flags.zf)
    {
        goto L_0x00aa9145;
    }
    // 00aa9158  895f14                 -mov dword ptr [edi + 0x14], ebx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(20) /* 0x14 */) = cpu.ebx;
    // 00aa915b  eb4b                   -jmp 0xaa91a8
    goto L_0x00aa91a8;
L_0x00aa915d:
    // 00aa915d  895f10                 -mov dword ptr [edi + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 00aa9160  8b5f18                 -mov ebx, dword ptr [edi + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */);
    // 00aa9163  43                     -inc ebx
    (cpu.ebx)++;
    // 00aa9164  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00aa9166  895f18                 -mov dword ptr [edi + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 00aa9169  83fa10                 +cmp edx, 0x10
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
    // 00aa916c  721e                   -jb 0xaa918c
    if (cpu.flags.cf)
    {
        goto L_0x00aa918c;
    }
    // 00aa916e  8d1c08                 -lea ebx, [eax + ecx]
    cpu.ebx = x86::reg32(cpu.eax + cpu.ecx * 1);
    // 00aa9171  895f0c                 -mov dword ptr [edi + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 00aa9174  8913                   -mov dword ptr [ebx], edx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
    // 00aa9176  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 00aa9178  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00aa917b  894b04                 -mov dword ptr [ebx + 4], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 00aa917e  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00aa9181  895308                 -mov dword ptr [ebx + 8], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00aa9184  895908                 -mov dword ptr [ecx + 8], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 00aa9187  895a04                 -mov dword ptr [edx + 4], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 00aa918a  eb12                   -jmp 0xaa919e
    goto L_0x00aa919e;
L_0x00aa918c:
    // 00aa918c  ff4f1c                 -dec dword ptr [edi + 0x1c]
    (app->getMemory<x86::reg32>(cpu.edi + x86::reg32(28) /* 0x1c */))--;
    // 00aa918f  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00aa9192  89570c                 -mov dword ptr [edi + 0xc], edx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00aa9195  8b5808                 -mov ebx, dword ptr [eax + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00aa9198  895a08                 -mov dword ptr [edx + 8], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 00aa919b  895304                 -mov dword ptr [ebx + 4], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.edx;
L_0x00aa919e:
    // 00aa919e  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 00aa91a0  80ca01                 -or dl, 1
    cpu.dl |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00aa91a3  8d6804                 -lea ebp, [eax + 4]
    cpu.ebp = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00aa91a6  8810                   -mov byte ptr [eax], dl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.dl;
L_0x00aa91a8:
    // 00aa91a8  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00aa91aa  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa91ab  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa91ac  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa91ad  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa91ae  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void sub_aa91b0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa91b0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aa91b1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aa91b2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00aa91b3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00aa91b4  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00aa91b6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aa91b8  0f841d010000           -je 0xaa92db
    if (cpu.flags.zf)
    {
        goto L_0x00aa92db;
    }
    // 00aa91be  8d58fc                 -lea ebx, [eax - 4]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(-4) /* -0x4 */);
    // 00aa91c1  f60301                 +test byte ptr [ebx], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebx) & 1 /*0x1*/));
    // 00aa91c4  0f8411010000           -je 0xaa92db
    if (cpu.flags.zf)
    {
        goto L_0x00aa92db;
    }
    // 00aa91ca  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 00aa91cc  80e2fe                 -and dl, 0xfe
    cpu.dl &= x86::reg8(x86::sreg8(254 /*0xfe*/));
    // 00aa91cf  8d0413                 -lea eax, [ebx + edx]
    cpu.eax = x86::reg32(cpu.ebx + cpu.edx * 1);
    // 00aa91d2  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00aa91d4  f60001                 +test byte ptr [eax], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax) & 1 /*0x1*/));
    // 00aa91d7  7522                   -jne 0xaa91fb
    if (!cpu.flags.zf)
    {
        goto L_0x00aa91fb;
    }
    // 00aa91d9  8b38                   -mov edi, dword ptr [eax]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax);
    // 00aa91db  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 00aa91dd  8913                   -mov dword ptr [ebx], edx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
    // 00aa91df  3b410c                 +cmp eax, dword ptr [ecx + 0xc]
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
    // 00aa91e2  7503                   -jne 0xaa91e7
    if (!cpu.flags.zf)
    {
        goto L_0x00aa91e7;
    }
    // 00aa91e4  89590c                 -mov dword ptr [ecx + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.ebx;
L_0x00aa91e7:
    // 00aa91e7  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00aa91ea  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00aa91ed  894208                 -mov dword ptr [edx + 8], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00aa91f0  895004                 -mov dword ptr [eax + 4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00aa91f3  ff4e1c                 +dec dword ptr [esi + 0x1c]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00aa91f6  e994000000             -jmp 0xaa928f
    goto L_0x00aa928f;
L_0x00aa91fb:
    // 00aa91fb  8913                   -mov dword ptr [ebx], edx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
    // 00aa91fd  8b410c                 -mov eax, dword ptr [ecx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00aa9200  39c3                   +cmp ebx, eax
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
    // 00aa9202  7316                   -jae 0xaa921a
    if (!cpu.flags.cf)
    {
        goto L_0x00aa921a;
    }
    // 00aa9204  3b5804                 +cmp ebx, dword ptr [eax + 4]
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
    // 00aa9207  0f8782000000           -ja 0xaa928f
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00aa928f;
    }
    // 00aa920d  8b4128                 -mov eax, dword ptr [ecx + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */);
    // 00aa9210  39c3                   +cmp ebx, eax
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
    // 00aa9212  0f8277000000           -jb 0xaa928f
    if (cpu.flags.cf)
    {
        goto L_0x00aa928f;
    }
    // 00aa9218  eb19                   -jmp 0xaa9233
    goto L_0x00aa9233;
L_0x00aa921a:
    // 00aa921a  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00aa921d  39c3                   +cmp ebx, eax
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
    // 00aa921f  0f826a000000           -jb 0xaa928f
    if (cpu.flags.cf)
    {
        goto L_0x00aa928f;
    }
    // 00aa9225  8d4120                 -lea eax, [ecx + 0x20]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 00aa9228  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00aa922b  39d3                   +cmp ebx, edx
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
    // 00aa922d  0f875c000000           -ja 0xaa928f
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00aa928f;
    }
L_0x00aa9233:
    // 00aa9233  8b7e1c                 -mov edi, dword ptr [esi + 0x1c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 00aa9236  8b4618                 -mov eax, dword ptr [esi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 00aa9239  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00aa923b  8d4f01                 -lea ecx, [edi + 1]
    cpu.ecx = x86::reg32(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 00aa923e  f7f1                   -div ecx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ecx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 00aa9240  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00aa9242  39f8                   +cmp eax, edi
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
    // 00aa9244  7328                   -jae 0xaa926e
    if (!cpu.flags.cf)
    {
        goto L_0x00aa926e;
    }
    // 00aa9246  8b4618                 -mov eax, dword ptr [esi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 00aa9249  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 00aa924b  01c9                   -add ecx, ecx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00aa924d  39f8                   +cmp eax, edi
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
    // 00aa924f  7705                   -ja 0xaa9256
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00aa9256;
    }
    // 00aa9251  b9ffffffff             -mov ecx, 0xffffffff
    cpu.ecx = 4294967295 /*0xffffffff*/;
L_0x00aa9256:
    // 00aa9256  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 00aa9258  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
L_0x00aa925a:
    // 00aa925a  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00aa925c  f6c201                 +test dl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 1 /*0x1*/));
    // 00aa925f  742e                   -je 0xaa928f
    if (cpu.flags.zf)
    {
        goto L_0x00aa928f;
    }
    // 00aa9261  83faff                 +cmp edx, -1
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
    // 00aa9264  7408                   -je 0xaa926e
    if (cpu.flags.zf)
    {
        goto L_0x00aa926e;
    }
    // 00aa9266  80e2fe                 -and dl, 0xfe
    cpu.dl &= x86::reg8(x86::sreg8(254 /*0xfe*/));
    // 00aa9269  01d0                   +add eax, edx
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
    // 00aa926b  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00aa926c  75ec                   -jne 0xaa925a
    if (!cpu.flags.zf)
    {
        goto L_0x00aa925a;
    }
L_0x00aa926e:
    // 00aa926e  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 00aa9271  39c3                   +cmp ebx, eax
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
    // 00aa9273  7303                   -jae 0xaa9278
    if (!cpu.flags.cf)
    {
        goto L_0x00aa9278;
    }
    // 00aa9275  8b4628                 -mov eax, dword ptr [esi + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
L_0x00aa9278:
    // 00aa9278  39c3                   +cmp ebx, eax
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
    // 00aa927a  7213                   -jb 0xaa928f
    if (cpu.flags.cf)
    {
        goto L_0x00aa928f;
    }
    // 00aa927c  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00aa927f  39c3                   +cmp ebx, eax
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
    // 00aa9281  720c                   -jb 0xaa928f
    if (cpu.flags.cf)
    {
        goto L_0x00aa928f;
    }
    // 00aa9283  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00aa9286  39c3                   +cmp ebx, eax
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
    // 00aa9288  7205                   -jb 0xaa928f
    if (cpu.flags.cf)
    {
        goto L_0x00aa928f;
    }
    // 00aa928a  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00aa928d  ebe9                   -jmp 0xaa9278
    goto L_0x00aa9278;
L_0x00aa928f:
    // 00aa928f  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00aa9292  8b3a                   -mov edi, dword ptr [edx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx);
    // 00aa9294  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 00aa9296  8b0b                   -mov ecx, dword ptr [ebx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx);
    // 00aa9298  39df                   +cmp edi, ebx
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
    // 00aa929a  7512                   -jne 0xaa92ae
    if (!cpu.flags.zf)
    {
        goto L_0x00aa92ae;
    }
    // 00aa929c  8b2a                   -mov ebp, dword ptr [edx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx);
    // 00aa929e  01e9                   -add ecx, ebp
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00aa92a0  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 00aa92a2  3b5e0c                 +cmp ebx, dword ptr [esi + 0xc]
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
    // 00aa92a5  7503                   -jne 0xaa92aa
    if (!cpu.flags.zf)
    {
        goto L_0x00aa92aa;
    }
    // 00aa92a7  89560c                 -mov dword ptr [esi + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.edx;
L_0x00aa92aa:
    // 00aa92aa  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00aa92ac  eb0f                   -jmp 0xaa92bd
    goto L_0x00aa92bd;
L_0x00aa92ae:
    // 00aa92ae  ff461c                 -inc dword ptr [esi + 0x1c]
    (app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */))++;
    // 00aa92b1  894308                 -mov dword ptr [ebx + 8], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00aa92b4  895304                 -mov dword ptr [ebx + 4], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00aa92b7  895a08                 -mov dword ptr [edx + 8], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 00aa92ba  895804                 -mov dword ptr [eax + 4], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ebx;
L_0x00aa92bd:
    // 00aa92bd  8b5618                 -mov edx, dword ptr [esi + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 00aa92c0  4a                     -dec edx
    (cpu.edx)--;
    // 00aa92c1  8b7e0c                 -mov edi, dword ptr [esi + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 00aa92c4  895618                 -mov dword ptr [esi + 0x18], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 00aa92c7  39fb                   +cmp ebx, edi
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
    // 00aa92c9  7308                   -jae 0xaa92d3
    if (!cpu.flags.cf)
    {
        goto L_0x00aa92d3;
    }
    // 00aa92cb  3b4e10                 +cmp ecx, dword ptr [esi + 0x10]
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
    // 00aa92ce  7603                   -jbe 0xaa92d3
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00aa92d3;
    }
    // 00aa92d0  894e10                 -mov dword ptr [esi + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.ecx;
L_0x00aa92d3:
    // 00aa92d3  3b4e14                 +cmp ecx, dword ptr [esi + 0x14]
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
    // 00aa92d6  7603                   -jbe 0xaa92db
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00aa92db;
    }
    // 00aa92d8  894e14                 -mov dword ptr [esi + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.ecx;
L_0x00aa92db:
    // 00aa92db  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa92dc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa92dd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa92de  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa92df  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_aa92e0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa92e0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aa92e1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aa92e2  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00aa92e4  a17c36ab00             -mov eax, dword ptr [0xab367c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11220604) /* 0xab367c */);
    // 00aa92e9  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00aa92eb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aa92ed  740d                   -je 0xaa92fc
    if (cpu.flags.zf)
    {
        goto L_0x00aa92fc;
    }
L_0x00aa92ef:
    // 00aa92ef  39c2                   +cmp edx, eax
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
    // 00aa92f1  7209                   -jb 0xaa92fc
    if (cpu.flags.cf)
    {
        goto L_0x00aa92fc;
    }
    // 00aa92f3  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00aa92f5  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00aa92f8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aa92fa  75f3                   -jne 0xaa92ef
    if (!cpu.flags.zf)
    {
        goto L_0x00aa92ef;
    }
L_0x00aa92fc:
    // 00aa92fc  895a04                 -mov dword ptr [edx + 4], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 00aa92ff  894208                 -mov dword ptr [edx + 8], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00aa9302  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00aa9304  7405                   -je 0xaa930b
    if (cpu.flags.zf)
    {
        goto L_0x00aa930b;
    }
    // 00aa9306  895308                 -mov dword ptr [ebx + 8], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00aa9309  eb06                   -jmp 0xaa9311
    goto L_0x00aa9311;
L_0x00aa930b:
    // 00aa930b  89157c36ab00           -mov dword ptr [0xab367c], edx
    app->getMemory<x86::reg32>(x86::reg32(11220604) /* 0xab367c */) = cpu.edx;
L_0x00aa9311:
    // 00aa9311  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aa9313  7403                   -je 0xaa9318
    if (cpu.flags.zf)
    {
        goto L_0x00aa9318;
    }
    // 00aa9315  895004                 -mov dword ptr [eax + 4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
L_0x00aa9318:
    // 00aa9318  8d5a20                 -lea ebx, [edx + 0x20]
    cpu.ebx = x86::reg32(cpu.edx + x86::reg32(32) /* 0x20 */);
    // 00aa931b  83c22c                 -add edx, 0x2c
    (cpu.edx) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00aa931e  c742f400000000         -mov dword ptr [edx - 0xc], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-12) /* -0xc */) = 0 /*0x0*/;
    // 00aa9325  c742e400000000         -mov dword ptr [edx - 0x1c], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-28) /* -0x1c */) = 0 /*0x0*/;
    // 00aa932c  c742ec00000000         -mov dword ptr [edx - 0x14], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-20) /* -0x14 */) = 0 /*0x0*/;
    // 00aa9333  c742f000000000         -mov dword ptr [edx - 0x10], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-16) /* -0x10 */) = 0 /*0x0*/;
    // 00aa933a  895af8                 -mov dword ptr [edx - 8], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-8) /* -0x8 */) = cpu.ebx;
    // 00aa933d  8b42d4                 -mov eax, dword ptr [edx - 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-44) /* -0x2c */);
    // 00aa9340  895afc                 -mov dword ptr [edx - 4], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */) = cpu.ebx;
    // 00aa9343  83e82c                 -sub eax, 0x2c
    (cpu.eax) -= x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00aa9346  895ae0                 -mov dword ptr [edx - 0x20], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-32) /* -0x20 */) = cpu.ebx;
    // 00aa9349  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 00aa934b  c70402ffffffff         -mov dword ptr [edx + eax], 0xffffffff
    app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 1) = 4294967295 /*0xffffffff*/;
    // 00aa9352  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00aa9354  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa9355  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa9356  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void sub_aa9358(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa9358  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aa9359  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aa935a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aa935b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aa935c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00aa935d  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00aa9360  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00aa9363  833d3038ab0000         +cmp dword ptr [0xab3830], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(11221040) /* 0xab3830 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00aa936a  7507                   -jne 0xaa9373
    if (!cpu.flags.zf)
    {
        goto L_0x00aa9373;
    }
    // 00aa936c  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00aa936e  e998000000             -jmp 0xaa940b
    goto L_0x00aa940b;
L_0x00aa9373:
    // 00aa9373  833d3c37ab00fe         +cmp dword ptr [0xab373c], -2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(11220796) /* 0xab373c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-2 /*-0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00aa937a  750b                   -jne 0xaa9387
    if (!cpu.flags.zf)
    {
        goto L_0x00aa9387;
    }
    // 00aa937c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00aa937e  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00aa9381  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa9382  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa9383  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa9384  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa9385  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa9386  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00aa9387:
    // 00aa9387  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00aa9389  e89a000000             -call 0xaa9428
    cpu.esp -= 4;
    sub_aa9428(app, cpu);
    if (cpu.terminate) return;
    // 00aa938e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aa9390  0f8475000000           -je 0xaa940b
    if (cpu.flags.zf)
    {
        goto L_0x00aa940b;
    }
    // 00aa9396  6a40                   -push 0x40
    app->getMemory<x86::reg32>(cpu.esp-4) = 64 /*0x40*/;
    cpu.esp -= 4;
    // 00aa9398  6800100000             -push 0x1000
    app->getMemory<x86::reg32>(cpu.esp-4) = 4096 /*0x1000*/;
    cpu.esp -= 4;
    // 00aa939d  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00aa93a1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aa93a2  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00aa93a4  2eff152c14ab00         -call dword ptr cs:[0xab142c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11211820) /* 0xab142c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa93ab  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00aa93ad  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aa93af  745a                   -je 0xaa940b
    if (cpu.flags.zf)
    {
        goto L_0x00aa940b;
    }
    // 00aa93b1  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00aa93b4  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    // 00aa93b7  83e804                 -sub eax, 4
    (cpu.eax) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00aa93ba  39f0                   +cmp eax, esi
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
    // 00aa93bc  760b                   -jbe 0xaa93c9
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00aa93c9;
    }
    // 00aa93be  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00aa93c0  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00aa93c3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa93c4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa93c5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa93c6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa93c7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa93c8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00aa93c9:
    // 00aa93c9  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00aa93cc  83f838                 +cmp eax, 0x38
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
    // 00aa93cf  730b                   -jae 0xaa93dc
    if (!cpu.flags.cf)
    {
        goto L_0x00aa93dc;
    }
    // 00aa93d1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00aa93d3  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00aa93d6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa93d7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa93d8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa93d9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa93da  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa93db  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00aa93dc:
    // 00aa93dc  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 00aa93de  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00aa93e0  e8fbfeffff             -call 0xaa92e0
    cpu.esp -= 4;
    sub_aa92e0(app, cpu);
    if (cpu.terminate) return;
    // 00aa93e5  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00aa93e7  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00aa93e9  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00aa93ec  0c01                   -or al, 1
    cpu.al |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00aa93ee  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 00aa93f0  8b7a18                 -mov edi, dword ptr [edx + 0x18]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 00aa93f3  c7421400000000         -mov dword ptr [edx + 0x14], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */) = 0 /*0x0*/;
    // 00aa93fa  47                     -inc edi
    (cpu.edi)++;
    // 00aa93fb  8d4304                 -lea eax, [ebx + 4]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 00aa93fe  897a18                 -mov dword ptr [edx + 0x18], edi
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */) = cpu.edi;
    // 00aa9401  e89ae9ffff             -call 0xaa7da0
    cpu.esp -= 4;
    sub_aa7da0(app, cpu);
    if (cpu.terminate) return;
    // 00aa9406  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x00aa940b:
    // 00aa940b  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00aa940e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa940f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa9410  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa9411  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa9412  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa9413  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_aa9414(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa9414  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aa9415  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00aa9417  e8542a0000             -call 0xaabe70
    cpu.esp -= 4;
    sub_aabe70(app, cpu);
    if (cpu.terminate) return;
    // 00aa941c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00aa941e  e835ffffff             -call 0xaa9358
    cpu.esp -= 4;
    sub_aa9358(app, cpu);
    if (cpu.terminate) return;
    // 00aa9423  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa9424  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_aa9428(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa9428  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aa9429  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aa942a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00aa942c  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00aa942e  83c007                 -add eax, 7
    (cpu.eax) += x86::reg32(x86::sreg32(7 /*0x7*/));
    // 00aa9431  24f8                   -and al, 0xf8
    cpu.al &= x86::reg8(x86::sreg8(248 /*0xf8*/));
    // 00aa9433  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aa9435  743d                   -je 0xaa9474
    if (cpu.flags.zf)
    {
        goto L_0x00aa9474;
    }
    // 00aa9437  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 00aa9439  83c03c                 -add eax, 0x3c
    (cpu.eax) += x86::reg32(x86::sreg32(60 /*0x3c*/));
    // 00aa943c  3b02                   +cmp eax, dword ptr [edx]
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
    // 00aa943e  7305                   -jae 0xaa9445
    if (!cpu.flags.cf)
    {
        goto L_0x00aa9445;
    }
    // 00aa9440  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00aa9442  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa9443  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa9444  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00aa9445:
    // 00aa9445  8b0d3438ab00           -mov ecx, dword ptr [0xab3834]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11221044) /* 0xab3834 */);
    // 00aa944b  39c8                   +cmp eax, ecx
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
    // 00aa944d  7304                   -jae 0xaa9453
    if (!cpu.flags.cf)
    {
        goto L_0x00aa9453;
    }
    // 00aa944f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00aa9451  24fe                   -and al, 0xfe
    cpu.al &= x86::reg8(x86::sreg8(254 /*0xfe*/));
L_0x00aa9453:
    // 00aa9453  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 00aa9455  05ff0f0000             -add eax, 0xfff
    (cpu.eax) += x86::reg32(x86::sreg32(4095 /*0xfff*/));
    // 00aa945a  3b02                   +cmp eax, dword ptr [edx]
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
    // 00aa945c  7305                   -jae 0xaa9463
    if (!cpu.flags.cf)
    {
        goto L_0x00aa9463;
    }
    // 00aa945e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00aa9460  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa9461  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa9462  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00aa9463:
    // 00aa9463  30c0                   -xor al, al
    cpu.al ^= x86::reg8(x86::sreg8(cpu.al));
    // 00aa9465  80e4f0                 -and ah, 0xf0
    cpu.ah &= x86::reg8(x86::sreg8(240 /*0xf0*/));
    // 00aa9468  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 00aa946a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aa946c  0f95c0                 -setne al
    cpu.al = !cpu.flags.zf;
    // 00aa946f  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
L_0x00aa9474:
    // 00aa9474  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa9475  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa9476  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_aa9480(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa9480  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00aa9482  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_aa9490(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa9490  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aa9491  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aa9492  ba40bfaa00             -mov edx, 0xaabf40
    cpu.edx = 11190080 /*0xaabf40*/;
    // 00aa9497  bb54c0aa00             -mov ebx, 0xaac054
    cpu.ebx = 11190356 /*0xaac054*/;
    // 00aa949c  89153838ab00           -mov dword ptr [0xab3838], edx
    app->getMemory<x86::reg32>(x86::reg32(11221048) /* 0xab3838 */) = cpu.edx;
    // 00aa94a2  891d3c38ab00           -mov dword ptr [0xab383c], ebx
    app->getMemory<x86::reg32>(x86::reg32(11221052) /* 0xab383c */) = cpu.ebx;
    // 00aa94a8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa94a9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa94aa  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void sub_aa94b0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa94b0  9b                     -wait 
    /*nothing*/;
    // 00aa94b1  dd30                   -fnsave dword ptr [eax]
    NFS2_ASSERT(false);
    // 00aa94b3  9b                     -wait 
    /*nothing*/;
    // 00aa94b4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_aa94b8(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa94b8  dd20                   -frstor dword ptr [eax]
    NFS2_ASSERT(false);
    // 00aa94ba  9b                     -wait 
    /*nothing*/;
    // 00aa94bb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_aa94bc(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa94bc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aa94bd  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aa94be  803d8d36ab0000         +cmp byte ptr [0xab368d], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(11220621) /* 0xab368d */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00aa94c5  7416                   -je 0xaa94dd
    if (cpu.flags.zf)
    {
        goto L_0x00aa94dd;
    }
    // 00aa94c7  bab094aa00             -mov edx, 0xaa94b0
    cpu.edx = 11179184 /*0xaa94b0*/;
    // 00aa94cc  bbb894aa00             -mov ebx, 0xaa94b8
    cpu.ebx = 11179192 /*0xaa94b8*/;
    // 00aa94d1  89154038ab00           -mov dword ptr [0xab3840], edx
    app->getMemory<x86::reg32>(x86::reg32(11221056) /* 0xab3840 */) = cpu.edx;
    // 00aa94d7  891d4438ab00           -mov dword ptr [0xab3844], ebx
    app->getMemory<x86::reg32>(x86::reg32(11221060) /* 0xab3844 */) = cpu.ebx;
L_0x00aa94dd:
    // 00aa94dd  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00aa94df  66a14838ab00           -mov ax, word ptr [0xab3848]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(11221064) /* 0xab3848 */);
    // 00aa94e5  e8b62b0000             -call 0xaac0a0
    cpu.esp -= 4;
    sub_aac0a0(app, cpu);
    if (cpu.terminate) return;
    // 00aa94ea  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa94eb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa94ec  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_aa94f0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa94f0  803d8d36ab0000         +cmp byte ptr [0xab368d], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(11220621) /* 0xab368d */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00aa94f7  75c3                   -jne 0xaa94bc
    if (!cpu.flags.zf)
    {
        return sub_aa94bc(app, cpu);
    }
    // 00aa94f9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void sub_aa94fc(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa94fc  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aa94fd  8a258c36ab00           -mov ah, byte ptr [0xab368c]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(11220620) /* 0xab368c */);
    // 00aa9503  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 00aa9505  7537                   -jne 0xaa953e
    if (!cpu.flags.zf)
    {
        goto L_0x00aa953e;
    }
    // 00aa9507  88258d36ab00           -mov byte ptr [0xab368d], ah
    app->getMemory<x86::reg8>(x86::reg32(11220621) /* 0xab368d */) = cpu.ah;
    // 00aa950d  30f6                   -xor dh, dh
    cpu.dh ^= x86::reg8(x86::sreg8(cpu.dh));
    // 00aa950f  2bc0                   -sub eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00aa9511  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00aa9512  dbe3                   -fninit 
    cpu.fpu.init();
    // 00aa9514  d93c24                 -fnstcw word ptr [esp]
    app->getMemory<x86::reg16>(cpu.esp) = cpu.fpu.control.word;
    // 00aa9517  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa9518  8ac4                   -mov al, ah
    cpu.al = cpu.ah;
    // 00aa951a  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 00aa951c  3c03                   +cmp al, 3
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
    // 00aa951e  7509                   -jne 0xaa9529
    if (!cpu.flags.zf)
    {
        goto L_0x00aa9529;
    }
    // 00aa9520  e897ffffff             -call 0xaa94bc
    cpu.esp -= 4;
    sub_aa94bc(app, cpu);
    if (cpu.terminate) return;
    // 00aa9525  88c6                   -mov dh, al
    cpu.dh = cpu.al;
    // 00aa9527  88c2                   -mov dl, al
    cpu.dl = cpu.al;
L_0x00aa9529:
    // 00aa9529  803d7837ab0000         +cmp byte ptr [0xab3778], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(11220856) /* 0xab3778 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00aa9530  750c                   -jne 0xaa953e
    if (!cpu.flags.zf)
    {
        goto L_0x00aa953e;
    }
    // 00aa9532  88358c36ab00           -mov byte ptr [0xab368c], dh
    app->getMemory<x86::reg8>(x86::reg32(11220620) /* 0xab368c */) = cpu.dh;
    // 00aa9538  88158d36ab00           -mov byte ptr [0xab368d], dl
    app->getMemory<x86::reg8>(x86::reg32(11220621) /* 0xab368d */) = cpu.dl;
L_0x00aa953e:
    // 00aa953e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa953f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_aa9540(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa9540  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_aa9550(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa9550  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_aa9554(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa9554  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aa9555  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aa9556  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aa9557  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aa9558  8b152056ab00           -mov edx, dword ptr [0xab5620]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11228704) /* 0xab5620 */);
    // 00aa955e  83fa40                 +cmp edx, 0x40
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
    // 00aa9561  7d1e                   -jge 0xaa9581
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00aa9581;
    }
    // 00aa9563  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00aa956a  bbf04fab00             -mov ebx, 0xab4ff0
    cpu.ebx = 11227120 /*0xab4ff0*/;
    // 00aa956f  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00aa9571  8d7201                 -lea esi, [edx + 1]
    cpu.esi = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 00aa9574  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00aa9577  89352056ab00           -mov dword ptr [0xab5620], esi
    app->getMemory<x86::reg32>(x86::reg32(11228704) /* 0xab5620 */) = cpu.esi;
    // 00aa957d  01c3                   +add ebx, eax
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
    // 00aa957f  eb67                   -jmp 0xaa95e8
    goto L_0x00aa95e8;
L_0x00aa9581:
    // 00aa9581  ba18000000             -mov edx, 0x18
    cpu.edx = 24 /*0x18*/;
    // 00aa9586  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00aa958b  e8402b0000             -call 0xaac0d0
    cpu.esp -= 4;
    sub_aac0d0(app, cpu);
    if (cpu.terminate) return;
    // 00aa9590  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00aa9592  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aa9594  750f                   -jne 0xaa95a5
    if (!cpu.flags.zf)
    {
        goto L_0x00aa95a5;
    }
    // 00aa9596  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00aa959b  b82c27ab00             -mov eax, 0xab272c
    cpu.eax = 11216684 /*0xab272c*/;
    // 00aa95a0  e857180000             -call 0xaaadfc
    cpu.esp -= 4;
    sub_aaadfc(app, cpu);
    if (cpu.terminate) return;
L_0x00aa95a5:
    // 00aa95a5  8b152456ab00           -mov edx, dword ptr [0xab5624]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11228708) /* 0xab5624 */);
    // 00aa95ab  42                     -inc edx
    (cpu.edx)++;
    // 00aa95ac  a12856ab00             -mov eax, dword ptr [0xab5628]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11228712) /* 0xab5628 */);
    // 00aa95b1  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 00aa95b4  e8372b0000             -call 0xaac0f0
    cpu.esp -= 4;
    sub_aac0f0(app, cpu);
    if (cpu.terminate) return;
    // 00aa95b9  a32856ab00             -mov dword ptr [0xab5628], eax
    app->getMemory<x86::reg32>(x86::reg32(11228712) /* 0xab5628 */) = cpu.eax;
    // 00aa95be  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aa95c0  750f                   -jne 0xaa95d1
    if (!cpu.flags.zf)
    {
        goto L_0x00aa95d1;
    }
    // 00aa95c2  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00aa95c7  b85027ab00             -mov eax, 0xab2750
    cpu.eax = 11216720 /*0xab2750*/;
    // 00aa95cc  e82b180000             -call 0xaaadfc
    cpu.esp -= 4;
    sub_aaadfc(app, cpu);
    if (cpu.terminate) return;
L_0x00aa95d1:
    // 00aa95d1  a12456ab00             -mov eax, dword ptr [0xab5624]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11228708) /* 0xab5624 */);
    // 00aa95d6  8b152856ab00           -mov edx, dword ptr [0xab5628]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11228712) /* 0xab5628 */);
    // 00aa95dc  8d4801                 -lea ecx, [eax + 1]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00aa95df  891c82                 -mov dword ptr [edx + eax*4], ebx
    app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 4) = cpu.ebx;
    // 00aa95e2  890d2456ab00           -mov dword ptr [0xab5624], ecx
    app->getMemory<x86::reg32>(x86::reg32(11228708) /* 0xab5624 */) = cpu.ecx;
L_0x00aa95e8:
    // 00aa95e8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aa95e9  2eff15e413ab00         -call dword ptr cs:[0xab13e4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11211748) /* 0xab13e4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa95f0  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00aa95f2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa95f3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa95f4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa95f5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa95f6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void sub_aa95f8(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa95f8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aa95f9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aa95fa  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aa95fb  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aa95fc  8b152056ab00           -mov edx, dword ptr [0xab5620]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11228704) /* 0xab5620 */);
    // 00aa9602  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00aa9604  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00aa9606  7e1b                   -jle 0xaa9623
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00aa9623;
    }
    // 00aa9608  bbf04fab00             -mov ebx, 0xab4ff0
    cpu.ebx = 11227120 /*0xab4ff0*/;
L_0x00aa960d:
    // 00aa960d  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aa960e  46                     -inc esi
    (cpu.esi)++;
    // 00aa960f  2eff157413ab00         -call dword ptr cs:[0xab1374]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11211636) /* 0xab1374 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa9616  8b0d2056ab00           -mov ecx, dword ptr [0xab5620]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11228704) /* 0xab5620 */);
    // 00aa961c  83c318                 -add ebx, 0x18
    (cpu.ebx) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00aa961f  39ce                   +cmp esi, ecx
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
    // 00aa9621  7cea                   -jl 0xaa960d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00aa960d;
    }
L_0x00aa9623:
    // 00aa9623  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa9624  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa9625  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa9626  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa9627  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_aa9628(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa9628  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aa9629  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aa962a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aa962b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aa962c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00aa962d  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00aa962e  8b152456ab00           -mov edx, dword ptr [0xab5624]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11228708) /* 0xab5624 */);
    // 00aa9634  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00aa9636  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00aa9638  7e2d                   -jle 0xaa9667
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00aa9667;
    }
    // 00aa963a  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x00aa963c:
    // 00aa963c  a12856ab00             -mov eax, dword ptr [0xab5628]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11228712) /* 0xab5628 */);
    // 00aa9641  8b0c03                 -mov ecx, dword ptr [ebx + eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + cpu.eax * 1);
    // 00aa9644  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aa9645  2eff157413ab00         -call dword ptr cs:[0xab1374]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11211636) /* 0xab1374 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa964c  a12856ab00             -mov eax, dword ptr [0xab5628]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11228712) /* 0xab5628 */);
    // 00aa9651  8b0403                 -mov eax, dword ptr [ebx + eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + cpu.eax * 1);
    // 00aa9654  46                     -inc esi
    (cpu.esi)++;
    // 00aa9655  e846e7ffff             -call 0xaa7da0
    cpu.esp -= 4;
    sub_aa7da0(app, cpu);
    if (cpu.terminate) return;
    // 00aa965a  8b3d2456ab00           -mov edi, dword ptr [0xab5624]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(11228708) /* 0xab5624 */);
    // 00aa9660  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00aa9663  39fe                   +cmp esi, edi
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
    // 00aa9665  7cd5                   -jl 0xaa963c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00aa963c;
    }
L_0x00aa9667:
    // 00aa9667  8b2d2856ab00           -mov ebp, dword ptr [0xab5628]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(11228712) /* 0xab5628 */);
    // 00aa966d  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00aa966f  7407                   -je 0xaa9678
    if (cpu.flags.zf)
    {
        goto L_0x00aa9678;
    }
    // 00aa9671  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00aa9673  e828e7ffff             -call 0xaa7da0
    cpu.esp -= 4;
    sub_aa7da0(app, cpu);
    if (cpu.terminate) return;
L_0x00aa9678:
    // 00aa9678  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa9679  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa967a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa967b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa967c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa967d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa967e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void sub_aa9680(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa9680  c7400800000000         -mov dword ptr [eax + 8], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 00aa9687  c7400c00000000         -mov dword ptr [eax + 0xc], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 00aa968e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void sub_aa9690(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa9690  b8c04eab00             -mov eax, 0xab4ec0
    cpu.eax = 11226816 /*0xab4ec0*/;
    // 00aa9695  e992000000             -jmp 0xaa972c
    return sub_aa972c(app, cpu);
}

/* align: skip 0x8b 0xc0 */
void sub_aa969c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa969c  b8c04eab00             -mov eax, 0xab4ec0
    cpu.eax = 11226816 /*0xab4ec0*/;
    // 00aa96a1  e9ea000000             -jmp 0xaa9790
    return sub_aa9790(app, cpu);
}

/* align: skip 0x8b 0xc0 */
void sub_aa96a8(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa96a8  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00aa96ab  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00aa96ae  05e04eab00             +add eax, 0xab4ee0
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(11226848 /*0xab4ee0*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00aa96b3  e974000000             -jmp 0xaa972c
    return sub_aa972c(app, cpu);
}

/* align: skip  */
void sub_aa96b8(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa96b8  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00aa96bb  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00aa96be  05e04eab00             +add eax, 0xab4ee0
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(11226848 /*0xab4ee0*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00aa96c3  e9c8000000             -jmp 0xaa9790
    return sub_aa9790(app, cpu);
}

/* align: skip  */
void sub_aa96c8(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa96c8  e9e71c0000             -jmp 0xaab3b4
    return sub_aab3b4(app, cpu);
}

/* align: skip 0x8d 0x40 0x00 */
void sub_aa96d0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa96d0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aa96d1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00aa96d3  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00aa96d6  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00aa96d9  05e04eab00             -add eax, 0xab4ee0
    (cpu.eax) += x86::reg32(x86::sreg32(11226848 /*0xab4ee0*/));
    // 00aa96de  e89dffffff             -call 0xaa9680
    cpu.esp -= 4;
    sub_aa9680(app, cpu);
    if (cpu.terminate) return;
    // 00aa96e3  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00aa96e5  e8221e0000             -call 0xaab50c
    cpu.esp -= 4;
    sub_aab50c(app, cpu);
    if (cpu.terminate) return;
    // 00aa96ea  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa96eb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_aa96ec(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa96ec  b8e04fab00             -mov eax, 0xab4fe0
    cpu.eax = 11227104 /*0xab4fe0*/;
    // 00aa96f1  eb39                   -jmp 0xaa972c
    return sub_aa972c(app, cpu);
}

/* align: skip 0x90 */
void sub_aa96f4(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa96f4  b8e04fab00             -mov eax, 0xab4fe0
    cpu.eax = 11227104 /*0xab4fe0*/;
    // 00aa96f9  e992000000             -jmp 0xaa9790
    return sub_aa9790(app, cpu);
}

/* align: skip 0x8b 0xc0 */
void sub_aa9700(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa9700  b8d04eab00             -mov eax, 0xab4ed0
    cpu.eax = 11226832 /*0xab4ed0*/;
    // 00aa9705  eb25                   -jmp 0xaa972c
    return sub_aa972c(app, cpu);
}

/* align: skip 0x90 */
void sub_aa9708(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa9708  b8d04eab00             -mov eax, 0xab4ed0
    cpu.eax = 11226832 /*0xab4ed0*/;
    // 00aa970d  e97e000000             -jmp 0xaa9790
    return sub_aa9790(app, cpu);
}

/* align: skip 0x8b 0xc0 */
void sub_aa9714(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa9714  b80056ab00             -mov eax, 0xab5600
    cpu.eax = 11228672 /*0xab5600*/;
    // 00aa9719  eb11                   -jmp 0xaa972c
    return sub_aa972c(app, cpu);
}

/* align: skip 0x90 */
void sub_aa971c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa971c  b80056ab00             -mov eax, 0xab5600
    cpu.eax = 11228672 /*0xab5600*/;
    // 00aa9721  eb6d                   -jmp 0xaa9790
    return sub_aa9790(app, cpu);
}

/* align: skip 0x90 */
void sub_aa9724(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa9724  b81056ab00             -mov eax, 0xab5610
    cpu.eax = 11228688 /*0xab5610*/;
    // 00aa9729  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 00aa972c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aa972d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aa972e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aa972f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aa9730  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00aa9731  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00aa9733  2eff15ac13ab00         -call dword ptr cs:[0xab13ac]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11211692) /* 0xab13ac */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa973a  8b5308                 -mov edx, dword ptr [ebx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 00aa973d  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00aa973f  39d0                   +cmp eax, edx
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
    // 00aa9741  743b                   -je 0xaa977e
    if (cpu.flags.zf)
    {
        goto L_0x00aa977e;
    }
    // 00aa9743  837b0400               +cmp dword ptr [ebx + 4], 0
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
    // 00aa9747  7528                   -jne 0xaa9771
    if (!cpu.flags.zf)
    {
        goto L_0x00aa9771;
    }
    // 00aa9749  b8f055ab00             -mov eax, 0xab55f0
    cpu.eax = 11228656 /*0xab55f0*/;
    // 00aa974e  e8d9ffffff             -call 0xaa972c
    cpu.esp -= 4;
    sub_aa972c(app, cpu);
    if (cpu.terminate) return;
    // 00aa9753  837b0400               +cmp dword ptr [ebx + 4], 0
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
    // 00aa9757  750e                   -jne 0xaa9767
    if (!cpu.flags.zf)
    {
        goto L_0x00aa9767;
    }
    // 00aa9759  e8f6fdffff             -call 0xaa9554
    cpu.esp -= 4;
    sub_aa9554(app, cpu);
    if (cpu.terminate) return;
    // 00aa975e  c7430401000000         -mov dword ptr [ebx + 4], 1
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = 1 /*0x1*/;
    // 00aa9765  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
L_0x00aa9767:
    // 00aa9767  b8f055ab00             -mov eax, 0xab55f0
    cpu.eax = 11228656 /*0xab55f0*/;
    // 00aa976c  e81f000000             -call 0xaa9790
    cpu.esp -= 4;
    sub_aa9790(app, cpu);
    if (cpu.terminate) return;
L_0x00aa9771:
    // 00aa9771  8b2b                   -mov ebp, dword ptr [ebx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx);
    // 00aa9773  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00aa9774  2eff157c13ab00         -call dword ptr cs:[0xab137c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11211644) /* 0xab137c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa977b  897308                 -mov dword ptr [ebx + 8], esi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.esi;
L_0x00aa977e:
    // 00aa977e  ff430c                 -inc dword ptr [ebx + 0xc]
    (app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */))++;
    // 00aa9781  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa9782  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa9783  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa9784  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa9785  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa9786  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_aa972c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00aa972c;
    // 00aa9724  b81056ab00             -mov eax, 0xab5610
    cpu.eax = 11228688 /*0xab5610*/;
    // 00aa9729  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_entry_0x00aa972c:
    // 00aa972c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aa972d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aa972e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aa972f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aa9730  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00aa9731  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00aa9733  2eff15ac13ab00         -call dword ptr cs:[0xab13ac]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11211692) /* 0xab13ac */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa973a  8b5308                 -mov edx, dword ptr [ebx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 00aa973d  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00aa973f  39d0                   +cmp eax, edx
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
    // 00aa9741  743b                   -je 0xaa977e
    if (cpu.flags.zf)
    {
        goto L_0x00aa977e;
    }
    // 00aa9743  837b0400               +cmp dword ptr [ebx + 4], 0
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
    // 00aa9747  7528                   -jne 0xaa9771
    if (!cpu.flags.zf)
    {
        goto L_0x00aa9771;
    }
    // 00aa9749  b8f055ab00             -mov eax, 0xab55f0
    cpu.eax = 11228656 /*0xab55f0*/;
    // 00aa974e  e8d9ffffff             -call 0xaa972c
    cpu.esp -= 4;
    sub_aa972c(app, cpu);
    if (cpu.terminate) return;
    // 00aa9753  837b0400               +cmp dword ptr [ebx + 4], 0
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
    // 00aa9757  750e                   -jne 0xaa9767
    if (!cpu.flags.zf)
    {
        goto L_0x00aa9767;
    }
    // 00aa9759  e8f6fdffff             -call 0xaa9554
    cpu.esp -= 4;
    sub_aa9554(app, cpu);
    if (cpu.terminate) return;
    // 00aa975e  c7430401000000         -mov dword ptr [ebx + 4], 1
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = 1 /*0x1*/;
    // 00aa9765  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
L_0x00aa9767:
    // 00aa9767  b8f055ab00             -mov eax, 0xab55f0
    cpu.eax = 11228656 /*0xab55f0*/;
    // 00aa976c  e81f000000             -call 0xaa9790
    cpu.esp -= 4;
    sub_aa9790(app, cpu);
    if (cpu.terminate) return;
L_0x00aa9771:
    // 00aa9771  8b2b                   -mov ebp, dword ptr [ebx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx);
    // 00aa9773  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00aa9774  2eff157c13ab00         -call dword ptr cs:[0xab137c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11211644) /* 0xab137c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa977b  897308                 -mov dword ptr [ebx + 8], esi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.esi;
L_0x00aa977e:
    // 00aa977e  ff430c                 -inc dword ptr [ebx + 0xc]
    (app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */))++;
    // 00aa9781  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa9782  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa9783  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa9784  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa9785  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa9786  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void sub_aa9788(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa9788  b81056ab00             -mov eax, 0xab5610
    cpu.eax = 11228688 /*0xab5610*/;
    // 00aa978d  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 00aa9790  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aa9791  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aa9792  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aa9793  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aa9794  8b500c                 -mov edx, dword ptr [eax + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00aa9797  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00aa9799  7617                   -jbe 0xaa97b2
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00aa97b2;
    }
    // 00aa979b  8d5aff                 -lea ebx, [edx - 1]
    cpu.ebx = x86::reg32(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 00aa979e  89580c                 -mov dword ptr [eax + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 00aa97a1  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00aa97a3  750d                   -jne 0xaa97b2
    if (!cpu.flags.zf)
    {
        goto L_0x00aa97b2;
    }
    // 00aa97a5  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax);
    // 00aa97a7  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aa97a8  895808                 -mov dword ptr [eax + 8], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 00aa97ab  2eff15e813ab00         -call dword ptr cs:[0xab13e8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11211752) /* 0xab13e8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00aa97b2:
    // 00aa97b2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa97b3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa97b4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa97b5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa97b6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_aa9790(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00aa9790;
    // 00aa9788  b81056ab00             -mov eax, 0xab5610
    cpu.eax = 11228688 /*0xab5610*/;
    // 00aa978d  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_entry_0x00aa9790:
    // 00aa9790  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aa9791  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aa9792  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aa9793  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aa9794  8b500c                 -mov edx, dword ptr [eax + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00aa9797  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00aa9799  7617                   -jbe 0xaa97b2
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00aa97b2;
    }
    // 00aa979b  8d5aff                 -lea ebx, [edx - 1]
    cpu.ebx = x86::reg32(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 00aa979e  89580c                 -mov dword ptr [eax + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 00aa97a1  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00aa97a3  750d                   -jne 0xaa97b2
    if (!cpu.flags.zf)
    {
        goto L_0x00aa97b2;
    }
    // 00aa97a5  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax);
    // 00aa97a7  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aa97a8  895808                 -mov dword ptr [eax + 8], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 00aa97ab  2eff15e813ab00         -call dword ptr cs:[0xab13e8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11211752) /* 0xab13e8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00aa97b2:
    // 00aa97b2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa97b3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa97b4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa97b5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa97b6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void sub_aa97b8(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa97b8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aa97b9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aa97ba  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aa97bb  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aa97bc  2eff15c413ab00         -call dword ptr cs:[0xab13c4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11211716) /* 0xab13c4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa97c3  8b15a436ab00           -mov edx, dword ptr [0xab36a4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11220644) /* 0xab36a4 */);
    // 00aa97c9  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aa97ca  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00aa97cc  2eff152014ab00         -call dword ptr cs:[0xab1420]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11211808) /* 0xab1420 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa97d3  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00aa97d5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aa97d7  7507                   -jne 0xaa97e0
    if (!cpu.flags.zf)
    {
        goto L_0x00aa97e0;
    }
    // 00aa97d9  e892290000             -call 0xaac170
    cpu.esp -= 4;
    sub_aac170(app, cpu);
    if (cpu.terminate) return;
    // 00aa97de  eb0b                   -jmp 0xaa97eb
    goto L_0x00aa97eb;
L_0x00aa97e0:
    // 00aa97e0  80785300               +cmp byte ptr [eax + 0x53], 0
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
    // 00aa97e4  7407                   -je 0xaa97ed
    if (cpu.flags.zf)
    {
        goto L_0x00aa97ed;
    }
    // 00aa97e6  e8c1290000             -call 0xaac1ac
    cpu.esp -= 4;
    sub_aac1ac(app, cpu);
    if (cpu.terminate) return;
L_0x00aa97eb:
    // 00aa97eb  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x00aa97ed:
    // 00aa97ed  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aa97ee  2eff150c14ab00         -call dword ptr cs:[0xab140c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11211788) /* 0xab140c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa97f5  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00aa97f7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa97f8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa97f9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa97fa  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa97fb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_aa97fc(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa97fc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aa97fd  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aa97fe  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00aa9800  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aa9802  7526                   -jne 0xaa982a
    if (!cpu.flags.zf)
    {
        goto L_0x00aa982a;
    }
    // 00aa9804  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00aa9809  8b154c38ab00           -mov edx, dword ptr [0xab384c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11221068) /* 0xab384c */);
    // 00aa980f  e8bc280000             -call 0xaac0d0
    cpu.esp -= 4;
    sub_aac0d0(app, cpu);
    if (cpu.terminate) return;
    // 00aa9814  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00aa9816  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aa9818  7410                   -je 0xaa982a
    if (cpu.flags.zf)
    {
        goto L_0x00aa982a;
    }
    // 00aa981a  8b1d4c38ab00           -mov ebx, dword ptr [0xab384c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(11221068) /* 0xab384c */);
    // 00aa9820  c6405201               -mov byte ptr [eax + 0x52], 1
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(82) /* 0x52 */) = 1 /*0x1*/;
    // 00aa9824  8998f0000000           -mov dword ptr [eax + 0xf0], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(240) /* 0xf0 */) = cpu.ebx;
L_0x00aa982a:
    // 00aa982a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00aa982c  e88f2b0000             -call 0xaac3c0
    cpu.esp -= 4;
    sub_aac3c0(app, cpu);
    if (cpu.terminate) return;
    // 00aa9831  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00aa9833  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa9834  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa9835  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void sub_aa9838(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa9838  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aa9839  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aa983a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aa983b  8b1da436ab00           -mov ebx, dword ptr [0xab36a4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(11220644) /* 0xab36a4 */);
    // 00aa9841  83fbff                 +cmp ebx, -1
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
    // 00aa9844  753b                   -jne 0xaa9881
    if (!cpu.flags.zf)
    {
        goto L_0x00aa9881;
    }
    // 00aa9846  2eff151814ab00         -call dword ptr cs:[0xab1418]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11211800) /* 0xab1418 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa984d  668b158537ab00         -mov dx, word ptr [0xab3785]
    cpu.dx = app->getMemory<x86::reg16>(x86::reg32(11220869) /* 0xab3785 */);
    // 00aa9854  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00aa9856  6681fa0080             +cmp dx, 0x8000
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
    // 00aa985b  7224                   -jb 0xaa9881
    if (cpu.flags.cf)
    {
        goto L_0x00aa9881;
    }
    // 00aa985d  803d8337ab0004         +cmp byte ptr [0xab3783], 4
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(11220867) /* 0xab3783 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(4 /*0x4*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00aa9864  731b                   -jae 0xaa9881
    if (!cpu.flags.cf)
    {
        goto L_0x00aa9881;
    }
L_0x00aa9866:
    // 00aa9866  83fbff                 +cmp ebx, -1
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
    // 00aa9869  7416                   -je 0xaa9881
    if (cpu.flags.zf)
    {
        goto L_0x00aa9881;
    }
    // 00aa986b  83fb02                 +cmp ebx, 2
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
    // 00aa986e  7711                   -ja 0xaa9881
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00aa9881;
    }
    // 00aa9870  891da436ab00           -mov dword ptr [0xab36a4], ebx
    app->getMemory<x86::reg32>(x86::reg32(11220644) /* 0xab36a4 */) = cpu.ebx;
    // 00aa9876  2eff151814ab00         -call dword ptr cs:[0xab1418]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11211800) /* 0xab1418 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa987d  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00aa987f  ebe5                   -jmp 0xaa9866
    goto L_0x00aa9866;
L_0x00aa9881:
    // 00aa9881  83fbff                 +cmp ebx, -1
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
    // 00aa9884  0f95c0                 -setne al
    cpu.al = !cpu.flags.zf;
    // 00aa9887  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00aa988c  891da436ab00           -mov dword ptr [0xab36a4], ebx
    app->getMemory<x86::reg32>(x86::reg32(11220644) /* 0xab36a4 */) = cpu.ebx;
    // 00aa9892  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa9893  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa9894  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa9895  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void sub_aa9898(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa9898  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aa9899  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aa989a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aa989b  833da436ab00ff         +cmp dword ptr [0xab36a4], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(11220644) /* 0xab36a4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00aa98a2  7506                   -jne 0xaa98aa
    if (!cpu.flags.zf)
    {
        goto L_0x00aa98aa;
    }
    // 00aa98a4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00aa98a6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa98a7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa98a8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa98a9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00aa98aa:
    // 00aa98aa  e84dffffff             -call 0xaa97fc
    cpu.esp -= 4;
    sub_aa97fc(app, cpu);
    if (cpu.terminate) return;
    // 00aa98af  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00aa98b1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aa98b3  7432                   -je 0xaa98e7
    if (cpu.flags.zf)
    {
        goto L_0x00aa98e7;
    }
    // 00aa98b5  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00aa98b7  8b80da000000           -mov eax, dword ptr [eax + 0xda]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(218) /* 0xda */);
    // 00aa98bd  e8be290000             -call 0xaac280
    cpu.esp -= 4;
    sub_aac280(app, cpu);
    if (cpu.terminate) return;
    // 00aa98c2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aa98c4  750d                   -jne 0xaa98d3
    if (!cpu.flags.zf)
    {
        goto L_0x00aa98d3;
    }
    // 00aa98c6  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00aa98c8  e8d3e4ffff             -call 0xaa7da0
    cpu.esp -= 4;
    sub_aa7da0(app, cpu);
    if (cpu.terminate) return;
    // 00aa98cd  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00aa98cf  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa98d0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa98d1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa98d2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00aa98d3:
    // 00aa98d3  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aa98d4  8b1da436ab00           -mov ebx, dword ptr [0xab36a4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(11220644) /* 0xab36a4 */);
    // 00aa98da  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aa98db  2eff152414ab00         -call dword ptr cs:[0xab1424]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11211812) /* 0xab1424 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa98e2  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x00aa98e7:
    // 00aa98e7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa98e8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa98e9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa98ea  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void sub_aa98ec(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa98ec  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aa98ed  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aa98ee  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aa98ef  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aa98f0  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00aa98f1  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00aa98f3  8b15a436ab00           -mov edx, dword ptr [0xab36a4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11220644) /* 0xab36a4 */);
    // 00aa98f9  83faff                 +cmp edx, -1
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
    // 00aa98fc  743d                   -je 0xaa993b
    if (cpu.flags.zf)
    {
        goto L_0x00aa993b;
    }
    // 00aa98fe  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aa98ff  2eff152014ab00         -call dword ptr cs:[0xab1420]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11211808) /* 0xab1420 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa9906  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aa9908  7431                   -je 0xaa993b
    if (cpu.flags.zf)
    {
        goto L_0x00aa993b;
    }
    // 00aa990a  8bb0de000000           -mov esi, dword ptr [eax + 0xde]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(222) /* 0xde */);
    // 00aa9910  8b80da000000           -mov eax, dword ptr [eax + 0xda]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(218) /* 0xda */);
    // 00aa9916  e8c9290000             -call 0xaac2e4
    cpu.esp -= 4;
    sub_aac2e4(app, cpu);
    if (cpu.terminate) return;
    // 00aa991b  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00aa991d  8b3da436ab00           -mov edi, dword ptr [0xab36a4]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(11220644) /* 0xab36a4 */);
    // 00aa9923  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00aa9924  2eff152414ab00         -call dword ptr cs:[0xab1424]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11211812) /* 0xab1424 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa992b  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00aa992d  740c                   -je 0xaa993b
    if (cpu.flags.zf)
    {
        goto L_0x00aa993b;
    }
    // 00aa992f  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00aa9931  7408                   -je 0xaa993b
    if (cpu.flags.zf)
    {
        goto L_0x00aa993b;
    }
    // 00aa9933  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aa9934  2eff156413ab00         -call dword ptr cs:[0xab1364]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11211620) /* 0xab1364 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00aa993b:
    // 00aa993b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa993c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa993d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa993e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa993f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa9940  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_aa9944(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa9944  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00aa9949  e89effffff             -call 0xaa98ec
    cpu.esp -= 4;
    sub_aa98ec(app, cpu);
    if (cpu.terminate) return;
    // 00aa994e  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
    // 00aa9950  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aa9951  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aa9952  8b15a436ab00           -mov edx, dword ptr [0xab36a4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11220644) /* 0xab36a4 */);
    // 00aa9958  83faff                 +cmp edx, -1
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
    // 00aa995b  7412                   -je 0xaa996f
    if (cpu.flags.zf)
    {
        goto L_0x00aa996f;
    }
    // 00aa995d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aa995e  2eff151c14ab00         -call dword ptr cs:[0xab141c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11211804) /* 0xab141c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa9965  c705a436ab00ffffffff   -mov dword ptr [0xab36a4], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(11220644) /* 0xab36a4 */) = 4294967295 /*0xffffffff*/;
L_0x00aa996f:
    // 00aa996f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa9970  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa9971  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_aa9950(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00aa9950;
    // 00aa9944  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00aa9949  e89effffff             -call 0xaa98ec
    cpu.esp -= 4;
    sub_aa98ec(app, cpu);
    if (cpu.terminate) return;
    // 00aa994e  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_entry_0x00aa9950:
    // 00aa9950  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aa9951  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aa9952  8b15a436ab00           -mov edx, dword ptr [0xab36a4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11220644) /* 0xab36a4 */);
    // 00aa9958  83faff                 +cmp edx, -1
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
    // 00aa995b  7412                   -je 0xaa996f
    if (cpu.flags.zf)
    {
        goto L_0x00aa996f;
    }
    // 00aa995d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aa995e  2eff151c14ab00         -call dword ptr cs:[0xab141c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11211804) /* 0xab141c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa9965  c705a436ab00ffffffff   -mov dword ptr [0xab36a4], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(11220644) /* 0xab36a4 */) = 4294967295 /*0xffffffff*/;
L_0x00aa996f:
    // 00aa996f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa9970  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa9971  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void sub_aa9974(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa9974  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aa9975  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aa9976  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aa9977  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aa9978  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00aa9979  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00aa997a  baa896aa00             -mov edx, 0xaa96a8
    cpu.edx = 11179688 /*0xaa96a8*/;
    // 00aa997f  bbb896aa00             -mov ebx, 0xaa96b8
    cpu.ebx = 11179704 /*0xaa96b8*/;
    // 00aa9984  b9c896aa00             -mov ecx, 0xaa96c8
    cpu.ecx = 11179720 /*0xaa96c8*/;
    // 00aa9989  bed096aa00             -mov esi, 0xaa96d0
    cpu.esi = 11179728 /*0xaa96d0*/;
    // 00aa998e  bf9096aa00             -mov edi, 0xaa9690
    cpu.edi = 11179664 /*0xaa9690*/;
    // 00aa9993  bd9c96aa00             -mov ebp, 0xaa969c
    cpu.ebp = 11179676 /*0xaa969c*/;
    // 00aa9998  b81497aa00             -mov eax, 0xaa9714
    cpu.eax = 11179796 /*0xaa9714*/;
    // 00aa999d  8915ac36ab00           -mov dword ptr [0xab36ac], edx
    app->getMemory<x86::reg32>(x86::reg32(11220652) /* 0xab36ac */) = cpu.edx;
    // 00aa99a3  891db036ab00           -mov dword ptr [0xab36b0], ebx
    app->getMemory<x86::reg32>(x86::reg32(11220656) /* 0xab36b0 */) = cpu.ebx;
    // 00aa99a9  890db436ab00           -mov dword ptr [0xab36b4], ecx
    app->getMemory<x86::reg32>(x86::reg32(11220660) /* 0xab36b4 */) = cpu.ecx;
    // 00aa99af  8935b836ab00           -mov dword ptr [0xab36b8], esi
    app->getMemory<x86::reg32>(x86::reg32(11220664) /* 0xab36b8 */) = cpu.esi;
    // 00aa99b5  893dbc36ab00           -mov dword ptr [0xab36bc], edi
    app->getMemory<x86::reg32>(x86::reg32(11220668) /* 0xab36bc */) = cpu.edi;
    // 00aa99bb  892dc036ab00           -mov dword ptr [0xab36c0], ebp
    app->getMemory<x86::reg32>(x86::reg32(11220672) /* 0xab36c0 */) = cpu.ebp;
    // 00aa99c1  a3d436ab00             -mov dword ptr [0xab36d4], eax
    app->getMemory<x86::reg32>(x86::reg32(11220692) /* 0xab36d4 */) = cpu.eax;
    // 00aa99c6  ba1c97aa00             -mov edx, 0xaa971c
    cpu.edx = 11179804 /*0xaa971c*/;
    // 00aa99cb  bb2c97aa00             -mov ebx, 0xaa972c
    cpu.ebx = 11179820 /*0xaa972c*/;
    // 00aa99d0  b99097aa00             -mov ecx, 0xaa9790
    cpu.ecx = 11179920 /*0xaa9790*/;
    // 00aa99d5  be8096aa00             -mov esi, 0xaa9680
    cpu.esi = 11179648 /*0xaa9680*/;
    // 00aa99da  bfec96aa00             -mov edi, 0xaa96ec
    cpu.edi = 11179756 /*0xaa96ec*/;
    // 00aa99df  bd0097aa00             -mov ebp, 0xaa9700
    cpu.ebp = 11179776 /*0xaa9700*/;
    // 00aa99e4  b8f496aa00             -mov eax, 0xaa96f4
    cpu.eax = 11179764 /*0xaa96f4*/;
    // 00aa99e9  8915d836ab00           -mov dword ptr [0xab36d8], edx
    app->getMemory<x86::reg32>(x86::reg32(11220696) /* 0xab36d8 */) = cpu.edx;
    // 00aa99ef  891d9c37ab00           -mov dword ptr [0xab379c], ebx
    app->getMemory<x86::reg32>(x86::reg32(11220892) /* 0xab379c */) = cpu.ebx;
    // 00aa99f5  890da037ab00           -mov dword ptr [0xab37a0], ecx
    app->getMemory<x86::reg32>(x86::reg32(11220896) /* 0xab37a0 */) = cpu.ecx;
    // 00aa99fb  8935a437ab00           -mov dword ptr [0xab37a4], esi
    app->getMemory<x86::reg32>(x86::reg32(11220900) /* 0xab37a4 */) = cpu.esi;
    // 00aa9a01  893dc436ab00           -mov dword ptr [0xab36c4], edi
    app->getMemory<x86::reg32>(x86::reg32(11220676) /* 0xab36c4 */) = cpu.edi;
    // 00aa9a07  892dc836ab00           -mov dword ptr [0xab36c8], ebp
    app->getMemory<x86::reg32>(x86::reg32(11220680) /* 0xab36c8 */) = cpu.ebp;
    // 00aa9a0d  a3cc36ab00             -mov dword ptr [0xab36cc], eax
    app->getMemory<x86::reg32>(x86::reg32(11220684) /* 0xab36cc */) = cpu.eax;
    // 00aa9a12  ba0897aa00             -mov edx, 0xaa9708
    cpu.edx = 11179784 /*0xaa9708*/;
    // 00aa9a17  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00aa9a1c  b92497aa00             -mov ecx, 0xaa9724
    cpu.ecx = 11179812 /*0xaa9724*/;
    // 00aa9a21  be8897aa00             -mov esi, 0xaa9788
    cpu.esi = 11179912 /*0xaa9788*/;
    // 00aa9a26  bf4499aa00             -mov edi, 0xaa9944
    cpu.edi = 11180356 /*0xaa9944*/;
    // 00aa9a2b  8915d036ab00           -mov dword ptr [0xab36d0], edx
    app->getMemory<x86::reg32>(x86::reg32(11220688) /* 0xab36d0 */) = cpu.edx;
    // 00aa9a31  e81efbffff             -call 0xaa9554
    cpu.esp -= 4;
    sub_aa9554(app, cpu);
    if (cpu.terminate) return;
    // 00aa9a36  8b157c48ab00           -mov edx, dword ptr [0xab487c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11225212) /* 0xab487c */);
    // 00aa9a3c  a3f055ab00             -mov dword ptr [0xab55f0], eax
    app->getMemory<x86::reg32>(x86::reg32(11228656) /* 0xab55f0 */) = cpu.eax;
    // 00aa9a41  891df455ab00           -mov dword ptr [0xab55f4], ebx
    app->getMemory<x86::reg32>(x86::reg32(11228660) /* 0xab55f4 */) = cpu.ebx;
    // 00aa9a47  890ddc36ab00           -mov dword ptr [0xab36dc], ecx
    app->getMemory<x86::reg32>(x86::reg32(11220700) /* 0xab36dc */) = cpu.ecx;
    // 00aa9a4d  8935e036ab00           -mov dword ptr [0xab36e0], esi
    app->getMemory<x86::reg32>(x86::reg32(11220704) /* 0xab36e0 */) = cpu.esi;
    // 00aa9a53  8b82da000000           -mov eax, dword ptr [edx + 0xda]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(218) /* 0xda */);
    // 00aa9a59  893de436ab00           -mov dword ptr [0xab36e4], edi
    app->getMemory<x86::reg32>(x86::reg32(11220708) /* 0xab36e4 */) = cpu.edi;
    // 00aa9a5f  e81c280000             -call 0xaac280
    cpu.esp -= 4;
    sub_aac280(app, cpu);
    if (cpu.terminate) return;
    // 00aa9a64  8b2d7c48ab00           -mov ebp, dword ptr [0xab487c]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(11225212) /* 0xab487c */);
    // 00aa9a6a  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00aa9a6b  a1a436ab00             -mov eax, dword ptr [0xab36a4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11220644) /* 0xab36a4 */);
    // 00aa9a70  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00aa9a71  2eff152414ab00         -call dword ptr cs:[0xab1424]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11211812) /* 0xab1424 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa9a78  c705a836ab00b897aa00   -mov dword ptr [0xab36a8], 0xaa97b8
    app->getMemory<x86::reg32>(x86::reg32(11220648) /* 0xab36a8 */) = 11179960 /*0xaa97b8*/;
    // 00aa9a82  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa9a83  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa9a84  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa9a85  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa9a86  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa9a87  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa9a88  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_aa9a8c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa9a8c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aa9a8d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aa9a8e  b8c04eab00             -mov eax, 0xab4ec0
    cpu.eax = 11226816 /*0xab4ec0*/;
    // 00aa9a93  bae04eab00             -mov edx, 0xab4ee0
    cpu.edx = 11226848 /*0xab4ee0*/;
    // 00aa9a98  ff15a437ab00           -call dword ptr [0xab37a4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11220900) /* 0xab37a4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa9a9e  8d9a00010000           -lea ebx, [edx + 0x100]
    cpu.ebx = x86::reg32(cpu.edx + x86::reg32(256) /* 0x100 */);
L_0x00aa9aa4:
    // 00aa9aa4  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00aa9aa6  83c210                 -add edx, 0x10
    (cpu.edx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00aa9aa9  ff15a437ab00           -call dword ptr [0xab37a4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11220900) /* 0xab37a4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa9aaf  39da                   +cmp edx, ebx
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
    // 00aa9ab1  75f1                   -jne 0xaa9aa4
    if (!cpu.flags.zf)
    {
        goto L_0x00aa9aa4;
    }
    // 00aa9ab3  b81056ab00             -mov eax, 0xab5610
    cpu.eax = 11228688 /*0xab5610*/;
    // 00aa9ab8  ff15a437ab00           -call dword ptr [0xab37a4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11220900) /* 0xab37a4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa9abe  e865fbffff             -call 0xaa9628
    cpu.esp -= 4;
    sub_aa9628(app, cpu);
    if (cpu.terminate) return;
    // 00aa9ac3  e828290000             -call 0xaac3f0
    cpu.esp -= 4;
    sub_aac3f0(app, cpu);
    if (cpu.terminate) return;
    // 00aa9ac8  e8a3230000             -call 0xaabe70
    cpu.esp -= 4;
    sub_aabe70(app, cpu);
    if (cpu.terminate) return;
    // 00aa9acd  b8e04fab00             -mov eax, 0xab4fe0
    cpu.eax = 11227104 /*0xab4fe0*/;
    // 00aa9ad2  ff15a437ab00           -call dword ptr [0xab37a4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11220900) /* 0xab37a4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa9ad8  b8d04eab00             -mov eax, 0xab4ed0
    cpu.eax = 11226832 /*0xab4ed0*/;
    // 00aa9add  ff15a437ab00           -call dword ptr [0xab37a4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11220900) /* 0xab37a4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa9ae3  b80056ab00             -mov eax, 0xab5600
    cpu.eax = 11228672 /*0xab5600*/;
    // 00aa9ae8  ff15a437ab00           -call dword ptr [0xab37a4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11220900) /* 0xab37a4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa9aee  b8f055ab00             -mov eax, 0xab55f0
    cpu.eax = 11228656 /*0xab55f0*/;
    // 00aa9af3  ff15a437ab00           -call dword ptr [0xab37a4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11220900) /* 0xab37a4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa9af9  e8fafaffff             -call 0xaa95f8
    cpu.esp -= 4;
    sub_aa95f8(app, cpu);
    if (cpu.terminate) return;
    // 00aa9afe  e84dfeffff             -call 0xaa9950
    cpu.esp -= 4;
    sub_aa9950(app, cpu);
    if (cpu.terminate) return;
    // 00aa9b03  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa9b04  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa9b05  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_aa9b10(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa9b10  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aa9b11  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aa9b12  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aa9b13  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aa9b14  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00aa9b15  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00aa9b17  6804010000             -push 0x104
    app->getMemory<x86::reg32>(cpu.esp-4) = 260 /*0x104*/;
    cpu.esp -= 4;
    // 00aa9b1c  681858ab00             -push 0xab5818
    app->getMemory<x86::reg32>(cpu.esp-4) = 11229208 /*0xab5818*/;
    cpu.esp -= 4;
    // 00aa9b21  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00aa9b23  2eff15c813ab00         -call dword ptr cs:[0xab13c8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11211720) /* 0xab13c8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa9b2a  6804010000             -push 0x104
    app->getMemory<x86::reg32>(cpu.esp-4) = 260 /*0x104*/;
    cpu.esp -= 4;
    // 00aa9b2f  681c59ab00             -push 0xab591c
    app->getMemory<x86::reg32>(cpu.esp-4) = 11229468 /*0xab591c*/;
    cpu.esp -= 4;
    // 00aa9b34  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aa9b35  be7427ab00             -mov esi, 0xab2774
    cpu.esi = 11216756 /*0xab2774*/;
    // 00aa9b3a  2eff15c813ab00         -call dword ptr cs:[0xab13c8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11211720) /* 0xab13c8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa9b41  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 00aa9b43  bf3056ab00             -mov edi, 0xab5630
    cpu.edi = 11228720 /*0xab5630*/;
    // 00aa9b48  88253056ab00           -mov byte ptr [0xab5630], ah
    app->getMemory<x86::reg8>(x86::reg32(11228720) /* 0xab5630 */) = cpu.ah;
    // 00aa9b4e  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00aa9b4f  1e                     -push ds
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.ds;
    cpu.esp -= 4;
    // 00aa9b50  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00aa9b51  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00aa9b52  2bc9                   +sub ecx, ecx
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
    // 00aa9b54  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00aa9b55  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 00aa9b57  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00aa9b59  4f                     -dec edi
    (cpu.edi)--;
L_0x00aa9b5a:
    // 00aa9b5a  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00aa9b5c  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00aa9b5e  3c00                   +cmp al, 0
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
    // 00aa9b60  7410                   -je 0xaa9b72
    if (cpu.flags.zf)
    {
        goto L_0x00aa9b72;
    }
    // 00aa9b62  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00aa9b65  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00aa9b68  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00aa9b6b  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00aa9b6e  3c00                   +cmp al, 0
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
    // 00aa9b70  75e8                   -jne 0xaa9b5a
    if (!cpu.flags.zf)
    {
        goto L_0x00aa9b5a;
    }
L_0x00aa9b72:
    // 00aa9b72  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa9b73  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00aa9b74  be1858ab00             -mov esi, 0xab5818
    cpu.esi = 11229208 /*0xab5818*/;
    // 00aa9b79  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00aa9b7a  1e                     -push ds
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.ds;
    cpu.esp -= 4;
    // 00aa9b7b  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00aa9b7c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00aa9b7d  2bc9                   +sub ecx, ecx
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
    // 00aa9b7f  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00aa9b80  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 00aa9b82  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00aa9b84  4f                     -dec edi
    (cpu.edi)--;
L_0x00aa9b85:
    // 00aa9b85  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00aa9b87  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00aa9b89  3c00                   +cmp al, 0
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
    // 00aa9b8b  7410                   -je 0xaa9b9d
    if (cpu.flags.zf)
    {
        goto L_0x00aa9b9d;
    }
    // 00aa9b8d  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00aa9b90  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00aa9b93  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00aa9b96  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00aa9b99  3c00                   +cmp al, 0
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
    // 00aa9b9b  75e8                   -jne 0xaa9b85
    if (!cpu.flags.zf)
    {
        goto L_0x00aa9b85;
    }
L_0x00aa9b9d:
    // 00aa9b9d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa9b9e  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00aa9b9f  bea827ab00             -mov esi, 0xab27a8
    cpu.esi = 11216808 /*0xab27a8*/;
    // 00aa9ba4  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00aa9ba5  1e                     -push ds
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.ds;
    cpu.esp -= 4;
    // 00aa9ba6  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00aa9ba7  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00aa9ba8  2bc9                   +sub ecx, ecx
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
    // 00aa9baa  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00aa9bab  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 00aa9bad  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00aa9baf  4f                     -dec edi
    (cpu.edi)--;
L_0x00aa9bb0:
    // 00aa9bb0  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00aa9bb2  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00aa9bb4  3c00                   +cmp al, 0
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
    // 00aa9bb6  7410                   -je 0xaa9bc8
    if (cpu.flags.zf)
    {
        goto L_0x00aa9bc8;
    }
    // 00aa9bb8  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00aa9bbb  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00aa9bbe  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00aa9bc1  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00aa9bc4  3c00                   +cmp al, 0
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
    // 00aa9bc6  75e8                   -jne 0xaa9bb0
    if (!cpu.flags.zf)
    {
        goto L_0x00aa9bb0;
    }
L_0x00aa9bc8:
    // 00aa9bc8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa9bc9  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00aa9bca  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00aa9bcc  681c59ab00             -push 0xab591c
    app->getMemory<x86::reg32>(cpu.esp-4) = 11229468 /*0xab591c*/;
    cpu.esp -= 4;
    // 00aa9bd1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00aa9bd2  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00aa9bd4  2eff155413ab00         -call dword ptr cs:[0xab1354]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11211604) /* 0xab1354 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa9bdb  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00aa9be0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa9be1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa9be2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa9be3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa9be4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa9be5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_aa9bf0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa9bf0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_aa9c00(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa9c00  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aa9c01  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aa9c02  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aa9c03  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00aa9c06  c7442408000000c0       -mov dword ptr [esp + 8], 0xc0000000
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = 3221225472 /*0xc0000000*/;
    // 00aa9c0e  c744240c7e015041       -mov dword ptr [esp + 0xc], 0x4150017e
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = 1095762302 /*0x4150017e*/;
    // 00aa9c16  c7042400000080         -mov dword ptr [esp], 0x80000000
    app->getMemory<x86::reg32>(cpu.esp) = 2147483648 /*0x80000000*/;
    // 00aa9c1d  c7442404ffff4741       -mov dword ptr [esp + 4], 0x4147ffff
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = 1095237631 /*0x4147ffff*/;
    // 00aa9c25  803d8d36ab0003         +cmp byte ptr [0xab368d], 3
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(11220621) /* 0xab368d */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(3 /*0x3*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00aa9c2c  7249                   -jb 0xaa9c77
    if (cpu.flags.cf)
    {
        goto L_0x00aa9c77;
    }
    // 00aa9c2e  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00aa9c32  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00aa9c36  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 00aa9c39  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00aa9c3d  e8b4270000             -call 0xaac3f6
    cpu.esp -= 4;
    sub_aac3f6(app, cpu);
    if (cpu.terminate) return;
    // 00aa9c42  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 00aa9c45  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00aa9c49  e86b2b0000             -call 0xaac7b9
    cpu.esp -= 4;
    sub_aac7b9(app, cpu);
    if (cpu.terminate) return;
    // 00aa9c4e  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00aa9c50  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00aa9c52  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00aa9c56  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00aa9c5a  e89d290000             -call 0xaac5fc
    cpu.esp -= 4;
    sub_aac5fc(app, cpu);
    if (cpu.terminate) return;
    // 00aa9c5f  bb3a8c30e2             -mov ebx, 0xe2308c3a
    cpu.ebx = 3794832442 /*0xe2308c3a*/;
    // 00aa9c64  b98e79453e             -mov ecx, 0x3e45798e
    cpu.ecx = 1044740494 /*0x3e45798e*/;
    // 00aa9c69  e8e82c0000             -call 0xaac956
    cpu.esp -= 4;
    sub_aac956(app, cpu);
    if (cpu.terminate) return;
    // 00aa9c6e  7e07                   -jle 0xaa9c77
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00aa9c77;
    }
    // 00aa9c70  800d9036ab0001         -or byte ptr [0xab3690], 1
    app->getMemory<x86::reg8>(x86::reg32(11220624) /* 0xab3690 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x00aa9c77:
    // 00aa9c77  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00aa9c7a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa9c7b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa9c7c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa9c7d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_aa9c7e(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa9c7e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aa9c7f  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00aa9c81  e802000000             -call 0xaa9c88
    cpu.esp -= 4;
    sub_aa9c88(app, cpu);
    if (cpu.terminate) return;
    // 00aa9c86  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa9c87  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_aa9c88(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa9c88  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00aa9c89  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00aa9c8b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aa9c8c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aa9c8d  83ec20                 -sub esp, 0x20
    (cpu.esp) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00aa9c90  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00aa9c92  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 00aa9c94  8945e0                 -mov dword ptr [ebp - 0x20], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.eax;
    // 00aa9c97  8b4204                 -mov eax, dword ptr [edx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00aa9c9a  8945e4                 -mov dword ptr [ebp - 0x1c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.eax;
    // 00aa9c9d  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 00aa9c9f  8945e8                 -mov dword ptr [ebp - 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.eax;
    // 00aa9ca2  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 00aa9ca5  8945ec                 -mov dword ptr [ebp - 0x14], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.eax;
    // 00aa9ca8  f6c140                 +test cl, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 64 /*0x40*/));
    // 00aa9cab  7407                   -je 0xaa9cb4
    if (cpu.flags.zf)
    {
        goto L_0x00aa9cb4;
    }
    // 00aa9cad  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 00aa9cb2  eb3a                   -jmp 0xaa9cee
    goto L_0x00aa9cee;
L_0x00aa9cb4:
    // 00aa9cb4  f6c180                 +test cl, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 128 /*0x80*/));
    // 00aa9cb7  7407                   -je 0xaa9cc0
    if (cpu.flags.zf)
    {
        goto L_0x00aa9cc0;
    }
    // 00aa9cb9  be02000000             -mov esi, 2
    cpu.esi = 2 /*0x2*/;
    // 00aa9cbe  eb2e                   -jmp 0xaa9cee
    goto L_0x00aa9cee;
L_0x00aa9cc0:
    // 00aa9cc0  f6c501                 +test ch, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 1 /*0x1*/));
    // 00aa9cc3  7407                   -je 0xaa9ccc
    if (cpu.flags.zf)
    {
        goto L_0x00aa9ccc;
    }
    // 00aa9cc5  be03000000             -mov esi, 3
    cpu.esi = 3 /*0x3*/;
    // 00aa9cca  eb22                   -jmp 0xaa9cee
    goto L_0x00aa9cee;
L_0x00aa9ccc:
    // 00aa9ccc  f6c508                 +test ch, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 8 /*0x8*/));
    // 00aa9ccf  7407                   -je 0xaa9cd8
    if (cpu.flags.zf)
    {
        goto L_0x00aa9cd8;
    }
    // 00aa9cd1  be04000000             -mov esi, 4
    cpu.esi = 4 /*0x4*/;
    // 00aa9cd6  eb16                   -jmp 0xaa9cee
    goto L_0x00aa9cee;
L_0x00aa9cd8:
    // 00aa9cd8  f6c502                 +test ch, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 2 /*0x2*/));
    // 00aa9cdb  7407                   -je 0xaa9ce4
    if (cpu.flags.zf)
    {
        goto L_0x00aa9ce4;
    }
    // 00aa9cdd  be06000000             -mov esi, 6
    cpu.esi = 6 /*0x6*/;
    // 00aa9ce2  eb0a                   -jmp 0xaa9cee
    goto L_0x00aa9cee;
L_0x00aa9ce4:
    // 00aa9ce4  f6c504                 +test ch, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 4 /*0x4*/));
    // 00aa9ce7  7405                   -je 0xaa9cee
    if (cpu.flags.zf)
    {
        goto L_0x00aa9cee;
    }
    // 00aa9ce9  be05000000             -mov esi, 5
    cpu.esi = 5 /*0x5*/;
L_0x00aa9cee:
    // 00aa9cee  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00aa9cf0  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00aa9cf3  8b0485a837ab00         -mov eax, dword ptr [eax*4 + 0xab37a8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11220904) /* 0xab37a8 */ + cpu.eax * 4);
    // 00aa9cfa  8975d8                 -mov dword ptr [ebp - 0x28], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */) = cpu.esi;
    // 00aa9cfd  8945dc                 -mov dword ptr [ebp - 0x24], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = cpu.eax;
    // 00aa9d00  f6c510                 +test ch, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 16 /*0x10*/));
    // 00aa9d03  740d                   -je 0xaa9d12
    if (cpu.flags.zf)
    {
        goto L_0x00aa9d12;
    }
    // 00aa9d05  dd05ec2eab00           +fld qword ptr [0xab2eec]
    cpu.fpu.push(x86::Float(app->getMemory<double>(x86::reg32(11218668) /* 0xab2eec */)));
    // 00aa9d0b  d9e0                   +fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
    // 00aa9d0d  dd5df0                 +fstp qword ptr [ebp - 0x10]
    app->getMemory<double>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00aa9d10  eb42                   -jmp 0xaa9d54
    goto L_0x00aa9d54;
L_0x00aa9d12:
    // 00aa9d12  f6c520                 +test ch, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 32 /*0x20*/));
    // 00aa9d15  740a                   -je 0xaa9d21
    if (cpu.flags.zf)
    {
        goto L_0x00aa9d21;
    }
    // 00aa9d17  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 00aa9d19  894df0                 -mov dword ptr [ebp - 0x10], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.ecx;
    // 00aa9d1c  894df4                 -mov dword ptr [ebp - 0xc], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.ecx;
    // 00aa9d1f  eb33                   -jmp 0xaa9d54
    goto L_0x00aa9d54;
L_0x00aa9d21:
    // 00aa9d21  f6c540                 +test ch, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 64 /*0x40*/));
    // 00aa9d24  740f                   -je 0xaa9d35
    if (cpu.flags.zf)
    {
        goto L_0x00aa9d35;
    }
    // 00aa9d26  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00aa9d28  bb0000f03f             -mov ebx, 0x3ff00000
    cpu.ebx = 1072693248 /*0x3ff00000*/;
    // 00aa9d2d  8955f0                 -mov dword ptr [ebp - 0x10], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.edx;
    // 00aa9d30  895df4                 -mov dword ptr [ebp - 0xc], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.ebx;
    // 00aa9d33  eb1f                   -jmp 0xaa9d54
    goto L_0x00aa9d54;
L_0x00aa9d35:
    // 00aa9d35  f6c580                 +test ch, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 128 /*0x80*/));
    // 00aa9d38  740f                   -je 0xaa9d49
    if (cpu.flags.zf)
    {
        goto L_0x00aa9d49;
    }
    // 00aa9d3a  a1ec2eab00             -mov eax, dword ptr [0xab2eec]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11218668) /* 0xab2eec */);
    // 00aa9d3f  8945f0                 -mov dword ptr [ebp - 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
    // 00aa9d42  a1f02eab00             -mov eax, dword ptr [0xab2ef0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11218672) /* 0xab2ef0 */);
    // 00aa9d47  eb08                   -jmp 0xaa9d51
    goto L_0x00aa9d51;
L_0x00aa9d49:
    // 00aa9d49  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 00aa9d4b  8945f0                 -mov dword ptr [ebp - 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
    // 00aa9d4e  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
L_0x00aa9d51:
    // 00aa9d51  8945f4                 -mov dword ptr [ebp - 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.eax;
L_0x00aa9d54:
    // 00aa9d54  8d45d8                 -lea eax, [ebp - 0x28]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-40) /* -0x28 */);
    // 00aa9d57  e8822c0000             -call 0xaac9de
    cpu.esp -= 4;
    sub_aac9de(app, cpu);
    if (cpu.terminate) return;
    // 00aa9d5c  8d65f8                 -lea esp, [ebp - 8]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00aa9d5f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa9d60  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa9d61  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa9d62  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_aa9d63(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa9d63  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00aa9d64  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00aa9d66  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00aa9d67  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aa9d68  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aa9d69  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aa9d6a  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00aa9d6d  8a5510                 -mov dl, byte ptr [ebp + 0x10]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 00aa9d70  80fa01                 +cmp dl, 1
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00aa9d73  7231                   -jb 0xaa9da6
    if (cpu.flags.cf)
    {
        goto L_0x00aa9da6;
    }
    // 00aa9d75  80fa03                 +cmp dl, 3
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(3 /*0x3*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00aa9d78  7607                   -jbe 0xaa9d81
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00aa9d81;
    }
    // 00aa9d7a  80fa04                 +cmp dl, 4
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(4 /*0x4*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00aa9d7d  7413                   -je 0xaa9d92
    if (cpu.flags.zf)
    {
        goto L_0x00aa9d92;
    }
    // 00aa9d7f  eb25                   -jmp 0xaa9da6
    goto L_0x00aa9da6;
L_0x00aa9d81:
    // 00aa9d81  88d0                   -mov al, dl
    cpu.al = cpu.dl;
    // 00aa9d83  0c40                   -or al, 0x40
    cpu.al |= x86::reg8(x86::sreg8(64 /*0x40*/));
    // 00aa9d85  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00aa9d8a  8d5508                 -lea edx, [ebp + 8]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00aa9d8d  80cc20                 +or ah, 0x20
    cpu.clear_co();
    cpu.set_szp((cpu.ah |= x86::reg8(x86::sreg8(32 /*0x20*/))));
    // 00aa9d90  eb36                   -jmp 0xaa9dc8
    goto L_0x00aa9dc8;
L_0x00aa9d92:
    // 00aa9d92  d9ee                   +fldz 
    cpu.fpu.push(0.0);
    // 00aa9d94  dc5d08                 +fcomp qword ptr [ebp + 8]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<double>(cpu.ebp + x86::reg32(8) /* 0x8 */)));
    cpu.fpu.pop();
    // 00aa9d97  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00aa9d99  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 00aa9d9a  760a                   -jbe 0xaa9da6
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00aa9da6;
    }
    // 00aa9d9c  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00aa9d9e  8955e8                 -mov dword ptr [ebp - 0x18], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.edx;
    // 00aa9da1  8955ec                 -mov dword ptr [ebp - 0x14], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.edx;
    // 00aa9da4  eb2a                   -jmp 0xaa9dd0
    goto L_0x00aa9dd0;
L_0x00aa9da6:
    // 00aa9da6  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00aa9da8  88d1                   -mov cl, dl
    cpu.cl = cpu.dl;
    // 00aa9daa  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00aa9dac  80cf81                 -or bh, 0x81
    cpu.bh |= x86::reg8(x86::sreg8(129 /*0x81*/));
    // 00aa9daf  80fa06                 +cmp dl, 6
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(6 /*0x6*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00aa9db2  750f                   -jne 0xaa9dc3
    if (!cpu.flags.zf)
    {
        goto L_0x00aa9dc3;
    }
    // 00aa9db4  d9ee                   +fldz 
    cpu.fpu.push(0.0);
    // 00aa9db6  dc5d08                 +fcomp qword ptr [ebp + 8]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<double>(cpu.ebp + x86::reg32(8) /* 0x8 */)));
    cpu.fpu.pop();
    // 00aa9db9  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00aa9dbb  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 00aa9dbc  7605                   -jbe 0xaa9dc3
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00aa9dc3;
    }
    // 00aa9dbe  80cd11                 -or ch, 0x11
    cpu.ch |= x86::reg8(x86::sreg8(17 /*0x11*/));
    // 00aa9dc1  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
L_0x00aa9dc3:
    // 00aa9dc3  8d5508                 -lea edx, [ebp + 8]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00aa9dc6  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x00aa9dc8:
    // 00aa9dc8  e8b1feffff             -call 0xaa9c7e
    cpu.esp -= 4;
    sub_aa9c7e(app, cpu);
    if (cpu.terminate) return;
    // 00aa9dcd  dd5de8                 -fstp qword ptr [ebp - 0x18]
    app->getMemory<double>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x00aa9dd0:
    // 00aa9dd0  dd45e8                 -fld qword ptr [ebp - 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.ebp + x86::reg32(-24) /* -0x18 */)));
    // 00aa9dd3  8d65f0                 -lea esp, [ebp - 0x10]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00aa9dd6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa9dd7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa9dd8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa9dd9  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa9dda  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa9ddb  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 0x00 */
void sub_aa9de0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa9de0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aa9de1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aa9de2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aa9de3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00aa9de4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00aa9de5  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00aa9de7  8b4210                 -mov eax, dword ptr [edx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00aa9dea  ff15ac36ab00           -call dword ptr [0xab36ac]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11220652) /* 0xab36ac */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa9df0  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00aa9df3  8b480c                 -mov ecx, dword ptr [eax + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00aa9df6  83f901                 +cmp ecx, 1
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
    // 00aa9df9  741e                   -je 0xaa9e19
    if (cpu.flags.zf)
    {
        goto L_0x00aa9e19;
    }
    // 00aa9dfb  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00aa9dfd  7413                   -je 0xaa9e12
    if (cpu.flags.zf)
    {
        goto L_0x00aa9e12;
    }
    // 00aa9dff  8b4210                 -mov eax, dword ptr [edx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00aa9e02  ff15b036ab00           -call dword ptr [0xab36b0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11220656) /* 0xab36b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa9e08  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00aa9e0d  e9dc000000             -jmp 0xaa9eee
    goto L_0x00aa9eee;
L_0x00aa9e12:
    // 00aa9e12  c7400c01000000         -mov dword ptr [eax + 0xc], 1
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = 1 /*0x1*/;
L_0x00aa9e19:
    // 00aa9e19  f6420c02               +test byte ptr [edx + 0xc], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */) & 2 /*0x2*/));
    // 00aa9e1d  7522                   -jne 0xaa9e41
    if (!cpu.flags.zf)
    {
        goto L_0x00aa9e41;
    }
    // 00aa9e1f  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 00aa9e24  e8f7130000             -call 0xaab220
    cpu.esp -= 4;
    sub_aab220(app, cpu);
    if (cpu.terminate) return;
    // 00aa9e29  804a0c20               -or byte ptr [edx + 0xc], 0x20
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */) |= x86::reg8(x86::sreg8(32 /*0x20*/));
    // 00aa9e2d  8b4210                 -mov eax, dword ptr [edx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00aa9e30  ff15b036ab00           -call dword ptr [0xab36b0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11220656) /* 0xab36b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa9e36  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00aa9e3b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa9e3c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa9e3d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa9e3e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa9e3f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa9e40  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00aa9e41:
    // 00aa9e41  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00aa9e44  83780800               +cmp dword ptr [eax + 8], 0
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
    // 00aa9e48  7507                   -jne 0xaa9e51
    if (!cpu.flags.zf)
    {
        goto L_0x00aa9e51;
    }
    // 00aa9e4a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00aa9e4c  e8af000000             -call 0xaa9f00
    cpu.esp -= 4;
    sub_aa9f00(app, cpu);
    if (cpu.terminate) return;
L_0x00aa9e51:
    // 00aa9e51  b900040000             -mov ecx, 0x400
    cpu.ecx = 1024 /*0x400*/;
    // 00aa9e56  83fb0a                 +cmp ebx, 0xa
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
    // 00aa9e59  7547                   -jne 0xaa9ea2
    if (!cpu.flags.zf)
    {
        goto L_0x00aa9ea2;
    }
    // 00aa9e5b  8a420c                 -mov al, byte ptr [edx + 0xc]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00aa9e5e  b900060000             -mov ecx, 0x600
    cpu.ecx = 1536 /*0x600*/;
    // 00aa9e63  a840                   +test al, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 64 /*0x40*/));
    // 00aa9e65  753b                   -jne 0xaa9ea2
    if (!cpu.flags.zf)
    {
        goto L_0x00aa9ea2;
    }
    // 00aa9e67  804a0d10               -or byte ptr [edx + 0xd], 0x10
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(13) /* 0xd */) |= x86::reg8(x86::sreg8(16 /*0x10*/));
    // 00aa9e6b  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 00aa9e6d  c6000d                 -mov byte ptr [eax], 0xd
    app->getMemory<x86::reg8>(cpu.eax) = 13 /*0xd*/;
    // 00aa9e70  8b2a                   -mov ebp, dword ptr [edx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx);
    // 00aa9e72  45                     -inc ebp
    (cpu.ebp)++;
    // 00aa9e73  8b4204                 -mov eax, dword ptr [edx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00aa9e76  892a                   -mov dword ptr [edx], ebp
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebp;
    // 00aa9e78  40                     -inc eax
    (cpu.eax)++;
    // 00aa9e79  8b7214                 -mov esi, dword ptr [edx + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */);
    // 00aa9e7c  894204                 -mov dword ptr [edx + 4], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00aa9e7f  39f0                   +cmp eax, esi
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
    // 00aa9e81  751f                   -jne 0xaa9ea2
    if (!cpu.flags.zf)
    {
        goto L_0x00aa9ea2;
    }
    // 00aa9e83  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00aa9e85  e8f6ebffff             -call 0xaa8a80
    cpu.esp -= 4;
    sub_aa8a80(app, cpu);
    if (cpu.terminate) return;
    // 00aa9e8a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aa9e8c  7414                   -je 0xaa9ea2
    if (cpu.flags.zf)
    {
        goto L_0x00aa9ea2;
    }
    // 00aa9e8e  8b4210                 -mov eax, dword ptr [edx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00aa9e91  ff15b036ab00           -call dword ptr [0xab36b0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11220656) /* 0xab36b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa9e97  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00aa9e9c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa9e9d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa9e9e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa9e9f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa9ea0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa9ea1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00aa9ea2:
    // 00aa9ea2  804a0d10               -or byte ptr [edx + 0xd], 0x10
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(13) /* 0xd */) |= x86::reg8(x86::sreg8(16 /*0x10*/));
    // 00aa9ea6  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 00aa9ea8  8818                   -mov byte ptr [eax], bl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.bl;
    // 00aa9eaa  8b3a                   -mov edi, dword ptr [edx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx);
    // 00aa9eac  47                     -inc edi
    (cpu.edi)++;
    // 00aa9ead  8b6a04                 -mov ebp, dword ptr [edx + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00aa9eb0  893a                   -mov dword ptr [edx], edi
    app->getMemory<x86::reg32>(cpu.edx) = cpu.edi;
    // 00aa9eb2  45                     -inc ebp
    (cpu.ebp)++;
    // 00aa9eb3  8b420c                 -mov eax, dword ptr [edx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00aa9eb6  896a04                 -mov dword ptr [edx + 4], ebp
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 00aa9eb9  85c1                   +test ecx, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.eax));
    // 00aa9ebb  7505                   -jne 0xaa9ec2
    if (!cpu.flags.zf)
    {
        goto L_0x00aa9ec2;
    }
    // 00aa9ebd  3b6a14                 +cmp ebp, dword ptr [edx + 0x14]
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
    // 00aa9ec0  751f                   -jne 0xaa9ee1
    if (!cpu.flags.zf)
    {
        goto L_0x00aa9ee1;
    }
L_0x00aa9ec2:
    // 00aa9ec2  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00aa9ec4  e8b7ebffff             -call 0xaa8a80
    cpu.esp -= 4;
    sub_aa8a80(app, cpu);
    if (cpu.terminate) return;
    // 00aa9ec9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aa9ecb  7414                   -je 0xaa9ee1
    if (cpu.flags.zf)
    {
        goto L_0x00aa9ee1;
    }
    // 00aa9ecd  8b4210                 -mov eax, dword ptr [edx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00aa9ed0  ff15b036ab00           -call dword ptr [0xab36b0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11220656) /* 0xab36b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa9ed6  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00aa9edb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa9edc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa9edd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa9ede  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa9edf  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa9ee0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00aa9ee1:
    // 00aa9ee1  8b4210                 -mov eax, dword ptr [edx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00aa9ee4  ff15b036ab00           -call dword ptr [0xab36b0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11220656) /* 0xab36b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa9eea  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00aa9eec  88d8                   -mov al, bl
    cpu.al = cpu.bl;
L_0x00aa9eee:
    // 00aa9eee  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa9eef  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa9ef0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa9ef1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa9ef2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa9ef3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_aa9f00(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa9f00  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aa9f01  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aa9f02  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aa9f03  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00aa9f05  e8062b0000             -call 0xaaca10
    cpu.esp -= 4;
    sub_aaca10(app, cpu);
    if (cpu.terminate) return;
    // 00aa9f0a  837a1400               +cmp dword ptr [edx + 0x14], 0
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
    // 00aa9f0e  7526                   -jne 0xaa9f36
    if (!cpu.flags.zf)
    {
        goto L_0x00aa9f36;
    }
    // 00aa9f10  8a620d                 -mov ah, byte ptr [edx + 0xd]
    cpu.ah = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(13) /* 0xd */);
    // 00aa9f13  f6c402                 +test ah, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 2 /*0x2*/));
    // 00aa9f16  7409                   -je 0xaa9f21
    if (cpu.flags.zf)
    {
        goto L_0x00aa9f21;
    }
    // 00aa9f18  c7421486000000         -mov dword ptr [edx + 0x14], 0x86
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */) = 134 /*0x86*/;
    // 00aa9f1f  eb15                   -jmp 0xaa9f36
    goto L_0x00aa9f36;
L_0x00aa9f21:
    // 00aa9f21  f6c404                 +test ah, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 4 /*0x4*/));
    // 00aa9f24  7409                   -je 0xaa9f2f
    if (cpu.flags.zf)
    {
        goto L_0x00aa9f2f;
    }
    // 00aa9f26  c7421401000000         -mov dword ptr [edx + 0x14], 1
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */) = 1 /*0x1*/;
    // 00aa9f2d  eb07                   -jmp 0xaa9f36
    goto L_0x00aa9f36;
L_0x00aa9f2f:
    // 00aa9f2f  c7421400100000         -mov dword ptr [edx + 0x14], 0x1000
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */) = 4096 /*0x1000*/;
L_0x00aa9f36:
    // 00aa9f36  8b4214                 -mov eax, dword ptr [edx + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */);
    // 00aa9f39  e872ddffff             -call 0xaa7cb0
    cpu.esp -= 4;
    sub_aa7cb0(app, cpu);
    if (cpu.terminate) return;
    // 00aa9f3e  8b5a08                 -mov ebx, dword ptr [edx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00aa9f41  894308                 -mov dword ptr [ebx + 8], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00aa9f44  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00aa9f47  83780800               +cmp dword ptr [eax + 8], 0
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
    // 00aa9f4b  7523                   -jne 0xaa9f70
    if (!cpu.flags.zf)
    {
        goto L_0x00aa9f70;
    }
    // 00aa9f4d  8a4a0d                 -mov cl, byte ptr [edx + 0xd]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(13) /* 0xd */);
    // 00aa9f50  80e1f8                 -and cl, 0xf8
    cpu.cl &= x86::reg8(x86::sreg8(248 /*0xf8*/));
    // 00aa9f53  884a0d                 -mov byte ptr [edx + 0xd], cl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(13) /* 0xd */) = cpu.cl;
    // 00aa9f56  88cd                   -mov ch, cl
    cpu.ch = cpu.cl;
    // 00aa9f58  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00aa9f5b  80cd04                 +or ch, 4
    cpu.clear_co();
    cpu.set_szp((cpu.ch |= x86::reg8(x86::sreg8(4 /*0x4*/))));
    // 00aa9f5e  8d5a18                 -lea ebx, [edx + 0x18]
    cpu.ebx = x86::reg32(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 00aa9f61  886a0d                 -mov byte ptr [edx + 0xd], ch
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(13) /* 0xd */) = cpu.ch;
    // 00aa9f64  895808                 -mov dword ptr [eax + 8], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 00aa9f67  c7421401000000         -mov dword ptr [edx + 0x14], 1
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */) = 1 /*0x1*/;
    // 00aa9f6e  eb04                   -jmp 0xaa9f74
    goto L_0x00aa9f74;
L_0x00aa9f70:
    // 00aa9f70  804a0c08               -or byte ptr [edx + 0xc], 8
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */) |= x86::reg8(x86::sreg8(8 /*0x8*/));
L_0x00aa9f74:
    // 00aa9f74  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00aa9f77  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00aa9f7a  c7420400000000         -mov dword ptr [edx + 4], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 00aa9f81  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 00aa9f83  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa9f84  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa9f85  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aa9f86  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_aa9f90(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aa9f90  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aa9f91  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00aa9f92  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00aa9f93  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00aa9f94  83ec70                 -sub esp, 0x70
    (cpu.esp) -= x86::reg32(x86::sreg32(112 /*0x70*/));
    // 00aa9f97  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 00aa9f99  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 00aa9f9b  30db                   -xor bl, bl
    cpu.bl ^= x86::reg8(x86::sreg8(cpu.bl));
    // 00aa9f9d  b964000000             -mov ecx, 0x64
    cpu.ecx = 100 /*0x64*/;
    // 00aa9fa2  885c246c               -mov byte ptr [esp + 0x6c], bl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(108) /* 0x6c */) = cpu.bl;
    // 00aa9fa6  30ff                   -xor bh, bh
    cpu.bh ^= x86::reg8(x86::sreg8(cpu.bh));
    // 00aa9fa8  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00aa9fab  66895c241e             -mov word ptr [esp + 0x1e], bx
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(30) /* 0x1e */) = cpu.bx;
    // 00aa9fb0  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00aa9fb2  66894c241c             -mov word ptr [esp + 0x1c], cx
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.cx;
    // 00aa9fb7  895c2410               -mov dword ptr [esp + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 00aa9fbb  8a3a                   -mov bh, byte ptr [edx]
    cpu.bh = app->getMemory<x86::reg8>(cpu.edx);
    // 00aa9fbd  89542468               -mov dword ptr [esp + 0x68], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */) = cpu.edx;
    // 00aa9fc1  84ff                   +test bh, bh
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & cpu.bh));
    // 00aa9fc3  0f8461030000           -je 0xaaa32a
    if (cpu.flags.zf)
    {
        goto L_0x00aaa32a;
    }
L_0x00aa9fc9:
    // 00aa9fc9  8b442468               -mov eax, dword ptr [esp + 0x68]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 00aa9fcd  8b6c2468               -mov ebp, dword ptr [esp + 0x68]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 00aa9fd1  8a28                   -mov ch, byte ptr [eax]
    cpu.ch = app->getMemory<x86::reg8>(cpu.eax);
    // 00aa9fd3  45                     -inc ebp
    (cpu.ebp)++;
    // 00aa9fd4  80fd25                 +cmp ch, 0x25
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
    // 00aa9fd7  7411                   -je 0xaa9fea
    if (cpu.flags.zf)
    {
        goto L_0x00aa9fea;
    }
    // 00aa9fd9  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00aa9fdb  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00aa9fdd  88ea                   -mov dl, ch
    cpu.dl = cpu.ch;
    // 00aa9fdf  896c2468               -mov dword ptr [esp + 0x68], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */) = cpu.ebp;
    // 00aa9fe3  ffd7                   -call edi
    cpu.ip = cpu.edi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aa9fe5  e918030000             -jmp 0xaaa302
    goto L_0x00aaa302;
L_0x00aa9fea:
    // 00aa9fea  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 00aa9fec  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00aa9fee  8d542460               -lea edx, [esp + 0x60]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 00aa9ff2  89442460               -mov dword ptr [esp + 0x60], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */) = cpu.eax;
    // 00aa9ff6  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00aa9ff8  e83b030000             -call 0xaaa338
    cpu.esp -= 4;
    sub_aaa338(app, cpu);
    if (cpu.terminate) return;
    // 00aa9ffd  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00aa9fff  8b442460               -mov eax, dword ptr [esp + 0x60]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 00aaa003  45                     -inc ebp
    (cpu.ebp)++;
    // 00aaa004  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 00aaa006  8a45ff                 -mov al, byte ptr [ebp - 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-1) /* -0x1 */);
    // 00aaa009  896c2468               -mov dword ptr [esp + 0x68], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */) = cpu.ebp;
    // 00aaa00d  88442415               -mov byte ptr [esp + 0x15], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(21) /* 0x15 */) = cpu.al;
    // 00aaa011  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 00aaa013  0f8411030000           -je 0xaaa32a
    if (cpu.flags.zf)
    {
        goto L_0x00aaa32a;
    }
    // 00aaa019  3c6e                   +cmp al, 0x6e
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
    // 00aaa01b  0f8570010000           -jne 0xaaa191
    if (!cpu.flags.zf)
    {
        goto L_0x00aaa191;
    }
    // 00aaa021  8a5c241e               -mov bl, byte ptr [esp + 0x1e]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(30) /* 0x1e */);
    // 00aaa025  f6c320                 +test bl, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 32 /*0x20*/));
    // 00aaa028  744f                   -je 0xaaa079
    if (cpu.flags.zf)
    {
        goto L_0x00aaa079;
    }
    // 00aaa02a  f6c380                 +test bl, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 128 /*0x80*/));
    // 00aaa02d  741f                   -je 0xaaa04e
    if (cpu.flags.zf)
    {
        goto L_0x00aaa04e;
    }
    // 00aaa02f  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 00aaa031  83c208                 -add edx, 8
    (cpu.edx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00aaa034  8916                   -mov dword ptr [esi], edx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edx;
    // 00aaa036  c452f8                 -les edx, ptr [edx - 8]
    NFS2_ASSERT(false);
    // 00aaa039  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00aaa03d  268902                 -mov dword ptr es:[edx], eax
    app->getMemory<x86::reg32>(cpu.ees + cpu.edx) = cpu.eax;
    // 00aaa040  8b442468               -mov eax, dword ptr [esp + 0x68]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 00aaa044  803800                 +cmp byte ptr [eax], 0
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
    // 00aaa047  7580                   -jne 0xaa9fc9
    if (!cpu.flags.zf)
    {
        goto L_0x00aa9fc9;
    }
    // 00aaa049  e9dc020000             -jmp 0xaaa32a
    goto L_0x00aaa32a;
L_0x00aaa04e:
    // 00aaa04e  f6c340                 +test bl, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 64 /*0x40*/));
    // 00aaa051  0f84e8000000           -je 0xaaa13f
    if (cpu.flags.zf)
    {
        goto L_0x00aaa13f;
    }
    // 00aaa057  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00aaa059  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00aaa05c  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 00aaa05e  8b50fc                 -mov edx, dword ptr [eax - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */);
    // 00aaa061  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00aaa065  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 00aaa067  8b442468               -mov eax, dword ptr [esp + 0x68]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 00aaa06b  803800                 +cmp byte ptr [eax], 0
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
    // 00aaa06e  0f8555ffffff           -jne 0xaa9fc9
    if (!cpu.flags.zf)
    {
        goto L_0x00aa9fc9;
    }
    // 00aaa074  e9b1020000             -jmp 0xaaa32a
    goto L_0x00aaa32a;
L_0x00aaa079:
    // 00aaa079  f6c310                 +test bl, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 16 /*0x10*/));
    // 00aaa07c  0f8489000000           -je 0xaaa10b
    if (cpu.flags.zf)
    {
        goto L_0x00aaa10b;
    }
    // 00aaa082  f6c380                 +test bl, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 128 /*0x80*/));
    // 00aaa085  742b                   -je 0xaaa0b2
    if (cpu.flags.zf)
    {
        goto L_0x00aaa0b2;
    }
    // 00aaa087  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 00aaa089  83c108                 -add ecx, 8
    (cpu.ecx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00aaa08c  890e                   -mov dword ptr [esi], ecx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.ecx;
    // 00aaa08e  c451f8                 -les edx, ptr [ecx - 8]
    NFS2_ASSERT(false);
    // 00aaa091  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00aaa095  66268902               -mov word ptr es:[edx], ax
    app->getMemory<x86::reg16>(cpu.ees + cpu.edx) = cpu.ax;
    // 00aaa099  8b442468               -mov eax, dword ptr [esp + 0x68]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 00aaa09d  803800                 +cmp byte ptr [eax], 0
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
    // 00aaa0a0  0f8523ffffff           -jne 0xaa9fc9
    if (!cpu.flags.zf)
    {
        goto L_0x00aa9fc9;
    }
    // 00aaa0a6  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00aaa0aa  83c470                 -add esp, 0x70
    (cpu.esp) += x86::reg32(x86::sreg32(112 /*0x70*/));
    // 00aaa0ad  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aaa0ae  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00aaa0af  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aaa0b0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aaa0b1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00aaa0b2:
    // 00aaa0b2  f6c340                 +test bl, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 64 /*0x40*/));
    // 00aaa0b5  742a                   -je 0xaaa0e1
    if (cpu.flags.zf)
    {
        goto L_0x00aaa0e1;
    }
    // 00aaa0b7  8b1e                   -mov ebx, dword ptr [esi]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi);
    // 00aaa0b9  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00aaa0bc  891e                   -mov dword ptr [esi], ebx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.ebx;
    // 00aaa0be  8b53fc                 -mov edx, dword ptr [ebx - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-4) /* -0x4 */);
    // 00aaa0c1  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00aaa0c5  668902                 -mov word ptr [edx], ax
    app->getMemory<x86::reg16>(cpu.edx) = cpu.ax;
    // 00aaa0c8  8b442468               -mov eax, dword ptr [esp + 0x68]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 00aaa0cc  803800                 +cmp byte ptr [eax], 0
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
    // 00aaa0cf  0f85f4feffff           -jne 0xaa9fc9
    if (!cpu.flags.zf)
    {
        goto L_0x00aa9fc9;
    }
    // 00aaa0d5  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00aaa0d9  83c470                 -add esp, 0x70
    (cpu.esp) += x86::reg32(x86::sreg32(112 /*0x70*/));
    // 00aaa0dc  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aaa0dd  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00aaa0de  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aaa0df  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aaa0e0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00aaa0e1:
    // 00aaa0e1  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 00aaa0e3  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00aaa0e6  8916                   -mov dword ptr [esi], edx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edx;
    // 00aaa0e8  8b52fc                 -mov edx, dword ptr [edx - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */);
    // 00aaa0eb  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00aaa0ef  668902                 -mov word ptr [edx], ax
    app->getMemory<x86::reg16>(cpu.edx) = cpu.ax;
    // 00aaa0f2  8b442468               -mov eax, dword ptr [esp + 0x68]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 00aaa0f6  803800                 +cmp byte ptr [eax], 0
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
    // 00aaa0f9  0f85cafeffff           -jne 0xaa9fc9
    if (!cpu.flags.zf)
    {
        goto L_0x00aa9fc9;
    }
    // 00aaa0ff  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00aaa103  83c470                 -add esp, 0x70
    (cpu.esp) += x86::reg32(x86::sreg32(112 /*0x70*/));
    // 00aaa106  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aaa107  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00aaa108  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aaa109  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aaa10a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00aaa10b:
    // 00aaa10b  f6c380                 +test bl, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 128 /*0x80*/));
    // 00aaa10e  742a                   -je 0xaaa13a
    if (cpu.flags.zf)
    {
        goto L_0x00aaa13a;
    }
    // 00aaa110  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00aaa112  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00aaa115  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 00aaa117  c450f8                 -les edx, ptr [eax - 8]
    NFS2_ASSERT(false);
    // 00aaa11a  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00aaa11e  268902                 -mov dword ptr es:[edx], eax
    app->getMemory<x86::reg32>(cpu.ees + cpu.edx) = cpu.eax;
    // 00aaa121  8b442468               -mov eax, dword ptr [esp + 0x68]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 00aaa125  803800                 +cmp byte ptr [eax], 0
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
    // 00aaa128  0f859bfeffff           -jne 0xaa9fc9
    if (!cpu.flags.zf)
    {
        goto L_0x00aa9fc9;
    }
    // 00aaa12e  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00aaa132  83c470                 -add esp, 0x70
    (cpu.esp) += x86::reg32(x86::sreg32(112 /*0x70*/));
    // 00aaa135  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aaa136  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00aaa137  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aaa138  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aaa139  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00aaa13a:
    // 00aaa13a  f6c340                 +test bl, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 64 /*0x40*/));
    // 00aaa13d  7429                   -je 0xaaa168
    if (cpu.flags.zf)
    {
        goto L_0x00aaa168;
    }
L_0x00aaa13f:
    // 00aaa13f  8b2e                   -mov ebp, dword ptr [esi]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi);
    // 00aaa141  83c504                 -add ebp, 4
    (cpu.ebp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00aaa144  892e                   -mov dword ptr [esi], ebp
    app->getMemory<x86::reg32>(cpu.esi) = cpu.ebp;
    // 00aaa146  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00aaa149  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00aaa14d  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 00aaa14f  8b442468               -mov eax, dword ptr [esp + 0x68]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 00aaa153  803800                 +cmp byte ptr [eax], 0
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
    // 00aaa156  0f856dfeffff           -jne 0xaa9fc9
    if (!cpu.flags.zf)
    {
        goto L_0x00aa9fc9;
    }
    // 00aaa15c  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00aaa160  83c470                 -add esp, 0x70
    (cpu.esp) += x86::reg32(x86::sreg32(112 /*0x70*/));
    // 00aaa163  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aaa164  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00aaa165  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aaa166  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aaa167  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00aaa168:
    // 00aaa168  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 00aaa16a  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00aaa16d  890e                   -mov dword ptr [esi], ecx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.ecx;
    // 00aaa16f  8b51fc                 -mov edx, dword ptr [ecx - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-4) /* -0x4 */);
    // 00aaa172  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00aaa176  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 00aaa178  8b442468               -mov eax, dword ptr [esp + 0x68]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 00aaa17c  803800                 +cmp byte ptr [eax], 0
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
    // 00aaa17f  0f8544feffff           -jne 0xaa9fc9
    if (!cpu.flags.zf)
    {
        goto L_0x00aa9fc9;
    }
    // 00aaa185  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00aaa189  83c470                 -add esp, 0x70
    (cpu.esp) += x86::reg32(x86::sreg32(112 /*0x70*/));
    // 00aaa18c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aaa18d  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00aaa18e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aaa18f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aaa190  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00aaa191:
    // 00aaa191  8d4c246c               -lea ecx, [esp + 0x6c]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(108) /* 0x6c */);
    // 00aaa195  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 00aaa197  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00aaa199  8d542464               -lea edx, [esp + 0x64]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(100) /* 0x64 */);
    // 00aaa19d  89442464               -mov dword ptr [esp + 0x64], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */) = cpu.eax;
    // 00aaa1a1  8d442438               -lea eax, [esp + 0x38]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 00aaa1a5  e8ea050000             -call 0xaaa794
    cpu.esp -= 4;
    sub_aaa794(app, cpu);
    if (cpu.terminate) return;
    // 00aaa1aa  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00aaa1ac  8b442464               -mov eax, dword ptr [esp + 0x64]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */);
    // 00aaa1b0  8ec2                   -mov es, edx
    cpu.es = cpu.edx;
    // 00aaa1b2  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 00aaa1b4  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00aaa1b8  8b4c2424               -mov ecx, dword ptr [esp + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00aaa1bc  8b542428               -mov edx, dword ptr [esp + 0x28]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00aaa1c0  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00aaa1c2  8b5c242c               -mov ebx, dword ptr [esp + 0x2c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00aaa1c6  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00aaa1c8  8b4c2430               -mov ecx, dword ptr [esp + 0x30]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 00aaa1cc  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00aaa1ce  8b542434               -mov edx, dword ptr [esp + 0x34]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00aaa1d2  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00aaa1d4  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00aaa1d8  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00aaa1da  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00aaa1dc  8a54241e               -mov dl, byte ptr [esp + 0x1e]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(30) /* 0x1e */);
    // 00aaa1e0  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 00aaa1e4  f6c208                 +test dl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 8 /*0x8*/));
    // 00aaa1e7  751d                   -jne 0xaaa206
    if (!cpu.flags.zf)
    {
        goto L_0x00aaa206;
    }
    // 00aaa1e9  807c241620             +cmp byte ptr [esp + 0x16], 0x20
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
    // 00aaa1ee  7516                   -jne 0xaaa206
    if (!cpu.flags.zf)
    {
        goto L_0x00aaa206;
    }
L_0x00aaa1f0:
    // 00aaa1f0  837c240400             +cmp dword ptr [esp + 4], 0
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
    // 00aaa1f5  7e0f                   -jle 0xaaa206
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00aaa206;
    }
    // 00aaa1f7  ba20000000             -mov edx, 0x20
    cpu.edx = 32 /*0x20*/;
    // 00aaa1fc  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00aaa1fe  ffd7                   -call edi
    cpu.ip = cpu.edi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aaa200  ff4c2404               +dec dword ptr [esp + 4]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00aaa204  ebea                   -jmp 0xaaa1f0
    goto L_0x00aaa1f0;
L_0x00aaa206:
    // 00aaa206  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00aaa20a  8d5c2438               -lea ebx, [esp + 0x38]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 00aaa20e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aaa210  7e16                   -jle 0xaaa228
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00aaa228;
    }
L_0x00aaa212:
    // 00aaa212  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00aaa214  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00aaa216  8a13                   -mov dl, byte ptr [ebx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebx);
    // 00aaa218  ffd7                   -call edi
    cpu.ip = cpu.edi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aaa21a  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00aaa21e  4a                     -dec edx
    (cpu.edx)--;
    // 00aaa21f  43                     -inc ebx
    (cpu.ebx)++;
    // 00aaa220  89542420               -mov dword ptr [esp + 0x20], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 00aaa224  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00aaa226  7fea                   -jg 0xaaa212
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00aaa212;
    }
L_0x00aaa228:
    // 00aaa228  837c242400             +cmp dword ptr [esp + 0x24], 0
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
    // 00aaa22d  7e0f                   -jle 0xaaa23e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00aaa23e;
    }
    // 00aaa22f  ba30000000             -mov edx, 0x30
    cpu.edx = 48 /*0x30*/;
    // 00aaa234  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00aaa236  ffd7                   -call edi
    cpu.ip = cpu.edi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aaa238  ff4c2424               +dec dword ptr [esp + 0x24]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00aaa23c  ebea                   -jmp 0xaaa228
    goto L_0x00aaa228;
L_0x00aaa23e:
    // 00aaa23e  8a5c2415               -mov bl, byte ptr [esp + 0x15]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(21) /* 0x15 */);
    // 00aaa242  80fb73                 +cmp bl, 0x73
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
    // 00aaa245  7533                   -jne 0xaaa27a
    if (!cpu.flags.zf)
    {
        goto L_0x00aaa27a;
    }
    // 00aaa247  f644241e20             +test byte ptr [esp + 0x1e], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(30) /* 0x1e */) & 32 /*0x20*/));
    // 00aaa24c  740f                   -je 0xaaa25d
    if (cpu.flags.zf)
    {
        goto L_0x00aaa25d;
    }
    // 00aaa24e  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 00aaa250  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 00aaa252  8cc2                   -mov edx, es
    cpu.edx = cpu.es;
    // 00aaa254  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00aaa256  e8d5040000             -call 0xaaa730
    cpu.esp -= 4;
    sub_aaa730(app, cpu);
    if (cpu.terminate) return;
    // 00aaa25b  eb4e                   -jmp 0xaaa2ab
    goto L_0x00aaa2ab;
L_0x00aaa25d:
    // 00aaa25d  837c242800             +cmp dword ptr [esp + 0x28], 0
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
    // 00aaa262  7e47                   -jle 0xaaa2ab
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00aaa2ab;
    }
    // 00aaa264  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00aaa266  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00aaa268  268a5500               -mov dl, byte ptr es:[ebp]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ees + cpu.ebp);
    // 00aaa26c  ffd7                   -call edi
    cpu.ip = cpu.edi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aaa26e  8b542428               -mov edx, dword ptr [esp + 0x28]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00aaa272  4a                     +dec edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00aaa273  45                     +inc ebp
    {
        x86::reg32& tmp = cpu.ebp;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00aaa274  89542428               -mov dword ptr [esp + 0x28], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.edx;
    // 00aaa278  ebe3                   -jmp 0xaaa25d
    goto L_0x00aaa25d;
L_0x00aaa27a:
    // 00aaa27a  80fb53                 +cmp bl, 0x53
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
    // 00aaa27d  750f                   -jne 0xaaa28e
    if (!cpu.flags.zf)
    {
        goto L_0x00aaa28e;
    }
    // 00aaa27f  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 00aaa281  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 00aaa283  8cc2                   -mov edx, es
    cpu.edx = cpu.es;
    // 00aaa285  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00aaa287  e8a4040000             -call 0xaaa730
    cpu.esp -= 4;
    sub_aaa730(app, cpu);
    if (cpu.terminate) return;
    // 00aaa28c  eb1d                   -jmp 0xaaa2ab
    goto L_0x00aaa2ab;
L_0x00aaa28e:
    // 00aaa28e  837c242800             +cmp dword ptr [esp + 0x28], 0
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
    // 00aaa293  7e16                   -jle 0xaaa2ab
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00aaa2ab;
    }
    // 00aaa295  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00aaa297  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00aaa299  268a5500               -mov dl, byte ptr es:[ebp]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ees + cpu.ebp);
    // 00aaa29d  ffd7                   -call edi
    cpu.ip = cpu.edi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aaa29f  8b4c2428               -mov ecx, dword ptr [esp + 0x28]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00aaa2a3  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00aaa2a4  45                     +inc ebp
    {
        x86::reg32& tmp = cpu.ebp;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00aaa2a5  894c2428               -mov dword ptr [esp + 0x28], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.ecx;
    // 00aaa2a9  ebe3                   -jmp 0xaaa28e
    goto L_0x00aaa28e;
L_0x00aaa2ab:
    // 00aaa2ab  837c242c00             +cmp dword ptr [esp + 0x2c], 0
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
    // 00aaa2b0  7e0f                   -jle 0xaaa2c1
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00aaa2c1;
    }
    // 00aaa2b2  ba30000000             -mov edx, 0x30
    cpu.edx = 48 /*0x30*/;
    // 00aaa2b7  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00aaa2b9  ffd7                   -call edi
    cpu.ip = cpu.edi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aaa2bb  ff4c242c               +dec dword ptr [esp + 0x2c]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00aaa2bf  ebea                   -jmp 0xaaa2ab
    goto L_0x00aaa2ab;
L_0x00aaa2c1:
    // 00aaa2c1  837c243000             +cmp dword ptr [esp + 0x30], 0
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
    // 00aaa2c6  7e16                   -jle 0xaaa2de
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00aaa2de;
    }
    // 00aaa2c8  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00aaa2ca  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00aaa2cc  268a5500               -mov dl, byte ptr es:[ebp]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ees + cpu.ebp);
    // 00aaa2d0  ffd7                   -call edi
    cpu.ip = cpu.edi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aaa2d2  8b542430               -mov edx, dword ptr [esp + 0x30]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 00aaa2d6  4a                     +dec edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00aaa2d7  45                     +inc ebp
    {
        x86::reg32& tmp = cpu.ebp;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00aaa2d8  89542430               -mov dword ptr [esp + 0x30], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.edx;
    // 00aaa2dc  ebe3                   -jmp 0xaaa2c1
    goto L_0x00aaa2c1;
L_0x00aaa2de:
    // 00aaa2de  837c243400             +cmp dword ptr [esp + 0x34], 0
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
    // 00aaa2e3  7e0f                   -jle 0xaaa2f4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00aaa2f4;
    }
    // 00aaa2e5  ba30000000             -mov edx, 0x30
    cpu.edx = 48 /*0x30*/;
    // 00aaa2ea  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00aaa2ec  ffd7                   -call edi
    cpu.ip = cpu.edi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aaa2ee  ff4c2434               +dec dword ptr [esp + 0x34]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00aaa2f2  ebea                   -jmp 0xaaa2de
    goto L_0x00aaa2de;
L_0x00aaa2f4:
    // 00aaa2f4  f644241e08             +test byte ptr [esp + 0x1e], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(30) /* 0x1e */) & 8 /*0x8*/));
    // 00aaa2f9  7407                   -je 0xaaa302
    if (cpu.flags.zf)
    {
        goto L_0x00aaa302;
    }
L_0x00aaa2fb:
    // 00aaa2fb  837c240400             +cmp dword ptr [esp + 4], 0
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
    // 00aaa300  7f19                   -jg 0xaaa31b
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00aaa31b;
    }
L_0x00aaa302:
    // 00aaa302  8b442468               -mov eax, dword ptr [esp + 0x68]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 00aaa306  803800                 +cmp byte ptr [eax], 0
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
    // 00aaa309  0f85bafcffff           -jne 0xaa9fc9
    if (!cpu.flags.zf)
    {
        goto L_0x00aa9fc9;
    }
    // 00aaa30f  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00aaa313  83c470                 +add esp, 0x70
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
    // 00aaa316  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aaa317  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00aaa318  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aaa319  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aaa31a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00aaa31b:
    // 00aaa31b  ba20000000             -mov edx, 0x20
    cpu.edx = 32 /*0x20*/;
    // 00aaa320  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00aaa322  ffd7                   -call edi
    cpu.ip = cpu.edi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aaa324  ff4c2404               +dec dword ptr [esp + 4]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00aaa328  ebd1                   -jmp 0xaaa2fb
    goto L_0x00aaa2fb;
L_0x00aaa32a:
    // 00aaa32a  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00aaa32e  83c470                 -add esp, 0x70
    (cpu.esp) += x86::reg32(x86::sreg32(112 /*0x70*/));
    // 00aaa331  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aaa332  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00aaa333  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aaa334  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aaa335  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void sub_aaa338(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aaa338  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aaa339  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aaa33a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00aaa33b  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00aaa33d  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00aaa33f  c6431620               -mov byte ptr [ebx + 0x16], 0x20
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(22) /* 0x16 */) = 32 /*0x20*/;
    // 00aaa343  e844010000             -call 0xaaa48c
    cpu.esp -= 4;
    sub_aaa48c(app, cpu);
    if (cpu.terminate) return;
    // 00aaa348  c7430400000000         -mov dword ptr [ebx + 4], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 00aaa34f  80382a                 +cmp byte ptr [eax], 0x2a
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
    // 00aaa352  7524                   -jne 0xaaa378
    if (!cpu.flags.zf)
    {
        goto L_0x00aaa378;
    }
    // 00aaa354  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 00aaa356  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00aaa359  8916                   -mov dword ptr [esi], edx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edx;
    // 00aaa35b  8b52fc                 -mov edx, dword ptr [edx - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */);
    // 00aaa35e  895304                 -mov dword ptr [ebx + 4], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00aaa361  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00aaa363  7d10                   -jge 0xaaa375
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00aaa375;
    }
    // 00aaa365  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00aaa367  8a6b1e                 -mov ch, byte ptr [ebx + 0x1e]
    cpu.ch = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(30) /* 0x1e */);
    // 00aaa36a  f7df                   -neg edi
    cpu.edi = ~cpu.edi + 1;
    // 00aaa36c  80cd08                 +or ch, 8
    cpu.clear_co();
    cpu.set_szp((cpu.ch |= x86::reg8(x86::sreg8(8 /*0x8*/))));
    // 00aaa36f  897b04                 -mov dword ptr [ebx + 4], edi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 00aaa372  886b1e                 -mov byte ptr [ebx + 0x1e], ch
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(30) /* 0x1e */) = cpu.ch;
L_0x00aaa375:
    // 00aaa375  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00aaa376  eb1f                   -jmp 0xaaa397
    goto L_0x00aaa397;
L_0x00aaa378:
    // 00aaa378  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 00aaa37a  80fa30                 +cmp dl, 0x30
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
    // 00aaa37d  7218                   -jb 0xaaa397
    if (cpu.flags.cf)
    {
        goto L_0x00aaa397;
    }
    // 00aaa37f  80fa39                 +cmp dl, 0x39
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
    // 00aaa382  7713                   -ja 0xaaa397
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00aaa397;
    }
    // 00aaa384  6b4b040a               -imul ecx, dword ptr [ebx + 4], 0xa
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */))) * x86::sreg64(x86::sreg32(10 /*0xa*/)));
    // 00aaa388  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00aaa38a  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 00aaa38c  83ea30                 -sub edx, 0x30
    (cpu.edx) -= x86::reg32(x86::sreg32(48 /*0x30*/));
    // 00aaa38f  01d1                   +add ecx, edx
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
    // 00aaa391  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00aaa392  894b04                 -mov dword ptr [ebx + 4], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 00aaa395  ebe1                   -jmp 0xaaa378
    goto L_0x00aaa378;
L_0x00aaa397:
    // 00aaa397  c74308ffffffff         -mov dword ptr [ebx + 8], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = 4294967295 /*0xffffffff*/;
    // 00aaa39e  80382e                 +cmp byte ptr [eax], 0x2e
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
    // 00aaa3a1  7554                   -jne 0xaaa3f7
    if (!cpu.flags.zf)
    {
        goto L_0x00aaa3f7;
    }
    // 00aaa3a3  c7430800000000         -mov dword ptr [ebx + 8], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 00aaa3aa  8a6801                 -mov ch, byte ptr [eax + 1]
    cpu.ch = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00aaa3ad  40                     -inc eax
    (cpu.eax)++;
    // 00aaa3ae  80fd2a                 +cmp ch, 0x2a
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
    // 00aaa3b1  751b                   -jne 0xaaa3ce
    if (!cpu.flags.zf)
    {
        goto L_0x00aaa3ce;
    }
    // 00aaa3b3  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 00aaa3b5  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00aaa3b8  8916                   -mov dword ptr [esi], edx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edx;
    // 00aaa3ba  8b52fc                 -mov edx, dword ptr [edx - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */);
    // 00aaa3bd  895308                 -mov dword ptr [ebx + 8], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00aaa3c0  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00aaa3c2  7d07                   -jge 0xaaa3cb
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00aaa3cb;
    }
    // 00aaa3c4  c74308ffffffff         -mov dword ptr [ebx + 8], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = 4294967295 /*0xffffffff*/;
L_0x00aaa3cb:
    // 00aaa3cb  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00aaa3cc  eb1f                   -jmp 0xaaa3ed
    goto L_0x00aaa3ed;
L_0x00aaa3ce:
    // 00aaa3ce  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 00aaa3d0  80fa30                 +cmp dl, 0x30
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
    // 00aaa3d3  7218                   -jb 0xaaa3ed
    if (cpu.flags.cf)
    {
        goto L_0x00aaa3ed;
    }
    // 00aaa3d5  80fa39                 +cmp dl, 0x39
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
    // 00aaa3d8  7713                   -ja 0xaaa3ed
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00aaa3ed;
    }
    // 00aaa3da  6b4b080a               -imul ecx, dword ptr [ebx + 8], 0xa
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */))) * x86::sreg64(x86::sreg32(10 /*0xa*/)));
    // 00aaa3de  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00aaa3e0  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 00aaa3e2  83ea30                 -sub edx, 0x30
    (cpu.edx) -= x86::reg32(x86::sreg32(48 /*0x30*/));
    // 00aaa3e5  01d1                   +add ecx, edx
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
    // 00aaa3e7  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00aaa3e8  894b08                 -mov dword ptr [ebx + 8], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 00aaa3eb  ebe1                   -jmp 0xaaa3ce
    goto L_0x00aaa3ce;
L_0x00aaa3ed:
    // 00aaa3ed  837b08ff               +cmp dword ptr [ebx + 8], -1
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
    // 00aaa3f1  7404                   -je 0xaaa3f7
    if (cpu.flags.zf)
    {
        goto L_0x00aaa3f7;
    }
    // 00aaa3f3  c6431620               -mov byte ptr [ebx + 0x16], 0x20
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(22) /* 0x16 */) = 32 /*0x20*/;
L_0x00aaa3f7:
    // 00aaa3f7  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 00aaa3f9  8d4801                 -lea ecx, [eax + 1]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00aaa3fc  80fa4e                 +cmp dl, 0x4e
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
    // 00aaa3ff  721f                   -jb 0xaaa420
    if (cpu.flags.cf)
    {
        goto L_0x00aaa420;
    }
    // 00aaa401  0f867b000000           -jbe 0xaaa482
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00aaa482;
    }
    // 00aaa407  80fa6c                 +cmp dl, 0x6c
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
    // 00aaa40a  720b                   -jb 0xaaa417
    if (cpu.flags.cf)
    {
        goto L_0x00aaa417;
    }
    // 00aaa40c  762b                   -jbe 0xaaa439
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00aaa439;
    }
    // 00aaa40e  80fa77                 +cmp dl, 0x77
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
    // 00aaa411  7426                   -je 0xaaa439
    if (cpu.flags.zf)
    {
        goto L_0x00aaa439;
    }
    // 00aaa413  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aaa414  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aaa415  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aaa416  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00aaa417:
    // 00aaa417  80fa68                 +cmp dl, 0x68
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
    // 00aaa41a  742b                   -je 0xaaa447
    if (cpu.flags.zf)
    {
        goto L_0x00aaa447;
    }
    // 00aaa41c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aaa41d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aaa41e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aaa41f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00aaa420:
    // 00aaa420  80fa49                 +cmp dl, 0x49
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
    // 00aaa423  720b                   -jb 0xaaa430
    if (cpu.flags.cf)
    {
        goto L_0x00aaa430;
    }
    // 00aaa425  7626                   -jbe 0xaaa44d
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00aaa44d;
    }
    // 00aaa427  80fa4c                 +cmp dl, 0x4c
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
    // 00aaa42a  743d                   -je 0xaaa469
    if (cpu.flags.zf)
    {
        goto L_0x00aaa469;
    }
    // 00aaa42c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aaa42d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aaa42e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aaa42f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00aaa430:
    // 00aaa430  80fa46                 +cmp dl, 0x46
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
    // 00aaa433  7443                   -je 0xaaa478
    if (cpu.flags.zf)
    {
        goto L_0x00aaa478;
    }
    // 00aaa435  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aaa436  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aaa437  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aaa438  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00aaa439:
    // 00aaa439  8a4b1e                 -mov cl, byte ptr [ebx + 0x1e]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(30) /* 0x1e */);
    // 00aaa43c  80c920                 -or cl, 0x20
    cpu.cl |= x86::reg8(x86::sreg8(32 /*0x20*/));
    // 00aaa43f  40                     -inc eax
    (cpu.eax)++;
    // 00aaa440  884b1e                 -mov byte ptr [ebx + 0x1e], cl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(30) /* 0x1e */) = cpu.cl;
    // 00aaa443  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aaa444  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aaa445  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aaa446  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00aaa447:
    // 00aaa447  804b1e10               +or byte ptr [ebx + 0x1e], 0x10
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(30) /* 0x1e */) |= x86::reg8(x86::sreg8(16 /*0x10*/))));
    // 00aaa44b  eb39                   -jmp 0xaaa486
    goto L_0x00aaa486;
L_0x00aaa44d:
    // 00aaa44d  80780136               +cmp byte ptr [eax + 1], 0x36
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
    // 00aaa451  7535                   -jne 0xaaa488
    if (!cpu.flags.zf)
    {
        goto L_0x00aaa488;
    }
    // 00aaa453  80780234               +cmp byte ptr [eax + 2], 0x34
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
    // 00aaa457  752f                   -jne 0xaaa488
    if (!cpu.flags.zf)
    {
        goto L_0x00aaa488;
    }
    // 00aaa459  8a6b1f                 -mov ch, byte ptr [ebx + 0x1f]
    cpu.ch = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(31) /* 0x1f */);
    // 00aaa45c  80cd01                 -or ch, 1
    cpu.ch |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00aaa45f  83c003                 -add eax, 3
    (cpu.eax) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 00aaa462  886b1f                 -mov byte ptr [ebx + 0x1f], ch
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(31) /* 0x1f */) = cpu.ch;
    // 00aaa465  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aaa466  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aaa467  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aaa468  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00aaa469:
    // 00aaa469  8a531f                 -mov dl, byte ptr [ebx + 0x1f]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(31) /* 0x1f */);
    // 00aaa46c  80ca01                 -or dl, 1
    cpu.dl |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00aaa46f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00aaa471  88531f                 -mov byte ptr [ebx + 0x1f], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(31) /* 0x1f */) = cpu.dl;
    // 00aaa474  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aaa475  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aaa476  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aaa477  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00aaa478:
    // 00aaa478  804b1e80               -or byte ptr [ebx + 0x1e], 0x80
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(30) /* 0x1e */) |= x86::reg8(x86::sreg8(128 /*0x80*/));
    // 00aaa47c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00aaa47e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aaa47f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aaa480  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aaa481  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00aaa482:
    // 00aaa482  804b1e40               -or byte ptr [ebx + 0x1e], 0x40
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(30) /* 0x1e */) |= x86::reg8(x86::sreg8(64 /*0x40*/));
L_0x00aaa486:
    // 00aaa486  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
L_0x00aaa488:
    // 00aaa488  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aaa489  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aaa48a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aaa48b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_aaa48c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aaa48c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aaa48d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aaa48e  66c7421e0000           -mov word ptr [edx + 0x1e], 0
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(30) /* 0x1e */) = 0 /*0x0*/;
    // 00aaa494  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 00aaa496  80fb2d                 +cmp bl, 0x2d
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
    // 00aaa499  7506                   -jne 0xaaa4a1
    if (!cpu.flags.zf)
    {
        goto L_0x00aaa4a1;
    }
    // 00aaa49b  804a1e08               +or byte ptr [edx + 0x1e], 8
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.edx + x86::reg32(30) /* 0x1e */) |= x86::reg8(x86::sreg8(8 /*0x8*/))));
    // 00aaa49f  eb42                   -jmp 0xaaa4e3
    goto L_0x00aaa4e3;
L_0x00aaa4a1:
    // 00aaa4a1  80fb23                 +cmp bl, 0x23
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
    // 00aaa4a4  7506                   -jne 0xaaa4ac
    if (!cpu.flags.zf)
    {
        goto L_0x00aaa4ac;
    }
    // 00aaa4a6  804a1e01               +or byte ptr [edx + 0x1e], 1
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.edx + x86::reg32(30) /* 0x1e */) |= x86::reg8(x86::sreg8(1 /*0x1*/))));
    // 00aaa4aa  eb37                   -jmp 0xaaa4e3
    goto L_0x00aaa4e3;
L_0x00aaa4ac:
    // 00aaa4ac  80fb2b                 +cmp bl, 0x2b
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
    // 00aaa4af  7513                   -jne 0xaaa4c4
    if (!cpu.flags.zf)
    {
        goto L_0x00aaa4c4;
    }
    // 00aaa4b1  8a6a1e                 -mov ch, byte ptr [edx + 0x1e]
    cpu.ch = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(30) /* 0x1e */);
    // 00aaa4b4  80cd04                 -or ch, 4
    cpu.ch |= x86::reg8(x86::sreg8(4 /*0x4*/));
    // 00aaa4b7  88eb                   -mov bl, ch
    cpu.bl = cpu.ch;
    // 00aaa4b9  886a1e                 -mov byte ptr [edx + 0x1e], ch
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(30) /* 0x1e */) = cpu.ch;
    // 00aaa4bc  80e3fd                 +and bl, 0xfd
    cpu.clear_co();
    cpu.set_szp((cpu.bl &= x86::reg8(x86::sreg8(253 /*0xfd*/))));
    // 00aaa4bf  885a1e                 -mov byte ptr [edx + 0x1e], bl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(30) /* 0x1e */) = cpu.bl;
    // 00aaa4c2  eb1f                   -jmp 0xaaa4e3
    goto L_0x00aaa4e3;
L_0x00aaa4c4:
    // 00aaa4c4  80fb20                 +cmp bl, 0x20
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
    // 00aaa4c7  7512                   -jne 0xaaa4db
    if (!cpu.flags.zf)
    {
        goto L_0x00aaa4db;
    }
    // 00aaa4c9  8a7a1e                 -mov bh, byte ptr [edx + 0x1e]
    cpu.bh = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(30) /* 0x1e */);
    // 00aaa4cc  f6c704                 +test bh, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 4 /*0x4*/));
    // 00aaa4cf  7512                   -jne 0xaaa4e3
    if (!cpu.flags.zf)
    {
        goto L_0x00aaa4e3;
    }
    // 00aaa4d1  88f9                   -mov cl, bh
    cpu.cl = cpu.bh;
    // 00aaa4d3  80c902                 +or cl, 2
    cpu.clear_co();
    cpu.set_szp((cpu.cl |= x86::reg8(x86::sreg8(2 /*0x2*/))));
    // 00aaa4d6  884a1e                 -mov byte ptr [edx + 0x1e], cl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(30) /* 0x1e */) = cpu.cl;
    // 00aaa4d9  eb08                   -jmp 0xaaa4e3
    goto L_0x00aaa4e3;
L_0x00aaa4db:
    // 00aaa4db  80fb30                 +cmp bl, 0x30
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
    // 00aaa4de  7511                   -jne 0xaaa4f1
    if (!cpu.flags.zf)
    {
        goto L_0x00aaa4f1;
    }
    // 00aaa4e0  885a16                 -mov byte ptr [edx + 0x16], bl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(22) /* 0x16 */) = cpu.bl;
L_0x00aaa4e3:
    // 00aaa4e3  40                     -inc eax
    (cpu.eax)++;
    // 00aaa4e4  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 00aaa4e6  80fb2d                 +cmp bl, 0x2d
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
    // 00aaa4e9  75b6                   -jne 0xaaa4a1
    if (!cpu.flags.zf)
    {
        goto L_0x00aaa4a1;
    }
    // 00aaa4eb  804a1e08               +or byte ptr [edx + 0x1e], 8
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.edx + x86::reg32(30) /* 0x1e */) |= x86::reg8(x86::sreg8(8 /*0x8*/))));
    // 00aaa4ef  ebf2                   -jmp 0xaaa4e3
    goto L_0x00aaa4e3;
L_0x00aaa4f1:
    // 00aaa4f1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aaa4f2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aaa4f3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_aaa4f4(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aaa4f4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aaa4f5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aaa4f6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00aaa4f7  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00aaa4f8  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00aaa4fa  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00aaa4fc  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00aaa4fe  8ec1                   -mov es, ecx
    cpu.es = cpu.ecx;
    // 00aaa500  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00aaa502:
    // 00aaa502  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00aaa504  268a1e                 -mov bl, byte ptr es:[esi]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ees + cpu.esi);
    // 00aaa507  42                     -inc edx
    (cpu.edx)++;
    // 00aaa508  84db                   +test bl, bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.bl));
    // 00aaa50a  7407                   -je 0xaaa513
    if (cpu.flags.zf)
    {
        goto L_0x00aaa513;
    }
    // 00aaa50c  39f8                   +cmp eax, edi
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
    // 00aaa50e  7403                   -je 0xaaa513
    if (cpu.flags.zf)
    {
        goto L_0x00aaa513;
    }
    // 00aaa510  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00aaa511  ebef                   -jmp 0xaaa502
    goto L_0x00aaa502;
L_0x00aaa513:
    // 00aaa513  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00aaa514  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aaa515  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aaa516  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aaa517  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_aaa518(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aaa518  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aaa519  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aaa51a  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00aaa51b  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00aaa51e  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 00aaa520  8ec2                   -mov es, edx
    cpu.es = cpu.edx;
    // 00aaa522  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00aaa524  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00aaa526  83feff                 +cmp esi, -1
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
    // 00aaa529  7521                   -jne 0xaaa54c
    if (!cpu.flags.zf)
    {
        goto L_0x00aaa54c;
    }
L_0x00aaa52b:
    // 00aaa52b  66268b33               -mov si, word ptr es:[ebx]
    cpu.si = app->getMemory<x86::reg16>(cpu.ees + cpu.ebx);
    // 00aaa52f  6685f6                 +test si, si
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.si & cpu.si));
    // 00aaa532  7440                   -je 0xaaa574
    if (cpu.flags.zf)
    {
        goto L_0x00aaa574;
    }
    // 00aaa534  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00aaa536  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00aaa538  6689f2                 -mov dx, si
    cpu.dx = cpu.si;
    // 00aaa53b  83c302                 -add ebx, 2
    (cpu.ebx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00aaa53e  e80d250000             -call 0xaaca50
    cpu.esp -= 4;
    sub_aaca50(app, cpu);
    if (cpu.terminate) return;
    // 00aaa543  83f8ff                 +cmp eax, -1
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
    // 00aaa546  74e3                   -je 0xaaa52b
    if (cpu.flags.zf)
    {
        goto L_0x00aaa52b;
    }
    // 00aaa548  01c1                   +add ecx, eax
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
    // 00aaa54a  ebdf                   -jmp 0xaaa52b
    goto L_0x00aaa52b;
L_0x00aaa54c:
    // 00aaa54c  6626833b00             +cmp word ptr es:[ebx], 0
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
    // 00aaa551  741d                   -je 0xaaa570
    if (cpu.flags.zf)
    {
        goto L_0x00aaa570;
    }
    // 00aaa553  39f1                   +cmp ecx, esi
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
    // 00aaa555  7f19                   -jg 0xaaa570
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00aaa570;
    }
    // 00aaa557  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00aaa559  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00aaa55b  66268b13               -mov dx, word ptr es:[ebx]
    cpu.dx = app->getMemory<x86::reg16>(cpu.ees + cpu.ebx);
    // 00aaa55f  83c302                 -add ebx, 2
    (cpu.ebx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00aaa562  e8e9240000             -call 0xaaca50
    cpu.esp -= 4;
    sub_aaca50(app, cpu);
    if (cpu.terminate) return;
    // 00aaa567  83f8ff                 +cmp eax, -1
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
    // 00aaa56a  74e0                   -je 0xaaa54c
    if (cpu.flags.zf)
    {
        goto L_0x00aaa54c;
    }
    // 00aaa56c  01c1                   +add ecx, eax
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
    // 00aaa56e  ebdc                   -jmp 0xaaa54c
    goto L_0x00aaa54c;
L_0x00aaa570:
    // 00aaa570  39f1                   +cmp ecx, esi
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
    // 00aaa572  7f04                   -jg 0xaaa578
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00aaa578;
    }
L_0x00aaa574:
    // 00aaa574  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00aaa576  eb02                   -jmp 0xaaa57a
    goto L_0x00aaa57a;
L_0x00aaa578:
    // 00aaa578  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x00aaa57a:
    // 00aaa57a  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00aaa57d  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00aaa57e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aaa57f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aaa580  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_aaa584(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aaa584  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aaa585  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aaa586  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00aaa587  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00aaa588  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00aaa58b  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 00aaa58d  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 00aaa590  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
    // 00aaa595  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 00aaa597  e840250000             -call 0xaacadc
    cpu.esp -= 4;
    sub_aacadc(app, cpu);
    if (cpu.terminate) return;
    // 00aaa59c  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00aaa59d  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00aaa59f  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00aaa5a1  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00aaa5a3  49                     -dec ecx
    (cpu.ecx)--;
    // 00aaa5a4  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00aaa5a6  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00aaa5a8  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00aaa5aa  49                     -dec ecx
    (cpu.ecx)--;
    // 00aaa5ab  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00aaa5ac  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00aaa5af  48                     -dec eax
    (cpu.eax)--;
    // 00aaa5b0  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00aaa5b2  7415                   -je 0xaaa5c9
    if (cpu.flags.zf)
    {
        goto L_0x00aaa5c9;
    }
    // 00aaa5b4  89ee                   -mov esi, ebp
    cpu.esi = cpu.ebp;
    // 00aaa5b6  8d1c28                 -lea ebx, [eax + ebp]
    cpu.ebx = x86::reg32(cpu.eax + cpu.ebp * 1);
    // 00aaa5b9  8d1429                 -lea edx, [ecx + ebp]
    cpu.edx = x86::reg32(cpu.ecx + cpu.ebp * 1);
L_0x00aaa5bc:
    // 00aaa5bc  4b                     -dec ebx
    (cpu.ebx)--;
    // 00aaa5bd  8a4aff                 -mov cl, byte ptr [edx - 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 00aaa5c0  4a                     -dec edx
    (cpu.edx)--;
    // 00aaa5c1  48                     -dec eax
    (cpu.eax)--;
    // 00aaa5c2  884b01                 -mov byte ptr [ebx + 1], cl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(1) /* 0x1 */) = cpu.cl;
    // 00aaa5c5  39f2                   +cmp edx, esi
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
    // 00aaa5c7  75f3                   -jne 0xaaa5bc
    if (!cpu.flags.zf)
    {
        goto L_0x00aaa5bc;
    }
L_0x00aaa5c9:
    // 00aaa5c9  8d1428                 -lea edx, [eax + ebp]
    cpu.edx = x86::reg32(cpu.eax + cpu.ebp * 1);
L_0x00aaa5cc:
    // 00aaa5cc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aaa5ce  7c07                   -jl 0xaaa5d7
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00aaa5d7;
    }
    // 00aaa5d0  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00aaa5d1  c60230                 -mov byte ptr [edx], 0x30
    app->getMemory<x86::reg8>(cpu.edx) = 48 /*0x30*/;
    // 00aaa5d4  4a                     +dec edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00aaa5d5  ebf5                   -jmp 0xaaa5cc
    goto L_0x00aaa5cc;
L_0x00aaa5d7:
    // 00aaa5d7  032c24                 -add ebp, dword ptr [esp]
    (cpu.ebp) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp)));
    // 00aaa5da  c6450000               -mov byte ptr [ebp], 0
    app->getMemory<x86::reg8>(cpu.ebp) = 0 /*0x0*/;
    // 00aaa5de  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00aaa5e1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aaa5e2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aaa5e3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aaa5e4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aaa5e5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_aaa5de(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00aaa5de;
    // 00aaa584  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aaa585  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aaa586  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00aaa587  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00aaa588  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00aaa58b  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 00aaa58d  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 00aaa590  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
    // 00aaa595  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 00aaa597  e840250000             -call 0xaacadc
    cpu.esp -= 4;
    sub_aacadc(app, cpu);
    if (cpu.terminate) return;
    // 00aaa59c  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00aaa59d  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00aaa59f  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00aaa5a1  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00aaa5a3  49                     -dec ecx
    (cpu.ecx)--;
    // 00aaa5a4  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00aaa5a6  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00aaa5a8  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00aaa5aa  49                     -dec ecx
    (cpu.ecx)--;
    // 00aaa5ab  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00aaa5ac  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00aaa5af  48                     -dec eax
    (cpu.eax)--;
    // 00aaa5b0  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00aaa5b2  7415                   -je 0xaaa5c9
    if (cpu.flags.zf)
    {
        goto L_0x00aaa5c9;
    }
    // 00aaa5b4  89ee                   -mov esi, ebp
    cpu.esi = cpu.ebp;
    // 00aaa5b6  8d1c28                 -lea ebx, [eax + ebp]
    cpu.ebx = x86::reg32(cpu.eax + cpu.ebp * 1);
    // 00aaa5b9  8d1429                 -lea edx, [ecx + ebp]
    cpu.edx = x86::reg32(cpu.ecx + cpu.ebp * 1);
L_0x00aaa5bc:
    // 00aaa5bc  4b                     -dec ebx
    (cpu.ebx)--;
    // 00aaa5bd  8a4aff                 -mov cl, byte ptr [edx - 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 00aaa5c0  4a                     -dec edx
    (cpu.edx)--;
    // 00aaa5c1  48                     -dec eax
    (cpu.eax)--;
    // 00aaa5c2  884b01                 -mov byte ptr [ebx + 1], cl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(1) /* 0x1 */) = cpu.cl;
    // 00aaa5c5  39f2                   +cmp edx, esi
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
    // 00aaa5c7  75f3                   -jne 0xaaa5bc
    if (!cpu.flags.zf)
    {
        goto L_0x00aaa5bc;
    }
L_0x00aaa5c9:
    // 00aaa5c9  8d1428                 -lea edx, [eax + ebp]
    cpu.edx = x86::reg32(cpu.eax + cpu.ebp * 1);
L_0x00aaa5cc:
    // 00aaa5cc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aaa5ce  7c07                   -jl 0xaaa5d7
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00aaa5d7;
    }
    // 00aaa5d0  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00aaa5d1  c60230                 -mov byte ptr [edx], 0x30
    app->getMemory<x86::reg8>(cpu.edx) = 48 /*0x30*/;
    // 00aaa5d4  4a                     +dec edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00aaa5d5  ebf5                   -jmp 0xaaa5cc
    goto L_0x00aaa5cc;
L_0x00aaa5d7:
    // 00aaa5d7  032c24                 -add ebp, dword ptr [esp]
    (cpu.ebp) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp)));
    // 00aaa5da  c6450000               -mov byte ptr [ebp], 0
    app->getMemory<x86::reg8>(cpu.ebp) = 0 /*0x0*/;
L_entry_0x00aaa5de:
    // 00aaa5de  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00aaa5e1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aaa5e2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aaa5e3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aaa5e4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aaa5e5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void sub_aaa5e8(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aaa5e8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aaa5e9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aaa5ea  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00aaa5eb  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00aaa5ec  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00aaa5ef  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00aaa5f1  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 00aaa5f3  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 00aaa5f6  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00aaa5f8  7d0b                   -jge 0xaaa605
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00aaa605;
    }
    // 00aaa5fa  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
    // 00aaa5fc  8d4801                 -lea ecx, [eax + 1]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00aaa5ff  c6002d                 -mov byte ptr [eax], 0x2d
    app->getMemory<x86::reg8>(cpu.eax) = 45 /*0x2d*/;
    // 00aaa602  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
L_0x00aaa605:
    // 00aaa605  837e08ff               +cmp dword ptr [esi + 8], -1
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
    // 00aaa609  7507                   -jne 0xaaa612
    if (!cpu.flags.zf)
    {
        goto L_0x00aaa612;
    }
    // 00aaa60b  c7460804000000         -mov dword ptr [esi + 8], 4
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = 4 /*0x4*/;
L_0x00aaa612:
    // 00aaa612  bb0a000000             -mov ebx, 0xa
    cpu.ebx = 10 /*0xa*/;
    // 00aaa617  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00aaa619  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00aaa61b  668b442402             -mov ax, word ptr [esp + 2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(2) /* 0x2 */);
    // 00aaa620  e8b7240000             -call 0xaacadc
    cpu.esp -= 4;
    sub_aacadc(app, cpu);
    if (cpu.terminate) return;
    // 00aaa625  8a21                   -mov ah, byte ptr [ecx]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ecx);
    // 00aaa627  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00aaa629  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 00aaa62b  7408                   -je 0xaaa635
    if (cpu.flags.zf)
    {
        goto L_0x00aaa635;
    }
L_0x00aaa62d:
    // 00aaa62d  8a5101                 -mov dl, byte ptr [ecx + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 00aaa630  41                     -inc ecx
    (cpu.ecx)++;
    // 00aaa631  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 00aaa633  75f8                   -jne 0xaaa62d
    if (!cpu.flags.zf)
    {
        goto L_0x00aaa62d;
    }
L_0x00aaa635:
    // 00aaa635  837e0800               +cmp dword ptr [esi + 8], 0
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
    // 00aaa639  7432                   -je 0xaaa66d
    if (cpu.flags.zf)
    {
        goto L_0x00aaa66d;
    }
    // 00aaa63b  c6012e                 -mov byte ptr [ecx], 0x2e
    app->getMemory<x86::reg8>(cpu.ecx) = 46 /*0x2e*/;
    // 00aaa63e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00aaa640  8b6e08                 -mov ebp, dword ptr [esi + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00aaa643  41                     -inc ecx
    (cpu.ecx)++;
    // 00aaa644  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00aaa646  7e22                   -jle 0xaaa66a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00aaa66a;
    }
L_0x00aaa648:
    // 00aaa648  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00aaa64a  6689542402             -mov word ptr [esp + 2], dx
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(2) /* 0x2 */) = cpu.dx;
    // 00aaa64f  8b3c24                 -mov edi, dword ptr [esp]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    // 00aaa652  6bd70a                 -imul edx, edi, 0xa
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edi)) * x86::sreg64(x86::sreg32(10 /*0xa*/)));
    // 00aaa655  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 00aaa658  8a542402               -mov dl, byte ptr [esp + 2]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(2) /* 0x2 */);
    // 00aaa65c  80c230                 -add dl, 0x30
    (cpu.dl) += x86::reg8(x86::sreg8(48 /*0x30*/));
    // 00aaa65f  8811                   -mov byte ptr [ecx], dl
    app->getMemory<x86::reg8>(cpu.ecx) = cpu.dl;
    // 00aaa661  40                     -inc eax
    (cpu.eax)++;
    // 00aaa662  8b6e08                 -mov ebp, dword ptr [esi + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00aaa665  41                     -inc ecx
    (cpu.ecx)++;
    // 00aaa666  39e8                   +cmp eax, ebp
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
    // 00aaa668  7cde                   -jl 0xaaa648
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00aaa648;
    }
L_0x00aaa66a:
    // 00aaa66a  c60100                 -mov byte ptr [ecx], 0
    app->getMemory<x86::reg8>(cpu.ecx) = 0 /*0x0*/;
L_0x00aaa66d:
    // 00aaa66d  f644240180             +test byte ptr [esp + 1], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1) /* 0x1 */) & 128 /*0x80*/));
    // 00aaa672  0f8466ffffff           -je 0xaaa5de
    if (cpu.flags.zf)
    {
        return sub_aaa5de(app, cpu);
    }
L_0x00aaa678:
    // 00aaa678  39d9                   +cmp ecx, ebx
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
    // 00aaa67a  7541                   -jne 0xaaa6bd
    if (!cpu.flags.zf)
    {
        goto L_0x00aaa6bd;
    }
    // 00aaa67c  8d4b01                 -lea ecx, [ebx + 1]
    cpu.ecx = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 00aaa67f  c60331                 -mov byte ptr [ebx], 0x31
    app->getMemory<x86::reg8>(cpu.ebx) = 49 /*0x31*/;
    // 00aaa682  803930                 +cmp byte ptr [ecx], 0x30
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
    // 00aaa685  7508                   -jne 0xaaa68f
    if (!cpu.flags.zf)
    {
        goto L_0x00aaa68f;
    }
L_0x00aaa687:
    // 00aaa687  8a4101                 -mov al, byte ptr [ecx + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 00aaa68a  41                     -inc ecx
    (cpu.ecx)++;
    // 00aaa68b  3c30                   +cmp al, 0x30
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
    // 00aaa68d  74f8                   -je 0xaaa687
    if (cpu.flags.zf)
    {
        goto L_0x00aaa687;
    }
L_0x00aaa68f:
    // 00aaa68f  8a21                   -mov ah, byte ptr [ecx]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ecx);
    // 00aaa691  80fc2e                 +cmp ah, 0x2e
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
    // 00aaa694  7518                   -jne 0xaaa6ae
    if (!cpu.flags.zf)
    {
        goto L_0x00aaa6ae;
    }
    // 00aaa696  c60130                 -mov byte ptr [ecx], 0x30
    app->getMemory<x86::reg8>(cpu.ecx) = 48 /*0x30*/;
    // 00aaa699  41                     -inc ecx
    (cpu.ecx)++;
    // 00aaa69a  8821                   -mov byte ptr [ecx], ah
    app->getMemory<x86::reg8>(cpu.ecx) = cpu.ah;
    // 00aaa69c  8a5101                 -mov dl, byte ptr [ecx + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 00aaa69f  41                     -inc ecx
    (cpu.ecx)++;
    // 00aaa6a0  80fa30                 +cmp dl, 0x30
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
    // 00aaa6a3  7509                   -jne 0xaaa6ae
    if (!cpu.flags.zf)
    {
        goto L_0x00aaa6ae;
    }
L_0x00aaa6a5:
    // 00aaa6a5  8a7101                 -mov dh, byte ptr [ecx + 1]
    cpu.dh = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 00aaa6a8  41                     -inc ecx
    (cpu.ecx)++;
    // 00aaa6a9  80fe30                 +cmp dh, 0x30
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
    // 00aaa6ac  74f7                   -je 0xaaa6a5
    if (cpu.flags.zf)
    {
        goto L_0x00aaa6a5;
    }
L_0x00aaa6ae:
    // 00aaa6ae  c60130                 -mov byte ptr [ecx], 0x30
    app->getMemory<x86::reg8>(cpu.ecx) = 48 /*0x30*/;
    // 00aaa6b1  41                     -inc ecx
    (cpu.ecx)++;
    // 00aaa6b2  c60100                 -mov byte ptr [ecx], 0
    app->getMemory<x86::reg8>(cpu.ecx) = 0 /*0x0*/;
    // 00aaa6b5  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00aaa6b8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aaa6b9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aaa6ba  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aaa6bb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aaa6bc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00aaa6bd:
    // 00aaa6bd  8a51ff                 -mov dl, byte ptr [ecx - 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(-1) /* -0x1 */);
    // 00aaa6c0  49                     -dec ecx
    (cpu.ecx)--;
    // 00aaa6c1  80fa2e                 +cmp dl, 0x2e
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
    // 00aaa6c4  7501                   -jne 0xaaa6c7
    if (!cpu.flags.zf)
    {
        goto L_0x00aaa6c7;
    }
    // 00aaa6c6  49                     -dec ecx
    (cpu.ecx)--;
L_0x00aaa6c7:
    // 00aaa6c7  8a31                   -mov dh, byte ptr [ecx]
    cpu.dh = app->getMemory<x86::reg8>(cpu.ecx);
    // 00aaa6c9  80fe39                 +cmp dh, 0x39
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
    // 00aaa6cc  740e                   -je 0xaaa6dc
    if (cpu.flags.zf)
    {
        goto L_0x00aaa6dc;
    }
    // 00aaa6ce  88f3                   -mov bl, dh
    cpu.bl = cpu.dh;
    // 00aaa6d0  fec3                   -inc bl
    (cpu.bl)++;
    // 00aaa6d2  8819                   -mov byte ptr [ecx], bl
    app->getMemory<x86::reg8>(cpu.ecx) = cpu.bl;
    // 00aaa6d4  83c404                 +add esp, 4
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
    // 00aaa6d7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aaa6d8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aaa6d9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aaa6da  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aaa6db  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00aaa6dc:
    // 00aaa6dc  c60130                 -mov byte ptr [ecx], 0x30
    app->getMemory<x86::reg8>(cpu.ecx) = 48 /*0x30*/;
    // 00aaa6df  eb97                   -jmp 0xaaa678
    goto L_0x00aaa678;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_aaa6e4(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aaa6e4  ff153838ab00           -call dword ptr [0xab3838]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11221048) /* 0xab3838 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aaa6ea  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void sub_aaa6ec(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aaa6ec  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aaa6ed  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aaa6ee  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aaa6ef  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aaa6f0  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00aaa6f1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00aaa6f2  f6401e08               +test byte ptr [eax + 0x1e], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(30) /* 0x1e */) & 8 /*0x8*/));
    // 00aaa6f6  7530                   -jne 0xaaa728
    if (!cpu.flags.zf)
    {
        goto L_0x00aaa728;
    }
    // 00aaa6f8  80781630               +cmp byte ptr [eax + 0x16], 0x30
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
    // 00aaa6fc  752a                   -jne 0xaaa728
    if (!cpu.flags.zf)
    {
        goto L_0x00aaa728;
    }
    // 00aaa6fe  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00aaa701  8b5820                 -mov ebx, dword ptr [eax + 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 00aaa704  8b4824                 -mov ecx, dword ptr [eax + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 00aaa707  29da                   -sub edx, ebx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00aaa709  8b7028                 -mov esi, dword ptr [eax + 0x28]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */);
    // 00aaa70c  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00aaa70e  8b782c                 -mov edi, dword ptr [eax + 0x2c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(44) /* 0x2c */);
    // 00aaa711  29f2                   -sub edx, esi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00aaa713  8b6830                 -mov ebp, dword ptr [eax + 0x30]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(48) /* 0x30 */);
    // 00aaa716  29fa                   -sub edx, edi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edi));
    // 00aaa718  8b5834                 -mov ebx, dword ptr [eax + 0x34]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(52) /* 0x34 */);
    // 00aaa71b  29ea                   -sub edx, ebp
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 00aaa71d  29da                   -sub edx, ebx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00aaa71f  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00aaa721  7e05                   -jle 0xaaa728
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00aaa728;
    }
    // 00aaa723  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00aaa725  894824                 -mov dword ptr [eax + 0x24], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */) = cpu.ecx;
L_0x00aaa728:
    // 00aaa728  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aaa729  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aaa72a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aaa72b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aaa72c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aaa72d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aaa72e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void sub_aaa730(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aaa730  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aaa731  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00aaa732  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00aaa733  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00aaa734  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00aaa737  8ec2                   -mov es, edx
    cpu.es = cpu.edx;
    // 00aaa739  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00aaa73b  8b5328                 -mov edx, dword ptr [ebx + 0x28]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */);
    // 00aaa73e  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 00aaa740  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00aaa742  7e45                   -jle 0xaaa789
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00aaa789;
    }
L_0x00aaa744:
    // 00aaa744  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00aaa746  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00aaa748  66268b17               -mov dx, word ptr es:[edi]
    cpu.dx = app->getMemory<x86::reg16>(cpu.ees + cpu.edi);
    // 00aaa74c  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00aaa74f  e8fc220000             -call 0xaaca50
    cpu.esp -= 4;
    sub_aaca50(app, cpu);
    if (cpu.terminate) return;
    // 00aaa754  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00aaa756  83f8ff                 +cmp eax, -1
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
    // 00aaa759  740d                   -je 0xaaa768
    if (cpu.flags.zf)
    {
        goto L_0x00aaa768;
    }
    // 00aaa75b  3b4328                 +cmp eax, dword ptr [ebx + 0x28]
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
    // 00aaa75e  7f22                   -jg 0xaaa782
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00aaa782;
    }
    // 00aaa760  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
L_0x00aaa762:
    // 00aaa762  49                     -dec ecx
    (cpu.ecx)--;
    // 00aaa763  83f9ff                 +cmp ecx, -1
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
    // 00aaa766  7508                   -jne 0xaaa770
    if (!cpu.flags.zf)
    {
        goto L_0x00aaa770;
    }
L_0x00aaa768:
    // 00aaa768  837b2800               +cmp dword ptr [ebx + 0x28], 0
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
    // 00aaa76c  7fd6                   -jg 0xaaa744
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00aaa744;
    }
    // 00aaa76e  eb19                   -jmp 0xaaa789
    goto L_0x00aaa789;
L_0x00aaa770:
    // 00aaa770  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00aaa772  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00aaa774  8a16                   -mov dl, byte ptr [esi]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi);
    // 00aaa776  ffd5                   -call ebp
    cpu.ip = cpu.ebp;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aaa778  8b4328                 -mov eax, dword ptr [ebx + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */);
    // 00aaa77b  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00aaa77c  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00aaa77d  894328                 -mov dword ptr [ebx + 0x28], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 00aaa780  ebe0                   -jmp 0xaaa762
    goto L_0x00aaa762;
L_0x00aaa782:
    // 00aaa782  c7432800000000         -mov dword ptr [ebx + 0x28], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */) = 0 /*0x0*/;
L_0x00aaa789:
    // 00aaa789  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00aaa78c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aaa78d  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00aaa78e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aaa78f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aaa790  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_aaa794(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aaa794  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aaa795  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00aaa796  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00aaa797  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00aaa798  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00aaa79b  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00aaa79d  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00aaa79f  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00aaa7a1  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00aaa7a3  c7432000000000         -mov dword ptr [ebx + 0x20], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */) = 0 /*0x0*/;
    // 00aaa7aa  c7432400000000         -mov dword ptr [ebx + 0x24], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(36) /* 0x24 */) = 0 /*0x0*/;
    // 00aaa7b1  c7432800000000         -mov dword ptr [ebx + 0x28], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */) = 0 /*0x0*/;
    // 00aaa7b8  c7432c00000000         -mov dword ptr [ebx + 0x2c], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(44) /* 0x2c */) = 0 /*0x0*/;
    // 00aaa7bf  c7433000000000         -mov dword ptr [ebx + 0x30], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(48) /* 0x30 */) = 0 /*0x0*/;
    // 00aaa7c6  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 00aaa7c8  8a4315                 -mov al, byte ptr [ebx + 0x15]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(21) /* 0x15 */);
    // 00aaa7cb  c7433400000000         -mov dword ptr [ebx + 0x34], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(52) /* 0x34 */) = 0 /*0x0*/;
    // 00aaa7d2  3c69                   +cmp al, 0x69
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
    // 00aaa7d4  721e                   -jb 0xaaa7f4
    if (cpu.flags.cf)
    {
        goto L_0x00aaa7f4;
    }
    // 00aaa7d6  0f8692000000           -jbe 0xaaa86e
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00aaa86e;
    }
    // 00aaa7dc  3c75                   +cmp al, 0x75
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
    // 00aaa7de  720b                   -jb 0xaaa7eb
    if (cpu.flags.cf)
    {
        goto L_0x00aaa7eb;
    }
    // 00aaa7e0  7625                   -jbe 0xaaa807
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00aaa807;
    }
    // 00aaa7e2  3c78                   +cmp al, 0x78
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
    // 00aaa7e4  7421                   -je 0xaaa807
    if (cpu.flags.zf)
    {
        goto L_0x00aaa807;
    }
    // 00aaa7e6  e960010000             -jmp 0xaaa94b
    goto L_0x00aaa94b;
L_0x00aaa7eb:
    // 00aaa7eb  3c6f                   +cmp al, 0x6f
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
    // 00aaa7ed  7418                   -je 0xaaa807
    if (cpu.flags.zf)
    {
        goto L_0x00aaa807;
    }
    // 00aaa7ef  e957010000             -jmp 0xaaa94b
    goto L_0x00aaa94b;
L_0x00aaa7f4:
    // 00aaa7f4  3c58                   +cmp al, 0x58
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
    // 00aaa7f6  0f824f010000           -jb 0xaaa94b
    if (cpu.flags.cf)
    {
        goto L_0x00aaa94b;
    }
    // 00aaa7fc  7609                   -jbe 0xaaa807
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00aaa807;
    }
    // 00aaa7fe  3c64                   +cmp al, 0x64
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
    // 00aaa800  746c                   -je 0xaaa86e
    if (cpu.flags.zf)
    {
        goto L_0x00aaa86e;
    }
    // 00aaa802  e944010000             -jmp 0xaaa94b
    goto L_0x00aaa94b;
L_0x00aaa807:
    // 00aaa807  f6411f01               +test byte ptr [ecx + 0x1f], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(31) /* 0x1f */) & 1 /*0x1*/));
    // 00aaa80b  7420                   -je 0xaaa82d
    if (cpu.flags.zf)
    {
        goto L_0x00aaa82d;
    }
    // 00aaa80d  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 00aaa80f  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00aaa812  891a                   -mov dword ptr [edx], ebx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebx;
    // 00aaa814  8b43fc                 -mov eax, dword ptr [ebx - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-4) /* -0x4 */);
    // 00aaa817  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00aaa81a  8b2a                   -mov ebp, dword ptr [edx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx);
    // 00aaa81c  83c504                 +add ebp, 4
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
    // 00aaa81f  892a                   -mov dword ptr [edx], ebp
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebp;
    // 00aaa821  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00aaa824  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00aaa828  e91e010000             -jmp 0xaaa94b
    goto L_0x00aaa94b;
L_0x00aaa82d:
    // 00aaa82d  f6411e20               +test byte ptr [ecx + 0x1e], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */) & 32 /*0x20*/));
    // 00aaa831  7413                   -je 0xaaa846
    if (cpu.flags.zf)
    {
        goto L_0x00aaa846;
    }
    // 00aaa833  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 00aaa835  83c004                 +add eax, 4
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
    // 00aaa838  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 00aaa83a  8b40fc                 -mov eax, dword ptr [eax - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */);
    // 00aaa83d  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00aaa841  e905010000             -jmp 0xaaa94b
    goto L_0x00aaa94b;
L_0x00aaa846:
    // 00aaa846  8b2a                   -mov ebp, dword ptr [edx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx);
    // 00aaa848  83c504                 -add ebp, 4
    (cpu.ebp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00aaa84b  892a                   -mov dword ptr [edx], ebp
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebp;
    // 00aaa84d  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00aaa850  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00aaa854  f6411e10               +test byte ptr [ecx + 0x1e], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */) & 16 /*0x10*/));
    // 00aaa858  0f84ed000000           -je 0xaaa94b
    if (cpu.flags.zf)
    {
        goto L_0x00aaa94b;
    }
    // 00aaa85e  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00aaa860  668b442408             -mov ax, word ptr [esp + 8]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00aaa865  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00aaa869  e9dd000000             -jmp 0xaaa94b
    goto L_0x00aaa94b;
L_0x00aaa86e:
    // 00aaa86e  f6411f01               +test byte ptr [ecx + 0x1f], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(31) /* 0x1f */) & 1 /*0x1*/));
    // 00aaa872  741d                   -je 0xaaa891
    if (cpu.flags.zf)
    {
        goto L_0x00aaa891;
    }
    // 00aaa874  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 00aaa876  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00aaa879  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 00aaa87b  8b40fc                 -mov eax, dword ptr [eax - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */);
    // 00aaa87e  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00aaa881  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 00aaa883  83c304                 +add ebx, 4
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
    // 00aaa886  891a                   -mov dword ptr [edx], ebx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebx;
    // 00aaa888  8b43fc                 -mov eax, dword ptr [ebx - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-4) /* -0x4 */);
    // 00aaa88b  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00aaa88f  eb33                   -jmp 0xaaa8c4
    goto L_0x00aaa8c4;
L_0x00aaa891:
    // 00aaa891  f6411e20               +test byte ptr [ecx + 0x1e], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */) & 32 /*0x20*/));
    // 00aaa895  740c                   -je 0xaaa8a3
    if (cpu.flags.zf)
    {
        goto L_0x00aaa8a3;
    }
    // 00aaa897  8b2a                   -mov ebp, dword ptr [edx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx);
    // 00aaa899  83c504                 +add ebp, 4
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
    // 00aaa89c  892a                   -mov dword ptr [edx], ebp
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebp;
    // 00aaa89e  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00aaa8a1  eb1d                   -jmp 0xaaa8c0
    goto L_0x00aaa8c0;
L_0x00aaa8a3:
    // 00aaa8a3  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 00aaa8a5  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00aaa8a8  891a                   -mov dword ptr [edx], ebx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebx;
    // 00aaa8aa  8b43fc                 -mov eax, dword ptr [ebx - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-4) /* -0x4 */);
    // 00aaa8ad  8a791e                 -mov bh, byte ptr [ecx + 0x1e]
    cpu.bh = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */);
    // 00aaa8b0  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00aaa8b4  f6c710                 +test bh, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 16 /*0x10*/));
    // 00aaa8b7  740b                   -je 0xaaa8c4
    if (cpu.flags.zf)
    {
        goto L_0x00aaa8c4;
    }
    // 00aaa8b9  8b442406               -mov eax, dword ptr [esp + 6]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(6) /* 0x6 */);
    // 00aaa8bd  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
L_0x00aaa8c0:
    // 00aaa8c0  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
L_0x00aaa8c4:
    // 00aaa8c4  8a591f                 -mov bl, byte ptr [ecx + 0x1f]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(31) /* 0x1f */);
    // 00aaa8c7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00aaa8c9  f6c301                 +test bl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 1 /*0x1*/));
    // 00aaa8cc  7409                   -je 0xaaa8d7
    if (cpu.flags.zf)
    {
        goto L_0x00aaa8d7;
    }
    // 00aaa8ce  f644240780             +test byte ptr [esp + 7], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(7) /* 0x7 */) & 128 /*0x80*/));
    // 00aaa8d3  7409                   -je 0xaaa8de
    if (cpu.flags.zf)
    {
        goto L_0x00aaa8de;
    }
    // 00aaa8d5  eb0b                   -jmp 0xaaa8e2
    goto L_0x00aaa8e2;
L_0x00aaa8d7:
    // 00aaa8d7  837c240800             +cmp dword ptr [esp + 8], 0
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
    // 00aaa8dc  7c04                   -jl 0xaaa8e2
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00aaa8e2;
    }
L_0x00aaa8de:
    // 00aaa8de  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aaa8e0  7442                   -je 0xaaa924
    if (cpu.flags.zf)
    {
        goto L_0x00aaa924;
    }
L_0x00aaa8e2:
    // 00aaa8e2  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 00aaa8e5  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00aaa8e8  895920                 -mov dword ptr [ecx + 0x20], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.ebx;
    // 00aaa8eb  c604062d               -mov byte ptr [esi + eax], 0x2d
    app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1) = 45 /*0x2d*/;
    // 00aaa8ef  f6411f01               +test byte ptr [ecx + 0x1f], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(31) /* 0x1f */) & 1 /*0x1*/));
    // 00aaa8f3  7429                   -je 0xaaa91e
    if (cpu.flags.zf)
    {
        goto L_0x00aaa91e;
    }
    // 00aaa8f5  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 00aaa8f8  8b6c2404               -mov ebp, dword ptr [esp + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00aaa8fc  f7d3                   -not ebx
    cpu.ebx = ~cpu.ebx;
    // 00aaa8fe  f7d5                   -not ebp
    cpu.ebp = ~cpu.ebp;
    // 00aaa900  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 00aaa903  8d4301                 -lea eax, [ebx + 1]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 00aaa906  896c2404               -mov dword ptr [esp + 4], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 00aaa90a  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00aaa90d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aaa90f  7505                   -jne 0xaaa916
    if (!cpu.flags.zf)
    {
        goto L_0x00aaa916;
    }
    // 00aaa911  8d4501                 -lea eax, [ebp + 1]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(1) /* 0x1 */);
    // 00aaa914  eb02                   -jmp 0xaaa918
    goto L_0x00aaa918;
L_0x00aaa916:
    // 00aaa916  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
L_0x00aaa918:
    // 00aaa918  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00aaa91c  eb2d                   -jmp 0xaaa94b
    goto L_0x00aaa94b;
L_0x00aaa91e:
    // 00aaa91e  f75c2408               +neg dword ptr [esp + 8]
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
    // 00aaa922  eb27                   -jmp 0xaaa94b
    goto L_0x00aaa94b;
L_0x00aaa924:
    // 00aaa924  8a411e                 -mov al, byte ptr [ecx + 0x1e]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */);
    // 00aaa927  a804                   +test al, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 4 /*0x4*/));
    // 00aaa929  740f                   -je 0xaaa93a
    if (cpu.flags.zf)
    {
        goto L_0x00aaa93a;
    }
    // 00aaa92b  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 00aaa92e  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00aaa931  895920                 -mov dword ptr [ecx + 0x20], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.ebx;
    // 00aaa934  c604062b               -mov byte ptr [esi + eax], 0x2b
    app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1) = 43 /*0x2b*/;
    // 00aaa938  eb11                   -jmp 0xaaa94b
    goto L_0x00aaa94b;
L_0x00aaa93a:
    // 00aaa93a  a802                   +test al, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 2 /*0x2*/));
    // 00aaa93c  740d                   -je 0xaaa94b
    if (cpu.flags.zf)
    {
        goto L_0x00aaa94b;
    }
    // 00aaa93e  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 00aaa941  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00aaa944  895920                 -mov dword ptr [ecx + 0x20], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.ebx;
    // 00aaa947  c6040620               -mov byte ptr [esi + eax], 0x20
    app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1) = 32 /*0x20*/;
L_0x00aaa94b:
    // 00aaa94b  8a4115                 -mov al, byte ptr [ecx + 0x15]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(21) /* 0x15 */);
    // 00aaa94e  bb0a000000             -mov ebx, 0xa
    cpu.ebx = 10 /*0xa*/;
    // 00aaa953  3c64                   +cmp al, 0x64
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
    // 00aaa955  7261                   -jb 0xaaa9b8
    if (cpu.flags.cf)
    {
        goto L_0x00aaa9b8;
    }
    // 00aaa957  0f860b020000           -jbe 0xaaab68
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00aaab68;
    }
    // 00aaa95d  3c6f                   +cmp al, 0x6f
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
    // 00aaa95f  7238                   -jb 0xaaa999
    if (cpu.flags.cf)
    {
        goto L_0x00aaa999;
    }
    // 00aaa961  0f86e1010000           -jbe 0xaaab48
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00aaab48;
    }
    // 00aaa967  3c73                   +cmp al, 0x73
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
    // 00aaa969  7221                   -jb 0xaaa98c
    if (cpu.flags.cf)
    {
        goto L_0x00aaa98c;
    }
    // 00aaa96b  0f86f0000000           -jbe 0xaaaa61
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00aaaa61;
    }
    // 00aaa971  3c75                   +cmp al, 0x75
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
    // 00aaa973  0f8204040000           -jb 0xaaad7d
    if (cpu.flags.cf)
    {
        goto L_0x00aaad7d;
    }
    // 00aaa979  0f86e9010000           -jbe 0xaaab68
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00aaab68;
    }
    // 00aaa97f  3c78                   +cmp al, 0x78
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
    // 00aaa981  0f847c010000           -je 0xaaab03
    if (cpu.flags.zf)
    {
        goto L_0x00aaab03;
    }
    // 00aaa987  e9f1030000             -jmp 0xaaad7d
    goto L_0x00aaad7d;
L_0x00aaa98c:
    // 00aaa98c  3c70                   +cmp al, 0x70
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
    // 00aaa98e  0f8489020000           -je 0xaaac1d
    if (cpu.flags.zf)
    {
        goto L_0x00aaac1d;
    }
    // 00aaa994  e9e4030000             -jmp 0xaaad7d
    goto L_0x00aaad7d;
L_0x00aaa999:
    // 00aaa999  3c66                   +cmp al, 0x66
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
    // 00aaa99b  0f829d000000           -jb 0xaaaa3e
    if (cpu.flags.cf)
    {
        goto L_0x00aaaa3e;
    }
    // 00aaa9a1  7666                   -jbe 0xaaaa09
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00aaaa09;
    }
    // 00aaa9a3  3c67                   +cmp al, 0x67
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
    // 00aaa9a5  0f8693000000           -jbe 0xaaaa3e
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00aaaa3e;
    }
    // 00aaa9ab  3c69                   +cmp al, 0x69
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
    // 00aaa9ad  0f84b5010000           -je 0xaaab68
    if (cpu.flags.zf)
    {
        goto L_0x00aaab68;
    }
    // 00aaa9b3  e9c5030000             -jmp 0xaaad7d
    goto L_0x00aaad7d;
L_0x00aaa9b8:
    // 00aaa9b8  3c47                   +cmp al, 0x47
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
    // 00aaa9ba  7238                   -jb 0xaaa9f4
    if (cpu.flags.cf)
    {
        goto L_0x00aaa9f4;
    }
    // 00aaa9bc  0f867c000000           -jbe 0xaaaa3e
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00aaaa3e;
    }
    // 00aaa9c2  3c53                   +cmp al, 0x53
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
    // 00aaa9c4  7221                   -jb 0xaaa9e7
    if (cpu.flags.cf)
    {
        goto L_0x00aaa9e7;
    }
    // 00aaa9c6  0f8695000000           -jbe 0xaaaa61
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00aaaa61;
    }
    // 00aaa9cc  3c58                   +cmp al, 0x58
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
    // 00aaa9ce  0f82a9030000           -jb 0xaaad7d
    if (cpu.flags.cf)
    {
        goto L_0x00aaad7d;
    }
    // 00aaa9d4  0f8629010000           -jbe 0xaaab03
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00aaab03;
    }
    // 00aaa9da  3c63                   +cmp al, 0x63
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
    // 00aaa9dc  0f84ce020000           -je 0xaaacb0
    if (cpu.flags.zf)
    {
        goto L_0x00aaacb0;
    }
    // 00aaa9e2  e996030000             -jmp 0xaaad7d
    goto L_0x00aaad7d;
L_0x00aaa9e7:
    // 00aaa9e7  3c50                   +cmp al, 0x50
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
    // 00aaa9e9  0f842e020000           -je 0xaaac1d
    if (cpu.flags.zf)
    {
        goto L_0x00aaac1d;
    }
    // 00aaa9ef  e989030000             -jmp 0xaaad7d
    goto L_0x00aaad7d;
L_0x00aaa9f4:
    // 00aaa9f4  3c45                   +cmp al, 0x45
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
    // 00aaa9f6  7204                   -jb 0xaaa9fc
    if (cpu.flags.cf)
    {
        goto L_0x00aaa9fc;
    }
    // 00aaa9f8  7644                   -jbe 0xaaaa3e
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00aaaa3e;
    }
    // 00aaa9fa  eb0d                   -jmp 0xaaaa09
    goto L_0x00aaaa09;
L_0x00aaa9fc:
    // 00aaa9fc  3c43                   +cmp al, 0x43
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
    // 00aaa9fe  0f8438030000           -je 0xaaad3c
    if (cpu.flags.zf)
    {
        goto L_0x00aaad3c;
    }
    // 00aaaa04  e974030000             -jmp 0xaaad7d
    goto L_0x00aaad7d;
L_0x00aaaa09:
    // 00aaaa09  f6411e10               +test byte ptr [ecx + 0x1e], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */) & 16 /*0x10*/));
    // 00aaaa0d  742f                   -je 0xaaaa3e
    if (cpu.flags.zf)
    {
        goto L_0x00aaaa3e;
    }
    // 00aaaa0f  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 00aaaa11  83c304                 +add ebx, 4
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
    // 00aaaa14  891a                   -mov dword ptr [edx], ebx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebx;
    // 00aaaa16  8b43fc                 -mov eax, dword ptr [ebx - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-4) /* -0x4 */);
    // 00aaaa19  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00aaaa1d  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00aaaa1f  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00aaaa21  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00aaaa23  e8c0fbffff             -call 0xaaa5e8
    cpu.esp -= 4;
    sub_aaa5e8(app, cpu);
    if (cpu.terminate) return;
    // 00aaaa28  bbffffffff             -mov ebx, 0xffffffff
    cpu.ebx = 4294967295 /*0xffffffff*/;
    // 00aaaa2d  8cda                   -mov edx, ds
    cpu.edx = cpu.ds;
    // 00aaaa2f  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00aaaa31  e8befaffff             -call 0xaaa4f4
    cpu.esp -= 4;
    sub_aaa4f4(app, cpu);
    if (cpu.terminate) return;
    // 00aaaa36  894128                 -mov dword ptr [ecx + 0x28], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 00aaaa39  e952030000             -jmp 0xaaad90
    goto L_0x00aaad90;
L_0x00aaaa3e:
    // 00aaaa3e  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00aaaa40  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00aaaa42  e89dfcffff             -call 0xaaa6e4
    cpu.esp -= 4;
    sub_aaa6e4(app, cpu);
    if (cpu.terminate) return;
    // 00aaaa47  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00aaaa49  e89efcffff             -call 0xaaa6ec
    cpu.esp -= 4;
    sub_aaa6ec(app, cpu);
    if (cpu.terminate) return;
    // 00aaaa4e  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00aaaa50  8d7e01                 -lea edi, [esi + 1]
    cpu.edi = x86::reg32(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00aaaa53  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00aaaa55  8cc2                   -mov edx, es
    cpu.edx = cpu.es;
    // 00aaaa57  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00aaaa59  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00aaaa5c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aaaa5d  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00aaaa5e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aaaa5f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aaaa60  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00aaaa61:
    // 00aaaa61  c60600                 -mov byte ptr [esi], 0
    app->getMemory<x86::reg8>(cpu.esi) = 0 /*0x0*/;
    // 00aaaa64  8a411e                 -mov al, byte ptr [ecx + 0x1e]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */);
    // 00aaaa67  a880                   +test al, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 128 /*0x80*/));
    // 00aaaa69  741d                   -je 0xaaaa88
    if (cpu.flags.zf)
    {
        goto L_0x00aaaa88;
    }
    // 00aaaa6b  8b2a                   -mov ebp, dword ptr [edx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx);
    // 00aaaa6d  83c508                 -add ebp, 8
    (cpu.ebp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00aaaa70  892a                   -mov dword ptr [edx], ebp
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebp;
    // 00aaaa72  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00aaaa75  668b55fc               -mov dx, word ptr [ebp - 4]
    cpu.dx = app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00aaaa79  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aaaa7b  7505                   -jne 0xaaaa82
    if (!cpu.flags.zf)
    {
        goto L_0x00aaaa82;
    }
    // 00aaaa7d  6685d2                 +test dx, dx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.dx & cpu.dx));
    // 00aaaa80  742e                   -je 0xaaaab0
    if (cpu.flags.zf)
    {
        goto L_0x00aaaab0;
    }
L_0x00aaaa82:
    // 00aaaa82  8ec2                   -mov es, edx
    cpu.es = cpu.edx;
    // 00aaaa84  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00aaaa86  eb28                   -jmp 0xaaaab0
    goto L_0x00aaaab0;
L_0x00aaaa88:
    // 00aaaa88  a840                   +test al, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 64 /*0x40*/));
    // 00aaaa8a  7410                   -je 0xaaaa9c
    if (cpu.flags.zf)
    {
        goto L_0x00aaaa9c;
    }
    // 00aaaa8c  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx);
    // 00aaaa8e  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00aaaa91  8932                   -mov dword ptr [edx], esi
    app->getMemory<x86::reg32>(cpu.edx) = cpu.esi;
    // 00aaaa93  8b46fc                 -mov eax, dword ptr [esi - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-4) /* -0x4 */);
    // 00aaaa96  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aaaa98  7416                   -je 0xaaaab0
    if (cpu.flags.zf)
    {
        goto L_0x00aaaab0;
    }
    // 00aaaa9a  eb0e                   -jmp 0xaaaaaa
    goto L_0x00aaaaaa;
L_0x00aaaa9c:
    // 00aaaa9c  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 00aaaa9e  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00aaaaa1  891a                   -mov dword ptr [edx], ebx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebx;
    // 00aaaaa3  8b43fc                 -mov eax, dword ptr [ebx - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-4) /* -0x4 */);
    // 00aaaaa6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aaaaa8  7406                   -je 0xaaaab0
    if (cpu.flags.zf)
    {
        goto L_0x00aaaab0;
    }
L_0x00aaaaaa:
    // 00aaaaaa  8cda                   -mov edx, ds
    cpu.edx = cpu.ds;
    // 00aaaaac  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00aaaaae  8ec2                   -mov es, edx
    cpu.es = cpu.edx;
L_0x00aaaab0:
    // 00aaaab0  80791553               +cmp byte ptr [ecx + 0x15], 0x53
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
    // 00aaaab4  7508                   -jne 0xaaaabe
    if (!cpu.flags.zf)
    {
        goto L_0x00aaaabe;
    }
    // 00aaaab6  f6411e10               +test byte ptr [ecx + 0x1e], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */) & 16 /*0x10*/));
    // 00aaaaba  7408                   -je 0xaaaac4
    if (cpu.flags.zf)
    {
        goto L_0x00aaaac4;
    }
    // 00aaaabc  eb14                   -jmp 0xaaaad2
    goto L_0x00aaaad2;
L_0x00aaaabe:
    // 00aaaabe  f6411e20               +test byte ptr [ecx + 0x1e], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */) & 32 /*0x20*/));
    // 00aaaac2  740e                   -je 0xaaaad2
    if (cpu.flags.zf)
    {
        goto L_0x00aaaad2;
    }
L_0x00aaaac4:
    // 00aaaac4  8cc2                   -mov edx, es
    cpu.edx = cpu.es;
    // 00aaaac6  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00aaaac8  8b5908                 -mov ebx, dword ptr [ecx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00aaaacb  e848faffff             -call 0xaaa518
    cpu.esp -= 4;
    sub_aaa518(app, cpu);
    if (cpu.terminate) return;
    // 00aaaad0  eb0c                   -jmp 0xaaaade
    goto L_0x00aaaade;
L_0x00aaaad2:
    // 00aaaad2  8cc2                   -mov edx, es
    cpu.edx = cpu.es;
    // 00aaaad4  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00aaaad6  8b5908                 -mov ebx, dword ptr [ecx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00aaaad9  e816faffff             -call 0xaaa4f4
    cpu.esp -= 4;
    sub_aaa4f4(app, cpu);
    if (cpu.terminate) return;
L_0x00aaaade:
    // 00aaaade  8b5108                 -mov edx, dword ptr [ecx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00aaaae1  894128                 -mov dword ptr [ecx + 0x28], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 00aaaae4  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00aaaae6  0f8ca4020000           -jl 0xaaad90
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00aaad90;
    }
    // 00aaaaec  39d0                   +cmp eax, edx
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
    // 00aaaaee  0f8e9c020000           -jle 0xaaad90
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00aaad90;
    }
    // 00aaaaf4  895128                 -mov dword ptr [ecx + 0x28], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */) = cpu.edx;
    // 00aaaaf7  8cc2                   -mov edx, es
    cpu.edx = cpu.es;
    // 00aaaaf9  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00aaaafb  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00aaaafe  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aaaaff  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00aaab00  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aaab01  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aaab02  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00aaab03:
    // 00aaab03  f6411e01               +test byte ptr [ecx + 0x1e], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */) & 1 /*0x1*/));
    // 00aaab07  743a                   -je 0xaaab43
    if (cpu.flags.zf)
    {
        goto L_0x00aaab43;
    }
    // 00aaab09  f6411f01               +test byte ptr [ecx + 0x1f], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(31) /* 0x1f */) & 1 /*0x1*/));
    // 00aaab0d  740f                   -je 0xaaab1e
    if (cpu.flags.zf)
    {
        goto L_0x00aaab1e;
    }
    // 00aaab0f  833c2400               +cmp dword ptr [esp], 0
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
    // 00aaab13  7510                   -jne 0xaaab25
    if (!cpu.flags.zf)
    {
        goto L_0x00aaab25;
    }
    // 00aaab15  837c240400             +cmp dword ptr [esp + 4], 0
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
    // 00aaab1a  7427                   -je 0xaaab43
    if (cpu.flags.zf)
    {
        goto L_0x00aaab43;
    }
    // 00aaab1c  eb07                   -jmp 0xaaab25
    goto L_0x00aaab25;
L_0x00aaab1e:
    // 00aaab1e  837c240800             +cmp dword ptr [esp + 8], 0
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
    // 00aaab23  741e                   -je 0xaaab43
    if (cpu.flags.zf)
    {
        goto L_0x00aaab43;
    }
L_0x00aaab25:
    // 00aaab25  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 00aaab28  8d5001                 -lea edx, [eax + 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00aaab2b  895120                 -mov dword ptr [ecx + 0x20], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 00aaab2e  c6040630               -mov byte ptr [esi + eax], 0x30
    app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1) = 48 /*0x30*/;
    // 00aaab32  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 00aaab35  8d5001                 -lea edx, [eax + 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00aaab38  895120                 -mov dword ptr [ecx + 0x20], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 00aaab3b  8d1406                 -lea edx, [esi + eax]
    cpu.edx = x86::reg32(cpu.esi + cpu.eax * 1);
    // 00aaab3e  8a4115                 -mov al, byte ptr [ecx + 0x15]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(21) /* 0x15 */);
    // 00aaab41  8802                   -mov byte ptr [edx], al
    app->getMemory<x86::reg8>(cpu.edx) = cpu.al;
L_0x00aaab43:
    // 00aaab43  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
L_0x00aaab48:
    // 00aaab48  8079156f               +cmp byte ptr [ecx + 0x15], 0x6f
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
    // 00aaab4c  751a                   -jne 0xaaab68
    if (!cpu.flags.zf)
    {
        goto L_0x00aaab68;
    }
    // 00aaab4e  8a511e                 -mov dl, byte ptr [ecx + 0x1e]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */);
    // 00aaab51  bb08000000             -mov ebx, 8
    cpu.ebx = 8 /*0x8*/;
    // 00aaab56  f6c201                 +test dl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 1 /*0x1*/));
    // 00aaab59  740d                   -je 0xaaab68
    if (cpu.flags.zf)
    {
        goto L_0x00aaab68;
    }
    // 00aaab5b  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 00aaab5e  8d5001                 -lea edx, [eax + 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00aaab61  895120                 -mov dword ptr [ecx + 0x20], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 00aaab64  c6040630               -mov byte ptr [esi + eax], 0x30
    app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1) = 48 /*0x30*/;
L_0x00aaab68:
    // 00aaab68  8cda                   -mov edx, ds
    cpu.edx = cpu.ds;
    // 00aaab6a  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 00aaab6d  8ec2                   -mov es, edx
    cpu.es = cpu.edx;
    // 00aaab6f  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 00aaab71  8a711f                 -mov dh, byte ptr [ecx + 0x1f]
    cpu.dh = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(31) /* 0x1f */);
    // 00aaab74  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00aaab76  f6c601                 +test dh, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 1 /*0x1*/));
    // 00aaab79  7436                   -je 0xaaabb1
    if (cpu.flags.zf)
    {
        goto L_0x00aaabb1;
    }
    // 00aaab7b  83790800               +cmp dword ptr [ecx + 8], 0
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
    // 00aaab7f  7515                   -jne 0xaaab96
    if (!cpu.flags.zf)
    {
        goto L_0x00aaab96;
    }
    // 00aaab81  833c2400               +cmp dword ptr [esp], 0
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
    // 00aaab85  750f                   -jne 0xaaab96
    if (!cpu.flags.zf)
    {
        goto L_0x00aaab96;
    }
    // 00aaab87  837c240400             +cmp dword ptr [esp + 4], 0
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
    // 00aaab8c  7508                   -jne 0xaaab96
    if (!cpu.flags.zf)
    {
        goto L_0x00aaab96;
    }
    // 00aaab8e  26c60000               -mov byte ptr es:[eax], 0
    app->getMemory<x86::reg8>(cpu.ees + cpu.eax) = 0 /*0x0*/;
    // 00aaab92  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00aaab94  eb59                   -jmp 0xaaabef
    goto L_0x00aaabef;
L_0x00aaab96:
    // 00aaab96  8b5120                 -mov edx, dword ptr [ecx + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 00aaab99  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00aaab9b  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 00aaab9d  e85e1f0000             -call 0xaacb00
    cpu.esp -= 4;
    sub_aacb00(app, cpu);
    if (cpu.terminate) return;
    // 00aaaba2  80791558               +cmp byte ptr [ecx + 0x15], 0x58
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
    // 00aaaba6  7539                   -jne 0xaaabe1
    if (!cpu.flags.zf)
    {
        goto L_0x00aaabe1;
    }
    // 00aaaba8  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00aaabaa  e8ed010000             -call 0xaaad9c
    cpu.esp -= 4;
    sub_aaad9c(app, cpu);
    if (cpu.terminate) return;
    // 00aaabaf  eb30                   -jmp 0xaaabe1
    goto L_0x00aaabe1;
L_0x00aaabb1:
    // 00aaabb1  83790800               +cmp dword ptr [ecx + 8], 0
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
    // 00aaabb5  750f                   -jne 0xaaabc6
    if (!cpu.flags.zf)
    {
        goto L_0x00aaabc6;
    }
    // 00aaabb7  837c240800             +cmp dword ptr [esp + 8], 0
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
    // 00aaabbc  7508                   -jne 0xaaabc6
    if (!cpu.flags.zf)
    {
        goto L_0x00aaabc6;
    }
    // 00aaabbe  26c60000               -mov byte ptr es:[eax], 0
    app->getMemory<x86::reg8>(cpu.ees + cpu.eax) = 0 /*0x0*/;
    // 00aaabc2  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00aaabc4  eb29                   -jmp 0xaaabef
    goto L_0x00aaabef;
L_0x00aaabc6:
    // 00aaabc6  8b5120                 -mov edx, dword ptr [ecx + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 00aaabc9  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00aaabcd  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 00aaabcf  e81c200000             -call 0xaacbf0
    cpu.esp -= 4;
    sub_aacbf0(app, cpu);
    if (cpu.terminate) return;
    // 00aaabd4  80791558               +cmp byte ptr [ecx + 0x15], 0x58
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
    // 00aaabd8  7507                   -jne 0xaaabe1
    if (!cpu.flags.zf)
    {
        goto L_0x00aaabe1;
    }
    // 00aaabda  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00aaabdc  e8bb010000             -call 0xaaad9c
    cpu.esp -= 4;
    sub_aaad9c(app, cpu);
    if (cpu.terminate) return;
L_0x00aaabe1:
    // 00aaabe1  bbffffffff             -mov ebx, 0xffffffff
    cpu.ebx = 4294967295 /*0xffffffff*/;
    // 00aaabe6  8cc2                   -mov edx, es
    cpu.edx = cpu.es;
    // 00aaabe8  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00aaabea  e805f9ffff             -call 0xaaa4f4
    cpu.esp -= 4;
    sub_aaa4f4(app, cpu);
    if (cpu.terminate) return;
L_0x00aaabef:
    // 00aaabef  894128                 -mov dword ptr [ecx + 0x28], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 00aaabf2  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00aaabf4  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00aaabf7  39c2                   +cmp edx, eax
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
    // 00aaabf9  7d05                   -jge 0xaaac00
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00aaac00;
    }
    // 00aaabfb  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00aaabfd  894124                 -mov dword ptr [ecx + 0x24], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(36) /* 0x24 */) = cpu.eax;
L_0x00aaac00:
    // 00aaac00  837908ff               +cmp dword ptr [ecx + 8], -1
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
    // 00aaac04  0f8586010000           -jne 0xaaad90
    if (!cpu.flags.zf)
    {
        goto L_0x00aaad90;
    }
    // 00aaac0a  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00aaac0c  e8dbfaffff             -call 0xaaa6ec
    cpu.esp -= 4;
    sub_aaa6ec(app, cpu);
    if (cpu.terminate) return;
    // 00aaac11  8cc2                   -mov edx, es
    cpu.edx = cpu.es;
    // 00aaac13  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00aaac15  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00aaac18  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aaac19  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00aaac1a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aaac1b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aaac1c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00aaac1d:
    // 00aaac1d  83790400               +cmp dword ptr [ecx + 4], 0
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
    // 00aaac21  7516                   -jne 0xaaac39
    if (!cpu.flags.zf)
    {
        goto L_0x00aaac39;
    }
    // 00aaac23  f6411e80               +test byte ptr [ecx + 0x1e], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */) & 128 /*0x80*/));
    // 00aaac27  7409                   -je 0xaaac32
    if (cpu.flags.zf)
    {
        goto L_0x00aaac32;
    }
    // 00aaac29  c741040d000000         -mov dword ptr [ecx + 4], 0xd
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = 13 /*0xd*/;
    // 00aaac30  eb07                   -jmp 0xaaac39
    goto L_0x00aaac39;
L_0x00aaac32:
    // 00aaac32  c7410408000000         -mov dword ptr [ecx + 4], 8
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = 8 /*0x8*/;
L_0x00aaac39:
    // 00aaac39  80611ef9               -and byte ptr [ecx + 0x1e], 0xf9
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */) &= x86::reg8(x86::sreg8(249 /*0xf9*/));
    // 00aaac3d  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 00aaac3f  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00aaac42  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 00aaac44  8a591e                 -mov bl, byte ptr [ecx + 0x1e]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */);
    // 00aaac47  8b68fc                 -mov ebp, dword ptr [eax - 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */);
    // 00aaac4a  f6c380                 +test bl, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 128 /*0x80*/));
    // 00aaac4d  7429                   -je 0xaaac78
    if (cpu.flags.zf)
    {
        goto L_0x00aaac78;
    }
    // 00aaac4f  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00aaac52  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 00aaac54  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 00aaac59  8b40fc                 -mov eax, dword ptr [eax - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */);
    // 00aaac5c  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00aaac5e  25ffff0000             +and eax, 0xffff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/))));
    // 00aaac63  e81cf9ffff             -call 0xaaa584
    cpu.esp -= 4;
    sub_aaa584(app, cpu);
    if (cpu.terminate) return;
    // 00aaac68  bb08000000             -mov ebx, 8
    cpu.ebx = 8 /*0x8*/;
    // 00aaac6d  8d5605                 -lea edx, [esi + 5]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(5) /* 0x5 */);
    // 00aaac70  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00aaac72  c646043a               -mov byte ptr [esi + 4], 0x3a
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(4) /* 0x4 */) = 58 /*0x3a*/;
    // 00aaac76  eb09                   -jmp 0xaaac81
    goto L_0x00aaac81;
L_0x00aaac78:
    // 00aaac78  bb08000000             -mov ebx, 8
    cpu.ebx = 8 /*0x8*/;
    // 00aaac7d  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00aaac7f  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
L_0x00aaac81:
    // 00aaac81  e8fef8ffff             -call 0xaaa584
    cpu.esp -= 4;
    sub_aaa584(app, cpu);
    if (cpu.terminate) return;
    // 00aaac86  80791550               +cmp byte ptr [ecx + 0x15], 0x50
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
    // 00aaac8a  7507                   -jne 0xaaac93
    if (!cpu.flags.zf)
    {
        goto L_0x00aaac93;
    }
    // 00aaac8c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00aaac8e  e809010000             -call 0xaaad9c
    cpu.esp -= 4;
    sub_aaad9c(app, cpu);
    if (cpu.terminate) return;
L_0x00aaac93:
    // 00aaac93  bbffffffff             -mov ebx, 0xffffffff
    cpu.ebx = 4294967295 /*0xffffffff*/;
    // 00aaac98  8cc2                   -mov edx, es
    cpu.edx = cpu.es;
    // 00aaac9a  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00aaac9c  e853f8ffff             -call 0xaaa4f4
    cpu.esp -= 4;
    sub_aaa4f4(app, cpu);
    if (cpu.terminate) return;
    // 00aaaca1  894120                 -mov dword ptr [ecx + 0x20], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 00aaaca4  8cc2                   -mov edx, es
    cpu.edx = cpu.es;
    // 00aaaca6  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00aaaca8  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00aaacab  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aaacac  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00aaacad  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aaacae  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aaacaf  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00aaacb0:
    // 00aaacb0  8a591e                 -mov bl, byte ptr [ecx + 0x1e]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */);
    // 00aaacb3  c7412001000000         -mov dword ptr [ecx + 0x20], 1
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = 1 /*0x1*/;
    // 00aaacba  f6c320                 +test bl, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 32 /*0x20*/));
    // 00aaacbd  7465                   -je 0xaaad24
    if (cpu.flags.zf)
    {
        goto L_0x00aaad24;
    }
    // 00aaacbf  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 00aaacc1  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00aaacc4  891a                   -mov dword ptr [edx], ebx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebx;
    // 00aaacc6  668b43fc               -mov ax, word ptr [ebx - 4]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(-4) /* -0x4 */);
    // 00aaacca  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00aaaccc  6689c2                 -mov dx, ax
    cpu.dx = cpu.ax;
    // 00aaaccf  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00aaacd3  e8781d0000             -call 0xaaca50
    cpu.esp -= 4;
    sub_aaca50(app, cpu);
    if (cpu.terminate) return;
    // 00aaacd8  83f8ff                 +cmp eax, -1
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
    // 00aaacdb  0f84af000000           -je 0xaaad90
    if (cpu.flags.zf)
    {
        goto L_0x00aaad90;
    }
    // 00aaace1  8a44240c               -mov al, byte ptr [esp + 0xc]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00aaace5  8b2d505aab00           -mov ebp, dword ptr [0xab5a50]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(11229776) /* 0xab5a50 */);
    // 00aaaceb  8806                   -mov byte ptr [esi], al
    app->getMemory<x86::reg8>(cpu.esi) = cpu.al;
    // 00aaaced  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00aaacef  0f849b000000           -je 0xaaad90
    if (cpu.flags.zf)
    {
        goto L_0x00aaad90;
    }
    // 00aaacf5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00aaacf7  8a44240c               -mov al, byte ptr [esp + 0xc]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00aaacfb  8a80615aab00           -mov al, byte ptr [eax + 0xab5a61]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(11229793) /* 0xab5a61 */);
    // 00aaad01  2401                   -and al, 1
    cpu.al &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00aaad03  25ff000000             +and eax, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 00aaad08  0f8482000000           -je 0xaaad90
    if (cpu.flags.zf)
    {
        goto L_0x00aaad90;
    }
    // 00aaad0e  8a44240d               -mov al, byte ptr [esp + 0xd]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(13) /* 0xd */);
    // 00aaad12  884601                 -mov byte ptr [esi + 1], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00aaad15  ff4120                 -inc dword ptr [ecx + 0x20]
    (app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */))++;
    // 00aaad18  8cc2                   -mov edx, es
    cpu.edx = cpu.es;
    // 00aaad1a  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00aaad1c  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00aaad1f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aaad20  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00aaad21  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aaad22  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aaad23  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00aaad24:
    // 00aaad24  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 00aaad26  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00aaad29  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 00aaad2b  8a40fc                 -mov al, byte ptr [eax - 4]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(-4) /* -0x4 */);
    // 00aaad2e  8806                   -mov byte ptr [esi], al
    app->getMemory<x86::reg8>(cpu.esi) = cpu.al;
    // 00aaad30  8cc2                   -mov edx, es
    cpu.edx = cpu.es;
    // 00aaad32  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00aaad34  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00aaad37  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aaad38  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00aaad39  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aaad3a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aaad3b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00aaad3c:
    // 00aaad3c  8b2a                   -mov ebp, dword ptr [edx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx);
    // 00aaad3e  83c504                 -add ebp, 4
    (cpu.ebp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00aaad41  892a                   -mov dword ptr [edx], ebp
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebp;
    // 00aaad43  668b55fc               -mov dx, word ptr [ebp - 4]
    cpu.dx = app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00aaad47  81e2ffff0000           -and edx, 0xffff
    cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00aaad4d  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00aaad4f  e8fc1c0000             -call 0xaaca50
    cpu.esp -= 4;
    sub_aaca50(app, cpu);
    if (cpu.terminate) return;
    // 00aaad54  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00aaad56  83f8ff                 +cmp eax, -1
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
    // 00aaad59  740f                   -je 0xaaad6a
    if (cpu.flags.zf)
    {
        goto L_0x00aaad6a;
    }
    // 00aaad5b  894120                 -mov dword ptr [ecx + 0x20], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 00aaad5e  8cc2                   -mov edx, es
    cpu.edx = cpu.es;
    // 00aaad60  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00aaad62  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00aaad65  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aaad66  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00aaad67  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aaad68  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aaad69  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00aaad6a:
    // 00aaad6a  c7412000000000         -mov dword ptr [ecx + 0x20], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = 0 /*0x0*/;
    // 00aaad71  8cc2                   -mov edx, es
    cpu.edx = cpu.es;
    // 00aaad73  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00aaad75  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00aaad78  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aaad79  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00aaad7a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aaad7b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aaad7c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00aaad7d:
    // 00aaad7d  c7410400000000         -mov dword ptr [ecx + 4], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 00aaad84  8a4115                 -mov al, byte ptr [ecx + 0x15]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(21) /* 0x15 */);
    // 00aaad87  8806                   -mov byte ptr [esi], al
    app->getMemory<x86::reg8>(cpu.esi) = cpu.al;
    // 00aaad89  c7412001000000         -mov dword ptr [ecx + 0x20], 1
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = 1 /*0x1*/;
L_0x00aaad90:
    // 00aaad90  8cc2                   -mov edx, es
    cpu.edx = cpu.es;
    // 00aaad92  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00aaad94  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00aaad97  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aaad98  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00aaad99  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aaad9a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aaad9b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_aaad9c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aaad9c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aaad9d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aaad9e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00aaada0  803800                 +cmp byte ptr [eax], 0
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
    // 00aaada3  7413                   -je 0xaaadb8
    if (cpu.flags.zf)
    {
        goto L_0x00aaadb8;
    }
L_0x00aaada5:
    // 00aaada5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00aaada7  8a02                   -mov al, byte ptr [edx]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx);
    // 00aaada9  e8d21e0000             -call 0xaacc80
    cpu.esp -= 4;
    sub_aacc80(app, cpu);
    if (cpu.terminate) return;
    // 00aaadae  8802                   -mov byte ptr [edx], al
    app->getMemory<x86::reg8>(cpu.edx) = cpu.al;
    // 00aaadb0  8a5a01                 -mov bl, byte ptr [edx + 1]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 00aaadb3  42                     -inc edx
    (cpu.edx)++;
    // 00aaadb4  84db                   +test bl, bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.bl));
    // 00aaadb6  75ed                   -jne 0xaaada5
    if (!cpu.flags.zf)
    {
        goto L_0x00aaada5;
    }
L_0x00aaadb8:
    // 00aaadb8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aaadb9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aaadba  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void sub_aaadc0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aaadc0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aaadc1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aaadc2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aaadc3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00aaadc4  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00aaadc7  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00aaadc9  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00aaadcb  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00aaadcd  eb01                   -jmp 0xaaadd0
    goto L_0x00aaadd0;
L_0x00aaadcf:
    // 00aaadcf  42                     -inc edx
    (cpu.edx)++;
L_0x00aaadd0:
    // 00aaadd0  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00aaadd2  8a0b                   -mov cl, byte ptr [ebx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ebx);
    // 00aaadd4  40                     -inc eax
    (cpu.eax)++;
    // 00aaadd5  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 00aaadd7  75f6                   -jne 0xaaadcf
    if (!cpu.flags.zf)
    {
        goto L_0x00aaadcf;
    }
    // 00aaadd9  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00aaaddb  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00aaaddf  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00aaade0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aaade1  a10838ab00             -mov eax, dword ptr [0xab3808]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11221000) /* 0xab3808 */);
    // 00aaade6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00aaade7  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00aaadea  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aaadeb  2eff154014ab00         -call dword ptr cs:[0xab1440]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11211840) /* 0xab1440 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aaadf2  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00aaadf4  e9a3e0ffff             -jmp 0xaa8e9c
    return sub_aa8e9c(app, cpu);
}

/* align: skip 0x8d 0x40 0x00 */
void sub_aaadfc(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aaadfc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aaadfd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aaadfe  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00aaae00  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00aaae02  8cda                   -mov edx, ds
    cpu.edx = cpu.ds;
    // 00aaae04  e8871e0000             -call 0xaacc90
    cpu.esp -= 4;
    sub_aacc90(app, cpu);
    if (cpu.terminate) return;
    // 00aaae09  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aaae0b  7509                   -jne 0xaaae16
    if (!cpu.flags.zf)
    {
        goto L_0x00aaae16;
    }
    // 00aaae0d  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00aaae0f  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00aaae11  e8aaffffff             -call 0xaaadc0
    cpu.esp -= 4;
    sub_aaadc0(app, cpu);
    if (cpu.terminate) return;
L_0x00aaae16:
    // 00aaae16  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aaae17  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aaae18  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_aaae20(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aaae20  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aaae21  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aaae22  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aaae23  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aaae24  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00aaae25  ff15bc36ab00           -call dword ptr [0xab36bc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11220668) /* 0xab36bc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aaae2b  8b35b447ab00           -mov esi, dword ptr [0xab47b4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(11225012) /* 0xab47b4 */);
    // 00aaae31  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00aaae33  7419                   -je 0xaaae4e
    if (cpu.flags.zf)
    {
        goto L_0x00aaae4e;
    }
    // 00aaae35  8b4e04                 -mov ecx, dword ptr [esi + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00aaae38  8b790c                 -mov edi, dword ptr [ecx + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00aaae3b  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00aaae3d  81e703400000           -and edi, 0x4003
    cpu.edi &= x86::reg32(x86::sreg32(16387 /*0x4003*/));
    // 00aaae43  a3b447ab00             -mov dword ptr [0xab47b4], eax
    app->getMemory<x86::reg32>(x86::reg32(11225012) /* 0xab47b4 */) = cpu.eax;
    // 00aaae48  6683cf03               +or di, 3
    cpu.clear_co();
    cpu.set_szp((cpu.di |= x86::reg16(x86::sreg16(3 /*0x3*/))));
    // 00aaae4c  eb4d                   -jmp 0xaaae9b
    goto L_0x00aaae9b;
L_0x00aaae4e:
    // 00aaae4e  b96033ab00             -mov ecx, 0xab3360
    cpu.ecx = 11219808 /*0xab3360*/;
    // 00aaae53  81f96835ab00           +cmp ecx, 0xab3568
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(11220328 /*0xab3568*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00aaae59  7328                   -jae 0xaaae83
    if (!cpu.flags.cf)
    {
        goto L_0x00aaae83;
    }
L_0x00aaae5b:
    // 00aaae5b  f6410c03               +test byte ptr [ecx + 0xc], 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */) & 3 /*0x3*/));
    // 00aaae5f  7517                   -jne 0xaaae78
    if (!cpu.flags.zf)
    {
        goto L_0x00aaae78;
    }
    // 00aaae61  b81d000000             -mov eax, 0x1d
    cpu.eax = 29 /*0x1d*/;
    // 00aaae66  e845ceffff             -call 0xaa7cb0
    cpu.esp -= 4;
    sub_aa7cb0(app, cpu);
    if (cpu.terminate) return;
    // 00aaae6b  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00aaae6d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aaae6f  7458                   -je 0xaaaec9
    if (cpu.flags.zf)
    {
        goto L_0x00aaaec9;
    }
    // 00aaae71  bf03000000             -mov edi, 3
    cpu.edi = 3 /*0x3*/;
    // 00aaae76  eb23                   -jmp 0xaaae9b
    goto L_0x00aaae9b;
L_0x00aaae78:
    // 00aaae78  83c11a                 -add ecx, 0x1a
    (cpu.ecx) += x86::reg32(x86::sreg32(26 /*0x1a*/));
    // 00aaae7b  81f96835ab00           +cmp ecx, 0xab3568
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(11220328 /*0xab3568*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00aaae81  72d8                   -jb 0xaaae5b
    if (cpu.flags.cf)
    {
        goto L_0x00aaae5b;
    }
L_0x00aaae83:
    // 00aaae83  b837000000             -mov eax, 0x37
    cpu.eax = 55 /*0x37*/;
    // 00aaae88  bf03400000             -mov edi, 0x4003
    cpu.edi = 16387 /*0x4003*/;
    // 00aaae8d  e81eceffff             -call 0xaa7cb0
    cpu.esp -= 4;
    sub_aa7cb0(app, cpu);
    if (cpu.terminate) return;
    // 00aaae92  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00aaae94  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aaae96  7431                   -je 0xaaaec9
    if (cpu.flags.zf)
    {
        goto L_0x00aaaec9;
    }
    // 00aaae98  8d481d                 -lea ecx, [eax + 0x1d]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(29) /* 0x1d */);
L_0x00aaae9b:
    // 00aaae9b  bb1a000000             -mov ebx, 0x1a
    cpu.ebx = 26 /*0x1a*/;
    // 00aaaea0  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00aaaea2  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00aaaea4  e807ccffff             -call 0xaa7ab0
    cpu.esp -= 4;
    sub_aa7ab0(app, cpu);
    if (cpu.terminate) return;
    // 00aaaea9  89790c                 -mov dword ptr [ecx + 0xc], edi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.edi;
    // 00aaaeac  894e04                 -mov dword ptr [esi + 4], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 00aaaeaf  a1b047ab00             -mov eax, dword ptr [0xab47b0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11225008) /* 0xab47b0 */);
    // 00aaaeb4  897108                 -mov dword ptr [ecx + 8], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.esi;
    // 00aaaeb7  8935b047ab00           -mov dword ptr [0xab47b0], esi
    app->getMemory<x86::reg32>(x86::reg32(11225008) /* 0xab47b0 */) = cpu.esi;
    // 00aaaebd  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 00aaaebf  ff15c036ab00           -call dword ptr [0xab36c0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11220672) /* 0xab36c0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aaaec5  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00aaaec7  eb12                   -jmp 0xaaaedb
    goto L_0x00aaaedb;
L_0x00aaaec9:
    // 00aaaec9  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 00aaaece  e84d030000             -call 0xaab220
    cpu.esp -= 4;
    sub_aab220(app, cpu);
    if (cpu.terminate) return;
    // 00aaaed3  ff15c036ab00           -call dword ptr [0xab36c0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11220672) /* 0xab36c0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aaaed9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00aaaedb:
    // 00aaaedb  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aaaedc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aaaedd  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aaaede  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aaaedf  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aaaee0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_aaaee4(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aaaee4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aaaee5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aaaee6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aaaee7  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00aaaee9  bab047ab00             -mov edx, 0xab47b0
    cpu.edx = 11225008 /*0xab47b0*/;
L_0x00aaaeee:
    // 00aaaeee  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 00aaaef0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aaaef2  7425                   -je 0xaaaf19
    if (cpu.flags.zf)
    {
        goto L_0x00aaaf19;
    }
    // 00aaaef4  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00aaaef7  39cb                   +cmp ebx, ecx
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
    // 00aaaef9  7404                   -je 0xaaaeff
    if (cpu.flags.zf)
    {
        goto L_0x00aaaeff;
    }
    // 00aaaefb  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00aaaefd  ebef                   -jmp 0xaaaeee
    goto L_0x00aaaeee;
L_0x00aaaeff:
    // 00aaaeff  8a490c                 -mov cl, byte ptr [ecx + 0xc]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00aaaf02  80c903                 -or cl, 3
    cpu.cl |= x86::reg8(x86::sreg8(3 /*0x3*/));
    // 00aaaf05  884b0c                 -mov byte ptr [ebx + 0xc], cl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.cl;
    // 00aaaf08  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 00aaaf0a  891a                   -mov dword ptr [edx], ebx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebx;
    // 00aaaf0c  8b15b447ab00           -mov edx, dword ptr [0xab47b4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11225012) /* 0xab47b4 */);
    // 00aaaf12  a3b447ab00             -mov dword ptr [0xab47b4], eax
    app->getMemory<x86::reg32>(x86::reg32(11225012) /* 0xab47b4 */) = cpu.eax;
    // 00aaaf17  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
L_0x00aaaf19:
    // 00aaaf19  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aaaf1a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aaaf1b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aaaf1c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_aaaf20(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aaaf20  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aaaf21  833db447ab0000         +cmp dword ptr [0xab47b4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(11225012) /* 0xab47b4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00aaaf28  7416                   -je 0xaaaf40
    if (cpu.flags.zf)
    {
        goto L_0x00aaaf40;
    }
L_0x00aaaf2a:
    // 00aaaf2a  a1b447ab00             -mov eax, dword ptr [0xab47b4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11225012) /* 0xab47b4 */);
    // 00aaaf2f  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00aaaf31  e86aceffff             -call 0xaa7da0
    cpu.esp -= 4;
    sub_aa7da0(app, cpu);
    if (cpu.terminate) return;
    // 00aaaf36  8915b447ab00           -mov dword ptr [0xab47b4], edx
    app->getMemory<x86::reg32>(x86::reg32(11225012) /* 0xab47b4 */) = cpu.edx;
    // 00aaaf3c  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00aaaf3e  75ea                   -jne 0xaaaf2a
    if (!cpu.flags.zf)
    {
        goto L_0x00aaaf2a;
    }
L_0x00aaaf40:
    // 00aaaf40  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aaaf41  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_aaaf50(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aaaf50  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aaaf51  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aaaf52  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00aaaf54  ff15bc36ab00           -call dword ptr [0xab36bc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11220668) /* 0xab36bc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aaaf5a  a1b047ab00             -mov eax, dword ptr [0xab47b0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11225008) /* 0xab47b0 */);
    // 00aaaf5f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aaaf61  750e                   -jne 0xaaaf71
    if (!cpu.flags.zf)
    {
        goto L_0x00aaaf71;
    }
L_0x00aaaf63:
    // 00aaaf63  ff15c036ab00           -call dword ptr [0xab36c0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11220672) /* 0xab36c0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aaaf69  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00aaaf6e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aaaf6f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aaaf70  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00aaaf71:
    // 00aaaf71  3b5804                 +cmp ebx, dword ptr [eax + 4]
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
    // 00aaaf74  7408                   -je 0xaaaf7e
    if (cpu.flags.zf)
    {
        goto L_0x00aaaf7e;
    }
    // 00aaaf76  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00aaaf78  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aaaf7a  74e7                   -je 0xaaaf63
    if (cpu.flags.zf)
    {
        goto L_0x00aaaf63;
    }
    // 00aaaf7c  ebf3                   -jmp 0xaaaf71
    goto L_0x00aaaf71;
L_0x00aaaf7e:
    // 00aaaf7e  ff15c036ab00           -call dword ptr [0xab36c0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11220672) /* 0xab36c0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aaaf84  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00aaaf89  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00aaaf8b  e804000000             -call 0xaaaf94
    cpu.esp -= 4;
    sub_aaaf94(app, cpu);
    if (cpu.terminate) return;
    // 00aaaf90  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aaaf91  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aaaf92  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void sub_aaaf94(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aaaf94  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aaaf95  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00aaaf97  e8c8000000             -call 0xaab064
    cpu.esp -= 4;
    sub_aab064(app, cpu);
    if (cpu.terminate) return;
    // 00aaaf9c  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00aaaf9e  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00aaafa0  e83fffffff             -call 0xaaaee4
    cpu.esp -= 4;
    sub_aaaee4(app, cpu);
    if (cpu.terminate) return;
    // 00aaafa5  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00aaafa7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aaafa8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_aaafac(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aaafac  83c030                 -add eax, 0x30
    (cpu.eax) += x86::reg32(x86::sreg32(48 /*0x30*/));
    // 00aaafaf  83f839                 +cmp eax, 0x39
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
    // 00aaafb2  7e03                   -jle 0xaaafb7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00aaafb7;
    }
    // 00aaafb4  83c027                 -add eax, 0x27
    (cpu.eax) += x86::reg32(x86::sreg32(39 /*0x27*/));
L_0x00aaafb7:
    // 00aaafb7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_aaafb8(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aaafb8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aaafb9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aaafba  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aaafbb  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00aaafbc  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00aaafbd  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00aaafc0  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00aaafc2  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 00aaafc5  e8f61c0000             -call 0xaaccc0
    cpu.esp -= 4;
    sub_aaccc0(app, cpu);
    if (cpu.terminate) return;
    // 00aaafca  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00aaafcc  c1eb10                 -shr ebx, 0x10
    cpu.ebx >>= 16 /*0x10*/ % 32;
    // 00aaafcf  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 00aaafd1  09c3                   -or ebx, eax
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.eax));
    // 00aaafd3  e8081e0000             -call 0xaacde0
    cpu.esp -= 4;
    sub_aacde0(app, cpu);
    if (cpu.terminate) return;
    // 00aaafd8  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00aaafda  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x00aaafdb:
    // 00aaafdb  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00aaafdd  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00aaafdf  3c00                   +cmp al, 0
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
    // 00aaafe1  7410                   -je 0xaaaff3
    if (cpu.flags.zf)
    {
        goto L_0x00aaaff3;
    }
    // 00aaafe3  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00aaafe6  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00aaafe9  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00aaafec  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00aaafef  3c00                   +cmp al, 0
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
    // 00aaaff1  75e8                   -jne 0xaaafdb
    if (!cpu.flags.zf)
    {
        goto L_0x00aaafdb;
    }
L_0x00aaaff3:
    // 00aaaff3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aaaff4  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00aaaff5  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00aaaff7  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00aaaff9  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00aaaffb  49                     -dec ecx
    (cpu.ecx)--;
    // 00aaaffc  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00aaaffe  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00aab000  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00aab002  49                     -dec ecx
    (cpu.ecx)--;
    // 00aab003  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00aab004  8d3429                 -lea esi, [ecx + ebp]
    cpu.esi = x86::reg32(cpu.ecx + cpu.ebp * 1);
    // 00aab007  8d5604                 -lea edx, [esi + 4]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00aab00a  c60674                 -mov byte ptr [esi], 0x74
    app->getMemory<x86::reg8>(cpu.esi) = 116 /*0x74*/;
    // 00aab00d  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
L_0x00aab00f:
    // 00aab00f  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00aab011  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00aab014  4a                     -dec edx
    (cpu.edx)--;
    // 00aab015  e892ffffff             -call 0xaaafac
    cpu.esp -= 4;
    sub_aaafac(app, cpu);
    if (cpu.terminate) return;
    // 00aab01a  c1eb04                 -shr ebx, 4
    cpu.ebx >>= 4 /*0x4*/ % 32;
    // 00aab01d  884201                 -mov byte ptr [edx + 1], al
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00aab020  39ca                   +cmp edx, ecx
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
    // 00aab022  75eb                   -jne 0xaab00f
    if (!cpu.flags.zf)
    {
        goto L_0x00aab00f;
    }
    // 00aab024  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00aab027  c1f804                 -sar eax, 4
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (4 /*0x4*/ % 32));
    // 00aab02a  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00aab02d  c646055f               -mov byte ptr [esi + 5], 0x5f
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(5) /* 0x5 */) = 95 /*0x5f*/;
    // 00aab031  e876ffffff             -call 0xaaafac
    cpu.esp -= 4;
    sub_aaafac(app, cpu);
    if (cpu.terminate) return;
    // 00aab036  884606                 -mov byte ptr [esi + 6], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(6) /* 0x6 */) = cpu.al;
    // 00aab039  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00aab03c  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00aab03f  e868ffffff             -call 0xaaafac
    cpu.esp -= 4;
    sub_aaafac(app, cpu);
    if (cpu.terminate) return;
    // 00aab044  c646082e               -mov byte ptr [esi + 8], 0x2e
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */) = 46 /*0x2e*/;
    // 00aab048  c6460974               -mov byte ptr [esi + 9], 0x74
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(9) /* 0x9 */) = 116 /*0x74*/;
    // 00aab04c  c6460a6d               -mov byte ptr [esi + 0xa], 0x6d
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(10) /* 0xa */) = 109 /*0x6d*/;
    // 00aab050  c6460b70               -mov byte ptr [esi + 0xb], 0x70
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(11) /* 0xb */) = 112 /*0x70*/;
    // 00aab054  c6460c00               -mov byte ptr [esi + 0xc], 0
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 00aab058  884607                 -mov byte ptr [esi + 7], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(7) /* 0x7 */) = cpu.al;
    // 00aab05b  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00aab05e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aab05f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aab060  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aab061  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aab062  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aab063  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_aab064(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aab064  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aab065  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aab066  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aab067  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00aab068  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00aab069  81ec14010000           -sub esp, 0x114
    (cpu.esp) -= x86::reg32(x86::sreg32(276 /*0x114*/));
    // 00aab06f  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00aab071  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00aab073  83780c00               +cmp dword ptr [eax + 0xc], 0
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
    // 00aab077  750a                   -jne 0xaab083
    if (!cpu.flags.zf)
    {
        goto L_0x00aab083;
    }
    // 00aab079  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00aab07e  e997000000             -jmp 0xaab11a
    goto L_0x00aab11a;
L_0x00aab083:
    // 00aab083  8a600d                 -mov ah, byte ptr [eax + 0xd]
    cpu.ah = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(13) /* 0xd */);
    // 00aab086  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00aab088  f6c410                 +test ah, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 16 /*0x10*/));
    // 00aab08b  7409                   -je 0xaab096
    if (cpu.flags.zf)
    {
        goto L_0x00aab096;
    }
    // 00aab08d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00aab08f  e8ecd9ffff             -call 0xaa8a80
    cpu.esp -= 4;
    sub_aa8a80(app, cpu);
    if (cpu.terminate) return;
    // 00aab094  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
L_0x00aab096:
    // 00aab096  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00aab099  ff15ac36ab00           -call dword ptr [0xab36ac]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11220652) /* 0xab36ac */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aab09f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00aab0a1  e80a1e0000             -call 0xaaceb0
    cpu.esp -= 4;
    sub_aaceb0(app, cpu);
    if (cpu.terminate) return;
    // 00aab0a6  83f8ff                 +cmp eax, -1
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
    // 00aab0a9  740e                   -je 0xaab0b9
    if (cpu.flags.zf)
    {
        goto L_0x00aab0b9;
    }
    // 00aab0ab  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00aab0ad  8b6910                 -mov ebp, dword ptr [ecx + 0x10]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00aab0b0  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00aab0b2  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00aab0b4  e8c7010000             -call 0xaab280
    cpu.esp -= 4;
    sub_aab280(app, cpu);
    if (cpu.terminate) return;
L_0x00aab0b9:
    // 00aab0b9  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00aab0bb  740a                   -je 0xaab0c7
    if (cpu.flags.zf)
    {
        goto L_0x00aab0c7;
    }
    // 00aab0bd  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00aab0c0  e84b1e0000             -call 0xaacf10
    cpu.esp -= 4;
    sub_aacf10(app, cpu);
    if (cpu.terminate) return;
    // 00aab0c5  09c6                   -or esi, eax
    cpu.esi |= x86::reg32(x86::sreg32(cpu.eax));
L_0x00aab0c7:
    // 00aab0c7  f6410c08               +test byte ptr [ecx + 0xc], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */) & 8 /*0x8*/));
    // 00aab0cb  7415                   -je 0xaab0e2
    if (cpu.flags.zf)
    {
        goto L_0x00aab0e2;
    }
    // 00aab0cd  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00aab0d0  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00aab0d3  e8c8ccffff             -call 0xaa7da0
    cpu.esp -= 4;
    sub_aa7da0(app, cpu);
    if (cpu.terminate) return;
    // 00aab0d8  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00aab0db  c7400800000000         -mov dword ptr [eax + 8], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
L_0x00aab0e2:
    // 00aab0e2  f6410d08               +test byte ptr [ecx + 0xd], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(13) /* 0xd */) & 8 /*0x8*/));
    // 00aab0e6  741a                   -je 0xaab102
    if (cpu.flags.zf)
    {
        goto L_0x00aab102;
    }
    // 00aab0e8  8b5108                 -mov edx, dword ptr [ecx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00aab0eb  8a5214                 -mov dl, byte ptr [edx + 0x14]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(20) /* 0x14 */);
    // 00aab0ee  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00aab0f0  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00aab0f6  e8bdfeffff             -call 0xaaafb8
    cpu.esp -= 4;
    sub_aaafb8(app, cpu);
    if (cpu.terminate) return;
    // 00aab0fb  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00aab0fd  e89e1e0000             -call 0xaacfa0
    cpu.esp -= 4;
    sub_aacfa0(app, cpu);
    if (cpu.terminate) return;
L_0x00aab102:
    // 00aab102  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00aab105  ff15b036ab00           -call dword ptr [0xab36b0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11220656) /* 0xab36b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aab10b  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00aab10d  7409                   -je 0xaab118
    if (cpu.flags.zf)
    {
        goto L_0x00aab118;
    }
    // 00aab10f  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00aab112  ff15b836ab00           -call dword ptr [0xab36b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11220664) /* 0xab36b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00aab118:
    // 00aab118  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x00aab11a:
    // 00aab11a  81c414010000           -add esp, 0x114
    (cpu.esp) += x86::reg32(x86::sreg32(276 /*0x114*/));
    // 00aab120  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aab121  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aab122  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aab123  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aab124  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aab125  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_aab130(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aab130  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aab131  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aab132  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00aab133  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00aab134  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00aab137  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00aab139  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00aab13b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aab13d  7c08                   -jl 0xaab147
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00aab147;
    }
    // 00aab13f  3b05043aab00           +cmp eax, dword ptr [0xab3a04]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(11221508) /* 0xab3a04 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00aab145  7614                   -jbe 0xaab15b
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00aab15b;
    }
L_0x00aab147:
    // 00aab147  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 00aab14c  e8cf000000             -call 0xaab220
    cpu.esp -= 4;
    sub_aab220(app, cpu);
    if (cpu.terminate) return;
    // 00aab151  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00aab156  e9b8000000             -jmp 0xaab213
    goto L_0x00aab213;
L_0x00aab15b:
    // 00aab15b  8b2d0838ab00           -mov ebp, dword ptr [0xab3808]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(11221000) /* 0xab3808 */);
    // 00aab161  8b6cb500               -mov ebp, dword ptr [ebp + esi*4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + cpu.esi * 4);
    // 00aab165  ff15ac36ab00           -call dword ptr [0xab36ac]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11220652) /* 0xab36ac */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aab16b  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00aab16d  e83e1e0000             -call 0xaacfb0
    cpu.esp -= 4;
    sub_aacfb0(app, cpu);
    if (cpu.terminate) return;
    // 00aab172  a880                   +test al, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 128 /*0x80*/));
    // 00aab174  7428                   -je 0xaab19e
    if (cpu.flags.zf)
    {
        goto L_0x00aab19e;
    }
    // 00aab176  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00aab178  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00aab17a  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00aab17c  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00aab17d  2eff150814ab00         -call dword ptr cs:[0xab1408]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11211784) /* 0xab1408 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aab184  83f8ff                 +cmp eax, -1
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
    // 00aab187  7515                   -jne 0xaab19e
    if (!cpu.flags.zf)
    {
        goto L_0x00aab19e;
    }
    // 00aab189  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00aab18b  ff15b036ab00           -call dword ptr [0xab36b0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11220656) /* 0xab36b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aab191  e80e1f0000             -call 0xaad0a4
    cpu.esp -= 4;
    sub_aad0a4(app, cpu);
    if (cpu.terminate) return;
    // 00aab196  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00aab199  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aab19a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aab19b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aab19c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aab19d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00aab19e:
    // 00aab19e  833d2037ab0000         +cmp dword ptr [0xab3720], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(11220768) /* 0xab3720 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00aab1a5  7428                   -je 0xaab1cf
    if (cpu.flags.zf)
    {
        goto L_0x00aab1cf;
    }
    // 00aab1a7  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00aab1a9  ff15f436ab00           -call dword ptr [0xab36f4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11220724) /* 0xab36f4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aab1af  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aab1b1  741c                   -je 0xaab1cf
    if (cpu.flags.zf)
    {
        goto L_0x00aab1cf;
    }
    // 00aab1b3  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00aab1b5  ff152037ab00           -call dword ptr [0xab3720]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11220768) /* 0xab3720 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aab1bb  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00aab1bd  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00aab1bf  ff15b036ab00           -call dword ptr [0xab36b0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11220656) /* 0xab36b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aab1c5  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00aab1c7  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00aab1ca  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aab1cb  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aab1cc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aab1cd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aab1ce  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00aab1cf:
    // 00aab1cf  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00aab1d1  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00aab1d5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00aab1d6  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aab1d7  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00aab1d8  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00aab1d9  2eff154014ab00         -call dword ptr cs:[0xab1440]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11211840) /* 0xab1440 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aab1e0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aab1e2  7515                   -jne 0xaab1f9
    if (!cpu.flags.zf)
    {
        goto L_0x00aab1f9;
    }
    // 00aab1e4  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00aab1e6  ff15b036ab00           -call dword ptr [0xab36b0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11220656) /* 0xab36b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aab1ec  e8b31e0000             -call 0xaad0a4
    cpu.esp -= 4;
    sub_aad0a4(app, cpu);
    if (cpu.terminate) return;
    // 00aab1f1  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00aab1f4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aab1f5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aab1f6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aab1f7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aab1f8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00aab1f9:
    // 00aab1f9  3b1c24                 +cmp ebx, dword ptr [esp]
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
    // 00aab1fc  740a                   -je 0xaab208
    if (cpu.flags.zf)
    {
        goto L_0x00aab208;
    }
    // 00aab1fe  b80c000000             -mov eax, 0xc
    cpu.eax = 12 /*0xc*/;
    // 00aab203  e818000000             -call 0xaab220
    cpu.esp -= 4;
    sub_aab220(app, cpu);
    if (cpu.terminate) return;
L_0x00aab208:
    // 00aab208  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00aab20a  ff15b036ab00           -call dword ptr [0xab36b0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11220656) /* 0xab36b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aab210  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
L_0x00aab213:
    // 00aab213  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00aab216  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aab217  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aab218  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aab219  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aab21a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void sub_aab220(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aab220  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aab221  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00aab223  ff15a836ab00           -call dword ptr [0xab36a8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11220648) /* 0xab36a8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aab229  895004                 -mov dword ptr [eax + 4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00aab22c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aab22d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void sub_aab230(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aab230  b80d000000             -mov eax, 0xd
    cpu.eax = 13 /*0xd*/;
    // 00aab235  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aab236  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00aab238  ff15a836ab00           -call dword ptr [0xab36a8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11220648) /* 0xab36a8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aab23e  895004                 -mov dword ptr [eax + 4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00aab241  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aab242  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void sub_aab244(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aab244  b80e000000             -mov eax, 0xe
    cpu.eax = 14 /*0xe*/;
    // 00aab249  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aab24a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00aab24c  ff15a836ab00           -call dword ptr [0xab36a8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11220648) /* 0xab36a8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aab252  895004                 -mov dword ptr [eax + 4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00aab255  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aab256  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void sub_aab258(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aab258  b809000000             -mov eax, 9
    cpu.eax = 9 /*0x9*/;
    // 00aab25d  e8beffffff             -call 0xaab220
    cpu.esp -= 4;
    sub_aab220(app, cpu);
    if (cpu.terminate) return;
    // 00aab262  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00aab267  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_aab268(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aab268  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aab269  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00aab26b  ff15a836ab00           -call dword ptr [0xab36a8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11220648) /* 0xab36a8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aab271  895008                 -mov dword ptr [eax + 8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00aab274  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aab275  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_aab280(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aab280  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aab281  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aab282  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00aab284  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00aab286  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aab288  7c08                   -jl 0xaab292
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00aab292;
    }
    // 00aab28a  3b05043aab00           +cmp eax, dword ptr [0xab3a04]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(11221508) /* 0xab3a04 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00aab290  7612                   -jbe 0xaab2a4
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00aab2a4;
    }
L_0x00aab292:
    // 00aab292  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 00aab297  e884ffffff             -call 0xaab220
    cpu.esp -= 4;
    sub_aab220(app, cpu);
    if (cpu.terminate) return;
    // 00aab29c  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00aab2a1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aab2a2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aab2a3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00aab2a4:
    // 00aab2a4  ff15ac36ab00           -call dword ptr [0xab36ac]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11220652) /* 0xab36ac */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aab2aa  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00aab2ac  e8ff1c0000             -call 0xaacfb0
    cpu.esp -= 4;
    sub_aacfb0(app, cpu);
    if (cpu.terminate) return;
    // 00aab2b1  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00aab2b3  7e10                   -jle 0xaab2c5
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00aab2c5;
    }
    // 00aab2b5  a880                   +test al, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 128 /*0x80*/));
    // 00aab2b7  750c                   -jne 0xaab2c5
    if (!cpu.flags.zf)
    {
        goto L_0x00aab2c5;
    }
    // 00aab2b9  80cc80                 -or ah, 0x80
    cpu.ah |= x86::reg8(x86::sreg8(128 /*0x80*/));
    // 00aab2bc  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00aab2be  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00aab2c0  e8431d0000             -call 0xaad008
    cpu.esp -= 4;
    sub_aad008(app, cpu);
    if (cpu.terminate) return;
L_0x00aab2c5:
    // 00aab2c5  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aab2c6  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00aab2c8  8b150838ab00           -mov edx, dword ptr [0xab3808]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11221000) /* 0xab3808 */);
    // 00aab2ce  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aab2cf  8b04b2                 -mov eax, dword ptr [edx + esi*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.esi * 4);
    // 00aab2d2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00aab2d3  2eff150814ab00         -call dword ptr cs:[0xab1408]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11211784) /* 0xab1408 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aab2da  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00aab2dc  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00aab2de  ff15b036ab00           -call dword ptr [0xab36b0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11220656) /* 0xab36b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aab2e4  83f9ff                 +cmp ecx, -1
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
    // 00aab2e7  7505                   -jne 0xaab2ee
    if (!cpu.flags.zf)
    {
        goto L_0x00aab2ee;
    }
    // 00aab2e9  e8b61d0000             -call 0xaad0a4
    cpu.esp -= 4;
    sub_aad0a4(app, cpu);
    if (cpu.terminate) return;
L_0x00aab2ee:
    // 00aab2ee  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00aab2f0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aab2f1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aab2f2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_aab300(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aab300  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aab301  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aab302  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aab303  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aab304  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00aab306  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00aab308  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aab30a  7c08                   -jl 0xaab314
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00aab314;
    }
    // 00aab30c  3b05043aab00           +cmp eax, dword ptr [0xab3a04]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(11221508) /* 0xab3a04 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00aab312  7614                   -jbe 0xaab328
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00aab328;
    }
L_0x00aab314:
    // 00aab314  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 00aab319  e802ffffff             -call 0xaab220
    cpu.esp -= 4;
    sub_aab220(app, cpu);
    if (cpu.terminate) return;
    // 00aab31e  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00aab323  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aab324  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aab325  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aab326  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aab327  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00aab328:
    // 00aab328  ff15ac36ab00           -call dword ptr [0xab36ac]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11220652) /* 0xab36ac */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aab32e  a10838ab00             -mov eax, dword ptr [0xab3808]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11221000) /* 0xab3808 */);
    // 00aab333  8b0498                 -mov eax, dword ptr [eax + ebx*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + cpu.ebx * 4);
    // 00aab336  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00aab337  2eff158813ab00         -call dword ptr cs:[0xab1388]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11211656) /* 0xab1388 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aab33e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aab340  750a                   -jne 0xaab34c
    if (!cpu.flags.zf)
    {
        goto L_0x00aab34c;
    }
    // 00aab342  e85d1d0000             -call 0xaad0a4
    cpu.esp -= 4;
    sub_aad0a4(app, cpu);
    if (cpu.terminate) return;
    // 00aab347  beffffffff             -mov esi, 0xffffffff
    cpu.esi = 4294967295 /*0xffffffff*/;
L_0x00aab34c:
    // 00aab34c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00aab34e  ff15b036ab00           -call dword ptr [0xab36b0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11220656) /* 0xab36b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aab354  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00aab356  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aab357  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aab358  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aab359  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aab35a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void sub_aab360(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aab360  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aab361  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aab362  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aab363  8b0d0838ab00           -mov ecx, dword ptr [0xab3808]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11221000) /* 0xab3808 */);
    // 00aab369  a10c38ab00             -mov eax, dword ptr [0xab380c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11221004) /* 0xab380c */);
    // 00aab36e  3b05043aab00           +cmp eax, dword ptr [0xab3a04]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(11221508) /* 0xab3a04 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00aab374  7304                   -jae 0xaab37a
    if (!cpu.flags.cf)
    {
        goto L_0x00aab37a;
    }
    // 00aab376  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00aab378  eb2f                   -jmp 0xaab3a9
    goto L_0x00aab3a9;
L_0x00aab37a:
    // 00aab37a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aab37c  7e26                   -jle 0xaab3a4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00aab3a4;
    }
    // 00aab37e  8b1d0c38ab00           -mov ebx, dword ptr [0xab380c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(11221004) /* 0xab380c */);
    // 00aab384  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00aab386  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00aab388  c1e302                 -shl ebx, 2
    cpu.ebx <<= 2 /*0x2*/ % 32;
L_0x00aab38b:
    // 00aab38b  833c0200               +cmp dword ptr [edx + eax], 0
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
    // 00aab38f  750c                   -jne 0xaab39d
    if (!cpu.flags.zf)
    {
        goto L_0x00aab39d;
    }
    // 00aab391  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00aab393  890d0838ab00           -mov dword ptr [0xab3808], ecx
    app->getMemory<x86::reg32>(x86::reg32(11221000) /* 0xab3808 */) = cpu.ecx;
    // 00aab399  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aab39a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aab39b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aab39c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00aab39d:
    // 00aab39d  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00aab3a0  39d8                   +cmp eax, ebx
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
    // 00aab3a2  7ce7                   -jl 0xaab38b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00aab38b;
    }
L_0x00aab3a4:
    // 00aab3a4  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x00aab3a9:
    // 00aab3a9  890d0838ab00           -mov dword ptr [0xab3808], ecx
    app->getMemory<x86::reg32>(x86::reg32(11221000) /* 0xab3808 */) = cpu.ecx;
    // 00aab3af  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aab3b0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aab3b1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aab3b2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void sub_aab3b4(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aab3b4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aab3b5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aab3b6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aab3b7  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aab3b8  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00aab3ba  ff15dc36ab00           -call dword ptr [0xab36dc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11220700) /* 0xab36dc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aab3c0  8b1d0c38ab00           -mov ebx, dword ptr [0xab380c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(11221004) /* 0xab380c */);
    // 00aab3c6  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00aab3c8  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00aab3ca  7e2d                   -jle 0xaab3f9
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00aab3f9;
    }
    // 00aab3cc  8d0c9d00000000         -lea ecx, [ebx*4]
    cpu.ecx = x86::reg32(cpu.ebx * 4);
    // 00aab3d3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00aab3d5:
    // 00aab3d5  8b1d0838ab00           -mov ebx, dword ptr [0xab3808]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(11221000) /* 0xab3808 */);
    // 00aab3db  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00aab3dd  833b00                 +cmp dword ptr [ebx], 0
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
    // 00aab3e0  750f                   -jne 0xaab3f1
    if (!cpu.flags.zf)
    {
        goto L_0x00aab3f1;
    }
    // 00aab3e2  8933                   -mov dword ptr [ebx], esi
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.esi;
    // 00aab3e4  ff15e036ab00           -call dword ptr [0xab36e0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11220704) /* 0xab36e0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aab3ea  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00aab3ec  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aab3ed  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aab3ee  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aab3ef  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aab3f0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00aab3f1:
    // 00aab3f1  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00aab3f4  42                     -inc edx
    (cpu.edx)++;
    // 00aab3f5  39c8                   +cmp eax, ecx
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
    // 00aab3f7  7cdc                   -jl 0xaab3d5
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00aab3d5;
    }
L_0x00aab3f9:
    // 00aab3f9  8b150c38ab00           -mov edx, dword ptr [0xab380c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11221004) /* 0xab380c */);
    // 00aab3ff  42                     -inc edx
    (cpu.edx)++;
    // 00aab400  a10838ab00             -mov eax, dword ptr [0xab3808]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11221000) /* 0xab3808 */);
    // 00aab405  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 00aab408  e8e30c0000             -call 0xaac0f0
    cpu.esp -= 4;
    sub_aac0f0(app, cpu);
    if (cpu.terminate) return;
    // 00aab40d  8b150c38ab00           -mov edx, dword ptr [0xab380c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11221004) /* 0xab380c */);
    // 00aab413  a30838ab00             -mov dword ptr [0xab3808], eax
    app->getMemory<x86::reg32>(x86::reg32(11221000) /* 0xab3808 */) = cpu.eax;
    // 00aab418  8d4a01                 -lea ecx, [edx + 1]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 00aab41b  893490                 -mov dword ptr [eax + edx*4], esi
    app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 4) = cpu.esi;
    // 00aab41e  890d0c38ab00           -mov dword ptr [0xab380c], ecx
    app->getMemory<x86::reg32>(x86::reg32(11221004) /* 0xab380c */) = cpu.ecx;
    // 00aab424  ff15e036ab00           -call dword ptr [0xab36e0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11220704) /* 0xab36e0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aab42a  a10c38ab00             -mov eax, dword ptr [0xab380c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11221004) /* 0xab380c */);
    // 00aab42f  48                     -dec eax
    (cpu.eax)--;
    // 00aab430  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aab431  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aab432  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aab433  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aab434  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_aab438(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aab438  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aab439  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aab43a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00aab43b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00aab43c  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00aab43d  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00aab440  8b3d0838ab00           -mov edi, dword ptr [0xab3808]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(11221000) /* 0xab3808 */);
    // 00aab446  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00aab449  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00aab44b  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00aab44d  0f8caa000000           -jl 0xaab4fd
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00aab4fd;
    }
    // 00aab453  ff15dc36ab00           -call dword ptr [0xab36dc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11220700) /* 0xab36dc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aab459  83fa01                 +cmp edx, 1
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
    // 00aab45c  7209                   -jb 0xaab467
    if (cpu.flags.cf)
    {
        goto L_0x00aab467;
    }
    // 00aab45e  7613                   -jbe 0xaab473
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00aab473;
    }
    // 00aab460  83fa02                 +cmp edx, 2
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
    // 00aab463  7416                   -je 0xaab47b
    if (cpu.flags.zf)
    {
        goto L_0x00aab47b;
    }
    // 00aab465  eb21                   -jmp 0xaab488
    goto L_0x00aab488;
L_0x00aab467:
    // 00aab467  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00aab469  751d                   -jne 0xaab488
    if (!cpu.flags.zf)
    {
        goto L_0x00aab488;
    }
    // 00aab46b  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 00aab46e  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aab46f  6af6                   -push -0xa
    app->getMemory<x86::reg32>(cpu.esp-4) = -10 /*-0xa*/;
    cpu.esp -= 4;
    // 00aab471  eb0e                   -jmp 0xaab481
    goto L_0x00aab481;
L_0x00aab473:
    // 00aab473  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 00aab476  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00aab477  6af5                   -push -0xb
    app->getMemory<x86::reg32>(cpu.esp-4) = -11 /*-0xb*/;
    cpu.esp -= 4;
    // 00aab479  eb06                   -jmp 0xaab481
    goto L_0x00aab481;
L_0x00aab47b:
    // 00aab47b  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 00aab47e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aab47f  6af4                   -push -0xc
    app->getMemory<x86::reg32>(cpu.esp-4) = -12 /*-0xc*/;
    cpu.esp -= 4;
L_0x00aab481:
    // 00aab481  2eff151014ab00         -call dword ptr cs:[0xab1410]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11211792) /* 0xab1410 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00aab488:
    // 00aab488  8b2d0c38ab00           -mov ebp, dword ptr [0xab380c]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(11221004) /* 0xab380c */);
    // 00aab48e  8d0cb500000000         -lea ecx, [esi*4]
    cpu.ecx = x86::reg32(cpu.esi * 4);
    // 00aab495  8b3d0838ab00           -mov edi, dword ptr [0xab3808]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(11221000) /* 0xab3808 */);
    // 00aab49b  39ee                   +cmp esi, ebp
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
    // 00aab49d  7d09                   -jge 0xaab4a8
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00aab4a8;
    }
    // 00aab49f  01f9                   +add ecx, edi
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
    // 00aab4a1  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00aab4a4  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 00aab4a6  eb49                   -jmp 0xaab4f1
    goto L_0x00aab4f1;
L_0x00aab4a8:
    // 00aab4a8  8d5104                 -lea edx, [ecx + 4]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00aab4ab  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00aab4ad  e83e0c0000             -call 0xaac0f0
    cpu.esp -= 4;
    sub_aac0f0(app, cpu);
    if (cpu.terminate) return;
    // 00aab4b2  8b150c38ab00           -mov edx, dword ptr [0xab380c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11221004) /* 0xab380c */);
    // 00aab4b8  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00aab4ba  39f2                   +cmp edx, esi
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
    // 00aab4bc  7d18                   -jge 0xaab4d6
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00aab4d6;
    }
    // 00aab4be  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00aab4c5  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
L_0x00aab4c7:
    // 00aab4c7  c7040300000000         -mov dword ptr [ebx + eax], 0
    app->getMemory<x86::reg32>(cpu.ebx + cpu.eax * 1) = 0 /*0x0*/;
    // 00aab4ce  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00aab4d1  42                     -inc edx
    (cpu.edx)++;
    // 00aab4d2  39c8                   +cmp eax, ecx
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
    // 00aab4d4  7cf1                   -jl 0xaab4c7
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00aab4c7;
    }
L_0x00aab4d6:
    // 00aab4d6  8d04b500000000         -lea eax, [esi*4]
    cpu.eax = x86::reg32(cpu.esi * 4);
    // 00aab4dd  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 00aab4e0  46                     -inc esi
    (cpu.esi)++;
    // 00aab4e1  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 00aab4e3  893d0838ab00           -mov dword ptr [0xab3808], edi
    app->getMemory<x86::reg32>(x86::reg32(11221000) /* 0xab3808 */) = cpu.edi;
    // 00aab4e9  89350c38ab00           -mov dword ptr [0xab380c], esi
    app->getMemory<x86::reg32>(x86::reg32(11221004) /* 0xab380c */) = cpu.esi;
    // 00aab4ef  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
L_0x00aab4f1:
    // 00aab4f1  ff15e036ab00           -call dword ptr [0xab36e0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11220704) /* 0xab36e0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aab4f7  8b3d0838ab00           -mov edi, dword ptr [0xab3808]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(11221000) /* 0xab3808 */);
L_0x00aab4fd:
    // 00aab4fd  8b3d0838ab00           -mov edi, dword ptr [0xab3808]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(11221000) /* 0xab3808 */);
    // 00aab503  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00aab506  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aab507  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aab508  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aab509  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aab50a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aab50b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_aab50c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aab50c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aab50d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00aab50f  ff15dc36ab00           -call dword ptr [0xab36dc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11220700) /* 0xab36dc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aab515  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00aab517  7e1c                   -jle 0xaab535
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00aab535;
    }
    // 00aab519  3b150c38ab00           +cmp edx, dword ptr [0xab380c]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(11221004) /* 0xab380c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00aab51f  7d14                   -jge 0xaab535
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00aab535;
    }
    // 00aab521  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00aab528  8b150838ab00           -mov edx, dword ptr [0xab3808]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11221000) /* 0xab3808 */);
    // 00aab52e  c7040200000000         -mov dword ptr [edx + eax], 0
    app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 1) = 0 /*0x0*/;
L_0x00aab535:
    // 00aab535  ff15e036ab00           -call dword ptr [0xab36e0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11220704) /* 0xab36e0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aab53b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aab53c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_aab540(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00aab540  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00aab541  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00aab542  6af6                   -push -0xa
    app->getMemory<x86::reg32>(cpu.esp-4) = -10 /*-0xa*/;
    cpu.esp -= 4;
    // 00aab544  2eff15dc13ab00         -call dword ptr cs:[0xab13dc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11211740) /* 0xab13dc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aab54b  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00aab54d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aab54f  7405                   -je 0xaab556
    if (cpu.flags.zf)
    {
        goto L_0x00aab556;
    }
    // 00aab551  83f8ff                 +cmp eax, -1
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
    // 00aab554  7505                   -jne 0xaab55b
    if (!cpu.flags.zf)
    {
        goto L_0x00aab55b;
    }
L_0x00aab556:
    // 00aab556  e845000000             -call 0xaab5a0
    cpu.esp -= 4;
    sub_aab5a0(app, cpu);
    if (cpu.terminate) return;
L_0x00aab55b:
    // 00aab55b  e854feffff             -call 0xaab3b4
    cpu.esp -= 4;
    sub_aab3b4(app, cpu);
    if (cpu.terminate) return;
    // 00aab560  6af5                   -push -0xb
    app->getMemory<x86::reg32>(cpu.esp-4) = -11 /*-0xb*/;
    cpu.esp -= 4;
    // 00aab562  2eff15dc13ab00         -call dword ptr cs:[0xab13dc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11211740) /* 0xab13dc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aab569  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00aab56b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aab56d  7405                   -je 0xaab574
    if (cpu.flags.zf)
    {
        goto L_0x00aab574;
    }
    // 00aab56f  83f8ff                 +cmp eax, -1
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
    // 00aab572  7505                   -jne 0xaab579
    if (!cpu.flags.zf)
    {
        goto L_0x00aab579;
    }
L_0x00aab574:
    // 00aab574  e827000000             -call 0xaab5a0
    cpu.esp -= 4;
    sub_aab5a0(app, cpu);
    if (cpu.terminate) return;
L_0x00aab579:
    // 00aab579  e836feffff             -call 0xaab3b4
    cpu.esp -= 4;
    sub_aab3b4(app, cpu);
    if (cpu.terminate) return;
    // 00aab57e  6af4                   -push -0xc
    app->getMemory<x86::reg32>(cpu.esp-4) = -12 /*-0xc*/;
    cpu.esp -= 4;
    // 00aab580  2eff15dc13ab00         -call dword ptr cs:[0xab13dc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11211740) /* 0xab13dc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00aab587  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00aab589  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00aab58b  7405                   -je 0xaab592
    if (cpu.flags.zf)
    {
        goto L_0x00aab592;
    }
    // 00aab58d  83f8ff                 +cmp eax, -1
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
    // 00aab590  7505                   -jne 0xaab597
    if (!cpu.flags.zf)
    {
        goto L_0x00aab597;
    }
L_0x00aab592:
    // 00aab592  e809000000             -call 0xaab5a0
    cpu.esp -= 4;
    sub_aab5a0(app, cpu);
    if (cpu.terminate) return;
L_0x00aab597:
    // 00aab597  e818feffff             -call 0xaab3b4
    cpu.esp -= 4;
    sub_aab3b4(app, cpu);
    if (cpu.terminate) return;
    // 00aab59c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aab59d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00aab59e  c3                     -ret 
    cpu.esp += 4;
    return;
}

}
